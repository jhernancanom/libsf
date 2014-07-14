//////////
//
// /libsf/source/vjr/object_accessors.h
//
//////
// Version 0.31
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


	// For specific sub-objects
	// FORM Properties
	void					iiSubobj_form_setIcon					(SObject* obj, SBitmap* bmp);
	bool					iiSubobj_form_setMinLeft				(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getMinLeft				(SObject* obj);
	bool					iiSubobj_form_setMinTop					(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getMinTop					(SObject* obj);
	bool					iiSubobj_form_setMinWidth				(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getMinWidth				(SObject* obj);
	bool					iiSubobj_form_setMinHeight				(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getMinHeight				(SObject* obj);
	bool					iiSubobj_form_setMaxLeft				(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getMaxLeft				(SObject* obj);
	bool					iiSubobj_form_setMaxTop					(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getMaxTop					(SObject* obj);
	bool					iiSubobj_form_setMaxWidth				(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getMaxWidth				(SObject* obj);
	bool					iiSubobj_form_setMaxHeight				(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getMaxHeight				(SObject* obj);
	bool					iiSubobj_form_setFontName				(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getFontName				(SObject* obj);
	bool					iiSubobj_form_setFontSize				(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getFontSize				(SObject* obj);
	bool					iiSubobj_form_setFontBold				(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getFontBold				(SObject* obj);
	bool					iiSubobj_form_setFontItalic				(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getFontItalic				(SObject* obj);
	bool					iiSubobj_form_setFontUnderline			(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getFontUnderline			(SObject* obj);
	bool					iiSubobj_form_setFontStrikethrough		(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getFontStrikethrough		(SObject* obj);
	bool					iiSubobj_form_setFontCondensed			(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getFontCondensed			(SObject* obj);
	bool					iiSubobj_form_setFontExtended			(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getFontExtended			(SObject* obj);
	bool					iiSubobj_form_setFontOutline			(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getFontOutline			(SObject* obj);
	bool					iiSubobj_form_setFontShadow				(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getFontShadow				(SObject* obj);
	bool					iiSubobj_form_setNwColor				(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getNwColor				(SObject* obj);
	bool					iiSubobj_form_setNeColor				(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getNeColor				(SObject* obj);
	bool					iiSubobj_form_setSwColor				(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getSwColor				(SObject* obj);
	bool					iiSubobj_form_setSeColor				(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getSeColor				(SObject* obj);
	bool					iiSubobj_form_setBackColor				(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getBackColor				(SObject* obj);
	bool					iiSubobj_form_setForeColor				(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getForeColor				(SObject* obj);
	bool					iiSubobj_form_setCaptionColor			(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getCaptionColor			(SObject* obj);
	bool					iiSubobj_form_setCaption				(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getCaption				(SObject* obj);
	bool					iiSubobj_form_setPicture				(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getPicture				(SObject* obj);
	bool					iiSubobj_form_setAllowOutput			(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getAllowOutput			(SObject* obj);
	bool					iiSubobj_form_setAlwaysOnBottom			(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getAlwaysOnBottom			(SObject* obj);
	bool					iiSubobj_form_setAlwaysOnTop			(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getAlwaysOnTop			(SObject* obj);
	bool					iiSubobj_form_setAutoCenter				(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getAutoCenter				(SObject* obj);
	bool					iiSubobj_form_setBorderStyle			(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getBorderStyle			(SObject* obj);
	bool					iiSubobj_form_setIsCloseable			(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getIsCloseable			(SObject* obj);
	bool					iiSubobj_form_setProcessKeyPreviewEvents(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getProcessKeyPreviewEvents(SObject* obj);
	bool					iiSubobj_form_setHasControlBox			(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getHasControlBox			(SObject* obj);
	bool					iiSubobj_form_setHasMinButton			(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getHasMinButton			(SObject* obj);
	bool					iiSubobj_form_setHasCloseButton			(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getHasCloseButton			(SObject* obj);
	bool					iiSubobj_form_setScaleMode				(SObject* obj, SVariable* var);
	bool					iiSubobj_form_setScaleMode_extraTest	(s32 value);
	SVariable*				iiSubobj_form_getScaleMode				(SObject* obj);
	bool					iiSubobj_form_setShowInTaskBar			(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getShowInTaskBar			(SObject* obj);
	bool					iiSubobj_form_setWindowState			(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getWindowState			(SObject* obj);
	bool					iiSubobj_form_setBindControls			(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getBindControls			(SObject* obj);
	bool					iiSubobj_form_setBufferMode				(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getBufferMode				(SObject* obj);
	bool					iiSubobj_form_setClipControls			(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getClipControls			(SObject* obj);
	bool					iiSubobj_form_setColorSource			(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getColorSource			(SObject* obj);
	bool					iiSubobj_form_setContinuousScroll		(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getContinuousScroll		(SObject* obj);
	bool					iiSubobj_form_setDataSession			(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getDataSession			(SObject* obj);
	bool					iiSubobj_form_setDataSessionId			(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getDataSessionId			(SObject* obj);
	bool					iiSubobj_form_setDeClass				(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getDeClass				(SObject* obj);
	bool					iiSubobj_form_setDeClassLibrary			(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getDeClassLibrary			(SObject* obj);
	bool					iiSubobj_form_setDefOleCid				(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getDefOleCid				(SObject* obj);
	bool					iiSubobj_form_setDesktop				(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getDesktop				(SObject* obj);
	bool					iiSubobj_form_setIsDockable				(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getIsDockable				(SObject* obj);
	bool					iiSubobj_form_setIsDocked				(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getIsDocked				(SObject* obj);
	bool					iiSubobj_form_setDockPosition			(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getDockPosition			(SObject* obj);
	bool					iiSubobj_form_setDrawMode				(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getDrawMode				(SObject* obj);
	bool					iiSubobj_form_setDrawStyle				(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getDrawStyle				(SObject* obj);
	bool					iiSubobj_form_setDrawWidth				(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getDrawWidth				(SObject* obj);
	bool					iiSubobj_form_setFillColor				(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getFillColor				(SObject* obj);
	bool					iiSubobj_form_setFillStyle				(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getFillStyle				(SObject* obj);
	bool					iiSubobj_form_setHalfHeightCaption		(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getHalfHeightCaption		(SObject* obj);
	bool					iiSubobj_form_setHScrollSmallChange		(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getHScrollSmallChange		(SObject* obj);
	bool					iiSubobj_form_setVScrollSmallChange		(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getVScrollSmallChange		(SObject* obj);
	bool					iiSubobj_form_setMacDesktop				(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getMacDesktop				(SObject* obj);
	bool					iiSubobj_form_setMdiForm				(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getMdiForm				(SObject* obj);
	bool					iiSubobj_form_setOleDragMode			(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getOleDragMode			(SObject* obj);
	bool					iiSubobj_form_setOleDragPicture			(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getOleDragPicture			(SObject* obj);
	bool					iiSubobj_form_setOleDropEffects			(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getOleDropEffects			(SObject* obj);
	bool					iiSubobj_form_setOleDropHasData			(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getOleDropHasData			(SObject* obj);
	bool					iiSubobj_form_setOleDropMode			(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getOleDropMode			(SObject* obj);
	bool					iiSubobj_form_setReleaseType			(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getReleaseType			(SObject* obj);
	bool					iiSubobj_form_setRightToLeft			(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getRightToLeft			(SObject* obj);
	bool					iiSubobj_form_setScrollbars				(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getScrollbars				(SObject* obj);
	bool					iiSubobj_form_setShowTips				(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getShowTips				(SObject* obj);
	bool					iiSubobj_form_setShowWindow				(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getShowWindow				(SObject* obj);
	bool					iiSubobj_form_setSizeBox				(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getSizeBox				(SObject* obj);
	bool					iiSubobj_form_setThemes					(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getThemes					(SObject* obj);
	bool					iiSubobj_form_setTitleBar				(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getTitleBar				(SObject* obj);
	bool					iiSubobj_form_setWindowType				(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getWindowType				(SObject* obj);
	bool					iiSubobj_form_setZoomBox				(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_form_getZoomBox				(SObject* obj);

	// SUBFORM Properties
	bool					iiSubobj_subform_setMinLeft				(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_subform_getMinLeft				(SObject* obj);
	bool					iiSubobj_subform_setMinTop				(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_subform_getMinTop				(SObject* obj);
	bool					iiSubobj_subform_setMinWidth			(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_subform_getMinWidth			(SObject* obj);
	bool					iiSubobj_subform_setMinHeight			(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_subform_getMinHeight			(SObject* obj);
	bool					iiSubobj_subform_setMaxLeft				(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_subform_getMaxLeft				(SObject* obj);
	bool					iiSubobj_subform_setMaxTop				(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_subform_getMaxTop				(SObject* obj);
	bool					iiSubobj_subform_setMaxWidth			(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_subform_getMaxWidth			(SObject* obj);
	bool					iiSubobj_subform_setMaxHeight			(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_subform_getMaxHeight			(SObject* obj);
	bool					iiSubobj_subform_setFontName			(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_subform_getFontName			(SObject* obj);
	bool					iiSubobj_subform_setFontSize			(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_subform_getFontSize			(SObject* obj);
	bool					iiSubobj_subform_setFontBold			(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_subform_getFontBold			(SObject* obj);
	bool					iiSubobj_subform_setFontItalic			(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_subform_getFontItalic			(SObject* obj);
	bool					iiSubobj_subform_setFontUnderline		(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_subform_getFontUnderline		(SObject* obj);
	bool					iiSubobj_subform_setFontStrikethrough	(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_subform_getFontStrikethrough	(SObject* obj);
	bool					iiSubobj_subform_setFontCondensed		(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_subform_getFontCondensed		(SObject* obj);
	bool					iiSubobj_subform_setFontExtended		(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_subform_getFontExtended		(SObject* obj);
	bool					iiSubobj_subform_setFontOutline			(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_subform_getFontOutline			(SObject* obj);
	bool					iiSubobj_subform_setFontShadow			(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_subform_getFontShadow			(SObject* obj);
	bool					iiSubobj_subform_setNwColor				(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_subform_getNwColor				(SObject* obj);
	bool					iiSubobj_subform_setNeColor				(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_subform_getNeColor				(SObject* obj);
	bool					iiSubobj_subform_setSwColor				(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_subform_getSwColor				(SObject* obj);
	bool					iiSubobj_subform_setSeColor				(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_subform_getSeColor				(SObject* obj);
	bool					iiSubobj_subform_setBackColor			(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_subform_getBackColor			(SObject* obj);
	bool					iiSubobj_subform_setForeColor			(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_subform_getForeColor			(SObject* obj);
	bool					iiSubobj_subform_setCaptionColor		(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_subform_getCaptionColor		(SObject* obj);
	bool					iiSubobj_subform_setCaption				(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_subform_getCaption				(SObject* obj);
	bool					iiSubobj_subform_setPicture				(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_subform_getPicture				(SObject* obj);
	bool					iiSubobj_subform_setAllowOutput			(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_subform_getAllowOutput			(SObject* obj);
	bool					iiSubobj_subform_setBorderStyle			(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_subform_getBorderStyle			(SObject* obj);
	bool					iiSubobj_subform_setProcessKeyPreviewEvents(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_subform_getProcessKeyPreviewEvents(SObject* obj);
	bool					iiSubobj_subform_setScaleMode			(SObject* obj, SVariable* var);
	bool					iiSubobj_subform_setScaleMode_extraTest	(s32 value);
	SVariable*				iiSubobj_subform_getScaleMode			(SObject* obj);
	bool					iiSubobj_subform_setWindowState			(SObject* obj, SVariable* var);
	SVariable*				iiSubobj_subform_getWindowState			(SObject* obj);
