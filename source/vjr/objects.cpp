//////////
//
// /libsf/source/vjr/objects.cpp
//
//////
// Version 0.53
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
		u32		lnPixelsRendered;
// 		bool	llRenderChildren;


		// Make sure our environment is sane
		logfunc(__FUNCTION__);
		lnPixelsRendered = 0;
		if (obj && obj->isRendered)
		{
			//////////
			// If they're forcing a render, set it up
			//////
				obj->isDirtyRender |= tlForceRender;


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
			// Check to see if anything below this level needs rendered
			//////
// 				llRenderChildren = obj->isDirtyRender;
// 				if (!obj->isDirtyRender)
// 					llRenderChildren |= iObj_render_descentCheck(obj, true, true);


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
if (!llPublishChildren)
	debug_break;

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
// Creates the empty object structure
//
//////
	SObject* iSubobj_createEmpty(SObject* template_empty, SObject* parent)
	{
		SObject*	emptyNew;
		SVariable*	var;


		logfunc(__FUNCTION__);
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

				// Initialize properties to VJr defaults
				emptyNew->objType		= _OBJ_TYPE_EMPTY;
				emptyNew->parent		= parent;
				iiSubobj_resetToDefaultEmpty(emptyNew, true, true, &gsProps_empty[0], gnProps_emptySize);

				// Initially populate
				setEnabled(emptyNew, _LOGICAL_TRUE);
				emptyNew->isRendered	= true;
				emptyNew->isPublished	= true;
				var = iObjProp_get_variable_byIndex(emptyNew, _INDEX_NAME);				iDatum_duplicate(&var->value, cgcName_empty, -1);
				var = iObjProp_get_variable_byIndex(emptyNew, _INDEX_CLASS);			iDatum_duplicate(&var->value, cgcName_empty, -1);

				// Events
				iEvents_resetToDefault(&emptyNew->ev);

				// Initialize based on template
				if (template_empty)
					iiSubobj_copyEmpty(emptyNew, template_empty);		// Copy from indicated template
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
		SVariable*	var;


		logfunc(__FUNCTION__);
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

				// Initialize properties to VJr defaults
				formNew->objType		= _OBJ_TYPE_FORM;
				formNew->parent			= parent;

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
					var = iObjProp_get_variable_byIndex(icon,		_INDEX_NAME);		iDatum_duplicate(&var->value,	cgcName_icon,			-1);
					var = iObjProp_get_variable_byIndex(caption,	_INDEX_NAME);		iDatum_duplicate(&var->value,	cgcName_caption,		-1);
					var = iObjProp_get_variable_byIndex(move,		_INDEX_NAME);		iDatum_duplicate(&var->value,	cgcName_iconMove,		-1);
					var = iObjProp_get_variable_byIndex(minimize,	_INDEX_NAME);		iDatum_duplicate(&var->value,	cgcName_iconMinimize,	-1);
					var = iObjProp_get_variable_byIndex(maximize,	_INDEX_NAME);		iDatum_duplicate(&var->value,	cgcName_iconMaximize,	-1);
					var = iObjProp_get_variable_byIndex(close,		_INDEX_NAME);		iDatum_duplicate(&var->value,	cgcName_iconClose,		-1);


				//////////
				// Default initialization
				//////
					iiSubobj_resetToDefaultForm(formNew, true, true, &gsProps_form[0], gnProps_formSize);


				// Initially populate
				setEnabled(formNew, _LOGICAL_TRUE);
				formNew->isRendered		= true;
				formNew->isPublished	= true;
				var = iObjProp_get_variable_byIndex(formNew, _INDEX_NAME);				iDatum_duplicate(&var->value, cgcName_form, -1);
				var = iObjProp_get_variable_byIndex(formNew, _INDEX_CLASS);				iDatum_duplicate(&var->value, cgcName_form, -1);
				iEvents_resetToDefault(&formNew->ev);
				iObj_setSize(formNew, 0, 0, 375, 250);

				// Initialize based on template
				if (template_form)
					iiSubobj_copyForm(formNew, template_form);		// Copy from indicated template
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
		SVariable*	var;


		logfunc(__FUNCTION__);
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

				// Initialize properties to VJr defaults
				subformNew->objType		= _OBJ_TYPE_SUBFORM;
				subformNew->parent		= parent;


				//////////
				// Create the default children for this object
				//////
					icon		= iObj_addChild(_OBJ_TYPE_IMAGE, subformNew);
					caption		= iObj_addChild(_OBJ_TYPE_LABEL, subformNew);


				//////////
				// Give them proper names
				//////
					var = iObjProp_get_variable_byIndex(icon,		_INDEX_NAME);		iDatum_duplicate(&var->value,	cgcName_icon,		-1);
					var = iObjProp_get_variable_byIndex(caption,	_INDEX_NAME);		iDatum_duplicate(&var->value,	cgcName_caption,	-1);


				//////////
				// Default initialization
				//////
					iiSubobj_resetToDefaultSubform(subformNew, true, true, &gsProps_subform[0], gnProps_subformSize);

				// Initially populate
				setEnabled(subformNew, _LOGICAL_TRUE);
				subformNew->isRendered	= true;
				subformNew->isPublished	= true;
				var = iObjProp_get_variable_byIndex(subformNew, _INDEX_NAME);			iDatum_duplicate(&var->value, cgcName_subform, -1);
				var = iObjProp_get_variable_byIndex(subformNew, _INDEX_CLASS);			iDatum_duplicate(&var->value, cgcName_subform, -1);
				iEvents_resetToDefault(&subformNew->ev);
				iObj_setSize(subformNew, 0, 0, 200, 100);

				// Initialize based on template
				if (template_subform)
					iiSubobj_copySubform(subformNew, template_subform);		// Copy from indicated template
			}


		//////////
		// Indicate our success or failure
		//////
			return(subformNew);
	}




//////////
//
// Creates the carousel object structure
//
//////
	SObject* iSubobj_createCarousel(SObject* template_carousel, SObject* parent)
	{
		SObject*	carouselNew;
		SObject*	icon;
		SObject*	caption;
		SObject*	close;
		SVariable*	var;


		logfunc(__FUNCTION__);
		//////////
		// Create the indicated item
		//////
			carouselNew = (SObject*)malloc(sizeof(SObject));


		//////////
		// If successful, initialize it
		//////
			if (carouselNew)
			{
				// Initialize
				memset(carouselNew, 0, sizeof(SObject));

				// Initialize properties to VJr defaults
				carouselNew->objType		= _OBJ_TYPE_CAROUSEL;
				carouselNew->parent			= parent;


				//////////
				// Create the default children for this object
				//////
					icon		= iObj_addChild(_OBJ_TYPE_IMAGE, carouselNew);
					caption		= iObj_addChild(_OBJ_TYPE_LABEL, carouselNew);
					close		= iObj_addChild(_OBJ_TYPE_IMAGE, carouselNew);


				//////////
				// Give them proper names
				//////
					var = iObjProp_get_variable_byIndex(icon,		_INDEX_NAME);		iDatum_duplicate(&var->value,	cgcName_icon,		-1);
					var = iObjProp_get_variable_byIndex(caption,	_INDEX_NAME);		iDatum_duplicate(&var->value,	cgcName_caption,	-1);
					var = iObjProp_get_variable_byIndex(close,		_INDEX_NAME);		iDatum_duplicate(&var->value,	cgcName_iconClose,	-1);


				//////////
				// Default initialization
				//////
					iiSubobj_resetToDefaultCarousel(carouselNew, true, true, &gsProps_carousel[0], gnProps_carouselSize);


				// Initially populate
				setEnabled(carouselNew, _LOGICAL_TRUE);
				carouselNew->isRendered		= true;
				carouselNew->isPublished	= true;
				var = iObjProp_get_variable_byIndex(carouselNew, _INDEX_NAME);			iDatum_duplicate(&var->value, cgcName_carousel, -1);
				var = iObjProp_get_variable_byIndex(carouselNew, _INDEX_CLASS);			iDatum_duplicate(&var->value, cgcName_carousel, -1);
				iEvents_resetToDefault(&carouselNew->ev);
				iObj_setSize(carouselNew, 0, 0, 320, 480);

				// Initialize based on template
				if (template_carousel)
					iiSubobj_copyCarousel(carouselNew, template_carousel);		// Copy from indicated template
			}


		//////////
		// Indicate our success or failure
		//////
			return(carouselNew);
	}




//////////
//
// Creates the rider object structure
//
//////
	SObject* iSubobj_createRider(SObject* template_rider, SObject* parent)
	{
		SObject*	riderNew;
		SVariable*	var;


		logfunc(__FUNCTION__);
		//////////
		// Create the indicated item
		//////
			riderNew = (SObject*)malloc(sizeof(SObject));


		//////////
		// If successful, initialize it
		//////
			if (riderNew)
			{
				// Initialize
				memset(riderNew, 0, sizeof(SObject));

				// Initialize properties to VJr defaults
				riderNew->objType		= _OBJ_TYPE_RIDER;
				riderNew->parent		= parent;
				iiSubobj_resetToDefaultRider(riderNew, true, true, &gsProps_rider[0], gnProps_riderSize);

				// Initially populate
				setEnabled(riderNew, _LOGICAL_TRUE);
				riderNew->isRendered	= true;
				riderNew->isPublished	= true;
				var = iObjProp_get_variable_byIndex(riderNew, _INDEX_NAME);				iDatum_duplicate(&var->value, cgcName_rider, -1);
				var = iObjProp_get_variable_byIndex(riderNew, _INDEX_CLASS);			iDatum_duplicate(&var->value, cgcName_rider, -1);
				iEvents_resetToDefault(&riderNew->ev);
				iObj_setSize(riderNew, 0, 0, 320, 480);

				// Initialize based on template
				if (template_rider)
					iiSubobj_copyRider(riderNew, template_rider);		// Copy from indicated template
			}


		//////////
		// Indicate our success or failure
		//////
			return(riderNew);
	}




//////////
//
// Creates the label object structure
//
//////
	SObject* iSubobj_createLabel(SObject* template_label, SObject* parent)
	{
		SObject*	labelNew;
		SVariable*	var;


		logfunc(__FUNCTION__);
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

				// Initialize properties to VJr defaults
				labelNew->objType		= _OBJ_TYPE_LABEL;
				labelNew->parent		= parent;
				iiSubobj_resetToDefaultLabel(labelNew, true, true, &gsProps_label[0], gnProps_labelSize);

				// Initially populate
				setEnabled(labelNew, _LOGICAL_TRUE);
				labelNew->isRendered	= true;
				labelNew->isPublished	= true;
				var = iObjProp_get_variable_byIndex(labelNew, _INDEX_NAME);				iDatum_duplicate(&var->value, cgcName_label, -1);
				var = iObjProp_get_variable_byIndex(labelNew, _INDEX_CLASS);			iDatum_duplicate(&var->value, cgcName_label, -1);
				iEvents_resetToDefault(&labelNew->ev);
				iObj_setSize(labelNew, 0, 0, 40, 17);

				// Initialize based on template
				if (template_label)
					iiSubobj_copyLabel(labelNew, template_label);		// Copy from indicated template
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
		SObject*	textboxNew;
		SVariable*	var;


		logfunc(__FUNCTION__);
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

				// Initialize properties to VJr defaults
				textboxNew->objType		= _OBJ_TYPE_TEXTBOX;
				textboxNew->parent		= parent;
				iiSubobj_resetToDefaultTextbox(textboxNew, true, true, &gsProps_textbox[0], gnProps_textboxSize);

				// Initially populate
				setEnabled(textboxNew, _LOGICAL_TRUE);
				textboxNew->isRendered	= true;
				textboxNew->isPublished	= true;
				var = iObjProp_get_variable_byIndex(textboxNew, _INDEX_NAME);				iDatum_duplicate(&var->value, cgcName_textbox, -1);
				var = iObjProp_get_variable_byIndex(textboxNew, _INDEX_CLASS);				iDatum_duplicate(&var->value, cgcName_textbox, -1);
				iEvents_resetToDefault(&textboxNew->ev);
				iObj_setSize(textboxNew, 0, 0, 100, 23);

				// Initialize based on template
				if (template_textbox)
					iiSubobj_copyTextbox(textboxNew, template_textbox);		// Copy from indicated template
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
		SObject*	buttonNew;
		SVariable*	var;


		logfunc(__FUNCTION__);
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

				// Initialize properties to VJr defaults
				buttonNew->objType		= _OBJ_TYPE_BUTTON;
				buttonNew->parent		= parent;
				iiSubobj_resetToDefaultButton(buttonNew, true, true, &gsProps_button[0], gnProps_buttonSize);

				// Initially populate
				setEnabled(buttonNew, _LOGICAL_TRUE);
				buttonNew->isRendered	= true;
				buttonNew->isPublished	= true;
				var = iObjProp_get_variable_byIndex(buttonNew, _INDEX_NAME);			iDatum_duplicate(&var->value, cgcName_button, -1);
				var = iObjProp_get_variable_byIndex(buttonNew, _INDEX_CLASS);			iDatum_duplicate(&var->value, cgcName_button, -1);
				iEvents_resetToDefault(&buttonNew->ev);
				iObj_setSize(buttonNew, 0, 0, 84, 27);

				// Initialize based on template
				if (template_button)
					iiSubobj_copyButton(buttonNew, template_button);		// Copy from indicated template
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
		SObject*	editboxNew;
		SVariable*	var;


		logfunc(__FUNCTION__);
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

				// Initialize properties to VJr defaults
				editboxNew->objType		= _OBJ_TYPE_EDITBOX;
				editboxNew->parent		= parent;
				iiSubobj_resetToDefaultEditbox(editboxNew, true, true, &gsProps_editbox[0], gnProps_editboxSize);

				// Initially populate
				setEnabled(editboxNew, _LOGICAL_TRUE);
				editboxNew->isRendered	= true;
				editboxNew->isPublished	= true;
				var = iObjProp_get_variable_byIndex(editboxNew, _INDEX_NAME);			iDatum_duplicate(&var->value, cgcName_editbox, -1);
				var = iObjProp_get_variable_byIndex(editboxNew, _INDEX_CLASS);			iDatum_duplicate(&var->value, cgcName_editbox, -1);
				iEvents_resetToDefault(&editboxNew->ev);
				iObj_setSize(editboxNew, 0, 0, 100, 53);

				// Initialize based on template
				if (template_editbox)
					iiSubobj_copyEditbox(editboxNew, template_editbox);		// Copy from indicated template
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
		SObject*	imageNew;
		SVariable*	var;


		logfunc(__FUNCTION__);
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

				// Initialize properties to VJr defaults
				imageNew->objType		= _OBJ_TYPE_IMAGE;
				imageNew->parent		= parent;
				iiSubobj_resetToDefaultImage(imageNew, true, true, &gsProps_image[0], gnProps_imageSize);

				// Initially populate
				setEnabled(imageNew, _LOGICAL_TRUE);
				imageNew->isRendered	= true;
				imageNew->isPublished	= true;
				var = iObjProp_get_variable_byIndex(imageNew, _INDEX_NAME);				iDatum_duplicate(&var->value, cgcName_image, -1);
				var = iObjProp_get_variable_byIndex(imageNew, _INDEX_CLASS);			iDatum_duplicate(&var->value, cgcName_image, -1);
				iEvents_resetToDefault(&imageNew->ev);
				iObj_setSize(imageNew, 0, 0, 100, 36);

				// Initialize based on template
				if (template_image)
					iiSubobj_copyImage(imageNew, template_image);		// Copy from indicated template
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
		SObject*	checkboxNew;
		SObject*	image;
		SObject*	label;
		SVariable*	var;


		logfunc(__FUNCTION__);
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

				// Initialize properties to VJr defaults
				checkboxNew->objType		= _OBJ_TYPE_CHECKBOX;
				checkboxNew->parent			= parent;


				//////////
				// Create the default children for this object
				//////
					image	= iObj_addChild(_OBJ_TYPE_IMAGE, checkboxNew);
					label	= iObj_addChild(_OBJ_TYPE_LABEL, checkboxNew);


				//////////
				// Give them proper names
				//////
					var = iObjProp_get_variable_byIndex(image,	_INDEX_NAME);			iDatum_duplicate(&var->value,	cgcName_checkboxImage,	-1);
					var = iObjProp_get_variable_byIndex(label,	_INDEX_NAME);			iDatum_duplicate(&var->value,	cgcName_checkboxLabel,	-1);


				//////////
				// Default initialization
				//////
					iiSubobj_resetToDefaultCheckbox(checkboxNew, true, true, &gsProps_checkbox[0], gnProps_checkboxSize);


				// Initially populate
				setEnabled(checkboxNew, _LOGICAL_TRUE);
				checkboxNew->isRendered		= true;
				checkboxNew->isPublished	= true;
				var = iObjProp_get_variable_byIndex(checkboxNew, _INDEX_NAME);			iDatum_duplicate(&var->value, cgcName_checkbox, -1);
				var = iObjProp_get_variable_byIndex(checkboxNew, _INDEX_CLASS);			iDatum_duplicate(&var->value, cgcName_checkbox, -1);
				iEvents_resetToDefault(&checkboxNew->ev);
				iObj_setSize(checkboxNew, 0, 0, 60, 17);

				// Initialize based on template
				if (template_checkbox)
					iiSubobj_copyCheckbox(checkboxNew, template_checkbox);		// Copy from indicated template
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
		SObject*	optionNew;
		SVariable*	var;


		logfunc(__FUNCTION__);
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

				// Initialize properties to VJr defaults
				optionNew->objType		= _OBJ_TYPE_OPTION;
				optionNew->parent		= parent;
				iiSubobj_resetToDefaultOption(optionNew, true, true, &gsProps_option[0], gnProps_optionSize);

				// Initially populate
				setEnabled(optionNew, _LOGICAL_TRUE);
				optionNew->isRendered	= true;
				optionNew->isPublished	= true;
				var = iObjProp_get_variable_byIndex(optionNew, _INDEX_NAME);			iDatum_duplicate(&var->value, cgcName_option, -1);
				var = iObjProp_get_variable_byIndex(optionNew, _INDEX_NAME);			iDatum_duplicate(&var->value, cgcName_option, -1);
				iEvents_resetToDefault(&optionNew->ev);
				iObj_setSize(optionNew, 0, 0, 60, 40);

				// Initialize based on template
				if (template_option)
					iiSubobj_copyOption(optionNew, template_option);		// Copy from indicated template
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
		SObject*	radioNew;
		SVariable*	var;


		logfunc(__FUNCTION__);
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

				// Initialize properties to VJr defaults
				radioNew->objType		= _OBJ_TYPE_RADIO;
				radioNew->parent		= parent;
				iiSubobj_resetToDefaultRadio(radioNew, true, true, &gsProps_radio[0], gnProps_radioSize);

				// Initially populate
				setEnabled(radioNew, _LOGICAL_TRUE);
				radioNew->isRendered	= true;
				radioNew->isPublished	= true;
				var = iObjProp_get_variable_byIndex(radioNew, _INDEX_NAME);			iDatum_duplicate(&var->value, cgcName_radio, -1);
				var = iObjProp_get_variable_byIndex(radioNew, _INDEX_CLASS);		iDatum_duplicate(&var->value, cgcName_radio, -1);
				iEvents_resetToDefault(&radioNew->ev);
				iObj_setSize(radioNew, 0, 0, 100, 100);

				// Initialize based on template
				if (template_radio)
					iiSubobj_copyRadio(radioNew, template_radio);		// Copy from indicated template
			}


		//////////
		// Indicate our success or failure
		//////
			return(radioNew);
	}




//////////
//
// Creates the cmdGroup structure
//
//////
	SObject* iSubobj_createCmdGroup(SObject* template_cmdGroup, SObject* parent)
	{
		SObject*	cmdGroupNew;
		SVariable*	var;


		logfunc(__FUNCTION__);
		//////////
		// Create the indicated item
		//////
			cmdGroupNew = (SObject*)malloc(sizeof(SObject));


		//////////
		// If successful, initialize it
		//////
			if (cmdGroupNew)
			{
				// Initialize
				memset(cmdGroupNew, 0, sizeof(SObject));

				// Initialize properties to VJr defaults
				cmdGroupNew->objType	= _OBJ_TYPE_CMDGROUP;
				cmdGroupNew->parent		= parent;
				iiSubobj_resetToDefaultCmdGroup(cmdGroupNew, true, true, &gsProps_cmdgroup[0], gnProps_cmdgroupSize);

				// Initially populate
				setEnabled(cmdGroupNew, _LOGICAL_TRUE);
				cmdGroupNew->isRendered		= true;
				cmdGroupNew->isPublished	= true;
				var = iObjProp_get_variable_byIndex(cmdGroupNew, _INDEX_NAME);			iDatum_duplicate(&var->value, cgcName_cmdgroup, -1);
				var = iObjProp_get_variable_byIndex(cmdGroupNew, _INDEX_CLASS);			iDatum_duplicate(&var->value, cgcName_cmdgroup, -1);
				iEvents_resetToDefault(&cmdGroupNew->ev);
				iObj_setSize(cmdGroupNew, 0, 0, 100, 100);

				// Initialize based on template
				if (template_cmdGroup)
					iiSubobj_copyCmdGroup(cmdGroupNew, template_cmdGroup);		// Copy from indicated template
			}


		//////////
		// Indicate our success or failure
		//////
			return(cmdGroupNew);
	}




//////////
//
// Creates the optGroup structure
//
//////
	SObject* iSubobj_createOptGroup(SObject* template_optGroup, SObject* parent)
	{
		SObject*	optGroupNew;
		SVariable*	var;


		logfunc(__FUNCTION__);
		//////////
		// Create the indicated item
		//////
			optGroupNew = (SObject*)malloc(sizeof(SObject));


		//////////
		// If successful, initialize it
		//////
			if (optGroupNew)
			{
				// Initialize
				memset(optGroupNew, 0, sizeof(SObject));

				// Initialize properties to VJr defaults
				optGroupNew->objType	= _OBJ_TYPE_OPTGROUP;
				optGroupNew->parent		= parent;
				iiSubobj_resetToDefaultOptGroup(optGroupNew, true, true, &gsProps_optgroup[0], gnProps_optgroupSize);

				// Initially populate
				setEnabled(optGroupNew, _LOGICAL_TRUE);
				optGroupNew->isRendered		= true;
				optGroupNew->isPublished	= true;
				var = iObjProp_get_variable_byIndex(optGroupNew, _INDEX_NAME);			iDatum_duplicate(&var->value, cgcName_optgroup, -1);
				var = iObjProp_get_variable_byIndex(optGroupNew, _INDEX_CLASS);			iDatum_duplicate(&var->value, cgcName_optgroup, -1);
				iEvents_resetToDefault(&optGroupNew->ev);
				iObj_setSize(optGroupNew, 0, 0, 100, 100);

				// Initialize based on template
				if (template_optGroup)
					iiSubobj_copyOptGroup(optGroupNew, template_optGroup);		// Copy from indicated template
			}


		//////////
		// Indicate our success or failure
		//////
			return(optGroupNew);
	}




//////////
//
// Creates the listbox structure
//
//////
	SObject* iSubobj_createListbox(SObject* template_listbox, SObject* parent)
	{
		SObject*	listboxNew;
		SVariable*	var;


		logfunc(__FUNCTION__);
		//////////
		// Create the indicated item
		//////
			listboxNew = (SObject*)malloc(sizeof(SObject));


		//////////
		// If successful, initialize it
		//////
			if (listboxNew)
			{
				// Initialize
				memset(listboxNew, 0, sizeof(SObject));

				// Initialize properties to VJr defaults
				listboxNew->objType	= _OBJ_TYPE_LISTBOX;
				listboxNew->parent		= parent;
				iiSubobj_resetToDefaultListbox(listboxNew, true, true, &gsProps_listbox[0], gnProps_listboxSize);

				// Initially populate
				setEnabled(listboxNew, _LOGICAL_TRUE);
				listboxNew->isRendered		= true;
				listboxNew->isPublished		= true;
				var = iObjProp_get_variable_byIndex(listboxNew, _INDEX_NAME);			iDatum_duplicate(&var->value, cgcName_listbox, -1);
				var = iObjProp_get_variable_byIndex(listboxNew, _INDEX_CLASS);			iDatum_duplicate(&var->value, cgcName_listbox, -1);
				iEvents_resetToDefault(&listboxNew->ev);
				iObj_setSize(listboxNew, 0, 0, 100, 100);

				// Initialize based on template
				if (template_listbox)
					iiSubobj_copyListbox(listboxNew, template_listbox);		// Copy from indicated template
			}


		//////////
		// Indicate our success or failure
		//////
			return(listboxNew);
	}




//////////
//
// Creates the combobox structure
//
//////
	SObject* iSubobj_createCombobox(SObject* template_combobox, SObject* parent)
	{
		SObject*	comboboxNew;
		SVariable*	var;


		logfunc(__FUNCTION__);
		//////////
		// Create the indicated item
		//////
			comboboxNew = (SObject*)malloc(sizeof(SObject));


		//////////
		// If successful, initialize it
		//////
			if (comboboxNew)
			{
				// Initialize
				memset(comboboxNew, 0, sizeof(SObject));

				// Initialize properties to VJr defaults
				comboboxNew->objType	= _OBJ_TYPE_COMBOBOX;
				comboboxNew->parent		= parent;
				iiSubobj_resetToDefaultCombobox(comboboxNew, true, true, &gsProps_combobox[0], gnProps_comboboxSize);

				// Initially populate
				setEnabled(comboboxNew, _LOGICAL_TRUE);
				comboboxNew->isRendered		= true;
				comboboxNew->isPublished	= true;
				var = iObjProp_get_variable_byIndex(comboboxNew, _INDEX_NAME);			iDatum_duplicate(&var->value, cgcName_combobox, -1);
				var = iObjProp_get_variable_byIndex(comboboxNew, _INDEX_CLASS);			iDatum_duplicate(&var->value, cgcName_combobox, -1);
				iEvents_resetToDefault(&comboboxNew->ev);
				iObj_setSize(comboboxNew, 0, 0, 100, 100);

				// Initialize based on template
				if (template_combobox)
					iiSubobj_copyCombobox(comboboxNew, template_combobox);		// Copy from indicated template
			}


		//////////
		// Indicate our success or failure
		//////
			return(comboboxNew);
	}




//////////
//
// Creates the formset structure
//
//////
	SObject* iSubobj_createFormset(SObject* template_formset, SObject* parent)
	{
		SObject*	formsetNew;
		SVariable*	var;


		logfunc(__FUNCTION__);
		//////////
		// Create the indicated item
		//////
			formsetNew = (SObject*)malloc(sizeof(SObject));


		//////////
		// If successful, initialize it
		//////
			if (formsetNew)
			{
				// Initialize
				memset(formsetNew, 0, sizeof(SObject));

				// Initialize properties to VJr defaults
				formsetNew->objType	= _OBJ_TYPE_FORMSET;
				formsetNew->parent		= parent;
				iiSubobj_resetToDefaultFormset(formsetNew, true, true, &gsProps_formset[0], gnProps_formsetSize);

				// Initially populate
				setEnabled(formsetNew, _LOGICAL_TRUE);
				formsetNew->isRendered		= true;
				formsetNew->isPublished		= true;
				var = iObjProp_get_variable_byIndex(formsetNew, _INDEX_NAME);			iDatum_duplicate(&var->value, cgcName_formset, -1);
				var = iObjProp_get_variable_byIndex(formsetNew, _INDEX_CLASS);			iDatum_duplicate(&var->value, cgcName_formset, -1);
				iEvents_resetToDefault(&formsetNew->ev);
				iObj_setSize(formsetNew, 0, 0, 100, 100);

				// Initialize based on template
				if (template_formset)
					iiSubobj_copyFormset(formsetNew, template_formset);		// Copy from indicated template
			}


		//////////
		// Indicate our success or failure
		//////
			return(formsetNew);
	}




//////////
//
// Creates the toolbar structure
//
//////
	SObject* iSubobj_createToolbar(SObject* template_toolbar, SObject* parent)
	{
		SObject*	toolbarNew;
		SVariable*	var;


		logfunc(__FUNCTION__);
		//////////
		// Create the indicated item
		//////
			toolbarNew = (SObject*)malloc(sizeof(SObject));


		//////////
		// If successful, initialize it
		//////
			if (toolbarNew)
			{
				// Initialize
				memset(toolbarNew, 0, sizeof(SObject));

				// Initialize properties to VJr defaults
				toolbarNew->objType		= _OBJ_TYPE_TOOLBAR;
				toolbarNew->parent		= parent;
				iiSubobj_resetToDefaultToolbar(toolbarNew, true, true, &gsProps_toolbar[0], gnProps_toolbarSize);

				// Initially populate
				setEnabled(toolbarNew, _LOGICAL_TRUE);
				toolbarNew->isRendered		= true;
				toolbarNew->isPublished		= true;
				var = iObjProp_get_variable_byIndex(toolbarNew, _INDEX_NAME);			iDatum_duplicate(&var->value, cgcName_toolbar, -1);
				var = iObjProp_get_variable_byIndex(toolbarNew, _INDEX_CLASS);			iDatum_duplicate(&var->value, cgcName_toolbar, -1);
				iEvents_resetToDefault(&toolbarNew->ev);
				iObj_setSize(toolbarNew, 0, 0, 100, 100);

				// Initialize based on template
				if (template_toolbar)
					iiSubobj_copyToolbar(toolbarNew, template_toolbar);		// Copy from indicated template
			}


		//////////
		// Indicate our success or failure
		//////
			return(toolbarNew);
	}




//////////
//
// Creates the separator structure
//
//////
	SObject* iSubobj_createSeparator(SObject* template_separator, SObject* parent)
	{
		SObject*	separatorNew;
		SVariable*	var;


		logfunc(__FUNCTION__);
		//////////
		// Create the indicated item
		//////
			separatorNew = (SObject*)malloc(sizeof(SObject));


		//////////
		// If successful, initialize it
		//////
			if (separatorNew)
			{
				// Initialize
				memset(separatorNew, 0, sizeof(SObject));

				// Initialize properties to VJr defaults
				separatorNew->objType	= _OBJ_TYPE_SEPARATOR;
				separatorNew->parent	= parent;
				iiSubobj_resetToDefaultSeparator(separatorNew, true, true, &gsProps_separator[0], gnProps_separatorSize);

				// Initially populate
				setEnabled(separatorNew, _LOGICAL_TRUE);
				separatorNew->isRendered	= true;
				separatorNew->isPublished	= true;
				var = iObjProp_get_variable_byIndex(separatorNew, _INDEX_NAME);			iDatum_duplicate(&var->value, cgcName_separator, -1);
				var = iObjProp_get_variable_byIndex(separatorNew, _INDEX_CLASS);		iDatum_duplicate(&var->value, cgcName_separator, -1);
				iEvents_resetToDefault(&separatorNew->ev);
				iObj_setSize(separatorNew, 0, 0, 100, 100);

				// Initialize based on template
				if (template_separator)
					iiSubobj_copySeparator(separatorNew, template_separator);		// Copy from indicated template
			}


		//////////
		// Indicate our success or failure
		//////
			return(separatorNew);
	}




//////////
//
// Creates the line structure
//
//////
	SObject* iSubobj_createLine(SObject* template_line, SObject* parent)
	{
		SObject*	lineNew;
		SVariable*	var;


		logfunc(__FUNCTION__);
		//////////
		// Create the indicated item
		//////
			lineNew = (SObject*)malloc(sizeof(SObject));


		//////////
		// If successful, initialize it
		//////
			if (lineNew)
			{
				// Initialize
				memset(lineNew, 0, sizeof(SObject));

				// Initialize properties to VJr defaults
				lineNew->objType	= _OBJ_TYPE_LINE;
				lineNew->parent		= parent;
				iiSubobj_resetToDefaultLine(lineNew, true, true, &gsProps_line[0], gnProps_lineSize);

				// Initially populate
				setEnabled(lineNew, _LOGICAL_TRUE);
				lineNew->isRendered		= true;
				lineNew->isPublished	= true;
				var = iObjProp_get_variable_byIndex(lineNew, _INDEX_NAME);			iDatum_duplicate(&var->value, cgcName_line, -1);
				var = iObjProp_get_variable_byIndex(lineNew, _INDEX_CLASS);			iDatum_duplicate(&var->value, cgcName_line, -1);
				iEvents_resetToDefault(&lineNew->ev);
				iObj_setSize(lineNew, 0, 0, 100, 100);

				// Initialize based on template
				if (template_line)
					iiSubobj_copyLine(lineNew, template_line);		// Copy from indicated template
			}


		//////////
		// Indicate our success or failure
		//////
			return(lineNew);
	}




//////////
//
// Creates the shape structure
//
//////
	SObject* iSubobj_createShape(SObject* template_shape, SObject* parent)
	{
		SObject*	shapeNew;
		SVariable*	var;


		logfunc(__FUNCTION__);
		//////////
		// Create the indicated item
		//////
			shapeNew = (SObject*)malloc(sizeof(SObject));


		//////////
		// If successful, initialize it
		//////
			if (shapeNew)
			{
				// Initialize
				memset(shapeNew, 0, sizeof(SObject));

				// Initialize properties to VJr defaults
				shapeNew->objType	= _OBJ_TYPE_SHAPE;
				shapeNew->parent	= parent;
				iiSubobj_resetToDefaultShape(shapeNew, true, true, &gsProps_shape[0], gnProps_shapeSize);

				// Initially populate
				setEnabled(shapeNew, _LOGICAL_TRUE);
				shapeNew->isRendered	= true;
				shapeNew->isPublished	= true;
				var = iObjProp_get_variable_byIndex(shapeNew, _INDEX_NAME);			iDatum_duplicate(&var->value, cgcName_shape, -1);
				var = iObjProp_get_variable_byIndex(shapeNew, _INDEX_CLASS);		iDatum_duplicate(&var->value, cgcName_shape, -1);
				iEvents_resetToDefault(&shapeNew->ev);
				iObj_setSize(shapeNew, 0, 0, 100, 100);

				// Initialize based on template
				if (template_shape)
					iiSubobj_copyShape(shapeNew, template_shape);		// Copy from indicated template
			}


		//////////
		// Indicate our success or failure
		//////
			return(shapeNew);
	}




//////////
//
// Creates the container structure
//
//////
	SObject* iSubobj_createContainer(SObject* template_container, SObject* parent)
	{
		SObject*	containerNew;
		SVariable*	var;


		logfunc(__FUNCTION__);
		//////////
		// Create the indicated item
		//////
			containerNew = (SObject*)malloc(sizeof(SObject));


		//////////
		// If successful, initialize it
		//////
			if (containerNew)
			{
				// Initialize
				memset(containerNew, 0, sizeof(SObject));

				// Initialize properties to VJr defaults
				containerNew->objType	= _OBJ_TYPE_CONTAINER;
				containerNew->parent	= parent;
				iiSubobj_resetToDefaultContainer(containerNew, true, true, &gsProps_container[0], gnProps_containerSize);

				// Initially populate
				setEnabled(containerNew, _LOGICAL_TRUE);
				containerNew->isRendered	= true;
				containerNew->isPublished	= true;
				var = iObjProp_get_variable_byIndex(containerNew, _INDEX_NAME);			iDatum_duplicate(&var->value, cgcName_container, -1);
				var = iObjProp_get_variable_byIndex(containerNew, _INDEX_CLASS);		iDatum_duplicate(&var->value, cgcName_container, -1);
				iEvents_resetToDefault(&containerNew->ev);
				iObj_setSize(containerNew, 0, 0, 100, 100);

				// Initialize based on template
				if (template_container)
					iiSubobj_copyContainer(containerNew, template_container);		// Copy from indicated template
			}


		//////////
		// Indicate our success or failure
		//////
			return(containerNew);
	}




//////////
//
// Creates the control structure
//
//////
	SObject* iSubobj_createControl(SObject* template_control, SObject* parent)
	{
		SObject*	controlNew;
		SVariable*	var;


		logfunc(__FUNCTION__);
		//////////
		// Create the indicated item
		//////
			controlNew = (SObject*)malloc(sizeof(SObject));


		//////////
		// If successful, initialize it
		//////
			if (controlNew)
			{
				// Initialize
				memset(controlNew, 0, sizeof(SObject));

				// Initialize properties to VJr defaults
				controlNew->objType		= _OBJ_TYPE_CONTROL;
				controlNew->parent		= parent;
				iiSubobj_resetToDefaultControl(controlNew, true, true, &gsProps_control[0], gnProps_controlSize);

				// Initially populate
				setEnabled(controlNew, _LOGICAL_TRUE);
				controlNew->isRendered		= true;
				controlNew->isPublished		= true;
				var = iObjProp_get_variable_byIndex(controlNew, _INDEX_NAME);			iDatum_duplicate(&var->value, cgcName_control, -1);
				var = iObjProp_get_variable_byIndex(controlNew, _INDEX_CLASS);			iDatum_duplicate(&var->value, cgcName_control, -1);
				iEvents_resetToDefault(&controlNew->ev);
				iObj_setSize(controlNew, 0, 0, 100, 100);

				// Initialize based on template
				if (template_control)
					iiSubobj_copyControl(controlNew, template_control);		// Copy from indicated template
			}


		//////////
		// Indicate our success or failure
		//////
			return(controlNew);
	}




//////////
//
// Creates the grid structure
//
//////
	SObject* iSubobj_createGrid(SObject* template_grid, SObject* parent)
	{
		SObject*	gridNew;
		SVariable*	var;


		logfunc(__FUNCTION__);
		//////////
		// Create the indicated item
		//////
			gridNew = (SObject*)malloc(sizeof(SObject));


		//////////
		// If successful, initialize it
		//////
			if (gridNew)
			{
				// Initialize
				memset(gridNew, 0, sizeof(SObject));

				// Initialize properties to VJr defaults
				gridNew->objType	= _OBJ_TYPE_GRID;
				gridNew->parent		= parent;
				iiSubobj_resetToDefaultGrid(gridNew, true, true, &gsProps_grid[0], gnProps_gridSize);

				// Initially populate
				setEnabled(gridNew, _LOGICAL_TRUE);
				gridNew->isRendered		= true;
				gridNew->isPublished	= true;
				var = iObjProp_get_variable_byIndex(gridNew, _INDEX_NAME);			iDatum_duplicate(&var->value, cgcName_grid, -1);
				var = iObjProp_get_variable_byIndex(gridNew, _INDEX_CLASS);			iDatum_duplicate(&var->value, cgcName_grid, -1);
				iEvents_resetToDefault(&gridNew->ev);
				iObj_setSize(gridNew, 0, 0, 100, 100);

				// Initialize based on template
				if (template_grid)
					iiSubobj_copyGrid(gridNew, template_grid);		// Copy from indicated template
			}


		//////////
		// Indicate our success or failure
		//////
			return(gridNew);
	}




//////////
//
// Creates the column structure
//
//////
	SObject* iSubobj_createColumn(SObject* template_column, SObject* parent)
	{
		SObject*	columnNew;
		SVariable*	var;


		logfunc(__FUNCTION__);
		//////////
		// Create the indicated item
		//////
			columnNew = (SObject*)malloc(sizeof(SObject));


		//////////
		// If successful, initialize it
		//////
			if (columnNew)
			{
				// Initialize
				memset(columnNew, 0, sizeof(SObject));

				// Initialize properties to VJr defaults
				columnNew->objType	= _OBJ_TYPE_COLUMN;
				columnNew->parent	= parent;
				iiSubobj_resetToDefaultColumn(columnNew, true, true, &gsProps_column[0], gnProps_columnSize);

				// Initially populate
				setEnabled(columnNew, _LOGICAL_TRUE);
				columnNew->isRendered	= true;
				columnNew->isPublished	= true;
				var = iObjProp_get_variable_byIndex(columnNew, _INDEX_NAME);			iDatum_duplicate(&var->value, cgcName_column, -1);
				var = iObjProp_get_variable_byIndex(columnNew, _INDEX_CLASS);			iDatum_duplicate(&var->value, cgcName_column, -1);
				iEvents_resetToDefault(&columnNew->ev);
				iObj_setSize(columnNew, 0, 0, 100, 100);

				// Initialize based on template
				if (template_column)
					iiSubobj_copyColumn(columnNew, template_column);		// Copy from indicated template
			}


		//////////
		// Indicate our success or failure
		//////
			return(columnNew);
	}




//////////
//
// Creates the header structure
//
//////
	SObject* iSubobj_createHeader(SObject* template_header, SObject* parent)
	{
		SObject*	headerNew;
		SVariable*	var;


		logfunc(__FUNCTION__);
		//////////
		// Create the indicated item
		//////
			headerNew = (SObject*)malloc(sizeof(SObject));


		//////////
		// If successful, initialize it
		//////
			if (headerNew)
			{
				// Initialize
				memset(headerNew, 0, sizeof(SObject));

				// Initialize properties to VJr defaults
				headerNew->objType	= _OBJ_TYPE_HEADER;
				headerNew->parent	= parent;
				iiSubobj_resetToDefaultHeader(headerNew, true, true, &gsProps_header[0], gnProps_headerSize);

				// Initially populate
				setEnabled(headerNew, _LOGICAL_TRUE);
				headerNew->isRendered	= true;
				headerNew->isPublished	= true;
				var = iObjProp_get_variable_byIndex(headerNew, _INDEX_NAME);			iDatum_duplicate(&var->value, cgcName_header, -1);
				var = iObjProp_get_variable_byIndex(headerNew, _INDEX_CLASS);			iDatum_duplicate(&var->value, cgcName_header, -1);
				iEvents_resetToDefault(&headerNew->ev);
				iObj_setSize(headerNew, 0, 0, 100, 100);

				// Initialize based on template
				if (template_header)
					iiSubobj_copyHeader(headerNew, template_header);		// Copy from indicated template
			}


		//////////
		// Indicate our success or failure
		//////
			return(headerNew);
	}




//////////
//
// Creates the olebound structure
//
//////
	SObject* iSubobj_createOleBound(SObject* template_oleBound, SObject* parent)
	{
		SObject*	oleBoundNew;
		SVariable*	var;


		logfunc(__FUNCTION__);
		//////////
		// Create the indicated item
		//////
			oleBoundNew = (SObject*)malloc(sizeof(SObject));


		//////////
		// If successful, initialize it
		//////
			if (oleBoundNew)
			{
				// Initialize
				memset(oleBoundNew, 0, sizeof(SObject));

				// Initialize properties to VJr defaults
				oleBoundNew->objType	= _OBJ_TYPE_OLEBOUND;
				oleBoundNew->parent		= parent;
				iiSubobj_resetToDefaultOleBound(oleBoundNew, true, true, &gsProps_olebound[0], gnProps_oleboundSize);

				// Initially populate
				setEnabled(oleBoundNew, _LOGICAL_TRUE);
				oleBoundNew->isRendered		= true;
				oleBoundNew->isPublished	= true;
				var = iObjProp_get_variable_byIndex(oleBoundNew, _INDEX_NAME);			iDatum_duplicate(&var->value, cgcName_olebound, -1);
				var = iObjProp_get_variable_byIndex(oleBoundNew, _INDEX_CLASS);			iDatum_duplicate(&var->value, cgcName_olebound, -1);
				iEvents_resetToDefault(&oleBoundNew->ev);
				iObj_setSize(oleBoundNew, 0, 0, 100, 100);

				// Initialize based on template
				if (template_oleBound)
					iiSubobj_copyOleBound(oleBoundNew, template_oleBound);		// Copy from indicated template
			}


		//////////
		// Indicate our success or failure
		//////
			return(oleBoundNew);
	}




//////////
//
// Creates the contain structure
//
//////
	SObject* iSubobj_createOleContain(SObject* template_oleContain, SObject* parent)
	{
		SObject*	oleContainNew;
		SVariable*	var;


		logfunc(__FUNCTION__);
		//////////
		// Create the indicated item
		//////
			oleContainNew = (SObject*)malloc(sizeof(SObject));


		//////////
		// If successful, initialize it
		//////
			if (oleContainNew)
			{
				// Initialize
				memset(oleContainNew, 0, sizeof(SObject));

				// Initialize properties to VJr defaults
				oleContainNew->objType	= _OBJ_TYPE_CONTAINER;
				oleContainNew->parent	= parent;
				iiSubobj_resetToDefaultContainer(oleContainNew, true, true, &gsProps_olecontain[0], gnProps_olecontainSize);

				// Initially populate
				setEnabled(oleContainNew, _LOGICAL_TRUE);
				oleContainNew->isRendered	= true;
				oleContainNew->isPublished	= true;
				var = iObjProp_get_variable_byIndex(oleContainNew, _INDEX_NAME);			iDatum_duplicate(&var->value, cgcName_olecontain, -1);
				var = iObjProp_get_variable_byIndex(oleContainNew, _INDEX_CLASS);			iDatum_duplicate(&var->value, cgcName_olecontain, -1);
				iEvents_resetToDefault(&oleContainNew->ev);
				iObj_setSize(oleContainNew, 0, 0, 100, 100);

				// Initialize based on template
				if (template_oleContain)
					iiSubobj_copyContainer(oleContainNew, template_oleContain);		// Copy from indicated template
			}


		//////////
		// Indicate our success or failure
		//////
			return(oleContainNew);
	}




//////////
//
// Creates the spinner structure
//
//////
	SObject* iSubobj_createSpinner(SObject* template_spinner, SObject* parent)
	{
		SObject*	spinnerNew;
		SVariable*	var;


		logfunc(__FUNCTION__);
		//////////
		// Create the indicated item
		//////
			spinnerNew = (SObject*)malloc(sizeof(SObject));


		//////////
		// If successful, initialize it
		//////
			if (spinnerNew)
			{
				// Initialize
				memset(spinnerNew, 0, sizeof(SObject));

				// Initialize properties to VJr defaults
				spinnerNew->objType		= _OBJ_TYPE_SPINNER;
				spinnerNew->parent		= parent;
				iiSubobj_resetToDefaultSpinner(spinnerNew, true, true, &gsProps_spinner[0], gnProps_spinnerSize);

				// Initially populate
				setEnabled(spinnerNew, _LOGICAL_TRUE);
				spinnerNew->isRendered		= true;
				spinnerNew->isPublished		= true;
				var = iObjProp_get_variable_byIndex(spinnerNew, _INDEX_NAME);			iDatum_duplicate(&var->value, cgcName_spinner, -1);
				var = iObjProp_get_variable_byIndex(spinnerNew, _INDEX_CLASS);			iDatum_duplicate(&var->value, cgcName_spinner, -1);
				iEvents_resetToDefault(&spinnerNew->ev);
				iObj_setSize(spinnerNew, 0, 0, 100, 100);

				// Initialize based on template
				if (template_spinner)
					iiSubobj_copySpinner(spinnerNew, template_spinner);		// Copy from indicated template
			}


		//////////
		// Indicate our success or failure
		//////
			return(spinnerNew);
	}




//////////
//
// Creates the timer structure
//
//////
	SObject* iSubobj_createTimer(SObject* template_timer, SObject* parent)
	{
		SObject*	timerNew;
		SVariable*	var;


		logfunc(__FUNCTION__);
		//////////
		// Create the indicated item
		//////
			timerNew = (SObject*)malloc(sizeof(SObject));


		//////////
		// If successful, initialize it
		//////
			if (timerNew)
			{
				// Initialize
				memset(timerNew, 0, sizeof(SObject));

				// Initialize properties to VJr defaults
				timerNew->objType	= _OBJ_TYPE_TIMER;
				timerNew->parent	= parent;
				iiSubobj_resetToDefaultTimer(timerNew, true, true, &gsProps_timer[0], gnProps_timerSize);

				// Initially populate
				setEnabled(timerNew, _LOGICAL_TRUE);
				timerNew->isRendered	= true;
				timerNew->isPublished	= true;
				var = iObjProp_get_variable_byIndex(timerNew, _INDEX_NAME);			iDatum_duplicate(&var->value, cgcName_timer, -1);
				var = iObjProp_get_variable_byIndex(timerNew, _INDEX_CLASS);		iDatum_duplicate(&var->value, cgcName_timer, -1);
				iEvents_resetToDefault(&timerNew->ev);
				iObj_setSize(timerNew, 0, 0, 100, 100);

				// Initialize based on template
				if (template_timer)
					iiSubobj_copyTimer(timerNew, template_timer);		// Copy from indicated template
			}


		//////////
		// Indicate our success or failure
		//////
			return(timerNew);
	}




//////////
//
// Creates the hyperlink structure
//
//////
	SObject* iSubobj_createHyperlink(SObject* template_hyperlink, SObject* parent)
	{
		SObject*	hyperlinkNew;
		SVariable*	var;


		logfunc(__FUNCTION__);
		//////////
		// Create the indicated item
		//////
			hyperlinkNew = (SObject*)malloc(sizeof(SObject));


		//////////
		// If successful, initialize it
		//////
			if (hyperlinkNew)
			{
				// Initialize
				memset(hyperlinkNew, 0, sizeof(SObject));

				// Initialize properties to VJr defaults
				hyperlinkNew->objType	= _OBJ_TYPE_HYPERLINK;
				hyperlinkNew->parent	= parent;
				iiSubobj_resetToDefaultHyperlink(hyperlinkNew, true, true, &gsProps_hyperlink[0], gnProps_hyperlinkSize);

				// Initially populate
				setEnabled(hyperlinkNew, _LOGICAL_TRUE);
				hyperlinkNew->isRendered	= true;
				hyperlinkNew->isPublished	= true;
				var = iObjProp_get_variable_byIndex(hyperlinkNew, _INDEX_NAME);			iDatum_duplicate(&var->value, cgcName_hyperlink, -1);
				var = iObjProp_get_variable_byIndex(hyperlinkNew, _INDEX_CLASS);		iDatum_duplicate(&var->value, cgcName_hyperlink, -1);
				iEvents_resetToDefault(&hyperlinkNew->ev);
				iObj_setSize(hyperlinkNew, 0, 0, 100, 100);

				// Initialize based on template
				if (template_hyperlink)
					iiSubobj_copyHyperlink(hyperlinkNew, template_hyperlink);		// Copy from indicated template
			}


		//////////
		// Indicate our success or failure
		//////
			return(hyperlinkNew);
	}




//////////
//
// Creates the collection structure
//
//////
	SObject* iSubobj_createCollection(SObject* template_collection, SObject* parent)
	{
		SObject*	collectionNew;
		SVariable*	var;


		logfunc(__FUNCTION__);
		//////////
		// Create the indicated item
		//////
			collectionNew = (SObject*)malloc(sizeof(SObject));


		//////////
		// If successful, initialize it
		//////
			if (collectionNew)
			{
				// Initialize
				memset(collectionNew, 0, sizeof(SObject));

				// Initialize properties to VJr defaults
				collectionNew->objType	= _OBJ_TYPE_COLLECTION;
				collectionNew->parent	= parent;
				iiSubobj_resetToDefaultCollection(collectionNew, true, true, &gsProps_collection[0], gnProps_collectionSize);

				// Initially populate
				setEnabled(collectionNew, _LOGICAL_TRUE);
				collectionNew->isRendered		= true;
				collectionNew->isPublished		= true;
				var = iObjProp_get_variable_byIndex(collectionNew, _INDEX_NAME);			iDatum_duplicate(&var->value, cgcName_collection, -1);
				var = iObjProp_get_variable_byIndex(collectionNew, _INDEX_CLASS);			iDatum_duplicate(&var->value, cgcName_collection, -1);
				iEvents_resetToDefault(&collectionNew->ev);
				iObj_setSize(collectionNew, 0, 0, 100, 100);

				// Initialize based on template
				if (template_collection)
					iiSubobj_copyCollection(collectionNew, template_collection);		// Copy from indicated template
			}


		//////////
		// Indicate our success or failure
		//////
			return(collectionNew);
	}




//////////
//
// Creates the cmdGroup structure
//
//////
	SObject* iSubobj_createPage(SObject* template_page, SObject* parent)
	{
		SObject*	pageNew;
		SVariable*	var;


		logfunc(__FUNCTION__);
		//////////
		// Create the indicated item
		//////
			pageNew = (SObject*)malloc(sizeof(SObject));


		//////////
		// If successful, initialize it
		//////
			if (pageNew)
			{
				// Initialize
				memset(pageNew, 0, sizeof(SObject));

				// Initialize properties to VJr defaults
				pageNew->objType	= _OBJ_TYPE_PAGE;
				pageNew->parent		= parent;
				iiSubobj_resetToDefaultPage(pageNew, true, true, &gsProps_page[0], gnProps_pageSize);

				// Initially populate
				setEnabled(pageNew, _LOGICAL_TRUE);
				pageNew->isRendered		= true;
				pageNew->isPublished	= true;
				var = iObjProp_get_variable_byIndex(pageNew, _INDEX_NAME);			iDatum_duplicate(&var->value, cgcName_page, -1);
				var = iObjProp_get_variable_byIndex(pageNew, _INDEX_CLASS);			iDatum_duplicate(&var->value, cgcName_page, -1);
				iEvents_resetToDefault(&pageNew->ev);
				iObj_setSize(pageNew, 0, 0, 100, 100);

				// Initialize based on template
				if (template_page)
					iiSubobj_copyPage(pageNew, template_page);		// Copy from indicated template
			}


		//////////
		// Indicate our success or failure
		//////
			return(pageNew);
	}




//////////
//
// Creates the pageframe structure
//
//////
	SObject* iSubobj_createPageframe(SObject* template_pageframe, SObject* parent)
	{
		SObject*	pageframeNew;
		SVariable*	var;


		logfunc(__FUNCTION__);
		//////////
		// Create the indicated item
		//////
			pageframeNew = (SObject*)malloc(sizeof(SObject));


		//////////
		// If successful, initialize it
		//////
			if (pageframeNew)
			{
				// Initialize
				memset(pageframeNew, 0, sizeof(SObject));

				// Initialize properties to VJr defaults
				pageframeNew->objType	= _OBJ_TYPE_PAGEFRAME;
				pageframeNew->parent	= parent;
				iiSubobj_resetToDefaultPageframe(pageframeNew, true, true, &gsProps_pageframe[0], gnProps_pageframeSize);

				// Initially populate
				setEnabled(pageframeNew, _LOGICAL_TRUE);
				pageframeNew->isRendered	= true;
				pageframeNew->isPublished	= true;
				var = iObjProp_get_variable_byIndex(pageframeNew, _INDEX_NAME);			iDatum_duplicate(&var->value, cgcName_pageframe, -1);
				var = iObjProp_get_variable_byIndex(pageframeNew, _INDEX_CLASS);		iDatum_duplicate(&var->value, cgcName_pageframe, -1);
				iEvents_resetToDefault(&pageframeNew->ev);
				iObj_setSize(pageframeNew, 0, 0, 100, 100);

				// Initialize based on template
				if (template_pageframe)
					iiSubobj_copyPageframe(pageframeNew, template_pageframe);		// Copy from indicated template
			}


		//////////
		// Indicate our success or failure
		//////
			return(pageframeNew);
	}




//////////
//
// Creates the session structure
//
//////
	SObject* iSubobj_createSession(SObject* template_session, SObject* parent)
	{
		SObject*	sessionNew;
		SVariable*	var;


		logfunc(__FUNCTION__);
		//////////
		// Create the indicated item
		//////
			sessionNew = (SObject*)malloc(sizeof(SObject));


		//////////
		// If successful, initialize it
		//////
			if (sessionNew)
			{
				// Initialize
				memset(sessionNew, 0, sizeof(SObject));

				// Initialize properties to VJr defaults
				sessionNew->objType		= _OBJ_TYPE_SESSION;
				sessionNew->parent		= parent;
				iiSubobj_resetToDefaultSession(sessionNew, true, true, &gsProps_session[0], gnProps_sessionSize);

				// Initially populate
				setEnabled(sessionNew, _LOGICAL_TRUE);
				sessionNew->isRendered		= true;
				sessionNew->isPublished		= true;
				var = iObjProp_get_variable_byIndex(sessionNew, _INDEX_NAME);			iDatum_duplicate(&var->value, cgcName_session, -1);
				var = iObjProp_get_variable_byIndex(sessionNew, _INDEX_CLASS);			iDatum_duplicate(&var->value, cgcName_session, -1);
				iEvents_resetToDefault(&sessionNew->ev);
				iObj_setSize(sessionNew, 0, 0, 100, 100);

				// Initialize based on template
				if (template_session)
					iiSubobj_copySession(sessionNew, template_session);		// Copy from indicated template
			}


		//////////
		// Indicate our success or failure
		//////
			return(sessionNew);
	}




//////////
//
// Creates the custom structure
//
//////
	SObject* iSubobj_createCustom(SObject* template_custom, SObject* parent)
	{
		SObject*	customNew;
		SVariable*	var;


		logfunc(__FUNCTION__);
		//////////
		// Create the indicated item
		//////
			customNew = (SObject*)malloc(sizeof(SObject));


		//////////
		// If successful, initialize it
		//////
			if (customNew)
			{
				// Initialize
				memset(customNew, 0, sizeof(SObject));

				// Initialize properties to VJr defaults
				customNew->objType		= _OBJ_TYPE_CUSTOM;
				customNew->parent		= parent;
				iiSubobj_resetToDefaultCustom(customNew, true, true, &gsProps_custom[0], gnProps_customSize);

				// Initially populate
				setEnabled(customNew, _LOGICAL_TRUE);
				customNew->isRendered		= true;
				customNew->isPublished		= true;
				var = iObjProp_get_variable_byIndex(customNew, _INDEX_NAME);			iDatum_duplicate(&var->value, cgcName_custom, -1);
				var = iObjProp_get_variable_byIndex(customNew, _INDEX_CLASS);			iDatum_duplicate(&var->value, cgcName_custom, -1);
				iEvents_resetToDefault(&customNew->ev);
				iObj_setSize(customNew, 0, 0, 100, 100);

				// Initialize based on template
				if (template_custom)
					iiSubobj_copyCustom(customNew, template_custom);		// Copy from indicated template
			}


		//////////
		// Indicate our success or failure
		//////
			return(customNew);
	}




//////////
//
// Creates the exception structure
//
//////
	SObject* iSubobj_createException(SObject* template_exception, SObject* parent)
	{
		SObject*	exceptionNew;
		SVariable*	var;


		logfunc(__FUNCTION__);
		//////////
		// Create the indicated item
		//////
			exceptionNew = (SObject*)malloc(sizeof(SObject));


		//////////
		// If successful, initialize it
		//////
			if (exceptionNew)
			{
				// Initialize
				memset(exceptionNew, 0, sizeof(SObject));

				// Initialize properties to VJr defaults
				exceptionNew->objType		= _OBJ_TYPE_EXCEPTION;
				exceptionNew->parent		= parent;
				iiSubobj_resetToDefaultException(exceptionNew, true, true, &gsProps_exception[0], gnProps_exceptionSize);

				// Initially populate
				setEnabled(exceptionNew, _LOGICAL_TRUE);
				exceptionNew->isRendered		= true;
				exceptionNew->isPublished		= true;
				var = iObjProp_get_variable_byIndex(exceptionNew, _INDEX_NAME);			iDatum_duplicate(&var->value, cgcName_exception, -1);
				var = iObjProp_get_variable_byIndex(exceptionNew, _INDEX_CLASS);		iDatum_duplicate(&var->value, cgcName_exception, -1);
				iEvents_resetToDefault(&exceptionNew->ev);
				iObj_setSize(exceptionNew, 0, 0, 100, 100);

				// Initialize based on template
				if (template_exception)
					iiSubobj_copyException(exceptionNew, template_exception);		// Copy from indicated template
			}


		//////////
		// Indicate our success or failure
		//////
			return(exceptionNew);
	}




//////////
//
// Called to copy the indicated empty from source to destination
//
//////
	void iiSubobj_copyEmpty(SObject* emptyDst, SObject* emptySrc)
	{
		logfunc(__FUNCTION__);
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
		logfunc(__FUNCTION__);
		//////////
		// Copy all standard properties
		//////
			memcpy(&formDst->p, &formSrc->p, sizeof(formDst->p));


		//////////
		// Copy the allocatables
		//////
			formDst->p.font	= iFont_duplicate(formSrc->p.font);
			iObjProp_set_bitmap_direct(formDst, _INDEX_ICON, iObjProp_get_bitmap(formSrc, _INDEX_ICON));
			iObjProp_copy_byIndex(formDst, _INDEX_CAPTION, formSrc, _INDEX_CAPTION);


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
// Called to copy the indicated empty subform source to destination
//
//////
	void iiSubobj_copySubform(SObject* subformDst, SObject* subformSrc)
	{
		logfunc(__FUNCTION__);
		//////////
		// Copy all standard properties
		//////
			memcpy(&subformDst->p, &subformSrc->p, sizeof(subformDst->p));


		//////////
		// Copy the allocatables
		//////
			subformDst->p.font	= iFont_duplicate(subformSrc->p.font);
			iObjProp_set_bitmap_direct(subformDst, _INDEX_ICON, iObjProp_get_bitmap(subformSrc, _INDEX_ICON));
			iObjProp_copy_byIndex(subformDst, _INDEX_CAPTION, subformSrc, _INDEX_CAPTION);

			// Picture
			iObjProp_copy_byIndex(subformDst, _INDEX_PICTURE,			subformSrc, _INDEX_PICTURE);
			iObjProp_copy_byIndex(subformDst, _INDEX_PICTUREBMP,		subformSrc, _INDEX_PICTUREBMP);
			iObjProp_copy_byIndex(subformDst, _INDEX_PICTUREBMP_DOWN,	subformSrc, _INDEX_PICTUREBMP_DOWN);
			iObjProp_copy_byIndex(subformDst, _INDEX_PICTUREBMP_OVER,	subformSrc, _INDEX_PICTUREBMP_OVER);


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
// Called to copy the indicated carousel source to destination
//
//////
	void iiSubobj_copyCarousel(SObject* carouselDst, SObject* carouselSrc)
	{
		logfunc(__FUNCTION__);
		//////////
		// Copy all standard properties
		//////
			memcpy(&carouselDst->p, &carouselSrc->p, sizeof(carouselDst->p));


		//////////
		// Copy the form-specific event handlers
		//////
			memcpy(&carouselDst->ev, &carouselSrc->ev, sizeof(carouselDst->ev));


		//////////
		// Duplicate all children for this object
		//////
			iObj_duplicateChildren(carouselDst, carouselSrc);
	}




//////////
//
// Called to copy the indicated rider source to destination
//
//////
	void iiSubobj_copyRider(SObject* riderDst, SObject* riderSrc)
	{
		logfunc(__FUNCTION__);
		//////////
		// Copy all standard properties
		//////
			memcpy(&riderDst->p, &riderSrc->p, sizeof(riderDst->p));


		//////////
		// Copy the form-specific event handlers
		//////
			memcpy(&riderDst->ev, &riderSrc->ev, sizeof(riderDst->ev));


		//////////
		// Duplicate all children for this object
		//////
			iObj_duplicateChildren(riderDst, riderSrc);
	}




//////////
//
// Called to copy the indicated label from source to destination
//
//////
	void iiSubobj_copyLabel(SObject* labelDst, SObject* labelSrc)
	{
		logfunc(__FUNCTION__);
		//////////
		// Copy all standard properties
		//////
			memcpy(&labelDst->p, &labelSrc->p, sizeof(labelDst->p));


		//////////
		// Copy the allocatables
		//////
			labelDst->p.font = iFont_duplicate(labelSrc->p.font);

			// Caption
			iObjProp_copy_byIndex(labelDst, _INDEX_CAPTION, labelSrc, _INDEX_CAPTION);


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
		logfunc(__FUNCTION__);
		//////////
		// Copy all standard properties
		//////
			memcpy(&textboxDst->p, &textboxSrc->p, sizeof(textboxDst->p));


		//////////
		// Copy the allocatables
		//////
			textboxDst->p.font		= iFont_duplicate(textboxSrc->p.font);
			iObjProp_set_bitmap_direct(textboxDst, _INDEX_ICON, iObjProp_get_bitmap(textboxSrc, _INDEX_ICON));

			// Caption
			iObjProp_copy_byIndex(textboxDst, _INDEX_CAPTION,			textboxSrc, _INDEX_CAPTION);

			// Value
			iObjProp_copy_byIndex(textboxDst, _INDEX_VALUE,				textboxSrc, _INDEX_VALUE);
			iObjProp_copy_byIndex(textboxDst, _INDEX_PICTURE,			textboxSrc, _INDEX_PICTURE);
			iObjProp_copy_byIndex(textboxDst, _INDEX_PICTUREBMP,		textboxSrc, _INDEX_PICTUREBMP);
			iObjProp_copy_byIndex(textboxDst, _INDEX_PICTUREBMP_DOWN,	textboxSrc, _INDEX_PICTUREBMP_DOWN);
			iObjProp_copy_byIndex(textboxDst, _INDEX_PICTUREBMP_OVER,	textboxSrc, _INDEX_PICTUREBMP_OVER);
			iObjProp_copy_byIndex(textboxDst, _INDEX_MASK,				textboxSrc, _INDEX_MASK);
	

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
		logfunc(__FUNCTION__);
		//////////
		// Copy all standard properties
		//////
			memcpy(&buttonDst->p, &buttonSrc->p, sizeof(buttonDst->p));


		//////////
		// Copy the allocatables
		//////
			buttonDst->p.font		= iFont_duplicate(buttonSrc->p.font);

			// Caption
			iObjProp_copy_byIndex(buttonDst, _INDEX_CAPTION,			buttonSrc, _INDEX_CAPTION);

			// Picture
			iObjProp_copy_byIndex(buttonDst, _INDEX_PICTURE,			buttonSrc, _INDEX_PICTURE);
			iObjProp_copy_byIndex(buttonDst, _INDEX_PICTUREBMP,			buttonSrc, _INDEX_PICTUREBMP);
			iObjProp_copy_byIndex(buttonDst, _INDEX_PICTUREBMP_DOWN,	buttonSrc, _INDEX_PICTUREBMP_DOWN);
			iObjProp_copy_byIndex(buttonDst, _INDEX_PICTUREBMP_OVER,	buttonSrc, _INDEX_PICTUREBMP_OVER);


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
		logfunc(__FUNCTION__);
		//////////
		// Copy all standard properties
		//////
			memcpy(&editboxDst->p, &editboxSrc->p, sizeof(editboxDst->p));


		//////////
		// Copy the allocatables
		//////
			editboxDst->p.font	= iFont_duplicate(editboxSrc->p.font);
			iObjProp_copy_byIndex(editboxDst, _INDEX_ICON,				editboxSrc, _INDEX_ICON);

			// Caption
			iObjProp_copy_byIndex(editboxDst, _INDEX_CAPTION,			editboxSrc, _INDEX_CAPTION);

			// Value
			iObjProp_copy_byIndex(editboxDst, _INDEX_VALUE,				editboxSrc, _INDEX_VALUE);
			iObjProp_copy_byIndex(editboxDst, _INDEX_PICTURE,			editboxSrc, _INDEX_PICTURE);
			iObjProp_copy_byIndex(editboxDst, _INDEX_PICTUREBMP,		editboxSrc, _INDEX_PICTUREBMP);
			iObjProp_copy_byIndex(editboxDst, _INDEX_PICTUREBMP_DOWN,	editboxSrc, _INDEX_PICTUREBMP_DOWN);
			iObjProp_copy_byIndex(editboxDst, _INDEX_PICTUREBMP_OVER,	editboxSrc, _INDEX_PICTUREBMP_OVER);
			iObjProp_copy_byIndex(editboxDst, _INDEX_MASK,				editboxSrc, _INDEX_MASK);


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
		logfunc(__FUNCTION__);
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
		logfunc(__FUNCTION__);
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
		logfunc(__FUNCTION__);
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
		logfunc(__FUNCTION__);
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
// Called to copy the indicated cmdGroup from source to destination
//
//////
	void iiSubobj_copyCmdGroup(SObject* cmdGroupDst, SObject* cmdGroupSrc)
	{
		logfunc(__FUNCTION__);
		//////////
		// Copy all standard properties
		//////
			memcpy(&cmdGroupDst->p, &cmdGroupSrc->p, sizeof(cmdGroupDst->p));


		//////////
		// Copy the allocatables
		//////
			// remember


		//////////
		// Copy the form-specific event handlers
		//////
			memcpy(&cmdGroupDst->ev, &cmdGroupSrc->ev, sizeof(cmdGroupDst->ev));


		//////////
		// Duplicate all children for this object
		//////
			iObj_duplicateChildren(cmdGroupDst, cmdGroupSrc);
	}




//////////
//
// Called to copy the indicated optGroup from source to destination
//
//////
	void iiSubobj_copyOptGroup(SObject* optGroupDst, SObject* optGroupSrc)
	{
		logfunc(__FUNCTION__);
		//////////
		// Copy all standard properties
		//////
			memcpy(&optGroupDst->p, &optGroupSrc->p, sizeof(optGroupDst->p));


		//////////
		// Copy the allocatables
		//////
			// remember


		//////////
		// Copy the form-specific event handlers
		//////
			memcpy(&optGroupDst->ev, &optGroupSrc->ev, sizeof(optGroupDst->ev));


		//////////
		// Duplicate all children for this object
		//////
			iObj_duplicateChildren(optGroupDst, optGroupSrc);
	}




//////////
//
// Called to copy the indicated listbox from source to destination
//
//////
	void iiSubobj_copyListbox(SObject* listboxDst, SObject* listboxSrc)
	{
		logfunc(__FUNCTION__);
		//////////
		// Copy all standard properties
		//////
			memcpy(&listboxDst->p, &listboxSrc->p, sizeof(listboxDst->p));


		//////////
		// Copy the allocatables
		//////
			// remember


		//////////
		// Copy the form-specific event handlers
		//////
			memcpy(&listboxDst->ev, &listboxSrc->ev, sizeof(listboxDst->ev));


		//////////
		// Duplicate all children for this object
		//////
			iObj_duplicateChildren(listboxDst, listboxSrc);
	}




//////////
//
// Called to copy the indicated combobox from source to destination
//
//////
	void iiSubobj_copyCombobox(SObject* comboboxDst, SObject* comboboxSrc)
	{
		logfunc(__FUNCTION__);
		//////////
		// Copy all standard properties
		//////
			memcpy(&comboboxDst->p, &comboboxSrc->p, sizeof(comboboxDst->p));


		//////////
		// Copy the allocatables
		//////
			// remember


		//////////
		// Copy the form-specific event handlers
		//////
			memcpy(&comboboxDst->ev, &comboboxSrc->ev, sizeof(comboboxDst->ev));


		//////////
		// Duplicate all children for this object
		//////
			iObj_duplicateChildren(comboboxDst, comboboxSrc);
	}




//////////
//
// Called to copy the indicated formset from source to destination
//
//////
	void iiSubobj_copyFormset(SObject* formsetDst, SObject* formsetSrc)
	{
		logfunc(__FUNCTION__);
		//////////
		// Copy all standard properties
		//////
			memcpy(&formsetDst->p, &formsetSrc->p, sizeof(formsetDst->p));


		//////////
		// Copy the allocatables
		//////
			// remember


		//////////
		// Copy the form-specific event handlers
		//////
			memcpy(&formsetDst->ev, &formsetSrc->ev, sizeof(formsetDst->ev));


		//////////
		// Duplicate all children for this object
		//////
			iObj_duplicateChildren(formsetDst, formsetSrc);
	}




//////////
//
// Called to copy the indicated toolbar from source to destination
//
//////
	void iiSubobj_copyToolbar(SObject* toolbarDst, SObject* toolbarSrc)
	{
		logfunc(__FUNCTION__);
		//////////
		// Copy all standard properties
		//////
			memcpy(&toolbarDst->p, &toolbarSrc->p, sizeof(toolbarDst->p));


		//////////
		// Copy the allocatables
		//////
			// remember


		//////////
		// Copy the form-specific event handlers
		//////
			memcpy(&toolbarDst->ev, &toolbarSrc->ev, sizeof(toolbarDst->ev));


		//////////
		// Duplicate all children for this object
		//////
			iObj_duplicateChildren(toolbarDst, toolbarSrc);
	}




//////////
//
// Called to copy the indicated separator from source to destination
//
//////
	void iiSubobj_copySeparator(SObject* separatorDst, SObject* separatorSrc)
	{
		logfunc(__FUNCTION__);
		//////////
		// Copy all standard properties
		//////
			memcpy(&separatorDst->p, &separatorSrc->p, sizeof(separatorDst->p));


		//////////
		// Copy the allocatables
		//////
			// remember


		//////////
		// Copy the form-specific event handlers
		//////
			memcpy(&separatorDst->ev, &separatorSrc->ev, sizeof(separatorDst->ev));


		//////////
		// Duplicate all children for this object
		//////
			iObj_duplicateChildren(separatorDst, separatorSrc);
	}




//////////
//
// Called to copy the indicated line from source to destination
//
//////
	void iiSubobj_copyLine(SObject* lineDst, SObject* lineSrc)
	{
		logfunc(__FUNCTION__);
		//////////
		// Copy all standard properties
		//////
			memcpy(&lineDst->p, &lineSrc->p, sizeof(lineDst->p));


		//////////
		// Copy the allocatables
		//////
			// remember


		//////////
		// Copy the form-specific event handlers
		//////
			memcpy(&lineDst->ev, &lineSrc->ev, sizeof(lineDst->ev));


		//////////
		// Duplicate all children for this object
		//////
			iObj_duplicateChildren(lineDst, lineSrc);
	}




//////////
//
// Called to copy the indicated shape from source to destination
//
//////
	void iiSubobj_copyShape(SObject* shapeDst, SObject* shapeSrc)
	{
		logfunc(__FUNCTION__);
		//////////
		// Copy all standard properties
		//////
			memcpy(&shapeDst->p, &shapeSrc->p, sizeof(shapeDst->p));


		//////////
		// Copy the allocatables
		//////
			// remember


		//////////
		// Copy the form-specific event handlers
		//////
			memcpy(&shapeDst->ev, &shapeSrc->ev, sizeof(shapeDst->ev));


		//////////
		// Duplicate all children for this object
		//////
			iObj_duplicateChildren(shapeDst, shapeSrc);
	}




//////////
//
// Called to copy the indicated container from source to destination
//
//////
	void iiSubobj_copyContainer(SObject* containerDst, SObject* containerSrc)
	{
		logfunc(__FUNCTION__);
		//////////
		// Copy all standard properties
		//////
			memcpy(&containerDst->p, &containerSrc->p, sizeof(containerDst->p));


		//////////
		// Copy the allocatables
		//////
			// remember


		//////////
		// Copy the form-specific event handlers
		//////
			memcpy(&containerDst->ev, &containerSrc->ev, sizeof(containerDst->ev));


		//////////
		// Duplicate all children for this object
		//////
			iObj_duplicateChildren(containerDst, containerSrc);
	}




//////////
//
// Called to copy the indicated control from source to destination
//
//////
	void iiSubobj_copyControl(SObject* controlDst, SObject* controlSrc)
	{
		logfunc(__FUNCTION__);
		//////////
		// Copy all standard properties
		//////
			memcpy(&controlDst->p, &controlSrc->p, sizeof(controlDst->p));


		//////////
		// Copy the allocatables
		//////
			// remember


		//////////
		// Copy the form-specific event handlers
		//////
			memcpy(&controlDst->ev, &controlSrc->ev, sizeof(controlDst->ev));


		//////////
		// Duplicate all children for this object
		//////
			iObj_duplicateChildren(controlDst, controlSrc);
	}




//////////
//
// Called to copy the indicated grid from source to destination
//
//////
	void iiSubobj_copyGrid(SObject* gridDst, SObject* gridSrc)
	{
		logfunc(__FUNCTION__);
		//////////
		// Copy all standard properties
		//////
			memcpy(&gridDst->p, &gridSrc->p, sizeof(gridDst->p));


		//////////
		// Copy the allocatables
		//////
			// remember


		//////////
		// Copy the form-specific event handlers
		//////
			memcpy(&gridDst->ev, &gridSrc->ev, sizeof(gridDst->ev));


		//////////
		// Duplicate all children for this object
		//////
			iObj_duplicateChildren(gridDst, gridSrc);
	}




//////////
//
// Called to copy the indicated column from source to destination
//
//////
	void iiSubobj_copyColumn(SObject* columnDst, SObject* columnSrc)
	{
		logfunc(__FUNCTION__);
		//////////
		// Copy all standard properties
		//////
			memcpy(&columnDst->p, &columnSrc->p, sizeof(columnDst->p));


		//////////
		// Copy the allocatables
		//////
			// remember


		//////////
		// Copy the form-specific event handlers
		//////
			memcpy(&columnDst->ev, &columnSrc->ev, sizeof(columnDst->ev));


		//////////
		// Duplicate all children for this object
		//////
			iObj_duplicateChildren(columnDst, columnSrc);
	}




//////////
//
// Called to copy the indicated header from source to destination
//
//////
	void iiSubobj_copyHeader(SObject* headerDst, SObject* headerSrc)
	{
		logfunc(__FUNCTION__);
		//////////
		// Copy all standard properties
		//////
			memcpy(&headerDst->p, &headerSrc->p, sizeof(headerDst->p));


		//////////
		// Copy the allocatables
		//////
			// remember


		//////////
		// Copy the form-specific event handlers
		//////
			memcpy(&headerDst->ev, &headerSrc->ev, sizeof(headerDst->ev));


		//////////
		// Duplicate all children for this object
		//////
			iObj_duplicateChildren(headerDst, headerSrc);
	}




//////////
//
// Called to copy the indicated oleBound from source to destination
//
//////
	void iiSubobj_copyOleBound(SObject* oleBoundDst, SObject* oleBoundSrc)
	{
		logfunc(__FUNCTION__);
		//////////
		// Copy all standard properties
		//////
			memcpy(&oleBoundDst->p, &oleBoundSrc->p, sizeof(oleBoundDst->p));


		//////////
		// Copy the allocatables
		//////
			// remember


		//////////
		// Copy the form-specific event handlers
		//////
			memcpy(&oleBoundDst->ev, &oleBoundSrc->ev, sizeof(oleBoundDst->ev));


		//////////
		// Duplicate all children for this object
		//////
			iObj_duplicateChildren(oleBoundDst, oleBoundSrc);
	}




//////////
//
// Called to copy the indicated oleContain from source to destination
//
//////
	void iiSubobj_copyOleContain(SObject* oleContainDst, SObject* oleContainSrc)
	{
		logfunc(__FUNCTION__);
		//////////
		// Copy all standard properties
		//////
			memcpy(&oleContainDst->p, &oleContainSrc->p, sizeof(oleContainDst->p));


		//////////
		// Copy the allocatables
		//////
			// remember


		//////////
		// Copy the form-specific event handlers
		//////
			memcpy(&oleContainDst->ev, &oleContainSrc->ev, sizeof(oleContainDst->ev));


		//////////
		// Duplicate all children for this object
		//////
			iObj_duplicateChildren(oleContainDst, oleContainSrc);
	}




//////////
//
// Called to copy the indicated spinner from source to destination
//
//////
	void iiSubobj_copySpinner(SObject* spinnerDst, SObject* spinnerSrc)
	{
		logfunc(__FUNCTION__);
		//////////
		// Copy all standard properties
		//////
			memcpy(&spinnerDst->p, &spinnerSrc->p, sizeof(spinnerDst->p));


		//////////
		// Copy the allocatables
		//////
			// remember


		//////////
		// Copy the form-specific event handlers
		//////
			memcpy(&spinnerDst->ev, &spinnerSrc->ev, sizeof(spinnerDst->ev));


		//////////
		// Duplicate all children for this object
		//////
			iObj_duplicateChildren(spinnerDst, spinnerSrc);
	}




//////////
//
// Called to copy the indicated timer from source to destination
//
//////
	void iiSubobj_copyTimer(SObject* timerDst, SObject* timerSrc)
	{
		logfunc(__FUNCTION__);
		//////////
		// Copy all standard properties
		//////
			memcpy(&timerDst->p, &timerSrc->p, sizeof(timerDst->p));


		//////////
		// Copy the allocatables
		//////
			// remember


		//////////
		// Copy the form-specific event handlers
		//////
			memcpy(&timerDst->ev, &timerSrc->ev, sizeof(timerDst->ev));


		//////////
		// Duplicate all children for this object
		//////
			iObj_duplicateChildren(timerDst, timerSrc);
	}




//////////
//
// Called to copy the indicated hyperlink from source to destination
//
//////
	void iiSubobj_copyHyperlink(SObject* hyperlinkDst, SObject* hyperlinkSrc)
	{
		logfunc(__FUNCTION__);
		//////////
		// Copy all standard properties
		//////
			memcpy(&hyperlinkDst->p, &hyperlinkSrc->p, sizeof(hyperlinkDst->p));


		//////////
		// Copy the allocatables
		//////
			// remember


		//////////
		// Copy the form-specific event handlers
		//////
			memcpy(&hyperlinkDst->ev, &hyperlinkSrc->ev, sizeof(hyperlinkDst->ev));


		//////////
		// Duplicate all children for this object
		//////
			iObj_duplicateChildren(hyperlinkDst, hyperlinkSrc);
	}




//////////
//
// Called to copy the indicated collection from source to destination
//
//////
	void iiSubobj_copyCollection(SObject* collectionDst, SObject* collectionSrc)
	{
		logfunc(__FUNCTION__);
		//////////
		// Copy all standard properties
		//////
			memcpy(&collectionDst->p, &collectionSrc->p, sizeof(collectionDst->p));


		//////////
		// Copy the allocatables
		//////
			// remember


		//////////
		// Copy the form-specific event handlers
		//////
			memcpy(&collectionDst->ev, &collectionSrc->ev, sizeof(collectionDst->ev));


		//////////
		// Duplicate all children for this object
		//////
			iObj_duplicateChildren(collectionDst, collectionSrc);
	}




//////////
//
// Called to copy the indicated page from source to destination
//
//////
	void iiSubobj_copyPage(SObject* pageDst, SObject* pageSrc)
	{
		logfunc(__FUNCTION__);
		//////////
		// Copy all standard properties
		//////
			memcpy(&pageDst->p, &pageSrc->p, sizeof(pageDst->p));


		//////////
		// Copy the allocatables
		//////
			// remember


		//////////
		// Copy the form-specific event handlers
		//////
			memcpy(&pageDst->ev, &pageSrc->ev, sizeof(pageDst->ev));


		//////////
		// Duplicate all children for this object
		//////
			iObj_duplicateChildren(pageDst, pageSrc);
	}




//////////
//
// Called to copy the indicated pageframe from source to destination
//
//////
	void iiSubobj_copyPageframe(SObject* pageframeDst, SObject* pageframeSrc)
	{
		logfunc(__FUNCTION__);
		//////////
		// Copy all standard properties
		//////
			memcpy(&pageframeDst->p, &pageframeSrc->p, sizeof(pageframeDst->p));


		//////////
		// Copy the allocatables
		//////
			// remember


		//////////
		// Copy the form-specific event handlers
		//////
			memcpy(&pageframeDst->ev, &pageframeSrc->ev, sizeof(pageframeDst->ev));


		//////////
		// Duplicate all children for this object
		//////
			iObj_duplicateChildren(pageframeDst, pageframeSrc);
	}




//////////
//
// Called to copy the indicated session from source to destination
//
//////
	void iiSubobj_copySession(SObject* sessionDst, SObject* sessionSrc)
	{
		logfunc(__FUNCTION__);
		//////////
		// Copy all standard properties
		//////
			memcpy(&sessionDst->p, &sessionSrc->p, sizeof(sessionDst->p));


		//////////
		// Copy the allocatables
		//////
			// remember


		//////////
		// Copy the form-specific event handlers
		//////
			memcpy(&sessionDst->ev, &sessionSrc->ev, sizeof(sessionDst->ev));


		//////////
		// Duplicate all children for this object
		//////
			iObj_duplicateChildren(sessionDst, sessionSrc);
	}




//////////
//
// Called to copy the indicated custom from source to destination
//
//////
	void iiSubobj_copyCustom(SObject* customDst, SObject* customSrc)
	{
		logfunc(__FUNCTION__);
		//////////
		// Copy all standard properties
		//////
			memcpy(&customDst->p, &customSrc->p, sizeof(customDst->p));


		//////////
		// Copy the allocatables
		//////
			// remember


		//////////
		// Copy the form-specific event handlers
		//////
			memcpy(&customDst->ev, &customSrc->ev, sizeof(customDst->ev));


		//////////
		// Duplicate all children for this object
		//////
			iObj_duplicateChildren(customDst, customSrc);
	}




//////////
//
// Called to copy the indicated exception from source to destination
//
//////
	void iiSubobj_copyException(SObject* exceptionDst, SObject* exceptionSrc)
	{
		logfunc(__FUNCTION__);
		//////////
		// Copy all standard properties
		//////
			memcpy(&exceptionDst->p, &exceptionSrc->p, sizeof(exceptionDst->p));


		//////////
		// Copy the allocatables
		//////
			// remember


		//////////
		// Copy the form-specific event handlers
		//////
			memcpy(&exceptionDst->ev, &exceptionSrc->ev, sizeof(exceptionDst->ev));


		//////////
		// Duplicate all children for this object
		//////
			iObj_duplicateChildren(exceptionDst, exceptionSrc);
	}




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
				*(u32*)&form->ev.general.activate		= (u32)&iDefaultCallback_onActivate;
				*(u32*)&form->ev.general.deactivate		= (u32)&iDefaultCallback_onDeactivate;


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
				*(u32*)&subform->ev.general.activate		= (u32)&iDefaultCallback_onActivate;
				*(u32*)&subform->ev.general.deactivate		= (u32)&iDefaultCallback_onDeactivate;


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

				iSEM_deleteChain(&editbox->p.em, true);
				editbox->p.em = iSEM_allocate(false);


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




//////////
//
// Called to delete the common properties
//
//////
	void iObj_deleteCommon(SObject* obj)
	{
		SWindow* win;


		//////////
		// See if this object is the top-level object to any windows, and if so disconnect it
		//////
			win = iWindow_findByObj(obj);
			if (win)
				iWindow_disconnectObj(win, obj);

// TODO:  iterate through obj->props and delete all
	}




//////////
//
// Called to delete the empty.
//
//////
	void iSubobj_deleteEmpty(SObject* empty, bool tlDeleteSelf)
	{
		logfunc(__FUNCTION__);
		//////////
		// Free common components
		//////
			iObj_deleteCommon(empty);


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
		logfunc(__FUNCTION__);
		//////////
		// Free common components
		//////
			iObj_deleteCommon(form);


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
		logfunc(__FUNCTION__);
		//////////
		// Free common components
		//////
			iObj_deleteCommon(subform);


		//////////
		// Free self
		//////
			if (tlDeleteSelf)
				free(subform);
	}




//////////
//
// Called to delete the carousel
//
//////
	void iSubobj_deleteCarousel(SObject* carousel, bool tlDeleteSelf, bool tlLeaveRiders, bool tlLeaveObjects)
	{
		SObject* rider;
		SObject* riderNext;


		logfunc(__FUNCTION__);
		//////////
		// Free common components
		//////
			iObj_deleteCommon(carousel);


		//////////
		// Act on riders
		//////
			if (tlLeaveRiders)
			{
				// We just need to orphanize each one
//////////
// Note:  Orphanizing riders is a potentially precarious thing.  They must be known as they are
//        not maintained in a buffer somewhere.  Typically this only occurs when migrating the
//        last rider from one carousel to another.  But regardless, care must be taken to prevent
//        the orphaned rider from hanging around unused and forgotten.
//////
				// Get the first
				rider = carousel->firstChild;

				// Mark the parent as now being free from children
				carousel->firstChild = NULL;

				// Iterate for every rider
				while (rider)
				{
					// Determine the next rider
					riderNext = (SObject*)rider->ll.next;

					// Orphanize this rider
					iLl_orphanizeNode((SLL*)rider);

					// Move to next rider
					rider = riderNext;
				}

			} else {
				// They are being deleted
				iObj_delete(&carousel->firstChild, true, true, true);
			}


		//////////
		// Free self
		//////
			if (tlDeleteSelf)
				free(carousel);
	}




//////////
//
// Called to delete the rider
//
//////
	void iSubobj_deleteRider(SObject* rider, bool tlDeleteSelf, bool tlLeaveObjects)
	{
		logfunc(__FUNCTION__);
		//////////
		// Free common components
		//////
			iObj_deleteCommon(rider);


		//////////
		// Act on objects
		//////
			if (!tlLeaveObjects)
				iObj_delete(&rider->firstChild, true, true, true);		// They are being deleted


		//////////
		// Free self
		//////
			if (tlDeleteSelf)
				free(rider);
	}




//////////
//
// Called to delete the label.
//
//////
	void iSubobj_deleteLabel(SObject* label, bool tlDeleteSelf)
	{
		logfunc(__FUNCTION__);
		//////////
		// Free common components
		//////
			iObj_deleteCommon(label);


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
		logfunc(__FUNCTION__);
		//////////
		// Free common components
		//////
			iObj_deleteCommon(textbox);


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
		logfunc(__FUNCTION__);
		//////////
		// Free common components
		//////
			iObj_deleteCommon(button);


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
		logfunc(__FUNCTION__);
		//////////
		// Free common components
		//////
			iObj_deleteCommon(editbox);


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
		logfunc(__FUNCTION__);
		//////////
		// Free common components
		//////
			iObj_deleteCommon(image);


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
		logfunc(__FUNCTION__);
		//////////
		// Free common components
		//////
			iObj_deleteCommon(checkbox);


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
		logfunc(__FUNCTION__);
		//////////
		// Free common components
		//////
			iObj_deleteCommon(option);


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
		logfunc(__FUNCTION__);
		//////////
		// Free common components
		//////
			iObj_deleteCommon(radio);


		//////////
		// Free self
		//////
			if (tlDeleteSelf)
				free(radio);
	}




//////////
//
// Renders an empty.  However, empty objects are not actually rendered.
// But they serve as placeholders for anything contained within.
//
//////
	u32 iSubobj_renderEmpty(SObject* empty)
	{
		logfunc(__FUNCTION__);
		//////////
		// Success!
		//////
			empty->isDirtyRender = false;
			return(0);		// Indicate that nothing was rendered which will affect the screen
	}




//////////
//
// Renders the form.
//
// Note:  The object rendering is independent of the publication of the constructed
//        bitmap.  The render operation only populates the bit buffer.  It will be
//        published at a later time, if indeed it is visible, however, it can after
//        rendering be re-directed to some other source, a disk file, or over a
//        network resource.
//
//////
	u32 iSubobj_renderForm(SObject* obj)
	{
		u32			lnPixelsRendered;
		RECT		lrc, lrc2;
		SBgra		backColor, borderColor, nwRgba, neRgba, swRgba, seRgba;
		SBitmap*	bmp;


		// Make sure our environment is sane
		logfunc(__FUNCTION__);
		lnPixelsRendered = 0;
		if (obj && obj->isRendered)
		{
			//////////
			// If we need re-rendering, re-render
			//////
				// The entire bmp
				SetRect(&lrc, 0, 0, obj->bmp->bi.biWidth, obj->bmp->bi.biHeight);

				// Do we need to redraw?  Or can we just copy?
				if (obj->isDirtyRender)
				{
					// Grab the colors
					borderColor = borderColor(obj);
					backColor	= backColor(obj);
					nwRgba		= nwRgba(obj);
					neRgba		= neRgba(obj);
					swRgba		= swRgba(obj);
					seRgba		= seRgba(obj);

					//////////
					// Frame it
					//////
						if (!obj->bc || !iBmp_isValidCache(&obj->bc, nwRgba.color, neRgba.color, swRgba.color, seRgba.color, obj->rc.right - obj->rc.left, obj->rc.bottom - obj->rc.top, obj->bmp->bi.biWidth, obj->bmp->bi.biHeight, 0))
						{
							// The bitmap cache is no longer valid
							iBmp_deleteCache(&obj->bc);

							// Draw the window border
							if (borderStyle(obj) != _BORDER_STYLE_NONE)		iBmp_fillRect(obj->bmp, &lrc, nwRgba, neRgba, swRgba, seRgba, true, &obj->rcClient,	true);
							else											iBmp_fillRect(obj->bmp, &lrc, nwRgba, neRgba, swRgba, seRgba, true, NULL,			false);

							// Apply a dappling
							iBmp_dapple(obj->bmp, bmpDapple1, 215.0f, 3);

							// Save the cache
							iBmp_createCache(&obj->bc, obj->bmp, nwRgba.color, neRgba.color, swRgba.color, seRgba.color, obj->rc.right - obj->rc.left, obj->rc.bottom - obj->rc.top, obj->bmp->bi.biWidth, obj->bmp->bi.biHeight, 0, true);

						} else {
							// Copy everything over from the cache
							memcpy(obj->bmp->bd, obj->bc->bmpCached->bd, obj->bc->bmpCached->bi.biSizeImage);
						}

						// Frame it
						iBmp_frameRect(obj->bmp, &lrc, borderColor, borderColor, borderColor, borderColor, false, NULL, false);

						// Draw the client area
						bmp = bmpVjrIcon;
						SetRect(&lrc2, 8, bmp->bi.biHeight + 2, lrc.right - bmp->bi.biHeight - 2, lrc.bottom - bmp->bi.biHeight - 1);
						if (backStyle(obj) == _BACK_STYLE_OPAQUE)
							iBmp_fillRect(obj->bmp, &lrc2, backColor, backColor, backColor, backColor, false, NULL, false);

						// Put a border around the client area
						if (borderStyle(obj) != _BORDER_STYLE_NONE)
						{
							InflateRect(&lrc2, 1, 1);
							iBmp_frameRect(obj->bmp, &lrc2, borderColor, borderColor, borderColor, borderColor, false, NULL, false);
						}


// Note:  Eventually these will be moved to form objects, like the icon, caption, and control buttons
					//////////
					// Resizing arrows
					//////
						// Upper left arrow
						SetRect(&lrc2, lrc.left + 1, lrc.top + 1, lrc.left + bmpArrowUl->bi.biWidth, lrc.top + bmpArrowUl->bi.biHeight);
						iBmp_bitBltMask(obj->bmp, &lrc2, bmpArrowUl);
CopyRect(&obj->rcArrowUl, &lrc2);

						// Upper right arrow
						SetRect(&lrc2, lrc.right - bmpArrowUr->bi.biWidth - 1, lrc.top + 1, lrc.right, lrc.top + bmpArrowUr->bi.biHeight);
						iBmp_bitBltMask(obj->bmp, &lrc2, bmpArrowUr);
CopyRect(&obj->rcArrowUr, &lrc2);

						// Lower right arrow
						SetRect(&lrc2, lrc.right - bmpArrowLr->bi.biWidth - 1, lrc.bottom - bmpArrowLr->bi.biHeight - 1, lrc.right, lrc.bottom);
						iBmp_bitBltMask(obj->bmp, &lrc2, bmpArrowLr);
CopyRect(&obj->rcArrowLl, &lrc2);

						// Lower left arrow
						SetRect(&lrc2, lrc.left + 1, lrc.bottom - bmpArrowLl->bi.biHeight - 1, lrc.left + bmpArrowLl->bi.biWidth, lrc.bottom);
						iBmp_bitBltMask(obj->bmp, &lrc2, bmpArrowLl);
CopyRect(&obj->rcArrowLr, &lrc2);


					//////////
					// Copy to prior rendered bitmap
					//////
						// Make sure our bmpPriorRendered exists
						obj->bmpPriorRendered = iBmp_verifyCopyIsSameSize(obj->bmpPriorRendered, obj->bmp);

						// Copy to the prior rendered version
						memcpy(obj->bmpPriorRendered->bd, obj->bmp->bd, obj->bmpPriorRendered->bi.biSizeImage);
						// Right now, we can use the bmpPriorRendered for a fast copy rather than 

				} else {
					// Render from its prior rendered version
					lnPixelsRendered += iBmp_bitBlt(obj->bmp, &lrc, obj->bmpPriorRendered);
				}


			//////////
			// Indicate we're no longer dirty, that we have everything rendered, but it needs publishing
			//////
				obj->isDirtyRender	= false;
				obj->isDirtyPublish	= true;
		}


		// Indicate how many pixels were drawn
		return(lnPixelsRendered);
	}




//////////
//
// Renders the subform.
//
//////
	u32 iSubobj_renderSubform(SObject* obj)
	{
		u32		lnPixelsRendered;
		bool	llIsFocusSubform;
		SBgra	backColor, borderColor, nwRgba, neRgba, swRgba, seRgba;
		RECT	lrc, lrc2;


		// Make sure our environment is sane
		logfunc(__FUNCTION__);
		lnPixelsRendered = 0;
		if (obj && obj->isRendered && obj->rc.right > 0 && obj->rc.bottom > 0 && obj->rc.right >= obj->rc.left && obj->rc.bottom >= obj->rc.bottom && obj->rc.right - obj->rc.left < 4400 && obj->rc.bottom - obj->rc.top < 4400)
		{
			// Grab our colors
			backColor	= backColor(obj);
			borderColor	= borderColor(obj);
			nwRgba		= nwRgba(obj);
			neRgba		= neRgba(obj);
			swRgba		= swRgba(obj);
			seRgba		= seRgba(obj);

			//////////
			// If we need re-rendering, re-render
			//////
				// The entire bmp
				SetRect(&lrc, 0, 0, obj->bmp->bi.biWidth, obj->bmp->bi.biHeight);

				// Do we need to redraw?  Or can we just copy?
				if (obj->isDirtyRender)
				{
					//////////
					// Frame it
					//////
						// Determine if a control on this subform has focus
						llIsFocusSubform = iObj_focus_descentCheck(obj, true, false);
						if (!obj->bc || !iBmp_isValidCache(&obj->bc, nwRgba.color, neRgba.color, swRgba.color, seRgba.color, obj->rc.right - obj->rc.left, obj->rc.bottom - obj->rc.top, obj->bmp->bi.biWidth, obj->bmp->bi.biHeight, (u32)llIsFocusSubform))
						{
							// The bitmap cache is no longer valid
							iBmp_deleteCache(&obj->bc);

							// Draw the window border
							if (backStyle(obj) == _BACK_STYLE_OPAQUE)
							{
								// Render the subform and client area
								if (llIsFocusSubform)		iBmp_fillRect(obj->bmp, &lrc, NwFocusColor,		NeFocusColor,	SwFocusColor,	SeFocusColor,	true, &obj->rcClient,	true);
								else						iBmp_fillRect(obj->bmp, &lrc, nwRgba,			neRgba,			swRgba,			seRgba,			true, &obj->rcClient,	true);

								// Make the client area white
								iBmp_fillRect(obj->bmp, &obj->rcClient, backColor, backColor, backColor, backColor, false, NULL, false);

							} else {
								// Render the subform
								if (llIsFocusSubform)		iBmp_fillRect(obj->bmp, &lrc, NwFocusColor,		NeFocusColor,	SwFocusColor,	SeFocusColor,	true, NULL, false);
								else						iBmp_fillRect(obj->bmp, &lrc, nwRgba,			neRgba,			swRgba,			seRgba,			true, NULL, false);
							}

							// Apply a dappling
							iBmp_dapple(obj->bmp, bmpDapple2, 225.0f, 3);

							// Save the cache
							iBmp_createCache(&obj->bc, obj->bmp, nwRgba.color, neRgba.color, swRgba.color, seRgba.color, obj->rc.right - obj->rc.left, obj->rc.bottom - obj->rc.top, obj->bmp->bi.biWidth, obj->bmp->bi.biHeight, (u32)llIsFocusSubform, true);

						} else {
							// Copy everything over from the cache
							memcpy(obj->bmp->bd, obj->bc->bmpCached->bd, obj->bc->bmpCached->bi.biSizeImage);
						}

						// Frame the client area
						if (borderStyle(obj) != _BORDER_STYLE_NONE)
						{
							CopyRect(&lrc2, &obj->rcClient);
							InflateRect(&lrc2, 1, 1);
							iBmp_frameRect(obj->bmp, &lrc2,	borderColor, borderColor, borderColor, borderColor, false, NULL, false);
							iBmp_frameRect(obj->bmp, &lrc,	borderColor, borderColor, borderColor, borderColor, false, NULL, false);
						}


					//////////
					// Copy to prior rendered bitmap
					//////
						// Make sure our bmpPriorRendered exists
						obj->bmpPriorRendered = iBmp_verifyCopyIsSameSize(obj->bmpPriorRendered, obj->bmp);

						// Copy to the prior rendered version
						memcpy(obj->bmpPriorRendered->bd, obj->bmp->bd, obj->bmpPriorRendered->bi.biSizeImage);
						// Right now, we can use the bmpPriorRendered for a fast copy rather than 

				} else {
					// Render from its prior rendered version
					lnPixelsRendered += iBmp_bitBlt(obj->bmp, &lrc, obj->bmpPriorRendered);
				}


			//////////
			// Indicate we're no longer dirty, that we have everything rendered, but it needs publishing
			//////
				obj->isDirtyRender = false;
				obj->isDirtyPublish	= true;
		}

		// Indicate how many pixels were drawn
		return(lnPixelsRendered);
	}




//////////
//
// Renders the carousel.  Note that carousels are not normally displayed.  The only time
// they'll be displayed by their rendered nature below is if they do not possess any riders.
//
//////
	u32 iSubobj_renderCarousel(SObject* obj)
	{
		u32			lnPixelsRendered;
		bool		llIsFocusCarousel;
		SBgra		nwRgba, neRgba, swRgba, seRgba;
		RECT		lrc;
		SObject*	objFocus;


		// Make sure our environment is sane
		logfunc(__FUNCTION__);
		lnPixelsRendered = 0;
		if (obj && obj->isRendered)
		{
			//////////
			// If we need re-rendering, re-render
			//////
				// The entire bmp
				SetRect(&lrc, 0, 0, obj->bmp->bi.biWidth, obj->bmp->bi.biHeight);

				// Re-render
				if (obj->isDirtyRender)
				{
					// Grab colors
					nwRgba = nwRgba(obj);
					neRgba = neRgba(obj);
					swRgba = swRgba(obj);
					seRgba = seRgba(obj);


					//////////
					// Frame it
					//////
						// Determine if a control on this subform has focus
						objFocus			= iObj_focus_descentCheckObj(obj, true, false);
						llIsFocusCarousel	= (objFocus != NULL);
						if (!obj->bc || !iBmp_isValidCache(&obj->bc, nwRgba.color, neRgba.color, swRgba.color, seRgba.color, obj->rc.right - obj->rc.left, obj->rc.bottom - obj->rc.top, obj->bmp->bi.biWidth, obj->bmp->bi.biHeight, (u32)llIsFocusCarousel))
						{
							// The bitmap cache is no longer valid
							iBmp_deleteCache(&obj->bc);

							// Draw the default background
							if (llIsFocusCarousel)		iBmp_fillRect(obj->bmp, &lrc, NwFocusColor,		NeFocusColor,	SwFocusColor,	SeFocusColor,	true, NULL, false);
							else						iBmp_fillRect(obj->bmp, &lrc, nwRgba,			neRgba,			swRgba,			seRgba,			true, NULL, false);

							// Apply a dappling
							iBmp_dapple(obj->bmp, bmpDapple2, 225.0f, 3);

							// Save the cache
							iBmp_createCache(&obj->bc, obj->bmp, nwRgba.color, neRgba.color, swRgba.color, seRgba.color, obj->rc.right - obj->rc.left, obj->rc.bottom - obj->rc.top, obj->bmp->bi.biWidth, obj->bmp->bi.biHeight, (u32)llIsFocusCarousel, true);

						} else {
							// Copy everything over from the cache
							memcpy(obj->bmp->bd, obj->bc->bmpCached->bd, obj->bc->bmpCached->bi.biSizeImage);
						}


					//////////
					// Copy to prior rendered bitmap
					//////
						// Make sure our bmpPriorRendered exists
						obj->bmpPriorRendered = iBmp_verifyCopyIsSameSize(obj->bmpPriorRendered, obj->bmp);

						// Copy to the prior rendered version
						memcpy(obj->bmpPriorRendered->bd, obj->bmp->bd, obj->bmpPriorRendered->bi.biSizeImage);
						// Right now, we can use the bmpPriorRendered for a fast copy rather than 

				} else {
					// Render from its prior rendered version
					lnPixelsRendered += iBmp_bitBlt(obj->bmp, &lrc, obj->bmpPriorRendered);
				}


			//////////
			// Indicate we're no longer dirty, that we have everything rendered, but it needs publishing
			//////
				obj->isDirtyRender = false;
				obj->isDirtyPublish	= true;
		}

		// Indicate status
		return(lnPixelsRendered);
	}




//////////
//
// Renders the rider.
//
//////
	u32 iSubobj_renderRider(SObject* obj)
	{
		u32		lnPixelsRendered;
		RECT	lrc;


		// Make sure our environment is sane
		logfunc(__FUNCTION__);
		lnPixelsRendered = 0;
		if (obj && obj->isRendered)
		{
			if (obj->isDirtyRender)
			{
				//////////
				// Fill in the background
				//////
					SetRect(&lrc, 0, 0, obj->bmp->bi.biWidth, obj->bmp->bi.biHeight);
					iBmp_fillRect(obj->bmp, &lrc, whiteColor, whiteColor, whiteColor, whiteColor, false, NULL, false);


				//////////
				// Copy to prior rendered bitmap
				//////
					// Make sure our bmpPriorRendered exists
					obj->bmpPriorRendered = iBmp_verifyCopyIsSameSize(obj->bmpPriorRendered, obj->bmp);

					// Copy to the prior rendered version
					memcpy(obj->bmpPriorRendered->bd, obj->bmp->bd, obj->bmpPriorRendered->bi.biSizeImage);
					// Right now, we can use the bmpPriorRendered for a fast copy rather than 

			} else {
				// Render from its prior rendered version
				lnPixelsRendered += iBmp_bitBlt(obj->bmp, &lrc, obj->bmpPriorRendered);
			}


			// Indicate we're no longer dirty, that we have everything rendered, but it needs publishing
			obj->isDirtyRender = false;
			obj->isDirtyPublish	= true;
		}

		// Indicate status
		return(lnPixelsRendered);
	}




//////////
//
// Renders the label.
//
//////
	u32 iSubobj_renderLabel(SObject* obj)
	{
		s32			backStyle;
		u32			lnPixelsRendered, lnFormat;
		SBgra		backColor, foreColor, borderColor;
		SVariable*	caption;
		SVariable*	value;
		RECT		lrc, lrc2;


		// Make sure our environment is sane
		logfunc(__FUNCTION__);
		lnPixelsRendered = 0;
		if (obj && obj->isRendered)
		{
			if (obj->isDirtyRender)
			{
				borderColor	= borderColor(obj);
				backColor	= backColor(obj);
				foreColor	= foreColor(obj);
				backStyle	= backStyle(obj);
				if (backStyle == _BACK_STYLE_OPAQUE)
				{
					// Use the back color
					SetBkColor(obj->bmp->hdc,	RGB(backColor.red, backColor.grn, backColor.blu));
					SetTextColor(obj->bmp->hdc,	RGB(foreColor.red, foreColor.grn, foreColor.blu));

				} else {
					// Use a black and white creation
					SetBkColor(obj->bmp->hdc, RGB(255,255,255));
					SetTextColor(obj->bmp->hdc, RGB(0,0,0));
				}

				// Fill in the background
				SetRect(&lrc, 0, 0, obj->bmp->bi.biWidth, obj->bmp->bi.biHeight);
				iBmp_fillRect(obj->bmp, &lrc, whiteColor, whiteColor, whiteColor, whiteColor, false, NULL, false);

				// Set the text parameters
				SetBkMode(obj->bmp->hdc, TRANSPARENT);
				SelectObject(obj->bmp->hdc, obj->p.font->hfont);

				// Determine our orientation
				switch (alignment(obj))
				{
					default:
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

				// Copy the rectangle
				CopyRect(&lrc2, &lrc);

				// Adjust if need be
				if (obj->parent && obj->parent->objType == _OBJ_TYPE_CHECKBOX)
					lrc.left += 4;

				// Draw the text
				caption = iObjProp_get_variable_byIndex(obj, _INDEX_CAPTION);
				value	= iObjProp_get_variable_byIndex(obj, _INDEX_VALUE);
				DrawText(obj->bmp->hdc, caption->value.data, caption->value.length, &lrc, lnFormat | DT_VCENTER | DT_END_ELLIPSIS);

				// And adjust back if need be
				if (obj->parent && obj->parent->objType == _OBJ_TYPE_CHECKBOX)
					lrc.left -= 4;

				// Frame rectangle
				if (borderStyle(obj) != _BORDER_STYLE_NONE)
					iBmp_frameRect(obj->bmp, &lrc, borderColor, borderColor, borderColor, borderColor, false, NULL, false);

				// For checkbox labels, we handle them differently
				if (obj->parent && obj->parent->objType == _OBJ_TYPE_CHECKBOX)
				{
					// Append the color marker at the end of the label
					SetRect(&lrc2, lrc.right - ((lrc.bottom - lrc.top) / 2), 0, lrc.right, lrc.bottom);
					if (get_s32(value) == 0)
					{
						// It's off, so color it red
						iBmp_fillRect(obj->bmp, &lrc2, NwCheckboxOffColor, NeCheckboxOffColor, SwCheckboxOffColor, SeCheckboxOffColor, true, NULL, false);

					} else {
						// It's on, so color it green
						iBmp_fillRect(obj->bmp, &lrc2, NwCheckboxOnColor, NeCheckboxOnColor, SwCheckboxOnColor, SeCheckboxOnColor, true, NULL, false);
					}

					// Colorize the area
					SetRect(&lrc2, lrc.left, lrc.top, lrc.right - ((lrc.bottom - lrc.top) / 2), lrc.bottom);
					     if (obj->ev.mouse.isMouseDown)		iBmp_colorize(obj->bmp, &lrc2, colorMouseDown,	false, 0.0f);
					else if (obj->ev.mouse.isMouseOver)		iBmp_colorize(obj->bmp, &lrc2, colorMouseOver,	false, 0.0f);

				} else if (backStyle == _BACK_STYLE_OPAQUE) {
					// Colorize the area
					     if (obj->ev.mouse.isMouseDown)		iBmp_colorize(obj->bmp, &lrc, colorMouseDown,	false, 0.0f);
					else if (obj->ev.mouse.isMouseOver)		iBmp_colorize(obj->bmp, &lrc, colorMouseOver,	false, 0.0f);
				}


				//////////
				// Copy to prior rendered bitmap
				//////
					// Make sure our bmpPriorRendered exists
					obj->bmpPriorRendered = iBmp_verifyCopyIsSameSize(obj->bmpPriorRendered, obj->bmp);

					// Copy to the prior rendered version
					memcpy(obj->bmpPriorRendered->bd, obj->bmp->bd, obj->bmpPriorRendered->bi.biSizeImage);
					// Right now, we can use the bmpPriorRendered for a fast copy rather than 

			} else {
				// Render from its prior rendered version
				lnPixelsRendered += iBmp_bitBlt(obj->bmp, &lrc, obj->bmpPriorRendered);
			}


			// Indicate we're no longer dirty, that we have everything rendered, but it needs publishing
			obj->isDirtyRender = false;
			obj->isDirtyPublish	= true;
		}

		// Indicate status
		return(lnPixelsRendered);
	}




//////////
//
// Renders the textbox.
//
//////
	u32 iSubobj_renderTextbox(SObject* obj)
	{
		u32			lnPixelsRendered, lnFormat;
		SBgra		backColor, foreColor, borderColor;
		SVariable*	value;
		RECT		lrc, lrc2;


		// Make sure our environment is sane
		logfunc(__FUNCTION__);
		lnPixelsRendered = 0;
		if (obj && obj->isRendered)
		{
			if (obj->isDirtyRender)
			{
				// Fill in the background
				SetRect(&lrc, 0, 0, obj->bmp->bi.biWidth, obj->bmp->bi.biHeight);
				iiBmp_frameInNineParts(obj->bmp, &lrc, bmpTextbox);

				// Grab the colors
				backColor	= backColor(obj);
				foreColor	= foreColor(obj);
				borderColor	= borderColor(obj);

				// Colorize
				     if (obj->ev.mouse.isMouseDown)		iBmp_colorize(obj->bmp, &lrc, colorMouseDown,	false, 0.0f);
				else if (obj->ev.mouse.isMouseOver)		iBmp_colorize(obj->bmp, &lrc, colorMouseOver,	false, 0.0f);
				else									iBmp_colorize(obj->bmp, &lrc, backColor(obj),	false, 0.0f);

				// Inset slightly for the text part
				CopyRect(&lrc2, &lrc);
				InflateRect(&lrc2, -4, -4);

				// If we're opaque, draw the text inset by a margin, otherwise just overlay
				if (backStyle(obj) == _BACK_STYLE_OPAQUE)
				{
					// Opaque
					SetBkColor(obj->bmp->hdc, RGB(backColor.red, backColor.grn, backColor.blu));
					SetBkMode(obj->bmp->hdc, OPAQUE);

				} else {
					// Transparent
					SetBkMode(obj->bmp->hdc, TRANSPARENT);
				}

				// Set the text parameters
				SetTextColor(obj->bmp->hdc, RGB(foreColor.red, foreColor.grn, foreColor.blu));
				SelectObject(obj->bmp->hdc, obj->p.font->hfont);

				// Determine our orientation
				switch (alignment(obj))
				{
					default:
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
				value = iObjProp_get_variable_byIndex(obj, _INDEX_VALUE);
				DrawText(obj->bmp->hdc, value->value.data, value->value.length, &lrc2, lnFormat | DT_VCENTER | DT_END_ELLIPSIS);

				// Frame rectangle
				if (borderStyle(obj) != _BORDER_STYLE_NONE)
					iBmp_frameRect(obj->bmp, &lrc, borderColor, borderColor, borderColor, borderColor, false, NULL, false);


				//////////
				// Copy to prior rendered bitmap
				//////
					// Make sure our bmpPriorRendered exists
					obj->bmpPriorRendered = iBmp_verifyCopyIsSameSize(obj->bmpPriorRendered, obj->bmp);

					// Copy to the prior rendered version
					memcpy(obj->bmpPriorRendered->bd, obj->bmp->bd, obj->bmpPriorRendered->bi.biSizeImage);
					// Right now, we can use the bmpPriorRendered for a fast copy rather than 

			} else {
				// Render from its prior rendered version
				lnPixelsRendered += iBmp_bitBlt(obj->bmp, &lrc, obj->bmpPriorRendered);
			}


			// Indicate we're no longer dirty, that we have everything rendered, but it needs publishing
			obj->isDirtyRender = false;
			obj->isDirtyPublish	= true;
		}

		// Indicate status
		return(lnPixelsRendered);
	}




//////////
//
// Renders the button.
//
//////
	u32 iSubobj_renderButton(SObject* obj)
	{
		u32			lnPixelsRendered, lnFormat;
		SBgra		backColor, foreColor, borderColor;
		SVariable*	caption;
		RECT		lrc, lrc2;


		// Make sure our environment is sane
		logfunc(__FUNCTION__);
		lnPixelsRendered = 0;
		if (obj && obj->isRendered)
		{
			if (obj->isDirtyRender)
			{
				// Fill in the background
				SetRect(&lrc, 0, 0, obj->bmp->bi.biWidth, obj->bmp->bi.biHeight);
				iiBmp_frameInNineParts(obj->bmp, &lrc, bmpButton);

				// Get the colors
				backColor	= backColor(obj);
				foreColor	= foreColor(obj);
				borderColor	= borderColor(obj);

				// Colorize
				     if (obj->ev.mouse.isMouseDown)		iBmp_colorize(obj->bmp, &lrc, colorMouseDown,	false, 0.0f);
				else if (obj->ev.mouse.isMouseOver)		iBmp_colorize(obj->bmp, &lrc, colorMouseOver,	false, 0.0f);
				else									iBmp_colorize(obj->bmp, &lrc, backColor(obj),	false, 0.0f);

				// Inset slightly for the text part
				CopyRect(&lrc2, &lrc);
				InflateRect(&lrc2, -4, -4);

				// If we're opaque, draw the text inset by a margin, otherwise just overlay
				if (backStyle(obj) == _BACK_STYLE_OPAQUE)
				{
					// Opaque
					SetBkColor(obj->bmp->hdc, RGB(backColor.red, backColor.grn, backColor.blu));
					SetBkMode(obj->bmp->hdc, OPAQUE);

				} else {
					// Transparent
					SetBkMode(obj->bmp->hdc, TRANSPARENT);
				}

				// Set the text parameters
				SetTextColor(obj->bmp->hdc, RGB(foreColor.red, foreColor.grn, foreColor.blu));
				SelectObject(obj->bmp->hdc, obj->p.font->hfont);

				// Determine our orientation
				switch (alignment(obj))
				{
					default:
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
				caption = iObjProp_get_variable_byIndex(obj, _INDEX_CAPTION);
				DrawText(obj->bmp->hdc, caption->value.data, caption->value.length, &lrc2, lnFormat | DT_VCENTER | DT_END_ELLIPSIS);

				// Frame rectangle
				if (borderStyle(obj) != _BORDER_STYLE_NONE)
					iBmp_frameRect(obj->bmp, &lrc, borderColor, borderColor, borderColor, borderColor, false, NULL, false);


				//////////
				// Copy to prior rendered bitmap
				//////
					// Make sure our bmpPriorRendered exists
					obj->bmpPriorRendered = iBmp_verifyCopyIsSameSize(obj->bmpPriorRendered, obj->bmp);

					// Copy to the prior rendered version
					memcpy(obj->bmpPriorRendered->bd, obj->bmp->bd, obj->bmpPriorRendered->bi.biSizeImage);
					// Right now, we can use the bmpPriorRendered for a fast copy rather than 

			} else {
				// Render from its prior rendered version
				lnPixelsRendered += iBmp_bitBlt(obj->bmp, &lrc, obj->bmpPriorRendered);
			}


			// Indicate we're no longer dirty, that we have everything rendered, but it needs publishing
			obj->isDirtyRender = false;
			obj->isDirtyPublish	= true;
		}

		// Indicate status
		return(lnPixelsRendered);
	}




//////////
//
// Renders the editbox.
//
//////
	u32 iSubobj_renderEditbox(SObject* obj)
	{
		u32		lnPixelsRendered;
		SBgra	borderColor;
		RECT	lrc;


		// Make sure our environment is sane
		logfunc(__FUNCTION__);
		lnPixelsRendered = 0;
		if (obj && obj->isRendered)
		{
			// Grab the rectangle
			iSEM_getRectAndFont(obj->p.em, obj, &lrc);

			// Are we rendering?
			if (obj->isDirtyRender)
			{
				// Re-render
				lnPixelsRendered = iSEM_render(obj->p.em, obj, obj->p.hasFocus);

				// Get colors
				borderColor = borderColor(obj);

				if (borderStyle(obj) != _BORDER_STYLE_NONE)
					iBmp_frameRect(obj->bmp, &lrc, borderColor, borderColor, borderColor, borderColor, false, NULL, false);

				//////////
				// Copy to prior rendered bitmap
				//////
					// Make sure our bmpPriorRendered exists
					obj->bmpPriorRendered = iBmp_verifyCopyIsSameSize(obj->bmpPriorRendered, obj->bmp);

					// Copy to the prior rendered version
					memcpy(obj->bmpPriorRendered->bd, obj->bmp->bd, obj->bmpPriorRendered->bi.biSizeImage);
					// Right now, we can use the bmpPriorRendered for a fast copy rather than 

			} else {
				// Render from its prior rendered version
				lnPixelsRendered += iBmp_bitBlt(obj->bmp, &lrc, obj->bmpPriorRendered);
			}


			// Indicate we're no longer dirty, that we have everything rendered, but it needs publishing
			obj->isDirtyRender = false;
			obj->isDirtyPublish	= true;
		}

		// Indicate status
		return(lnPixelsRendered);
	}




//////////
//
// Renders the image.
//
//////
	u32 iSubobj_renderImage(SObject* obj)
	{
		u32			lnPixelsRendered;
		SBitmap*	bmp;
		RECT		lrc;


		// Make sure our environment is sane
		logfunc(__FUNCTION__);
		lnPixelsRendered = 0;
		if (obj && obj->isRendered)
		{
			// Compute our rectangle for drawing
			SetRect(&lrc, 0, 0, obj->bmp->bi.biWidth, obj->bmp->bi.biHeight);

			if (obj->isDirtyRender)
			{
				// Based on the current conditions, render the appropriate image
				if (obj->ev.mouse.isMouseDown)
				{
					// Mouse is down on this item
					bmp = iObjProp_get_bitmap(obj, _INDEX_PICTUREBMP_DOWN);

				} else if (obj->ev.mouse.isMouseOver) {
					// Mouse is over this item
					bmp = iObjProp_get_bitmap(obj, _INDEX_PICTUREBMP_OVER);

				} else {
					// Render normally
					bmp = iObjProp_get_bitmap(obj, _INDEX_PICTUREBMP);
				}

				// Render it
				lnPixelsRendered += iBmp_bitBlt(obj->bmp, &lrc, bmp);

				// For checkbox images, we colorize them differently
				if (obj->parent && obj->parent->objType == _OBJ_TYPE_CHECKBOX)
				{
					// Colorize
						 if (obj->ev.mouse.isMouseDown)		iBmp_colorize(obj->bmp, &lrc, colorMouseDown,	false, 0.0f);
					else if (obj->ev.mouse.isMouseOver)		iBmp_colorize(obj->bmp, &lrc, colorMouseOver,	false, 0.0f);
				}


				//////////
				// Copy to prior rendered bitmap
				//////
					// Make sure our bmpPriorRendered exists
					obj->bmpPriorRendered = iBmp_verifyCopyIsSameSize(obj->bmpPriorRendered, obj->bmp);

					// Copy to the prior rendered version
					memcpy(obj->bmpPriorRendered->bd, obj->bmp->bd, obj->bmpPriorRendered->bi.biSizeImage);
					// Right now, we can use the bmpPriorRendered for a fast copy rather than 

			} else {
				// Render from its prior rendered version
				lnPixelsRendered += iBmp_bitBlt(obj->bmp, &lrc, obj->bmpPriorRendered);
			}

			// Indicate we're no longer dirty, that we have everything rendered, but it needs publishing
			obj->isDirtyRender = false;
			obj->isDirtyPublish	= true;
		}

		// Indicate status
		return(lnPixelsRendered);
	}




//////////
//
// Renders the logical checkbox control.  The checkbox is not actually rendered, but
// rather it reads from the parent whatever is underneath its rectangle at the point
// of the render request, then it draws the child objects atop itself.
//
//////
	u32 iSubobj_renderCheckbox(SObject* obj)
	{
		u32		lnPixelsRendered;
		RECT	lrc;


		// Make sure our environment is sane
		logfunc(__FUNCTION__);
		lnPixelsRendered = 0;
		if (obj && obj->isRendered)
		{
			// Compute our rectangle for drawing
			SetRect(&lrc, 0, 0, obj->bmp->bi.biWidth, obj->bmp->bi.biHeight);

			// There is nothing actually rendered here, but the child renders into it
			if (obj->isDirtyRender)
			{
				//////////
				// Copy to prior rendered bitmap
				//////
					// Make sure our bmpPriorRendered exists
					obj->bmpPriorRendered = iBmp_verifyCopyIsSameSize(obj->bmpPriorRendered, obj->bmp);

					// Copy to the prior rendered version
					memcpy(obj->bmpPriorRendered->bd, obj->bmp->bd, obj->bmpPriorRendered->bi.biSizeImage);
					// Right now, we can use the bmpPriorRendered for a fast copy rather than 

			} else {
				// Render from its prior rendered version
				lnPixelsRendered += iBmp_bitBlt(obj->bmp, &lrc, obj->bmpPriorRendered);
			}

			// Indicate we're no longer dirty, that we have everything rendered, but it needs publishing
			obj->isDirtyRender = false;
			obj->isDirtyPublish	= true;
		}

		// Indicate status
		return(lnPixelsRendered);
	}




//////////
//
// Renders the option.
//
//////
	u32 iSubobj_renderOption(SObject* obj)
	{
		logfunc(__FUNCTION__);


			//////////
			// Indicate we're no longer dirty, that we have everything
			//////
				obj->isDirtyRender = false;
		return(0);
	}




//////////
//
// Renders the radio.
//
//////
	u32 iSubobj_renderRadio(SObject* obj)
	{
		u32			lnPixelsRendered, lnXCenter, lnYCenter, lnSkip;
		f32			lfTheta, lfRadius;
		f64			lfValue, lfMin, lfMax;
		SBitmap*	bmpRadioScale;
		SBgra		foreColor;
		RECT		lrc, lrc2;
		s8*			lcSprintfFormat;
		s8			buffer[64];


		// Make sure our environment is sane
		logfunc(__FUNCTION__);
		lnPixelsRendered = 0;
		if (obj && obj->isRendered)
		{
			// Compute our rectangle for drawing
			SetRect(&lrc, 0, 0, obj->bmp->bi.biWidth, obj->bmp->bi.biHeight);

			if (obj->isDirtyRender)
			{
				//////////
				// Get the values
				//////
					lfValue	= iObjProp_get_f64_direct(obj, _INDEX_VALUE);
					lfMin	= iObjProp_get_f64_direct(obj, _INDEX_VALUE_MINIMUM);
					lfMax	= iObjProp_get_f64_direct(obj, _INDEX_VALUE_MAXIMUM);

					// Make sure max is greater than or equal to min, and value is in range
					lfMax	= max(lfMin, lfMax);
					lfValue	= min(max(lfValue, lfMin), lfMax);

					// Determine the percentage
					lfTheta	= (f32)((lfValue - lfMin) / (lfMax - lfMin)) * (f32)(M_PI * 2.0);

					// Color
					foreColor = foreColor(obj);


				//////////
				// Determine the scaling ratio for the dial indicator
				//////
					// Create a copy for later scaling
					bmpRadioScale = iBmp_allocate();
					iBmp_createBySize(bmpRadioScale, bmpRadio->bi.biWidth, bmpRadio->bi.biHeight, 24);
					bmpRadioScale = iBmp_copy(bmpRadio);


				//////////
				// Compute the position the dial indicator based on settings, and build the lrc2 on it
				//////
					lfRadius	= (f32)bmpRadioScale->bi.biWidth * 0.225f;
					lnXCenter	= (u32)(((f32)bmpRadioScale->bi.biWidth  / 2.0f));
					lnYCenter	= (u32)(((f32)bmpRadioScale->bi.biHeight / 2.0f));

					// Build the rect
					SetRect(&lrc2,	(u32)(lnXCenter + (lfRadius * cos(lfTheta)) - (bmpRadioDot->bi.biWidth / 2)),
									(u32)(lnYCenter - (lfRadius * sin(lfTheta)) - (bmpRadioDot->bi.biHeight / 2)),
									0, 0);
					
					lrc2.right	= lrc2.left	+ bmpRadioDot->bi.biWidth;
					lrc2.bottom	= lrc2.top	+ bmpRadioDot->bi.biHeight;
					iBmp_bitBltMask(bmpRadioScale, &lrc2, bmpRadioDot);


				// Scale the base into it
				iBmp_scale(obj->bmp, bmpRadioScale);

				// Delete the scaled dot
				iBmp_delete(&bmpRadioScale, true, true);


				//////////
				// Draw the text of the value into the center
				//////
					lcSprintfFormat = iMath_roundTo(&lfValue, iObjProp_get_f64_direct(obj, _INDEX_ROUND_TO));
					sprintf(buffer, lcSprintfFormat, lfValue);

					if (buffer[strlen(buffer)] == '.')
						buffer[strlen(buffer)] = 0;

					lnSkip = iSkipWhitespaces(buffer, strlen(buffer));

					SetRect(&lrc2,	obj->bmp->bi.biWidth / 7,
									(obj->bmp->bi.biHeight / 2) - (obj->bmp->bi.biHeight / 7),
									obj->bmp->bi.biWidth * 6 / 7,
									(obj->bmp->bi.biHeight / 2) + (obj->bmp->bi.biHeight / 7));
					
					SetTextColor(obj->bmp->hdc, RGB(foreColor.red, foreColor.grn, foreColor.blu));
					SetBkMode(obj->bmp->hdc, TRANSPARENT);
					SelectObject(obj->bmp->hdc, ((obj->p.font) ? obj->p.font : gsFontDefault));
					DrawText(obj->bmp->hdc, buffer + lnSkip, strlen(buffer + lnSkip), &lrc2, DT_CENTER | DT_SINGLELINE | DT_VCENTER);


				// Colorize
				     if (obj->ev.mouse.isMouseDown)		iBmp_colorize(obj->bmp, &lrc, colorMouseDown,	false, 0.0f);
				else if (obj->ev.mouse.isMouseOver)		iBmp_colorize(obj->bmp, &lrc, colorMouseOver,	false, 0.0f);
				else									iBmp_colorize(obj->bmp, &lrc, backColor(obj),	false, 0.0f);


				//////////
				// Copy to prior rendered bitmap
				//////
					// Make sure our bmpPriorRendered exists
					obj->bmpPriorRendered = iBmp_verifyCopyIsSameSize(obj->bmpPriorRendered, obj->bmp);

					// Copy to the prior rendered version
					memcpy(obj->bmpPriorRendered->bd, obj->bmp->bd, obj->bmpPriorRendered->bi.biSizeImage);
					// Right now, we can use the bmpPriorRendered for a fast copy rather than 

			} else {
				// Render from its prior rendered version
				lnPixelsRendered += iBmp_bitBlt(obj->bmp, &lrc, obj->bmpPriorRendered);
			}

			// Indicate we're no longer dirty, that we have everything rendered, but it needs publishing
			obj->isDirtyRender = false;
			obj->isDirtyPublish	= true;
		}

		// Indicate status
		return(lnPixelsRendered);
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
