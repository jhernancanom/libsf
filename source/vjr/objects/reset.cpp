//////////
//
// /libsf/source/vjr/objects/reset.cpp
//
//////
// Version 0.54
// Copyright (c) 2014 by Rick C. Hodgin
//////
// Last update:
//     Dec.18.2014
//////
// Change log:
//     Dec.18.2014 - Initial creation
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









//////////
//
// Called to reset the object to its hard defaults.
//
//////
	void iiSubobj_resetToDefaultEmpty(SObject* empty, bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount)
	{
		logfunc(__FUNCTION__);
		if (empty)
		{
			//////////
			// Reset the common settings
			//////
				iiObj_resetToDefaultCommon(empty, true, true, propList, tnPropCount);
		}

		// No object-specific initialization because empty objects do nothing except exist as placeholders
	}

	void iiSubobj_resetToDefaultForm(SObject* form, bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount)
	{
		SObject*	objChild;
		SBitmap*	bmp;
		RECT		lrc;


		logfunc(__FUNCTION__);
		if (form)
		{
			//////////
			// Reset the common settings
			//////
				iiObj_resetToDefaultCommon(form, true, true, propList, tnPropCount);


			//////////
			// Set default size and position
			//////
				SetRect(&form->rc, 0, 0, 375, 250);
				SetRect(&form->rco, 0, 0, 375, 250);
				SetRect(&form->rcp, 0, 0, 375, 250);

				// Set the size of the child components
				iObj_setSize(form, 0, 0, 375, 250);

				// Font
				iFont_delete(&form->p.font, true);
				form->p.font = iFont_duplicate(gsFontDefault);


			//////////
			// Set default anchor to fixed in all positions, no resize
			//////
				setAnchor(form, _ANCHOR_FIXED_NORESIZE);
				setBackColor(form, whiteColor);
				setForeColor(form, blackColor);
				setIcon(form, bmpVjrIcon);
				setCaption(form, cgcName_form);
				setPictureBmp(form, bmpNoImage);


			//////////
			// Events
			//////
				*(uptr*)&form->ev.general.activate		= (uptr)&iDefaultCallback_onActivate;
				*(uptr*)&form->ev.general.deactivate	= (uptr)&iDefaultCallback_onDeactivate;


			//////////
			// Reset our min/max
			//////
				SetRect(&form->p.rcMax, -1, -1, -1, -1);
				SetRect(&form->p.rcMin, -1, -1, -1, -1);


			//////////
			// Default child settings
			//////
				SetRect(&lrc, 0, 0, bmpArrowUl->bi.biWidth, bmpArrowUl->bi.biHeight);
				objChild = form->firstChild;
				while (objChild)
				{
					// See which object this is
					if (objChild->objType == _OBJ_TYPE_IMAGE && isName(objChild, cgcName_icon))
					{
						// Adjust the size
						iObj_setSize(objChild, objChild->rc.left, objChild->rc.top, bmpVjrIcon->bi.biWidth, bmpVjrIcon->bi.biHeight);

						// Form icon
						setPictureBmp(objChild, bmpVjrIcon);
						setPictureBmpDown(objChild, bmpVjrIcon);
						setPictureBmpOver(objChild, bmpVjrIcon);

						// Add highlighting for the over and down
						bmp = iObjProp_get_bitmap(objChild, _INDEX_PICTUREBMP_OVER);			iBmp_colorize(bmp, &lrc, colorMouseOver, false, 0.25f);
						bmp = iObjProp_get_bitmap(objChild, _INDEX_PICTUREBMP_DOWN);			iBmp_colorize(bmp, &lrc, colorMouseDown, false, 0.25f);
						setBackStyle(objChild, _BACK_STYLE_TRANSPARENT);
						setVisible(objChild, _LOGICAL_TRUE);

					} else if (objChild->objType == _OBJ_TYPE_LABEL && isName(objChild, cgcName_caption)) {
						// Caption
						setCaption(objChild, cgcName_formCaption);
						iObjProp_set_s32_direct(objChild, _INDEX_BACKSTYLE, _BACK_STYLE_TRANSPARENT);
						iFont_delete(&objChild->p.font, true);
						objChild->p.font		= iFont_create(cgcFontName_windowTitleBar, 12, FW_NORMAL, false, false);
						setVisible(objChild, _LOGICAL_TRUE);

					} else if (objChild->objType == _OBJ_TYPE_IMAGE && isName(objChild, cgcName_iconMove)) {
						// Adjust the size
						iObj_setSize(objChild, objChild->rc.left, objChild->rc.top, bmpVjrIcon->bi.biWidth, bmpVjrIcon->bi.biHeight);

						// Move icon
						setPictureBmp(objChild, bmpMove);
						setPictureBmpDown(objChild, bmpMove);
						setPictureBmpOver(objChild, bmpMove);

						// Add highlighting for the over and down
						bmp = iObjProp_get_bitmap(objChild, _INDEX_PICTUREBMP_OVER);			iBmp_colorize(bmp, &lrc, colorMouseOver, false, 0.25f);
						bmp = iObjProp_get_bitmap(objChild, _INDEX_PICTUREBMP_DOWN);			iBmp_colorize(bmp, &lrc, colorMouseDown, false, 0.25f);
						setBackStyle(objChild, _BACK_STYLE_TRANSPARENT);
						setVisible(objChild, _LOGICAL_TRUE);

					} else if (objChild->objType == _OBJ_TYPE_IMAGE && isName(objChild, cgcName_iconMinimize)) {
						// Adjust the size
						iObj_setSize(objChild, objChild->rc.left, objChild->rc.top, bmpVjrIcon->bi.biWidth, bmpVjrIcon->bi.biHeight);

						// Minimize icon
						setPictureBmp(objChild, bmpMinimize);
						setPictureBmpDown(objChild, bmpMinimize);
						setPictureBmpOver(objChild, bmpMinimize);

						// Add highlighting for the over and down
						bmp = iObjProp_get_bitmap(objChild, _INDEX_PICTUREBMP_OVER);
						iBmp_colorize(bmp, &lrc, colorMouseOver, false, 0.25f);
						bmp = iObjProp_get_bitmap(objChild, _INDEX_PICTUREBMP_DOWN);
						iBmp_colorize(bmp, &lrc, colorMouseDown, false, 0.25f);
						setBackStyle(objChild, _BACK_STYLE_TRANSPARENT);
						setVisible(objChild, _LOGICAL_TRUE);

					} else if (objChild->objType == _OBJ_TYPE_IMAGE && isName(objChild, cgcName_iconMaximize)) {
						// Adjust the size
						iObj_setSize(objChild, objChild->rc.left, objChild->rc.top, bmpVjrIcon->bi.biWidth, bmpVjrIcon->bi.biHeight);

						// Maximize icon
						setPictureBmp(objChild, bmpMaximize);
						setPictureBmpDown(objChild, bmpMaximize);
						setPictureBmpOver(objChild, bmpMaximize);

						// Add highlighting for the over and down
						bmp = iObjProp_get_bitmap(objChild, _INDEX_PICTUREBMP_OVER);			iBmp_colorize(bmp, &lrc, colorMouseOver, false, 0.25f);
						bmp = iObjProp_get_bitmap(objChild, _INDEX_PICTUREBMP_DOWN);			iBmp_colorize(bmp, &lrc, colorMouseDown, false, 0.25f);
						setBackStyle(objChild, _BACK_STYLE_TRANSPARENT);
						setVisible(objChild, _LOGICAL_TRUE);

					} else if (objChild->objType == _OBJ_TYPE_IMAGE && isName(objChild, cgcName_iconClose)) {
						// Adjust the size
						iObj_setSize(objChild, objChild->rc.left, objChild->rc.top, bmpVjrIcon->bi.biWidth, bmpVjrIcon->bi.biHeight);

						// Close icon
						setPictureBmp(objChild, bmpClose);
						setPictureBmpDown(objChild, bmpClose);
						setPictureBmpOver(objChild, bmpClose);

						// Add highlighting for the over and down
						bmp = iObjProp_get_bitmap(objChild, _INDEX_PICTUREBMP_OVER);			iBmp_colorize(bmp, &lrc, colorMouseOver, false, 0.25f);
						bmp = iObjProp_get_bitmap(objChild, _INDEX_PICTUREBMP_DOWN);			iBmp_colorize(bmp, &lrc, colorMouseDown, false, 0.25f);
						setBackStyle(objChild, _BACK_STYLE_TRANSPARENT);
						setVisible(objChild, _LOGICAL_TRUE);
					}

					// Move to next object
					objChild = (SObject*)objChild->ll.next;
				}
		}
	}

	void iiSubobj_resetToDefaultSubform(SObject* subform, bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount)
	{
		SObject*	objChild;
		SBitmap*	bmp;
		RECT		lrc;


		logfunc(__FUNCTION__);
		if (subform)
		{
			//////////
			// Reset the common settings
			//////
				iiObj_resetToDefaultCommon(subform, true, true, propList, tnPropCount);


			//////////
			// Set default size and position
			//////
				SetRect(&subform->rc, 0, 0, 200, 100);
				SetRect(&subform->rco, 0, 0, 200, 100);
				SetRect(&subform->rcp, 0, 0, 200, 100);

				// Set the size of the child components
				iObj_setSize(subform, 0, 0, 200, 100);

				// Font
				iFont_delete(&subform->p.font, true);
				subform->p.font = iFont_duplicate(gsFontDefault);


			//////////
			// Set the defaults
			//////
				setAnchor(subform, _ANCHOR_FIXED_NORESIZE);
				setBackColor(subform, whiteColor);
				setBackStyle(subform, _BACK_STYLE_TRANSPARENT);
				setForeColor(subform, blackColor);
				setIcon(subform, bmpVjrIcon);
				setCaption(subform, cgcName_subform);


			//////////
			// Events
			//////
				*(uptr*)&subform->ev.general.activate		= (uptr)&iDefaultCallback_onActivate;
				*(uptr*)&subform->ev.general.deactivate		= (uptr)&iDefaultCallback_onDeactivate;


			//////////
			// Default child settings
			//////
				SetRect(&lrc, 0, 0, bmpArrowUl->bi.biWidth, bmpArrowUl->bi.biHeight);
				objChild = subform->firstChild;
				while (objChild)
				{
					// See which object this is
					if (objChild->objType == _OBJ_TYPE_IMAGE && isName(objChild, cgcName_icon))
					{
						// Adjust the size
						iObj_setSize(objChild, objChild->rc.left, objChild->rc.top, bmpVjrIcon->bi.biWidth, bmpVjrIcon->bi.biHeight);

						// Form icon
						setPictureBmp(objChild, bmpVjrIcon);
						setPictureBmpDown(objChild, bmpVjrIcon);
						setPictureBmpOver(objChild, bmpVjrIcon);

						// Add highlighting for the over and down
						bmp = iObjProp_get_bitmap(objChild, _INDEX_PICTUREBMP_OVER);			iBmp_colorize(bmp, &lrc, colorMouseOver, false, 0.5f);
						bmp = iObjProp_get_bitmap(objChild, _INDEX_PICTUREBMP_DOWN);			iBmp_colorize(bmp, &lrc, colorMouseDown, false, 0.5f);
						setBackStyle(objChild, _BACK_STYLE_TRANSPARENT);
						setVisible(objChild, _LOGICAL_TRUE);

					} else if (objChild->objType == _OBJ_TYPE_LABEL && isName(objChild, cgcName_caption)) {
						// Caption
						iObjProp_set_character_direct(objChild, _INDEX_CAPTION, cgcName_formCaption, -1);
						iObjProp_set_s32_direct(objChild, _INDEX_BACKSTYLE, _BACK_STYLE_TRANSPARENT);
						iFont_delete(&objChild->p.font, true);
						objChild->p.font = iFont_create(cgcFontName_windowTitleBar, 10, FW_NORMAL, false, false);
						setVisible(objChild, _LOGICAL_TRUE);
					}

					// Move to next object
					objChild = (SObject*)objChild->ll.next;
				}
		}
	}

	void iiSubobj_resetToDefaultCarousel(SObject* carousel, bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount)
	{
		RECT		lrc;
		SBitmap*	bmp;
		SObject*	objChild;


		logfunc(__FUNCTION__);
		if (carousel)
		{
			//////////
			// Reset the common settings
			//////
				iiObj_resetToDefaultCommon(carousel, true, true, propList, tnPropCount);


			//////////
			// Set default size and position
			//////
				SetRect(&carousel->rc, 0, 0, 320, 480);
				SetRect(&carousel->rco, 0, 0, 320, 480);
				SetRect(&carousel->rcp, 0, 0, 320, 480);

				// Set the size
				iObj_setSize(carousel, 0, 0, 320, 480);


			//////////
			// Default child settings
			//////
				SetRect(&lrc, 0, 0, bmpArrowUl->bi.biWidth, bmpArrowUl->bi.biHeight);
				objChild = carousel->firstChild;
				while (objChild)
				{
					// See which object this is
					if (objChild->objType == _OBJ_TYPE_IMAGE && isName(objChild, cgcName_icon))
					{
						// Adjust the size
						iObj_setSize(objChild, objChild->rc.left, objChild->rc.top, bmpCarouselIcon->bi.biWidth, bmpCarouselIcon->bi.biHeight);

						// Carousel icon
						iObjProp_set_bitmap_direct(objChild, _INDEX_PICTUREBMP,			bmpCarouselIcon);
						iObjProp_set_bitmap_direct(objChild, _INDEX_PICTUREBMP_DOWN,	bmpCarouselIcon);
						iObjProp_set_bitmap_direct(objChild, _INDEX_PICTUREBMP_OVER,	bmpCarouselIcon);

						// Add highlighting for the over and down
						bmp = iObjProp_get_bitmap(objChild, _INDEX_PICTUREBMP_OVER);			iBmp_colorize(bmp, &lrc, colorMouseOver, false, 0.25f);
						bmp = iObjProp_get_bitmap(objChild, _INDEX_PICTUREBMP_DOWN);			iBmp_colorize(bmp, &lrc, colorMouseDown, false, 0.25f);
						setVisible(objChild, _LOGICAL_TRUE);

					} else if (objChild->objType == _OBJ_TYPE_LABEL && isName(objChild, cgcName_caption)) {
						// Caption
						setCaption(objChild, cgcName_formCaption);
						iObjProp_set_s32_direct(objChild, _INDEX_BACKSTYLE, _BACK_STYLE_TRANSPARENT);
						iFont_delete(&objChild->p.font, true);
						objChild->p.font = iFont_create(cgcFontName_windowTitleBar, 12, FW_NORMAL, false, false);
						setVisible(objChild, _LOGICAL_TRUE);

					} else if (objChild->objType == _OBJ_TYPE_IMAGE && isName(objChild, cgcName_iconClose)) {
						// Adjust the size
						iObj_setSize(objChild, objChild->rc.left, objChild->rc.top, bmpCarouselIcon->bi.biWidth, bmpCarouselIcon->bi.biHeight);

						// Close icon
						iObjProp_set_bitmap_direct(objChild, _INDEX_PICTUREBMP,			bmpClose);
						iObjProp_set_bitmap_direct(objChild, _INDEX_PICTUREBMP_DOWN,	bmpClose);
						iObjProp_set_bitmap_direct(objChild, _INDEX_PICTUREBMP_OVER,	bmpClose);

						// Add highlighting for the over and down
						bmp = iObjProp_get_bitmap(objChild, _INDEX_PICTUREBMP_OVER);			iBmp_colorize(bmp, &lrc, colorMouseOver, false, 0.25f);
						bmp = iObjProp_get_bitmap(objChild, _INDEX_PICTUREBMP_DOWN);			iBmp_colorize(bmp, &lrc, colorMouseDown, false, 0.25f);
						setVisible(objChild, _LOGICAL_TRUE);
					}

					// Move to next object
					objChild = (SObject*)objChild->ll.next;
				}

		}
	}

	void iiSubobj_resetToDefaultRider(SObject* rider, bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount)
	{
		logfunc(__FUNCTION__);
		if (rider)
		{
			//////////
			// Reset the common settings
			//////
				iiObj_resetToDefaultCommon(rider, true, true, propList, tnPropCount);


			//////////
			// Set default size and position
			//////
				SetRect(&rider->rc, 0, 0, 320, 480);
				SetRect(&rider->rco, 0, 0, 320, 480);
				SetRect(&rider->rcp, 0, 0, 320, 480);

				// Set the size
				iObj_setSize(rider, 0, 0, 320, 480);
		}
	}

	void iiSubobj_resetToDefaultLabel(SObject* label, bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount)
	{
		logfunc(__FUNCTION__);
		if (label)
		{
			//////////
			// Reset the common settings
			//////
				iiObj_resetToDefaultCommon(label, true, true, propList, tnPropCount);


			//////////
			// Set default size and position
			//////
				SetRect(&label->rc, 0, 0, 40, 17);
				SetRect(&label->rco, 0, 0, 40, 17);
				SetRect(&label->rcp, 0, 0, 40, 17);

				// Set the size
				iObj_setSize(label, 0, 0, 40, 17);

				// Font
				iFont_delete(&label->p.font, true);
				label->p.font = iFont_duplicate(gsFontDefault);


			//////////
			// Set the default colors
			//////
				setBackColor(label, whiteColor);
				setForeColor(label, blackColor);


			//////////
			// Set the characteristics
			//////
				setAlignment(label, _ALIGNMENT_LEFT);
				setCaption(label, cgcName_label);
				setBackStyle(label, _BACK_STYLE_TRANSPARENT);
				setBorderStyle(label, _BORDER_STYLE_NONE);
				setBorderColor(label, blackColor);
				setDisabledBackColor(label, disabledBackColor);
				setDisabledForeColor(label, disabledForeColor);
		}
	}

	void iiSubobj_resetToDefaultTextbox(SObject* textbox, bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount)
	{
		logfunc(__FUNCTION__);
		if (textbox)
		{
			//////////
			// Reset the common settings
			//////
				iiObj_resetToDefaultCommon(textbox, true, true, propList, tnPropCount);


			//////////
			// Set default size and position
			//////
				SetRect(&textbox->rc, 0, 0, 100, 23);
				SetRect(&textbox->rco, 0, 0, 100, 23);
				SetRect(&textbox->rcp, 0, 0, 100, 23);

				// Set the size
				iObj_setSize(textbox, 0, 0, 100, 23);

				// Font
				iFont_delete(&textbox->p.font, true);
				textbox->p.font = iFont_duplicate(gsFontDefault);


			//////////
			// Set the defaults
			//////
				setAnchor(textbox, _ANCHOR_FIXED_NORESIZE);
				setBackColor(textbox, whiteColor);
				setForeColor(textbox, blackColor);
				setStyle(textbox, _STYLE_3D);
				setAlignment(textbox, _ALIGNMENT_LEFT);
				setBackStyle(textbox, _BACK_STYLE_OPAQUE);
				setBorderStyle(textbox, _BORDER_STYLE_NONE);
				setBorderColor(textbox, blackColor);
				setSelectedBackColor(textbox, selectedBackColor);
				setSelectedForeColor(textbox, selectedForeColor);
				setDisabledBackColor(textbox, disabledBackColor);
				setDisabledForeColor(textbox, disabledForeColor);


			//////////
			// Indicate the callback handler
			//////
				*(u32*)&textbox->ev.general.onInteractiveChange	= *(u32*)&iDefaultCallback_onInteractiveChange;
				*(u32*)&textbox->ev.general.onProgrammaticChange	= *(u32*)&iDefaultCallback_onProgrammaticChange;
		}
	}

	void iiSubobj_resetToDefaultButton(SObject* button, bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount)
	{
		logfunc(__FUNCTION__);
		if (button)
		{
			//////////
			// Reset the common settings
			//////
				iiObj_resetToDefaultCommon(button, true, true, propList, tnPropCount);


			//////////
			// Set default size and position
			//////
				SetRect(&button->rc, 0, 0, 84, 27);
				SetRect(&button->rco, 0, 0, 84, 27);
				SetRect(&button->rcp, 0, 0, 84, 27);

				// Set the size
				iObj_setSize(button, 0, 0, 84, 27);

				// Font
				button->p.font = iFont_duplicate(gsFontDefault);


			//////////
			// Set the default properties
			//////
				setBackColor(button, grayColor);
				setForeColor(button, blackColor);
				setStyle(button, _STYLE_3D);
				setAlignment(button, _ALIGNMENT_CENTER);
				setBackStyle(button, _BACK_STYLE_TRANSPARENT);
				setCaption(button, cgcName_button);
				setDisabledBackColor(button, disabledBackColor);
				setDisabledForeColor(button, disabledForeColor);


			//////////
			// Events
			//////
				*(u32*)&button->ev.general.onInteractiveChange	= *(u32*)&iDefaultCallback_onInteractiveChange;
				*(u32*)&button->ev.general.onProgrammaticChange	= *(u32*)&iDefaultCallback_onProgrammaticChange;
		}
	}

	void iiSubobj_resetToDefaultEditbox(SObject* editbox, bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount)
	{
		logfunc(__FUNCTION__);
		if (editbox)
		{
			//////////
			// Reset the common settings
			//////
				iiObj_resetToDefaultCommon(editbox, true, true, propList, tnPropCount);


			//////////
			// Set default size and position
			//////
				SetRect(&editbox->rc, 0, 0, 100, 53);
				SetRect(&editbox->rco, 0, 0, 100, 53);
				SetRect(&editbox->rcp, 0, 0, 100, 53);

				// Set the size
				iObj_setSize(editbox, 0, 0, 100, 53);

				// Font
				editbox->p.font = iFont_duplicate(gsFontDefault);


			//////////
			// Set the defaults
			//////
				setBackColor(editbox, whiteColor);
				setForeColor(editbox, blackColor);
				setStyle(editbox, _STYLE_3D);
				setAlignment(editbox, _ALIGNMENT_LEFT);
				setBackStyle(editbox, _BACK_STYLE_OPAQUE);
				setBorderStyle(editbox, _BORDER_STYLE_NONE);
				setBorderColor(editbox, blackColor);
				setSelectedBackColor(editbox, selectedBackColor);
				setSelectedBackColor(editbox, selectedForeColor);
				setDisabledBackColor(editbox, disabledBackColor);
				setDisabledForeColor(editbox, disabledForeColor);

				iSEM_deleteChain(&editbox->p.sem, true);
				editbox->p.sem = iSEM_allocate(false);


			//////////
			// Events
			//////
				*(u32*)&editbox->ev.general.onInteractiveChange		= *(u32*)&iDefaultCallback_onInteractiveChange;
				*(u32*)&editbox->ev.general.onProgrammaticChange	= *(u32*)&iDefaultCallback_onProgrammaticChange;
		}
	}

	void iiSubobj_resetToDefaultImage(SObject* image, bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount)
	{
		logfunc(__FUNCTION__);
		if (image)
		{
			//////////
			// Reset the common settings
			//////
				iiObj_resetToDefaultCommon(image, true, true, propList, tnPropCount);


			//////////
			// Set default size and position
			//////
				SetRect(&image->rc, 0, 0, 100, 36);
				SetRect(&image->rco, 0, 0, 100, 36);
				SetRect(&image->rcp, 0, 0, 100, 36);

				// Set the size
				iObj_setSize(image, 0, 0, 100, 36);


			//////////
			// Set the default values
			//////
				setStyle(image, _IMAGE_STYLE_OPAQUE);
				setPictureBmp(image, bmpNoImage);


			//////////
			// Events
			//////
				*(u32*)&image->ev.general.onProgrammaticChange	= *(u32*)&iDefaultCallback_onProgrammaticChange;
		}
	}

	void iiSubobj_resetToDefaultCheckbox(SObject* checkbox, bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount)
	{
		SObject*	objChild;
		SBitmap*	bmp;
		RECT		lrc;


		logfunc(__FUNCTION__);
		if (checkbox)
		{
			//////////
			// Reset the common settings
			//////
				iiObj_resetToDefaultCommon(checkbox, true, true, propList, tnPropCount);


			//////////
			// Set default size, position, font
			//////
				SetRect(&checkbox->rc, 0, 0, 60, 17);
				SetRect(&checkbox->rco, 0, 0, 60, 17);
				SetRect(&checkbox->rcp, 0, 0, 60, 17);

				// Set the size
				iObj_setSize(checkbox, 0, 0, 60, 17);

				// Font
				checkbox->p.font = iFont_duplicate(gsFontDefault9);


			//////////
			// Set the default values
			//////
				setValue_s32(checkbox, 0);

				setBackColor(checkbox, whiteColor);
				setForeColor(checkbox, blackColor);
				setAlignment(checkbox, _ALIGNMENT_LEFT);
				setStyle(checkbox, _STYLE_3D);
				setCaption(checkbox, cgcName_checkbox);
				setBackStyle(checkbox, _BACK_STYLE_TRANSPARENT);
				setBorderStyle(checkbox, _BORDER_STYLE_NONE);
				setBorderColor(checkbox, blackColor);
				setDisabledBackColor(checkbox, disabledBackColor);
				setDisabledForeColor(checkbox, disabledForeColor);


			//////////
			// Events
			//////
				*(u32*)&checkbox->ev.general.onInteractiveChange	= *(u32*)&iDefaultCallback_onInteractiveChange;
				*(u32*)&checkbox->ev.general.onProgrammaticChange	= *(u32*)&iDefaultCallback_onProgrammaticChange;


			//////////
			// Default child settings
			//////
				SetRect(&lrc, 0, 0, bmpArrowUl->bi.biWidth, bmpArrowUl->bi.biHeight);
				objChild = checkbox->firstChild;
				while (objChild)
				{
					// See which object this is
					if (objChild->objType == _OBJ_TYPE_IMAGE && isName(objChild, cgcName_checkboxImage))
					{
						// Adjust the size
						iObj_setSize(objChild, objChild->rc.left, objChild->rc.top, 17, objChild->rc.bottom);

						// Checkbox image
						bmp = iBmp_allocate();
						iBmp_createBySize(bmp, 17, 17, 24);

						// Based on type, populate the image
						if (iObjProp_get_s32_direct(checkbox, _INDEX_VALUE) == 0)
						{
							// Off
							iBmp_scale(bmp, bmpCheckboxOff);	// Set the new

						} else {
							// On
							iBmp_scale(bmp, bmpCheckboxOn);		// Set the new
						}

						// Replicate that image for the over and down images
						iObjProp_set_bitmap_direct(objChild, _INDEX_PICTUREBMP,			bmp);
						iObjProp_set_bitmap_direct(objChild, _INDEX_PICTUREBMP_DOWN,	bmp);
						iObjProp_set_bitmap_direct(objChild, _INDEX_PICTUREBMP_OVER,	bmp);

						// Delete the temporary image
						iBmp_delete(&bmp, true, true);

						// Add highlighting for the over and down
						bmp = iObjProp_get_bitmap(objChild, _INDEX_PICTUREBMP_OVER);			iBmp_colorize(bmp, &lrc, colorMouseOver, false, 0.5f);
						bmp = iObjProp_get_bitmap(objChild, _INDEX_PICTUREBMP_DOWN);			iBmp_colorize(bmp, &lrc, colorMouseDown, false, 0.5f);

						// Mark it for re-rendering
						objChild->isDirtyRender	= true;
						setVisible(objChild, _LOGICAL_TRUE);

					} else if (objChild->objType == _OBJ_TYPE_LABEL && isName(objChild, cgcName_checkboxLabel)) {
						// Adjust the size
						iObj_setSize(objChild, 17, 0, 60, objChild->rc.bottom);

						// Checkbox label
						setCaption(objChild, cgcName_checkbox);
						setBackStyle(objChild, _BACK_STYLE_TRANSPARENT);
						iFont_delete(&objChild->p.font, true);
						objChild->p.font = iFont_duplicate(checkbox->p.font);

						// Mark it for re-rendering
						objChild->isDirtyRender	= true;
						setVisible(objChild, _LOGICAL_TRUE);
					}

					// Move to next object
					objChild = (SObject*)objChild->ll.next;
				}
		}
	}

	void iiSubobj_resetToDefaultOption(SObject* option, bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount)
	{
		logfunc(__FUNCTION__);
		if (option)
		{
			//////////
			// Reset the common settings
			//////
				iiObj_resetToDefaultCommon(option, true, true, propList, tnPropCount);


			//////////
			// Set default size and position
			//////
				SetRect(&option->rc, 0, 0, 60, 40);
				SetRect(&option->rco, 0, 0, 60, 40);
				SetRect(&option->rcp, 0, 0, 60, 40);

				// Set the size
				iObj_setSize(option, 0, 0, 60, 40);

				// Font
				option->p.font = iFont_duplicate(gsFontDefault9);


			//////////
			// Set the default values
			//////
				setBackColor(option, whiteColor);
				setForeColor(option, blackColor);
				setAlignment(option, _ALIGNMENT_LEFT);
				setStyle(option, _STYLE_3D);
				setCount(option, 0);
				setMultiSelect(option, _LOGICAL_FALSE);


			//////////
			// Events
			//////
				*(u32*)&option->ev.general.onSelect				= *(u32*)&iDefaultCallback_onSelect;
				*(u32*)&option->ev.general.onDeselect			= *(u32*)&iDefaultCallback_onDeselect;
				*(u32*)&option->ev.general.onInteractiveChange	= *(u32*)&iDefaultCallback_onInteractiveChange;
				*(u32*)&option->ev.general.onProgrammaticChange	= *(u32*)&iDefaultCallback_onProgrammaticChange;
		}
	}

	void iiSubobj_resetToDefaultRadio(SObject* radio, bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount)
	{
		logfunc(__FUNCTION__);
		if (radio)
		{
			//////////
			// Reset the common settings
			//////
				iiObj_resetToDefaultCommon(radio, true, true, propList, tnPropCount);


			//////////
			// Set default size and position
			//////
				SetRect(&radio->rc, 0, 0, 72, 72);
				SetRect(&radio->rco, 0, 0, 72, 72);
				SetRect(&radio->rcp, 0, 0, 72, 72);

				// Set the size
				iObj_setSize(radio, 0, 0, 72, 72);

				// Font
				radio->p.font  = iFont_duplicate(gsFontDefault);


			//////////
			// Set the default properties
			//////
				setBackColor(radio, whiteColor);
				setForeColor(radio, blackColor);
				setAlignment(radio, _ALIGNMENT_LEFT);
				setStyle(radio, _STYLE_3D);

				setValue_f64(radio, 1.0);
				setValueMinimum(radio, 1.0);
				setValueMaximum(radio, 100.0);
				setValueRoundTo(radio, 1.0f);

				setBackStyle(radio, _BACK_STYLE_OPAQUE);
				setBorderStyle(radio, _BORDER_STYLE_NONE);
				setBorderColor(radio, blackColor);
				setDisabledBackColor(radio, disabledBackColor);
				setDisabledForeColor(radio, disabledForeColor);


			//////////
			// Events
			//////
				*(u32*)&radio->ev.general.onInteractiveChange	= *(u32*)&iDefaultCallback_onInteractiveChange;
				*(u32*)&radio->ev.general.onProgrammaticChange	= *(u32*)&iDefaultCallback_onProgrammaticChange;
		}
	}




	void iiSubobj_resetToDefaultCmdGroup(SObject* cmdGroup, bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount)
	{
	}

	void iiSubobj_resetToDefaultOptGroup(SObject* optGroup, bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount)
	{
	}

	void iiSubobj_resetToDefaultListbox(SObject* listbox, bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount)
	{
	}

	void iiSubobj_resetToDefaultCombobox(SObject* combobox, bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount)
	{
	}

	void iiSubobj_resetToDefaultFormset(SObject* formset, bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount)
	{
	}

	void iiSubobj_resetToDefaultToolbar(SObject* toolbar, bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount)
	{
	}

	void iiSubobj_resetToDefaultSeparator(SObject* separator, bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount)
	{
	}

	void iiSubobj_resetToDefaultLine(SObject* line, bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount)
	{
	}

	void iiSubobj_resetToDefaultShape(SObject* shape, bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount)
	{
	}

	void iiSubobj_resetToDefaultContainer(SObject* container, bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount)
	{
	}

	void iiSubobj_resetToDefaultControl(SObject* control, bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount)
	{
	}

	void iiSubobj_resetToDefaultGrid(SObject* grid, bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount)
	{
	}

	void iiSubobj_resetToDefaultColumn(SObject* column, bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount)
	{
	}

	void iiSubobj_resetToDefaultHeader(SObject* header, bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount)
	{
	}

	void iiSubobj_resetToDefaultOleBound(SObject* oleBound, bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount)
	{
	}

	void iiSubobj_resetToDefaultOleContain(SObject* oleContain, bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount)
	{
	}

	void iiSubobj_resetToDefaultSpinner(SObject* spinner, bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount)
	{
	}

	void iiSubobj_resetToDefaultTimer(SObject* timer, bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount)
	{
	}

	void iiSubobj_resetToDefaultHyperlink(SObject* hyperlink, bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount)
	{
	}

	void iiSubobj_resetToDefaultCollection(SObject* collection, bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount)
	{
	}

	void iiSubobj_resetToDefaultPage(SObject* page, bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount)
	{
	}

	void iiSubobj_resetToDefaultPageframe(SObject* pageframe, bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount)
	{
	}

	void iiSubobj_resetToDefaultSession(SObject* session, bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount)
	{
	}

	void iiSubobj_resetToDefaultCustom(SObject* custom, bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount)
	{
	}

	void iiSubobj_resetToDefaultException(SObject* exception, bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propList, u32 tnPropCount)
	{
	}
