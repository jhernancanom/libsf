//////////
//
// /libsf/source/vjr/source/objects/events.cpp
//
//////
//    _     _ _     _____ _____ 
//   | |   (_) |__ / ____|  ___|
//   | |   | | '_ \\___ \|  __|
//   | |___| | |_) |___) | |
//   |_____|_|_.__/_____/|_|
//
//   Liberty Software Foundation
// and the Village Freedom Project
//   __     _______     ____  
//   \ \   / /  ___| __|  _ \ 
//    \ \ / /| |_ | '__| |_) |
//     \ V / |  _|| |  |  __/ 
//      \_/  |_|  |_|  |_|
//
//////
// Version 0.56
// Copyright (c) 2014 by Rick C. Hodgin
//////
// Last update:
//     Jul.04.2014
//////
// Change log:
//     Jul.04.2014 - Initial creation
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
// onMouseMove
//////
	SVariable* varX_onMouseMove			= NULL;
	SVariable* varY_onMouseMove			= NULL;
	SVariable* varCtrl_onMouseMove		= NULL;
	SVariable* varAlt_onMouseMove		= NULL;
	SVariable* varShift_onMouseMove		= NULL;
	SVariable* varClick_onMouseMove		= NULL;


//////////
// onMouseDown
//////
	SVariable* varX_onMouseDown			= NULL;
	SVariable* varY_onMouseDown			= NULL;
	SVariable* varCtrl_onMouseDown		= NULL;
	SVariable* varAlt_onMouseDown		= NULL;
	SVariable* varShift_onMouseDown		= NULL;
	SVariable* varClick_onMouseDown		= NULL;


//////////
// onMouseClickEx
//////
	SVariable* varX_onMouseClickEx		= NULL;
	SVariable* varY_onMouseClickEx		= NULL;
	SVariable* varCtrl_onMouseClickEx	= NULL;
	SVariable* varAlt_onMouseClickEx	= NULL;
	SVariable* varShift_onMouseClickEx	= NULL;
	SVariable* varClick_onMouseClickEx	= NULL;


//////////
// onMouseUp
//////
	SVariable* varX_onMouseUp			= NULL;
	SVariable* varY_onMouseUp			= NULL;
	SVariable* varCtrl_onMouseUp		= NULL;
	SVariable* varAlt_onMouseUp			= NULL;
	SVariable* varShift_onMouseUp		= NULL;
	SVariable* varClick_onMouseUp		= NULL;


//////////
// onMouseWheel
//////
	SVariable* varX_onMouseWheel		= NULL;
	SVariable* varY_onMouseWheel		= NULL;
	SVariable* varCtrl_onMouseWheel		= NULL;
	SVariable* varAlt_onMouseWheel		= NULL;
	SVariable* varShift_onMouseWheel	= NULL;
	SVariable* varClick_onMouseWheel	= NULL;
	SVariable* varDeltaY_onMouseWheel	= NULL;


//////////
// onKeyDown
//////
	SVariable* varCtrl_onKeyDown		= NULL;
	SVariable* varAlt_onKeyDown			= NULL;
	SVariable* varShift_onKeyDown		= NULL;
	SVariable* varCaps_onKeyDown		= NULL;
	SVariable* varAsciiChar_onKeyDown	= NULL;
	SVariable* varVKey_onKeyDown		= NULL;
	SVariable* varIsCAS_onKeyDown		= NULL;
	SVariable* varIsAscii_onKeyDown		= NULL;


//////////
// onKeyUp
//////
	SVariable* varCtrl_onKeyUp			= NULL;
	SVariable* varAlt_onKeyUp			= NULL;
	SVariable* varShift_onKeyUp			= NULL;
	SVariable* varCaps_onKeyUp			= NULL;
	SVariable* varAsciiChar_onKeyUp		= NULL;
	SVariable* varVKey_onKeyUp			= NULL;
	SVariable* varIsCAS_onKeyUp			= NULL;
	SVariable* varIsAscii_onKeyUp		= NULL;




//////////
//
// Initialize the weakly typed events passed parameters
//
//////
	void iEvents_init(SThisCode* thisCode)
	{
		//////////
		// onMouseMove
		//////
			if (!varX_onMouseMove)				varX_onMouseMove		= iVariable_create(thisCode, _VAR_TYPE_S32,		NULL);
			if (!varY_onMouseMove)				varY_onMouseMove		= iVariable_create(thisCode, _VAR_TYPE_S32,		NULL);
			if (!varCtrl_onMouseMove)			varCtrl_onMouseMove		= iVariable_create(thisCode, _VAR_TYPE_LOGICAL,	NULL);
			if (!varAlt_onMouseMove)			varAlt_onMouseMove		= iVariable_create(thisCode, _VAR_TYPE_LOGICAL,	NULL);
			if (!varShift_onMouseMove)			varShift_onMouseMove	= iVariable_create(thisCode, _VAR_TYPE_LOGICAL,	NULL);
			if (!varClick_onMouseMove)			varClick_onMouseMove	= iVariable_create(thisCode, _VAR_TYPE_S32,		NULL);


		//////////
		// onMouseDown
		//////
			if (!varX_onMouseDown)				varX_onMouseDown		= iVariable_create(thisCode, _VAR_TYPE_S32,		NULL);
			if (!varY_onMouseDown)				varY_onMouseDown		= iVariable_create(thisCode, _VAR_TYPE_S32,		NULL);
			if (!varCtrl_onMouseDown)			varCtrl_onMouseDown		= iVariable_create(thisCode, _VAR_TYPE_LOGICAL,	NULL);
			if (!varAlt_onMouseDown)			varAlt_onMouseDown		= iVariable_create(thisCode, _VAR_TYPE_LOGICAL,	NULL);
			if (!varShift_onMouseDown)			varShift_onMouseDown	= iVariable_create(thisCode, _VAR_TYPE_LOGICAL,	NULL);
			if (!varClick_onMouseDown)			varClick_onMouseDown	= iVariable_create(thisCode, _VAR_TYPE_S32,		NULL);


		//////////
		// onMouseClickEx
		//////
			if (!varX_onMouseClickEx)			varX_onMouseClickEx		= iVariable_create(thisCode, _VAR_TYPE_S32,		NULL);
			if (!varY_onMouseClickEx)			varY_onMouseClickEx		= iVariable_create(thisCode, _VAR_TYPE_S32,		NULL);
			if (!varCtrl_onMouseClickEx)		varCtrl_onMouseClickEx	= iVariable_create(thisCode, _VAR_TYPE_LOGICAL,	NULL);
			if (!varAlt_onMouseClickEx)			varAlt_onMouseClickEx	= iVariable_create(thisCode, _VAR_TYPE_LOGICAL,	NULL);
			if (!varShift_onMouseClickEx)		varShift_onMouseClickEx	= iVariable_create(thisCode, _VAR_TYPE_LOGICAL,	NULL);
			if (!varClick_onMouseClickEx)		varClick_onMouseClickEx	= iVariable_create(thisCode, _VAR_TYPE_S32,		NULL);


		//////////
		// onMouseUp
		//////
			if (!varX_onMouseUp)				varX_onMouseUp			= iVariable_create(thisCode, _VAR_TYPE_S32,		NULL);
			if (!varY_onMouseUp)				varY_onMouseUp			= iVariable_create(thisCode, _VAR_TYPE_S32,		NULL);
			if (!varCtrl_onMouseUp)				varCtrl_onMouseUp		= iVariable_create(thisCode, _VAR_TYPE_LOGICAL,	NULL);
			if (!varAlt_onMouseUp)				varAlt_onMouseUp		= iVariable_create(thisCode, _VAR_TYPE_LOGICAL,	NULL);
			if (!varShift_onMouseUp)			varShift_onMouseUp		= iVariable_create(thisCode, _VAR_TYPE_LOGICAL,	NULL);
			if (!varClick_onMouseUp)			varClick_onMouseUp		= iVariable_create(thisCode, _VAR_TYPE_S32,		NULL);


		//////////
		// onMouseWheel
		//////
			if (!varX_onMouseWheel)				varX_onMouseWheel		= iVariable_create(thisCode, _VAR_TYPE_S32,		NULL);
			if (!varY_onMouseWheel)				varY_onMouseWheel		= iVariable_create(thisCode, _VAR_TYPE_S32,		NULL);
			if (!varCtrl_onMouseWheel)			varCtrl_onMouseWheel	= iVariable_create(thisCode, _VAR_TYPE_LOGICAL,	NULL);
			if (!varAlt_onMouseWheel)			varAlt_onMouseWheel		= iVariable_create(thisCode, _VAR_TYPE_LOGICAL,	NULL);
			if (!varShift_onMouseWheel)			varShift_onMouseWheel	= iVariable_create(thisCode, _VAR_TYPE_LOGICAL,	NULL);
			if (!varClick_onMouseWheel)			varClick_onMouseWheel	= iVariable_create(thisCode, _VAR_TYPE_S32,		NULL);
			if (!varDeltaY_onMouseWheel)		varDeltaY_onMouseWheel	= iVariable_create(thisCode, _VAR_TYPE_S32,		NULL);


		//////////
		// onKeyDown
		//////
			if (!varCtrl_onKeyDown)				varCtrl_onKeyDown		= iVariable_create(thisCode, _VAR_TYPE_LOGICAL,	NULL);
			if (!varAlt_onKeyDown)				varAlt_onKeyDown		= iVariable_create(thisCode, _VAR_TYPE_LOGICAL,	NULL);
			if (!varShift_onKeyDown)			varShift_onKeyDown		= iVariable_create(thisCode, _VAR_TYPE_LOGICAL,	NULL);
			if (!varCaps_onKeyDown)				varCaps_onKeyDown		= iVariable_create(thisCode, _VAR_TYPE_LOGICAL,	NULL);
			if (!varAsciiChar_onKeyDown)		varAsciiChar_onKeyDown	= iVariable_create(thisCode, _VAR_TYPE_U16,		NULL);
			if (!varVKey_onKeyDown)				varVKey_onKeyDown		= iVariable_create(thisCode, _VAR_TYPE_S16,		NULL);
			if (!varIsCAS_onKeyDown)			varIsCAS_onKeyDown		= iVariable_create(thisCode, _VAR_TYPE_LOGICAL,	NULL);
			if (!varIsAscii_onKeyDown)			varIsAscii_onKeyDown	= iVariable_create(thisCode, _VAR_TYPE_LOGICAL,	NULL);


		//////////
		// onKeyUp
		//////
			if (!varCtrl_onKeyUp)				varCtrl_onKeyUp			= iVariable_create(thisCode, _VAR_TYPE_LOGICAL,	NULL);
			if (!varAlt_onKeyUp)				varAlt_onKeyUp			= iVariable_create(thisCode, _VAR_TYPE_LOGICAL,	NULL);
			if (!varShift_onKeyUp)				varShift_onKeyUp		= iVariable_create(thisCode, _VAR_TYPE_LOGICAL,	NULL);
			if (!varCaps_onKeyUp)				varCaps_onKeyUp			= iVariable_create(thisCode, _VAR_TYPE_LOGICAL,	NULL);
			if (!varAsciiChar_onKeyUp)			varAsciiChar_onKeyUp	= iVariable_create(thisCode, _VAR_TYPE_U16,		NULL);
			if (!varVKey_onKeyUp)				varVKey_onKeyUp			= iVariable_create(thisCode, _VAR_TYPE_S16,		NULL);
			if (!varIsCAS_onKeyUp)				varIsCAS_onKeyUp		= iVariable_create(thisCode, _VAR_TYPE_LOGICAL,	NULL);
			if (!varIsAscii_onKeyUp)			varIsAscii_onKeyUp		= iVariable_create(thisCode, _VAR_TYPE_LOGICAL,	NULL);
	}




//////////
//
// Called to reset an object's events to its default
//
//////
	void iEvents_resetToDefault(SThisCode* thisCode, SEvents* ev)
	{
		SEventsGeneral*		g;
		SEventsMouse*		m;
		SEventsKeyboard*	k;


		// Make sure our environment is sane
		if (ev)
		{
			//////////
			// Grab our events
			//////
				g = &ev->general;
				m = &ev->mouse;
				k = &ev->keyboard;


			//////////
			// Reset general events
			//////
				*(uptr*)&g->onLoad					= (uptr)&iDefaultCallback_onLoad;
				*(uptr*)&g->onInit					= (uptr)&iDefaultCallback_onInit;
				*(uptr*)&g->onCreated				= (uptr)&iDefaultCallback_onCreated;
				*(uptr*)&g->onResize				= (uptr)&iDefaultCallback_onResize;
				*(uptr*)&g->onMoved					= (uptr)&iDefaultCallback_onMoved;
				*(uptr*)&g->onRender				= (uptr)&iDefaultCallback_onRender;
				*(uptr*)&g->onPublish				= (uptr)&iDefaultCallback_onPublish;
				*(uptr*)&g->onQueryUnload			= (uptr)&iDefaultCallback_onQueryUnload;
				*(uptr*)&g->onDestroy				= (uptr)&iDefaultCallback_onDestroy;
				*(uptr*)&g->onUnload				= (uptr)&iDefaultCallback_onUnload;
				*(uptr*)&g->onGotFocus				= (uptr)&iDefaultCallback_onGotFocus;
				*(uptr*)&g->onLostFocus				= (uptr)&iDefaultCallback_onLostFocus;
				*(uptr*)&g->onAddObject				= (uptr)&iDefaultCallback_onAddObject;
				*(uptr*)&g->onAddProperty			= (uptr)&iDefaultCallback_onAddProperty;
				*(uptr*)&g->onError					= (uptr)&iDefaultCallback_onError;
				*(uptr*)&g->onScrolled				= (uptr)&iDefaultCallback_onScrolled;
				*(uptr*)&g->activate				= (uptr)&iDefaultCallback_onActivate;
				*(uptr*)&g->deactivate				= (uptr)&iDefaultCallback_onDeactivate;
				*(uptr*)&g->onSelect				= (uptr)&iDefaultCallback_onSelect;
				*(uptr*)&g->onDeselect				= (uptr)&iDefaultCallback_onDeselect;
				*(uptr*)&g->onInteractiveChange		= (uptr)&iDefaultCallback_onInteractiveChange;
				*(uptr*)&g->onProgrammaticChange	= (uptr)&iDefaultCallback_onProgrammaticChange;
				*(uptr*)&g->onSetActiveControl		= (uptr)&iDefaultCallback_onSetActiveControl;
				*(uptr*)&g->onSpin					= (uptr)&iDefaultCallback_onSpin;
				*(uptr*)&g->onSpin					= (uptr)&iDefaultCallback_onSpin;


			//////////
			// Reset mouse events
			//////
				*(uptr*)&m->onMouseClickEx			= (uptr)&iDefaultCallback_onMouseClickEx;
				*(uptr*)&m->onMouseDblClickEx		= (uptr)&iDefaultCallback_onMouseDblClickEx;
				*(uptr*)&m->onMouseWheel			= (uptr)&iDefaultCallback_onMouseWheel;
				*(uptr*)&m->onMouseMove				= (uptr)&iDefaultCallback_onMouseMove;
				*(uptr*)&m->onMouseDown				= (uptr)&iDefaultCallback_onMouseDown;
				*(uptr*)&m->onMouseUp				= (uptr)&iDefaultCallback_onMouseUp;
				*(uptr*)&m->onMouseEnter			= (uptr)&iDefaultCallback_onMouseEnter;
				*(uptr*)&m->onMouseLeave			= (uptr)&iDefaultCallback_onMouseLeave;
				*(uptr*)&m->onMouseHover			= (uptr)&iDefaultCallback_onMouseHover;


			//////////
			// Reset keyboard events
			//////
				*(uptr*)&k->onKeyDown			= (uptr)&iDefaultCallback_onKeyDown;
				*(uptr*)&k->onKeyUp				= (uptr)&iDefaultCallback_onKeyUp;
		}
	}




//////////
//
// Called with strongly typed variables to dispatch the same event using weakly typed
// SVariable variables, so as to align with conventional source code processing.
//
//////
	bool iiEventDispatch_onMouseMove(SThisCode* thisCode, SEvents* ev, SWindow* win, SObject* obj, s32 x, s32 y, bool tlCtrl, bool tlAlt, bool tlShift, u32 tnClicks)
	{
		//////////
		// Prepare for dispatch
		//////
			iVariable_set_s32		(thisCode, varX_onMouseMove,		x);
			iVariable_set_s32		(thisCode, varY_onMouseMove,		y);
			iVariable_set_logical	(thisCode, varCtrl_onMouseMove,		((tlCtrl)	? _LOGICAL_TRUE : _LOGICAL_FALSE));
			iVariable_set_logical	(thisCode, varAlt_onMouseMove,		((tlAlt)	? _LOGICAL_TRUE : _LOGICAL_FALSE));
			iVariable_set_logical	(thisCode, varShift_onMouseMove,	((tlShift)	? _LOGICAL_TRUE : _LOGICAL_FALSE));
			iVariable_set_s32		(thisCode, varClick_onMouseMove,	tnClicks);


		//////////
		// Dispatch
		//////
			return(ev->mouse.onMouseMove(thisCode, win, obj,
													varX_onMouseMove,		varY_onMouseMove,
													varCtrl_onMouseMove,	varAlt_onMouseMove,		varShift_onMouseMove,
													varClick_onMouseMove));
	}




//////////
//
// Called with strongly typed variables to dispatch the same event using weakly typed
// SVariable variables, so as to align with conventional source code processing.
//
//////
	bool iiEventDispatch_onMouseDown(SThisCode* thisCode, SEvents* ev, SWindow* win, SObject* obj, s32 x, s32 y, bool tlCtrl, bool tlAlt, bool tlShift, u32 tnClicks)
	{
		//////////
		// Prepare for dispatch
		//////
			iVariable_set_s32		(thisCode, varX_onMouseDown,			x);
			iVariable_set_s32		(thisCode, varY_onMouseDown,			y);
			iVariable_set_logical	(thisCode, varCtrl_onMouseDown,			((tlCtrl)	? _LOGICAL_TRUE : _LOGICAL_FALSE));
			iVariable_set_logical	(thisCode, varAlt_onMouseDown,			((tlAlt)	? _LOGICAL_TRUE : _LOGICAL_FALSE));
			iVariable_set_logical	(thisCode, varShift_onMouseDown,		((tlShift)	? _LOGICAL_TRUE : _LOGICAL_FALSE));
			iVariable_set_s32		(thisCode, varClick_onMouseDown,		tnClicks);


		//////////
		// Dispatch
		//////
			return(ev->mouse.onMouseDown(thisCode, win, obj,
													varX_onMouseDown,			varY_onMouseDown,
													varCtrl_onMouseDown,		varAlt_onMouseDown,		varShift_onMouseDown,
													varClick_onMouseDown));
	}




//////////
//
// Called with strongly typed variables to dispatch the same event using weakly typed
// SVariable variables, so as to align with conventional source code processing.
//
//////
	bool iiEventDispatch_onMouseClickEx(SThisCode* thisCode, SEvents* ev, SWindow* win, SObject* obj, s32 x, s32 y, bool tlCtrl, bool tlAlt, bool tlShift, u32 tnClicks)
	{
		//////////
		// Prepare for dispatch
		//////
			iVariable_set_s32		(thisCode, varX_onMouseClickEx,			x);
			iVariable_set_s32		(thisCode, varY_onMouseClickEx,			y);
			iVariable_set_logical	(thisCode, varCtrl_onMouseClickEx,		((tlCtrl)	? _LOGICAL_TRUE : _LOGICAL_FALSE));
			iVariable_set_logical	(thisCode, varAlt_onMouseClickEx,		((tlAlt)	? _LOGICAL_TRUE : _LOGICAL_FALSE));
			iVariable_set_logical	(thisCode, varShift_onMouseClickEx,		((tlShift)	? _LOGICAL_TRUE : _LOGICAL_FALSE));
			iVariable_set_s32		(thisCode, varClick_onMouseClickEx,		tnClicks);


		//////////
		// Dispatch
		//////
			return(ev->mouse.onMouseClickEx(thisCode, win, obj,
														varX_onMouseClickEx,		varY_onMouseClickEx,
														varCtrl_onMouseClickEx,		varAlt_onMouseClickEx,		varShift_onMouseClickEx,
														varClick_onMouseClickEx));
	}




//////////
//
// Called with strongly typed variables to dispatch the same event using weakly typed
// SVariable variables, so as to align with conventional source code processing.
//
//////
	bool iiEventDispatch_onMouseUp(SThisCode* thisCode, SEvents* ev, SWindow* win, SObject* obj, s32 x, s32 y, bool tlCtrl, bool tlAlt, bool tlShift, u32 tnClicks)
	{
		//////////
		// Prepare for dispatch
		//////
			iVariable_set_s32		(thisCode, varX_onMouseUp,			x);
			iVariable_set_s32		(thisCode, varY_onMouseUp,			y);
			iVariable_set_logical	(thisCode, varCtrl_onMouseUp,		((tlCtrl)	? _LOGICAL_TRUE : _LOGICAL_FALSE));
			iVariable_set_logical	(thisCode, varAlt_onMouseUp,		((tlAlt)	? _LOGICAL_TRUE : _LOGICAL_FALSE));
			iVariable_set_logical	(thisCode, varShift_onMouseUp,		((tlShift)	? _LOGICAL_TRUE : _LOGICAL_FALSE));
			iVariable_set_s32		(thisCode, varClick_onMouseUp,		tnClicks);


		//////////
		// Dispatch
		//////
			return(ev->mouse.onMouseUp(thisCode, win, obj,
													varX_onMouseUp,			varY_onMouseUp,
													varCtrl_onMouseUp,		varAlt_onMouseUp,		varShift_onMouseUp,
													varClick_onMouseUp));
	}




//////////
//
// Called with strongly typed variables to dispatch the same event using weakly typed
// SVariable variables, so as to align with conventional source code processing.
//
//////
	bool iiEventDispatch_onMouseWheel(SThisCode* thisCode, SEvents* ev, SWindow* win, SObject* obj, s32 x, s32 y, bool tlCtrl, bool tlAlt, bool tlShift, u32 tnClicks, s32 tnDeltaY)
	{
		//////////
		// Prepare for dispatch
		//////
			iVariable_set_s32		(thisCode, varX_onMouseWheel,			x);
			iVariable_set_s32		(thisCode, varY_onMouseWheel,			y);
			iVariable_set_logical	(thisCode, varCtrl_onMouseWheel,		((tlCtrl)	? _LOGICAL_TRUE : _LOGICAL_FALSE));
			iVariable_set_logical	(thisCode, varAlt_onMouseWheel,			((tlAlt)	? _LOGICAL_TRUE : _LOGICAL_FALSE));
			iVariable_set_logical	(thisCode, varShift_onMouseWheel,		((tlShift)	? _LOGICAL_TRUE : _LOGICAL_FALSE));
			iVariable_set_s32		(thisCode, varClick_onMouseWheel,		tnClicks);
			iVariable_set_s32		(thisCode, varDeltaY_onMouseWheel,		tnDeltaY);


		//////////
		// Dispatch
		//////
			return(ev->mouse.onMouseWheel(thisCode, win, obj,
														varX_onMouseWheel,			varY_onMouseWheel,
														varCtrl_onMouseWheel,		varAlt_onMouseWheel,	varShift_onMouseWheel,
														varClick_onMouseWheel,
														varDeltaY_onMouseWheel));
	}




//////////
//
// Called with strongly typed variables to dispatch the same event using weakly typed
// SVariable variables, so as to align with conventional source code processing.
//
//////
	bool iiEventDispatch_onKeyDown(SThisCode* thisCode, SEvents* ev, SWindow* win, SObject* obj, bool tlCtrl, bool tlAlt, bool tlShift, bool tlCaps, u16 tnAsciiChar, u16 tvKey, bool tlIsCAS, bool tlIsAscii)
	{
		//////////
		// Prepare for dispatch
		//////
			iVariable_set_logical	(thisCode, varCtrl_onKeyDown,			((tlCtrl)		? _LOGICAL_TRUE : _LOGICAL_FALSE));
			iVariable_set_logical	(thisCode, varAlt_onKeyDown,			((tlAlt)		? _LOGICAL_TRUE : _LOGICAL_FALSE));
			iVariable_set_logical	(thisCode, varShift_onKeyDown,			((tlShift)		? _LOGICAL_TRUE : _LOGICAL_FALSE));
			iVariable_set_logical	(thisCode, varCaps_onKeyDown,			((tlCaps)		? _LOGICAL_TRUE : _LOGICAL_FALSE));
			iVariable_set_u16		(thisCode, varAsciiChar_onKeyDown,		tnAsciiChar);
			iVariable_set_s16		(thisCode, varVKey_onKeyDown,			tvKey);
			iVariable_set_logical	(thisCode, varIsCAS_onKeyDown,			((tlIsCAS)		? _LOGICAL_TRUE : _LOGICAL_FALSE));
			iVariable_set_logical	(thisCode, varIsAscii_onKeyDown,		((tlIsAscii)	? _LOGICAL_TRUE : _LOGICAL_FALSE));


		//////////
		// Dispatch
		//////
			return(ev->keyboard.onKeyDown(thisCode, win, obj,
													varCtrl_onKeyDown,		varAlt_onKeyDown,			varShift_onKeyDown,
													varCaps_onKeyDown,		varAsciiChar_onKeyDown,		varVKey_onKeyDown,
													varIsCAS_onKeyDown,		varIsAscii_onKeyDown));
	}




//////////
//
// Called with strongly typed variables to dispatch the same event using weakly typed
// SVariable variables, so as to align with conventional source code processing.
//
//////
	bool iiEventDispatch_onKeyUp(SThisCode* thisCode, SEvents* ev, SWindow* win, SObject* obj, bool tlCtrl, bool tlAlt, bool tlShift, bool tlCaps, u16 tnAsciiChar, u16 tvKey, bool tlIsCAS, bool tlIsAscii)
	{
		//////////
		// Prepare for dispatch
		//////
			iVariable_set_logical	(thisCode, varCtrl_onKeyUp,			((tlCtrl)		? _LOGICAL_TRUE : _LOGICAL_FALSE));
			iVariable_set_logical	(thisCode, varAlt_onKeyUp,			((tlAlt)		? _LOGICAL_TRUE : _LOGICAL_FALSE));
			iVariable_set_logical	(thisCode, varShift_onKeyUp,		((tlShift)		? _LOGICAL_TRUE : _LOGICAL_FALSE));
			iVariable_set_logical	(thisCode, varCaps_onKeyUp,			((tlCaps)		? _LOGICAL_TRUE : _LOGICAL_FALSE));
			iVariable_set_u16		(thisCode, varAsciiChar_onKeyUp,	tnAsciiChar);
			iVariable_set_s16		(thisCode, varVKey_onKeyUp,			tvKey);
			iVariable_set_logical	(thisCode, varIsCAS_onKeyUp,		((tlIsCAS)		? _LOGICAL_TRUE : _LOGICAL_FALSE));
			iVariable_set_logical	(thisCode, varIsAscii_onKeyUp,		((tlIsAscii)	? _LOGICAL_TRUE : _LOGICAL_FALSE));


		//////////
		// Dispatch
		//////
			return(ev->keyboard.onKeyUp(thisCode, win, obj,
													varCtrl_onKeyUp,		varAlt_onKeyUp,				varShift_onKeyUp,
													varCaps_onKeyUp,		varAsciiChar_onKeyUp,		varVKey_onKeyUp,
													varIsCAS_onKeyUp,		varIsAscii_onKeyUp));
	}
