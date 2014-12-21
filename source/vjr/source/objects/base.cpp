//////////
//
// /libsf/source/vjr/objects/base.cpp
//
//////
// Version 0.54
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
	SObject* iObj_create(s32 objType, SObject* objParent)
	{
		// We need to create it
		logfunc(__FUNCTION__);
		switch (objType)
		{
			case _OBJ_TYPE_EMPTY:		// Empty, used as a placeholder object that is not drawn
				return(iSubobj_createEmpty(NULL, objParent));

			case _OBJ_TYPE_FORM:			// Form class, the main outer window the OS sees
				return(iSubobj_createForm(NULL, objParent));

			case _OBJ_TYPE_SUBFORM:		// A new class which has its own drawing content and can be moved about using UI features
				return(iSubobj_createSubform(NULL, objParent));

			case _OBJ_TYPE_CAROUSEL:	// A new class which is its a holder for riders, allowing multiple classes to be docked and interacted with/upon as a group
				return(iSubobj_createCarousel(NULL, objParent));

			case _OBJ_TYPE_RIDER:		// A new class which wraps around a form or subform allowing it to be presented inside a carousel
				return(iSubobj_createRider(NULL, objParent));

			case _OBJ_TYPE_LABEL:		// A label
				return(iSubobj_createLabel(NULL, objParent));

			case _OBJ_TYPE_TEXTBOX:		// An input textbox
				return(iSubobj_createTextbox(NULL, objParent));

			case _OBJ_TYPE_BUTTON:		// A push button
				return(iSubobj_createButton(NULL, objParent));

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

			case _OBJ_TYPE_CMDGROUP:	// A command button group
				return(iSubobj_createCmdGroup(NULL, objParent));

			case _OBJ_TYPE_OPTGROUP:	// An option group
				return(iSubobj_createOptGroup(NULL, objParent));

			case _OBJ_TYPE_LISTBOX:		// A listbox
				return(iSubobj_createListbox(NULL, objParent));

			case _OBJ_TYPE_COMBOBOX:	// A combobox
				return(iSubobj_createCombobox(NULL, objParent));

			case _OBJ_TYPE_FORMSET:		// A formset
				return(iSubobj_createFormset(NULL, objParent));

			case _OBJ_TYPE_TOOLBAR:		// A toolbar
				return(iSubobj_createToolbar(NULL, objParent));

			case _OBJ_TYPE_SEPARATOR:	// A separator
				return(iSubobj_createSeparator(NULL, objParent));

			case _OBJ_TYPE_LINE:		// A line
				return(iSubobj_createLine(NULL, objParent));

			case _OBJ_TYPE_SHAPE:		// A shape
				return(iSubobj_createShape(NULL, objParent));

			case _OBJ_TYPE_CONTAINER:	// A container
				return(iSubobj_createContainer(NULL, objParent));

			case _OBJ_TYPE_CONTROL:		// A blocking container
				return(iSubobj_createControl(NULL, objParent));

			case _OBJ_TYPE_GRID:		// A grid
				return(iSubobj_createGrid(NULL, objParent));

			case _OBJ_TYPE_COLUMN:		// A grid's column object
				return(iSubobj_createColumn(NULL, objParent));

			case _OBJ_TYPE_HEADER:		// A grid's header object
				return(iSubobj_createHeader(NULL, objParent));

			case _OBJ_TYPE_OLEBOUND:	// A bound OLE object
				return(iSubobj_createOleBound(NULL, objParent));

			case _OBJ_TYPE_OLECONTAIN:	// An OLE container control object
				return(iSubobj_createOleContain(NULL, objParent));

			case _OBJ_TYPE_SPINNER:		// A spinner
				return(iSubobj_createSpinner(NULL, objParent));

			case _OBJ_TYPE_TIMER:		// A timer
				return(iSubobj_createTimer(NULL, objParent));

			case _OBJ_TYPE_HYPERLINK:	// A hyperlink
				return(iSubobj_createHyperlink(NULL, objParent));

			case _OBJ_TYPE_COLLECTION:	// A collection
				return(iSubobj_createCollection(NULL, objParent));

			case _OBJ_TYPE_PAGE:		// A page within a pageframe
				return(iSubobj_createPage(NULL, objParent));

			case _OBJ_TYPE_PAGEFRAME:	// A pageframe
				return(iSubobj_createPageframe(NULL, objParent));

			case _OBJ_TYPE_SESSION:		// A session
				return(iSubobj_createSession(NULL, objParent));

			case _OBJ_TYPE_CUSTOM:		// A custom class
				return(iSubobj_createCustom(NULL, objParent));

			case _OBJ_TYPE_EXCEPTION:	// An exception
				return(iSubobj_createException(NULL, objParent));

			default:
// TODO:  We should never get here.  If we do it's a developer error.  Check the call stack and determine the cause.
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
	SObject* iObj_addChild(s32 objType, SObject* objParent)
	{
		SObject* objNew;


		// Make sure our environment is sane
		logfunc(__FUNCTION__);
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
		logfunc(__FUNCTION__);
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
	void iObj_delete(SObject** objRoot, bool tlDeleteSelf, bool tlDeleteChildren, bool tlDeleteSiblings)
	{
		SObject* obj;
		SObject* objSib;
		SObject* objSibNext;


		logfunc(__FUNCTION__);
		// Make sure our environment is sane
		if (objRoot && *objRoot)
		{
			//////////
			// Grab our object, and mark it deleted
			//////
				obj			= *objRoot;
				*objRoot	= NULL;


			//////////
			// Delete children
			//////
				if (tlDeleteChildren && obj->firstChild)
					iObj_delete(&obj->firstChild, true, true, true);


			//////////
			// Delete siblings
			//////
				if (tlDeleteSiblings && obj->ll.next)
				{
					// Iterate by looking ahead to the next entry, so we update the chain
					objSib = (SObject*)obj->ll.next;
					while (objSib)
					{
						// Grab the next sibling
						objSibNext = (SObject*)objSib->ll.next;

						// Delete this sibling
						iObj_delete(&objSib, true, true, false);

						// Move to next sibling
						objSib = objSibNext;
					}
				}


			//////////
			// Delete self
			//////
				switch (obj->objType)
				{
					case _OBJ_TYPE_EMPTY:
						iSubobj_deleteEmpty(obj, true);
						break;
					case _OBJ_TYPE_FORM:
						iSubobj_deleteForm(obj, true);
						break;
					case _OBJ_TYPE_SUBFORM:
						iSubobj_deleteSubform(obj, true);
						break;
					case _OBJ_TYPE_CAROUSEL:
						iSubobj_deleteCarousel(obj, true, tlDeleteChildren, tlDeleteChildren);
						break;
					case _OBJ_TYPE_RIDER:
						iSubobj_deleteRider(obj, true, false);
						break;
					case _OBJ_TYPE_LABEL:
						iSubobj_deleteLabel(obj, true);
						break;
					case _OBJ_TYPE_TEXTBOX:
						iSubobj_deleteTextbox(obj, true);
						break;
					case _OBJ_TYPE_BUTTON:
						iSubobj_deleteButton(obj, true);
						break;
					case _OBJ_TYPE_EDITBOX:
						iSubobj_deleteEditbox(obj, true);
						break;
					case _OBJ_TYPE_IMAGE:
						iSubobj_deleteImage(obj, true);
						break;
					case _OBJ_TYPE_CHECKBOX:
						iSubobj_deleteCheckbox(obj, true);
						break;
					case _OBJ_TYPE_OPTION:
						iSubobj_deleteOption(obj, true);
						break;
					case _OBJ_TYPE_RADIO:
						iSubobj_deleteRadio(obj, true);
						break;
				}
		}
	}




//////////
//
// Called to set focus on the indicated control.
//
//////
	bool iObj_setFocus(SWindow* win, SObject* obj, bool tlClearOtherControlsWithFocus)
	{
		logfunc(__FUNCTION__);
		// Clear the focus if we should
		if (tlClearOtherControlsWithFocus)
			iObj_clearFocus(win, iObj_find_rootmostObject(obj), true, true);

		// Set the focus
		if (!obj->p.hasFocus)
		{
			// Set focus
			obj->p.hasFocus = true;

			// Mark the object dirty
			iObj_setDirtyRender_ascent(obj, true);

			// Signal the change
			if (obj->ev.general._onGotFocus)
				obj->ev.general.onGotFocus(win, obj);

			// Indicate we set focus
			return(true);
		}

		// Indicate focus was not changed
		return(false);
	}




//////////
//
// Clear the focus.
//
//////
	void iObj_clearFocus(SWindow* win, SObject* obj, bool tlClearChildren, bool tlClearSiblings)
	{
		SObject*			objSib;
		SFocusHighlight*	focus;


		// Clear children
		logfunc(__FUNCTION__);
		if (tlClearChildren && obj->firstChild)
			iObj_clearFocus(win, obj->firstChild, true, true);

		// Clear self
		if (obj->p.hasFocus)
		{
			// Clear focus
			obj->p.hasFocus = false;

			// Mark the object dirty
			iObj_setDirtyRender_ascent(obj, true);

			// Remove the focus highlight window around the control (if any)
			focus = iFocusHighlight_findByObj(obj);
			if (focus)
				iFocusHighlight_delete(focus);

			// If it was a checkbox that lost focus, then we need to release the parent as well
			if (obj->parent && obj->parent->objType == _OBJ_TYPE_CHECKBOX)
			{
				// The control was part of a checkbox, make sure the parent is released as well
				focus = iFocusHighlight_findByObj(obj->parent);
				if (focus)
					iFocusHighlight_delete(focus);
			}

			// Signal the change
			if (obj->ev.general._onLostFocus)
				obj->ev.general.onLostFocus(win, obj);
		}

		// Clear siblings
		if (tlClearSiblings && obj->ll.next)
		{
			// Begin at the next sibling
			objSib = (SObject*)obj->ll.next;
			while (objSib)
			{
				// Clear this sibling
				iObj_clearFocus(win, objSib, true, false);

				// Move to the next sibling
				objSib = (SObject*)objSib->ll.next;
			}
		}
	}




//////////
//
// Finds the root parent and returns that value
//
//////
	SObject* iObj_find_rootmostObject(SObject* obj)
	{
		// If there's a parent, continue up the chain
		logfunc(__FUNCTION__);
		if (obj->parent)		return(iObj_find_rootmostObject(obj->parent));
		else					return(obj);		// This is the parent-most object
	}




//////////
//
// Called to find the RECT of the indicated object in screen coordinates
//
//////
	bool iObj_find_screenRect(SObject* obj, RECT* rc)
	{
		SObject*	objRoot;
		SWindow*	win;
		RECT		lrcWin, lrcObj;


		// Make sure our environment is sane
		logfunc(__FUNCTION__);
		if (obj && rc)
		{
			// Grab the parent-most object
			objRoot = iObj_find_rootmostObject(obj);

			// It must be a form, so we look for the form on the window
			win = iWindow_findByObj(objRoot);
			if (win)
			{
				// Get the coordinates
				CopyRect(&lrcWin, &win->rc);
				SetRect(&lrcObj, 0, 0, objRoot->bmp->bi.biWidth, objRoot->bmp->bi.biHeight);

				// Adjust for the child object's location within
				if (iObj_find_relativeRect(objRoot, obj, 0, 0, &lrcObj, true, true))
				{
					// Calculate the adjustment
					SetRect(rc, lrcWin.left + lrcObj.left, lrcWin.top + lrcObj.top, lrcWin.left + lrcObj.right, lrcWin.top + lrcObj.bottom);

					// Indicate success
					return(true);
				}
			}
		}
		// If we get here, we could not obtain that information
		return(false);
	}




//////////
//
// Called to find the relative rectangle of the indicated 
//
//////
	bool iObj_find_relativeRect(SObject* objThis, SObject* objTarget, s32 x, s32 y, RECT* rc, bool tlProcessChildren, bool tlProcessSiblings)
	{
		s32			lnX, lnY;
		SObject*	objSib;


		// Make sure our environment is sane
		logfunc(__FUNCTION__);
		if (objThis && objTarget)
		{
			// Copy the variables
			lnX = x + objThis->rc.left;
			lnY = y + objThis->rc.top;

			// Add in the client coordinates for forms and sub-forms
			if (objThis->objType == _OBJ_TYPE_FORM || objThis->objType == _OBJ_TYPE_SUBFORM)
			{
				lnX += objThis->rcClient.left;
				lnY += objThis->rcClient.top;
			}


			//////////
			// Is this the control?
			//////
				if (objThis == objTarget)
				{
					// Build the rectangle
					SetRect(rc,	lnX - ((objTarget->objType == _OBJ_TYPE_FORM || objTarget->objType == _OBJ_TYPE_SUBFORM) ? objTarget->rcClient.left : 0),
								lnY - ((objTarget->objType == _OBJ_TYPE_FORM || objTarget->objType == _OBJ_TYPE_SUBFORM) ? objTarget->rcClient.top  : 0),
								lnX - ((objTarget->objType == _OBJ_TYPE_FORM || objTarget->objType == _OBJ_TYPE_SUBFORM) ? objTarget->rcClient.left : 0) + objTarget->rc.right  - objTarget->rc.left,
								lnY - ((objTarget->objType == _OBJ_TYPE_FORM || objTarget->objType == _OBJ_TYPE_SUBFORM) ? objTarget->rcClient.top  : 0) + objTarget->rc.bottom - objTarget->rc.top);

					// Indicate success
					return(true);
				}


			//////////
			// Scan through children
			//////
				if (objThis->firstChild && tlProcessChildren)
				{
					if (iObj_find_relativeRect(objThis->firstChild, objTarget, lnX, lnY, rc, true, true))
						return(true);
				}


			//////////
			// Check siblings
			//////
				if (tlProcessSiblings)
				{
					// Begin at the first sibling
					objSib = (SObject*)objThis->ll.next;
					while (objSib)
					{
						// Process this sibling
						if (iObj_find_relativeRect(objSib, objTarget, x, y, rc, true, false))
							return(true);

						// Move to the next sibling
						objSib = (SObject*)objSib->ll.next;
					}
				}
			}

		// Invalid
		return(false);
	}




//////////
//
// Called to find the thisForm
//
//////
	SObject* iObj_find_thisForm(SObject* obj)
	{
		logfunc(__FUNCTION__);
		return(iObj_findParentObject(obj, _OBJ_TYPE_FORM, true));
	}




//////////
//
// Called to find the thisSubform object
//
//////
	SObject* iObj_find_thisSubform(SObject* obj)
	{
		logfunc(__FUNCTION__);
		return(iObj_findParentObject(obj, _OBJ_TYPE_SUBFORM, true));
	}




//////////
//
// Called to find the thisRider object
//
//////
	SObject* iObj_find_thisRider(SObject* obj)
	{
		logfunc(__FUNCTION__);
		return(iObj_findParentObject(obj, _OBJ_TYPE_RIDER, true));
	}




/////////
//
// Called to search for the indicated object
//
//////
	SObject* iObj_findParentObject(SObject* objStart, s32 objType, bool tlIncludeSelfInSearch)
	{
		logfunc(__FUNCTION__);

		if (objStart->objType == objType && tlIncludeSelfInSearch)
		{
			// This is the subform
			return(objStart);

		} else {
			// If we can traverse higher, go higher, if not we're done
			if (objStart->parent)		return(iObj_findParentObject(objStart->parent, objType, true));
			else						return(NULL);
		}
	}




//////////
//
// Called to determine if the indicated object is the command window
//
//////
	bool iObj_isCommandWindow(SObject* obj)
	{
		logfunc(__FUNCTION__);
		return(obj == command);
	}




//////////
//
// Called to set the focus highlights (blue borders around the focused control)
//
//////
	void iObj_setFocusHighlights(SWindow* win, SObject* obj, s32 x, s32 y, bool tlProcessChildren, bool tlProcessSiblings)
	{
		u32					lnI;
		s32					lnX, lnY;
		bool				llFound, llChildHasFocus;
		RECT				lrc;
		SObject*			objSib;
		SFocusHighlight*	focus;
		SFocusHighlight*	focusUnused;


		// Make sure our environment is sane
		logfunc(__FUNCTION__);
		focus = NULL;
		if (win && obj && GetActiveWindow() == win->hwnd)
		{
			// Copy the variables
			lnX = x + obj->rc.left;
			lnY = y + obj->rc.top;

			// Add in the client coordinates for forms and sub-forms
			if (obj->objType == _OBJ_TYPE_FORM || obj->objType == _OBJ_TYPE_SUBFORM)
			{
				lnX += obj->rcClient.left;
				lnY += obj->rcClient.top;
			}


			//////////
			// Scan through children
			//////
				if (obj->firstChild && tlProcessChildren)
					iObj_setFocusHighlights(win, obj->firstChild, lnX, lnY, true, true);


			//////////
			// Is this a focus window?
			//////
				// Search for an existing focus window for this control
				llFound		= false;
				focusUnused	= 0;
				for (lnI = 0; !llFound && lnI < gFocusHighlights->populatedLength; lnI += sizeof(SFocusHighlight))
				{
					// Grab this pointer
					focus = (SFocusHighlight*)(gFocusHighlights->data + lnI);

					// Is this it?
					     if (focus->isValid && focus->obj == obj)		llFound		= true;
					else if (focusUnused == NULL)						focusUnused	= focus;
				}

				// Check the checkbox
				llChildHasFocus = false;
				if (obj->objType == _OBJ_TYPE_CHECKBOX)
				{
					// Does the image have focus?
					llChildHasFocus  = (obj->firstChild && obj->firstChild->p.hasFocus);
					llChildHasFocus |= (obj->firstChild && obj->firstChild->ll.next && ((SObject*)obj->firstChild->ll.next)->p.hasFocus);
				}

				// Should this control have focus?
				if ((obj->p.hasFocus || llChildHasFocus) && !(obj->parent && obj->parent->objType == _OBJ_TYPE_CHECKBOX))
				{
					// This needs to be a focus window
					if (!llFound)
					{
						// We need to add it
						if (!focusUnused)
						{
							// Append a new record
							focus = (SFocusHighlight*)iBuilder_allocateBytes(gFocusHighlights, sizeof(SFocusHighlight));

						} else {
							// Use the first unused record we found
							focus = focusUnused;
						}

						// If the item was created okay, process it
						if (focus)
						{
							// Populate the new entry
							focus->obj	= obj;
							focus->win	= win;
							SetRect(&lrc,	lnX - ((obj->objType == _OBJ_TYPE_FORM || obj->objType == _OBJ_TYPE_SUBFORM) ? obj->rcClient.left : 0) - gsCurrentSetting->_set_focus_highlight_pixels - gsCurrentSetting->_set_focus_highlight_border_pixels,
											lnY - ((obj->objType == _OBJ_TYPE_FORM || obj->objType == _OBJ_TYPE_SUBFORM) ? obj->rcClient.top  : 0) - gsCurrentSetting->_set_focus_highlight_pixels - gsCurrentSetting->_set_focus_highlight_border_pixels,
											lnX - ((obj->objType == _OBJ_TYPE_FORM || obj->objType == _OBJ_TYPE_SUBFORM) ? obj->rcClient.left : 0) + gsCurrentSetting->_set_focus_highlight_pixels + gsCurrentSetting->_set_focus_highlight_border_pixels + obj->rc.right  - obj->rc.left,
											lnY - ((obj->objType == _OBJ_TYPE_FORM || obj->objType == _OBJ_TYPE_SUBFORM) ? obj->rcClient.top  : 0) + gsCurrentSetting->_set_focus_highlight_pixels + gsCurrentSetting->_set_focus_highlight_border_pixels + obj->rc.bottom - obj->rc.top);

							// Physically create the window
							iFocusHighlight_create(focus, &lrc);
						}
					}

				} else if (focus) {
					// This needs to NOT be a focus window
					if (llFound)
						iFocusHighlight_delete(focus);
				}


			//////////
			// Check siblings
			//////
				if (tlProcessSiblings)
				{
					// Begin at the first sibling
					objSib = (SObject*)obj->ll.next;
					while (objSib)
					{
						// Process this sibling
						iObj_setFocusHighlights(win, objSib, x, y, true, false);

						// Move to the next sibling
						objSib = (SObject*)objSib->ll.next;
					}
				}
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


		logfunc(__FUNCTION__);
		//////////
		// Process any children first
		//////
			if (obj->firstChild)
				iObj_findFocusControls(obj->firstChild, objFocusControls, true);

		
		//////////
		// Process self
		//////
			if (obj->p.hasFocus)
				iBuilder_append_uptr(objFocusControls, (uptr)obj);


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
// Called to move to set focus on the previous control
//
//////
	bool iObj_setFocusObjectPrev(SWindow* win, SObject* obj)
	{
		// Attempt the focus
		logfunc(__FUNCTION__);
		if (obj->ll.prev)
			return(iObj_setFocus(win, (SObject*)obj->ll.prev, true));

		// Nothing before
		return(false);
	}




/////////
//
// Called to move to set focus on the next control
//
//////
	bool iObj_setFocusObjectNext(SWindow* win, SObject* obj)
	{
		// Attempt the focus
		logfunc(__FUNCTION__);
		if (obj->ll.next)
			return(iObj_setFocus(win, (SObject*)obj->ll.next, true));

		// Nothing after
		return(false);
	}




//////////
//
// Called to check to see if any object at or below the indicated object has focus
//
//////
	bool iObj_focus_descentCheck(SObject* obj, bool tlCheckChildren, bool tlCheckSiblings)
	{
		return((iObj_focus_descentCheckObj(obj, tlCheckChildren, tlCheckSiblings) != NULL));
	}




//////////
//
// Called to return which control (if any) has focus
//
//////
	SObject* iObj_focus_descentCheckObj(SObject* obj, bool tlCheckChildren, bool tlCheckSiblings)
	{
		SObject* objSib;
		SObject* objFocus;


		//////////
		// If it has focus we're done (because we're only looking to see IF any have focus)
		//////
			if (obj->p.hasFocus)
				return(obj);


		//////////
		// Check the children
		//////
			if (tlCheckChildren && obj->firstChild && (objFocus = iObj_focus_descentCheckObj(obj->firstChild, true, true)))
				return(objFocus);


		//////////
		// Check the siblings
		//////
			if (tlCheckSiblings && obj->ll.next)
			{
				// Skip to the sibling
				objSib = (SObject*)obj->ll.next;
				while (objSib)
				{
					// See if this one has focus
					if ((objFocus = iObj_focus_descentCheckObj(objSib, true, false)))
						return(objFocus);

					// Move to next sibling
					objSib = (SObject*)objSib->ll.next;
				}
			}


		//////////
		// If we get here, this object and its children do not have focus
		//////
			return(NULL);
	}




//////////
//
// Called to mark the object dirty for rendering.
//
//////
	void iObj_setDirtyRender_ascent(SObject* obj, bool tlMarkParents)
	{
		logfunc(__FUNCTION__);
		if (obj)
		{
			// Mark the object dirty
			obj->isDirtyRender	= true;
			obj->isDirtyPublish	= true;

			// Mark the parent
			if (tlMarkParents && obj->parent)
				iObj_setDirtyRender_ascent(obj->parent, true);
		}
	}




//////////
//
// Called to mark the object and optionally all its children and siblings 
//
//////
	void iObj_setDirtyRender_descent(SObject* obj, bool tlProcessChildren, bool tlProcessSiblings)
	{
		SObject* objSib;


		logfunc(__FUNCTION__);
		if (obj)
		{
			//////////
			// Mark the object dirty
			//////
				obj->isDirtyRender	= true;
				obj->isDirtyPublish	= true;


			//////////
			// Process children?
			//////
				if (tlProcessChildren && obj->firstChild)
					iObj_setDirtyRender_descent(obj, true, true);


			//////////
			// Process siblings
			//////
				if (tlProcessSiblings && obj->ll.next)
				{
					// Grab the first sibling
					objSib = (SObject*)obj->ll.next;
					while (objSib)
					{
						// Process this sibling
						iObj_setDirtyRender_descent(objSib, true, false);

						// Move to next sibling
						objSib = (SObject*)objSib->ll.next;
					}
				}
		}
	}




//////////
//
// Called to mark the object dirty for publishing.
//
//////
	void iObj_setDirtyPublish_ascent(SObject* obj, bool tlMarkParents)
	{
		logfunc(__FUNCTION__);
		if (obj)
		{
			// Mark the object dirty
			obj->isDirtyPublish = true;

			// Mark the parent
			if (tlMarkParents && obj->parent)
				iObj_setDirtyPublish_ascent(obj->parent, true);
		}
	}




//////////
//
// Called to mark the object and optionally all its children and siblings 
//
//////
	void iObj_setDirtyPublish_descent(SObject* obj, bool tlProcessChildren, bool tlProcessSiblings)
	{
		SObject* objSib;


		logfunc(__FUNCTION__);
		if (obj)
		{
			//////////
			// Mark the object dirty for publishing
			//////
				obj->isDirtyPublish	= true;


			//////////
			// Process children?
			//////
				if (tlProcessChildren && obj->firstChild)
					iObj_setDirtyPublish_descent(obj, true, true);


			//////////
			// Process siblings
			//////
				if (tlProcessSiblings && obj->ll.next)
				{
					// Grab the first sibling
					objSib = (SObject*)obj->ll.next;
					while (objSib)
					{
						// Process this sibling
						iObj_setDirtyPublish_descent(objSib, true, false);

						// Move to next sibling
						objSib = (SObject*)objSib->ll.next;
					}
				}
		}
	}




//////////
//
// Called to render the indicated object
//
//////
	u32 iObj_render(SObject* obj, bool tlForceRender)
	{
		u32			lnPixelsRendered;
		SObject*	objRoot;
		SWindow*	win;


		// Make sure our environment is sane
		logfunc(__FUNCTION__);
		lnPixelsRendered = 0;
		if (obj && obj->isRendered)
		{
			//////////
			// If they're forcing a render, set it up
			//////
				obj->isDirtyRender		|= tlForceRender;
				obj->ogl.quad.updateTextureWithNewBitmap	= obj->isDirtyRender;


			//////////
			// Make sure there is a bit bucket
			//////
				if (!obj->bmp)
				{
					// Initially allocate
					obj->isDirtyRender	= true;
					obj->bmp			= iBmp_allocate();
					iBmp_createBySize(obj->bmp,		obj->rc.right - obj->rc.left,
													obj->rc.bottom - obj->rc.top,
													24);

				} else if (obj->bmp->bi.biWidth != obj->rc.right - obj->rc.left || obj->bmp->bi.biHeight != obj->rc.bottom - obj->rc.top) {
					// Resize
					obj->isDirtyRender = true;
					obj->bmp			= iBmp_verifySizeOrResize(obj->bmp,		obj->rc.right - obj->rc.left,
																				obj->rc.bottom - obj->rc.top,
																				obj->bmp->bi.biBitCount);
				}


			//////////
			// See if there is any onRender() algorithm associated with this object
			//////
				if (obj->ev.general._onRender)
				{
					// Find the root object
					objRoot = iObj_find_rootmostObject(obj);
					if (objRoot)
					{
						// Locate the associated window (if any)
						win = iWindow_findByObj(objRoot);
						obj->ev.general.onRender(win, obj);
					}
				}


			//////////
			// Which object are they rendering?
			//////
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
// TODO:  We should never get here... we should fire off an internal consistency error ... or a signal flare.  Something to draw attention.
						break;
				}
		}

		// Indicate how many pixels were rendered
		return(lnPixelsRendered);
	}




//////////
//
// Called to descend through the children to see if anything needs to be rendered.
//
//////
	bool iObj_render_descentCheck(SObject* obj, bool tlCheckChildren, bool tlCheckSiblings)
	{
		SObject* objSib;


		//////////
		// If it's dirty, we need to render
		//////
			if (obj->isDirtyRender)
				return(true);


		//////////
		// Check the children
		//////
			if (tlCheckChildren && obj->firstChild && iObj_render_descentCheck(obj->firstChild, true, true))
				return(true);


		//////////
		// Check the siblings
		//////
			if (tlCheckSiblings && obj->ll.next)
			{
				// Skip to the sibling
				objSib = (SObject*)obj->ll.next;
				while (objSib)
				{
					// See if this one needs rendering
					if (iObj_render_descentCheck(objSib, true, false))
						return(true);

					// Move to next sibling
					objSib = (SObject*)objSib->ll.next;
				}
			}


		//////////
		// If we get here, this object and its children do not need to be rendered
		//////
			return(false);
	}




//////////
//
// Called from subobjects to render any object children and sibling they may have based on flags
//
//////
	u32 iObj_renderChildrenAndSiblings(SObject* obj, bool tlRenderChildren, bool tlRenderSiblings, bool tlForceRender)
	{
		u32			lnPixelsRendered;
		SObject*	objSib;


		logfunc(__FUNCTION__);
		//////////
		// Render any children
		//////
			lnPixelsRendered = 0;
			if (tlRenderChildren && obj->firstChild)
				lnPixelsRendered += iObj_renderChildrenAndSiblings(obj->firstChild, true, true, tlForceRender);


		//////////
		// Render self
		//////
			obj->isDirtyRender |= tlForceRender;
			lnPixelsRendered += iObj_render(obj, tlForceRender);


		//////////
		// Render any siblings
		//////
			if (tlRenderSiblings && obj->ll.next)
			{
				objSib = (SObject*)obj->ll.next;
				while (objSib)
				{
					// Render this sibling
					lnPixelsRendered += iObj_renderChildrenAndSiblings(objSib, true, false, tlForceRender);

					// Move to next sibling
					objSib = (SObject*)objSib->ll.next;
				}
			}


		//////////
		// Indicate how much was rendered
		//////
			return(lnPixelsRendered);
	}




//////////
//
// Called to publish the indicated object, which takes the rendered bitmaps of all child objects
// and overlays them where they should be.
//
//////
	u32 iObj_publish(SObject* obj, RECT* rc, SBitmap* bmpDst, bool tlPublishChildren, bool tlPublishSiblings, bool tlForcePublish, s32 tnLevel)
	{
		s32			lnWidth, lnHeight, lnBackStyle;
		u32			lnPixelsRendered;
		bool		llPublishChildren, llIsVisible, llIsEnabled;
		RECT		lrc, lrcChild, lrc2;
		SWindow*	win;
		SObject*	objRoot;
		SObject*	objSib;


		// Make sure our environment is sane
		logfunc(__FUNCTION__);
		lnPixelsRendered = 0;
		if (obj && obj->bmp)
		{
			//////////
			// Set the force publish flag if need be
			//////
				obj->isDirtyPublish |= (tlForcePublish || tnLevel == 1);


			//////////
			// Determine the position within the parent's rectangle where this object will go
			//////
				// Adjust this item within the parent's rectangle
				SetRect(&lrc,	rc->left	+ obj->rc.left,
								rc->top		+ obj->rc.top,
								rc->left	+ obj->rc.right,
								rc->top		+ obj->rc.bottom);

				// Default the parent's rectangle for any subsequent drawing within by children
				SetRect(&lrcChild, 0, 0, obj->bmp->bi.biWidth, obj->bmp->bi.biHeight);

				// This is a top-level entry, so adjust everything to rcClient, or to 0
				llPublishChildren = true;
				switch (obj->objType)
				{
					case _OBJ_TYPE_FORM:
						// Bypass the frame area
						CopyRect(&lrcChild, &obj->rcClient);
						break;

					case _OBJ_TYPE_SUBFORM:
						// Bypass the frame area
						CopyRect(&lrcChild, &obj->rcClient);

						// Validate if anything has changed on this subform's children, if not then we don't need to publish anything below
						if (!obj->isDirtyPublish && obj->firstChild)
							llPublishChildren = iObj_publish_descentCheck(obj->firstChild, true, true);
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
				llIsVisible = isVisible(obj);
				llIsEnabled = isEnabled(obj);
				lnBackStyle	= backStyle(obj);
				if (llPublishChildren && llIsVisible && tlPublishChildren && obj->firstChild)
					lnPixelsRendered += iObj_publish(obj->firstChild, &lrcChild, obj->bmp, true, true, tlForcePublish, tnLevel + 1);


			//////////
			// Publish this item
			//////
				if (llIsVisible)
				{
					//////////
					// See if there is any onPublish() algorithm associated with this object
					//////
						if (obj->ev.general._onPublish)
						{
							// Find the root object
							objRoot = iObj_find_rootmostObject(obj);
							if (objRoot)
							{
								// Locate the associated window (if any)
								win = iWindow_findByObj(objRoot);
								obj->ev.general.onPublish(win, obj);
							}
						}


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
						if (bmpDst && obj->isPublished && obj->isDirtyPublish)
						{
							// If it's not enabled, grayscale it
							if (!llIsEnabled)
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
										if (lnBackStyle == _BACK_STYLE_OPAQUE)		lnPixelsRendered += iBmp_bitBlt(bmpDst,		&lrc, obj->bmpScaled);
										else										lnPixelsRendered += iBmp_bitBltMask(bmpDst,	&lrc, obj->bmpScaled);
										break;

									default:
										lnPixelsRendered += iBmp_bitBlt(bmpDst, &lrc, obj->bmpScaled);
										break;
								}
						}

					} else {
						// We can just copy
						if (bmpDst && obj->isPublished && obj->isDirtyPublish && tnLevel != 0)
						{
							// If it's not enabled, grayscale it
							if (!llIsEnabled)
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
										if (lnBackStyle == _BACK_STYLE_OPAQUE)		lnPixelsRendered += iBmp_bitBlt(bmpDst, &lrc, obj->bmp);
										else										lnPixelsRendered += iBmp_bitBltMask(bmpDst, &lrc, obj->bmp);
										break;

									case _OBJ_TYPE_LABEL:
										// Non-opaque labels are rendered as black on white, with that grayscale being used to influence the forecolor
										if (lnBackStyle == _BACK_STYLE_OPAQUE)		lnPixelsRendered += iBmp_bitBlt(bmpDst, &lrc, obj->bmp);
										else										lnPixelsRendered += iBmp_bitBlt_byGraymask(bmpDst, &lrc, obj->bmp, iObjProp_get_sbgra_direct(obj, _INDEX_FORECOLOR));
										break;

									default:
										lnPixelsRendered += iBmp_bitBlt(bmpDst, &lrc, obj->bmp);
										break;
								}
						}
					}
				}


			//////////
			// Lower the flag at this level
			//////
				obj->isDirtyPublish = false;


// s8 buffer[256];
// if (tnLevel >= 0)
// {
// 	sprintf(buffer, "c:\\temp\\publish\\%u_%u_%d.bmp\0", ++gnNextUniqueId, (u32)obj, tnLevel);
// 	iBmp_saveToDisk(bmpDst, buffer);
// }

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
						lnPixelsRendered += iObj_publish(objSib, rc, bmpDst, true, false, tlForcePublish, tnLevel);

						// Move to next sibling
						objSib = (SObject*)objSib->ll.next;
					}
				}
		}


		//////////
		// Indicate how many pixels were painted
		//////
			return(lnPixelsRendered);
	}




//////////
//
// Called to descend through the children to see if anything needs to be published.
//
//////
	bool iObj_publish_descentCheck(SObject * obj, bool tlCheckChildren, bool tlCheckSiblings)
	{
		SObject* objSib;


		//////////
		// If it's dirty, we need to publish
		//////
			if (obj->isDirtyPublish)
				return(true);


		//////////
		// Check the children
		//////
			if (tlCheckChildren && obj->firstChild && iObj_publish_descentCheck(obj->firstChild, true, true))
				return(true);


		//////////
		// Check the siblings
		//////
			if (tlCheckSiblings && obj->ll.next)
			{
				// Skip to the sibling
				objSib = (SObject*)obj->ll.next;
				while (objSib)
				{
					// See if this one needs to be published
					if (iObj_publish_descentCheck(objSib, true, false))
						return(true);

					// Move to next sibling
					objSib = (SObject*)objSib->ll.next;
				}
			}


		//////////
		// If we get here, this object and its children do not need to be published
		//////
			return(false);
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
		logfunc(__FUNCTION__);
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
		logfunc(__FUNCTION__);
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
		logfunc(__FUNCTION__);
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
		s32			lnAlignment;
		SObject*	objChild;
		SBitmap*	bmp;
		RECT		lrc;


		// Resize if need be (32-bit bitmap for labels, 24-bit for everything else)
		logfunc(__FUNCTION__);
		if (obj->bmp && (obj->bmp->bi.biWidth != tnWidth || obj->bmp->bi.biHeight != tnHeight))
			iBmp_delete(&obj->bmp, true, true);

		// Delete any prior rendered buffers, and any scaled buffers
		if (obj->bmpPriorRendered)			iBmp_delete(&obj->bmpPriorRendered,		true, true);
		if (obj->bmpScaled)					iBmp_delete(&obj->bmpScaled,			true, true);

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
						if (objChild->objType == _OBJ_TYPE_IMAGE && isName(objChild, cgcName_icon))
						{
							logfunc("form icon");
							// Form icon
							SetRect(&objChild->rc,
										bmpArrowUl->bi.biWidth + 4 - obj->rcClient.left,
										1 - obj->rcClient.top,
										bmpArrowUl->bi.biWidth + 4 - obj->rcClient.left + bmpArrowUl->bi.biWidth,
										1 + bmpArrowUl->bi.biHeight - obj->rcClient.top);

							// Update the size
							iObj_setSize(objChild, objChild->rc.left, objChild->rc.top, objChild->rc.right - objChild->rc.left, objChild->rc.bottom - objChild->rc.top);

						} else if (objChild->objType == _OBJ_TYPE_LABEL && isName(objChild, cgcName_caption)) {
							// Caption
							logfunc("form caption");
							SetRect(&objChild->rc,
										bmpArrowUl->bi.biWidth + 4 + bmpArrowUl->bi.biWidth + 8 - obj->rcClient.left,
										2 - obj->rcClient.top,
										tnWidth - (5 * (bmpArrowUl->bi.biWidth + 2)) - obj->rcClient.left - 4,
										1 + bmpArrowUl->bi.biHeight - obj->rcClient.top);

							// Update the size
							iObj_setSize(objChild, objChild->rc.left, objChild->rc.top, objChild->rc.right - objChild->rc.left, objChild->rc.bottom - objChild->rc.top);

						} else if (objChild->objType == _OBJ_TYPE_IMAGE && isName(objChild, cgcName_iconMove)) {
							// Move icon
							logfunc("form move icon");
							SetRect(&objChild->rc,
										tnWidth - (5 * (bmpArrowUl->bi.biWidth + 2)) - obj->rcClient.left,
										1 - obj->rcClient.top,
										tnWidth - (5 * (bmpArrowUl->bi.biWidth + 2)) - obj->rcClient.left + bmpArrowUl->bi.biWidth,
										1 + bmpArrowUl->bi.biHeight - obj->rcClient.top);

							// Update the size
							iObj_setSize(objChild, objChild->rc.left, objChild->rc.top, objChild->rc.right - objChild->rc.left, objChild->rc.bottom - objChild->rc.top);

						} else if (objChild->objType == _OBJ_TYPE_IMAGE && isName(objChild, cgcName_iconMinimize)) {
							// Minimize icon
							logfunc("form minimize icon");
							SetRect(&objChild->rc,
										tnWidth - (4 * (bmpArrowUl->bi.biWidth + 2)) - obj->rcClient.left,
										1 - obj->rcClient.top,
										tnWidth - (4 * (bmpArrowUl->bi.biWidth + 2)) - obj->rcClient.left + bmpArrowUl->bi.biWidth,
										1 + bmpArrowUl->bi.biHeight - obj->rcClient.top);

							// Update the size
							iObj_setSize(objChild, objChild->rc.left, objChild->rc.top, objChild->rc.right - objChild->rc.left, objChild->rc.bottom - objChild->rc.top);

						} else if (objChild->objType == _OBJ_TYPE_IMAGE && isName(objChild, cgcName_iconMaximize)) {
							// Maximize icon
							logfunc("form maximize icon");
							SetRect(&objChild->rc,
										tnWidth - (3 * (bmpArrowUl->bi.biWidth + 2)) - obj->rcClient.left,
										1 - obj->rcClient.top,
										tnWidth - (3 * (bmpArrowUl->bi.biWidth + 2)) - obj->rcClient.left + bmpArrowUl->bi.biWidth,
										1 + bmpArrowUl->bi.biHeight - obj->rcClient.top);

							// Update the size
							iObj_setSize(objChild, objChild->rc.left, objChild->rc.top, objChild->rc.right - objChild->rc.left, objChild->rc.bottom - objChild->rc.top);

						} else if (objChild->objType == _OBJ_TYPE_IMAGE && isName(objChild, cgcName_iconClose)) {
							// Close icon
							logfunc("form close icon");
							SetRect(&objChild->rc,
										tnWidth - (2 * (bmpArrowUl->bi.biWidth + 2)) - obj->rcClient.left,
										1 - obj->rcClient.top,
										tnWidth - (2 * (bmpArrowUl->bi.biWidth + 2)) - obj->rcClient.left + bmpArrowUl->bi.biWidth,
										1 + bmpArrowUl->bi.biHeight - obj->rcClient.top);

							// Update the size
							iObj_setSize(objChild, objChild->rc.left, objChild->rc.top, objChild->rc.right - objChild->rc.left, objChild->rc.bottom - objChild->rc.top);
						}

						// Move to next object
						objChild = (SObject*)objChild->ll.next;
					}
				break;

			case _OBJ_TYPE_SUBFORM:
				if (borderStyle(obj) != _BORDER_STYLE_NONE)		SetRect(&obj->rcClient, 1, bmpArrowUl->bi.biHeight + 1, tnWidth - 8 - 1, tnHeight - 1);
				else											SetRect(&obj->rcClient, 0, bmpArrowUl->bi.biHeight, tnWidth - 8, tnHeight);

				//////////
				// Default child settings:
				// [icon][caption                     ]
				//////
					objChild = obj->firstChild;
					while (objChild)
					{
						// See which object this is
						if (objChild->objType == _OBJ_TYPE_IMAGE && isName(objChild, cgcName_icon))
						{
							// Subform icon
							logfunc("subform icon");
							SetRect(&objChild->rc,
										1,
										1 - obj->rcClient.top,
										1 + bmpArrowUl->bi.biWidth,
										1 + bmpArrowUl->bi.biHeight - obj->rcClient.top);

							// Update the size
							iObj_setSize(objChild, objChild->rc.left, objChild->rc.top, objChild->rc.right - objChild->rc.left, objChild->rc.bottom - objChild->rc.top);

						} else if (objChild->objType == _OBJ_TYPE_LABEL && isName(objChild, cgcName_caption)) {
							// Caption
							logfunc("subform caption");
							SetRect(&objChild->rc,
										1 + bmpArrowUl->bi.biWidth + 4,
										2 - obj->rcClient.top,
										tnWidth - 4,
										2 - obj->rcClient.top + objChild->p.font->tm.tmHeight + 2);

							// Update the size
							iObj_setSize(objChild,	objChild->rc.left,
													objChild->rc.top,
													objChild->rc.right  - objChild->rc.left,
													objChild->rc.bottom - objChild->rc.top);
						}

						// Move to next object
						objChild = (SObject*)objChild->ll.next;
					}
				break;

			case _OBJ_TYPE_LABEL:
			case _OBJ_TYPE_EDITBOX:
			case _OBJ_TYPE_IMAGE:
			case _OBJ_TYPE_BUTTON:
				// Just use the default rcClient settings above
				break;

			case _OBJ_TYPE_TEXTBOX:
				// Just use the default rcClient settings above
				break;

			case _OBJ_TYPE_CHECKBOX:
				//////////
				// Default child settings
				// [check][label]
				//////
					SetRect(&lrc, 0, 0, tnHeight, tnHeight);
					lnAlignment	= alignment(obj);
					objChild	= obj->firstChild;
					while (objChild)
					{
						// See which object this is
						if (objChild->objType == _OBJ_TYPE_IMAGE && isName(objChild, cgcName_checkboxImage))
						{
							// Adjust the size and position
							logfunc("checkbox image");
							switch (lnAlignment)
							{
								default:
								case _ALIGNMENT_LEFT:
									iObj_setSize(objChild, 0, 0, tnHeight, tnHeight);
									break;

								case _ALIGNMENT_RIGHT:
									iObj_setSize(objChild, obj->rc.right - tnHeight, 0, obj->rc.right - obj->rc.left - tnHeight, tnHeight);
									break;
							}

							// Checkbox image
							bmp = iBmp_allocate();
							iBmp_createBySize(bmp, tnHeight, tnHeight, 24);

							// Based on type, populate the image
							if (iObjProp_get_s32_direct(obj, _INDEX_VALUE) == 0)
							{
								// Off
								iBmp_scale(bmp, bmpCheckboxOff);		// Set the new

							} else {
								// On
								iBmp_scale(bmp, bmpCheckboxOn);			// Set the new
							}

							// Populate the standard image
							iObjProp_set_bitmap_direct(obj, _INDEX_PICTUREBMP,		bmp);
							iObjProp_set_bitmap_direct(obj, _INDEX_PICTUREBMP_DOWN,	bmp);
							iObjProp_set_bitmap_direct(obj, _INDEX_PICTUREBMP_OVER,	bmp);

							// Delete our template
							iBmp_delete(&bmp, true, true);

							// Add highlighting for the over and down
							bmp = iObjProp_get_bitmap(obj, _INDEX_PICTUREBMP_OVER);				iBmp_colorize(bmp, &lrc, colorMouseOver, false, 0.5f);
							bmp = iObjProp_get_bitmap(obj, _INDEX_PICTUREBMP_DOWN);				iBmp_colorize(bmp, &lrc, colorMouseDown, false, 0.5f);

							// Mark it for re-render
							objChild->isDirtyRender = true;

						} else if (objChild->objType == _OBJ_TYPE_LABEL && isName(objChild, cgcName_checkboxLabel)) {
							// Adjust the size
							logfunc("checkbox label");
							switch (alignment(obj))
							{
								default:
								case _ALIGNMENT_LEFT:
									iObj_setSize(objChild, tnHeight, 0, obj->rc.right - obj->rc.left - tnHeight, tnHeight);
									break;

								case _ALIGNMENT_RIGHT:
									iObj_setSize(objChild, 0, 0, obj->rc.right - obj->rc.left - tnHeight, tnHeight);
									break;
							}

							// Mark it for re-render
							objChild->isDirtyRender = true;
						}

						// Move to next object
						objChild = (SObject*)objChild->ll.next;
					}
				break;

			case _OBJ_TYPE_OPTION:
				// Just use the default rcClient settings above
				break;

			case _OBJ_TYPE_RADIO:
				// Just use the default rcClient settings above
				break;
		}

		// Mark it dirty for a full re-render
		obj->isDirtyRender = true;
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
		logfunc(__FUNCTION__);
		winNew = NULL;
		if (obj_form)
			winNew = iWindow_createForObject(obj_form, winReuse, icon);

		// Indicate our status
		return(winNew);
	}




//////////
//
// Searches the indicated object for the indicated property
//
//////
	SVariable* iObj_getPropertyAsVariable(SObject* obj, s8* tcPropertyName, u32 tnPropertyNameLength, SComp* comp)
	{
		SBaseclassList*		lbcl;
		SObjPropertyMap*	lpm;


		// Make sure our environment is sane
		logfunc(__FUNCTION__);
		if (obj)
		{
			// Find out our property interface
			lbcl = iiObj_getBaseclass_byType(obj->objType);
			if (lbcl)
			{
				// Search through the properties
				lpm = lbcl->objProps;
				while (lpm && gsProps_master[lpm->index].propName)
				{
					// Is this the name?
					if (gsProps_master[lpm->index].propLength == tnPropertyNameLength && _memicmp(tcPropertyName, gsProps_master[lpm->index].propName, tnPropertyNameLength) == 0)
						return(obj->props[lpm->index]);		// This is the property, retrieve its value

					// Move to next property
					++lpm;
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
		logfunc(__FUNCTION__);
		if (obj)
		{
			// Update the sub-object data
			switch (obj->objType)
			{
				case _OBJ_TYPE_EMPTY:		// Empty, used as a placeholder object that is not drawn
					iiSubobj_resetToDefaultEmpty(obj, tlResetProperties, tlResetMethods, &gsProps_empty[0], gnProps_emptySize);
					break;

				case _OBJ_TYPE_FORM:			// Form class, the main outer window the OS sees
					iiSubobj_resetToDefaultForm(obj, tlResetProperties, tlResetMethods, &gsProps_form[0], gnProps_formSize);
					break;

				case _OBJ_TYPE_SUBFORM:		// A new class which has its own drawing content and can be moved about using UI features
					iiSubobj_resetToDefaultSubform(obj, tlResetProperties, tlResetMethods, &gsProps_subform[0], gnProps_subformSize);
					break;

				case _OBJ_TYPE_LABEL:		// A label
					iiSubobj_resetToDefaultLabel(obj, tlResetProperties, tlResetMethods, &gsProps_label[0], gnProps_labelSize);
					break;

				case _OBJ_TYPE_TEXTBOX:		// An input textbox
					iiSubobj_resetToDefaultTextbox(obj, tlResetProperties, tlResetMethods, &gsProps_textbox[0], gnProps_textboxSize);
					break;

				case _OBJ_TYPE_BUTTON:		// A push button
					iiSubobj_resetToDefaultButton(obj, tlResetProperties, tlResetMethods, &gsProps_button[0], gnProps_buttonSize);
					break;

				case _OBJ_TYPE_EDITBOX:		// An input multi-line editbox
					iiSubobj_resetToDefaultEditbox(obj, tlResetProperties, tlResetMethods, &gsProps_editbox[0], gnProps_editboxSize);
					break;

				case _OBJ_TYPE_IMAGE:		// A graphical image
					iiSubobj_resetToDefaultImage(obj, tlResetProperties, tlResetMethods, &gsProps_image[0], gnProps_imageSize);
					break;

				case _OBJ_TYPE_CHECKBOX:		// A checkbox
					iiSubobj_resetToDefaultCheckbox(obj, tlResetProperties, tlResetMethods, &gsProps_checkbox[0], gnProps_checkboxSize);
					break;

				case _OBJ_TYPE_OPTION:		// A combination selection
					iiSubobj_resetToDefaultOption(obj, tlResetProperties, tlResetMethods, &gsProps_option[0], gnProps_optionSize);
					break;

				case _OBJ_TYPE_RADIO:		// A radio dial, which can also present as a slider or spinner
					iiSubobj_resetToDefaultRadio(obj, tlResetProperties, tlResetMethods, &gsProps_radio[0], gnProps_radioSize);
					break;

				default:
// TODO:  We should never get here... we should fire off an internal consistency error
					break;
			}
		}
	}




//////////
//
// Resets common object properties to their defaults.
//
//////
	void iiObj_resetToDefaultCommon(SObject* obj, bool tlResetProperties, bool tlResetMethods, SObjPropertyMap* propMap, s32 tnPropCount)
	{
		s32 lnI, lnIndex, lnAllocationSize;


		logfunc(__FUNCTION__);
		//////////
		// Make sure the properties are allocated
		//////
			if (!obj->props)
			{
				lnAllocationSize	= tnPropCount * sizeof(SVariable*);
				obj->props			= (SVariable**)malloc(lnAllocationSize);
				memset(obj->props, 0, lnAllocationSize);
			}


		//////////
		// Set properties
		//////
			for (lnI = 0; lnI < tnPropCount; lnI++)
			{
				//////////
				// Grab the index of this entry in the master list
				//////
					lnIndex = propMap[lnI].index;


				//////////
				// Delete the old variable
				//////
					if (obj->props[lnI])
					{
						iVariable_delete(obj->props[lnI], true);
						obj->props[lnI] = NULL;
					}


				//////////
				// Create the base variable based on the master init variable created at startup
				//////
// if (lnIndex == 235 || lnIndex == 234 || lnIndex == 233)
// 	debug_break;
					obj->props[lnI] = iVariable_copy(gsProps_master[lnIndex].varInit, false);

// Should never happen
if (!obj->props[lnI])
	debug_break;

				//////////
				// Perform any base class initialization
				//////
					if (gsProps_master[lnIndex]._initterBase)
						gsProps_master[lnIndex].initterBase(obj, lnIndex);


				//////////
				// Finalize the initialization with any additional steps specific to the object
				//////
					if (propMap[lnI]._initterObject)
						propMap[lnI].initterObject(obj, lnIndex);
			}


		//////////
		// Related to rendering
		//////
			obj->isRendered		= true;
			obj->isPublished	= true;
			obj->isDirtyRender	= true;


		//////////
		// Any properties within
		//////
			if (tlResetProperties)
				iVariable_politelyDeleteChain(&obj->firstProperty, true);


		//////////
		// Any methods defined
		//////
			if (tlResetMethods)
				iSEM_deleteChain(&obj->firstMethod, true);


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
	}




//////////
//
// Called to translate the text-based class name to its internal object type.
//
//////
	s32 iiObj_getBaseclassType_byName(s8* tcTextname, s32 tnTextnameLength)
	{
		s32 lnI;
		
		
		// Iterate through each function for matches
		logfunc(__FUNCTION__);
		for (lnI = 0; gsKnownBaseclasses[lnI].objType != 0; lnI++)
		{
			// Is this the named function?
			if (gsKnownBaseclasses[lnI].baseclassNameLength == tnTextnameLength && _memicmp(tcTextname, (s8*)gsKnownBaseclasses[lnI].baseclassName, tnTextnameLength) == 0)
				return(gsKnownBaseclasses[lnI].objType);
		}
		// If we get here, not found
		return(0);
	}




//////////
//
// Called to translate the text-based class name to its internal object reference
//
//////
	SBaseclassList* iiObj_getBaseclass_byName(s8* tcTextname, s32 tnTextnameLength)
	{
		s32 lnI;
		
		
		// Iterate through each function for matches
		logfunc(__FUNCTION__);
		for (lnI = 0; gsKnownBaseclasses[lnI].objType != 0; lnI++)
		{
			// Is this the named function?
			if (gsKnownBaseclasses[lnI].baseclassNameLength == tnTextnameLength && _memicmp(tcTextname, (s8*)gsKnownBaseclasses[lnI].baseclassName, tnTextnameLength) == 0)
				return(&gsKnownBaseclasses[lnI]);
		}
		// If we get here, not found
		return(NULL);
	}





//////////
//
// Called to translate the class object type to its text-base name
//
//////
	SBaseclassList* iiObj_getBaseclass_byType(s32 tnObjType)
	{
		// Iterate through each function for matches
		logfunc(__FUNCTION__);
		if (tnObjType < gnKnownBaseclasses_size)
			return(&gsKnownBaseclasses[tnObjType - 1]);

		// If we get here, invalid
		return(NULL);
	}




//////////
//
// Called to publish the carousel.
//
//////
	u32 iSubobj_publishCarousel(SObject* carousel, bool tlForcePublish)
	{
// TODO:  Working here
		return(0);
	}




//////////
//
// Called to publish the rider within the carousel
//
//////
	u32 iSubobj_publishRider(SObject* rider, bool tlForcePublish)
	{
// TODO:  Working here
		return(0);
	}
