//////////
//
// /libsf/source/vjr/source/vjr_sup.cpp
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
// Creates the message window used for communicating actions
//
//////
	void iInit_createMessageWindow(void)
	{
		ATOM			atom;
		WNDCLASSEXA		classa;


		//////////
		// Register the classes if need be
		//////
			while (1)
			{
				if (!GetClassInfoExA(ghInstance, (cs8*)cgcMessageWindowClass, &classa))
				{
					// Initialize
					memset(&classa, 0, sizeof(classa));

					// Populate
					classa.cbSize				= sizeof(WNDCLASSEXA);
					classa.hInstance			= ghInstance;
					classa.lpszClassName		= (cs8*)cgcMessageWindowClass;
					classa.lpfnWndProc			= &iWindow_wndProcMessage;

					// Register
					atom = RegisterClassExA(&classa);
					if (!atom)
						break;
				}



			//////////
			// Create the message window
			//////
				ghwndMsg = CreateWindowA((cs8*)cgcMessageWindowClass, (cs8*)cgcMessageWindowClass, 0, 0, 0, 0, 0, HWND_MESSAGE, NULL, ghInstance, 0);
				if (ghwndMsg)
				{
					// Create a timer for the message window firing 20x per second
					SetTimer(ghwndMsg, 0, 50, NULL);

					// Read events
					CreateThread(NULL, 0, &iReadEvents_messageWindow, 0, 0, 0);
					return;
				}
				break;
			}
			// We should never get here
			MessageBoxA(NULL, "Error creating Visual FreePro Jr's message window.", "VJr - Fatal Error", MB_OK);
	}




//////////
//
// In order for a window pointer to be valid, it must be in the range gWindows->data to
// gWindows->data + gWindows->populatedLength.
//
//////
	bool isValidWindow(uptr tnWindowPtr)
	{
// TODO:  We may need to add a module test here to make sure the ((tnWindowPtr - gsWindows) % sizeof(SWindow)) == 0
		return(tnWindowPtr >= gWindows->_data && tnWindowPtr < (gWindows->_data + gWindows->populatedLength));
	}




//////////
//
// Thread to handle message window events
//
//////
	DWORD WINAPI iReadEvents_messageWindow(LPVOID lpParameter)
	{
		MSG msg;


		// Read until the message window goes bye bye
		while (GetMessage(&msg, ghwndMsg, 0, 0) > 0)
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		// When we get here, we're shutting down
		return 0;
	}




//////////
//
// Processes internal messages to process things internally.
//
//////
	LRESULT CALLBACK iWindow_wndProcMessage(HWND hwnd, UINT msg, WPARAM w, LPARAM l)
	{
		u32			lnI;
		MSG			msgPeek;
		SWindow*	win;


		// Call Windows' default procedure handler
		switch (msg)
		{
			case WM_TIMER:
				// See if any windows need to receive this message
				for (lnI = 0; lnI < gWindows->populatedLength; lnI += sizeof(SWindow))
				{
					// Grab this one
					win = (SWindow*)(gWindows->data_u8 + lnI);

					// If it's in use, and it's moving or resizing, send it this message
					if (win->isValid && (win->isMoving || win->isResizing))
					{
						// Send the message if there isn't already one of these messages in the queue
						if (!PeekMessage(&msgPeek, win->hwnd, WM_TIMER, WM_TIMER, PM_NOREMOVE))
							PostMessage(win->hwnd, WM_TIMER, 0, 0);		// Not in queue, send it
					}
				}
				// Indicate we processed it
				return 0;
				break;
		}
		return(DefWindowProc(hwnd, msg, w, l));
	}




//////////
//
// Loads the default settings for each object, populating them in turn.
//
//////
	void iInit_createDefaultObjects(void)
	{
		//////////
		// Create each default object
		//////
			gobj_defaultEmpty		= iObj_create(_OBJ_TYPE_EMPTY,		NULL);
			gobj_defaultLabel		= iObj_create(_OBJ_TYPE_LABEL,		NULL);
			gobj_defaultTextbox		= iObj_create(_OBJ_TYPE_TEXTBOX,	NULL);
			gobj_defaultButton		= iObj_create(_OBJ_TYPE_BUTTON,		NULL);
			gobj_defaultImage		= iObj_create(_OBJ_TYPE_IMAGE,		NULL);
			gobj_defaultCheckbox	= iObj_create(_OBJ_TYPE_CHECKBOX,	NULL);
			// Option and radio both have label controls within
			gobj_defaultOption		= iObj_create(_OBJ_TYPE_OPTION,		NULL);
			gobj_defaultRadio		= iObj_create(_OBJ_TYPE_RADIO,		NULL);
			// Forms and subforms are created last because they have internal child objects references to classes which must be created before
			gobj_defaultForm		= iObj_create(_OBJ_TYPE_FORM,		NULL);
			gobj_defaultSubform		= iObj_create(_OBJ_TYPE_SUBFORM,	NULL);
	}




//////////
//
// Temporary manual function to create the new JDebi screen.
//
//////
	void iInit_create_jdebi(void)
	{
		s32			lnLeft, lnTop, lnWidth, lnHeight;
		RECT		lrc;


		//////////
		// Create the object and its sub-objects
		//////
			// Create object
			_jdebi = iObj_create(_OBJ_TYPE_FORM, NULL);
			if (!_jdebi)
				return;

			// Set the app icon and enable the border
			propSetPictureBmp(_jdebi, bmpJDebiIcon);
			propSetBorderStyle(_jdebi, _BORDER_STYLE_FIXED);

			// Give it a fixed point font
			_jdebi->p.font = iFont_create(cgcFontName_defaultFixed, 10, FW_MEDIUM, false, false);


		//////////
		// Size it to just under half the screen initially
		//////
			GetWindowRect(GetDesktopWindow(), &lrc);
			lnWidth		= (lrc.right - lrc.left);
			lnHeight	= (lrc.bottom - lrc.top);

		
		//////////
		// Size and position it
		//////
			lnLeft		= (lrc.right  - lrc.left) / 32;
			lnTop		= (lrc.bottom - lrc.top)  / 32;
			lnWidth		-= (2 * lnLeft);
			lnHeight	-= (2 * lnTop);
			iObj_setSize(_jdebi, lnLeft, lnTop, lnWidth, lnHeight);


		//////////
		// Create the subforms
		//////
			sourceCode		= iObj_addChild(_OBJ_TYPE_SUBFORM, _jdebi);
			locals			= iObj_addChild(_OBJ_TYPE_SUBFORM, _jdebi);
			watch			= iObj_addChild(_OBJ_TYPE_SUBFORM, _jdebi);
			command			= iObj_addChild(_OBJ_TYPE_SUBFORM, _jdebi);
			debug			= iObj_addChild(_OBJ_TYPE_SUBFORM, _jdebi);
			output			= iObj_addChild(_OBJ_TYPE_SUBFORM, _jdebi);
			sourceLight		= iObj_addChild(_OBJ_TYPE_SUBFORM, _jdebi);
			_screen			= iObj_addChild(_OBJ_TYPE_SUBFORM, _jdebi);

			// Set the icons
			propSetIcon(sourceCode,		bmpSourceCodeIcon);
			propSetIcon(locals,			bmpLocalsIcon);
			propSetIcon(watch,			bmpWatchIcon);
			propSetIcon(command,		bmpCommandIcon);
			propSetIcon(debug,			bmpDebugIcon);
			propSetIcon(output,			bmpOutputIcon);
			propSetIcon(sourceLight,	bmpSourceLightIcon);
			propSetIcon(_screen,		bmpVjrIcon);
			propSetIcon(_jdebi,			bmpJDebiIcon);

			// Make them visible
			propSetVisible(sourceCode,	_LOGICAL_TRUE);
			propSetVisible(locals,		_LOGICAL_TRUE);
			propSetVisible(watch,		_LOGICAL_TRUE);
			propSetVisible(command,		_LOGICAL_TRUE);
			propSetVisible(sourceLight,	_LOGICAL_TRUE);
			propSetVisible(_screen,		_LOGICAL_TRUE);


		//////////
		// Position and size each window
		//////
			lnWidth		= (_jdebi->rcClient.right - _jdebi->rcClient.left) / 8;
			lnHeight	= (_jdebi->rcClient.bottom - _jdebi->rcClient.top) / 8;
			iObj_setSize(sourceCode,	0,						0,							5 * lnWidth,																6 * lnHeight);
			iObj_setSize(locals,		sourceCode->rc.right,	0,							lnWidth * 3 / 2,															2 * lnHeight);
			iObj_setSize(watch,			locals->rc.right,		0,							(_jdebi->rcClient.right - _jdebi->rcClient.left) - locals->rc.right,		2 * lnHeight);
			iObj_setSize(command,		0,						sourceCode->rc.bottom,		5 * lnWidth,																(_jdebi->rcClient.bottom - _jdebi->rcClient.top) - sourceCode->rc.bottom);
			iObj_setSize(sourceLight,	sourceCode->rc.right,	watch->rc.bottom,			(_jdebi->rcClient.right - _jdebi->rcClient.left) - sourceCode->rc.right,	2 * lnHeight);
			iObj_setSize(_screen,		sourceCode->rc.right,	sourceLight->rc.bottom,		(_jdebi->rcClient.right - _jdebi->rcClient.left) - sourceCode->rc.right,	(_jdebi->rcClient.bottom - _jdebi->rcClient.top) - sourceLight->rc.bottom);

			// These are created, but they are not visible
// 			iObj_setSize(debug,			command->rc.right,		watch->rc.bottom,			(sourceCode->rc.right - command->rc.right) / 2,									(_jdebi->rcClient.bottom - _jdebi->rcClient.top) - watch->rc.bottom);
// 			iObj_setSize(output,		debug->rc.right,		watch->rc.bottom,			sourceCode->rc.right - debug->rc.right,											(_jdebi->rcClient.bottom - _jdebi->rcClient.top) - watch->rc.bottom);

		//////////
		// Add the editbox controls to the subforms
		//////
			sourceCode_editbox	= iObj_addChild(_OBJ_TYPE_EDITBOX,	sourceCode);
			locals_editbox		= iObj_addChild(_OBJ_TYPE_EDITBOX,	locals);
			watch_editbox		= iObj_addChild(_OBJ_TYPE_EDITBOX,	watch);
			command_editbox		= iObj_addChild(_OBJ_TYPE_EDITBOX,	command);
			debug_editbox		= iObj_addChild(_OBJ_TYPE_EDITBOX,	debug);
			output_editbox		= iObj_addChild(_OBJ_TYPE_EDITBOX,	output);
			screen_editbox		= iObj_addChild(_OBJ_TYPE_EDITBOX,	_screen);
			sourceLight_empty	= iObj_addChild(_OBJ_TYPE_EMPTY,	sourceLight);


		//////////
		// Add the editbox controls to the subforms
		//////
			propSetVisible(sourceCode_editbox,	_LOGICAL_TRUE);
			propSetVisible(locals_editbox,		_LOGICAL_TRUE);
			propSetVisible(watch_editbox,		_LOGICAL_TRUE);
			propSetVisible(command_editbox,		_LOGICAL_TRUE);
			propSetVisible(debug_editbox,		_LOGICAL_TRUE);
			propSetVisible(output_editbox,		_LOGICAL_TRUE);
			propSetVisible(screen_editbox,		_LOGICAL_TRUE);
			propSetVisible(sourceLight_empty,	_LOGICAL_TRUE);


		//////////
		// Position and size each control
		//////
			lnHeight = (_jdebi->rcClient.bottom - _jdebi->rcClient.top) / 8;
			iObj_setSize(sourceCode_editbox,	48,	24,		sourceCode->rcClient.right	- sourceCode->rcClient.left - 48,	sourceCode->rcClient.bottom		- sourceCode->rcClient.top - 24);
			iObj_setSize(locals_editbox,		8,	0,		locals->rcClient.right		- locals->rcClient.left - 8,		locals->rcClient.bottom			- locals->rcClient.top);
			iObj_setSize(watch_editbox,			8,	0,		watch->rcClient.right		- watch->rcClient.left - 8,			watch->rcClient.bottom			- watch->rcClient.top);
			iObj_setSize(command_editbox,		8,	0,		command->rcClient.right		- command->rcClient.left - 8,		command->rcClient.bottom		- command->rcClient.top);
			iObj_setSize(debug_editbox,			8,	0,		debug->rcClient.right		- debug->rcClient.left - 8,			debug->rcClient.bottom			- debug->rcClient.top);
			iObj_setSize(output_editbox,		8,	0,		output->rcClient.right		- output->rcClient.left - 8,		output->rcClient.bottom			- output->rcClient.top);
			iObj_setSize(screen_editbox,		8,	0,		_screen->rcClient.right		- _screen->rcClient.left - 8,		_screen->rcClient.bottom		- _screen->rcClient.top);
			iObj_setSize(sourceLight_empty,		0,	0,		sourceLight->rcClient.right	- sourceLight->rcClient.left,		sourceLight->rcClient.bottom	- sourceLight->rcClient.top);


		//////////
		// Give it a caption
		//////
			propSetCaption(_jdebi, cgcJDebiTitle);


		//////////
		// SourceCode window caption and font
		//////
			propSetBackStyle(sourceCode, _BACK_STYLE_TRANSPARENT);
			propSetCaption(sourceCode, cgcSourceCodeTitle);

			// Adjust the caption width
			((SObject*)sourceCode->firstChild->ll.next)->rc.right = 90;

			sourceCode_editbox->p.font					= iFont_create(cgcFontName_defaultFixed, 10, FW_MEDIUM, false, false);
			sourceCode_editbox->ev.keyboard._onKeyDown	= (uptr)&iSEM_onKeyDown_sourceCode;
			propSetBorderStyle(sourceCode_editbox, _BORDER_STYLE_FIXED);
			propSetBorderColor(sourceCode_editbox, lineNumberBackColor);
			sourceCode_editbox->p.sem->showCursorLine	= true;
			sourceCode_editbox->p.sem->isSourceCode		= true;
			sourceCode_editbox->p.sem->showLineNumbers	= true;


		//////////
		// Locals window caption and font
		//////
// TODO:  Working here...
			iObjProp_set_character_direct(locals, _INDEX_CAPTION, cgcLocalsTitle, sizeof(cgcLocalsTitle) - 1);
			locals_editbox->p.font					= iFont_create(cgcFontName_defaultFixed, 10, FW_MEDIUM, false, false);
			locals_editbox->ev.keyboard._onKeyDown	= (uptr)&iSEM_onKeyDown;

			// Adjust the caption width
			((SObject*)locals->firstChild->ll.next)->rc.right = 65;


		//////////
		// Watch window caption and font
		//////
			iObjProp_set_character_direct(watch, _INDEX_CAPTION, cgcWatchTitle, sizeof(cgcWatchTitle) - 1);
			watch_editbox->p.font					= iFont_create(cgcFontName_defaultFixed, 10, FW_MEDIUM, false, false);
			watch_editbox->ev.keyboard._onKeyDown	= (uptr)&iSEM_onKeyDown;
			watch_editbox->p.sem->showCursorLine		= true;

			// Adjust the caption width
			((SObject*)watch->firstChild->ll.next)->rc.right = 65;


		//////////
		// Command window caption and font
		//////
			iObjProp_set_character_direct(command, _INDEX_CAPTION, cgcCommandTitle, sizeof(cgcCommandTitle) - 1);
			command_editbox->p.font					= iFont_create(cgcFontName_defaultFixed, 10, FW_MEDIUM, false, false);
			command_editbox->ev.keyboard._onKeyDown		= (uptr)&iSEM_onKeyDown_sourceCode;
			command_editbox->p.hasFocus					= true;
			command_editbox->p.sem->showCursorLine		= true;
			command_editbox->p.sem->isSourceCode			= true;
			command_editbox->p.sem->showLineNumbers		= true;

			// Adjust the caption width
			((SObject*)command->firstChild->ll.next)->rc.right = 80;


		//////////
		// Debug window caption and font
		//////
			iObjProp_set_character_direct(debug, _INDEX_CAPTION, cgcDebugTitle, sizeof(cgcDebugTitle) - 1);
			debug_editbox->p.font					= iFont_create(cgcFontName_defaultFixed, 10, FW_MEDIUM, false, false);
			debug_editbox->ev.keyboard._onKeyDown	= (uptr)&iSEM_onKeyDown;
			debug_editbox->p.sem->showCursorLine		= true;

			// Adjust the caption width
			((SObject*)debug->firstChild->ll.next)->rc.right = 65;


		//////////
		// Output window caption and font
		//////
			iObjProp_set_character_direct(output, _INDEX_CAPTION, cgcOutputTitle, sizeof(cgcOutputTitle) - 1);
			output_editbox->p.font					= iFont_create(cgcFontName_defaultFixed, 8, FW_MEDIUM, false, false);
			output_editbox->ev.keyboard._onKeyDown	= (uptr)&iSEM_onKeyDown;
			output_editbox->p.sem->showCursorLine	= true;

			// Adjust the caption width
			((SObject*)output->firstChild->ll.next)->rc.right = 70;


		//////////
		// SourceLight a caption and font
		//////
			iObjProp_set_character_direct(sourceLight, _INDEX_CAPTION, cgcSourceLightTitle, sizeof(cgcSourceLightTitle) - 1);
			sourceLight->p.font = iFont_create(cgcFontName_defaultFixed, 10, FW_MEDIUM, false, false);
			propSetVisible(sourceLight, _LOGICAL_TRUE);
			propSetBackStyle(sourceLight, _BACK_STYLE_OPAQUE);
			sourceLight_empty->ev.general._onRender = (uptr)&iSourceLight_copy;


		//////////
		// _screen a caption and font
		//////
			iObjProp_set_character_direct(_screen, _INDEX_CAPTION, cgcScreenTitle, sizeof(cgcScreenTitle) - 1);
			_screen->p.font = iFont_create(cgcFontName_defaultFixed, 10, FW_MEDIUM, false, false);


		//////////
		// Setup _screen's editbox
		//////
			screen_editbox->p.font					= iFont_create(cgcFontName_defaultFixed, 10, FW_MEDIUM, false, false);
			screen_editbox->ev.keyboard._onKeyDown	= (uptr)&iSEM_onKeyDown;
			screenData								= screen_editbox->p.sem;
			screenData->showCursorLine				= true;
			screenData->showEndLine					= true;
			propSetVisible(_screen, _LOGICAL_TRUE);


		//////////
		// Set it visible
		//////
			propSetVisible(_jdebi, _LOGICAL_TRUE);
	}




//////////
//
// Called to create the default datetime variable that are constant references
//
//////
	void iInit_createDefaultDatetimes(void)
	{
		SDateTime dt;


		//////////
		// Jan.01.2000 00:00:00.000
		//////
			_datetime_Jan_01_2000 = iVariable_create(_VAR_TYPE_DATETIME, NULL);
			dt.julian	= 2451545;
			dt.seconds	= 0.0f;
			iDatum_duplicate(&_datetime_Jan_01_2000->value, (u8*)&dt, 8);
	}




//////////
//
// Called to build the splash screen for startup display.  This contains this format:
//
// These items to the left look like wings or road-signs, each independent.
//						 ____________________ _____________________
// 	[o New feature #1]	|                    |                     |
// 	[o New feature #2]	|                    |                     |
// 	[o New feature #3]	|                    |                     |
// 	[o New feature #4]	|                    |	[Loading item 1]   |
// 						|                    |	[Loading item 2]   |
// 						|                    |	[Loading item 3]   |
// 						|                    |	[Loading item N]   |
// 						|____________________|_____________________|
// The items to the right are in a traditional subform with an editbox contained within, and look like a text file.
//
//////
	SBitmap* iiVjr_buildSplashScreen(SBitmap* bmpSplash)
	{
		u32			lnX, lnY;
		SBitmap*	bmp;
		RECT		lrc, lrc2;


		// Create our target bitmap
		bmp = iBmp_allocate();
		iBmp_createBySize(bmp, bmpSplash->bi.biWidth * 3, bmpSplash->bi.biHeight, 24);

		// Fill it with the mask color
		SetRect(&lrc, 0, 0, bmp->bi.biWidth, bmp->bi.biHeight);
		iBmp_fillRect(bmp, &lrc, maskColor, maskColor, maskColor, maskColor, false, NULL, false);

		// Overlay the actual splash image
		SetRect(&lrc2, bmpSplash->bi.biWidth, 0, bmpSplash->bi.biWidth * 2, bmpSplash->bi.biHeight);
		iBmp_bitBlt(bmp, &lrc2, bmpSplash);

		// Build the right side loader item list
		SetRect(&lrc2, 2 * bmpSplash->bi.biWidth, 0, bmp->bi.biWidth, bmpSplash->bi.biHeight);
		iVjr_createOverlayListing(bmp, &lrc2);
		iVjr_renderOverlayListing(bmp, &lrc2);

		// Overlay the accomplishments
		SetRect(&lrc2, 0, 0, bmpSplash->bi.biWidth, bmpSplash->bi.biHeight);
		iVjr_renderAccomplishments(bmp, &lrc2);

		// Append the current version text
		if (iBmp_locateMarker(bmp, 240, 24, 240, &lnX, &lnY, true))
		{
			// Append the version string
			SelectObject(bmp->hdc, gsFontDefaultItalic8->hfont);
			SetTextColor(bmp->hdc, RGB(0,0,0));
			SetBkMode(bmp->hdc, TRANSPARENT);
			SetRect(&lrc, lnX, lnY, (2 * bmpSplash->bi.biWidth) - (lnX - bmpSplash->bi.biWidth), lnY + gsFontDefaultItalic8->tm.tmHeight);
			DrawText(bmp->hdc, (s8*)cgcVersionShort, sizeof(cgcVersionShort) - 1, &lrc, DT_SINGLELINE | DT_LEFT | DT_CENTER);
		}

		// Return our bitmap
		return(bmp);
	}




//////////
//
// Append to the system log
//
//////
	void iVjr_appendSystemLog(u8* tcLogText)
	{
		u8 buffer[2048];


		// Lock it down
		EnterCriticalSection(&cs_logData);

		// Append to it
		sprintf((s8*)buffer, (s8*)"[%u] %s\0", (u32)((s64)GetTickCount() - systemStartedTickCount), (s8*)tcLogText);
		iSEM_appendLine(systemLog, buffer, -1, false);

		// Release it
		LeaveCriticalSection(&cs_logData);

#ifndef _VJR_LOG_ALL
		// Render it
		if (!glShuttingDown)
			iVjr_renderOverlayListing(gSplash.bmp, &gobj_splashListing->rc);
#endif
	}




//////////
//
// Called to flush the system log to disk
//
//////
	void iVjr_flushSystemLog(void)
	{
		iSEM_saveToDisk(systemLog, cgcSystemLogFilename);
	}




//////////
//
// Called to release all of the allocated memory
//
//////
	void iVjr_releaseMemory(void)
	{
		iBmp_delete(&bmpArrowUl,					true, true);
		iBmp_delete(&bmpArrowUr,					true, true);
		iBmp_delete(&bmpArrowLl,					true, true);
		iBmp_delete(&bmpArrowLr,					true, true);

		// Load our icons and images
		iBmp_delete(&bmpVjrIcon,					true, true);
		iBmp_delete(&bmpJDebiIcon,					true, true);
		iBmp_delete(&bmpSourceCodeIcon,				true, true);
		iBmp_delete(&bmpLocalsIcon,					true, true);
		iBmp_delete(&bmpWatchIcon,					true, true);
		iBmp_delete(&bmpCommandIcon,				true, true);
		iBmp_delete(&bmpDebugIcon,					true, true);
		iBmp_delete(&bmpOutputIcon,					true, true);
		iBmp_delete(&bmpSourceLightIcon,			true, true);
		iBmp_delete(&bmpCarouselCarouselIcon,		true, true);
		iBmp_delete(&bmpCarouselTabsIcon,			true, true);
		iBmp_delete(&bmpCarouselPad,				true, true);
		iBmp_delete(&bmpCarouselIcon,				true, true);
		iBmp_delete(&bmpNoImage,					true, true);
		iBmp_delete(&bmpClose,						true, true);
		iBmp_delete(&bmpMaximize,					true, true);
		iBmp_delete(&bmpMinimize,					true, true);
		iBmp_delete(&bmpMove,						true, true);
		iBmp_delete(&bmpCheckboxOn,					true, true);
		iBmp_delete(&bmpCheckboxOff,				true, true);
		iBmp_delete(&bmpButton,						true, true);
		iBmp_delete(&bmpTextbox,					true, true);
		iBmp_delete(&bmpStoplightRed,				true, true);
		iBmp_delete(&bmpStoplightAmber,				true, true);
		iBmp_delete(&bmpStoplightGreen,				true, true);
		iBmp_delete(&bmpStoplightBlue,				true, true);
		iBmp_delete(&bmpBreakpointAlways,			true, true);
		iBmp_delete(&bmpBreakpointAlwaysCountdown,	true, true);
		iBmp_delete(&bmpConditionalTrue,			true, true);
		iBmp_delete(&bmpConditionalFalse,			true, true);
		iBmp_delete(&bmpConditionalTrueCountdown,	true, true);
		iBmp_delete(&bmpConditionalFalseCountdown,	true, true);
		iBmp_delete(&bmpDapple1,					true, true);
		iBmp_delete(&bmpDapple2,					true, true);

		// Casks
		iVjr_releaseCaskIcons();

		// The radio image has a 44x44 dot in the upper-left.
		iBmp_delete(&bmpRadio,						true, true);
		iBmp_delete(&bmpRadioDot,					true, true);

		// Splash screen
		iBmp_delete(&bmpVjrSplash,					true, true);

		// Focus window accumulator
		iBuilder_freeAndRelease(&gFocusHighlights);

		// Default reference datetimes
		iVjr_releaseAllDefaultDatetimes();

		// Default objects
		iVjr_releaseAllDefaultObjects();

		// Main screen window
		iVjr_release_jdebi();

		// Global variables
		iVariable_delete(varGlobals,		true);
		iVariable_delete(varConstant_space,	true);
		iVariable_delete(varEmptyString,	true);
		iVariable_delete(var2000Spaces,		true);
		iVariable_delete(varTrue,			true);
		iVariable_delete(varFalse,			true);

		// Delete the splash objects and images
		iObj_delete(&gobj_splashListing, true, true, true);
		iBmp_delete(&gSplash.bmp, true, false);

		// Release our builders
		iWindow_releaseAll(&gWindows, true);
		iFont_releaseAll(gFonts, true);
	}




//////////
//
// Called to handle some shutdown cleanups
//
//////
	void iVjr_releaseAllDefaultDatetimes(void)
	{
		iVariable_delete(_datetime_Jan_01_2000, true);
	}

	void iVjr_releaseAllDefaultObjects(void)
	{
		iObj_delete(&gobj_defaultEmpty,		true, true, true);
		iObj_delete(&gobj_defaultLabel,		true, true, true);
		iObj_delete(&gobj_defaultTextbox,	true, true, true);
		iObj_delete(&gobj_defaultButton,	true, true, true);
		iObj_delete(&gobj_defaultImage,		true, true, true);
		iObj_delete(&gobj_defaultCheckbox,	true, true, true);
		iObj_delete(&gobj_defaultOption,	true, true, true);
		iObj_delete(&gobj_defaultRadio,		true, true, true);
		iObj_delete(&gobj_defaultForm,		true, true, true);
		iObj_delete(&gobj_defaultSubform,	true, true, true);
	}

	void iVjr_release_jdebi(void)
	{
		iObj_delete(&_jdebi, true, true, true);
	}

	void iVjr_releaseCaskIcons(void)
	{
		iBmp_delete(&bmpCaskIconsTiled,				true, true);
		iBmp_delete(&bmpCaskRoundLeft,				true, true);
		iBmp_delete(&bmpCaskRoundRight,				true, true);
		iBmp_delete(&bmpCaskSquareLeft,				true, true);
		iBmp_delete(&bmpCaskSquareRight,			true, true);
		iBmp_delete(&bmpCaskTriangleLeft,			true, true);
		iBmp_delete(&bmpCaskTriangleRight,			true, true);
		iBmp_delete(&bmpCaskTildeLeft,				true, true);
		iBmp_delete(&bmpCaskTildeRight,				true, true);
		iBmp_delete(&bmpCaskPips1,					true, true);
		iBmp_delete(&bmpCaskPips2,					true, true);
		iBmp_delete(&bmpCaskPips3,					true, true);
		iBmp_delete(&bmpCaskSideExtender,			true, true);
		iBmp_delete(&bmpCaskSideExtenderLeft,		true, true);
		iBmp_delete(&bmpCaskSideExtenderMiddle,		true, true);
		iBmp_delete(&bmpCaskSideExtenderRight,		true, true);
		iBmp_delete(&bmpCaskExtenderMiddle,			true, true);
		iBmp_delete(&bmpCaskExtenderLeft1,			true, true);
		iBmp_delete(&bmpCaskExtenderLeft2,			true, true);
		iBmp_delete(&bmpCaskExtenderRight2,			true, true);
		iBmp_delete(&bmpCaskExtenderRight1,			true, true);
	}




//////////
//
// Called as a central location to shutdown the system politely.
//
//////
	void iVjr_shutdown(void)
	{
		// Indicate we're shutting down
		glShuttingDown = true;

		// System is shutting down
		iVjr_appendSystemLog((u8*)"Unengage VJr");

		// Tell OS to unengage our process
		iVjr_appendSystemLog((u8*)"Notify OS to shutdown");

		// Flush the log
		iVjr_flushSystemLog();

		// Save where we were
		iSEM_saveToDisk(screenData,				cgcScreenDataFilename);
		iSEM_saveToDisk(command_editbox->p.sem,	cgcCommandHistoryFilename);

		// Close the allocated memory blocks
		iVjr_releaseMemory();

		// Signal quit message
		PostQuitMessage(0);
	}




//////////
//
// Called to display a splash screen.
// Note:  The incoming parameter must be a COPY of the original if
//        the original is to persist after display.
//
//////
	DWORD WINAPI iSplash_show(LPVOID/*SBitmap**/ lpParameter)
	{
		s32				lnLeft, lnTop;
		WNDCLASSEXA		classex;
		RECT			lrcWindow, lrcClient;
		HRGN			lrgn;
		MSG				msg;


		// Delete any existing splash screens
		iSplash_delete((LPVOID)0);

		// Store the bitmap
		gSplash.bmp = (SBitmap*)lpParameter;

		// Make sure the class is registered
		if (!GetClassInfoExA(ghInstance, (cs8*)cgcSplashClass, &classex))
		{
			// Initialize
			memset(&classex, 0, sizeof(classex));

			// Populate
			classex.cbSize				= sizeof(WNDCLASSEXA);
			classex.hInstance			= ghInstance;
			classex.style				= CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
			classex.lpszClassName		= (cs8*)cgcSplashClass;
			classex.hCursor				= LoadCursor(NULL, IDC_ARROW);
			classex.lpfnWndProc			= &iSplash_wndProc;

			// Register
			RegisterClassExA(&classex);
		}

		// Create the window
		GetWindowRect(GetDesktopWindow(), &lrcWindow);
		lnLeft	= ((lrcWindow.right  - lrcWindow.left) / 2) - (gSplash.bmp->bi.biWidth  / 2);
		lnTop	= ((lrcWindow.bottom - lrcWindow.top)  / 2) - (gSplash.bmp->bi.biHeight / 2);
		gSplash.hwnd = CreateWindowEx(WS_EX_TOPMOST, (cs8*)cgcSplashClass, NULL, WS_POPUP, 
											lnLeft,
											lnTop,
											gSplash.bmp->bi.biWidth,
											gSplash.bmp->bi.biHeight,
											NULL, NULL, GetModuleHandle(NULL), 0);

		// Process any region info
		GetClientRect(gSplash.hwnd, &lrcClient);
		lrgn = iBmp_extractRgnByMask(gSplash.bmp, &lrcClient);
		SetWindowRgn(gSplash.hwnd, lrgn, false);
		
		// Create a timer to send events to the window every 1/4 second
		SetTimer(gSplash.hwnd, (uptr)&gSplash, 250, 0);

		// Position above all windows
		SetWindowPos(gSplash.hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW | SWP_NOACTIVATE);

		// Read until the splash window goes bye bye
		gSplash.isValid = true;
		while (glIsMouseOverSplash || gSplash.isValid)
		{
			//////////
			// Read and process a message
			//////
				if (GetMessage(&msg, gSplash.hwnd, 0, 0))
				{
					TranslateMessage(&msg);
					DispatchMessage(&msg);

				} else {
					Sleep(0);
				}
		}
		// Log it
		iVjr_appendSystemLog((u8*)"Splash screen unengaged");

		// Delete the timer
		KillTimer(gSplash.hwnd, 0);

		// Delete the bitmap
		iBmp_delete(&gSplash.bmp, true, true);

		// Delete the region
		DeleteObject((HGDIOBJ)lrgn);

		// Destroy the window
		DestroyWindow(gSplash.hwnd);
		gSplash.hwnd = 0;

		// All done
		return(0);
	}




//////////
//
// Called to delete the splash screen (if any)
//
//////
	DWORD WINAPI iSplash_delete(LPVOID lpParameter)
	{
		// Close any prior splash screen
		if (gSplash.isValid)
		{
			// Sleep for the indicated time
			Sleep((DWORD)(uptr)lpParameter);

			// Log it
			iVjr_appendSystemLog((u8*)"Splash screen can unengage");

			// Indicate no longer valid
			gSplash.isValid = false;
		}

		// All done
		return(0);
	}




//////////
//
// Callback to handle the splash screen thingys :-)
//
//////
	LRESULT CALLBACK iSplash_wndProc(HWND hwnd, UINT m, WPARAM w, LPARAM l)
	{
		HDC			lhdc;
		PAINTSTRUCT	ps;
		HRGN		lrgn;
		RECT		lrc;
		POINT		pt;


		if (m == WM_TIMER)
		{
			GetCursorPos(&pt);
			GetWindowRect(hwnd, &lrc);
			lrgn = CreateRectRgn(lrc.left, lrc.top, lrc.right, lrc.bottom);
			GetWindowRgn(hwnd, lrgn);
			glIsMouseOverSplash = ((PtInRegion(lrgn, pt.x - lrc.left, pt.y - lrc.top)) ? true : false);
		}

		// The only message we handle is the paint
		if (gSplash.bmp)
		{
			switch (m)
			{
				case WM_PAINT:
					// Start painting
					lhdc = BeginPaint(hwnd, &ps);

					// Paint it
					BitBlt(lhdc, 0, 0, gSplash.bmp->bi.biWidth, gSplash.bmp->bi.biHeight, gSplash.bmp->hdc, 0, 0, SRCCOPY);

					// All done
					EndPaint(hwnd, &ps);
					return(0);
			}
		}

		// Default handler
		return(DefWindowProc(hwnd, m, w, l));
	}




//////////
//
// Called to play the startup aria while the splash screen is viable.
//
//////
	DWORD WINAPI iPlay_ariaSplash(LPVOID lpParameter)
	{
		u32		stopTickCount;
		f32		lfVolume;
		u64		lnSoundHandle;
		u8		buffer[256];


		// Load the sound file (if it exists)
		if (iFile_readContents((s8*)lpParameter, NULL, &soundData_s8, &soundCount))
		{
			// Log it
			sprintf((s8*)buffer, "Engage %s\0", (s8*)lpParameter);
			iVjr_appendSystemLog(buffer);

			// Begin at the beginning
			soundOffset = 0;
			soundCount	/= 4;	// Each sound item is an f32

			// Attempt to create the sound stream
			lnSoundHandle	= sound_createStream(44100, (u64)&iPlay_ariaSplash_callback);
			lfVolume		= 1.0f;//0.25f;
			sound_playStart(lnSoundHandle, lfVolume);

			// Repeat until the splash screen is over, or the song ends
			stopTickCount = GetTickCount() + 2500;
			while (glIsMouseOverSplash || (gSplash.isValid && soundOffset < soundCount) || GetTickCount() < stopTickCount)
			{
				// Continue looping so long as the mouse is over
				if (glIsMouseOverSplash && soundOffset >= soundCount)
					soundOffset = 0;

				// Wait 1/10th second
				Sleep(100);
			}

			// If we haven't finished, continue until the volume turns down after one second
			while (lfVolume > 0.0f)
			{
				// Turn down the volume 1/10th
				lfVolume -= 0.025f;
				sound_setVolume(lnSoundHandle, lfVolume);

				// Wait 1/10th second
				Sleep(100);
			}
			// Log it
			sprintf((s8*)buffer, "Unengage %s\0", (s8*)lpParameter);
			iVjr_appendSystemLog(buffer);

			// When we get here, we're done playing
			sound_playCancel(lnSoundHandle);

			// Raise the termination flag until we can shut down the playback
			soundOffset = soundCount;

			// Free the sound buffer
			free(soundData_s8);
			soundData_s8 = NULL;

			// Clear the handle
			sound_deleteHandle(lnSoundHandle);

		} else {
			// Log it
			sprintf((s8*)buffer, "Inquiry on sound file %s\0", (s8*)lpParameter);
			iVjr_appendSystemLog(buffer);
		}

		// Completed
		return(0);
	}

	void WINAPI iPlay_ariaSplash_callback(f32* sampleBuffer, u32 tnSamples, bool* tlContinueAfterThisSampleSet)
	{
		u32 lnI;


		// Make sure we have something to do
		for (lnI = 0; lnI < tnSamples && soundData_f32 && soundOffset < soundCount; lnI++, soundOffset++)
			sampleBuffer[lnI] = soundData_f32[soundOffset];

		// Pad with 0.0s
		for ( ; lnI < tnSamples; lnI++)
			sampleBuffer[lnI] = 0.0f;

		// Indicate if the sound should continue after this
		*tlContinueAfterThisSampleSet = (glIsMouseOverSplash || (soundOffset < soundCount));
	}




//////////
//
// Processes messages from the interface window, to forward on to the original window
//
//////
	LRESULT CALLBACK iWindow_wndProcForms(HWND h, UINT m, WPARAM w, LPARAM l)
	{
		SWindow*		win;
		POINT			lpt;
		HDC				lhdc;
		PAINTSTRUCT		ps;


		// See if we know this hwnd
		win = iWindow_findByHwnd(h);
		if (win)
		{
			// It was one of our windows
			switch (m)
			{
				case WMVJR_FIRST_CREATION:
					// Currently unused
					break;

				case WM_TIMER:
					if (win->isMoving || win->isResizing)
					{
						// Grab the mouse coordinates
						GetCursorPos(&lpt);
						win->mouseCurrent.positionInOsDesktop.x = lpt.x;
						win->mouseCurrent.positionInOsDesktop.y = lpt.y;

						// Reposition or resize
						iiMouse_processMouseEvents_windowSpecial(win);
					}
					break;

				case WM_DESTROY:
					// Currently unused
					break;

				case WM_KILLFOCUS:
				case WM_WINDOWPOSCHANGING:
					iFocusHighlight_deleteAll();
					break;

				case WM_SETFOCUS:
				case WM_WINDOWPOSCHANGED:
					iWindow_render(win, true);
					break;

				case WM_LBUTTONDOWN:
				case WM_LBUTTONUP:
				case WM_RBUTTONDOWN:
				case WM_RBUTTONUP:
				case WM_MBUTTONDOWN:
				case WM_MBUTTONUP:
				case WM_RBUTTONDBLCLK:
				case WM_LBUTTONDBLCLK:
				case WM_MBUTTONDBLCLK:
#ifdef WM_MOUSEHWHEEL
				case WM_MOUSEHWHEEL:
#endif
				case WM_MOUSEWHEEL:
				case WM_MOUSEMOVE:
				case WM_MOUSEHOVER:
					if (!win->isMoving && !win->isResizing)
						return(iMouse_processMessage(win, m, w, l));
					break;

				case WM_SYSKEYDOWN:
				case WM_SYSKEYUP:
					if (w == VK_F10)		return(iKeyboard_processMessage(win, ((WM_SYSKEYDOWN) ? WM_KEYDOWN : WM_KEYUP), w, l));
					else					return(iKeyboard_processMessage(win, m, w, l));		// Send it as is
					break;

				case WM_KEYDOWN:
				case WM_KEYUP:
					return(iKeyboard_processMessage(win, m, w, l));

				case WM_CAPTURECHANGED:
					if (win->isMoving)
					{
						// Stop the movement
//						iStopMove();

					} else if (win->isResizing) {
						// Stop the resize
//						iStopResize();

					} else {
						// Make sure our flags are lowered
						win->isMoving	= false;
						win->isResizing	= false;
					}
					break;

				case WM_PAINT:
					// Paint it
					lhdc = BeginPaint(h, &ps);
					BitBlt(lhdc, 0, 0, win->obj->bmp->bi.biWidth, win->obj->bmp->bi.biHeight, win->obj->bmp->hdc, 0, 0, SRCCOPY);
					EndPaint(h, &ps);
					return 0;
			}
		}

		// Call Windows' default procedure handler
		return(DefWindowProc(h, m, w, l));
	}




//////////
//
// Called to create the Windows-facing window for the indicated object.
// Note:  Any object can be presented in a window, though typically on form objects are.
//
//////
	SWindow* iWindow_createForObject(SObject* obj, SWindow* winReuse, s32 icon)
	{
		s32				lnWidth, lnHeight;
		SWindow*		winNew;
		WNDCLASSEXA		classex;
		SVariable*		var;
		s8				buffer[128];
		s8				bufferClass[256];


		// Make sure our environment is sane
		winNew = NULL;
		if (obj)
		{
			//////////
			// Create if need be
			//////
				if (!winReuse)		winNew = iWindow_allocate();
				else				winNew = winReuse;


			//////////
			// If we have a window, prepare it
			//////
				if (winNew)
				{
					//////////
					// Lock down
					//////
						EnterCriticalSection(&winNew->cs);


					//////////
					// Initialize
					//////
						memset(buffer, 0, sizeof(buffer));


					//////////
					// Populate
					//////
						lnWidth		= obj->rc.right - obj->rc.left;
						lnHeight	= obj->rc.bottom - obj->rc.top;
						CopyRect(&winNew->rc, &obj->rc);
						winNew->obj = obj;


					//////////
					// Create our accumulation buffer
					//////
						winNew->bmp = iBmp_allocate();
						iBmp_createBySize(winNew->bmp, lnWidth, lnHeight, 24);


					//////////
					// Register the general window class if need be
					//////
						icon = ((icon <= 0) ? IDI_VJR : icon);
						sprintf(bufferClass, "%s%u\0", (s8*)cgcWindowClass, icon);
						if (!GetClassInfoExA(ghInstance, bufferClass, &classex))
						{
							// Initialize
							memset(&classex, 0, sizeof(classex));

							// Populate
							classex.cbSize				= sizeof(WNDCLASSEXA);
							classex.hInstance			= ghInstance;
							classex.style				= CS_OWNDC | CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
							classex.lpszClassName		= bufferClass;
							classex.hIcon				= LoadIcon(ghInstance, MAKEINTRESOURCE(icon));
							classex.hCursor				= LoadCursor(NULL, IDC_ARROW);
							classex.lpfnWndProc			= &iWindow_wndProcForms;

							// Register
							RegisterClassExA(&classex);
						}


					//////////
					// Physically create the window
					//////
						// Window name
						var = iObjProp_get_variable_byIndex(obj, _INDEX_NAME);
						if (var->varType != _VAR_TYPE_CHARACTER)
						{
							// Use a default name
							memcpy(buffer, cgcName_form, sizeof(cgcName_form));

						} else {
							// Use the indicated name
							memcpy(buffer, var->value.data,	min(var->value.length, (s32)sizeof(buffer) - 1));
						}

						// Build it
						winNew->hwnd = CreateWindow(bufferClass, buffer, WS_POPUP, 
														winNew->rc.left, 
														winNew->rc.top, 
														winNew->rc.right - winNew->rc.left, 
														winNew->rc.bottom - winNew->rc.top, 
														NULL, NULL, ghInstance, 0);

						// Set the coordinates for the form within the window
						SetRect(&obj->rc, 0, 0, lnWidth, lnHeight);

						// Initialize it internally
						PostMessage(winNew->hwnd, WMVJR_FIRST_CREATION, 0, 0);

						// If visible, show it
						if (propIsVisible(obj))
							ShowWindow(winNew->hwnd, SW_SHOW);


					//////////
					// Unlock
					//////
						LeaveCriticalSection(&winNew->cs);
				}
		}

		// Indicate our status
		return(winNew);
	}




//////////
//
// Called to delete all of the windows
//
//////
	void iWindow_releaseAll(SBuilder** windowRoot, bool tlDeleteSelf)
	{
		u32			lnI;
		SBuilder*	windows;
		SWindow*	win;


		// Make sure our environment is sane
		if (windowRoot && *windowRoot)
		{
			//////////
			// Grab the pointer
			//////
				windows = *windowRoot;


			//////////
			// Iterat to delete all windows
			//////
				for (lnI = 0; lnI < windows->populatedLength; lnI += sizeof(SWindow))
				{
					// Grab this pointer
					win = (SWindow*)(windows->data_u8 + lnI);

					// Lock it down
					EnterCriticalSection(&win->cs);

					// Delete
					if (win->isValid)
						iWindow_delete(win, false);		// Delete the window (marks itself invalid)

					// Unlock it
					LeaveCriticalSection(&win->cs);
				}


			//////////
			// Delete
			//////
				if (tlDeleteSelf)
					iBuilder_freeAndRelease(windowRoot);
		}
	}




//////////
//
// Called to delete the indicated window.
// Note:  When called, the window must be already locked (if required).
//
//////
	void iWindow_delete(SWindow* win, bool tlDeleteSelf)
	{
		// Make sure our environment is sane
		if (win && iWindow_isPointerValid(win))
		{
			// Delete it
			iBmp_delete(&win->bmp, true, true);
			iObj_delete(&win->obj, true, true, true);

			// Delete self
			if (tlDeleteSelf)
			{
				// Release the critical section
				DeleteCriticalSection(&win->cs);
				free(win);

			} else {
				win->isValid = false;
			}
		}
	}




//////////
//
// Called to search the known windows for the indicated window by hwnd
//
//////
	SWindow* iWindow_findByHwnd(HWND hwnd)
	{
		u32			lnI;
		HWND		lnHwnd;
		SWindow*	win;


		// Make sure our environment is sane
		if (gWindows)
		{
			// Iterate through all known windows and see which one is which
			for (lnI = 0; lnI < gWindows->populatedLength; lnI += sizeof(SWindow))
			{
				// Grab this one
				win = (SWindow*)(gWindows->data_u8 + lnI);

				// Lock it down
				EnterCriticalSection(&win->cs);

				// Validate validity
				if (win->isValid)
				{
					// Grab the hwnd
					lnHwnd = win->hwnd;

				} else {
					lnHwnd = NULL;
				}

				// Unlock it
				LeaveCriticalSection(&win->cs);

				// Is this our man?
				if (lnHwnd && lnHwnd == hwnd)
				{
					// Indicate our find
					return(win);
				}
			}
		}
		// If we get here, not found
		return(NULL);
	}




//////////
//
// Called to search the known windows for the indicated window by object
//
//////
	SWindow* iWindow_findByObj(SObject* obj)
	{
		u32			lnI;
		SObject*	wobj;
		SWindow*	win;


		// Iterate through all known windows and see which one is which
		for (lnI = 0; lnI < gWindows->populatedLength; lnI += sizeof(SWindow))
		{
			// Grab this one
			win = (SWindow*)(gWindows->data_u8 + lnI);

			// Lock it down
			EnterCriticalSection(&win->cs);

			// Validate validity
			if (win->isValid)
			{
				// Grab the object
				wobj = win->obj;

			} else {
				wobj= NULL;
			}

			// Unlock it
			LeaveCriticalSection(&win->cs);

			// Is this our man?
			if (wobj && wobj == obj)
			{
				// Indicate our find
				return(win);
			}
		}
		// If we get here, not found
		return(NULL);
	}




//////////
//
// Called to
//
//////
	SWindow* iWindow_allocate(void)
	{
		u32			lnI;
		bool		llFound;
		SWindow*	win;
		
		
		// Iterate through existing slots for isValid=false windows
		for (lnI = 0; lnI < gWindows->populatedLength; lnI += sizeof(SWindow))
		{
			// Grab this one
			win = (SWindow*)(gWindows->data_u8 + lnI);

			// Lock it down
			if (TryEnterCriticalSection(&win->cs))
			{
				// Is this one invalid?
				if (!win->isValid)
				{
					// We can use this one
					llFound			= true;
					win->isValid	= true;

				} else {
					// We must continue looking
					llFound			= false;
				}

				// Unlock it
				LeaveCriticalSection(&win->cs);

				// If we found it, use it
				if (llFound)
					return(win);
			}
		}

		// If we get here, it wasn't found
		win = (SWindow*)iBuilder_allocateBytes(gWindows, sizeof(SWindow));
		if (win)
		{
			// Initialize
			memset(win, 0, sizeof(SWindow));

			// Initially populate
			InitializeCriticalSection(&win->cs);
			win->isValid = true;
		}

		// Indicate our status
		return(win);
	}




//////////
//
// Disconnect the object from the window
//
//////
	void iWindow_disconnectObj(SWindow* win, SObject* obj)
	{
		if (win && win->obj && iWindow_isPointerValid(win))
		{
			// Lock it down
			EnterCriticalSection(&win->cs);

			// Validate validity
			if (win->isValid)
				win->obj = NULL;	// Remove the object reference

			// Unlock it
			LeaveCriticalSection(&win->cs);
		}
	}




//////////
//
// Called to re-render the indicated window
//
//////
	void iWindow_render(SWindow* win, bool tlForce)
	{
		// Make sure we have something to render
		if (win && win->obj && iWindow_isPointerValid(win))
		{
			// Lock it down
			EnterCriticalSection(&win->cs);

			// Validate validity
			if (win->isValid)
			{
				// Render anything needing rendering
				iObj_renderChildrenAndSiblings(win->obj, true, true, tlForce);

				// Publish anything needing publishing
				iObj_publish(win->obj, &win->rc, win->bmp, true, true, tlForce, 0);

// Update the openGL window
// iGrace_display();

				// Determine the focus highlights
				iObj_setFocusHighlights(win, win->obj, 0, 0, true, true);

				// And force the redraw
				InvalidateRect(win->hwnd, 0, FALSE);
			}

			// Unlock
			LeaveCriticalSection(&win->cs);
		}
	}




//////////
//
// Called to begin moving the window
//
//////
	void iWindow_move(SWindow* win)
	{
		// Begin the move of this window
	}




//////////
//
// Called to minimize the window
//
//////
	void iWindow_minimize(SWindow* win)
	{
		ShowWindow(win->hwnd, SW_MINIMIZE);
	}




//////////
//
// Called to minimize the window
//
//////
	void iWindow_maximize(SWindow* win)
	{
	}




//////////
//
// Called to validate if the window pointer is valid or not
//
//////
	bool iWindow_isPointerValid(SWindow* win)
	{
		if (gWindows && win && (uptr)win >= gWindows->_data && (uptr)win <= (gWindows->_data + gWindows->populatedLength))
			return(true);	// Valid

		// If we get here, invalid
		return(false);
	}




//////////
//
// Create a new focus highlight window
//
//////
	void iFocusHighlight_create(SFocusHighlight* focus, RECT* rc)
	{
		WNDCLASSEX	wcex;
		ATOM		atom;
		HRGN		lrgn;
		RECT		lrc, lrcp, lrcParent;


		//////////
		// See if the class is already defined
		//////
			if (!GetClassInfoEx(GetModuleHandle(NULL), (cs8*)cgcFocusHighlightClass, &wcex))
			{
				// We need to create said class with our class making skills
				// If we get here, not yet registered
				memset(&wcex, 0, sizeof(wcex));
				wcex.cbSize         = sizeof(wcex);
				wcex.style          = CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
				wcex.lpfnWndProc    = &iFocusHighlight_wndProc;
				wcex.hInstance      = GetModuleHandle(NULL);
				wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
				wcex.lpszClassName  = (cs8*)cgcFocusHighlightClass;
				atom				= RegisterClassExA(&wcex);

				// Was it registered?
				if (!atom)
					return;		// Nope ... when we get here, failure
			}


		//////////
		// Create the window
		//////
			focus->hwnd = CreateWindowEx(WS_EX_TOOLWINDOW, (cs8*)cgcFocusHighlightClass, NULL, WS_POPUP, rc->left, rc->top, rc->right - rc->left, rc->bottom - rc->top, NULL, NULL, GetModuleHandle(NULL), 0);


		//////////
		// If the window needs repositioned or resized, do so
		//////
			GetWindowRect(focus->win->hwnd, &lrcp);
			CopyRect(&lrcParent, &lrcp);
			AdjustWindowRect(&lrcParent, GetWindowLong(focus->win->hwnd, GWL_STYLE), (GetMenu(focus->win->hwnd) != NULL));
			lrcParent.left	= lrcp.left + (lrcp.left - lrcp.left);
			lrcParent.top	= lrcp.top  + (lrcp.top  - lrcp.top);


		//////////
		// Cut out a region for the indicated border pixel width, so the window is transparent except for where it should cut through
		//////
			GetClientRect(focus->hwnd, &lrc);
			focus->hrgn = CreateRectRgnIndirect(&lrc);
			InflateRect(&lrc, - gsCurrentSetting->_set_focus_highlight_pixels, - gsCurrentSetting->_set_focus_highlight_pixels);
			lrgn = CreateRectRgnIndirect(&lrc);
			CombineRgn(focus->hrgn, focus->hrgn, lrgn, RGN_XOR);		// Create a region with the inner part masked out
			SetWindowRgn(focus->hwnd, focus->hrgn, TRUE);


		//////////
		// Store the settings
		//////
			focus->readWriteBrush	= CreateSolidBrush(RGB(focusHighlightReadWriteColor.red,	focusHighlightReadWriteColor.grn,	focusHighlightReadWriteColor.blu));
			focus->readOnlyBrush	= CreateSolidBrush(RGB(focusHighlightReadOnlyColor.red,		focusHighlightReadOnlyColor.grn,	focusHighlightReadOnlyColor.blu));
			GetWindowRect(focus->hwnd, &focus->rc);


		//////////
		// Display the window
		//////
			focus->isValid = true;
			SetWindowPos(focus->hwnd, HWND_TOPMOST, lrcParent.left + rc->left, lrcParent.top + rc->top, rc->right - rc->left, rc->bottom - rc->top, SWP_SHOWWINDOW | SWP_NOACTIVATE);
	}




//////////
//
// Delete a previous window
//
//////
	void iFocusHighlight_delete(SFocusHighlight* focus)
	{
		if (focus && focus->isValid)
		{
			// Delete the window
			DestroyWindow(focus->hwnd);

			// Destroy the region
			DeleteObject((HGDIOBJ)focus->hrgn);

			// Release the variables
			memset(focus, 0, sizeof(SFocusHighlight));
		}
	}




//////////
//
// Called to delete all of the focus highlights
//
//////
	void iFocusHighlight_deleteAll(void)
	{
		u32					lnI;
		SFocusHighlight*	focus;


		// Make sure our environment is sane
		if (gFocusHighlights)
		{
			// Iterate through all focus windows
			for (lnI = 0; lnI < gFocusHighlights->populatedLength; lnI += sizeof(SFocusHighlight))
			{
				// Grab the focus
				focus = (SFocusHighlight*)(gFocusHighlights->data_u8 + lnI);

				// Delete it if it exists
				if (focus && focus->isValid)
					iFocusHighlight_delete(focus);
			}
		}
	}




//////////
//
// Called to find a focus highlight window by its hwnd
//
//////
	SFocusHighlight* iFocusHighlight_findByHwnd(HWND hwnd)
	{
		u32					lnI;
		SFocusHighlight*	focus;


		// Iterate through each item
		for (lnI = 0; lnI < gFocusHighlights->populatedLength; lnI += sizeof(SFocusHighlight))
		{
			// Grab the pointer
			focus = (SFocusHighlight*)(gFocusHighlights->data_u8 + lnI);

			// Is this it?
			if (focus->hwnd == hwnd)
				return(focus);
		}

		// If we get here, it wasn't found
		return(NULL);
	}




//////////
//
// Called to find a focus highlight window by its object
//
//////
	SFocusHighlight* iFocusHighlight_findByObj(SObject* obj)
	{
		u32					lnI;
		SFocusHighlight*	focus;


		// Iterate through each item
		for (lnI = 0; lnI < gFocusHighlights->populatedLength; lnI += sizeof(SFocusHighlight))
		{
			// Grab the pointer
			focus = (SFocusHighlight*)(gFocusHighlights->data_u8 + lnI);

			// Is this it?
			if (focus->obj == obj)
				return(focus);
		}

		// If we get here, it wasn't found
		return(NULL);
	}




//////////
//
// Handles the focus highlight borders
//
//////
	LRESULT CALLBACK iFocusHighlight_wndProc(HWND hwnd, UINT m, WPARAM w, LPARAM l)
	{
		SFocusHighlight*	focus;
		HDC					lhdc;
		PAINTSTRUCT			ps;


		// Find the focus window
		focus = iFocusHighlight_findByHwnd(hwnd);

		// Did we find
		if (focus && focus->isValid)
		{
			// The only message we handle is the paint
			if (m == WM_PAINT)
			{
				// Start painting
				lhdc = BeginPaint(hwnd, &ps);

				// Paint it
				if (propIsReadonly(focus->obj))
				{
					// Read-only coloring
					FillRect(lhdc, &ps.rcPaint, focus->readOnlyBrush);

				} else {
					// Read-write coloring
					FillRect(lhdc, &ps.rcPaint, focus->readWriteBrush);
				}

				// All done
				EndPaint(hwnd, &ps);
				return(0);
			}
		}

		// Default handler
		return(DefWindowProc(hwnd, m, w, l));
	}




//////////
//
// Called to allocate a tooltip structure and prepare it for display
//
//////
	STooltip* iTooltip_allocate(RECT* rc, SBitmap* bmp, s32 tnTimeoutMs, bool tlAllowMove, bool tlAllowSticky)
	{
		STooltip* tooltip;


		// Allocate a structure
		tooltip = (STooltip*)malloc(sizeof(STooltip));
		if (tooltip)
		{
			// Initialize
			memset(tooltip, 0, sizeof(STooltip));

			// Populate
			CopyRect(&tooltip->rc, rc);
			tooltip->bmp			= bmp;
			tooltip->timeoutMs		= tnTimeoutMs;
			tooltip->allowMove		= tlAllowMove;
			tooltip->allowSticky	= tlAllowSticky;
		}

		// Indicate our status
		return(tooltip);
	}




//////////
//
// Called to create a new tooltip at the indicated coordinates with the indicated text
//
//////
	void iTooltip_show(STooltip* tooltip)
	{
		CreateThread(NULL, 0, &iTooltip_thread, tooltip, 0, 0);
	}

	DWORD WINAPI iTooltip_thread(LPVOID lpParameter/*STooltip*/)
	{
		s32			lnWidth, lnHeight;
		WNDCLASSEX	wcex;
		ATOM		atom;
		MSG			msg;
		STooltip*	tooltip;


		//////////
		// See if the class is already defined
		//////
			if (!GetClassInfoEx(GetModuleHandle(NULL), (cs8*)cgcTooltipClass, &wcex))
			{
				// We need to create said class with our class making skills
				// If we get here, not yet registered
				memset(&wcex, 0, sizeof(wcex));
				wcex.cbSize         = sizeof(wcex);
				wcex.style          = CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
				wcex.lpfnWndProc    = &iTooltip_wndProc;
				wcex.hInstance      = GetModuleHandle(NULL);
				wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
				wcex.lpszClassName  = (cs8*)cgcTooltipClass;
				atom				= RegisterClassExA(&wcex);

				// Was it registered?
				if (!atom)
					ExitThread(-1);		// Nope ... when we get here, failure
			}


		//////////
		// Get the structure
		//////
			tooltip = (STooltip*)lpParameter;

		//////////
		// Create the window
		//////
			lnWidth			= tooltip->rc.right  - tooltip->rc.left;
			lnHeight		= tooltip->rc.bottom - tooltip->rc.top;
			tooltip->hwnd	= CreateWindowEx(WS_EX_TOOLWINDOW, (cs8*)cgcTooltipClass, NULL, 
												WS_POPUP,
												tooltip->rc.left,
												tooltip->rc.top,
												lnWidth,
												lnHeight,
												NULL, NULL, GetModuleHandle(NULL), 0);

		//////////
		// Store the settings
		//////
#ifdef __64_BIT_COMPILER__
			// I get a warning in VS2010 if I use this code, and if I don't I get a warning in GCC... can't win. :-)
			SetWindowLong(tooltip->hwnd, GWL_USERDATA, (uptr)lpParameter);
#else
			SetWindowLong(tooltip->hwnd, GWL_USERDATA, (long)lpParameter);
#endif


		//////////
		// Display the window
		//////
			tooltip->isValid = true;
			SetWindowPos(tooltip->hwnd, HWND_TOPMOST, tooltip->rc.left, tooltip->rc.top, lnWidth, lnHeight, SWP_SHOWWINDOW | SWP_NOACTIVATE);


		//////////
		// Create the timer
		//////
			SetTimer(tooltip->hwnd, (uptr)tooltip, _TOOLTIP_TIMER_INTERVAL, 0);


		//////////
		// Process messages
		//////
			while (tooltip->isValid && GetMessage(&msg, NULL, 0, 0))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}

			// Delete the window
			iTooltip_delete(tooltip);

			// Free self
			free(tooltip);

			// All done
			ExitThread(0);

			// The following return(0) line is required for VC98, but will never be used
			return(0);
	}




//////////
//
// Called to delete a specific tooltip
//
//////
	void iTooltip_delete(STooltip* tooltip)
	{
		// Indicate it's no longer valid
		tooltip->isValid = false;

		// Kill the timer
		KillTimer(tooltip->hwnd, (uptr)tooltip);

		// Delete the bitmap
		if (tooltip->bmp)
			iBmp_delete(&tooltip->bmp, true, true);

		// Delete the window
		DestroyWindow(tooltip->hwnd);
	}




//////////
//
// Called to handle window events based on the tooltip
//
//////
	LRESULT CALLBACK iTooltip_wndProc(HWND hwnd, UINT m, WPARAM w, LPARAM l)
	{
		HDC			lhdc;
		PAINTSTRUCT	ps;
		STooltip*	tooltip;


		// The only message we handle is the paint
		tooltip = (STooltip*)GetWindowLong(hwnd, GWL_USERDATA);		// GCC's 64-bit compiler throws a warning on this line ... I'm not sure how to remove it.
		if (tooltip)
		{
			switch (m)
			{
				case WM_LBUTTONDOWN:
				case WM_MBUTTONDOWN:
				case WM_RBUTTONDOWN:
					// They clicked on it, they want it removed
					tooltip->isValid = false;
					break;

				case WM_TIMER:
					// Decrease by our timer interval
					tooltip->timeoutMs -= _TOOLTIP_TIMER_INTERVAL;

					// If we're reached the timeout interval, delete it
					if (tooltip->timeoutMs <= 0)
						tooltip->isValid = false;

					break;

				case WM_PAINT:
					// Start painting
					lhdc = BeginPaint(hwnd, &ps);

					// Paint it
					if (tooltip->bmp)
						BitBlt(lhdc, 0, 0, tooltip->bmp->bi.biWidth, tooltip->bmp->bi.biHeight, tooltip->bmp->hdc, 0, 0, SRCCOPY);

					// All done
					EndPaint(hwnd, &ps);
					return(0);
			}
		}

		// Default handler
		return(DefWindowProc(hwnd, m, w, l));
	}




//////////
//
// Called to reset the sourceLight to an empty state
//
//////
	void iSourceLight_reset(void)
	{
		RECT lrc;


		// If we have a sourceLight bitmap...
		if (bmpSourceLight)
		{
			// Make it all white
			SetRect(&lrc, 0, 0, bmpSourceLight->bi.biWidth, bmpSourceLight->bi.biHeight);
			iBmp_fillRect(bmpSourceLight, &lrc, whiteColor, whiteColor, whiteColor, whiteColor, false, NULL, false);

			// Reset the coordinates to the top
			gnSourceLightX	= _SOURCELIGHT_MARGIN;
			gnSourceLightY	= _SOURCELIGHT_MARGIN;
		}
	}




//////////
//
// Called to copy the sourceLight contents to the indicated object's bitmap
//
///////
	bool iSourceLight_copy(SWindow* win, SObject* obj)
	{
		s32		scrollX, scrollY;
		RECT	lrc;


		// Make sure our environment is sane
		if (obj && obj->bmp && bmpSourceLight)
		{
			//////////
			// Grab our scroll offsets
			//////
				scrollX = iObjProp_get_s32_direct(obj, _INDEX_SCROLLX);
				scrollY = iObjProp_get_s32_direct(obj, _INDEX_SCROLLX);


			//////////
			// Copy over the part that will fit
			//////
				iiBmp_bitBltPortion(obj->bmp, 0, 0, obj->bmp->bi.biWidth, obj->bmp->bi.biHeight, bmpSourceLight, scrollX, scrollY);


			//////////
			// Fill in any rectangles beyond the scroll
			//////
// TODO:  An optimization here would be to not overlay any portion in the lower-right both horizontally and vertically
				// Portion at the right
				if (bmpSourceLight->bi.biWidth - scrollX < obj->bmp->bi.biWidth)
				{
					// From the edge of the sourceLight content to the extent of the bitmap horizontally
					SetRect(&lrc, bmpSourceLight->bi.biWidth - scrollX, 0, obj->bmp->bi.biWidth, obj->bmp->bi.biHeight);
					iBmp_fillRect(obj->bmp, &lrc, whiteColor, whiteColor, whiteColor, whiteColor, false, NULL, false);
				}

				// Portion at the bottom
				if (bmpSourceLight->bi.biHeight - scrollY < obj->bmp->bi.biHeight)
				{
					// From the edge of the sourceLight content to the extent of the bitmap horizontally
					SetRect(&lrc, 0, bmpSourceLight->bi.biHeight - scrollY, obj->bmp->bi.biWidth, obj->bmp->bi.biHeight);
					iBmp_fillRect(obj->bmp, &lrc, whiteColor, whiteColor, whiteColor, whiteColor, false, NULL, false);
				}
		}

		// Indicate that the processing should continue
		return(true);
	}




//////////
//
// Called to read the contents of the indicated file
//
//////
	bool iFile_readContents(s8* tcFilename, FILE** tfh, s8** data, u32* dataLength)
	{
		u32		lnNumread;
		FILE*	lfh;


		// Make sure our environment is sane
		if (tcFilename && data && dataLength)
		{
			// Try to open the file
			lfh = fopen(tcFilename, "rb+");
			if (lfh)
			{
				// Find out how big it is
				fseek(lfh, 0, SEEK_END);
				*dataLength = ftell(lfh);
				fseek(lfh, 0, SEEK_SET);

				// Allocate a buffer that large
				*data = (s8*)malloc(*dataLength);
				if (*data)
				{
					// Read the contents
					lnNumread = (u32)fread(*data, 1, *dataLength, lfh);
					if (lnNumread == *dataLength)
					{
						// We read everything
						if (tfh)
						{
							// Save the file handle, return it open
							*tfh = lfh;

						} else {
							// Close the file handle
							fclose(lfh);
						}

						// Indicate success
						return(true);
					}

				} else {
					// Error allocating that much memory
					fclose(lfh);
				}
			}
		}
		// If we get here, failure
		return(false);
	}




//////////
//
// Adjusts the brightness of the indicated color by the indicated percentage.
//
//////
	void iMisc_adjustColorBrightness(SBgra& color, f32 tfPercent)
	{
		f32 red, grn, blu;


		//////////
		// Adjust the color
		//////
			tfPercent	= (100.0f + tfPercent) / 100.0f;
			red			= (f32)color.red * tfPercent;
			grn			= (f32)color.grn * tfPercent;
			blu			= (f32)color.blu * tfPercent;


		//////////
		// Constrict it into range
		//////
			red			= min(max(red, 0.0f), 255.0f);
			grn			= min(max(grn, 0.0f), 255.0f);
			blu			= min(max(blu, 0.0f), 255.0f);


		//////////
		// Set the color back
		//////
			color.red	= (u8)red;
			color.grn	= (u8)grn;
			color.blu	= (u8)blu;
	}




//////////
//
// Called to shutdown the system politely, closing everything that's open
//
//////
	bool iInit_shutdownPolitely(void)
	{
		return(true);
	}




//////////
//
// Time functions
//
//////
	s64 iTime_computeMilliseconds(SYSTEMTIME* time)
	{
		s64 lnMs;
		

		// Compute the milliseconds
		lnMs	=		(time->wMilliseconds)
					+	(time->wSecond			* 1000)
					+	(time->wMinute			* 1000 * 60)
					+	(time->wHour			* 1000 * 60 * 60)
					+	(time->wDay				* 1000 * 60 * 60 * 24)
					+	(time->wMonth			* 1000 * 60 * 60 * 24 * 31)
					+	(time->wYear			* 1000 * 60 * 60 * 24 * 31 * 366);
		return(lnMs);
	}

	s64 iTime_getSystemMs(void)
	{
		SYSTEMTIME time;
		GetSystemTime(&time);
		return(iTime_computeMilliseconds(&time));
	}

	s64 iTime_getLocalMs(void)
	{
		SYSTEMTIME time;
		GetLocalTime(&time);
		return(iTime_computeMilliseconds(&time));
	}

	bool iTestExactlyEqual(u8* left, u32 leftLength, cu8* right, u32 rightLength)
	{
		return(iTestExactlyEqual(left, leftLength, (u8*)right, rightLength));
	}

	bool iTestExactlyEqual(u8* left, u32 leftLength, u8* right, u32 rightLength)
	{
		// Everything must be established
		if (left && right && leftLength == rightLength)
			return(_memicmp((s8*)left, (s8*)right, leftLength) == 0);	// Test equality without regards to case
		
		// If we get here, no match
		return(false);
	}

	bool iTestExactlyEqual_case(u8* left, u32 leftLength, cu8* right, u32 rightLength)
	{
		return(iTestExactlyEqual_case(left, leftLength, (u8*)right, rightLength));
	}

	bool iTestExactlyEqual_case(u8* left, u32 leftLength, u8* right, u32 rightLength)
	{
		// Everything must be established
		if (left && right && leftLength == rightLength)
			return(memcmp((s8*)left, (s8*)right, leftLength) == 0);	// Test equality

		// If we get here, no match
		return(false);
	}

	bool iIsNeedleInHaystack(s8* haystack, s32 haystackLength, s8* needle, s32 needleLength)
	{
		return(iIsNeedleInHaystack(haystack, haystackLength, needle, needleLength, NULL));
	}

	// Case sensitive variation
	bool iIsNeedleInHaystackCase(s8* haystack, s32 haystackLength, s8* needle, s32 needleLength)
	{
		return(iIsNeedleInHaystackCase(haystack, haystackLength, needle, needleLength, NULL));
	}

	bool iIsNeedleInHaystack(s8* haystack, s32 haystackLength, s8* needle, s32 needleLength, u32* tnStart)
	{
		s32 lnI;


		// Make sure the lengths are valid
		if (haystackLength < 0)		haystackLength	= (s32)strlen(haystack);
		if (needleLength < 0)		needleLength	= (s32)strlen(needle);

		// Iterate to see if we find it
		for (lnI = 0; lnI <= haystackLength - needleLength; lnI++)
		{
			if (_memicmp(haystack + lnI, needle, needleLength) == 0)
			{
				// Store the offset if we're supposed to
				if (tnStart)
					*tnStart = lnI;
				// Indicate success
				return(true);
			}
		}

		// Failure
		return(false);
	}

	bool iIsNeedleInHaystackCase(s8* haystack, s32 haystackLength, s8* needle, s32 needleLength, u32* tnStart)
	{
		s32 lnI;


		// Make sure the lengths are valid
		if (haystackLength < 0)		haystackLength	= (s32)strlen(haystack);
		if (needleLength < 0)		needleLength	= (s32)strlen(needle);

		// Check to see if the specified word / phrase / whatever exists on this line
		for (lnI = 0; lnI <= haystackLength - needleLength; lnI++)
		{
			if (memcmp(haystack + lnI, needle, needleLength) == 0)
			{
				// Store the offset if we're supposed to
				if (tnStart)
					*tnStart = lnI;
				// Indicate success
				return(true);
			}
		}

		// Failure
		return(false);
	}

	// Search only for a single character without regard to case
	bool iIsCharacterInHaystack(s8* haystack, s32 haystackLength, s8 needle, u32* tnOffset)
	{
		s32		lnI;
		s8		c;


		// Make sure the length is valid
		if (haystackLength < 0)
			haystackLength	= (s32)strlen(haystack);

		// Check to see if the specified word / phrase / whatever contains this character
		c = iLowerCharacter(needle);
		for (lnI = 0; lnI < haystackLength; lnI++)
		{
			if (iLowerCharacter(haystack[lnI]) == c)
			{
				if (tnOffset)
					*tnOffset = lnI;

				return(true);
			}
		}

		// Failure
		return(false);
	}

	// Search only for a single character by case
	bool iIsCharacterInHaystackCase(s8* haystack, s32 haystackLength, s8 needle, u32* tnOffset)
	{
		s32 lnI;


		// Make sure the length is valid
		if (haystackLength < 0)
			haystackLength	= (s32)strlen(haystack);

		// Check to see if the specified word / phrase / whatever contains this character
		for (lnI = 0; lnI < haystackLength; lnI++)
		{
			if (haystack[lnI] == needle)
			{
				if (tnOffset)
					*tnOffset = lnI;

				return(true);
			}
		}

		// Failure
		return(false);
	}

	// Searches backwards for the specified character
	bool iIsCharacterInHaystackReversed(s8* haystack, s32 haystackLength, s8 needle, u32* tnOffset)
	{
		s32		lnI;
		s8		c;


		// Make sure the length is valid
		if (haystackLength < 0)
			haystackLength	= (s32)strlen(haystack);

		// Check to see if the specified word / phrase / whatever contains this character
		c = iLowerCharacter(needle);
		for (lnI = haystackLength - 1; lnI >= 0; lnI--)
		{
			if (iLowerCharacter(haystack[lnI]) == c)
			{
				if (tnOffset)
					*tnOffset = lnI;

				return(true);
			}
		}

		// Failure
		return(false);
	}

	bool iIsCharacterInHaystackReversedCase(s8* haystack, s32 haystackLength, s8 needle, u32* tnOffset)
	{
		s32 lnI;


		// Make sure the length is valid
		if (haystackLength < 0)
			haystackLength	= (s32)strlen(haystack);

		// Check to see if the specified word / phrase / whatever contains this character
		for (lnI = haystackLength - 1; lnI >= 0; lnI--)
		{
			if (haystack[lnI] == needle)
			{
				if (tnOffset)
					*tnOffset = lnI;

				return(true);
			}
		}

		// Failure
		return(false);
	}

	s64 iMath_delta(s64 tnBaseValue, s64 tnSubtractionValue)
	{
		return(tnBaseValue - tnSubtractionValue);
	}




//////////
//
// Checks to see if the specified needle is found at the start of the haystack
//
//////
	bool iDoesHaystackStartWithNeedle(s8* haystack, s32 haystackLength, s8* needle, s32 needleLength)
	{
		s32 lnWhitespaces;


		// Make sure the length is valid
		if (haystackLength < 0)
			haystackLength	= (s32)strlen(haystack);

		// Skip past any whitespaces
		lnWhitespaces = 0;
		iSkipWhitespaces(haystack, (u32*)&lnWhitespaces, haystackLength);

		// Check to see if the specified word / phrase / whatever exists on this line
		if (haystackLength - lnWhitespaces >= needleLength)
		{
			if (_memicmp(haystack + lnWhitespaces, needle, needleLength) == 0)
				return(true);
		}

		// Failure
		return(false);
	}

	// Case sensitive variation
	bool iDoesHaystackStartWithNeedleCase(s8* haystack, s32 haystackLength, s8* needle, s32 needleLength)
	{
		s32 lnWhitespaces;


		// Make sure the lengths are valid
		if (haystackLength < 0)		haystackLength	= (s32)strlen(haystack);
		if (needleLength < 0)		needleLength	= (s32)strlen(needle);

		// Skip past any whitespaces
		lnWhitespaces = 0;
		iSkipWhitespaces(haystack, (u32*)&lnWhitespaces, haystackLength);

		// Check to see if the specified word / phrase / whatever exists on this line
		if (haystackLength - lnWhitespaces >= needleLength)
		{
			if (memcmp(haystack + lnWhitespaces, needle, needleLength) == 0)
				return(true);
		}

		// Failure
		return(false);
	}

	s8 iLowerCharacter(s8 ch)
	{
		if (ch >= 'A' && ch <= 'Z')
			ch += 0x20;
		return(ch);
	}




//////////
//
// Skips past whitespace characters (tabs and spaces)
// Move the offset byte forward until we're no longer sitting on a
// whitespace character, and indicate how many we skipped.
//
//////
	u32 iSkipWhitespaces(s8* source, u32* offset, u32 maxLength)
	{
		s8		c;
		u32		lnLength, lnOffset;


		// Make sure the length is valid
		if (maxLength < 0)
			maxLength = (u32)strlen(source);

		// Make sure we have valid parameters
		if (!offset)
		{
			// They didn't give us an offset, so we use our own, home-grown solution, that's right, my friend! :-)
			lnOffset	= 0;
			offset = &lnOffset;
		}

		// Move from the current location to its new location
		lnLength = 0;
		while (*offset < maxLength)
		{
			c = source[*offset];
			if (c != 32/*space*/ && c != 9/*tab*/)
				return(lnLength);		// It's no longer a whitespace

			// Move to the next position
			++lnLength;
			++*offset;
		}
		return(lnLength);
	}




//////////
//
// Called to round the value to the indicated decimal place
//
//////
	s8* iMath_roundTo(f64* tfValue, f64 tfRoundTo)
	{
		if (tfRoundTo == 1000.0)				{ *tfValue = ((f64)((s64)(*tfValue / 1000.0)) * 1000.0);						return((s8*)"%15.0lf"); }
		if (tfRoundTo == 100.0)					{ *tfValue = ((f64)((s64)(*tfValue / 100.0)) * 100.0);							return((s8*)"%15.0lf"); }
		if (tfRoundTo == 10.0)					{ *tfValue = ((f64)((s64)(*tfValue / 10.0)) * 10.0);							return((s8*)"%15.0lf"); }
		if (tfRoundTo == 1.0)					{ /* This entry added for speed, as it's likely to be a very common round */	return((s8*)"%15.0lf"); }
		if (tfRoundTo == 0.1)					{ *tfValue = ((f64)((s64)(*tfValue * 10.0)) / 10.0);							return((s8*)"%15.1lf"); }
		if (tfRoundTo == 0.01)					{ *tfValue = ((f64)((s64)(*tfValue * 100.0)) / 100.0);							return((s8*)"%15.2lf"); }
		if (tfRoundTo == 0.001)					{ *tfValue = ((f64)((s64)(*tfValue * 1000.0)) / 1000.0);						return((s8*)"%15.3lf"); }
		if (tfRoundTo == 0.0001)				{ *tfValue = ((f64)((s64)(*tfValue * 10000.0)) / 10000.0);						return((s8*)"%15.4lf"); }
		if (tfRoundTo == 0.00001)				{ *tfValue = ((f64)((s64)(*tfValue * 100000.0)) / 100000.0);					return((s8*)"%15.5lf"); }
		if (tfRoundTo == 0.000001)				{ *tfValue = ((f64)((s64)(*tfValue * 1000000.0)) / 1000000.0);					return((s8*)"%15.6lf"); }
		if (tfRoundTo == 0.0000001)				{ *tfValue = ((f64)((s64)(*tfValue * 10000000.0)) / 10000000.0);				return((s8*)"%15.7lf"); }
		if (tfRoundTo == 0.00000001)			{ *tfValue = ((f64)((s64)(*tfValue * 100000000.0)) / 100000000.0);				return((s8*)"%15.8lf"); }
		if (tfRoundTo == 0.000000001)			{ *tfValue = ((f64)((s64)(*tfValue * 1000000000.0)) / 1000000000.0);			return((s8*)"%15.9lf"); }
		if (tfRoundTo == 0.0000000001)			{ *tfValue = ((f64)((s64)(*tfValue * 10000000000.0)) / 10000000000.0);			return((s8*)"%15.10lf"); }
		if (tfRoundTo == 0.00000000001)			{ *tfValue = ((f64)((s64)(*tfValue * 100000000000.0)) / 100000000000.0);		return((s8*)"%15.11lf"); }
		if (tfRoundTo == 0.000000000001)		{ *tfValue = ((f64)((s64)(*tfValue * 1000000000000.0)) / 1000000000000.0);		return((s8*)"%15.12lf"); }
		if (tfRoundTo == 0.0000000000001)		{ *tfValue = ((f64)((s64)(*tfValue * 10000000000000.0)) / 10000000000000.0);	return((s8*)"%15.13lf"); }
		if (tfRoundTo == 100000000000000.0)		{ *tfValue = ((f64)((s64)(*tfValue / 100000000000000.0)) * 100000000000000.0);	return((s8*)"%15.0lf"); }
		if (tfRoundTo == 10000000000000.0)		{ *tfValue = ((f64)((s64)(*tfValue / 10000000000000.0)) * 10000000000000.0);	return((s8*)"%15.0lf"); }
		if (tfRoundTo == 1000000000000.0)		{ *tfValue = ((f64)((s64)(*tfValue / 1000000000000.0)) * 1000000000000.0);		return((s8*)"%15.0lf"); }
		if (tfRoundTo == 100000000000.0)		{ *tfValue = ((f64)((s64)(*tfValue / 100000000000.0)) * 100000000000.0);		return((s8*)"%15.0lf"); }
		if (tfRoundTo == 10000000000.0)			{ *tfValue = ((f64)((s64)(*tfValue / 10000000000.0)) * 10000000000.0);			return((s8*)"%15.0lf"); }
		if (tfRoundTo == 1000000000.0)			{ *tfValue = ((f64)((s64)(*tfValue / 1000000000.0)) * 1000000000.0);			return((s8*)"%15.0lf"); }
		if (tfRoundTo == 100000000.0)			{ *tfValue = ((f64)((s64)(*tfValue / 100000000.0)) * 100000000.0);				return((s8*)"%15.0lf"); }
		if (tfRoundTo == 10000000.0)			{ *tfValue = ((f64)((s64)(*tfValue / 10000000.0)) * 10000000.0);				return((s8*)"%15.0lf"); }
		if (tfRoundTo == 1000000.0)				{ *tfValue = ((f64)((s64)(*tfValue / 1000000.0)) * 1000000.0);					return((s8*)"%15.0lf"); }
		if (tfRoundTo == 100000.0)				{ *tfValue = ((f64)((s64)(*tfValue / 100000.0)) * 100000.0);					return((s8*)"%15.0lf"); }
		if (tfRoundTo == 10000.0)				{ *tfValue = ((f64)((s64)(*tfValue / 10000.0)) * 10000.0);						return((s8*)"%15.0lf"); }

		// If we get here, an unknown value
		return((s8*)"%.0lf");
	}




//////////
//
// Called to see if a value is between two others, inclusive
//
//////
	bool iMath_between(s32 tnValue, s32 tnN1, s32 tnN2)
	{
		// The math is simple :-)
		if (tnValue >= min(tnN1, tnN2) && tnValue <= max(tnN1, tnN2))
			return(true);

		// If we get here, not between
		return(false);
	}




//////////
//
// Convert the case.
//
//////
	s8 iLowerCase(s8 c)
	{
		if (c >= 'A' && c <= 'Z')		return(c + 0x20);
		else							return(c);
	}

	s8 iUpperCase(s8 c)
	{
		if (c >= 'a' && c <= 'z')		return(c - 0x20);
		else							return(c);
	}




//////////
//
// Called to duplicate the indicated string
//
//////
	s8* iDuplicateString(s8* tcText)
	{
		u32		lnLength;
		s8*		ptr;


		// Allocate it
		lnLength	= (u32)strlen(tcText) + 1;
		ptr			= (s8*)malloc(lnLength);

		// Copy it (including the trailing null)
		if (ptr)
			memcpy(ptr, tcText, lnLength);

		// All done
		return(ptr);
	}




//////////
//
// Called to process the mouse messages.
//
//////
	s32 iMouse_processMessage(SWindow* win, UINT msg, WPARAM w, LPARAM l)
	{
		//////////
		// If we're a valid window, process the mouse
		//////
			if (win && win->obj && win->obj->rc.right > win->obj->rc.left)
			{
				// Copy the prior mouse condition to the current one
				memcpy(&win->mousePrior, &win->mouseCurrent, sizeof(win->mousePrior));
				
				// Translate the mouse from the scaled position to its real position
				iiMouse_translatePosition(win, (POINTS*)&l, msg);

				// Signal the event(s)
				iiMouse_processMouseEvents(win, msg, w, l);
			}
			// If we get here, invalid
			return(-1);
	}




//////////
//
// Called to translate the mouse position for the source window.
// Note:  The win parameter is required.
//
//////
	void iiMouse_translatePosition(SWindow* win, POINTS* pt, UINT msg)
	{
		POINT	lpt, lptOnOSDesktop;
		bool	llWheelMessage;


		//////////
		// Translate our SHORT points structure to the LONG point structure
		//////
			if (pt)
			{
				lpt.x = pt->x;
				lpt.y = pt->y;
				win->mouseCurrent.position.x = lpt.x;
				win->mouseCurrent.position.y = lpt.y;
			}


		//////////
		// Get the mouse flags
		//////
			iiMouse_getFlags_async(	&win->mouseCurrent.isCtrl,		&win->mouseCurrent.isAlt,			&win->mouseCurrent.isShift,
									&win->mouseCurrent.buttonLeft,	&win->mouseCurrent.buttonMiddle,	&win->mouseCurrent.buttonRight,
									&win->mouseCurrent.isCaps,
									&win->mouseCurrent.buttonAnyDown);


		//////////
		// If we're moving or resizing, also read the screen coordinate mouse data, and then return
		//////
			GetCursorPos(&lptOnOSDesktop);
			if (!(win->isMoving || win->isResizing))
			{
				// Get the mouse pointer in screen coordinates
				win->mouseCurrent.positionInOsDesktop.x = lptOnOSDesktop.x;
				win->mouseCurrent.positionInOsDesktop.y = lptOnOSDesktop.y;
				return;
			}


		//////////
		// If it's a mouse scroll, the coordinates are given in screen coordinates.
		// Subtract off the window portion
		//////
			llWheelMessage = (msg == WM_MOUSEWHEEL);
#ifdef WM_MOUSEHWHEEL
			llWheelMessage |= (msg == WM_MOUSEHWHEEL);
#endif
			if (llWheelMessage)
			{
				win->mouseCurrent.position.x -= win->rc.left;
				win->mouseCurrent.position.y -= win->rc.top;
			}
	}




//////////
//
// Process the mouse events in the client area for this form
//
//////
	s32 iiMouse_processMouseEvents(SWindow* win, UINT msg, WPARAM w, LPARAM l)
	{
		s32			lnResult;
		bool		llProcessed;
		SObject*	obj;


		//////////
		// Grab our pointer
		//////
			obj = win->obj;


		//////////
		// Determine the click flags
		//////
			obj->ev.mouse.thisClick = 0;
			obj->ev.mouse.thisClick	|= ((win->mouseCurrent.buttonLeft)		? _MOUSE_LEFT_BUTTON	: 0);
			obj->ev.mouse.thisClick	|= ((win->mouseCurrent.buttonMiddle)	? _MOUSE_MIDDLE_BUTTON	: 0);
			obj->ev.mouse.thisClick	|= ((win->mouseCurrent.buttonRight)		? _MOUSE_RIGHT_BUTTON	: 0);


		//////////
		// Iterate through objects to see where it is the mouse is traipsing
		//////
			// Note:  win->mouseLastPosition holds the coordinates
			// Note:  win->is* flags indicate both button and keyboard state conditions (ctrl, alt, shift, caps)
			llProcessed = false;
			switch (msg)
			{
				case WM_MOUSEWHEEL:
					// Signal a mouseScroll
					if (!win->isMoving && ! win->isResizing)
					{
						win->mouseCurrent.wheelDeltaV	= (s32)((s16)(((u32)w) >> 16)) / WHEEL_DELTA;
						win->mouseCurrent.wheelDeltaH	= 0;
						iiMouse_processMouseEvents_common(win, obj, &obj->rc, msg, true, true, &llProcessed);
					}
					break;

#ifdef WM_MOUSEHWHEEL
				case WM_MOUSEHWHEEL:
					// Signal a mouseHScroll
					if (!win->isMoving && ! win->isResizing)
					{
						win->mouseCurrent.wheelDeltaV	= 0;
						win->mouseCurrent.wheelDeltaH	= (s32)((s16)(((u32)w) >> 16)) / WHEEL_DELTA;
						iiMouse_processMouseEvents_common(win, obj, &obj->rc, msg, true, true, &llProcessed);
					}
					break;
#endif

				case WM_MOUSEMOVE:
					// Check for mouseEnter and mouseLeave, then a mouseMove
					if (!win->isMoving && ! win->isResizing)
					{
						// Process normal mouse moves
						iiMouse_processMouseEvents_mouseMove(win, obj, &obj->rc, true, true, &llProcessed);
						
						// The mouse has moved, reset the hover counter
						obj->ev.mouse.startHoverTickCount	= GetTickCount();
						obj->ev.mouse.hasHoverSignaled		= false;
					}
					break;


				case WM_LBUTTONDOWN:
				case WM_RBUTTONDOWN:
				case WM_MBUTTONDOWN:
					// Signal a mouseDown, then a click
					if (iiMouse_processMouseEvents_common(win, obj, &obj->rc, msg, true, true, &llProcessed))
					{
						// Set the last click
						obj->ev.mouse._lastClick = obj->ev.mouse.thisClick;
					}
					break;

				case WM_LBUTTONUP:
				case WM_RBUTTONUP:
				case WM_MBUTTONUP:
					// Signal a mouseUp
					if (!win->isMoving && ! win->isResizing)
					{
						// A mouse button was released
						iiMouse_processMouseEvents_common(win, obj, &obj->rc, msg, true, true, &llProcessed);
					}
					break;

				case WM_LBUTTONDBLCLK:
					// Signal a double click
//					iiMouse_processMouseEvents_client_dblClickEx(win, obj, &obj->rc, _MOUSE_LEFT_BUTTON, true, true);
					break;

				case WM_RBUTTONDBLCLK:
					// Signal a double click
//					iiMouse_processMouseEvents_client_dblClickEx(win, obj, &obj->rc, _MOUSE_RIGHT_BUTTON, true, true);
					break;

				case WM_MBUTTONDBLCLK:
					// Signal a double click
//					iiMouse_processMouseEvents_client_dblClickEx(win, obj, &obj->rc, _MOUSE_MIDDLE_BUTTON, true, true);
					break;
			}


		// Indicate our status
		lnResult = 0;
		return(lnResult);
	}




//////////
//
// Called as a common function to obtain the coordinates for the current object descent
//
//////
	bool iiMouse_processMouseEvents_getRectDescent(SWindow* win, SObject* obj, RECT* rc, RECT& lrc, RECT& lrcClient)
	{
		//////////
		// Determine the position within the parent's rectangle where this object will go
		//////
			// Adjust this item within the parent's rectangle
			SetRect(&lrc,	rc->left	+ obj->rc.left,
							rc->top		+ obj->rc.top,
							rc->left	+ obj->rc.right,
							rc->top		+ obj->rc.bottom);


		//////////
		// Are we in the client area?
		//////
			switch (obj->objType)
			{
				case _OBJ_TYPE_FORM:
				case _OBJ_TYPE_SUBFORM:
					// Adjust by the client coordinates
					SetRect(&lrcClient,	lrc.left	+ obj->rcClient.left,
										lrc.top		+ obj->rcClient.top,
										lrc.left	+ obj->rcClient.left	+ (obj->rcClient.right	- obj->rcClient.left),
										lrc.top		+ obj->rcClient.top		+ (obj->rcClient.bottom	- obj->rcClient.top));
					break;

				default:
					// Use the full coordinates
					CopyRect(&lrcClient, &lrc);
					break;
			}


		//////////
		// Clip to the parent rectangle
		//////
			if (!obj->parent || obj->parent->objType != _OBJ_TYPE_FORM)
			{
				lrc.right	= min(rc->right,	lrc.right);
				lrc.bottom	= min(rc->bottom,	lrc.bottom);
			}


		//////////
		// Indicate if we're in the client area
		//////
			return((PtInRect(&lrcClient, win->mouseCurrent.position)) ? true : false);
	}




//////////
//
// Called to process the mouse move events when the window is being moved or resized
//
//////
	void iiMouse_processMouseEvents_windowSpecial(SWindow* win)
	{
		s32 lnDeltaX, lnDeltaY;


		//////////
		// If the window is moving or resizing
		//////
			if (win->isMoving)
			{
				//////////
				// Get current mouse flags
				//////
					iiMouse_getFlags_async(	&win->mouseCurrent.isCtrl,		&win->mouseCurrent.isAlt,			&win->mouseCurrent.isShift,
											&win->mouseCurrent.buttonLeft,	&win->mouseCurrent.buttonMiddle,	&win->mouseCurrent.buttonRight,
											&win->mouseCurrent.isCaps,
											&win->mouseCurrent.buttonAnyDown);


				//////////
				// Calculate the deltas from where it began moving
				//////
					// delta = (started - current)
					lnDeltaX = win->mouseMoveResizeStart.positionInOsDesktop.x - win->mouseCurrent.positionInOsDesktop.x;
					lnDeltaY = win->mouseMoveResizeStart.positionInOsDesktop.y - win->mouseCurrent.positionInOsDesktop.y;


				//////////
				// Are we done?
				//////
					if (!win->mouseCurrent.buttonLeft)
					{
						// They've released the mouse button since the last move
						// We go ahead and process through even if it hasn't moved

					} else if (lnDeltaX == win->movingLastDeltaX && lnDeltaY == win->movingLastDeltaY) {
						// Nothing has changed this go around
						return;
					}


				//////////
				// Set our last values
				//////
					win->movingLastDeltaX = lnDeltaX;
					win->movingLastDeltaY = lnDeltaY;


				//////////
				// Position the window to its new location
				//////
					SetWindowPos(win->hwnd, NULL, win->rc.left - lnDeltaX, win->rc.top - lnDeltaY, 0, 0, SWP_NOSIZE | SWP_NOZORDER);


				//////////
				// If we're done, then we're done
				//////
					if (!win->mouseCurrent.buttonLeft)
					{
						// We're done
						GetWindowRect(win->hwnd, &win->rc);
						win->isMoving = false;
					}

			} else if (win->isResizing) {
				// Resizing
			}
	}




//////////
//
// Called to process mouseEnter and mouseLeave events based on mouse movement
//
//////
	void iiMouse_processMouseEvents_mouseMove(SWindow* win, SObject* obj, RECT* rc, bool tlProcessChildren, bool tlProcessSiblings, bool* tlProcessed)
	{
		bool		llInClientArea;
		RECT		lrc, lrcClient;
		SObject*	objSib;


		// Make sure our object environment is sane
		if (!propIsEnabled(obj) || !obj->bmp)
			return;


		//////////
		// Get the rectangle we're in at this level
		/////
			llInClientArea = iiMouse_processMouseEvents_getRectDescent(win, obj, rc, lrc, lrcClient);


		//////////
		// Process any children
		//////
			if (tlProcessChildren && obj->firstChild)
				iiMouse_processMouseEvents_mouseMove(win, obj->firstChild, &lrcClient, true, true, tlProcessed);


		//////////
		// Are we within this object?
		//////
			if (PtInRect(&lrc, win->mouseCurrent.position))
			{
				// We are in this object
				*tlProcessed = true;	// Indicate we've processed this
				if (!obj->ev.mouse.isMouseOver)
				{
					// Signal the mouseEnter event
					if (obj->ev.mouse._onMouseEnter)
						obj->ev.mouse.onMouseEnter(win, obj);
				}

				// Are we in the client area?
				if (llInClientArea)
				{
					//////////
					// Signal the mouseMove event
					//////
						if (obj->ev.mouse._onMouseMove)
						{
							obj->ev.mouse.onMouseMove(win, obj, 
														win->mouseCurrent.position.x - lrc.left, 
														win->mouseCurrent.position.y - lrc.top, 
														win->mouseCurrent.isCtrl, win->mouseCurrent.isAlt, win->mouseCurrent.isShift,
														win->obj->ev.mouse.thisClick);
						}

				} else {
					// We are in the non-client area

					//////////
					// Signal the mouseMove event in the non-client area, which means negative values, or
					// values outside of the width
					//
					// For non-client areas, we translate to negative is to the left or above the client area,
					// with values extending beyond the width and height if it is in the outer area
					//////
						*tlProcessed = true;	// Indicate we've processed this
						if (obj->ev.mouse._onMouseMove)
						{
							obj->ev.mouse.onMouseMove(win, obj, 
														win->mouseCurrent.position.x - lrcClient.left, 
														win->mouseCurrent.position.y - lrcClient.top, 
														win->mouseCurrent.isCtrl, win->mouseCurrent.isAlt, win->mouseCurrent.isShift,
														win->obj->ev.mouse.thisClick);
						}
				}

			} else {
				// We are outside of this object
				if (obj->ev.mouse.isMouseOver)
				{
					// Signal the mouseLeave event
					if (obj->ev.mouse._onMouseLeave)
						obj->ev.mouse.onMouseLeave(win, obj);
				}
			}


		//////////
		// Process any siblings
		//////
			if (tlProcessSiblings)
			{
				// Begin at the next sibling
				objSib = obj->ll.nextObject;
				while (objSib)
				{
					// Process this sibling
					iiMouse_processMouseEvents_mouseMove(win, objSib, rc, true, false, tlProcessed);

					// Move to next sibling
					objSib = objSib->ll.nextObject;
				}
			}
	}




//////////
//
// Called to signal a mouseDown event, then the mouseClickEx event
//
//////
	bool iiMouse_processMouseEvents_common(SWindow* win, SObject* obj, RECT* rc, UINT m, bool tlProcessChildren, bool tlProcessSiblings, bool* tlProcessed)
	{
		bool		llInClientArea, llContinue;
		RECT		lrc, lrcClient;
		SObject*	objSib;


		// Make sure our environment is sane
		llContinue = false;
		if (obj && propIsEnabled(obj) && obj->bmp)
		{
			// Get the rectangle we're in at this level
			llContinue		= true;
			llInClientArea	= iiMouse_processMouseEvents_getRectDescent(win, obj, rc, lrc, lrcClient);


			//////////
			// Process any children
			//////
				if (tlProcessChildren && obj->firstChild)
					llContinue = iiMouse_processMouseEvents_common(win, obj->firstChild, &lrcClient, m, true, true, tlProcessed);


			//////////
			// Are we still needing processing?
			//////
				if (!*tlProcessed)
				{
					// Indicate if the mouse is still down here
					obj->ev.mouse.isMouseDown = (obj->ev.mouse.thisClick != 0);

					// Are we in this object?
					if (llInClientArea)
					{
						// What was the mouse message?
						switch (m)
						{
							case WM_LBUTTONDOWN:
							case WM_RBUTTONDOWN:
							case WM_MBUTTONDOWN:
								// Signal the mouseDown event
								*tlProcessed = true;		// Indicate we've processed this
								if (llContinue && obj->ev.mouse._onMouseDown)
									llContinue = obj->ev.mouse.onMouseDown(	win, obj, 
																			win->mouseCurrent.position.x - lrc.left, 
																			win->mouseCurrent.position.y - lrc.top, 
																			win->mouseCurrent.isCtrl, win->mouseCurrent.isAlt, win->mouseCurrent.isShift,
																			win->obj->ev.mouse.thisClick);
								
								// Signal the click event
								if (llContinue && obj->ev.mouse._onMouseClickEx)
									llContinue = obj->ev.mouse.onMouseClickEx(	win, obj, 
																				win->mouseCurrent.position.x - lrc.left, 
																				win->mouseCurrent.position.y - lrc.top, 
																				win->mouseCurrent.isCtrl, win->mouseCurrent.isAlt, win->mouseCurrent.isShift,
																				win->obj->ev.mouse.thisClick);
									break;

							case WM_LBUTTONUP:
							case WM_RBUTTONUP:
							case WM_MBUTTONUP:
								// Signal the mouseUp event
								*tlProcessed = true;		// Indicate we've processed this
								if (llContinue && obj->ev.mouse._onMouseUp)
									llContinue = obj->ev.mouse.onMouseUp(	win, obj, 
																			win->mouseCurrent.position.x - lrc.left, 
																			win->mouseCurrent.position.y - lrc.top, 
																			win->mouseCurrent.isCtrl, win->mouseCurrent.isAlt, win->mouseCurrent.isShift,
																			win->obj->ev.mouse.thisClick);
								break;

							case WM_MOUSEWHEEL:
#ifdef WM_MOUSEHWHEEL
							case WM_MOUSEHWHEEL:
#endif
								// Signal the mouseWheel event
								*tlProcessed = true;		// Indicate we've processed this
								if (llContinue && obj->ev.mouse._onMouseWheel)
									llContinue = obj->ev.mouse.onMouseWheel(win, obj, 
																			win->mouseCurrent.position.x - lrc.left, 
																			win->mouseCurrent.position.y - lrc.top, 
																			win->mouseCurrent.isCtrl, win->mouseCurrent.isAlt, win->mouseCurrent.isShift,
																			win->obj->ev.mouse.thisClick,
																			win->mouseCurrent.wheelDeltaV);
								break;
						}

					} else if (PtInRect(&lrc, win->mouseCurrent.position)) {
						//////////
						// Signal the mouseMove event in the non-client area, which means negative values, or values
						// outside of the width.  For non-client areas, we translate to negative is to the left or
						// above the client area, with values extending beyond the width and height if it is in the
						// outer area
						//////
				

						// What was the mouse message?
						switch (m)
						{
							case WM_LBUTTONDOWN:
							case WM_RBUTTONDOWN:
							case WM_MBUTTONDOWN:
								// Signal the mouseDown event
								*tlProcessed = true;		// Indicate we've processed this
								if (llContinue && obj->ev.mouse._onMouseDown)
									llContinue = obj->ev.mouse.onMouseDown(	win, obj, 
																			win->mouseCurrent.position.x - lrcClient.left, 
																			win->mouseCurrent.position.y - lrcClient.top, 
																			win->mouseCurrent.isCtrl, win->mouseCurrent.isAlt, win->mouseCurrent.isShift,
																			win->obj->ev.mouse.thisClick);
								

								// Signal the click event
								if (llContinue && obj->ev.mouse._onMouseClickEx)
									llContinue = obj->ev.mouse.onMouseClickEx(	win, obj, 
																				win->mouseCurrent.position.x - lrcClient.left, 
																				win->mouseCurrent.position.y - lrcClient.top, 
																				win->mouseCurrent.isCtrl, win->mouseCurrent.isAlt, win->mouseCurrent.isShift,
																				win->obj->ev.mouse.thisClick);

							case WM_LBUTTONUP:
							case WM_RBUTTONUP:
							case WM_MBUTTONUP:
								// Signal the mouseUp event
								*tlProcessed = true;		// Indicate we've processed this
								if (llContinue && obj->ev.mouse._onMouseUp)
									llContinue = obj->ev.mouse.onMouseUp(	win, obj, 
																			win->mouseCurrent.position.x - lrcClient.left, 
																			win->mouseCurrent.position.y - lrcClient.top, 
																			win->mouseCurrent.isCtrl, win->mouseCurrent.isAlt, win->mouseCurrent.isShift,
																			win->obj->ev.mouse.thisClick);
								break;

							case WM_MOUSEWHEEL:
#ifdef WM_MOUSEHWHEEL
							case WM_MOUSEHWHEEL:
#endif
								// Signal the mouseWheel event
								*tlProcessed = true;		// Indicate we've processed this
								if (llContinue && obj->ev.mouse._onMouseWheel)
									llContinue = obj->ev.mouse.onMouseWheel(win, obj, 
																			win->mouseCurrent.position.x - lrcClient.left, 
																			win->mouseCurrent.position.y - lrcClient.top, 
																			win->mouseCurrent.isCtrl, win->mouseCurrent.isAlt, win->mouseCurrent.isShift,
																			win->obj->ev.mouse.thisClick,
																			win->mouseCurrent.wheelDeltaV);
								break;
						}
					}


				//////////
				// Process any siblings
				//////
					if (llContinue && tlProcessSiblings)
					{
						// Begin at the next sibling
						objSib = obj->ll.nextObject;
						while (llContinue && !*tlProcessed && objSib)
						{
							// Process this sibling
							llContinue = iiMouse_processMouseEvents_common(win, objSib, rc, m, true, false, tlProcessed);
							if (!llContinue)
								break;

							// Move to next sibling
							objSib = objSib->ll.nextObject;
						}
					}
			}
		}

		// Indicate if the caller should continue
		return(llContinue);
	}




// //////////
// //
// // Process the mouse events in the non-client area for this form
// //
// //////
// 	s32 iiMouse_processMouseEvents_nonclient(SWindow* win, UINT m, WPARAM w, LPARAM l)
// 	{
// 		s32			lnResult, lnDeltaX, lnDeltaY, lnWidth, lnHeight, lnLeft, lnTop;
// 		bool		llCtrl, llAlt, llShift, llLeft, llRight, llMiddle, llCaps;
// 		SObject*	obj;
// 		RECT		lrc;
// 		POINT		pt, ptScreen;
// 
// 
// 		//////////
// 		// Grab our pointer
// 		//////
// 			obj = win->obj;
// 
// 
// 		//////////
// 		// Determine mouse button and keyboard key attributes
// 		//////
// 			iiMouse_getFlags(&llCtrl, &llAlt, &llShift, &llLeft, &llMiddle, &llRight, &llCaps);
// 
// 
// 		//////////
// 		// Iterate through the known objects
// 		//////
// 			pt.x = win->mouseAdjustedPosition.x;
// 			pt.y = win->mouseAdjustedPosition.y;
// 
// 			// They clicked on something
// 			if (m == WM_LBUTTONDOWN)
// 			{
// 				// Close button
// 				if (PtInRect(&obj->rcClose, pt))
// 				{
// 					// Send the quit message
// 					PostQuitMessage(0);
// 
// 				// Minimize button
// 				} else if (PtInRect(&obj->rcMinimize, pt)) {
// 					// Minimize the window
// 					CloseWindow(win->hwnd);
// 
// 				} else {
// 					// The mouse has gone down in a nonclient area.
// 					// Note where the mouse went down in case they are beginning a move.
// 					win->mousePositionClick.x = pt.x;
// 					win->mousePositionClick.y = pt.y;
// 
// 					// Get the current mouse position
// 					GetCursorPos(&ptScreen);
// 					win->mousePositionClickScreen.x = ptScreen.x;
// 					win->mousePositionClickScreen.y = ptScreen.y;
// 				}
// 
// 			} else if (m == WM_MOUSEMOVE) {
// 				// The mouse is moving
// 				if (win->isMoving)
// 				{
// 					// Update to the new position
// 					// Get the current mouse position
// 					GetCursorPos(&ptScreen);
// 
// 					// Determine the deltas
// 					lnDeltaX = ptScreen.x - win->mousePositionClickScreen.x;
// 					lnDeltaY = ptScreen.y - win->mousePositionClickScreen.y;
// 
// 					// Position the window at that delta
// 					GetWindowRect(win->hwnd, &lrc);
// 
// 					// It has moved since the last positioning
// 					SetWindowPos(win->hwnd, NULL,
// 									obj->rc.left + lnDeltaX,
// 									obj->rc.top + lnDeltaY,
// 									obj->rc.right  - obj->rc.left,
// 									obj->rc.bottom - obj->rc.top,
// 									SWP_NOSIZE | SWP_NOREPOSITION);
// 
// 				} else if (win->isResizing) {
// 					// Update to the new size
// 
// 				} else if (!glIsMoving && !glIsResizing) {
// 					// They may be beginning a move or resize
// 					if (llLeft)
// 					{
// 						// Did they move in a button?
// 						if (!(PtInRect(&obj->rcIcon, pt) || PtInRect(&obj->rcMove, pt) || PtInRect(&obj->rcMinimize, pt) || PtInRect(&obj->rcMaximize, pt) || PtInRect(&obj->rcClose, pt)))
// 						{
// 							// Nope.  Are they moving in a resizing arrow?
// 							if (PtInRect(&obj->rcArrowUl, pt) || PtInRect(&obj->rcArrowUr, pt) || PtInRect(&obj->rcArrowLl, pt) || PtInRect(&obj->rcArrowLr, pt))
// 							{
// 								// We are beginning a resize
// 								win->isResizing	= true;
// 								glIsResizing	= true;
// 								SetCapture(win->hwnd);
// // TODO:  write the resizing code
// 
// 							} else {
// 								// We are beginning a move
// 								win->isMoving	= true;
// 								glIsMoving		= true;
// 								SetCapture(win->hwnd);
// 							}
// 						}
// 					}
// 				}
// 
// 			} else if (m == WM_LBUTTONUP) {
// 				// They've released the mouse
// 				if (win->isMoving)
// 				{
// 					// We're done moving
// 					win->isMoving	= false;
// 					glIsMoving		= false;
// 					ReleaseCapture();
// 
// 					// Get the current mouse position
// 					GetCursorPos(&ptScreen);
// 
// 					// Determine the deltas
// 					lnDeltaX = ptScreen.x - win->mousePositionClickScreen.x;
// 					lnDeltaY = ptScreen.y - win->mousePositionClickScreen.y;
// 
// 					// Position the window finally
// 					lnWidth		= obj->rc.right  - obj->rc.left;
// 					lnHeight	= obj->rc.bottom - obj->rc.top;
// 					lnLeft		= obj->rc.left   + lnDeltaX;
// 					lnTop		= obj->rc.top    + lnDeltaY;
// 					SetRect(&obj->rc, lnLeft, lnTop, lnLeft + lnWidth, lnTop + lnHeight);
// 
// 					// Position the window at that delta
// 					SetWindowPos(win->hwnd, NULL, lnLeft, lnTop, lnWidth, lnHeight, SWP_NOSIZE | SWP_NOREPOSITION);
// 
// 				} else if (win->isResizing) {
// 					// We're done resizing
// 					win->isResizing = false;
// 					glIsResizing	= false;
// 					ReleaseCapture();
// 
// 				} else {
// 					// The mouse is simply released.  How nice. :-)
// 					win->isMoving	= false;
// 					win->isResizing = false;
// 					glIsMoving		= false;
// 					glIsResizing	= false;
// 				}
// 			}
// 
// 
// 		// Indicate our status
// 		lnResult = 0;
// 		return(lnResult);
// 	}




//////////
//
// Based upon the WPARAM we determine the keys, except Alt, which is
// determined by the VK_MENU key's current state.
//
//////
	void iiMouse_getFlags_wparam(WPARAM w, bool* tlCtrl, bool* tlAlt, bool* tlShift, bool* tlLeft, bool* tlMiddle, bool* tlRight, bool* tlCaps, bool* tlAnyButton)
	{
		//////////
		// Obtain from WPARAM
		//////
			*tlCtrl			= ((w & MK_CONTROL)		!= 0);
			*tlAlt			= (GetKeyState(VK_MENU)	< 0);
			*tlShift		= ((w & MK_SHIFT)		!= 0);
			*tlLeft			= ((w & MK_LBUTTON)		!= 0);
			*tlRight		= ((w & MK_RBUTTON)		!= 0);
			*tlMiddle		= ((w & MK_MBUTTON)		!= 0);
			*tlAnyButton	= (*tlLeft || *tlMiddle || *tlRight);
	}




//////////
//
// Based upon the WPARAM we determine the keys, except Alt, which is
// determined by the VK_MENU key's current state.
//
//////
	void iiMouse_getFlags_async(bool* tlCtrl, bool* tlAlt, bool* tlShift, bool* tlLeft, bool* tlMiddle, bool* tlRight, bool* tlCaps, bool* tlAnyButton)
	{
		//////////
		// Grab each one asynchronously
		//////
			*tlCtrl			= ((GetAsyncKeyState(VK_CONTROL)	& 0x8000)	!= 0);
			*tlAlt			= (GetKeyState(VK_MENU)							< 0);
			*tlShift		= ((GetAsyncKeyState(VK_SHIFT)		& 0x8000)	!= 0);
			*tlLeft			= ((GetAsyncKeyState(VK_LBUTTON)	& 0x8000)	!= 0);
			*tlMiddle		= ((GetAsyncKeyState(VK_MBUTTON)	& 0x8000)	!= 0);
			*tlRight		= ((GetAsyncKeyState(VK_RBUTTON)	& 0x8000)	!= 0);
			*tlCaps			= (GetAsyncKeyState(VK_CAPITAL)		& 0x8000)	!= 0;
			*tlAnyButton	= (*tlLeft || *tlMiddle || *tlRight);
	}




//////////
//
// Process the indicated keystroke
//
//////
	s32 iKeyboard_processMessage(SWindow* win, UINT m, WPARAM vKey, LPARAM tnScanCode)
	{
		s16			lnAsciiChar;
		u32			lnI, lnScanCode, lnObjFocusControlsCount;
		SBuilder*	objFocusControls;
		SObject*	obj;
		bool		llCtrl, llAlt, llShift, llLeft, llMiddle, llRight, llCaps, llIsAscii, llIsCAS, llIsAnyMouseButtonDown;
		u8			keyboardState[256];


		//////////
		// Grab our key states
		//////
			iiMouse_getFlags_async(&llCtrl, &llAlt, &llShift, &llLeft, &llMiddle, &llRight, &llCaps, &llIsAnyMouseButtonDown);


		//////////
		// See if it's a printable character
		//////
			lnScanCode	= (tnScanCode & 0xff000) >> 12;
			lnAsciiChar	= 0;
			GetKeyboardState(&keyboardState[0]);
			llIsAscii	= (ToAscii((UINT)vKey, lnScanCode, &keyboardState[0], (LPWORD)&lnAsciiChar, 0) >= 1);


		//////////
		// Create buffers
		//////
			objFocusControls = NULL;
			iBuilder_createAndInitialize((SBuilder**)&objFocusControls,	64);


		//////////
		// Find out which objects within has focus
		//////
			iObj_findFocusControls(win->obj, objFocusControls, true);
			lnObjFocusControlsCount = objFocusControls->populatedLength / sizeof(SObject*);
			if (lnObjFocusControlsCount == 0)
				return(0);		// Nothing to process


		//////////
		// Determine if this keystroke is only a CTRL, SHIFT, or ALT.
		//////
			llIsCAS = (vKey == VK_SHIFT || vKey == VK_CONTROL || vKey == VK_MENU);


		//////////
		// Send it to each control with focus
		//////
			for (lnI = 0; lnI < lnObjFocusControlsCount; lnI++)
			{
				// Grab this object and its buffer
				obj	= *(SObject**)(objFocusControls->data_u8 + (lnI * sizeof(SObject*)));

				// Call the appropriate handler
				if (m == WM_KEYDOWN && obj->ev.keyboard._onKeyDown)
				{
					// Signal the down key event
					obj->ev.keyboard.onKeyDown	(win, obj, llCtrl, llAlt, llShift, llCaps, lnAsciiChar, (u16)vKey, llIsCAS, llIsAscii);

				} else if (m == WM_KEYUP && obj->ev.keyboard._onKeyUp) {
					// Signal the up key event
					obj->ev.keyboard.onKeyUp	(win, obj, llCtrl, llAlt, llShift, llCaps, lnAsciiChar, (u16)vKey, llIsCAS, llIsAscii);
				}
			}
		

		//////////
		// Release the focus control list
		//////
			if (objFocusControls)
				iBuilder_freeAndRelease(&objFocusControls);


		// All done
		return(0);
	}




//////////
//
// Called to load the cask icons from the icon tile image
//
//////
	void iVjr_init_loadCaskIcons(void)
	{
// TODO:  There's a BXML file with this information (cask_icons.bxml).
//        BXML support should be added to VJr and then that information used to do this, rather than by hard-coding.
#ifndef _OPPIE_COMPILE
		bmpCaskIconsTiled			= iBmp_rawLoad(cgc_caskIconsBmp);
#endif
		bmpCaskRoundLeft			= iBmp_createAndExtractRect(bmpCaskIconsTiled, 12, 2, 31, 38);
		bmpCaskRoundRight			= iBmp_createAndExtractRect(bmpCaskIconsTiled, 33, 2, 52, 38);
		bmpCaskSquareLeft			= iBmp_createAndExtractRect(bmpCaskIconsTiled, 12, 44, 31, 80);
		bmpCaskSquareRight			= iBmp_createAndExtractRect(bmpCaskIconsTiled, 33, 44, 52, 80);
		bmpCaskTriangleLeft			= iBmp_createAndExtractRect(bmpCaskIconsTiled, 2, 86, 31, 122);
		bmpCaskTriangleRight		= iBmp_createAndExtractRect(bmpCaskIconsTiled, 33, 86, 62, 122);
		bmpCaskTildeLeft			= iBmp_createAndExtractRect(bmpCaskIconsTiled, 125, 86, 142, 122);
		bmpCaskTildeRight			= iBmp_createAndExtractRect(bmpCaskIconsTiled, 144, 86, 161, 122);
		bmpCaskPips1				= iBmp_createAndExtractRect(bmpCaskIconsTiled, 54, 7, 65, 33);
		bmpCaskPips2				= iBmp_createAndExtractRect(bmpCaskIconsTiled, 67, 7, 78, 33);
		bmpCaskPips3				= iBmp_createAndExtractRect(bmpCaskIconsTiled, 80, 7, 91, 33);
		bmpCaskSideExtender			= iBmp_createAndExtractRect(bmpCaskIconsTiled, 72, 44, 76, 79);
		bmpCaskSideExtenderLeft		= iBmp_createAndExtractRect(bmpCaskIconsTiled, 54, 44, 58, 79);
		bmpCaskSideExtenderMiddle	= iBmp_createAndExtractRect(bmpCaskIconsTiled, 60, 44, 64, 79);
		bmpCaskSideExtenderRight	= iBmp_createAndExtractRect(bmpCaskIconsTiled, 66, 44, 70, 79);
		bmpCaskExtenderMiddle		= iBmp_createAndExtractRect(bmpCaskIconsTiled, 70, 86, 74, 122);
		bmpCaskExtenderLeft1		= iBmp_createAndExtractRect(bmpCaskIconsTiled, 64, 86, 68, 122);
		bmpCaskExtenderLeft2		= iBmp_createAndExtractRect(bmpCaskIconsTiled, 76, 86, 87, 122);
		bmpCaskExtenderRight2		= iBmp_createAndExtractRect(bmpCaskIconsTiled, 89, 86, 100, 122);
		bmpCaskExtenderRight1		= iBmp_createAndExtractRect(bmpCaskIconsTiled, 102, 86, 106, 122);

		// Grab the cask color masks
		caskOrange1					= iBmp_extractColorAtPoint(bmpCaskIconsTiled, 160, 18);
		caskOrange2					= iBmp_extractColorAtPoint(bmpCaskIconsTiled, 154, 18);
		caskOrange3					= iBmp_extractColorAtPoint(bmpCaskIconsTiled, 148, 18);
		caskRed1					= iBmp_extractColorAtPoint(bmpCaskIconsTiled, 160, 23);
		caskRed2					= iBmp_extractColorAtPoint(bmpCaskIconsTiled, 154, 23);
		caskRed3					= iBmp_extractColorAtPoint(bmpCaskIconsTiled, 148, 23);
		caskBlue1					= iBmp_extractColorAtPoint(bmpCaskIconsTiled, 160, 28);
		caskBlue2					= iBmp_extractColorAtPoint(bmpCaskIconsTiled, 154, 28);
		caskBlue3					= iBmp_extractColorAtPoint(bmpCaskIconsTiled, 148, 28);
		caskPurple1					= iBmp_extractColorAtPoint(bmpCaskIconsTiled, 160, 33);
		caskPurple2					= iBmp_extractColorAtPoint(bmpCaskIconsTiled, 154, 33);
		caskPurple3					= iBmp_extractColorAtPoint(bmpCaskIconsTiled, 148, 33);
		caskCyan1					= iBmp_extractColorAtPoint(bmpCaskIconsTiled, 160, 38);
		caskCyan2					= iBmp_extractColorAtPoint(bmpCaskIconsTiled, 154, 38);
		caskCyan3					= iBmp_extractColorAtPoint(bmpCaskIconsTiled, 148, 38);
		caskGreen1					= iBmp_extractColorAtPoint(bmpCaskIconsTiled, 160, 43);
		caskGreen2					= iBmp_extractColorAtPoint(bmpCaskIconsTiled, 154, 43);
		caskGreen3					= iBmp_extractColorAtPoint(bmpCaskIconsTiled, 148, 43);
		caskYellow1					= iBmp_extractColorAtPoint(bmpCaskIconsTiled, 160, 48);
		caskYellow2					= iBmp_extractColorAtPoint(bmpCaskIconsTiled, 154, 48);
		caskYellow3					= iBmp_extractColorAtPoint(bmpCaskIconsTiled, 148, 48);
		caskGray1					= iBmp_extractColorAtPoint(bmpCaskIconsTiled, 160, 53);
		caskGray2					= iBmp_extractColorAtPoint(bmpCaskIconsTiled, 154, 53);
		caskGray3					= iBmp_extractColorAtPoint(bmpCaskIconsTiled, 148, 53);
		caskWhite1					= iBmp_extractColorAtPoint(bmpCaskIconsTiled, 160, 58);
		caskWhite2					= iBmp_extractColorAtPoint(bmpCaskIconsTiled, 154, 58);
		caskWhite3					= iBmp_extractColorAtPoint(bmpCaskIconsTiled, 148, 58);
		caskBlack1					= iBmp_extractColorAtPoint(bmpCaskIconsTiled, 160, 63);
		caskBlack2					= iBmp_extractColorAtPoint(bmpCaskIconsTiled, 154, 63);
		caskBlack3					= iBmp_extractColorAtPoint(bmpCaskIconsTiled, 148, 63);
	}




//////////
//
// Called to build the listing along the right side, which is a subform with
// an editbox contained within to hold the items.
//
//////
	void iVjr_createOverlayListing(SBitmap* bmp, RECT* trc)
	{
		//////////
		// Create the object
		//////
			// Create object
			gobj_splashListing = iObj_create(_OBJ_TYPE_SUBFORM, NULL);
			if (!gobj_splashListing)
				return;

			// Set the icon and border
			iObjProp_set_bitmap_direct(gobj_splashListing, _INDEX_ICON, bmpOutputIcon);
			iObjProp_set_s32_direct(gobj_splashListing, _INDEX_BORDERSTYLE, _BORDER_STYLE_FIXED);


		//////////
		// Give it a caption
		//////
			propSetCaption(gobj_splashListing, cgcSystemLog);


		//////////
		// Size and position it
		//////
			iObj_setSize(gobj_splashListing, trc->left, trc->top, trc->right - trc->left, bmp->bi.biHeight);
			gobj_splashListing->bmp = iBmp_allocate();
			iBmp_createBySize(gobj_splashListing->bmp, trc->right - trc->left, trc->bottom - trc->top, bmp->bi.biBitCount);


		//////////
		// Add the editbox
		//////
			gobj_splashListingEditbox							= iObj_addChild(_OBJ_TYPE_EDITBOX,	gobj_splashListing);
			iObj_setSize(gobj_splashListingEditbox, 0, 0, gobj_splashListing->rcClient.right - gobj_splashListing->rcClient.left, gobj_splashListing->rcClient.bottom - gobj_splashListing->rcClient.top);
			gobj_splashListingEditbox->bmp = iBmp_allocate();
			iBmp_createBySize(gobj_splashListingEditbox->bmp, gobj_splashListing->rcClient.right - gobj_splashListing->rcClient.left, gobj_splashListing->rcClient.bottom - gobj_splashListing->rcClient.top, bmp->bi.biBitCount);
			gobj_splashListingEditbox->p.font					= iFont_create(cgcFontName_defaultFixed, 8, FW_NORMAL, false, false);
			gobj_splashListingEditbox->p.sem->font				= iFont_create(cgcFontName_defaultFixed, 8, FW_NORMAL, false, false);
			gobj_splashListingEditbox->ev.keyboard._onKeyDown	= (uptr)&iSEM_onKeyDown;
			iObjProp_set_logical_direct(gobj_splashListingEditbox, _INDEX_VISIBLE, _LOGICAL_TRUE);
			systemLog											= gobj_splashListingEditbox->p.sem;
			systemLog->showEndLine								= true;
			systemLog->showCursorLine							= true;


		//////////
		// Set it visible
		//////
			iObjProp_set_logical_direct(gobj_splashListing, _INDEX_VISIBLE, _LOGICAL_TRUE);
	}




//////////
//
// Called to render the listing.
//
//////
	void iVjr_renderOverlayListing(SBitmap* bmp, RECT* trc)
	{
		RECT lrc;


		// Make sure our environment is sane
		if (gobj_splashListing && gobj_splashListingEditbox)
		{
			// Move to the end of the list
			iSEM_navigateToEndLine(gobj_splashListingEditbox->p.sem, gobj_splashListing);

			if (trc && gobj_splashListing->bmp)
			{
				// Render
				iObj_renderChildrenAndSiblings(gobj_splashListing, true, true, true);

				// Publish it if we can
				if (bmp)
				{
					// Publish
					SetRect(&lrc, 0, 0, gobj_splashListing->bmp->bi.biWidth, gobj_splashListing->bmp->bi.biHeight);
					iObj_publish(gobj_splashListing, &lrc, bmp, true, true, true, 0);

					// Update our bitmap
					iBmp_bitBlt(bmp, trc, gobj_splashListing->bmp);

					// Redraw it on the OS
					InvalidateRect(gSplash.hwnd, 0, false);
				}
			}
		}
	}




//////////
//
// Physically render the accomplishment
//
//////
	#define _RED	0
	#define _AMBER	1
	#define _GREEN	2
	#define _BLUE	3

	void iiVjr_renderAccomplishment(SBitmap* bmp, RECT* trc, s32 tnRAGB, s8* tcAccomplishment, s8* tcVersion, bool tlBold, bool tlItalic, bool tlUnderline, s32 tnAdjustAccomplishmentFontSize, s32 tnAdjustVersionFontSize)
	{
		s32			lnWidthAccomplishment;//, lnWidthVersion;
		RECT		lrc, lrc2, lrcAccomplishment, lrcVersion;
		SBgra		baseColor, leftColor, rightColor;
		SFont*		font8;
		SFont*		font9;
		COLORREF	textColor;


		//////////
		// Construct the fonts
		//////
			font8 = iFont_create(cgcFontName_default, 8 + tnAdjustVersionFontSize,			((tlBold) ? FW_BOLD : FW_NORMAL), 0,					0);
			font9 = iFont_create(cgcFontName_default, 9 + tnAdjustAccomplishmentFontSize,	((tlBold) ? FW_BOLD : FW_NORMAL), ((tlItalic) ? 1 : 0), ((tlUnderline) ? 1 : 0));


		//////////
		// Determine how big the accomplishment and version texts are
		//////
			SelectObject(bmp->hdc, font9->hfont);
			SetRect(&lrcAccomplishment, 0, 0, bmp->bi.biWidth, bmp->bi.biHeight);
			DrawText(bmp->hdc, tcAccomplishment, (int)strlen(tcAccomplishment), &lrcAccomplishment, DT_SINGLELINE | DT_LEFT | DT_CALCRECT);


		//////////
		// Compute the size of the version text
		//////
			if (tcVersion)
			{
				// There is a version
				SelectObject(bmp->hdc, font8->hfont);
				SetRect(&lrcVersion, 0, 0, bmp->bi.biWidth, bmp->bi.biHeight);
				DrawText(bmp->hdc, tcVersion, (int)strlen(tcVersion), &lrcVersion, DT_SINGLELINE | DT_LEFT | DT_CALCRECT);

			} else {
				// No version
				SetRect(&lrcVersion, 0, 0, 0, 0);
			}

		
		//////////
		// Build our target size rectangle
		//////
			lnWidthAccomplishment	= lrcAccomplishment.right - lrcAccomplishment.left;
//			lnWidthVersion			= lrcVersion.right - lrcVersion.left;
//			s32 lnWidth				= bmpStoplightRed->bi.biWidth + 4 + lnWidthVersion + ((lnWidthVersion != 0) ? 12 : 0) + lnWidthAccomplishment + 4;
			SetRect(&lrc, trc->left/*trc->right - lnWidth*/, trc->top, trc->right, trc->top + bmpStoplightRed->bi.biHeight);


		//////////
		// Fill it with the gradient color
		//////
			switch (tnRAGB)
			{
				case _RED:
					baseColor = iBmp_extractColorAtPoint(bmpStoplightRed, bmpStoplightRed->bi.biWidth / 2, bmpStoplightRed->bi.biHeight / 2);
					break;

				case _AMBER:
					baseColor = iBmp_extractColorAtPoint(bmpStoplightAmber, bmpStoplightAmber->bi.biWidth / 2, bmpStoplightAmber->bi.biHeight / 2);
					break;

				case _GREEN:
					baseColor = iBmp_extractColorAtPoint(bmpStoplightGreen, bmpStoplightGreen->bi.biWidth / 2, bmpStoplightGreen->bi.biHeight / 2);
					break;

				default:
				case _BLUE:
					baseColor	= iBmp_extractColorAtPoint(bmpStoplightBlue, bmpStoplightBlue->bi.biWidth / 2, bmpStoplightBlue->bi.biHeight / 2);
					break;
			}
			leftColor = iBmp_colorCombine(baseColor, whiteColor, 0.50f);
			CopyRect(&lrc2, &lrc);
			lrc2.left	+= bmpStoplightRed->bi.biWidth;
			lrc2.right	= (lrc2.right - lrc2.left) / 4;
			iBmp_fillRect(bmp, &lrc2, leftColor, whiteColor, leftColor, whiteColor, true, NULL, false);

			lrc2.left	= lrc2.right;
			lrc2.right	= lrc.right;
			rightColor	= iBmp_colorCombine(baseColor, whiteColor, 0.10f);
			iBmp_fillRect(bmp, &lrc2, whiteColor, rightColor, whiteColor, rightColor, true, NULL, false);


		//////////
		// Overlay the appropriate signal
		//////
			switch (tnRAGB)
			{
				case _RED:
					iBmp_bitBlt(bmp, &lrc, bmpStoplightRed);
					textColor = RGB(128,32,32);
					break;

				case _AMBER:
					iBmp_bitBlt(bmp, &lrc, bmpStoplightAmber);
					textColor = RGB(112,92,64);
					break;

				case _GREEN:
					iBmp_bitBlt(bmp, &lrc, bmpStoplightGreen);
					textColor = RGB(16,128,16);
					break;

				default:
				case _BLUE:
					iBmp_bitBlt(bmp, &lrc, bmpStoplightBlue);
					textColor = RGB(32,32,128);
					break;
			}


		//////////
		// Add in the version
		//////
			// Move over for the next text (either version or accomplishment)
			++lrc.top;
			lrc.left += bmpStoplightRed->bi.biWidth + 4;
			if (tcVersion)
			{
				// Draw the version
				SelectObject(bmp->hdc, font8->hfont);
				SetTextColor(bmp->hdc, textColor);
				SetBkMode(bmp->hdc, TRANSPARENT);
				DrawText(bmp->hdc, tcVersion, (int)strlen(tcVersion), &lrc, DT_SINGLELINE | DT_LEFT);
			}


		//////////
		// Add in the accomplishment
		//////
			// SEt for the accomplishment
			lrc.left = trc->right - lnWidthAccomplishment - 4;
			SelectObject(bmp->hdc, font9->hfont);
			SetTextColor(bmp->hdc, textColor);
			SetBkMode(bmp->hdc, TRANSPARENT);
			DrawText(bmp->hdc, tcAccomplishment, (int)strlen(tcAccomplishment), &lrc, DT_SINGLELINE | DT_LEFT);


		//////////
		// Draw a frame around this region so it marks the boundaries
		//////
			SetRect(&lrc, 0, 0, trc->right, trc->top + bmpStoplightRed->bi.biHeight);
			iBmp_frameRect(bmp, &lrc, blackColor, blackColor, blackColor, blackColor, false, NULL, false);


		//////////
		// Adjust the next rect down for the next one
		//////
			trc->top	+= bmpStoplightRed->bi.biHeight;
			trc->bottom	+= bmpStoplightRed->bi.biHeight;
	}





//////////
//
// Overlay the accomplishments in this release/version.
//
//////
	void iVjr_renderAccomplishments(SBitmap* bmp, RECT* trc)
	{
		RECT lrc;


		// Begin at the top
		CopyRect(&lrc, trc);

		// System log
		iiVjr_renderAccomplishment(bmp, &lrc, _BLUE, "Forms working (future, James 4:15)",			"0.70", false, false, false, -2, 0);
		iiVjr_renderAccomplishment(bmp, &lrc, _BLUE, "Compiler completed (future, James 4:15)",		"0.65", false, false, false, -2, 0);
		iiVjr_renderAccomplishment(bmp, &lrc, _BLUE, "Running programs (future, James 4:15)",		"0.60", false, false, false, -2, 0);

		iiVjr_renderAccomplishment(bmp, &lrc, _GREEN, "Native 32-bit and 64-bit Versions",			"0.55", false, false, false, 0, 0);

		iiVjr_renderAccomplishment(bmp, &lrc, _GREEN, "Support for Shift+Spaces in names",			"0.54", false, false, false, -2, 0);

		iiVjr_renderAccomplishment(bmp, &lrc, _GREEN, "Internal Property refactoring",				"0.54", false, false, false, -2, 0);

		iiVjr_renderAccomplishment(bmp, &lrc, _GREEN, "CHRTRAN() and STRTRAN()",					"0.52", false, false, false, -2, 0);

		iiVjr_renderAccomplishment(bmp, &lrc, _GREEN, "Bug fixes, memory leaks removed",			"0.51", false, false, false, -2, 0);

		iiVjr_renderAccomplishment(bmp, &lrc, _GREEN, "Editor highlights word under cursor",		"0.50", false, false, false, -2, 0);
		iiVjr_renderAccomplishment(bmp, &lrc, _GREEN, "UI redesign geared toward debugger",			"0.50", false, false, false, -2, 0);

//		iiVjr_renderAccomplishment(bmp, &lrc, _GREEN, "Editor development",							"0.49", false, false, false, -2, 0);

//		iiVjr_renderAccomplishment(bmp, &lrc, _GREEN, "Editor line numbers, breakpoints",			"0.48", false, false, false, -2, 0);

		iiVjr_renderAccomplishment(bmp, &lrc, _GREEN, "Editor resize CTRL+ and CTRL-",				"0.47", false, false, false, -2, 0);

//		iiVjr_renderAccomplishment(bmp, &lrc, _GREEN, "Casks",										"0.46", false, true, false, -2, 0);

// Planned:
//		iiVjr_renderAccomplishment(bmp, &lrc, _BLUE,  "Syntax highlighting (future, James 4:15)",	"0.50", false, false, false, -2, 0);
		iiVjr_renderAccomplishment(bmp, &lrc, _GREEN, "Syntax highlighting",						"0.45", false, true, false, -2, 0);

// 		iiVjr_renderAccomplishment(bmp, &lrc, _GREEN, "Tabs expanded, mouse wheel",					"0.44", false, true, false, -2, 0);

		iiVjr_renderAccomplishment(bmp, &lrc, _AMBER, "TRANSFORM() partially supported",			"0.43", false, true, false, -1, 0);
//		iiVjr_renderAccomplishment(bmp, &lrc, _GREEN, "PADC(), PADL(), PADR()",						"0.43", false, true, false, -2, 0);
// 		iiVjr_renderAccomplishment(bmp, &lrc, _GREEN, "OCCURS(), OCCURSC()",						"0.43", false, true, false, -2, 0);
// 		iiVjr_renderAccomplishment(bmp, &lrc, _GREEN, "AT(), ATC(), RAT(), RATC()",					"0.43", false, true, false, -2, 0);

// 		iiVjr_renderAccomplishment(bmp, &lrc, _GREEN, "Bugfix on function parsing",					"0.42", false, true, false, -2, 0);

// 		iiVjr_renderAccomplishment(bmp, &lrc, _GREEN, "System log",									"0.41", false, true, false, -2, 0);
//		iiVjr_renderAccomplishment(bmp, &lrc, _GREEN, "Focus highlight border bugfix",				"0.41", false, true, false, -2, 0);
//		iiVjr_renderAccomplishment(bmp, &lrc, _GREEN, "Memory leak bug fixes",						"0.41", false, true, false, -2, 0);

// 		iiVjr_renderAccomplishment(bmp, &lrc, _GREEN, "Sound support",								"0.40", false, true, false, -2, 0);

//		iiVjr_renderAccomplishment(bmp, &lrc, _GREEN, "Focus highlight border",						"0.39", false, true, false, -2, 0);
 		iiVjr_renderAccomplishment(bmp, &lrc, _AMBER, "Tooltips framed (hover framed)",				"0.39", false, true, false, -1, 0);
// 		iiVjr_renderAccomplishment(bmp, &lrc, _GREEN, "_screen editable",							"0.39", false, true, false, -2, 0);

//		iiVjr_renderAccomplishment(bmp, &lrc, _GREEN, "MinGW GCC 4.8.1 and CodeLite",				"0.38", false, true, false, -2, 0);
	}
