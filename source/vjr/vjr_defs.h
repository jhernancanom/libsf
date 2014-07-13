//////////
//
// /libsf/source/vjr/vjr_defs.h
//
//////
// Version 0.31
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
//////
//
// Jun.17.2014
// Note:  The function definitions below use a naming convention to indicate some of
//        their functionality.  All functions prefixed with "i" are internal functions.
//        If you see one with "ii" or "iii" they bypass standard checks (like null pointers)
//        and are only called from the internal functions.  In general, always use the
//        "i" functions if you are unsure if something will be populated or not.  If you
//        have already tested it and know it's populated, then it is safe to call an "ii"
//        function.
//
//////
//
//




//////////
// vjr.cpp
//////
//	int APIENTRY			WinMain									(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, s32 nCmdShow);
	void					iInit_vjr								(HACCEL* hAccelTable);


//////////
// objects.cpp
//////
	SObject*				iObj_create								(u32 tnBaseType, void* obj_data);
	SObject*				iObj_copy								(SObject* template_obj, SObject* next, SObject* parent, bool tlCopyChildren, bool tlCopySubobjects, bool tlCreateSeparateBitmapBuffers);
	void					iObj_delete								(SObject** obj, bool tlDeleteSelf);
	u32						iObj_render								(SObject* obj, bool tlRenderChildren, bool tlRenderSiblings);
	void					iObj_renderChildrenAndSiblings			(SObject* obj, bool tlRenderChildren, bool tlRenderSiblings);
	u32						iObj_publish							(SBitmap* bmpDst, RECT* trc, SObject* obj, bool tlPublishChildren, bool tlPublishSiblings);
	void					iObj_duplicateChain						(SObject** root, SObject* chain);
	void					iObj_appendObjToParent					(SObject* parent, SObject* obj);
	void					iObj_duplicateChildren					(SObject* objDst, SObject* objSrc);
	void					iObj_setSize							(SObject* obj, s32 tnLeft, s32 tnTop, s32 tnWidth, s32 tnHeight);
	SWindow* 				iObj_createWindowForForm				(SObject* obj_form, SWindow* win, s32 icon);
	bool					iObj_setVisible							(SObject* obj, bool tlNewVisible);
	void*					iObj_copySubobj							(SObject* template_obj);
	SVariable*				iObj_getPropertyAsVariable				(SObject* obj, s8* tcPropertyName, u32 tnPropertyNameLength, SComp* comp);
	void					iiObj_resetToDefault					(SObject* obj, bool tlResetProperties, bool tlResetMethods);
	void					iiObj_resetToDefaultCommon				(SObject* obj, bool tlResetProperties, bool tlResetMethods);
	s32						iiObj_getBaseclass_byName				(s8* tcTextname, s32 tnTextnameLength);
	SBaseclassList*			iiObj_getBaseclass_byType				(u32 tnObjType);

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

	// Creation of individual sub-objects
	SSubObjEmpty*			iSubobj_createEmpty						(SSubObjEmpty*		template_subobj, SObject* parent);
	SSubObjForm*			iSubobj_createForm						(SSubObjForm*		template_subobj, SObject* parent);
	SSubObjSubform*			iSubobj_createSubform					(SSubObjSubform*	template_subobj, SObject* parent);
	SSubObjLabel*			iSubobj_createLabel						(SSubObjLabel*		template_subobj, SObject* parent);
	SSubObjTextbox*			iSubobj_createTextbox					(SSubObjTextbox*	template_subobj, SObject* parent);
	SSubObjButton*			iSubobj_createButton					(SSubObjButton*		template_subobj, SObject* parent);
	SSubObjEditbox*			iSubobj_createEditbox					(SSubObjEditbox*	template_subobj, SObject* parent);
	SSubObjImage*			iSubobj_createImage						(SSubObjImage*		template_subobj, SObject* parent);
	SSubObjCheckbox*		iSubobj_createCheckbox					(SSubObjCheckbox*	template_subobj, SObject* parent);
	SSubObjOption*			iSubobj_createOption					(SSubObjOption*		template_subobj, SObject* parent);
	SSubObjRadio*			iSubobj_createRadio						(SSubObjRadio*		template_subobj, SObject* parent);

	// For copy operations
	void					iiSubobj_copyEmpty						(SSubObjEmpty*		subobjDst,	SSubObjEmpty*		subobjSrc);
	void					iiSubobj_copyForm						(SSubObjForm*		subobjDst,	SSubObjForm*		subobjSrc);
	void					iiSubobj_copySubform					(SSubObjSubform*	subobjDst,	SSubObjSubform*		subobjSrc);
	void					iiSubobj_copyLabel						(SSubObjLabel*		subobjDst,	SSubObjLabel*		subobjSrc);
	void					iiSubobj_copyTextbox					(SSubObjTextbox*	subobjDst,	SSubObjTextbox*		subobjSrc);
	void					iiSubobj_copyButton						(SSubObjButton*		subobjDst,	SSubObjButton*		subobjSrc);
	void					iiSubobj_copyEditbox					(SSubObjEditbox*	subobjDst,	SSubObjEditbox*		subobjSrc);
	void					iiSubobj_copyImage						(SSubObjImage*		subobjDst,	SSubObjImage*		subobjSrc);
	void					iiSubobj_copyCheckbox					(SSubObjCheckbox*	subobjDst,	SSubObjCheckbox*	subobjSrc);
	void					iiSubobj_copyOption						(SSubObjOption*		subobjDst,	SSubObjOption*		subobjSrc);
	void					iiSubobj_copyRadio						(SSubObjRadio*		subobjDst,	SSubObjRadio*		subobjSrc);

	// For initialization
	void					iiSubobj_resetToDefaultEmpty			(SSubObjEmpty*		empty,		bool tlResetObject, bool tlResetProperties, bool tlResetMethods);
	void					iiSubobj_resetToDefaultForm				(SSubObjForm*		form,		bool tlResetObject, bool tlResetProperties, bool tlResetMethods);
	void					iiSubobj_resetToDefaultSubform			(SSubObjSubform*	subform,	bool tlResetObject, bool tlResetProperties, bool tlResetMethods);
	void					iiSubobj_resetToDefaultLabel			(SSubObjLabel*		label,		bool tlResetObject, bool tlResetProperties, bool tlResetMethods);
	void					iiSubobj_resetToDefaultTextbox			(SSubObjTextbox*	textbox,	bool tlResetObject, bool tlResetProperties, bool tlResetMethods);
	void					iiSubobj_resetToDefaultButton			(SSubObjButton*		button,		bool tlResetObject, bool tlResetProperties, bool tlResetMethods);
	void					iiSubobj_resetToDefaultEditbox			(SSubObjEditbox*	editbox,	bool tlResetObject, bool tlResetProperties, bool tlResetMethods);
	void					iiSubobj_resetToDefaultImage			(SSubObjImage*		image,		bool tlResetObject, bool tlResetProperties, bool tlResetMethods);
	void					iiSubobj_resetToDefaultCheckbox			(SSubObjCheckbox*	checkbox,	bool tlResetObject, bool tlResetProperties, bool tlResetMethods);
	void					iiSubobj_resetToDefaultOption			(SSubObjOption*		option,		bool tlResetObject, bool tlResetProperties, bool tlResetMethods);
	void					iiSubobj_resetToDefaultRadio			(SSubObjRadio*		radio,		bool tlResetObject, bool tlResetProperties, bool tlResetMethods);


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


	// Delete individual sub-objects
	void					iSubobj_deleteEmpty						(SSubObjEmpty*		empty,		bool tlDeleteSelf);
	void					iSubobj_deleteForm						(SSubObjForm*		form,		bool tlDeleteSelf);
	void					iSubobj_deleteSubform					(SSubObjSubform*	subform,	bool tlDeleteSelf);
	void					iSubobj_deleteLabel						(SSubObjLabel*		label,		bool tlDeleteSelf);
	void					iSubobj_deleteTextbox					(SSubObjTextbox*	textbox,	bool tlDeleteSelf);
	void					iSubobj_deleteButton					(SSubObjButton*		button,		bool tlDeleteSelf);
	void					iSubobj_deleteEditbox					(SSubObjEditbox*	editbox,	bool tlDeleteSelf);
	void					iSubobj_deleteImage						(SSubObjImage*		image,		bool tlDeleteSelf);
	void					iSubobj_deleteCheckbox					(SSubObjCheckbox*	checkbox,	bool tlDeleteSelf);
	void					iSubobj_deleteOption					(SSubObjOption*		option,		bool tlDeleteSelf);
	void					iSubobj_deleteRadio						(SSubObjRadio*		radio,		bool tlDeleteSelf);


	// Default render of sub-objects
	u32						iSubobj_renderEmpty						(SObject* obj,		SSubObjEmpty*		empty,		bool tlRenderChildren,	bool tlRenderSiblings);
	u32						iSubobj_renderForm						(SObject* obj,		SSubObjForm*		form,		bool tlRenderChildren,	bool tlRenderSiblings);
	u32						iSubobj_renderSubform					(SObject* obj,		SSubObjSubform*		subform,	bool tlRenderChildren,	bool tlRenderSiblings);
	u32						iSubobj_renderLabel						(SObject* obj,		SSubObjLabel*		label,		bool tlRenderChildren,	bool tlRenderSiblings);
	u32						iSubobj_renderTextbox					(SObject* obj,		SSubObjTextbox*		textbox,	bool tlRenderChildren,	bool tlRenderSiblings);
	u32						iSubobj_renderButton					(SObject* obj,		SSubObjButton*		button,		bool tlRenderChildren,	bool tlRenderSiblings);
	u32						iSubobj_renderEditbox					(SObject* obj,		SSubObjEditbox*		editbox,	bool tlRenderChildren,	bool tlRenderSiblings);
	u32						iSubobj_renderImage						(SObject* obj,		SSubObjImage*		image,		bool tlRenderChildren,	bool tlRenderSiblings);
	u32						iSubobj_renderCheckbox					(SObject* obj,		SSubObjCheckbox*	checkbox,	bool tlRenderChildren,	bool tlRenderSiblings);
	u32						iSubobj_renderOption					(SObject* obj,		SSubObjOption*		option,		bool tlRenderChildren,	bool tlRenderSiblings);
	u32						iSubobj_renderRadio						(SObject* obj,		SSubObjRadio*		radio,		bool tlRenderChildren,	bool tlRenderSiblings);


//////////
// callbacks.cpp
//////
	bool					iDefaultCallback_onLoad					(SObject* o);
	bool					iDefaultCallback_onInit					(SObject* o);
	bool					iDefaultCallback_onCreated				(SObject* o);
	bool					iDefaultCallback_onResize				(SObject* o, u32* widthRequired_out, u32* heightRequired_out);
	bool					iDefaultCallback_onRender				(SObject* o);
	bool					iDefaultCallback_onPublish				(SObject* o);
	bool					iDefaultCallback_onDestroy				(SObject* o);
	bool					iDefaultCallback_onUnload				(SObject* o);
	bool					iDefaultCallback_onGotFocus				(SObject* o);
	bool					iDefaultCallback_onLostFocus			(SObject* o);
	bool					iDefaultCallback_onMouseClickEx			(SObject* o, u32 x, u32 y, bool tlCtrl, bool tlAlt, bool tlShift, u32 tnClick);
	bool					iDefaultCallback_onMouseWheel			(SObject* o, s32 tnUnits);
	bool					iDefaultCallback_onMouseMove			(SObject* o, u32 x, u32 y, bool tlCtrl, bool tlAlt, bool tlShift, u32 tnClick);
	bool					iDefaultCallback_onMouseDown			(SObject* o, u32 x, u32 y, bool tlCtrl, bool tlAlt, bool tlShift, u32 tnClick, u32 tnLastClick);
	bool					iDefaultCallback_onMouseUp				(SObject* o, u32 x, u32 y, bool tlCtrl, bool tlAlt, bool tlShift, u32 tnClick, u32 tnLastClick);
	bool					iDefaultCallback_onMouseEnter			(SObject* o);
	bool					iDefaultCallback_onMouseLeave			(SObject* o);
	bool					iDefaultCallback_onMouseHover			(SObject* o, u32 x, u32 y, bool tlCtrl, bool tlAlt, bool tlShift, u32 tnClick);
	bool					iDefaultCallback_onKeyDown				(SObject* o, bool tlCtrl, bool tlAlt, bool tlShift, s16 tcAscii, u16 tnVKey, bool tlIsCAS, bool tlIsAscii);
	bool					iDefaultCallback_onKeyUp				(SObject* o, bool tlCtrl, bool tlAlt, bool tlShift, s16 tcAscii, u16 tnVKey, bool tlIsCAS, bool tlIsAscii);
	bool					iDefaultCallback_onActivate				(SObject* o);
	bool					iDefaultCallback_onDeactivate			(SObject* o);
	bool					iDefaultCallback_onInteractiveChange	(SObject* o);
	bool					iDefaultCallback_onProgrammaticChange	(SObject* o);
	bool					iDefaultCallback_onSelect				(SObject* o, SObject* oItem);
	bool					iDefaultCallback_onDeselect				(SObject* o, SObject* oItem);
	bool					iDefaultCallback_onMoved				(SObject* o, u32* xOverride_out, u32* yOverride_out);
	bool					iDefaultCallback_onQueryUnload			(SObject* o);
	bool					iDefaultCallback_onAddObject			(SObject* o);
	bool					iDefaultCallback_onAddProperty			(SObject* o);
	bool					iDefaultCallback_onError				(SObject* o);
	bool					iDefaultCallback_onScrolled				(SObject* o);


//////////
// events.cpp
//////
	void					iEvents_resetToDefault					(SEvents* ev);



//////////
// vjr_sup.cpp
//////
	void					iInit_createMessageWindow				(void);
	bool					isValidWindow							(u32 tnWindow);
	void					iInit_createDefaultObjects				(void);
	void					iInit_create_screenObject				(void);
	void					iInit_create_jdebiObject				(void);
	void					iInit_createDefaultDatetimes			(void);

	DWORD	WINAPI			iReadEvents_messageWindow				(LPVOID lpParameter);
	LRESULT	CALLBACK		iMessage_wndProcWindow					(HWND hwnd, UINT m, WPARAM w, LPARAM l);
	LRESULT	CALLBACK		iWindow_wndProc							(HWND hwnd, UINT m, WPARAM w, LPARAM l);
	SWindow* 				iWindow_createForObject					(SObject* obj, SWindow* win, s32 icon);
	SWindow*				iWindow_findByHwnd						(HWND hwnd);
	SWindow*				iWindow_allocate						(void);
	void					iWindow_render							(SWindow* win);
	void					iColor_adjustBrightness					(SBgra& color, f32 tfPercent);
	bool					iInit_shutdownPolitely					(void);

	void					iComputeScreenWindowClientAreaDimensions	(SSize* size);
	void					iComputeScreenWindowNonclientAreaDimensions	(SSize* size);
	void					iAdjustScreenWindowDimensions				(SSize* size);
	void					iComputeJDebiWindowClientAreaDimensions		(SSize* size);
	void					iComputeJDebiWindowNonclientAreaDimensions	(SSize* size);
	void					iAdjustJDebiWindowDimensions				(SSize* size);

	s64						iTime_computeMilliseconds				(SYSTEMTIME* time);
	s64						iTime_getSystemMs						(void);
	s64						iTime_getLocalMs						(void);
	s64						iMath_delta								(s64 tnBaseValue, s64 tnSubtractionValue);
	s8*						iDuplicateString						(s8* tcText);
	SFont*					iFont_allocate							(void);
	SFont*					iFont_duplicate							(SFont* fontSource);
	SFont*					iFont_create							(cs8* tcFontName, u32 tnFontSize, u32 tnFontWeight, u32 tnItalics, u32 tnUnderline);
	void					iiFont_refresh							(SFont* font);
	void					iFont_delete							(SFont** font, bool tlDeleteSelf);
	u32						iFont_findClosestSizeMatch				(s8* tcText, s8* tcFontName, u32 tnFontSize, u32 tnFontBold, u32 tnFontItalic, u32 tnFontUnderline, u32 tnWidth, u32 tnHeight, u32 tnWidthDesired, u32 tnHeightDesired);

	// Mouse processing (callback from iWindow_wndProc()
	s32						iMouse_processMessage					(SWindow* win, UINT m, WPARAM w, LPARAM l);
	void					iiMouse_translatePosition				(SWindow* win, POINTS* pt);
	s32						iiMouse_processMouseEvents_client		(SWindow* win, UINT m, WPARAM w, LPARAM l);
	s32						iiMouse_processMouseEvents_nonclient	(SWindow* win, UINT m, WPARAM w, LPARAM l);
	void					iiMouse_getFlags						(bool* tlCtrl, bool* tlAlt, bool* tlShift, bool* tlLeft, bool* tlMiddle, bool* tlRight, bool* tlCaps);

	// For processing keystrokes
	s32						iKeyboard_processMessage				(SWindow* win, UINT m, WPARAM w, LPARAM l);

	// EditChainManager
	// Moved to edit_chain_manager.cpp

	// Edit Chain
	// Moved to edit_chain.cpp

	// Engine
	// Moved to engine.cpp

	// Translate
	void*					iTranslate_p1_to_p2						(SBuilder* root, void* ptr);
	void*					iTranslate_p2_to_p1						(SBuilder* root, void* ptr);

	// ExtraInfo
	void					iExtraInfo_free							(SEditChainManager* ecm, SEditChain* ec, SExtraInfo** root, bool tlDeleteSelf);

	// Datum
	void					iDatum_allocateSpace					(SDatum* datum,            s32 dataLength);
	SDatum*					iDatum_allocate							(                s8* data, s32 dataLength);
	void					iDatum_duplicate						(SDatum* datum,  s8* data, s32 dataLength);
	void					iDatum_duplicate						(SDatum* datum, cs8* data, s32 dataLength);
	void					iDatum_duplicate						(SDatum* datumDst, SDatum* datumSrc);
	bool					iDatum_resize							(SDatum* datum, s32 newDataLength);
	s32						iDatum_compare							(SDatum* datumLeft, SDatum* datumRight);
	void					iDatum_delete							(SDatum* datum, bool tlDeleteSelf);
	void					iiDatum_delete							(SDatum* datum);


//////////
// bitmaps.cpp
//////
	SBitmap*				iBmp_allocate							(void);
	SBitmap*				iBmp_copy								(SBitmap* bmpSrc);
	SBitmap*				iBmp_verifyCopyIsSameSize				(SBitmap* bmpCopy, SBitmap* bmp);
	SBitmap*				iBmp_verifySizeOrResize					(SBitmap* bmp, u32 tnWidth, u32 tnHeight);
	SBitmap*				iBmp_rawLoad							(cu8* bmpRawFileData);
	void					iBmp_convertTo32Bits					(SBitmap* bmp);
	void					iBmp_copy24To32							(SBitmap* bmp32, SBitmap* bmp24);
	bool					iBmp_validate							(SBitmap* bmp);
	s32						iBmp_computeRowWidth					(SBitmap* bmp);
	void					iBmp_createBySize						(SBitmap* bmp, u32 width, u32 height, u32 tnBitCount);
	void					iBmp_populateBitmapStructure			(SBitmap* bmp, u32 tnWidth, u32 tnHeight, u32 tnBitCount);
	void					iBmp_delete								(SBitmap** bmp, bool tlFreeBits, bool tlDeleteSelf);
	void					iBmp_invert								(SBitmap* bmp, s32 tnUlX, s32 tnUlY, s32 tnLrX, s32 tnLrY);
	void					iBmp_bitBltObject						(SBitmap* bmpDst, SObject* obj, SBitmap* bmpSrc);
	void					iBmp_bitBltObjectMask					(SBitmap* bmpDst, SObject* obj, SBitmap* bmpSrc);
	u32						iBmp_bitBlt								(SBitmap* bmpDst, RECT* trc, SBitmap* bmpSrc);
// TODO:  The following void functions need to be changed to u32 and indicate how many pixels were rendered
	void					iBmp_bitBltMask							(SBitmap* bmpDst, RECT* trc, SBitmap* bmpSrc);
	void					iBmp_drawPoint							(SBitmap* bmp, s32 tnX, s32 tnY, SBgra color);
	void					iBmp_fillRect							(SBitmap* bmp, RECT* rc, SBgra colorNW, SBgra colorNE, SBgra colorSW, SBgra colorSE, bool tlUseGradient);
	void					iBmp_frameRect							(SBitmap* bmp, RECT* rc, SBgra colorNW, SBgra colorNE, SBgra colorSW, SBgra colorSE, bool tlUseGradient);
	void					iBmp_drawHorizontalLine					(SBitmap* bmp, s32 tnX1, s32 tnX2, s32 tnY, SBgra color);
	void					iBmp_drawVerticalLine					(SBitmap* bmp, s32 tnY1, s32 tnY2, s32 tnX, SBgra color);
	void					iBmp_drawHorizontalLineGradient			(SBitmap* bmp, s32 tnX1, s32 tnX2, s32 tnY, f32 tfRed, f32 tfGrn, f32 tfBlu, f32 tfRedInc, f32 tfGrnInc, f32 tfBluInc);
	void					iBmp_drawVerticalLineGradient			(SBitmap* bmp, s32 tnY1, s32 tnY2, s32 tnX, f32 tfRed, f32 tfGrn, f32 tfBlu, f32 tfRedInc, f32 tfGrnInc, f32 tfBluInc);

	//////////
	// For scaling
	//////
		u32					iBmp_scale								(SBitmap* bmpScaled, SBitmap* bmp);
		u32					iiBmp_scale_Process						(SBitmap* bmpDst, SBitmap* bmpSrc, f32 tfVerticalScaler, f32 tfHorizontalScaler);
		void				iiBmp_scale_processPixels				(SBitmapProcess* bp);
		void				iiBmp_scale_processSpannedPixel1		(SBitmapProcess* bp);
		void				iiBmp_scale_processSpannedPixel2		(SBitmapProcess* bp);
		void				iiBmp_scale_processSpannedPixel3		(SBitmapProcess* bp);
		void				iiBmp_scale_processSpannedPixel4		(SBitmapProcess* bp);
		void				iiBmp_scale_processSpannedPixel5		(SBitmapProcess* bp);
		void				iiBmp_scale_processSpannedPixel6		(SBitmapProcess* bp);
		void				iiBmp_scale_processSpannedPixel7		(SBitmapProcess* bp);
		void				iiBmp_scale_processSpannedPixel8		(SBitmapProcess* bp);
		void				iiBmp_scale_processSpannedPixel9		(SBitmapProcess* bp);
		u32					iiBmp_scale_processGetIntegersBetween	(f32 p1, f32 p2);
	//////
	// End
	//////////


//////////
// vjr_dbf.cpp
//////
	u32						dbf_open								(s8* tcPathname, s8* tcAlias, bool tlExclusive);
	u32						dbf_close								(u32 tnHandle);
	u32						dbf_goto								(u32 tnHandle, u32 tnRecno);
	u32						dbf_read_field							(u32 tnHandle, u32 tnFieldNumber, s8* tcFieldName, s8** txData, u32** txDataLength);
	u32						dbf_write_field							(u32 tnHandle, u32 tnFieldNumber, s8* tcFieldName, s8* txData, u32* txDataLength);
