//////////
//
// /libsf/source/vjr/vjr_const.h
//
//////
// Version 0.53
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




struct SVariable;
struct SObject;
struct SEM;


// Unsigned
#if !defined(_MSC_VER)
	// gcc
	typedef unsigned long long	u64;
	typedef unsigned			u32;
	typedef unsigned short		u16;
	typedef unsigned char		u8;

	typedef long long			s64;
	typedef int					s32;
	typedef short				s16;
	typedef char				s8;

#else
	typedef	unsigned __int64	u64;
	typedef	unsigned long		u32;
	typedef	unsigned short		u16;
	typedef	unsigned char		u8;

	// Signed
	typedef	__int64				s64;
	typedef	long				s32;
	typedef	short				s16;
	typedef	char				s8;
#endif

// Floating point
typedef		float				f32;
typedef		double				f64;

// Constant signed
typedef		const s8			cs8;
typedef		const s16			cs16;
typedef		const s32			cs32;
typedef		const s64			cs64;

// Constant unsigned
typedef		const u8			cu8;
typedef		const u16			cu16;
typedef		const u32			cu32;
typedef		const u64			cu64;

// Constant floating point
typedef		const f64			cf64;
typedef		const f64			cf64;


// Used for passing complex parameters as references, such as SObjectpp&, or SEMpp&
typedef SObject**	SObjectpp;
typedef SEM**		SEMpp;


//////////
// Union helper
//////
	#define _union(x, y, z) union { x z; y _ ## z; };


//////////
// Macro helpers
//////
	#define iVariable_isValid(var)					(var && (var->varType == _VAR_TYPE_CHARACTER/*0-length character variables do not have allocated buffers*/ || (var->value.data && var->value.length != 0)))
	#define iVariable_getType(var)					var->varType
	#define iVariable_isTypeObject(var)				(var->varType == _VAR_TYPE_OBJECT)
	#define iVariable_isTypethisCode(var)			(var->varType == _VAR_TYPE_THISCODE)
	#define iVariable_isTypeLogical(var)			(var->varType == _VAR_TYPE_LOGICAL)
	#define iVariable_isTypeCharacter(var)			(var->varType == _VAR_TYPE_CHARACTER)
	#define iVariable_isTypeNumeric(var)			(var->varType >= _VAR_TYPE_NUMERIC_START && var->varType <= _VAR_TYPE_NUMERIC_END)
	#define iVariable_isNumeric64Bit(var)			(var->varType == _VAR_TYPE_S64 || var->varType == _VAR_TYPE_U64 || var->varType == _VAR_TYPE_CURRENCY)
	#define iVariable_isTypeDate(var)				(var->varType == _VAR_TYPE_DATE)
	#define iVariable_isTypeDatetime(var)			(var->varType == _VAR_TYPE_DATETIME)
	#define iVariable_isTypeBig(var)				(var->varType == _VAR_TYPE_BI || var->varType == _VAR_TYPE_BFP)
	#define iVariable_isTypeFloatingPoint(var)		(var->varType == _VAR_TYPE_F32 || var->varType == _VAR_TYPE_F64)
	#define iVariable_isTypeFloat(var)				(var->varType == _VAR_TYPE_F32)
	#define iVariable_isTypeDouble(var)				(var->varType == _VAR_TYPE_F64)
	#define iVariable_isTypeCurrency(var)			(var->varType == _VAR_TYPE_CURRENCY)
	#define iVariable_isTypeBigInteger(var)			(var->varType == _VAR_TYPE_BI)
	#define iVariable_isTypeBigFloatingPoint(var)	(var->varType == _VAR_TYPE_BFP)

	#define isVisible(obj)							(iObjProp_get_logical_direct(obj, _INDEX_VISIBLE)  != _LOGICAL_FALSE)
	#define isEnabled(obj)							(iObjProp_get_logical_direct(obj, _INDEX_ENABLED)  != _LOGICAL_FALSE)
	#define isReadonly(obj)							(iObjProp_get_logical_direct(obj, _INDEX_READONLY) != _LOGICAL_FALSE)
	#define isName(obj, text)						(iObjProp_compare_character(obj, _INDEX_NAME, (s8*)text, sizeof(text) - 1) == 0)

	#define backStyle(obj)							iObjProp_get_s32_direct(obj, _INDEX_BACKSTYLE)
	#define borderStyle(obj)						iObjProp_get_s32_direct(obj, _INDEX_BORDERSTYLE)
	#define borderColor(obj)						iObjProp_get_sbgra_direct(obj, _INDEX_BORDERCOLOR)
	#define foreColor(obj)							iObjProp_get_sbgra_direct(obj, _INDEX_FORECOLOR)
	#define backColor(obj)							iObjProp_get_sbgra_direct(obj, _INDEX_BACKCOLOR)
	#define nwRgba(obj)								iObjProp_get_sbgra_direct(obj, _INDEX_NWCOLOR)
	#define neRgba(obj)								iObjProp_get_sbgra_direct(obj, _INDEX_NECOLOR)
	#define swRgba(obj)								iObjProp_get_sbgra_direct(obj, _INDEX_SWCOLOR)
	#define seRgba(obj)								iObjProp_get_sbgra_direct(obj, _INDEX_SECOLOR)
	#define alignment(obj)							iObjProp_get_s32_direct(obj, _INDEX_ALIGNMENT)

	#define setValue_s32(obj, value)				iObjProp_set_s32_direct(obj, _INDEX_VALUE, value)
	#define setValue_f64(obj, value)				iObjProp_set_f64_direct(obj, _INDEX_VALUE, value)
	#define setValueMinimum(obj, value)				iObjProp_set_f64_direct(obj, _INDEX_VALUE_MINIMUM, value)
	#define setValueMaximum(obj, value)				iObjProp_set_f64_direct(obj, _INDEX_VALUE_MAXIMUM, value)
	#define setValueRoundTo(obj, value)				iObjProp_set_f64_direct(obj, _INDEX_ROUND_TO, value)

	#define setBackColor(obj, color)				iObjProp_set_sbgra_direct(obj, _INDEX_BACKCOLOR, color)
	#define setForeColor(obj, color)				iObjProp_set_sbgra_direct(obj, _INDEX_FORECOLOR, color)
	#define setBorderColor(obj, color)				iObjProp_set_sbgra_direct(obj, _INDEX_BORDERCOLOR, color)
	#define setDisabledBackColor(obj, color)		iObjProp_set_sbgra_direct(obj, _INDEX_DISABLEDBACKCOLOR, color)
	#define setDisabledForeColor(obj, color)		iObjProp_set_sbgra_direct(obj, _INDEX_DISABLEDFORECOLOR, color)
	#define setSelectedBackColor(obj, color)		iObjProp_set_sbgra_direct(obj, _INDEX_SELECTEDBACKCOLOR, color);
	#define setSelectedForeColor(obj, color)		iObjProp_set_sbgra_direct(obj, _INDEX_SELECTEDFORECOLOR, color);

	#define setAnchor(obj, value)					iObjProp_set_s32_direct(obj, _INDEX_ANCHOR, value)
	#define setIcon(obj, bmp)						iObjProp_set_bitmap_direct(obj, _INDEX_ICON, bmp)
	#define setVisible(obj, value)					iObjProp_set_logical_direct(obj, _INDEX_VISIBLE, value)
	#define setEnabled(obj, value)					iObjProp_set_logical_direct(obj, _INDEX_ENABLED, value);
	#define setAlignment(obj, value)				iObjProp_set_s32_direct(obj, _INDEX_ALIGNMENT, value)
	#define setStyle(obj, value)					iObjProp_set_s32_direct(obj, _INDEX_STYLE, value)
	#define setBackStyle(obj, value)				iObjProp_set_s32_direct(obj, _INDEX_BACKSTYLE, value)
	#define setBorderStyle(obj, value)				iObjProp_set_s32_direct(obj, _INDEX_BORDERSTYLE, value)
	#define setCaption(obj, value)					iObjProp_set_character_direct(obj, _INDEX_CAPTION, (s8*)value, sizeof(value) - 1)
	#define setCount(obj, value)					iObjProp_set_s32_direct(obj, _INDEX_COUNT, value)
	#define setMultiSelect(obj, value)				iObjProp_set_logical_direct(obj, _INDEX_MULTISELECT, value)
	#define setPictureBmp(obj, bmp)					iObjProp_set_bitmap_direct(obj, _INDEX_PICTUREBMP, bmp)
	#define setPictureBmpDown(obj, bmp)				iObjProp_set_bitmap_direct(obj, _INDEX_PICTUREBMP_DOWN, bmp)
	#define setPictureBmpOver(obj, bmp)				iObjProp_set_bitmap_direct(obj, _INDEX_PICTUREBMP_OVER, bmp)


//////////
// Red,Grn,Blu,Alp color maker
//////
	#define rgba(r,g,b,a)					((a & 0xff) << 24) + \
											((r & 0xff) << 16) + \
											((g & 0xff) <<  8) + \
											((b & 0xff))

	#define rgb(r,g,b)						(0xff       << 24) + \
											((r & 0xff) << 16) + \
											((g & 0xff) <<  8) + \
											((b & 0xff))

	#define bgra(b,g,r,a)					((a & 0xff) << 24) + \
											((b & 0xff) << 16) + \
											((g & 0xff) <<  8) + \
											((r & 0xff))

	#define bgr(b,g,r)						(0xff       << 24) + \
											((b & 0xff) << 16) + \
											((g & 0xff) <<  8) + \
											((r & 0xff))

	#define alp(rgbaColor)					((rgbaColor >> 24) & 0xff)
	#define red(rgbaColor)					((rgbaColor >> 16) & 0xff)
	#define grn(rgbaColor)					((rgbaColor >> 8)  & 0xff)
	#define blu(rgbaColor)					( rgbaColor        & 0xff)

	#define _disabledBackColor				rgba(255, 255, 255, 255)
	#define _disabledForeColor				rgba(192, 192, 230, 255)
	#define _whiteColor						rgba(255, 255, 255, 255)
	#define _grayColor						rgba(192, 192, 192, 255)
	#define _blackColor						rgba(0, 0, 0, 255)
	#define _selectedBackColor				rgba(220, 235, 255, 255)
	#define _selectedForeColor				rgba(0, 0, 164, 255)
	#define _nwColor						rgba(230, 230, 255, 255)
	#define _neColor						rgba(192, 212, 255, 255)
	#define _swColor						rgba(212, 212, 255, 255)
	#define _seColor						rgba(172, 192, 235, 255)

#if !defined(_MSC_VER)
	// gcc
	#define debug_break						asm("int $3")
#else
	// visual studio
	#define debug_break						_asm int 3
#endif


// Definitions missing in MinGW
#if !defined(_MSC_VER)
	// gcc
	#define WM_MOUSEHWHEEL                  0x020E
	#define CLEARTYPE_NATURAL_QUALITY       6
#endif


//////////
// Reference datetimes
//////
	SVariable*			_datetime_Jan_01_2000				= NULL;


//////////
// Min/max constants
//////
	const s8			_s8_min								= (s8)-128;
	const s8			_s8_max								= 127;
	const u8			_u8_max								= 255;
	const s16			_s16_min							= (s16)-32768;
	const s16			_s16_max							= 32767;
	const u16			_u16_max							= 65535;
	const s32			_s32_min							= 0xffffffff;
	const s32			_s32_max							= 0x7fffffff;
	const u32			_u32_max							= 0xffffffff;
	const s64			_s64_min							= 0xffffffffffffffff;
	const s64			_s64_max							= 0x7fffffffffffffff;
	const u64			_u64_max							= 0xffffffffffffffff;
	const f32			_f32_min							= 3.402823466e+38f;
	const f32			_f32_max							= 1.175494351e-38f;
	const f64			_f64_min							= 2.22507385850720138e-308;
	const f64			_f64_max							= 1.79769313486231571e+308;


//////////
// System constants
//////
	const s32			_MENU_BAR_HEIGHT					= 16;						// Each menu is 16 pixels high
	const s32			_SOURCELIGHT_MARGIN					= 8;


//////////
// Object types
//////
	// Note:  This starting value of 1 is important.  It is used in at least iiObj_getBaseclass_byType() and related functions.
	const u32			_OBJ_TYPE_EMPTY						= 1;						// Empty, used as a placeholder object that is not drawn
	const u32			_OBJ_TYPE_FORM						= 2;						// Form class, the main outer window the OS sees
	const u32			_OBJ_TYPE_SUBFORM					= 3;						// A new class which has its own drawing content and can be moved about using UI features
	const u32			_OBJ_TYPE_CAROUSEL					= 4;						// A carousel is a holder for riders
	const u32			_OBJ_TYPE_RIDER						= 5;						// A rider holds a form or subform and sizes it based on user interaction within its carousel
	const u32			_OBJ_TYPE_LABEL						= 6;						// A label
	const u32			_OBJ_TYPE_TEXTBOX					= 7;						// An input textbox
	const u32			_OBJ_TYPE_BUTTON					= 8;						// A push button
	const u32			_OBJ_TYPE_EDITBOX					= 9;						// An input multi-line editbox
	const u32			_OBJ_TYPE_IMAGE						= 10;						// A graphical image
	const u32			_OBJ_TYPE_CHECKBOX					= 11;						// A checkbox
	const u32			_OBJ_TYPE_OPTION					= 12;						// A combination selection
	const u32			_OBJ_TYPE_RADIO						= 13;						// A radio dial, which can also present as a slider or spinner
	const u32			_OBJ_TYPE_CMDGROUP					= 14;						// A command button group
	const u32			_OBJ_TYPE_OPTGROUP					= 15;						// An option group
	const u32			_OBJ_TYPE_LISTBOX					= 16;						// A listbox
	const u32			_OBJ_TYPE_COMBOBOX					= 17;						// A combobox
	const u32			_OBJ_TYPE_FORMSET					= 18;						// A formset
	const u32			_OBJ_TYPE_TOOLBAR					= 19;						// A toolbar
	const u32			_OBJ_TYPE_SEPARATOR					= 20;						// A separator
	const u32			_OBJ_TYPE_LINE						= 21;						// A line
	const u32			_OBJ_TYPE_SHAPE						= 22;						// A shape
	const u32			_OBJ_TYPE_CONTAINER					= 23;						// A container
	const u32			_OBJ_TYPE_CONTROL					= 24;						// A blocking container
	const u32			_OBJ_TYPE_GRID						= 25;						// A grid
	const u32			_OBJ_TYPE_COLUMN					= 26;						// A grid's column object
	const u32			_OBJ_TYPE_HEADER					= 27;						// A grid's header object
	const u32			_OBJ_TYPE_OLEBOUND					= 28;						// A bound OLE object
	const u32			_OBJ_TYPE_OLECONTAIN				= 29;						// An OLE container control object
	const u32			_OBJ_TYPE_SPINNER					= 30;						// A spinner
	const u32			_OBJ_TYPE_TIMER						= 31;						// A timer
	const u32			_OBJ_TYPE_HYPERLINK					= 32;						// A hyperlink
	const u32			_OBJ_TYPE_COLLECTION				= 33;						// A collection
	const u32			_OBJ_TYPE_PAGE						= 34;						// A page within a pageframe
	const u32			_OBJ_TYPE_PAGEFRAME					= 35;						// A pageframe
	const u32			_OBJ_TYPE_SESSION					= 36;						// A session
	const u32			_OBJ_TYPE_CUSTOM					= 37;						// A custom class
	const u32			_OBJ_TYPE_EXCEPTION					= 38;						// An exception

//////////
// A shortcut timesaver offered out of the goodness of my heart. :-)
// 	switch (obj->objType)
// 	{
// 		case _OBJ_TYPE_EMPTY:
// 			break;
// 		case _OBJ_TYPE_FORM:
// 			break;
// 		case _OBJ_TYPE_SUBFORM:
// 			break;
// 		case _OBJ_TYPE_CAROUSEL:
// 			break;
// 		case _OBJ_TYPE_RIDER:
// 			break;
// 		case _OBJ_TYPE_LABEL:
// 			break;
// 		case _OBJ_TYPE_TEXTBOX:
// 			break;
// 		case _OBJ_TYPE_BUTTON:
// 			break;
// 		case _OBJ_TYPE_EDITBOX:
// 			break;
// 		case _OBJ_TYPE_IMAGE:
// 			break;
// 		case _OBJ_TYPE_CHECKBOX:
// 			break;
// 		case _OBJ_TYPE_OPTION:
// 			break;
// 		case _OBJ_TYPE_RADIO:
// 			break;
// 	}
//////


//////////
// Image styles
//////
	const u32			_IMAGE_STYLE_OPAQUE					= 0;
	const u32			_IMAGE_STYLE_TRANSPARENT			= 1;


//////////
// Option styles
//////
	const u32			_STYLE_PLAIN						= 0;
	const u32			_STYLE_2D							= 1;
	const u32			_STYLE_3D							= 2;


//////////
// Alignment modes
//////
	const u32			_ALIGNMENT_LEFT						= 0;
	const u32			_ALIGNMENT_RIGHT					= 1;
	const u32			_ALIGNMENT_CENTER					= 2;


//////////
// Border styles
//////
	const u32			_BORDER_STYLE_NONE					= 0;						// No border, not sizable
	const u32			_BORDER_STYLE_OUTLINE				= 1;						// Outline border, not sizable
	const u32			_BORDER_STYLE_FIXED					= 2;						// Normal border, not sizable
	const u32			_BORDER_STYLE_SIZABLE				= 3;						// Normal border, sizable


//////////
// Back styles
//////
	const u32			_BACK_STYLE_TRANSPARENT				= 0;						// Transparent styles
	const u32			_BACK_STYLE_OPAQUE					= 1;						// Opaque styles


//////////
// Form scale mode
//////
	const u32			_SCALE_MODE_FOXELS					= 0;						// Foxels, based on sysmetrics() average font width and height
	//const u32			_SCALE_MODE_INCHES					= 1;						// Inches, based on correlating inches to default dpi
	const u32			_SCALE_MODE_PIXELS					= 3;						// Pixels, based on individual pixels


//////////
// Fill style
//////
	const u32			_FILL_STYLE_SOLID					= 0;						// Solid fill
	const u32			_FILL_STYLE_TRANSPARENT				= 1;						// Transparent (no fill)
	const u32			_FILL_STYLE_HORIZONTAL				= 2;						// Horizontal lines
	const u32			_FILL_STYLE_VERTICAL				= 3;						// Vertical lines
	const u32			_FILL_STYLE_UL2LR_DIAGONAL			= 4;						// Upper-left to lower-right diagonal
	const u32			_FILL_STYLE_LL2UR_DIAGONAL			= 5;						// Lower-left to upper-right diagonal
	const u32			_FILL_STYLE_HORIZONTAL_AND_VERTICAL	= 6;						// Squares, both horizontal and vertical lines
	const u32			_FILL_STYLE_BOTH_DIAGONALS			= 7;						// Diamonds, both diagonal directions


//////////
// Form windows
//////
	const u32			_WINDOW_STATE_NORMAL				= 0;						// Normal
	const u32			_WINDOW_STATE_MINIMIZED				= 1;						// Minimized
	const u32			_WINDOW_STATE_MAXIMIZED				= 2;						// Maximized

	const u32			_WINDOW_TYPE_MODELESS				= 0;						// Works in cooperation with other forms
	const u32			_WINDOW_TYPE_MODAL					= 1;						// The focus is limited to one form
	const u32			_WINDOW_TYPE_READ					= 2;						// The input is a READ window
	const u32			_WINDOW_TYPE_READ_MODAL				= 3;						// The input is a READ MODAL window


//////////
// Object mouse pointers
//////
	const u32			_MOUSE_POINTER_DEFAULT				= 0;
	const u32			_MOUSE_POINTER_ARROW1				= 1;
	const u32			_MOUSE_POINTER_CROSS				= 2;
	const u32			_MOUSE_POINTER_I_BEAM				= 3;
	const u32			_MOUSE_POINTER_ICON					= 4;
	const u32			_MOUSE_POINTER_SIZE					= 5;
	const u32			_MOUSE_POINTER_SIZE_NE_SW			= 6;
	const u32			_MOUSE_POINTER_SIZE_NS				= 7;
	const u32			_MOUSE_POINTER_SIZE_NW_SE			= 8;
	const u32			_MOUSE_POINTER_SIZE_W_E				= 9;
	const u32			_MOUSE_POINTER_UP_ARROW				= 10;
	const u32			_MOUSE_POINTER_HOURGLASS			= 11;
	const u32			_MOUSE_POINTER_NO_DROP				= 12;
	const u32			_MOUSE_POINTER_HIDE_POINTER			= 13;
	const u32			_MOUSE_POINTER_ARROW2				= 14;
	const u32			_MOUSE_POINTER_HAND					= 15;
	const u32			_MOUSE_POINTER_DOWN_ARROW			= 16;
	const u32			_MOUSE_POINTER_MAGNIFYING_GLASS		= 17;
	const u32			_MOUSE_POINTER_CUSTOM				= 18;


//////////
// Drag mode
//////
	const u32			_DRAG_MODE_MANUAL					= 0;
	const u32			_DRAG_MODE_AUTOMATIC				= 1;


//////////
// OLE constants
//////
	const u32			_DROP_EFFECT_NONE					= 0;
	const u32			_DROP_EFFECT_COPY					= 1;
	const u32			_DROP_EFFECT_MOVE					= 2;
	const u32			_DROP_EFFECT_LINK					= 4;

	const u32			_DROP_HAS_DATA_AUTOMATIC			= -1;
	const u32			_DROP_HAS_DATA_NO					= 0;
	const u32			_DROP_HAS_DATA_YES					= 1;

	const u32			_DROP_DISABLED						= 0;
	const u32			_DROP_ENABLED						= 1;
	const u32			_DROP_TO_CONTAINER					= 2;

	const u32			_OLE_IS_ACTIVEX						= -2;
	const u32			_OLE_IS_BOUND_EMPTY					= -1;
	const u32			_OLE_IS_LINKED						= 0;
	const u32			_OLE_IS_EMBEDDED					= 1;


//////////
// Grid related
//////
	const u32			_GRID_PANEL_LEFT					= 0;
	const u32			_GRID_PANEL_RIGHT					= 1;

	const u32			_GRID_LINES_NONE					= 0;						// No grid lines (leave the background fill color)
	const u32			_GRID_LINES_HORIZONTAL				= 1;						// Horizontal lines only
	const u32			_GRID_LINES_VERTICAL				= 2;						// Vertical lines only
	const u32			_GRID_LINES_BOTH					= 3;						// Both horizontal and vertical

	const u32			_GRID_NO_PARTITION					= 0;
	const u32			_GRID_PARTITION						= 1;

	const u32			_GRID_RECORD_SOURCE_TABLE			= 0;
	const u32			_GRID_RECORD_SOURCE_ALIAS			= 1;
	const u32			_GRID_RECORD_SOURCE_PROMPT			= 2;
	const u32			_GRID_RECORD_SOURCE_QUERY			= 3;
	const u32			_GRID_RECORD_SOURCE_SQL				= 4;

	const u32			_GRID_ROW_COL_CHANGE_NONE			= 0;
	const u32			_GRID_ROW_COL_CHANGE_ROW			= 1;
	const u32			_GRID_ROW_COL_CHANGE_COL			= 2;

	const u32			_GRID_VIEW_BROWSE					= 0;
	const u32			_GRID_VIEW_CHANGE					= 1;
	const u32			_GRID_VIEW_CHANGE_LEFT				= 2;
	const u32			_GRID_VIEW_CHANGE_BOTH				= 3;


//////////
// Visual effects
//////
	const u32			_VISUAL_EFFECT_NONE					= 0;
	const u32			_VISUAL_EFFECT_RAISED				= 1;
	const u32			_VISUAL_EFFECT_DEPRESSED			= 2;


//////////
// Tabs on a pageframe
//////
	const u32			_TAB_ORIENTATION_TOP				= 0;
	const u32			_TAB_ORIENTATION_BOTTOM				= 1;
	const u32			_TAB_ORIENTATION_LEFT				= 2;
	const u32			_TAB_ORIENTATION_RIGHT				= 3;

	const u32			_TAB_STYLE_JUSTIFIED				= 0;
	const u32			_TAB_STYLE_UNJUSTIFIED				= 1;


//////////
// Date entry settings
//////
	const u32			_STRICT_DATE_LOOSE					= 0;
	const u32			_STRICT_DATE_STRICT					= 1;


//////////
// Stretch mode
//////
	const u32			_STRETCH_CLIP						= 0;
	const u32			_STRETCH_ISOMETRIC					= 1;
	const u32			_STRETCH_STRETCH					= 2;


//////////
// Show window constants
//////
	const u32			_SHOW_WINDOW_IN_SCREEN				= 0;
	const u32			_SHOW_WINDOW_AS_CHILD				= 1;
	const u32			_SHOW_WINDOW_IN_OS					= 2;


//////////
// Seconds settings
//////
	const u32			_SECONDS_OFF						= 0;
	const u32			_SECONDS_ON							= 1;
	const u32			_SECONDS_SET						= 2;


//////////
// Scroll bars setting
//////
	const u32			_SCROLL_BARS_NONE					= 0;
	const u32			_SCROLL_BARS_HORIZONTAL				= 1;
	const u32			_SCROLL_BARS_VERTICAL				= 2;
	const u32			_SCROLL_BARS_BOTH					= 3;


//////////
// Row source types for listbox and combobox
//////
	const u32			_ROW_SOURCE_TYPE_NONE				= 0;
	const u32			_ROW_SOURCE_TYPE_VALUE				= 1;
	const u32			_ROW_SOURCE_TYPE_ALIAS				= 2;
	const u32			_ROW_SOURCE_TYPE_SQL				= 3;
	const u32			_ROW_SOURCE_TYPE_QUERY				= 4;
	const u32			_ROW_SOURCE_TYPE_ARRAY				= 5;
	const u32			_ROW_SOURCE_TYPE_FIELDS				= 6;
	const u32			_ROW_SOURCE_TYPE_FILES				= 7;
	const u32			_ROW_SOURCE_TYPE_STRUCTURE			= 8;
	const u32			_ROW_SOURCE_TYPE_POPUP				= 9;
	const u32			_ROW_SOURCE_TYPE_COLLECTION			= 10;


//////////
// Rotation for images
//////
	const u32			_ROTATE_NONE						= 0;
	const u32			_ROTATE_90							= 1;
	const u32			_ROTATE_180							= 2;
	const u32			_ROTATE_270							= 3;
	const u32			_ROTATE_NONE_FLIP					= 4;
	const u32			_ROTATE_90_FLIP						= 5;
	const u32			_ROTATE_180_FLIP					= 6;
	const u32			_ROTATE_270_FLIP					= 7;


//////////
// Release type
//////
	const u32			_RELEASE_TYPE_VARIABLE				= 0;
	const u32			_RELEASE_TYPE_CLOSE					= 1;
	const u32			_RELEASE_TYPE_QUIT					= 2;
 

//////////
// Picture constants
//////
	const u32			_PICTURE_LEFT_TOP					= 0;
	const u32			_PICTURE_LEFT_CENTERED				= 1;
	const u32			_PICTURE_LEFT_BOTTOM				= 2;
	const u32			_PICTURE_RIGHT_TOP					= 3;
	const u32			_PICTURE_RIGHT_CENTERED				= 4;
	const u32			_PICTURE_RIGHT_BOTTOM				= 5;
	const u32			_PICTURE_ABOVE_LEFT					= 6;
	const u32			_PICTURE_ABOVE_CENTERED				= 7;
	const u32			_PICTURE_ABOVE_RIGHT				= 8;
	const u32			_PICTURE_BELOW_LEFT					= 9;
	const u32			_PICTURE_BELOW_CENTERED				= 10;
	const u32			_PICTURE_BELOW_RIGHT				= 11;
	const u32			_PICTURE_CENTERED_TOP				= 12;
	const u32			_PICTURE_CENTERED_RELATIVE			= 13;
	const u32			_PICTURE_CENTERED_NO_TEXT3			= 14;

	const u32			_PICTURE_NO_DISPLAY					= 0;
	const u32			_PICTURE_CLIP						= 1;
	const u32			_PICTURE_SCALE						= 2;
	const u32			_PICTURE_STRETCH					= 3;


//////////
// Object clickEx click flags
//////
	const u32			_MOUSE_LEFT_BUTTON					= 1;
	const u32			_MOUSE_MIDDLE_BUTTON				= 2;
	const u32			_MOUSE_RIGHT_BUTTON					= 4;


//////////
// Object anchor mode bit masks
// Note:  If conflicting values are attempted, they are ignored.
//////
	const u32			_ANCHOR_FIXED_NORESIZE				= 0;
	const u32			_ANCHOR_TOP_ABSOLUTE				= 1;
	const u32			_ANCHOR_LEFT_ABSOLUTE				= 2;
	const u32			_ANCHOR_BOTTOM_ABSOLUTE				= 4;
	const u32			_ANCHOR_RIGHT_ABSOLUTE				= 8;
	const u32			_ANCHOR_TOP_RELATIVE				= 16;
	const u32			_ANCHOR_LEFT_RELATIVE				= 32;
	const u32			_ANCHOR_BOTTOM_RELATIVE				= 64;
	const u32			_ANCHOR_RIGHT_RELATIVE				= 128;
	const u32			_ANCHOR_DO_NOT_RESIZE_HORIZONTALLY	= 256;
	const u32			_ANCHOR_DO_NOT_RESIZE_VERTICALLY	= 512;


//////////
// Object property flags
//////
	const u32			_EMPTY								= 1;
	const u32			_FORM								= 2;
	const u32			_SUBFORM							= 4;
	const u32			_LABEL								= 8;
	const u32			_TEXTBOX							= 16;
	const u32			_BUTTON								= 32;
	const u32			_EDITBOX							= 64;
	const u32			_IMAGE								= 128;
	const u32			_CHECKBOX							= 256;
	const u32			_OPTION								= 512;
	const u32			_RADIO								= 1024;
	const u32			_ALL								= _EMPTY + _FORM + _SUBFORM + _LABEL + _TEXTBOX + _BUTTON + _EDITBOX + _IMAGE + _CHECKBOX + _OPTION + _RADIO;


//////////
// Internal messages
//////
	const u32			WMVJR_FIRST_CREATION				= WM_USER + 1;


//////////
// For tooltips, 20x per second
//////
	const u32			_TOOLTIP_TIMER_INTERVAL				= 250;
	const u32			_TOOLTIP_TIMER_DEFAULT_TIMEOUT		= 2500;		// 2.5 seconds


//////////
// Internal variable names
//////
	const s8			cgcName_startupTime[]				= "_startupTime";


//////////
// Base class control names
//////
	const s8			cgcName_empty[]						= "empty";
	const s8			cgcName_form[]						= "form";
	const s8			cgcName_subform[]					= "subform";
	const s8			cgcName_carousel[]					= "carousel";
	const s8			cgcName_rider[]						= "rider";
	const s8			cgcName_label[]						= "label";
	const s8			cgcName_textbox[]					= "textbox";
	const s8			cgcName_button[]					= "button";
	const s8			cgcName_editbox[]					= "editbox";
	const s8			cgcName_image[]						= "image";
	const s8			cgcName_checkbox[]					= "checkbox";
	const s8			cgcName_option[]					= "option";
	const s8			cgcName_radio[]						= "radio";
	const s8			cgcName_cmdgroup[]					= "commandgroup";
	const s8			cgcName_optgroup[]					= "optiongroup";
	const s8			cgcName_listbox[]					= "listbox";
	const s8			cgcName_combobox[]					= "combobox";
	const s8			cgcName_formset[]					= "formset";
	const s8			cgcName_toolbar[]					= "toolbar";
	const s8			cgcName_separator[]					= "separator";
	const s8			cgcName_line[]						= "line";
	const s8			cgcName_shape[]						= "shape";
	const s8			cgcName_container[]					= "container";
	const s8			cgcName_control[]					= "control";
	const s8			cgcName_grid[]						= "grid";
	const s8			cgcName_column[]					= "column";
	const s8			cgcName_header[]					= "header";
	const s8			cgcName_olebound[]					= "olebound";
	const s8			cgcName_olecontain[]				= "olecontainer";
	const s8			cgcName_spinner[]					= "spinner";
	const s8			cgcName_timer[]						= "timer";
	const s8			cgcName_hyperlink[]					= "hyperlink";
	const s8			cgcName_collection[]				= "collection";
	const s8			cgcName_page[]						= "page";
	const s8			cgcName_pageframe[]					= "pageframe";
	const s8			cgcName_session[]					= "session";
	const s8			cgcName_custom[]					= "custom";
	const s8			cgcName_exception[]					= "exception";

	// The form caption
	const s8			cgcName_formCaption[]				= "VJr Form";


//////////
// Default values for various types
//////
	const s8			cgc_defaultNumeric[10]				= { 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 };	// Numeric values are internally stored as 80-bit BCDs, 18 significant digits with sign
	const s8			cgc_defaultDate[]					= "        ";
	const s8			cgc_spaceText[]						= " ";




//////////
// Auto-added child object names
//////
	const s8			cgcName_icon[]						= "_icon";								// Forms automatically get an app icon
	const s8			cgcName_caption[]					= "_caption";							// Forms, subforms automatically get a caption
	const s8			cgcName_iconMove[]					= "_move";								// Forms automatically get a move button (to move any subforms within using bars)
	const s8			cgcName_iconMinimize[]				= "_minimize";							// Forms automatically get a minimize button
	const s8			cgcName_iconMaximize[]				= "_maximize";							// Forms automatically get a maximize button
	const s8			cgcName_iconClose[]					= "_close";								// Forms automatically get a close button

	const s8			cgcName_checkboxImage[]				= "_cbimage";							// Checkboxes automatically get a checkbox image
	const s8			cgcName_checkboxLabel[]				= "_cblabel";							// Checkboxes automatically get a checkbox label


//////////
// Supported languages
//////
	const s8			cgcEnglish[]						= "en";									// English


//////////
// Constant strings
//////
	const s8			cgcMessageWindowClass[]				= "VJr.MessageWindow";
	const s8			cgcWindowClass[]					= "VJr.Window";
	const s8			cgcFocusHighlightClass[]			= "VJr.FocusWindow";
	const s8			cgcTooltipClass[]					= "VJr.TooltipWindow";
	const s8			cgcSplashClass[]					= "VJr.SplashWindow";
	const s8			cgcSourceCodeTitle[]				= "SourceCode";
	const s8			cgcLocalsTitle[]					= "Locals";
	const s8			cgcWatchTitle[]						= "Watch";
	const s8			cgcCommandTitle[]					= "Command";
	const s8			cgcDebugTitle[]						= "Debug";
	const s8			cgcOutputTitle[]					= "Output";
	const s8			cgcSourceLightTitle[]				= "SourceLight";
	const s8			cgcSystemLog[]						= "System Log";
	const s8			cgc_noMateFound[]					= "Mate not found";
	const s8			cgcVersionShort[]					= "Version 0.53";
	const s8			cgcScreenTitle[]					= "Visual FreePro, Jr. 0.53 -- Sep.06.2014";
	const s8			cgcJDebiTitle[]						= "JDebi Debugger 0.53 -- Sep.06.2014";
	const s8			cgcVersionText[]					= "Visual FreePro, Jr. 00.53.0001.9999 for Windows";
// VERSION() support
	const s8			cgcVersion1Text[]					= "Visual FreePro, Jr. 00.53.0001.9999 for Windows [Sep.06.2014 00:00:00] Product ID 31415-926-5358979-32384";
	const s8			cgcVersion4Text[]					= "00.53.0001.9999";
	const s32			gnVersion5							= 53;	// 0.53
	const s32			gnVersion2							= 2;	// Professional
	const s32			gnVersion3							= 0;	// English
	const s8			cgcFontName_default[]				= "Ubuntu";
	const s8			cgcFontName_defaultFixed[]			= "Ubuntu Mono";
	const s8			cgcFontName_windowTitleBar[]		= "Ubuntu Condensed";
	const s8			cgcFontName_subwindowTitleBar[]		= "Ubuntu Condensed";
	const s8			cgcFontName_defaultTooltip[]		= "Ubuntu Condensed";
	const s8			cgcFontName_cask[]					= "Ubuntu Mono";
	const s8			cgcSystemLogFilename[]				= "system.log";
	const s8			cgcScreenDataFilename[]				= "screen.vjr";
	const s8			cgcCommandHistoryFilename[]			= "command.vjr";
	const s8			cgcStartupPrgFilename[]				= "startup.prg";
	const s8			cgcSoundStartupWav[]				= "startup_44100_f32.wav";
