//////////
//
// /libsf/source/vjr/objects/events.cpp
//
//////
// Version 0.54
// Copyright (c) 2014 by Rick C. Hodgin
//////
// Last update:
//     Jul.04.2014
//////
// Change log:
//     Jul.04.2014 - Initial creation
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




void iEvents_resetToDefault(SEvents* ev)
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
			*(u32*)&g->onLoad				= (uptr)&iDefaultCallback_onLoad;
			*(u32*)&g->onInit				= (uptr)&iDefaultCallback_onInit;
			*(u32*)&g->onCreated			= (uptr)&iDefaultCallback_onCreated;
			*(u32*)&g->onResize				= (uptr)&iDefaultCallback_onResize;
			*(u32*)&g->onMoved				= (uptr)&iDefaultCallback_onMoved;
			*(u32*)&g->onRender				= (uptr)&iDefaultCallback_onRender;
			*(u32*)&g->onPublish			= (uptr)&iDefaultCallback_onPublish;
			*(u32*)&g->onQueryUnload		= (uptr)&iDefaultCallback_onQueryUnload;
			*(u32*)&g->onDestroy			= (uptr)&iDefaultCallback_onDestroy;
			*(u32*)&g->onUnload				= (uptr)&iDefaultCallback_onUnload;
			*(u32*)&g->onGotFocus			= (uptr)&iDefaultCallback_onGotFocus;
			*(u32*)&g->onLostFocus			= (uptr)&iDefaultCallback_onLostFocus;
			*(u32*)&g->onAddObject			= (uptr)&iDefaultCallback_onAddObject;
			*(u32*)&g->onAddProperty		= (uptr)&iDefaultCallback_onAddProperty;
			*(u32*)&g->onError				= (uptr)&iDefaultCallback_onError;
			*(u32*)&g->onScrolled			= (uptr)&iDefaultCallback_onScrolled;
			*(u32*)&g->activate				= (uptr)&iDefaultCallback_onActivate;
			*(u32*)&g->deactivate			= (uptr)&iDefaultCallback_onDeactivate;
			*(u32*)&g->onSelect				= (uptr)&iDefaultCallback_onSelect;
			*(u32*)&g->onDeselect			= (uptr)&iDefaultCallback_onDeselect;
			*(u32*)&g->onInteractiveChange	= (uptr)&iDefaultCallback_onInteractiveChange;
			*(u32*)&g->onProgrammaticChange	= (uptr)&iDefaultCallback_onProgrammaticChange;


		//////////
		// Reset mouse events
		//////
			*(u32*)&m->onMouseClickEx		= (uptr)&iDefaultCallback_onMouseClickEx;
			*(u32*)&m->onMouseDblClickEx	= (uptr)&iDefaultCallback_onMouseDblClickEx;
			*(u32*)&m->onMouseWheel			= (uptr)&iDefaultCallback_onMouseWheel;
			*(u32*)&m->onMouseMove			= (uptr)&iDefaultCallback_onMouseMove;
			*(u32*)&m->onMouseDown			= (uptr)&iDefaultCallback_onMouseDown;
			*(u32*)&m->onMouseUp			= (uptr)&iDefaultCallback_onMouseUp;
			*(u32*)&m->onMouseEnter			= (uptr)&iDefaultCallback_onMouseEnter;
			*(u32*)&m->onMouseLeave			= (uptr)&iDefaultCallback_onMouseLeave;
			*(u32*)&m->onMouseHover			= (uptr)&iDefaultCallback_onMouseHover;


		//////////
		// Reset keyboard events
		//////
			*(u32*)&k->onKeyDown			= (uptr)&iDefaultCallback_onKeyDown;
			*(u32*)&k->onKeyUp				= (uptr)&iDefaultCallback_onKeyUp;
	}
}
