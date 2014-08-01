//////////
//
// /libsf/source/vjr/vjr.cpp
//
//////
// Version 0.40
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
		iVjr_init(&hAccelTable);


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
	void iVjr_init(HACCEL* hAccelTable)
	{
		RECT		lrc;
		SBitmap*	bmp;


		// Get startup time
		systemStartedMs = iTime_getLocalMs();

		// Keyboard shortcuts
		*hAccelTable = LoadAccelerators(ghInstance, MAKEINTRESOURCE(IDC_VJR));

		// Initialize our critical sections
		InitializeCriticalSection(&gcsUniqueIdAccess);

		// These arrows are used as a standard throughout the system for the size of an icon.
		// They must be loaded first.
		bmpArrowUl			= iBmp_rawLoad(cgc_arrowUlBmp);
		bmpArrowUr			= iBmp_rawLoad(cgc_arrowUrBmp);
		bmpArrowLl			= iBmp_rawLoad(cgc_arrowLlBmp);
		bmpArrowLr			= iBmp_rawLoad(cgc_arrowLrBmp);

		// Initialize our builders
		iBuilder_createAndInitialize(&gWindows,	-1);
		iBuilder_createAndInitialize(&gFonts,	-1);

		// Default font
		gsFontDefault				= iFont_create(cgcDefaultFontName,			10,	FW_NORMAL,	0, 0);
		gsFontDefault9				= iFont_create(cgcDefaultFontName,			9,	FW_NORMAL,	0, 0);
		gsFontDefaultBold			= iFont_create(cgcDefaultFontName,			10,	FW_BOLD,	0, 0);
		gsFontDefaultFixedPoint		= iFont_create(cgcDefaultFixedFontName,		10,	FW_NORMAL,	0, 0);
		gsWindowTitleBarFont		= iFont_create(cgcWindowTitleBarFontName,	12,	FW_NORMAL,	0, 0);
		gsWindowTitleBarFontSubform	= iFont_create(cgcWindowTitleBarFontName,	10,	FW_NORMAL,	0, 0);

		// Initialize the sound system
		isound_initialize();
		memset(&gseRootSounds, 0, sizeof(gseRootSounds));	// Initialize our root sounds array

//////////
// Jul.29.2014
// Removed due to limitations in the Shobjidl.h in MinGW.  Can be manually re-added with copy-and-paste... enjoy doing that! :-)
//		// Taskbar interface
//		HRESULT		hRes;
//		hRes = OleInitialize(NULL);
//		CoCreateInstance(CLSID_TaskbarList, 0, CLSCTX_INPROC_SERVER, IID_ITaskbarList, (void**)&giTaskbar);
//////////


		//////////
		// Load our icons and images
		//////
			bmpVjrIcon			= iBmp_rawLoad(cgc_appIconBmp);
			bmpJDebiIcon		= iBmp_rawLoad(cgc_jdebiAppIconBmp);
			bmpSourceCodeIcon	= iBmp_rawLoad(cgc_sourcecodeIconBmp);
			bmpLocalsIcon		= iBmp_rawLoad(cgc_localsIconBmp);
			bmpWatchIcon		= iBmp_rawLoad(cgc_watchIconBmp);
			bmpCommandIcon		= iBmp_rawLoad(cgc_commandIconBmp);
			bmpDebugIcon		= iBmp_rawLoad(cgc_debugIconBmp);
			bmpOutputIcon		= iBmp_rawLoad(cgc_outputIconBmp);

			// Create a 1x1 no image bitmap placeholder
			bmpNoImage			= iBmp_allocate();
			iBmp_createBySize(bmpNoImage, 1, 1, 32);

			bmpClose			= iBmp_rawLoad(cgc_closeBmp);
			bmpMaximize			= iBmp_rawLoad(cgc_maximizeBmp);
			bmpMinimize			= iBmp_rawLoad(cgc_minimizeBmp);
			bmpMove				= iBmp_rawLoad(cgc_moveBmp);

			bmpCheckboxOn		= iBmp_rawLoad(cgc_checkboxOnBmp);
			bmpCheckboxOff		= iBmp_rawLoad(cgc_checkboxOffBmp);

			bmpButton			= iBmp_rawLoad(cgc_buttonBmp);
			bmpTextbox			= iBmp_rawLoad(cgc_textboxBmp);

			bmpStoplightRed		= iBmp_rawLoad(cgc_stoplightRedBmp);
			bmpStoplightAmber	= iBmp_rawLoad(cgc_stoplightAmberBmp);
			bmpStoplightGreen	= iBmp_rawLoad(cgc_stoplightGreenBmp);

			// The radio image has a 44x44 dot in the upper-left.
			bmpRadio			= iBmp_rawLoad(cgc_radioBmp);									// Load the raw bmpRadio
			SetRect(&lrc, 0, 0, 44, 44);
			bmpRadioDot			= iBmp_allocate();
			iBmp_createBySize(bmpRadioDot, 44, 44, 24);
			iBmp_extractRect(bmpRadioDot, &lrc, bmpRadio, 0, 0);								// Extract the 44x44 rectangle
			iBmp_fillRect(bmpRadio, &lrc, white, white, white, white, false, NULL, false);		// And cover it up with white


		// Load the splash screen
		bmpVjrSplash = iBmp_rawLoad(cgc_splashBmp);
		bmp = iiVjr_buildSplashScreen(bmpVjrSplash);
		CreateThread(0, 0, &iSplash_show, bmp, 0, 0);

		// Play the startup music if any
		CreateThread(0, 0, &iPlay_ariaSplash, (LPVOID)cgcSoundStartupWav, 0, 0);

		// Focus window accumulator
		iBuilder_createAndInitialize(&gFocusHighlights, -1);


		// Create the default reference datetimes
		iInit_createDefaultDatetimes();

		// Create our message window
		iInit_createMessageWindow();

		// Create our default objects
		iInit_createDefaultObjects();

		// Create our main screen window
		iInit_create_screenObject();
		iInit_create_jdebiObject();

		// Initially render each one
		iObj_render(gobj_screen,	true);
		iObj_render(gobj_jdebi,		true);

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
		if (!iEditManager_loadFromDisk(screenData, NULL, (s8*)cgcScreenDataFilename, true))
		{
			iEditManager_appendLine(screenData, (s8*)cgcScreenTitle, -1);
			iEditManager_appendLine(screenData, NULL, 0);
			iEditManager_appendLine(screenData, (s8*)"Please report any bugs:  http://www.visual-freepro.org/forum", -1);
			iEditManager_appendLine(screenData, (s8*)"Thank you, and may the Lord Jesus Christ bless you richly. :-)", -1);
			iEditManager_appendLine(screenData, NULL, 0);
			iEditManager_appendLine(screenData, (s8*)"              _____", -1);
			iEditManager_appendLine(screenData, (s8*)"             |     |", -1);
			iEditManager_appendLine(screenData, (s8*)"             |     |", -1);
			iEditManager_appendLine(screenData, (s8*)"     ________|     |________     In God's sight we've come together.", -1);
			iEditManager_appendLine(screenData, (s8*)"    |                       |    We've come together to help each other.", -1);
			iEditManager_appendLine(screenData, (s8*)"    |________       ________|    Let's grow this project up ... together!", -1);
			iEditManager_appendLine(screenData, (s8*)"             |     |             In service and love to The Lord, forever!", -1);
			iEditManager_appendLine(screenData, (s8*)"             |     |", -1);
			iEditManager_appendLine(screenData, (s8*)"             |     |             Sponsored by:", -1);
			iEditManager_appendLine(screenData, (s8*)"             |     |                LibSF -- Liberty Software Foundation", -1);
			iEditManager_appendLine(screenData, (s8*)"             |     |", -1);
			iEditManager_appendLine(screenData, (s8*)"             |     |             We need more coders. Please consider helping out.", -1);
			iEditManager_appendLine(screenData, (s8*)"             |     |             Your contribution would make a difference.", -1);
			iEditManager_appendLine(screenData, (s8*)"             |     |", -1);
			iEditManager_appendLine(screenData, (s8*)"             |_____|", -1);
			iEditManager_appendLine(screenData, NULL, 0);
		}
		// Navigate to the end of the content
		iEditManager_navigateEnd(screenData, gobj_screen);

		// Initially populate _jdebi
		// Load in the history if it exists
		if (!iEditManager_loadFromDisk(command_editbox->pa.em, NULL, (s8*)cgcCommandHistoryFilename, true))
		{
			iEditManager_appendLine(command_editbox->pa.em, (s8*)"*** Welcome to Visual FreePro, Junior! :-)", -1);
			iEditManager_appendLine(command_editbox->pa.em, (s8*)"*** For now, this can be thought of as a command window ... with a twist.", -1);
			iEditManager_appendLine(command_editbox->pa.em, (s8*)"*** It works like an editor window.  You can insert new lines, edit old ones, etc.", -1);
			iEditManager_appendLine(command_editbox->pa.em, (s8*)"*** To execute a command, press F6 or Enter if you're on the last line, or use F6 on any line.", -1);
			iEditManager_appendLine(command_editbox->pa.em, (s8*)"*** You can use clear, quit, ? 999, ? \"sample\" (literals), and ? _startupTime (global variable) in this daily build.", -1);
			iEditManager_appendLine(command_editbox->pa.em, (s8*)"*** Remember this always:  Love makes you smile. It keeps an inward peace unlike any other. :-)", -1);
		}
		// Navigate to the last line
		iEditManager_navigateEnd(command_editbox->pa.em, command_editbox);
		// Make sure there's a blank line at the end
		if (command_editbox->pa.em->ecCursorLine->sourceCodePopulated != 0)
		{
			iEditManager_appendLine(command_editbox->pa.em, NULL, 0);
			iEditManager_navigateEnd(command_editbox->pa.em, command_editbox);
		}

		// Load some source code
		iEditManager_loadFromDisk(sourceCode_editbox->pa.em, NULL, (s8*)cgcStartupPrgFilename, true);

		// Redraw
		iWindow_render(gWinJDebi, true);

		// Redraw
		iWindow_render(gWinScreen, true);

		// Remove the splash screen 1/2 second later
		CreateThread(0, 0, &iSplash_delete, (LPVOID)500, 0, 0);;
	}




//////////
//
// Called to build the listing along the right side, which is a subform with
// an editbox contained within to hold the items.
//
//////
	void iVjr_createOverlayListing(SBitmap* bmp, RECT* trc)
	{
		SVariable* caption;


		//////////
		// Create the object
		//////
			// Create object
			gobj_splashListing = iObj_create(_OBJ_TYPE_SUBFORM, NULL);
			if (!gobj_splashListing)
				return;

			// Set the icon
			iObj_setIcon(gobj_splashListing, bmpOutputIcon);


			//////////
			// Give it a caption
			//////
				caption = iVariable_createAndPopulate(_VAR_TYPE_CHARACTER, cgcScreenTitle, sizeof(cgcScreenTitle) - 1);
				iObj_setCaption(gobj_screen, caption);
				iVariable_delete(caption, true);


			// Give it a fixed point font
			gobj_splashListing->pa.font = iFont_create((s8*)cgcDefaultFixedFontName, 8, FW_MEDIUM, false, false);


		//////////
		// Size and position it
		//////
			iObj_setSize(gobj_splashListing, trc->left, trc->top, trc->right - trc->left, bmp->bi.biHeight);


		//////////
		// Add the editbox
		//////
			gobj_splashListingEditbox							= iObj_addChild(_OBJ_TYPE_EDITBOX,	gobj_splashListing);
			iObj_setSize(gobj_splashListingEditbox, 0, 0, gobj_splashListing->rcClient.right - gobj_splashListing->rcClient.left, gobj_splashListing->rcClient.bottom - gobj_splashListing->rcClient.top);
			gobj_splashListingEditbox->pa.font					= iFont_create((s8*)cgcDefaultFixedFontName, 10, FW_MEDIUM, false, false);
			gobj_splashListingEditbox->ev.keyboard._onKeyDown	= (u32)&iEditManager_onKeyDown;
			logData												= gobj_splashListingEditbox->pa.em;
			logData->showEndLine								= true;
			logData->showCursorLine								= true;


		//////////
		// Set it visible
		//////
			iObj_setVisible(gobj_splashListing, true);
	}




//////////
//
// Called to render the listing.
//
//////
	void iVjr_renderOverlayListing(SBitmap* bmp, RECT* trc)
	{
		iEditManager_navigateEnd(gobj_splashListingEditbox->pa.em, gobj_splashListing);
		iObj_render(gobj_splashListing, true);
		iBmp_bitBlt(bmp, trc, gobj_splashListing->bmp);
	}




//////////
//
// Physically render the accomplishment
//
//////
	#define _RED	0
	#define _AMBER	1
	#define _GREEN	2
	void iiVjr_renderAccomplishment(SBitmap* bmp, RECT* trc, s32 tnRAG, s8* tcAccomplishment, s8* tcAuthor)
	{
		s32			lnWidthAccomplishment, lnWidthAuthor;
		RECT		lrc, lrc2, lrcAccomplishment, lrcAuthor;
		SBgra		leftColor;
		COLORREF	textColor;


		//////////
		// Determine how big the accomplishment and author texts are
		//////
			SelectObject(bmp->hdc, gsFontDefault9->hfont);
			SetRect(&lrcAccomplishment, 0, 0, bmp->bi.biWidth, bmp->bi.biHeight);
			DrawText(bmp->hdc, tcAccomplishment, strlen(tcAccomplishment), &lrcAccomplishment, DT_SINGLELINE | DT_LEFT | DT_CALCRECT);


		//////////
		// Compute the size of the author text
		//////
			if (tcAuthor)
			{
				// There is an author
				SelectObject(bmp->hdc, gsFontDefaultFixedPoint->hfont);
				SetRect(&lrcAuthor, 0, 0, bmp->bi.biWidth, bmp->bi.biHeight);
				DrawText(bmp->hdc, tcAuthor, strlen(tcAuthor), &lrcAuthor, DT_SINGLELINE | DT_LEFT | DT_CALCRECT);

			} else {
				// No author
				SetRect(&lrcAuthor, 0, 0, 0, 0);
			}

		
		//////////
		// Build our target size rectangle
		//////
			lnWidthAccomplishment	= lrcAccomplishment.right - lrcAccomplishment.left;
			lnWidthAuthor			= lrcAuthor.right - lrcAuthor.left;
//////////
// An alternative design is to use lnWidth and trc->right - lnWidth for the lrc.left setting
//			s32 lnWidth
//			lnWidth = bmpStoplightRed->bi.biWidth + 4 + lnWidthAuthor + ((lnWidthAuthor != 0) ? 12 : 0) + lnWidthAccomplishment + 4;
//////
			SetRect(&lrc, trc->left, trc->top, trc->right, trc->top + bmpStoplightRed->bi.biHeight);


		//////////
		// Fill it with the gradient color
		//////
			switch (tnRAG)
			{
				case _RED:
					leftColor = iBmp_extractColorAtPoint(bmpStoplightRed, bmpStoplightRed->bi.biWidth / 2, bmpStoplightRed->bi.biHeight / 2);
					break;

				default:
				case _AMBER:
					leftColor = iBmp_extractColorAtPoint(bmpStoplightAmber, bmpStoplightAmber->bi.biWidth / 2, bmpStoplightAmber->bi.biHeight / 2);
					break;

				case _GREEN:
					leftColor = iBmp_extractColorAtPoint(bmpStoplightGreen, bmpStoplightGreen->bi.biWidth / 2, bmpStoplightGreen->bi.biHeight / 2);
					break;
			}
			CopyRect(&lrc2, &lrc);
			lrc2.right = lrc2.left + bmpStoplightRed->bi.biWidth + lnWidthAuthor + 12;
			iBmp_fillRect(bmp, &lrc2, leftColor, white, leftColor, white, true, NULL, false);
			lrc2.left	= lrc2.right;
			lrc2.right	= lrc.right;
			iBmp_fillRect(bmp, &lrc2, white, white, white, white, false, NULL, false);


		//////////
		// Overlay the appropriate signal
		//////
			switch (tnRAG)
			{
				case _RED:
					iBmp_bitBlt(bmp, &lrc, bmpStoplightRed);
					textColor = RGB(64,0,0);
					break;

				default:
				case _AMBER:
					iBmp_bitBlt(bmp, &lrc, bmpStoplightAmber);
					textColor = RGB(64,48,0);
					break;

				case _GREEN:
					iBmp_bitBlt(bmp, &lrc, bmpStoplightGreen);
					textColor = RGB(0,64,0);
					break;
			}


		//////////
		// Add in the author
		//////
			// Move over for the next text (either author or accomplishment)
			lrc.top += 3;
			lrc.left += bmpStoplightRed->bi.biWidth + 4;
			if (tcAuthor)
			{
				// Draw the author
				SelectObject(bmp->hdc, gsFontDefaultFixedPoint->hfont);
				SetTextColor(bmp->hdc, textColor);
				SetBkMode(bmp->hdc, TRANSPARENT);
				DrawText(bmp->hdc, tcAuthor, strlen(tcAuthor), &lrc, DT_SINGLELINE | DT_LEFT);
			}


		//////////
		// Add in the accomplishment
		//////
			// SEt for the accomplishment
			lrc.left = trc->right - lnWidthAccomplishment - 4;
			SelectObject(bmp->hdc, gsFontDefault9->hfont);
			SetTextColor(bmp->hdc, textColor);
			SetBkMode(bmp->hdc, TRANSPARENT);
			DrawText(bmp->hdc, tcAccomplishment, strlen(tcAccomplishment), &lrc, DT_SINGLELINE | DT_LEFT);


		//////////
		// Adjust the next rect down for the next one
		//////
			trc->top	+= bmpStoplightRed->bi.biHeight + 4;
			trc->bottom	+= bmpStoplightRed->bi.biHeight + 4;
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

		// New splash screen
		iiVjr_renderAccomplishment(bmp, &lrc, _GREEN, "New splash screen", "Rick");

		// Memory leak bug fixes
		iiVjr_renderAccomplishment(bmp, &lrc, _GREEN, "Memory leak bug fixes", "Rick");

		// STUFF() param 4 error
		iiVjr_renderAccomplishment(bmp, &lrc, _GREEN, "STUFF() param 4 error", "Rick");
	}
