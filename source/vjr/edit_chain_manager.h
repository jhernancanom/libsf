//////////
//
// /libsf/source/vjr/edit_chain_manager.h
//
//////
// Version 0.54
// Copyright (c) 2014 by Rick C. Hodgin
//////
// Last update:
//     Jul.06.2014
//////
// Change log:
//     Jul.06.2014 - Initial creation
//////
//
// This software is released as Liberty Software under a Repeat License, as governed
// by the Public Benefit License v1.0 or later (PBL).
//
// You are free to use, copy, modify and share this software.  However, it can only
// be released under the PBL version indicated, and every project must include a copy
// of the pbl.txt document for its version as is at http://www.libsf.org/licenses/.
//
// For additional information about this project, or to view the license, see:
//
//     http://www.libsf.org/
//     http://www.libsf.org/licenses/
//     http://www.visual-freepro.org/vjr/indexmain.html
//     http://www.visual-freepro.org/wiki/index.php/PBL
//
// Thank you.  And may The Lord bless you richly as you lift up your life, your
// talents, your gifts, your praise, unto Him.  In Jesus' name I pray.  Amen.
//
//




//////////
// Constants
//////
	const u32				_ECM_MINIMUM_LINE_ALLOCATION_LENGTH		= 96;		// Allocate data in 96 byte blocks


//////////
// Structs
//////
	struct SFont;
	struct SFunction;
	struct SVariable;

	// When line-selecting, indicates the type
	const u32		_SEM_SELECT_MODE_NONE						= 0;
	const u32		_SEM_SELECT_MODE_LINE						= 1;
	const u32		_SEM_SELECT_MODE_COLUMN						= 2;
	const u32		_SEM_SELECT_MODE_ANCHOR						= 3;

	// Breakpoint types
	const u32		_BREAKPOINT_NONE							= 0;	// No breakpoint
	const u32		_BREAKPOINT_ALWAYS							= 1;	// Always stops
	const u32		_BREAKPOINT_CONDITIONAL_TRUE				= 2;	// Breaks when the condition is true
	const u32		_BREAKPOINT_CONDITIONAL_FALSE				= 3;	// Breaks when the condition is false
	const u32		_BREAKPOINT_CONDITIONAL_TRUE_COUNTDOWN		= 4;	// Breaks when the condition is true, and the countdown reaches zero
	const u32		_BREAKPOINT_CONDITIONAL_FALSE_COUNTDOWN		= 5;	// Breaks when the condition is false, and the countdown reaches zero

	struct SUndo
	{
		u32			uidBefore;												// The item before
		u32			uidAfter;												// The item after

		SLine*	first;													// The first SEditChain that would've gone between them
		// If multiple lines were deleted, the chain is moved here.
		// If the line was changed, the old value is here
	};

	struct SSourceCode
	{
		SFunction*		firstFunction;									// First function in the program

		SVariable*		params;											// The first parameter in the function
		SVariable*		globals;										// The first global variable declared
		SVariable*		locals;											// The first local variable declared
		SVariable*		returns;										// The first return variable declared
		SVariable*		scoped;											// The first scoped/temporary variable needed by the function

		SEM*			sourceCode;										// The source code for this program
	};

	struct SBreakpoint
	{
		// See _BREAKPOINT_* constants
		u32				type;
		bool			isUsed;											// Allocated in gBreakpoints as a bulk structure

		// If there's a countdown
		u32				countdownResetValue;							// The value the countdown will reset to once it fires, if 0 always fires
		u32				countdown;										// Countdown to 0 when it fires

		// A test condition
		SSourceCode*	conditionalCode;								// What is the conditional test expression for this breakpoint firing?

		// Code to execute when the conditionalCode returns true
		SSourceCode*	executeCode;									// Arbitrary code to execute when the breakpoint fires
																		// Explicitly:  breakpoint_always(), breakpoint_true(), breakpoint_false()
	};

	struct SLine
	{
		SLL				ll;												// Link list throughout
		u32				uid;											// Unique id for this line, used for undos and identifying individual lines which may move about

		// Each render, these are updated
		u32				renderId;										// Each time it's rendered, this value is set
		RECT			rcLastRender;									// The rectangle within the parent of the last render

		u32				lineNumber;										// This line's number
		SBreakpoint*	breakpoint;										// If there's a breakpoint here, what kind?
		SDatum*			sourceCode;										// The text on this line is LEFT(sourceCode.data, sourceCodePopulated)
		s32				sourceCodePopulated;							// The actual populated length sourceCode

		// New line flag, original value as of original load, or last save
		bool			isNewLine;										// If the line's been added during normal editing
		SDatum*			sourceCodeOriginal;								// The original sourceCode when the line was first created, or last saved.  Note:  The length here is the total length as this value does not change

		// Compiler information (see compiler.cpp)
		bool			forceRecompile;									// A flag that if set forces a recompile of this line
		SCompiler*		compilerInfo;									// Information about the last time this line was compiled
		SCompiler*		compilerInfoLast;								// Used during edit-and-continue compilation

		// General purpose extra data
		SExtraInfo*		extra_info;										// Extra information about this item in the chain
	};

	struct SEMPoint
	{
		SLine*			line;											// The actual line here
		u32				uid;											// The UID of the line
		u32				lineNumber;										// The line number
		s32				column;											// The column on this line where the selection is currently
	};


	//////////
	// SEM is short for "SEditManager"
	// Note:  This is also a reference to Sammy Edward Mitchell, the author of
	//        The SEMware Editor, TSE, without whom I would not have been as
	//        prolific in my software development.
	//////
		struct SEM
		{
			SLine*		firstLine;										// First in the chain (first->prev is NULL)
			SLine*		lastLine;										// Last in the chain (last->next is NULL)
			bool		isReadOnly;										// If read-only no changes are allowed, only navigation
			bool		stopNavigationOnNbsp;							// Do ctrl+left/right operations stop at every part of nbsp names (by default, no)?

			// If populated, this SEM is only a placeholder for this instance, and the this->reference points to the real SEM we should use
			SEM*		indirect;										// If not NULL, this SEM points to another SEM which is the real code block
			// NOTE:  Everything below is used ONLY IF INDIRECT IS NULL


		//////////
		// For display
		//////
			SLine*		line_top;										// Top item in the current view
			SLine*		line_cursor;									// Line where the cursor is
			SLine*		line_cursorLast;								// The last location before movement was made
			bool		isOverwrite;									// Are we in overwrite mode?
			bool		showLineNumbers;								// Should we render line numbers?
			bool		showCursorLine;									// Should we render the cursor line?
			bool		showEndLine;									// Should we render the end line in a different color?
			bool		isHeavyProcessing;								// When large amounts of processing will be conducted, the display can be disabled
			bool		isSourceCode;									// Is this source code?
			bool		allowMoveBeyondEndOfLine;						// Do we allow them to move beyond the end of the line?
			RECT		rcLineNumberLastRender;							// Used for mouse clicking, to determine how much we adjust

			// Editing cues
			bool		hideEditCues;									// If true, will not show the changedColor or newColor
			SBgra		changedColor;									// The color when data has changed
			SBgra		newColor;										// The color when data is new

			// Percentages (values are typically 0.05f and 0.15f for 5% to 15%)
			f32			minNbspColorInfluence;							// How much minimum influence should the Nbsp color have for highlighting
			f32			maxNbspColorInfluence;							// How much maximum?

			s32			columnEdit;										// Column we're currently inputting
			s32			columnLeft;										// The column we're displaying at the left-most position (of horizontally scrolled, this will be greater than 0)
			s32			tabWidth;										// How many characters does a tab expand to?
			bool		areTabsEnforced;								// If tabs are enforced, then navigation across whitespaces lands on tab boundaries
			SFont*		font;											// Optional, if not NULL then it overrides the object's font
			u32			renderId;										// Each time it's rendered, the count is incremented.  This allows lines to be tested to see if they are actively rendered, or were previously rendered.

		
		//////////
		// Overlay highlight information to display near the cursor line
		//////
			SLine*		line_highlightBefore;							// Something to highlight before the cursor line
			SLine*		line_highlightAfter;							// Something to highlight after the cursor line


		//////////
		// Note:  If isSelectingLine, then full line select mode.
		//        If isSelectingColumn, then column select mode.
		//        If isSelectingAnchor, then anchor select mode.
		//////
			u32			selectMode;										// See _SEM_SELECT_MODE_* constants
			SEMPoint	selectOrigin;									// Where the selection started
			SEMPoint	selectEnd;										// Where the selection has ended


		//////////
		// For compiled programs
		//////
			SFunction	firstFunction;									// By default, we always create a function head for any code blocks that don't have an explicit "FUNCTION" at the top.


		//////////
		// The undo history operates in two levels:
		// (1) When going through ecm-> it is undoHistory.
		// (2) If accessing ecm->undoHistory-> then it is theUndo, which holds the undo information for that operation.
		//////
			union {
				// If referenced through ecm-> then undoHistory is the undo history for this sec
				SEM*	undoHistory;									// The lines affected by the undo

				// If referenced through ecm->undoHistory, then theUndo is the one in use here
				SUndo*	theUndo;										// If referenced through ecm->undoHistory-> then it only uses theUndo
			};
		};

	struct SEM_callback
	{
		SEM*		sem;											// The manager
		SLine*		line;											// This line

		// Functions to use to access this extra info block
		union {
			u32				_callback;
			void			(*callback)		(SEM_callback* ecb);	// Callback to delete any extra information.  The ec->sourceCode and ec itself will be deleted automatically.
		};

	};


//////////
// Forward declarations
//////
	SEM*					iSEM_allocate						(bool tlIsSourceCode);
	SBuilder*				iSEM_accumulateBuilder				(SEM* sem, SLine* ecHintStart, SLine* ecHintEnd);
	bool					iSEM_saveToDisk						(SEM* sem, s8* tcPathname);
	bool					iSEM_loadFromDisk					(SEM* sem, s8* tcPathname, bool isSourceCode);
	bool					iSEM_duplicate						(SEM** root, SEM* chain, bool tlIncludeUndoHistory);
	void					iSEM_delete							(SEM** root, bool tlDeleteSelf);
	void					iSEM_deleteChain					(SEM** root, bool tlDeleteSelf);
	void					iSEM_deleteChainWithCallback		(SEM** root, bool tlDeleteSelf, SEM_callback* ecb);
	void					iSEM_renumber						(SEM* sem, u32 tnStartingLineNumber);
	SLine*					iSEM_appendLine						(SEM* sem, s8* tcText, s32 tnTextLength, bool tlSetNewLineFlag);
	SLine*					iSEM_insertLine						(SEM* sem, s8* tcText, s32 tnTextLength, SLine* line, bool tlInsertAfter, bool tlSetNewLineFlag);
	void					iSEM_deleteLine						(SEM* sem);
	SFont*					iSEM_getRectAndFont					(SEM* sem, SObject* obj, RECT* rc);
	void					iSEM_getColors						(SEM* sem, SObject* obj, SBgra& backColor, SBgra& foreColor);
	u32						iSEM_render							(SEM* sem, SObject* obj, bool tlRenderCursorline);
	void					iSEM_render_highlightSelectedComps	(SEM* sem, SComp* firstComp);
	bool					iSEM_verifyCursorIsVisible			(SEM* sem, SObject* obj);
	bool					iSEM_onKeyDown_sourceCode			(SWindow* win, SObject* obj, bool tlCtrl, bool tlAlt, bool tlShift, bool tlCaps, s16 tcAscii, u16 tnVKey, bool tlIsCAS, bool tlIsAscii);
	bool					iSEM_onKeyDown						(SWindow* win, SObject* obj, bool tlCtrl, bool tlAlt, bool tlShift, bool tlCaps, s16 tcAscii, u16 tnVKey, bool tlIsCAS, bool tlIsAscii);
	void*					iSEM_findMate						(SEM* sem, SLine* lineStart, SComp* comp);
	void					iSEM_addTooltipHighlight			(SEM* sem, SLine* line, SObject* obj, s8* tcText, s32 tnTextLength, bool tlShowAbove);


	// Editor movements
	bool					iSEM_keystroke						(SEM* sem, SObject* obj, u8 asciiChar);
	bool					iSEM_scroll							(SEM* sem, SObject* obj, s32 deltaY, s32 deltaX);
	bool					iSEM_navigate						(SEM* sem, SObject* obj, s32 deltaY, s32 deltaX);
	bool					iSEM_navigatePages					(SEM* sem, SObject* obj, s32 deltaY);
	bool					iSEM_clearLine						(SEM* sem, SObject* obj);
	bool					iSEM_clearToEndOfLine				(SEM* sem, SObject* obj);
	bool					iSEM_clearToBeginningOfLine			(SEM* sem, SObject* obj);
	bool					iSEM_toggleInsert					(SEM* sem, SObject* obj);
	bool					iSEM_tabIn							(SEM* sem, SObject* obj);
	bool					iSEM_tabOut							(SEM* sem, SObject* obj);
	bool					iSEM_returnKey						(SEM* sem, SObject* obj);
	bool					iSEM_selectAll						(SEM* sem, SObject* obj);
	bool					iSEM_cut							(SEM* sem, SObject* obj);
	bool					iSEM_copy							(SEM* sem, SObject* obj);
	bool					iSEM_paste							(SEM* sem, SObject* obj);
	bool					iSEM_navigateWordLeft				(SEM* sem, SObject* obj, bool tlVerifyCursorIsVisible);
	bool					iSEM_navigateWordRight				(SEM* sem, SObject* obj, bool tlVerifyCursorIsVisible);
	bool					iSEM_navigateToTopLine				(SEM* sem, SObject* obj);
	bool					iSEM_navigateToEndLine				(SEM* sem, SObject* obj);
	bool					iSEM_navigateToSelectStart			(SEM* sem, SObject* obj, bool tlMoveByOrigin);
	bool					iSEM_navigateToSelectEnd			(SEM* sem, SObject* obj, bool tlMoveByOrigin);
	bool					iSEM_rollUp							(SEM* sem, SObject* obj);
	bool					iSEM_rollDown						(SEM* sem, SObject* obj);
	bool					iSEM_centerCursorLine				(SEM* sem, SObject* obj);
	bool					iSEM_selectLineUp					(SEM* sem, SObject* obj);
	bool					iSEM_selectLineDown					(SEM* sem, SObject* obj);
	bool					iSEM_selectLeft						(SEM* sem, SObject* obj);
	bool					iSEM_selectRight					(SEM* sem, SObject* obj);
	bool					iSEM_selectToEndOfLine				(SEM* sem, SObject* obj);
	bool					iSEM_selectToBeginOfLine			(SEM* sem, SObject* obj);
	bool					iSEM_selectColumnToggle				(SEM* sem, SObject* obj);
	bool					iSEM_selectLineToggle				(SEM* sem, SObject* obj);
	bool					iSEM_selectAnchorToggle				(SEM* sem, SObject* obj);
	bool					iSEM_selectWordLeft					(SEM* sem, SObject* obj);
	bool					iSEM_selectWordRight				(SEM* sem, SObject* obj);
	bool					iSEM_selectToTopLine				(SEM* sem, SObject* obj);
	bool					iSEM_selectToEndLine				(SEM* sem, SObject* obj);
	bool					iSEM_deleteLeft						(SEM* sem, SObject* obj);
	bool					iSEM_deleteRight					(SEM* sem, SObject* obj);
	bool					iSEM_deleteWordLeft					(SEM* sem, SObject* obj);
	bool					iSEM_deleteWordRight				(SEM* sem, SObject* obj);
	bool					iSEM_navigateTo_pixelXY				(SEM* sem, SObject* obj, s32 x, s32 y);
	bool					iiSEM_isBreakingCharacter			(SEM* sem, SLine* line, s32 tnDeltaTest);
	void					iSEM_selectStart					(SEM* sem, u32 tnSelectMode);
	bool					iSEM_isSelecting					(SEM* sem);
	void					iSEM_selectStop						(SEM* sem);
	void					iSEM_selectUpdateExtents			(SEM* sem);
