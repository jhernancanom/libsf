//////////
//
// /libsf/source/vjr/vjr.cpp
//
//////
// Version 0.30
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
//     http://www.visual-freepro.org/wiki/index.php/Repeat_License
//
// Thank you.  And may The Lord bless you richly as you lift up your life, your
// talents, your gifts, your praise, unto Him.  In Jesus' name I pray.  Amen.
//
//




#include "vjr.h"




int CALLBACK WinMain(	HINSTANCE	hInstance,
						HINSTANCE	hPrevInstance,
						LPSTR		lpCmdLine,
						int			nCmdShow	)
{
	MSG		msg;
	HACCEL	hAccelTable;


	//////////
	// Initialize
	//////
		ghInstance = hInstance;
		iInit_vjr(&hAccelTable);


	//////////
	// Read events
	//////
		while (GetMessage(&msg, NULL, 0, 0))
		{
			if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		// When the WM_QUIT message is received, we exit
		return((int)msg.wParam);
}




//////////
//
// Startup initialization, called from WinMain() only.
//
//////
	void iInit_vjr(HACCEL* hAccelTable)
	{
		HRESULT hRes;


		// Keyboard shortcuts
		*hAccelTable = LoadAccelerators(ghInstance, MAKEINTRESOURCE(IDC_VJR));

		// Taskbar interface
		hRes = OleInitialize(NULL);
		CoCreateInstance(CLSID_TaskbarList, 0, CLSCTX_INPROC_SERVER, IID_ITaskbarList, (void**)&giTaskbar);

		// Initialize our builder
		iBuilder_createAndInitialize(&gWindows,	-1);
		iBuilder_createAndInitialize(&gFonts,	-1);

		// Initialize our critical sections
		InitializeCriticalSection(&gcsUniqueIdAccess);

		// Get startup time
		systemStartedMs = iTime_getLocalMs();

		// Default font
		gsFont					= iFont_create(cgcDefaultFont,			10, FW_NORMAL,	0, 0);
		gsWindowTitleBarFont	= iFont_create(cgcWindowTitleBarFont,	12, FW_NORMAL,	0, 0);


		//////////
		// Load our icons and images
		//////
			bmpVjrIcon		= iBmp_rawLoad(cgc_appIconBmp);
			bmpJDebiIcon	= iBmp_rawLoad(cgc_jdebiAppIconBmp);

			// Create a 1x1 no image bitmap placeholder
			bmpNoImage		= iBmp_allocate();
			iBmp_createBySize(bmpNoImage, 1, 1, 32);

			bmpClose		= iBmp_rawLoad(cgc_closeBmp);
			bmpMaximize		= iBmp_rawLoad(cgc_maximizeBmp);
			bmpMinimize		= iBmp_rawLoad(cgc_minimizeBmp);
			bmpMove			= iBmp_rawLoad(cgc_moveBmp);

			bmpArrowUl		= iBmp_rawLoad(cgc_arrowUlBmp);
			bmpArrowUr		= iBmp_rawLoad(cgc_arrowUrBmp);
			bmpArrowLl		= iBmp_rawLoad(cgc_arrowLlBmp);
			bmpArrowLr		= iBmp_rawLoad(cgc_arrowLrBmp);


		// Create the default reference datetimes
		iInit_createDefaultDatetimes();

		// Create our message window
		iInit_createMessageWindow();

		// Create our default objects
		iInit_createDefaultObjects();

		// Create the buffers for screen and command history
		screenData		= iEditChainManager_allocate();
		commandHistory	= iEditChainManager_allocate();

		// Set the cursor line data on commandHistory only
		commandHistory->showCursorLine	= true;
		commandHistory->showEndLine		= true;

		// Create our main screen window
		iInit_create_screenObject();
		iInit_create_jdebiObject();

		// Initially render each one
		iObj_render(gobj_screen, true, true);
		iObj_render(gobj_jdebi, true, true);

		// Create our global variables
		varGlobals = function_datetime(NULL, NULL, NULL, NULL, NULL, NULL, NULL);
		iDatum_duplicate(&varGlobals->name, cgcName_startupTime, -1);

		// Attach them to physical windows
		gWinScreen	= iWindow_allocate();
		gWinJDebi	= iWindow_allocate();
		iObj_createWindowForForm(gobj_screen,	gWinScreen,	IDI_VJR);
		iObj_createWindowForForm(gobj_jdebi,	gWinJDebi,	IDI_JDEBI);

		// Initially populate _screen
		// Load in the history if it exists
		if (!iEditChainManager_loadFromDisk(screenData, NULL, (s8*)cgcScreenDataFilename, true))
		{
			iEditChainManager_appendLine(screenData, (s8*)cgcScreenTitle, -1);
			iEditChainManager_appendLine(screenData, NULL, 0);
			iEditChainManager_appendLine(screenData, "Please report any bugs:  http://www.visual-freepro.org/forum", -1);
			iEditChainManager_appendLine(screenData, "Thank you, and may the Lord Jesus Christ bless you richly. :-)", -1);
			iEditChainManager_appendLine(screenData, NULL, 0);
			iEditChainManager_appendLine(screenData, "              _____", -1);
			iEditChainManager_appendLine(screenData, "             |     |", -1);
			iEditChainManager_appendLine(screenData, "             |     |", -1);
			iEditChainManager_appendLine(screenData, "     ________|     |________     In God's sight we've come together.", -1);
			iEditChainManager_appendLine(screenData, "    |                       |    We've come together to help each other.", -1);
			iEditChainManager_appendLine(screenData, "    |________       ________|    Let's grow this project up ... together!", -1);
			iEditChainManager_appendLine(screenData, "             |     |             In service and love to The Lord, forever!", -1);
			iEditChainManager_appendLine(screenData, "             |     |", -1);
			iEditChainManager_appendLine(screenData, "             |     |             Sponsored by:", -1);
			iEditChainManager_appendLine(screenData, "             |     |                LibSF -- Liberty Software Foundation", -1);
			iEditChainManager_appendLine(screenData, "             |     |", -1);
			iEditChainManager_appendLine(screenData, "             |     |             We need more coders. Please consider helping out.", -1);
			iEditChainManager_appendLine(screenData, "             |     |             Your contribution would make a difference.", -1);
			iEditChainManager_appendLine(screenData, "             |     |", -1);
			iEditChainManager_appendLine(screenData, "             |_____|", -1);
			iEditChainManager_appendLine(screenData, NULL, 0);
		}
		// Navigate to the end of the content
		iEditChainManager_navigateEnd(screenData, gobj_screen);
		// Redraw
		gobj_screen->isDirty = true;
		iWindow_render(gWinScreen);

		// Initially populate _jdebi
		// Load in the history if it exists
		if (!iEditChainManager_loadFromDisk(commandHistory, NULL, (s8*)cgcCommandHistoryFilename, true))
		{
			iEditChainManager_appendLine(commandHistory, "*** Welcome to Visual FreePro, Junior! :-)", -1);
			iEditChainManager_appendLine(commandHistory, "*** For now, this can be thought of as a command window ... with a twist.", -1);
			iEditChainManager_appendLine(commandHistory, "*** It works like an editor window.  You can insert new lines, edit old ones, etc.", -1);
			iEditChainManager_appendLine(commandHistory, "*** To execute a command, press F6 or Enter if you're on the last line, or use F6 on any line.", -1);
			iEditChainManager_appendLine(commandHistory, "*** You can use clear, quit, ? 999, ? \"sample\" (literals), and ? _startupTime (global variable) in this daily build.", -1);
			iEditChainManager_appendLine(commandHistory, "*** Remember this always:  Love makes you smile. It keeps an inward peace unlike any other. :-)", -1);
		}
		// Navigate to the last line
		iEditChainManager_navigateEnd(commandHistory, gobj_jdebi);
		// Make sure there's a blank line at the end
		if (commandHistory->ecCursorLine->sourceCodePopulated != 0)
		{
			iEditChainManager_appendLine(commandHistory, NULL, 0);
			iEditChainManager_navigateEnd(commandHistory, gobj_jdebi);
		}
		// Redraw
		gobj_jdebi->isDirty = true;
		iWindow_render(gWinJDebi);
	}
