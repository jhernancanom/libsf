//////////
//
// /libsf/source/vjr/vjr_structs0.h
//
//////
// Version 0.54
// Copyright (c) 2014 by Rick C. Hodgin
//////
// Last update:
//     Jun.29.2014
//////
// Change log:
//     Jun.29.2014 - Initial creation
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




// Forward definition for references
struct SObject;
struct SVariable;
struct SEM;
struct SLine;
struct SComp;
struct SCompiler;
struct SFunction;
struct SObjPropertyMap;




struct SBgr
{
	u8	blu;
	u8	grn;
	u8	red;
};

struct SBgra
{
	union {
		u32		color;
		struct {
			u8	blu;
			u8	grn;
			u8	red;
			u8	alp;
		};
	};
};


struct SBgraf
{
	f32		blu;				// 24-bit RGB values in bitmap files are physically stored as BGR
	f32		grn;
	f32		red;
	f32		alp;				// For 32-bit bitmaps

	f32		area;				// Holds area
};

struct SBitmap
{
	// Device context and bitmap handle to this data
	HDC					hdc;
	HBITMAP				hbmp;

	// Raw bitmap data (suitable for writing to disk)
	BITMAPFILEHEADER	bh;
	BITMAPINFOHEADER	bi;
	s8*					bd;
	u32					rowWidth;
};

struct SBmpCache
{
	SBitmap*		bmpCached;
	u32				data1;
	u32				data2;
	u32				data3;
	u32				data4;
	u32				data5;
	u32				data6;
	u32				data7;
	u32				data8;
	u32				data9;
};


// For processing the scaling of bitmaps
struct SBitmapProcess
{
	// Holds the source canvas
	SBitmap*			src;

	// Holds storage data for single spanned pixels
	u32					red;
	u32					grn;
	u32					blu;
	u32					alp;

	// tpoints is a buffer created to store the conversion pixel data during accumulation.
	// Use formula:
	//		tpoints	= (SRGBAF*)malloc(		((u32)(1.0/ratioV) + 3)   *
	//										((u32)(1.0/ratioH) + 3))
	//
	f32					ratioV;				// (f32)bio->biHeight	/ (f32)bii->biHeight;
	f32					ratioH;				// (f32)bio->biWidth	/ (f32)bii->biWidth;
	u32					count;				// Number of valid points in tpoints
	SBgraf*				pixels;				// Accumulation buffer for point data needed to feed into destination

	// Temporary variables used for processing
	union {
		SBgra*			optra;				// (For 32-bit bitmaps) Output pointer to the upper-left pixel for this x,y
		SBgr*			optr;				// (For 24-bit bitmaps) Output pointer to the upper-left pixel for this x,y
	};
	union {
		SBgra*			iptrAnchora;		// (For 32-bit bitmaps) Input pointer to the left-most pixel of the first row (the anchor)
		SBgr*			iptrAnchor;			// (For 24-bit bitmaps) Input pointer to the left-most pixel of the first row (the anchor)
	};
	union {
		SBgra*			iptra;				// (For 32-bit bitmaps) Input pointer to the left-most pixel for this y row
		SBgr*			iptr;				// (For 24-bit bitmaps) Input pointer to the left-most pixel for this y row
	};
	f32					ulx;				// Upper-left X
	f32					uly;				// Upper-left Y
	f32					lrx;				// Lower-right X
	f32					lry;				// Lower-right Y
	f32					widthLeft;			// Width for each left-most pixel
	f32					widthRight;			// Width for each right-most pixel
	f32					height;				// Height for a particular pixel portion (upper, lower)
	f32					area;				// Temporary computed area for various pixels
	s32					left;				// Left-side pixel offset into line
	s32					right;				// Number of pixels to reach the right-most pixel
	s32					middleStartH;		// Starting pixel offset for middle span
	s32					middleFinishH;		// Ending pixel offset for middle span
	s32					middleStartV;		// Middle starting pixel
	s32					middleFinishV;		// Middle ending pixel

	// Indicates the span from upper-left corner
	bool				spans2H;			// Spans at least 2 pixels horizontally, meaning it begins somewhere in 1.x, for example, and ends somewhere beyond 2.x
	bool				spans3H;			// Spans at least 3 pixels horizontally, meaning it begins somewhere in 1.x, for example, and ends somewhere beyond 3.x
	bool				spans2V;			// Spans at least 2 pixels vertically, meaning it begins somewhere in 1.x, for example, and ends somewhere beyond 2.x
	bool				spans3V;			// Spans at least 3 pixels vertically, meaning it begins somewhere in 1.x, for example, and ends somewhere beyond 3.x
};

struct SSize
{
	union {
		s32		width;
		f32		fWidth;
	};
	union {
		s32		height;
		f32		fHeight;
	};
};

struct SRect
{
	s32			left;
	s32			top;
	s32			right;
	s32			bottom;
};

struct SXYS32
{
	s32			x;
	s32			y;
};

struct SWindow
{
	bool				isValid;										// When windows fall out of scope they are marked not valid

	HWND				hwnd;											// The window's hwnd
	SBitmap*			bmp;											// Accumulation buffer for drawing
	RECT				rc;												// Rectangle of window's physical position
	SObject*			obj;											// The top-level object being rendered in this window

	// Mouse data
	POINT				mousePosition;									// Mouse position in this window
	s32					mouseWheelDelta;								// How far the vertical mouse wheel has scrolled
	s32					mouseHWheelDelta;								// How far the horizontal mouse wheel has scrolled
	bool				isMouseLeftButton;								// Is the left mouse button down?
	bool				isMouseMiddleButton;							// Is the middle mouse button down?
	bool				isMouseRightButton;								// Is the right mouse button down?
	bool				isCaps;											// Is caps lock on?
	bool				isCtrl;											// Is the control key down?
	bool				isAlt;											// Is the alt key down?
	bool				isShift;										// Is the shift key down?

	// For manual movement
	bool				isMoving;										// Is this window moving?
	bool				isResizing;										// Is this window resizing?
	u32					resizingFrom;									// If resizing, the arrow (upper-left, upper-right, lower-left, lower-right)

	// Updated as the mouse moves across the form
	POINT				mousePositionClick;								// When the mouse was last left-clicked, this is where it was clicked
	POINT				mousePositionClickScreen;						// In screen coordinates, the location where the mouse was last left-button clicked down

	CRITICAL_SECTION	cs;												// Atomic access
};

struct SDatum
{
	union {
		s8*			data;												// Content
		s8*			data_s8;											// To access the data as s8
		u8*			data_u8;											// To access the data as u8
		u64*		data_u64;											// To access the data as u64
		s64*		data_s64;											// To access the data as s64
		u32*		data_u32;											// To access the data as u32
		s32*		data_s32;											// To access the data as s32
		u16*		data_u16;											// To access the data as u16
		s16*		data_s16;											// To access the data as s16
		f32*		data_f32;											// To access the data as f32
		f64*		data_f64;											// To access the data as f64
		s8*			data_cs8;											// To access the data as cs8
		s8*			data_cu8;											// To access the data as cu8
		SBgra*		data_bgra;											// to access the data as SBgra
		SBgra*		data_bgr;											// to access the data as SBgr
	};
	s32				length;												// Content length
};

struct STranslate
{
	void*		p1;														// Pointer 1
	void*		p2;														// Pointer 2
};

// struct STranslateExtra
// {
// 	void*		p1;														// Pointer 1
// 	void*		p2;														// Pointer 2
// 
// 	// Extra information
// 	union {
// 		struct {
// 			u8		u8Data1;
// 			u8		u8Data2;
// 			u8		u8Data3;
// 			u8		u8Data4;
// 		};
// 		struct {
// 			s8		s8Data1;
// 			s8		s8Data2;
// 			s8		s8Data3;
// 			s8		s8Data4;
// 		};
// 		struct {
// 			u16		u16Data1;
// 			u16		u16Data2;
// 		};
// 		struct {
// 			s16		s16Data1;
// 			s16		s16Data2;
// 		};
// 		u32		u32Data;
// 		s32		s32Data;
// 		bool	used;
// 		void*	extra;
// 	};
// };

struct SVariable
{
	SLL			ll;
	SVariable*	indirect;												// If non-NULL, and not an object or thisCode, this variable is an indirect reference to an underlying variable.
	bool		isVarAllocated;											// If true, this variable structure was allocated, and needs to be released upon delete.

	// Variable data
	SDatum		name;													// Name of this variable (alway allocated)
	u32			arrayRows;												// If created as an array, how many rows
	u32			arrayCols;												// If created as an array, how many columns

	// Variable content based on type
	u32			varType;												// Variable type (see _VAR_TYPE_* constants)
	bool		isValueAllocated;										// If true, the data pointed to by this->value.data, or this->obj, or this->bmp, or this->thisCode was allocated
	union {
		SObject*		obj;											// The object this item relates to.  If isValueAllocated is set, this variable owns the object.
		SFunction*		thisCode;										// Pointer to the code block this relates to
		SBitmap*		bmp;											// The bitmap this item points to
		SDatum			value;											// The actual value
	};

	// If this variable is related to a component, indicate it here
	SComp*		compRelated;											// Can vary regularly, but when available at compile time and in immediate scope, relates to a component

	// If assign or access
	SEM*		firstAccess;											// Source code executed whenever this variable is accessed
	SEM*		firstAssign;											// Source code executed whenever this variable is assigned
};

struct SBaseclassList
{
	s32				objType;											// Translation between objType...

	// Class name
	cs8*			baseclassName;										// ...and the text-based name of the base class
	s32				baseclassNameLength;

	union {
		u32				_objProps;
		SObjPropertyMap*	objProps;									// Root property map for this object
	};
};

struct SAsciiCompSearcher
{
	cs8*		keyword;												// Text keyword being searched
	s32			length;													// Length of the keyword (negative for case sensitive, positive case insensitive, 0 for termination entry)
	bool		repeats;												// Can this item repeat?  Or is this a one-shot keyword?
	s32			iCode;													// An associated code to store when this entry is found
	bool		firstOnLine;											// Should this item ONLY be the first on line?
	s32			iCat;													// This entry's general category (function, operator, keyword, flow)

	// For syntax highlighting
	SBgra*		syntaxHighlightColor;									// Color to display this component in
	bool		useBoldFont;											// Should this be bolded?

	// An optional extra callback to parse on finds
	union {
		u32		_onFind;
		void	(*onFind)(SAsciiCompSearcher* tacs, SComp* comp);
	};
};

struct SCompiler;
struct SBreakpoint;
struct SExtraInfo;

struct SLine
{
	SLL				ll;												// Link list throughout
	u32				uid;											// Unique id for this line, used for undos and identifying individual lines which may move about (note this value must be isolated and separate from ll.uniqueId)

	// Line information
	u32				lineNumber;										// This line's number
	bool			isNewLine;										// If the line's been added during normal editing
	SDatum*			sourceCodeOriginal;								// The original sourceCode when the line was first created, or last saved (note the length here is the total length as this value does not change, but is setup exactly when it is updated)
	SDatum*			sourceCode;										// The text on this line is LEFT(sourceCode.data, sourceCodePopulated)
	s32				sourceCode_populatedLength;						// The actual populated length of sourceCode, which may differ from sourceCode.length (which is the allocated length fo sourceCode.data)

	// Each render, these are updated
	u32				renderId;										// Each time it's rendered, this value is set
	RECT			rcLastRender;									// The rectangle within the parent of the last render

	// Compiler information (see compiler.cpp)
	bool			forceRecompile;									// A flag that if set forces a recompile of this line
	SCompiler*		compilerInfo;									// Information about the last time this line was compiled
	SCompiler*		compilerInfoLast;								// Used during edit-and-continue compilation

	// General purpose extra data
	SBreakpoint*	breakpoint;										// If there's a breakpoint here, what kind?
	SExtraInfo*		extra_info;										// Extra information about this item in the chain
};

// Structure of parsed components on a line, tokens by another name
struct SComp
{
	SLL				ll;												// 2-way link list

	// Information about the component
	SLine*			line;											// The line this component relates to
	s32				iCode;											// Refer to _ICODE_* constants
	s32				iCat;											// Refer to _ICAT_* constants
	SBgra*			color;											// Syntax highlight color
	bool			useBoldFont;									// Syntax highlight font should be bold?
	s32				start;											// Start into the indicates line's source code
	s32				length;											// Length of the component
	s32				nbspCount;										// Number of non-breaking-spaces in this component

	// For each compilation pass, components can be marked in error or warning or both
	bool			isError;										// Is this component part of an error?
	bool			isWarning;										// Is this component part of a warning?

	// For selected components
	SBgra*			overrideSelectionBackColor;
	SBgra*			overrideSelectionForeColor;

	// If this is a character that matches something (the closest parenthesis, bracket, or brace) then this color will be populated
	SBgra*			overrideMatchingForeColor;
	SBgra*			overrideMatchingBackColor;

	// For faster rendering in source code windows
	SBmpCache*		bc;												// Holds drawn things (casks for example)
};
