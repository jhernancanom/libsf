//////////
//
// /libsf/source/vjr/vjr_defs.h
//
//////
// Version 0.33
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
// Note:  Property accessors are in the object_accessors.h and object_accessors.cpp source files
//////
	SObject*				iObj_create								(u32 objType, SObject* objParent);
	SObject*				iObj_addChild							(u32 objType, SObject* objParent);
	SObject*				iObj_copy								(SObject* template_obj, SObject* next, SObject* parent, bool tlCopyChildren, bool tlCreateSeparateBitmapBuffers);
	void					iObj_delete								(SObject** obj, bool tlDeleteSelf);
	void					iObj_findFocusControls					(SObject*  obj, SBuilder* objFocusControls, bool tlProcessSiblings);
	void					iObj_setDirty							(SObject* obj, bool tlMarkParents);
	u32						iObj_render								(SObject*  obj, bool tlForceRender);
	void					iObj_renderChildrenAndSiblings			(SObject*  obj, bool tlRenderChildren, bool tlRenderSiblings, bool tlForceRender);
	u32						iObj_publish							(SBitmap* bmpDst, RECT* rc, SObject* obj, bool tlPublishChildren, bool tlPublishSiblings);
	void					iObj_duplicateChain						(SObject** root, SObject* chain);
	void					iObj_appendObjToParent					(SObject*  parent, SObject* obj);
	void					iObj_duplicateChildren					(SObject*  objDst, SObject* objSrc);
	void					iObj_setSize							(SObject*  obj, s32 tnLeft, s32 tnTop, s32 tnWidth, s32 tnHeight);
	SWindow* 				iObj_createWindowForForm				(SObject*  form, SWindow* win, s32 icon);
	bool					iObj_setVisible							(SObject*  obj, bool tlNewVisible);
	SVariable*				iObj_getPropertyAsVariable				(SObject*  obj, s8* tcPropertyName, u32 tnPropertyNameLength, SComp* comp);
	void					iiObj_resetToDefault					(SObject*  obj, bool tlResetProperties, bool tlResetMethods);
	void					iiObj_resetToDefaultCommon				(SObject*  obj, bool tlResetProperties, bool tlResetMethods);
	s32						iiObj_getBaseclass_byName				(s8* tcTextname, s32 tnTextnameLength);
	SBaseclassList*			iiObj_getBaseclass_byType				(u32 tnObjType);

	// Creation of individual sub-objects
	SObject*				iSubobj_createEmpty						(SObject*	template_empty,		SObject* parent);
	SObject*				iSubobj_createForm						(SObject*	template_form,		SObject* parent);
	SObject*				iSubobj_createSubform					(SObject*	template_subform,	SObject* parent);
	SObject*				iSubobj_createLabel						(SObject*	template_label,		SObject* parent);
	SObject*				iSubobj_createTextbox					(SObject*	template_textbox,	SObject* parent);
	SObject*				iSubobj_createButton					(SObject*	template_button,	SObject* parent);
	SObject*				iSubobj_createEditbox					(SObject*	template_editbox,	SObject* parent);
	SObject*				iSubobj_createImage						(SObject*	template_image,		SObject* parent);
	SObject*				iSubobj_createCheckbox					(SObject*	template_checkbox,	SObject* parent);
	SObject*				iSubobj_createOption					(SObject*	template_option,	SObject* parent);
	SObject*				iSubobj_createRadio						(SObject*	template_radio,		SObject* parent);

	// For copy operations
	void					iiSubobj_copyEmpty						(SObject*	emptyDst,		SObject*	emptySrc);
	void					iiSubobj_copyForm						(SObject*	formDst,		SObject*	formSrc);
	void					iiSubobj_copySubform					(SObject*	subformDst,		SObject*	subformSrc);
	void					iiSubobj_copyLabel						(SObject*	labelDst,		SObject*	labelSrc);
	void					iiSubobj_copyTextbox					(SObject*	textboxDst,		SObject*	textboxSrc);
	void					iiSubobj_copyButton						(SObject*	buttonDst,		SObject*	buttonSrc);
	void					iiSubobj_copyEditbox					(SObject*	editboxDst,		SObject*	editboxSrc);
	void					iiSubobj_copyImage						(SObject*	imageDst,		SObject*	imageSrc);
	void					iiSubobj_copyCheckbox					(SObject*	checkboxDst,	SObject*	checkboxSrc);
	void					iiSubobj_copyOption						(SObject*	optionDst,		SObject*	optionSrc);
	void					iiSubobj_copyRadio						(SObject*	radioDst,		SObject*	radioSrc);

	// For initialization
	void					iiSubobj_resetToDefaultEmpty			(SObject*	empty,		bool tlResetProperties, bool tlResetMethods);
	void					iiSubobj_resetToDefaultForm				(SObject*	form,		bool tlResetProperties, bool tlResetMethods);
	void					iiSubobj_resetToDefaultSubform			(SObject*	subform,	bool tlResetProperties, bool tlResetMethods);
	void					iiSubobj_resetToDefaultLabel			(SObject*	label,		bool tlResetProperties, bool tlResetMethods);
	void					iiSubobj_resetToDefaultTextbox			(SObject*	textbox,	bool tlResetProperties, bool tlResetMethods);
	void					iiSubobj_resetToDefaultButton			(SObject*	button,		bool tlResetProperties, bool tlResetMethods);
	void					iiSubobj_resetToDefaultEditbox			(SObject*	editbox,	bool tlResetProperties, bool tlResetMethods);
	void					iiSubobj_resetToDefaultImage			(SObject*	image,		bool tlResetProperties, bool tlResetMethods);
	void					iiSubobj_resetToDefaultCheckbox			(SObject*	checkbox,	bool tlResetProperties, bool tlResetMethods);
	void					iiSubobj_resetToDefaultOption			(SObject*	option,		bool tlResetProperties, bool tlResetMethods);
	void					iiSubobj_resetToDefaultRadio			(SObject*	radio,		bool tlResetProperties, bool tlResetMethods);

	// Delete individual sub-objects
	void					iSubobj_deleteEmpty						(SObject*	empty,		bool tlDeleteSelf);
	void					iSubobj_deleteForm						(SObject*	form,		bool tlDeleteSelf);
	void					iSubobj_deleteSubform					(SObject*	subform,	bool tlDeleteSelf);
	void					iSubobj_deleteLabel						(SObject*	label,		bool tlDeleteSelf);
	void					iSubobj_deleteTextbox					(SObject*	textbox,	bool tlDeleteSelf);
	void					iSubobj_deleteButton					(SObject*	button,		bool tlDeleteSelf);
	void					iSubobj_deleteEditbox					(SObject*	editbox,	bool tlDeleteSelf);
	void					iSubobj_deleteImage						(SObject*	image,		bool tlDeleteSelf);
	void					iSubobj_deleteCheckbox					(SObject*	checkbox,	bool tlDeleteSelf);
	void					iSubobj_deleteOption					(SObject*	option,		bool tlDeleteSelf);
	void					iSubobj_deleteRadio						(SObject*	radio,		bool tlDeleteSelf);


	// Default render of sub-objects
	u32						iSubobj_renderEmpty						(SObject* empty);
	u32						iSubobj_renderForm						(SObject* form);
	u32						iSubobj_renderSubform					(SObject* subform);
	u32						iSubobj_renderLabel						(SObject* label);
	u32						iSubobj_renderTextbox					(SObject* textbox);
	u32						iSubobj_renderButton					(SObject* button);
	u32						iSubobj_renderEditbox					(SObject* editbox);
	u32						iSubobj_renderImage						(SObject* image);
	u32						iSubobj_renderCheckbox					(SObject* checkbox);
	u32						iSubobj_renderOption					(SObject* option);
	u32						iSubobj_renderRadio						(SObject* radio);


//////////
// callbacks.cpp
//////
	bool					iDefaultCallback_onLoad					(SWindow* win, SObject* obj);
	bool					iDefaultCallback_onInit					(SWindow* win, SObject* obj);
	bool					iDefaultCallback_onCreated				(SWindow* win, SObject* obj);
	bool					iDefaultCallback_onResize				(SWindow* win, SObject* obj, u32* widthRequired_out, u32* heightRequired_out);
	bool					iDefaultCallback_onRender				(SWindow* win, SObject* obj);
	bool					iDefaultCallback_onPublish				(SWindow* win, SObject* obj);
	bool					iDefaultCallback_onDestroy				(SWindow* win, SObject* obj);
	bool					iDefaultCallback_onUnload				(SWindow* win, SObject* obj);
	bool					iDefaultCallback_onGotFocus				(SWindow* win, SObject* obj);
	bool					iDefaultCallback_onLostFocus			(SWindow* win, SObject* obj);
	bool					iDefaultCallback_onMouseClickEx			(SWindow* win, SObject* obj, s32 x, s32 y, bool tlCtrl, bool tlAlt, bool tlShift, u32 tnClick);
	bool					iDefaultCallback_onMouseDblClickEx		(SWindow* win, SObject* obj, s32 x, s32 y, bool tlCtrl, bool tlAlt, bool tlShift, u32 tnClick);
	bool					iDefaultCallback_onMouseWheel			(SWindow* win, SObject* obj, s32 tnUnits);
	bool					iDefaultCallback_onMouseMove			(SWindow* win, SObject* obj, s32 x, s32 y, bool tlCtrl, bool tlAlt, bool tlShift, u32 tnClick);
	bool					iDefaultCallback_onMouseDown			(SWindow* win, SObject* obj, s32 x, s32 y, bool tlCtrl, bool tlAlt, bool tlShift, u32 tnClick);
	bool					iDefaultCallback_onMouseUp				(SWindow* win, SObject* obj, s32 x, s32 y, bool tlCtrl, bool tlAlt, bool tlShift, u32 tnClick);
	bool					iDefaultCallback_onMouseEnter			(SWindow* win, SObject* obj);
	bool					iDefaultCallback_onMouseLeave			(SWindow* win, SObject* obj);
	bool					iDefaultCallback_onMouseHover			(SWindow* win, SObject* obj, s32 x, s32 y, bool tlCtrl, bool tlAlt, bool tlShift, u32 tnClick);
	bool					iDefaultCallback_onKeyDown				(SWindow* win, SObject* obj, bool tlCtrl, bool tlAlt, bool tlShift, s16 tcAscii, u16 tnVKey, bool tlIsCAS, bool tlIsAscii);
	bool					iDefaultCallback_onKeyUp				(SWindow* win, SObject* obj, bool tlCtrl, bool tlAlt, bool tlShift, s16 tcAscii, u16 tnVKey, bool tlIsCAS, bool tlIsAscii);
	bool					iDefaultCallback_onActivate				(SWindow* win, SObject* obj);
	bool					iDefaultCallback_onDeactivate			(SWindow* win, SObject* obj);
	bool					iDefaultCallback_onInteractiveChange	(SWindow* win, SObject* obj);
	bool					iDefaultCallback_onProgrammaticChange	(SWindow* win, SObject* obj);
	bool					iDefaultCallback_onSelect				(SWindow* win, SObject* obj);
	bool					iDefaultCallback_onDeselect				(SWindow* win, SObject* obj);
	bool					iDefaultCallback_onMoved				(SWindow* win, SObject* obj, u32* xOverride_out, u32* yOverride_out);
	bool					iDefaultCallback_onQueryUnload			(SWindow* win, SObject* obj);
	bool					iDefaultCallback_onAddObject			(SWindow* win, SObject* obj);
	bool					iDefaultCallback_onAddProperty			(SWindow* win, SObject* obj);
	bool					iDefaultCallback_onError				(SWindow* win, SObject* obj);
	bool					iDefaultCallback_onScrolled				(SWindow* win, SObject* obj);


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
	LRESULT	CALLBACK		iWindow_wndProcMessage					(HWND hwnd, UINT m, WPARAM w, LPARAM l);
	LRESULT	CALLBACK		iWindow_wndProcForms					(HWND hwnd, UINT m, WPARAM w, LPARAM l);
	SWindow* 				iWindow_createForObject					(SObject* obj, SWindow* winReuse, s32 icon);
	SWindow*				iWindow_findByHwnd						(HWND hwnd);
	SWindow*				iWindow_allocate						(void);
	void					iWindow_render							(SWindow* win, bool tlForceRedraw);
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
	s8						iLowerCase								(s8 c);
	s8						iUpperCase								(s8 c);
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
	s32						iiMouse_processMouseEvents				(SWindow* win, UINT m, WPARAM w, LPARAM l);
	void					iiMouse_processMouseEvents_mouseMove	(SWindow* win, SObject* obj, RECT* rc, bool tlProcessChildren, bool tlProcessSiblings);
	void					iiMouse_processMouseEvents_mouseDown	(SWindow* win, SObject* obj, RECT* rc, bool tlProcessChildren, bool tlProcessSiblings, bool* tlProcessed);
	void					iiMouse_processMouseEvents_mouseUp		(SWindow* win, SObject* obj, RECT* rc, bool tlProcessChildren, bool tlProcessSiblings, bool* tlProcessed);
//	s32						iiMouse_processMouseEvents_nonclient	(SWindow* win, UINT m, WPARAM w, LPARAM l);
	void					iiMouse_getFlags_wparam					(WPARAM w, bool* tlCtrl, bool* tlAlt, bool* tlShift, bool* tlLeft, bool* tlMiddle, bool* tlRight, bool* tlCaps);
	void					iiMouse_getFlags_async					(          bool* tlCtrl, bool* tlAlt, bool* tlShift, bool* tlLeft, bool* tlMiddle, bool* tlRight, bool* tlCaps);

	// For processing keystrokes
	s32						iKeyboard_processMessage				(SWindow* win, UINT m, WPARAM w, LPARAM l);

	// EditManager
	// Moved to edit_chain_manager.cpp

	// Edit Chain
	// Moved to edit_chain.cpp

	// Engine
	// Moved to engine.cpp

	// Translate
	void*					iTranslate_p1_to_p2						(SBuilder* root, void* ptr);
	void*					iTranslate_p2_to_p1						(SBuilder* root, void* ptr);

	// ExtraInfo
	void					iExtraInfo_free							(SEM* em, SEdit* ec, SExtraInfo** root, bool tlDeleteSelf);

	// Datum
	void					iDatum_allocateSpace					(SDatum* datum,            s32 dataLength);
	SDatum*					iDatum_allocate							(                s8* data, s32 dataLength);
	void					iDatum_duplicate						(SDatum* datum,  s8* data, s32 dataLength);
	void					iDatum_duplicate						(SDatum* datum, cs8* data, s32 dataLength);
	void					iDatum_duplicate						(SDatum* datumDst, SDatum* datumSrc);
	bool					iDatum_resize							(SDatum* datum, s32 newDataLength);
	s32						iDatum_compare							(SDatum* datumLeft, SDatum* datumRight);
	s32						iDatum_compare							(SDatum* datumLeft, s8*  data, s32 dataLength);
	s32						iDatum_compare							(SDatum* datumLeft, cs8* data, s32 dataLength);
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
	void					iBmp_saveToDisk							(SBitmap* bmp, s8* tcPathname);
	void					iBmp_convertTo32Bits					(SBitmap* bmp);
	void					iBmp_convertTo24Bits					(SBitmap* bmp);
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
	u32						iBmp_grayscale							(SBitmap* bmp, RECT* trc);
	u32						iBmp_colorize							(SBitmap* bmp, RECT* trc, SBgra colorTemplate, bool tlClampColor);
// TODO:  The following void functions need to be changed to u32 and indicate how many pixels were rendered
	void					iBmp_bitBltMask							(SBitmap* bmpDst, RECT* trc, SBitmap* bmpSrc);
	void					iBmp_drawPoint							(SBitmap* bmp, s32 tnX, s32 tnY, SBgra color);
	void					iBmp_fillRect							(SBitmap* bmp, RECT* rc, SBgra colorNW, SBgra colorNE, SBgra colorSW, SBgra colorSE, bool tlUseGradient, RECT* rcClip, bool tluseClip);
	void					iBmp_frameRect							(SBitmap* bmp, RECT* rc, SBgra colorNW, SBgra colorNE, SBgra colorSW, SBgra colorSE, bool tlUseGradient, RECT* rcClip, bool tluseClip);
	void					iBmp_drawHorizontalLine					(SBitmap* bmp, s32 tnX1, s32 tnX2, s32 tnY, SBgra color);
	void					iBmp_drawVerticalLine					(SBitmap* bmp, s32 tnY1, s32 tnY2, s32 tnX, SBgra color);
	void					iBmp_drawHorizontalLineGradient			(SBitmap* bmp, s32 tnX1, s32 tnX2, s32 tnY, f32 tfRed, f32 tfGrn, f32 tfBlu, f32 tfRedInc, f32 tfGrnInc, f32 tfBluInc, RECT* rcClip, bool tluseClip);
	void					iBmp_drawVerticalLineGradient			(SBitmap* bmp, s32 tnY1, s32 tnY2, s32 tnX, f32 tfRed, f32 tfGrn, f32 tfBlu, f32 tfRedInc, f32 tfGrnInc, f32 tfBluInc, RECT* rcClip, bool tluseClip);

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
