//////////
//
// /libsf/source/vjr/source/vjr_globals.h
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
// Global Variables
//////
	HINSTANCE			ghInstance							= null0;
	bool				glShuttingDown						= false;
//	ITaskbarList*		giTaskbar							= NULL;
	SThisCode*			_thisCodeNull						= NULL;


//////////
// TOOD: We need to add semaphores to these because the ultimate goal is to allow multiple
//       threads running simultaneously, but each of them running completely independent programs.
// BEGIN
//////
	SBuilder*			gWindows							= NULL;
	SBuilder*			gFonts								= NULL;
	SBuilder*			gBreakpoints						= NULL;
//////
// END
//////////

	HWND				ghwndMsg							= null0;
	CRITICAL_SECTION	cs_uniqueIdAccess;
	CRITICAL_SECTION	cs_logData;
	u32					gnNextUniqueId						= 0;
	s64					systemStartedMs						= 0;
	u32					systemStartedTickCount				= 0;

	// For splash aria and general sound support
	static union {
		s8*				soundData_s8;
		f32*			soundData_f32;
	};
	u32					soundOffset, soundCount;

	// Main screen display history, and system log data
	SEM*				screenData							= NULL;									// The data displayed on the screen
	SEM*				systemLog							= NULL;									// The data displayed on the screen

	// Global variables
	SVariable*			varGlobals							= NULL;									// All global variables are stored
	SVariable*			varConstant_space					= NULL;									// Holds a single space, and is a constant
	SVariable*			varEmptyString						= NULL;
	SVariable*			var2000Spaces						= NULL;
	SVariable*			varZero								= NULL;									// A constant 0
	SVariable*			varTrue								= NULL;									// A constant .T.
	SVariable*			varFalse							= NULL;									// A constant .F.
	SVariable*			varSix								= NULL;									// A numeric value of 6, used for padding widths
	SVariable*			varTwoFiftyFive						= NULL;									// A numeric value of 255, used for color channels

	// Default variable values used for references
	SVariable*			varDefault_null						= NULL;									// NULL
	SVariable*			varDefault_numeric					= NULL;									// "   0"
	SVariable*			varDefault_s32						= NULL;									// 0
	SVariable*			varDefault_u32						= NULL;									// 0
	SVariable*			varDefault_f32						= NULL;									// +0.0
	SVariable*			varDefault_s64						= NULL;									// 0
	SVariable*			varDefault_u64						= NULL;									// 0
	SVariable*			varDefault_f64						= NULL;									// +0.0
	SVariable*			varDefault_date						= NULL;									// "  /  /    "
	SVariable*			varDefault_datetime					= NULL;									// "  /  /       :  :     "
	SVariable*			varDefault_currency					= NULL;									// 0.0000
	SVariable*			varDefault_s16						= NULL;									// 0
	SVariable*			varDefault_u16						= NULL;									// 0
	SVariable*			varDefault_s8						= NULL;									// 0
	SVariable*			varDefault_u8						= NULL;									// 0
	SVariable*			varDefault_logical					= NULL;									// .F.
	SVariable*			varDefault_bitmap					= NULL;									// 1x1 white pixel bitmap
	SVariable*			varDefault_thiscode					= NULL;									// An empty function with no executable code, no parameters, no variables, and no parents

	// Focus highlight windows, and tooltip window
	SBuilder*			gFocusHighlights					= NULL;									// Holds SFocusHighlight structures
	SSplash				gSplash;																	// For the active splash screen

	// Global sourceLight accumulator window
	SBitmap*			bmpSourceLight						= NULL;									// SourceLight is always contextual.  This bitmap is constantly created and destroyed.
	s32					gnSourceLightX						= _SOURCELIGHT_MARGIN;
	s32					gnSourceLightY						= _SOURCELIGHT_MARGIN;

	// App icons
	SBitmap*			bmpVjrIcon							= NULL;
	SBitmap*			bmpVjrSplash						= NULL;
	SBitmap*			bmpJDebiIcon						= NULL;
	SBitmap*			bmpSourceCodeIcon					= NULL;
	SBitmap*			bmpLocalsIcon						= NULL;
	SBitmap*			bmpWatchIcon						= NULL;
	SBitmap*			bmpCommandIcon						= NULL;
	SBitmap*			bmpDebugIcon						= NULL;
	SBitmap*			bmpOutputIcon						= NULL;
	SBitmap*			bmpSourceLightIcon					= NULL;

	// Carousel
	SBitmap*			bmpCarouselCarouselIcon				= NULL;
	SBitmap*			bmpCarouselTabsIcon					= NULL;
	SBitmap*			bmpCarouselPad						= NULL;
	SBitmap*			bmpCarouselIcon						= NULL;

	// When there is no image
	SBitmap*			bmpNoImage							= NULL;

	// For mouse objects
	SBitmap*			bmpMove								= NULL;									// Icons used for move, minimize, maximize, close
	SBitmap*			bmpMinimize							= NULL;
	SBitmap*			bmpMaximize							= NULL;
	SBitmap*			bmpClose							= NULL;

	// For the corner triangles
	SBitmap*			bmpArrowUl							= NULL;									// Icons used for the move arrows
	SBitmap*			bmpArrowUr							= NULL;
	SBitmap*			bmpArrowLr							= NULL;
	SBitmap*			bmpArrowLl							= NULL;

	// For checkbox
	SBitmap*			bmpCheckboxOn						= NULL;
	SBitmap*			bmpCheckboxOff						= NULL;

	// For button
	SBitmap*			bmpButton							= NULL;

	// For textbox
	SBitmap*			bmpTextbox							= NULL;

	// For radio
	SBitmap*			bmpRadio							= NULL;
	SBitmap*			bmpRadioDot							= NULL;

	// Dapple
	SBitmap*			bmpDapple1							= NULL;
	SBitmap*			bmpDapple2							= NULL;

//////////
// Cask graphics
// BEGIN
//////
	SBitmap*			bmpCaskIconsTiled					= NULL;			// Single master icon file
	SBitmap*			bmpCaskRoundLeft					= NULL;
	SBitmap*			bmpCaskRoundRight					= NULL;
	SBitmap*			bmpCaskSquareLeft					= NULL;
	SBitmap*			bmpCaskSquareRight					= NULL;
	SBitmap*			bmpCaskTriangleLeft					= NULL;
	SBitmap*			bmpCaskTriangleRight				= NULL;
	SBitmap*			bmpCaskTildeLeft					= NULL;
	SBitmap*			bmpCaskTildeRight					= NULL;
	SBitmap*			bmpCaskPips1						= NULL;
	SBitmap*			bmpCaskPips2						= NULL;
	SBitmap*			bmpCaskPips3						= NULL;
	SBitmap*			bmpCaskSideExtender					= NULL;
	SBitmap*			bmpCaskSideExtenderLeft				= NULL;
	SBitmap*			bmpCaskSideExtenderMiddle			= NULL;
	SBitmap*			bmpCaskSideExtenderRight			= NULL;
	SBitmap*			bmpCaskExtenderMiddle				= NULL;
	SBitmap*			bmpCaskExtenderLeft1				= NULL;
	SBitmap*			bmpCaskExtenderLeft2				= NULL;
	SBitmap*			bmpCaskExtenderRight2				= NULL;
	SBitmap*			bmpCaskExtenderRight1				= NULL;
// TODO:  Cask boxes, 13 additional pieces
	SBgra				caskOrange1;
	SBgra				caskOrange2;
	SBgra				caskOrange3;
	SBgra				caskRed1;
	SBgra				caskRed2;
	SBgra				caskRed3;
	SBgra				caskBlue1;
	SBgra				caskBlue2;
	SBgra				caskBlue3;
	SBgra				caskPurple1;
	SBgra				caskPurple2;
	SBgra				caskPurple3;
	SBgra				caskCyan1;
	SBgra				caskCyan2;
	SBgra				caskCyan3;
	SBgra				caskGreen1;
	SBgra				caskGreen2;
	SBgra				caskGreen3;
	SBgra				caskYellow1;
	SBgra				caskYellow2;
	SBgra				caskYellow3;
	SBgra				caskGray1;
	SBgra				caskGray2;
	SBgra				caskGray3;
	SBgra				caskWhite1;
	SBgra				caskWhite2;
	SBgra				caskWhite3;
	SBgra				caskBlack1;
	SBgra				caskBlack2;
	SBgra				caskBlack3;
//////
// END
//////////


//////////
// General icons
// BEGIN
//////
	cu32	_BMP__pursueAcceptOne							= 0;			// Accept one level of the current pursues
	cu32	_BMP__pursue									= 1;			// Enter another pursue level
	cu32	_BMP__pursueRejectOne							= 2;			// Reject one level of the current pursues
	cu32	_BMP__noStepIntoFunctionEnable					= 3;			// Allow this function to be stepped into"
	cu32	_BMP__noStepIntoFunctionDisable					= 4;			// Disallow this function to be stepped into"
	cu32	_BMP__breadcrumbsPrevDocument					= 5;			// Move to the previous breadcrumb
	cu32	_BMP__breadcrumbsNextDocument					= 6;			// Move to the next breadcrumb
	cu32	_BMP__breadcrumbsLineEnable						= 7;			// Line breadcrumbs
	cu32	_BMP__breadcrumbsDisable						= 8;			// Disable breadcrumbs
	cu32	_BMP__stepInto									= 9;			// Steps into the current source code line
	cu32	_BMP__stepOver									= 10;			// Steps over the current source code line
	cu32	_BMP__stepOut									= 11;			// Steps out of the current function
	cu32	_BMP__stepOutAll								= 12;			// Steps forward to next return
	cu32	_BMP__stepToCursorLine							= 13;			// Steps forward to the cursor line
	cu32	_BMP__stepInHorizontal							= 14;			// Steps horizontally into the current source code line
	cu32	_BMP__stepOutHorizontal							= 15;			// Steps horizontally out of the current source code line
	cu32	_BMP__stepOutOne								= 16;			// Steps out of the current block
	cu32	_BMP__stepToError								= 17;			// Steps back to the line causing the error
	cu32	_BMP__breakpointSetLine							= 18;			// Set an unconditional breakpoint on the current line
	cu32	_BMP__breakpointView							= 19;			// View all breakpoints
	cu32	_BMP__breakpointSetHorizontal					= 20;			// Set a horizontal breakpoint on the current line
	cu32	_BMP__breakpointSetCondition					= 21;			// Set a conditional breakpoint on the current line
	cu32	_BMP__breakpointDelete							= 22;			// Delete the current breakpoint
	cu32	_BMP__breakpointEnableAll						= 23;			// Enable all breakpoints
	cu32	_BMP__breakpointDisableAll						= 24;			// Disable all breakpoints
	cu32	_BMP__breakpointToggleEnabledAll				= 25;			// Toggle all breakpoints' enabled status
	cu32	_BMP__breakpointDeleteAll						= 26;			// Delete all breakpoints
	cu32	_BMP__findPrevCurrentDocument					= 27;			// Find the previous matching entry in the current document
	cu32	_BMP__findNextCurrentDocument					= 28;			// Find the next matching entry in the current document
	cu32	_BMP__findPrevAllDocuments						= 29;			// Find the previous matching entry in all documents
	cu32	_BMP__findNextAllDocuments						= 30;			// Find the next matching entry in all documents
	cu32	_BMP__replacePrevCurrentDocument				= 31;			// Find and replace the previous matching entry in the current document
	cu32	_BMP__replaceNextCurrentDocument				= 32;			// Find and replace the next matching entry in the current document
	cu32	_BMP__replacePrevAllDocuments					= 33;			// Find and replace the previous matching entry in all documents
	cu32	_BMP__replaceNextAllDocuments					= 34;			// Find and replace the next matching entry in all documents
	cu32	_BMP__findShowAll								= 35;			// Show all finds
	cu32	_BMP__bookmarkAddHorizontal						= 36;			// Adds horizontal bookmark at the current line and column
	cu32	_BMP__bookmarkDeleteHorizontal					= 37;			// Delete horizontal bookmark at the current line and column
	cu32	_BMP__bookmarkPrevAllDocuments					= 38;			// Goto the previous bookmark in all documents
	cu32	_BMP__bookmakrNextAllDocuments					= 39;			// Goto the next bookmark in all documents
	cu32	_BMP__bookmarkPrevCurrentDocument				= 40;			// Goto the previous bookmark in the current document
	cu32	_BMP__bookmarkNextCurrentDocument				= 41;			// Goto the next bookmark in the current document
	cu32	_BMP__bookmarkAdd								= 42;			// Add bookmark at the current line
	cu32	_BMP__bookmarkDelete							= 43;			// Delete bookmark at the current line
	cu32	_BMP__bookmarkShow								= 44;			// Shows all bookmarks for rapid navigation
	cu32	_BMP__anchor									= 45;			// Anchors the current document to the next version
	cu32	_BMP__undo										= 46;			// Undo last operation
	cu32	_BMP__redo										= 47;			// Redo last operation
	cu32	_BMP__anchorPrev								= 48;			// Navigate to previous anchor version" var1="anchorCurrent-1
	cu32	_BMP__anchorNext								= 49;			// Navigate to next anchor version" var1="anchorCurrent+1
	cu32	_BMP__programRegisters							= 50;			// Display the program registers
	cu32	_BMP__controlRegisters							= 51;			// Display the control registers
	cu32	_BMP__integerRegisters							= 52;			// Display the integer registers
	cu32	_BMP__floatingPointRegisters					= 53;			// Display the floating point registers
	cu32	_BMP__sourceCode								= 54;			// Display the source code window
	cu32	_BMP__callStack									= 55;			// Display the call stack window
	cu32	_BMP__snippets									= 56;			// Display the snippets window
	cu32	_BMP__threads									= 57;			// Display the threads window
	cu32	_BMP__programs									= 58;			// Display the programs window
	cu32	_BMP__memory									= 59;			// Display the memory window
	cu32	_BMP__layout									= 60;			// Display the layout window
	cu32	_BMP__application								= 61;			// Display the application window
	cu32	_BMP__timers									= 62;			// Display the timers window
	cu32	_BMP__autos										= 63;			// Display the autos window
	cu32	_BMP__locals									= 64;			// Display the locals window
	cu32	_BMP__watch										= 65;			// Display the watch window
	cu32	_BMP__hover										= 66;			// Display the hover window
	cu32	_BMP__play										= 67;			// Resume normal execution
	cu32	_BMP__pause										= 68;			// Pause execution of the current thread
	cu32	_BMP__unused1									= 69;			// unused
	cu32	_BMP__restart									= 70;			// Restart with normal execution
	cu32	_BMP__assemblyMix								= 71;			// Toggle display of virtual machine disassembly
	cu32	_BMP__breadcrumbsPrev							= 72;			// Move to the previous breadcrumbs only in the current function
	cu32	_BMP__breadcrumbsNext							= 73;			// Move to the next breadcrumbs only in the current function
	cu32	_BMP__breadcrumbsPrevFunction					= 74;			// Move to the breadcrumbs in previous function
	cu32	_BMP__breadcrumbsNextFunction					= 75;			// Move to the breadcrumbs in next function
	cu32	_BMP__pursuePrev								= 76;			// Examine previous pursue level" var1="pursueCurrent-1/>
	cu32	_BMP__pursueNext								= 77;			// Examine next pursue level" var1="pursueCurrent+1
	cu32	_BMP__breadcrumbsDeltasEnable					= 78;			// Breadcrumb deltas enabled
	cu32	_BMP__stack										= 79;			// Display stack
	cu32	_BMP__scratch									= 80;			// Display scratch memory
	cu32	_BMP__viewEditToggle							= 81;			// Toggle source code edit view
	cu32	_BMP__viewTouchToggle							= 82;			// Toggle touch view
	cu32	_BMP__viewBounceToggle_On						= 83;			// Toggle viewing the current line in bounce view
	cu32	_BMP__viewBoolToggle_On							= 84;			// Toggle viewing the current line in bool view
	cu32	_BMP__chainNew									= 85;			// Create a new chain view window
	cu32	_BMP__chainAddLine								= 86;			// Add a line to the active chain view window
	cu32	_BMP__chainAddBlock								= 87;			// Add a block to the active chain view window
	cu32	_BMP__chainAddFunction							= 88;			// Add a function to the active chain view window
	cu32	_BMP__chainAddFile								= 89;			// Add the current document to the active chain view window
	cu32	_BMP__tabIn										= 90;			// Shifts text right
	cu32	_BMP__tabOut									= 91;			// Shifts text left
	cu32	_BMP__shiftDown									= 92;			// Shifts text down
	cu32	_BMP__shiftUp									= 93;			// Shifts text up
	cu32	_BMP__lineComment								= 94;			// Prefix with line comments
	cu32	_BMP__blockComment								= 95;			// Surround with a block comment
	cu32	_BMP__wordLeft									= 96;			// Move word left
	cu32	_BMP__wordRight									= 97;			// Move word right
	cu32	_BMP__lineStart									= 98;			// Move to line start
	cu32	_BMP__lineEnd									= 99;			// Move to line end
	cu32	_BMP__screenTop									= 100;			// Move to top line on screen
	cu32	_BMP__screenBottom								= 101;			// Move to bottom line on screen
	cu32	_BMP__fileTop									= 102;			// Move to top line of file
	cu32	_BMP__fileEnd									= 103;			// Move to bottom line of file
	cu32	_BMP__previousBlock								= 104;			// Move up to bottom of previous block
	cu32	_BMP__nextBlockOut								= 105;			// Move down to top of next outer block
	cu32	_BMP__previousFunction							= 106;			// Move up to bottom of previous function
	cu32	_BMP__nextFunction								= 107;			// Move top top of next function
	cu32	_BMP__nextBlockIn								= 108;			// Move down to top of next inner block
	cu32	_BMP__clipListNew								= 109;			// Create a new clip list
	cu32	_BMP__clipListDelete							= 110;			// Delete the active clip list entry
	cu32	_BMP__clipListCopyBlock							= 111;			// Copy selected block to clip list
	cu32	_BMP__clipListCutBlock							= 112;			// Cut selected block to clip list
	cu32	_BMP__clipListPaste								= 113;			// Paste from clip list
	cu32	_BMP__clipListPrepend							= 114;			// Set clip list to prepend added items
	cu32	_BMP__clipListAppend							= 115;			// Set clip list to append added items
	cu32	_BMP__clipListView								= 116;			// View/edit clip list entries
	cu32	_BMP__assemblyOff								= 117;			// Toggle display of virtual machine disassembly
	cu32	_BMP__pursueCount								= 118;			// Shows current pursue view level, and total nested levels" var1="pursueCurrent" var2="pursueCount
	cu32	_BMP__assemblyOnly								= 119;			// Toggle display of virtual machine disassembly
	cu32	_BMP__anchorCount								= 120;			// Shows current anchor view level, and total anchor levels" var1="anchorCurrent" var2="anchorCount
	cu32	_BMP__suspend									= 121;			// Suspend the virtual machine" var1="suspend1" var2="suspend2" var3="suspend3" var4="suspend4" var5="suspend5" var6="suspend6" var7="suspend7" var8="suspend8
	cu32	_BMP__resume									= 122;			// Resume the virtual machine" var1="resume1" var2="resume2" var3="resume3" var4="resume4" var5="resume5" var6="resume6" var7="resume7" var8="resume8
	cu32	_BMP__breadcrumbsCount							= 123;			// Shows the breadcrumbs count" var1="breadcrumbsCount
	cu32	_BMP__pursueEnabled								= 124;			// Shown when pursue mode is enabled
	cu32	_BMP__clipListCount								= 125;			// Shows how many items are in the clip list
	cu32	_BMP__chainDelete								= 126;			// Deletes the current chain view
	cu32	_BMP__chainCount								= 127;			// Shows how many chain views there are
	cu32	_BMP__chainView									= 128;			// View/edit chain view entries
	cu32	_BMP__chainAddHorizontal						= 129;			// Add a line to the active chain view window
	cu32	_BMP__noStepIntoFunctionInstanceEnable			= 130;			// Allow the instance of this function to be stepped into"
	cu32	_BMP__noStepIntoFunctionInstanceDisable			= 131;			// Disallow the instance of this function to be stepped into"
	cu32	_BMP__breadcrumbsView							= 132;			// View all breadcrumbs
	cu32	_BMP__stepToCursorHorizontal					= 133;			// Steps forward to the horizontal cursor position on the current line
	cu32	_BMP__stepInOne									= 134;			// Steps in to the next deeper block
	cu32	_BMP__clipListTrailingCRLF_On					= 135;			// Each appended item will automatically append a trailing CR/LF
	cu32	_BMP__clipListTrailingCRLF_Off					= 136;			// Each appended item will not automatically append a trailing CR/LF
	cu32	_BMP__clipListCopyLine							= 137;			// Copy current line to clip list
	cu32	_BMP__clipListCutLine							= 138;			// Cut current line to clip list
	cu32	_BMP__clipListCopyHorizontal					= 139;			// Copy horizontal portion to clip list
	cu32	_BMP__clipListCutHorizontal						= 140;			// Cut horizontal portion to clip list
	cu32	_BMP__clipListCopyDocument						= 141;			// Copy entire document to clip list
	cu32	_BMP__clipListCutDocument						= 142;			// Cut entire document to clip list
	cu32	_BMP__clipListPasteDelete						= 143;			// Paste from and delete clip list
	cu32	_BMP__clipListCopyBlockNew						= 144;			// Copy selected block to a new clip list
	cu32	_BMP__clipListCutBlockNew						= 145;			// Cut selected block to a new clip list
	cu32	_BMP__clipListCopyLineNew						= 146;			// Copy current line to a new clip list
	cu32	_BMP__clipListCutLineNew						= 147;			// Cut current line to a new clip list
	cu32	_BMP__clipListCopyHorizontalNew					= 148;			// Copy horizontal portion to a new clip list
	cu32	_BMP__clipListCutHorizontalNew					= 149;			// Cut horizontal portion to a new clip list
	cu32	_BMP__clipListCopyDocumentNew					= 150;			// Copy entire document to a new clip list
	cu32	_BMP__clipListCutDocumentNew					= 151;			// Cut entire document to a new clip list
	cu32	_BMP__clipListReplace							= 152;			// Set clip list to replace added items
	cu32	_BMP__breakpointToggleEnabledEnable				= 153;			// Toggle the breakpoint's enabled status
	cu32	_BMP__breakpointToggleEnabledDisable			= 154;			// Toggle the breakpoint's enabled status
	cu32	_BMP__breakpointToggleHorizontalEnabledEnable	= 155;			// Toggle the horizontal breakpoint's enabled status
	cu32	_BMP__breakpointToggleHorizontalEnabledDisable	= 156;			// Toggle the horizontal breakpoint's enabled status
	cu32	_BMP__replaceAllPrevCurrentDocument				= 157;			// Find and replace all using the previous matching entry in the current document
	cu32	_BMP__replaceAllNextCurrentDocument				= 158;			// Find and replace all using the previous matching entry in the current document
	cu32	_BMP__replaceAllPrevAllDocuments				= 159;			// Find and replace all using the previous matching entry in all documents
	cu32	_BMP__replaceAllNextAllDocuments				= 160;			// Find and replace all using the previous matching entry in all documents
	cu32	_BMP__replaceAllView							= 161;			// View all replace candidates in current document, or all documents
	cu32	_BMP__toUpper									= 162;			// Convert to upper case
	cu32	_BMP__toLower									= 163;			// Convert to lower case
	cu32	_BMP__toFlip									= 164;			// Flip upper case to lower case, and lower case to upper case
	cu32	_BMP__toProper									= 165;			// Convert to proper case
	cu32	_BMP__findWordUpCurrentDocument					= 166;			// Find the word in the current document at the cursor up
	cu32	_BMP__findWordDownCurrentDocument				= 167;			// Find the word in the current document at the cursor down
	cu32	_BMP__findWordView								= 168;			// View all instances of the word at the cursor in current document, or all documents
	cu32	_BMP__findWordUpAllDocuments					= 169;			// Find the word in all documents at the cursor up
	cu32	_BMP__findWordDownAllDocuments					= 170;			// Find the word in all currents document at the cursor down
	cu32	_BMP__breakpointOneAddLine						= 171;			// Adds a breakpoint to stop at one time on the current line
	cu32	_BMP__breakpointOneAddHorizontal				= 172;			// Adds a breakpoint to stop at one time horizontally
	cu32	_BMP__breakpointOneDelete						= 173;			// Deletes a breakpoint to stop at one time
	cu32	_BMP__breakpointOneBlocksAdd					= 174;			// Adds a breakpoint to stop at one time at the start of each block
	cu32	_BMP__breakpointOneBlocksDelete					= 175;			// Deletes all breakpoints to stop at one time at the start of each block
	cu32	_BMP__functionUpCurrentDocument					= 176;			// Move to the previous function in the current document
	cu32	_BMP__functionDownCurrentDocument				= 177;			// Move to the previous function in the current document
	cu32	_BMP__functionUpAllDocuments					= 178;			// Move to the previous function in all documents
	cu32	_BMP__functionDownAllDocuments					= 179;			// Move to the previous function in all documents
	cu32	_BMP__functionView								= 180;			// View all functions in the current document, or all documents
	cu32	_BMP__deleteToEndOfLine							= 181;			// Deletes everything at end of line
	cu32	_BMP__deleteToStartOfLine						= 182;			// Deletes everything to start of line
	cu32	_BMP__selectLine								= 183;			// Begins selecting in entire line mode
	cu32	_BMP__selectCommand								= 184;			// Begins selecting in entire line / command mode
	cu32	_BMP__selectColumn								= 185;			// Begins selecting in column
	cu32	_BMP__selectStart								= 186;			// Begins selecting at the cursor location
	cu32	_BMP__selectBlock								= 187;			// Selects the current block
	cu32	_BMP__selectFunction							= 188;			// Selects the current function
	cu32	_BMP__selectBlockOut							= 189;			// Selects up to include the immediate outter block
	cu32	_BMP__selectBlockIn								= 190;			// Selects down to the inner block
	cu32	_BMP__selectBlockUp								= 191;			// Selects the immediate block up
	cu32	_BMP__selectBlockDown							= 192;			// Selects the immediate block down
	cu32	_BMP__selectFunctionUpCurrentDocument			= 193;			// Selects the immediate function above in the current document
	cu32	_BMP__selectFunctionDownCurrentDocument			= 194;			// Selects the immediate function below in the current document
	cu32	_BMP__selectFunctionUpAllDocuments				= 195;			// Selects the immediate function above in all documents
	cu32	_BMP__selectFunctionDownAllDocuments			= 196;			// Selects the immediate function below in all documents
	cu32	_BMP__selectNone								= 197;			// Removes all selections
	cu32	_BMP__selectMode_Unselected						= 198;			// Unselect anything selected, and select only the new region
	cu32	_BMP__selectAddMode_Unselected					= 199;			// Adds the new selected region to the current selection
	cu32	_BMP__selectSubtractMode_Unselected				= 200;			// Trims out the new selected region from the current selection
	cu32	_BMP__selectUnionMode_Unselected				= 201;			// Trims the current selection down to the union with the new selected region
	cu32	_BMP__selectAllCurrentDocument					= 202;			// Selects all in the current document
	cu32	_BMP__viewSpreadsheetToggle						= 203;			// Toggle spreadsheet edit view
	cu32	_BMP__viewBounceToggle_Off						= 204;			// Toggle viewing the current line in bounce view
	cu32	_BMP__viewBoolToggle_Off						= 205;			// Toggle viewing the current line in bool view
	cu32	_BMP__chainAddSpreadsheet						= 206;			// Add data from the current spreadsheet view to the active chain view window
	cu32	_BMP__selectMode_Selected						= 207;			// Unselect anything selected, and select only the new region
	cu32	_BMP__selectAddMode_Selected					= 208;			// Adds the new selected region to the current selection
	cu32	_BMP__selectSubtractMode_Selected				= 209;			// Trims out the new selected region from the current selection
	cu32	_BMP__selectUnionMode_Selected					= 210;			// Trims the current selection down to the union with the new selected region
	cu32	_BMP__selectMode_Toggle							= 211;			// Toggle unselecting anything selected, and select only the new region
	cu32	_BMP__selectAddMode_Toggle						= 212;			// Toggle adding the new selected region to the current selection
	cu32	_BMP__selectSubtractMode_Toggle					= 213;			// Toggle trimming out the new selected region from the current selection
	cu32	_BMP__selectUnionMode_Toggle					= 214;			// Toggle trimming the current selection down to the union with the new selected region
	cu32	_BMP__vvmSettings								= 215;			// View the VVM settings
	cu32	_BMP__breadcrumbsHorizontalEnable				= 216;			// Horizontal breadcrumbs
	cu32	_BMP__breadcrumbsDeltasDisable					= 217;			// Breadcrumb deltas disabled
	cu32	_BMP__breadcrumbsClear							= 218;			// Enable breadcrumbs deltas
	cu32	_BMP__vvmDebuggers								= 219;			// View the multiple VVM debugger instance running
	cu32	_BMP__vvmLink									= 220;			// Link this debugger instance to another debugger instance
	cu32	_BMP__chainPursue								= 221;			// Add pursue line data to the active chain view window
	cu32	_BMP__breadcrumbsDeltaPrev						= 222;			// Move to previous breadcrumb in the current document which had a delta
	cu32	_BMP__breadcrumbsDeltaNext						= 223;			// Move to next breadcrumb in the current document which had a delta
	cu32	_BMP__vvmNext									= 224;			// Move to next debugger instance
	cu32	_BMP__vvmPrev									= 225;			// Move to previous debugger instance
	cu32	_BMP__chainAddBreadcrumbs						= 226;			// Add breadcrumbs to the active chain view window
	cu32	_BMP__stepSetCurrentLine						= 227;			// Set the next source code line to execute
	cu32	_BMP__stepShowCurrentLine						= 228;			// Show the current executing source code line
	cu32	_BMP__stepSetCurrentHorizontal					= 229;			// Set the next source code command to execute horizontally
	cu32	_BMP__chainAddBreadcrumbsAndDeltas				= 230;			// Add breadcrumbs and deltas to the active chain view window
	cu32	_BMP__chainAddBreadcrumbsDeltasOnly				= 231;			// Add breadcrumb deltas to the active chain view window
	cu32	_BMP__viewEdit									= 232;			// Switch to source code edit view
	cu32	_BMP__viewTouch									= 233;			// Switch to touch view
	cu32	_BMP__viewSpreadsheet							= 234;			// Switch to spreadsheet edit view
	cu32	_BMP__resizer									= 235;			// Resize the control
	cu32	_BMP__breadcrumbsDeltaPrevDocument				= 236;			// Move to previous breadcrumb which had a delta
	cu32	_BMP__breadcrumbsDeltaNextDocument				= 237;			// Move to next breadcrumb which had a delta
	cu32	_BMP__pursueDeltaPrev							= 238;			// Move to the previous delta in the current pursue
	cu32	_BMP__pursueDeltaNext							= 239;			// Move to the next delta in the current pursue
	cu32	_BMP__deltaPrev									= 240;			// Move to the previous delta
	cu32	_BMP__deltaNext									= 241;			// Move to the next delta
	cu32	_BMP__chainPursueDeltas							= 242;			// Add pursue deltas data to the active chain view window
	cu32	_BMP__roundRed									= 243;			// Round red icon
	cu32	_BMP__roundGrn									= 244;			// Round green icon
	cu32	_BMP__roundBlu									= 245;			// Round blue icon
	cu32	_BMP__edit										= 246;			// Edit icon
	cu32	_BMP__move										= 247;			// Move icon
	cu32	_BMP__stretch									= 248;			// Stretch icon
	cu32	_BMP__rotate									= 249;			// Rotate icon
	cu32	_BMP__exit										= 250;			// Exit icon
	cu32	_BMP__unused2									= 251;			// unused
	cu32	_BMP__unused3									= 252;			// unused
	cu32	_BMP__new										= 253;			// New icon
	cu32	_BMP__run										= 254;			// Run icon
	cu32	_BMP__SourceLight								= 255;			// SourceLight icon
	cu32	_BMP__save										= 256;			// Save icon
	cu32	_BMP__saveAll									= 257;			// Save all icon
	cu32	_BMP__open										= 258;			// Open icon
	cu32	_BMP__cross										= 259;			// Cross icon
	cu32	_BMP__app_win									= 260;			// Application icon
	cu32	_BMP__halt_win									= 261;			// Hand/halt! icon
	cu32	_BMP__question_mark_win							= 262;			// Question mark icon
	cu32	_BMP__exclamation_point_win						= 263;			// Exclamation point icon
	cu32	_BMP__stop_sign_win								= 264;			// Stop sign icon
	cu32	_BMP__shield_win								= 265;			// Shield icon
	// Maximum
	cu32	_BMP__ARRAY_MAX									= 265;			// N icons in the tile/strip


	// Constants for the tiled strip layout
	cu32	_BMP__ARRAY_STRIDE_WIDTH						= 38;			// 38 pixels wide
	cu32	_BMP__ARRAY_STRIDE_HEIGHT						= 38;			// 38 pixels tall
	cu32	_BMP__ARRAY_WIDTH								= 36;			// 36 pixels wide
	cu32	_BMP__ARRAY_HEIGHT								= 36;			// 36 pixels tall

	// Actual bitmaps
	SBitmap* bmpArrayTiled									= NULL;
	SBitmap* bmpArray[_BMP__ARRAY_MAX];
//////
// END
//////////


	// For accomplishments
	SBitmap*			bmpStoplightRed						= NULL;
	SBitmap*			bmpStoplightAmber					= NULL;
	SBitmap*			bmpStoplightGreen					= NULL;
	SBitmap*			bmpStoplightBlue					= NULL;

	// For breakpoints
	SBitmap*			bmpBreakpointAlways					= NULL;
	SBitmap*			bmpBreakpointAlwaysCountdown		= NULL;
	SBitmap*			bmpConditionalTrue					= NULL;
	SBitmap*			bmpConditionalFalse					= NULL;
	SBitmap*			bmpConditionalTrueCountdown			= NULL;
	SBitmap*			bmpConditionalFalseCountdown		= NULL;


	// Default screens used by VJr
	SObject*			_settings							= NULL;
	SObject*			_screen								= NULL;
	SObject*			screen_editbox						= NULL;
	SObject*			_jdebi								= NULL;
	SObject*			sourceCode							= NULL;
	SObject*			locals								= NULL;
	SObject*			watch								= NULL;
	SObject*			command								= NULL;
	SObject*			debug								= NULL;
	SObject*			output								= NULL;
	SObject*			sourceLight							= NULL;
	SObject*			sourceLight_empty					= NULL;
	SObject*			sourceCode_editbox					= NULL;
	SObject*			locals_editbox						= NULL;
	SObject*			watch_editbox						= NULL;
	SObject*			command_editbox						= NULL;
	SObject*			debug_editbox						= NULL;
	SObject*			output_editbox						= NULL;
	SObject*			gobj_splashListing					= NULL;
	SObject*			gobj_splashListingEditbox			= NULL;

	// Windows related to the objects
	SWindow*			gWinJDebi							= NULL;

	// Default class structures
	SObject*			gobj_defaultEmpty					= NULL;
	SObject*			gobj_defaultForm					= NULL;
	SObject*			gobj_defaultSubform					= NULL;
	SObject*			gobj_defaultLabel					= NULL;
	SObject*			gobj_defaultTextbox					= NULL;
	SObject*			gobj_defaultButton					= NULL;
	SObject*			gobj_defaultImage					= NULL;
	SObject*			gobj_defaultCheckbox				= NULL;
	SObject*			gobj_defaultOption					= NULL;
	SObject*			gobj_defaultRadio					= NULL;
	SObject*			gobj_defaultCmdGroup				= NULL;
	SObject*			gobj_defaultOptGroup				= NULL;
	SObject*			gobj_defaultListbox					= NULL;
	SObject*			gobj_defaultCombobox				= NULL;
	SObject*			gobj_defaultFormset					= NULL;
	SObject*			gobj_defaultToolbar					= NULL;
	SObject*			gobj_defaultSeparator				= NULL;
	SObject*			gobj_defaultLine					= NULL;
	SObject*			gobj_defaultShape					= NULL;
	SObject*			gobj_defaultContainer				= NULL;
	SObject*			gobj_defaultControl					= NULL;
	SObject*			gobj_defaultGrid					= NULL;
	SObject*			gobj_defaultColumn					= NULL;
	SObject*			gobj_defaultHeader					= NULL;
	SObject*			gobj_defaultOleBound				= NULL;
	SObject*			gobj_defaultOleContain				= NULL;
	SObject*			gobj_defaultSpinner					= NULL;
	SObject*			gobj_defaultTimer					= NULL;
	SObject*			gobj_defaultHyperlink				= NULL;
	SObject*			gobj_defaultCollection				= NULL;
	SObject*			gobj_defaultPage					= NULL;
	SObject*			gobj_defaultPageFrame				= NULL;
	SObject*			gobj_defaultSession					= NULL;
	SObject*			gobj_defaultCustom					= NULL;
	SObject*			gobj_defaultException				= NULL;
	SObject*			gobj_defaultSettings				= NULL;


	//////////
	// General defaults
	//////
		SFont*			gsFontDefault						= NULL;									// Ubuntu 10 pt
		SFont*			gsFontDefault9						= NULL;									// Ubuntu 9 pt
		SFont*			gsFontDefaultBold					= NULL;									// Ubuntu 10 pt bold
		SFont*			gsFontDefaultItalic8				= NULL;									// Ubuntu 9 pt Italic
		SFont*			gsFontDefaultFixedPoint				= NULL;									// Ubuntu Mono 10 pt
		SFont*			gsWindowTitleBarFont				= NULL;									// Ubuntu Condensed Bold 12 pt
		SFont*			gsWindowTitleBarFontSubform			= NULL;									// Ubuntu Condensed Bold 10 pt
		SFont*			gsFontDefaultTooltip				= NULL;									// Ubuntu Condensed Bold 9 pt
		SFont*			gsFontCask							= NULL;									// Cask font, Ubuntu Bold 30 pt
		// Global colors
		const SBgra		whiteColor							= { _whiteColor };
		const SBgra		grayColor							= { _grayColor };
		const SBgra		blackColor							= { _blackColor };
		const SBgra		yellowColor							= { rgba(255, 255, 0, 255) };
		const SBgra		redColor							= { rgba(255, 0, 0, 255) };
		const SBgra		greenColor							= { rgba(0, 255, 0, 255) };
		const SBgra		blueColor							= { rgba(0, 0, 255, 255) };
		const SBgra		cyanColor							= { rgba(0, 255, 255, 255) };
		const SBgra		orangeColor							= { rgba(255, 200, 64, 255) };
		const SBgra		fuchsiaColor						= { rgba(255, 255, 0, 255) };
		const SBgra		darkRedColor						= { rgba(80, 0, 0, 255) };
		const SBgra		darkOrangeColor						= { rgba(128, 64, 0, 255) };
		const SBgra		darkGreenColor						= { rgba(0, 80, 0, 255) };
		const SBgra		darkBlueColor						= { rgba(0, 0, 80, 255) };
		const SBgra		pastelYellowColor					= { rgba(255, 255, 192, 255) };
		const SBgra		pastelRedColor						= { rgba(255, 210, 210, 255) };
		const SBgra		pastelOrangeColor					= { rgba(255, 215, 164, 255) };
		const SBgra		pastelGreenColor					= { rgba(192, 255, 192, 255) };
		const SBgra		pastelBlueColor						= { rgba(210, 210, 255, 255) };
		const SBgra		maskColor							= { rgba(222, 22, 222, 255) };			// Hideous fuscia (by design)
		SBgra			tooltipNwBackColor					= { rgba(255, 254, 230, 255) };			// Pastel yellow
		SBgra			tooltipNeBackColor					= { rgba(252, 242, 192, 25) };			// Less pastel yellow, somewhat pale
		SBgra			tooltipSwBackColor					= { rgba(249, 222, 133, 255) };			// Orange/golden yellow
		SBgra			tooltipSeBackColor					= { rgba(247, 210, 96, 255) };			// More orange/golden yellow
		SBgra			tooltipForecolor					= { rgba(84, 56, 12, 255) };			// Dark chocolate brown
		SBgra			lineNumberFillColor					= { rgba(225, 245, 240, 255) };
		SBgra			lineNumberBackColor					= { rgba(215, 235, 230, 255) };
		SBgra			lineNumberForeColor					= { rgba(191, 208, 191, 255) };
		SBgra			breadcrumbBackColor					= { rgba(180, 220, 240, 255) };			// Cyanish
		SBgra			breadcrumbForeColor					= { rgba(0, 0, 164, 255) };				// Semidark blue
		SBgra			breakpointBackColor					= { rgba(180, 140, 220, 255) };			// Purplish
		SBgra			breakpointForeColor					= { rgba(64, 32, 92, 255) };			// Dark purple
		SBgra			currentStatementBackColor			= { rgba(225, 255, 192, 255) };			// Pastel lime greenish
		SBgra			currentStatementForeColor			= { rgba(0, 64, 0, 255) };				// Dark green
		SBgra			overrideMatchingBackColor			= { rgba(0, 255, 0, 255) };				// Green
		SBgra			overrideMatchingForeColor			= { rgba(0, 0, 0, 255) };				// Black
		SBgra			overrideMatchingBackColorMultiple	= { rgba(0, 255, 0, 255) };				// Green
		SBgra			overrideMatchingForeColorMultiple	= { rgba(0, 0, 0, 255) };				// Black
		SBgra			selectedBackColor					= { _selectedBackColor };				// Pastel turquoise
		SBgra			selectedForeColor					= { _selectedForeColor };				// Darkish blue
		SBgra			disabledBackColor					= { _disabledBackColor };
		SBgra			disabledForeColor					= { _disabledForeColor };
		SBgra			disabledItemBackColor				= { _disabledBackColor };
		SBgra			disabledItemForeColor				= { _disabledForeColor };
		SBgra			highlightSymbolBackColor			= { rgba(235, 220, 255, 255) };			// Very pastel purple
		SBgra			colorTracking						= { rgba(0, 0, 255, 255) };				// Blue
		f32				trackingRatio						= 0.025f;
		SBgra			colorMouseOver						= { rgba(255, 255, 0, 255) };			// Yellow
		SBgra			colorMouseDown						= { rgba(0, 255, 0, 255) };				// Green
		SBgra			editNewColor						= { rgba(64, 200, 64, 255) };			// Greenish
		SBgra			editChangedColor					= { rgba(255, 200, 64, 255) };			// Amberish


		// Forms four-corner window color schemes (eventually these will be loaded from themes.dbf)
// Orange theme:
		const SBgra		NwFocusColor						= { rgba(255, 218, 148, 255) };
		const SBgra		NeFocusColor						= { rgba(255, 208, 115, 255) };
		const SBgra		SwFocusColor						= { rgba(255, 208, 115, 255) };
		const SBgra		SeFocusColor						= { rgba(235, 198, 105, 255) };
// Purple theme
// 		const SBgra		NwFocusColor						= { rgba(233, 219, 255, 255) };
// 		const SBgra		NeFocusColor						= { rgba(205, 172, 255, 255) };
// 		const SBgra		SwFocusColor						= { rgba(233, 219, 255, 255) };
// 		const SBgra		SeFocusColor						= { rgba(182, 153, 226, 255) };

		// Subforms four-corner window color schemes (eventually these will be loaded from themes.dbf)
// Golden theme:
// 		SBgra			NwColor2							= { rgba(245, 225, 175, 255) };
// 		SBgra			NeColor2							= { rgba(252, 242, 192, 25) };			// Less pastel yellow, somewhat pale
// 		SBgra			SwColor2							= { rgba(249, 222, 133, 255) };			// Orange/golden yellow
// 		SBgra			SeColor2							= { rgba(247, 210, 96, 255) };			// More orange/golden yellow
// Blue theme:
		const SBgra		NwNonfocusColor						= { _nwColor };
		const SBgra		NeNonfocusColor						= { _neColor };
		const SBgra		SwNonfocusColor						= { _swColor };
		const SBgra		SeNonfocusColor						= { _seColor };
// Orange theme:
// 		const SBgra		NwColor2							= { rgba(255, 222, 156, 255) };
// 		const SBgra		NeColor2							= { rgba(255, 200, 92, 255) };
// 		const SBgra		SwColor2							= { rgba(255, 222, 156, 255) };
// 		const SBgra		SeColor2							= { rgba(229, 180, 83, 255) };

		// Colors for checkbox corners
		const SBgra		NwCheckboxOnColor					= { rgba(24, 153, 2, 255) };			// Green
		const SBgra		NeCheckboxOnColor					= { rgba(37, 163, 3, 255) };
		const SBgra		SwCheckboxOnColor					= { rgba(5, 140, 0, 255) };
		const SBgra		SeCheckboxOnColor					= { rgba(131, 220, 11, 255) };
		const SBgra		NwCheckboxOffColor					= { rgba(193, 34, 34, 255) };			// Red
		const SBgra		NeCheckboxOffColor					= { rgba(181, 64, 64, 255) };
		const SBgra		SwCheckboxOffColor					= { rgba(171, 92, 94, 255) };
		const SBgra		SeCheckboxOffColor					= { rgba(212, 128, 131, 255) };

		// Colors for the focus window
		SBgra			focusHighlightReadWriteColor		= { rgba(112, 164, 255, 255) };
		SBgra			focusHighlightReadOnlyColor			= { rgba(255, 112, 112, 255) };


	//////////
	// Mouse options
	//////
		bool			glIsMoving							= false;
		bool			glIsResizing						= false;
		bool			glIsMouseOverSplash					= false;

// 		SXYS32			gMousePositionMoveStart				= { -1, -1 };							// Mouse position when the move started
// 		SXYS32			gMousePositionMoveEnd				= { -1, -1 };							// Mouse position when the move ended
// 		SXYS32			gMousePositionResizeStart			= { -1, -1 };							// Mouse position when the resize started
// 		SXYS32			gMousePositionResizeEnd				= { -1, -1 };							// Mouse position when the resize ended
//
// 		SXYS32			gMousePosition						= { -1, -1 };							// Mouse position indicated by windows in the interface window
// 		bool			glMouseInClientArea					= false;								// When the mouse is in the client area, this flag is raised
// 		SXYS32			gMousePositionClientArea			= { -1, -1 };							// Mouse position in the client area of the interface window
// 		SXYS32			gnMouseDelta						= { 0, 0 };								// Change in position
// 		bool			glMouseLeftButton					= false;
// 		bool			glMouseMiddleButton					= false;
// 		bool			glMouseRightButton					= false;

