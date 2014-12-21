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
			*(uptr*)&g->onLoad				= (uptr)&iDefaultCallback_onLoad;
			*(uptr*)&g->onInit				= (uptr)&iDefaultCallback_onInit;
			*(uptr*)&g->onCreated			= (uptr)&iDefaultCallback_onCreated;
			*(uptr*)&g->onResize				= (uptr)&iDefaultCallback_onResize;
			*(uptr*)&g->onMoved				= (uptr)&iDefaultCallback_onMoved;
			*(uptr*)&g->onRender				= (uptr)&iDefaultCallback_onRender;
			*(uptr*)&g->onPublish			= (uptr)&iDefaultCallback_onPublish;
			*(uptr*)&g->onQueryUnload		= (uptr)&iDefaultCallback_onQueryUnload;
			*(uptr*)&g->onDestroy			= (uptr)&iDefaultCallback_onDestroy;
			*(uptr*)&g->onUnload				= (uptr)&iDefaultCallback_onUnload;
			*(uptr*)&g->onGotFocus			= (uptr)&iDefaultCallback_onGotFocus;
			*(uptr*)&g->onLostFocus			= (uptr)&iDefaultCallback_onLostFocus;
			*(uptr*)&g->onAddObject			= (uptr)&iDefaultCallback_onAddObject;
			*(uptr*)&g->onAddProperty		= (uptr)&iDefaultCallback_onAddProperty;
			*(uptr*)&g->onError				= (uptr)&iDefaultCallback_onError;
			*(uptr*)&g->onScrolled			= (uptr)&iDefaultCallback_onScrolled;
			*(uptr*)&g->activate				= (uptr)&iDefaultCallback_onActivate;
			*(uptr*)&g->deactivate			= (uptr)&iDefaultCallback_onDeactivate;
			*(uptr*)&g->onSelect				= (uptr)&iDefaultCallback_onSelect;
			*(uptr*)&g->onDeselect			= (uptr)&iDefaultCallback_onDeselect;
			*(uptr*)&g->onInteractiveChange	= (uptr)&iDefaultCallback_onInteractiveChange;
			*(uptr*)&g->onProgrammaticChange	= (uptr)&iDefaultCallback_onProgrammaticChange;


		//////////
		// Reset mouse events
		//////
			*(uptr*)&m->onMouseClickEx		= (uptr)&iDefaultCallback_onMouseClickEx;
			*(uptr*)&m->onMouseDblClickEx	= (uptr)&iDefaultCallback_onMouseDblClickEx;
			*(uptr*)&m->onMouseWheel			= (uptr)&iDefaultCallback_onMouseWheel;
			*(uptr*)&m->onMouseMove			= (uptr)&iDefaultCallback_onMouseMove;
			*(uptr*)&m->onMouseDown			= (uptr)&iDefaultCallback_onMouseDown;
			*(uptr*)&m->onMouseUp			= (uptr)&iDefaultCallback_onMouseUp;
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
