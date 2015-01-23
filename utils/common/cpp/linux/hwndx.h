//////////
//
// /libsf/utils/common/cpp/linux/hwndx.h
//
//////
// Version 0.55
// Copyright (c) 2015 by Rick C. Hodgin
//////
// Last update:
//     Jan.17.2014
//////
// Change log:
//     Jan.17.2014 - Initial creation
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




#include "/libsf/utils/common/cpp/builder.h"
#include "/libsf/utils/common/cpp/datum.h"




#define _X11_OK					0
#define _X11_NO_DISPLAY			-1
#define _X11_UNSUPPORTED		-2
#define _X11_NO_WINDOW			-3
#define _X11_NO_VIRTUAL_SCREEN	-4
#define _X11_NO_PIXEL_BUFFER	-5
#define _X11_GENERAL_FAILURE	-99

struct SHdcX;




//////////
// Windows Hwnd -to- X-Windows translation
//////
	struct SXWindow
	{
		Display*		display;
		Window			window;
		Screen*			screenptr;
		s32				screennum;
		Visual*			visual;
		GC				gc;
		
		XImage*			ximage;
		SBgra*			virtualscreen;
		
		XImage*			ximage2;
		SBgra*			virtualscreen2;

		s32				width;
		s32				height;
		s32				depth;
		s32				pixelsize;
		s32				screensize;
	};


	struct SClassX
	{
		bool			isValid;
		WNDCLASSEX		wcx;
		SDatum			cClass;
	};

	struct SHwndX
	{
		// For Windows
		uptr			hwnd;
		bool			isValid;
		bool			isVisible;
		bool			isEnabled;
		pthread_t		nThreadId;
		RECT			rc;
		RECT			rcClient;
		SBuilder*		msgQueue;
		
		// Note:  Both of these contain the trailing NULL in their length ... this is done because some callbacks require ASCIIZ strings
		SDatum			cClass;
		SDatum			cTitle;
		
		// Current mouse and keyboard flags
		uptr			mouseKbdFlags;
		POINT			mousePt;

		// Structure used for callbacks
		CREATESTRUCT	data;
		SClassX*		cls;
		SHdcX*			hdc;
		
		// For X-windows
		SXWindow		x11;
	};
	
	struct SMessageX
	{
		MSG				msg;
	};
	
	struct STimerX
	{
		bool		isValid;
		SHwndX*		winAssociated;
		
		// From setitimer()
		s32			timerId;
	};
	
	struct SFontX
	{
		bool		isValid;
		Font		xfont;
	}
	
	struct SHdcX
	{
		bool		isValid;
		HDC			hdc;
		
		// Current settings for the device context
		SFontX*		font;
		bool		isOpaque;
		SBgra		colorFore;
		SBgra		colorBack;
		
		// Bitmaps take on the size of the thing they belong to, so they may be constantly resized
		SBitmap*	bmp;
	};

	struct SDesktopX
	{
		Display*	display;
		s32			screen;
		s32			depth;
		s32			connection;
		Window		windowDesktop;
	};


//////////
// Global variables
//////
	SBuilder*		gsWindows								= NULL;
	SBuilder*		gsClasses								= NULL;
	SBuilder*		gsHdcs									= NULL;
	
	// "Desktop" window related
	SHwndX*			gsDesktopWindow							= iHwndX_declareDesktopHwnd();
	SDesktopX		gsDesktop;
	HWND			ghWndDesktop							= NULL;




//////////
// Prototype definitions
//////
	bool			iHwndX_postMessage_byWin				(SHwndX* win,	uptr message, uptr wParam, uptr lParam);
	bool			iHwndX_postMessage_byHwnd				(HWND hWnd,		uptr message, uptr wParam, uptr lParam);
	SHwndX*			iHwndX_declareDesktopHwnd				(void);
	DWORD			iHwndX_getTime							(void);
	SHwndX*			iHwndX_findWindow_byHwnd				(HWND hWnd);
	SHdcX*			iHwndX_findHdc_byHdc					(HDC hdc);
	SClassX*		iHwndX_findClass_byName					(s8* lpClassName);
	void			iHwndX_createWindow						(SHwndX* win);
	SXWindow*		iHwndX_createXWindow					(SHwndX* win);
	s32				iHwndX_initializeXWindow				(SXWindow* win, s32 width, s32 height, s8* title);
	bool			iHwndX_addTimer							(SHwndX* win, s32 nIDEvent, UINT uElapse);
