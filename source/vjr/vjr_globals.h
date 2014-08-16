//////////
//
// /libsf/source/vjr/vjr_globals.h
//
//////
// Version 0.51
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




//////////
// Global Variables
//////
	HINSTANCE			ghInstance							= NULL;
	bool				glShuttingDown						= false;
//	ITaskbarList*		giTaskbar							= NULL;

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

	HWND				ghwndMsg							= NULL;
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

	// Focus highlight windows, and tooltip window
	SBuilder*			gFocusHighlights					= NULL;									// Holds SFocusHighlight structures
	SSplash				gSplash;																	// For the active splash screen

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
	SBitmap*			bmpCarouselIcon						= NULL;
	SBitmap*			bmpTabsIcon							= NULL;
	SBitmap*			bmpCarouselPad						= NULL;

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
	SObject*			sourceCode_editbox					= NULL;
	SObject*			locals_editbox						= NULL;
// 	SObject*			locals_autos						= NULL;
// 	SObject*			locals_globals						= NULL;
// 	SObject*			locals_readwrite					= NULL;
// 	SObject*			locals_refactor						= NULL;
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
		const SBgra		whiteColor							= { rgba(255, 255, 255, 255) };
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
		const SBgra		blackColor							= { rgba(0, 0, 0, 255) };
		const SBgra		grayColor							= { rgba(192, 192, 192, 255) };
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
		SBgra			selectedBackColor					= { rgba(200, 225, 255, 255) };
		SBgra			selectedForeColor					= { rgba(0, 0, 192, 255) };
		SBgra			disabledBackColor					= { rgba(255, 255, 255, 255) };
		SBgra			disabledForeColor					= { rgba(192, 192, 230, 255) };
		SBgra			highlightSymbolBackColor			= { rgba(235, 220, 255, 255) };			// Very pastel purple
		SBgra			colorTracking						= { rgba(0, 0, 255, 255) };				// Blue
		f32				trackingRatio						= 0.025f;
		SBgra			colorMouseOver						= { rgba(255, 255, 0, 255) };			// Yellow
		SBgra			colorMouseDown						= { rgba(0, 255, 0, 255) };				// Green

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
		const SBgra		NwNonfocusColor						= { rgba(230, 230, 255, 255) };
		const SBgra		NeNonfocusColor						= { rgba(192, 212, 255, 255) };
		const SBgra		SwNonfocusColor						= { rgba(212, 212, 255, 255) };
		const SBgra		SeNonfocusColor						= { rgba(172, 192, 235, 255) };
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

