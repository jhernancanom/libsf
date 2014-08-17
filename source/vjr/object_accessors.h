//////////
//
// /libsf/source/vjr/object_accessors.h
//
//////
// Version 0.51.1
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
