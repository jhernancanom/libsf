//////////
//
// /libsf/source/vjr/objects.cpp
//
//////
// Version 0.34
// Copyright (c) 2014 by Rick C. Hodgin
//////
// Last update:
//     Jun.14.2014
//////
// Change log:
//     Jun.14.2014 - Initial creation
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









//////////
//
// Creates the object structure
//
//////
	SObject* iObj_create(u32 objType, SObject* objParent)
	{
		// We need to create it
		switch (objType)
		{
			case _OBJ_TYPE_EMPTY:		// Empty, used as a placeholder object that is not drawn
				return(iSubobj_createEmpty(NULL, objParent));
				break;

			case _OBJ_TYPE_FORM:			// Form class, the main outer window the OS sees
				return(iSubobj_createForm(NULL, objParent));
				break;

			case _OBJ_TYPE_SUBFORM:		// A new class which has its own drawing content and can be moved about using UI features
				return(iSubobj_createSubform(NULL, objParent));
				break;

			case _OBJ_TYPE_LABEL:		// A label
				return(iSubobj_createLabel(NULL, objParent));
				break;

			case _OBJ_TYPE_TEXTBOX:		// An input textbox
				return(iSubobj_createTextbox(NULL, objParent));
				break;

			case _OBJ_TYPE_BUTTON:		// A push button
				return(iSubobj_createButton(NULL, objParent));
				break;

			case _OBJ_TYPE_EDITBOX:		// An input multi-line editbox
				return(iSubobj_createEditbox(NULL, objParent));

			case _OBJ_TYPE_IMAGE:		// A graphical image
				return(iSubobj_createImage(NULL, objParent));

			case _OBJ_TYPE_CHECKBOX:		// A checkbox
				return(iSubobj_createCheckbox(NULL, objParent));

			case _OBJ_TYPE_OPTION:		// A combination selection
				return(iSubobj_createOption(NULL, objParent));

			case _OBJ_TYPE_RADIO:		// A radio dial, which can also present as a slider or spinner
				return(iSubobj_createRadio(NULL, objParent));

			default:
// TODO:  We should never get here... we should fire off an internal consistency error
				return(NULL);
		}
	}




//////////
//
// Called to create an object and append it to the
// indicated object as a child.
//
//////
//
// Returns:
//		SObject*		-- To new object which was added
//		sub_obj_output	-- Populated with the pointer of the sub-object
//
//////
	SObject* iObj_addChild(u32 objType, SObject* objParent)
	{
		SObject* objNew;


		// Make sure our environment is sane
		objNew = NULL;
		if (objParent)
		{
			// Create the new object using the default template
			objNew = iObj_create(objType, objParent);

			// Append if valid
			if (objNew)
				iObj_appendObjToParent(objParent, objNew);
		}

		// Indicate our status
		return(objNew);
	}




//////////
//
// Copy the indicated object
//
//////
	SObject* iObj_copy(SObject* template_obj, SObject* next, SObject* parent, bool tlCopyChildren, bool tlCreateSeparateBitmapBuffers)
	{
		SObject* obj;


		// Create the object
		obj = (SObject*)malloc(sizeof(SObject));
		if (obj)
		{
			//////////
			// Initialize the object
			//////
				memset(obj, 0, sizeof(SObject));


			//////////
			// Copy the object's existing contents
			//////
// TODO:  Need to copy other properties here as well
				if (template_obj)
					memcpy(&obj->p, &template_obj->p, sizeof(obj->p));		// Copy the existing object properties


			//////////
			// Update the next and parent, and clear out any bmpScaled
			//////
				obj->ll.next	= (SLL*)next;
				obj->parent		= parent;
				obj->bmpScaled	= NULL;


			//////////
			// Copy the bitmap, subojects, and/or children (if need be)
			//////
				if (template_obj)
				{
					// Duplicate the bitmap buffer if need be
					if (tlCreateSeparateBitmapBuffers)
						obj->bmp = iBmp_copy(template_obj->bmp);

					// Copy children if need be
					if (tlCopyChildren && template_obj->firstChild)
						obj->firstChild = iObj_copy(template_obj->firstChild, NULL, obj, true, tlCreateSeparateBitmapBuffers);
				}
		}

		// Indicate our success or failure
		return(obj);
	}




//////////
//
// Delete the indicated object.
//
//////
	void iObj_delete(SObject** objRoot, bool tlDeleteSelf)
	{
		SObject* obj;


		// Make sure our environment is sane
		if (objRoot && *objRoot)
		{
			obj = *objRoot;
// TODO:  write this code
		}
	}




//////////
//
// Called to get a list of controls which have focus
//
//////
	void iObj_findFocusControls(SObject* obj, SBuilder* objFocusControls, bool tlProcessSiblings)
	{
		SObject* objSib;


		//////////
		// Process any children first
		//////
			if (obj->firstChild)
				iObj_findFocusControls(obj->firstChild, objFocusControls, true);

		
		//////////
		// Process self
		//////
			if (obj->p.hasFocus)
				iBuilder_append_u32(objFocusControls, (u32)obj);


		//////////
		// Process any siblings
		//////
			if (tlProcessSiblings)
			{
				// Iterate through every sibling and process it, but don't process its siblings
				objSib = (SObject*)obj->ll.next;
				while (objSib)
				{
					// Process this sibling
					iObj_findFocusControls(objSib, objFocusControls, false);

					// Move to next sibling
					objSib = (SObject*)objSib->ll.next;
				}
			}
	}




//////////
//
// Called to mark the object dirty.
//
//////
	void iObj_setDirty(SObject* obj, bool tlMarkParents)
	{
		if (obj)
		{
			// Mark the object dirty
			obj->isDirty = true;

			// Mark the parent
			if (tlMarkParents && obj->parent)
				iObj_setDirty(obj->parent, true);
		}
	}




//////////
//
// Called to render the indicated object
//
//////
	u32 iObj_render(SObject* obj, bool tlForceRender)
	{
		u32 lnPixelsRendered;


		// Make sure our environment is sane
		lnPixelsRendered = 0;
		if (obj && obj->isRendered)
		{
			// If they're forcing a render, set it up
			obj->isDirty |= tlForceRender;

			// Which object are they rendering?
			switch (obj->objType)
			{
				case _OBJ_TYPE_EMPTY:		// Empty, used as a placeholder object that is not drawn
					lnPixelsRendered += iSubobj_renderEmpty(obj);
					break;

				case _OBJ_TYPE_FORM:			// Form class, the main outer window the OS sees
					lnPixelsRendered += iSubobj_renderForm(obj);
					break;

				case _OBJ_TYPE_SUBFORM:		// A new class which has its own drawing content and can be moved about using UI features
					lnPixelsRendered += iSubobj_renderSubform(obj);
					break;

				case _OBJ_TYPE_LABEL:		// A label
					lnPixelsRendered += iSubobj_renderLabel(obj);
					break;

				case _OBJ_TYPE_TEXTBOX:		// An input textbox
					lnPixelsRendered += iSubobj_renderTextbox(obj);
					break;

				case _OBJ_TYPE_BUTTON:		// A push button
					lnPixelsRendered += iSubobj_renderButton(obj);
					break;

				case _OBJ_TYPE_EDITBOX:		// An input multi-line editbox
					lnPixelsRendered += iSubobj_renderEditbox(obj);
					break;

				case _OBJ_TYPE_IMAGE:		// A graphical image
					lnPixelsRendered += iSubobj_renderImage(obj);
					break;

				case _OBJ_TYPE_CHECKBOX:		// A checkbox
					lnPixelsRendered += iSubobj_renderCheckbox(obj);
					break;

				case _OBJ_TYPE_OPTION:		// A combination selection
					lnPixelsRendered += iSubobj_renderOption(obj);
					break;

				case _OBJ_TYPE_RADIO:		// A radio dial, which can also present as a slider or spinner
					lnPixelsRendered += iSubobj_renderRadio(obj);
					break;

				default:
// TODO:  We should never get here... we should fire off an internal consistency error
					break;
			}
		}

		// Indicate how many pixels were rendered
		return(lnPixelsRendered);
	}




//////////
//
// Called from subobjects to render any object children and sibling they may have based on flags
//
//////
	void iObj_renderChildrenAndSiblings(SObject* obj, bool tlRenderChildren, bool tlRenderSiblings, bool tlForceRender)
	{
		SObject* objSib;


		//////////
		// Render any children
		//////
			if (tlRenderChildren && obj->firstChild)
				iObj_renderChildrenAndSiblings(obj->firstChild, true, true, tlForceRender);


		//////////
		// Render self
		//////
			if (tlForceRender || obj->isDirty)
				iObj_render(obj, tlForceRender);

		//////////
		// Render any siblings
		//////
			if (tlRenderSiblings && obj->ll.next)
			{
				objSib = (SObject*)obj->ll.next;
				while (objSib)
				{
					// Render this sibling
					iObj_renderChildrenAndSiblings(objSib, true, false, tlForceRender);

					// Move to next sibling
					objSib = (SObject*)objSib->ll.next;
				}
			}
	}




//////////
//
// Called to publish the indicated object, which takes the rendered bitmaps of all child objects
// and overlays them where they should be.
//
//////
	u32 iObj_publish(SBitmap* bmpDst, RECT* rc, SObject* obj, bool tlPublishChildren, bool tlPublishSiblings)
	{
		u32			lnWidth, lnHeight, lnPixelsRendered;
		RECT		lrc, lrcParent, lrc2;
		SObject*	objSib;


		// Make sure our environment is sane
		lnPixelsRendered = 0;
		if (obj && obj->bmp)
		{
			//////////
			// Determine the position within the parent's rectangle where this object will go
			//////
				// Adjust this item within the parent's rectangle
				SetRect(&lrc,	rc->left	+ obj->rc.left,
								rc->top		+ obj->rc.top,
								rc->left	+ obj->rc.right,
								rc->top		+ obj->rc.bottom);

				// Default the parent rectangle for any subsequent drawing within
				SetRect(&lrcParent, 0, 0, obj->bmp->bi.biWidth, obj->bmp->bi.biHeight);

				// This is a top-level entry, so adjust everything to rcClient, or to 0
				switch (obj->objType)
				{
					case _OBJ_TYPE_FORM:
					case _OBJ_TYPE_SUBFORM:
						// Bypass the frame area
						CopyRect(&lrcParent, &obj->rcClient);
						break;
				}


			//////////
			// Clip the publication to the target rectangle
			//////
				lrc.right	= min(rc->right, lrc.right);
				lrc.bottom	= min(rc->bottom, lrc.bottom);


			//////////
			// Publish any children
			//////
				if (tlPublishChildren && obj->firstChild)
					lnPixelsRendered += iObj_publish(obj->bmp, &lrcParent, obj->firstChild, true, true);


			//////////
			// Publish this item
			//////
				// The size of the bitmap should equal the size of the rectangle on the parent.
				lnWidth		= obj->rc.right - obj->rc.left;
				lnHeight	= obj->rc.bottom - obj->rc.top;
				// If it's different, then we need to scale the content
				if (lnWidth != obj->bmp->bi.biWidth || lnHeight != obj->bmp->bi.biHeight)
				{
					// Need to scale, but do we need to create or alter our scaled target bitmap?
					if (!obj->bmpScaled || lnWidth != obj->bmpScaled->bi.biWidth || lnHeight != obj->bmpScaled->bi.biHeight)
					{
						// Delete any existing bitmap
						iBmp_delete(&obj->bmpScaled, true, true);

						// Create the new one
						obj->bmpScaled = iBmp_allocate();
						iBmp_createBySize(obj->bmpScaled, lnWidth, lnHeight, 24);
						// Now when we scale into it, it will be the right size
					}

					// Perform the scale
					iBmp_scale(obj->bmpScaled, obj->bmp);

					// Perform the bitblt
					if (bmpDst && obj->isPublished)
					{
						// If it's not enabled, grayscale it
						if (!obj->p.isEnabled)
						{
							SetRect(&lrc2, 0, 0, obj->bmpScaled->bi.biWidth, obj->bmpScaled->bi.biHeight);
							iBmp_grayscale(obj->bmpScaled, &lrc2);
						}


						//////////
						// Copy
						//////
							switch (obj->objType)
							{
								case _OBJ_TYPE_IMAGE:
								case _OBJ_TYPE_LABEL:
									if (obj->p.isOpaque)		lnPixelsRendered += iBmp_bitBlt(bmpDst,		&lrc, obj->bmpScaled);
									else						lnPixelsRendered += iBmp_bitBltMask(bmpDst,	&lrc, obj->bmpScaled);
									break;

								default:
									lnPixelsRendered += iBmp_bitBlt(bmpDst, &lrc, obj->bmpScaled);
									break;
							}
					}

				} else {
					// We can just copy
					if (bmpDst && obj->isPublished)
					{
						// If it's not enabled, grayscale it
						if (!obj->p.isEnabled)
						{
							SetRect(&lrc2, 0, 0, obj->bmp->bi.biWidth, obj->bmp->bi.biHeight);
							iBmp_grayscale(obj->bmp, &lrc2);
						}


						//////////
						// Copy
						//////
							switch (obj->objType)
							{
								case _OBJ_TYPE_IMAGE:
									if (obj->p.isOpaque)		lnPixelsRendered += iBmp_bitBlt(bmpDst, &lrc, obj->bmp);
									else						lnPixelsRendered += iBmp_bitBltMask(bmpDst, &lrc, obj->bmp);
									break;

								case _OBJ_TYPE_LABEL:
									if (obj->p.isOpaque)		lnPixelsRendered += iBmp_bitBlt(bmpDst, &lrc, obj->bmp);
									else						lnPixelsRendered += iBmp_bitBlt_byGraymask(bmpDst, &lrc, obj->bmp, obj->p.foreColor);
									break;

								default:
									lnPixelsRendered += iBmp_bitBlt(bmpDst, &lrc, obj->bmp);
									break;
							}
					}
				}


			//////////
			// Publish any siblings
			//////
				if (tlPublishSiblings)
				{
					// Begin at the next sibling
					objSib = (SObject*)obj->ll.next;
					while (objSib)
					{
						// Publish this sibling
						lnPixelsRendered += iObj_publish(bmpDst, rc, objSib, true, false);

						// Move to next sibling
						objSib = (SObject*)objSib->ll.next;
					}
				}
		}
// s8 buffer[256];
// sprintf(buffer, "c:\\temp\\publish_%u.bmp\0", (u32)obj);
// iBmp_saveToDisk(bmpDst, buffer);



		//////////
		// Indicate how many pixels were painted
		//////
			return(lnPixelsRendered);
	}




//////////
//
// Duplicate the chain of ObjectLabels, so the destination has a copy of each.
//
//////
	void iObj_duplicateChain(SObject** root, SObject* chain)
	{
		SObject*	obj;
		SObject**	oPrevPtr;


		// Create the master record
		if (root)
		{
			// Repeat adding as many entries as there are
			oPrevPtr = root;
			while (chain)
			{
				// Create this object
				obj = iObj_copy(chain, NULL, chain, true, true);
				if (obj)
				{
					// Update the duplicate object's forward pointer in the chain
					*oPrevPtr = obj;

					// Setup the next forward pointer
					oPrevPtr = (SObject**)&obj->ll.next;
				}

				// Move to next item in the chain
				chain = (SObject*)chain->ll.next;
			}
		}
	}




//////////
//
// Called to append the indicated object to the parent
//
//////
	void iObj_appendObjToParent(SObject* parent, SObject* obj)
	{
		// Make sure our environment is sane
		if (parent && obj)
			iLl_appendExistingNodeAtEnd((SLL**)&parent->firstChild, (SLL*)obj);
	}




//////////
//
// Called to duplicate the child objects to this object
//
//////
	void iObj_duplicateChildren(SObject* objDst, SObject* objSrc)
	{
		SObject*	objChild;
		SObject*	objCopy;


		// Make sure our environment is sane
		if (objDst && objSrc && objSrc->firstChild)
		{
			// Duplicate this entry
			objChild = objSrc->firstChild;
			while (objChild)
			{
				// Create the copy (note that all children are automatically copied by using the reference as a template)
				switch (objChild->objType)
				{
					case _OBJ_TYPE_EMPTY:
						objCopy = iSubobj_createForm(objChild, objDst);
						break;

					case _OBJ_TYPE_FORM:
						objCopy = iSubobj_createForm(objChild, objDst);
						break;

					case _OBJ_TYPE_SUBFORM:
						objCopy = iSubobj_createSubform(objChild, objDst);
						break;

					case _OBJ_TYPE_LABEL:
						objCopy = iSubobj_createLabel(objChild, objDst);
						break;

					case _OBJ_TYPE_TEXTBOX:
						objCopy = iSubobj_createTextbox(objChild, objDst);
						break;

					case _OBJ_TYPE_BUTTON:
						objCopy = iSubobj_createButton(objChild, objDst);
						break;

					case _OBJ_TYPE_EDITBOX:
						objCopy = iSubobj_createEditbox(objChild, objDst);
						break;

					case _OBJ_TYPE_IMAGE:
						objCopy = iSubobj_createImage(objChild, objDst);
						break;

					case _OBJ_TYPE_CHECKBOX:
						objCopy = iSubobj_createCheckbox(objChild, objDst);
						break;

					case _OBJ_TYPE_OPTION:
						objCopy = iSubobj_createOption(objChild, objDst);
						break;

					case _OBJ_TYPE_RADIO:
						objCopy = iSubobj_createRadio(objChild, objDst);
						break;

					default:
						objCopy = NULL;
						break;
				}

				// Append the copy if valid
				if (objCopy)
					iObj_appendObjToParent(objDst, objChild);

				// Move to next
				objChild = (SObject*)objChild->ll.next;
			}
		}
	}




//////////
//
// Called to set the object size
//
//////
	void iObj_setSize(SObject* obj, s32 tnLeft, s32 tnTop, s32 tnWidth, s32 tnHeight)
	{
		SObject* objChild;


		// Resize if need be (32-bit bitmap for labels, 24-bit for everything else)
		obj->bmp = iBmp_verifySizeOrResize(obj->bmp, tnWidth, tnHeight, 24);

		// Position and size its rectangle
		SetRect(&obj->rc,			tnLeft, tnTop, tnLeft + tnWidth, tnTop + tnHeight);
		CopyRect(&obj->rcClient,	&obj->rc);

		// Update the client area
		switch (obj->objType)
		{
			case _OBJ_TYPE_EMPTY:
				// Just use the default rcClient settings above
				break;

			case _OBJ_TYPE_FORM:
				SetRect(&obj->rcClient, 8, bmpArrowUl->bi.biHeight + 2, tnWidth - bmpArrowUl->bi.biHeight - 2, tnHeight - bmpArrowUl->bi.biHeight - 1);

				//////////
				// Default child settings:
				// [icon][caption                     ][move][minimize][maximize][close]
				//////
					objChild = obj->firstChild;
					while (objChild)
					{
						// See which object this is
						if (objChild->objType == _OBJ_TYPE_IMAGE && iDatum_compare(&objChild->pa.name, cgcName_icon, sizeof(cgcName_icon) - 1) == 0)
						{
							// Form icon
							SetRect(&objChild->rc,
										bmpArrowUl->bi.biWidth + 4 - obj->rcClient.left,
										1 - obj->rcClient.top,
										bmpArrowUl->bi.biWidth + 4 - obj->rcClient.left + bmpArrowUl->bi.biWidth,
										1 + bmpArrowUl->bi.biHeight - obj->rcClient.top);

							// Update the size
							iObj_setSize(objChild, objChild->rc.left, objChild->rc.top, objChild->rc.right - objChild->rc.left, objChild->rc.bottom - objChild->rc.top);

						} else if (objChild->objType == _OBJ_TYPE_LABEL && iDatum_compare(&objChild->pa.name, cgcCaption_icon, sizeof(cgcCaption_icon) - 1) == 0) {
							// Caption
							SetRect(&objChild->rc,
										bmpArrowUl->bi.biWidth + 4 + bmpArrowUl->bi.biWidth + 4 - obj->rcClient.left,
										1 - obj->rcClient.top,
										tnWidth - (5 * (bmpArrowUl->bi.biWidth + 4)) - 1,
										1 + bmpArrowUl->bi.biHeight - obj->rcClient.top);

							// Update the size
							iObj_setSize(objChild, objChild->rc.left, objChild->rc.top, objChild->rc.right - objChild->rc.left, objChild->rc.bottom - objChild->rc.top);

						} else if (objChild->objType == _OBJ_TYPE_IMAGE && iDatum_compare(&objChild->pa.name, cgcName_iconMove, sizeof(cgcName_iconMove) - 1) == 0) {
							// Move icon
							SetRect(&objChild->rc,
										tnWidth - (5 * (bmpArrowUl->bi.biWidth + 4)) - obj->rcClient.left,
										1 - obj->rcClient.top,
										(tnWidth - (5 * (bmpArrowUl->bi.biWidth + 4))) + bmpArrowUl->bi.biWidth,
										1 + bmpArrowUl->bi.biHeight - obj->rcClient.top);

							// Update the size
							iObj_setSize(objChild, objChild->rc.left, objChild->rc.top, objChild->rc.right - objChild->rc.left, objChild->rc.bottom - objChild->rc.top);

						} else if (objChild->objType == _OBJ_TYPE_IMAGE && iDatum_compare(&objChild->pa.name, cgcName_iconMinimize, sizeof(cgcName_iconMinimize) - 1) == 0) {
							// Minimize icon
							SetRect(&objChild->rc,
										tnWidth - (4 * (bmpArrowUl->bi.biWidth + 4)) - obj->rcClient.left,
										1 - obj->rcClient.top,
										(tnWidth - (4 * (bmpArrowUl->bi.biWidth + 4))) + bmpArrowUl->bi.biWidth,
										1 + bmpArrowUl->bi.biHeight - obj->rcClient.top);

							// Update the size
							iObj_setSize(objChild, objChild->rc.left, objChild->rc.top, objChild->rc.right - objChild->rc.left, objChild->rc.bottom - objChild->rc.top);

						} else if (objChild->objType == _OBJ_TYPE_IMAGE && iDatum_compare(&objChild->pa.name, cgcName_iconMaximize, sizeof(cgcName_iconMaximize) - 1) == 0) {
							// Maximize icon
							SetRect(&objChild->rc,
										tnWidth - (3 * (bmpArrowUl->bi.biWidth + 4)) - obj->rcClient.left,
										1 - obj->rcClient.top,
										(tnWidth - (3 * (bmpArrowUl->bi.biWidth + 4))) + bmpArrowUl->bi.biWidth,
										1 + bmpArrowUl->bi.biHeight - obj->rcClient.top);

							// Update the size
							iObj_setSize(objChild, objChild->rc.left, objChild->rc.top, objChild->rc.right - objChild->rc.left, objChild->rc.bottom - objChild->rc.top);

						} else if (objChild->objType == _OBJ_TYPE_IMAGE && iDatum_compare(&objChild->pa.name, cgcName_iconClose, sizeof(cgcName_iconClose) - 1) == 0) {
							// Close icon
							SetRect(&objChild->rc,
										tnWidth - (2 * (bmpArrowUl->bi.biWidth + 4)) - obj->rcClient.left,
										1 - obj->rcClient.top,
										(tnWidth - (2 * (bmpArrowUl->bi.biWidth + 4))) + bmpArrowUl->bi.biWidth,
										1 + bmpArrowUl->bi.biHeight - obj->rcClient.top);

							// Update the size
							iObj_setSize(objChild, objChild->rc.left, objChild->rc.top, objChild->rc.right - objChild->rc.left, objChild->rc.bottom - objChild->rc.top);
						}

						// Move to next object
						objChild = (SObject*)objChild->ll.next;
					}

				break;

			case _OBJ_TYPE_SUBFORM:
				SetRect(&obj->rcClient, 0, bmpArrowUl->bi.biHeight, tnWidth - 8, tnHeight);
				break;

			case _OBJ_TYPE_LABEL:
				// Just use the default rcClient settings above
				break;

			case _OBJ_TYPE_TEXTBOX:
				// Just use the default rcClient settings above
				break;

			case _OBJ_TYPE_BUTTON:
				// Just use the default rcClient settings above
				break;

			case _OBJ_TYPE_EDITBOX:
				// Just use the default rcClient settings above
				break;

			case _OBJ_TYPE_IMAGE:
				// Just use the default rcClient settings above
				break;

			case _OBJ_TYPE_CHECKBOX:
				// Just use the default rcClient settings above
				break;

			case _OBJ_TYPE_OPTION:
				// Just use the default rcClient settings above
				break;

			case _OBJ_TYPE_RADIO:
				// Just use the default rcClient settings above
				break;
		}

		// Mark it dirty for a full re-render
		obj->isDirty = true;
	}




//////////
//
// Called to create the Windows-side window for the form.  The normal bit buffer is
// rendered regardless of whether or not the form is presented outwardly.  It can be
// used as an off-screen buffer in that way.
//
//////
	SWindow* iObj_createWindowForForm(SObject* obj_form, SWindow* winReuse, s32 icon)
	{
		SWindow* winNew;


		// Make sure our environment is sane
		winNew = NULL;
		if (obj_form)
			winNew = iWindow_createForObject(obj_form, winReuse, icon);

		// Indicate our status
		return(winNew);
	}




//////////
//
// Called to set the visible status of the indicated object.
// Returns the previous visible status.
//
//////
	bool iObj_setVisible(SObject* obj, bool tlNewVisible)
	{
		bool llOldVisible;


		// Make sure our environment is sane
		llOldVisible = false;
		if (obj)
		{
			llOldVisible		= obj->p.isVisible;
			obj->p.isVisible	= tlNewVisible;
		}

		// Indicate prior visible
		return(llOldVisible);
	}




//////////
//
// Searches the indicated object for the indicated property
//
//////
	SVariable* iObj_getPropertyAsVariable(SObject* obj, s8* tcPropertyName, u32 tnPropertyNameLength, SComp* comp)
	{
		SBaseclassList* lbcl;
		SPropertyList*	lpl;


		// Make sure our environment is sane
		if (obj)
		{
			// Find out our property interface
			lbcl = iiObj_getBaseclass_byType(obj->objType);
			if (lbcl)
			{
				// Search through the properties
				lpl = lbcl->objProps;
				while (lpl && lpl->textName)
				{
					// Is this the name?
					if (lpl->textNameLength == tnPropertyNameLength && _memicmp(tcPropertyName, lpl->textName, tnPropertyNameLength) == 0)
					{
						// This is the property, retrieve its value
						return(lpl->get(obj));
					}

					// Move to next property
					++lpl;
				}
				// If we get here, we didn't find it on the object
			}
		}
		// If we get here, wasn't found
		return(NULL);
	}




//////////
//
// Called to reset the object's properties to their default values.
// Only an internal function, and only used during initialization.
// After that the main gobj_default* objects are used for creating
// all default base class objects thereafter.
//
//////
	void iiObj_resetToDefault(SObject* obj, bool tlResetProperties, bool tlResetMethods)
	{
		// Make sure our environment is sane
		if (obj)
		{
			// Update the sub-object data
			switch (obj->objType)
			{
				case _OBJ_TYPE_EMPTY:		// Empty, used as a placeholder object that is not drawn
					iiSubobj_resetToDefaultEmpty(obj, tlResetProperties, tlResetMethods);
					break;

				case _OBJ_TYPE_FORM:			// Form class, the main outer window the OS sees
					iiSubobj_resetToDefaultForm(obj, tlResetProperties, tlResetMethods);
					break;

				case _OBJ_TYPE_SUBFORM:		// A new class which has its own drawing content and can be moved about using UI features
					iiSubobj_resetToDefaultSubform(obj, tlResetProperties, tlResetMethods);
					break;

				case _OBJ_TYPE_LABEL:		// A label
					iiSubobj_resetToDefaultLabel(obj, tlResetProperties, tlResetMethods);
					break;

				case _OBJ_TYPE_TEXTBOX:		// An input textbox
					iiSubobj_resetToDefaultTextbox(obj, tlResetProperties, tlResetMethods);
					break;

				case _OBJ_TYPE_BUTTON:		// A push button
					iiSubobj_resetToDefaultButton(obj, tlResetProperties, tlResetMethods);
					break;

				case _OBJ_TYPE_EDITBOX:		// An input multi-line editbox
					iiSubobj_resetToDefaultEditbox(obj, tlResetProperties, tlResetMethods);
					break;

				case _OBJ_TYPE_IMAGE:		// A graphical image
					iiSubobj_resetToDefaultImage(obj, tlResetProperties, tlResetMethods);
					break;

				case _OBJ_TYPE_CHECKBOX:		// A checkbox
					iiSubobj_resetToDefaultCheckbox(obj, tlResetProperties, tlResetMethods);
					break;

				case _OBJ_TYPE_OPTION:		// A combination selection
					iiSubobj_resetToDefaultOption(obj, tlResetProperties, tlResetMethods);
					break;

				case _OBJ_TYPE_RADIO:		// A radio dial, which can also present as a slider or spinner
					iiSubobj_resetToDefaultRadio(obj, tlResetProperties, tlResetMethods);
					break;

				default:
// TODO:  We should never get here... we should fire off an internal consistency error
					break;
			}
		}
	}




//////////
//
// Resets common object properties to their defaults
//
//////
	void iiObj_resetToDefaultCommon(SObject* obj, bool tlResetProperties, bool tlResetMethods)
	{
		/////////
		// Information about the object itself
		//////
			obj->p.tabIndex					= 0;
			obj->p.tabStop					= true;
			obj->p.helpContextId			= -1;
			obj->p.hasWhatsThisButton		= false;
			obj->p.hasWhatsThisHelp			= false;
			obj->p.whatsThisHelpId			= -1;


		//////////
		// Clear out the comment and tag
		//////
			iDatum_delete(&obj->pa.tag, false);


		//////////
		// Clear out the mouse information
		//////
			iBmp_delete(&obj->pa.mouseIcon, true, true);
			obj->p.mousePointer				= _MOUSE_POINTER_DEFAULT;


		//////////
		// Object flags
		//////
			obj->p.isEnabled				= true;
			obj->p.hasFocus					= false;
			obj->p.isMovable				= true;
			obj->p.isVisible				= false;
			// Related to rendering
			obj->isRendered					= true;
			obj->isPublished				= true;
			obj->isDirty					= true;


		//////////
		// Any properties within
		//////
			if (tlResetProperties)
				iVariable_politelyDeleteChain(&obj->firstProperty, true);


		//////////
		// Any methods defined
		//////
			if (tlResetMethods)
				iEditManager_deleteChain(&obj->firstMethod, true);


		//////////
		// Events
		//////
			iEvents_resetToDefault(&obj->ev);


		//////////
		// Remove any prior renderings, and reset render parameters
		//////
			iBmp_delete(&obj->bmp, true, true);
			iBmp_delete(&obj->bmpPriorRendered, true, true);
			iBmp_delete(&obj->bmpScaled, true, true);
			obj->scrollOffsetX	= 0;
			obj->scrollOffsetY	= 0;
			obj->isScaled		= false;


		//////////
		// Reset the object's size
		//////
			iObj_setSize(obj, obj->rc.left, obj->rc.top, obj->rc.right - obj->rc.left, obj->rc.bottom - obj->rc.top);
	}




//////////
//
// Called to translate the text-based class name to its internal object type.
//
//////
	s32 iiObj_getBaseclass_byName(s8* tcTextname, s32 tnTextnameLength)
	{
		SBaseclassList* lbcl;
		
		
		// Iterate through each function for matches
		lbcl = &gsKnownBaseclasses[0];
		while (lbcl && lbcl->baseclassName != NULL)
		{
			// Is this the named function?
			if (lbcl->baseclassNameLength == tnTextnameLength && _memicmp(tcTextname, (s8*)lbcl->baseclassName, tnTextnameLength) == 0)
				return(lbcl->objType);

			// Move to next function
			++lbcl;
		}
		// If we get here, not found
		return(-1);
	}




//////////
//
// Called to translate the class object type to its text-base name
//
//////
	SBaseclassList* iiObj_getBaseclass_byType(u32 tnObjType)
	{
		SBaseclassList* lbcl;
		
		
		// Iterate through each function for matches
		lbcl = &gsKnownBaseclasses[0];
		while (lbcl && lbcl->baseclassName != NULL)
		{
			// Is this the named function?
			if (lbcl->objType == tnObjType)
				return(lbcl);

			// Move to next function
			++lbcl;
		}
		// If we get here, not found
		return(NULL);
	}




//////////
//
// Creates the empty object structure
//
//////
	SObject* iSubobj_createEmpty(SObject* template_empty, SObject* parent)
	{
		SObject* emptyNew;


		//////////
		// Create the indicated item
		//////
			emptyNew = (SObject*)malloc(sizeof(SObject));


		//////////
		// If successful, initialize it
		//////
			if (emptyNew)
			{
				// Initialize
				memset(emptyNew, 0, sizeof(SObject));

				// Initially populate
				emptyNew->objType		= _OBJ_TYPE_EMPTY;
				emptyNew->parent		= parent;
				emptyNew->p.isEnabled	= true;
				emptyNew->isRendered	= true;
				emptyNew->isPublished	= true;
				iDatum_duplicate(&emptyNew->pa.name,		cgcName_empty, -1);
				iDatum_duplicate(&emptyNew->pa.className,	cgcName_empty, -1);
				iEvents_resetToDefault(&emptyNew->ev);

				// Initialize based on template
				if (template_empty)
				{
					// Copy from indicated template
					iiSubobj_copyEmpty(emptyNew, template_empty);

				} else {
					// Use VJr defaults
					iiSubobj_resetToDefaultEmpty(emptyNew, true, true);
				}

			}


		//////////
		// Indicate our success or failure
		//////
			return(emptyNew);
	}




//////////
//
// Creates the form object structure
//
//////
	SObject* iSubobj_createForm(SObject* template_form, SObject* parent)
	{
		SObject*	formNew;
		SObject*	icon;
		SObject*	caption;
		SObject*	move;
		SObject*	minimize;
		SObject*	maximize;
		SObject*	close;


		//////////
		// Create the indicated item
		//////
			formNew = (SObject*)malloc(sizeof(SObject));


		//////////
		// If successful, initialize it
		//////
			if (formNew)
			{
				// Initialize
				memset(formNew, 0, sizeof(SObject));

				// Initially populate
				formNew->objType		= _OBJ_TYPE_FORM;
				formNew->parent			= parent;
				formNew->p.isEnabled	= true;
				formNew->isRendered		= true;
				formNew->isPublished	= true;
				iDatum_duplicate(&formNew->pa.name,			cgcName_form, -1);
				iDatum_duplicate(&formNew->pa.className,	cgcName_form, -1);
				iEvents_resetToDefault(&formNew->ev);
				iObj_setSize(formNew, 0, 0, 375, 250);

				// Initialize based on template
				if (template_form)
				{
					// Copy from indicated template
					iiSubobj_copyForm(formNew, template_form);

				} else {
					//////////
					// Create the default children for this object
					//////
						icon		= iObj_addChild(_OBJ_TYPE_IMAGE, formNew);
						caption		= iObj_addChild(_OBJ_TYPE_LABEL, formNew);
						move		= iObj_addChild(_OBJ_TYPE_IMAGE, formNew);
						minimize	= iObj_addChild(_OBJ_TYPE_IMAGE, formNew);
						maximize	= iObj_addChild(_OBJ_TYPE_IMAGE, formNew);
						close		= iObj_addChild(_OBJ_TYPE_IMAGE, formNew);


					//////////
					// Give them proper names
					//////
						iDatum_duplicate(&icon->pa.name,		cgcName_icon,			-1);
						iDatum_duplicate(&caption->pa.name,		cgcCaption_icon,		-1);
						iDatum_duplicate(&move->pa.name,		cgcName_iconMove,		-1);
						iDatum_duplicate(&minimize->pa.name,	cgcName_iconMinimize,	-1);
						iDatum_duplicate(&maximize->pa.name,	cgcName_iconMaximize,	-1);
						iDatum_duplicate(&close->pa.name,		cgcName_iconClose,		-1);


					//////////
					// Use VJr defaults
					//////
						iiSubobj_resetToDefaultForm(formNew, true, true);
				}
			}


		//////////
		// Indicate our success or failure
		//////
			return(formNew);
	}




//////////
//
// Creates the subform object structure
//
//////
	SObject* iSubobj_createSubform(SObject* template_subform, SObject* parent)
	{
		SObject*	subformNew;
		SObject*	icon;
		SObject*	caption;


		//////////
		// Create the indicated item
		//////
			subformNew = (SObject*)malloc(sizeof(SObject));


		//////////
		// If successful, initialize it
		//////
			if (subformNew)
			{
				// Initialize
				memset(subformNew, 0, sizeof(SObject));

				// Initially populate
				subformNew->objType		= _OBJ_TYPE_SUBFORM;
				subformNew->parent		= parent;
				subformNew->p.isEnabled	= true;
				subformNew->isRendered	= true;
				subformNew->isPublished	= true;
				iDatum_duplicate(&subformNew->pa.name,		cgcName_subform, -1);
				iDatum_duplicate(&subformNew->pa.className,	cgcName_subform, -1);
				iEvents_resetToDefault(&subformNew->ev);
				iObj_setSize(subformNew, 0, 0, 200, 100);

				// Initialize based on template
				if (template_subform)
				{
					// Copy from indicated template
					iiSubobj_copySubform(subformNew, template_subform);

				} else {
					//////////
					// Create the default children for this object
					//////
						icon		= iObj_addChild(_OBJ_TYPE_IMAGE, subformNew);
						caption		= iObj_addChild(_OBJ_TYPE_LABEL, subformNew);


					//////////
					// Give them proper names
					//////
						iDatum_duplicate(&icon->pa.name,	cgcName_icon,		-1);
						iDatum_duplicate(&caption->pa.name,	cgcCaption_icon,	-1);


					//////////
					// Use VJr defaults
					//////
						iiSubobj_resetToDefaultSubform(subformNew, true, true);
				}
			}


		//////////
		// Indicate our success or failure
		//////
			return(subformNew);
	}




//////////
//
// Creates the label object structure
//
//////
	SObject* iSubobj_createLabel(SObject* template_label, SObject* parent)
	{
		SObject* labelNew;


		//////////
		// Create the indicated item
		//////
			labelNew = (SObject*)malloc(sizeof(SObject));


		//////////
		// If successful, initialize it
		//////
			if (labelNew)
			{
				// Initialize
				memset(labelNew, 0, sizeof(SObject));

				// Initially populate
				labelNew->objType		= _OBJ_TYPE_LABEL;
				labelNew->parent		= parent;
				labelNew->p.isEnabled	= true;
				labelNew->isRendered	= true;
				labelNew->isPublished	= true;
				iDatum_duplicate(&labelNew->pa.name,		cgcName_label, -1);
				iDatum_duplicate(&labelNew->pa.className,	cgcName_label, -1);
				iEvents_resetToDefault(&labelNew->ev);
				iObj_setSize(labelNew, 0, 0, 40, 17);

				// Initialize based on template
				if (template_label)
				{
					// Copy from indicated template
					iiSubobj_copyLabel(labelNew, template_label);

				} else {
					// Use VJr defaults
					iiSubobj_resetToDefaultLabel(labelNew, true, true);
				}
			}


		//////////
		// Indicate our success or failure
		//////
			return(labelNew);
	}




//////////
//
// Creates the textbox object structure
//
//////
	SObject* iSubobj_createTextbox(SObject* template_textbox, SObject* parent)
	{
		SObject* textboxNew;


		//////////
		// Create the indicated item
		//////
			textboxNew = (SObject*)malloc(sizeof(SObject));


		//////////
		// If successful, initialize it
		//////
			if (textboxNew)
			{
				// Initialize
				memset(textboxNew, 0, sizeof(SObject));

				// Initially populate
				textboxNew->objType		= _OBJ_TYPE_TEXTBOX;
				textboxNew->parent		= parent;
				textboxNew->p.isEnabled	= true;
				textboxNew->isRendered	= true;
				textboxNew->isPublished	= true;
				iDatum_duplicate(&textboxNew->pa.name,		cgcName_textbox, -1);
				iDatum_duplicate(&textboxNew->pa.className,	cgcName_textbox, -1);
				iEvents_resetToDefault(&textboxNew->ev);
				iObj_setSize(textboxNew, 0, 0, 100, 23);

				// Initialize based on template
				if (template_textbox)
				{
					// Copy from indicated template
					iiSubobj_copyTextbox(textboxNew, template_textbox);

				} else {
					// Use VJr defaults
					iiSubobj_resetToDefaultTextbox(textboxNew, true, true);
				}
			}


		//////////
		// Indicate our success or failure
		//////
			return(textboxNew);
	}




//////////
//
// Creates the button object structure
//
//////
	SObject* iSubobj_createButton(SObject* template_button, SObject* parent)
	{
		SObject* buttonNew;


		//////////
		// Create the indicated item
		//////
			buttonNew = (SObject*)malloc(sizeof(SObject));


		//////////
		// If successful, initialize it
		//////
			if (buttonNew)
			{
				// Initialize
				memset(buttonNew, 0, sizeof(SObject));

				// Initially populate
				buttonNew->objType		= _OBJ_TYPE_BUTTON;
				buttonNew->parent		= parent;
				buttonNew->p.isEnabled	= true;
				buttonNew->isRendered	= true;
				buttonNew->isPublished	= true;
				iDatum_duplicate(&buttonNew->pa.name,		cgcName_button, -1);
				iDatum_duplicate(&buttonNew->pa.className,	cgcName_button, -1);
				iEvents_resetToDefault(&buttonNew->ev);
				iObj_setSize(buttonNew, 0, 0, 84, 27);

				// Initialize based on template
				if (template_button)
				{
					// Copy from indicated template
					iiSubobj_copyButton(buttonNew, template_button);

				} else {
					// Use VJr defaults
					iiSubobj_resetToDefaultButton(buttonNew, true, true);
				}
			}


		//////////
		// Indicate our success or failure
		//////
			return(buttonNew);
	}




//////////
//
// Creates the editbox object structure
//
//////
	SObject* iSubobj_createEditbox(SObject* template_editbox, SObject* parent)
	{
		SObject* editboxNew;


		//////////
		// Create the indicated item
		//////
			editboxNew = (SObject*)malloc(sizeof(SObject));


		//////////
		// If successful, initialize it
		//////
			if (editboxNew)
			{
				// Initialize
				memset(editboxNew, 0, sizeof(SObject));

				// Initially populate
				editboxNew->objType		= _OBJ_TYPE_EDITBOX;
				editboxNew->parent		= parent;
				editboxNew->p.isEnabled	= true;
				editboxNew->isRendered	= true;
				editboxNew->isPublished	= true;
				iDatum_duplicate(&editboxNew->pa.name,		cgcName_editbox, -1);
				iDatum_duplicate(&editboxNew->pa.className,	cgcName_editbox, -1);
				iEvents_resetToDefault(&editboxNew->ev);
				iObj_setSize(editboxNew, 0, 0, 100, 53);

				// Initialize based on template
				if (template_editbox)
				{
					// Copy from indicated template
					iiSubobj_copyEditbox(editboxNew, template_editbox);

				} else {
					// Use VJr defaults
					iiSubobj_resetToDefaultEditbox(editboxNew, true, true);
				}
			}


		//////////
		// Indicate our success or failure
		//////
			return(editboxNew);
	}




//////////
//
// Creates the image object structure
//
//////
	SObject* iSubobj_createImage(SObject* template_image, SObject* parent)
	{
		SObject* imageNew;


		//////////
		// Create the indicated item
		//////
			imageNew = (SObject*)malloc(sizeof(SObject));


		//////////
		// If successful, initialize it
		//////
			if (imageNew)
			{
				// Initialize
				memset(imageNew, 0, sizeof(SObject));

				// Initially populate
				imageNew->objType		= _OBJ_TYPE_IMAGE;
				imageNew->parent		= parent;
				imageNew->p.isEnabled	= true;
				imageNew->isRendered	= true;
				imageNew->isPublished	= true;
				iDatum_duplicate(&imageNew->pa.name,		cgcName_image, -1);
				iDatum_duplicate(&imageNew->pa.className,	cgcName_image, -1);
				iEvents_resetToDefault(&imageNew->ev);
				iObj_setSize(imageNew, 0, 0, 100, 36);

				// Initialize based on template
				if (template_image)
				{
					// Copy from indicated template
					iiSubobj_copyImage(imageNew, template_image);

				} else {
					// Use VJr defaults
					iiSubobj_resetToDefaultImage(imageNew, true, true);
				}
			}


		//////////
		// Indicate our success or failure
		//////
			return(imageNew);
	}




//////////
//
// Creates the checkbox object structure
//
//////
	SObject* iSubobj_createCheckbox(SObject* template_checkbox, SObject* parent)
	{
		SObject* checkboxNew;


		//////////
		// Create the indicated item
		//////
			checkboxNew = (SObject*)malloc(sizeof(SObject));


		//////////
		// If successful, initialize it
		//////
			if (checkboxNew)
			{
				// Initialize
				memset(checkboxNew, 0, sizeof(SObject));

				// Initially populate
				checkboxNew->objType		= _OBJ_TYPE_CHECKBOX;
				checkboxNew->parent			= parent;
				checkboxNew->p.isEnabled	= true;
				checkboxNew->isRendered		= true;
				checkboxNew->isPublished	= true;
				iDatum_duplicate(&checkboxNew->pa.name,			cgcName_checkbox, -1);
				iDatum_duplicate(&checkboxNew->pa.className,	cgcName_checkbox, -1);
				iEvents_resetToDefault(&checkboxNew->ev);
				iObj_setSize(checkboxNew, 0, 0, 60, 17);

				// Initialize based on template
				if (template_checkbox)
				{
					// Copy from indicated template
					iiSubobj_copyCheckbox(checkboxNew, template_checkbox);

				} else {
					// Use VJr defaults
					iiSubobj_resetToDefaultCheckbox(checkboxNew, true, true);
				}
			}


		//////////
		// Indicate our success or failure
		//////
			return(checkboxNew);
	}




//////////
//
// Creates the combo object structure
//
//////
	SObject* iSubobj_createOption(SObject* template_option, SObject* parent)
	{
		SObject* optionNew;


		//////////
		// Create the indicated item
		//////
			optionNew = (SObject*)malloc(sizeof(SObject));


		//////////
		// If successful, initialize it
		//////
			if (optionNew)
			{
				// Initialize
				memset(optionNew, 0, sizeof(SObject));

				// Initially populate
				optionNew->objType		= _OBJ_TYPE_OPTION;
				optionNew->parent		= parent;
				optionNew->p.isEnabled	= true;
				optionNew->isRendered	= true;
				optionNew->isPublished	= true;
				iDatum_duplicate(&optionNew->pa.name,		cgcName_option, -1);
				iDatum_duplicate(&optionNew->pa.className,	cgcName_option, -1);
				iEvents_resetToDefault(&optionNew->ev);
				iObj_setSize(optionNew, 0, 0, 60, 40);

				// Initialize based on template
				if (template_option)
				{
					// Copy from indicated template
					iiSubobj_copyOption(optionNew, template_option);

				} else {
					// Use VJr defaults
					iiSubobj_resetToDefaultOption(optionNew, true, true);
				}
			}


		//////////
		// Indicate our success or failure
		//////
			return(optionNew);
	}




//////////
//
// Creates the radio object structure
//
//////
	SObject* iSubobj_createRadio(SObject* template_radio, SObject* parent)
	{
		SObject* radioNew;


		//////////
		// Create the indicated item
		//////
			radioNew = (SObject*)malloc(sizeof(SObject));


		//////////
		// If successful, initialize it
		//////
			if (radioNew)
			{
				// Initialize
				memset(radioNew, 0, sizeof(SObject));

				// Initially populate
				radioNew->objType		= _OBJ_TYPE_RADIO;
				radioNew->parent		= parent;
				radioNew->p.isEnabled	= true;
				radioNew->isRendered	= true;
				radioNew->isPublished	= true;
				iDatum_duplicate(&radioNew->pa.name,		cgcName_radio, -1);
				iDatum_duplicate(&radioNew->pa.className,	cgcName_radio, -1);
				iEvents_resetToDefault(&radioNew->ev);
				iObj_setSize(radioNew, 0, 0, 100, 100);

				// Initialize based on template
				if (template_radio)
				{
					// Copy from indicated template
					iiSubobj_copyRadio(radioNew, template_radio);

				} else {
					// Use VJr defaults
					iiSubobj_resetToDefaultRadio(radioNew, true, true);
				}
			}


		//////////
		// Indicate our success or failure
		//////
			return(radioNew);
	}




//////////
//
// Called to copy the indicated empty from source to destination
//
//////
	void iiSubobj_copyEmpty(SObject* emptyDst, SObject* emptySrc)
	{
		//////////
		// Duplicate all children for this object
		//////
			iObj_duplicateChildren(emptyDst, emptySrc);
	}




//////////
//
// Called to copy the indicated form from source to destination
//
//////
	void iiSubobj_copyForm(SObject* formDst, SObject* formSrc)
	{
		//////////
		// Copy all standard properties
		//////
			memcpy(&formDst->p, &formSrc->p, sizeof(formDst->p));


		//////////
		// Copy the allocatables
		//////
			formDst->pa.font		= iFont_duplicate(formSrc->pa.font);
			formDst->pa.bmpIcon		= iBmp_copy(formSrc->pa.bmpIcon);
			iDatum_duplicate(&formDst->pa.caption, &formSrc->pa.caption);


		//////////
		// Copy the form-specific event handlers
		//////
			memcpy(&formDst->ev, &formSrc->ev, sizeof(formDst->ev));


		//////////
		// Duplicate all children for this object
		//////
			iObj_duplicateChildren(formDst, formSrc);
	}




//////////
//
// Called to copy the indicated empty subfrom source to destination
//
//////
	void iiSubobj_copySubform(SObject* subformDst, SObject* subformSrc)
	{
		//////////
		// Copy all standard properties
		//////
			memcpy(&subformDst->p, &subformSrc->p, sizeof(subformDst->p));


		//////////
		// Copy the allocatables
		//////
			subformDst->pa.font		= iFont_duplicate(subformSrc->pa.font);
			subformDst->pa.bmpIcon	= iBmp_copy(subformSrc->pa.bmpIcon);
			iDatum_duplicate(&subformDst->pa.caption, &subformSrc->pa.caption);

			// Picture
			iBmp_delete(&subformDst->pa.bmpPicture, true, true);
			subformDst->pa.bmpPicture = iBmp_copy(subformSrc->pa.bmpPicture);
			iDatum_duplicate(&subformDst->pa.pictureName, &subformSrc->pa.pictureName);


		//////////
		// Copy the form-specific event handlers
		//////
			memcpy(&subformDst->ev, &subformSrc->ev, sizeof(subformDst->ev));


		//////////
		// Duplicate all children for this object
		//////
			iObj_duplicateChildren(subformDst, subformSrc);
	}




//////////
//
// Called to copy the indicated label from source to destination
//
//////
	void iiSubobj_copyLabel(SObject* labelDst, SObject* labelSrc)
	{
		//////////
		// Copy all standard properties
		//////
			memcpy(&labelDst->p, &labelSrc->p, sizeof(labelDst->p));


		//////////
		// Copy the allocatables
		//////
			labelDst->pa.font		= iFont_duplicate(labelSrc->pa.font);

			// Caption
			iDatum_duplicate(&labelDst->pa.caption, &labelSrc->pa.caption);


		//////////
		// Copy the form-specific event handlers
		//////
			memcpy(&labelDst->ev, &labelSrc->ev, sizeof(labelDst->ev));


		//////////
		// Duplicate all children for this object
		//////
			iObj_duplicateChildren(labelDst, labelSrc);
	}




//////////
//
// Called to copy the indicated textbox from source to destination
//
//////
	void iiSubobj_copyTextbox(SObject* textboxDst, SObject* textboxSrc)
	{
		//////////
		// Copy all standard properties
		//////
			memcpy(&textboxDst->p, &textboxSrc->p, sizeof(textboxDst->p));


		//////////
		// Copy the allocatables
		//////
			textboxDst->pa.font		= iFont_duplicate(textboxSrc->pa.font);
			textboxDst->pa.bmpIcon	= iBmp_copy(textboxSrc->pa.bmpIcon);

			// Caption
			iDatum_duplicate(&textboxDst->pa.caption, &textboxSrc->pa.caption);

			// Value
			textboxDst->pa.value	= iVariable_create(_VAR_TYPE_CHARACTER, NULL);
			textboxDst->pa.picture	= iVariable_create(_VAR_TYPE_CHARACTER, NULL);
			textboxDst->pa.mask		= iVariable_create(_VAR_TYPE_CHARACTER, NULL);
			iVariable_copyVariable(textboxDst->pa.value,	textboxSrc->pa.value);
			iVariable_copyVariable(textboxDst->pa.picture,	textboxSrc->pa.picture);
			iVariable_copyVariable(textboxDst->pa.mask,		textboxSrc->pa.mask);


		//////////
		// Copy the form-specific event handlers
		//////
			memcpy(&textboxDst->ev, &textboxSrc->ev, sizeof(textboxDst->ev));


		//////////
		// Duplicate all children for this object
		//////
			iObj_duplicateChildren(textboxDst, textboxSrc);
	}




//////////
//
// Called to copy the indicated button from source to destination
//
//////
	void iiSubobj_copyButton(SObject* buttonDst, SObject* buttonSrc)
	{
		//////////
		// Copy all standard properties
		//////
			memcpy(&buttonDst->p, &buttonSrc->p, sizeof(buttonDst->p));


		//////////
		// Copy the allocatables
		//////
			buttonDst->pa.font		= iFont_duplicate(buttonSrc->pa.font);

			// Caption
			iDatum_duplicate(&buttonDst->pa.caption, &buttonSrc->pa.caption);

			// Picture
			iBmp_delete(&buttonDst->pa.bmpPicture, true, true);
			buttonDst->pa.bmpPicture = iBmp_copy(buttonSrc->pa.bmpPicture);
			iDatum_duplicate(&buttonDst->pa.pictureName, &buttonSrc->pa.pictureName);


		//////////
		// Copy the form-specific event handlers
		//////
			memcpy(&buttonDst->ev, &buttonSrc->ev, sizeof(buttonDst->ev));


		//////////
		// Duplicate all children for this object
		//////
			iObj_duplicateChildren(buttonDst, buttonSrc);
	}




//////////
//
// Called to copy the indicated editbox from source to destination
//
//////
	void iiSubobj_copyEditbox(SObject* editboxDst, SObject* editboxSrc)
	{
		//////////
		// Copy all standard properties
		//////
			memcpy(&editboxDst->p, &editboxSrc->p, sizeof(editboxDst->p));


		//////////
		// Copy the allocatables
		//////
			editboxDst->pa.font		= iFont_duplicate(editboxSrc->pa.font);
			editboxDst->pa.bmpIcon	= iBmp_copy(editboxSrc->pa.bmpIcon);

			// Caption
			iDatum_duplicate(&editboxDst->pa.caption, &editboxSrc->pa.caption);

			// Value
			editboxDst->pa.value	= iVariable_create(_VAR_TYPE_CHARACTER, NULL);
			editboxDst->pa.picture	= iVariable_create(_VAR_TYPE_CHARACTER, NULL);
			editboxDst->pa.mask		= iVariable_create(_VAR_TYPE_CHARACTER, NULL);
			iVariable_copyVariable(editboxDst->pa.value,	editboxSrc->pa.value);
			iVariable_copyVariable(editboxDst->pa.picture,	editboxSrc->pa.picture);
			iVariable_copyVariable(editboxDst->pa.mask,		editboxSrc->pa.mask);


		//////////
		// Copy the form-specific event handlers
		//////
			memcpy(&editboxDst->ev, &editboxSrc->ev, sizeof(editboxDst->ev));


		//////////
		// Duplicate all children for this object
		//////
			iObj_duplicateChildren(editboxDst, editboxSrc);
	}




//////////
//
// Called to copy the indicated image from source to destination
//
//////
	void iiSubobj_copyImage(SObject* imageDst, SObject* imageSrc)
	{
		//////////
		// Copy all standard properties
		//////
			memcpy(&imageDst->p, &imageSrc->p, sizeof(imageDst->p));


		//////////
		// Copy the allocatables
		//////
			// remember


		//////////
		// Copy the form-specific event handlers
		//////
			memcpy(&imageDst->ev, &imageSrc->ev, sizeof(imageDst->ev));


		//////////
		// Duplicate all children for this object
		//////
			iObj_duplicateChildren(imageDst, imageSrc);
	}




//////////
//
// Called to copy the indicated checkbox from source to destination
//
//////
	void iiSubobj_copyCheckbox(SObject* checkboxDst, SObject* checkboxSrc)
	{
		//////////
		// Copy all standard properties
		//////
			memcpy(&checkboxDst->p, &checkboxSrc->p, sizeof(checkboxDst->p));


		//////////
		// Copy the allocatables
		//////
			// remember


		//////////
		// Copy the form-specific event handlers
		//////
			memcpy(&checkboxDst->ev, &checkboxSrc->ev, sizeof(checkboxDst->ev));


		//////////
		// Duplicate all children for this object
		//////
			iObj_duplicateChildren(checkboxDst, checkboxSrc);
	}




//////////
//
// Called to copy the indicated option from source to destination
//
//////
	void iiSubobj_copyOption(SObject* optionDst, SObject* optionSrc)
	{
		//////////
		// Copy all standard properties
		//////
			memcpy(&optionDst->p, &optionSrc->p, sizeof(optionDst->p));


		//////////
		// Copy the allocatables
		//////
			// remember


		//////////
		// Copy the form-specific event handlers
		//////
			memcpy(&optionDst->ev, &optionSrc->ev, sizeof(optionDst->ev));


		//////////
		// Duplicate all children for this object
		//////
			iObj_duplicateChildren(optionDst, optionSrc);
	}




//////////
//
// Called to copy the indicated radio from source to destination
//
//////
	void iiSubobj_copyRadio(SObject* radioDst, SObject* radioSrc)
	{
		//////////
		// Copy all standard properties
		//////
			memcpy(&radioDst->p, &radioSrc->p, sizeof(radioDst->p));


		//////////
		// Copy the allocatables
		//////
			// remember


		//////////
		// Copy the form-specific event handlers
		//////
			memcpy(&radioDst->ev, &radioSrc->ev, sizeof(radioDst->ev));


		//////////
		// Duplicate all children for this object
		//////
			iObj_duplicateChildren(radioDst, radioSrc);
	}




//////////
//
// Called to reset the object to its hard defaults.
//
//////
	void iiSubobj_resetToDefaultEmpty(SObject* empty, bool tlResetProperties, bool tlResetMethods)
	{
		if (empty)
		{
			//////////
			// Reset the common settings
			//////
				iiObj_resetToDefaultCommon(empty, true, true);
		}

		// No object-specific initialization because empty objects do nothing except exist as placeholders
	}

	void iiSubobj_resetToDefaultForm(SObject* form, bool tlResetProperties, bool tlResetMethods)
	{
		SObject*	objChild;
		RECT		lrc;


		if (form)
		{
			//////////
			// Reset the common settings
			//////
				iiObj_resetToDefaultCommon(form, true, true);


			//////////
			// Set default size and position
			//////
				SetRect(&form->rc, 0, 0, 375, 250);
				SetRect(&form->rco, 0, 0, 375, 250);
				SetRect(&form->rcp, 0, 0, 375, 250);

				// Set the size of the child components
				iObj_setSize(form, 0, 0, 375, 250);


			//////////
			// Set default anchor to fixed in all positions, no resize
			//////
				form->p.anchor				= _ANCHOR_FIXED_NORESIZE;
		

			//////////
			// Set the default font
			//////
				iFont_delete(&form->pa.font, true);
				form->pa.font					= iFont_duplicate(gsFontDefault);


			//////////
			// Set the default colors
			//////
				form->p.nwRgba.color		= NwColor.color;
				form->p.neRgba.color		= NeColor.color;
				form->p.swRgba.color		= SwColor.color;
				form->p.seRgba.color		= SeColor.color;
				form->p.backColor.color		= white.color;
				form->p.foreColor.color		= black.color;
				form->p.captionColor.color	= dark_blue.color;


			//////////
			// Set the default form icon
			//////
				iBmp_delete(&form->pa.bmpIcon, true, true);
				form->pa.bmpIcon			= iBmp_copy(bmpVjrIcon);


			//////////
			// Set the default caption
			//////
				iDatum_duplicate(&form->pa.caption, cgcName_form, -1);


			//////////
			// Set the default form-specific events
			//////
				*(u32*)&form->ev.general.activate		= (u32)&iDefaultCallback_onActivate;
				*(u32*)&form->ev.general.deactivate		= (u32)&iDefaultCallback_onDeactivate;


			//////////
			// Reset our min/max
			//////
				SetRect(&form->p.rcMax, -1, -1, -1, -1);
				SetRect(&form->p.rcMin, -1, -1, -1, -1);


			//////////
			// Clear the picture
			//////
				iBmp_delete(&form->pa.bmpPicture, true, true);


			//////////
			// General flags and settings
			//////
				form->p.allowOutput						= true;
				form->p.alwaysOnBottom					= false;
				form->p.alwaysOnTop						= false;
				form->p.autoCenter						= false;
				form->p.borderStyle						= _BORDER_STYLE_SIZABLE;
				form->p.isClosable						= true;
				form->p.processKeyPreviewEvents			= false;
				form->p.hasControlBox					= true;
				form->p.hasMinButton					= true;
				form->p.hasMaxButton					= true;
				form->p.hasCloseButton					= true;
				form->p.scaleMode						= _SCALE_MODE_PIXELS;
				form->p.showInTaskBar					= true;
				form->p.windowState						= _WINDOW_STATE_NORMAL;

				// The following are ignored, maintained only for backward compatibility
				form->p.bindControls					= true;
				form->p.bufferMode						= 2;
				form->p.clipControls					= false;
				form->p.colorSource						= 4;
				form->p.continuousScroll				= true;
				iObj_delete(&form->pa.dataSession, true);
				form->p.dataSessionId					= -1;
				iDatum_delete(&form->pa.declass, false);
				iDatum_delete(&form->pa.declasslibrary, false);
				form->p.defolecid						= -1;
				form->p.desktop							= false;
				form->p.isDockable						= false;
				form->p.isDocked						= false;
				form->p.dockPosition					= -1;
				form->p.drawmode						= -1;
				form->p.drawstyle						= 13;
				form->p.drawwidth						= 1;
				form->p.fillColor.color					= rgba(255,255,255,255);
				form->p.fillStyle						= 0;
				form->p.halfHeightCaption				= false;
				form->p.hScrollSmallChange				= 10;
				form->p.vScrollSmallChange				= 10;
				form->p.macDesktop						= false;
				form->p.mdiForm							= false;
				form->p.oleDragMode						= 0;
				iBmp_delete(&form->pa.oleDragPicture, true, true);
				form->p.oleDropEffects					= 3;
				form->p.oleDropHasData					= -1;
				form->p.oleDropMode						= 0;
				form->p.releaseType						= 0;
				form->p.rightToLeft						= false;
				form->p.scrollbars						= 3;
				form->p.showTips						= true;
				form->p.showWindow						= 2;
				form->p.sizeBox							= false;
				form->p.themes							= true;
				form->p.titleBar						= 1;
				form->p.windowType						= 0;
				form->p.zoomBox							= false;


			//////////
			// Default child settings
			//////
				SetRect(&lrc, 0, 0, bmpArrowUl->bi.biWidth, bmpArrowUl->bi.biHeight);
				objChild = form->firstChild;
				while (objChild)
				{
					// See which object this is
					if (objChild->objType == _OBJ_TYPE_IMAGE && iDatum_compare(&objChild->pa.name, cgcName_icon, sizeof(cgcName_icon) - 1) == 0)
					{
						// Adjust the size
						iObj_setSize(objChild, objChild->rc.left, objChild->rc.top, bmpVjrIcon->bi.biWidth, bmpVjrIcon->bi.biHeight);

						// Form icon
						iBmp_delete(&objChild->pa.bmpPicture,		true, true);	// Delete the old
						iBmp_delete(&objChild->pa.bmpPictureOver,	true, true);	// Delete the old
						iBmp_delete(&objChild->pa.bmpPictureDown,	true, true);	// Delete the old
						objChild->pa.bmpPicture		= iBmp_copy(bmpVjrIcon);		// Set the new
						objChild->pa.bmpPictureOver	= iBmp_copy(bmpVjrIcon);		// Set the new
						objChild->pa.bmpPictureDown	= iBmp_copy(bmpVjrIcon);		// Set the new

						// Add highlighting for the over and down
						iBmp_colorize(objChild->pa.bmpPictureOver, &lrc, colorMouseOver,	false);
						iBmp_colorize(objChild->pa.bmpPictureDown, &lrc, colorMouseDown,	false);
// iBmp_saveToDisk(objChild->pa.bmpPictureOver, "c:\\temp\\over.bmp");
// iBmp_saveToDisk(objChild->pa.bmpPictureDown, "c:\\temp\\down.bmp");

						// Icon
						iBmp_delete(&objChild->pa.bmpIcon, true, true);				// Delete the old
						objChild->pa.bmpIcon = iBmp_copy(bmpVjrIcon);				// Set the new

					} else if (objChild->objType == _OBJ_TYPE_LABEL && iDatum_compare(&objChild->pa.name, cgcCaption_icon, sizeof(cgcCaption_icon) - 1) == 0) {
						// Caption
						iDatum_delete(&objChild->pa.caption, false);
						iDatum_duplicate(&objChild->pa.caption, cgcName_formCaption, sizeof(cgcName_formCaption) - 1);
						objChild->p.isOpaque = false;
						iFont_delete(&objChild->pa.font, true);
						objChild->pa.font = iFont_create(cgcWindowTitleBarFontName, 12, FW_NORMAL, false, false);

					} else if (objChild->objType == _OBJ_TYPE_IMAGE && iDatum_compare(&objChild->pa.name, cgcName_iconMove, sizeof(cgcName_iconMove) - 1) == 0) {
						// Adjust the size
						iObj_setSize(objChild, objChild->rc.left, objChild->rc.top, bmpVjrIcon->bi.biWidth, bmpVjrIcon->bi.biHeight);

						// Move icon
						iBmp_delete(&objChild->pa.bmpPicture,		true, true);	// Delete the old
						iBmp_delete(&objChild->pa.bmpPictureOver,	true, true);	// Delete the old
						iBmp_delete(&objChild->pa.bmpPictureDown,	true, true);	// Delete the old
						objChild->pa.bmpPicture		= iBmp_copy(bmpMove);			// Set the new
						objChild->pa.bmpPictureOver	= iBmp_copy(bmpMove);			// Set the new
						objChild->pa.bmpPictureDown	= iBmp_copy(bmpMove);			// Set the new

						// Add highlighting for the over and down
						iBmp_colorize(objChild->pa.bmpPictureOver, &lrc, colorMouseOver,	false);
						iBmp_colorize(objChild->pa.bmpPictureDown, &lrc, colorMouseDown,	false);
// iBmp_saveToDisk(objChild->pa.bmpPictureOver, "c:\\temp\\over.bmp");
// iBmp_saveToDisk(objChild->pa.bmpPictureDown, "c:\\temp\\down.bmp");

						// Icon
						iBmp_delete(&objChild->pa.bmpIcon, true, true);				// Delete the old
						objChild->pa.bmpIcon = iBmp_copy(bmpMove);					// Set the new

					} else if (objChild->objType == _OBJ_TYPE_IMAGE && iDatum_compare(&objChild->pa.name, cgcName_iconMinimize, sizeof(cgcName_iconMinimize) - 1) == 0) {
						// Adjust the size
						iObj_setSize(objChild, objChild->rc.left, objChild->rc.top, bmpVjrIcon->bi.biWidth, bmpVjrIcon->bi.biHeight);

						// Minimize icon
						iBmp_delete(&objChild->pa.bmpPicture,		true, true);	// Delete the old
						iBmp_delete(&objChild->pa.bmpPictureOver,	true, true);	// Delete the old
						iBmp_delete(&objChild->pa.bmpPictureDown,	true, true);	// Delete the old
						objChild->pa.bmpPicture		= iBmp_copy(bmpMinimize);		// Set the new
						objChild->pa.bmpPictureOver	= iBmp_copy(bmpMinimize);		// Set the new
						objChild->pa.bmpPictureDown	= iBmp_copy(bmpMinimize);		// Set the new

						// Add highlighting for the over and down
						iBmp_colorize(objChild->pa.bmpPictureOver, &lrc, colorMouseOver,	false);
						iBmp_colorize(objChild->pa.bmpPictureDown, &lrc, colorMouseDown,	false);
// iBmp_saveToDisk(objChild->pa.bmpPictureOver, "c:\\temp\\over.bmp");
// iBmp_saveToDisk(objChild->pa.bmpPictureDown, "c:\\temp\\down.bmp");

						// Icon
						iBmp_delete(&objChild->pa.bmpIcon, true, true);				// Delete the old
						objChild->pa.bmpIcon = iBmp_copy(bmpMinimize);				// Set the new

					} else if (objChild->objType == _OBJ_TYPE_IMAGE && iDatum_compare(&objChild->pa.name, cgcName_iconMaximize, sizeof(cgcName_iconMaximize) - 1) == 0) {
						// Adjust the size
						iObj_setSize(objChild, objChild->rc.left, objChild->rc.top, bmpVjrIcon->bi.biWidth, bmpVjrIcon->bi.biHeight);

						// Maximize icon
						iBmp_delete(&objChild->pa.bmpPicture,		true, true);	// Delete the old
						iBmp_delete(&objChild->pa.bmpPictureOver,	true, true);	// Delete the old
						iBmp_delete(&objChild->pa.bmpPictureDown,	true, true);	// Delete the old
						objChild->pa.bmpPicture		= iBmp_copy(bmpMaximize);		// Set the new
						objChild->pa.bmpPictureOver	= iBmp_copy(bmpMaximize);		// Set the new
						objChild->pa.bmpPictureDown	= iBmp_copy(bmpMaximize);		// Set the new

						// Add highlighting for the over and down
						iBmp_colorize(objChild->pa.bmpPictureOver, &lrc, colorMouseOver,	false);
						iBmp_colorize(objChild->pa.bmpPictureDown, &lrc, colorMouseDown,	false);
// iBmp_saveToDisk(objChild->pa.bmpPictureOver, "c:\\temp\\over.bmp");
// iBmp_saveToDisk(objChild->pa.bmpPictureDown, "c:\\temp\\down.bmp");

						// Icon
						iBmp_delete(&objChild->pa.bmpIcon, true, true);				// Delete the old
						objChild->pa.bmpIcon = iBmp_copy(bmpMaximize);				// Set the new

					} else if (objChild->objType == _OBJ_TYPE_IMAGE && iDatum_compare(&objChild->pa.name, cgcName_iconClose, sizeof(cgcName_iconClose) - 1) == 0) {
						// Adjust the size
						iObj_setSize(objChild, objChild->rc.left, objChild->rc.top, bmpVjrIcon->bi.biWidth, bmpVjrIcon->bi.biHeight);

						// Close icon
						iBmp_delete(&objChild->pa.bmpPicture,		true, true);	// Delete the old
						iBmp_delete(&objChild->pa.bmpPictureOver,	true, true);	// Delete the old
						iBmp_delete(&objChild->pa.bmpPictureDown,	true, true);	// Delete the old
						objChild->pa.bmpPicture		= iBmp_copy(bmpClose);			// Set the new
						objChild->pa.bmpPictureOver	= iBmp_copy(bmpClose);			// Set the new
						objChild->pa.bmpPictureDown	= iBmp_copy(bmpClose);			// Set the new

						// Add highlighting for the over and down
						iBmp_colorize(objChild->pa.bmpPictureOver, &lrc, colorMouseOver,	false);
						iBmp_colorize(objChild->pa.bmpPictureDown, &lrc, colorMouseDown,	false);
// iBmp_saveToDisk(objChild->pa.bmpPictureOver, "c:\\temp\\over.bmp");
// iBmp_saveToDisk(objChild->pa.bmpPictureDown, "c:\\temp\\down.bmp");

						// Icon
						iBmp_delete(&objChild->pa.bmpIcon, true, true);				// Delete the old
						objChild->pa.bmpIcon = iBmp_copy(bmpClose);					// Set the new
					}

					// Move to next object
					objChild = (SObject*)objChild->ll.next;
				}
		}
	}

	void iiSubobj_resetToDefaultSubform(SObject* subform, bool tlResetProperties, bool tlResetMethods)
	{
		if (subform)
		{
			//////////
			// Reset the common settings
			//////
				iiObj_resetToDefaultCommon(subform, true, true);


			//////////
			// Set default size and position
			//////
				SetRect(&subform->rc, 0, 0, 200, 100);
				SetRect(&subform->rco, 0, 0, 200, 100);
				SetRect(&subform->rcp, 0, 0, 200, 100);

				// Set the size of the child components
				iObj_setSize(subform, 0, 0, 200, 100);


			//////////
			// Set default anchor to fixed in all positions, no resize
			//////
				subform->p.anchor = _ANCHOR_FIXED_NORESIZE;


			//////////
			// Set the default font
			//////
				iFont_delete(&subform->pa.font, true);
				subform->pa.font				= iFont_duplicate(gsFontDefault);


			//////////
			// Set the default colors
			//////
				subform->p.nwRgba.color			= NwColor.color;
				subform->p.neRgba.color			= NeColor.color;
				subform->p.swRgba.color			= SwColor.color;
				subform->p.seRgba.color			= SeColor.color;
				subform->p.backColor.color		= white.color;
				subform->p.foreColor.color		= black.color;
				subform->p.captionColor.color	= dark_blue.color;


			//////////
			// Set the default form icon
			//////
				iBmp_delete(&subform->pa.bmpIcon, true, true);
				subform->pa.bmpIcon			= iBmp_copy(bmpVjrIcon);


			//////////
			// Set the default caption
			//////
				iDatum_duplicate(&subform->pa.caption, cgcName_subform, -1);


			//////////
			// Set the default form-specific events
			//////
				*(u32*)&subform->ev.general.activate		= (u32)&iDefaultCallback_onActivate;
				*(u32*)&subform->ev.general.deactivate		= (u32)&iDefaultCallback_onDeactivate;
		}
	}

	void iiSubobj_resetToDefaultLabel(SObject* label, bool tlResetProperties, bool tlResetMethods)
	{
		u32 lnHeight;


		if (label)
		{
			//////////
			// Reset the common settings
			//////
				iiObj_resetToDefaultCommon(label, true, true);


			//////////
			// Set default size and position
			//////
				lnHeight = max(gsFontDefault->tm.tmHeight + 2, 10);
				SetRect(&label->rc, 0, 0, 40, 17);
				SetRect(&label->rco, 0, 0, 40, 17);
				SetRect(&label->rcp, 0, 0, 40, 17);

				// Set the size
				iObj_setSize(label, 0, 0, 40, 17);


			//////////
			// Set default anchor to fixed in all positions, no resize
			//////
				label->p.anchor = _ANCHOR_FIXED_NORESIZE;


			//////////
			// Set the default font
			//////
				iFont_delete(&label->pa.font, true);
				label->pa.font						= iFont_duplicate(gsFontDefault);


			//////////
			// Set the default colors
			//////
				label->p.backColor.color				= white.color;
				label->p.foreColor.color				= black.color;


			//////////
			// Set the characteristics
			//////
				label->p.alignment					= _ALIGNMENT_LEFT;
				iDatum_duplicate(&label->pa.caption, cgcName_label, 5);
				label->p.isOpaque					= false;
				label->p.isBorder					= false;
				label->p.borderColor.color			= black.color;
				label->p.disabledBackColor.color	= disabledBackColor.color;
				label->p.disabledForeColor.color	= disabledForeColor.color;
		}
	}

	void iiSubobj_resetToDefaultTextbox(SObject* textbox, bool tlResetProperties, bool tlResetMethods)
	{
		if (textbox)
		{
			//////////
			// Reset the common settings
			//////
				iiObj_resetToDefaultCommon(textbox, true, true);


			//////////
			// Set default size and position
			//////
				SetRect(&textbox->rc, 0, 0, 100, 23);
				SetRect(&textbox->rco, 0, 0, 100, 23);
				SetRect(&textbox->rcp, 0, 0, 100, 23);

				// Set the size
				iObj_setSize(textbox, 0, 0, 100, 23);


			//////////
			// Set default anchor to fixed in all positions, no resize
			//////
				textbox->p.anchor = _ANCHOR_FIXED_NORESIZE;


			//////////
			// Set the default font
			//////
				iFont_delete(&textbox->pa.font, true);
				textbox->pa.font					= iFont_duplicate(gsFontDefault);


			//////////
			// Set the default colors
			//////
				textbox->p.backColor.color			= white.color;
				textbox->p.foreColor.color			= black.color;


			//////////
			// Set the characteristics
			//////
				textbox->p.style					= _STYLE_3D;
				textbox->p.alignment				= _ALIGNMENT_LEFT;
				iVariable_delete(textbox->pa.value, false);

				textbox->p.cursor					= 0;
				textbox->p.selectStart				= -1;
				textbox->p.selectEnd				= -1;

				textbox->p.isOpaque					= true;
				textbox->p.isBorder					= false;
				textbox->p.borderColor.color		= black.color;
				textbox->p.selectedBackColor.color	= selectedBackColor.color;
				textbox->p.selectedForeColor.color	= selectedForeColor.color;
				textbox->p.disabledBackColor.color	= disabledBackColor.color;
				textbox->p.disabledForeColor.color	= disabledForeColor.color;


			//////////
			// Indicate the callback handler
			//////
				*(u32*)&textbox->ev.general.onInteractiveChange	= *(u32*)&iDefaultCallback_onInteractiveChange;
				*(u32*)&textbox->ev.general.onProgrammaticChange	= *(u32*)&iDefaultCallback_onProgrammaticChange;
		}
	}

	void iiSubobj_resetToDefaultButton(SObject* button, bool tlResetProperties, bool tlResetMethods)
	{
		if (button)
		{
			//////////
			// Reset the common settings
			//////
				iiObj_resetToDefaultCommon(button, true, true);


			//////////
			// Set default size and position
			//////
				SetRect(&button->rc, 0, 0, 84, 27);
				SetRect(&button->rco, 0, 0, 84, 27);
				SetRect(&button->rcp, 0, 0, 84, 27);

				// Set the size
				iObj_setSize(button, 0, 0, 84, 27);


			button->pa.font						= iFont_duplicate(gsFontDefault);
			button->p.backColor.color			= white.color;
			button->p.foreColor.color			= black.color;

			button->p.style						= _STYLE_3D;
			button->p.alignment					= _ALIGNMENT_LEFT;
			iDatum_duplicate(&button->pa.caption,	"Button", 6);

			button->p.disabledBackColor.color	= disabledBackColor.color;
			button->p.disabledForeColor.color	= disabledForeColor.color;

			*(u32*)&button->ev.general.onInteractiveChange	= *(u32*)&iDefaultCallback_onInteractiveChange;
			*(u32*)&button->ev.general.onProgrammaticChange	= *(u32*)&iDefaultCallback_onProgrammaticChange;
		}
	}

	void iiSubobj_resetToDefaultEditbox(SObject* editbox, bool tlResetProperties, bool tlResetMethods)
	{
		if (editbox)
		{
			//////////
			// Reset the common settings
			//////
				iiObj_resetToDefaultCommon(editbox, true, true);


			//////////
			// Set default size and position
			//////
				SetRect(&editbox->rc, 0, 0, 100, 53);
				SetRect(&editbox->rco, 0, 0, 100, 53);
				SetRect(&editbox->rcp, 0, 0, 100, 53);

				// Set the size
				iObj_setSize(editbox, 0, 0, 100, 53);


			editbox->pa.font						= iFont_duplicate(gsFontDefault);
			editbox->p.backColor.color				= white.color;
			editbox->p.foreColor.color				= black.color;

			editbox->p.style						= _STYLE_3D;
			editbox->p.alignment					= _ALIGNMENT_LEFT;

			editbox->p.cursor						= 0;
			editbox->p.selectStart					= -1;
			editbox->p.selectEnd					= -1;

			editbox->p.isOpaque						= true;
			editbox->p.isBorder						= false;
			editbox->p.borderColor.color			= black.color;
			editbox->p.selectedBackColor.color		= selectedBackColor.color;
			editbox->p.selectedForeColor.color		= selectedForeColor.color;
			editbox->p.disabledBackColor.color		= disabledBackColor.color;
			editbox->p.disabledForeColor.color		= disabledForeColor.color;

			iEditManager_deleteChain(&editbox->pa.em, true);
			editbox->pa.em							= iEditManager_allocate();

			*(u32*)&editbox->ev.general.onInteractiveChange		= *(u32*)&iDefaultCallback_onInteractiveChange;
			*(u32*)&editbox->ev.general.onProgrammaticChange	= *(u32*)&iDefaultCallback_onProgrammaticChange;
		}
	}

	void iiSubobj_resetToDefaultImage(SObject* image, bool tlResetProperties, bool tlResetMethods)
	{
		if (image)
		{
			//////////
			// Reset the common settings
			//////
				iiObj_resetToDefaultCommon(image, true, true);


			//////////
			// Set default size and position
			//////
				SetRect(&image->rc, 0, 0, 100, 36);
				SetRect(&image->rco, 0, 0, 100, 36);
				SetRect(&image->rcp, 0, 0, 100, 36);

				// Set the size
				iObj_setSize(image, 0, 0, 100, 36);


			image->p.style						= _IMAGE_STYLE_OPAQUE;
			image->p.image						= iBmp_copy(bmpNoImage);

			*(u32*)&image->ev.general.onProgrammaticChange	= *(u32*)&iDefaultCallback_onProgrammaticChange;
		}
	}

	void iiSubobj_resetToDefaultCheckbox(SObject* checkbox, bool tlResetProperties, bool tlResetMethods)
	{
		if (checkbox)
		{
			//////////
			// Reset the common settings
			//////
				iiObj_resetToDefaultCommon(checkbox, true, true);


			//////////
			// Set default size and position
			//////
				SetRect(&checkbox->rc, 0, 0, 60, 17);
				SetRect(&checkbox->rco, 0, 0, 60, 17);
				SetRect(&checkbox->rcp, 0, 0, 60, 17);

				// Set the size
				iObj_setSize(checkbox, 0, 0, 60, 17);


			checkbox->pa.font						= iFont_duplicate(gsFontDefault);
			checkbox->p.backColor.color				= white.color;
			checkbox->p.foreColor.color				= black.color;

			checkbox->p.alignment					= _ALIGNMENT_LEFT;
			checkbox->p.style						= _STYLE_3D;
			iVariable_delete(checkbox->pa.value, false);
			iDatum_duplicate(&checkbox->pa.caption, cgcName_checkbox, 8);

			checkbox->p.isOpaque					= true;
			checkbox->p.isBorder					= false;
			checkbox->p.borderColor.color			= black.color;
			checkbox->p.disabledBackColor.color		= disabledBackColor.color;
			checkbox->p.disabledForeColor.color		= disabledForeColor.color;

			*(u32*)&checkbox->ev.general.onInteractiveChange	= *(u32*)&iDefaultCallback_onInteractiveChange;
			*(u32*)&checkbox->ev.general.onProgrammaticChange	= *(u32*)&iDefaultCallback_onProgrammaticChange;
		}
	}

	void iiSubobj_resetToDefaultOption(SObject* option, bool tlResetProperties, bool tlResetMethods)
	{
		SObject* label1;
		SObject* label2;


		if (option)
		{
			//////////
			// Reset the common settings
			//////
				iiObj_resetToDefaultCommon(option, true, true);


			//////////
			// Set default size and position
			//////
				SetRect(&option->rc, 0, 0, 60, 40);
				SetRect(&option->rco, 0, 0, 60, 40);
				SetRect(&option->rcp, 0, 0, 60, 40);

				// Set the size
				iObj_setSize(option, 0, 0, 60, 40);


			option->p.backColor.color			= white.color;
			option->p.foreColor.color			= black.color;

			option->p.alignment					= _ALIGNMENT_LEFT;
			option->p.style						= _STYLE_3D;

			option->p.optionCount				= 2;
			option->p.multiSelect				= false;

			// Create the two objects
			label1 = iObj_create(_OBJ_TYPE_LABEL, option);
			label2 = iObj_create(_OBJ_TYPE_LABEL, option);
			iLl_appendExistingNodeAtEnd((SLL**)&option->pa.firstOption, (SLL*)label1);
			iLl_appendExistingNodeAtEnd((SLL**)&option->pa.firstOption, (SLL*)label2);

			// Copy the events
			*(u32*)&option->ev.general.onSelect				= *(u32*)&iDefaultCallback_onSelect;
			*(u32*)&option->ev.general.onDeselect			= *(u32*)&iDefaultCallback_onDeselect;
			*(u32*)&option->ev.general.onInteractiveChange	= *(u32*)&iDefaultCallback_onInteractiveChange;
			*(u32*)&option->ev.general.onProgrammaticChange	= *(u32*)&iDefaultCallback_onProgrammaticChange;
		}
	}

	void iiSubobj_resetToDefaultRadio(SObject* radio, bool tlResetProperties, bool tlResetMethods)
	{
		if (radio)
		{
			//////////
			// Reset the common settings
			//////
				iiObj_resetToDefaultCommon(radio, true, true);


			//////////
			// Set default size and position
			//////
				SetRect(&radio->rc, 0, 0, 100, 100);
				SetRect(&radio->rco, 0, 0, 100, 100);
				SetRect(&radio->rcp, 0, 0, 100, 100);

				// Set the size
				iObj_setSize(radio, 0, 0, 100, 100);


			radio->pa.font						= iFont_duplicate(gsFontDefault);
			radio->p.backColor.color			= white.color;
			radio->p.foreColor.color			= black.color;

			radio->p.alignment					= _ALIGNMENT_LEFT;
			radio->p.style						= _STYLE_3D;
			iVariable_reset(radio->pa.value);
			radio->p.minValue					= 0;
			radio->p.maxValue					= 100;
			radio->p.roundTo					= 1.0f;

			radio->p.isOpaque					= true;
			radio->p.isBorder					= false;
			radio->p.borderColor.color			= black.color;
			radio->p.disabledBackColor.color	= disabledBackColor.color;
			radio->p.disabledForeColor.color	= disabledForeColor.color;

			*(u32*)&radio->ev.general.onInteractiveChange		= *(u32*)&iDefaultCallback_onInteractiveChange;
			*(u32*)&radio->ev.general.onProgrammaticChange	= *(u32*)&iDefaultCallback_onProgrammaticChange;
		}
	}




//////////
//
// Called to delete the empty.
//
//////
	void iSubobj_deleteEmpty(SObject* empty, bool tlDeleteSelf)
	{
		//////////
		// Free self
		//////
			if (tlDeleteSelf)
				free(empty);
	}




//////////
//
// Called to delete the form.
//
//////
	void iSubobj_deleteForm(SObject* form, bool tlDeleteSelf)
	{
		//////////
		// Free subobject components
		//////
			iFont_delete(&form->pa.font,		true);
			iBmp_delete(&form->pa.bmpIcon,		true, true);
			iDatum_delete(&form->pa.caption,	false);


		//////////
		// Free self
		//////
			if (tlDeleteSelf)
				free(form);
	}




//////////
//
// Called to delete the subform.
//
//////
	void iSubobj_deleteSubform(SObject* subform, bool tlDeleteSelf)
	{
		//////////
		// Free subobject components
		//////
			iFont_delete(&subform->pa.font,		true);
			iBmp_delete(&subform->pa.bmpIcon,	true, true);
			iDatum_delete(&subform->pa.caption,	false);


		//////////
		// Free self
		//////
			if (tlDeleteSelf)
				free(subform);
	}




//////////
//
// Called to delete the label.
//
//////
	void iSubobj_deleteLabel(SObject* label, bool tlDeleteSelf)
	{
		//////////
		// Free subobject components
		//////
			iFont_delete(&label->pa.font,		true);
			iDatum_delete(&label->pa.caption,	false);


		//////////
		// Free self
		//////
			if (tlDeleteSelf)
				free(label);
	}




//////////
//
// Called to delete the textbox.
//
//////
	void iSubobj_deleteTextbox(SObject* textbox, bool tlDeleteSelf)
	{
		//////////
		// Free subobject components
		//////
			iFont_delete(&textbox->pa.font,			true);
			iVariable_delete(textbox->pa.value,		false);
			iVariable_delete(textbox->pa.picture,	false);
			iVariable_delete(textbox->pa.mask,		false);


		//////////
		// Free self
		//////
			if (tlDeleteSelf)
				free(textbox);
	}




//////////
//
// Called to delete the button.
//
//////
	void iSubobj_deleteButton(SObject* button, bool tlDeleteSelf)
	{
		//////////
		// Free subobject components
		//////
			iFont_delete(&button->pa.font,		true);
			iDatum_delete(&button->pa.caption,	false);


		//////////
		// Free self
		//////
			if (tlDeleteSelf)
				free(button);
	}




//////////
//
// Called to delete the editbox.
//
//////
	void iSubobj_deleteEditbox(SObject* editbox, bool tlDeleteSelf)
	{
		//////////
		// Free subobject components
		//////
			iFont_delete(&editbox->pa.font,				true);
			iEditManager_delete(&editbox->pa.em,	true);


		//////////
		// Free self
		//////
			if (tlDeleteSelf)
				free(editbox);
	}




//////////
//
// Called to delete the image.
//
//////
	void iSubobj_deleteImage(SObject* image, bool tlDeleteSelf)
	{
		//////////
		// Free subobject components
		//////


		//////////
		// Free self
		//////
			if (tlDeleteSelf)
				free(image);
	}




//////////
//
// Called to delete the checkbox.
//
//////
	void iSubobj_deleteCheckbox(SObject* checkbox, bool tlDeleteSelf)
	{
		//////////
		// Free subobject components
		//////


		//////////
		// Free self
		//////
			if (tlDeleteSelf)
				free(checkbox);
	}




//////////
//
// Called to delete the option.
//
//////
	void iSubobj_deleteOption(SObject* option, bool tlDeleteSelf)
	{
		//////////
		// Free subobject components
		//////


		//////////
		// Free self
		//////
			if (tlDeleteSelf)
				free(option);
	}




//////////
//
// Called to delete the radio.
//
//////
	void iSubobj_deleteRadio(SObject* radio, bool tlDeleteSelf)
	{
		//////////
		// Free subobject components
		//////


		//////////
		// Free self
		//////
			if (tlDeleteSelf)
				free(radio);
	}




//////////
//
// Renders an empty.  Note, empty objects are not rendered.  This control, however,
// can have controls within which are rendered to off-screen buffers, used for whatever
// non-visual purposes exist.  As such, render calls are still made to it.
//
//////
	u32 iSubobj_renderEmpty(SObject* empty)
	{
		//////////
		// Success!
		//////
			empty->isDirty = false;
			return(0);		// Indicate that nothing was rendered which will affect the screen
	}




//////////
//
// Renders the form, which traverses through all child objects and renders to the
// furthest extent before rendering itself.
//
// Note:  The object rendering is independent of the publication of the constructed
//        bitmap.  The render operation only populates the bit buffer.  It will be
//        published at a later time, if indeed it is visible, however, it can after
//        rendering be re-directed to some other source, a disk file, or over a
//        network resource.
//
//////
	u32 iSubobj_renderForm(SObject* form)
	{
		u32		lnPixelsRendered;
		RECT	lrc, lrc2;


		// Make sure our environment is sane
		lnPixelsRendered = 0;
		if (form)
		{
			//////////
			// Make sure there is a bit bucket
			//////
				if (!form->bmp)
				{
					form->bmp = iBmp_allocate();
					iBmp_createBySize(form->bmp, form->rc.right - form->rc.left, form->rc.bottom - form->rc.top, 24);
				}


			//////////
			// If we need re-rendering, re-render
			//////
				// The entire bmp
				SetRect(&lrc, 0, 0, form->bmp->bi.biWidth, form->bmp->bi.biHeight);

				// Do we need to redraw?  Or can we just copy?
				if (form->isDirty || lnPixelsRendered != 0)
				{
					//////////
					// Frame it
					//////
						// Draw the window border
						iBmp_fillRect(form->bmp, &lrc, form->p.nwRgba, form->p.neRgba, form->p.swRgba, form->p.seRgba, true, &form->rcClient, true);

						// Frame it
						iBmp_frameRect(form->bmp, &lrc, black, black, black, black, false, NULL, false);

						// Draw the client area
						SetRect(&lrc2, 8, form->pa.bmpIcon->bi.biHeight + 2, lrc.right - form->pa.bmpIcon->bi.biHeight - 2, lrc.bottom - form->pa.bmpIcon->bi.biHeight - 1);
						iBmp_fillRect(form->bmp, &lrc2, white, white, white, white, false, NULL, false);
// These rc* copies were added temporarily until the full object structure is coded and working
//CopyRect(&form->rcClient, &lrc2);

						// Put a border around the client area
						InflateRect(&lrc2, 1, 1);
						iBmp_frameRect(form->bmp, &lrc2, black, black, black, black, false, NULL, false);


// 					//////////
// 					// Form icon and standard controls
// 					//////
// 						// Form icon
// 						SetRect(&lrc3,	bmpArrowUl->bi.biWidth + 8, 1, bmpArrowUl->bi.biWidth + 8 + form->pa.bmpIcon->bi.biWidth, 1 + form->pa.bmpIcon->bi.biHeight);
// 						iBmp_bitBltMask(form->bmp, &lrc3, form->pa.bmpIcon);
// CopyRect(&form->rcIcon, &lrc3);
// 
// 						// Close
// 						SetRect(&lrc2,	lrc.right - bmpArrowUr->bi.biWidth - 8 - bmpClose->bi.biWidth, lrc.top + 1, lrc.right - bmpArrowUr->bi.biWidth - 8, lrc.bottom - 1);
// 						iBmp_bitBltMask(form->bmp, &lrc2, bmpClose);
// CopyRect(&form->rcClose, &lrc2);
// 
// 						// Maximize
// 						SetRect(&lrc2,	lrc2.left - bmpMaximize->bi.biWidth - 1, lrc2.top, lrc2.left - 1, lrc2.bottom);
// 						iBmp_bitBltMask(form->bmp, &lrc2, bmpMaximize);
// CopyRect(&form->rcMaximize, &lrc2);
// 
// 						// Minimize
// 						SetRect(&lrc2,	lrc2.left - bmpMinimize->bi.biWidth - 1, lrc2.top, lrc2.left - 1, lrc2.bottom);
// 						iBmp_bitBltMask(form->bmp, &lrc2, bmpMinimize);
// CopyRect(&form->rcMinimize, &lrc2);
// 
// 						// Move
// 						SetRect(&lrc4,	lrc2.left - bmpMove->bi.biWidth - 1, lrc2.top, lrc2.left - 1, lrc2.bottom);
// 						iBmp_bitBltMask(form->bmp, &lrc4, bmpMove);
// CopyRect(&form->rcMove, &lrc4);


					//////////
					// Resizing arrows
					//////
						// Upper left arrow
						SetRect(&lrc2, lrc.left + 1, lrc.top + 1, lrc.left + bmpArrowUl->bi.biWidth, lrc.top + bmpArrowUl->bi.biHeight);
						iBmp_bitBltMask(form->bmp, &lrc2, bmpArrowUl);
CopyRect(&form->rcArrowUl, &lrc2);

						// Upper right arrow
						SetRect(&lrc2, lrc.right - bmpArrowUr->bi.biWidth - 1, lrc.top + 1, lrc.right, lrc.top + bmpArrowUr->bi.biHeight);
						iBmp_bitBltMask(form->bmp, &lrc2, bmpArrowUr);
CopyRect(&form->rcArrowUr, &lrc2);

						// Lower right arrow
						SetRect(&lrc2, lrc.right - bmpArrowLr->bi.biWidth - 1, lrc.bottom - bmpArrowLr->bi.biHeight - 1, lrc.right, lrc.bottom);
						iBmp_bitBltMask(form->bmp, &lrc2, bmpArrowLr);
CopyRect(&form->rcArrowLl, &lrc2);

						// Lower left arrow
						SetRect(&lrc2, lrc.left + 1, lrc.bottom - bmpArrowLl->bi.biHeight - 1, lrc.left + bmpArrowLl->bi.biWidth, lrc.bottom);
						iBmp_bitBltMask(form->bmp, &lrc2, bmpArrowLl);
CopyRect(&form->rcArrowLr, &lrc2);


// 					//////////
// 					// Form caption
// 					//////
//						HFONT lhfontOld;
//
// 						SetRect(&lrc2, lrc3.right + 8, lrc3.top + 1, lrc4.right - 8, lrc3.bottom + 1);
// CopyRect(&form->rcCaption, &lrc2);
// 						lhfontOld = (HFONT)SelectObject(form->bmp->hdc, gsWindowTitleBarFont->hfont);
// 						SetBkMode(form->bmp->hdc, TRANSPARENT);
// 						SetTextColor(form->bmp->hdc, (COLORREF)RGB(form->p.captionColor.red, form->p.captionColor.grn, form->p.captionColor.blu));
// 						DrawTextA(form->bmp->hdc, form->pa.caption.data, form->pa.caption.length, &lrc2, DT_VCENTER);
// 						SelectObject(form->bmp->hdc, lhfontOld);


					//////////
					// Copy to prior rendered bitmap
					//////
						// Make sure our bmpPriorRendered exists
						form->bmpPriorRendered = iBmp_verifyCopyIsSameSize(form->bmpPriorRendered, form->bmp);

						// Copy to the prior rendered version
						lnPixelsRendered += iBmp_bitBlt(form->bmpPriorRendered, &lrc, form->bmp);
						// Right now, we can use the bmpPriorRendered for a fast copy rather than 

// 				} else {
// 					// Render from its prior rendered version
// 					lnPixelsRendered += iBmp_bitBlt(obj->bmp, &lrc, obj->bmpPriorRendered);
				}


//////////
// For temporary, we are adding additional renderings for _screen
//////
	if (form == gobj_screen)
	{
		iEditManager_render(screenData, gobj_screen);
		if (gWinScreen)
			InvalidateRect(gWinScreen->hwnd, 0, FALSE);
	}


			//////////
			// Indicate we're no longer dirty, that we have everything
			//////
				form->isDirty = false;
// s8 buffer[256];
// sprintf(buffer, "c:\\temp\\forms\\%u.bmp\0", (u32)form);
// iBmp_saveToDisk(form->bmp, buffer);
		}


		// Indicate how many pixels were drawn
		return(lnPixelsRendered);
	}




//////////
//
// Renders the subform, which traverses through all child objects and renders to the
// furthest extent before rendering itself.
//
// Note:  See "Note" on iRenderForm().
//
//////
	u32 iSubobj_renderSubform(SObject* subform)
	{
		u32		lnPixelsRendered;
		RECT	lrc, lrc2, lrc3;
		HFONT	lhfontOld;


		// Make sure our environment is sane
		lnPixelsRendered = 0;
		if (subform && subform->isDirty && subform->isRendered && subform->rc.right > 0 && subform->rc.bottom > 0 && subform->rc.right >= subform->rc.left && subform->rc.bottom >= subform->rc.bottom && subform->rc.right - subform->rc.left < 4400 && subform->rc.bottom - subform->rc.top < 4400)
		{
			//////////
			// Make sure there is a bit bucket
			//////
				if (!subform->bmp)
				{
					// Initially allocate
					subform->bmp = iBmp_allocate();
					iBmp_createBySize(subform->bmp, subform->rc.right - subform->rc.left, subform->rc.bottom - subform->rc.top, 24);

				} else if (subform->bmp->bi.biWidth != subform->rc.right - subform->rc.left || subform->bmp->bi.biHeight != subform->rc.bottom - subform->rc.top) {
					// Resize
					subform->bmp = iBmp_verifySizeOrResize(subform->bmp, subform->rc.right - subform->rc.left, subform->rc.bottom - subform->rc.top, subform->bmp->bi.biBitCount);
				}


			//////////
			// If we need re-rendering, re-render
			//////
				// The entire bmp
				SetRect(&lrc, 0, 0, subform->bmp->bi.biWidth, subform->bmp->bi.biHeight);

				// Do we need to redraw?  Or can we just copy?
				if (subform->isDirty || lnPixelsRendered != 0)
				{
					//////////
					// Frame it
					//////
						// Draw the window border
						iBmp_fillRect(subform->bmp, &lrc, subform->p.nwRgba, subform->p.neRgba, subform->p.swRgba, subform->p.seRgba, true, &subform->rcClient, true);

						// Frame it
						CopyRect(&lrc2, &lrc);
						SetRect(&lrc2, lrc2.left - 1, lrc2.top - 1, lrc2.right + 1, lrc2.bottom + 1);
						iBmp_frameRect(subform->bmp, &lrc2, black, black, black, black, false, NULL, false);

						// Draw the client area
						SetRect(&lrc2, 0, subform->pa.bmpIcon->bi.biHeight - 1, lrc.right - 8, lrc.bottom);
						// Make everything white
						iBmp_fillRect(subform->bmp, &lrc2, white, white, white, white, false, NULL, false);
// These rc* copies were added temporarily until the full object structure is coded and working
//CopyRect(&subform->rcClient, &lrc2);
						// Put a border around the client area
						SetRect(&lrc2, -1, lrc2.top, lrc2.right, lrc2.bottom + 1);
//						iBmp_frameRect(obj->bmp, &lrc2, black, black, black, black, false);



					//////////
					// Subform icon and standard controls
					//////
						// Subform icon
						SetRect(&lrc3, 0, 0, subform->pa.bmpIcon->bi.biWidth + 8 + subform->pa.bmpIcon->bi.biWidth, subform->pa.bmpIcon->bi.biHeight);
						iBmp_bitBltMask(subform->bmp, &lrc3, subform->pa.bmpIcon);
CopyRect(&subform->rcIcon, &lrc3);

//////////
// Subforms don't currently have automatic close, maximize, minimize, or move buttons, but they can be added programmatically.
// I may change that in the future.  It will depend on how well they integrated into the JDebi Debugger.
// 						// Close
// 						SetRect(&lrc2,	lrc.right - bmpArrowUr->bi.biWidth - 8 - bmpClose->bi.biWidth, lrc.top + 1, lrc.right - bmpArrowUr->bi.biWidth - 8, lrc.bottom - 1);
// 						iBmp_bitBltMask(obj->bmp, &lrc2, bmpClose);
// CopyRect(&subform->rcClose, &lrc2);
// 
// 						// Maximize
// 						SetRect(&lrc2,	lrc2.left - bmpMaximize->bi.biWidth - 1, lrc2.top, lrc2.left - 1, lrc2.bottom);
// 						iBmp_bitBltMask(obj->bmp, &lrc2, bmpMaximize);
// CopyRect(&subform->rcMaximize, &lrc2);
// 
// 						// Minimize
// 						SetRect(&lrc2,	lrc2.left - bmpMinimize->bi.biWidth - 1, lrc2.top, lrc2.left - 1, lrc2.bottom);
// 						iBmp_bitBltMask(obj->bmp, &lrc2, bmpMinimize);
// CopyRect(&subform->rcMinimize, &lrc2);
// 
// 						// Move
// 						SetRect(&lrc4,	lrc2.left - bmpMove->bi.biWidth - 1, lrc2.top, lrc2.left - 1, lrc2.bottom);
// 						iBmp_bitBltMask(obj->bmp, &lrc4, bmpMove);
// CopyRect(&subform->rcMove, &lrc4);
//////


					//////////
					// Subform caption
					//////
						SetRect(&lrc2, subform->pa.bmpIcon->bi.biWidth + 8, lrc3.top + 2, subform->bmp->bi.biWidth - 8, lrc3.bottom);
CopyRect(&subform->rcCaption, &lrc2);
						lhfontOld = (HFONT)SelectObject(subform->bmp->hdc, gsWindowTitleBarFontSubform->hfont);
						SetBkMode(subform->bmp->hdc, TRANSPARENT);
						SetTextColor(subform->bmp->hdc, (COLORREF)RGB(subform->p.captionColor.red, subform->p.captionColor.grn, subform->p.captionColor.blu));
						DrawTextA(subform->bmp->hdc, subform->pa.caption.data, subform->pa.caption.length, &lrc2, DT_VCENTER);
						SelectObject(subform->bmp->hdc, lhfontOld);


//////////
// For temporary, we are adding additional renderings for the command subform
//////
// if (iDatum_compare(&subform->pa.caption, (s8*)cgcCommandTitle, -1) == 0)
// {
// 	iEditManager_render(command_editbox->pa.em, subform);
// 
// } else if (iDatum_compare(&subform->pa.caption, (s8*)cgcSourceCodeTitle, -1) == 0) {
// 	iEditManager_navigateEnd(sourceCode_editbox->pa.em, subform);
// 	iEditManager_render(sourceCode_editbox->pa.em, subform);
// 
// } else if (iDatum_compare(&subform->pa.caption, (s8*)cgcLocalsTitle, -1) == 0) {
// 	iEditManager_navigateEnd(locals_editbox->pa.em, subform);
// 	iEditManager_render(locals_editbox->pa.em, subform);
// 
// } else if (iDatum_compare(&subform->pa.caption, (s8*)cgcWatchTitle, -1) == 0) {
// 	iEditManager_navigateEnd(watch_editbox->pa.em, subform);
// 	iEditManager_render(watch_editbox->pa.em, subform);
// 
// } else if (iDatum_compare(&subform->pa.caption, (s8*)cgcDebugTitle, -1) == 0) {
// 	iEditManager_navigateEnd(debug_editbox->pa.em, subform);
// 	iEditManager_render(debug_editbox->pa.em, subform);
// 
// } else if (iDatum_compare(&subform->pa.caption, (s8*)cgcOutputTitle, -1) == 0) {
// 	iEditManager_navigateEnd(output_editbox->pa.em, subform);
// 	iEditManager_render(output_editbox->pa.em, subform);
// }


					//////////
					// Copy to prior rendered bitmap
					//////
						// Make sure our bmpPriorRendered exists
						subform->bmpPriorRendered = iBmp_verifyCopyIsSameSize(subform->bmpPriorRendered, subform->bmp);

						// Copy to the prior rendered version
						lnPixelsRendered += iBmp_bitBlt(subform->bmpPriorRendered, &lrc, subform->bmp);
						// Right now, we can use the bmpPriorRendered for a fast copy rather than 

// 				} else {
// 					// Render from its prior rendered version
// 					lnPixelsRendered += iBmp_bitBlt(obj->bmp, &lrc, obj->bmpPriorRendered);
				}


			//////////
			// Indicate we're no longer dirty, that we have everything
			//////
				subform->isDirty = false;
// s8 buffer[256];
// sprintf(buffer, "c:\\temp\\subforms\\%u.bmp\0", (u32)subform);
// iBmp_saveToDisk(subform->bmp, buffer);
		}

		// Indicate how many pixels were drawn
		return(lnPixelsRendered);
	}




//////////
//
// Renders the label, and traverses any child objects contained within to render them.
//
// Note:  See "Note" on iRenderForm().
//
//////
	u32 iSubobj_renderLabel(SObject* obj)
	{
		u32		lnPixelsRendered, lnFormat;
		RECT	lrc;


		// Make sure our environment is sane
		lnPixelsRendered = 0;
		if (obj && obj->isDirty  && obj->isRendered)
		{
			if (obj->p.isOpaque)
			{
				// Use the back color
				SetBkColor(obj->bmp->hdc, RGB(obj->p.backColor.red, obj->p.backColor.grn, obj->p.backColor.blu));
				SetTextColor(obj->bmp->hdc, RGB(obj->p.foreColor.red, obj->p.foreColor.grn, obj->p.foreColor.blu));

			} else {
				// Use a black and white creation
				SetBkColor(obj->bmp->hdc, RGB(255,255,255));
				SetTextColor(obj->bmp->hdc, RGB(0,0,0));
			}

			// Fill in the background
			SetRect(&lrc, 0, 0, obj->bmp->bi.biWidth, obj->bmp->bi.biHeight);
			iBmp_fillRect(obj->bmp, &lrc, white, white, white, white, false, NULL, false);

			// Set the text parameters
			SetBkMode(obj->bmp->hdc, TRANSPARENT);
			SelectObject(obj->bmp->hdc, obj->pa.font->hfont);

			// Determine our orientation
			switch (obj->p.alignment)
			{
				case _ALIGNMENT_LEFT:
					lnFormat = DT_LEFT;
					break;

				case _ALIGNMENT_RIGHT:
					lnFormat = DT_RIGHT;
					break;

				case _ALIGNMENT_CENTER:
					lnFormat = DT_CENTER;
					break;
			}

			// Draw the text
			DrawText(obj->bmp->hdc, obj->pa.caption.data, obj->pa.caption.length, &lrc, lnFormat | DT_VCENTER | DT_END_ELLIPSIS);

			// Frame rectangle
			if (obj->p.isBorder)
				iBmp_frameRect(obj->bmp, &lrc, obj->p.borderColor, obj->p.borderColor, obj->p.borderColor, obj->p.borderColor, false, NULL, false);

			// Indicate we're no longer dirty, that we have everything
			obj->isDirty = false;
		}

		// Indicate status
		return(lnPixelsRendered);
	}




//////////
//
// Renders the textbox, and traverses any child objects contained within to render them.
//
// Note:  See "Note" on iRenderForm().
//
//////
	u32 iSubobj_renderTextbox(SObject* obj)
	{


			//////////
			// Indicate we're no longer dirty, that we have everything
			//////
				obj->isDirty = false;
		return(0);
	}




//////////
//
// Renders the button, and traverses any child objects contained within to render them.
//
// Note:  See "Note" on iRenderForm().
//
//////
	u32 iSubobj_renderButton(SObject* obj)
	{


			//////////
			// Indicate we're no longer dirty, that we have everything
			//////
				obj->isDirty = false;
		return(0);
	}




//////////
//
// Renders the editbox, and traverses any child objects contained within to render them.
//
// Note:  See "Note" on iRenderForm().
//
//////
	u32 iSubobj_renderEditbox(SObject* obj)
	{
		u32 lnPixelsRendered;

//		iEditManager_navigateEnd(obj->pa.em, obj);
// if (iDatum_compare(&obj->parent->pa.caption, "command", 7) == 0)
// 	_asm nop;
		lnPixelsRendered = iEditManager_render(obj->pa.em, obj);

		// Indicate we're no longer dirty, that we have everything
		obj->isDirty = false;

		// Indicate status
		return(lnPixelsRendered);
	}




//////////
//
// Renders the image, and traverses any child objects contained within to render them.
//
// Note:  See "Note" on iRenderForm().
//
//////
	u32 iSubobj_renderImage(SObject* obj)
	{
		u32		lnPixelsRendered;
		RECT	lrc;


		// Make sure our environment is sane
		lnPixelsRendered = 0;
		if (obj && obj->bmp)
		{
			// Compute our rectangle for drawing
			SetRect(&lrc, 0, 0, obj->bmp->bi.biWidth, obj->bmp->bi.biHeight);

			// Based on the current conditions, render the appropriate image
			if (obj->ev.mouse.isMouseDown)
			{
				// Mouse is over this item
				lnPixelsRendered += iBmp_bitBlt(obj->bmp, &lrc, obj->pa.bmpPictureDown);

			} else if (obj->ev.mouse.isMouseOver) {
				// Mouse is over this item
				lnPixelsRendered += iBmp_bitBlt(obj->bmp, &lrc, obj->pa.bmpPictureOver);

			} else {
				// Render normally
				lnPixelsRendered += iBmp_bitBlt(obj->bmp, &lrc, obj->pa.bmpPicture);
			}

			// Indicate we're no longer dirty, that we have everything
			obj->isDirty = false;
		}

		// Indicate status
		return(lnPixelsRendered);
	}




//////////
//
// Renders the checkbox, and traverses any child objects contained within to render them.
//
// Note:  See "Note" on iRenderForm().
//
//////
	u32 iSubobj_renderCheckbox(SObject* obj)
	{


			//////////
			// Indicate we're no longer dirty, that we have everything
			//////
				obj->isDirty = false;
		return(0);
	}




//////////
//
// Renders the option, and traverses any child objects contained within to render them.
//
// Note:  See "Note" on iRenderForm().
//
//////
	u32 iSubobj_renderOption(SObject* obj)
	{


			//////////
			// Indicate we're no longer dirty, that we have everything
			//////
				obj->isDirty = false;
		return(0);
	}




//////////
//
// Renders the radio, and traverses any child objects contained within to render them.
//
// Note:  See "Note" on iRenderForm().
//
//////
	u32 iSubobj_renderRadio(SObject* obj)
	{


			//////////
			// Indicate we're no longer dirty, that we have everything
			//////
				obj->isDirty = false;
		return(0);
	}
