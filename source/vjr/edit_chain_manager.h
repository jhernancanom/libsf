//////////
//
// /libsf/source/vjr/edit_chain_manager.h
//
//////
// Version 0.47
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
//     http://www.visual-freepro.org/wiki/index.php/Repeat_License
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

		SEdit*	first;													// The first SEditChain that would've gone between them
		// If multiple lines were deleted, the chain is moved here.
		// If the line was changed, the old value is here
	};

	struct SSourceCode
	{
		SFunction*	firstFunction;												// First function in the program

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
		u32			type;
		bool		isUsed;												// Allocated in gBreakpoints as a bulk structure

		// If there's a countdown
		u32			countdownResetValue;								// The value the countdown will reset to once it fires, if 0 always fires
		u32			countdown;											// Countdown to 0 when it fires

		// A test condition
		SSourceCode*	conditionalCode;								// What is the conditional test expression for this breakpoint firing?

		// Code to execute when the conditionalCode returns true
		SSourceCode*	executeCode;									// Arbitrary code to execute when the breakpoint fires
																		// Explicitly:  breakpoint_always(), breakpoint_true(), breakpoint_false()
	};

	struct SEdit
	{
		SLL				ll;												// Link list throughout
		u32				uid;											// Unique id for this line, used for undos and identifying individual lines which may move about

		u32				line;											// This line's number
		SBreakpoint*	breakpoint;										// If there's a breakpoint here, what kind?
		SDatum*			sourceCode;										// The text on this line is LEFT(d.data, dPopulated)
		s32				sourceCodePopulated;							// The actual populated length of d (d is allocated in blocks to allow for minor edits without constantly reallocating)

		// Compiler information (see compiler.cpp)
		bool			forceRecompile;									// A flag that if set forces a recompile of this line
		SCompiler*		compilerInfo;									// Information about the last time this line was compiled

		// General purpose extra data
		SExtraInfo*		extra_info;										// Extra information about this item in the chain
	};


	//////////
	// SEM is short for "SEditManager"
	// Note:  This is also a reference to Sammy Edward Mitchell, the author of
	//        The SEMware Editor, TSE, without whom I would not have been as
	//        prolific in my software development.
	//////
		struct SEM
		{
			SEdit*		ecFirst;										// First in the chain (first->prev is NULL)
			SEdit*		ecLast;											// Last in the chain (last->next is NULL)
			bool		isReadOnly;										// If read-only no changes are allowed, only navigation

			// If populated, this ECM is only a placeholder for this instance, and the this->reference points to the real ECM we should use
			SEM*		indirect;										// If not NULL, this ECM points to another ECM which is the real code block
			// NOTE:  Everything below is used ONLY IF INDIRECT IS NULL


			//////////
			// For display
			//////
			SEdit*		ecTopLine;										// Top item in the current view
			SEdit*		ecCursorLine;									// Line where the cursor is
			SEdit*		ecCursorLineLast;								// The last location before movement was made
			bool		isOverwrite;									// Are we in overwrite mode?
			bool		showLineNumbers;								// Should we render line numbers?
			RECT		rcLineNumberLastRender;							// Used for mouse clicking, to determine how much we adjust
			bool		showCursorLine;									// Should we render the cursor line?
			bool		showEndLine;									// Should we render the end line in a different color?
			bool		isHeavyProcessing;								// When large amounts of processing will be conducted, the display can be disabled
			bool		isSourceCode;									// Is this source code?

			s32			column;											// Column we're currently inputting
			s32			leftColumn;										// The column we're displaying at the left-most position (of horizontally scrolled, this will be greater than 0)
			s32			tabWidth;										// How many characters does a tab expand to?
			bool		tabsEnforced;									// If tabs are enforced, then navigation across whitespaces lands on tab boundaries
			SFont*		font;											// Optional, if not NULL then it overrides the object's font


			//////////
			// Selected lines
			//////
			SEdit*		ecSelectedLineStart;							// First line that's selected
			SEdit*		ecSelectedLineEnd;								// Last line that's selected


			//////////
			// Note:  If not isColumn or isAnchor, then it is full line select.
			//        If isColumn, then column select mode.
			//        If isAnchor, then anchor select mode.
			//////
			bool		isColumn;										// If column select mode...
			u32			selectedColumn_startCol;						// Column select mode start
			u32			selectedColumn_endCol;							// end
			bool		isAnchor;										// If anchor select mode...
			u32			selectedAnchor_startCol;						// Anchor select mode start
			u32			selectedAnchor_endCol;							// end


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
		SEM*		em;												// The manager
		SEdit*		ec;												// This line

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
	SBuilder*				iSEM_accumulateBuilder				(SEM* em, SEdit* ecHintStart, SEdit* ecHintEnd);
	bool					iSEM_saveToDisk						(SEM* em, s8* tcPathname);
	bool					iSEM_loadFromDisk					(SEM* em, s8* tcPathname, bool isSourceCode);
	bool					iSEM_duplicate						(SEM** root, SEM* chain, bool tlIncludeUndoHistory);
	void					iSEM_delete							(SEM** root, bool tlDeleteSelf);
	void					iSEM_deleteChain					(SEM** root, bool tlDeleteSelf);
	void					iSEM_deleteChainWithCallback		(SEM** root, bool tlDeleteSelf, SEM_callback* ecb);
	void					iSEM_renumber						(SEM* em, u32 tnStartingLineNumber);
	SEdit*					iSEM_appendLine						(SEM* em, s8* tcText, s32 tnTextLength);
	SEdit*					iSEM_insertLine						(SEM* em, s8* tcText, s32 tnTextLength, SEdit* line, bool tlInsertAfter);
	void					iSEM_deleteLine						(SEM* em);
	SFont*					iSEM_getRectAndFont					(SEM* em, SObject* obj, RECT* rc);
	void					iSEM_getColors						(SEM* em, SObject* obj, SBgra& backColor, SBgra& foreColor);
	u32						iSEM_render							(SEM* em, SObject* obj, bool tlRenderCursorline);
	bool					iSEM_verifyCursorIsVisible			(SEM* em, SObject* obj);
	bool					iSEM_onKeyDown_sourceCode			(SWindow* win, SObject* obj, bool tlCtrl, bool tlAlt, bool tlShift, bool tlCaps, s16 tcAscii, u16 tnVKey, bool tlIsCAS, bool tlIsAscii);
	bool					iSEM_onKeyDown						(SWindow* win, SObject* obj, bool tlCtrl, bool tlAlt, bool tlShift, bool tlCaps, s16 tcAscii, u16 tnVKey, bool tlIsCAS, bool tlIsAscii);


	// Editor movements
	bool					iSEM_keystroke						(SEM* em, SObject* obj, u8 asciiChar);
	bool					iSEM_scroll							(SEM* em, SObject* obj, s32 deltaY, s32 deltaX);
	bool					iSEM_navigate						(SEM* em, SObject* obj, s32 deltaY, s32 deltaX);
	bool					iSEM_navigatePages					(SEM* em, SObject* obj, s32 deltaY);
	bool					iSEM_clearLine						(SEM* em, SObject* obj);
	bool					iSEM_clearToEndOfLine				(SEM* em, SObject* obj);
	bool					iSEM_clearToBeginningOfLine			(SEM* em, SObject* obj);
	bool					iSEM_toggleInsert					(SEM* em, SObject* obj);
	bool					iSEM_tabIn							(SEM* em, SObject* obj);
	bool					iSEM_tabOut							(SEM* em, SObject* obj);
	bool					iSEM_returnKey						(SEM* em, SObject* obj);
	bool					iSEM_selectAll						(SEM* em, SObject* obj);
	bool					iSEM_cut							(SEM* em, SObject* obj);
	bool					iSEM_copy							(SEM* em, SObject* obj);
	bool					iSEM_paste							(SEM* em, SObject* obj);
	bool					iSEM_navigateWordLeft				(SEM* em, SObject* obj);
	bool					iSEM_navigateWordRight				(SEM* em, SObject* obj);
	bool					iSEM_navigateTop					(SEM* em, SObject* obj);
	bool					iSEM_navigateEnd					(SEM* em, SObject* obj);
	bool					iSEM_selectLineUp					(SEM* em, SObject* obj);
	bool					iSEM_selectLineDown					(SEM* em, SObject* obj);
	bool					iSEM_selectLeft						(SEM* em, SObject* obj);
	bool					iSEM_selectRight					(SEM* em, SObject* obj);
	bool					iSEM_selectToEndOfLine				(SEM* em, SObject* obj);
	bool					iSEM_selectToBeginOfLine			(SEM* em, SObject* obj);
	bool					iSEM_selectColumnToggle				(SEM* em, SObject* obj);
	bool					iSEM_selectLineToggle				(SEM* em, SObject* obj);
	bool					iSEM_selectWordLeft					(SEM* em, SObject* obj);
	bool					iSEM_selectWordRight				(SEM* em, SObject* obj);
	bool					iSEM_deleteLeft						(SEM* em, SObject* obj);
	bool					iSEM_deleteRight					(SEM* em, SObject* obj);
	bool					iSEM_deleteWordLeft					(SEM* em, SObject* obj);
	bool					iSEM_deleteWordRight				(SEM* em, SObject* obj);
	bool					iSEM_navigateTo_pixelXY				(SEM* em, SObject* obj, s32 x, s32 y);
