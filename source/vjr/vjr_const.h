//////////
//
// /libsf/source/vjr/vjr_const.h
//
//////
// Version 0.52
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
	#define iVariable_isTypeFloatingPoint(var)		(var->varType == _VAR_TYPE_F32 || var->varType == _VAR_TYPE_F64 || var->varType == _VAR_TYPE_FLOAT || var->varType == _VAR_TYPE_DOUBLE)
	#define iVariable_isTypeFloat(var)				(var->varType == _VAR_TYPE_F32 || var->varType == _VAR_TYPE_FLOAT)
	#define iVariable_isTypeDouble(var)				(var->varType == _VAR_TYPE_F64 || var->varType == _VAR_TYPE_DOUBLE)
	#define iVariable_isTypeCurrency(var)			(var->varType == _VAR_TYPE_CURRENCY)
	#define iVariable_isTypeBigInteger(var)			(var->varType == _VAR_TYPE_BI)
	#define iVariable_isTypeBigFloatingPoint(var)	(var->varType == _VAR_TYPE_BFP)


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


//////////
// System constants
//////
	const s32			_MENU_BAR_HEIGHT					= 16;						// Each menu is 16 pixels high


//////////
// Object types
//////
	const u32			_OBJ_TYPE_EMPTY						= 0;						// Empty, used as a placeholder object that is not drawn
	const u32			_OBJ_TYPE_FORM						= 1;						// Form class, the main outer window the OS sees
	const u32			_OBJ_TYPE_SUBFORM					= 2;						// A new class which has its own drawing content and can be moved about using UI features
	const u32			_OBJ_TYPE_CAROUSEL					= 3;						// A carousel is a holder for riders
	const u32			_OBJ_TYPE_RIDER						= 4;						// A rider holds a form or subform and sizes it based on user interaction within its carousel
	const u32			_OBJ_TYPE_LABEL						= 5;						// A label
	const u32			_OBJ_TYPE_TEXTBOX					= 6;						// An input textbox
	const u32			_OBJ_TYPE_BUTTON					= 7;						// A push button
	const u32			_OBJ_TYPE_EDITBOX					= 8;						// An input multi-line editbox
	const u32			_OBJ_TYPE_IMAGE						= 9;						// A graphical image
	const u32			_OBJ_TYPE_CHECKBOX					= 10;						// A checkbox
	const u32			_OBJ_TYPE_OPTION					= 11;						// A combination selection
	const u32			_OBJ_TYPE_RADIO						= 12;						// A radio dial, which can also present as a slider or spinner

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
// Form border styles
//////
	const u32			_BORDER_STYLE_NONE					= 0;						// No border, not sizable
	const u32			_BORDER_STYLE_OUTLINE				= 1;						// Outline border, not sizable
	const u32			_BORDER_STYLE_FIXED					= 2;						// Normal border, not sizable
	const u32			_BORDER_STYLE_SIZABLE				= 3;						// Normal border, sizable


//////////
// Form scale mode
//////
	const u32			_SCALE_MODE_FOXELS					= 0;						// Foxels, based on sysmetrics() average font width and height
	//const u32			_SCALE_MODE_INCHES					= 1;						// Inches, based on correlating inches to default dpi
	const u32			_SCALE_MODE_PIXELS					= 3;						// Pixels, based on individual pixels


//////////
// Form window state
//////
	const u32			_WINDOW_STATE_NORMAL				= 0;						// Normal
	const u32			_WINDOW_STATE_MINIMIZED				= 1;						// Minimized
	const u32			_WINDOW_STATE_MAXIMIZED				= 2;						// Maximized


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
// Variable types
//////
	// Note:  Lower-bit is a flag:	0-variable, 1-reference to a variable
	const u32			_VARIABLE_TYPE_LOGICAL				= 0;						// Logical values are 0=.F., others=.T., and explicit values for 2=.O., 3=.P., 4=.X., 5=.Y., and 6=.Z. through SETLOGICALX() and GETLOGICALX()
	const u32			_VARIABLE_TYPE_NUMERIC				= 1 << 1;					// Maintains its value in converted-to-text form, but is numeric
	const u32			_VARIABLE_TYPE_CHARACTER			= 2 << 1;					// A character string
	const u32			_VARIABLE_TYPE_F32					= 3 << 1;					// A 32-bit floating point value with length and decimals
	const u32			_VARIABLE_TYPE_F64					= 4 << 1;					// A 64-bit floating point value with length and decimals
	const u32			_VARIABLE_TYPE_S8					= 5 << 1;					// An 8-bit signed integer
	const u32			_VARIABLE_TYPE_U8					= 6 << 1;					// An 8-bit unsigned integer
	const u32			_VARIABLE_TYPE_S16					= 7 << 1;					// A 16-bit signed integer
	const u32			_VARIABLE_TYPE_U16					= 8 << 1;					// A 16-bit unsigned integer
	const u32			_VARIABLE_TYPE_S32					= 9 << 1;					// A 32-bit signed integer
	const u32			_VARIABLE_TYPE_U32					= 10 << 1;					// A 32-bit unsigned integer
	const u32			_VARIABLE_TYPE_S64					= 11 << 1;					// A 64-bit signed integer
	const u32			_VARIABLE_TYPE_U64					= 12 << 1;					// A 64-bit unsigned integer
	const u32			_VARIABLE_TYPE_CURRENCY				= 13 << 1;					// A 64-bit signed integer with fixed length and decimals
	const u32			_VARIABLE_TYPE_DATE					= 14 << 1;					// A date
	const u32			_VARIABLE_TYPE_DATETIME				= 15 << 1;					// A datetime
	const u32			_VARIABLE_TYPE_DATETIMEX			= 16 << 1;					// A datetimex
	const u32			_VARIABLE_TYPE_BI					= 17 << 1;					// Big integer with length
	const u32			_VARIABLE_TYPE_BFP					= 18 << 1;					// Big floating with length and decimals
	const u32			_VARIABLE_TYPE_COLOR				= 19 << 1;					// An RGB() color
	const u32			_VARIABLE_TYPE_COLORA				= 20 << 1;					// An RGBA() color
	const u32			_VARIABLE_TYPE_ARRAY				= 80 << 1;					// Indicates the variable is an array
	const u32			_VARIABLE_TYPE_GUID8				= 90 << 1;					// GUID-8 byte form (automatically coordinated data across multiple physical locations of an application, even when offline)
	const u32			_VARIABLE_TYPE_GUID16				= 91 << 1;					// GUID-16 byte form (a form allowing for more unique records)
	const u32			_VARIABLE_TYPE_OBJECT				= 100 << 1;					// An object (class structure)
	const u32			_VARIABLE_TYPE_THISCODE				= 200 << 1;					// thisCode reference
	const u32			_VARIABLE_TYPE_FIELD				= 1000 << 1;				// A field from something with an alias


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
	const s8			cgcName_formCaption[]				= "VJr Form";


//////////
// Default values for various types
//////
	const s8			cgc_defaultNumeric[]				= "0";
	const s8			cgc_defaultDate[]					= "        ";
	const s8			cgc_spaceText[]						= " ";


//////////
// Base object property names
//////
	const s8			cgcName_parent[]					= "parent";
	const s8			cgcName_tabIndex[]					= "tabIndex";
	const s8			cgcName_tabStop[]					= "tabStop";
	const s8			cgcName_helpContextId[]				= "helpContextId";
	const s8			cgcName_hasWhatsThisButton[]		= "hasWhatsThisButton";
	const s8			cgcName_hasWhatsThisHelp[]			= "hasWhatsThisHelp";
	const s8			cgcName_whatsThisHelpId[]			= "whatsThisHelpId";
	const s8			cgcName_name[]						= "name";
	const s8			cgcName_className[]					= "classname";
	const s8			cgcName_classLibrary[]				= "classLibrary";
	const s8			cgcName_comment[]					= "comment";
	const s8			cgcName_toolTip[]					= "toolTip";
	const s8			cgcName_tag[]						= "tag";
	const s8			cgcName_mousePointer[]				= "mousePointer";
	const s8			cgcName_isEnabled[]					= "isEnabled";
	const s8			cgcName_hasFocus[]					= "hasFocus";
	const s8			cgcName_isMovable[]					= "isMovable";
	const s8			cgcName_isRendered[]				= "isRendered";
	const s8			cgcName_isPublished[]				= "isPublished";
	const s8			cgcName_isVisible[]					= "visible";
	const s8			cgcName_isDirty[]					= "isDirty";
	const s8			cgcName_left[]						= "left";
	const s8			cgcName_top[]						= "top";
	const s8			cgcName_width[]						= "width";
	const s8			cgcName_height[]					= "height";
	const s8			cgcName_anchor[]					= "anchor";
	const s8			cgcName_scrollX[]					= "scrollX";
	const s8			cgcName_scrollY[]					= "scrollY";
	const s8			cgcName_scaleX[]					= "scaleX";
	const s8			cgcName_scaleY[]					= "scaleY";

//////////
// Sub-object property names
//////
	const s8			cgcName_minLeft[]					= "minLeft";
	const s8			cgcName_minTop[]					= "minTop";
	const s8			cgcName_minWidth[]					= "minWidth";
	const s8			cgcName_minHeight[]					= "minHeight";
	const s8			cgcName_maxLeft[]					= "maxLeft";
	const s8			cgcName_maxTop[]					= "maxTop";
	const s8			cgcName_maxWidth[]					= "maxWidth";
	const s8			cgcName_maxHeight[]					= "maxHeight";
	const s8			cgcName_fontName[]					= "fontName";
	const s8			cgcName_fontSize[]					= "fontSize";
	const s8			cgcName_fontBold[]					= "fontBold";
	const s8			cgcName_fontItalic[]				= "fontItalic";
	const s8			cgcName_fontUnderline[]				= "fontUnderline";
	const s8			cgcName_fontStrikethrough[]			= "fontStrikethrough";
	const s8			cgcName_fontCondensed[]				= "fontCondensed";
	const s8			cgcName_fontExtended[]				= "fontExtended";
	const s8			cgcName_fontOutline[]				= "fontOutline";
	const s8			cgcName_fontShadow[]				= "fontShadow";
	const s8			cgcName_nwColor[]					= "nwColor";
	const s8			cgcName_neColor[]					= "neColor";
	const s8			cgcName_swColor[]					= "swColor";
	const s8			cgcName_seColor[]					= "seColor";
	const s8			cgcName_backColor[]					= "backColor";
	const s8			cgcName_foreColor[]					= "foreColor";
	const s8			cgcName_captionColor[]				= "captionColor";
	const s8			cgcName_caption[]					= "caption";
	const s8			cgcName_picture[]					= "picture";
	const s8			cgcName_allowOutput[]				= "allowOutput";
	const s8			cgcName_alwaysOnBottom[]			= "alwaysOnBottom";
	const s8			cgcName_alwaysOnTop[]				= "alwaysOnTop";
	const s8			cgcName_autoCenter[]				= "autoCenter";
	const s8			cgcName_borderStyle[]				= "borderStyle";
	const s8			cgcName_isCloseable[]				= "closable";
	const s8			cgcName_processKeyPreviewEvents[]	= "processKeyPreviewEvents";
	const s8			cgcName_hasControlBox[]				= "controlBox";
	const s8			cgcName_hasMinButton[]				= "minButton";
	const s8			cgcName_hasCloseButton[]			= "closeButton";
	const s8			cgcName_scaleMode[]					= "scaleMode";
	const s8			cgcName_showInTaskBar[]				= "showInTaskBar";
	const s8			cgcName_windowState[]				= "windowState";
	const s8			cgcName_bindControls[]				= "bindControls";
	const s8			cgcName_bufferMode[]				= "bufferMode";
	const s8			cgcName_clipControls[]				= "clipControls";
	const s8			cgcName_colorSource[]				= "colorSource";
	const s8			cgcName_continuousScroll[]			= "continuousScroll";
	const s8			cgcName_dataSession[]				= "dataSession";
	const s8			cgcName_dataSessionId[]				= "dataSessionId";
	const s8			cgcName_deClass[]					= "deClass";
	const s8			cgcName_deClassLibrary[]			= "deClassLibrary";
	const s8			cgcName_defOleCid[]					= "defOleCid";
	const s8			cgcName_desktop[]					= "desktop";
	const s8			cgcName_isDockable[]				= "dockable";
	const s8			cgcName_isDocked[]					= "docked";
	const s8			cgcName_dockPosition[]				= "dockPosition";
	const s8			cgcName_drawMode[]					= "drawMode";
	const s8			cgcName_drawStyle[]					= "drawStyle";
	const s8			cgcName_drawWidth[]					= "drawWidth";
	const s8			cgcName_fillColor[]					= "fillColor";
	const s8			cgcName_fillStyle[]					= "fillStyle";
	const s8			cgcName_halfHeightCaption[]			= "halfHeightCaption";
	const s8			cgcName_hScrollSmallChange[]		= "hScrollSmallChange";
	const s8			cgcName_vScrollSmallChange[]		= "vScrollSmallChange";
	const s8			cgcName_macDesktop[]				= "macDesktop";
	const s8			cgcName_mdiForm[]					= "mdiForm";
	const s8			cgcName_oleDragMode[]				= "oleDragMode";
	const s8			cgcName_oleDragPicture[]			= "oleDragPicture";
	const s8			cgcName_oleDropEffects[]			= "oleDropEffects";
	const s8			cgcName_oleDropHasData[]			= "oleDropHasData";
	const s8			cgcName_oleDropMode[]				= "oleDropMode";
	const s8			cgcName_releaseType[]				= "releaseType";
	const s8			cgcName_rightToLeft[]				= "rightToLeft";
	const s8			cgcName_scrollbars[]				= "scrollbars";
	const s8			cgcName_showTips[]					= "showTips";
	const s8			cgcName_showWindow[]				= "showWindow";
	const s8			cgcName_sizeBox[]					= "sizeBox";
	const s8			cgcName_themes[]					= "themes";
	const s8			cgcName_titleBar[]					= "titleBar";
	const s8			cgcName_windowType[]				= "windowType";
	const s8			cgcName_zoomBox[]					= "zoomBox";

	// Property map
	const s8			cgc_activeColumn[]					= "activeColumn";
	const s8			cgc_activeControl[]					= "activeControl";
	const s8			cgc_activeForm[]					= "activeForm";
	const s8			cgc_activePage[]					= "activePage";
	const s8			cgc_activeRow[]						= "activeRow";
	const s8			cgc_addLineFeeds[]					= "addLineFeeds";
	const s8			cgc_align[]							= "align";
	const s8			cgc_alignment[]						= "alignment";
	const s8			cgc_allowAddNew[]					= "allowAddNew";
	const s8			cgc_allowAutoColumnFit[]			= "allowAutoColumnFit";
	const s8			cgc_allowCellSelection[]			= "allowCellSelection";
	const s8			cgc_allowHeaderSizing[]				= "allowHeaderSizing";
	const s8			cgc_allowOutput[]					= "allowOutput";
	const s8			cgc_allowRowSizing[]				= "allowRowSizing";
	const s8			cgc_allowTabs[]						= "allowTabs";
	const s8			cgc_alwaysOnBottom[]				= "alwaysOnBottom";
	const s8			cgc_alwaysOnTop[]					= "alwaysOnTop";
	const s8			cgc_anchor[]						= "anchor";
	const s8			cgc_application[]					= "application";
	const s8			cgc_autoActivate[]					= "autoActivate";
	const s8			cgc_autoCenter[]					= "autoCenter";
	const s8			cgc_autoCompSource[]				= "autoCompSource";
	const s8			cgc_autoCompTable[]					= "autoCompTable";
	const s8			cgc_autoComplete[]					= "autoComplete";
	const s8			cgc_autoHideScrollBar[]				= "autoHideScrollBar";
	const s8			cgc_autoRelease[]					= "autoRelease";
	const s8			cgc_autoSize[]						= "autoSize";
	const s8			cgc_autoVerbMenu[]					= "autoVerbMenu";
	const s8			cgc_backColor[]						= "backColor";
	const s8			cgc_backStyle[]						= "backStyle";
	const s8			cgc_baseClass[]						= "baseClass";
	const s8			cgc_bindControls[]					= "bindControls";
	const s8			cgc_borderColor[]					= "borderColor";
	const s8			cgc_borderStyle[]					= "borderStyle";
	const s8			cgc_borderWidth[]					= "borderWidth";
	const s8			cgc_bound[]							= "bound";
	const s8			cgc_boundColumn[]					= "boundColumn";
	const s8			cgc_boundTo[]						= "boundTo";
	const s8			cgc_bufferMode[]					= "bufferMode";
	const s8			cgc_buttonCount[]					= "buttonCount";
	const s8			cgc_cancel[]						= "cancel";
	const s8			cgc_caption[]						= "caption";
	const s8			cgc_centered[]						= "centered";
	const s8			cgc_century[]						= "century";
	const s8			cgc_childOrder[]					= "childOrder";
	const s8			cgc_class[]							= "class";
	const s8			cgc_classLibrary[]					= "classLibrary";
	const s8			cgc_clipControls[]					= "clipControls";
	const s8			cgc_closable[]						= "closable";
	const s8			cgc_colorScheme[]					= "colorScheme";
	const s8			cgc_colorSource[]					= "colorSource";
	const s8			cgc_columnCount[]					= "columnCount";
	const s8			cgc_columnLines[]					= "columnLines";
	const s8			cgc_columnOrder[]					= "columnOrder";
	const s8			cgc_columnWidths[]					= "columnWidths";
	const s8			cgc_columns[]						= "columns";
	const s8			cgc_comment[]						= "comment";
	const s8			cgc_continuousScroll[]				= "continuousScroll";
	const s8			cgc_controlBox[]					= "controlBox";
	const s8			cgc_controlCount[]					= "controlCount";
	const s8			cgc_controlSource[]					= "controlSource";
	const s8			cgc_controls[]						= "controls";
	const s8			cgc_count[]							= "count";
	const s8			cgc_currentControl[]				= "currentControl";
	const s8			cgc_currentX[]						= "currentX";
	const s8			cgc_currentY[]						= "currentY";
	const s8			cgc_curvature[]						= "curvature";
	const s8			cgc_dEClass[]						= "dEClass";
	const s8			cgc_dEClassLibrary[]				= "dEClassLibrary";
	const s8			cgc_dataEnvironment[]				= "dataEnvironment";
	const s8			cgc_dataSession[]					= "dataSession";
	const s8			cgc_dataSessionID[]					= "dataSessionID";
	const s8			cgc_dateFormat[]					= "dateFormat";
	const s8			cgc_dateMark[]						= "dateMark";
	const s8			cgc_defOLELCID[]					= "defOLELCID";
	const s8			cgc_default[]						= "default";
	const s8			cgc_deleteMark[]					= "deleteMark";
	const s8			cgc_desktop[]						= "desktop";
	const s8			cgc_details[]						= "details";
	const s8			cgc_disabledBackColor[]				= "disabledBackColor";
	const s8			cgc_disabledForeColor[]				= "disabledForeColor";
	const s8			cgc_disabledItemBackColor[]			= "disabledItemBackColor";
	const s8			cgc_disabledItemForeColor[]			= "disabledItemForeColor";
	const s8			cgc_disabledPicture[]				= "disabledPicture";
	const s8			cgc_displayCount[]					= "displayCount";
	const s8			cgc_displayValue[]					= "displayValue";
	const s8			cgc_doCreate[]						= "doCreate";
	const s8			cgc_dockPosition[]					= "dockPosition";
	const s8			cgc_dockable[]						= "dockable";
	const s8			cgc_docked[]						= "docked";
	const s8			cgc_documentFile[]					= "documentFile";
	const s8			cgc_downPicture[]					= "downPicture";
	const s8			cgc_dragIcon[]						= "dragIcon";
	const s8			cgc_dragMode[]						= "dragMode";
	const s8			cgc_drawMode[]						= "drawMode";
	const s8			cgc_drawStyle[]						= "drawStyle";
	const s8			cgc_drawWidth[]						= "drawWidth";
	const s8			cgc_dynamicAlignment[]				= "dynamicAlignment";
	const s8			cgc_dynamicBackColor[]				= "dynamicBackColor";
	const s8			cgc_dynamicCurrentControl[]			= "dynamicCurrentControl";
	const s8			cgc_dynamicFontBold[]				= "dynamicFontBold";
	const s8			cgc_dynamicFontItalic[]				= "dynamicFontItalic";
	const s8			cgc_dynamicFontName[]				= "dynamicFontName";
	const s8			cgc_dynamicFontOutline[]			= "dynamicFontOutline";
	const s8			cgc_dynamicFontShadow[]				= "dynamicFontShadow";
	const s8			cgc_dynamicFontSize[]				= "dynamicFontSize";
	const s8			cgc_dynamicFontStrikeThru[]			= "dynamicFontStrikeThru";
	const s8			cgc_dynamicFontUnderline[]			= "dynamicFontUnderline";
	const s8			cgc_dynamicForeColor[]				= "dynamicForeColor";
	const s8			cgc_dynamicInputMask[]				= "dynamicInputMask";
	const s8			cgc_enableHyperlinks[]				= "enableHyperlinks";
	const s8			cgc_enabled[]						= "enabled";
	const s8			cgc_errorNo[]						= "errorNo";
	const s8			cgc_fillColor[]						= "fillColor";
	const s8			cgc_fillStyle[]						= "fillStyle";
	const s8			cgc_firstElement[]					= "firstElement";
	const s8			cgc_fontBold[]						= "fontBold";
	const s8			cgc_fontCharSet[]					= "fontCharSet";
	const s8			cgc_fontCondense[]					= "fontCondense";
	const s8			cgc_fontExtend[]					= "fontExtend";
	const s8			cgc_fontItalic[]					= "fontItalic";
	const s8			cgc_fontName[]						= "fontName";
	const s8			cgc_fontOutline[]					= "fontOutline";
	const s8			cgc_fontShadow[]					= "fontShadow";
	const s8			cgc_fontSize[]						= "fontSize";
	const s8			cgc_fontStrikeThru[]				= "fontStrikeThru";
	const s8			cgc_fontUnderLine[]					= "fontUnderLine";
	const s8			cgc_fontUnderline[]					= "fontUnderline";
	const s8			cgc_foreColor[]						= "foreColor";
	const s8			cgc_formCount[]						= "formCount";
	const s8			cgc_format[]						= "format";
	const s8			cgc_forms[]							= "forms";
	const s8			cgc_gridLineColor[]					= "gridLineColor";
	const s8			cgc_gridLineWidth[]					= "gridLineWidth";
	const s8			cgc_gridLines[]						= "gridLines";
	const s8			cgc_hScrollSmallChange[]			= "hScrollSmallChange";
	const s8			cgc_hWnd[]							= "hWnd";
	const s8			cgc_halfHeightCaption[]				= "halfHeightCaption";
	const s8			cgc_headerClass[]					= "headerClass";
	const s8			cgc_headerClassLibrary[]			= "headerClassLibrary";
	const s8			cgc_headerHeight[]					= "headerHeight";
	const s8			cgc_height[]						= "height";
	const s8			cgc_helpContextID[]					= "helpContextID";
	const s8			cgc_hideSelection[]					= "hideSelection";
	const s8			cgc_highLight[]						= "highLight";
	const s8			cgc_highLightRow[]					= "highLightRow";
	const s8			cgc_highlightBackColor[]			= "highlightBackColor";
	const s8			cgc_highlightForeColor[]			= "highlightForeColor";
	const s8			cgc_highlightRowLineWidth[]			= "highlightRowLineWidth";
	const s8			cgc_highlightStyle[]				= "highlightStyle";
	const s8			cgc_hostName[]						= "hostName";
	const s8			cgc_hours[]							= "hours";
	const s8			cgc_iMEMode[]						= "iMEMode";
	const s8			cgc_icon[]							= "icon";
	const s8			cgc_increment[]						= "increment";
	const s8			cgc_incrementalSearch[]				= "incrementalSearch";
	const s8			cgc_inputMask[]						= "inputMask";
	const s8			cgc_integralHeight[]				= "integralHeight";
	const s8			cgc_interval[]						= "interval";
	const s8			cgc_itemBackColor[]					= "itemBackColor";
	const s8			cgc_itemData[]						= "itemData";
	const s8			cgc_itemForeColor[]					= "itemForeColor";
	const s8			cgc_itemIDData[]					= "itemIDData";
	const s8			cgc_itemTips[]						= "itemTips";
	const s8			cgc_keyPreview[]					= "keyPreview";
	const s8			cgc_keySort[]						= "keySort";
	const s8			cgc_keyboardHighValue[]				= "keyboardHighValue";
	const s8			cgc_keyboardLowValue[]				= "keyboardLowValue";
	const s8			cgc_left[]							= "left";
	const s8			cgc_leftColumn[]					= "leftColumn";
	const s8			cgc_lineContents[]					= "lineContents";
	const s8			cgc_lineNo[]						= "lineNo";
	const s8			cgc_lineSlant[]						= "lineSlant";
	const s8			cgc_linkMaster[]					= "linkMaster";
	const s8			cgc_list[]							= "list";
	const s8			cgc_listCount[]						= "listCount";
	const s8			cgc_listIndex[]						= "listIndex";
	const s8			cgc_listItem[]						= "listItem";
	const s8			cgc_listItemID[]					= "listItemID";
	const s8			cgc_lockColumns[]					= "lockColumns";
	const s8			cgc_lockColumnsLeft[]				= "lockColumnsLeft";
	const s8			cgc_lockScreen[]					= "lockScreen";
	const s8			cgc_mDIForm[]						= "mDIForm";
	const s8			cgc_macDesktop[]					= "macDesktop";
	const s8			cgc_margin[]						= "margin";
	const s8			cgc_maxButton[]						= "maxButton";
	const s8			cgc_maxHeight[]						= "maxHeight";
	const s8			cgc_maxLeft[]						= "maxLeft";
	const s8			cgc_maxLength[]						= "maxLength";
	const s8			cgc_maxTop[]						= "maxTop";
	const s8			cgc_maxWidth[]						= "maxWidth";
	const s8			cgc_memberClass[]					= "memberClass";
	const s8			cgc_memberClassLibrary[]			= "memberClassLibrary";
	const s8			cgc_memoWindow[]					= "memoWindow";
	const s8			cgc_message[]						= "message";
	const s8			cgc_minButton[]						= "minButton";
	const s8			cgc_minHeight[]						= "minHeight";
	const s8			cgc_minWidth[]						= "minWidth";
	const s8			cgc_mouseIcon[]						= "mouseIcon";
	const s8			cgc_mousePointer[]					= "mousePointer";
	const s8			cgc_movable[]						= "movable";
	const s8			cgc_moverBars[]						= "moverBars";
	const s8			cgc_multiSelect[]					= "multiSelect";
	const s8			cgc_name[]							= "name";
	const s8			cgc_newIndex[]						= "newIndex";
	const s8			cgc_newItemID[]						= "newItemID";
	const s8			cgc_nullDisplay[]					= "nullDisplay";
	const s8			cgc_numberOfElements[]				= "numberOfElements";
	const s8			cgc_oLEClass[]						= "oLEClass";
	const s8			cgc_oLEDragMode[]					= "oLEDragMode";
	const s8			cgc_oLEDragPicture[]				= "oLEDragPicture";
	const s8			cgc_oLEDropEffects[]				= "oLEDropEffects";
	const s8			cgc_oLEDropHasData[]				= "oLEDropHasData";
	const s8			cgc_oLEDropMode[]					= "oLEDropMode";
	const s8			cgc_oLEDropTextInsertion[]			= "oLEDropTextInsertion";
	const s8			cgc_oLELCID[]						= "oLELCID";
	const s8			cgc_oLETypeAllowed[]				= "oLETypeAllowed";
	const s8			cgc_object[]						= "object";
	const s8			cgc_objects[]						= "objects";
	const s8			cgc_openWindow[]					= "openWindow";
	const s8			cgc_optimize[]						= "optimize";
	const s8			cgc_pageCount[]						= "pageCount";
	const s8			cgc_pageHeight[]					= "pageHeight";
	const s8			cgc_pageOrder[]						= "pageOrder";
	const s8			cgc_pageWidth[]						= "pageWidth";
	const s8			cgc_pages[]							= "pages";
	const s8			cgc_panel[]							= "panel";
	const s8			cgc_panelLink[]						= "panelLink";
	const s8			cgc_parent[]						= "parent";
	const s8			cgc_parentClass[]					= "parentClass";
	const s8			cgc_partition[]						= "partition";
	const s8			cgc_passwordChar[]					= "passwordChar";
	const s8			cgc_picture[]						= "picture";
	const s8			cgc_pictureMargin[]					= "pictureMargin";
	const s8			cgc_picturePosition[]				= "picturePosition";
	const s8			cgc_pictureSelectionDisplay[]		= "pictureSelectionDisplay";
	const s8			cgc_pictureSpacing[]				= "pictureSpacing";
	const s8			cgc_pictureVal[]					= "pictureVal";
	const s8			cgc_polyPoints[]					= "polyPoints";
	const s8			cgc_procedure[]						= "procedure";
	const s8			cgc_readBackColor[]					= "readBackColor";
	const s8			cgc_readCycle[]						= "readCycle";
	const s8			cgc_readForeColor[]					= "readForeColor";
	const s8			cgc_readLock[]						= "readLock";
	const s8			cgc_readMouse[]						= "readMouse";
	const s8			cgc_readOnly[]						= "readOnly";
	const s8			cgc_readSave[]						= "readSave";
	const s8			cgc_readTimeOut[]					= "readTimeOut";
	const s8			cgc_recordMark[]					= "recordMark";
	const s8			cgc_recordSource[]					= "recordSource";
	const s8			cgc_recordSourceType[]				= "recordSourceType";
	const s8			cgc_relationalExpr[]				= "relationalExpr";
	const s8			cgc_relativeColumn[]				= "relativeColumn";
	const s8			cgc_relativeRow[]					= "relativeRow";
	const s8			cgc_releaseType[]					= "releaseType";
	const s8			cgc_resizable[]						= "resizable";
	const s8			cgc_rightToLeft[]					= "rightToLeft";
	const s8			cgc_rotateFlip[]					= "rotateFlip";
	const s8			cgc_rotation[]						= "rotation";
	const s8			cgc_rowColChange[]					= "rowColChange";
	const s8			cgc_rowHeight[]						= "rowHeight";
	const s8			cgc_rowSource[]						= "rowSource";
	const s8			cgc_rowSourceType[]					= "rowSourceType";
	const s8			cgc_scaleMode[]						= "scaleMode";
	const s8			cgc_scrollBars[]					= "scrollBars";
	const s8			cgc_seconds[]						= "seconds";
	const s8			cgc_selLength[]						= "selLength";
	const s8			cgc_selStart[]						= "selStart";
	const s8			cgc_selText[]						= "selText";
	const s8			cgc_selectOnEntry[]					= "selectOnEntry";
	const s8			cgc_selected[]						= "selected";
	const s8			cgc_selectedBackColor[]				= "selectedBackColor";
	const s8			cgc_selectedForeColor[]				= "selectedForeColor";
	const s8			cgc_selectedID[]					= "selectedID";
	const s8			cgc_selectedItemBackColor[]			= "selectedItemBackColor";
	const s8			cgc_selectedItemForeColor[]			= "selectedItemForeColor";
	const s8			cgc_showInTaskbar[]					= "showInTaskbar";
	const s8			cgc_showTips[]						= "showTips";
	const s8			cgc_showWindow[]					= "showWindow";
	const s8			cgc_sizable[]						= "sizable";
	const s8			cgc_sizeBox[]						= "sizeBox";
	const s8			cgc_sorted[]						= "sorted";
	const s8			cgc_sparse[]						= "sparse";
	const s8			cgc_specialEffect[]					= "specialEffect";
	const s8			cgc_spinnerHighValue[]				= "spinnerHighValue";
	const s8			cgc_spinnerLowValue[]				= "spinnerLowValue";
	const s8			cgc_splitBar[]						= "splitBar";
	const s8			cgc_stackLevel[]					= "stackLevel";
	const s8			cgc_statusBarText[]					= "statusBarText";
	const s8			cgc_stretch[]						= "stretch";
	const s8			cgc_strictDateEntry[]				= "strictDateEntry";
	const s8			cgc_style[]							= "style";
	const s8			cgc_tabIndex[]						= "tabIndex";
	const s8			cgc_tabOrientation[]				= "tabOrientation";
	const s8			cgc_tabStop[]						= "tabStop";
	const s8			cgc_tabStyle[]						= "tabStyle";
	const s8			cgc_tabs[]							= "tabs";
	const s8			cgc_tag[]							= "tag";
	const s8			cgc_terminateRead[]					= "terminateRead";
	const s8			cgc_text[]							= "text";
	const s8			cgc_themes[]						= "themes";
	const s8			cgc_titleBar[]						= "titleBar";
	const s8			cgc_toolTipText[]					= "toolTipText";
	const s8			cgc_top[]							= "top";
	const s8			cgc_topIndex[]						= "topIndex";
	const s8			cgc_topItemID[]						= "topItemID";
	const s8			cgc_userValue[]						= "userValue";
	const s8			cgc_vScrollSmallChange[]			= "vScrollSmallChange";
	const s8			cgc_value[]							= "value";
	const s8			cgc_view[]							= "view";
	const s8			cgc_viewPortHeight[]				= "viewPortHeight";
	const s8			cgc_viewPortLeft[]					= "viewPortLeft";
	const s8			cgc_viewPortTop[]					= "viewPortTop";
	const s8			cgc_viewPortWidth[]					= "viewPortWidth";
	const s8			cgc_visible[]						= "visible";
	const s8			cgc_visualEffect[]					= "visualEffect";
	const s8			cgc_whatsThisButton[]				= "whatsThisButton";
	const s8			cgc_whatsThisHelp[]					= "whatsThisHelp";
	const s8			cgc_whatsThisHelpID[]				= "whatsThisHelpID";
	const s8			cgc_width[]							= "width";
	const s8			cgc_windowList[]					= "windowList";
	const s8			cgc_windowState[]					= "windowState";
	const s8			cgc_windowType[]					= "windowType";
	const s8			cgc_wordWrap[]						= "wordWrap";
	const s8			cgc_zoomBox[]						= "zoomBox";




//////////
// Auto-added child object names
//////
	const s8			cgcName_icon[]						= "_icon";								// Forms automatically get an app icon
	const s8			cgcCaption_icon[]					= "_caption";							// Forms, subforms automatically get a caption
	const s8			cgcName_iconMove[]					= "_move";								// Forms automatically get a move button (to move any subforms within using bars)
	const s8			cgcName_iconMinimize[]				= "_minimize";							// Forms automatically get a minimize button
	const s8			cgcName_iconMaximize[]				= "_maximize";							// Forms automatically get a maximize button
	const s8			cgcName_iconClose[]					= "_close";								// Forms automatically get a close button

	const s8			cgcName_checkboxImage[]				= "_cbimage";							// Checkboxes automatically get a checkbox image
	const s8			cgcName_checkboxLabel[]				= "_cblabel";							// Checkboxes automatically get a checkbox label


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
	const s8			cgcVersionShort[]					= "Version 0.52";
	const s8			cgcScreenTitle[]					= "Visual FreePro, Jr. 0.52 -- Aug.21.2014";
	const s8			cgcJDebiTitle[]						= "JDebi Debugger 0.52 -- Aug.21.2014";
	const s8			cgcVersionText[]					= "Visual FreePro, Jr. 00.52.0001.9999 for Windows";
// VERSION() support
	const s8			cgcVersion1Text[]					= "Visual FreePro, Jr. 00.52.0001.9999 for Windows [Aug.21.2014 00:00:00] Product ID 31415-926-5358979-32384";
	const s8			cgcVersion4Text[]					= "00.52.0001.9999";
	const s32			gnVersion5							= 52;	// 0.51
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
