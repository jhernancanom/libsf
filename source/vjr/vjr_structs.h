//////////
//
// /libsf/source/vjr/vjr_structs.h
//
//////
// Version 0.36
// Copyright (c) 2014 by Rick C. Hodgin
//////
// Last update:
//     Feb.12.2014
//////
// Change log:
//     Feb.12.2014 - Initial creation
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




struct SExtraInfo
{
	SExtraInfo* next;													// Next extra info item in chain (if any)
	u32			use_identifier;											// A registered identifier with the system for this extra info block
	u32			type;													// Application defined type, identifies what's stored in this.info.data
	SDatum		info;													// The extra info

	// Functions to use to access this extra info block
	void		(*onAccess)					(SEM* chainMgr, SEdit* chain, SExtraInfo* extra_info);	// When the parent chain is accessed
	void		(*onArrival)				(SEM* chainMgr, SEdit* chain, SExtraInfo* extra_info);	// When the target implementation is sitting on the chain record
	void		(*onUpdate)					(SEM* chainMgr, SEdit* chain, SExtraInfo* extra_info);	// When the parent chain is updated

	// Functions called before freeing, and after allocating, the this.info datum
	SExtraInfo*	(*extra_info_allocate)		(SEM* chainMgr, SEdit* chain, SExtraInfo* extra_info);	// Called to allocate this.info per needs
	SExtraInfo*	(*extra_info_duplicate)		(SEM* chainMgr, SEdit* chain, SExtraInfo* extra_info);	// Called when a chain is duplicated, determines what if any of the source's data needs to be duplicated as well
	SExtraInfo*	(*extra_info_free)			(SEM* chainMgr, SEdit* chain, SExtraInfo* extra_info);	// Called to free any data in this.info
};

struct SDateTime
{
	u32		julian;														// Julian day number
	f32		seconds;													// Seconds elapsed since midnight
};

struct SUndo
{
	u32			uidBefore;												// The item before
	u32			uidAfter;												// The item after

	SEdit*	first;													// The first SEditChain that would've gone between them
	// If multiple lines were deleted, the chain is moved here.
	// If the line was changed, the old value is here
};

struct SEdit
{
	SLL			ll;														// Link list throughout
	u32			uid;													// Unique id for this line, used for undos and identifying individual lines which may move about

	u32			line;													// This line's number
	SDatum*		sourceCode;												// The text on this line is LEFT(d.data, dPopulated)
	s32			sourceCodePopulated;									// The actual populated length of d (d is allocated in blocks to allow for minor edits without constantly reallocating)

	// Compiler information (see compiler.cpp)
	bool		forceRecompile;											// A flag that if set forces a recompile of this line
	SCompiler*	compilerInfo;											// Information about the last time this line was compiled

	// General purpose extra data
	SExtraInfo*	extra_info;												// Extra information about this item in the chain
};

// SEM is short for "SEditManager"
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
	bool		showCursorLine;									// Should we render the cursor line?
	bool		showEndLine;									// Should we render the end line in a different color?
	bool		isHeavyProcessing;								// When large amounts of processing will be conducted, the display can be disabled

	s32			column;											// Column we're currently inputting
	s32			leftColumn;										// The column we're displaying at the left-most position (of horizontally scrolled, this will be greater than 0)


//////////
// Selected lines
//////
	SEdit*			ecSelectedLineStart;							// First line that's selected
	SEdit*			ecSelectedLineEnd;								// Last line that's selected


//////////
// Note:  If not isColumn or isAnchor, then it is full line select.
//        If isColumn, then column select mode.
//        If isAnchor, then anchor select mode.
//////
	bool		isColumn;										// If column select mode...
	u32			selectedColumnStart;							// Column select mode start
	u32			selectedColumnEnd;								// end
	bool		isAnchor;										// If anchor select mode...
	u32			selectedAnchorStart;							// Anchor select mode start
	u32			selectedAnchorEnd;								// end


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

struct SEcCallback
{
	SEM*		em;												// The manager
	SEdit*		ec;												// This line

	// Functions to use to access this extra info block
	union {
		u32				_callback;
		void			(*callback)		(SEcCallback* ecb);		// Callback to delete any extra information.  The ec->sourceCode and ec itself will be deleted automatically.
	};

};

struct SFont
{
	HDC			hdc;						// Device context used for its creation

	// Current font instance flags
	SDatum		name;						// Name of this font
	s32			charset;					// Font charset
	bool		isBold;						// Is the font bold? (Note: This is independent of the font name itself having bold in it, such as "Ubuntu Bold"
	bool		isItalic;					// Is the font italic?
	bool		isUnderline;				// Is the font underline?
	bool		isStrikethrough;			// Is the font strikethrough?
	bool		isCondensed;				// Is the font condensed?
	bool		isExtended;					// Is the font extended?
	bool		isOutline;					// Is the font outlined?
	bool		isShadow;					// Is the font shadowed?

	// Handles to the current font setting
	HFONT		hfont;

	// Internal Windows settings
	s32			_sizeUsedForCreateFont;
	u32			_size;
	u32			_weight;
	u32			_italics;
	u32			_underline;
	TEXTMETRIC	tm;
};

struct SHover
{
	HWND		hwnd;						// Window for the hover
	SBitmap*	bmp;						// Bitmap for the hover text
};

struct SEventsGeneral
{
	union {
		u32		_onLoad;
		bool	(*onLoad)					(SWindow* win, SObject* obj);							// Called to load anything needed by the init() event (holds a template/skeleton object)
	};
	union {
		u32		_onInit;
		bool	(*onInit)					(SWindow* win, SObject* obj);							// Called to initialize anything
	};
	union {
		u32		_onCreated;
		bool	(*onCreated)				(SWindow* win, SObject* obj);							// Called after initialization, before the object is sized
	};
	union {
		u32		_onResize;
		bool	(*onResize)					(SWindow* win, SObject* obj, u32* widthRequired_out, u32* heightRequired_out);	// Called to size or resize the object
	};
	union {
		u32		_onMoved;
		bool	(*onMoved)					(SWindow* win, SObject* obj, u32* xOverride_out, u32* yOverride_out);			// Called when the object has been moved
	};
	union {
		u32		_onRender;
		bool	(*onRender)					(SWindow* win, SObject* obj);							// Called to render to bmp (returns if anything was drawn)
	};
	union {
		u32		_onPublish;
		bool	(*onPublish)				(SWindow* win, SObject* obj);							// Called to publish the control onto the parent (which will populate bmpScale if need be)
	};
	union {
		u32		_onQueryUnload;
		bool	(*onQueryUnload)			(SWindow* win, SObject* obj);							// Called before onDestroy, determines if the form should actually be destroyed
	};
	union {
		u32		_onDestroy;
		bool	(*onDestroy)				(SWindow* win, SObject* obj);							// Called when the object will be destroyed
	};
	union {
		u32		_onUnload;
		bool	(*onUnload)					(SWindow* win, SObject* obj);							// Called after the object has been destroyed, to unload anything (holds a template/skeleton object)
	};
	union {
		u32		_onGotFocus;
		bool	(*onGotFocus)				(SWindow* win, SObject* obj);							// Called when the object receives focus (note multiple items can have simultaneous focus)
	};
	union {
		u32		_onLostFocus;
		bool	(*onLostFocus)				(SWindow* win, SObject* obj);							// Called when the object loses focus
	};
	union {
		u32		_onAddObject;
		bool	(*onAddObject)				(SWindow* win, SObject* obj);							// Called when an object is added
	};
	union {
		u32		_onAddProperty;
		bool	(*onAddProperty)			(SWindow* win, SObject* obj);							// Called when a property is added
	};
	union {
		u32		_onError;
		bool	(*onError)					(SWindow* win, SObject* obj);							// Called when an error is triggered in code on an object
	};
	union {
		u32		_onScrolled;
		bool	(*onScrolled)				(SWindow* win, SObject* obj);							// Called when an object has been scrolled
	};
	union {
		u32		_activate;
		bool	(*activate)					(SWindow* win, SObject* obj);							// Called when activated
	};
	union {
		u32		_deactivate;
		bool	(*deactivate)				(SWindow* win, SObject* obj);							// Called when deactivated
	};
	union {
		u32		_onSelect;
		bool	(*onSelect)					(SWindow* win, SObject* obj, SObject* oItem);			// When an option is selected
	};
	union {
		u32		_onDeselect;
		bool	(*onDeselect)				(SWindow* win, SObject* obj, SObject* oItem);			// When an option is deselected
	};
	union {
		u32		_onInteractiveChange;
		bool	(*onInteractiveChange)		(SWindow* win, SObject* obj);							// Called when the data changes
	};
	union {
		u32		_onProgrammaticChange;
		bool	(*onProgrammaticChange)		(SWindow* win, SObject* obj);							// Called when the data changes
	};
};

struct SEventsMouse
{
	// Holds status for changes
	u32			_lastClick;													// When the last mouseClickEx was called, what was the tnClick value?
	u32			thisClick;													// The tnClick parameter passed below, it is the _MOUSE_*_BUTTON amalgam based on the current mouse button state
	bool		isMouseDown;												// Is the mouse down over this item?
	bool		isMouseOver;												// Used for signaling enter/leave events
	u32			startHoverTickCount;										// At each last mouseMove the startHoverTickCount is set, if the interval elapses the hover event is triggered
	SHover*		hover;														// If there's an active hover, this value is not NULL
	bool		hasHoverSignaled;											// If the hover has signaled already on this control

	// Mouse callbacks issued by VJr to the internal object controller.
	// These will be translated by the internal object controller into executable VJr VXB code.
	// Return value indicates if the event should be sent to its parent instead (if NODEFAULT was issued during execution).
	union {
		u32		_onMouseClickEx;
		bool	(*onMouseClickEx)		(SWindow* win, SObject* obj, s32 x, s32 y, bool tlCtrl, bool tlAlt, bool tlShift, u32 tnClick);	// 1=left, 2=middle, 4=right, 2^n bit positions indicate which buttons are clicked
	};
	union {
		u32		_onMouseDblClickEx;
		bool	(*onMouseDblClickEx)	(SWindow* win, SObject* obj, s32 x, s32 y, bool tlCtrl, bool tlAlt, bool tlShift, u32 tnClick);	// 1=left, 2=middle, 4=right, 2^n bit positions indicate which buttons are clicked
	};
	union {
		u32		_onMouseWheel;
		bool	(*onMouseWheel)			(SWindow* win, SObject* obj, s32 tnUnits);			// Signed units indicating direction and velocity
	};
	union {
		u32		_onMouseMove;
		bool	(*onMouseMove)			(SWindow* win, SObject* obj, s32 x, s32 y, bool tlCtrl, bool tlAlt, bool tlShift, u32 tnClick);	// Coordinates for the move
	};
	union {
		u32		_onMouseDown;
		bool	(*onMouseDown)			(SWindow* win, SObject* obj, s32 x, s32 y, bool tlCtrl, bool tlAlt, bool tlShift, u32 tnClick);	// Coordinates for where the mouse button changed
	};
	union {
		u32		_onMouseUp;
		bool	(*onMouseUp)			(SWindow* win, SObject* obj, s32 x, s32 y, bool tlCtrl, bool tlAlt, bool tlShift, u32 tnClick);	// Coordinates for where the mouse button changed
	};
	union {
		u32		_onMouseEnter;
		bool	(*onMouseEnter)			(SWindow* win, SObject* obj);						// When mouse enters an object
	};
	union {
		u32		_onMouseLeave;
		bool	(*onMouseLeave)			(SWindow* win, SObject* obj);						// When mouse leaves an object
	};
	union {
		u32		_onMouseHover;
		bool	(*onMouseHover)			(SWindow* win, SObject* obj, s32 x, s32 y, bool tlCtrl, bool tlAlt, bool tlShift, u32 tnClick);	// Coordinates where hovering
	};
};

struct SEventsKeyboard
{
	// Keyboard callbacks
	// Bool indicates if the event should be sent to its parent instead
	union {
		u32		_onKeyDown;
		bool	(*onKeyDown)		(SWindow* win, SObject* obj, bool tlCtrl, bool tlAlt, bool tlShift, bool tlCaps, s16 tnAsciiChar, u16 tnVKey, bool tlIsCAS, bool tlIsAscii);
	};
	union {
		u32		_onKeyUp;
		bool	(*onKeyUp)			(SWindow* win, SObject* obj, bool tlCtrl, bool tlAlt, bool tlShift, bool tlCaps, s16 tnAsciiChar, u16 tnVKey, bool tlIsCAS, bool tlIsAscii);
	};
};

struct SEvents
{
	SEventsGeneral		general;										// General object events
	SEventsMouse		mouse;											// Mouse events for the object
	SEventsKeyboard		keyboard;										// Keyboard events for the object
};

struct SProperties
{
	// Information about the object itself
	s32			tabIndex;												// The tab order
	bool		tabStop;												// Does this object stop for tabs?
	s32			helpContextId;											// Help context
	bool		hasWhatsThisButton;										// Does it have a what's this button?
	bool		hasWhatsThisHelp;										// Does it have what's this help?
	s32			whatsThisHelpId;										// The what's this help id

	// Mouse information
	s32			mousePointer;											// The mouse pointer to use

	// Object flags
	bool		isEnabled;												// If it is responding to events
	bool		hasFocus;												// Does this object have focus?
	bool		isMovable;												// Is this object movable?
	bool		isVisible;												// If it's visible

	RECT		rcMax;													// The maximum rectangle for the form
	RECT		rcMin;													// The minimum rectangle for the form

	SBgra		nwRgba;													// Northwest back color for border
	SBgra		neRgba;													// Northeast back color for border
	SBgra		swRgba;													// Southwest back color for border
	SBgra		seRgba;													// Southeast back color for border
	SBgra		backColor;												// Back color for the client content
	SBgra		foreColor;												// Default text fore color
	SBgra		captionColor;											// Color of the caption

	// General flags and settings
	bool		allowOutput;											// Allow output to the form?
	bool		alwaysOnBottom;											// Is this form always on the bottom of the Z-order?
	bool		alwaysOnTop;											// Is this form always on the top of the z-order?
	bool		autoCenter;												// Should this form auto-center itself relative to its parent?
	s32			borderStyle;											// 0=none, 1=fixed, 2=fixed standard presentation, 3=sizable presentation
	bool		isClosable;											// Is the form closeable through user interaction?
	bool		processKeyPreviewEvents;								// Do keystrokes for controls on the form go through the form's Key* events as well?
	bool		hasControlBox;											// Does the form show its control box?
	bool		hasMinButton;											// Is the minimize button shown?
	bool		hasMaxButton;											// Is the maximize button shown?
	bool		hasCloseButton;											// Is the close button shown?
	s32			scaleMode;												// 0=foxels, 3=pixels (default)
	bool		showInTaskBar;											// Is this form shown in a taskbar?  Only relates to top-level forms (no parent, or parent is _screen).
	s32			windowState;											// 0=normal, 1=minimized, 2=maximized

	// The following are ignored, maintained only for backward compatibility
	bool		bindControls;											// Are controls bound to their source?
	s32			bufferMode;												// 0=none, 1=pessimistic, 1=optimistic, VJr always uses optimistic. Developers can use the LOCK command if they want a record explicitly locked.
	bool		clipControls;											// Ignored. VJr always re-renders the entire control.
	s32			colorSource;											// Ignored. VJr always uses its themed controls.
	bool		continuousScroll;										// Ignored.
	s32			dataSessionId;											// Ignored, always set to -1.
	s32			defolecid;												// Ignored, always uses system locale.
	bool		desktop;												// Ignored, all VJr forms can be shown anywhere.  To keep inside a window, parent it to _screen or a form.
	bool		isDockable;												// Ignored, always set to .F., docking is not supported in VJr.
	bool		isDocked;												// Ignored, always set to .F..
	s32			dockPosition;											// Ignored, always set to -1.
	s32			drawmode;												// Ignored, drawing is not supported in VJr this way.  See the _graphics object.
	s32			drawstyle;												// Ignored, always set to 13.
	s32			drawwidth;												// Ignored, always set to 1.
	SBgra		fillColor;												// Ignored, always set to RGB(255,255,255).
	s32			fillStyle;												// Ignored, always set to 0.
	bool		halfHeightCaption;										// Ignored, always set to .F..
	s32			hScrollSmallChange;										// Ignored, always uses system defaults.
	s32			vScrollSmallChange;										// Ignored, always uses system defaults.
	bool		macDesktop;												// Ignored, always set to .F..
	bool		mdiForm;												// Ignroed, always set to .F..
	s32			oleDragMode;											// Ignored, always set to 0.
	s32			oleDropEffects;											// Ignored, always set to 3.
	s32			oleDropHasData;											// Ignored, always set to -1.
	s32			oleDropMode;											// Ignored, always set to 0.
	s32			releaseType;											// Ignored, always returns 0.
	bool		rightToLeft;											// Ignored, always returns .F..
	s32			scrollbars;												// Ignored, always returns 3 both, scrollbars are automatic in VJr.
	s32			showTips;												// Ignored, always returns .T..
	s32			showWindow;												// Ignored, always returns 2, all forms in VJr are top-level modeless forms. Min/max constraints can keep it in a fixed position it within a parent window.
	bool		sizeBox;												// Ignored, always returns .F..
	bool		themes;													// Ignored, always returns .T., VJr always uses its own themes for graphics.
	s32			titleBar;												// Ignored, returns what is indicated by borderStyle.
	s32			windowType;												// Ignored, always returns 0=modeless, all forms in VJr are modeless.
	bool		zoomBox;												// Ignored, always returns .F.
	s32			anchor;												// Method this item uses when its parent is resized

	// Used only for labels in lists, like SObjectOption
	bool		selected;												// Is this item selected?

	// Flags for data
	u32			style;													// See _TEXTBOX_STYLE_* constants (plain, 2D, 3D)
	u32			alignment;												// 0=left, 1=right, 2=center, always centered vertically

	// Flags for display and input
	s32			cursor;													// Position of the flashing cursor, where input goes
	s32			selectStart;											// Where does the selection begin?
	s32			selectEnd;												// Where does the selection end?

	// Flags for rendering
	bool		isOpaque;												// Is the label opaque?
	bool		isBorder;												// Is there a border?
	SBgra		borderColor;											// Border color
	SBgra		selectedBackColor;										// Selected background color
	SBgra		selectedForeColor;										// Selected foreground color
	SBgra		disabledBackColor;										// Disabled background color
	SBgra		disabledForeColor;										// Disabled foreground color

// Image
	SBitmap*	image;													// Image displayed when the mouse IS NOT over this control
	SBitmap*	imageOver;												// Image displayed when the mouse IS over this control

	u32			optionCount;											// How many options are there?
	bool		multiSelect;											// Allow multiple items to be selected?

	f64			minValue;												// Minimum value to display
	f64			maxValue;												// Maximum value to display
	f64			roundTo;												// Round 10=tens place, 1=whole integers, 0.1=one decimal place, 0.01=two decimal places, and so on
};

struct SPropertiesA
{
	SFont*		font;													// Default font instance

	SBitmap*	bmpIcon;											// Icon for the form
	SBitmap*	mouseIcon;												// The mouse icon

	SDatum		name;													// If a user object, this object's name
	SDatum		caption;												// Caption
	SDatum		className;												// The class
	SDatum		classLibrary;											// The class location

	SDatum		comment;
	SDatum		tooltip;
	SDatum		tag;

	SVariable*	value;													// Value for the control
	SVariable*	picture;												// Picture for the control
	SVariable*	mask;													// Input mask for the control

	SEM*		em;													// The content being edited

	SDatum		pictureName;											// The name of the file used for the picture
	SBitmap*	bmpPicture;												// The image for the picture
	SDatum		pictureOverName;										// The name of the file used for the picture when the mouse is over
	SBitmap*	bmpPictureOver;											// The image for the picture when the mouse is over
	SDatum		pictureDownName;										// The name of the file used for the picture when the mouse is pressed down on the item
	SBitmap*	bmpPictureDown;											// The image for the picture when the mouse is pressed down on the item

	SObject*	dataSession;											// Ignored, always set to .NULL..
	SDatum		declass;												// Ignored, always empty.
	SDatum		declasslibrary;											// Ignored, always empty.

	SBitmap*	oleDragPicture;											// Ignored, always set to .NULL..

	SObject*	firstOption;											// Each option has its own set of properties, and each is of _OBJECT_TYPE_LABEL
};

struct SObject
{
	SLL			ll;														// Linked list
	SObject*	parent;													// Pointer to parent object for this instance
	SObject*	firstChild;												// Pointer to child objects (all objects are containers)

	// Object flags
	bool		isRendered;												// Is it rendered (can be rendered even if it's not visible)?
	bool		isPublished;											// Should this control be published?  Every object has a .lockScreen property which allows it to not be published while changes are made.
	bool		isDirtyRender;											// Is set if this or any child object needs re-rendered
	bool		isDirtyPublish;											// Is set if this or any child object needs re-published

	// Defined class, class information
	u32			objType;												// Object base type/class (see _OBJECT_TYPE_* constants)

	// Common properties that are literal(p) and allocated(pa) values
	SProperties		p;													// Common object properties
	SPropertiesA	pa;													// Common object properties allocated

	// Related position in the member hierarchy
	SVariable*	firstProperty;											// Runtime-added user-defined property
	SEM*		firstMethod;											// Runtime-added user-defined methods

	// Events
	SEvents		ev;														// Events for this object


//////////
// Object size in pixels, per the .Left, .Top, .Width, and .Height properties
//////
	RECT		rc;													// Object's current position in its parent
	RECT		rco;												// Object's original position in its parent
	RECT		rcp;												// Original size of parent at creation


//////////
// Drawing canvas
//////
	SBitmap*	bmp;												// If exists, canvas for the content
	SBitmap*	bmpPriorRendered;									// Used for speedups when not isDirty
	// If not scaled:
	s32			scrollOffsetX;										// If the bmp->bi coordinates are larger than its display area, the upper-left X coordinate
	s32			scrollOffsetY;										// ...the upper-left Y coordinate
	// If scaled, updated only during publish():
	bool		isScaled;											// If the bmp->bi coordinates are larger than its display area, should it be scaled?
	SBitmap*	bmpScaled;											// The bmp scaled into RC's size


//////////
// Temporary properties added during development to facilitate display until such time as the full object hierarchy is created for every object.
// Updated each render
//////
	RECT		rcClient;												// The client area of the form
	RECT		rcCaption;												// The caption area (used for moving the form around)
	RECT		rcArrowUl;												// The upper-left resize arrow is
	RECT		rcArrowUr;												// The upper-right resize arrow is
	RECT		rcArrowLl;												// The lower-left resize arrow is
	RECT		rcArrowLr;												// The lower-right resize arrow is
	RECT		rcIcon;													// The form icon
	RECT		rcMove;													// The move button of the form
	RECT		rcMinimize;												// The minimize button of the form
	RECT		rcMaximize;												// The maximize button of the form
	RECT		rcClose;												// The close button of the form
};
