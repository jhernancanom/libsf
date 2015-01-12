//////////
//
// /libsf/source/vjr/source/vjr_structs.h
//
//////
// Version 0.55
// Copyright (c) 2014 by Rick C. Hodgin
//////
// Last update:
//     Feb.12.2014
//////
// Change log:
//     Feb.12.2014 - Initial creation
//////
//
// This document is released as Liberty Software under a Repeat License, as governed
// by the Public Benefit License v1.0 or later (PBL).
//
// The PBL is a public domain license with a caveat:  self accountability unto God.
// You are free to use, copy, modify and share this software for any purpose, however,
// it is the desire of those working on this project that the software remain open.
// It is our request that you maintain it that way.  This is not a legal request unto
// our court systems, but rather a personal matter between you and God.  Our talents
// were received from God, and given to you through this forum.  And it is our wish
// that those talents reach out to as many as possible in a form allowing them to wield
// this content for their own betterment, as you are now considering doing.  And whereas
// we could've forced the issue through something like a copyleft-protected release, the
// truth is we are all giving an account of our lives unto God continually by the daily
// choices we make.  And here again is another case where you get to demonstrate your
// character unto God, and unto your fellow man.
//
// Jesus came to this Earth to set the captives free, to save men's eternal souls from
// the punishment demanded by our sin.  Each one of us is given the opportunity to
// receive Him in this world and be saved.  Whether we choose to receive Him, and follow
// Him, and purpose our lives on the goals He has for each of us (all of which are
// beneficial for all involved), is one way we reveal our character continually.  God
// sees straight through to the heart, bypassing all of the words, all of the facades.
// He is our Creator, and He knows who we are truly.
//
// Jesus is called "Christ" because He saves men from the eternal flames of Hell, the
// just punishment of rebellion against God (rebellion against truth) by eternal beings,
// which each of us are.
//
// Do not let His free gift escape you because of some desire to shortcut what is right
// in your life. Instead, do what is right, and do it because He is who He is, and what
// He has done to save us from such a fate.  Demonstrate to Him, to me, and to all of
// mankind, and to all of the Heavenly hosts, exactly who you are on the inside.  Receive
// Jesus Christ into your heart, learn of Him, of how He came here to guide us into that
// which is of His Kingdom and will be forever hereafter we leave this world.  Do this,
// and live.
//
// Every project released by Liberty Software Foundation will include a copy of the
// pbl.txt document, which can be found at http://www.libsf.org/licenses/.
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




struct SDateTime
{
	u32		julian;														// Julian day number
	f32		seconds;													// Seconds elapsed since midnight
};

struct SFont
{
	bool		isUsed;						// Is this font slot used?
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
		uptr	_onLoad;
		bool	(*onLoad)					(SWindow* win, SObject* obj);							// Called to load anything needed by the init() event (holds a template/skeleton object)
	};
	union {
		uptr	_onInit;
		bool	(*onInit)					(SWindow* win, SObject* obj);							// Called to initialize anything
	};
	union {
		uptr	_onCreated;
		bool	(*onCreated)				(SWindow* win, SObject* obj);							// Called after initialization, before the object is sized
	};
	union {
		uptr	_onResize;
		bool	(*onResize)					(SWindow* win, SObject* obj, u32* widthRequired_out, u32* heightRequired_out);	// Called to size or resize the object
	};
	union {
		uptr	_onMoved;
		bool	(*onMoved)					(SWindow* win, SObject* obj, u32* xOverride_out, u32* yOverride_out);			// Called when the object has been moved
	};
	union {
		uptr	_onRender;
		bool	(*onRender)					(SWindow* win, SObject* obj);							// Called to render to bmp (returns if anything was drawn)
	};
	union {
		uptr	_onPublish;
		bool	(*onPublish)				(SWindow* win, SObject* obj);							// Called to publish the control onto the parent (which will populate bmpScale if need be)
	};
	union {
		uptr	_onQueryUnload;
		bool	(*onQueryUnload)			(SWindow* win, SObject* obj);							// Called before onDestroy, determines if the form should actually be destroyed
	};
	union {
		uptr	_onDestroy;
		bool	(*onDestroy)				(SWindow* win, SObject* obj);							// Called when the object will be destroyed
	};
	union {
		uptr	_onUnload;
		bool	(*onUnload)					(SWindow* win, SObject* obj);							// Called after the object has been destroyed, to unload anything (holds a template/skeleton object)
	};
	union {
		uptr	_onGotFocus;
		bool	(*onGotFocus)				(SWindow* win, SObject* obj);							// Called when the object receives focus (note multiple items can have simultaneous focus)
	};
	union {
		uptr	_onLostFocus;
		bool	(*onLostFocus)				(SWindow* win, SObject* obj);							// Called when the object loses focus
	};
	union {
		uptr	_onAddObject;
		bool	(*onAddObject)				(SWindow* win, SObject* obj);							// Called when an object is added
	};
	union {
		uptr	_onAddProperty;
		bool	(*onAddProperty)			(SWindow* win, SObject* obj);							// Called when a property is added
	};
	union {
		uptr	_onError;
		bool	(*onError)					(SWindow* win, SObject* obj);							// Called when an error is triggered in code on an object
	};
	union {
		uptr	_onScrolled;
		bool	(*onScrolled)				(SWindow* win, SObject* obj);							// Called when an object has been scrolled
	};
	union {
		uptr	_activate;
		bool	(*activate)					(SWindow* win, SObject* obj);							// Called when activated
	};
	union {
		uptr	_deactivate;
		bool	(*deactivate)				(SWindow* win, SObject* obj);							// Called when deactivated
	};
	union {
		uptr	_onSelect;
		bool	(*onSelect)					(SWindow* win, SObject* obj, SObject* oItem);			// When an option is selected
	};
	union {
		uptr	_onDeselect;
		bool	(*onDeselect)				(SWindow* win, SObject* obj, SObject* oItem);			// When an option is deselected
	};
	union {
		uptr	_onInteractiveChange;
		bool	(*onInteractiveChange)		(SWindow* win, SObject* obj);							// Called when the data changes
	};
	union {
		uptr	_onProgrammaticChange;
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
		uptr	_onMouseClickEx;
		bool	(*onMouseClickEx)		(SWindow* win, SObject* obj, s32 x, s32 y, bool tlCtrl, bool tlAlt, bool tlShift, u32 tnClick);	// 1=left, 2=middle, 4=right, 2^n bit positions indicate which buttons are clicked
	};
	union {
		uptr	_onMouseDblClickEx;
		bool	(*onMouseDblClickEx)	(SWindow* win, SObject* obj, s32 x, s32 y, bool tlCtrl, bool tlAlt, bool tlShift, u32 tnClick);	// 1=left, 2=middle, 4=right, 2^n bit positions indicate which buttons are clicked
	};
	union {
		uptr	_onMouseWheel;
		bool	(*onMouseWheel)			(SWindow* win, SObject* obj, s32 x, s32 y, bool tlCtrl, bool tlAlt, bool tlShift, u32 tnClick, s32 tnUnits);			// Signed units indicating direction and velocity
	};
	union {
		uptr	_onMouseMove;
		bool	(*onMouseMove)			(SWindow* win, SObject* obj, s32 x, s32 y, bool tlCtrl, bool tlAlt, bool tlShift, u32 tnClick);	// Coordinates for the move
	};
	union {
		uptr	_onMouseDown;
		bool	(*onMouseDown)			(SWindow* win, SObject* obj, s32 x, s32 y, bool tlCtrl, bool tlAlt, bool tlShift, u32 tnClick);	// Coordinates for where the mouse button changed
	};
	union {
		uptr	_onMouseUp;
		bool	(*onMouseUp)			(SWindow* win, SObject* obj, s32 x, s32 y, bool tlCtrl, bool tlAlt, bool tlShift, u32 tnClick);	// Coordinates for where the mouse button changed
	};
	union {
		uptr	_onMouseEnter;
		bool	(*onMouseEnter)			(SWindow* win, SObject* obj);						// When mouse enters an object
	};
	union {
		uptr	_onMouseLeave;
		bool	(*onMouseLeave)			(SWindow* win, SObject* obj);						// When mouse leaves an object
	};
	union {
		uptr	_onMouseHover;
		bool	(*onMouseHover)			(SWindow* win, SObject* obj, s32 x, s32 y, bool tlCtrl, bool tlAlt, bool tlShift, u32 tnClick);	// Coordinates where hovering
	};
};

struct SEventsKeyboard
{
	// Keyboard callbacks
	// Bool indicates if the event should be sent to its parent instead
	union {
		uptr	_onKeyDown;
		bool	(*onKeyDown)		(SWindow* win, SObject* obj, bool tlCtrl, bool tlAlt, bool tlShift, bool tlCaps, s16 tnAsciiChar, u16 tnVKey, bool tlIsCAS, bool tlIsAscii);
	};
	union {
		uptr	_onKeyUp;
		bool	(*onKeyUp)			(SWindow* win, SObject* obj, bool tlCtrl, bool tlAlt, bool tlShift, bool tlCaps, s16 tnAsciiChar, u16 tnVKey, bool tlIsCAS, bool tlIsAscii);
	};
};

struct SEvents
{
	SEventsGeneral		general;									// General object events
	SEventsMouse		mouse;										// Mouse events for the object
	SEventsKeyboard		keyboard;									// Keyboard events for the object
};

struct SProperties
{
	RECT		rcMax;												// The maximum rectangle for the form
	RECT		rcMin;												// The minimum rectangle for the form

	bool		hasFocus;											// Does this object have focus?
 	bool		processKeyPreviewEvents;							// Do keystrokes for controls on the form go through the form's Key* events as well?

	SEM*		sem;												// The content being edited
	SFont*		font;												// Default font instance
};

struct SObjNodeData
{
	SObject*	obj;												// If the node was created so that A was linked to B, A is primary
	SBgra		color;												// Color for the node ball
	SDatum		label;												// An optional bit of text for the node hookup
};

// Nodes run from something to something else...
struct SObjNode
{
	// Link lists along from and to chains
	SLL				from_ll;										// Node link in the from chain
	SLL				to_ll;											// Node link in the to chain

	// From configuration
	SObjNodeData	from;											// The data for this node
	bool			from_isEast;									// Does the from node originate easterly?
	s32				from_slotNum;									// The node slot number for the from
	s32				from_maxTextLength;								// Maximum text length along this from_ll chain

	// To configuration
	SObjNodeData	to;												// ...and this is the to. :-)
	bool			to_isWest;										// Does the to terminate from the west?
	s32				to_slotNum;										// The node slot number for the to
	s32				to_maxTextLength;								// Maximum text length along this to_ll chain
};

struct SObject
{
	SLL			ll;													// Linked list
	SObject*	parent;												// Pointer to parent object for this instance
	SObject*	firstChild;											// Pointer to child objects (all objects are containers)

	// Defined class, class information
	s32			objType;											// Object base type/class (see _OBJECT_TYPE_* constants)

	// Object flags
	bool		isRendered;											// Is it rendered (can be rendered even if it's not visible)?
	bool		isPublished;										// Should this control be published?  Every object has a .lockScreen property which allows it to not be published while changes are made.
	bool		isDirtyRender;										// Is set if this or any child object needs re-rendered
	bool		isDirtyPublish;										// Is set if this or any child object needs re-published


	//////////
	// Object size in pixels, per the .Left, .Top, .Width, and .Height properties
	//////
		RECT		rc;												// Object's current position in its parent
		RECT		rco;											// Object's original position in its parent
		RECT		rcp;											// Original size of parent at creation
		RECT		rcClient;										// Client portion within the size of the object


	//////////
	// Common properties that are literal(p) and allocated(pa) values
	//////
		SProperties		p;											// Common object properties
		SVariable**		props;										// An allocated array of properties (varies in size by object)
		u32				propsCount;									// The number of property variables allocated

		// Related position in the member hierarchy
		SVariable*	firstProperty;									// User-defined property (design time and runtime)
		SEM*		firstMethod;									// User-defined methods (design time and runtime)

		// Related access and assign methods
		bool		anyPropertyHasAccessOrAssignMethods;
		SEM*		firstAccess;									// User-defined property access methods (design time and runtime)
		SEM*		firstAssign;									// User-defined property assignment methods (designt ime and runtime)

		// Events
		SEvents		ev;												// Events for this object


	//////////
	// Base drawing canvas
	//////
		SBitmap*	bmp;											// If exists, canvas for the content
		SBitmap*	bmpPriorRendered;								// Used for speedups when not isDirty
		SBmpCache*	bc;												// For certain compute intensive operations (color gradient controls), the bitmap is only drawn/computed once and then copied thereafter, unless any of eight data points change
		// If not scaled:
		s32			scrollOffsetX;									// If the bmp->bi coordinates are larger than its display area, the upper-left X coordinate
		s32			scrollOffsetY;									// ...the upper-left Y coordinate
		// If scaled, updated only during publish():
		bool		isScaled;										// If the bmp->bi coordinates are larger than its display area, should it be scaled?
		SBitmap*	bmpScaled;										// The bmp scaled into RC's size


#ifdef _GRACE_OGL
	//////////
	// OpenGL
	//////
		// Visualization
		SGraceOgl	ogl;											// Open GL coordinates

		// Nodes connect to this object on the left or top
		SObjNode*	toLeft;											// First node in the west direction
		SObjNode*	toTop;											// First node in the east direction

		// This node connects to other things from the right or bottom
		SObjNode*	fromRight;										// First node in the north direction
		SObjNode*	fromBottom;										// First node in the south direction
#endif
};

struct SFocusHighlight
{
	bool		isValid;											// Is this item valid?

	SWindow*	win;												// The window this focus highlight entry relates to
	SObject*	obj;												// The object being focused

	HWND		hwnd;												// The HWND for this window
	HRGN		hrgn;												// Handle to the clip region
	HBRUSH		readWriteBrush;										// Read-write color, bluish
	HBRUSH		readOnlyBrush;										// Read-only color, reddish

	RECT		rc;													// In screen coordinates
};

struct STooltip
{
	bool		isValid;											// Is this item valid?

	SObject*	obj;												// The object owning the tip
	s32			timeoutMs;											// Tooltips have a lifetime... in milliseconds

	bool		allowMove;											// Can the tooltip be moved?
	bool		allowSticky;										// Can they pin the tooltip so it doesn't expire?

	HWND		hwnd;												// The HWND for this window
	RECT		rc;													// In screen coordinates
	SBitmap*	bmp;												// The rendered bitmap for the tooltip
};

struct SSplash
{
	bool		isValid;											// Is the splash screen active/displayed?

	HWND		hwnd;												// The HWND to the splash screen
	RECT		rc;													// In screen coordinates
	SBitmap*	bmp;												// The rendered bitmap
};
