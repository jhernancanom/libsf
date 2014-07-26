//////////
//
// /libsf/source/vjr/callbacks.cpp
//
//////
// Version 0.34
// Copyright (c) 2014 by Rick C. Hodgin
//////
// Last update:
//     Jun.15.2014
//////
// Change log:
//     Jun.15.2014 - Initial creation
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

	bool iDefaultCallback_onMouseWheel(SWindow* win, SObject* obj, s32 tnUnits)
	{
		// Assume we consumed the mouse wheel, and that the parent doesn't need to receive it
		return(false);
	}

	bool iDefaultCallback_onMouseMove(SWindow* win, SObject* obj, s32 x, s32 y, bool tlCtrl, bool tlAlt, bool tlShift, u32 tnClick)
	{
		// Assume we consumed the mouse move, and that the parent doesn't need to receive it
		return(false);
	}

	bool iDefaultCallback_onMouseDown(SWindow* win, SObject* obj, s32 x, s32 y, bool tlCtrl, bool tlAlt, bool tlShift, u32 tnClick)
	{
		// Assume we consumed the mouse down event, and that the parent doesn't need to receive it
		return(false);
	}

	bool iDefaultCallback_onMouseUp(SWindow* win, SObject* obj, s32 x, s32 y, bool tlCtrl, bool tlAlt, bool tlShift, u32 tnClick)
	{
		// Assume we consumed the mosue up event, and that the parent doesn't need to receive it
		return(false);
	}

	bool iDefaultCallback_onMouseEnter(SWindow* win, SObject* obj)
	{
		// Assume we consumed the enter, and that the parent doesn't need to receive it
		return(false);
	}

	bool iDefaultCallback_onMouseLeave(SWindow* win, SObject* obj)
	{
		// Assume we consumed the leave, and that the parent doesn't need to receive it
		return(false);
	}

	bool iDefaultCallback_onMouseHover(SWindow* win, SObject* obj, s32 x, s32 y, bool tlCtrl, bool tlAlt, bool tlShift, u32 tnClick)
	{
		// Assume we consumed the hover, and that the parent doesn't need to receive it
		return(false);
	}

	bool iDefaultCallback_onKeyDown(SWindow* win, SObject* obj, bool tlCtrl, bool tlAlt, bool tlShift, s16 tcAscii, u16 tnVKey, bool tlIsCAS, bool tlIsAscii)
	{
		// Assume we consumed the keydown, and that the parent doesn't need to receive it
		return(false);
	}

	bool iDefaultCallback_onKeyUp(SWindow* win, SObject* obj, bool tlCtrl, bool tlAlt, bool tlShift, s16 tcAscii, u16 tnVKey, bool tlIsCAS, bool tlIsAscii)
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
