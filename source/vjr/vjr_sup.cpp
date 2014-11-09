//////////
//
// /libsf/source/vjr/vjr_sup.cpp
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
				if (!GetClassInfoExA(ghInstance, cgcMessageWindowClass, &classa))
				{
					// Initialize
					memset(&classa, 0, sizeof(classa));

					// Populate
					classa.cbSize				= sizeof(WNDCLASSEXA);
					classa.hInstance			= ghInstance;
					classa.lpszClassName		= cgcMessageWindowClass;
					classa.lpfnWndProc			= &iWindow_wndProcMessage;

					// Register
					atom = RegisterClassExA(&classa);
					if (!atom)
						break;
				}



			//////////
			// Create the message window
			//////
				ghwndMsg = CreateWindowA(cgcMessageWindowClass, cgcMessageWindowClass, 0, 0, 0, 0, 0, HWND_MESSAGE, NULL, ghInstance, 0);
				if (ghwndMsg)
				{
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
	bool isValidWindow(u32 w)
	{
		return(w >= (u32)gWindows->data && w < (u32)(gWindows->data + gWindows->populatedLength));
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
	LRESULT CALLBACK iWindow_wndProcMessage(HWND hwnd, UINT m, WPARAM w, LPARAM l)
	{
		// Call Windows' default procedure handler
		return(DefWindowProc(hwnd, m, w, l));
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
			setPictureBmp(_jdebi, bmpJDebiIcon);
			setBorderStyle(_jdebi, _BORDER_STYLE_FIXED);

			// Give it a fixed point font
			_jdebi->p.font = iFont_create((s8*)cgcFontName_defaultFixed, 10, FW_MEDIUM, false, false);


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
			setIcon(sourceCode,		bmpSourceCodeIcon);
			setIcon(locals,			bmpLocalsIcon);
			setIcon(watch,			bmpWatchIcon);
			setIcon(command,		bmpCommandIcon);
			setIcon(debug,			bmpDebugIcon);
			setIcon(output,			bmpOutputIcon);
			setIcon(sourceLight,	bmpSourceLightIcon);
			setIcon(_screen,		bmpVjrIcon);
			setIcon(_jdebi,			bmpJDebiIcon);

			// Make them visible
			setVisible(sourceCode,	_LOGICAL_TRUE);
			setVisible(locals,		_LOGICAL_TRUE);
			setVisible(watch,		_LOGICAL_TRUE);
			setVisible(command,		_LOGICAL_TRUE);
			setVisible(sourceLight,	_LOGICAL_TRUE);
			setVisible(_screen,		_LOGICAL_TRUE);


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
			setVisible(sourceCode_editbox,	_LOGICAL_TRUE);
			setVisible(locals_editbox,		_LOGICAL_TRUE);
			setVisible(watch_editbox,		_LOGICAL_TRUE);
			setVisible(command_editbox,		_LOGICAL_TRUE);
			setVisible(debug_editbox,		_LOGICAL_TRUE);
			setVisible(output_editbox,		_LOGICAL_TRUE);
			setVisible(screen_editbox,		_LOGICAL_TRUE);
			setVisible(sourceLight_empty,	_LOGICAL_TRUE);


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
			setCaption(_jdebi, cgcJDebiTitle);


		//////////
		// SourceCode window caption and font
		//////
			setBackStyle(sourceCode, _BACK_STYLE_TRANSPARENT);
			setCaption(sourceCode, cgcSourceCodeTitle);

			// Adjust the caption width
			((SObject*)sourceCode->firstChild->ll.next)->rc.right = 90;

			sourceCode_editbox->p.font					= iFont_create((s8*)cgcFontName_defaultFixed, 10, FW_MEDIUM, false, false);
			sourceCode_editbox->ev.keyboard._onKeyDown	= (u32)&iSEM_onKeyDown_sourceCode;
			setBorderStyle(sourceCode_editbox, _BORDER_STYLE_FIXED);
			setBorderColor(sourceCode_editbox, lineNumberBackColor);
			sourceCode_editbox->p.sem->showCursorLine	= true;
			sourceCode_editbox->p.sem->isSourceCode		= true;
			sourceCode_editbox->p.sem->showLineNumbers	= true;


		//////////
		// Locals window caption and font
		//////
// TODO:  Working here...
			iObjProp_set_character_direct(locals, _INDEX_CAPTION, cgcLocalsTitle, sizeof(cgcLocalsTitle) - 1);
			locals_editbox->p.font					= iFont_create((s8*)cgcFontName_defaultFixed, 10, FW_MEDIUM, false, false);
			locals_editbox->ev.keyboard._onKeyDown	= (u32)&iSEM_onKeyDown;

			// Adjust the caption width
			((SObject*)locals->firstChild->ll.next)->rc.right = 65;


		//////////
		// Watch window caption and font
		//////
			iObjProp_set_character_direct(watch, _INDEX_CAPTION, cgcWatchTitle, sizeof(cgcWatchTitle) - 1);
			watch_editbox->p.font					= iFont_create((s8*)cgcFontName_defaultFixed, 10, FW_MEDIUM, false, false);
			watch_editbox->ev.keyboard._onKeyDown	= (u32)&iSEM_onKeyDown;
			watch_editbox->p.sem->showCursorLine		= true;

			// Adjust the caption width
			((SObject*)watch->firstChild->ll.next)->rc.right = 65;


		//////////
		// Command window caption and font
		//////
			iObjProp_set_character_direct(command, _INDEX_CAPTION, cgcCommandTitle, sizeof(cgcCommandTitle) - 1);
			command_editbox->p.font					= iFont_create((s8*)cgcFontName_defaultFixed, 10, FW_MEDIUM, false, false);
			command_editbox->ev.keyboard._onKeyDown		= (u32)&iSEM_onKeyDown_sourceCode;
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
			debug_editbox->p.font					= iFont_create((s8*)cgcFontName_defaultFixed, 10, FW_MEDIUM, false, false);
			debug_editbox->ev.keyboard._onKeyDown	= (u32)&iSEM_onKeyDown;
			debug_editbox->p.sem->showCursorLine		= true;

			// Adjust the caption width
			((SObject*)debug->firstChild->ll.next)->rc.right = 65;


		//////////
		// Output window caption and font
		//////
			iObjProp_set_character_direct(output, _INDEX_CAPTION, cgcOutputTitle, sizeof(cgcOutputTitle) - 1);
			output_editbox->p.font					= iFont_create((s8*)cgcFontName_defaultFixed, 8, FW_MEDIUM, false, false);
			output_editbox->ev.keyboard._onKeyDown	= (u32)&iSEM_onKeyDown;
			output_editbox->p.sem->showCursorLine	= true;

			// Adjust the caption width
			((SObject*)output->firstChild->ll.next)->rc.right = 70;


		//////////
		// SourceLight a caption and font
		//////
			iObjProp_set_character_direct(sourceLight, _INDEX_CAPTION, cgcSourceLightTitle, sizeof(cgcSourceLightTitle) - 1);
			sourceLight->p.font = iFont_create((s8*)cgcFontName_defaultFixed, 10, FW_MEDIUM, false, false);
			setVisible(sourceLight, _LOGICAL_TRUE);
			setBackStyle(sourceLight, _BACK_STYLE_OPAQUE);
			sourceLight_empty->ev.general._onRender = (u32)&iSourceLight_copy;


		//////////
		// _screen a caption and font
		//////
			iObjProp_set_character_direct(_screen, _INDEX_CAPTION, cgcScreenTitle, sizeof(cgcScreenTitle) - 1);
			_screen->p.font = iFont_create((s8*)cgcFontName_defaultFixed, 10, FW_MEDIUM, false, false);


		//////////
		// Setup _screen's editbox
		//////
			screen_editbox->p.font					= iFont_create((s8*)cgcFontName_defaultFixed, 10, FW_MEDIUM, false, false);
			screen_editbox->ev.keyboard._onKeyDown	= (u32)&iSEM_onKeyDown;
			screenData								= screen_editbox->p.sem;
			screenData->showCursorLine				= true;
			screenData->showEndLine					= true;
			setVisible(_screen, _LOGICAL_TRUE);


		//////////
		// Set it visible
		//////
			setVisible(_jdebi, _LOGICAL_TRUE);
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
			iDatum_duplicate(&_datetime_Jan_01_2000->value, (s8*)&dt, 8);
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
	void iVjr_appendSystemLog(s8* tcLogText)
	{
		s8 buffer[2048];


		// Lock it down
		EnterCriticalSection(&cs_logData);

		// Append to it
		sprintf(buffer, "[%u] %s\0", (u32)((s64)GetTickCount() - systemStartedTickCount), tcLogText);
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
		iSEM_saveToDisk(systemLog, (s8*)cgcSystemLogFilename);
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
		iVjr_appendSystemLog("Unengage VJr");

		// Tell OS to unengage our process
		iVjr_appendSystemLog("Notify OS to shutdown");

		// Flush the log
		iVjr_flushSystemLog();

		// Save where we were
		iSEM_saveToDisk(screenData,				(s8*)cgcScreenDataFilename);
		iSEM_saveToDisk(command_editbox->p.sem,	(s8*)cgcCommandHistoryFilename);

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
		if (!GetClassInfoExA(ghInstance, cgcSplashClass, &classex))
		{
			// Initialize
			memset(&classex, 0, sizeof(classex));

			// Populate
			classex.cbSize				= sizeof(WNDCLASSEXA);
			classex.hInstance			= ghInstance;
			classex.style				= CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
			classex.lpszClassName		= cgcSplashClass;
			classex.hCursor				= LoadCursor(NULL, IDC_ARROW);
			classex.lpfnWndProc			= &iSplash_wndProc;

			// Register
			RegisterClassExA(&classex);
		}

		// Create the window
		GetWindowRect(GetDesktopWindow(), &lrcWindow);
		lnLeft	= ((lrcWindow.right  - lrcWindow.left) / 2) - (gSplash.bmp->bi.biWidth  / 2);
		lnTop	= ((lrcWindow.bottom - lrcWindow.top)  / 2) - (gSplash.bmp->bi.biHeight / 2);
		gSplash.hwnd = CreateWindowEx(WS_EX_TOPMOST, cgcSplashClass, NULL, WS_POPUP, 
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
		SetTimer(gSplash.hwnd, (u32)&gSplash, 250, 0);

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
		iVjr_appendSystemLog("Splash screen unengaged");

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
			Sleep((u32)lpParameter);

			// Log it
			iVjr_appendSystemLog("Splash screen can unengage");

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
		s8		buffer[256];


		// Load the sound file (if it exists)
		if (iFile_readContents((s8*)lpParameter, NULL, &soundData_s8, &soundCount))
		{
			// Log it
			sprintf(buffer, "Engage %s\0", (s8*)lpParameter);
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
			sprintf(buffer, "Unengage %s\0", (s8*)lpParameter);
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
			sprintf(buffer, "Inquiry on sound file %s\0", (s8*)lpParameter);
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
					// Lock down
					EnterCriticalSection(&winNew->cs);

					// Initialize
					memset(buffer, 0, sizeof(buffer));

					// Populate
					lnWidth		= obj->rc.right - obj->rc.left;
					lnHeight	= obj->rc.bottom - obj->rc.top;
					CopyRect(&winNew->rc, &obj->rc);
					winNew->obj = obj;

					// Create our accumulation buffer
					winReuse->bmp = iBmp_allocate();
					iBmp_createBySize(winReuse->bmp, lnWidth, lnHeight, 24);


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
							memcpy(buffer, var->value.data,	min(var->value.length, sizeof(buffer) - 1));
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
						if (isVisible(obj))
							ShowWindow(winNew->hwnd, SW_SHOW);

					// Unlock
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
			// Iterate to delete all windows
			//////
				for (lnI = 0; lnI < windows->populatedLength; lnI += sizeof(SWindow))
				{
					// Grab this pointer
					win = (SWindow*)(windows->data + lnI);

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
				win = (SWindow*)(gWindows->data + lnI);

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
			win = (SWindow*)(gWindows->data + lnI);

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
			win = (SWindow*)(gWindows->data + lnI);

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


void iTest_nodeLine(SBitmap* bmp, f32 lfFactorX, f32 lfFactorY)
{
	s32		lnI, lnWidth;
	SXYF32*	points1;
	SXYF32*	points2;
	SXYF32	p1, p2, p3, p4, p5;
	f32		lfWidth, lfHeight;


	lfWidth  = bmp->bi.biWidth  * lfFactorX / 8.0f;
	lfHeight = bmp->bi.biHeight * lfFactorY / 8.0f;

	p1.x = ((f32)bmp->bi.biWidth  / 2.0f) - (lfWidth / 2.0f);
	p1.y = ((f32)bmp->bi.biHeight / 2.0f) - (lfHeight / 2.0f);

	p2.x = ((f32)bmp->bi.biWidth  / 2.0f) - (lfWidth / 4.0f);
	p2.y = ((f32)bmp->bi.biHeight / 2.0f) - (lfHeight / 2.0f);

	p3.x = ((f32)bmp->bi.biWidth  / 2.0f);
	p3.y = ((f32)bmp->bi.biHeight / 2.0f);
	points1 = iivvm_canvasBezier3(20, &p1, &p2, &p3);

	p4.x = ((f32)bmp->bi.biWidth  / 2.0f) + (lfWidth / 4.0f);
	p4.y = ((f32)bmp->bi.biHeight / 2.0f) + (lfHeight / 2.0f);

	p5.x = ((f32)bmp->bi.biWidth  / 2.0f) + (lfWidth / 2.0f);
	p5.y = ((f32)bmp->bi.biHeight / 2.0f) + (lfHeight / 2.0f);
	points2 = iivvm_canvasBezier3(20, &p5, &p4, &p3);

	lnWidth = 5;
	for (lnI = 0; lnI < 20 - 1; lnI++)
	{
		iBmp_drawArbitraryQuad(bmp, (s32)points1[lnI].x, (s32)points1[lnI].y, (s32)points1[lnI+1].x, (s32)points1[lnI+1].y, lnWidth, true, blackColor);
		iBmp_drawArbitraryQuad(bmp, (s32)points2[lnI].x, (s32)points2[lnI].y, (s32)points2[lnI+1].x, (s32)points2[lnI+1].y, lnWidth, true, blackColor);
	}
	--lnI;
	iBmp_drawArbitraryQuad(bmp, (s32)points1[lnI].x, (s32)points1[lnI].y, (s32)points2[lnI].x, (s32)points2[lnI].y, lnWidth, true, blackColor);
	free(points1);
	free(points2);
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

iTest_nodeLine(win->obj->bmp, 1.0f, 1.0f);
iTest_nodeLine(win->obj->bmp, 5.0f, 1.75f);
iTest_nodeLine(win->obj->bmp, 7.0f, 1.50f);
iTest_nodeLine(win->obj->bmp, 7.0f, 7.0f);
iTest_nodeLine(win->obj->bmp, 5.0f, 7.0f);
iTest_nodeLine(win->obj->bmp, 3.0f, 7.0f);
iTest_nodeLine(win->obj->bmp, 1.0f, 7.0f);

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
		if (gWindows && win && (u32)win >= (u32)gWindows->data && (u32)win <= ((u32)gWindows->data + gWindows->populatedLength))
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
			if (!GetClassInfoEx(GetModuleHandle(NULL), cgcFocusHighlightClass, &wcex))
			{
				// We need to create said class with our class making skills
				// If we get here, not yet registered
				memset(&wcex, 0, sizeof(wcex));
				wcex.cbSize         = sizeof(wcex);
				wcex.style          = CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
				wcex.lpfnWndProc    = &iFocusHighlight_wndProc;
				wcex.hInstance      = GetModuleHandle(NULL);
				wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
				wcex.lpszClassName  = cgcFocusHighlightClass;
				atom				= RegisterClassExA(&wcex);

				// Was it registered?
				if (!atom)
					return;		// Nope ... when we get here, failure
			}


		//////////
		// Create the window
		//////
			focus->hwnd = CreateWindowEx(WS_EX_TOOLWINDOW, cgcFocusHighlightClass, NULL, WS_POPUP, rc->left, rc->top, rc->right - rc->left, rc->bottom - rc->top, NULL, NULL, GetModuleHandle(NULL), 0);


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
				focus = (SFocusHighlight*)(gFocusHighlights->data + lnI);

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
			focus = (SFocusHighlight*)(gFocusHighlights->data + lnI);

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
			focus = (SFocusHighlight*)(gFocusHighlights->data + lnI);

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
				if (isReadonly(focus->obj))
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
			if (!GetClassInfoEx(GetModuleHandle(NULL), cgcTooltipClass, &wcex))
			{
				// We need to create said class with our class making skills
				// If we get here, not yet registered
				memset(&wcex, 0, sizeof(wcex));
				wcex.cbSize         = sizeof(wcex);
				wcex.style          = CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
				wcex.lpfnWndProc    = &iTooltip_wndProc;
				wcex.hInstance      = GetModuleHandle(NULL);
				wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
				wcex.lpszClassName  = cgcTooltipClass;
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
			tooltip->hwnd	= CreateWindowEx(WS_EX_TOOLWINDOW, cgcTooltipClass, NULL, 
												WS_POPUP,
												tooltip->rc.left,
												tooltip->rc.top,
												lnWidth,
												lnHeight,
												NULL, NULL, GetModuleHandle(NULL), 0);

		//////////
		// Store the settings
		//////
			SetWindowLong(tooltip->hwnd, GWL_USERDATA, (u32)tooltip);


		//////////
		// Display the window
		//////
			tooltip->isValid = true;
			SetWindowPos(tooltip->hwnd, HWND_TOPMOST, tooltip->rc.left, tooltip->rc.top, lnWidth, lnHeight, SWP_SHOWWINDOW | SWP_NOACTIVATE);


		//////////
		// Create the timer
		//////
			SetTimer(tooltip->hwnd, (u32)tooltip, _TOOLTIP_TIMER_INTERVAL, 0);


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
		KillTimer(tooltip->hwnd, (u32)tooltip);

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
		tooltip = (STooltip*)GetWindowLong(hwnd, GWL_USERDATA);
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
					lnNumread = fread(*data, 1, *dataLength, lfh);
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

	bool iTestExactlyEqual(s8* left, u32 leftLength, cs8* right, u32 rightLength)
	{
		return(iTestExactlyEqual(left, leftLength, (s8*)right, rightLength));
	}

	bool iTestExactlyEqual(s8* left, u32 leftLength, s8* right, u32 rightLength)
	{
		// Everything must be established
		if (left && right && leftLength == rightLength)
			return(_memicmp(left, right, leftLength) == 0);	// Test equality without regards to case
		
		// If we get here, no match
		return(false);
	}

	bool iTestExactlyEqual_case(s8* left, u32 leftLength, cs8* right, u32 rightLength)
	{
		return(iTestExactlyEqual_case(left, leftLength, (s8*)right, rightLength));
	}

	bool iTestExactlyEqual_case(s8* left, u32 leftLength, s8* right, u32 rightLength)
	{
		// Everything must be established
		if (left && right && leftLength == rightLength)
			return(memcmp(left, right, leftLength) == 0);	// Test equality

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
		if (haystackLength < 0)		haystackLength	= strlen(haystack);
		if (needleLength < 0)		needleLength	= strlen(needle);

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
		if (haystackLength < 0)		haystackLength	= strlen(haystack);
		if (needleLength < 0)		needleLength	= strlen(needle);

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
			haystackLength	= strlen(haystack);

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
			haystackLength	= strlen(haystack);

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
			haystackLength	= strlen(haystack);

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
			haystackLength	= strlen(haystack);

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
			haystackLength	= strlen(haystack);

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
		if (haystackLength < 0)		haystackLength	= strlen(haystack);
		if (needleLength < 0)		needleLength	= strlen(needle);

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
			maxLength = strlen(source);

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
		lnLength	= strlen(tcText) + 1;
		ptr			= (s8*)malloc(lnLength);

		// Copy it (including the trailing null)
		if (ptr)
			memcpy(ptr, tcText, lnLength);

		// All done
		return(ptr);
	}




//////////
//
// Called to duplicate a font that was found from the list of known system fonts
//
//////
	SFont* iFont_duplicate(SFont* fontSource)
	{
		SFont* font;


		// Make sure our environment is sane
		font = NULL;
		if (fontSource)
		{
			// Allocate a copy
			return(iFont_create(fontSource->name.data, fontSource->_size, fontSource->_weight, ((fontSource->isItalic) ? 1 : 0), ((fontSource->isUnderline) ? 1 : 0)));
		}

		// Indicate our success or failure
		return(font);
	}





//////////
//
// Create a new font
//
//////
	SFont* iFont_create(cs8* tcFontName, u32 tnFontSize, u32 tnFontWeight, u32 tnItalics, u32 tnUnderline)
	{
		s32		lnLength;
		u32		lnI;
		SFont*	font;
		SFont*	fontFirstUnused;


		//////////
		// See if there is an unused slot
		//////
			fontFirstUnused	= NULL;
			lnLength		= strlen(tcFontName);
			for (lnI = 0; lnI < gFonts->populatedLength; lnI += sizeof(SFont))
			{
				// Grab the pointer
				font = (SFont*)(gFonts->data + lnI);

				// If used
				if (!font->isUsed)
				{
					// Mark this one if we haven't found a free slot yet
					fontFirstUnused = font;
					break;
				}
			}


		//////////
		// Allocate a new pointer
		//////
			if (!fontFirstUnused)		font = (SFont*)iBuilder_allocateBytes(gFonts, sizeof(SFont));
			else						font = fontFirstUnused;

			// Double-check
			if (!font)
				return(font);

			// Initialize
			memset(font, 0, sizeof(SFont));


		//////////
		// Populate
		//////
			font->isUsed					= true;
			font->hdc						= CreateCompatibleDC(GetDC(GetDesktopWindow()));
			iDatum_duplicate(&font->name, (s8*)tcFontName, lnLength + 1);
			font->_size						= tnFontSize;
			font->_weight					= tnFontWeight;
			font->_italics					= tnItalics;
			font->_underline				= tnUnderline;
			font->isItalic					= ((tnItalics == 0)				? false : true);
			font->isBold					= ((tnFontWeight > FW_NORMAL)	? true : false);
			font->isUnderline				= ((tnUnderline == 0)			? false : true);
			iiFont_refresh(font);


		// Indicate our success
		return(font);
	}




//////////
//
// Change the font size
//
//////
	SFont* iFont_bigger(SFont* font, bool tlDeleteAfterCreateNew)
	{
		SFont* fontNew;


		// Make sure our environment is sane
		if (font && font->_size <= 128)
		{
			// Create the larger font
			fontNew = font;
			fontNew = iFont_create(fontNew->name.data, fontNew->_size + 1, fontNew->_weight, ((fontNew->isItalic) ? 1 : 0), ((fontNew->isUnderline) ? 1 : 0));
			if (!fontNew)
				return(font);

			// Delete the reference font if instructed
			if (tlDeleteAfterCreateNew)
				iFont_delete(&font, true);

			// Indicate our status
			return(fontNew);
		}
		// If we get here, failure
		return(font);
	}

	SFont* iFont_smaller(SFont* font, bool tlDeleteAfterCreateNew)
	{
		SFont* fontNew;


		// Make sure our environment is sane
		if (font && font->_size >= 4)
		{
			// Create the larger font
			fontNew = font;
			fontNew = iFont_create(fontNew->name.data, fontNew->_size - 1, fontNew->_weight, ((fontNew->isItalic) ? 1 : 0), ((fontNew->isUnderline) ? 1 : 0));
			if (!fontNew)
				return(font);

			// Delete the reference font if instructed
			if (tlDeleteAfterCreateNew)
				iFont_delete(&font, true);

			// Indicate our status
			return(fontNew);
		}
		// If we get here, failure
		return(font);
	}




//////////
//
// Called typically after some setting on the font is changed to "refresh"
// the font with the new settings in its device context.
//
//////
	void iiFont_refresh(SFont* font)
	{
		// Create the font
		font->_sizeUsedForCreateFont	= -MulDiv(font->_size, GetDeviceCaps(GetDC(GetDesktopWindow()), LOGPIXELSY), 72);
		font->hfont						= CreateFont(font->_sizeUsedForCreateFont, 0, 0, 0, font->_weight, (font->isItalic ? 1 : 0), (font->isUnderline ? 1 : 0), false, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_NATURAL_QUALITY, FF_SWISS, font->name.data);
		SelectObject(font->hdc, font->hfont);

		// Find out the text metrics
		GetTextMetricsA(font->hdc, &font->tm);
	}




//////////
//
// Free the indicated font resource
//
//////
	void iFont_delete(SFont** fontRoot, bool tlDeleteSelf)
	{
		SFont* font;


		if (fontRoot && *fontRoot)
		{
			// Grab our pointer
			font = *fontRoot;


			//////////
			// Free components
			//////
				DeleteObject((HGDIOBJ)font->hfont);
				DeleteDC(font->hdc);
				iDatum_delete(&font->name, false);


			//////////
			// Free self
			//////
				if (tlDeleteSelf && ((u32)font < (u32)gFonts->data || (u32)font > ((u32)gFonts->data + gFonts->populatedLength)))
				{
					// Delete the memory block
					free(font);
					*fontRoot = NULL;

				} else {
					// Just mark it unused
					font->isUsed = false;
				}
		}
	}




//////////
//
// Called to release all fonts allocated in this block
//
//////
	void iFont_releaseAll(SBuilder* fontRoot, bool tlDeleteSelf)
	{
		u32		lnI;
		SFont*	font;


		// Make sure our environment is sane
		if (fontRoot)
		{
			//////////
			// Delete all allocated fonts
			//////
				for (lnI = 0; lnI < fontRoot->populatedLength; lnI += sizeof(SFont))
				{
					// Grab the pointer
					font = (SFont*)(fontRoot->data + lnI);

					// Delete this font
					if (font->isUsed)
					{
						iFont_delete(&font, false);	// Delete the font
						font->isUsed = false;		// Mark the slot unused
					}
				}


			//////////
			// Delete self
			//////
				if (tlDeleteSelf)
					iBuilder_freeAndRelease(&fontRoot);
		}
	}




//////////
//
// A particular font occupies a certain physical amount of text relative to the rectangle it inhabits.
// In order for this font to be scaled up, the font dynamics will need to change somewhat as per the limitations
// within the font design.  As such, we have to scan upward to find the closest matching font that is equal to
// or less than the ratios indicated at the current size, yet for the desired size.
//
//////
	u32 iFont_findClosestSizeMatch(s8* tcText, s8* tcFontName, u32 tnFontSize, u32 tnFontBold, u32 tnFontItalic, u32 tnFontUnderline, u32 tnWidth, u32 tnHeight, u32 tnWidthDesired, u32 tnHeightDesired)
	{
		s32			lnI, lnJ, lnTextLength, lnFontBold;
		f64			lfRatioH, lfRatioV, lfRatioHThis, lfRatioVThis;
		SSize		size[200];
		RECT		lrc;
		SFont*		font;


		// Iterate from the current size upward for a maximum of 200 font point sizes, but also not more than 3x its current point size
		lnTextLength	= strlen(tcText);
		lnFontBold		= ((tnFontBold) ? FW_BOLD : FW_NORMAL);
		for (lnI = 0; lnI == 0 || (lnI < 200 && (s32)(tnFontSize + lnI) < (s32)(tnFontSize * 3) && lrc.bottom < (s32)((f32)tnHeightDesired * 1.25f) && lrc.right < (s32)((f32)tnWidthDesired * 1.25f)); lnI++)
		{
			// Grab this font
			font = iFont_create(tcFontName, tnFontSize + lnI, lnFontBold, tnFontItalic, tnFontUnderline);

			// Find out how big this font would be drawn for this text
			SetRect(&lrc, 0, 0, 0, 0);
			DrawText(font->hdc, tcText, lnTextLength, &lrc, DT_CALCRECT);
			size[lnI].fWidth	= (f32)(lrc.right - lrc.left);
			size[lnI].fHeight	= (f32)(lrc.bottom - lrc.top);
		}
		// When we get here, we have all of the fonts computed
		// size[0] contains the raw font
		// We search for size[1..N] which has the font which most closely matches its proportions for the tnWidthDesired, tnHeightDesired,
		// as per the ratio 

		// Compute the size[0]
		lfRatioH	= (f64)(size[0].fWidth)  / (f64)tnWidth;
		lfRatioV	= (f64)(size[0].fHeight) / (f64)tnHeight;

		// Search backwards to find the first one that matches
		for (lnJ = lnI - 1; lnJ > 0; lnJ--)
		{
			if ((s32)size[lnJ].fWidth <= (s32)tnWidthDesired && (s32)size[lnJ].fHeight <= (s32)tnHeightDesired)
			{
				// Calculate this item's size
				lfRatioHThis	= (f64)(size[lnJ].fWidth)  / (f64)tnWidthDesired;
				lfRatioVThis	= (f64)(size[lnJ].fHeight) / (f64)tnHeightDesired;

				// See if we've found our font
				if (lfRatioHThis <= lfRatioH && lfRatioVThis <= lfRatioV)
					return(tnFontSize + (u32)lnJ);
			}
		}
		// If we get here, we couldn't find one ... indicate failure
		return(0);
	}




//////////
//
// Called to process the mouse messages.
//
//////
	s32 iMouse_processMessage(SWindow* win, UINT m, WPARAM w, LPARAM l)
	{
		//////////
		// If we're a valid window, process the mouse
		//////
			if (win && win->obj && win->obj->rc.right > win->obj->rc.left)
			{
				// Translate the mouse from the scaled position to its real position
				iiMouse_translatePosition(win, (POINTS*)&l, m);

				// Signal the event(s)
				iiMouse_processMouseEvents(win, m, w, l);
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
	void iiMouse_translatePosition(SWindow* win, POINTS* pt, UINT m)
	{
		POINT	lpt;
		bool	llWheelMessage;


		//////////
		// If we're moving or resizing, we're reading screen coordinate mouse data
		//////
			if (win->isMoving || win->isResizing)
			{
				// Get the mouse pointer in screen coordinates
				GetCursorPos(&lpt);

			} else {
				// Use the indicated coordinates
				lpt.x = pt->x;
				lpt.y = pt->y;
			}


		//////////
		// Translate our SHORT points structure to the LONG point structure
		//////
			win->mousePosition.x = lpt.x;
			win->mousePosition.y = lpt.y;


		//////////
		// If we're moving or resizing, we're reading screen coordinate mouse data
		//////
			if (win->isMoving || win->isResizing)
				return;


		//////////
		// If it's a mouse scroll, the coordinates are given in screen coordinates.
		// Subtract off the window portion
		//////
			llWheelMessage = (m == WM_MOUSEWHEEL);
#ifdef WM_MOUSEHWHEEL
			llWheelMessage |= (m == WM_MOUSEHWHEEL);
#endif
			if (llWheelMessage)
			{
				win->mousePosition.x -= win->rc.left;
				win->mousePosition.y -= win->rc.top;
			}


		//////////
		// Get the mouse flags
		//////
			iiMouse_getFlags_async(&win->isCtrl, &win->isAlt, &win->isShift, &win->isMouseLeftButton, &win->isMouseMiddleButton, &win->isMouseRightButton, &win->isCaps);
	}




//////////
//
// Process the mouse events in the client area for this form
//
//////
	s32 iiMouse_processMouseEvents(SWindow* win, UINT m, WPARAM w, LPARAM l)
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
			obj->ev.mouse.thisClick	|= ((win->isMouseLeftButton)	? _MOUSE_LEFT_BUTTON	: 0);
			obj->ev.mouse.thisClick	|= ((win->isMouseMiddleButton)	? _MOUSE_MIDDLE_BUTTON	: 0);
			obj->ev.mouse.thisClick	|= ((win->isMouseRightButton)	? _MOUSE_RIGHT_BUTTON	: 0);


		//////////
		// Iterate through objects to see where it is the mouse is traipsing
		//////
			// Note:  win->mouseLastPosition holds the coordinates
			// Note:  win->is* flags indicate both button and keyboard state conditions (ctrl, alt, shift, caps)
			llProcessed = false;
			switch (m)
			{
				case WM_MOUSEWHEEL:
					// Signal a mouseScroll
					win->mouseWheelDelta	= (s32)((s16)(((u32)w) >> 16)) / WHEEL_DELTA;
					win->mouseHWheelDelta	= 0;
					iiMouse_processMouseEvents_common(win, obj, &obj->rc, m, true, true, &llProcessed);
					break;

#ifdef WM_MOUSEHWHEEL
				case WM_MOUSEHWHEEL:
					// Signal a mouseHScroll
					win->mouseWheelDelta	= 0;
					win->mouseHWheelDelta	= (s32)((s16)(((u32)w) >> 16)) / WHEEL_DELTA;
					iiMouse_processMouseEvents_common(win, obj, &obj->rc, m, true, true, &llProcessed);
					break;
#endif

				case WM_MOUSEMOVE:
					// Check for mouseEnter and mouseLeave, then a mouseMove
					iiMouse_processMouseEvents_mouseMove(win, obj, &obj->rc, true, true, &llProcessed);

					// The mouse has moved, reset the hover counter
					obj->ev.mouse.startHoverTickCount	= GetTickCount();
					obj->ev.mouse.hasHoverSignaled		= false;
					break;


				case WM_LBUTTONDOWN:
				case WM_RBUTTONDOWN:
				case WM_MBUTTONDOWN:
					// Signal a mouseDown, then a click
					if (iiMouse_processMouseEvents_common(win, obj, &obj->rc, m, true, true, &llProcessed))
					{
						// Set the last click
						obj->ev.mouse._lastClick = obj->ev.mouse.thisClick;
					}
					break;

				case WM_LBUTTONUP:
				case WM_RBUTTONUP:
				case WM_MBUTTONUP:
					// Signal a mouseUp
					iiMouse_processMouseEvents_common(win, obj, &obj->rc, m, true, true, &llProcessed);
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
			lrc.right	= min(rc->right,	lrc.right);
			lrc.bottom	= min(rc->bottom,	lrc.bottom);


		//////////
		// Indicate if we're in the client area
		//////
			return((PtInRect(&lrcClient, win->mousePosition)) ? true : false);
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


		// Make sure our environment is sane
		if (obj && isEnabled(obj) && obj->bmp)
		{
			// Get the rectangle we're in at this level
			llInClientArea = iiMouse_processMouseEvents_getRectDescent(win, obj, rc, lrc, lrcClient);


			//////////
			// Process any children
			//////
				if (tlProcessChildren && obj->firstChild)
					iiMouse_processMouseEvents_mouseMove(win, obj->firstChild, &lrcClient, true, true, tlProcessed);


			//////////
			// Are we within this object?
			//////
				if (PtInRect(&lrc, win->mousePosition))
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
															win->mousePosition.x - lrc.left, 
															win->mousePosition.y - lrc.top, 
															win->isCtrl, win->isAlt, win->isShift, win->obj->ev.mouse.thisClick);
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
															win->mousePosition.x - lrcClient.left, 
															win->mousePosition.y - lrcClient.top, 
															win->isCtrl, win->isAlt, win->isShift, win->obj->ev.mouse.thisClick);
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
					objSib = (SObject*)obj->ll.next;
					while (objSib)
					{
						// Process this sibling
						iiMouse_processMouseEvents_mouseMove(win, objSib, rc, true, false, tlProcessed);

						// Move to next sibling
						objSib = (SObject*)objSib->ll.next;
					}
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
		if (obj && isEnabled(obj) && obj->bmp)
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
																			win->mousePosition.x - lrc.left, 
																			win->mousePosition.y - lrc.top, 
																			win->isCtrl, win->isAlt, win->isShift, win->obj->ev.mouse.thisClick);
								
								// Signal the click event
								if (llContinue && obj->ev.mouse._onMouseClickEx)
									llContinue = obj->ev.mouse.onMouseClickEx(	win, obj, 
																				win->mousePosition.x - lrc.left, 
																				win->mousePosition.y - lrc.top, 
																				win->isCtrl, win->isAlt, win->isShift, win->obj->ev.mouse.thisClick);
									break;

							case WM_LBUTTONUP:
							case WM_RBUTTONUP:
							case WM_MBUTTONUP:
								// Signal the mouseUp event
								*tlProcessed = true;		// Indicate we've processed this
								if (llContinue && obj->ev.mouse._onMouseUp)
									llContinue = obj->ev.mouse.onMouseUp(	win, obj, 
																			win->mousePosition.x - lrc.left, 
																			win->mousePosition.y - lrc.top, 
																			win->isCtrl, win->isAlt, win->isShift, win->obj->ev.mouse.thisClick);
								break;

							case WM_MOUSEWHEEL:
#ifdef WM_MOUSEHWHEEL
							case WM_MOUSEHWHEEL:
#endif
								// Signal the mouseWheel event
								*tlProcessed = true;		// Indicate we've processed this
								if (llContinue && obj->ev.mouse._onMouseWheel)
									llContinue = obj->ev.mouse.onMouseWheel(win, obj, 
																			win->mousePosition.x - lrc.left, 
																			win->mousePosition.y - lrc.top, 
																			win->isCtrl, win->isAlt, win->isShift, win->obj->ev.mouse.thisClick,
																			win->mouseWheelDelta);
								break;
						}

					} else if (PtInRect(&lrc, win->mousePosition)) {
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
																			win->mousePosition.x - lrcClient.left, 
																			win->mousePosition.y - lrcClient.top, 
																			win->isCtrl, win->isAlt, win->isShift, win->obj->ev.mouse.thisClick);
								

								// Signal the click event
								if (llContinue && obj->ev.mouse._onMouseClickEx)
									llContinue = obj->ev.mouse.onMouseClickEx(	win, obj, 
																				win->mousePosition.x - lrcClient.left, 
																				win->mousePosition.y - lrcClient.top, 
																				win->isCtrl, win->isAlt, win->isShift, win->obj->ev.mouse.thisClick);

							case WM_LBUTTONUP:
							case WM_RBUTTONUP:
							case WM_MBUTTONUP:
								// Signal the mouseUp event
								*tlProcessed = true;		// Indicate we've processed this
								if (llContinue && obj->ev.mouse._onMouseUp)
									llContinue = obj->ev.mouse.onMouseUp(	win, obj, 
																			win->mousePosition.x - lrcClient.left, 
																			win->mousePosition.y - lrcClient.top, 
																			win->isCtrl, win->isAlt, win->isShift, win->obj->ev.mouse.thisClick);
								break;

							case WM_MOUSEWHEEL:
#ifdef WM_MOUSEHWHEEL
							case WM_MOUSEHWHEEL:
#endif
								// Signal the mouseWheel event
								*tlProcessed = true;		// Indicate we've processed this
								if (llContinue && obj->ev.mouse._onMouseWheel)
									llContinue = obj->ev.mouse.onMouseWheel(win, obj, 
																			win->mousePosition.x - lrcClient.left, 
																			win->mousePosition.y - lrcClient.top, 
																			win->isCtrl, win->isAlt, win->isShift, win->obj->ev.mouse.thisClick,
																			win->mouseWheelDelta);
								break;
						}
					}


				//////////
				// Process any siblings
				//////
					if (llContinue && tlProcessSiblings)
					{
						// Begin at the next sibling
						objSib = (SObject*)obj->ll.next;
						while (llContinue && !*tlProcessed && objSib)
						{
							// Process this sibling
							llContinue = iiMouse_processMouseEvents_common(win, objSib, rc, m, true, false, tlProcessed);
							if (!llContinue)
								break;

							// Move to next sibling
							objSib = (SObject*)objSib->ll.next;
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
	void iiMouse_getFlags_wparam(WPARAM w, bool* tlCtrl, bool* tlAlt, bool* tlShift, bool* tlLeft, bool* tlMiddle, bool* tlRight, bool* tlCaps)
	{
		//////////
		// Obtain from WPARAM
		//////
			*tlCtrl		= ((w & MK_CONTROL)		!= 0);
			*tlAlt		= (GetKeyState(VK_MENU)	< 0);
			*tlShift	= ((w & MK_SHIFT)		!= 0);
			*tlLeft		= ((w & MK_LBUTTON)		!= 0);
			*tlRight	= ((w & MK_RBUTTON)		!= 0);
			*tlMiddle	= ((w & MK_MBUTTON)		!= 0);
	}




//////////
//
// Based upon the WPARAM we determine the keys, except Alt, which is
// determined by the VK_MENU key's current state.
//
//////
	void iiMouse_getFlags_async(bool* tlCtrl, bool* tlAlt, bool* tlShift, bool* tlLeft, bool* tlMiddle, bool* tlRight, bool* tlCaps)
	{
		//////////
		// Grab each one asynchronously
		//////
			*tlCtrl		= ((GetAsyncKeyState(VK_CONTROL)	& 0x8000)	!= 0);
			*tlAlt		= (GetKeyState(VK_MENU)							< 0);
			*tlShift	= ((GetAsyncKeyState(VK_SHIFT)		& 0x8000)	!= 0);
			*tlLeft		= ((GetAsyncKeyState(VK_LBUTTON)	& 0x8000)	!= 0);
			*tlMiddle	= ((GetAsyncKeyState(VK_MBUTTON)	& 0x8000)	!= 0);
			*tlRight	= ((GetAsyncKeyState(VK_RBUTTON)	& 0x8000)	!= 0);
			*tlCaps		= (GetAsyncKeyState(VK_CAPITAL)		& 0x8000)	!= 0;
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
		bool		llCtrl, llAlt, llShift, llLeft, llMiddle, llRight, llCaps, llIsAscii, llIsCAS;
		u8			keyboardState[256];


		//////////
		// Grab our key states
		//////
			iiMouse_getFlags_async(&llCtrl, &llAlt, &llShift, &llLeft, &llMiddle, &llRight, &llCaps);


		//////////
		// See if it's a printable character
		//////
			lnScanCode	= (tnScanCode & 0xff000) >> 12;
			lnAsciiChar	= 0;
			GetKeyboardState(&keyboardState[0]);
			llIsAscii	= (ToAscii(vKey, lnScanCode, &keyboardState[0], (LPWORD)&lnAsciiChar, 0) >= 1);


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
				obj	= *(SObject**)(objFocusControls->data + (lnI * sizeof(SObject*)));

				// Call the appropriate handler
				if (m == WM_KEYDOWN && obj->ev.keyboard._onKeyDown)
				{
					// Signal the down key event
					obj->ev.keyboard.onKeyDown	(win, obj, llCtrl, llAlt, llShift, llCaps, lnAsciiChar, vKey, llIsCAS, llIsAscii);

				} else if (m == WM_KEYUP && obj->ev.keyboard._onKeyUp) {
					// Signal the up key event
					obj->ev.keyboard.onKeyUp	(win, obj, llCtrl, llAlt, llShift, llCaps, lnAsciiChar, vKey, llIsCAS, llIsAscii);
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
// Added to do a simple top-down translation of the pointers from p1 to p2.
//
//////
	void* iTranslate_p1_to_p2(SBuilder* root, void* ptr)
	{
		u32				lnI, lnCount;
		STranslate*		xlat;


// TODO:  COMPLETELY UNTESTED.  BREAKPOINT AND EXAMINE.
debug_break;
		//////////
		// Iterate in a top-down manner
		//////
			lnCount	= root->populatedLength / sizeof(STranslate);
			xlat	= (STranslate*)root->data;
			for (lnI = 0; lnI < lnCount; lnI++, xlat++)
			{
				// See if this translation is the translation
				if (xlat->p1 == ptr)
					return(xlat->p2);		// Yes
			}
			// If we get here, not found


		//////////
		// Indicate failure
		//////
			return(NULL);
	}

	void* iTranslate_p2_to_p1(SBuilder* root, void* ptr)
	{
		u32				lnI, lnCount;
		STranslate*		xlat;


// TODO:  COMPLETELY UNTESTED.  BREAKPOINT AND EXAMINE.
debug_break;
		//////////
		// Iterate in a top-down manner
		//////
			lnCount = root->populatedLength / sizeof(STranslate);
			xlat	= (STranslate*)root->data;
			for (lnI = 0; lnI < lnCount; lnI++, xlat++)
			{
				// See if this translation is the translation
				if (xlat->p2 == ptr)
					return(xlat->p1);		// Yes
			}
			// If we get here, not found


		//////////
		// Indicate failure
		//////
			return(NULL);
	}




//////////
//
// Called to free the extra info associated with this entry
//
//////
	void iExtraInfo_free(SEM* sem, SLine* ec, SExtraInfo** root, bool tlDeleteSelf)
	{
		SExtraInfo*		ei;
		SExtraInfo*		eiNext;


		// Make sure our environment is sane
		if (root && *root)
		{
// TODO:  COMPLETELY UNTESTED.  BREAKPOINT AND EXAMINE.
debug_break;
			// Iterate through all entries in the chain
			ei = *root;
			while (ei)
			{
				//////////
				// Note the next entry
				//////
					eiNext = ei->next;


				//////////
				// Free the data contained within
				// Note:  If they have an extra_info_free() function defined, we need to call it first so they can release whatever is contained within the info block
				//////
					if (*(u32*)&ei->extra_info_free != 0)
					{
						// Free anything within using the callback
						ei->extra_info_free(NULL, ec, ei);
						// At this point we anything it had inside is now free
					}

					// Now, manually free the actual info block itself
					iDatum_delete(&ei->info, false);


				//////////
				// Free self if need be
				//////
					if (tlDeleteSelf)
						free(ei);


				//////////
				// Move to next entry
				//////
					ei = eiNext;
			}
		}
	}




//////////
//
// Datum storage
//
//////
	void iDatum_allocateSpace(SDatum* datum, s32 dataLength)
	{
		// Make sure our environment is sane
		if (datum)
		{
			if (datum->data && datum->length != dataLength)
			{
				// Release anything that's already there
				iiDatum_delete(datum);
			}

			// Allocate the space
			if (dataLength > 0)
				datum->data = (s8*)malloc(dataLength);

			// Set the length
			datum->length = dataLength;

			// Initialize
			if (datum->data)
				memset(datum->data, 0, dataLength);
		}
	}

	SDatum* iDatum_allocate(s8* data, s32 dataLength)
	{
		SDatum* datumNew;


		// Allocate our new datum
		datumNew = (SDatum*)malloc(sizeof(SDatum));
		if (datumNew)
		{
			// Initialize
			memset(datumNew, 0, sizeof(SDatum));

			// Copy over the content
			if (data && dataLength)
			{
				// We may need to set the length
				if (dataLength < 0)
					dataLength = strlen(data);

				// Initialize
				memset(datumNew, 0, sizeof(SDatum));

				// Populate
				iDatum_duplicate(datumNew, data, dataLength);
			}
		}

		// Indicate our status
		return(datumNew);
	}

	void iDatum_duplicate(SDatum* datum, s8* data, s32 dataLength)
	{
		// Make sure our environment is sane
		if (datum && data)
		{
			// We may need to set the length
			if (dataLength < 0)
				dataLength = strlen(data);

			// Release anything that's already there
			iiDatum_delete(datum);

			// Store the new data
			if (dataLength > 0)
			{
				datum->data = (s8*)malloc(dataLength);

				// Copy over if we were successful
				if (datum->data)
					memcpy(datum->data, data, dataLength);

			} else {
				// There is no data here
				datum->data = NULL;
			}

			// Store the new length
			datum->length = dataLength;
		}
	}

	void iDatum_duplicate(SDatum* datum, cs8* data, s32 dataLength)
	{
		iDatum_duplicate(datum, (s8*)data, dataLength);
	}

	void iDatum_duplicate(SDatum* datumDst, SDatum* datumSrc)
	{
		// Make sure our environment is sane
		if (datumDst && datumSrc && datumSrc->data)
			iDatum_duplicate(datumDst, datumSrc->data, datumSrc->length);
	}

	bool iDatum_resize(SDatum* datum, s32 newDataLength)
	{
		s8* ptr;


		// Make sure our environment is sane
		if (datum && newDataLength != 0)
		{
			if (datum->length == newDataLength)
				return(true);		// It's already the same length

			// Allocate our new block
			ptr = (s8*)malloc(newDataLength);
			if (ptr)
			{
				// Copy everything that will fit
				memcpy(ptr, datum->data, min(newDataLength, datum->length));

				// Fill the remainder with NULLs if any
				if (newDataLength > datum->length)
					memset(ptr + datum->length, 0, newDataLength - datum->length);

				// Delete the old data
				if (datum->data)
					free(datum->data);

				// And populate with the new data
				datum->data		= ptr;
				datum->length	= newDataLength;

				// All done
				return(true);

			} else {
				// Failure
				return(false);
			}

		} else {
			// No data to work with
			return(false);
		}
	}

	// Returns -1, 0, or 1 (indicating left is less than, equal to, or greater than right)
	s32 iDatum_compare(SDatum* datumLeft, SDatum* datumRight)
	{
		s32 lnResult;


		// Default to invalid data
		lnResult = -2;

		// Make sure our environment is sane
		if (datumLeft && datumLeft->data && datumLeft->length != 0 && datumRight && datumRight->data && datumRight->length > 0)
		{
			// Do a standard compare
			lnResult = _memicmp(datumLeft->data, datumRight->data, min(datumLeft->length, datumRight->length));
		}

		// Indicate our result
		return(lnResult);
	}

	s32 iDatum_compare(SDatum* datumLeft, s8* data, s32 dataLength)
	{
		s32 lnResult;


		// Default to invalid data
		lnResult = -2;

		// Make sure our environment is sane
		if (datumLeft && datumLeft->data && datumLeft->length != 0 && data)
		{
			// Make sure our length is set
			if (dataLength < 0)
				dataLength = strlen(data);

			// Do a standard compare
			lnResult = _memicmp(datumLeft->data, data, min(datumLeft->length, dataLength));
		}

		// Indicate our result
		return(lnResult);
	}

	s32 iDatum_compare(SDatum* datumLeft, cs8* data, s32 dataLength)
	{
		return(iDatum_compare(datumLeft, (s8*)data, dataLength));
	}

	void iDatum_delete(SDatum* datum, bool tlDeleteSelf)
	{
		// Make sure our environment is sane
		if (datum)
		{
			// Delete the content
			iiDatum_delete(datum);

			// Delete self if need be
			if (tlDeleteSelf)
				free(datum);
		}
	}

	void iiDatum_delete(SDatum* datum)
	{
		// Make sure our environment is sane
		if (datum->data)
		{
			free(datum->data);
			datum->data = NULL;
		}

		// Reset the length to zero
		datum->length = 0;
	}
