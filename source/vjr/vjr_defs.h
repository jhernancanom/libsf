//////////
//
// /libsf/source/vjr/vjr_defs.h
//
//////
// Version 0.54
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




struct SObjPropertyMap;




//////////
// vjr.cpp
//////
//	int APIENTRY			WinMain									(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, s32 nCmdShow);
	void					iVjr_init								(HACCEL* hAccelTable);
	void					iVjr_init_loadCaskIcons					(void);
	void					iVjr_createOverlayListing				(SBitmap* bmp, RECT* trc);
	void					iVjr_renderOverlayListing				(SBitmap* bmp, RECT* trc);
	void					iiVjr_renderAccomplishment				(SBitmap* bmp, RECT* trc, s32 tnRAG, s8* tcAccomplishment, s8* tcVersion, bool tlBold, bool tlItalic, bool tlUnderline, s32 tnAdjustAccomplishmentFontSize, s32 tnAdjustVersionFontSize);
	void					iVjr_renderAccomplishments				(SBitmap* bmp, RECT* trc);


//////////
// objects.cpp
// Note:  Property accessors are in the object_accessors.h and object_accessors.cpp source files
//////
	SObject*				iObj_create								(s32 objType, SObject* objParent);
	SObject*				iObj_addChild							(s32 objType, SObject* objParent);
	SObject*				iObj_copy								(SObject* template_obj, SObject* next, SObject* parent, bool tlCopyChildren, bool tlCreateSeparateBitmapBuffers);
	void					iObj_delete								(SObject** obj, bool tlDeleteSelf, bool tlDeleteChildren, bool tlDeleteSiblings);
	bool					iObj_setFocus							(SWindow* win, SObject* obj, bool tlClearOtherControlsWithFocus);
	void					iObj_clearFocus							(SWindow* win, SObject* obj, bool tlClearChildren, bool tlClearSiblings);
	SObject*				iObj_find_rootmostObject				(SObject* obj);
	bool					iObj_find_screenRect					(SObject* obj, RECT* rc);
	bool					iObj_find_relativeRect					(SObject* objThis, SObject* objTarget, s32 x, s32 y, RECT* rc, bool tlProcessChildren, bool tlProcessSiblings);
	SObject*				iObj_find_thisForm						(SObject* obj);
	SObject*				iObj_find_thisSubform					(SObject* obj);
	SObject*				iObj_find_thisRider						(SObject* obj);
	SObject*				iObj_findParentObject					(SObject* objStart, s32 objType, bool tlIncludeSelfInSearch);
	bool					iObj_isCommandWindow					(SObject* obj);
	void					iObj_setFocusHighlights					(SWindow* win, SObject* obj, s32 x, s32 y, bool tlProcessChildren, bool tlProcessSiblings);
	void					iObj_findFocusControls					(SObject* obj, SBuilder* objFocusControls, bool tlProcessSiblings);
	bool					iObj_setFocusObjectPrev					(SWindow* win, SObject* obj);
	bool					iObj_setFocusObjectNext					(SWindow* win, SObject* obj);
	bool					iObj_focus_descentCheck					(SObject* obj, bool tlCheckChildren, bool tlCheckSiblings);
	SObject*				iObj_focus_descentCheckObj				(SObject* obj, bool tlCheckChildren, bool tlCheckSiblings);
	void					iObj_setDirtyRender_ascent				(SObject* obj, bool tlMarkParents);
	void					iObj_setDirtyRender_descent				(SObject* obj, bool tlProcessChildren, bool tlProcessSiblings);
	void					iObj_setDirtyPublish_ascent				(SObject* obj, bool tlMarkParents);
	void					iObj_setDirtyPublish_descent			(SObject* obj, bool tlProcessChildren, bool tlProcessSiblings);
	u32						iObj_render								(SObject* obj, bool tlForceRender);
	bool					iObj_render_descentCheck				(SObject* obj, bool tlCheckChildren, bool tlCheckSiblings);
	u32						iObj_renderChildrenAndSiblings			(SObject* obj, bool tlRenderChildren, bool tlRenderSiblings, bool tlForceRender);
	u32						iObj_publish							(SObject* obj, RECT* rc, SBitmap* bmpDst, bool tlPublishChildren, bool tlPublishSiblings, bool tlForcePublish, s32 tnLevel);
	bool					iObj_publish_descentCheck				(SObject * obj, bool tlCheckChildren, bool tlCheckSiblings);
	void					iObj_duplicateChain						(SObject** root, SObject* chain);
	void					iObj_appendObjToParent					(SObject*  parent, SObject* obj);
	void					iObj_duplicateChildren					(SObject*  objDst, SObject* objSrc);
	void					iObj_setSize							(SObject*  obj, s32 tnLeft, s32 tnTop, s32 tnWidth, s32 tnHeight);
	SWindow* 				iObj_createWindowForForm				(SObject*  form, SWindow* win, s32 icon);
	SVariable*				iObj_getPropertyAsVariable				(SObject*  obj, s8* tcPropertyName, u32 tnPropertyNameLength, SComp* comp);
	void					iiObj_resetToDefault					(SObject*  obj, bool tlResetProperties, bool tlResetMethods);
	void					iiObj_resetToDefaultCommon				(SObject*  obj, bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, s32 tnPropCount);
	s32						iiObj_getBaseclassType_byName			(s8* tcTextname, s32 tnTextnameLength);
	SBaseclassList*			iiObj_getBaseclass_byName				(s8* tcTextname, s32 tnTextnameLength);
	SBaseclassList*			iiObj_getBaseclass_byType				(s32 tnObjType);

	// Creation of individual sub-objects
	SObject*				iSubobj_createEmpty						(SObject*	template_empty,			SObject* parent);
	SObject*				iSubobj_createForm						(SObject*	template_form,			SObject* parent);
	SObject*				iSubobj_createSubform					(SObject*	template_subform,		SObject* parent);
	SObject*				iSubobj_createCarousel					(SObject*	template_carousel,		SObject* parent);
	SObject*				iSubobj_createRider						(SObject*	template_rider,			SObject* parent);
	SObject*				iSubobj_createLabel						(SObject*	template_label,			SObject* parent);
	SObject*				iSubobj_createTextbox					(SObject*	template_textbox,		SObject* parent);
	SObject*				iSubobj_createButton					(SObject*	template_button,		SObject* parent);
	SObject*				iSubobj_createEditbox					(SObject*	template_editbox,		SObject* parent);
	SObject*				iSubobj_createImage						(SObject*	template_image,			SObject* parent);
	SObject*				iSubobj_createCheckbox					(SObject*	template_checkbox,		SObject* parent);
	SObject*				iSubobj_createOption					(SObject*	template_option,		SObject* parent);
	SObject*				iSubobj_createRadio						(SObject*	template_radio,			SObject* parent);
	SObject*				iSubobj_createCmdGroup					(SObject*	template_CmdGroup,		SObject* parent);
	SObject*				iSubobj_createOptGroup					(SObject*	template_OptGroup,		SObject* parent);
	SObject*				iSubobj_createListbox					(SObject*	template_Listbox,		SObject* parent);
	SObject*				iSubobj_createCombobox					(SObject*	template_Combobox,		SObject* parent);
	SObject*				iSubobj_createFormset					(SObject*	template_Formset,		SObject* parent);
	SObject*				iSubobj_createToolbar					(SObject*	template_Toolbar,		SObject* parent);
	SObject*				iSubobj_createSeparator					(SObject*	template_Separator,		SObject* parent);
	SObject*				iSubobj_createLine						(SObject*	template_Line,			SObject* parent);
	SObject*				iSubobj_createShape						(SObject*	template_Shape,			SObject* parent);
	SObject*				iSubobj_createContainer					(SObject*	template_Container,		SObject* parent);
	SObject*				iSubobj_createControl					(SObject*	template_Control,		SObject* parent);
	SObject*				iSubobj_createGrid						(SObject*	template_Grid,			SObject* parent);
	SObject*				iSubobj_createColumn					(SObject*	template_Column,		SObject* parent);
	SObject*				iSubobj_createHeader					(SObject*	template_Header,		SObject* parent);
	SObject*				iSubobj_createOleBound					(SObject*	template_OleBound,		SObject* parent);
	SObject*				iSubobj_createOleContain				(SObject*	template_OleContain,	SObject* parent);
	SObject*				iSubobj_createSpinner					(SObject*	template_Spinner,		SObject* parent);
	SObject*				iSubobj_createTimer						(SObject*	template_Timer,			SObject* parent);
	SObject*				iSubobj_createHyperlink					(SObject*	template_Hyperlink,		SObject* parent);
	SObject*				iSubobj_createCollection				(SObject*	template_Collection,	SObject* parent);
	SObject*				iSubobj_createPage						(SObject*	template_Page,			SObject* parent);
	SObject*				iSubobj_createPageframe					(SObject*	template_Pageframe,		SObject* parent);
	SObject*				iSubobj_createSession					(SObject*	template_Session,		SObject* parent);
	SObject*				iSubobj_createCustom					(SObject*	template_Custom,		SObject* parent);
	SObject*				iSubobj_createException					(SObject*	template_Exception,		SObject* parent);


	// For copy operations
	void					iiSubobj_copyEmpty						(SObject*	emptyDst,		SObject*	emptySrc);
	void					iiSubobj_copyForm						(SObject*	formDst,		SObject*	formSrc);
	void					iiSubobj_copySubform					(SObject*	subformDst,		SObject*	subformSrc);
	void					iiSubobj_copyCarousel					(SObject*	carouselDst,	SObject*	carouselSrc);
	void					iiSubobj_copyRider						(SObject*	riderDst,		SObject*	riderSrc);
	void					iiSubobj_copyLabel						(SObject*	labelDst,		SObject*	labelSrc);
	void					iiSubobj_copyTextbox					(SObject*	textboxDst,		SObject*	textboxSrc);
	void					iiSubobj_copyButton						(SObject*	buttonDst,		SObject*	buttonSrc);
	void					iiSubobj_copyEditbox					(SObject*	editboxDst,		SObject*	editboxSrc);
	void					iiSubobj_copyImage						(SObject*	imageDst,		SObject*	imageSrc);
	void					iiSubobj_copyCheckbox					(SObject*	checkboxDst,	SObject*	checkboxSrc);
	void					iiSubobj_copyOption						(SObject*	optionDst,		SObject*	optionSrc);
	void					iiSubobj_copyRadio						(SObject*	radioDst,		SObject*	radioSrc);
	void					iiSubobj_copyCmdGroup					(SObject*	cmdGroupDst,	SObject*	cmdGroupSrc);
	void					iiSubobj_copyOptGroup					(SObject*	optGroupDst,	SObject*	optGroupSrc);
	void					iiSubobj_copyListbox					(SObject*	listboxDst,		SObject*	listboxSrc);
	void					iiSubobj_copyCombobox					(SObject*	comboboxDst,	SObject*	comboboxSrc);
	void					iiSubobj_copyFormset					(SObject*	formsetDst,		SObject*	formsetSrc);
	void					iiSubobj_copyToolbar					(SObject*	toolbarDst,		SObject*	toolbarSrc);
	void					iiSubobj_copySeparator					(SObject*	separatorDst,	SObject*	separatorSrc);
	void					iiSubobj_copyLine						(SObject*	lineDst,		SObject*	lineSrc);
	void					iiSubobj_copyShape						(SObject*	shapeDst,		SObject*	shapeSrc);
	void					iiSubobj_copyContainer					(SObject*	containerDst,	SObject*	containerSrc);
	void					iiSubobj_copyControl					(SObject*	controlDst,		SObject*	controlSrc);
	void					iiSubobj_copyGrid						(SObject*	gridDst,		SObject*	gridSrc);
	void					iiSubobj_copyColumn						(SObject*	columnDst,		SObject*	columnSrc);
	void					iiSubobj_copyHeader						(SObject*	headerDst,		SObject*	headerSrc);
	void					iiSubobj_copyOleBound					(SObject*	oleBoundDst,	SObject*	oleBoundSrc);
	void					iiSubobj_copyOleContain					(SObject*	oleContainDst,	SObject*	oleContainSrc);
	void					iiSubobj_copySpinner					(SObject*	spinnerDst,		SObject*	spinnerSrc);
	void					iiSubobj_copyTimer						(SObject*	timerDst,		SObject*	timerSrc);
	void					iiSubobj_copyHyperlink					(SObject*	hyperlinkDst,	SObject*	hyperlinkSrc);
	void					iiSubobj_copyCollection					(SObject*	collectionDst,	SObject*	collectionSrc);
	void					iiSubobj_copyPage						(SObject*	pageDst,		SObject*	pageSrc);
	void					iiSubobj_copyPageframe					(SObject*	pageframeDst,	SObject*	pageframeSrc);
	void					iiSubobj_copySession					(SObject*	sessionDst,		SObject*	sessionSrc);
	void					iiSubobj_copyCustom						(SObject*	customDst,		SObject*	customSrc);
	void					iiSubobj_copyException					(SObject*	exceptionDst,	SObject*	exceptionSrc);


	// For initialization
	void					iiSubobj_resetToDefaultEmpty			(SObject*	empty,		bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount);
	void					iiSubobj_resetToDefaultForm				(SObject*	form,		bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount);
	void					iiSubobj_resetToDefaultSubform			(SObject*	subform,	bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount);
	void					iiSubobj_resetToDefaultCarousel			(SObject*	carousel,	bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount);
	void					iiSubobj_resetToDefaultRider			(SObject*	rider,		bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount);
	void					iiSubobj_resetToDefaultLabel			(SObject*	label,		bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount);
	void					iiSubobj_resetToDefaultTextbox			(SObject*	textbox,	bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount);
	void					iiSubobj_resetToDefaultButton			(SObject*	button,		bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount);
	void					iiSubobj_resetToDefaultEditbox			(SObject*	editbox,	bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount);
	void					iiSubobj_resetToDefaultImage			(SObject*	image,		bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount);
	void					iiSubobj_resetToDefaultCheckbox			(SObject*	checkbox,	bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount);
	void					iiSubobj_resetToDefaultOption			(SObject*	option,		bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount);
	void					iiSubobj_resetToDefaultRadio			(SObject*	radio,		bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount);
	void					iiSubobj_resetToDefaultCmdGroup			(SObject*	cmdGroup,	bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount);
	void					iiSubobj_resetToDefaultOptGroup			(SObject*	optGroup,	bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount);
	void					iiSubobj_resetToDefaultListbox			(SObject*	listbox,	bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount);
	void					iiSubobj_resetToDefaultCombobox			(SObject*	combobox,	bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount);
	void					iiSubobj_resetToDefaultFormset			(SObject*	formset,	bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount);
	void					iiSubobj_resetToDefaultToolbar			(SObject*	toolbar,	bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount);
	void					iiSubobj_resetToDefaultSeparator		(SObject*	separator,	bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount);
	void					iiSubobj_resetToDefaultLine				(SObject*	line,		bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount);
	void					iiSubobj_resetToDefaultShape			(SObject*	shape,		bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount);
	void					iiSubobj_resetToDefaultContainer		(SObject*	container,	bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount);
	void					iiSubobj_resetToDefaultControl			(SObject*	control,	bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount);
	void					iiSubobj_resetToDefaultGrid				(SObject*	grid,		bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount);
	void					iiSubobj_resetToDefaultColumn			(SObject*	column,		bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount);
	void					iiSubobj_resetToDefaultHeader			(SObject*	header,		bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount);
	void					iiSubobj_resetToDefaultOleBound			(SObject*	oleBound,	bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount);
	void					iiSubobj_resetToDefaultOleContain		(SObject*	oleContain,	bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount);
	void					iiSubobj_resetToDefaultSpinner			(SObject*	spinner,	bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount);
	void					iiSubobj_resetToDefaultTimer			(SObject*	timer,		bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount);
	void					iiSubobj_resetToDefaultHyperlink		(SObject*	hyperlink,	bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount);
	void					iiSubobj_resetToDefaultCollection		(SObject*	collection,	bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount);
	void					iiSubobj_resetToDefaultPage				(SObject*	page,		bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount);
	void					iiSubobj_resetToDefaultPageframe		(SObject*	pageframe,	bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount);
	void					iiSubobj_resetToDefaultSession			(SObject*	session,	bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount);
	void					iiSubobj_resetToDefaultCustom			(SObject*	custom,		bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount);
	void					iiSubobj_resetToDefaultException		(SObject*	exception,	bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount);


	// Delete individual sub-objects
	void					iObj_deleteCommon						(SObject*	obj);
	void					iSubobj_deleteEmpty						(SObject*	empty,		bool tlDeleteSelf);
	void					iSubobj_deleteForm						(SObject*	form,		bool tlDeleteSelf);
	void					iSubobj_deleteSubform					(SObject*	subform,	bool tlDeleteSelf);
	void					iSubobj_deleteCarousel					(SObject*	carousel,	bool tlDeleteSelf, bool tlLeaveRiders, bool tlLeaveObjects);
	void					iSubobj_deleteRider						(SObject*	rider,		bool tlDeleteSelf, bool tlLeaveObjects);
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
	u32						iSubobj_renderCarousel					(SObject* carousel);
	u32						iSubobj_renderRider						(SObject* rider);
	u32						iSubobj_renderLabel						(SObject* label);
	u32						iSubobj_renderTextbox					(SObject* textbox);
	u32						iSubobj_renderButton					(SObject* button);
	u32						iSubobj_renderEditbox					(SObject* editbox);
	u32						iSubobj_renderImage						(SObject* image);
	u32						iSubobj_renderCheckbox					(SObject* checkbox);
	u32						iSubobj_renderOption					(SObject* option);
	u32						iSubobj_renderRadio						(SObject* radio);


	// Default publish of carousels and riders
	u32						iSubobj_publishCarousel					(SObject* carousel,	bool tlForcePublish);
	u32						iSubobj_publishRider					(SObject* rider,	bool tlForcePublish);


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
	bool					iDefaultCallback_onMouseWheel			(SWindow* win, SObject* obj, s32 x, s32 y, bool tlCtrl, bool tlAlt, bool tlShift, u32 tnClick, s32 tnUnits);
	bool					iDefaultCallback_onMouseMove			(SWindow* win, SObject* obj, s32 x, s32 y, bool tlCtrl, bool tlAlt, bool tlShift, u32 tnClick);
	bool					iDefaultCallback_onMouseDown			(SWindow* win, SObject* obj, s32 x, s32 y, bool tlCtrl, bool tlAlt, bool tlShift, u32 tnClick);
	bool					iDefaultCallback_onMouseUp				(SWindow* win, SObject* obj, s32 x, s32 y, bool tlCtrl, bool tlAlt, bool tlShift, u32 tnClick);
	bool					iDefaultCallback_onMouseEnter			(SWindow* win, SObject* obj);
	bool					iDefaultCallback_onMouseLeave			(SWindow* win, SObject* obj);
	bool					iDefaultCallback_onMouseHover			(SWindow* win, SObject* obj, s32 x, s32 y, bool tlCtrl, bool tlAlt, bool tlShift, u32 tnClick);
	bool					iDefaultCallback_onKeyDown				(SWindow* win, SObject* obj, bool tlCtrl, bool tlAlt, bool tlShift, bool llCaps, s16 tcAscii, u16 tnVKey, bool tlIsCAS, bool tlIsAscii);
	bool					iDefaultCallback_onKeyUp				(SWindow* win, SObject* obj, bool tlCtrl, bool tlAlt, bool tlShift, bool llCaps, s16 tcAscii, u16 tnVKey, bool tlIsCAS, bool tlIsAscii);
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
	void					iInit_create_jdebi						(void);
	void					iInit_createDefaultDatetimes			(void);
	SBitmap*				iiVjr_buildSplashScreen					(SBitmap* bmpSplash);
	void					iVjr_appendSystemLog					(s8* tcLogText);
	void					iVjr_flushSystemLog						(void);
	void					iVjr_releaseMemory						(void);
	void					iVjr_releaseAllDefaultDatetimes			(void);
	void					iVjr_releaseAllDefaultObjects			(void);
	void					iVjr_release_jdebi						(void);
	void					iVjr_releaseCaskIcons					(void);
	void					iVjr_shutdown							(void);

	DWORD	WINAPI			iSplash_show							(LPVOID/*SBitmap* bmp*/ lpParameter);
	DWORD	WINAPI			iSplash_delete							(LPVOID/*bool tlWait*/ lpParameter);
	void	CALLBACK		iSplash_timerProc						(HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime);
	LRESULT CALLBACK		iSplash_wndProc							(HWND hwnd, UINT m, WPARAM w, LPARAM l);

	DWORD	WINAPI			iPlay_ariaSplash						(LPVOID lpParameter);
	void WINAPI				iPlay_ariaSplash_callback				(f32* sampleBuffer, u32 tnSamples, bool* tlContinueAfterThisSampleSet);

	DWORD	WINAPI			iReadEvents_messageWindow				(LPVOID lpParameter);
	LRESULT	CALLBACK		iWindow_wndProcMessage					(HWND hwnd, UINT m, WPARAM w, LPARAM l);
	LRESULT	CALLBACK		iWindow_wndProcForms					(HWND hwnd, UINT m, WPARAM w, LPARAM l);
	SWindow* 				iWindow_createForObject					(SObject* obj, SWindow* winReuse, s32 icon);
	void					iWindow_releaseAll						(SBuilder** windowRoot, bool tlDeleteSelf);
	void					iWindow_delete							(SWindow* win, bool tlDeleteSelf);
	SWindow*				iWindow_findByHwnd						(HWND hwnd);
	SWindow*				iWindow_findByObj						(SObject* obj);
	SWindow*				iWindow_allocate						(void);
	void					iWindow_disconnectObj					(SWindow* win, SObject* obj);
	void					iWindow_render							(SWindow* win, bool tlForceRedraw);
	void					iWindow_move							(SWindow* win);
	void					iWindow_minimize						(SWindow* win);
	void					iWindow_maximize						(SWindow* win);
	bool					iWindow_isPointerValid							(SWindow* win);

	void					iFocusHighlight_create					(SFocusHighlight* focus, RECT* rc);
	void					iFocusHighlight_delete					(SFocusHighlight* focus);
	void					iFocusHighlight_deleteAll				(void);
	SFocusHighlight*		iFocusHighlight_findByHwnd				(HWND hwnd);
	SFocusHighlight*		iFocusHighlight_findByObj				(SObject* obj);
	LRESULT CALLBACK		iFocusHighlight_wndProc					(HWND hwnd, UINT m, WPARAM w, LPARAM l);

	STooltip*				iTooltip_allocate						(RECT* rc, SBitmap* bmp, s32 tnTimeoutMs, bool tlAllowMove, bool tlAllowSticky);
	void					iTooltip_show							(STooltip* tooltip);
	DWORD WINAPI			iTooltip_thread							(LPVOID lpParameter/*STooltip*/);
	void					iTooltip_delete							(STooltip* tooltip);
	LRESULT CALLBACK		iTooltip_wndProc						(HWND hwnd, UINT m, WPARAM w, LPARAM l);

	void					iSourceLight_reset						(void);
	bool					iSourceLight_copy						(SWindow* win, SObject* obj);

	bool					iFile_readContents						(s8* tcFilename, FILE** tfh, s8** data, u32* dataLength);

	void					iMisc_adjustColorBrightness				(SBgra& color, f32 tfPercent);
	bool					iInit_shutdownPolitely					(void);

	s64						iTime_computeMilliseconds				(SYSTEMTIME* time);
	s64						iTime_getSystemMs						(void);
	s64						iTime_getLocalMs						(void);
	s8						iLowerCase								(s8 c);
	s8						iUpperCase								(s8 c);
	
	bool					iTestExactlyEqual						(s8* left, u32 leftLength, cs8* right, u32 rightLength);
	bool					iTestExactlyEqual						(s8* left, u32 leftLength,  s8* right, u32 rightLength);
	bool					iTestExactlyEqual_case					(s8* left, u32 leftLength, cs8* right, u32 rightLength);
	bool					iTestExactlyEqual_case					(s8* left, u32 leftLength,  s8* right, u32 rightLength);
	bool					iIsNeedleInHaystack						(s8* haystack, s32 haystackLength, s8* needle, s32 needleLength);
	bool					iIsNeedleInHaystackCase					(s8* haystack, s32 haystackLength, s8* needle, s32 needleLength);
	bool					iIsNeedleInHaystack						(s8* haystack, s32 haystackLength, s8* needle, s32 needleLength, u32* tnStart);
	bool					iIsNeedleInHaystackCase					(s8* haystack, s32 haystackLength, s8* needle, s32 needleLength, u32* tnStart);
	bool					iIsCharacterInHaystack					(s8* haystack, s32 haystackLength, s8 needle, u32* tnOffset);
	bool					iIsCharacterInHaystackCase				(s8* haystack, s32 haystackLength, s8 needle, u32* tnOffset);
	bool					iIsCharacterInHaystackReversed			(s8* haystack, s32 haystackLength, s8 needle, u32* tnOffset);
	bool					iIsCharacterInHaystackReversedCase		(s8* haystack, s32 haystackLength, s8 needle, u32* tnOffset);
	bool					iDoesHaystackStartWithNeedle			(s8* haystack, s32 haystackLength, s8* needle, s32 needleLength);
	bool					iDoesHaystackStartWithNeedleCase		(s8* haystack, s32 haystackLength, s8* needle, s32 needleLength);
	s8						iLowerCharacter							(s8 ch);
	u32						iSkipWhitespaces						(s8* source, u32* offset, u32 maxLength);

	s64						iMath_delta								(s64 tnBaseValue, s64 tnSubtractionValue);
	s8*						iMath_roundTo							(f64* tfValue, f64 tfRoundTo);
	bool					iMath_between							(s32 tnValue, s32 tnN1, s32 tnN2);

	s8*						iDuplicateString						(s8* tcText);

	// Mouse processing (callback from iWindow_wndProc()
	s32						iMouse_processMessage					(SWindow* win, UINT m, WPARAM w, LPARAM l);
	void					iiMouse_translatePosition				(SWindow* win, POINTS* pt, UINT m);
	s32						iiMouse_processMouseEvents				(SWindow* win, UINT m, WPARAM w, LPARAM l);
	void					iiMouse_processMouseEvents_mouseMove	(SWindow* win, SObject* obj, RECT* rc,         bool tlProcessChildren, bool tlProcessSiblings, bool* tlProcessed);
	bool					iiMouse_processMouseEvents_common		(SWindow* win, SObject* obj, RECT* rc, UINT m, bool tlProcessChildren, bool tlProcessSiblings, bool* tlProcessed);
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
	void					iExtraInfo_free							(SEM* sem, SLine* ec, SExtraInfo** root, bool tlDeleteSelf);
