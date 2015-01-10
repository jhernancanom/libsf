//////////
//
// /libsf/source/vjr/source/objects/callbacks.cpp
//
//////
// Version 0.54
// Copyright (c) 2014 by Rick C. Hodgin
//////
// Last update:
//     Jun.15.2014
//////
// Change log:
//     Jun.15.2014 - Initial creation
//////
//
// This document is released as Liberty Software under a Repeat License, as governed
// by the Public Benefit License v1.0 or later (PBL).
//
// The PBL is a public domain license with a caveat:  self accountability unto God.
// You are free to use, copy, modify and share this software for any purpose, however,
// it is the desire of those working on this project that the software remain open.
// It is our request that you maintain it that way.  This is not a legal request unto
// our court systems, but rather a personal matter between you and God.  Our talents
// were received from God, and given to you through this forum.  And it is our wish
// that those talents reach out to as many as possible in a form allowing them to wield
// this content for their own betterment, as you are now considering doing.  And whereas
// we could've forced the issue through something like a copyleft-protected release, the
// truth is we are all giving an account of our lives unto God continually by the daily
// choices we make.  And here again is another case where you get to demonstrate your
// character unto God, and unto your fellow man.
//
// Jesus came to this Earth to set the captives free, to save men's eternal souls from
// the punishment demanded by our sin.  Each one of us is given the opportunity to
// receive Him in this world and be saved.  Whether we choose to receive Him, and follow
// Him, and purpose our lives on the goals He has for each of us (all of which are
// beneficial for all involved), is one way we reveal our character continually.  God
// sees straight through to the heart, bypassing all of the words, all of the facades.
// He is our Creator, and He knows who we are truly.
//
// Jesus is called "Christ" because He saves men from the eternal flames of Hell, the
// just punishment of rebellion against God (rebellion against truth) by eternal beings,
// which each of us are.
//
// Do not let His free gift escape you because of some desire to shortcut what is right
// in your life. Instead, do what is right, and do it because He is who He is, and what
// He has done to save us from such a fate.  Demonstrate to Him, to me, and to all of
// mankind, and to all of the Heavenly hosts, exactly who you are on the inside.  Receive
// Jesus Christ into your heart, learn of Him, of how He came here to guide us into that
// which is of His Kingdom and will be forever hereafter we leave this world.  Do this,
// and live.
//
// Every project released by Liberty Software Foundation will include a copy of the
// pbl.txt document, which can be found at http://www.libsf.org/licenses/.
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
// Default callbacks
//
//////
	bool iDefaultCallback_onLoad(SWindow* win, SObject* obj)
	{
		// Assume it's okay to load
		return(true);
	}

	bool iDefaultCallback_onInit(SWindow* win, SObject* obj)
	{
		// Assume we consumed the gotFocus, and that the parent doesn't need to receive it
		return(false);
	}

	bool iDefaultCallback_onCreated(SWindow* win, SObject* obj)
	{
		// Assume we consumed the gotFocus, and that the parent doesn't need to receive it
		return(false);
	}

	bool iDefaultCallback_onResize(SWindow* win, SObject* obj, u32* widthRequired_out, u32* heightRequired_out)
	{
		// Assume we consumed the gotFocus, and that the parent doesn't need to receive it
		return(false);
	}

	bool iDefaultCallback_onRender(SWindow* win, SObject* obj)
	{
		// Assume it was rendered okay
		return(true);
	}

	bool iDefaultCallback_onPublish(SWindow* win, SObject* obj)
	{
		// Assume it was published okay
		return(true);
	}

	bool iDefaultCallback_onDestroy(SWindow* win, SObject* obj)
	{
		// Assume we consumed the gotFocus, and that the parent doesn't need to receive it
		return(false);
	}

	bool iDefaultCallback_onUnload(SWindow* win, SObject* obj)
	{
		// Assume we consumed the gotFocus, and that the parent doesn't need to receive it
		return(false);
	}

	bool iDefaultCallback_onGotFocus(SWindow* win, SObject* obj)
	{
		// Assume we consumed the gotFocus, and that the parent doesn't need to receive it
		return(false);
	}

	bool iDefaultCallback_onLostFocus(SWindow* win, SObject* obj)
	{
		// Assume we consumed the lostFocus, and that the parent doesn't need to receive it
		return(false);
	}

	bool iDefaultCallback_onMouseClickEx(SWindow* win, SObject* obj, s32 x, s32 y, bool tlCtrl, bool tlAlt, bool tlShift, u32 tnClick)
	{
		// Assume we consumed the mouse click, and that the parent doesn't need to receive it
		return(false);
	}

	bool iDefaultCallback_onMouseDblClickEx(SWindow* win, SObject* obj, s32 x, s32 y, bool tlCtrl, bool tlAlt, bool tlShift, u32 tnClick)
	{
		// Assume we consumed the mouse click, and that the parent doesn't need to receive it
		return(false);
	}

	bool iDefaultCallback_onMouseWheel(SWindow* win, SObject* obj, s32 x, s32 y, bool tlCtrl, bool tlAlt, bool tlShift, u32 tnClick, s32 tnUnits)
	{
		// Assume we consumed the mouse wheel, and that the parent doesn't need to receive it
		if (obj->objType == _OBJ_TYPE_EDITBOX)
		{
			// Ctrl+MouseWheel is a normal navigate
			if (tlCtrl)
			{
				// They are just moving the cursor line
				iSEM_navigate(obj->p.sem, obj, tnUnits * ((tlShift) ? -1 : -3), 0);

			// MouseWheel is a scroll
			} else {
				// They want to scroll the entire window, including the cursor line
				iSEM_scroll(obj->p.sem, obj, tnUnits * ((tlShift) ? -1 : -3), 0);
			}
			iObj_setDirtyRender_ascent(obj, true);
			iWindow_render(win, false);
		}
		return(false);
	}

	bool iDefaultCallback_onMouseMove(SWindow* win, SObject* obj, s32 x, s32 y, bool tlCtrl, bool tlAlt, bool tlShift, u32 tnClick)
	{
		f64			lfPercent, lfX, lfY, lfWidth, lfHeight;
		SVariable*	valueMin;


		// If we're clicking on a radio button, adjust the dial
		if (tnClick != 0 && obj->objType == _OBJ_TYPE_RADIO)
		{
			// The mouse indicates the position
			// Determine theta
			lfWidth		= (f64)(obj->rc.right  - obj->rc.left);
			lfHeight	= (f64)(obj->rc.bottom - obj->rc.top);
			lfX			= (f64)x - (lfWidth / 2.0);
			lfY			= (lfHeight - (f64)y) - (lfHeight / 2.0);

			lfPercent	= atan2(lfY, lfX) / (M_PI * 2.0);
			if (lfPercent < 0.0)
				lfPercent += 1.0;

			valueMin = iObjProp_get_variable_byIndex(obj, _INDEX_VALUE_MINIMUM);
			iObjProp_set_f64_direct(obj, _INDEX_VALUE, get_f64(valueMin) + (lfPercent * (iObjProp_get_f64_direct(obj, _INDEX_VALUE_MAXIMUM) - get_f64(valueMin))));
			iObj_setDirtyRender_ascent(obj, true);
			iWindow_render(win, false);

		} else if (obj->objType == _OBJ_TYPE_EDITBOX) {
			if ((tnClick & _MOUSE_LEFT_BUTTON) != 0)
			{
				// They are clicking and dragging

				// Need to navigate to the indicated x,y coordinate
				iSEM_navigateTo_pixelXY(obj->p.sem, obj, x, y);

				// Mark the mouse activity
				iSEM_selectStart(obj->p.sem, _SEM_SELECT_MODE_ANCHOR);

				// Redraw our changes
				iObj_setDirtyRender_ascent(obj, true);
				iWindow_render(win, false);
			}
		}

		return(false);
	}

	bool iDefaultCallback_onMouseDown(SWindow* win, SObject* obj, s32 x, s32 y, bool tlCtrl, bool tlAlt, bool tlShift, u32 tnClick)
	{
		bool		llMouseDown;
		f64			lfPercent, lfX, lfY, lfWidth, lfHeight, lfValue;
		SVariable*	varName;
		SVariable*	valueMin;
		SObject*	objRoot;


		// Set the flag
		llMouseDown = true;

		// If focus isn't already set on this control, set focus on this control
		if (!obj->p.hasFocus)
		{
			objRoot = iObj_find_rootmostObject(obj);
			if (objRoot)
				iObj_clearFocus(win, objRoot, true, true);

			iObj_setFocus(win, obj, true);
			iObj_setDirtyRender_ascent(objRoot, true);
		}

		// For forms, they can be clicking down on special things for various operations
		if (obj->parent && obj->parent->objType == _OBJ_TYPE_FORM && win->obj == obj->parent)
		{
			// Left button only?
			if (win->mouseCurrent.buttonLeft && !win->mouseCurrent.buttonMiddle && !win->mouseCurrent.buttonRight)
			{
				// We're on the top-level form for the window
				varName = iObjProp_get_variable_byIndex(obj, _INDEX_NAME);
				if (	iDatum_compare(&varName->value, cgcName_iconMove,	sizeof(cgcName_iconMove) - 1)	== 0
					||	iDatum_compare(&varName->value, cgcName_caption,	sizeof(cgcName_caption) - 1)	== 0)
				{
					// We're on the _move icon or the caption, which means they want to move the window
					win->isMoving = true;
					memcpy(&win->rcMoveResizeStart,		&win->rc,			sizeof(win->rcMoveResizeStart));
					memcpy(&win->mouseMoveResizeStart,	&win->mouseCurrent,	sizeof(win->mouseMoveResizeStart));

//				} else if (iDatum_compare(&varName->value, cgcName_iconScaleUl, sizeof(cgcName_iconScaleUl) - 1) == 0) {
//					// We're on the upper-left scaling arrow
//				} else if (iDatum_compare(&varName->value, cgcName_iconScaleUr, sizeof(cgcName_iconScaleUr) - 1) == 0) {
//					// We're on the upper-right scaling arrow
//				} else if (iDatum_compare(&varName->value, cgcName_iconScaleLr, sizeof(cgcName_iconScaleLr) - 1) == 0) {
//					// We're on the lower-right scaling arrow
//				} else if (iDatum_compare(&varName->value, cgcName_iconScaleLl, sizeof(cgcName_iconScaleLl) - 1) == 0) {
//					// We're on the lower-left scaling arrow
				}
			}
		}

		if (obj->parent && obj->parent->objType == _OBJ_TYPE_CHECKBOX)
		{
			// For checkboxes, we toggle
			// They're clicking on a checkbox, toggle the value and re-render
			iObjProp_set_s32_direct(obj, _INDEX_VALUE, ((iObjProp_get_s32_direct(obj, _INDEX_VALUE) != 0) ? 0 : 1));

			// Calling the size with its current size forces the refresh
			iObj_setSize(obj->parent,
							obj->parent->rc.left,
							obj->parent->rc.top,
							obj->parent->rc.right  - obj->parent->rc.left,
							obj->parent->rc.bottom - obj->parent->rc.top);

		} else if (obj->objType == _OBJ_TYPE_EDITBOX) {
			// Need to navigate to the indicated x,y coordinate
			iSEM_navigateTo_pixelXY(obj->p.sem, obj, x, y);

			// Mark the mouse activity
			if (!tlShift)		iSEM_selectStop(obj->p.sem);
			else				iSEM_selectStart(obj->p.sem, _SEM_SELECT_MODE_ANCHOR);

		} else if (obj->objType == _OBJ_TYPE_RADIO) {
			// The mouse indicates the position
			// Determine theta
			lfWidth							= (f64)(obj->rc.right  - obj->rc.left);
			lfHeight						= (f64)(obj->rc.bottom - obj->rc.top);
			lfX								= (f64)x - (lfWidth / 2.0);
			lfY								= (lfHeight - (f64)y) - (lfHeight / 2.0);
			lfPercent						= atan2(lfY, lfX) / (M_PI * 2.0);
			if (lfPercent < 0.0)
				lfPercent += 1.0;

			valueMin	= iObjProp_get_variable_byIndex(obj, _INDEX_VALUE_MINIMUM);
			lfValue		= get_f64(valueMin) + (lfPercent * (iObjProp_get_f64_direct(obj, _INDEX_VALUE_MAXIMUM) - get_f64(valueMin)));
			iObjProp_set_f64_direct(obj, _INDEX_VALUE, lfValue);

		} else {
			// Assume we consumed the mouse down event, and that the parent doesn't need to receive it
			switch (obj->objType)
			{
				case _OBJ_TYPE_IMAGE:
					if (isName(obj, cgcName_iconClose)) {
						// Close
						iVjr_shutdown();	// They clicked quit
						return(false);		// When we get here, the object no longer exists

					} else if (isName(obj, cgcName_iconMove)) {
						// Move
						llMouseDown					= false;
						obj->ev.mouse.isMouseOver	= false;
						iWindow_move(win);

					} else if (isName(obj, cgcName_iconMinimize)) {
						// Minimize
						llMouseDown					= false;
						obj->ev.mouse.isMouseOver	= false;
						iWindow_minimize(win);

					} else if (isName(obj, cgcName_iconMaximize)) {
						// Maximize
						llMouseDown					= false;
						obj->ev.mouse.isMouseOver	= false;
						iWindow_maximize(win);
					}
					break;
			}
		}

		// Update our condition
		obj->ev.mouse.isMouseDown = llMouseDown;
		iObj_setDirtyRender_ascent(obj, true);
		iWindow_render(win, false);
		return(true);
	}

	bool iDefaultCallback_onMouseUp(SWindow* win, SObject* obj, s32 x, s32 y, bool tlCtrl, bool tlAlt, bool tlShift, u32 tnClick)
	{
		// We are leaving this object, lower the flag
		obj->ev.mouse.isMouseDown = (obj->ev.mouse.thisClick != 0);	// Indicate if the mouse is down here
		obj->ev.mouse.isMouseDown = false;
		iObj_setDirtyRender_ascent(obj, true);
		iWindow_render(win, false);
		return(false);
	}

	bool iDefaultCallback_onMouseEnter(SWindow* win, SObject* obj)
	{
		// We are newly over this object, raise the flag
		obj->ev.mouse.isMouseDown = (obj->ev.mouse.thisClick != 0);	// Indicate if the mouse is down here
		if (!obj->ev.mouse.isMouseOver)
		{
			obj->ev.mouse.isMouseOver = true;
			iObj_setDirtyRender_ascent(obj, true);
			iWindow_render(win, false);
		}

		// Assume we consumed the enter, and that the parent doesn't need to receive it
		return(false);
	}

	bool iDefaultCallback_onMouseLeave(SWindow* win, SObject* obj)
	{
		// Assume we consumed the leave, and that the parent doesn't need to receive it
		if (obj->ev.mouse.isMouseOver)
		{
			obj->ev.mouse.isMouseOver = false;
			iObj_setDirtyRender_ascent(obj, true);
			iWindow_render(win, false);
		}
		return(false);
	}

	bool iDefaultCallback_onMouseHover(SWindow* win, SObject* obj, s32 x, s32 y, bool tlCtrl, bool tlAlt, bool tlShift, u32 tnClick)
	{
		// Assume we consumed the hover, and that the parent doesn't need to receive it
		return(false);
	}

	bool iDefaultCallback_onKeyDown(SWindow* win, SObject* obj, bool tlCtrl, bool tlAlt, bool tlShift, bool llCaps, s16 tcAscii, u16 tnVKey, bool tlIsCAS, bool tlIsAscii)
	{
		bool		llRender;
		SObject*	objCheckbox;
		SObject*	objRender2;


		//////////
		// See if we're on a checkbox
		//////
			llRender	= false;
			objCheckbox	= NULL;
			if (obj->objType == _OBJ_TYPE_CHECKBOX)
			{
				// The object itself is a checkbox
				objCheckbox = obj;
				objRender2	= obj;

			} else if (obj->parent && obj->parent->objType == _OBJ_TYPE_CHECKBOX) {
				// The parent is a checkbox
				objCheckbox = obj->parent;
				objRender2	= obj;
			}

			if (objCheckbox)
			{
				if (tnVKey == VK_SPACE || tnVKey == VK_RETURN)
				{
					// Toggle the value and redraw
					llRender = true;
					iObjProp_set_s32_direct(objCheckbox, _INDEX_VALUE, ((iObjProp_get_s32_direct(objCheckbox, _INDEX_VALUE) == 0) ? 1 : 0));
					iObj_setDirtyRender_ascent(objCheckbox, false);
					if (objRender2 != objCheckbox)
						iObj_setDirtyRender_ascent(objRender2, false);

				} else if (tlShift && tnVKey == VK_TAB) {
					// Move to previous object
					llRender = iObj_setFocusObjectPrev(win, objCheckbox);

				} else if (tnVKey == VK_TAB) {
					// Move to next object
					llRender = iObj_setFocusObjectNext(win, objCheckbox);

				} else if (tlIsAscii) {
					if ((u8)tcAscii == 't' || (u8)tcAscii == 'T' || (u8)tcAscii == 'y' || (u8)tcAscii == 'Y' || (u8)tcAscii == '1')
					{
						// Set it to on
						llRender = true;
						iObjProp_set_s32_direct(obj, _INDEX_VALUE, 1);
						iObj_setDirtyRender_ascent(objCheckbox, false);
						if (objRender2 != objCheckbox)
							iObj_setDirtyRender_ascent(objRender2, false);

					} else if ((u8)tcAscii == 'f' || (u8)tcAscii == 'F' || (u8)tcAscii == 'n' || (u8)tcAscii == 'N' || (u8)tcAscii == '0') {
						// Set it to off
						llRender = true;
						iObjProp_set_s32_direct(obj, _INDEX_VALUE, 0);
						iObj_setDirtyRender_ascent(objCheckbox, false);
						if (objRender2 != objCheckbox)
							iObj_setDirtyRender_ascent(objRender2, false);
					}
				}

			} else {
				// Not a checkbox
				if (tlShift && tnVKey == VK_TAB)
				{
					// Move to previous object
					llRender = iObj_setFocusObjectPrev(win, obj);

				} else if (tnVKey == VK_TAB) {
					// Move to next object
					llRender = iObj_setFocusObjectNext(win, obj);
				}
			}


		// Redraw if need be
		if (llRender)
		{
			// Redraw the checkbox if needed
			if (objCheckbox)
				iObj_setSize(objCheckbox, objCheckbox->rc.left, objCheckbox->rc.top, objCheckbox->rc.right - objCheckbox->rc.left, objCheckbox->rc.bottom - objCheckbox->rc.top);

			// Redraw the window
			iWindow_render(win, false);
		}
		
		return(false);
	}

	bool iDefaultCallback_onKeyUp(SWindow* win, SObject* obj, bool tlCtrl, bool tlAlt, bool tlShift, bool llCaps, s16 tcAscii, u16 tnVKey, bool tlIsCAS, bool tlIsAscii)
	{
		// Assume we consumed the keyup, and that the parent doesn't need to receive it
		return(false);
	}

	bool iDefaultCallback_onActivate(SWindow* win, SObject* obj)
	{
		// Assume we consumed the activate, and that the parent doesn't need to receive it
		return(false);
	}

	bool iDefaultCallback_onDeactivate(SWindow* win, SObject* obj)
	{
		// Assume we consumed the deactivate, and that the parent doesn't need to receive it
		return(false);
	}

	bool iDefaultCallback_onInteractiveChange(SWindow* win, SObject* obj)
	{
		// Assume we consumed the interactiveChange, and that the parent doesn't need to receive it
		return(false);
	}

	bool iDefaultCallback_onProgrammaticChange(SWindow* win, SObject* obj)
	{
		// Assume we consumed the programmaticChange, and that the parent doesn't need to receive it
		return(false);
	}

	bool iDefaultCallback_onSelect(SWindow* win, SObject* obj)
	{
		// Assume we consumed the onSelect, and that the parent doesn't need to receive it
		return(false);
	}

	bool iDefaultCallback_onDeselect(SWindow* win, SObject* obj)
	{
		// Assume we consumed the onDeselect, and that the parent doesn't need to receive it
		return(false);
	}

	bool iDefaultCallback_onMoved(SWindow* win, SObject* obj, u32* xOverride_out, u32* yOverride_out)
	{
		// Assume we consumed the onDeselect, and that the parent doesn't need to receive it
		return(false);
	}

	bool iDefaultCallback_onQueryUnload(SWindow* win, SObject* obj)
	{
		// Assume we consumed the onDeselect, and that the parent doesn't need to receive it
		return(false);
	}

	bool iDefaultCallback_onAddObject(SWindow* win, SObject* obj)
	{
		// Assume we consumed the onDeselect, and that the parent doesn't need to receive it
		return(false);
	}

	bool iDefaultCallback_onAddProperty(SWindow* win, SObject* obj)
	{
		// Assume we consumed the onDeselect, and that the parent doesn't need to receive it
		return(false);
	}

	bool iDefaultCallback_onError(SWindow* win, SObject* obj)
	{
		// Assume we consumed the onDeselect, and that the parent doesn't need to receive it
		return(false);
	}

	bool iDefaultCallback_onScrolled(SWindow* win, SObject* obj)
	{
		// Assume we consumed the onDeselect, and that the parent doesn't need to receive it
		return(false);
	}
