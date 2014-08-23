//////////
//
// /libsf/source/vjr/object_accessors.h
//
//////
// Version 0.52
// Copyright (c) 2014 by Rick C. Hodgin
//////
// Last update:
//     Jul.13.2014
//////
// Change log:
//     Jul.13.2014 - Initial creation
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
// To jump immediately to a section, search for one of these here or in object_accessors.cpp:
//		OBJECT Properties
//		FORM Properties
//		SUBFORM Properties
//
//////









//////////
// Forward declarations
//////
	// Base object accessors
	bool					iObj_setLogical							(SObject* obj, SVariable* var, bool* tlDest);
	SVariable*				iObj_getLogical							(SObject* obj, bool tlValue);
	bool					iObj_setInteger							(SObject* obj, SVariable* var, s32* tlDest, s32 tnMin, s32 tnMax, bool tlUseMinMaxTest, u32 tnExtraTestFunction);
	SVariable*				iObj_getInteger							(SObject* obj, s32 value);
	bool					iObj_setCharacter						(SObject* obj, SVariable* var, SDatum* datum, s8* tcData, s32 tnDataLength);
	SVariable*				iObj_getCharacter						(SObject* obj, SDatum* datum);
	bool					iObj_setError							(SObject* obj, SVariable* var);
	SVariable*				iObj_getError							(SObject* obj);

	// OBJECT Properties
	SVariable*				iObj_getProperty_parent                 (SObject* obj);
	bool					iObj_setProperty_tabIndex               (SObject* obj, SVariable* var);
	SVariable*				iObj_getProperty_tabIndex               (SObject* obj);
	bool					iObj_setProperty_tabStop                (SObject* obj, SVariable* var);
	SVariable*				iObj_getProperty_tabStop                (SObject* obj);
	bool					iObj_setProperty_helpContextId          (SObject* obj, SVariable* var);
	SVariable*				iObj_getProperty_helpContextId          (SObject* obj);
	bool					iObj_setProperty_hasWhatsThisButton     (SObject* obj, SVariable* var);
	SVariable*				iObj_getProperty_hasWhatsThisButton     (SObject* obj);
	bool					iObj_setProperty_hasWhatsThisHelp       (SObject* obj, SVariable* var);
	SVariable*				iObj_getProperty_hasWhatsThisHelp       (SObject* obj);
	bool					iObj_setProperty_whatsThisHelpId        (SObject* obj, SVariable* var);
	SVariable*				iObj_getProperty_whatsThisHelpId        (SObject* obj);
	bool					iObj_setProperty_name                   (SObject* obj, SVariable* var);
	SVariable*				iObj_getProperty_name                   (SObject* obj);
	bool					iObj_setProperty_className              (SObject* obj, SVariable* var);
	SVariable*				iObj_getProperty_className              (SObject* obj);
	bool					iObj_setProperty_classLibrary           (SObject* obj, SVariable* var);
	SVariable*				iObj_getProperty_classLibrary           (SObject* obj);
	bool					iObj_setProperty_comment                (SObject* obj, SVariable* var);
	SVariable*				iObj_getProperty_comment                (SObject* obj);
	bool					iObj_setProperty_toolTip                (SObject* obj, SVariable* var);
	SVariable*				iObj_getProperty_toolTip                (SObject* obj);
	bool					iObj_setProperty_tag                    (SObject* obj, SVariable* var);
	SVariable*				iObj_getProperty_tag                    (SObject* obj);
	bool					iObj_setProperty_mousePointer           (SObject* obj, SVariable* var);
	bool					iObj_setProperty_mousePointer_extraSetTest(s32 value);
	SVariable*				iObj_getProperty_mousePointer           (SObject* obj);
	bool					iObj_setProperty_isEnabled              (SObject* obj, SVariable* var);
	SVariable*				iObj_getProperty_isEnabled              (SObject* obj);
	bool					iObj_setProperty_hasFocus               (SObject* obj, SVariable* var);
	SVariable*				iObj_getProperty_hasFocus               (SObject* obj);
	bool					iObj_setProperty_isMovable              (SObject* obj, SVariable* var);
	SVariable*				iObj_getProperty_isMovable              (SObject* obj);
	bool					iObj_setProperty_isRendered             (SObject* obj, SVariable* var);
	SVariable*				iObj_getProperty_isRendered             (SObject* obj);
	bool					iObj_setProperty_isPublished            (SObject* obj, SVariable* var);
	SVariable*				iObj_getProperty_isPublished            (SObject* obj);
	bool					iObj_setProperty_isVisible              (SObject* obj, SVariable* var);
	SVariable*				iObj_getProperty_isVisible              (SObject* obj);
	bool					iObj_setProperty_isDirty                (SObject* obj, SVariable* var);
	SVariable*				iObj_getProperty_isDirty                (SObject* obj);
	bool					iObj_setProperty_left                   (SObject* obj, SVariable* var);
	SVariable*				iObj_getProperty_left                   (SObject* obj);
	bool					iObj_setProperty_top                    (SObject* obj, SVariable* var);
	SVariable*				iObj_getProperty_top                    (SObject* obj);
	bool					iObj_setProperty_width                  (SObject* obj, SVariable* var);
	SVariable*				iObj_getProperty_width                  (SObject* obj);
	bool					iObj_setProperty_height                 (SObject* obj, SVariable* var);
	SVariable*				iObj_getProperty_height                 (SObject* obj);
	bool					iObj_setProperty_anchor                 (SObject* obj, SVariable* var);
	SVariable*				iObj_getProperty_anchor                 (SObject* obj);
	bool					iObj_setProperty_scrollX                (SObject* obj, SVariable* var);
	SVariable*				iObj_getProperty_scrollX                (SObject* obj);
	bool					iObj_setProperty_scrollY                (SObject* obj, SVariable* var);
	SVariable*				iObj_getProperty_scrollY                (SObject* obj);
	bool					iObj_setProperty_scaleX                 (SObject* obj, SVariable* var);
	SVariable*				iObj_getProperty_scaleX                 (SObject* obj);
	bool					iObj_setProperty_scaleY                 (SObject* obj, SVariable* var);
	SVariable*				iObj_getProperty_scaleY                 (SObject* obj);

	void					iObj_setIcon							(SObject* obj, SBitmap* bmp);
	bool					iObj_setMinLeft							(SObject* obj, SVariable* var);
	SVariable*				iObj_getMinLeft							(SObject* obj);
	bool					iObj_setMinTop							(SObject* obj, SVariable* var);
	SVariable*				iObj_getMinTop							(SObject* obj);
	bool					iObj_setMinWidth						(SObject* obj, SVariable* var);
	SVariable*				iObj_getMinWidth						(SObject* obj);
	bool					iObj_setMinHeight						(SObject* obj, SVariable* var);
	SVariable*				iObj_getMinHeight						(SObject* obj);
	bool					iObj_setMaxLeft							(SObject* obj, SVariable* var);
	SVariable*				iObj_getMaxLeft							(SObject* obj);
	bool					iObj_setMaxTop							(SObject* obj, SVariable* var);
	SVariable*				iObj_getMaxTop							(SObject* obj);
	bool					iObj_setMaxWidth						(SObject* obj, SVariable* var);
	SVariable*				iObj_getMaxWidth						(SObject* obj);
	bool					iObj_setMaxHeight						(SObject* obj, SVariable* var);
	SVariable*				iObj_getMaxHeight						(SObject* obj);
	bool					iObj_setFontName						(SObject* obj, SVariable* var);
	SVariable*				iObj_getFontName						(SObject* obj);
	bool					iObj_setFontSize						(SObject* obj, SVariable* var);
	SVariable*				iObj_getFontSize						(SObject* obj);
	bool					iObj_setFontBold						(SObject* obj, SVariable* var);
	SVariable*				iObj_getFontBold						(SObject* obj);
	bool					iObj_setFontItalic						(SObject* obj, SVariable* var);
	SVariable*				iObj_getFontItalic						(SObject* obj);
	bool					iObj_setFontUnderline					(SObject* obj, SVariable* var);
	SVariable*				iObj_getFontUnderline					(SObject* obj);
	bool					iObj_setFontStrikethrough				(SObject* obj, SVariable* var);
	SVariable*				iObj_getFontStrikethrough				(SObject* obj);
	bool					iObj_setFontCondensed					(SObject* obj, SVariable* var);
	SVariable*				iObj_getFontCondensed					(SObject* obj);
	bool					iObj_setFontExtended					(SObject* obj, SVariable* var);
	SVariable*				iObj_getFontExtended					(SObject* obj);
	bool					iObj_setFontOutline						(SObject* obj, SVariable* var);
	SVariable*				iObj_getFontOutline						(SObject* obj);
	bool					iObj_setFontShadow						(SObject* obj, SVariable* var);
	SVariable*				iObj_getFontShadow						(SObject* obj);
	bool					iObj_setNwColor							(SObject* obj, SVariable* var);
	SVariable*				iObj_getNwColor							(SObject* obj);
	bool					iObj_setNeColor							(SObject* obj, SVariable* var);
	SVariable*				iObj_getNeColor							(SObject* obj);
	bool					iObj_setSwColor							(SObject* obj, SVariable* var);
	SVariable*				iObj_getSwColor							(SObject* obj);
	bool					iObj_setSeColor							(SObject* obj, SVariable* var);
	SVariable*				iObj_getSeColor							(SObject* obj);
	bool					iObj_setBackColor						(SObject* obj, SVariable* var);
	SVariable*				iObj_getBackColor						(SObject* obj);
	bool					iObj_setForeColor						(SObject* obj, SVariable* var);
	SVariable*				iObj_getForeColor						(SObject* obj);
	bool					iObj_setCaptionColor					(SObject* obj, SVariable* var);
	SVariable*				iObj_getCaptionColor					(SObject* obj);
	bool					iObj_setCaption							(SObject* obj, SVariable* var);
	SVariable*				iObj_getCaption							(SObject* obj);
	bool					iObj_setPicture							(SObject* obj, SVariable* var);
	SVariable*				iObj_getPicture							(SObject* obj);
	bool					iObj_setAllowOutput						(SObject* obj, SVariable* var);
	SVariable*				iObj_getAllowOutput						(SObject* obj);
	bool					iObj_setAlwaysOnBottom					(SObject* obj, SVariable* var);
	SVariable*				iObj_getAlwaysOnBottom					(SObject* obj);
	bool					iObj_setAlwaysOnTop						(SObject* obj, SVariable* var);
	SVariable*				iObj_getAlwaysOnTop						(SObject* obj);
	bool					iObj_setAutoCenter						(SObject* obj, SVariable* var);
	SVariable*				iObj_getAutoCenter						(SObject* obj);
	bool					iObj_setBorderStyle						(SObject* obj, SVariable* var);
	SVariable*				iObj_getBorderStyle						(SObject* obj);
	bool					iObj_setIsCloseable						(SObject* obj, SVariable* var);
	SVariable*				iObj_getIsCloseable						(SObject* obj);
	bool					iObj_setProcessKeyPreviewEvents			(SObject* obj, SVariable* var);
	SVariable*				iObj_getProcessKeyPreviewEvents			(SObject* obj);
	bool					iObj_setHasControlBox					(SObject* obj, SVariable* var);
	SVariable*				iObj_getHasControlBox					(SObject* obj);
	bool					iObj_setHasMinButton					(SObject* obj, SVariable* var);
	SVariable*				iObj_getHasMinButton					(SObject* obj);
	bool					iObj_setHasCloseButton					(SObject* obj, SVariable* var);
	SVariable*				iObj_getHasCloseButton					(SObject* obj);
	bool					iObj_setScaleMode						(SObject* obj, SVariable* var);
	bool					iObj_setScaleMode_extraTest				(s32 value);
	SVariable*				iObj_getScaleMode						(SObject* obj);
	bool					iObj_setShowInTaskBar					(SObject* obj, SVariable* var);
	SVariable*				iObj_getShowInTaskBar					(SObject* obj);
	bool					iObj_setWindowState						(SObject* obj, SVariable* var);
	SVariable*				iObj_getWindowState						(SObject* obj);
	bool					iObj_setBindControls					(SObject* obj, SVariable* var);
	SVariable*				iObj_getBindControls					(SObject* obj);
	bool					iObj_setBufferMode						(SObject* obj, SVariable* var);
	SVariable*				iObj_getBufferMode						(SObject* obj);
	bool					iObj_setClipControls					(SObject* obj, SVariable* var);
	SVariable*				iObj_getClipControls					(SObject* obj);
	bool					iObj_setColorSource						(SObject* obj, SVariable* var);
	SVariable*				iObj_getColorSource						(SObject* obj);
	bool					iObj_setContinuousScroll				(SObject* obj, SVariable* var);
	SVariable*				iObj_getContinuousScroll				(SObject* obj);
	bool					iObj_setDataSession						(SObject* obj, SVariable* var);
	SVariable*				iObj_getDataSession						(SObject* obj);
	bool					iObj_setDataSessionId					(SObject* obj, SVariable* var);
	SVariable*				iObj_getDataSessionId					(SObject* obj);
	bool					iObj_setDeClass							(SObject* obj, SVariable* var);
	SVariable*				iObj_getDeClass							(SObject* obj);
	bool					iObj_setDeClassLibrary					(SObject* obj, SVariable* var);
	SVariable*				iObj_getDeClassLibrary					(SObject* obj);
	bool					iObj_setDefOleCid						(SObject* obj, SVariable* var);
	SVariable*				iObj_getDefOleCid						(SObject* obj);
	bool					iObj_setDesktop							(SObject* obj, SVariable* var);
	SVariable*				iObj_getDesktop							(SObject* obj);
	bool					iObj_setIsDockable						(SObject* obj, SVariable* var);
	SVariable*				iObj_getIsDockable						(SObject* obj);
	bool					iObj_setIsDocked						(SObject* obj, SVariable* var);
	SVariable*				iObj_getIsDocked						(SObject* obj);
	bool					iObj_setDockPosition					(SObject* obj, SVariable* var);
	SVariable*				iObj_getDockPosition					(SObject* obj);
	bool					iObj_setDrawMode						(SObject* obj, SVariable* var);
	SVariable*				iObj_getDrawMode						(SObject* obj);
	bool					iObj_setDrawStyle						(SObject* obj, SVariable* var);
	SVariable*				iObj_getDrawStyle						(SObject* obj);
	bool					iObj_setDrawWidth						(SObject* obj, SVariable* var);
	SVariable*				iObj_getDrawWidth						(SObject* obj);
	bool					iObj_setFillColor						(SObject* obj, SVariable* var);
	SVariable*				iObj_getFillColor						(SObject* obj);
	bool					iObj_setFillStyle						(SObject* obj, SVariable* var);
	SVariable*				iObj_getFillStyle						(SObject* obj);
	bool					iObj_setHalfHeightCaption				(SObject* obj, SVariable* var);
	SVariable*				iObj_getHalfHeightCaption				(SObject* obj);
	bool					iObj_setHScrollSmallChange				(SObject* obj, SVariable* var);
	SVariable*				iObj_getHScrollSmallChange				(SObject* obj);
	bool					iObj_setVScrollSmallChange				(SObject* obj, SVariable* var);
	SVariable*				iObj_getVScrollSmallChange				(SObject* obj);
	bool					iObj_setMacDesktop						(SObject* obj, SVariable* var);
	SVariable*				iObj_getMacDesktop						(SObject* obj);
	bool					iObj_setMdiForm							(SObject* obj, SVariable* var);
	SVariable*				iObj_getMdiForm							(SObject* obj);
	bool					iObj_setOleDragMode						(SObject* obj, SVariable* var);
	SVariable*				iObj_getOleDragMode						(SObject* obj);
	bool					iObj_setOleDragPicture					(SObject* obj, SVariable* var);
	SVariable*				iObj_getOleDragPicture					(SObject* obj);
	bool					iObj_setOleDropEffects					(SObject* obj, SVariable* var);
	SVariable*				iObj_getOleDropEffects					(SObject* obj);
	bool					iObj_setOleDropHasData					(SObject* obj, SVariable* var);
	SVariable*				iObj_getOleDropHasData					(SObject* obj);
	bool					iObj_setOleDropMode						(SObject* obj, SVariable* var);
	SVariable*				iObj_getOleDropMode						(SObject* obj);
	bool					iObj_setReleaseType						(SObject* obj, SVariable* var);
	SVariable*				iObj_getReleaseType						(SObject* obj);
	bool					iObj_setRightToLeft						(SObject* obj, SVariable* var);
	SVariable*				iObj_getRightToLeft						(SObject* obj);
	bool					iObj_setScrollbars						(SObject* obj, SVariable* var);
	SVariable*				iObj_getScrollbars						(SObject* obj);
	bool					iObj_setShowTips						(SObject* obj, SVariable* var);
	SVariable*				iObj_getShowTips						(SObject* obj);
	bool					iObj_setShowWindow						(SObject* obj, SVariable* var);
	SVariable*				iObj_getShowWindow						(SObject* obj);
	bool					iObj_setSizeBox							(SObject* obj, SVariable* var);
	SVariable*				iObj_getSizeBox							(SObject* obj);
	bool					iObj_setThemes							(SObject* obj, SVariable* var);
	SVariable*				iObj_getThemes							(SObject* obj);
	bool					iObj_setTitleBar						(SObject* obj, SVariable* var);
	SVariable*				iObj_getTitleBar						(SObject* obj);
	bool					iObj_setWindowType						(SObject* obj, SVariable* var);
	SVariable*				iObj_getWindowType						(SObject* obj);
	bool					iObj_setZoomBox							(SObject* obj, SVariable* var);
	SVariable*				iObj_getZoomBox							(SObject* obj);









//////////
// Property translation text name to property value
//////
	SPropertyList gsBaseObjectProperties[] = {
		{	cgcName_parent,					sizeof(cgcName_parent) - 1,					_ALL,					(u32)&iObj_setError,							(u32)&iObj_getProperty_parent					},
		{	cgcName_tabIndex,				sizeof(cgcName_tabIndex) - 1,				_ALL,					(u32)&iObj_setProperty_tabIndex,				(u32)&iObj_getProperty_tabIndex					},
		{	cgcName_tabStop,				sizeof(cgcName_tabStop) - 1,				_ALL,					(u32)&iObj_setProperty_tabStop,					(u32)&iObj_getProperty_tabStop					},
		{	cgcName_helpContextId,			sizeof(cgcName_helpContextId) - 1,			_ALL,					(u32)&iObj_setProperty_helpContextId,			(u32)&iObj_getProperty_helpContextId			},
		{	cgcName_hasWhatsThisButton,		sizeof(cgcName_hasWhatsThisButton) - 1,		_ALL,					(u32)&iObj_setProperty_hasWhatsThisButton,		(u32)&iObj_getProperty_hasWhatsThisButton		},
		{	cgcName_hasWhatsThisHelp,		sizeof(cgcName_hasWhatsThisHelp) - 1,		_ALL,					(u32)&iObj_setProperty_hasWhatsThisHelp,		(u32)&iObj_getProperty_hasWhatsThisHelp			},
		{	cgcName_whatsThisHelpId,		sizeof(cgcName_whatsThisHelpId) - 1,		_ALL,					(u32)&iObj_setProperty_whatsThisHelpId,			(u32)&iObj_getProperty_whatsThisHelpId			},
		{	cgcName_name,					sizeof(cgcName_name) - 1,					_ALL,					(u32)&iObj_setProperty_name,					(u32)&iObj_getProperty_name						},
		{	cgcName_className,				sizeof(cgcName_className) - 1,				_ALL,					(u32)&iObj_setError,							(u32)&iObj_getProperty_className				},
		{	cgcName_classLibrary,			sizeof(cgcName_classLibrary) - 1,			_ALL,					(u32)&iObj_setError,							(u32)&iObj_getProperty_classLibrary				},
		{	cgcName_comment,				sizeof(cgcName_comment) - 1,				_ALL,					(u32)&iObj_setProperty_comment,					(u32)&iObj_getProperty_comment					},
		{	cgcName_toolTip,				sizeof(cgcName_toolTip) - 1,				_ALL,					(u32)&iObj_setProperty_toolTip,					(u32)&iObj_getProperty_toolTip					},
		{	cgcName_tag,					sizeof(cgcName_tag) - 1,					_ALL,					(u32)&iObj_setProperty_tag,						(u32)&iObj_getProperty_tag						},
		{	cgcName_mousePointer,			sizeof(cgcName_mousePointer) - 1,			_ALL,					(u32)&iObj_setProperty_mousePointer,			(u32)&iObj_getProperty_mousePointer				},
		{	cgcName_isEnabled,				sizeof(cgcName_isEnabled) - 1,				_ALL,					(u32)&iObj_setProperty_isEnabled,				(u32)&iObj_getProperty_isEnabled				},
		{	cgcName_hasFocus,				sizeof(cgcName_hasFocus) - 1,				_ALL,					(u32)&iObj_setProperty_hasFocus,				(u32)&iObj_getProperty_hasFocus					},
		{	cgcName_isMovable,				sizeof(cgcName_isMovable) - 1,				_ALL,					(u32)&iObj_setProperty_isMovable,				(u32)&iObj_getProperty_isMovable				},
		{	cgcName_isRendered,				sizeof(cgcName_isRendered) - 1,				_ALL,					(u32)&iObj_setProperty_isRendered,				(u32)&iObj_getProperty_isRendered				},
		{	cgcName_isPublished,			sizeof(cgcName_isPublished) - 1,			_ALL,					(u32)&iObj_setProperty_isPublished,				(u32)&iObj_getProperty_isPublished				},
		{	cgcName_isVisible,				sizeof(cgcName_isVisible) - 1,				_ALL,					(u32)&iObj_setProperty_isVisible,				(u32)&iObj_getProperty_isVisible				},
		{	cgcName_isDirty,				sizeof(cgcName_isDirty) - 1,				_ALL,					(u32)&iObj_setProperty_isDirty,					(u32)&iObj_getProperty_isDirty					},
		{	cgcName_left,					sizeof(cgcName_left) - 1,					_ALL,					(u32)&iObj_setProperty_left,					(u32)&iObj_getProperty_left						},
		{	cgcName_top,					sizeof(cgcName_top) - 1,					_ALL,					(u32)&iObj_setProperty_top,						(u32)&iObj_getProperty_top						},
		{	cgcName_width,					sizeof(cgcName_width) - 1,					_ALL,					(u32)&iObj_setProperty_width,					(u32)&iObj_getProperty_width					},
		{	cgcName_height,					sizeof(cgcName_height) - 1,					_ALL,					(u32)&iObj_setProperty_height,					(u32)&iObj_getProperty_height					},
		{	cgcName_anchor,					sizeof(cgcName_anchor) - 1,					_ALL,					(u32)&iObj_setProperty_anchor,					(u32)&iObj_getProperty_anchor					},
		{	cgcName_scrollX,				sizeof(cgcName_scrollX) - 1,				_ALL,					(u32)&iObj_setProperty_scrollX,					(u32)&iObj_getProperty_scrollX					},
		{	cgcName_scrollY,				sizeof(cgcName_scrollY) - 1,				_ALL,					(u32)&iObj_setProperty_scrollY,					(u32)&iObj_getProperty_scrollY					},
		{	cgcName_scaleX,					sizeof(cgcName_scaleX) - 1,					_ALL,					(u32)&iObj_setProperty_scaleX,					(u32)&iObj_getProperty_scaleX					},
		{	cgcName_scaleY,					sizeof(cgcName_scaleY) - 1,					_ALL,					(u32)&iObj_setProperty_scaleY,					(u32)&iObj_getProperty_scaleY					},
		{	cgcName_minLeft,				sizeof(cgcName_minLeft) - 1,				_FORM + _SUBFORM,		(u32)&iObj_setMinLeft,                 (u32)&iObj_getMinLeft					},
		{	cgcName_minTop,					sizeof(cgcName_minTop) - 1,					_FORM + _SUBFORM,		(u32)&iObj_setMinTop,                  (u32)&iObj_getMinTop					},
		{	cgcName_minWidth,				sizeof(cgcName_minWidth) - 1,				_FORM + _SUBFORM,		(u32)&iObj_setMinWidth,                (u32)&iObj_getMinWidth					},
		{	cgcName_minHeight,				sizeof(cgcName_minHeight) - 1,				_FORM + _SUBFORM,		(u32)&iObj_setMinHeight,               (u32)&iObj_getMinHeight				},
		{	cgcName_maxLeft,				sizeof(cgcName_maxLeft) - 1,				_FORM + _SUBFORM,		(u32)&iObj_setMaxLeft,                 (u32)&iObj_getMaxLeft					},
		{	cgcName_maxTop,					sizeof(cgcName_maxTop) - 1,					_FORM + _SUBFORM,		(u32)&iObj_setMaxTop,                  (u32)&iObj_getMaxTop					},
		{	cgcName_maxWidth,				sizeof(cgcName_maxWidth) - 1,				_FORM + _SUBFORM,		(u32)&iObj_setMaxWidth,                (u32)&iObj_getMaxWidth					},
		{	cgcName_maxHeight,				sizeof(cgcName_maxHeight) - 1,				_FORM + _SUBFORM,		(u32)&iObj_setMaxHeight,               (u32)&iObj_getMaxHeight				},
		{	cgcName_fontName,				sizeof(cgcName_fontName) - 1,				_FORM + _SUBFORM,		(u32)&iObj_setFontName,                (u32)&iObj_getFontName					},
		{	cgcName_fontSize,				sizeof(cgcName_fontSize) - 1,				_FORM + _SUBFORM,		(u32)&iObj_setFontSize,                (u32)&iObj_getFontSize					},
		{	cgcName_fontBold,				sizeof(cgcName_fontBold) - 1,				_FORM + _SUBFORM,		(u32)&iObj_setFontBold,                (u32)&iObj_getFontBold					},
		{	cgcName_fontItalic,				sizeof(cgcName_fontItalic) - 1,				_FORM + _SUBFORM,		(u32)&iObj_setFontItalic,              (u32)&iObj_getFontItalic				},
		{	cgcName_fontUnderline,			sizeof(cgcName_fontUnderline) - 1,			_FORM + _SUBFORM,		(u32)&iObj_setFontUnderline,           (u32)&iObj_getFontUnderline			},
		{	cgcName_fontStrikethrough,		sizeof(cgcName_fontStrikethrough) - 1,		_FORM + _SUBFORM,		(u32)&iObj_setFontStrikethrough,       (u32)&iObj_getFontStrikethrough		},
		{	cgcName_fontCondensed,			sizeof(cgcName_fontCondensed) - 1,			_FORM + _SUBFORM,		(u32)&iObj_setFontCondensed,           (u32)&iObj_getFontCondensed			},
		{	cgcName_fontExtended,			sizeof(cgcName_fontExtended) - 1,			_FORM + _SUBFORM,		(u32)&iObj_setFontExtended,            (u32)&iObj_getFontExtended				},
		{	cgcName_fontOutline,			sizeof(cgcName_fontOutline) - 1,			_FORM + _SUBFORM,		(u32)&iObj_setFontOutline,             (u32)&iObj_getFontOutline				},
		{	cgcName_fontShadow,				sizeof(cgcName_fontShadow) - 1,				_FORM + _SUBFORM,		(u32)&iObj_setFontShadow,              (u32)&iObj_getFontShadow				},
		{	cgcName_nwColor,				sizeof(cgcName_nwColor) - 1,				_FORM + _SUBFORM,		(u32)&iObj_setNwColor,                 (u32)&iObj_getNwColor					},
		{	cgcName_neColor,				sizeof(cgcName_neColor) - 1,				_FORM + _SUBFORM,		(u32)&iObj_setNeColor,                 (u32)&iObj_getNeColor					},
		{	cgcName_swColor,				sizeof(cgcName_swColor) - 1,				_FORM + _SUBFORM,		(u32)&iObj_setSwColor,                 (u32)&iObj_getSwColor					},
		{	cgcName_seColor,				sizeof(cgcName_seColor) - 1,				_FORM + _SUBFORM,		(u32)&iObj_setSeColor,                 (u32)&iObj_getSeColor					},
		{	cgcName_backColor,				sizeof(cgcName_backColor) - 1,				_FORM + _SUBFORM,		(u32)&iObj_setBackColor,               (u32)&iObj_getBackColor				},
		{	cgcName_foreColor,				sizeof(cgcName_foreColor) - 1,				_FORM + _SUBFORM,		(u32)&iObj_setForeColor,               (u32)&iObj_getForeColor				},
		{	cgcName_captionColor,			sizeof(cgcName_captionColor) - 1,			_FORM + _SUBFORM,		(u32)&iObj_setCaptionColor,            (u32)&iObj_getCaptionColor				},
		{	cgcName_caption,				sizeof(cgcName_caption) - 1,				_FORM + _SUBFORM,		(u32)&iObj_setCaption,                 (u32)&iObj_getCaption					},
		{	cgcName_picture,				sizeof(cgcName_picture) - 1,				_FORM + _SUBFORM,		(u32)&iObj_setPicture,                 (u32)&iObj_getPicture					},
		{	cgcName_allowOutput,			sizeof(cgcName_allowOutput) - 1,			_FORM + _SUBFORM,		(u32)&iObj_setAllowOutput,             (u32)&iObj_getAllowOutput				},
		{	cgcName_alwaysOnBottom,			sizeof(cgcName_alwaysOnBottom) - 1,			_FORM,					(u32)&iObj_setAlwaysOnBottom,          (u32)&iObj_getAlwaysOnBottom			},
		{	cgcName_alwaysOnTop,			sizeof(cgcName_alwaysOnTop) - 1,			_FORM,					(u32)&iObj_setAlwaysOnTop,             (u32)&iObj_getAlwaysOnTop				},
		{	cgcName_autoCenter,				sizeof(cgcName_autoCenter) - 1,				_FORM,					(u32)&iObj_setAutoCenter,              (u32)&iObj_getAutoCenter				},
		{	cgcName_borderStyle,			sizeof(cgcName_borderStyle) - 1,			_FORM + _SUBFORM,		(u32)&iObj_setBorderStyle,             (u32)&iObj_getBorderStyle				},
		{	cgcName_isCloseable,			sizeof(cgcName_isCloseable) - 1,			_FORM,					(u32)&iObj_setIsCloseable,             (u32)&iObj_getIsCloseable				},
		{	cgcName_processKeyPreviewEvents,sizeof(cgcName_processKeyPreviewEvents) - 1,_FORM + _SUBFORM,		(u32)&iObj_setProcessKeyPreviewEvents, (u32)&iObj_getProcessKeyPreviewEvents	},
		{	cgcName_hasControlBox,			sizeof(cgcName_hasControlBox) - 1,			_FORM,					(u32)&iObj_setHasControlBox,           (u32)&iObj_getHasControlBox			},
		{	cgcName_hasMinButton,			sizeof(cgcName_hasMinButton) - 1,			_FORM,					(u32)&iObj_setHasMinButton,            (u32)&iObj_getHasMinButton				},
		{	cgcName_hasCloseButton,			sizeof(cgcName_hasCloseButton) - 1,			_FORM,					(u32)&iObj_setHasCloseButton,          (u32)&iObj_getHasCloseButton			},
		{	cgcName_scaleMode,				sizeof(cgcName_scaleMode) - 1,				_FORM + _SUBFORM,		(u32)&iObj_setScaleMode,               (u32)&iObj_getScaleMode				},
		{	cgcName_showInTaskBar,			sizeof(cgcName_showInTaskBar) - 1,			_FORM,					(u32)&iObj_setShowInTaskBar,           (u32)&iObj_getShowInTaskBar			},
		{	cgcName_windowState,			sizeof(cgcName_windowState) - 1,			_FORM + _SUBFORM,		(u32)&iObj_setWindowState,             (u32)&iObj_getWindowState				},
		{	cgcName_bindControls,			sizeof(cgcName_bindControls) - 1,			_FORM,					(u32)&iObj_setBindControls,            (u32)&iObj_getBindControls				},
		{	cgcName_bufferMode,				sizeof(cgcName_bufferMode) - 1,				_FORM,					(u32)&iObj_setBufferMode,              (u32)&iObj_getBufferMode				},
		{	cgcName_clipControls,			sizeof(cgcName_clipControls) - 1,			_FORM,					(u32)&iObj_setClipControls,            (u32)&iObj_getClipControls				},
		{	cgcName_colorSource,			sizeof(cgcName_colorSource) - 1,			_FORM,					(u32)&iObj_setColorSource,             (u32)&iObj_getColorSource				},
		{	cgcName_continuousScroll,		sizeof(cgcName_continuousScroll) - 1,		_FORM,					(u32)&iObj_setContinuousScroll,        (u32)&iObj_getContinuousScroll			},
		{	cgcName_dataSession,			sizeof(cgcName_dataSession) - 1,			_FORM,					(u32)&iObj_setDataSession,             (u32)&iObj_getDataSession				},
		{	cgcName_dataSessionId,			sizeof(cgcName_dataSessionId) - 1,			_FORM,					(u32)&iObj_setDataSessionId,           (u32)&iObj_getDataSessionId			},
		{	cgcName_deClass,				sizeof(cgcName_deClass) - 1,				_FORM,					(u32)&iObj_setDeClass,                 (u32)&iObj_getDeClass					},
		{	cgcName_deClassLibrary,			sizeof(cgcName_deClassLibrary) - 1,			_FORM,					(u32)&iObj_setDeClassLibrary,          (u32)&iObj_getDeClassLibrary			},
		{	cgcName_defOleCid,				sizeof(cgcName_defOleCid) - 1,				_FORM,					(u32)&iObj_setDefOleCid,               (u32)&iObj_getDefOleCid				},
		{	cgcName_desktop,				sizeof(cgcName_desktop) - 1,				_FORM,					(u32)&iObj_setDesktop,                 (u32)&iObj_getDesktop					},
		{	cgcName_isDockable,				sizeof(cgcName_isDockable) - 1,				_FORM,					(u32)&iObj_setIsDockable,              (u32)&iObj_getIsDockable				},
		{	cgcName_isDocked,				sizeof(cgcName_isDocked) - 1,				_FORM,					(u32)&iObj_setIsDocked,                (u32)&iObj_getIsDocked					},
		{	cgcName_dockPosition,			sizeof(cgcName_dockPosition) - 1,			_FORM,					(u32)&iObj_setDockPosition,            (u32)&iObj_getDockPosition				},
		{	cgcName_drawMode,				sizeof(cgcName_drawMode) - 1,				_FORM,					(u32)&iObj_setDrawMode,                (u32)&iObj_getDrawMode					},
		{	cgcName_drawStyle,				sizeof(cgcName_drawStyle) - 1,				_FORM,					(u32)&iObj_setDrawStyle,               (u32)&iObj_getDrawStyle				},
		{	cgcName_drawWidth,				sizeof(cgcName_drawWidth) - 1,				_FORM,					(u32)&iObj_setDrawWidth,               (u32)&iObj_getDrawWidth				},
		{	cgcName_fillColor,				sizeof(cgcName_fillColor) - 1,				_FORM,					(u32)&iObj_setFillColor,               (u32)&iObj_getFillColor				},
		{	cgcName_fillStyle,				sizeof(cgcName_fillStyle) - 1,				_FORM,					(u32)&iObj_setFillStyle,               (u32)&iObj_getFillStyle				},
		{	cgcName_halfHeightCaption,		sizeof(cgcName_halfHeightCaption) - 1,		_FORM,					(u32)&iObj_setHalfHeightCaption,       (u32)&iObj_getHalfHeightCaption		},
		{	cgcName_hScrollSmallChange,		sizeof(cgcName_hScrollSmallChange) - 1,		_FORM,					(u32)&iObj_setHScrollSmallChange,      (u32)&iObj_getHScrollSmallChange		},
		{	cgcName_vScrollSmallChange,		sizeof(cgcName_vScrollSmallChange) - 1,		_FORM,					(u32)&iObj_setVScrollSmallChange,      (u32)&iObj_getVScrollSmallChange		},
		{	cgcName_macDesktop,				sizeof(cgcName_macDesktop) - 1,				_FORM,					(u32)&iObj_setMacDesktop,              (u32)&iObj_getMacDesktop				},
		{	cgcName_mdiForm,				sizeof(cgcName_mdiForm) - 1,				_FORM,					(u32)&iObj_setMdiForm,                 (u32)&iObj_getMdiForm					},
		{	cgcName_oleDragMode,			sizeof(cgcName_oleDragMode) - 1,			_FORM,					(u32)&iObj_setOleDragMode,             (u32)&iObj_getOleDragMode				},
		{	cgcName_oleDragPicture,			sizeof(cgcName_oleDragPicture) - 1,			_FORM,					(u32)&iObj_setError,							(u32)&iObj_getError								},
		{	cgcName_oleDropEffects,			sizeof(cgcName_oleDropEffects) - 1,			_FORM,					(u32)&iObj_setOleDropEffects,          (u32)&iObj_getOleDropEffects			},
		{	cgcName_oleDropHasData,			sizeof(cgcName_oleDropHasData) - 1,			_FORM,					(u32)&iObj_setOleDropHasData,          (u32)&iObj_getOleDropHasData			},
		{	cgcName_oleDropMode,			sizeof(cgcName_oleDropMode) - 1,			_FORM,					(u32)&iObj_setOleDropMode,             (u32)&iObj_getOleDropMode				},
		{	cgcName_releaseType,			sizeof(cgcName_releaseType) - 1,			_FORM,					(u32)&iObj_setReleaseType,             (u32)&iObj_getReleaseType				},
		{	cgcName_rightToLeft,			sizeof(cgcName_rightToLeft) - 1,			_FORM,					(u32)&iObj_setRightToLeft,             (u32)&iObj_getRightToLeft				},
		{	cgcName_scrollbars,				sizeof(cgcName_scrollbars) - 1,				_FORM,					(u32)&iObj_setScrollbars,              (u32)&iObj_getScrollbars				},
		{	cgcName_showTips,				sizeof(cgcName_showTips) - 1,				_FORM,					(u32)&iObj_setShowTips,                (u32)&iObj_getShowTips					},
		{	cgcName_showWindow,				sizeof(cgcName_showWindow) - 1,				_FORM,					(u32)&iObj_setShowWindow,              (u32)&iObj_getShowWindow				},
		{	cgcName_sizeBox,				sizeof(cgcName_sizeBox) - 1,				_FORM,					(u32)&iObj_setSizeBox,                 (u32)&iObj_getSizeBox					},
		{	cgcName_themes,					sizeof(cgcName_themes) - 1,					_FORM,					(u32)&iObj_setThemes,                  (u32)&iObj_getThemes					},
		{	cgcName_titleBar,				sizeof(cgcName_titleBar) - 1,				_FORM,					(u32)&iObj_setTitleBar,                (u32)&iObj_getTitleBar					},
		{	cgcName_windowType,				sizeof(cgcName_windowType) - 1,				_FORM,					(u32)&iObj_setWindowType,              (u32)&iObj_getWindowType				},
		{	cgcName_zoomBox,				sizeof(cgcName_zoomBox) - 1,				_FORM,					(u32)&iObj_setZoomBox,                 (u32)&iObj_getZoomBox					},
		// Note:  Do not delete this line, it is used to terminate the search list
		{	0, 0, 0, 0	}
	};


//////////
// Baseclass translation text name to objType, and objType to full record
//////
	SBaseclassList gsKnownBaseclasses[] = {
		//	objType					Text name				Length of name						Base object property list
		//  ------------------		-----------------		-------------------------------		-------------------------------
		{	_OBJ_TYPE_EMPTY,		cgcName_empty,			sizeof(cgcName_empty)		- 1,	(u32)&gsBaseObjectProperties[0]		},
		{	_OBJ_TYPE_FORM,			cgcName_form,			sizeof(cgcName_form)		- 1,	(u32)&gsBaseObjectProperties[0]		},
		{	_OBJ_TYPE_SUBFORM,		cgcName_subform,		sizeof(cgcName_subform)		- 1,	(u32)&gsBaseObjectProperties[0]		},
		{	_OBJ_TYPE_LABEL,		cgcName_label,			sizeof(cgcName_label)		- 1,	(u32)&gsBaseObjectProperties[0]		},
		{	_OBJ_TYPE_TEXTBOX,		cgcName_textbox,		sizeof(cgcName_textbox)		- 1,	(u32)&gsBaseObjectProperties[0]		},
		{	_OBJ_TYPE_BUTTON,		cgcName_button,			sizeof(cgcName_button)		- 1,	(u32)&gsBaseObjectProperties[0]		},
		{	_OBJ_TYPE_EDITBOX,		cgcName_editbox,		sizeof(cgcName_editbox)		- 1,	(u32)&gsBaseObjectProperties[0]		},
		{	_OBJ_TYPE_IMAGE,		cgcName_image,			sizeof(cgcName_image)		- 1,	(u32)&gsBaseObjectProperties[0]		},
		{	_OBJ_TYPE_CHECKBOX,		cgcName_checkbox,		sizeof(cgcName_checkbox)	- 1,	(u32)&gsBaseObjectProperties[0]		},
		{	_OBJ_TYPE_OPTION,		cgcName_option,			sizeof(cgcName_option)		- 1,	(u32)&gsBaseObjectProperties[0]		},
		{	_OBJ_TYPE_RADIO,		cgcName_radio,			sizeof(cgcName_radio)		- 1,	(u32)&gsBaseObjectProperties[0]		},
		// Note:  Do not delete this line, it is used to terminate the search list
		{	0,						NULL,					0,									0	}
	};




//////////
// Define the setters and getters
//////
	bool		iObj_set_activeColumn						(SObject* obj, SVariable* var);
	bool		iObj_set_activeControl						(SObject* obj, SVariable* var);
	bool		iObj_set_activeForm							(SObject* obj, SVariable* var);
	bool		iObj_set_activePage							(SObject* obj, SVariable* var);
	bool		iObj_set_activeRow							(SObject* obj, SVariable* var);
	bool		iObj_set_addLineFeeds						(SObject* obj, SVariable* var);
	bool		iObj_set_align								(SObject* obj, SVariable* var);
	bool		iObj_set_alignment							(SObject* obj, SVariable* var);
	bool		iObj_set_allowAddNew						(SObject* obj, SVariable* var);
	bool		iObj_set_allowAutoColumnFit					(SObject* obj, SVariable* var);
	bool		iObj_set_allowCellSelection					(SObject* obj, SVariable* var);
	bool		iObj_set_allowHeaderSizing					(SObject* obj, SVariable* var);
	bool		iObj_set_allowOutput						(SObject* obj, SVariable* var);
	bool		iObj_set_allowRowSizing						(SObject* obj, SVariable* var);
	bool		iObj_set_allowTabs							(SObject* obj, SVariable* var);
	bool		iObj_set_alwaysOnBottom						(SObject* obj, SVariable* var);
	bool		iObj_set_alwaysOnTop						(SObject* obj, SVariable* var);
	bool		iObj_set_anchor								(SObject* obj, SVariable* var);
	bool		iObj_set_application						(SObject* obj, SVariable* var);
	bool		iObj_set_autoActivate						(SObject* obj, SVariable* var);
	bool		iObj_set_autoCenter							(SObject* obj, SVariable* var);
	bool		iObj_set_autoCompSource						(SObject* obj, SVariable* var);
	bool		iObj_set_autoCompTable						(SObject* obj, SVariable* var);
	bool		iObj_set_autoComplete						(SObject* obj, SVariable* var);
	bool		iObj_set_autoHideScrollBar					(SObject* obj, SVariable* var);
	bool		iObj_set_autoRelease						(SObject* obj, SVariable* var);
	bool		iObj_set_autoSize							(SObject* obj, SVariable* var);
	bool		iObj_set_autoVerbMenu						(SObject* obj, SVariable* var);
	bool		iObj_set_backColor							(SObject* obj, SVariable* var);
	bool		iObj_set_backStyle							(SObject* obj, SVariable* var);
	bool		iObj_set_baseClass							(SObject* obj, SVariable* var);
	bool		iObj_set_bindControls						(SObject* obj, SVariable* var);
	bool		iObj_set_borderColor						(SObject* obj, SVariable* var);
	bool		iObj_set_borderStyle						(SObject* obj, SVariable* var);
	bool		iObj_set_borderWidth						(SObject* obj, SVariable* var);
	bool		iObj_set_bound								(SObject* obj, SVariable* var);
	bool		iObj_set_boundColumn						(SObject* obj, SVariable* var);
	bool		iObj_set_boundTo							(SObject* obj, SVariable* var);
	bool		iObj_set_bufferMode							(SObject* obj, SVariable* var);
	bool		iObj_set_buttonCount						(SObject* obj, SVariable* var);
	bool		iObj_set_cancel								(SObject* obj, SVariable* var);
	bool		iObj_set_caption							(SObject* obj, SVariable* var);
	bool		iObj_set_centered							(SObject* obj, SVariable* var);
	bool		iObj_set_century							(SObject* obj, SVariable* var);
	bool		iObj_set_childOrder							(SObject* obj, SVariable* var);
	bool		iObj_set_class								(SObject* obj, SVariable* var);
	bool		iObj_set_classLibrary						(SObject* obj, SVariable* var);
	bool		iObj_set_clipControls						(SObject* obj, SVariable* var);
	bool		iObj_set_closable							(SObject* obj, SVariable* var);
	bool		iObj_set_colorScheme						(SObject* obj, SVariable* var);
	bool		iObj_set_colorSource						(SObject* obj, SVariable* var);
	bool		iObj_set_columnCount						(SObject* obj, SVariable* var);
	bool		iObj_set_columnLines						(SObject* obj, SVariable* var);
	bool		iObj_set_columnOrder						(SObject* obj, SVariable* var);
	bool		iObj_set_columnWidths						(SObject* obj, SVariable* var);
	bool		iObj_set_columns							(SObject* obj, SVariable* var);
	bool		iObj_set_comment							(SObject* obj, SVariable* var);
	bool		iObj_set_continuousScroll					(SObject* obj, SVariable* var);
	bool		iObj_set_controlBox							(SObject* obj, SVariable* var);
	bool		iObj_set_controlCount						(SObject* obj, SVariable* var);
	bool		iObj_set_controlSource						(SObject* obj, SVariable* var);
	bool		iObj_set_controls							(SObject* obj, SVariable* var);
	bool		iObj_set_count								(SObject* obj, SVariable* var);
	bool		iObj_set_currentControl						(SObject* obj, SVariable* var);
	bool		iObj_set_currentX							(SObject* obj, SVariable* var);
	bool		iObj_set_currentY							(SObject* obj, SVariable* var);
	bool		iObj_set_curvature							(SObject* obj, SVariable* var);
	bool		iObj_set_dEClass							(SObject* obj, SVariable* var);
	bool		iObj_set_dEClassLibrary						(SObject* obj, SVariable* var);
	bool		iObj_set_dataEnvironment					(SObject* obj, SVariable* var);
	bool		iObj_set_dataSession						(SObject* obj, SVariable* var);
	bool		iObj_set_dataSessionID						(SObject* obj, SVariable* var);
	bool		iObj_set_dateFormat							(SObject* obj, SVariable* var);
	bool		iObj_set_dateMark							(SObject* obj, SVariable* var);
	bool		iObj_set_defOLELCID							(SObject* obj, SVariable* var);
	bool		iObj_set_default							(SObject* obj, SVariable* var);
	bool		iObj_set_deleteMark							(SObject* obj, SVariable* var);
	bool		iObj_set_desktop							(SObject* obj, SVariable* var);
	bool		iObj_set_details							(SObject* obj, SVariable* var);
	bool		iObj_set_disabledBackColor					(SObject* obj, SVariable* var);
	bool		iObj_set_disabledForeColor					(SObject* obj, SVariable* var);
	bool		iObj_set_disabledItemBackColor				(SObject* obj, SVariable* var);
	bool		iObj_set_disabledItemForeColor				(SObject* obj, SVariable* var);
	bool		iObj_set_disabledPicture					(SObject* obj, SVariable* var);
	bool		iObj_set_displayCount						(SObject* obj, SVariable* var);
	bool		iObj_set_displayValue						(SObject* obj, SVariable* var);
	bool		iObj_set_doCreate							(SObject* obj, SVariable* var);
	bool		iObj_set_dockPosition						(SObject* obj, SVariable* var);
	bool		iObj_set_dockable							(SObject* obj, SVariable* var);
	bool		iObj_set_docked								(SObject* obj, SVariable* var);
	bool		iObj_set_documentFile						(SObject* obj, SVariable* var);
	bool		iObj_set_downPicture						(SObject* obj, SVariable* var);
	bool		iObj_set_dragIcon							(SObject* obj, SVariable* var);
	bool		iObj_set_dragMode							(SObject* obj, SVariable* var);
	bool		iObj_set_drawMode							(SObject* obj, SVariable* var);
	bool		iObj_set_drawStyle							(SObject* obj, SVariable* var);
	bool		iObj_set_drawWidth							(SObject* obj, SVariable* var);
	bool		iObj_set_dynamicAlignment					(SObject* obj, SVariable* var);
	bool		iObj_set_dynamicBackColor					(SObject* obj, SVariable* var);
	bool		iObj_set_dynamicCurrentControl				(SObject* obj, SVariable* var);
	bool		iObj_set_dynamicFontBold					(SObject* obj, SVariable* var);
	bool		iObj_set_dynamicFontItalic					(SObject* obj, SVariable* var);
	bool		iObj_set_dynamicFontName					(SObject* obj, SVariable* var);
	bool		iObj_set_dynamicFontOutline					(SObject* obj, SVariable* var);
	bool		iObj_set_dynamicFontShadow					(SObject* obj, SVariable* var);
	bool		iObj_set_dynamicFontSize					(SObject* obj, SVariable* var);
	bool		iObj_set_dynamicFontStrikeThru				(SObject* obj, SVariable* var);
	bool		iObj_set_dynamicFontUnderline				(SObject* obj, SVariable* var);
	bool		iObj_set_dynamicForeColor					(SObject* obj, SVariable* var);
	bool		iObj_set_dynamicInputMask					(SObject* obj, SVariable* var);
	bool		iObj_set_enableHyperlinks					(SObject* obj, SVariable* var);
	bool		iObj_set_enabled							(SObject* obj, SVariable* var);
	bool		iObj_set_errorNo							(SObject* obj, SVariable* var);
	bool		iObj_set_fillColor							(SObject* obj, SVariable* var);
	bool		iObj_set_fillStyle							(SObject* obj, SVariable* var);
	bool		iObj_set_firstElement						(SObject* obj, SVariable* var);
	bool		iObj_set_fontBold							(SObject* obj, SVariable* var);
	bool		iObj_set_fontCharSet						(SObject* obj, SVariable* var);
	bool		iObj_set_fontCondense						(SObject* obj, SVariable* var);
	bool		iObj_set_fontExtend							(SObject* obj, SVariable* var);
	bool		iObj_set_fontItalic							(SObject* obj, SVariable* var);
	bool		iObj_set_fontName							(SObject* obj, SVariable* var);
	bool		iObj_set_fontOutline						(SObject* obj, SVariable* var);
	bool		iObj_set_fontShadow							(SObject* obj, SVariable* var);
	bool		iObj_set_fontSize							(SObject* obj, SVariable* var);
	bool		iObj_set_fontStrikeThru						(SObject* obj, SVariable* var);
	bool		iObj_set_fontUnderLine						(SObject* obj, SVariable* var);
	bool		iObj_set_fontUnderline						(SObject* obj, SVariable* var);
	bool		iObj_set_foreColor							(SObject* obj, SVariable* var);
	bool		iObj_set_formCount							(SObject* obj, SVariable* var);
	bool		iObj_set_format								(SObject* obj, SVariable* var);
	bool		iObj_set_forms								(SObject* obj, SVariable* var);
	bool		iObj_set_gridLineColor						(SObject* obj, SVariable* var);
	bool		iObj_set_gridLineWidth						(SObject* obj, SVariable* var);
	bool		iObj_set_gridLines							(SObject* obj, SVariable* var);
	bool		iObj_set_hScrollSmallChange					(SObject* obj, SVariable* var);
	bool		iObj_set_hWnd								(SObject* obj, SVariable* var);
	bool		iObj_set_halfHeightCaption					(SObject* obj, SVariable* var);
	bool		iObj_set_headerClass						(SObject* obj, SVariable* var);
	bool		iObj_set_headerClassLibrary					(SObject* obj, SVariable* var);
	bool		iObj_set_headerHeight						(SObject* obj, SVariable* var);
	bool		iObj_set_height								(SObject* obj, SVariable* var);
	bool		iObj_set_helpContextID						(SObject* obj, SVariable* var);
	bool		iObj_set_hideSelection						(SObject* obj, SVariable* var);
	bool		iObj_set_highLight							(SObject* obj, SVariable* var);
	bool		iObj_set_highLightRow						(SObject* obj, SVariable* var);
	bool		iObj_set_highlightBackColor					(SObject* obj, SVariable* var);
	bool		iObj_set_highlightForeColor					(SObject* obj, SVariable* var);
	bool		iObj_set_highlightRowLineWidth				(SObject* obj, SVariable* var);
	bool		iObj_set_highlightStyle						(SObject* obj, SVariable* var);
	bool		iObj_set_hostName							(SObject* obj, SVariable* var);
	bool		iObj_set_hours								(SObject* obj, SVariable* var);
	bool		iObj_set_iMEMode							(SObject* obj, SVariable* var);
	bool		iObj_set_icon								(SObject* obj, SVariable* var);
	bool		iObj_set_increment							(SObject* obj, SVariable* var);
	bool		iObj_set_incrementalSearch					(SObject* obj, SVariable* var);
	bool		iObj_set_inputMask							(SObject* obj, SVariable* var);
	bool		iObj_set_integralHeight						(SObject* obj, SVariable* var);
	bool		iObj_set_interval							(SObject* obj, SVariable* var);
	bool		iObj_set_itemBackColor						(SObject* obj, SVariable* var);
	bool		iObj_set_itemData							(SObject* obj, SVariable* var);
	bool		iObj_set_itemForeColor						(SObject* obj, SVariable* var);
	bool		iObj_set_itemIDData							(SObject* obj, SVariable* var);
	bool		iObj_set_itemTips							(SObject* obj, SVariable* var);
	bool		iObj_set_keyPreview							(SObject* obj, SVariable* var);
	bool		iObj_set_keySort							(SObject* obj, SVariable* var);
	bool		iObj_set_keyboardHighValue					(SObject* obj, SVariable* var);
	bool		iObj_set_keyboardLowValue					(SObject* obj, SVariable* var);
	bool		iObj_set_left								(SObject* obj, SVariable* var);
	bool		iObj_set_leftColumn							(SObject* obj, SVariable* var);
	bool		iObj_set_lineContents						(SObject* obj, SVariable* var);
	bool		iObj_set_lineNo								(SObject* obj, SVariable* var);
	bool		iObj_set_lineSlant							(SObject* obj, SVariable* var);
	bool		iObj_set_linkMaster							(SObject* obj, SVariable* var);
	bool		iObj_set_list								(SObject* obj, SVariable* var);
	bool		iObj_set_listCount							(SObject* obj, SVariable* var);
	bool		iObj_set_listIndex							(SObject* obj, SVariable* var);
	bool		iObj_set_listItem							(SObject* obj, SVariable* var);
	bool		iObj_set_listItemID							(SObject* obj, SVariable* var);
	bool		iObj_set_lockColumns						(SObject* obj, SVariable* var);
	bool		iObj_set_lockColumnsLeft					(SObject* obj, SVariable* var);
	bool		iObj_set_lockScreen							(SObject* obj, SVariable* var);
	bool		iObj_set_mDIForm							(SObject* obj, SVariable* var);
	bool		iObj_set_macDesktop							(SObject* obj, SVariable* var);
	bool		iObj_set_margin								(SObject* obj, SVariable* var);
	bool		iObj_set_maxButton							(SObject* obj, SVariable* var);
	bool		iObj_set_maxHeight							(SObject* obj, SVariable* var);
	bool		iObj_set_maxLeft							(SObject* obj, SVariable* var);
	bool		iObj_set_maxLength							(SObject* obj, SVariable* var);
	bool		iObj_set_maxTop								(SObject* obj, SVariable* var);
	bool		iObj_set_maxWidth							(SObject* obj, SVariable* var);
	bool		iObj_set_memberClass						(SObject* obj, SVariable* var);
	bool		iObj_set_memberClassLibrary					(SObject* obj, SVariable* var);
	bool		iObj_set_memoWindow							(SObject* obj, SVariable* var);
	bool		iObj_set_message							(SObject* obj, SVariable* var);
	bool		iObj_set_minButton							(SObject* obj, SVariable* var);
	bool		iObj_set_minHeight							(SObject* obj, SVariable* var);
	bool		iObj_set_minWidth							(SObject* obj, SVariable* var);
	bool		iObj_set_mouseIcon							(SObject* obj, SVariable* var);
	bool		iObj_set_mousePointer						(SObject* obj, SVariable* var);
	bool		iObj_set_movable							(SObject* obj, SVariable* var);
	bool		iObj_set_moverBars							(SObject* obj, SVariable* var);
	bool		iObj_set_multiSelect						(SObject* obj, SVariable* var);
	bool		iObj_set_name								(SObject* obj, SVariable* var);
	bool		iObj_set_newIndex							(SObject* obj, SVariable* var);
	bool		iObj_set_newItemID							(SObject* obj, SVariable* var);
	bool		iObj_set_nullDisplay						(SObject* obj, SVariable* var);
	bool		iObj_set_numberOfElements					(SObject* obj, SVariable* var);
	bool		iObj_set_oLEClass							(SObject* obj, SVariable* var);
	bool		iObj_set_oLEDragMode						(SObject* obj, SVariable* var);
	bool		iObj_set_oLEDragPicture						(SObject* obj, SVariable* var);
	bool		iObj_set_oLEDropEffects						(SObject* obj, SVariable* var);
	bool		iObj_set_oLEDropHasData						(SObject* obj, SVariable* var);
	bool		iObj_set_oLEDropMode						(SObject* obj, SVariable* var);
	bool		iObj_set_oLEDropTextInsertion				(SObject* obj, SVariable* var);
	bool		iObj_set_oLELCID							(SObject* obj, SVariable* var);
	bool		iObj_set_oLETypeAllowed						(SObject* obj, SVariable* var);
	bool		iObj_set_object								(SObject* obj, SVariable* var);
	bool		iObj_set_objects							(SObject* obj, SVariable* var);
	bool		iObj_set_openWindow							(SObject* obj, SVariable* var);
	bool		iObj_set_optimize							(SObject* obj, SVariable* var);
	bool		iObj_set_pageCount							(SObject* obj, SVariable* var);
	bool		iObj_set_pageHeight							(SObject* obj, SVariable* var);
	bool		iObj_set_pageOrder							(SObject* obj, SVariable* var);
	bool		iObj_set_pageWidth							(SObject* obj, SVariable* var);
	bool		iObj_set_pages								(SObject* obj, SVariable* var);
	bool		iObj_set_panel								(SObject* obj, SVariable* var);
	bool		iObj_set_panelLink							(SObject* obj, SVariable* var);
	bool		iObj_set_parent								(SObject* obj, SVariable* var);
	bool		iObj_set_parentClass						(SObject* obj, SVariable* var);
	bool		iObj_set_partition							(SObject* obj, SVariable* var);
	bool		iObj_set_passwordChar						(SObject* obj, SVariable* var);
	bool		iObj_set_picture							(SObject* obj, SVariable* var);
	bool		iObj_set_pictureMargin						(SObject* obj, SVariable* var);
	bool		iObj_set_picturePosition					(SObject* obj, SVariable* var);
	bool		iObj_set_pictureSelectionDisplay			(SObject* obj, SVariable* var);
	bool		iObj_set_pictureSpacing						(SObject* obj, SVariable* var);
	bool		iObj_set_pictureVal							(SObject* obj, SVariable* var);
	bool		iObj_set_polyPoints							(SObject* obj, SVariable* var);
	bool		iObj_set_procedure							(SObject* obj, SVariable* var);
	bool		iObj_set_readBackColor						(SObject* obj, SVariable* var);
	bool		iObj_set_readCycle							(SObject* obj, SVariable* var);
	bool		iObj_set_readForeColor						(SObject* obj, SVariable* var);
	bool		iObj_set_readLock							(SObject* obj, SVariable* var);
	bool		iObj_set_readMouse							(SObject* obj, SVariable* var);
	bool		iObj_set_readOnly							(SObject* obj, SVariable* var);
	bool		iObj_set_readSave							(SObject* obj, SVariable* var);
	bool		iObj_set_readTimeOut						(SObject* obj, SVariable* var);
	bool		iObj_set_recordMark							(SObject* obj, SVariable* var);
	bool		iObj_set_recordSource						(SObject* obj, SVariable* var);
	bool		iObj_set_recordSourceType					(SObject* obj, SVariable* var);
	bool		iObj_set_relationalExpr						(SObject* obj, SVariable* var);
	bool		iObj_set_relativeColumn						(SObject* obj, SVariable* var);
	bool		iObj_set_relativeRow						(SObject* obj, SVariable* var);
	bool		iObj_set_releaseType						(SObject* obj, SVariable* var);
	bool		iObj_set_resizable							(SObject* obj, SVariable* var);
	bool		iObj_set_rightToLeft						(SObject* obj, SVariable* var);
	bool		iObj_set_rotateFlip							(SObject* obj, SVariable* var);
	bool		iObj_set_rotation							(SObject* obj, SVariable* var);
	bool		iObj_set_rowColChange						(SObject* obj, SVariable* var);
	bool		iObj_set_rowHeight							(SObject* obj, SVariable* var);
	bool		iObj_set_rowSource							(SObject* obj, SVariable* var);
	bool		iObj_set_rowSourceType						(SObject* obj, SVariable* var);
	bool		iObj_set_scaleMode							(SObject* obj, SVariable* var);
	bool		iObj_set_scrollBars							(SObject* obj, SVariable* var);
	bool		iObj_set_seconds							(SObject* obj, SVariable* var);
	bool		iObj_set_selLength							(SObject* obj, SVariable* var);
	bool		iObj_set_selStart							(SObject* obj, SVariable* var);
	bool		iObj_set_selText							(SObject* obj, SVariable* var);
	bool		iObj_set_selectOnEntry						(SObject* obj, SVariable* var);
	bool		iObj_set_selected							(SObject* obj, SVariable* var);
	bool		iObj_set_selectedBackColor					(SObject* obj, SVariable* var);
	bool		iObj_set_selectedForeColor					(SObject* obj, SVariable* var);
	bool		iObj_set_selectedID							(SObject* obj, SVariable* var);
	bool		iObj_set_selectedItemBackColor				(SObject* obj, SVariable* var);
	bool		iObj_set_selectedItemForeColor				(SObject* obj, SVariable* var);
	bool		iObj_set_showInTaskbar						(SObject* obj, SVariable* var);
	bool		iObj_set_showTips							(SObject* obj, SVariable* var);
	bool		iObj_set_showWindow							(SObject* obj, SVariable* var);
	bool		iObj_set_sizable							(SObject* obj, SVariable* var);
	bool		iObj_set_sizeBox							(SObject* obj, SVariable* var);
	bool		iObj_set_sorted								(SObject* obj, SVariable* var);
	bool		iObj_set_sparse								(SObject* obj, SVariable* var);
	bool		iObj_set_specialEffect						(SObject* obj, SVariable* var);
	bool		iObj_set_spinnerHighValue					(SObject* obj, SVariable* var);
	bool		iObj_set_spinnerLowValue					(SObject* obj, SVariable* var);
	bool		iObj_set_splitBar							(SObject* obj, SVariable* var);
	bool		iObj_set_stackLevel							(SObject* obj, SVariable* var);
	bool		iObj_set_statusBarText						(SObject* obj, SVariable* var);
	bool		iObj_set_stretch							(SObject* obj, SVariable* var);
	bool		iObj_set_strictDateEntry					(SObject* obj, SVariable* var);
	bool		iObj_set_style								(SObject* obj, SVariable* var);
	bool		iObj_set_tabIndex							(SObject* obj, SVariable* var);
	bool		iObj_set_tabOrientation						(SObject* obj, SVariable* var);
	bool		iObj_set_tabStop							(SObject* obj, SVariable* var);
	bool		iObj_set_tabStyle							(SObject* obj, SVariable* var);
	bool		iObj_set_tabs								(SObject* obj, SVariable* var);
	bool		iObj_set_tag								(SObject* obj, SVariable* var);
	bool		iObj_set_terminateRead						(SObject* obj, SVariable* var);
	bool		iObj_set_text								(SObject* obj, SVariable* var);
	bool		iObj_set_themes								(SObject* obj, SVariable* var);
	bool		iObj_set_titleBar							(SObject* obj, SVariable* var);
	bool		iObj_set_toolTipText						(SObject* obj, SVariable* var);
	bool		iObj_set_top								(SObject* obj, SVariable* var);
	bool		iObj_set_topIndex							(SObject* obj, SVariable* var);
	bool		iObj_set_topItemID							(SObject* obj, SVariable* var);
	bool		iObj_set_userValue							(SObject* obj, SVariable* var);
	bool		iObj_set_vScrollSmallChange					(SObject* obj, SVariable* var);
	bool		iObj_set_value								(SObject* obj, SVariable* var);
	bool		iObj_set_view								(SObject* obj, SVariable* var);
	bool		iObj_set_viewPortHeight						(SObject* obj, SVariable* var);
	bool		iObj_set_viewPortLeft						(SObject* obj, SVariable* var);
	bool		iObj_set_viewPortTop						(SObject* obj, SVariable* var);
	bool		iObj_set_viewPortWidth						(SObject* obj, SVariable* var);
	bool		iObj_set_visible							(SObject* obj, SVariable* var);
	bool		iObj_set_visualEffect						(SObject* obj, SVariable* var);
	bool		iObj_set_whatsThisButton					(SObject* obj, SVariable* var);
	bool		iObj_set_whatsThisHelp						(SObject* obj, SVariable* var);
	bool		iObj_set_whatsThisHelpID					(SObject* obj, SVariable* var);
	bool		iObj_set_width								(SObject* obj, SVariable* var);
	bool		iObj_set_windowList							(SObject* obj, SVariable* var);
	bool		iObj_set_windowState						(SObject* obj, SVariable* var);
	bool		iObj_set_windowType							(SObject* obj, SVariable* var);
	bool		iObj_set_wordWrap							(SObject* obj, SVariable* var);
	bool		iObj_set_zoomBox							(SObject* obj, SVariable* var);

	SVariable*	iObj_get_activeColumn						(SObject* obj);
	SVariable*	iObj_get_activeControl						(SObject* obj);
	SVariable*	iObj_get_activeForm							(SObject* obj);
	SVariable*	iObj_get_activePage							(SObject* obj);
	SVariable*	iObj_get_activeRow							(SObject* obj);
	SVariable*	iObj_get_addLineFeeds						(SObject* obj);
	SVariable*	iObj_get_align								(SObject* obj);
	SVariable*	iObj_get_alignment							(SObject* obj);
	SVariable*	iObj_get_allowAddNew						(SObject* obj);
	SVariable*	iObj_get_allowAutoColumnFit					(SObject* obj);
	SVariable*	iObj_get_allowCellSelection					(SObject* obj);
	SVariable*	iObj_get_allowHeaderSizing					(SObject* obj);
	SVariable*	iObj_get_allowOutput						(SObject* obj);
	SVariable*	iObj_get_allowRowSizing						(SObject* obj);
	SVariable*	iObj_get_allowTabs							(SObject* obj);
	SVariable*	iObj_get_alwaysOnBottom						(SObject* obj);
	SVariable*	iObj_get_alwaysOnTop						(SObject* obj);
	SVariable*	iObj_get_anchor								(SObject* obj);
	SVariable*	iObj_get_application						(SObject* obj);
	SVariable*	iObj_get_autoActivate						(SObject* obj);
	SVariable*	iObj_get_autoCenter							(SObject* obj);
	SVariable*	iObj_get_autoCompSource						(SObject* obj);
	SVariable*	iObj_get_autoCompTable						(SObject* obj);
	SVariable*	iObj_get_autoComplete						(SObject* obj);
	SVariable*	iObj_get_autoHideScrollBar					(SObject* obj);
	SVariable*	iObj_get_autoRelease						(SObject* obj);
	SVariable*	iObj_get_autoSize							(SObject* obj);
	SVariable*	iObj_get_autoVerbMenu						(SObject* obj);
	SVariable*	iObj_get_backColor							(SObject* obj);
	SVariable*	iObj_get_backStyle							(SObject* obj);
	SVariable*	iObj_get_baseClass							(SObject* obj);
	SVariable*	iObj_get_bindControls						(SObject* obj);
	SVariable*	iObj_get_borderColor						(SObject* obj);
	SVariable*	iObj_get_borderStyle						(SObject* obj);
	SVariable*	iObj_get_borderWidth						(SObject* obj);
	SVariable*	iObj_get_bound								(SObject* obj);
	SVariable*	iObj_get_boundColumn						(SObject* obj);
	SVariable*	iObj_get_boundTo							(SObject* obj);
	SVariable*	iObj_get_bufferMode							(SObject* obj);
	SVariable*	iObj_get_buttonCount						(SObject* obj);
	SVariable*	iObj_get_cancel								(SObject* obj);
	SVariable*	iObj_get_caption							(SObject* obj);
	SVariable*	iObj_get_centered							(SObject* obj);
	SVariable*	iObj_get_century							(SObject* obj);
	SVariable*	iObj_get_childOrder							(SObject* obj);
	SVariable*	iObj_get_class								(SObject* obj);
	SVariable*	iObj_get_classLibrary						(SObject* obj);
	SVariable*	iObj_get_clipControls						(SObject* obj);
	SVariable*	iObj_get_closable							(SObject* obj);
	SVariable*	iObj_get_colorScheme						(SObject* obj);
	SVariable*	iObj_get_colorSource						(SObject* obj);
	SVariable*	iObj_get_columnCount						(SObject* obj);
	SVariable*	iObj_get_columnLines						(SObject* obj);
	SVariable*	iObj_get_columnOrder						(SObject* obj);
	SVariable*	iObj_get_columnWidths						(SObject* obj);
	SVariable*	iObj_get_columns							(SObject* obj);
	SVariable*	iObj_get_comment							(SObject* obj);
	SVariable*	iObj_get_continuousScroll					(SObject* obj);
	SVariable*	iObj_get_controlBox							(SObject* obj);
	SVariable*	iObj_get_controlCount						(SObject* obj);
	SVariable*	iObj_get_controlSource						(SObject* obj);
	SVariable*	iObj_get_controls							(SObject* obj);
	SVariable*	iObj_get_count								(SObject* obj);
	SVariable*	iObj_get_currentControl						(SObject* obj);
	SVariable*	iObj_get_currentX							(SObject* obj);
	SVariable*	iObj_get_currentY							(SObject* obj);
	SVariable*	iObj_get_curvature							(SObject* obj);
	SVariable*	iObj_get_dEClass							(SObject* obj);
	SVariable*	iObj_get_dEClassLibrary						(SObject* obj);
	SVariable*	iObj_get_dataEnvironment					(SObject* obj);
	SVariable*	iObj_get_dataSession						(SObject* obj);
	SVariable*	iObj_get_dataSessionID						(SObject* obj);
	SVariable*	iObj_get_dateFormat							(SObject* obj);
	SVariable*	iObj_get_dateMark							(SObject* obj);
	SVariable*	iObj_get_defOLELCID							(SObject* obj);
	SVariable*	iObj_get_default							(SObject* obj);
	SVariable*	iObj_get_deleteMark							(SObject* obj);
	SVariable*	iObj_get_desktop							(SObject* obj);
	SVariable*	iObj_get_details							(SObject* obj);
	SVariable*	iObj_get_disabledBackColor					(SObject* obj);
	SVariable*	iObj_get_disabledForeColor					(SObject* obj);
	SVariable*	iObj_get_disabledItemBackColor				(SObject* obj);
	SVariable*	iObj_get_disabledItemForeColor				(SObject* obj);
	SVariable*	iObj_get_disabledPicture					(SObject* obj);
	SVariable*	iObj_get_displayCount						(SObject* obj);
	SVariable*	iObj_get_displayValue						(SObject* obj);
	SVariable*	iObj_get_doCreate							(SObject* obj);
	SVariable*	iObj_get_dockPosition						(SObject* obj);
	SVariable*	iObj_get_dockable							(SObject* obj);
	SVariable*	iObj_get_docked								(SObject* obj);
	SVariable*	iObj_get_documentFile						(SObject* obj);
	SVariable*	iObj_get_downPicture						(SObject* obj);
	SVariable*	iObj_get_dragIcon							(SObject* obj);
	SVariable*	iObj_get_dragMode							(SObject* obj);
	SVariable*	iObj_get_drawMode							(SObject* obj);
	SVariable*	iObj_get_drawStyle							(SObject* obj);
	SVariable*	iObj_get_drawWidth							(SObject* obj);
	SVariable*	iObj_get_dynamicAlignment					(SObject* obj);
	SVariable*	iObj_get_dynamicBackColor					(SObject* obj);
	SVariable*	iObj_get_dynamicCurrentControl				(SObject* obj);
	SVariable*	iObj_get_dynamicFontBold					(SObject* obj);
	SVariable*	iObj_get_dynamicFontItalic					(SObject* obj);
	SVariable*	iObj_get_dynamicFontName					(SObject* obj);
	SVariable*	iObj_get_dynamicFontOutline					(SObject* obj);
	SVariable*	iObj_get_dynamicFontShadow					(SObject* obj);
	SVariable*	iObj_get_dynamicFontSize					(SObject* obj);
	SVariable*	iObj_get_dynamicFontStrikeThru				(SObject* obj);
	SVariable*	iObj_get_dynamicFontUnderline				(SObject* obj);
	SVariable*	iObj_get_dynamicForeColor					(SObject* obj);
	SVariable*	iObj_get_dynamicInputMask					(SObject* obj);
	SVariable*	iObj_get_enableHyperlinks					(SObject* obj);
	SVariable*	iObj_get_enabled							(SObject* obj);
	SVariable*	iObj_get_errorNo							(SObject* obj);
	SVariable*	iObj_get_fillColor							(SObject* obj);
	SVariable*	iObj_get_fillStyle							(SObject* obj);
	SVariable*	iObj_get_firstElement						(SObject* obj);
	SVariable*	iObj_get_fontBold							(SObject* obj);
	SVariable*	iObj_get_fontCharSet						(SObject* obj);
	SVariable*	iObj_get_fontCondense						(SObject* obj);
	SVariable*	iObj_get_fontExtend							(SObject* obj);
	SVariable*	iObj_get_fontItalic							(SObject* obj);
	SVariable*	iObj_get_fontName							(SObject* obj);
	SVariable*	iObj_get_fontOutline						(SObject* obj);
	SVariable*	iObj_get_fontShadow							(SObject* obj);
	SVariable*	iObj_get_fontSize							(SObject* obj);
	SVariable*	iObj_get_fontStrikeThru						(SObject* obj);
	SVariable*	iObj_get_fontUnderLine						(SObject* obj);
	SVariable*	iObj_get_fontUnderline						(SObject* obj);
	SVariable*	iObj_get_foreColor							(SObject* obj);
	SVariable*	iObj_get_formCount							(SObject* obj);
	SVariable*	iObj_get_format								(SObject* obj);
	SVariable*	iObj_get_forms								(SObject* obj);
	SVariable*	iObj_get_gridLineColor						(SObject* obj);
	SVariable*	iObj_get_gridLineWidth						(SObject* obj);
	SVariable*	iObj_get_gridLines							(SObject* obj);
	SVariable*	iObj_get_hScrollSmallChange					(SObject* obj);
	SVariable*	iObj_get_hWnd								(SObject* obj);
	SVariable*	iObj_get_halfHeightCaption					(SObject* obj);
	SVariable*	iObj_get_headerClass						(SObject* obj);
	SVariable*	iObj_get_headerClassLibrary					(SObject* obj);
	SVariable*	iObj_get_headerHeight						(SObject* obj);
	SVariable*	iObj_get_height								(SObject* obj);
	SVariable*	iObj_get_helpContextID						(SObject* obj);
	SVariable*	iObj_get_hideSelection						(SObject* obj);
	SVariable*	iObj_get_highLight							(SObject* obj);
	SVariable*	iObj_get_highLightRow						(SObject* obj);
	SVariable*	iObj_get_highlightBackColor					(SObject* obj);
	SVariable*	iObj_get_highlightForeColor					(SObject* obj);
	SVariable*	iObj_get_highlightRowLineWidth				(SObject* obj);
	SVariable*	iObj_get_highlightStyle						(SObject* obj);
	SVariable*	iObj_get_hostName							(SObject* obj);
	SVariable*	iObj_get_hours								(SObject* obj);
	SVariable*	iObj_get_iMEMode							(SObject* obj);
	SVariable*	iObj_get_icon								(SObject* obj);
	SVariable*	iObj_get_increment							(SObject* obj);
	SVariable*	iObj_get_incrementalSearch					(SObject* obj);
	SVariable*	iObj_get_inputMask							(SObject* obj);
	SVariable*	iObj_get_integralHeight						(SObject* obj);
	SVariable*	iObj_get_interval							(SObject* obj);
	SVariable*	iObj_get_itemBackColor						(SObject* obj);
	SVariable*	iObj_get_itemData							(SObject* obj);
	SVariable*	iObj_get_itemForeColor						(SObject* obj);
	SVariable*	iObj_get_itemIDData							(SObject* obj);
	SVariable*	iObj_get_itemTips							(SObject* obj);
	SVariable*	iObj_get_keyPreview							(SObject* obj);
	SVariable*	iObj_get_keySort							(SObject* obj);
	SVariable*	iObj_get_keyboardHighValue					(SObject* obj);
	SVariable*	iObj_get_keyboardLowValue					(SObject* obj);
	SVariable*	iObj_get_left								(SObject* obj);
	SVariable*	iObj_get_leftColumn							(SObject* obj);
	SVariable*	iObj_get_lineContents						(SObject* obj);
	SVariable*	iObj_get_lineNo								(SObject* obj);
	SVariable*	iObj_get_lineSlant							(SObject* obj);
	SVariable*	iObj_get_linkMaster							(SObject* obj);
	SVariable*	iObj_get_list								(SObject* obj);
	SVariable*	iObj_get_listCount							(SObject* obj);
	SVariable*	iObj_get_listIndex							(SObject* obj);
	SVariable*	iObj_get_listItem							(SObject* obj);
	SVariable*	iObj_get_listItemID							(SObject* obj);
	SVariable*	iObj_get_lockColumns						(SObject* obj);
	SVariable*	iObj_get_lockColumnsLeft					(SObject* obj);
	SVariable*	iObj_get_lockScreen							(SObject* obj);
	SVariable*	iObj_get_mDIForm							(SObject* obj);
	SVariable*	iObj_get_macDesktop							(SObject* obj);
	SVariable*	iObj_get_margin								(SObject* obj);
	SVariable*	iObj_get_maxButton							(SObject* obj);
	SVariable*	iObj_get_maxHeight							(SObject* obj);
	SVariable*	iObj_get_maxLeft							(SObject* obj);
	SVariable*	iObj_get_maxLength							(SObject* obj);
	SVariable*	iObj_get_maxTop								(SObject* obj);
	SVariable*	iObj_get_maxWidth							(SObject* obj);
	SVariable*	iObj_get_memberClass						(SObject* obj);
	SVariable*	iObj_get_memberClassLibrary					(SObject* obj);
	SVariable*	iObj_get_memoWindow							(SObject* obj);
	SVariable*	iObj_get_message							(SObject* obj);
	SVariable*	iObj_get_minButton							(SObject* obj);
	SVariable*	iObj_get_minHeight							(SObject* obj);
	SVariable*	iObj_get_minWidth							(SObject* obj);
	SVariable*	iObj_get_mouseIcon							(SObject* obj);
	SVariable*	iObj_get_mousePointer						(SObject* obj);
	SVariable*	iObj_get_movable							(SObject* obj);
	SVariable*	iObj_get_moverBars							(SObject* obj);
	SVariable*	iObj_get_multiSelect						(SObject* obj);
	SVariable*	iObj_get_name								(SObject* obj);
	SVariable*	iObj_get_newIndex							(SObject* obj);
	SVariable*	iObj_get_newItemID							(SObject* obj);
	SVariable*	iObj_get_nullDisplay						(SObject* obj);
	SVariable*	iObj_get_numberOfElements					(SObject* obj);
	SVariable*	iObj_get_oLEClass							(SObject* obj);
	SVariable*	iObj_get_oLEDragMode						(SObject* obj);
	SVariable*	iObj_get_oLEDragPicture						(SObject* obj);
	SVariable*	iObj_get_oLEDropEffects						(SObject* obj);
	SVariable*	iObj_get_oLEDropHasData						(SObject* obj);
	SVariable*	iObj_get_oLEDropMode						(SObject* obj);
	SVariable*	iObj_get_oLEDropTextInsertion				(SObject* obj);
	SVariable*	iObj_get_oLELCID							(SObject* obj);
	SVariable*	iObj_get_oLETypeAllowed						(SObject* obj);
	SVariable*	iObj_get_object								(SObject* obj);
	SVariable*	iObj_get_objects							(SObject* obj);
	SVariable*	iObj_get_openWindow							(SObject* obj);
	SVariable*	iObj_get_optimize							(SObject* obj);
	SVariable*	iObj_get_pageCount							(SObject* obj);
	SVariable*	iObj_get_pageHeight							(SObject* obj);
	SVariable*	iObj_get_pageOrder							(SObject* obj);
	SVariable*	iObj_get_pageWidth							(SObject* obj);
	SVariable*	iObj_get_pages								(SObject* obj);
	SVariable*	iObj_get_panel								(SObject* obj);
	SVariable*	iObj_get_panelLink							(SObject* obj);
	SVariable*	iObj_get_parent								(SObject* obj);
	SVariable*	iObj_get_parentClass						(SObject* obj);
	SVariable*	iObj_get_partition							(SObject* obj);
	SVariable*	iObj_get_passwordChar						(SObject* obj);
	SVariable*	iObj_get_picture							(SObject* obj);
	SVariable*	iObj_get_pictureMargin						(SObject* obj);
	SVariable*	iObj_get_picturePosition					(SObject* obj);
	SVariable*	iObj_get_pictureSelectionDisplay			(SObject* obj);
	SVariable*	iObj_get_pictureSpacing						(SObject* obj);
	SVariable*	iObj_get_pictureVal							(SObject* obj);
	SVariable*	iObj_get_polyPoints							(SObject* obj);
	SVariable*	iObj_get_procedure							(SObject* obj);
	SVariable*	iObj_get_readBackColor						(SObject* obj);
	SVariable*	iObj_get_readCycle							(SObject* obj);
	SVariable*	iObj_get_readForeColor						(SObject* obj);
	SVariable*	iObj_get_readLock							(SObject* obj);
	SVariable*	iObj_get_readMouse							(SObject* obj);
	SVariable*	iObj_get_readOnly							(SObject* obj);
	SVariable*	iObj_get_readSave							(SObject* obj);
	SVariable*	iObj_get_readTimeOut						(SObject* obj);
	SVariable*	iObj_get_recordMark							(SObject* obj);
	SVariable*	iObj_get_recordSource						(SObject* obj);
	SVariable*	iObj_get_recordSourceType					(SObject* obj);
	SVariable*	iObj_get_relationalExpr						(SObject* obj);
	SVariable*	iObj_get_relativeColumn						(SObject* obj);
	SVariable*	iObj_get_relativeRow						(SObject* obj);
	SVariable*	iObj_get_releaseType						(SObject* obj);
	SVariable*	iObj_get_resizable							(SObject* obj);
	SVariable*	iObj_get_rightToLeft						(SObject* obj);
	SVariable*	iObj_get_rotateFlip							(SObject* obj);
	SVariable*	iObj_get_rotation							(SObject* obj);
	SVariable*	iObj_get_rowColChange						(SObject* obj);
	SVariable*	iObj_get_rowHeight							(SObject* obj);
	SVariable*	iObj_get_rowSource							(SObject* obj);
	SVariable*	iObj_get_rowSourceType						(SObject* obj);
	SVariable*	iObj_get_scaleMode							(SObject* obj);
	SVariable*	iObj_get_scrollBars							(SObject* obj);
	SVariable*	iObj_get_seconds							(SObject* obj);
	SVariable*	iObj_get_selLength							(SObject* obj);
	SVariable*	iObj_get_selStart							(SObject* obj);
	SVariable*	iObj_get_selText							(SObject* obj);
	SVariable*	iObj_get_selectOnEntry						(SObject* obj);
	SVariable*	iObj_get_selected							(SObject* obj);
	SVariable*	iObj_get_selectedBackColor					(SObject* obj);
	SVariable*	iObj_get_selectedForeColor					(SObject* obj);
	SVariable*	iObj_get_selectedID							(SObject* obj);
	SVariable*	iObj_get_selectedItemBackColor				(SObject* obj);
	SVariable*	iObj_get_selectedItemForeColor				(SObject* obj);
	SVariable*	iObj_get_showInTaskbar						(SObject* obj);
	SVariable*	iObj_get_showTips							(SObject* obj);
	SVariable*	iObj_get_showWindow							(SObject* obj);
	SVariable*	iObj_get_sizable							(SObject* obj);
	SVariable*	iObj_get_sizeBox							(SObject* obj);
	SVariable*	iObj_get_sorted								(SObject* obj);
	SVariable*	iObj_get_sparse								(SObject* obj);
	SVariable*	iObj_get_specialEffect						(SObject* obj);
	SVariable*	iObj_get_spinnerHighValue					(SObject* obj);
	SVariable*	iObj_get_spinnerLowValue					(SObject* obj);
	SVariable*	iObj_get_splitBar							(SObject* obj);
	SVariable*	iObj_get_stackLevel							(SObject* obj);
	SVariable*	iObj_get_statusBarText						(SObject* obj);
	SVariable*	iObj_get_stretch							(SObject* obj);
	SVariable*	iObj_get_strictDateEntry					(SObject* obj);
	SVariable*	iObj_get_style								(SObject* obj);
	SVariable*	iObj_get_tabIndex							(SObject* obj);
	SVariable*	iObj_get_tabOrientation						(SObject* obj);
	SVariable*	iObj_get_tabStop							(SObject* obj);
	SVariable*	iObj_get_tabStyle							(SObject* obj);
	SVariable*	iObj_get_tabs								(SObject* obj);
	SVariable*	iObj_get_tag								(SObject* obj);
	SVariable*	iObj_get_terminateRead						(SObject* obj);
	SVariable*	iObj_get_text								(SObject* obj);
	SVariable*	iObj_get_themes								(SObject* obj);
	SVariable*	iObj_get_titleBar							(SObject* obj);
	SVariable*	iObj_get_toolTipText						(SObject* obj);
	SVariable*	iObj_get_top								(SObject* obj);
	SVariable*	iObj_get_topIndex							(SObject* obj);
	SVariable*	iObj_get_topItemID							(SObject* obj);
	SVariable*	iObj_get_userValue							(SObject* obj);
	SVariable*	iObj_get_vScrollSmallChange					(SObject* obj);
	SVariable*	iObj_get_value								(SObject* obj);
	SVariable*	iObj_get_view								(SObject* obj);
	SVariable*	iObj_get_viewPortHeight						(SObject* obj);
	SVariable*	iObj_get_viewPortLeft						(SObject* obj);
	SVariable*	iObj_get_viewPortTop						(SObject* obj);
	SVariable*	iObj_get_viewPortWidth						(SObject* obj);
	SVariable*	iObj_get_visible							(SObject* obj);
	SVariable*	iObj_get_visualEffect						(SObject* obj);
	SVariable*	iObj_get_whatsThisButton					(SObject* obj);
	SVariable*	iObj_get_whatsThisHelp						(SObject* obj);
	SVariable*	iObj_get_whatsThisHelpID					(SObject* obj);
	SVariable*	iObj_get_width								(SObject* obj);
	SVariable*	iObj_get_windowList							(SObject* obj);
	SVariable*	iObj_get_windowState						(SObject* obj);
	SVariable*	iObj_get_windowType							(SObject* obj);
	SVariable*	iObj_get_wordWrap							(SObject* obj);
	SVariable*	iObj_get_zoomBox							(SObject* obj);





//////////
// Property map of the base classes
//////
	struct SPropertyMap
	{
		cs8*		property;
		u32			length;
		bool		(*setter)	(SObject* obj, SVariable* var);
		SVariable*	(*getter)	(SObject* obj);
	};

	SPropertyMap gcProps_checkbox[] = 
	{
		// Translation for VJr provided by Hernan Cano Martinez
		{   cgc_alignment,                  9,        &iObj_set_alignment,                    &iObj_get_alignment                     },
		{   cgc_anchor,                     6,        &iObj_set_anchor,                       &iObj_get_anchor                        },
		{   cgc_application,                11,       &iObj_set_application,                  &iObj_get_application                   },
		{   cgc_autoSize,                   8,        &iObj_set_autoSize,                     &iObj_get_autoSize                      },
		{   cgc_backStyle,                  9,        &iObj_set_backStyle,                    &iObj_get_backStyle                     },
		{   cgc_baseClass,                  9,        &iObj_set_baseClass,                    &iObj_get_baseClass                     },
		{   cgc_class,                      5,        &iObj_set_class,                        &iObj_get_class                         },
		{   cgc_classLibrary,               12,       &iObj_set_classLibrary,                 &iObj_get_classLibrary                  },
		{   cgc_caption,                    7,        &iObj_set_caption,                      &iObj_get_caption                       },
		{   cgc_centered,                   8,        &iObj_set_centered,                     &iObj_get_centered                      },
		{   cgc_colorScheme,                11,       &iObj_set_colorScheme,                  &iObj_get_colorScheme                   },
		{   cgc_colorSource,                11,       &iObj_set_colorSource,                  &iObj_get_colorSource                   },
		{   cgc_foreColor,                  9,        &iObj_set_foreColor,                    &iObj_get_foreColor                     },
		{   cgc_backColor,                  9,        &iObj_set_backColor,                    &iObj_get_backColor                     },
		{   cgc_disabledBackColor,          17,       &iObj_set_disabledBackColor,            &iObj_get_disabledBackColor             },
		{   cgc_disabledForeColor,          17,       &iObj_set_disabledForeColor,            &iObj_get_disabledForeColor             },
		{   cgc_comment,                    7,        &iObj_set_comment,                      &iObj_get_comment                       },
		{   cgc_controlSource,              13,       &iObj_set_controlSource,                &iObj_get_controlSource                 },
		{   cgc_dragIcon,                   8,        &iObj_set_dragIcon,                     &iObj_get_dragIcon                      },
		{   cgc_dragMode,                   8,        &iObj_set_dragMode,                     &iObj_get_dragMode                      },
		{   cgc_enabled,                    7,        &iObj_set_enabled,                      &iObj_get_enabled                       },
		{   cgc_fontBold,                   8,        &iObj_set_fontBold,                     &iObj_get_fontBold                      },
		{   cgc_fontCharSet,                11,       &iObj_set_fontCharSet,                  &iObj_get_fontCharSet                   },
		{   cgc_fontCondense,               12,       &iObj_set_fontCondense,                 &iObj_get_fontCondense                  },
		{   cgc_fontExtend,                 10,       &iObj_set_fontExtend,                   &iObj_get_fontExtend                    },
		{   cgc_fontItalic,                 10,       &iObj_set_fontItalic,                   &iObj_get_fontItalic                    },
		{   cgc_fontName,                   8,        &iObj_set_fontName,                     &iObj_get_fontName                      },
		{   cgc_fontOutline,                11,       &iObj_set_fontOutline,                  &iObj_get_fontOutline                   },
		{   cgc_fontShadow,                 10,       &iObj_set_fontShadow,                   &iObj_get_fontShadow                    },
		{   cgc_fontStrikeThru,             14,       &iObj_set_fontStrikeThru,               &iObj_get_fontStrikeThru                },
		{   cgc_fontUnderline,              13,       &iObj_set_fontUnderline,                &iObj_get_fontUnderline                 },
		{   cgc_height,                     6,        &iObj_set_height,                       &iObj_get_height                        },
		{   cgc_helpContextID,              13,       &iObj_set_helpContextID,                &iObj_get_helpContextID                 },
		{   cgc_left,                       4,        &iObj_set_left,                         &iObj_get_left                          },
		{   cgc_mouseIcon,                  9,        &iObj_set_mouseIcon,                    &iObj_get_mouseIcon                     },
		{   cgc_mousePointer,               12,       &iObj_set_mousePointer,                 &iObj_get_mousePointer                  },
		{   cgc_name,                       4,        &iObj_set_name,                         &iObj_get_name                          },
		{   cgc_oLEDragMode,                11,       &iObj_set_oLEDragMode,                  &iObj_get_oLEDragMode                   },
		{   cgc_oLEDragPicture,             14,       &iObj_set_oLEDragPicture,               &iObj_get_oLEDragPicture                },
		{   cgc_oLEDropEffects,             14,       &iObj_set_oLEDropEffects,               &iObj_get_oLEDropEffects                },
		{   cgc_oLEDropHasData,             14,       &iObj_set_oLEDropHasData,               &iObj_get_oLEDropHasData                },
		{   cgc_parent,                     6,        &iObj_set_parent,                       &iObj_get_parent                        },
		{   cgc_parentClass,                11,       &iObj_set_parentClass,                  &iObj_get_parentClass                   },
		{   cgc_picture,                    7,        &iObj_set_picture,                      &iObj_get_picture                       },
		{   cgc_pictureMargin,              13,       &iObj_set_pictureMargin,                &iObj_get_pictureMargin                 },
		{   cgc_picturePosition,            15,       &iObj_set_picturePosition,              &iObj_get_picturePosition               },
		{   cgc_pictureSpacing,             14,       &iObj_set_pictureSpacing,               &iObj_get_pictureSpacing                },
		{   cgc_disabledPicture,            15,       &iObj_set_disabledPicture,              &iObj_get_disabledPicture               },
		{   cgc_downPicture,                11,       &iObj_set_downPicture,                  &iObj_get_downPicture                   },
		{   cgc_readOnly,                   8,        &iObj_set_readOnly,                     &iObj_get_readOnly                      },
		{   cgc_rightToLeft,                11,       &iObj_set_rightToLeft,                  &iObj_get_rightToLeft                   },
		{   cgc_specialEffect,              13,       &iObj_set_specialEffect,                &iObj_get_specialEffect                 },
		{   cgc_statusBarText,              13,       &iObj_set_statusBarText,                &iObj_get_statusBarText                 },
		{   cgc_style,                      5,        &iObj_set_style,                        &iObj_get_style                         },
		{   cgc_tabIndex,                   8,        &iObj_set_tabIndex,                     &iObj_get_tabIndex                      },
		{   cgc_tabStop,                    7,        &iObj_set_tabStop,                      &iObj_get_tabStop                       },
		{   cgc_tag,                        3,        &iObj_set_tag,                          &iObj_get_tag                           },
		{   cgc_terminateRead,              13,       &iObj_set_terminateRead,                &iObj_get_terminateRead                 },
		{   cgc_themes,                     6,        &iObj_set_themes,                       &iObj_get_themes                        },
		{   cgc_toolTipText,                11,       &iObj_set_toolTipText,                  &iObj_get_toolTipText                   },
		{   cgc_top,                        3,        &iObj_set_top,                          &iObj_get_top                           },
		{   cgc_value,                      5,        &iObj_set_value,                        &iObj_get_value                         },
		{   cgc_visible,                    7,        &iObj_set_visible,                      &iObj_get_visible                       },
		{   cgc_whatsThisHelpID,            15,       &iObj_set_whatsThisHelpID,              &iObj_get_whatsThisHelpID               },
		{   cgc_width,                      5,        &iObj_set_width,                        &iObj_get_width                         },
		{   cgc_wordWrap,                   8,        &iObj_set_wordWrap,                     &iObj_get_wordWrap                      },
		{   NULL,                           0,        0,                                      0                                       }
	};

	SPropertyMap gcProps_cmdbutton[] = 
	{
		// Translation for VJr provided by Hernan Cano Martinez
		{   cgc_alignment,                  9,        &iObj_set_alignment,                    &iObj_get_alignment                     },
		{   cgc_anchor,                     6,        &iObj_set_anchor,                       &iObj_get_anchor                        },
		{   cgc_application,                11,       &iObj_set_application,                  &iObj_get_application                   },
		{   cgc_autoSize,                   8,        &iObj_set_autoSize,                     &iObj_get_autoSize                      },
		{   cgc_baseClass,                  9,        &iObj_set_baseClass,                    &iObj_get_baseClass                     },
		{   cgc_class,                      5,        &iObj_set_class,                        &iObj_get_class                         },
		{   cgc_classLibrary,               12,       &iObj_set_classLibrary,                 &iObj_get_classLibrary                  },
		{   cgc_cancel,                     6,        &iObj_set_cancel,                       &iObj_get_cancel                        },
		{   cgc_default,                    7,        &iObj_set_default,                      &iObj_get_default                       },
		{   cgc_caption,                    7,        &iObj_set_caption,                      &iObj_get_caption                       },
		{   cgc_colorScheme,                11,       &iObj_set_colorScheme,                  &iObj_get_colorScheme                   },
		{   cgc_colorSource,                11,       &iObj_set_colorSource,                  &iObj_get_colorSource                   },
		{   cgc_foreColor,                  9,        &iObj_set_foreColor,                    &iObj_get_foreColor                     },
		{   cgc_backColor,                  9,        &iObj_set_backColor,                    &iObj_get_backColor                     },
		{   cgc_disabledBackColor,          17,       &iObj_set_disabledBackColor,            &iObj_get_disabledBackColor             },
		{   cgc_disabledForeColor,          17,       &iObj_set_disabledForeColor,            &iObj_get_disabledForeColor             },
		{   cgc_comment,                    7,        &iObj_set_comment,                      &iObj_get_comment                       },
		{   cgc_dragIcon,                   8,        &iObj_set_dragIcon,                     &iObj_get_dragIcon                      },
		{   cgc_dragMode,                   8,        &iObj_set_dragMode,                     &iObj_get_dragMode                      },
		{   cgc_enabled,                    7,        &iObj_set_enabled,                      &iObj_get_enabled                       },
		{   cgc_fontBold,                   8,        &iObj_set_fontBold,                     &iObj_get_fontBold                      },
		{   cgc_fontCharSet,                11,       &iObj_set_fontCharSet,                  &iObj_get_fontCharSet                   },
		{   cgc_fontCondense,               12,       &iObj_set_fontCondense,                 &iObj_get_fontCondense                  },
		{   cgc_fontExtend,                 10,       &iObj_set_fontExtend,                   &iObj_get_fontExtend                    },
		{   cgc_fontItalic,                 10,       &iObj_set_fontItalic,                   &iObj_get_fontItalic                    },
		{   cgc_fontName,                   8,        &iObj_set_fontName,                     &iObj_get_fontName                      },
		{   cgc_fontOutline,                11,       &iObj_set_fontOutline,                  &iObj_get_fontOutline                   },
		{   cgc_fontShadow,                 10,       &iObj_set_fontShadow,                   &iObj_get_fontShadow                    },
		{   cgc_fontSize,                   8,        &iObj_set_fontSize,                     &iObj_get_fontSize                      },
		{   cgc_fontStrikeThru,             14,       &iObj_set_fontStrikeThru,               &iObj_get_fontStrikeThru                },
		{   cgc_fontUnderline,              13,       &iObj_set_fontUnderline,                &iObj_get_fontUnderline                 },
		{   cgc_height,                     6,        &iObj_set_height,                       &iObj_get_height                        },
		{   cgc_helpContextID,              13,       &iObj_set_helpContextID,                &iObj_get_helpContextID                 },
		{   cgc_left,                       4,        &iObj_set_left,                         &iObj_get_left                          },
		{   cgc_mouseIcon,                  9,        &iObj_set_mouseIcon,                    &iObj_get_mouseIcon                     },
		{   cgc_mousePointer,               12,       &iObj_set_mousePointer,                 &iObj_get_mousePointer                  },
		{   cgc_name,                       4,        &iObj_set_name,                         &iObj_get_name                          },
		{   cgc_oLEDragMode,                11,       &iObj_set_oLEDragMode,                  &iObj_get_oLEDragMode                   },
		{   cgc_oLEDragPicture,             14,       &iObj_set_oLEDragPicture,               &iObj_get_oLEDragPicture                },
		{   cgc_oLEDropEffects,             14,       &iObj_set_oLEDropEffects,               &iObj_get_oLEDropEffects                },
		{   cgc_oLEDropHasData,             14,       &iObj_set_oLEDropHasData,               &iObj_get_oLEDropHasData                },
		{   cgc_oLEDropMode,                11,       &iObj_set_oLEDropMode,                  &iObj_get_oLEDropMode                   },
		{   cgc_parent,                     6,        &iObj_set_parent,                       &iObj_get_parent                        },
		{   cgc_parentClass,                11,       &iObj_set_parentClass,                  &iObj_get_parentClass                   },
		{   cgc_picture,                    7,        &iObj_set_picture,                      &iObj_get_picture                       },
		{   cgc_pictureMargin,              13,       &iObj_set_pictureMargin,                &iObj_get_pictureMargin                 },
		{   cgc_picturePosition,            15,       &iObj_set_picturePosition,              &iObj_get_picturePosition               },
		{   cgc_pictureSpacing,             14,       &iObj_set_pictureSpacing,               &iObj_get_pictureSpacing                },
		{   cgc_disabledPicture,            15,       &iObj_set_disabledPicture,              &iObj_get_disabledPicture               },
		{   cgc_downPicture,                11,       &iObj_set_downPicture,                  &iObj_get_downPicture                   },
		{   cgc_rightToLeft,                11,       &iObj_set_rightToLeft,                  &iObj_get_rightToLeft                   },
		{   cgc_specialEffect,              13,       &iObj_set_specialEffect,                &iObj_get_specialEffect                 },
		{   cgc_statusBarText,              13,       &iObj_set_statusBarText,                &iObj_get_statusBarText                 },
		{   cgc_style,                      5,        &iObj_set_style,                        &iObj_get_style                         },
		{   cgc_tabIndex,                   8,        &iObj_set_tabIndex,                     &iObj_get_tabIndex                      },
		{   cgc_tabStop,                    7,        &iObj_set_tabStop,                      &iObj_get_tabStop                       },
		{   cgc_tag,                        3,        &iObj_set_tag,                          &iObj_get_tag                           },
		{   cgc_terminateRead,              13,       &iObj_set_terminateRead,                &iObj_get_terminateRead                 },
		{   cgc_themes,                     6,        &iObj_set_themes,                       &iObj_get_themes                        },
		{   cgc_toolTipText,                11,       &iObj_set_toolTipText,                  &iObj_get_toolTipText                   },
		{   cgc_top,                        3,        &iObj_set_top,                          &iObj_get_top                           },
		{   cgc_visible,                    7,        &iObj_set_visible,                      &iObj_get_visible                       },
		{   cgc_visualEffect,               12,       &iObj_set_visualEffect,                 &iObj_get_visualEffect                  },
		{   cgc_whatsThisHelpID,            15,       &iObj_set_whatsThisHelpID,              &iObj_get_whatsThisHelpID               },
		{   cgc_width,                      5,        &iObj_set_width,                        &iObj_get_width                         },
		{   cgc_wordWrap,                   8,        &iObj_set_wordWrap,                     &iObj_get_wordWrap                      },
		{   NULL,                           0,        0,                                      0                                       }
	};

	SPropertyMap gcProps_cmdgroup[] = 
	{
		// Translation for VJr provided by Hernan Cano Martinez
		{   cgc_anchor,                     6,        &iObj_set_anchor,                       &iObj_get_anchor                        },
		{   cgc_autoSize,                   8,        &iObj_set_autoSize,                     &iObj_get_autoSize                      },
		{   cgc_backStyle,                  9,        &iObj_set_backStyle,                    &iObj_get_backStyle                     },
		{   cgc_buttonCount,                11,       &iObj_set_buttonCount,                  &iObj_get_buttonCount                   },
		{   cgc_borderColor,                11,       &iObj_set_borderColor,                  &iObj_get_borderColor                   },
		{   cgc_borderStyle,                11,       &iObj_set_borderStyle,                  &iObj_get_borderStyle                   },
		{   cgc_colorSource,                11,       &iObj_set_colorSource,                  &iObj_get_colorSource                   },
		{   cgc_backColor,                  9,        &iObj_set_backColor,                    &iObj_get_backColor                     },
		{   cgc_comment,                    7,        &iObj_set_comment,                      &iObj_get_comment                       },
		{   cgc_controlSource,              13,       &iObj_set_controlSource,                &iObj_get_controlSource                 },
		{   cgc_dragIcon,                   8,        &iObj_set_dragIcon,                     &iObj_get_dragIcon                      },
		{   cgc_dragMode,                   8,        &iObj_set_dragMode,                     &iObj_get_dragMode                      },
		{   cgc_enabled,                    7,        &iObj_set_enabled,                      &iObj_get_enabled                       },
		{   cgc_height,                     6,        &iObj_set_height,                       &iObj_get_height                        },
		{   cgc_helpContextID,              13,       &iObj_set_helpContextID,                &iObj_get_helpContextID                 },
		{   cgc_left,                       4,        &iObj_set_left,                         &iObj_get_left                          },
		{   cgc_memberClass,                11,       &iObj_set_memberClass,                  &iObj_get_memberClass                   },
		{   cgc_memberClassLibrary,         18,       &iObj_set_memberClassLibrary,           &iObj_get_memberClassLibrary            },
		{   cgc_mouseIcon,                  9,        &iObj_set_mouseIcon,                    &iObj_get_mouseIcon                     },
		{   cgc_mousePointer,               12,       &iObj_set_mousePointer,                 &iObj_get_mousePointer                  },
		{   cgc_name,                       4,        &iObj_set_name,                         &iObj_get_name                          },
		{   cgc_oLEDragMode,                11,       &iObj_set_oLEDragMode,                  &iObj_get_oLEDragMode                   },
		{   cgc_oLEDragPicture,             14,       &iObj_set_oLEDragPicture,               &iObj_get_oLEDragPicture                },
		{   cgc_oLEDropEffects,             14,       &iObj_set_oLEDropEffects,               &iObj_get_oLEDropEffects                },
		{   cgc_oLEDropMode,                11,       &iObj_set_oLEDropMode,                  &iObj_get_oLEDropMode                   },
		{   cgc_specialEffect,              13,       &iObj_set_specialEffect,                &iObj_get_specialEffect                 },
		{   cgc_statusBarText,              13,       &iObj_set_statusBarText,                &iObj_get_statusBarText                 },
		{   cgc_tag,                        3,        &iObj_set_tag,                          &iObj_get_tag                           },
		{   cgc_terminateRead,              13,       &iObj_set_terminateRead,                &iObj_get_terminateRead                 },
		{   cgc_themes,                     6,        &iObj_set_themes,                       &iObj_get_themes                        },
		{   cgc_toolTipText,                11,       &iObj_set_toolTipText,                  &iObj_get_toolTipText                   },
		{   cgc_top,                        3,        &iObj_set_top,                          &iObj_get_top                           },
		{   cgc_value,                      5,        &iObj_set_value,                        &iObj_get_value                         },
		{   cgc_visible,                    7,        &iObj_set_visible,                      &iObj_get_visible                       },
		{   cgc_whatsThisHelpID,            15,       &iObj_set_whatsThisHelpID,              &iObj_get_whatsThisHelpID               },
		{   cgc_width,                      5,        &iObj_set_width,                        &iObj_get_width                         },
		{   NULL,                           0,        0,                                      0                                       }
	};

	SPropertyMap gcProps_label[] = 
	{
		// Translation for VJr provided by Hernan Cano Martinez
		{   cgc_alignment,                  9,        &iObj_set_alignment,                    &iObj_get_alignment                     },
		{   cgc_anchor,                     6,        &iObj_set_anchor,                       &iObj_get_anchor                        },
		{   cgc_application,                11,       &iObj_set_application,                  &iObj_get_application                   },
		{   cgc_autoSize,                   8,        &iObj_set_autoSize,                     &iObj_get_autoSize                      },
		{   cgc_backStyle,                  9,        &iObj_set_backStyle,                    &iObj_get_backStyle                     },
		{   cgc_baseClass,                  9,        &iObj_set_baseClass,                    &iObj_get_baseClass                     },
		{   cgc_class,                      5,        &iObj_set_class,                        &iObj_get_class                         },
		{   cgc_classLibrary,               12,       &iObj_set_classLibrary,                 &iObj_get_classLibrary                  },
		{   cgc_borderStyle,                11,       &iObj_set_borderStyle,                  &iObj_get_borderStyle                   },
		{   cgc_caption,                    7,        &iObj_set_caption,                      &iObj_get_caption                       },
		{   cgc_colorScheme,                11,       &iObj_set_colorScheme,                  &iObj_get_colorScheme                   },
		{   cgc_colorSource,                11,       &iObj_set_colorSource,                  &iObj_get_colorSource                   },
		{   cgc_foreColor,                  9,        &iObj_set_foreColor,                    &iObj_get_foreColor                     },
		{   cgc_backColor,                  9,        &iObj_set_backColor,                    &iObj_get_backColor                     },
		{   cgc_disabledBackColor,          17,       &iObj_set_disabledBackColor,            &iObj_get_disabledBackColor             },
		{   cgc_disabledForeColor,          17,       &iObj_set_disabledForeColor,            &iObj_get_disabledForeColor             },
		{   cgc_comment,                    7,        &iObj_set_comment,                      &iObj_get_comment                       },
		{   cgc_dragIcon,                   8,        &iObj_set_dragIcon,                     &iObj_get_dragIcon                      },
		{   cgc_dragMode,                   8,        &iObj_set_dragMode,                     &iObj_get_dragMode                      },
		{   cgc_enabled,                    7,        &iObj_set_enabled,                      &iObj_get_enabled                       },
		{   cgc_fontBold,                   8,        &iObj_set_fontBold,                     &iObj_get_fontBold                      },
		{   cgc_fontCharSet,                11,       &iObj_set_fontCharSet,                  &iObj_get_fontCharSet                   },
		{   cgc_fontCondense,               12,       &iObj_set_fontCondense,                 &iObj_get_fontCondense                  },
		{   cgc_fontExtend,                 10,       &iObj_set_fontExtend,                   &iObj_get_fontExtend                    },
		{   cgc_fontItalic,                 10,       &iObj_set_fontItalic,                   &iObj_get_fontItalic                    },
		{   cgc_fontName,                   8,        &iObj_set_fontName,                     &iObj_get_fontName                      },
		{   cgc_fontOutline,                11,       &iObj_set_fontOutline,                  &iObj_get_fontOutline                   },
		{   cgc_fontShadow,                 10,       &iObj_set_fontShadow,                   &iObj_get_fontShadow                    },
		{   cgc_fontSize,                   8,        &iObj_set_fontSize,                     &iObj_get_fontSize                      },
		{   cgc_fontStrikeThru,             14,       &iObj_set_fontStrikeThru,               &iObj_get_fontStrikeThru                },
		{   cgc_fontUnderline,              13,       &iObj_set_fontUnderline,                &iObj_get_fontUnderline                 },
		{   cgc_height,                     6,        &iObj_set_height,                       &iObj_get_height                        },
		{   cgc_helpContextID,              13,       &iObj_set_helpContextID,                &iObj_get_helpContextID                 },
		{   cgc_left,                       4,        &iObj_set_left,                         &iObj_get_left                          },
		{   cgc_mouseIcon,                  9,        &iObj_set_mouseIcon,                    &iObj_get_mouseIcon                     },
		{   cgc_mousePointer,               12,       &iObj_set_mousePointer,                 &iObj_get_mousePointer                  },
		{   cgc_name,                       4,        &iObj_set_name,                         &iObj_get_name                          },
		{   cgc_oLEDragMode,                11,       &iObj_set_oLEDragMode,                  &iObj_get_oLEDragMode                   },
		{   cgc_oLEDragPicture,             14,       &iObj_set_oLEDragPicture,               &iObj_get_oLEDragPicture                },
		{   cgc_oLEDropEffects,             14,       &iObj_set_oLEDropEffects,               &iObj_get_oLEDropEffects                },
		{   cgc_oLEDropHasData,             14,       &iObj_set_oLEDropHasData,               &iObj_get_oLEDropHasData                },
		{   cgc_oLEDropMode,                11,       &iObj_set_oLEDropMode,                  &iObj_get_oLEDropMode                   },
		{   cgc_parent,                     6,        &iObj_set_parent,                       &iObj_get_parent                        },
		{   cgc_parentClass,                11,       &iObj_set_parentClass,                  &iObj_get_parentClass                   },
		{   cgc_rightToLeft,                11,       &iObj_set_rightToLeft,                  &iObj_get_rightToLeft                   },
		{   cgc_rotation,                   8,        &iObj_set_rotation,                     &iObj_get_rotation                      },
		{   cgc_statusBarText,              13,       &iObj_set_statusBarText,                &iObj_get_statusBarText                 },
		{   cgc_style,                      5,        &iObj_set_style,                        &iObj_get_style                         },
		{   cgc_tabIndex,                   8,        &iObj_set_tabIndex,                     &iObj_get_tabIndex                      },
		{   cgc_tag,                        3,        &iObj_set_tag,                          &iObj_get_tag                           },
		{   cgc_toolTipText,                11,       &iObj_set_toolTipText,                  &iObj_get_toolTipText                   },
		{   cgc_top,                        3,        &iObj_set_top,                          &iObj_get_top                           },
		{   cgc_visible,                    7,        &iObj_set_visible,                      &iObj_get_visible                       },
		{   cgc_whatsThisHelpID,            15,       &iObj_set_whatsThisHelpID,              &iObj_get_whatsThisHelpID               },
		{   cgc_width,                      5,        &iObj_set_width,                        &iObj_get_width                         },
		{   cgc_wordWrap,                   8,        &iObj_set_wordWrap,                     &iObj_get_wordWrap                      },
		{   NULL,                           0,        0,                                      0                                       }
	};

	SPropertyMap gcProps_option[] = 
	{
		// Translation for VJr provided by Hernan Cano Martinez
		{   cgc_alignment,                  9,        &iObj_set_alignment,                    &iObj_get_alignment                     },
		{   cgc_anchor,                     6,        &iObj_set_anchor,                       &iObj_get_anchor                        },
		{   cgc_autoSize,                   8,        &iObj_set_autoSize,                     &iObj_get_autoSize                      },
		{   cgc_backStyle,                  9,        &iObj_set_backStyle,                    &iObj_get_backStyle                     },
		{   cgc_caption,                    7,        &iObj_set_caption,                      &iObj_get_caption                       },
		{   cgc_colorScheme,                11,       &iObj_set_colorScheme,                  &iObj_get_colorScheme                   },
		{   cgc_colorSource,                11,       &iObj_set_colorSource,                  &iObj_get_colorSource                   },
		{   cgc_foreColor,                  9,        &iObj_set_foreColor,                    &iObj_get_foreColor                     },
		{   cgc_backColor,                  9,        &iObj_set_backColor,                    &iObj_get_backColor                     },
		{   cgc_disabledBackColor,          17,       &iObj_set_disabledBackColor,            &iObj_get_disabledBackColor             },
		{   cgc_disabledForeColor,          17,       &iObj_set_disabledForeColor,            &iObj_get_disabledForeColor             },
		{   cgc_comment,                    7,        &iObj_set_comment,                      &iObj_get_comment                       },
		{   cgc_controlSource,              13,       &iObj_set_controlSource,                &iObj_get_controlSource                 },
		{   cgc_dragIcon,                   8,        &iObj_set_dragIcon,                     &iObj_get_dragIcon                      },
		{   cgc_dragMode,                   8,        &iObj_set_dragMode,                     &iObj_get_dragMode                      },
		{   cgc_enabled,                    7,        &iObj_set_enabled,                      &iObj_get_enabled                       },
		{   cgc_fontBold,                   8,        &iObj_set_fontBold,                     &iObj_get_fontBold                      },
		{   cgc_fontCharSet,                11,       &iObj_set_fontCharSet,                  &iObj_get_fontCharSet                   },
		{   cgc_fontCondense,               12,       &iObj_set_fontCondense,                 &iObj_get_fontCondense                  },
		{   cgc_fontExtend,                 10,       &iObj_set_fontExtend,                   &iObj_get_fontExtend                    },
		{   cgc_fontItalic,                 10,       &iObj_set_fontItalic,                   &iObj_get_fontItalic                    },
		{   cgc_fontName,                   8,        &iObj_set_fontName,                     &iObj_get_fontName                      },
		{   cgc_fontOutline,                11,       &iObj_set_fontOutline,                  &iObj_get_fontOutline                   },
		{   cgc_fontShadow,                 10,       &iObj_set_fontShadow,                   &iObj_get_fontShadow                    },
		{   cgc_fontSize,                   8,        &iObj_set_fontSize,                     &iObj_get_fontSize                      },
		{   cgc_fontStrikeThru,             14,       &iObj_set_fontStrikeThru,               &iObj_get_fontStrikeThru                },
		{   cgc_fontUnderline,              13,       &iObj_set_fontUnderline,                &iObj_get_fontUnderline                 },
		{   cgc_height,                     6,        &iObj_set_height,                       &iObj_get_height                        },
		{   cgc_helpContextID,              13,       &iObj_set_helpContextID,                &iObj_get_helpContextID                 },
		{   cgc_left,                       4,        &iObj_set_left,                         &iObj_get_left                          },
		{   cgc_mouseIcon,                  9,        &iObj_set_mouseIcon,                    &iObj_get_mouseIcon                     },
		{   cgc_mousePointer,               12,       &iObj_set_mousePointer,                 &iObj_get_mousePointer                  },
		{   cgc_name,                       4,        &iObj_set_name,                         &iObj_get_name                          },
		{   cgc_oLEDragMode,                11,       &iObj_set_oLEDragMode,                  &iObj_get_oLEDragMode                   },
		{   cgc_oLEDragPicture,             14,       &iObj_set_oLEDragPicture,               &iObj_get_oLEDragPicture                },
		{   cgc_oLEDropEffects,             14,       &iObj_set_oLEDropEffects,               &iObj_get_oLEDropEffects                },
		{   cgc_oLEDropMode,                11,       &iObj_set_oLEDropMode,                  &iObj_get_oLEDropMode                   },
		{   cgc_picture,                    7,        &iObj_set_picture,                      &iObj_get_picture                       },
		{   cgc_pictureMargin,              13,       &iObj_set_pictureMargin,                &iObj_get_pictureMargin                 },
		{   cgc_picturePosition,            15,       &iObj_set_picturePosition,              &iObj_get_picturePosition               },
		{   cgc_pictureSpacing,             14,       &iObj_set_pictureSpacing,               &iObj_get_pictureSpacing                },
		{   cgc_disabledPicture,            15,       &iObj_set_disabledPicture,              &iObj_get_disabledPicture               },
		{   cgc_downPicture,                11,       &iObj_set_downPicture,                  &iObj_get_downPicture                   },
		{   cgc_rightToLeft,                11,       &iObj_set_rightToLeft,                  &iObj_get_rightToLeft                   },
		{   cgc_specialEffect,              13,       &iObj_set_specialEffect,                &iObj_get_specialEffect                 },
		{   cgc_statusBarText,              13,       &iObj_set_statusBarText,                &iObj_get_statusBarText                 },
		{   cgc_style,                      5,        &iObj_set_style,                        &iObj_get_style                         },
		{   cgc_tabIndex,                   8,        &iObj_set_tabIndex,                     &iObj_get_tabIndex                      },
		{   cgc_tabStop,                    7,        &iObj_set_tabStop,                      &iObj_get_tabStop                       },
		{   cgc_tag,                        3,        &iObj_set_tag,                          &iObj_get_tag                           },
		{   cgc_terminateRead,              13,       &iObj_set_terminateRead,                &iObj_get_terminateRead                 },
		{   cgc_themes,                     6,        &iObj_set_themes,                       &iObj_get_themes                        },
		{   cgc_toolTipText,                11,       &iObj_set_toolTipText,                  &iObj_get_toolTipText                   },
		{   cgc_top,                        3,        &iObj_set_top,                          &iObj_get_top                           },
		{   cgc_value,                      5,        &iObj_set_value,                        &iObj_get_value                         },
		{   cgc_visible,                    7,        &iObj_set_visible,                      &iObj_get_visible                       },
		{   cgc_whatsThisHelpID,            15,       &iObj_set_whatsThisHelpID,              &iObj_get_whatsThisHelpID               },
		{   cgc_width,                      5,        &iObj_set_width,                        &iObj_get_width                         },
		{   cgc_wordWrap,                   8,        &iObj_set_wordWrap,                     &iObj_get_wordWrap                      },
		{   NULL,                           0,        0,                                      0                                       }
	};

	SPropertyMap gcProps_optgroup[] = 
	{
		// Translation for VJr provided by Hernan Cano Martinez
		{   cgc_anchor,                     6,        &iObj_set_anchor,                       &iObj_get_anchor                        },
		{   cgc_autoSize,                   8,        &iObj_set_autoSize,                     &iObj_get_autoSize                      },
		{   cgc_backStyle,                  9,        &iObj_set_backStyle,                    &iObj_get_backStyle                     },
		{   cgc_buttonCount,                11,       &iObj_set_buttonCount,                  &iObj_get_buttonCount                   },
		{   cgc_borderColor,                11,       &iObj_set_borderColor,                  &iObj_get_borderColor                   },
		{   cgc_borderStyle,                11,       &iObj_set_borderStyle,                  &iObj_get_borderStyle                   },
		{   cgc_colorSource,                11,       &iObj_set_colorSource,                  &iObj_get_colorSource                   },
		{   cgc_backColor,                  9,        &iObj_set_backColor,                    &iObj_get_backColor                     },
		{   cgc_comment,                    7,        &iObj_set_comment,                      &iObj_get_comment                       },
		{   cgc_controlSource,              13,       &iObj_set_controlSource,                &iObj_get_controlSource                 },
		{   cgc_dragIcon,                   8,        &iObj_set_dragIcon,                     &iObj_get_dragIcon                      },
		{   cgc_dragMode,                   8,        &iObj_set_dragMode,                     &iObj_get_dragMode                      },
		{   cgc_enabled,                    7,        &iObj_set_enabled,                      &iObj_get_enabled                       },
		{   cgc_height,                     6,        &iObj_set_height,                       &iObj_get_height                        },
		{   cgc_helpContextID,              13,       &iObj_set_helpContextID,                &iObj_get_helpContextID                 },
		{   cgc_left,                       4,        &iObj_set_left,                         &iObj_get_left                          },
		{   cgc_memberClass,                11,       &iObj_set_memberClass,                  &iObj_get_memberClass                   },
		{   cgc_memberClassLibrary,         18,       &iObj_set_memberClassLibrary,           &iObj_get_memberClassLibrary            },
		{   cgc_mouseIcon,                  9,        &iObj_set_mouseIcon,                    &iObj_get_mouseIcon                     },
		{   cgc_mousePointer,               12,       &iObj_set_mousePointer,                 &iObj_get_mousePointer                  },
		{   cgc_name,                       4,        &iObj_set_name,                         &iObj_get_name                          },
		{   cgc_oLEDragMode,                11,       &iObj_set_oLEDragMode,                  &iObj_get_oLEDragMode                   },
		{   cgc_oLEDragPicture,             14,       &iObj_set_oLEDragPicture,               &iObj_get_oLEDragPicture                },
		{   cgc_oLEDropEffects,             14,       &iObj_set_oLEDropEffects,               &iObj_get_oLEDropEffects                },
		{   cgc_oLEDropMode,                11,       &iObj_set_oLEDropMode,                  &iObj_get_oLEDropMode                   },
		{   cgc_specialEffect,              13,       &iObj_set_specialEffect,                &iObj_get_specialEffect                 },
		{   cgc_statusBarText,              13,       &iObj_set_statusBarText,                &iObj_get_statusBarText                 },
		{   cgc_tabIndex,                   8,        &iObj_set_tabIndex,                     &iObj_get_tabIndex                      },
		{   cgc_tag,                        3,        &iObj_set_tag,                          &iObj_get_tag                           },
		{   cgc_terminateRead,              13,       &iObj_set_terminateRead,                &iObj_get_terminateRead                 },
		{   cgc_themes,                     6,        &iObj_set_themes,                       &iObj_get_themes                        },
		{   cgc_toolTipText,                11,       &iObj_set_toolTipText,                  &iObj_get_toolTipText                   },
		{   cgc_top,                        3,        &iObj_set_top,                          &iObj_get_top                           },
		{   cgc_value,                      5,        &iObj_set_value,                        &iObj_get_value                         },
		{   cgc_visible,                    7,        &iObj_set_visible,                      &iObj_get_visible                       },
		{   cgc_whatsThisHelpID,            15,       &iObj_set_whatsThisHelpID,              &iObj_get_whatsThisHelpID               },
		{   cgc_width,                      5,        &iObj_set_width,                        &iObj_get_width                         },
		{   NULL,                           0,        0,                                      0                                       }
	};

	SPropertyMap gcProps_textbox[] = 
	{
		// Translation for VJr provided by Hernan Cano Martinez
		{   cgc_alignment,                  9,        &iObj_set_alignment,                    &iObj_get_alignment                     },
		{   cgc_anchor,                     6,        &iObj_set_anchor,                       &iObj_get_anchor                        },
		{   cgc_application,                11,       &iObj_set_application,                  &iObj_get_application                   },
		{   cgc_autoComplete,               12,       &iObj_set_autoComplete,                 &iObj_get_autoComplete                  },
		{   cgc_autoCompTable,              13,       &iObj_set_autoCompTable,                &iObj_get_autoCompTable                 },
		{   cgc_autoCompSource,             14,       &iObj_set_autoCompSource,               &iObj_get_autoCompSource                },
		{   cgc_backStyle,                  9,        &iObj_set_backStyle,                    &iObj_get_backStyle                     },
		{   cgc_baseClass,                  9,        &iObj_set_baseClass,                    &iObj_get_baseClass                     },
		{   cgc_class,                      5,        &iObj_set_class,                        &iObj_get_class                         },
		{   cgc_classLibrary,               12,       &iObj_set_classLibrary,                 &iObj_get_classLibrary                  },
		{   cgc_borderColor,                11,       &iObj_set_borderColor,                  &iObj_get_borderColor                   },
		{   cgc_borderStyle,                11,       &iObj_set_borderStyle,                  &iObj_get_borderStyle                   },
		{   cgc_century,                    7,        &iObj_set_century,                      &iObj_get_century                       },
		{   cgc_colorScheme,                11,       &iObj_set_colorScheme,                  &iObj_get_colorScheme                   },
		{   cgc_colorSource,                11,       &iObj_set_colorSource,                  &iObj_get_colorSource                   },
		{   cgc_foreColor,                  9,        &iObj_set_foreColor,                    &iObj_get_foreColor                     },
		{   cgc_backColor,                  9,        &iObj_set_backColor,                    &iObj_get_backColor                     },
		{   cgc_disabledBackColor,          17,       &iObj_set_disabledBackColor,            &iObj_get_disabledBackColor             },
		{   cgc_disabledForeColor,          17,       &iObj_set_disabledForeColor,            &iObj_get_disabledForeColor             },
		{   cgc_comment,                    7,        &iObj_set_comment,                      &iObj_get_comment                       },
		{   cgc_controlSource,              13,       &iObj_set_controlSource,                &iObj_get_controlSource                 },
		{   cgc_dateFormat,                 10,       &iObj_set_dateFormat,                   &iObj_get_dateFormat                    },
		{   cgc_dateMark,                   8,        &iObj_set_dateMark,                     &iObj_get_dateMark                      },
		{   cgc_dragIcon,                   8,        &iObj_set_dragIcon,                     &iObj_get_dragIcon                      },
		{   cgc_dragMode,                   8,        &iObj_set_dragMode,                     &iObj_get_dragMode                      },
		{   cgc_enabled,                    7,        &iObj_set_enabled,                      &iObj_get_enabled                       },
		{   cgc_enableHyperlinks,           16,       &iObj_set_enableHyperlinks,             &iObj_get_enableHyperlinks              },
		{   cgc_fontBold,                   8,        &iObj_set_fontBold,                     &iObj_get_fontBold                      },
		{   cgc_fontCharSet,                11,       &iObj_set_fontCharSet,                  &iObj_get_fontCharSet                   },
		{   cgc_fontCondense,               12,       &iObj_set_fontCondense,                 &iObj_get_fontCondense                  },
		{   cgc_fontExtend,                 10,       &iObj_set_fontExtend,                   &iObj_get_fontExtend                    },
		{   cgc_fontItalic,                 10,       &iObj_set_fontItalic,                   &iObj_get_fontItalic                    },
		{   cgc_fontName,                   8,        &iObj_set_fontName,                     &iObj_get_fontName                      },
		{   cgc_fontOutline,                11,       &iObj_set_fontOutline,                  &iObj_get_fontOutline                   },
		{   cgc_fontShadow,                 10,       &iObj_set_fontShadow,                   &iObj_get_fontShadow                    },
		{   cgc_fontSize,                   8,        &iObj_set_fontSize,                     &iObj_get_fontSize                      },
		{   cgc_fontStrikeThru,             14,       &iObj_set_fontStrikeThru,               &iObj_get_fontStrikeThru                },
		{   cgc_fontUnderline,              13,       &iObj_set_fontUnderline,                &iObj_get_fontUnderline                 },
		{   cgc_format,                     6,        &iObj_set_format,                       &iObj_get_format                        },
		{   cgc_height,                     6,        &iObj_set_height,                       &iObj_get_height                        },
		{   cgc_helpContextID,              13,       &iObj_set_helpContextID,                &iObj_get_helpContextID                 },
		{   cgc_hideSelection,              13,       &iObj_set_hideSelection,                &iObj_get_hideSelection                 },
		{   cgc_hours,                      5,        &iObj_set_hours,                        &iObj_get_hours                         },
		{   cgc_iMEMode,                    7,        &iObj_set_iMEMode,                      &iObj_get_iMEMode                       },
		{   cgc_inputMask,                  9,        &iObj_set_inputMask,                    &iObj_get_inputMask                     },
		{   cgc_integralHeight,             14,       &iObj_set_integralHeight,               &iObj_get_integralHeight                },
		{   cgc_left,                       4,        &iObj_set_left,                         &iObj_get_left                          },
		{   cgc_margin,                     6,        &iObj_set_margin,                       &iObj_get_margin                        },
		{   cgc_maxLength,                  9,        &iObj_set_maxLength,                    &iObj_get_maxLength                     },
		{   cgc_mouseIcon,                  9,        &iObj_set_mouseIcon,                    &iObj_get_mouseIcon                     },
		{   cgc_mousePointer,               12,       &iObj_set_mousePointer,                 &iObj_get_mousePointer                  },
		{   cgc_memoWindow,                 10,       &iObj_set_memoWindow,                   &iObj_get_memoWindow                    },
		{   cgc_name,                       4,        &iObj_set_name,                         &iObj_get_name                          },
		{   cgc_nullDisplay,                11,       &iObj_set_nullDisplay,                  &iObj_get_nullDisplay                   },
		{   cgc_oLEDragMode,                11,       &iObj_set_oLEDragMode,                  &iObj_get_oLEDragMode                   },
		{   cgc_oLEDragPicture,             14,       &iObj_set_oLEDragPicture,               &iObj_get_oLEDragPicture                },
		{   cgc_oLEDropEffects,             14,       &iObj_set_oLEDropEffects,               &iObj_get_oLEDropEffects                },
		{   cgc_oLEDropHasData,             14,       &iObj_set_oLEDropHasData,               &iObj_get_oLEDropHasData                },
		{   cgc_oLEDropMode,                11,       &iObj_set_oLEDropMode,                  &iObj_get_oLEDropMode                   },
		{   cgc_oLEDropTextInsertion,       20,       &iObj_set_oLEDropTextInsertion,         &iObj_get_oLEDropTextInsertion          },
		{   cgc_openWindow,                 10,       &iObj_set_openWindow,                   &iObj_get_openWindow                    },
		{   cgc_parent,                     6,        &iObj_set_parent,                       &iObj_get_parent                        },
		{   cgc_parentClass,                11,       &iObj_set_parentClass,                  &iObj_get_parentClass                   },
		{   cgc_passwordChar,               12,       &iObj_set_passwordChar,                 &iObj_get_passwordChar                  },
		{   cgc_readOnly,                   8,        &iObj_set_readOnly,                     &iObj_get_readOnly                      },
		{   cgc_rightToLeft,                11,       &iObj_set_rightToLeft,                  &iObj_get_rightToLeft                   },
		{   cgc_seconds,                    7,        &iObj_set_seconds,                      &iObj_get_seconds                       },
		{   cgc_selectedBackColor,          17,       &iObj_set_selectedBackColor,            &iObj_get_selectedBackColor             },
		{   cgc_selectedForeColor,          17,       &iObj_set_selectedForeColor,            &iObj_get_selectedForeColor             },
		{   cgc_selectOnEntry,              13,       &iObj_set_selectOnEntry,                &iObj_get_selectOnEntry                 },
		{   cgc_selLength,                  9,        &iObj_set_selLength,                    &iObj_get_selLength                     },
		{   cgc_selStart,                   8,        &iObj_set_selStart,                     &iObj_get_selStart                      },
		{   cgc_selText,                    7,        &iObj_set_selText,                      &iObj_get_selText                       },
		{   cgc_specialEffect,              13,       &iObj_set_specialEffect,                &iObj_get_specialEffect                 },
		{   cgc_statusBarText,              13,       &iObj_set_statusBarText,                &iObj_get_statusBarText                 },
		{   cgc_strictDateEntry,            15,       &iObj_set_strictDateEntry,              &iObj_get_strictDateEntry               },
		{   cgc_style,                      5,        &iObj_set_style,                        &iObj_get_style                         },
		{   cgc_tabIndex,                   8,        &iObj_set_tabIndex,                     &iObj_get_tabIndex                      },
		{   cgc_tabStop,                    7,        &iObj_set_tabStop,                      &iObj_get_tabStop                       },
		{   cgc_tag,                        3,        &iObj_set_tag,                          &iObj_get_tag                           },
		{   cgc_terminateRead,              13,       &iObj_set_terminateRead,                &iObj_get_terminateRead                 },
		{   cgc_text,                       4,        &iObj_set_text,                         &iObj_get_text                          },
		{   cgc_themes,                     6,        &iObj_set_themes,                       &iObj_get_themes                        },
		{   cgc_toolTipText,                11,       &iObj_set_toolTipText,                  &iObj_get_toolTipText                   },
		{   cgc_top,                        3,        &iObj_set_top,                          &iObj_get_top                           },
		{   cgc_value,                      5,        &iObj_set_value,                        &iObj_get_value                         },
		{   cgc_visible,                    7,        &iObj_set_visible,                      &iObj_get_visible                       },
		{   cgc_whatsThisHelpID,            15,       &iObj_set_whatsThisHelpID,              &iObj_get_whatsThisHelpID               },
		{   cgc_width,                      5,        &iObj_set_width,                        &iObj_get_width                         },
		{   NULL,                           0,        0,                                      0                                       }
	};

	SPropertyMap gcProps_editbox[] = 
	{
		// Translation for VJr provided by Hernan Cano Martinez
		{   cgc_addLineFeeds,               12,       &iObj_set_addLineFeeds,                 &iObj_get_addLineFeeds                  },
		{   cgc_alignment,                  9,        &iObj_set_alignment,                    &iObj_get_alignment                     },
		{   cgc_allowTabs,                  9,        &iObj_set_allowTabs,                    &iObj_get_allowTabs                     },
		{   cgc_anchor,                     6,        &iObj_set_anchor,                       &iObj_get_anchor                        },
		{   cgc_application,                11,       &iObj_set_application,                  &iObj_get_application                   },
		{   cgc_backStyle,                  9,        &iObj_set_backStyle,                    &iObj_get_backStyle                     },
		{   cgc_baseClass,                  9,        &iObj_set_baseClass,                    &iObj_get_baseClass                     },
		{   cgc_class,                      5,        &iObj_set_class,                        &iObj_get_class                         },
		{   cgc_classLibrary,               12,       &iObj_set_classLibrary,                 &iObj_get_classLibrary                  },
		{   cgc_borderColor,                11,       &iObj_set_borderColor,                  &iObj_get_borderColor                   },
		{   cgc_borderStyle,                11,       &iObj_set_borderStyle,                  &iObj_get_borderStyle                   },
		{   cgc_colorScheme,                11,       &iObj_set_colorScheme,                  &iObj_get_colorScheme                   },
		{   cgc_colorSource,                11,       &iObj_set_colorSource,                  &iObj_get_colorSource                   },
		{   cgc_foreColor,                  9,        &iObj_set_foreColor,                    &iObj_get_foreColor                     },
		{   cgc_backColor,                  9,        &iObj_set_backColor,                    &iObj_get_backColor                     },
		{   cgc_disabledBackColor,          17,       &iObj_set_disabledBackColor,            &iObj_get_disabledBackColor             },
		{   cgc_disabledForeColor,          17,       &iObj_set_disabledForeColor,            &iObj_get_disabledForeColor             },
		{   cgc_comment,                    7,        &iObj_set_comment,                      &iObj_get_comment                       },
		{   cgc_controlSource,              13,       &iObj_set_controlSource,                &iObj_get_controlSource                 },
		{   cgc_dragIcon,                   8,        &iObj_set_dragIcon,                     &iObj_get_dragIcon                      },
		{   cgc_dragMode,                   8,        &iObj_set_dragMode,                     &iObj_get_dragMode                      },
		{   cgc_enabled,                    7,        &iObj_set_enabled,                      &iObj_get_enabled                       },
		{   cgc_enableHyperlinks,           16,       &iObj_set_enableHyperlinks,             &iObj_get_enableHyperlinks              },
		{   cgc_fontBold,                   8,        &iObj_set_fontBold,                     &iObj_get_fontBold                      },
		{   cgc_fontCharSet,                11,       &iObj_set_fontCharSet,                  &iObj_get_fontCharSet                   },
		{   cgc_fontCondense,               12,       &iObj_set_fontCondense,                 &iObj_get_fontCondense                  },
		{   cgc_fontExtend,                 10,       &iObj_set_fontExtend,                   &iObj_get_fontExtend                    },
		{   cgc_fontItalic,                 10,       &iObj_set_fontItalic,                   &iObj_get_fontItalic                    },
		{   cgc_fontName,                   8,        &iObj_set_fontName,                     &iObj_get_fontName                      },
		{   cgc_fontOutline,                11,       &iObj_set_fontOutline,                  &iObj_get_fontOutline                   },
		{   cgc_fontShadow,                 10,       &iObj_set_fontShadow,                   &iObj_get_fontShadow                    },
		{   cgc_fontSize,                   8,        &iObj_set_fontSize,                     &iObj_get_fontSize                      },
		{   cgc_fontStrikeThru,             14,       &iObj_set_fontStrikeThru,               &iObj_get_fontStrikeThru                },
		{   cgc_fontUnderline,              13,       &iObj_set_fontUnderline,                &iObj_get_fontUnderline                 },
		{   cgc_format,                     6,        &iObj_set_format,                       &iObj_get_format                        },
		{   cgc_height,                     6,        &iObj_set_height,                       &iObj_get_height                        },
		{   cgc_helpContextID,              13,       &iObj_set_helpContextID,                &iObj_get_helpContextID                 },
		{   cgc_hideSelection,              13,       &iObj_set_hideSelection,                &iObj_get_hideSelection                 },
		{   cgc_iMEMode,                    7,        &iObj_set_iMEMode,                      &iObj_get_iMEMode                       },
		{   cgc_integralHeight,             14,       &iObj_set_integralHeight,               &iObj_get_integralHeight                },
		{   cgc_left,                       4,        &iObj_set_left,                         &iObj_get_left                          },
		{   cgc_margin,                     6,        &iObj_set_margin,                       &iObj_get_margin                        },
		{   cgc_maxLength,                  9,        &iObj_set_maxLength,                    &iObj_get_maxLength                     },
		{   cgc_mouseIcon,                  9,        &iObj_set_mouseIcon,                    &iObj_get_mouseIcon                     },
		{   cgc_mousePointer,               12,       &iObj_set_mousePointer,                 &iObj_get_mousePointer                  },
		{   cgc_name,                       4,        &iObj_set_name,                         &iObj_get_name                          },
		{   cgc_nullDisplay,                11,       &iObj_set_nullDisplay,                  &iObj_get_nullDisplay                   },
		{   cgc_oLEDragMode,                11,       &iObj_set_oLEDragMode,                  &iObj_get_oLEDragMode                   },
		{   cgc_oLEDragPicture,             14,       &iObj_set_oLEDragPicture,               &iObj_get_oLEDragPicture                },
		{   cgc_oLEDropEffects,             14,       &iObj_set_oLEDropEffects,               &iObj_get_oLEDropEffects                },
		{   cgc_oLEDropHasData,             14,       &iObj_set_oLEDropHasData,               &iObj_get_oLEDropHasData                },
		{   cgc_oLEDropMode,                11,       &iObj_set_oLEDropMode,                  &iObj_get_oLEDropMode                   },
		{   cgc_oLEDropTextInsertion,       20,       &iObj_set_oLEDropTextInsertion,         &iObj_get_oLEDropTextInsertion          },
		{   cgc_parent,                     6,        &iObj_set_parent,                       &iObj_get_parent                        },
		{   cgc_parentClass,                11,       &iObj_set_parentClass,                  &iObj_get_parentClass                   },
		{   cgc_passwordChar,               12,       &iObj_set_passwordChar,                 &iObj_get_passwordChar                  },
		{   cgc_readOnly,                   8,        &iObj_set_readOnly,                     &iObj_get_readOnly                      },
		{   cgc_rightToLeft,                11,       &iObj_set_rightToLeft,                  &iObj_get_rightToLeft                   },
		{   cgc_scrollBars,                 10,       &iObj_set_scrollBars,                   &iObj_get_scrollBars                    },
		{   cgc_selectedBackColor,          17,       &iObj_set_selectedBackColor,            &iObj_get_selectedBackColor             },
		{   cgc_selectedForeColor,          17,       &iObj_set_selectedForeColor,            &iObj_get_selectedForeColor             },
		{   cgc_selectOnEntry,              13,       &iObj_set_selectOnEntry,                &iObj_get_selectOnEntry                 },
		{   cgc_selLength,                  9,        &iObj_set_selLength,                    &iObj_get_selLength                     },
		{   cgc_selStart,                   8,        &iObj_set_selStart,                     &iObj_get_selStart                      },
		{   cgc_selText,                    7,        &iObj_set_selText,                      &iObj_get_selText                       },
		{   cgc_specialEffect,              13,       &iObj_set_specialEffect,                &iObj_get_specialEffect                 },
		{   cgc_statusBarText,              13,       &iObj_set_statusBarText,                &iObj_get_statusBarText                 },
		{   cgc_tabIndex,                   8,        &iObj_set_tabIndex,                     &iObj_get_tabIndex                      },
		{   cgc_tabStop,                    7,        &iObj_set_tabStop,                      &iObj_get_tabStop                       },
		{   cgc_tag,                        3,        &iObj_set_tag,                          &iObj_get_tag                           },
		{   cgc_terminateRead,              13,       &iObj_set_terminateRead,                &iObj_get_terminateRead                 },
		{   cgc_text,                       4,        &iObj_set_text,                         &iObj_get_text                          },
		{   cgc_toolTipText,                11,       &iObj_set_toolTipText,                  &iObj_get_toolTipText                   },
		{   cgc_top,                        3,        &iObj_set_top,                          &iObj_get_top                           },
		{   cgc_value,                      5,        &iObj_set_value,                        &iObj_get_value                         },
		{   cgc_visible,                    7,        &iObj_set_visible,                      &iObj_get_visible                       },
		{   cgc_whatsThisHelpID,            15,       &iObj_set_whatsThisHelpID,              &iObj_get_whatsThisHelpID               },
		{   cgc_width,                      5,        &iObj_set_width,                        &iObj_get_width                         },
		{   NULL,                           0,        0,                                      0                                       }
	};

	SPropertyMap gcProps_listbox[] = 
	{
		// Translation for VJr provided by Hernan Cano Martinez
		{   cgc_anchor,                     6,        &iObj_set_anchor,                       &iObj_get_anchor                        },
		{   cgc_application,                11,       &iObj_set_application,                  &iObj_get_application                   },
		{   cgc_autoHideScrollBar,          17,       &iObj_set_autoHideScrollBar,            &iObj_get_autoHideScrollBar             },
		{   cgc_baseClass,                  9,        &iObj_set_baseClass,                    &iObj_get_baseClass                     },
		{   cgc_class,                      5,        &iObj_set_class,                        &iObj_get_class                         },
		{   cgc_classLibrary,               12,       &iObj_set_classLibrary,                 &iObj_get_classLibrary                  },
		{   cgc_listCount,                  9,        &iObj_set_listCount,                    &iObj_get_listCount                     },
		{   cgc_columnCount,                11,       &iObj_set_columnCount,                  &iObj_get_columnCount                   },
		{   cgc_borderColor,                11,       &iObj_set_borderColor,                  &iObj_get_borderColor                   },
		{   cgc_boundColumn,                11,       &iObj_set_boundColumn,                  &iObj_get_boundColumn                   },
		{   cgc_boundTo,                    7,        &iObj_set_boundTo,                      &iObj_get_boundTo                       },
		{   cgc_colorScheme,                11,       &iObj_set_colorScheme,                  &iObj_get_colorScheme                   },
		{   cgc_colorSource,                11,       &iObj_set_colorSource,                  &iObj_get_colorSource                   },
		{   cgc_disabledBackColor,          17,       &iObj_set_disabledBackColor,            &iObj_get_disabledBackColor             },
		{   cgc_disabledForeColor,          17,       &iObj_set_disabledForeColor,            &iObj_get_disabledForeColor             },
		{   cgc_disabledItemBackColor,      21,       &iObj_set_disabledItemBackColor,        &iObj_get_disabledItemBackColor         },
		{   cgc_disabledItemForeColor,      21,       &iObj_set_disabledItemForeColor,        &iObj_get_disabledItemForeColor         },
		{   cgc_columnLines,                11,       &iObj_set_columnLines,                  &iObj_get_columnLines                   },
		{   cgc_columnWidths,               12,       &iObj_set_columnWidths,                 &iObj_get_columnWidths                  },
		{   cgc_comment,                    7,        &iObj_set_comment,                      &iObj_get_comment                       },
		{   cgc_controlSource,              13,       &iObj_set_controlSource,                &iObj_get_controlSource                 },
		{   cgc_rowSource,                  9,        &iObj_set_rowSource,                    &iObj_get_rowSource                     },
		{   cgc_rowSourceType,              13,       &iObj_set_rowSourceType,                &iObj_get_rowSourceType                 },
		{   cgc_displayValue,               12,       &iObj_set_displayValue,                 &iObj_get_displayValue                  },
		{   cgc_dragIcon,                   8,        &iObj_set_dragIcon,                     &iObj_get_dragIcon                      },
		{   cgc_dragMode,                   8,        &iObj_set_dragMode,                     &iObj_get_dragMode                      },
		{   cgc_enabled,                    7,        &iObj_set_enabled,                      &iObj_get_enabled                       },
		{   cgc_firstElement,               12,       &iObj_set_firstElement,                 &iObj_get_firstElement                  },
		{   cgc_fontBold,                   8,        &iObj_set_fontBold,                     &iObj_get_fontBold                      },
		{   cgc_fontCharSet,                11,       &iObj_set_fontCharSet,                  &iObj_get_fontCharSet                   },
		{   cgc_fontCondense,               12,       &iObj_set_fontCondense,                 &iObj_get_fontCondense                  },
		{   cgc_fontExtend,                 10,       &iObj_set_fontExtend,                   &iObj_get_fontExtend                    },
		{   cgc_fontItalic,                 10,       &iObj_set_fontItalic,                   &iObj_get_fontItalic                    },
		{   cgc_fontName,                   8,        &iObj_set_fontName,                     &iObj_get_fontName                      },
		{   cgc_fontOutline,                11,       &iObj_set_fontOutline,                  &iObj_get_fontOutline                   },
		{   cgc_fontShadow,                 10,       &iObj_set_fontShadow,                   &iObj_get_fontShadow                    },
		{   cgc_fontSize,                   8,        &iObj_set_fontSize,                     &iObj_get_fontSize                      },
		{   cgc_fontStrikeThru,             14,       &iObj_set_fontStrikeThru,               &iObj_get_fontStrikeThru                },
		{   cgc_fontUnderLine,              13,       &iObj_set_fontUnderLine,                &iObj_get_fontUnderLine                 },
		{   cgc_height,                     6,        &iObj_set_height,                       &iObj_get_height                        },
		{   cgc_helpContextID,              13,       &iObj_set_helpContextID,                &iObj_get_helpContextID                 },
		{   cgc_incrementalSearch,          17,       &iObj_set_incrementalSearch,            &iObj_get_incrementalSearch             },
		{   cgc_integralHeight,             14,       &iObj_set_integralHeight,               &iObj_get_integralHeight                },
		{   cgc_itemBackColor,              13,       &iObj_set_itemBackColor,                &iObj_get_itemBackColor                 },
		{   cgc_itemForeColor,              13,       &iObj_set_itemForeColor,                &iObj_get_itemForeColor                 },
		{   cgc_itemData,                   8,        &iObj_set_itemData,                     &iObj_get_itemData                      },
		{   cgc_itemIDData,                 10,       &iObj_set_itemIDData,                   &iObj_get_itemIDData                    },
		{   cgc_itemTips,                   8,        &iObj_set_itemTips,                     &iObj_get_itemTips                      },
		{   cgc_left,                       4,        &iObj_set_left,                         &iObj_get_left                          },
		{   cgc_list,                       4,        &iObj_set_list,                         &iObj_get_list                          },
		{   cgc_listIndex,                  9,        &iObj_set_listIndex,                    &iObj_get_listIndex                     },
		{   cgc_listItem,                   8,        &iObj_set_listItem,                     &iObj_get_listItem                      },
		{   cgc_listItemID,                 10,       &iObj_set_listItemID,                   &iObj_get_listItemID                    },
		{   cgc_mouseIcon,                  9,        &iObj_set_mouseIcon,                    &iObj_get_mouseIcon                     },
		{   cgc_mousePointer,               12,       &iObj_set_mousePointer,                 &iObj_get_mousePointer                  },
		{   cgc_moverBars,                  9,        &iObj_set_moverBars,                    &iObj_get_moverBars                     },
		{   cgc_multiSelect,                11,       &iObj_set_multiSelect,                  &iObj_get_multiSelect                   },
		{   cgc_name,                       4,        &iObj_set_name,                         &iObj_get_name                          },
		{   cgc_newIndex,                   8,        &iObj_set_newIndex,                     &iObj_get_newIndex                      },
		{   cgc_newItemID,                  9,        &iObj_set_newItemID,                    &iObj_get_newItemID                     },
		{   cgc_nullDisplay,                11,       &iObj_set_nullDisplay,                  &iObj_get_nullDisplay                   },
		{   cgc_numberOfElements,           16,       &iObj_set_numberOfElements,             &iObj_get_numberOfElements              },
		{   cgc_oLEDragMode,                11,       &iObj_set_oLEDragMode,                  &iObj_get_oLEDragMode                   },
		{   cgc_oLEDragPicture,             14,       &iObj_set_oLEDragPicture,               &iObj_get_oLEDragPicture                },
		{   cgc_oLEDropEffects,             14,       &iObj_set_oLEDropEffects,               &iObj_get_oLEDropEffects                },
		{   cgc_oLEDropHasData,             14,       &iObj_set_oLEDropHasData,               &iObj_get_oLEDropHasData                },
		{   cgc_oLEDropMode,                11,       &iObj_set_oLEDropMode,                  &iObj_get_oLEDropMode                   },
		{   cgc_parent,                     6,        &iObj_set_parent,                       &iObj_get_parent                        },
		{   cgc_parentClass,                11,       &iObj_set_parentClass,                  &iObj_get_parentClass                   },
		{   cgc_picture,                    7,        &iObj_set_picture,                      &iObj_get_picture                       },
		{   cgc_rightToLeft,                11,       &iObj_set_rightToLeft,                  &iObj_get_rightToLeft                   },
		{   cgc_selected,                   8,        &iObj_set_selected,                     &iObj_get_selected                      },
		{   cgc_selectedID,                 10,       &iObj_set_selectedID,                   &iObj_get_selectedID                    },
		{   cgc_selectedItemBackColor,      21,       &iObj_set_selectedItemBackColor,        &iObj_get_selectedItemBackColor         },
		{   cgc_selectedItemForeColor,      21,       &iObj_set_selectedItemForeColor,        &iObj_get_selectedItemForeColor         },
		{   cgc_sorted,                     6,        &iObj_set_sorted,                       &iObj_get_sorted                        },
		{   cgc_specialEffect,              13,       &iObj_set_specialEffect,                &iObj_get_specialEffect                 },
		{   cgc_statusBarText,              13,       &iObj_set_statusBarText,                &iObj_get_statusBarText                 },
		{   cgc_tabIndex,                   8,        &iObj_set_tabIndex,                     &iObj_get_tabIndex                      },
		{   cgc_tabStop,                    7,        &iObj_set_tabStop,                      &iObj_get_tabStop                       },
		{   cgc_tag,                        3,        &iObj_set_tag,                          &iObj_get_tag                           },
		{   cgc_terminateRead,              13,       &iObj_set_terminateRead,                &iObj_get_terminateRead                 },
		{   cgc_themes,                     6,        &iObj_set_themes,                       &iObj_get_themes                        },
		{   cgc_toolTipText,                11,       &iObj_set_toolTipText,                  &iObj_get_toolTipText                   },
		{   cgc_top,                        3,        &iObj_set_top,                          &iObj_get_top                           },
		{   cgc_topIndex,                   8,        &iObj_set_topIndex,                     &iObj_get_topIndex                      },
		{   cgc_topItemID,                  9,        &iObj_set_topItemID,                    &iObj_get_topItemID                     },
		{   cgc_value,                      5,        &iObj_set_value,                        &iObj_get_value                         },
		{   cgc_visible,                    7,        &iObj_set_visible,                      &iObj_get_visible                       },
		{   cgc_whatsThisHelpID,            15,       &iObj_set_whatsThisHelpID,              &iObj_get_whatsThisHelpID               },
		{   cgc_width,                      5,        &iObj_set_width,                        &iObj_get_width                         },
		{   NULL,                           0,        0,                                      0                                       }
	};

	SPropertyMap gcProps_combobox[] = 
	{
		// Translation for VJr provided by Hernan Cano Martinez
		{   cgc_alignment,                  9,        &iObj_set_alignment,                    &iObj_get_alignment                     },
		{   cgc_anchor,                     6,        &iObj_set_anchor,                       &iObj_get_anchor                        },
		{   cgc_application,                11,       &iObj_set_application,                  &iObj_get_application                   },
		{   cgc_baseClass,                  9,        &iObj_set_baseClass,                    &iObj_get_baseClass                     },
		{   cgc_class,                      5,        &iObj_set_class,                        &iObj_get_class                         },
		{   cgc_classLibrary,               12,       &iObj_set_classLibrary,                 &iObj_get_classLibrary                  },
		{   cgc_listCount,                  9,        &iObj_set_listCount,                    &iObj_get_listCount                     },
		{   cgc_columnCount,                11,       &iObj_set_columnCount,                  &iObj_get_columnCount                   },
		{   cgc_borderColor,                11,       &iObj_set_borderColor,                  &iObj_get_borderColor                   },
		{   cgc_borderStyle,                11,       &iObj_set_borderStyle,                  &iObj_get_borderStyle                   },
		{   cgc_boundColumn,                11,       &iObj_set_boundColumn,                  &iObj_get_boundColumn                   },
		{   cgc_boundTo,                    7,        &iObj_set_boundTo,                      &iObj_get_boundTo                       },
		{   cgc_colorScheme,                11,       &iObj_set_colorScheme,                  &iObj_get_colorScheme                   },
		{   cgc_colorSource,                11,       &iObj_set_colorSource,                  &iObj_get_colorSource                   },
		{   cgc_foreColor,                  9,        &iObj_set_foreColor,                    &iObj_get_foreColor                     },
		{   cgc_backColor,                  9,        &iObj_set_backColor,                    &iObj_get_backColor                     },
		{   cgc_disabledBackColor,          17,       &iObj_set_disabledBackColor,            &iObj_get_disabledBackColor             },
		{   cgc_disabledForeColor,          17,       &iObj_set_disabledForeColor,            &iObj_get_disabledForeColor             },
		{   cgc_disabledItemBackColor,      21,       &iObj_set_disabledItemBackColor,        &iObj_get_disabledItemBackColor         },
		{   cgc_disabledItemForeColor,      21,       &iObj_set_disabledItemForeColor,        &iObj_get_disabledItemForeColor         },
		{   cgc_columnLines,                11,       &iObj_set_columnLines,                  &iObj_get_columnLines                   },
		{   cgc_columnWidths,               12,       &iObj_set_columnWidths,                 &iObj_get_columnWidths                  },
		{   cgc_comment,                    7,        &iObj_set_comment,                      &iObj_get_comment                       },
		{   cgc_controlSource,              13,       &iObj_set_controlSource,                &iObj_get_controlSource                 },
		{   cgc_rowSource,                  9,        &iObj_set_rowSource,                    &iObj_get_rowSource                     },
		{   cgc_rowSourceType,              13,       &iObj_set_rowSourceType,                &iObj_get_rowSourceType                 },
		{   cgc_displayCount,               12,       &iObj_set_displayCount,                 &iObj_get_displayCount                  },
		{   cgc_displayValue,               12,       &iObj_set_displayValue,                 &iObj_get_displayValue                  },
		{   cgc_dragIcon,                   8,        &iObj_set_dragIcon,                     &iObj_get_dragIcon                      },
		{   cgc_dragMode,                   8,        &iObj_set_dragMode,                     &iObj_get_dragMode                      },
		{   cgc_enabled,                    7,        &iObj_set_enabled,                      &iObj_get_enabled                       },
		{   cgc_firstElement,               12,       &iObj_set_firstElement,                 &iObj_get_firstElement                  },
		{   cgc_fontBold,                   8,        &iObj_set_fontBold,                     &iObj_get_fontBold                      },
		{   cgc_fontCharSet,                11,       &iObj_set_fontCharSet,                  &iObj_get_fontCharSet                   },
		{   cgc_fontCondense,               12,       &iObj_set_fontCondense,                 &iObj_get_fontCondense                  },
		{   cgc_fontExtend,                 10,       &iObj_set_fontExtend,                   &iObj_get_fontExtend                    },
		{   cgc_fontItalic,                 10,       &iObj_set_fontItalic,                   &iObj_get_fontItalic                    },
		{   cgc_fontName,                   8,        &iObj_set_fontName,                     &iObj_get_fontName                      },
		{   cgc_fontOutline,                11,       &iObj_set_fontOutline,                  &iObj_get_fontOutline                   },
		{   cgc_fontShadow,                 10,       &iObj_set_fontShadow,                   &iObj_get_fontShadow                    },
		{   cgc_fontSize,                   8,        &iObj_set_fontSize,                     &iObj_get_fontSize                      },
		{   cgc_fontStrikeThru,             14,       &iObj_set_fontStrikeThru,               &iObj_get_fontStrikeThru                },
		{   cgc_fontUnderline,              13,       &iObj_set_fontUnderline,                &iObj_get_fontUnderline                 },
		{   cgc_format,                     6,        &iObj_set_format,                       &iObj_get_format                        },
		{   cgc_height,                     6,        &iObj_set_height,                       &iObj_get_height                        },
		{   cgc_helpContextID,              13,       &iObj_set_helpContextID,                &iObj_get_helpContextID                 },
		{   cgc_hideSelection,              13,       &iObj_set_hideSelection,                &iObj_get_hideSelection                 },
		{   cgc_iMEMode,                    7,        &iObj_set_iMEMode,                      &iObj_get_iMEMode                       },
		{   cgc_incrementalSearch,          17,       &iObj_set_incrementalSearch,            &iObj_get_incrementalSearch             },
		{   cgc_inputMask,                  9,        &iObj_set_inputMask,                    &iObj_get_inputMask                     },
		{   cgc_itemBackColor,              13,       &iObj_set_itemBackColor,                &iObj_get_itemBackColor                 },
		{   cgc_itemForeColor,              13,       &iObj_set_itemForeColor,                &iObj_get_itemForeColor                 },
		{   cgc_itemData,                   8,        &iObj_set_itemData,                     &iObj_get_itemData                      },
		{   cgc_itemIDData,                 10,       &iObj_set_itemIDData,                   &iObj_get_itemIDData                    },
		{   cgc_itemTips,                   8,        &iObj_set_itemTips,                     &iObj_get_itemTips                      },
		{   cgc_left,                       4,        &iObj_set_left,                         &iObj_get_left                          },
		{   cgc_list,                       4,        &iObj_set_list,                         &iObj_get_list                          },
		{   cgc_listIndex,                  9,        &iObj_set_listIndex,                    &iObj_get_listIndex                     },
		{   cgc_listItem,                   8,        &iObj_set_listItem,                     &iObj_get_listItem                      },
		{   cgc_listItemID,                 10,       &iObj_set_listItemID,                   &iObj_get_listItemID                    },
		{   cgc_margin,                     6,        &iObj_set_margin,                       &iObj_get_margin                        },
		{   cgc_maxLength,                  9,        &iObj_set_maxLength,                    &iObj_get_maxLength                     },
		{   cgc_mouseIcon,                  9,        &iObj_set_mouseIcon,                    &iObj_get_mouseIcon                     },
		{   cgc_mousePointer,               12,       &iObj_set_mousePointer,                 &iObj_get_mousePointer                  },
		{   cgc_name,                       4,        &iObj_set_name,                         &iObj_get_name                          },
		{   cgc_newIndex,                   8,        &iObj_set_newIndex,                     &iObj_get_newIndex                      },
		{   cgc_newItemID,                  9,        &iObj_set_newItemID,                    &iObj_get_newItemID                     },
		{   cgc_nullDisplay,                11,       &iObj_set_nullDisplay,                  &iObj_get_nullDisplay                   },
		{   cgc_numberOfElements,           16,       &iObj_set_numberOfElements,             &iObj_get_numberOfElements              },
		{   cgc_oLEDragMode,                11,       &iObj_set_oLEDragMode,                  &iObj_get_oLEDragMode                   },
		{   cgc_oLEDragPicture,             14,       &iObj_set_oLEDragPicture,               &iObj_get_oLEDragPicture                },
		{   cgc_oLEDropEffects,             14,       &iObj_set_oLEDropEffects,               &iObj_get_oLEDropEffects                },
		{   cgc_oLEDropHasData,             14,       &iObj_set_oLEDropHasData,               &iObj_get_oLEDropHasData                },
		{   cgc_oLEDropMode,                11,       &iObj_set_oLEDropMode,                  &iObj_get_oLEDropMode                   },
		{   cgc_oLEDropTextInsertion,       20,       &iObj_set_oLEDropTextInsertion,         &iObj_get_oLEDropTextInsertion          },
		{   cgc_parent,                     6,        &iObj_set_parent,                       &iObj_get_parent                        },
		{   cgc_parentClass,                11,       &iObj_set_parentClass,                  &iObj_get_parentClass                   },
		{   cgc_picture,                    7,        &iObj_set_picture,                      &iObj_get_picture                       },
		{   cgc_pictureSelectionDisplay,    23,       &iObj_set_pictureSelectionDisplay,      &iObj_get_pictureSelectionDisplay       },
		{   cgc_readOnly,                   8,        &iObj_set_readOnly,                     &iObj_get_readOnly                      },
		{   cgc_rightToLeft,                11,       &iObj_set_rightToLeft,                  &iObj_get_rightToLeft                   },
		{   cgc_selected,                   8,        &iObj_set_selected,                     &iObj_get_selected                      },
		{   cgc_selectedID,                 10,       &iObj_set_selectedID,                   &iObj_get_selectedID                    },
		{   cgc_selectedBackColor,          17,       &iObj_set_selectedBackColor,            &iObj_get_selectedBackColor             },
		{   cgc_selectedForeColor,          17,       &iObj_set_selectedForeColor,            &iObj_get_selectedForeColor             },
		{   cgc_selectedItemBackColor,      21,       &iObj_set_selectedItemBackColor,        &iObj_get_selectedItemBackColor         },
		{   cgc_selectedItemForeColor,      21,       &iObj_set_selectedItemForeColor,        &iObj_get_selectedItemForeColor         },
		{   cgc_selectOnEntry,              13,       &iObj_set_selectOnEntry,                &iObj_get_selectOnEntry                 },
		{   cgc_selLength,                  9,        &iObj_set_selLength,                    &iObj_get_selLength                     },
		{   cgc_selStart,                   8,        &iObj_set_selStart,                     &iObj_get_selStart                      },
		{   cgc_selText,                    7,        &iObj_set_selText,                      &iObj_get_selText                       },
		{   cgc_sorted,                     6,        &iObj_set_sorted,                       &iObj_get_sorted                        },
		{   cgc_specialEffect,              13,       &iObj_set_specialEffect,                &iObj_get_specialEffect                 },
		{   cgc_statusBarText,              13,       &iObj_set_statusBarText,                &iObj_get_statusBarText                 },
		{   cgc_style,                      5,        &iObj_set_style,                        &iObj_get_style                         },
		{   cgc_tabIndex,                   8,        &iObj_set_tabIndex,                     &iObj_get_tabIndex                      },
		{   cgc_tabStop,                    7,        &iObj_set_tabStop,                      &iObj_get_tabStop                       },
		{   cgc_tag,                        3,        &iObj_set_tag,                          &iObj_get_tag                           },
		{   cgc_terminateRead,              13,       &iObj_set_terminateRead,                &iObj_get_terminateRead                 },
		{   cgc_text,                       4,        &iObj_set_text,                         &iObj_get_text                          },
		{   cgc_themes,                     6,        &iObj_set_themes,                       &iObj_get_themes                        },
		{   cgc_toolTipText,                11,       &iObj_set_toolTipText,                  &iObj_get_toolTipText                   },
		{   cgc_top,                        3,        &iObj_set_top,                          &iObj_get_top                           },
		{   cgc_topIndex,                   8,        &iObj_set_topIndex,                     &iObj_get_topIndex                      },
		{   cgc_topItemID,                  9,        &iObj_set_topItemID,                    &iObj_get_topItemID                     },
		{   cgc_value,                      5,        &iObj_set_value,                        &iObj_get_value                         },
		{   cgc_visible,                    7,        &iObj_set_visible,                      &iObj_get_visible                       },
		{   cgc_whatsThisHelpID,            15,       &iObj_set_whatsThisHelpID,              &iObj_get_whatsThisHelpID               },
		{   cgc_width,                      5,        &iObj_set_width,                        &iObj_get_width                         },
		{   NULL,                           0,        0,                                      0                                       }
	};

	SPropertyMap gcProps_form[] = 
	{
		// Translation for VJr provided by Hernan Cano Martinez
		{   cgc_activeControl,              13,       &iObj_set_activeControl,                &iObj_get_activeControl                 },
		{   cgc_activeForm,                 10,       &iObj_set_activeForm,                   &iObj_get_activeForm                    },
		{   cgc_allowOutput,                11,       &iObj_set_allowOutput,                  &iObj_get_allowOutput                   },
		{   cgc_alwaysOnTop,                11,       &iObj_set_alwaysOnTop,                  &iObj_get_alwaysOnTop                   },
		{   cgc_alwaysOnBottom,             14,       &iObj_set_alwaysOnBottom,               &iObj_get_alwaysOnBottom                },
		{   cgc_bindControls,               12,       &iObj_set_bindControls,                 &iObj_get_bindControls                  },
		{   cgc_bufferMode,                 10,       &iObj_set_bufferMode,                   &iObj_get_bufferMode                    },
		{   cgc_controlBox,                 10,       &iObj_set_controlBox,                   &iObj_get_controlBox                    },
		{   cgc_closable,                   8,        &iObj_set_closable,                     &iObj_get_closable                      },
		{   cgc_continuousScroll,           16,       &iObj_set_continuousScroll,             &iObj_get_continuousScroll              },
		{   cgc_dataSession,                11,       &iObj_set_dataSession,                  &iObj_get_dataSession                   },
		{   cgc_dataSessionID,              13,       &iObj_set_dataSessionID,                &iObj_get_dataSessionID                 },
		{   cgc_dataEnvironment,            15,       &iObj_set_dataEnvironment,              &iObj_get_dataEnvironment               },
		{   cgc_dEClass,                    7,        &iObj_set_dEClass,                      &iObj_get_dEClass                       },
		{   cgc_dEClassLibrary,             14,       &iObj_set_dEClassLibrary,               &iObj_get_dEClassLibrary                },
		{   cgc_defOLELCID,                 10,       &iObj_set_defOLELCID,                   &iObj_get_defOLELCID                    },
		{   cgc_desktop,                    7,        &iObj_set_desktop,                      &iObj_get_desktop                       },
		{   cgc_macDesktop,                 10,       &iObj_set_macDesktop,                   &iObj_get_macDesktop                    },
		{   cgc_dockPosition,               12,       &iObj_set_dockPosition,                 &iObj_get_dockPosition                  },
		{   cgc_dockable,                   8,        &iObj_set_dockable,                     &iObj_get_dockable                      },
		{   cgc_docked,                     6,        &iObj_set_docked,                       &iObj_get_docked                        },
		{   cgc_mDIForm,                    7,        &iObj_set_mDIForm,                      &iObj_get_mDIForm                       },
		{   cgc_doCreate,                   8,        &iObj_set_doCreate,                     &iObj_get_doCreate                      },
		{   cgc_fillColor,                  9,        &iObj_set_fillColor,                    &iObj_get_fillColor                     },
		{   cgc_fillStyle,                  9,        &iObj_set_fillStyle,                    &iObj_get_fillStyle                     },
		{   cgc_hScrollSmallChange,         18,       &iObj_set_hScrollSmallChange,           &iObj_get_hScrollSmallChange            },
		{   cgc_vScrollSmallChange,         18,       &iObj_set_vScrollSmallChange,           &iObj_get_vScrollSmallChange            },
		{   cgc_lockScreen,                 10,       &iObj_set_lockScreen,                   &iObj_get_lockScreen                    },
		{   cgc_maxButton,                  9,        &iObj_set_maxButton,                    &iObj_get_maxButton                     },
		{   cgc_minButton,                  9,        &iObj_set_minButton,                    &iObj_get_minButton                     },
		{   cgc_movable,                    7,        &iObj_set_movable,                      &iObj_get_movable                       },
		{   cgc_maxHeight,                  9,        &iObj_set_maxHeight,                    &iObj_get_maxHeight                     },
		{   cgc_maxWidth,                   8,        &iObj_set_maxWidth,                     &iObj_get_maxWidth                      },
		{   cgc_maxTop,                     6,        &iObj_set_maxTop,                       &iObj_get_maxTop                        },
		{   cgc_maxLeft,                    7,        &iObj_set_maxLeft,                      &iObj_get_maxLeft                       },
		{   cgc_minHeight,                  9,        &iObj_set_minHeight,                    &iObj_get_minHeight                     },
		{   cgc_minWidth,                   8,        &iObj_set_minWidth,                     &iObj_get_minWidth                      },
		{   cgc_scaleMode,                  9,        &iObj_set_scaleMode,                    &iObj_get_scaleMode                     },
		{   cgc_showTips,                   8,        &iObj_set_showTips,                     &iObj_get_showTips                      },
		{   cgc_showWindow,                 10,       &iObj_set_showWindow,                   &iObj_get_showWindow                    },
		{   cgc_showInTaskbar,              13,       &iObj_set_showInTaskbar,                &iObj_get_showInTaskbar                 },
		{   cgc_sizeBox,                    7,        &iObj_set_sizeBox,                      &iObj_get_sizeBox                       },
		{   cgc_windowType,                 10,       &iObj_set_windowType,                   &iObj_get_windowType                    },
		{   cgc_windowState,                11,       &iObj_set_windowState,                  &iObj_get_windowState                   },
		{   cgc_autoCenter,                 10,       &iObj_set_autoCenter,                   &iObj_get_autoCenter                    },
		{   cgc_baseClass,                  9,        &iObj_set_baseClass,                    &iObj_get_baseClass                     },
		{   cgc_class,                      5,        &iObj_set_class,                        &iObj_get_class                         },
		{   cgc_classLibrary,               12,       &iObj_set_classLibrary,                 &iObj_get_classLibrary                  },
		{   cgc_controls,                   8,        &iObj_set_controls,                     &iObj_get_controls                      },
		{   cgc_controlCount,               12,       &iObj_set_controlCount,                 &iObj_get_controlCount                  },
		{   cgc_objects,                    7,        &iObj_set_objects,                      &iObj_get_objects                       },
		{   cgc_borderStyle,                11,       &iObj_set_borderStyle,                  &iObj_get_borderStyle                   },
		{   cgc_clipControls,               12,       &iObj_set_clipControls,                 &iObj_get_clipControls                  },
		{   cgc_caption,                    7,        &iObj_set_caption,                      &iObj_get_caption                       },
		{   cgc_halfHeightCaption,          17,       &iObj_set_halfHeightCaption,            &iObj_get_halfHeightCaption             },
		{   cgc_colorSource,                11,       &iObj_set_colorSource,                  &iObj_get_colorSource                   },
		{   cgc_foreColor,                  9,        &iObj_set_foreColor,                    &iObj_get_foreColor                     },
		{   cgc_backColor,                  9,        &iObj_set_backColor,                    &iObj_get_backColor                     },
		{   cgc_currentX,                   8,        &iObj_set_currentX,                     &iObj_get_currentX                      },
		{   cgc_currentY,                   8,        &iObj_set_currentY,                     &iObj_get_currentY                      },
		{   cgc_comment,                    7,        &iObj_set_comment,                      &iObj_get_comment                       },
		{   cgc_drawMode,                   8,        &iObj_set_drawMode,                     &iObj_get_drawMode                      },
		{   cgc_drawStyle,                  9,        &iObj_set_drawStyle,                    &iObj_get_drawStyle                     },
		{   cgc_drawWidth,                  9,        &iObj_set_drawWidth,                    &iObj_get_drawWidth                     },
		{   cgc_enabled,                    7,        &iObj_set_enabled,                      &iObj_get_enabled                       },
		{   cgc_fontBold,                   8,        &iObj_set_fontBold,                     &iObj_get_fontBold                      },
		{   cgc_fontCharSet,                11,       &iObj_set_fontCharSet,                  &iObj_get_fontCharSet                   },
		{   cgc_fontCondense,               12,       &iObj_set_fontCondense,                 &iObj_get_fontCondense                  },
		{   cgc_fontExtend,                 10,       &iObj_set_fontExtend,                   &iObj_get_fontExtend                    },
		{   cgc_fontItalic,                 10,       &iObj_set_fontItalic,                   &iObj_get_fontItalic                    },
		{   cgc_fontName,                   8,        &iObj_set_fontName,                     &iObj_get_fontName                      },
		{   cgc_fontOutline,                11,       &iObj_set_fontOutline,                  &iObj_get_fontOutline                   },
		{   cgc_fontShadow,                 10,       &iObj_set_fontShadow,                   &iObj_get_fontShadow                    },
		{   cgc_fontSize,                   8,        &iObj_set_fontSize,                     &iObj_get_fontSize                      },
		{   cgc_fontStrikeThru,             14,       &iObj_set_fontStrikeThru,               &iObj_get_fontStrikeThru                },
		{   cgc_fontUnderline,              13,       &iObj_set_fontUnderline,                &iObj_get_fontUnderline                 },
		{   cgc_height,                     6,        &iObj_set_height,                       &iObj_get_height                        },
		{   cgc_helpContextID,              13,       &iObj_set_helpContextID,                &iObj_get_helpContextID                 },
		{   cgc_hWnd,                       4,        &iObj_set_hWnd,                         &iObj_get_hWnd                          },
		{   cgc_keyPreview,                 10,       &iObj_set_keyPreview,                   &iObj_get_keyPreview                    },
		{   cgc_left,                       4,        &iObj_set_left,                         &iObj_get_left                          },
		{   cgc_lockScreen,                 10,       &iObj_set_lockScreen,                   &iObj_get_lockScreen                    },
		{   cgc_mouseIcon,                  9,        &iObj_set_mouseIcon,                    &iObj_get_mouseIcon                     },
		{   cgc_mousePointer,               12,       &iObj_set_mousePointer,                 &iObj_get_mousePointer                  },
		{   cgc_name,                       4,        &iObj_set_name,                         &iObj_get_name                          },
		{   cgc_oLEDragMode,                11,       &iObj_set_oLEDragMode,                  &iObj_get_oLEDragMode                   },
		{   cgc_oLEDragPicture,             14,       &iObj_set_oLEDragPicture,               &iObj_get_oLEDragPicture                },
		{   cgc_oLEDropEffects,             14,       &iObj_set_oLEDropEffects,               &iObj_get_oLEDropEffects                },
		{   cgc_oLEDropHasData,             14,       &iObj_set_oLEDropHasData,               &iObj_get_oLEDropHasData                },
		{   cgc_oLEDropMode,                11,       &iObj_set_oLEDropMode,                  &iObj_get_oLEDropMode                   },
		{   cgc_parent,                     6,        &iObj_set_parent,                       &iObj_get_parent                        },
		{   cgc_parentClass,                11,       &iObj_set_parentClass,                  &iObj_get_parentClass                   },
		{   cgc_icon,                       4,        &iObj_set_icon,                         &iObj_get_icon                          },
		{   cgc_picture,                    7,        &iObj_set_picture,                      &iObj_get_picture                       },
		{   cgc_releaseType,                11,       &iObj_set_releaseType,                  &iObj_get_releaseType                   },
		{   cgc_rightToLeft,                11,       &iObj_set_rightToLeft,                  &iObj_get_rightToLeft                   },
		{   cgc_scrollBars,                 10,       &iObj_set_scrollBars,                   &iObj_get_scrollBars                    },
		{   cgc_tabIndex,                   8,        &iObj_set_tabIndex,                     &iObj_get_tabIndex                      },
		{   cgc_tabStop,                    7,        &iObj_set_tabStop,                      &iObj_get_tabStop                       },
		{   cgc_tag,                        3,        &iObj_set_tag,                          &iObj_get_tag                           },
		{   cgc_themes,                     6,        &iObj_set_themes,                       &iObj_get_themes                        },
		{   cgc_titleBar,                   8,        &iObj_set_titleBar,                     &iObj_get_titleBar                      },
		{   cgc_top,                        3,        &iObj_set_top,                          &iObj_get_top                           },
		{   cgc_visible,                    7,        &iObj_set_visible,                      &iObj_get_visible                       },
		{   cgc_viewPortHeight,             14,       &iObj_set_viewPortHeight,               &iObj_get_viewPortHeight                },
		{   cgc_viewPortLeft,               12,       &iObj_set_viewPortLeft,                 &iObj_get_viewPortLeft                  },
		{   cgc_viewPortTop,                11,       &iObj_set_viewPortTop,                  &iObj_get_viewPortTop                   },
		{   cgc_viewPortWidth,              13,       &iObj_set_viewPortWidth,                &iObj_get_viewPortWidth                 },
		{   cgc_whatsThisHelpID,            15,       &iObj_set_whatsThisHelpID,              &iObj_get_whatsThisHelpID               },
		{   cgc_whatsThisHelp,              13,       &iObj_set_whatsThisHelp,                &iObj_get_whatsThisHelp                 },
		{   cgc_whatsThisButton,            15,       &iObj_set_whatsThisButton,              &iObj_get_whatsThisButton               },
		{   cgc_width,                      5,        &iObj_set_width,                        &iObj_get_width                         },
		{   cgc_zoomBox,                    7,        &iObj_set_zoomBox,                      &iObj_get_zoomBox                       },
		{   NULL,                           0,        0,                                      0                                       }
	};

	SPropertyMap gcProps_formset[] = 
	{
		// Translation for VJr provided by Hernan Cano Martinez
		{   cgc_activeForm,                 10,       &iObj_set_activeForm,                   &iObj_get_activeForm                    },
		{   cgc_autoRelease,                11,       &iObj_set_autoRelease,                  &iObj_get_autoRelease                   },
		{   cgc_bufferMode,                 10,       &iObj_set_bufferMode,                   &iObj_get_bufferMode                    },
		{   cgc_dataSession,                11,       &iObj_set_dataSession,                  &iObj_get_dataSession                   },
		{   cgc_dataSessionID,              13,       &iObj_set_dataSessionID,                &iObj_get_dataSessionID                 },
		{   cgc_dataEnvironment,            15,       &iObj_set_dataEnvironment,              &iObj_get_dataEnvironment               },
		{   cgc_application,                11,       &iObj_set_application,                  &iObj_get_application                   },
		{   cgc_baseClass,                  9,        &iObj_set_baseClass,                    &iObj_get_baseClass                     },
		{   cgc_class,                      5,        &iObj_set_class,                        &iObj_get_class                         },
		{   cgc_classLibrary,               12,       &iObj_set_classLibrary,                 &iObj_get_classLibrary                  },
		{   cgc_forms,                      5,        &iObj_set_forms,                        &iObj_get_forms                         },
		{   cgc_formCount,                  9,        &iObj_set_formCount,                    &iObj_get_formCount                     },
		{   cgc_objects,                    7,        &iObj_set_objects,                      &iObj_get_objects                       },
		{   cgc_comment,                    7,        &iObj_set_comment,                      &iObj_get_comment                       },
		{   cgc_name,                       4,        &iObj_set_name,                         &iObj_get_name                          },
		{   cgc_parent,                     6,        &iObj_set_parent,                       &iObj_get_parent                        },
		{   cgc_parentClass,                11,       &iObj_set_parentClass,                  &iObj_get_parentClass                   },
		{   cgc_readBackColor,              13,       &iObj_set_readBackColor,                &iObj_get_readBackColor                 },
		{   cgc_readCycle,                  9,        &iObj_set_readCycle,                    &iObj_get_readCycle                     },
		{   cgc_readForeColor,              13,       &iObj_set_readForeColor,                &iObj_get_readForeColor                 },
		{   cgc_readLock,                   8,        &iObj_set_readLock,                     &iObj_get_readLock                      },
		{   cgc_readMouse,                  9,        &iObj_set_readMouse,                    &iObj_get_readMouse                     },
		{   cgc_readSave,                   8,        &iObj_set_readSave,                     &iObj_get_readSave                      },
		{   cgc_readTimeOut,                11,       &iObj_set_readTimeOut,                  &iObj_get_readTimeOut                   },
		{   cgc_tag,                        3,        &iObj_set_tag,                          &iObj_get_tag                           },
		{   cgc_visible,                    7,        &iObj_set_visible,                      &iObj_get_visible                       },
		{   cgc_windowList,                 10,       &iObj_set_windowList,                   &iObj_get_windowList                    },
		{   cgc_windowType,                 10,       &iObj_set_windowType,                   &iObj_get_windowType                    },
		{   NULL,                           0,        0,                                      0                                       }
	};

	SPropertyMap gcProps_toolbar[] = 
	{
		// Translation for VJr provided by Hernan Cano Martinez
		{   cgc_activeControl,              13,       &iObj_set_activeControl,                &iObj_get_activeControl                 },
		{   cgc_controlBox,                 10,       &iObj_set_controlBox,                   &iObj_get_controlBox                    },
		{   cgc_dataSession,                11,       &iObj_set_dataSession,                  &iObj_get_dataSession                   },
		{   cgc_dataSessionID,              13,       &iObj_set_dataSessionID,                &iObj_get_dataSessionID                 },
		{   cgc_dockPosition,               12,       &iObj_set_dockPosition,                 &iObj_get_dockPosition                  },
		{   cgc_docked,                     6,        &iObj_set_docked,                       &iObj_get_docked                        },
		{   cgc_movable,                    7,        &iObj_set_movable,                      &iObj_get_movable                       },
		{   cgc_scaleMode,                  9,        &iObj_set_scaleMode,                    &iObj_get_scaleMode                     },
		{   cgc_showTips,                   8,        &iObj_set_showTips,                     &iObj_get_showTips                      },
		{   cgc_showWindow,                 10,       &iObj_set_showWindow,                   &iObj_get_showWindow                    },
		{   cgc_application,                11,       &iObj_set_application,                  &iObj_get_application                   },
		{   cgc_baseClass,                  9,        &iObj_set_baseClass,                    &iObj_get_baseClass                     },
		{   cgc_class,                      5,        &iObj_set_class,                        &iObj_get_class                         },
		{   cgc_classLibrary,               12,       &iObj_set_classLibrary,                 &iObj_get_classLibrary                  },
		{   cgc_controls,                   8,        &iObj_set_controls,                     &iObj_get_controls                      },
		{   cgc_controlCount,               12,       &iObj_set_controlCount,                 &iObj_get_controlCount                  },
		{   cgc_objects,                    7,        &iObj_set_objects,                      &iObj_get_objects                       },
		{   cgc_caption,                    7,        &iObj_set_caption,                      &iObj_get_caption                       },
		{   cgc_colorSource,                11,       &iObj_set_colorSource,                  &iObj_get_colorSource                   },
		{   cgc_foreColor,                  9,        &iObj_set_foreColor,                    &iObj_get_foreColor                     },
		{   cgc_backColor,                  9,        &iObj_set_backColor,                    &iObj_get_backColor                     },
		{   cgc_comment,                    7,        &iObj_set_comment,                      &iObj_get_comment                       },
		{   cgc_enabled,                    7,        &iObj_set_enabled,                      &iObj_get_enabled                       },
		{   cgc_height,                     6,        &iObj_set_height,                       &iObj_get_height                        },
		{   cgc_helpContextID,              13,       &iObj_set_helpContextID,                &iObj_get_helpContextID                 },
		{   cgc_hWnd,                       4,        &iObj_set_hWnd,                         &iObj_get_hWnd                          },
		{   cgc_keyPreview,                 10,       &iObj_set_keyPreview,                   &iObj_get_keyPreview                    },
		{   cgc_left,                       4,        &iObj_set_left,                         &iObj_get_left                          },
		{   cgc_lockScreen,                 10,       &iObj_set_lockScreen,                   &iObj_get_lockScreen                    },
		{   cgc_mouseIcon,                  9,        &iObj_set_mouseIcon,                    &iObj_get_mouseIcon                     },
		{   cgc_mousePointer,               12,       &iObj_set_mousePointer,                 &iObj_get_mousePointer                  },
		{   cgc_name,                       4,        &iObj_set_name,                         &iObj_get_name                          },
		{   cgc_oLEDragMode,                11,       &iObj_set_oLEDragMode,                  &iObj_get_oLEDragMode                   },
		{   cgc_oLEDragPicture,             14,       &iObj_set_oLEDragPicture,               &iObj_get_oLEDragPicture                },
		{   cgc_oLEDropEffects,             14,       &iObj_set_oLEDropEffects,               &iObj_get_oLEDropEffects                },
		{   cgc_oLEDropHasData,             14,       &iObj_set_oLEDropHasData,               &iObj_get_oLEDropHasData                },
		{   cgc_oLEDropMode,                11,       &iObj_set_oLEDropMode,                  &iObj_get_oLEDropMode                   },
		{   cgc_parent,                     6,        &iObj_set_parent,                       &iObj_get_parent                        },
		{   cgc_parentClass,                11,       &iObj_set_parentClass,                  &iObj_get_parentClass                   },
		{   cgc_sizable,                    7,        &iObj_set_sizable,                      &iObj_get_sizable                       },
		{   cgc_tag,                        3,        &iObj_set_tag,                          &iObj_get_tag                           },
		{   cgc_themes,                     6,        &iObj_set_themes,                       &iObj_get_themes                        },
		{   cgc_top,                        3,        &iObj_set_top,                          &iObj_get_top                           },
		{   cgc_visible,                    7,        &iObj_set_visible,                      &iObj_get_visible                       },
		{   cgc_whatsThisHelpID,            15,       &iObj_set_whatsThisHelpID,              &iObj_get_whatsThisHelpID               },
		{   cgc_width,                      5,        &iObj_set_width,                        &iObj_get_width                         },
		{   NULL,                           0,        0,                                      0                                       }
	};

	SPropertyMap gcProps_separator[] = 
	{
		// Translation for VJr provided by Hernan Cano Martinez
		{   cgc_application,                11,       &iObj_set_application,                  &iObj_get_application                   },
		{   cgc_baseClass,                  9,        &iObj_set_baseClass,                    &iObj_get_baseClass                     },
		{   cgc_class,                      5,        &iObj_set_class,                        &iObj_get_class                         },
		{   cgc_classLibrary,               12,       &iObj_set_classLibrary,                 &iObj_get_classLibrary                  },
		{   cgc_comment,                    7,        &iObj_set_comment,                      &iObj_get_comment                       },
		{   cgc_enabled,                    7,        &iObj_set_enabled,                      &iObj_get_enabled                       },
		{   cgc_name,                       4,        &iObj_set_name,                         &iObj_get_name                          },
		{   cgc_parent,                     6,        &iObj_set_parent,                       &iObj_get_parent                        },
		{   cgc_parentClass,                11,       &iObj_set_parentClass,                  &iObj_get_parentClass                   },
		{   cgc_style,                      5,        &iObj_set_style,                        &iObj_get_style                         },
		{   cgc_tag,                        3,        &iObj_set_tag,                          &iObj_get_tag                           },
		{   cgc_visible,                    7,        &iObj_set_visible,                      &iObj_get_visible                       },
		{   NULL,                           0,        0,                                      0                                       }
	};

	SPropertyMap gcProps_line[] = 
	{
		// Translation for VJr provided by Hernan Cano Martinez
		{   cgc_anchor,                     6,        &iObj_set_anchor,                       &iObj_get_anchor                        },
		{   cgc_application,                11,       &iObj_set_application,                  &iObj_get_application                   },
		{   cgc_baseClass,                  9,        &iObj_set_baseClass,                    &iObj_get_baseClass                     },
		{   cgc_class,                      5,        &iObj_set_class,                        &iObj_get_class                         },
		{   cgc_classLibrary,               12,       &iObj_set_classLibrary,                 &iObj_get_classLibrary                  },
		{   cgc_borderColor,                11,       &iObj_set_borderColor,                  &iObj_get_borderColor                   },
		{   cgc_borderWidth,                11,       &iObj_set_borderWidth,                  &iObj_get_borderWidth                   },
		{   cgc_borderStyle,                11,       &iObj_set_borderStyle,                  &iObj_get_borderStyle                   },
		{   cgc_colorSource,                11,       &iObj_set_colorSource,                  &iObj_get_colorSource                   },
		{   cgc_comment,                    7,        &iObj_set_comment,                      &iObj_get_comment                       },
		{   cgc_dragIcon,                   8,        &iObj_set_dragIcon,                     &iObj_get_dragIcon                      },
		{   cgc_dragMode,                   8,        &iObj_set_dragMode,                     &iObj_get_dragMode                      },
		{   cgc_drawMode,                   8,        &iObj_set_drawMode,                     &iObj_get_drawMode                      },
		{   cgc_enabled,                    7,        &iObj_set_enabled,                      &iObj_get_enabled                       },
		{   cgc_height,                     6,        &iObj_set_height,                       &iObj_get_height                        },
		{   cgc_helpContextID,              13,       &iObj_set_helpContextID,                &iObj_get_helpContextID                 },
		{   cgc_left,                       4,        &iObj_set_left,                         &iObj_get_left                          },
		{   cgc_lineSlant,                  9,        &iObj_set_lineSlant,                    &iObj_get_lineSlant                     },
		{   cgc_mousePointer,               12,       &iObj_set_mousePointer,                 &iObj_get_mousePointer                  },
		{   cgc_name,                       4,        &iObj_set_name,                         &iObj_get_name                          },
		{   cgc_oLEDragMode,                11,       &iObj_set_oLEDragMode,                  &iObj_get_oLEDragMode                   },
		{   cgc_oLEDragPicture,             14,       &iObj_set_oLEDragPicture,               &iObj_get_oLEDragPicture                },
		{   cgc_oLEDropEffects,             14,       &iObj_set_oLEDropEffects,               &iObj_get_oLEDropEffects                },
		{   cgc_oLEDropHasData,             14,       &iObj_set_oLEDropHasData,               &iObj_get_oLEDropHasData                },
		{   cgc_oLEDropMode,                11,       &iObj_set_oLEDropMode,                  &iObj_get_oLEDropMode                   },
		{   cgc_parent,                     6,        &iObj_set_parent,                       &iObj_get_parent                        },
		{   cgc_parentClass,                11,       &iObj_set_parentClass,                  &iObj_get_parentClass                   },
		{   cgc_polyPoints,                 10,       &iObj_set_polyPoints,                   &iObj_get_polyPoints                    },
		{   cgc_rotation,                   8,        &iObj_set_rotation,                     &iObj_get_rotation                      },
		{   cgc_statusBarText,              13,       &iObj_set_statusBarText,                &iObj_get_statusBarText                 },
		{   cgc_tag,                        3,        &iObj_set_tag,                          &iObj_get_tag                           },
		{   cgc_toolTipText,                11,       &iObj_set_toolTipText,                  &iObj_get_toolTipText                   },
		{   cgc_top,                        3,        &iObj_set_top,                          &iObj_get_top                           },
		{   cgc_visible,                    7,        &iObj_set_visible,                      &iObj_get_visible                       },
		{   cgc_whatsThisHelpID,            15,       &iObj_set_whatsThisHelpID,              &iObj_get_whatsThisHelpID               },
		{   cgc_width,                      5,        &iObj_set_width,                        &iObj_get_width                         },
		{   NULL,                           0,        0,                                      0                                       }
	};

	SPropertyMap gcProps_shape[] = 
	{
		// Translation for VJr provided by Hernan Cano Martinez
		{   cgc_fillColor,                  9,        &iObj_set_fillColor,                    &iObj_get_fillColor                     },
		{   cgc_fillStyle,                  9,        &iObj_set_fillStyle,                    &iObj_get_fillStyle                     },
		{   cgc_anchor,                     6,        &iObj_set_anchor,                       &iObj_get_anchor                        },
		{   cgc_application,                11,       &iObj_set_application,                  &iObj_get_application                   },
		{   cgc_backStyle,                  9,        &iObj_set_backStyle,                    &iObj_get_backStyle                     },
		{   cgc_baseClass,                  9,        &iObj_set_baseClass,                    &iObj_get_baseClass                     },
		{   cgc_class,                      5,        &iObj_set_class,                        &iObj_get_class                         },
		{   cgc_classLibrary,               12,       &iObj_set_classLibrary,                 &iObj_get_classLibrary                  },
		{   cgc_borderColor,                11,       &iObj_set_borderColor,                  &iObj_get_borderColor                   },
		{   cgc_borderWidth,                11,       &iObj_set_borderWidth,                  &iObj_get_borderWidth                   },
		{   cgc_borderStyle,                11,       &iObj_set_borderStyle,                  &iObj_get_borderStyle                   },
		{   cgc_curvature,                  9,        &iObj_set_curvature,                    &iObj_get_curvature                     },
		{   cgc_colorScheme,                11,       &iObj_set_colorScheme,                  &iObj_get_colorScheme                   },
		{   cgc_colorSource,                11,       &iObj_set_colorSource,                  &iObj_get_colorSource                   },
		{   cgc_backColor,                  9,        &iObj_set_backColor,                    &iObj_get_backColor                     },
		{   cgc_comment,                    7,        &iObj_set_comment,                      &iObj_get_comment                       },
		{   cgc_dragIcon,                   8,        &iObj_set_dragIcon,                     &iObj_get_dragIcon                      },
		{   cgc_dragMode,                   8,        &iObj_set_dragMode,                     &iObj_get_dragMode                      },
		{   cgc_drawMode,                   8,        &iObj_set_drawMode,                     &iObj_get_drawMode                      },
		{   cgc_enabled,                    7,        &iObj_set_enabled,                      &iObj_get_enabled                       },
		{   cgc_height,                     6,        &iObj_set_height,                       &iObj_get_height                        },
		{   cgc_helpContextID,              13,       &iObj_set_helpContextID,                &iObj_get_helpContextID                 },
		{   cgc_left,                       4,        &iObj_set_left,                         &iObj_get_left                          },
		{   cgc_mouseIcon,                  9,        &iObj_set_mouseIcon,                    &iObj_get_mouseIcon                     },
		{   cgc_mousePointer,               12,       &iObj_set_mousePointer,                 &iObj_get_mousePointer                  },
		{   cgc_name,                       4,        &iObj_set_name,                         &iObj_get_name                          },
		{   cgc_oLEDragMode,                11,       &iObj_set_oLEDragMode,                  &iObj_get_oLEDragMode                   },
		{   cgc_oLEDragPicture,             14,       &iObj_set_oLEDragPicture,               &iObj_get_oLEDragPicture                },
		{   cgc_oLEDropEffects,             14,       &iObj_set_oLEDropEffects,               &iObj_get_oLEDropEffects                },
		{   cgc_oLEDropHasData,             14,       &iObj_set_oLEDropHasData,               &iObj_get_oLEDropHasData                },
		{   cgc_oLEDropMode,                11,       &iObj_set_oLEDropMode,                  &iObj_get_oLEDropMode                   },
		{   cgc_parent,                     6,        &iObj_set_parent,                       &iObj_get_parent                        },
		{   cgc_parentClass,                11,       &iObj_set_parentClass,                  &iObj_get_parentClass                   },
		{   cgc_polyPoints,                 10,       &iObj_set_polyPoints,                   &iObj_get_polyPoints                    },
		{   cgc_rotation,                   8,        &iObj_set_rotation,                     &iObj_get_rotation                      },
		{   cgc_specialEffect,              13,       &iObj_set_specialEffect,                &iObj_get_specialEffect                 },
		{   cgc_tag,                        3,        &iObj_set_tag,                          &iObj_get_tag                           },
		{   cgc_toolTipText,                11,       &iObj_set_toolTipText,                  &iObj_get_toolTipText                   },
		{   cgc_top,                        3,        &iObj_set_top,                          &iObj_get_top                           },
		{   cgc_visible,                    7,        &iObj_set_visible,                      &iObj_get_visible                       },
		{   cgc_whatsThisHelpID,            15,       &iObj_set_whatsThisHelpID,              &iObj_get_whatsThisHelpID               },
		{   cgc_width,                      5,        &iObj_set_width,                        &iObj_get_width                         },
		{   NULL,                           0,        0,                                      0                                       }
	};

	SPropertyMap gcProps_image[] = 
	{
		// Translation for VJr provided by Hernan Cano Martinez
		{   cgc_anchor,                     6,        &iObj_set_anchor,                       &iObj_get_anchor                        },
		{   cgc_application,                11,       &iObj_set_application,                  &iObj_get_application                   },
		{   cgc_backStyle,                  9,        &iObj_set_backStyle,                    &iObj_get_backStyle                     },
		{   cgc_baseClass,                  9,        &iObj_set_baseClass,                    &iObj_get_baseClass                     },
		{   cgc_class,                      5,        &iObj_set_class,                        &iObj_get_class                         },
		{   cgc_classLibrary,               12,       &iObj_set_classLibrary,                 &iObj_get_classLibrary                  },
		{   cgc_borderColor,                11,       &iObj_set_borderColor,                  &iObj_get_borderColor                   },
		{   cgc_borderStyle,                11,       &iObj_set_borderStyle,                  &iObj_get_borderStyle                   },
		{   cgc_colorSource,                11,       &iObj_set_colorSource,                  &iObj_get_colorSource                   },
		{   cgc_comment,                    7,        &iObj_set_comment,                      &iObj_get_comment                       },
		{   cgc_dragIcon,                   8,        &iObj_set_dragIcon,                     &iObj_get_dragIcon                      },
		{   cgc_dragMode,                   8,        &iObj_set_dragMode,                     &iObj_get_dragMode                      },
		{   cgc_enabled,                    7,        &iObj_set_enabled,                      &iObj_get_enabled                       },
		{   cgc_height,                     6,        &iObj_set_height,                       &iObj_get_height                        },
		{   cgc_helpContextID,              13,       &iObj_set_helpContextID,                &iObj_get_helpContextID                 },
		{   cgc_left,                       4,        &iObj_set_left,                         &iObj_get_left                          },
		{   cgc_mousePointer,               12,       &iObj_set_mousePointer,                 &iObj_get_mousePointer                  },
		{   cgc_name,                       4,        &iObj_set_name,                         &iObj_get_name                          },
		{   cgc_oLEDragMode,                11,       &iObj_set_oLEDragMode,                  &iObj_get_oLEDragMode                   },
		{   cgc_oLEDragPicture,             14,       &iObj_set_oLEDragPicture,               &iObj_get_oLEDragPicture                },
		{   cgc_oLEDropEffects,             14,       &iObj_set_oLEDropEffects,               &iObj_get_oLEDropEffects                },
		{   cgc_oLEDropHasData,             14,       &iObj_set_oLEDropHasData,               &iObj_get_oLEDropHasData                },
		{   cgc_oLEDropMode,                11,       &iObj_set_oLEDropMode,                  &iObj_get_oLEDropMode                   },
		{   cgc_parent,                     6,        &iObj_set_parent,                       &iObj_get_parent                        },
		{   cgc_parentClass,                11,       &iObj_set_parentClass,                  &iObj_get_parentClass                   },
		{   cgc_picture,                    7,        &iObj_set_picture,                      &iObj_get_picture                       },
		{   cgc_pictureVal,                 10,       &iObj_set_pictureVal,                   &iObj_get_pictureVal                    },
		{   cgc_rotateFlip,                 10,       &iObj_set_rotateFlip,                   &iObj_get_rotateFlip                    },
		{   cgc_stretch,                    7,        &iObj_set_stretch,                      &iObj_get_stretch                       },
		{   cgc_statusBarText,              13,       &iObj_set_statusBarText,                &iObj_get_statusBarText                 },
		{   cgc_tag,                        3,        &iObj_set_tag,                          &iObj_get_tag                           },
		{   cgc_themes,                     6,        &iObj_set_themes,                       &iObj_get_themes                        },
		{   cgc_toolTipText,                11,       &iObj_set_toolTipText,                  &iObj_get_toolTipText                   },
		{   cgc_top,                        3,        &iObj_set_top,                          &iObj_get_top                           },
		{   cgc_visible,                    7,        &iObj_set_visible,                      &iObj_get_visible                       },
		{   cgc_whatsThisHelpID,            15,       &iObj_set_whatsThisHelpID,              &iObj_get_whatsThisHelpID               },
		{   cgc_width,                      5,        &iObj_set_width,                        &iObj_get_width                         },
		{   NULL,                           0,        0,                                      0                                       }
	};

	SPropertyMap gcProps_container[] = 
	{
		// Translation for VJr provided by Hernan Cano Martinez
		{   cgc_activeControl,              13,       &iObj_set_activeControl,                &iObj_get_activeControl                 },
		{   cgc_anchor,                     6,        &iObj_set_anchor,                       &iObj_get_anchor                        },
		{   cgc_application,                11,       &iObj_set_application,                  &iObj_get_application                   },
		{   cgc_backStyle,                  9,        &iObj_set_backStyle,                    &iObj_get_backStyle                     },
		{   cgc_baseClass,                  9,        &iObj_set_baseClass,                    &iObj_get_baseClass                     },
		{   cgc_class,                      5,        &iObj_set_class,                        &iObj_get_class                         },
		{   cgc_classLibrary,               12,       &iObj_set_classLibrary,                 &iObj_get_classLibrary                  },
		{   cgc_controls,                   8,        &iObj_set_controls,                     &iObj_get_controls                      },
		{   cgc_controlCount,               12,       &iObj_set_controlCount,                 &iObj_get_controlCount                  },
		{   cgc_objects,                    7,        &iObj_set_objects,                      &iObj_get_objects                       },
		{   cgc_borderColor,                11,       &iObj_set_borderColor,                  &iObj_get_borderColor                   },
		{   cgc_borderWidth,                11,       &iObj_set_borderWidth,                  &iObj_get_borderWidth                   },
		{   cgc_colorSource,                11,       &iObj_set_colorSource,                  &iObj_get_colorSource                   },
		{   cgc_foreColor,                  9,        &iObj_set_foreColor,                    &iObj_get_foreColor                     },
		{   cgc_backColor,                  9,        &iObj_set_backColor,                    &iObj_get_backColor                     },
		{   cgc_comment,                    7,        &iObj_set_comment,                      &iObj_get_comment                       },
		{   cgc_dragIcon,                   8,        &iObj_set_dragIcon,                     &iObj_get_dragIcon                      },
		{   cgc_dragMode,                   8,        &iObj_set_dragMode,                     &iObj_get_dragMode                      },
		{   cgc_enabled,                    7,        &iObj_set_enabled,                      &iObj_get_enabled                       },
		{   cgc_height,                     6,        &iObj_set_height,                       &iObj_get_height                        },
		{   cgc_helpContextID,              13,       &iObj_set_helpContextID,                &iObj_get_helpContextID                 },
		{   cgc_left,                       4,        &iObj_set_left,                         &iObj_get_left                          },
		{   cgc_mouseIcon,                  9,        &iObj_set_mouseIcon,                    &iObj_get_mouseIcon                     },
		{   cgc_mousePointer,               12,       &iObj_set_mousePointer,                 &iObj_get_mousePointer                  },
		{   cgc_name,                       4,        &iObj_set_name,                         &iObj_get_name                          },
		{   cgc_oLEDragMode,                11,       &iObj_set_oLEDragMode,                  &iObj_get_oLEDragMode                   },
		{   cgc_oLEDragPicture,             14,       &iObj_set_oLEDragPicture,               &iObj_get_oLEDragPicture                },
		{   cgc_oLEDropEffects,             14,       &iObj_set_oLEDropEffects,               &iObj_get_oLEDropEffects                },
		{   cgc_oLEDropHasData,             14,       &iObj_set_oLEDropHasData,               &iObj_get_oLEDropHasData                },
		{   cgc_oLEDropMode,                11,       &iObj_set_oLEDropMode,                  &iObj_get_oLEDropMode                   },
		{   cgc_parent,                     6,        &iObj_set_parent,                       &iObj_get_parent                        },
		{   cgc_parentClass,                11,       &iObj_set_parentClass,                  &iObj_get_parentClass                   },
		{   cgc_picture,                    7,        &iObj_set_picture,                      &iObj_get_picture                       },
		{   cgc_specialEffect,              13,       &iObj_set_specialEffect,                &iObj_get_specialEffect                 },
		{   cgc_statusBarText,              13,       &iObj_set_statusBarText,                &iObj_get_statusBarText                 },
		{   cgc_tabIndex,                   8,        &iObj_set_tabIndex,                     &iObj_get_tabIndex                      },
		{   cgc_tabStop,                    7,        &iObj_set_tabStop,                      &iObj_get_tabStop                       },
		{   cgc_tag,                        3,        &iObj_set_tag,                          &iObj_get_tag                           },
		{   cgc_toolTipText,                11,       &iObj_set_toolTipText,                  &iObj_get_toolTipText                   },
		{   cgc_top,                        3,        &iObj_set_top,                          &iObj_get_top                           },
		{   cgc_visible,                    7,        &iObj_set_visible,                      &iObj_get_visible                       },
		{   cgc_whatsThisHelpID,            15,       &iObj_set_whatsThisHelpID,              &iObj_get_whatsThisHelpID               },
		{   cgc_width,                      5,        &iObj_set_width,                        &iObj_get_width                         },
		{   NULL,                           0,        0,                                      0                                       }
	};

	SPropertyMap gcProps_control[] = 
	{
		// Translation for VJr provided by Hernan Cano Martinez
		{   cgc_activeControl,              13,       &iObj_set_activeControl,                &iObj_get_activeControl                 },
		{   cgc_anchor,                     6,        &iObj_set_anchor,                       &iObj_get_anchor                        },
		{   cgc_application,                11,       &iObj_set_application,                  &iObj_get_application                   },
		{   cgc_backStyle,                  9,        &iObj_set_backStyle,                    &iObj_get_backStyle                     },
		{   cgc_baseClass,                  9,        &iObj_set_baseClass,                    &iObj_get_baseClass                     },
		{   cgc_class,                      5,        &iObj_set_class,                        &iObj_get_class                         },
		{   cgc_classLibrary,               12,       &iObj_set_classLibrary,                 &iObj_get_classLibrary                  },
		{   cgc_controls,                   8,        &iObj_set_controls,                     &iObj_get_controls                      },
		{   cgc_controlCount,               12,       &iObj_set_controlCount,                 &iObj_get_controlCount                  },
		{   cgc_objects,                    7,        &iObj_set_objects,                      &iObj_get_objects                       },
		{   cgc_borderColor,                11,       &iObj_set_borderColor,                  &iObj_get_borderColor                   },
		{   cgc_borderWidth,                11,       &iObj_set_borderWidth,                  &iObj_get_borderWidth                   },
		{   cgc_colorSource,                11,       &iObj_set_colorSource,                  &iObj_get_colorSource                   },
		{   cgc_foreColor,                  9,        &iObj_set_foreColor,                    &iObj_get_foreColor                     },
		{   cgc_backColor,                  9,        &iObj_set_backColor,                    &iObj_get_backColor                     },
		{   cgc_comment,                    7,        &iObj_set_comment,                      &iObj_get_comment                       },
		{   cgc_dragIcon,                   8,        &iObj_set_dragIcon,                     &iObj_get_dragIcon                      },
		{   cgc_dragMode,                   8,        &iObj_set_dragMode,                     &iObj_get_dragMode                      },
		{   cgc_enabled,                    7,        &iObj_set_enabled,                      &iObj_get_enabled                       },
		{   cgc_height,                     6,        &iObj_set_height,                       &iObj_get_height                        },
		{   cgc_helpContextID,              13,       &iObj_set_helpContextID,                &iObj_get_helpContextID                 },
		{   cgc_left,                       4,        &iObj_set_left,                         &iObj_get_left                          },
		{   cgc_mouseIcon,                  9,        &iObj_set_mouseIcon,                    &iObj_get_mouseIcon                     },
		{   cgc_mousePointer,               12,       &iObj_set_mousePointer,                 &iObj_get_mousePointer                  },
		{   cgc_name,                       4,        &iObj_set_name,                         &iObj_get_name                          },
		{   cgc_oLEDragMode,                11,       &iObj_set_oLEDragMode,                  &iObj_get_oLEDragMode                   },
		{   cgc_oLEDragPicture,             14,       &iObj_set_oLEDragPicture,               &iObj_get_oLEDragPicture                },
		{   cgc_oLEDropEffects,             14,       &iObj_set_oLEDropEffects,               &iObj_get_oLEDropEffects                },
		{   cgc_oLEDropHasData,             14,       &iObj_set_oLEDropHasData,               &iObj_get_oLEDropHasData                },
		{   cgc_oLEDropMode,                11,       &iObj_set_oLEDropMode,                  &iObj_get_oLEDropMode                   },
		{   cgc_parent,                     6,        &iObj_set_parent,                       &iObj_get_parent                        },
		{   cgc_parentClass,                11,       &iObj_set_parentClass,                  &iObj_get_parentClass                   },
		{   cgc_picture,                    7,        &iObj_set_picture,                      &iObj_get_picture                       },
		{   cgc_specialEffect,              13,       &iObj_set_specialEffect,                &iObj_get_specialEffect                 },
		{   cgc_statusBarText,              13,       &iObj_set_statusBarText,                &iObj_get_statusBarText                 },
		{   cgc_tabIndex,                   8,        &iObj_set_tabIndex,                     &iObj_get_tabIndex                      },
		{   cgc_tabStop,                    7,        &iObj_set_tabStop,                      &iObj_get_tabStop                       },
		{   cgc_tag,                        3,        &iObj_set_tag,                          &iObj_get_tag                           },
		{   cgc_toolTipText,                11,       &iObj_set_toolTipText,                  &iObj_get_toolTipText                   },
		{   cgc_top,                        3,        &iObj_set_top,                          &iObj_get_top                           },
		{   cgc_visible,                    7,        &iObj_set_visible,                      &iObj_get_visible                       },
		{   cgc_whatsThisHelpID,            15,       &iObj_set_whatsThisHelpID,              &iObj_get_whatsThisHelpID               },
		{   cgc_width,                      5,        &iObj_set_width,                        &iObj_get_width                         },
		{   NULL,                           0,        0,                                      0                                       }
	};

	SPropertyMap gcProps_grid[] = 
	{
		// Translation for VJr provided by Hernan Cano Martinez
		{   cgc_activeColumn,               12,       &iObj_set_activeColumn,                 &iObj_get_activeColumn                  },
		{   cgc_activeRow,                  9,        &iObj_set_activeRow,                    &iObj_get_activeRow                     },
		{   cgc_allowAddNew,                11,       &iObj_set_allowAddNew,                  &iObj_get_allowAddNew                   },
		{   cgc_allowAutoColumnFit,         18,       &iObj_set_allowAutoColumnFit,           &iObj_get_allowAutoColumnFit            },
		{   cgc_allowCellSelection,         18,       &iObj_set_allowCellSelection,           &iObj_get_allowCellSelection            },
		{   cgc_allowHeaderSizing,          17,       &iObj_set_allowHeaderSizing,            &iObj_get_allowHeaderSizing             },
		{   cgc_allowRowSizing,             14,       &iObj_set_allowRowSizing,               &iObj_get_allowRowSizing                },
		{   cgc_gridLineColor,              13,       &iObj_set_gridLineColor,                &iObj_get_gridLineColor                 },
		{   cgc_gridLines,                  9,        &iObj_set_gridLines,                    &iObj_get_gridLines                     },
		{   cgc_gridLineWidth,              13,       &iObj_set_gridLineWidth,                &iObj_get_gridLineWidth                 },
		{   cgc_headerHeight,               12,       &iObj_set_headerHeight,                 &iObj_get_headerHeight                  },
		{   cgc_highLight,                  9,        &iObj_set_highLight,                    &iObj_get_highLight                     },
		{   cgc_highlightBackColor,         18,       &iObj_set_highlightBackColor,           &iObj_get_highlightBackColor            },
		{   cgc_highlightForeColor,         18,       &iObj_set_highlightForeColor,           &iObj_get_highlightForeColor            },
		{   cgc_highlightStyle,             14,       &iObj_set_highlightStyle,               &iObj_get_highlightStyle                },
		{   cgc_highLightRow,               12,       &iObj_set_highLightRow,                 &iObj_get_highLightRow                  },
		{   cgc_highlightRowLineWidth,      21,       &iObj_set_highlightRowLineWidth,        &iObj_get_highlightRowLineWidth         },
		{   cgc_leftColumn,                 10,       &iObj_set_leftColumn,                   &iObj_get_leftColumn                    },
		{   cgc_linkMaster,                 10,       &iObj_set_linkMaster,                   &iObj_get_linkMaster                    },
		{   cgc_childOrder,                 10,       &iObj_set_childOrder,                   &iObj_get_childOrder                    },
		{   cgc_lockColumns,                11,       &iObj_set_lockColumns,                  &iObj_get_lockColumns                   },
		{   cgc_lockColumnsLeft,            15,       &iObj_set_lockColumnsLeft,              &iObj_get_lockColumnsLeft               },
		{   cgc_memberClass,                11,       &iObj_set_memberClass,                  &iObj_get_memberClass                   },
		{   cgc_memberClassLibrary,         18,       &iObj_set_memberClassLibrary,           &iObj_get_memberClassLibrary            },
		{   cgc_optimize,                   8,        &iObj_set_optimize,                     &iObj_get_optimize                      },
		{   cgc_partition,                  9,        &iObj_set_partition,                    &iObj_get_partition                     },
		{   cgc_panelLink,                  9,        &iObj_set_panelLink,                    &iObj_get_panelLink                     },
		{   cgc_panel,                      5,        &iObj_set_panel,                        &iObj_get_panel                         },
		{   cgc_splitBar,                   8,        &iObj_set_splitBar,                     &iObj_get_splitBar                      },
		{   cgc_deleteMark,                 10,       &iObj_set_deleteMark,                   &iObj_get_deleteMark                    },
		{   cgc_recordMark,                 10,       &iObj_set_recordMark,                   &iObj_get_recordMark                    },
		{   cgc_relativeColumn,             14,       &iObj_set_relativeColumn,               &iObj_get_relativeColumn                },
		{   cgc_relativeRow,                11,       &iObj_set_relativeRow,                  &iObj_get_relativeRow                   },
		{   cgc_view,                       4,        &iObj_set_view,                         &iObj_get_view                          },
		{   cgc_anchor,                     6,        &iObj_set_anchor,                       &iObj_get_anchor                        },
		{   cgc_application,                11,       &iObj_set_application,                  &iObj_get_application                   },
		{   cgc_baseClass,                  9,        &iObj_set_baseClass,                    &iObj_get_baseClass                     },
		{   cgc_class,                      5,        &iObj_set_class,                        &iObj_get_class                         },
		{   cgc_classLibrary,               12,       &iObj_set_classLibrary,                 &iObj_get_classLibrary                  },
		{   cgc_columns,                    7,        &iObj_set_columns,                      &iObj_get_columns                       },
		{   cgc_columnCount,                11,       &iObj_set_columnCount,                  &iObj_get_columnCount                   },
		{   cgc_objects,                    7,        &iObj_set_objects,                      &iObj_get_objects                       },
		{   cgc_foreColor,                  9,        &iObj_set_foreColor,                    &iObj_get_foreColor                     },
		{   cgc_backColor,                  9,        &iObj_set_backColor,                    &iObj_get_backColor                     },
		{   cgc_comment,                    7,        &iObj_set_comment,                      &iObj_get_comment                       },
		{   cgc_recordSource,               12,       &iObj_set_recordSource,                 &iObj_get_recordSource                  },
		{   cgc_recordSourceType,           16,       &iObj_set_recordSourceType,             &iObj_get_recordSourceType              },
		{   cgc_dragIcon,                   8,        &iObj_set_dragIcon,                     &iObj_get_dragIcon                      },
		{   cgc_dragMode,                   8,        &iObj_set_dragMode,                     &iObj_get_dragMode                      },
		{   cgc_enabled,                    7,        &iObj_set_enabled,                      &iObj_get_enabled                       },
		{   cgc_fontBold,                   8,        &iObj_set_fontBold,                     &iObj_get_fontBold                      },
		{   cgc_fontCharSet,                11,       &iObj_set_fontCharSet,                  &iObj_get_fontCharSet                   },
		{   cgc_fontCondense,               12,       &iObj_set_fontCondense,                 &iObj_get_fontCondense                  },
		{   cgc_fontExtend,                 10,       &iObj_set_fontExtend,                   &iObj_get_fontExtend                    },
		{   cgc_fontItalic,                 10,       &iObj_set_fontItalic,                   &iObj_get_fontItalic                    },
		{   cgc_fontName,                   8,        &iObj_set_fontName,                     &iObj_get_fontName                      },
		{   cgc_fontOutline,                11,       &iObj_set_fontOutline,                  &iObj_get_fontOutline                   },
		{   cgc_fontShadow,                 10,       &iObj_set_fontShadow,                   &iObj_get_fontShadow                    },
		{   cgc_fontSize,                   8,        &iObj_set_fontSize,                     &iObj_get_fontSize                      },
		{   cgc_fontStrikeThru,             14,       &iObj_set_fontStrikeThru,               &iObj_get_fontStrikeThru                },
		{   cgc_fontUnderline,              13,       &iObj_set_fontUnderline,                &iObj_get_fontUnderline                 },
		{   cgc_headerHeight,               12,       &iObj_set_headerHeight,                 &iObj_get_headerHeight                  },
		{   cgc_height,                     6,        &iObj_set_height,                       &iObj_get_height                        },
		{   cgc_helpContextID,              13,       &iObj_set_helpContextID,                &iObj_get_helpContextID                 },
		{   cgc_left,                       4,        &iObj_set_left,                         &iObj_get_left                          },
		{   cgc_mouseIcon,                  9,        &iObj_set_mouseIcon,                    &iObj_get_mouseIcon                     },
		{   cgc_mousePointer,               12,       &iObj_set_mousePointer,                 &iObj_get_mousePointer                  },
		{   cgc_name,                       4,        &iObj_set_name,                         &iObj_get_name                          },
		{   cgc_oLEDragMode,                11,       &iObj_set_oLEDragMode,                  &iObj_get_oLEDragMode                   },
		{   cgc_oLEDragPicture,             14,       &iObj_set_oLEDragPicture,               &iObj_get_oLEDragPicture                },
		{   cgc_oLEDropEffects,             14,       &iObj_set_oLEDropEffects,               &iObj_get_oLEDropEffects                },
		{   cgc_oLEDropHasData,             14,       &iObj_set_oLEDropHasData,               &iObj_get_oLEDropHasData                },
		{   cgc_oLEDropMode,                11,       &iObj_set_oLEDropMode,                  &iObj_get_oLEDropMode                   },
		{   cgc_parent,                     6,        &iObj_set_parent,                       &iObj_get_parent                        },
		{   cgc_parentClass,                11,       &iObj_set_parentClass,                  &iObj_get_parentClass                   },
		{   cgc_readOnly,                   8,        &iObj_set_readOnly,                     &iObj_get_readOnly                      },
		{   cgc_relationalExpr,             14,       &iObj_set_relationalExpr,               &iObj_get_relationalExpr                },
		{   cgc_rightToLeft,                11,       &iObj_set_rightToLeft,                  &iObj_get_rightToLeft                   },
		{   cgc_rowColChange,               12,       &iObj_set_rowColChange,                 &iObj_get_rowColChange                  },
		{   cgc_rowHeight,                  9,        &iObj_set_rowHeight,                    &iObj_get_rowHeight                     },
		{   cgc_scrollBars,                 10,       &iObj_set_scrollBars,                   &iObj_get_scrollBars                    },
		{   cgc_selectedItemBackColor,      21,       &iObj_set_selectedItemBackColor,        &iObj_get_selectedItemBackColor         },
		{   cgc_selectedItemForeColor,      21,       &iObj_set_selectedItemForeColor,        &iObj_get_selectedItemForeColor         },
		{   cgc_statusBarText,              13,       &iObj_set_statusBarText,                &iObj_get_statusBarText                 },
		{   cgc_tabIndex,                   8,        &iObj_set_tabIndex,                     &iObj_get_tabIndex                      },
		{   cgc_tabStop,                    7,        &iObj_set_tabStop,                      &iObj_get_tabStop                       },
		{   cgc_tag,                        3,        &iObj_set_tag,                          &iObj_get_tag                           },
		{   cgc_themes,                     6,        &iObj_set_themes,                       &iObj_get_themes                        },
		{   cgc_toolTipText,                11,       &iObj_set_toolTipText,                  &iObj_get_toolTipText                   },
		{   cgc_top,                        3,        &iObj_set_top,                          &iObj_get_top                           },
		{   cgc_value,                      5,        &iObj_set_value,                        &iObj_get_value                         },
		{   cgc_visible,                    7,        &iObj_set_visible,                      &iObj_get_visible                       },
		{   cgc_whatsThisHelpID,            15,       &iObj_set_whatsThisHelpID,              &iObj_get_whatsThisHelpID               },
		{   cgc_width,                      5,        &iObj_set_width,                        &iObj_get_width                         },
		{   NULL,                           0,        0,                                      0                                       }
	};

	SPropertyMap gcProps_column[] = 
	{
		// Translation for VJr provided by Hernan Cano Martinez
		{   cgc_currentControl,             14,       &iObj_set_currentControl,               &iObj_get_currentControl                },
		{   cgc_dynamicAlignment,           16,       &iObj_set_dynamicAlignment,             &iObj_get_dynamicAlignment              },
		{   cgc_dynamicBackColor,           16,       &iObj_set_dynamicBackColor,             &iObj_get_dynamicBackColor              },
		{   cgc_dynamicCurrentControl,      21,       &iObj_set_dynamicCurrentControl,        &iObj_get_dynamicCurrentControl         },
		{   cgc_dynamicFontBold,            15,       &iObj_set_dynamicFontBold,              &iObj_get_dynamicFontBold               },
		{   cgc_dynamicFontItalic,          17,       &iObj_set_dynamicFontItalic,            &iObj_get_dynamicFontItalic             },
		{   cgc_dynamicFontName,            15,       &iObj_set_dynamicFontName,              &iObj_get_dynamicFontName               },
		{   cgc_dynamicFontOutline,         18,       &iObj_set_dynamicFontOutline,           &iObj_get_dynamicFontOutline            },
		{   cgc_dynamicFontShadow,          17,       &iObj_set_dynamicFontShadow,            &iObj_get_dynamicFontShadow             },
		{   cgc_dynamicFontSize,            15,       &iObj_set_dynamicFontSize,              &iObj_get_dynamicFontSize               },
		{   cgc_dynamicFontStrikeThru,      21,       &iObj_set_dynamicFontStrikeThru,        &iObj_get_dynamicFontStrikeThru         },
		{   cgc_dynamicFontUnderline,       20,       &iObj_set_dynamicFontUnderline,         &iObj_get_dynamicFontUnderline          },
		{   cgc_dynamicForeColor,           16,       &iObj_set_dynamicForeColor,             &iObj_get_dynamicForeColor              },
		{   cgc_dynamicInputMask,           16,       &iObj_set_dynamicInputMask,             &iObj_get_dynamicInputMask              },
		{   cgc_sparse,                     6,        &iObj_set_sparse,                       &iObj_get_sparse                        },
		{   cgc_columnOrder,                11,       &iObj_set_columnOrder,                  &iObj_get_columnOrder                   },
		{   cgc_headerClass,                11,       &iObj_set_headerClass,                  &iObj_get_headerClass                   },
		{   cgc_headerClassLibrary,         18,       &iObj_set_headerClassLibrary,           &iObj_get_headerClassLibrary            },
		{   cgc_movable,                    7,        &iObj_set_movable,                      &iObj_get_movable                       },
		{   cgc_alignment,                  9,        &iObj_set_alignment,                    &iObj_get_alignment                     },
		{   cgc_application,                11,       &iObj_set_application,                  &iObj_get_application                   },
		{   cgc_baseClass,                  9,        &iObj_set_baseClass,                    &iObj_get_baseClass                     },
		{   cgc_class,                      5,        &iObj_set_class,                        &iObj_get_class                         },
		{   cgc_classLibrary,               12,       &iObj_set_classLibrary,                 &iObj_get_classLibrary                  },
		{   cgc_controls,                   8,        &iObj_set_controls,                     &iObj_get_controls                      },
		{   cgc_controlCount,               12,       &iObj_set_controlCount,                 &iObj_get_controlCount                  },
		{   cgc_objects,                    7,        &iObj_set_objects,                      &iObj_get_objects                       },
		{   cgc_bound,                      5,        &iObj_set_bound,                        &iObj_get_bound                         },
		{   cgc_foreColor,                  9,        &iObj_set_foreColor,                    &iObj_get_foreColor                     },
		{   cgc_backColor,                  9,        &iObj_set_backColor,                    &iObj_get_backColor                     },
		{   cgc_comment,                    7,        &iObj_set_comment,                      &iObj_get_comment                       },
		{   cgc_controlSource,              13,       &iObj_set_controlSource,                &iObj_get_controlSource                 },
		{   cgc_enabled,                    7,        &iObj_set_enabled,                      &iObj_get_enabled                       },
		{   cgc_fontBold,                   8,        &iObj_set_fontBold,                     &iObj_get_fontBold                      },
		{   cgc_fontCharSet,                11,       &iObj_set_fontCharSet,                  &iObj_get_fontCharSet                   },
		{   cgc_fontCondense,               12,       &iObj_set_fontCondense,                 &iObj_get_fontCondense                  },
		{   cgc_fontExtend,                 10,       &iObj_set_fontExtend,                   &iObj_get_fontExtend                    },
		{   cgc_fontItalic,                 10,       &iObj_set_fontItalic,                   &iObj_get_fontItalic                    },
		{   cgc_fontName,                   8,        &iObj_set_fontName,                     &iObj_get_fontName                      },
		{   cgc_fontOutline,                11,       &iObj_set_fontOutline,                  &iObj_get_fontOutline                   },
		{   cgc_fontShadow,                 10,       &iObj_set_fontShadow,                   &iObj_get_fontShadow                    },
		{   cgc_fontSize,                   8,        &iObj_set_fontSize,                     &iObj_get_fontSize                      },
		{   cgc_fontStrikeThru,             14,       &iObj_set_fontStrikeThru,               &iObj_get_fontStrikeThru                },
		{   cgc_fontUnderline,              13,       &iObj_set_fontUnderline,                &iObj_get_fontUnderline                 },
		{   cgc_format,                     6,        &iObj_set_format,                       &iObj_get_format                        },
		{   cgc_inputMask,                  9,        &iObj_set_inputMask,                    &iObj_get_inputMask                     },
		{   cgc_mouseIcon,                  9,        &iObj_set_mouseIcon,                    &iObj_get_mouseIcon                     },
		{   cgc_mousePointer,               12,       &iObj_set_mousePointer,                 &iObj_get_mousePointer                  },
		{   cgc_name,                       4,        &iObj_set_name,                         &iObj_get_name                          },
		{   cgc_parent,                     6,        &iObj_set_parent,                       &iObj_get_parent                        },
		{   cgc_parentClass,                11,       &iObj_set_parentClass,                  &iObj_get_parentClass                   },
		{   cgc_readOnly,                   8,        &iObj_set_readOnly,                     &iObj_get_readOnly                      },
		{   cgc_selectOnEntry,              13,       &iObj_set_selectOnEntry,                &iObj_get_selectOnEntry                 },
		{   cgc_resizable,                  9,        &iObj_set_resizable,                    &iObj_get_resizable                     },
		{   cgc_statusBarText,              13,       &iObj_set_statusBarText,                &iObj_get_statusBarText                 },
		{   cgc_tag,                        3,        &iObj_set_tag,                          &iObj_get_tag                           },
		{   cgc_toolTipText,                11,       &iObj_set_toolTipText,                  &iObj_get_toolTipText                   },
		{   cgc_visible,                    7,        &iObj_set_visible,                      &iObj_get_visible                       },
		{   cgc_width,                      5,        &iObj_set_width,                        &iObj_get_width                         },
		{   NULL,                           0,        0,                                      0                                       }
	};

	SPropertyMap gcProps_header[] = 
	{
		// Translation for VJr provided by Hernan Cano Martinez
		{   cgc_alignment,                  9,        &iObj_set_alignment,                    &iObj_get_alignment                     },
		{   cgc_anchor,                     6,        &iObj_set_anchor,                       &iObj_get_anchor                        },
		{   cgc_application,                11,       &iObj_set_application,                  &iObj_get_application                   },
		{   cgc_baseClass,                  9,        &iObj_set_baseClass,                    &iObj_get_baseClass                     },
		{   cgc_class,                      5,        &iObj_set_class,                        &iObj_get_class                         },
		{   cgc_classLibrary,               12,       &iObj_set_classLibrary,                 &iObj_get_classLibrary                  },
		{   cgc_caption,                    7,        &iObj_set_caption,                      &iObj_get_caption                       },
		{   cgc_foreColor,                  9,        &iObj_set_foreColor,                    &iObj_get_foreColor                     },
		{   cgc_backColor,                  9,        &iObj_set_backColor,                    &iObj_get_backColor                     },
		{   cgc_comment,                    7,        &iObj_set_comment,                      &iObj_get_comment                       },
		{   cgc_fontBold,                   8,        &iObj_set_fontBold,                     &iObj_get_fontBold                      },
		{   cgc_fontCharSet,                11,       &iObj_set_fontCharSet,                  &iObj_get_fontCharSet                   },
		{   cgc_fontCondense,               12,       &iObj_set_fontCondense,                 &iObj_get_fontCondense                  },
		{   cgc_fontExtend,                 10,       &iObj_set_fontExtend,                   &iObj_get_fontExtend                    },
		{   cgc_fontItalic,                 10,       &iObj_set_fontItalic,                   &iObj_get_fontItalic                    },
		{   cgc_fontName,                   8,        &iObj_set_fontName,                     &iObj_get_fontName                      },
		{   cgc_fontOutline,                11,       &iObj_set_fontOutline,                  &iObj_get_fontOutline                   },
		{   cgc_fontShadow,                 10,       &iObj_set_fontShadow,                   &iObj_get_fontShadow                    },
		{   cgc_fontSize,                   8,        &iObj_set_fontSize,                     &iObj_get_fontSize                      },
		{   cgc_fontStrikeThru,             14,       &iObj_set_fontStrikeThru,               &iObj_get_fontStrikeThru                },
		{   cgc_fontUnderline,              13,       &iObj_set_fontUnderline,                &iObj_get_fontUnderline                 },
		{   cgc_mouseIcon,                  9,        &iObj_set_mouseIcon,                    &iObj_get_mouseIcon                     },
		{   cgc_mousePointer,               12,       &iObj_set_mousePointer,                 &iObj_get_mousePointer                  },
		{   cgc_name,                       4,        &iObj_set_name,                         &iObj_get_name                          },
		{   cgc_parent,                     6,        &iObj_set_parent,                       &iObj_get_parent                        },
		{   cgc_parentClass,                11,       &iObj_set_parentClass,                  &iObj_get_parentClass                   },
		{   cgc_picture,                    7,        &iObj_set_picture,                      &iObj_get_picture                       },
		{   cgc_statusBarText,              13,       &iObj_set_statusBarText,                &iObj_get_statusBarText                 },
		{   cgc_tag,                        3,        &iObj_set_tag,                          &iObj_get_tag                           },
		{   cgc_toolTipText,                11,       &iObj_set_toolTipText,                  &iObj_get_toolTipText                   },
		{   cgc_wordWrap,                   8,        &iObj_set_wordWrap,                     &iObj_get_wordWrap                      },
		{   NULL,                           0,        0,                                      0                                       }
	};

	SPropertyMap gcProps_olebound[] = 
	{
		// Translation for VJr provided by Hernan Cano Martinez
		{   cgc_autoActivate,               12,       &iObj_set_autoActivate,                 &iObj_get_autoActivate                  },
		{   cgc_autoSize,                   8,        &iObj_set_autoSize,                     &iObj_get_autoSize                      },
		{   cgc_autoVerbMenu,               12,       &iObj_set_autoVerbMenu,                 &iObj_get_autoVerbMenu                  },
		{   cgc_documentFile,               12,       &iObj_set_documentFile,                 &iObj_get_documentFile                  },
		{   cgc_hostName,                   8,        &iObj_set_hostName,                     &iObj_get_hostName                      },
		{   cgc_object,                     6,        &iObj_set_object,                       &iObj_get_object                        },
		{   cgc_anchor,                     6,        &iObj_set_anchor,                       &iObj_get_anchor                        },
		{   cgc_application,                11,       &iObj_set_application,                  &iObj_get_application                   },
		{   cgc_baseClass,                  9,        &iObj_set_baseClass,                    &iObj_get_baseClass                     },
		{   cgc_class,                      5,        &iObj_set_class,                        &iObj_get_class                         },
		{   cgc_classLibrary,               12,       &iObj_set_classLibrary,                 &iObj_get_classLibrary                  },
		{   cgc_comment,                    7,        &iObj_set_comment,                      &iObj_get_comment                       },
		{   cgc_controlSource,              13,       &iObj_set_controlSource,                &iObj_get_controlSource                 },
		{   cgc_dragIcon,                   8,        &iObj_set_dragIcon,                     &iObj_get_dragIcon                      },
		{   cgc_dragMode,                   8,        &iObj_set_dragMode,                     &iObj_get_dragMode                      },
		{   cgc_enabled,                    7,        &iObj_set_enabled,                      &iObj_get_enabled                       },
		{   cgc_height,                     6,        &iObj_set_height,                       &iObj_get_height                        },
		{   cgc_helpContextID,              13,       &iObj_set_helpContextID,                &iObj_get_helpContextID                 },
		{   cgc_left,                       4,        &iObj_set_left,                         &iObj_get_left                          },
		{   cgc_mousePointer,               12,       &iObj_set_mousePointer,                 &iObj_get_mousePointer                  },
		{   cgc_name,                       4,        &iObj_set_name,                         &iObj_get_name                          },
		{   cgc_oLEClass,                   8,        &iObj_set_oLEClass,                     &iObj_get_oLEClass                      },
		{   cgc_oLELCID,                    7,        &iObj_set_oLELCID,                      &iObj_get_oLELCID                       },
		{   cgc_oLETypeAllowed,             14,       &iObj_set_oLETypeAllowed,               &iObj_get_oLETypeAllowed                },
		{   cgc_parentClass,                11,       &iObj_set_parentClass,                  &iObj_get_parentClass                   },
		{   cgc_sizable,                    7,        &iObj_set_sizable,                      &iObj_get_sizable                       },
		{   cgc_stretch,                    7,        &iObj_set_stretch,                      &iObj_get_stretch                       },
		{   cgc_statusBarText,              13,       &iObj_set_statusBarText,                &iObj_get_statusBarText                 },
		{   cgc_tabIndex,                   8,        &iObj_set_tabIndex,                     &iObj_get_tabIndex                      },
		{   cgc_tabStop,                    7,        &iObj_set_tabStop,                      &iObj_get_tabStop                       },
		{   cgc_tag,                        3,        &iObj_set_tag,                          &iObj_get_tag                           },
		{   cgc_toolTipText,                11,       &iObj_set_toolTipText,                  &iObj_get_toolTipText                   },
		{   cgc_top,                        3,        &iObj_set_top,                          &iObj_get_top                           },
		{   cgc_visible,                    7,        &iObj_set_visible,                      &iObj_get_visible                       },
		{   cgc_whatsThisHelpID,            15,       &iObj_set_whatsThisHelpID,              &iObj_get_whatsThisHelpID               },
		{   cgc_width,                      5,        &iObj_set_width,                        &iObj_get_width                         },
		{   cgc_wordWrap,                   8,        &iObj_set_wordWrap,                     &iObj_get_wordWrap                      },
		{   NULL,                           0,        0,                                      0                                       }
	};

	SPropertyMap gcProps_olecontain[] = 
	{
		// Translation for VJr provided by Hernan Cano Martinez
		{   cgc_autoActivate,               12,       &iObj_set_autoActivate,                 &iObj_get_autoActivate                  },
		{   cgc_autoSize,                   8,        &iObj_set_autoSize,                     &iObj_get_autoSize                      },
		{   cgc_autoVerbMenu,               12,       &iObj_set_autoVerbMenu,                 &iObj_get_autoVerbMenu                  },
		{   cgc_documentFile,               12,       &iObj_set_documentFile,                 &iObj_get_documentFile                  },
		{   cgc_hostName,                   8,        &iObj_set_hostName,                     &iObj_get_hostName                      },
		{   cgc_object,                     6,        &iObj_set_object,                       &iObj_get_object                        },
		{   cgc_align,                      5,        &iObj_set_align,                        &iObj_get_align                         },
		{   cgc_anchor,                     6,        &iObj_set_anchor,                       &iObj_get_anchor                        },
		{   cgc_application,                11,       &iObj_set_application,                  &iObj_get_application                   },
		{   cgc_baseClass,                  9,        &iObj_set_baseClass,                    &iObj_get_baseClass                     },
		{   cgc_class,                      5,        &iObj_set_class,                        &iObj_get_class                         },
		{   cgc_classLibrary,               12,       &iObj_set_classLibrary,                 &iObj_get_classLibrary                  },
		{   cgc_cancel,                     6,        &iObj_set_cancel,                       &iObj_get_cancel                        },
		{   cgc_default,                    7,        &iObj_set_default,                      &iObj_get_default                       },
		{   cgc_comment,                    7,        &iObj_set_comment,                      &iObj_get_comment                       },
		{   cgc_controlSource,              13,       &iObj_set_controlSource,                &iObj_get_controlSource                 },
		{   cgc_dragIcon,                   8,        &iObj_set_dragIcon,                     &iObj_get_dragIcon                      },
		{   cgc_dragMode,                   8,        &iObj_set_dragMode,                     &iObj_get_dragMode                      },
		{   cgc_enabled,                    7,        &iObj_set_enabled,                      &iObj_get_enabled                       },
		{   cgc_height,                     6,        &iObj_set_height,                       &iObj_get_height                        },
		{   cgc_helpContextID,              13,       &iObj_set_helpContextID,                &iObj_get_helpContextID                 },
		{   cgc_left,                       4,        &iObj_set_left,                         &iObj_get_left                          },
		{   cgc_mouseIcon,                  9,        &iObj_set_mouseIcon,                    &iObj_get_mouseIcon                     },
		{   cgc_mousePointer,               12,       &iObj_set_mousePointer,                 &iObj_get_mousePointer                  },
		{   cgc_name,                       4,        &iObj_set_name,                         &iObj_get_name                          },
		{   cgc_oLEClass,                   8,        &iObj_set_oLEClass,                     &iObj_get_oLEClass                      },
		{   cgc_oLELCID,                    7,        &iObj_set_oLELCID,                      &iObj_get_oLELCID                       },
		{   cgc_oLETypeAllowed,             14,       &iObj_set_oLETypeAllowed,               &iObj_get_oLETypeAllowed                },
		{   cgc_parent,                     6,        &iObj_set_parent,                       &iObj_get_parent                        },
		{   cgc_parentClass,                11,       &iObj_set_parentClass,                  &iObj_get_parentClass                   },
		{   cgc_sizable,                    7,        &iObj_set_sizable,                      &iObj_get_sizable                       },
		{   cgc_stretch,                    7,        &iObj_set_stretch,                      &iObj_get_stretch                       },
		{   cgc_tabIndex,                   8,        &iObj_set_tabIndex,                     &iObj_get_tabIndex                      },
		{   cgc_tabStop,                    7,        &iObj_set_tabStop,                      &iObj_get_tabStop                       },
		{   cgc_tag,                        3,        &iObj_set_tag,                          &iObj_get_tag                           },
		{   cgc_top,                        3,        &iObj_set_top,                          &iObj_get_top                           },
		{   cgc_visible,                    7,        &iObj_set_visible,                      &iObj_get_visible                       },
		{   cgc_whatsThisHelpID,            15,       &iObj_set_whatsThisHelpID,              &iObj_get_whatsThisHelpID               },
		{   cgc_width,                      5,        &iObj_set_width,                        &iObj_get_width                         },
		{   NULL,                           0,        0,                                      0                                       }
	};

	SPropertyMap gcProps_spinner[] = 
	{
		// Translation for VJr provided by Hernan Cano Martinez
		{   cgc_spinnerHighValue,           16,       &iObj_set_spinnerHighValue,             &iObj_get_spinnerHighValue              },
		{   cgc_spinnerLowValue,            15,       &iObj_set_spinnerLowValue,              &iObj_get_spinnerLowValue               },
		{   cgc_keyboardHighValue,          17,       &iObj_set_keyboardHighValue,            &iObj_get_keyboardHighValue             },
		{   cgc_keyboardLowValue,           16,       &iObj_set_keyboardLowValue,             &iObj_get_keyboardLowValue              },
		{   cgc_increment,                  9,        &iObj_set_increment,                    &iObj_get_increment                     },
		{   cgc_alignment,                  9,        &iObj_set_alignment,                    &iObj_get_alignment                     },
		{   cgc_anchor,                     6,        &iObj_set_anchor,                       &iObj_get_anchor                        },
		{   cgc_application,                11,       &iObj_set_application,                  &iObj_get_application                   },
		{   cgc_baseClass,                  9,        &iObj_set_baseClass,                    &iObj_get_baseClass                     },
		{   cgc_class,                      5,        &iObj_set_class,                        &iObj_get_class                         },
		{   cgc_classLibrary,               12,       &iObj_set_classLibrary,                 &iObj_get_classLibrary                  },
		{   cgc_borderColor,                11,       &iObj_set_borderColor,                  &iObj_get_borderColor                   },
		{   cgc_borderStyle,                11,       &iObj_set_borderStyle,                  &iObj_get_borderStyle                   },
		{   cgc_colorScheme,                11,       &iObj_set_colorScheme,                  &iObj_get_colorScheme                   },
		{   cgc_colorSource,                11,       &iObj_set_colorSource,                  &iObj_get_colorSource                   },
		{   cgc_foreColor,                  9,        &iObj_set_foreColor,                    &iObj_get_foreColor                     },
		{   cgc_backColor,                  9,        &iObj_set_backColor,                    &iObj_get_backColor                     },
		{   cgc_disabledBackColor,          17,       &iObj_set_disabledBackColor,            &iObj_get_disabledBackColor             },
		{   cgc_disabledForeColor,          17,       &iObj_set_disabledForeColor,            &iObj_get_disabledForeColor             },
		{   cgc_comment,                    7,        &iObj_set_comment,                      &iObj_get_comment                       },
		{   cgc_controlSource,              13,       &iObj_set_controlSource,                &iObj_get_controlSource                 },
		{   cgc_dragIcon,                   8,        &iObj_set_dragIcon,                     &iObj_get_dragIcon                      },
		{   cgc_dragMode,                   8,        &iObj_set_dragMode,                     &iObj_get_dragMode                      },
		{   cgc_enabled,                    7,        &iObj_set_enabled,                      &iObj_get_enabled                       },
		{   cgc_fontBold,                   8,        &iObj_set_fontBold,                     &iObj_get_fontBold                      },
		{   cgc_fontCharSet,                11,       &iObj_set_fontCharSet,                  &iObj_get_fontCharSet                   },
		{   cgc_fontCondense,               12,       &iObj_set_fontCondense,                 &iObj_get_fontCondense                  },
		{   cgc_fontExtend,                 10,       &iObj_set_fontExtend,                   &iObj_get_fontExtend                    },
		{   cgc_fontItalic,                 10,       &iObj_set_fontItalic,                   &iObj_get_fontItalic                    },
		{   cgc_fontName,                   8,        &iObj_set_fontName,                     &iObj_get_fontName                      },
		{   cgc_fontOutline,                11,       &iObj_set_fontOutline,                  &iObj_get_fontOutline                   },
		{   cgc_fontShadow,                 10,       &iObj_set_fontShadow,                   &iObj_get_fontShadow                    },
		{   cgc_fontSize,                   8,        &iObj_set_fontSize,                     &iObj_get_fontSize                      },
		{   cgc_fontStrikeThru,             14,       &iObj_set_fontStrikeThru,               &iObj_get_fontStrikeThru                },
		{   cgc_fontUnderline,              13,       &iObj_set_fontUnderline,                &iObj_get_fontUnderline                 },
		{   cgc_format,                     6,        &iObj_set_format,                       &iObj_get_format                        },
		{   cgc_height,                     6,        &iObj_set_height,                       &iObj_get_height                        },
		{   cgc_helpContextID,              13,       &iObj_set_helpContextID,                &iObj_get_helpContextID                 },
		{   cgc_hideSelection,              13,       &iObj_set_hideSelection,                &iObj_get_hideSelection                 },
		{   cgc_inputMask,                  9,        &iObj_set_inputMask,                    &iObj_get_inputMask                     },
		{   cgc_left,                       4,        &iObj_set_left,                         &iObj_get_left                          },
		{   cgc_margin,                     6,        &iObj_set_margin,                       &iObj_get_margin                        },
		{   cgc_mouseIcon,                  9,        &iObj_set_mouseIcon,                    &iObj_get_mouseIcon                     },
		{   cgc_mousePointer,               12,       &iObj_set_mousePointer,                 &iObj_get_mousePointer                  },
		{   cgc_name,                       4,        &iObj_set_name,                         &iObj_get_name                          },
		{   cgc_nullDisplay,                11,       &iObj_set_nullDisplay,                  &iObj_get_nullDisplay                   },
		{   cgc_oLEDragMode,                11,       &iObj_set_oLEDragMode,                  &iObj_get_oLEDragMode                   },
		{   cgc_oLEDragPicture,             14,       &iObj_set_oLEDragPicture,               &iObj_get_oLEDragPicture                },
		{   cgc_oLEDropEffects,             14,       &iObj_set_oLEDropEffects,               &iObj_get_oLEDropEffects                },
		{   cgc_oLEDropHasData,             14,       &iObj_set_oLEDropHasData,               &iObj_get_oLEDropHasData                },
		{   cgc_oLEDropMode,                11,       &iObj_set_oLEDropMode,                  &iObj_get_oLEDropMode                   },
		{   cgc_oLEDropTextInsertion,       20,       &iObj_set_oLEDropTextInsertion,         &iObj_get_oLEDropTextInsertion          },
		{   cgc_parent,                     6,        &iObj_set_parent,                       &iObj_get_parent                        },
		{   cgc_parentClass,                11,       &iObj_set_parentClass,                  &iObj_get_parentClass                   },
		{   cgc_readOnly,                   8,        &iObj_set_readOnly,                     &iObj_get_readOnly                      },
		{   cgc_rightToLeft,                11,       &iObj_set_rightToLeft,                  &iObj_get_rightToLeft                   },
		{   cgc_selectedBackColor,          17,       &iObj_set_selectedBackColor,            &iObj_get_selectedBackColor             },
		{   cgc_selectedForeColor,          17,       &iObj_set_selectedForeColor,            &iObj_get_selectedForeColor             },
		{   cgc_selectOnEntry,              13,       &iObj_set_selectOnEntry,                &iObj_get_selectOnEntry                 },
		{   cgc_selLength,                  9,        &iObj_set_selLength,                    &iObj_get_selLength                     },
		{   cgc_selStart,                   8,        &iObj_set_selStart,                     &iObj_get_selStart                      },
		{   cgc_selText,                    7,        &iObj_set_selText,                      &iObj_get_selText                       },
		{   cgc_specialEffect,              13,       &iObj_set_specialEffect,                &iObj_get_specialEffect                 },
		{   cgc_statusBarText,              13,       &iObj_set_statusBarText,                &iObj_get_statusBarText                 },
		{   cgc_tabIndex,                   8,        &iObj_set_tabIndex,                     &iObj_get_tabIndex                      },
		{   cgc_tabStop,                    7,        &iObj_set_tabStop,                      &iObj_get_tabStop                       },
		{   cgc_tag,                        3,        &iObj_set_tag,                          &iObj_get_tag                           },
		{   cgc_terminateRead,              13,       &iObj_set_terminateRead,                &iObj_get_terminateRead                 },
		{   cgc_text,                       4,        &iObj_set_text,                         &iObj_get_text                          },
		{   cgc_themes,                     6,        &iObj_set_themes,                       &iObj_get_themes                        },
		{   cgc_toolTipText,                11,       &iObj_set_toolTipText,                  &iObj_get_toolTipText                   },
		{   cgc_top,                        3,        &iObj_set_top,                          &iObj_get_top                           },
		{   cgc_value,                      5,        &iObj_set_value,                        &iObj_get_value                         },
		{   cgc_visible,                    7,        &iObj_set_visible,                      &iObj_get_visible                       },
		{   cgc_whatsThisHelpID,            15,       &iObj_set_whatsThisHelpID,              &iObj_get_whatsThisHelpID               },
		{   cgc_width,                      5,        &iObj_set_width,                        &iObj_get_width                         },
		{   NULL,                           0,        0,                                      0                                       }
	};

	SPropertyMap gcProps_timer[] = 
	{
		// Translation for VJr provided by Hernan Cano Martinez
		{   cgc_interval,                   8,        &iObj_set_interval,                     &iObj_get_interval                      },
		{   cgc_application,                11,       &iObj_set_application,                  &iObj_get_application                   },
		{   cgc_baseClass,                  9,        &iObj_set_baseClass,                    &iObj_get_baseClass                     },
		{   cgc_class,                      5,        &iObj_set_class,                        &iObj_get_class                         },
		{   cgc_classLibrary,               12,       &iObj_set_classLibrary,                 &iObj_get_classLibrary                  },
		{   cgc_comment,                    7,        &iObj_set_comment,                      &iObj_get_comment                       },
		{   cgc_enabled,                    7,        &iObj_set_enabled,                      &iObj_get_enabled                       },
		{   cgc_height,                     6,        &iObj_set_height,                       &iObj_get_height                        },
		{   cgc_left,                       4,        &iObj_set_left,                         &iObj_get_left                          },
		{   cgc_name,                       4,        &iObj_set_name,                         &iObj_get_name                          },
		{   cgc_parent,                     6,        &iObj_set_parent,                       &iObj_get_parent                        },
		{   cgc_parentClass,                11,       &iObj_set_parentClass,                  &iObj_get_parentClass                   },
		{   cgc_tag,                        3,        &iObj_set_tag,                          &iObj_get_tag                           },
		{   cgc_top,                        3,        &iObj_set_top,                          &iObj_get_top                           },
		{   cgc_width,                      5,        &iObj_set_width,                        &iObj_get_width                         },
		{   NULL,                           0,        0,                                      0                                       }
	};

	SPropertyMap gcProps_hyperlink[] = 
	{
		// Translation for VJr provided by Hernan Cano Martinez
		{   cgc_application,                11,       &iObj_set_application,                  &iObj_get_application                   },
		{   cgc_baseClass,                  9,        &iObj_set_baseClass,                    &iObj_get_baseClass                     },
		{   cgc_class,                      5,        &iObj_set_class,                        &iObj_get_class                         },
		{   cgc_classLibrary,               12,       &iObj_set_classLibrary,                 &iObj_get_classLibrary                  },
		{   cgc_comment,                    7,        &iObj_set_comment,                      &iObj_get_comment                       },
		{   cgc_name,                       4,        &iObj_set_name,                         &iObj_get_name                          },
		{   cgc_parent,                     6,        &iObj_set_parent,                       &iObj_get_parent                        },
		{   cgc_parentClass,                11,       &iObj_set_parentClass,                  &iObj_get_parentClass                   },
		{   cgc_tag,                        3,        &iObj_set_tag,                          &iObj_get_tag                           },
		{   NULL,                           0,        0,                                      0                                       }
	};

	SPropertyMap gcProps_collection[] = 
	{
		// Translation for VJr provided by Hernan Cano Martinez
		{   cgc_keySort,                    7,        &iObj_set_keySort,                      &iObj_get_keySort                       },
		{   cgc_baseClass,                  9,        &iObj_set_baseClass,                    &iObj_get_baseClass                     },
		{   cgc_class,                      5,        &iObj_set_class,                        &iObj_get_class                         },
		{   cgc_classLibrary,               12,       &iObj_set_classLibrary,                 &iObj_get_classLibrary                  },
		{   cgc_count,                      5,        &iObj_set_count,                        &iObj_get_count                         },
		{   cgc_comment,                    7,        &iObj_set_comment,                      &iObj_get_comment                       },
		{   cgc_name,                       4,        &iObj_set_name,                         &iObj_get_name                          },
		{   cgc_parent,                     6,        &iObj_set_parent,                       &iObj_get_parent                        },
		{   cgc_parentClass,                11,       &iObj_set_parentClass,                  &iObj_get_parentClass                   },
		{   cgc_tag,                        3,        &iObj_set_tag,                          &iObj_get_tag                           },
		{   NULL,                           0,        0,                                      0                                       }
	};

	SPropertyMap gcProps_page[] = 
	{
		// Translation for VJr provided by Hernan Cano Martinez
		{   cgc_activeControl,              13,       &iObj_set_activeControl,                &iObj_get_activeControl                 },
		{   cgc_pageOrder,                  9,        &iObj_set_pageOrder,                    &iObj_get_pageOrder                     },
		{   cgc_application,                11,       &iObj_set_application,                  &iObj_get_application                   },
		{   cgc_backStyle,                  9,        &iObj_set_backStyle,                    &iObj_get_backStyle                     },
		{   cgc_baseClass,                  9,        &iObj_set_baseClass,                    &iObj_get_baseClass                     },
		{   cgc_class,                      5,        &iObj_set_class,                        &iObj_get_class                         },
		{   cgc_classLibrary,               12,       &iObj_set_classLibrary,                 &iObj_get_classLibrary                  },
		{   cgc_controls,                   8,        &iObj_set_controls,                     &iObj_get_controls                      },
		{   cgc_controlCount,               12,       &iObj_set_controlCount,                 &iObj_get_controlCount                  },
		{   cgc_objects,                    7,        &iObj_set_objects,                      &iObj_get_objects                       },
		{   cgc_caption,                    7,        &iObj_set_caption,                      &iObj_get_caption                       },
		{   cgc_colorSource,                11,       &iObj_set_colorSource,                  &iObj_get_colorSource                   },
		{   cgc_foreColor,                  9,        &iObj_set_foreColor,                    &iObj_get_foreColor                     },
		{   cgc_backColor,                  9,        &iObj_set_backColor,                    &iObj_get_backColor                     },
		{   cgc_comment,                    7,        &iObj_set_comment,                      &iObj_get_comment                       },
		{   cgc_dragIcon,                   8,        &iObj_set_dragIcon,                     &iObj_get_dragIcon                      },
		{   cgc_dragMode,                   8,        &iObj_set_dragMode,                     &iObj_get_dragMode                      },
		{   cgc_enabled,                    7,        &iObj_set_enabled,                      &iObj_get_enabled                       },
		{   cgc_fontBold,                   8,        &iObj_set_fontBold,                     &iObj_get_fontBold                      },
		{   cgc_fontCharSet,                11,       &iObj_set_fontCharSet,                  &iObj_get_fontCharSet                   },
		{   cgc_fontCondense,               12,       &iObj_set_fontCondense,                 &iObj_get_fontCondense                  },
		{   cgc_fontExtend,                 10,       &iObj_set_fontExtend,                   &iObj_get_fontExtend                    },
		{   cgc_fontItalic,                 10,       &iObj_set_fontItalic,                   &iObj_get_fontItalic                    },
		{   cgc_fontName,                   8,        &iObj_set_fontName,                     &iObj_get_fontName                      },
		{   cgc_fontOutline,                11,       &iObj_set_fontOutline,                  &iObj_get_fontOutline                   },
		{   cgc_fontShadow,                 10,       &iObj_set_fontShadow,                   &iObj_get_fontShadow                    },
		{   cgc_fontSize,                   8,        &iObj_set_fontSize,                     &iObj_get_fontSize                      },
		{   cgc_fontStrikeThru,             14,       &iObj_set_fontStrikeThru,               &iObj_get_fontStrikeThru                },
		{   cgc_fontUnderline,              13,       &iObj_set_fontUnderline,                &iObj_get_fontUnderline                 },
		{   cgc_helpContextID,              13,       &iObj_set_helpContextID,                &iObj_get_helpContextID                 },
		{   cgc_mouseIcon,                  9,        &iObj_set_mouseIcon,                    &iObj_get_mouseIcon                     },
		{   cgc_mousePointer,               12,       &iObj_set_mousePointer,                 &iObj_get_mousePointer                  },
		{   cgc_name,                       4,        &iObj_set_name,                         &iObj_get_name                          },
		{   cgc_oLEDragMode,                11,       &iObj_set_oLEDragMode,                  &iObj_get_oLEDragMode                   },
		{   cgc_oLEDragPicture,             14,       &iObj_set_oLEDragPicture,               &iObj_get_oLEDragPicture                },
		{   cgc_oLEDropEffects,             14,       &iObj_set_oLEDropEffects,               &iObj_get_oLEDropEffects                },
		{   cgc_oLEDropHasData,             14,       &iObj_set_oLEDropHasData,               &iObj_get_oLEDropHasData                },
		{   cgc_oLEDropMode,                11,       &iObj_set_oLEDropMode,                  &iObj_get_oLEDropMode                   },
		{   cgc_parent,                     6,        &iObj_set_parent,                       &iObj_get_parent                        },
		{   cgc_parentClass,                11,       &iObj_set_parentClass,                  &iObj_get_parentClass                   },
		{   cgc_picture,                    7,        &iObj_set_picture,                      &iObj_get_picture                       },
		{   cgc_tag,                        3,        &iObj_set_tag,                          &iObj_get_tag                           },
		{   cgc_toolTipText,                11,       &iObj_set_toolTipText,                  &iObj_get_toolTipText                   },
		{   cgc_whatsThisHelpID,            15,       &iObj_set_whatsThisHelpID,              &iObj_get_whatsThisHelpID               },
		{   NULL,                           0,        0,                                      0                                       }
	};

	SPropertyMap gcProps_pageframe[] = 
	{
		// Translation for VJr provided by Hernan Cano Martinez
		{   cgc_activePage,                 10,       &iObj_set_activePage,                   &iObj_get_activePage                    },
		{   cgc_tabOrientation,             14,       &iObj_set_tabOrientation,               &iObj_get_tabOrientation                },
		{   cgc_tabs,                       4,        &iObj_set_tabs,                         &iObj_get_tabs                          },
		{   cgc_pageHeight,                 10,       &iObj_set_pageHeight,                   &iObj_get_pageHeight                    },
		{   cgc_pageWidth,                  9,        &iObj_set_pageWidth,                    &iObj_get_pageWidth                     },
		{   cgc_anchor,                     6,        &iObj_set_anchor,                       &iObj_get_anchor                        },
		{   cgc_application,                11,       &iObj_set_application,                  &iObj_get_application                   },
		{   cgc_baseClass,                  9,        &iObj_set_baseClass,                    &iObj_get_baseClass                     },
		{   cgc_class,                      5,        &iObj_set_class,                        &iObj_get_class                         },
		{   cgc_classLibrary,               12,       &iObj_set_classLibrary,                 &iObj_get_classLibrary                  },
		{   cgc_pages,                      5,        &iObj_set_pages,                        &iObj_get_pages                         },
		{   cgc_pageCount,                  9,        &iObj_set_pageCount,                    &iObj_get_pageCount                     },
		{   cgc_objects,                    7,        &iObj_set_objects,                      &iObj_get_objects                       },
		{   cgc_borderColor,                11,       &iObj_set_borderColor,                  &iObj_get_borderColor                   },
		{   cgc_borderWidth,                11,       &iObj_set_borderWidth,                  &iObj_get_borderWidth                   },
		{   cgc_colorSource,                11,       &iObj_set_colorSource,                  &iObj_get_colorSource                   },
		{   cgc_comment,                    7,        &iObj_set_comment,                      &iObj_get_comment                       },
		{   cgc_dragIcon,                   8,        &iObj_set_dragIcon,                     &iObj_get_dragIcon                      },
		{   cgc_dragMode,                   8,        &iObj_set_dragMode,                     &iObj_get_dragMode                      },
		{   cgc_enabled,                    7,        &iObj_set_enabled,                      &iObj_get_enabled                       },
		{   cgc_height,                     6,        &iObj_set_height,                       &iObj_get_height                        },
		{   cgc_helpContextID,              13,       &iObj_set_helpContextID,                &iObj_get_helpContextID                 },
		{   cgc_left,                       4,        &iObj_set_left,                         &iObj_get_left                          },
		{   cgc_memberClass,                11,       &iObj_set_memberClass,                  &iObj_get_memberClass                   },
		{   cgc_memberClassLibrary,         18,       &iObj_set_memberClassLibrary,           &iObj_get_memberClassLibrary            },
		{   cgc_mouseIcon,                  9,        &iObj_set_mouseIcon,                    &iObj_get_mouseIcon                     },
		{   cgc_mousePointer,               12,       &iObj_set_mousePointer,                 &iObj_get_mousePointer                  },
		{   cgc_name,                       4,        &iObj_set_name,                         &iObj_get_name                          },
		{   cgc_oLEDragMode,                11,       &iObj_set_oLEDragMode,                  &iObj_get_oLEDragMode                   },
		{   cgc_oLEDragPicture,             14,       &iObj_set_oLEDragPicture,               &iObj_get_oLEDragPicture                },
		{   cgc_oLEDropEffects,             14,       &iObj_set_oLEDropEffects,               &iObj_get_oLEDropEffects                },
		{   cgc_oLEDropHasData,             14,       &iObj_set_oLEDropHasData,               &iObj_get_oLEDropHasData                },
		{   cgc_oLEDropMode,                11,       &iObj_set_oLEDropMode,                  &iObj_get_oLEDropMode                   },
		{   cgc_parent,                     6,        &iObj_set_parent,                       &iObj_get_parent                        },
		{   cgc_parentClass,                11,       &iObj_set_parentClass,                  &iObj_get_parentClass                   },
		{   cgc_rightToLeft,                11,       &iObj_set_rightToLeft,                  &iObj_get_rightToLeft                   },
		{   cgc_specialEffect,              13,       &iObj_set_specialEffect,                &iObj_get_specialEffect                 },
		{   cgc_statusBarText,              13,       &iObj_set_statusBarText,                &iObj_get_statusBarText                 },
		{   cgc_tabStyle,                   8,        &iObj_set_tabStyle,                     &iObj_get_tabStyle                      },
		{   cgc_tabIndex,                   8,        &iObj_set_tabIndex,                     &iObj_get_tabIndex                      },
		{   cgc_tabStop,                    7,        &iObj_set_tabStop,                      &iObj_get_tabStop                       },
		{   cgc_tag,                        3,        &iObj_set_tag,                          &iObj_get_tag                           },
		{   cgc_themes,                     6,        &iObj_set_themes,                       &iObj_get_themes                        },
		{   cgc_toolTipText,                11,       &iObj_set_toolTipText,                  &iObj_get_toolTipText                   },
		{   cgc_top,                        3,        &iObj_set_top,                          &iObj_get_top                           },
		{   cgc_visible,                    7,        &iObj_set_visible,                      &iObj_get_visible                       },
		{   cgc_whatsThisHelpID,            15,       &iObj_set_whatsThisHelpID,              &iObj_get_whatsThisHelpID               },
		{   cgc_width,                      5,        &iObj_set_width,                        &iObj_get_width                         },
		{   NULL,                           0,        0,                                      0                                       }
	};

	SPropertyMap gcProps_session[] = 
	{
		// Translation for VJr provided by Hernan Cano Martinez
		{   cgc_dataSession,                11,       &iObj_set_dataSession,                  &iObj_get_dataSession                   },
		{   cgc_dataSessionID,              13,       &iObj_set_dataSessionID,                &iObj_get_dataSessionID                 },
		{   cgc_application,                11,       &iObj_set_application,                  &iObj_get_application                   },
		{   cgc_baseClass,                  9,        &iObj_set_baseClass,                    &iObj_get_baseClass                     },
		{   cgc_class,                      5,        &iObj_set_class,                        &iObj_get_class                         },
		{   cgc_classLibrary,               12,       &iObj_set_classLibrary,                 &iObj_get_classLibrary                  },
		{   cgc_comment,                    7,        &iObj_set_comment,                      &iObj_get_comment                       },
		{   cgc_name,                       4,        &iObj_set_name,                         &iObj_get_name                          },
		{   cgc_parent,                     6,        &iObj_set_parent,                       &iObj_get_parent                        },
		{   cgc_parentClass,                11,       &iObj_set_parentClass,                  &iObj_get_parentClass                   },
		{   cgc_tag,                        3,        &iObj_set_tag,                          &iObj_get_tag                           },
		{   NULL,                           0,        0,                                      0                                       }
	};

	SPropertyMap gcProps_custom[] = 
	{
		// Translation for VJr provided by Hernan Cano Martinez
		{   cgc_application,                11,       &iObj_set_application,                  &iObj_get_application                   },
		{   cgc_baseClass,                  9,        &iObj_set_baseClass,                    &iObj_get_baseClass                     },
		{   cgc_class,                      5,        &iObj_set_class,                        &iObj_get_class                         },
		{   cgc_classLibrary,               12,       &iObj_set_classLibrary,                 &iObj_get_classLibrary                  },
		{   cgc_controls,                   8,        &iObj_set_controls,                     &iObj_get_controls                      },
		{   cgc_controlCount,               12,       &iObj_set_controlCount,                 &iObj_get_controlCount                  },
		{   cgc_objects,                    7,        &iObj_set_objects,                      &iObj_get_objects                       },
		{   cgc_comment,                    7,        &iObj_set_comment,                      &iObj_get_comment                       },
		{   cgc_height,                     6,        &iObj_set_height,                       &iObj_get_height                        },
		{   cgc_helpContextID,              13,       &iObj_set_helpContextID,                &iObj_get_helpContextID                 },
		{   cgc_left,                       4,        &iObj_set_left,                         &iObj_get_left                          },
		{   cgc_name,                       4,        &iObj_set_name,                         &iObj_get_name                          },
		{   cgc_parent,                     6,        &iObj_set_parent,                       &iObj_get_parent                        },
		{   cgc_parentClass,                11,       &iObj_set_parentClass,                  &iObj_get_parentClass                   },
		{   cgc_picture,                    7,        &iObj_set_picture,                      &iObj_get_picture                       },
		{   cgc_tag,                        3,        &iObj_set_tag,                          &iObj_get_tag                           },
		{   cgc_top,                        3,        &iObj_set_top,                          &iObj_get_top                           },
		{   cgc_whatsThisHelpID,            15,       &iObj_set_whatsThisHelpID,              &iObj_get_whatsThisHelpID               },
		{   cgc_width,                      5,        &iObj_set_width,                        &iObj_get_width                         },
		{   NULL,                           0,        0,                                      0                                       }
	};

	SPropertyMap gcProps_exception[] = 
	{
		// Translation for VJr provided by Hernan Cano Martinez
		{   cgc_details,                    7,        &iObj_set_details,                      &iObj_get_details                       },
		{   cgc_errorNo,                    7,        &iObj_set_errorNo,                      &iObj_get_errorNo                       },
		{   cgc_lineContents,               12,       &iObj_set_lineContents,                 &iObj_get_lineContents                  },
		{   cgc_lineNo,                     6,        &iObj_set_lineNo,                       &iObj_get_lineNo                        },
		{   cgc_message,                    7,        &iObj_set_message,                      &iObj_get_message                       },
		{   cgc_procedure,                  9,        &iObj_set_procedure,                    &iObj_get_procedure                     },
		{   cgc_stackLevel,                 10,       &iObj_set_stackLevel,                   &iObj_get_stackLevel                    },
		{   cgc_userValue,                  9,        &iObj_set_userValue,                    &iObj_get_userValue                     },
		{   cgc_baseClass,                  9,        &iObj_set_baseClass,                    &iObj_get_baseClass                     },
		{   cgc_class,                      5,        &iObj_set_class,                        &iObj_get_class                         },
		{   cgc_classLibrary,               12,       &iObj_set_classLibrary,                 &iObj_get_classLibrary                  },
		{   cgc_comment,                    7,        &iObj_set_comment,                      &iObj_get_comment                       },
		{   cgc_name,                       4,        &iObj_set_name,                         &iObj_get_name                          },
		{   cgc_parent,                     6,        &iObj_set_parent,                       &iObj_get_parent                        },
		{   cgc_parentClass,                11,       &iObj_set_parentClass,                  &iObj_get_parentClass                   },
		{   cgc_tag,                        3,        &iObj_set_tag,                          &iObj_get_tag                           },
		{   NULL,                           0,        0,                                      0                                       }
	};
