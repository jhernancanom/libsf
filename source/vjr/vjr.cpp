//////////
//
// /libsf/source/vjr/vjr.cpp
//
//////
// Version 0.52
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
		iVjr_appendSystemLog("Initialization complete");


	//////////
	// Read events
	//////
		iVjr_appendSystemLog("Engage main  loop");
		while (GetMessage(&msg, NULL, 0, 0))
		{
			if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		// When the WM_QUIT message is received, we exit


	//////////
	// Do allocated resource shutdown
	//////
		if (!glShuttingDown)
			iVjr_shutdown();


	//////////
	// Return our exit code
	//////
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
		s8			buffer[256];


		// Get startup time
		systemStartedTickCount	= GetTickCount();
		systemStartedMs			= iTime_getLocalMs();

		// Default value for spinners
		gsInitialization[_INDEX_INCREMENT]._f64 = 1.0;

		// Initialize primitive variables
		varConstant_space	= iVariable_createAndPopulate(_VAR_TYPE_CHARACTER, cgc_spaceText, 1);
		varEmptyString		= iVariable_createAndPopulate(_VAR_TYPE_CHARACTER, (s8*)NULL, 0);
		var2000Spaces		= iVariable_create(_VAR_TYPE_CHARACTER, NULL);
		iDatum_allocateSpace(&var2000Spaces->value, 2000);
		memset(var2000Spaces->value.data, 32, 2000);

		// Keyboard shortcuts
		*hAccelTable = LoadAccelerators(ghInstance, MAKEINTRESOURCE(IDC_VJR));

		// Initialize our critical sections
		InitializeCriticalSection(&cs_uniqueIdAccess);
		InitializeCriticalSection(&cs_logData);

		// These arrows are used as a standard throughout the system for the size of an icon.
		// They must be loaded first.
		bmpArrowUl		= iBmp_rawLoad(cgc_arrowUlBmp);
		bmpArrowUr		= iBmp_rawLoad(cgc_arrowUrBmp);
		bmpArrowLl		= iBmp_rawLoad(cgc_arrowLlBmp);
		bmpArrowLr		= iBmp_rawLoad(cgc_arrowLrBmp);

		// Initialize our builders
		iBuilder_createAndInitialize(&gWindows,	-1);
		iBuilder_createAndInitialize(&gFonts,	-1);

		// Default font
		gsFontDefault				= iFont_create(cgcFontName_default,			10,	FW_NORMAL,	0, 0);
		gsFontDefault9				= iFont_create(cgcFontName_default,			9,	FW_NORMAL,	0, 0);
		gsFontDefaultBold			= iFont_create(cgcFontName_default,			10,	FW_BOLD,	0, 0);
		gsFontDefaultItalic8		= iFont_create(cgcFontName_default,			8,	FW_NORMAL,	1, 0);
		gsFontDefaultFixedPoint		= iFont_create(cgcFontName_defaultFixed,	10,	FW_NORMAL,	0, 0);
		gsWindowTitleBarFont		= iFont_create(cgcFontName_windowTitleBar,	12,	FW_NORMAL,	0, 0);
		gsWindowTitleBarFontSubform	= iFont_create(cgcFontName_windowTitleBar,	10,	FW_NORMAL,	0, 0);
		gsFontDefaultTooltip		= iFont_create(cgcFontName_defaultTooltip,	9,	FW_BOLD,	0, 0);
		gsFontCask					= iFont_create(cgcFontName_cask,			20, FW_BOLD,	0, 0);

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
			bmpSourceLightIcon	= iBmp_rawLoad(cgc_sourcelightIconBmp);

			// Carousels
			bmpCarouselCarouselIcon	= iBmp_rawLoad(cgc_carouselCarouselBmp);
			bmpCarouselTabsIcon		= iBmp_rawLoad(cgc_carouselTabsBmp);
			bmpCarouselPad			= iBmp_rawLoad(cgc_carouselPadBmp);
			bmpCarouselIcon			= iBmp_rawLoad(cgc_carouselIconBmp);

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
			bmpStoplightBlue	= iBmp_rawLoad(cgc_stoplightBlueBmp);

			bmpBreakpointAlways				= iBmp_rawLoad(cgc_breakpointAlways);
			bmpBreakpointAlwaysCountdown	= iBmp_rawLoad(cgc_breakpointAlwaysCountdown);
			bmpConditionalTrue				= iBmp_rawLoad(cgc_breakpointConditionalTrue);
			bmpConditionalFalse				= iBmp_rawLoad(cgc_breakpointConditionalFalse);
			bmpConditionalTrueCountdown		= iBmp_rawLoad(cgc_breakpointConditionalTrueCountdown);
			bmpConditionalFalseCountdown	= iBmp_rawLoad(cgc_breakpointConditionalFalseCountdown);

			bmpDapple1			= iBmp_rawLoad(cgc_dappleBmp);
			bmpDapple2			= iBmp_rawLoad(cgc_dapple2Bmp);

			//////////
			// Casks
			//////
				iVjr_init_loadCaskIcons();


			//////////
			// The radio image has a 44x44 dot in the upper-left.
			//////
				bmpRadio	= iBmp_rawLoad(cgc_radioBmp);											// Load the raw bmpRadio
				bmpRadioDot = iBmp_createAndExtractRect(bmpRadio, 0, 0, 44, 44);					// Extract the 44x44 rectangle
				SetRect(&lrc, 0, 0, 44, 44);
				iBmp_fillRect(bmpRadio, &lrc, whiteColor, whiteColor, whiteColor, whiteColor, false, NULL, false);		// And cover it up with white


		// Load the splash screen
		bmpVjrSplash = iBmp_rawLoad(cgc_splashBmp);
		bmp = iiVjr_buildSplashScreen(bmpVjrSplash);
		CreateThread(0, 0, &iSplash_show, bmp, 0, 0);

		// Play the startup music if any
		sprintf(buffer, "VJr launched %u milliseconds after system boot\0", systemStartedTickCount);
		iVjr_appendSystemLog(buffer);
		CreateThread(0, 0, &iPlay_ariaSplash, (LPVOID)cgcSoundStartupWav, 0, 0);

		// Focus window accumulator
		iVjr_appendSystemLog("Create focus highlight buffer");
		iBuilder_createAndInitialize(&gFocusHighlights, -1);

		// Create the default reference datetimes
		iVjr_appendSystemLog("Create default datetime variables");
		iInit_createDefaultDatetimes();

		// Create our message window
		iVjr_appendSystemLog("Create message window");
		iInit_createMessageWindow();

		// Create our default objects
		iVjr_appendSystemLog("Create default objects");
		iInit_createDefaultObjects();

		// Create our main screen window
		iVjr_appendSystemLog("TEMPORARY:  Manually create _jdebi");
		iInit_create_jdebi();

		// Initially render each one
		iVjr_appendSystemLog("Render _jdebi");
		iObj_render(_jdebi,		true);

		// Create our global variables
		iVjr_appendSystemLog("Create _startupTime");
		varGlobals			= function_datetime(NULL, NULL, NULL, NULL, NULL, NULL, NULL);
		iDatum_duplicate(&varGlobals->name, cgcName_startupTime, -1);

		// Attach them to physical windows
		iVjr_appendSystemLog("Allocate OS Window for _jdebi");
		gWinJDebi = iWindow_allocate();
		iObj_createWindowForForm(_jdebi,	gWinJDebi,	IDI_JDEBI);

		// Initially populate _screen
		// Load in the history if it exists
		if (!iSEM_loadFromDisk(screenData, (s8*)cgcScreenDataFilename, false))
		{
			iVjr_appendSystemLog("Populate _screen with default data");
			iSEM_appendLine(screenData, (s8*)cgcScreenTitle, -1);
			iSEM_appendLine(screenData, NULL, 0);
			iSEM_appendLine(screenData, (s8*)"Please report any bugs:  http://www.visual-freepro.org/forum", -1);
			iSEM_appendLine(screenData, (s8*)"Thank you, and may the Lord Jesus Christ bless you richly. :-)", -1);
			iSEM_appendLine(screenData, NULL, 0);
			iSEM_appendLine(screenData, (s8*)"              _____", -1);
			iSEM_appendLine(screenData, (s8*)"             |     |", -1);
			iSEM_appendLine(screenData, (s8*)"             |     |", -1);
			iSEM_appendLine(screenData, (s8*)"     ________|     |________     In God's sight we've come together.", -1);
			iSEM_appendLine(screenData, (s8*)"    |                       |    We've come together to help each other.", -1);
			iSEM_appendLine(screenData, (s8*)"    |________       ________|    Let's grow this project up ... together!", -1);
			iSEM_appendLine(screenData, (s8*)"             |     |             In service and love to The Lord, forever!", -1);
			iSEM_appendLine(screenData, (s8*)"             |     |", -1);
			iSEM_appendLine(screenData, (s8*)"             |     |             Sponsored by:", -1);
			iSEM_appendLine(screenData, (s8*)"             |     |                LibSF -- Liberty Software Foundation", -1);
			iSEM_appendLine(screenData, (s8*)"             |     |", -1);
			iSEM_appendLine(screenData, (s8*)"             |     |             We need more coders. Please consider helping out.", -1);
			iSEM_appendLine(screenData, (s8*)"             |     |             Your contribution would make a difference.", -1);
			iSEM_appendLine(screenData, (s8*)"             |     |", -1);
			iSEM_appendLine(screenData, (s8*)"             |_____|", -1);
			iSEM_appendLine(screenData, NULL, 0);
		}
		// Navigate to the end of the content
		iSEM_navigateToEndLine(screenData, _screen);

		// Initially populate _jdebi
		// Load in the history if it exists
		if (!iSEM_loadFromDisk(command_editbox->p.em, (s8*)cgcCommandHistoryFilename, true))
		{
			iSEM_appendLine(command_editbox->p.em, (s8*)"*** Welcome to Visual FreePro, Junior! :-)", -1);
			iSEM_appendLine(command_editbox->p.em, (s8*)"*** For now, this can be thought of as a command window ... with a twist.", -1);
			iSEM_appendLine(command_editbox->p.em, (s8*)"*** It works like an editor window.  You can insert new lines, edit old ones, etc.", -1);
			iSEM_appendLine(command_editbox->p.em, (s8*)"*** To execute a command, press F6 or Enter if you're on the last line, or use F6 on any line.", -1);
			iSEM_appendLine(command_editbox->p.em, (s8*)"*** You can use clear, quit, ? 999, ? \"sample\" (literals), and ? _startupTime (global variable) in this daily build.", -1);
			iSEM_appendLine(command_editbox->p.em, (s8*)"*** Remember this always:  Love makes you smile. It keeps an inward peace unlike any other. :-)", -1);
		}

		// Navigate to the last line
		iSEM_navigateToEndLine(command_editbox->p.em, command_editbox);

		// Make sure there's a blank line at the end
		if (command_editbox->p.em->ecCursorLine->sourceCodePopulated != 0)
		{
			iSEM_appendLine(command_editbox->p.em, NULL, 0);
			iSEM_navigateToEndLine(command_editbox->p.em, command_editbox);
		}

		// Load some source code
		iSEM_loadFromDisk(sourceCode_editbox->p.em, (s8*)cgcStartupPrgFilename, true);

		// Redraw
		iVjr_appendSystemLog("Final render _jdebi");
		iWindow_render(gWinJDebi, true);

		// Remove the splash screen 1/2 second later
		CreateThread(0, 0, &iSplash_delete, (LPVOID)500, 0, 0);;
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
		bmpCaskIconsTiled			= iBmp_rawLoad(cgc_caskIconsBmp);
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
		SVariable* caption;


		//////////
		// Create the object
		//////
			// Create object
			gobj_splashListing = iObj_create(_OBJ_TYPE_SUBFORM, NULL);
			if (!gobj_splashListing)
				return;

			// Set the icon and border
			iObj_set_icon(gobj_splashListing, bmpOutputIcon);
			iVariable_set_s32(gobj_splashListing->p.borderStyle, _BORDER_STYLE_FIXED);


			//////////
			// Give it a caption
			//////
				caption = iVariable_createAndPopulate(_VAR_TYPE_CHARACTER, cgcSystemLog, sizeof(cgcSystemLog) - 1);
				iObj_set_caption(gobj_splashListing, caption);
				iVariable_delete(caption, true);


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
			gobj_splashListingEditbox->pa.font					= iFont_create((s8*)cgcFontName_defaultFixed, 8, FW_NORMAL, false, false);
			gobj_splashListingEditbox->p.em->font				= iFont_create((s8*)cgcFontName_defaultFixed, 8, FW_NORMAL, false, false);
			gobj_splashListingEditbox->ev.keyboard._onKeyDown	= (u32)&iSEM_onKeyDown;
			iVariable_set_bool(gobj_splashListingEditbox->p.visible, true);
			systemLog											= gobj_splashListingEditbox->p.em;
			systemLog->showEndLine								= true;
			systemLog->showCursorLine							= true;


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
		RECT lrc;


		// Make sure our environment is sane
		if (gobj_splashListing && gobj_splashListingEditbox)
		{
			// Move to the end of the list
			iSEM_navigateToEndLine(gobj_splashListingEditbox->p.em, gobj_splashListing);

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
			DrawText(bmp->hdc, tcAccomplishment, strlen(tcAccomplishment), &lrcAccomplishment, DT_SINGLELINE | DT_LEFT | DT_CALCRECT);


		//////////
		// Compute the size of the version text
		//////
			if (tcVersion)
			{
				// There is a version
				SelectObject(bmp->hdc, font8->hfont);
				SetRect(&lrcVersion, 0, 0, bmp->bi.biWidth, bmp->bi.biHeight);
				DrawText(bmp->hdc, tcVersion, strlen(tcVersion), &lrcVersion, DT_SINGLELINE | DT_LEFT | DT_CALCRECT);

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
				DrawText(bmp->hdc, tcVersion, strlen(tcVersion), &lrc, DT_SINGLELINE | DT_LEFT);
			}


		//////////
		// Add in the accomplishment
		//////
			// SEt for the accomplishment
			lrc.left = trc->right - lnWidthAccomplishment - 4;
			SelectObject(bmp->hdc, font9->hfont);
			SetTextColor(bmp->hdc, textColor);
			SetBkMode(bmp->hdc, TRANSPARENT);
			DrawText(bmp->hdc, tcAccomplishment, strlen(tcAccomplishment), &lrc, DT_SINGLELINE | DT_LEFT);


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

		iiVjr_renderAccomplishment(bmp, &lrc, _GREEN, "CHRTRAN() and STRTRAN()",					"0.52", false, false, false, 0, 0);

		iiVjr_renderAccomplishment(bmp, &lrc, _GREEN, "Bug fixes, memory leaks removed",			"0.51", false, false, false, -2, 0);

		iiVjr_renderAccomplishment(bmp, &lrc, _GREEN, "Editor highlights word under cursor",		"0.50", false, false, false, -2, 0);
		iiVjr_renderAccomplishment(bmp, &lrc, _GREEN, "UI redesign geared toward debugger",			"0.50", false, false, false, -2, 0);

		iiVjr_renderAccomplishment(bmp, &lrc, _GREEN, "Editor development",							"0.49", false, false, false, -2, 0);

		iiVjr_renderAccomplishment(bmp, &lrc, _GREEN, "Editor line numbers, breakpoints",			"0.48", false, false, false, -2, 0);

		iiVjr_renderAccomplishment(bmp, &lrc, _GREEN, "Editor resize CTRL+ and CTRL-",				"0.47", false, false, false, -2, 0);

		iiVjr_renderAccomplishment(bmp, &lrc, _GREEN, "Casks",										"0.46", false, true, false, -2, 0);

// Planned:
//		iiVjr_renderAccomplishment(bmp, &lrc, _BLUE,  "Syntax highlighting (future, James 4:15)",	"0.50", false, false, false, -2, 0);
		iiVjr_renderAccomplishment(bmp, &lrc, _GREEN, "Syntax highlighting",						"0.45", false, true, false, -2, 0);

		iiVjr_renderAccomplishment(bmp, &lrc, _GREEN, "Tabs expanded, mouse wheel",					"0.44", false, true, false, -2, 0);

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
