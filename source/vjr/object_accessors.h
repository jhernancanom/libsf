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
	void					iiSubobj_subform_setIcon				(SObject* obj, SBitmap* bmp);
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









//////////
// Property translation text name to property value
//////
	SPropertyList gsBaseObjectProperties[] = {
		{	cgcName_parent,					sizeof(cgcName_parent) - 1,					(u32)&iObj_setError,							(u32)&iObj_getProperty_parent				},
		{	cgcName_tabIndex,				sizeof(cgcName_tabIndex) - 1,				(u32)&iObj_setProperty_tabIndex,				(u32)&iObj_getProperty_tabIndex				},
		{	cgcName_tabStop,				sizeof(cgcName_tabStop) - 1,				(u32)&iObj_setProperty_tabStop,					(u32)&iObj_getProperty_tabStop				},
		{	cgcName_helpContextId,			sizeof(cgcName_helpContextId) - 1,			(u32)&iObj_setProperty_helpContextId,			(u32)&iObj_getProperty_helpContextId		},
		{	cgcName_hasWhatsThisButton,		sizeof(cgcName_hasWhatsThisButton) - 1,		(u32)&iObj_setProperty_hasWhatsThisButton,		(u32)&iObj_getProperty_hasWhatsThisButton	},
		{	cgcName_hasWhatsThisHelp,		sizeof(cgcName_hasWhatsThisHelp) - 1,		(u32)&iObj_setProperty_hasWhatsThisHelp,		(u32)&iObj_getProperty_hasWhatsThisHelp		},
		{	cgcName_whatsThisHelpId,		sizeof(cgcName_whatsThisHelpId) - 1,		(u32)&iObj_setProperty_whatsThisHelpId,			(u32)&iObj_getProperty_whatsThisHelpId		},
		{	cgcName_name,					sizeof(cgcName_name) - 1,					(u32)&iObj_setProperty_name,					(u32)&iObj_getProperty_name					},
		{	cgcName_className,				sizeof(cgcName_className) - 1,				(u32)&iObj_setError,							(u32)&iObj_getProperty_className			},
		{	cgcName_classLibrary,			sizeof(cgcName_classLibrary) - 1,			(u32)&iObj_setError,							(u32)&iObj_getProperty_classLibrary			},
		{	cgcName_comment,				sizeof(cgcName_comment) - 1,				(u32)&iObj_setProperty_comment,					(u32)&iObj_getProperty_comment				},
		{	cgcName_toolTip,				sizeof(cgcName_toolTip) - 1,				(u32)&iObj_setProperty_toolTip,					(u32)&iObj_getProperty_toolTip				},
		{	cgcName_tag,					sizeof(cgcName_tag) - 1,					(u32)&iObj_setProperty_tag,						(u32)&iObj_getProperty_tag					},
		{	cgcName_mousePointer,			sizeof(cgcName_mousePointer) - 1,			(u32)&iObj_setProperty_mousePointer,			(u32)&iObj_getProperty_mousePointer			},
		{	cgcName_isEnabled,				sizeof(cgcName_isEnabled) - 1,				(u32)&iObj_setProperty_isEnabled,				(u32)&iObj_getProperty_isEnabled			},
		{	cgcName_hasFocus,				sizeof(cgcName_hasFocus) - 1,				(u32)&iObj_setProperty_hasFocus,				(u32)&iObj_getProperty_hasFocus				},
		{	cgcName_isMovable,				sizeof(cgcName_isMovable) - 1,				(u32)&iObj_setProperty_isMovable,				(u32)&iObj_getProperty_isMovable			},
		{	cgcName_isRendered,				sizeof(cgcName_isRendered) - 1,				(u32)&iObj_setProperty_isRendered,				(u32)&iObj_getProperty_isRendered			},
		{	cgcName_isPublished,			sizeof(cgcName_isPublished) - 1,			(u32)&iObj_setProperty_isPublished,				(u32)&iObj_getProperty_isPublished			},
		{	cgcName_isVisible,				sizeof(cgcName_isVisible) - 1,				(u32)&iObj_setProperty_isVisible,				(u32)&iObj_getProperty_isVisible			},
		{	cgcName_isDirty,				sizeof(cgcName_isDirty) - 1,				(u32)&iObj_setProperty_isDirty,					(u32)&iObj_getProperty_isDirty				},
		{	cgcName_left,					sizeof(cgcName_left) - 1,					(u32)&iObj_setProperty_left,					(u32)&iObj_getProperty_left					},
		{	cgcName_top,					sizeof(cgcName_top) - 1,					(u32)&iObj_setProperty_top,						(u32)&iObj_getProperty_top					},
		{	cgcName_width,					sizeof(cgcName_width) - 1,					(u32)&iObj_setProperty_width,					(u32)&iObj_getProperty_width				},
		{	cgcName_height,					sizeof(cgcName_height) - 1,					(u32)&iObj_setProperty_height,					(u32)&iObj_getProperty_height				},
		{	cgcName_anchor,					sizeof(cgcName_anchor) - 1,					(u32)&iObj_setProperty_anchor,					(u32)&iObj_getProperty_anchor				},
		{	cgcName_scrollX,				sizeof(cgcName_scrollX) - 1,				(u32)&iObj_setProperty_scrollX,					(u32)&iObj_getProperty_scrollX				},
		{	cgcName_scrollY,				sizeof(cgcName_scrollY) - 1,				(u32)&iObj_setProperty_scrollY,					(u32)&iObj_getProperty_scrollY				},
		{	cgcName_scaleX,					sizeof(cgcName_scaleX) - 1,					(u32)&iObj_setProperty_scaleX,					(u32)&iObj_getProperty_scaleX				},
		{	cgcName_scaleY,					sizeof(cgcName_scaleY) - 1,					(u32)&iObj_setProperty_scaleY,					(u32)&iObj_getProperty_scaleY				},
		// Note:  Do not delete this line, it is used to terminate the search list
		{	0, 0, 0, 0	}
	};

	SPropertyList gsEmptyProperties[] = {
//		{	cgcName_parent,					sizeof(cgcName_parent) - 1,					(u32)&iObj_setError,							(u32)&iObj_getProperty_parent				},
		// Note:  Do not delete this line, it is used to terminate the search list
		{	0, 0, 0, 0	}
	};

	SPropertyList gsFormProperties[] = {
		{	cgcName_minLeft,				sizeof(cgcName_minLeft) - 1,				(u32)&iiSubobj_form_setMinLeft,                  (u32)&iiSubobj_form_getMinLeft					},
		{	cgcName_minTop,					sizeof(cgcName_minTop) - 1,					(u32)&iiSubobj_form_setMinTop,                   (u32)&iiSubobj_form_getMinTop					},
		{	cgcName_minWidth,				sizeof(cgcName_minWidth) - 1,				(u32)&iiSubobj_form_setMinWidth,                 (u32)&iiSubobj_form_getMinWidth				},
		{	cgcName_minHeight,				sizeof(cgcName_minHeight) - 1,				(u32)&iiSubobj_form_setMinHeight,                (u32)&iiSubobj_form_getMinHeight				},
		{	cgcName_maxLeft,				sizeof(cgcName_maxLeft) - 1,				(u32)&iiSubobj_form_setMaxLeft,                  (u32)&iiSubobj_form_getMaxLeft					},
		{	cgcName_maxTop,					sizeof(cgcName_maxTop) - 1,					(u32)&iiSubobj_form_setMaxTop,                   (u32)&iiSubobj_form_getMaxTop					},
		{	cgcName_maxWidth,				sizeof(cgcName_maxWidth) - 1,				(u32)&iiSubobj_form_setMaxWidth,                 (u32)&iiSubobj_form_getMaxWidth				},
		{	cgcName_maxHeight,				sizeof(cgcName_maxHeight) - 1,				(u32)&iiSubobj_form_setMaxHeight,                (u32)&iiSubobj_form_getMaxHeight				},
		{	cgcName_fontName,				sizeof(cgcName_fontName) - 1,				(u32)&iiSubobj_form_setFontName,                 (u32)&iiSubobj_form_getFontName				},
		{	cgcName_fontSize,				sizeof(cgcName_fontSize) - 1,				(u32)&iiSubobj_form_setFontSize,                 (u32)&iiSubobj_form_getFontSize				},
		{	cgcName_fontBold,				sizeof(cgcName_fontBold) - 1,				(u32)&iiSubobj_form_setFontBold,                 (u32)&iiSubobj_form_getFontBold				},
		{	cgcName_fontItalic,				sizeof(cgcName_fontItalic) - 1,				(u32)&iiSubobj_form_setFontItalic,               (u32)&iiSubobj_form_getFontItalic				},
		{	cgcName_fontUnderline,			sizeof(cgcName_fontUnderline) - 1,			(u32)&iiSubobj_form_setFontUnderline,            (u32)&iiSubobj_form_getFontUnderline			},
		{	cgcName_fontStrikethrough,		sizeof(cgcName_fontStrikethrough) - 1,		(u32)&iiSubobj_form_setFontStrikethrough,        (u32)&iiSubobj_form_getFontStrikethrough		},
		{	cgcName_fontCondensed,			sizeof(cgcName_fontCondensed) - 1,			(u32)&iiSubobj_form_setFontCondensed,            (u32)&iiSubobj_form_getFontCondensed			},
		{	cgcName_fontExtended,			sizeof(cgcName_fontExtended) - 1,			(u32)&iiSubobj_form_setFontExtended,             (u32)&iiSubobj_form_getFontExtended			},
		{	cgcName_fontOutline,			sizeof(cgcName_fontOutline) - 1,			(u32)&iiSubobj_form_setFontOutline,              (u32)&iiSubobj_form_getFontOutline				},
		{	cgcName_fontShadow,				sizeof(cgcName_fontShadow) - 1,				(u32)&iiSubobj_form_setFontShadow,               (u32)&iiSubobj_form_getFontShadow				},
		{	cgcName_nwColor,				sizeof(cgcName_nwColor) - 1,				(u32)&iiSubobj_form_setNwColor,                  (u32)&iiSubobj_form_getNwColor					},
		{	cgcName_neColor,				sizeof(cgcName_neColor) - 1,				(u32)&iiSubobj_form_setNeColor,                  (u32)&iiSubobj_form_getNeColor					},
		{	cgcName_swColor,				sizeof(cgcName_swColor) - 1,				(u32)&iiSubobj_form_setSwColor,                  (u32)&iiSubobj_form_getSwColor					},
		{	cgcName_seColor,				sizeof(cgcName_seColor) - 1,				(u32)&iiSubobj_form_setSeColor,                  (u32)&iiSubobj_form_getSeColor					},
		{	cgcName_backColor,				sizeof(cgcName_backColor) - 1,				(u32)&iiSubobj_form_setBackColor,                (u32)&iiSubobj_form_getBackColor				},
		{	cgcName_foreColor,				sizeof(cgcName_foreColor) - 1,				(u32)&iiSubobj_form_setForeColor,                (u32)&iiSubobj_form_getForeColor				},
		{	cgcName_captionColor,			sizeof(cgcName_captionColor) - 1,			(u32)&iiSubobj_form_setCaptionColor,             (u32)&iiSubobj_form_getCaptionColor			},
		{	cgcName_caption,				sizeof(cgcName_caption) - 1,				(u32)&iiSubobj_form_setCaption,                  (u32)&iiSubobj_form_getCaption					},
		{	cgcName_picture,				sizeof(cgcName_picture) - 1,				(u32)&iiSubobj_form_setPicture,                  (u32)&iiSubobj_form_getPicture					},
		{	cgcName_allowOutput,			sizeof(cgcName_allowOutput) - 1,			(u32)&iiSubobj_form_setAllowOutput,              (u32)&iiSubobj_form_getAllowOutput				},
		{	cgcName_alwaysOnBottom,			sizeof(cgcName_alwaysOnBottom) - 1,			(u32)&iiSubobj_form_setAlwaysOnBottom,           (u32)&iiSubobj_form_getAlwaysOnBottom			},
		{	cgcName_alwaysOnTop,			sizeof(cgcName_alwaysOnTop) - 1,			(u32)&iiSubobj_form_setAlwaysOnTop,              (u32)&iiSubobj_form_getAlwaysOnTop				},
		{	cgcName_autoCenter,				sizeof(cgcName_autoCenter) - 1,				(u32)&iiSubobj_form_setAutoCenter,               (u32)&iiSubobj_form_getAutoCenter				},
		{	cgcName_borderStyle,			sizeof(cgcName_borderStyle) - 1,			(u32)&iiSubobj_form_setBorderStyle,              (u32)&iiSubobj_form_getBorderStyle				},
		{	cgcName_isCloseable,			sizeof(cgcName_isCloseable) - 1,			(u32)&iiSubobj_form_setIsCloseable,              (u32)&iiSubobj_form_getIsCloseable				},
		{	cgcName_processKeyPreviewEvents,sizeof(cgcName_processKeyPreviewEvents) - 1,(u32)&iiSubobj_form_setProcessKeyPreviewEvents,  (u32)&iiSubobj_form_getProcessKeyPreviewEvents	},
		{	cgcName_hasControlBox,			sizeof(cgcName_hasControlBox) - 1,			(u32)&iiSubobj_form_setHasControlBox,            (u32)&iiSubobj_form_getHasControlBox			},
		{	cgcName_hasMinButton,			sizeof(cgcName_hasMinButton) - 1,			(u32)&iiSubobj_form_setHasMinButton,             (u32)&iiSubobj_form_getHasMinButton			},
		{	cgcName_hasCloseButton,			sizeof(cgcName_hasCloseButton) - 1,			(u32)&iiSubobj_form_setHasCloseButton,           (u32)&iiSubobj_form_getHasCloseButton			},
		{	cgcName_scaleMode,				sizeof(cgcName_scaleMode) - 1,				(u32)&iiSubobj_form_setScaleMode,                (u32)&iiSubobj_form_getScaleMode				},
		{	cgcName_showInTaskBar,			sizeof(cgcName_showInTaskBar) - 1,			(u32)&iiSubobj_form_setShowInTaskBar,            (u32)&iiSubobj_form_getShowInTaskBar			},
		{	cgcName_windowState,			sizeof(cgcName_windowState) - 1,			(u32)&iiSubobj_form_setWindowState,              (u32)&iiSubobj_form_getWindowState				},
		{	cgcName_bindControls,			sizeof(cgcName_bindControls) - 1,			(u32)&iiSubobj_form_setBindControls,             (u32)&iiSubobj_form_getBindControls			},
		{	cgcName_bufferMode,				sizeof(cgcName_bufferMode) - 1,				(u32)&iiSubobj_form_setBufferMode,               (u32)&iiSubobj_form_getBufferMode				},
		{	cgcName_clipControls,			sizeof(cgcName_clipControls) - 1,			(u32)&iiSubobj_form_setClipControls,             (u32)&iiSubobj_form_getClipControls			},
		{	cgcName_colorSource,			sizeof(cgcName_colorSource) - 1,			(u32)&iiSubobj_form_setColorSource,              (u32)&iiSubobj_form_getColorSource				},
		{	cgcName_continuousScroll,		sizeof(cgcName_continuousScroll) - 1,		(u32)&iiSubobj_form_setContinuousScroll,         (u32)&iiSubobj_form_getContinuousScroll		},
		{	cgcName_dataSession,			sizeof(cgcName_dataSession) - 1,			(u32)&iiSubobj_form_setDataSession,              (u32)&iiSubobj_form_getDataSession				},
		{	cgcName_dataSessionId,			sizeof(cgcName_dataSessionId) - 1,			(u32)&iiSubobj_form_setDataSessionId,            (u32)&iiSubobj_form_getDataSessionId			},
		{	cgcName_deClass,				sizeof(cgcName_deClass) - 1,				(u32)&iiSubobj_form_setDeClass,                  (u32)&iiSubobj_form_getDeClass					},
		{	cgcName_deClassLibrary,			sizeof(cgcName_deClassLibrary) - 1,			(u32)&iiSubobj_form_setDeClassLibrary,           (u32)&iiSubobj_form_getDeClassLibrary			},
		{	cgcName_defOleCid,				sizeof(cgcName_defOleCid) - 1,				(u32)&iiSubobj_form_setDefOleCid,                (u32)&iiSubobj_form_getDefOleCid				},
		{	cgcName_desktop,				sizeof(cgcName_desktop) - 1,				(u32)&iiSubobj_form_setDesktop,                  (u32)&iiSubobj_form_getDesktop					},
		{	cgcName_isDockable,				sizeof(cgcName_isDockable) - 1,				(u32)&iiSubobj_form_setIsDockable,               (u32)&iiSubobj_form_getIsDockable				},
		{	cgcName_isDocked,				sizeof(cgcName_isDocked) - 1,				(u32)&iiSubobj_form_setIsDocked,                 (u32)&iiSubobj_form_getIsDocked				},
		{	cgcName_dockPosition,			sizeof(cgcName_dockPosition) - 1,			(u32)&iiSubobj_form_setDockPosition,             (u32)&iiSubobj_form_getDockPosition			},
		{	cgcName_drawMode,				sizeof(cgcName_drawMode) - 1,				(u32)&iiSubobj_form_setDrawMode,                 (u32)&iiSubobj_form_getDrawMode				},
		{	cgcName_drawStyle,				sizeof(cgcName_drawStyle) - 1,				(u32)&iiSubobj_form_setDrawStyle,                (u32)&iiSubobj_form_getDrawStyle				},
		{	cgcName_drawWidth,				sizeof(cgcName_drawWidth) - 1,				(u32)&iiSubobj_form_setDrawWidth,                (u32)&iiSubobj_form_getDrawWidth				},
		{	cgcName_fillColor,				sizeof(cgcName_fillColor) - 1,				(u32)&iiSubobj_form_setFillColor,                (u32)&iiSubobj_form_getFillColor				},
		{	cgcName_fillStyle,				sizeof(cgcName_fillStyle) - 1,				(u32)&iiSubobj_form_setFillStyle,                (u32)&iiSubobj_form_getFillStyle				},
		{	cgcName_halfHeightCaption,		sizeof(cgcName_halfHeightCaption) - 1,		(u32)&iiSubobj_form_setHalfHeightCaption,        (u32)&iiSubobj_form_getHalfHeightCaption		},
		{	cgcName_hScrollSmallChange,		sizeof(cgcName_hScrollSmallChange) - 1,		(u32)&iiSubobj_form_setHScrollSmallChange,       (u32)&iiSubobj_form_getHScrollSmallChange		},
		{	cgcName_vScrollSmallChange,		sizeof(cgcName_vScrollSmallChange) - 1,		(u32)&iiSubobj_form_setVScrollSmallChange,       (u32)&iiSubobj_form_getVScrollSmallChange		},
		{	cgcName_macDesktop,				sizeof(cgcName_macDesktop) - 1,				(u32)&iiSubobj_form_setMacDesktop,               (u32)&iiSubobj_form_getMacDesktop				},
		{	cgcName_mdiForm,				sizeof(cgcName_mdiForm) - 1,				(u32)&iiSubobj_form_setMdiForm,                  (u32)&iiSubobj_form_getMdiForm					},
		{	cgcName_oleDragMode,			sizeof(cgcName_oleDragMode) - 1,			(u32)&iiSubobj_form_setOleDragMode,              (u32)&iiSubobj_form_getOleDragMode				},
		{	cgcName_oleDragPicture,			sizeof(cgcName_oleDragPicture) - 1,			(u32)&iObj_setError,							(u32)&iObj_getError								},
		{	cgcName_oleDropEffects,			sizeof(cgcName_oleDropEffects) - 1,			(u32)&iiSubobj_form_setOleDropEffects,           (u32)&iiSubobj_form_getOleDropEffects			},
		{	cgcName_oleDropHasData,			sizeof(cgcName_oleDropHasData) - 1,			(u32)&iiSubobj_form_setOleDropHasData,           (u32)&iiSubobj_form_getOleDropHasData			},
		{	cgcName_oleDropMode,			sizeof(cgcName_oleDropMode) - 1,			(u32)&iiSubobj_form_setOleDropMode,              (u32)&iiSubobj_form_getOleDropMode				},
		{	cgcName_releaseType,			sizeof(cgcName_releaseType) - 1,			(u32)&iiSubobj_form_setReleaseType,              (u32)&iiSubobj_form_getReleaseType				},
		{	cgcName_rightToLeft,			sizeof(cgcName_rightToLeft) - 1,			(u32)&iiSubobj_form_setRightToLeft,              (u32)&iiSubobj_form_getRightToLeft				},
		{	cgcName_scrollbars,				sizeof(cgcName_scrollbars) - 1,				(u32)&iiSubobj_form_setScrollbars,               (u32)&iiSubobj_form_getScrollbars				},
		{	cgcName_showTips,				sizeof(cgcName_showTips) - 1,				(u32)&iiSubobj_form_setShowTips,                 (u32)&iiSubobj_form_getShowTips				},
		{	cgcName_showWindow,				sizeof(cgcName_showWindow) - 1,				(u32)&iiSubobj_form_setShowWindow,               (u32)&iiSubobj_form_getShowWindow				},
		{	cgcName_sizeBox,				sizeof(cgcName_sizeBox) - 1,				(u32)&iiSubobj_form_setSizeBox,                  (u32)&iiSubobj_form_getSizeBox					},
		{	cgcName_themes,					sizeof(cgcName_themes) - 1,					(u32)&iiSubobj_form_setThemes,                   (u32)&iiSubobj_form_getThemes					},
		{	cgcName_titleBar,				sizeof(cgcName_titleBar) - 1,				(u32)&iiSubobj_form_setTitleBar,                 (u32)&iiSubobj_form_getTitleBar				},
		{	cgcName_windowType,				sizeof(cgcName_windowType) - 1,				(u32)&iiSubobj_form_setWindowType,               (u32)&iiSubobj_form_getWindowType				},
		{	cgcName_zoomBox,				sizeof(cgcName_zoomBox) - 1,				(u32)&iiSubobj_form_setZoomBox,                  (u32)&iiSubobj_form_getZoomBox					},
		// Note:  Do not delete this line, it is used to terminate the search list
		{	0, 0, 0, 0	}
	};

	SPropertyList gsSubformProperties[] = {
		{	cgcName_minLeft,				sizeof(cgcName_minLeft) - 1,				(u32)&iiSubobj_subform_setMinLeft,                  (u32)&iiSubobj_subform_getMinLeft					},
		{	cgcName_minTop,					sizeof(cgcName_minTop) - 1,					(u32)&iiSubobj_subform_setMinTop,                   (u32)&iiSubobj_subform_getMinTop					},
		{	cgcName_minWidth,				sizeof(cgcName_minWidth) - 1,				(u32)&iiSubobj_subform_setMinWidth,                 (u32)&iiSubobj_subform_getMinWidth					},
		{	cgcName_minHeight,				sizeof(cgcName_minHeight) - 1,				(u32)&iiSubobj_subform_setMinHeight,                (u32)&iiSubobj_subform_getMinHeight					},
		{	cgcName_maxLeft,				sizeof(cgcName_maxLeft) - 1,				(u32)&iiSubobj_subform_setMaxLeft,                  (u32)&iiSubobj_subform_getMaxLeft					},
		{	cgcName_maxTop,					sizeof(cgcName_maxTop) - 1,					(u32)&iiSubobj_subform_setMaxTop,                   (u32)&iiSubobj_subform_getMaxTop					},
		{	cgcName_maxWidth,				sizeof(cgcName_maxWidth) - 1,				(u32)&iiSubobj_subform_setMaxWidth,                 (u32)&iiSubobj_subform_getMaxWidth					},
		{	cgcName_maxHeight,				sizeof(cgcName_maxHeight) - 1,				(u32)&iiSubobj_subform_setMaxHeight,                (u32)&iiSubobj_subform_getMaxHeight					},
		{	cgcName_fontName,				sizeof(cgcName_fontName) - 1,				(u32)&iiSubobj_subform_setFontName,                 (u32)&iiSubobj_subform_getFontName					},
		{	cgcName_fontSize,				sizeof(cgcName_fontSize) - 1,				(u32)&iiSubobj_subform_setFontSize,                 (u32)&iiSubobj_subform_getFontSize					},
		{	cgcName_fontBold,				sizeof(cgcName_fontBold) - 1,				(u32)&iiSubobj_subform_setFontBold,                 (u32)&iiSubobj_subform_getFontBold					},
		{	cgcName_fontItalic,				sizeof(cgcName_fontItalic) - 1,				(u32)&iiSubobj_subform_setFontItalic,               (u32)&iiSubobj_subform_getFontItalic				},
		{	cgcName_fontUnderline,			sizeof(cgcName_fontUnderline) - 1,			(u32)&iiSubobj_subform_setFontUnderline,            (u32)&iiSubobj_subform_getFontUnderline				},
		{	cgcName_fontStrikethrough,		sizeof(cgcName_fontStrikethrough) - 1,		(u32)&iiSubobj_subform_setFontStrikethrough,        (u32)&iiSubobj_subform_getFontStrikethrough			},
		{	cgcName_fontCondensed,			sizeof(cgcName_fontCondensed) - 1,			(u32)&iiSubobj_subform_setFontCondensed,            (u32)&iiSubobj_subform_getFontCondensed				},
		{	cgcName_fontExtended,			sizeof(cgcName_fontExtended) - 1,			(u32)&iiSubobj_subform_setFontExtended,             (u32)&iiSubobj_subform_getFontExtended				},
		{	cgcName_fontOutline,			sizeof(cgcName_fontOutline) - 1,			(u32)&iiSubobj_subform_setFontOutline,              (u32)&iiSubobj_subform_getFontOutline				},
		{	cgcName_fontShadow,				sizeof(cgcName_fontShadow) - 1,				(u32)&iiSubobj_subform_setFontShadow,               (u32)&iiSubobj_subform_getFontShadow				},
		{	cgcName_nwColor,				sizeof(cgcName_nwColor) - 1,				(u32)&iiSubobj_subform_setNwColor,                  (u32)&iiSubobj_subform_getNwColor					},
		{	cgcName_neColor,				sizeof(cgcName_neColor) - 1,				(u32)&iiSubobj_subform_setNeColor,                  (u32)&iiSubobj_subform_getNeColor					},
		{	cgcName_swColor,				sizeof(cgcName_swColor) - 1,				(u32)&iiSubobj_subform_setSwColor,                  (u32)&iiSubobj_subform_getSwColor					},
		{	cgcName_seColor,				sizeof(cgcName_seColor) - 1,				(u32)&iiSubobj_subform_setSeColor,                  (u32)&iiSubobj_subform_getSeColor					},
		{	cgcName_backColor,				sizeof(cgcName_backColor) - 1,				(u32)&iiSubobj_subform_setBackColor,                (u32)&iiSubobj_subform_getBackColor					},
		{	cgcName_foreColor,				sizeof(cgcName_foreColor) - 1,				(u32)&iiSubobj_subform_setForeColor,                (u32)&iiSubobj_subform_getForeColor					},
		{	cgcName_captionColor,			sizeof(cgcName_captionColor) - 1,			(u32)&iiSubobj_subform_setCaptionColor,             (u32)&iiSubobj_subform_getCaptionColor				},
		{	cgcName_caption,				sizeof(cgcName_caption) - 1,				(u32)&iiSubobj_subform_setCaption,                  (u32)&iiSubobj_subform_getCaption					},
		{	cgcName_picture,				sizeof(cgcName_picture) - 1,				(u32)&iiSubobj_subform_setPicture,                  (u32)&iiSubobj_subform_getPicture					},
		{	cgcName_allowOutput,			sizeof(cgcName_allowOutput) - 1,			(u32)&iiSubobj_subform_setAllowOutput,              (u32)&iiSubobj_subform_getAllowOutput				},
		{	cgcName_borderStyle,			sizeof(cgcName_borderStyle) - 1,			(u32)&iiSubobj_subform_setBorderStyle,              (u32)&iiSubobj_subform_getBorderStyle				},
		{	cgcName_processKeyPreviewEvents,sizeof(cgcName_processKeyPreviewEvents) - 1,(u32)&iiSubobj_subform_setProcessKeyPreviewEvents,  (u32)&iiSubobj_subform_getProcessKeyPreviewEvents	},
		{	cgcName_scaleMode,				sizeof(cgcName_scaleMode) - 1,				(u32)&iiSubobj_subform_setScaleMode,                (u32)&iiSubobj_subform_getScaleMode					},
		{	cgcName_windowState,			sizeof(cgcName_windowState) - 1,			(u32)&iiSubobj_subform_setWindowState,              (u32)&iiSubobj_subform_getWindowState				},
		// Note:  Do not delete this line, it is used to terminate the search list
		{	0, 0, 0, 0	}
	};

	SPropertyList gsLabelProperties[] = {
//		{	cgcName_parent,					sizeof(cgcName_parent) - 1,					(u32)&iObj_setError,							(u32)&iObj_getProperty_parent				},
		// Note:  Do not delete this line, it is used to terminate the search list
		{	0, 0, 0, 0	}
	};

	SPropertyList gsTextboxProperties[] = {
//		{	cgcName_parent,					sizeof(cgcName_parent) - 1,					(u32)&iObj_setError,							(u32)&iObj_getProperty_parent				},
		// Note:  Do not delete this line, it is used to terminate the search list
		{	0, 0, 0, 0	}
	};

	SPropertyList gsButtonProperties[] = {
//		{	cgcName_parent,					sizeof(cgcName_parent) - 1,					(u32)&iObj_setError,							(u32)&iObj_getProperty_parent				},
		// Note:  Do not delete this line, it is used to terminate the search list
		{	0, 0, 0, 0	}
	};

	SPropertyList gsEditboxProperties[] = {
//		{	cgcName_parent,					sizeof(cgcName_parent) - 1,					(u32)&iObj_setError,							(u32)&iObj_getProperty_parent				},
		// Note:  Do not delete this line, it is used to terminate the search list
		{	0, 0, 0, 0	}
	};

	SPropertyList gsImageProperties[] = {
//		{	cgcName_parent,					sizeof(cgcName_parent) - 1,					(u32)&iObj_setError,							(u32)&iObj_getProperty_parent				},
		// Note:  Do not delete this line, it is used to terminate the search list
		{	0, 0, 0, 0	}
	};

	SPropertyList gsCheckboxProperties[] = {
//		{	cgcName_parent,					sizeof(cgcName_parent) - 1,					(u32)&iObj_setError,							(u32)&iObj_getProperty_parent				},
		// Note:  Do not delete this line, it is used to terminate the search list
		{	0, 0, 0, 0	}
	};

	SPropertyList gsOptionProperties[] = {
//		{	cgcName_parent,					sizeof(cgcName_parent) - 1,					(u32)&iObj_setError,							(u32)&iObj_getProperty_parent				},
		// Note:  Do not delete this line, it is used to terminate the search list
		{	0, 0, 0, 0	}
	};

	SPropertyList gsRadioProperties[] = {
//		{	cgcName_parent,					sizeof(cgcName_parent) - 1,					(u32)&iObj_setError,							(u32)&iObj_getProperty_parent				},
		// Note:  Do not delete this line, it is used to terminate the search list
		{	0, 0, 0, 0	}
	};


//////////
// Baseclass translation text name to objType, and objType to full record
//////
	SBaseclassList gsKnownBaseclasses[] = {
		//	objType					Text name				Length of name						Base object property list			Sub-object property list
		//  ------------------		-----------------		-------------------------------		-------------------------------		---------------------------
		{	_OBJ_TYPE_EMPTY,		cgcName_empty,			sizeof(cgcName_empty)		- 1,	(u32)&gsBaseObjectProperties[0],	(u32)&gsEmptyProperties[0]		},
		{	_OBJ_TYPE_FORM,			cgcName_form,			sizeof(cgcName_form)		- 1,	(u32)&gsBaseObjectProperties[0],	(u32)&gsFormProperties[0]		},
		{	_OBJ_TYPE_SUBFORM,		cgcName_subform,		sizeof(cgcName_subform)		- 1,	(u32)&gsBaseObjectProperties[0],	(u32)&gsSubformProperties[0]	},
		{	_OBJ_TYPE_LABEL,		cgcName_label,			sizeof(cgcName_label)		- 1,	(u32)&gsBaseObjectProperties[0],	(u32)&gsLabelProperties[0]		},
		{	_OBJ_TYPE_TEXTBOX,		cgcName_textbox,		sizeof(cgcName_textbox)		- 1,	(u32)&gsBaseObjectProperties[0],	(u32)&gsTextboxProperties[0]	},
		{	_OBJ_TYPE_BUTTON,		cgcName_button,			sizeof(cgcName_button)		- 1,	(u32)&gsBaseObjectProperties[0],	(u32)&gsButtonProperties[0]		},
		{	_OBJ_TYPE_EDITBOX,		cgcName_editbox,		sizeof(cgcName_editbox)		- 1,	(u32)&gsBaseObjectProperties[0],	(u32)&gsEditboxProperties[0]	},
		{	_OBJ_TYPE_IMAGE,		cgcName_image,			sizeof(cgcName_image)		- 1,	(u32)&gsBaseObjectProperties[0],	(u32)&gsImageProperties[0]		},
		{	_OBJ_TYPE_CHECKBOX,		cgcName_checkbox,		sizeof(cgcName_checkbox)	- 1,	(u32)&gsBaseObjectProperties[0],	(u32)&gsCheckboxProperties[0]	},
		{	_OBJ_TYPE_OPTION,		cgcName_option,			sizeof(cgcName_option)		- 1,	(u32)&gsBaseObjectProperties[0],	(u32)&gsOptionProperties[0]		},
		{	_OBJ_TYPE_RADIO,		cgcName_radio,			sizeof(cgcName_radio)		- 1,	(u32)&gsBaseObjectProperties[0],	(u32)&gsRadioProperties[0]		},
		// Note:  Do not delete this line, it is used to terminate the search list
		{	0,						NULL,					0,									NULL,								NULL	}
	};
