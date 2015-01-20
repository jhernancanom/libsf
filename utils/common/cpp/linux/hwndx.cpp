//////////
//
// /libsf/utils/common/cpp/linux/hwndx.cpp
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




//////////
//
// Posts a message to the indicated win->msgQueue.
//
//////
	bool iHwndX_postMessage_byWin(SHwndX* win, uptr message, uptr wParam, uptr lParam)
	{
		SMessageX* msg;
		
		
		// Make sure our environment is sane
		if (win && win->isValid)
		{
			//////////
			// Make sure there's a message queue
			//////
				if (!win->msgQueue)
					iBuilder_createAndInitialize(&win->msgQueue, -1);
			
			
			//////////
			// Append the message
			//////
				msg = (SMessageX*)iBuilder_appendData(win->msgQueue, sizeof(SMessageX));
				if (msg)
				{
					msg->msg.hwnd		= win->hwnd;
					msg->msg.message	= message;
					msg->msg.wParam		= wParam;
					msg->msg.lParam		= lParam;
					msg->msg.time		= iHwnd_getTime();
					memcpy(&msg->msg.pt, win->pt, sizeof(msg->msg.pt));
					
					// Indicate success
					return(true);
				}
		}
		
		// If we get here, failure
		return(false);
	}




//////////
//
// Posts a message to the win->msgQueue derived by the hWnd.
//
//////
	bool iHwndX_postMessage_byHwnd(HWND hWnd, uptr message, uptr wParam, uptr lParam)
	{
		SHwndX* win;
		
		
		// Try to find the window
		win = iHwndX_findWindow_byHwnd(hWnd);
		if (win)
			return(iHwndX_postMessage_byWin(win, message, wParam, lParam));
		
		// If we get here, not found
		return(false);
	}




//////////
//
// Called at startup one time to declare the initial desktop window as a pseudo-window
// which is 
//
//////
	SHwndX* iHwndX_declareDesktopHwnd(void)
	{
		s32			lnWidth, lnHeight;
		WNDCLASSEX	wcx;


		//////////
		// Allocate our primary SHwndX buffer if need be
		//////
			if (!gsWindows)
				iBuilder_createAndInitialize(&gsWindows, -1);
		
		
		//////////
		// Connect to X11
		//////
			gsDesktop.display		= XOpenDisplay(NULL);
			gsDesktop.screen		= DefaultScreen(gsDesktop.display);
			gsDesktop.depth			= DefaultDepth(gsDesktop.display, gsDesktop.screen);
			gsDesktop.connection	= ConnectionNumber(gsDesktop.display);
			gsDesktop.rootwindow	= RootWindow(gsDesktop.display, gsDesktop.screen);

		
		//////////
		// Register our logical desktop class
		//////
			memset(&wcx, 0, sizeof(wcx));
			wcx.cbSize			= sizeof(wcx);
			wcx.style			= CS_OWNDC;
			wcx._lpfnWndProc	= &DefWindowProc;
			wcx.lpszClassName	= cgcDesktop;
			wcx.lpszMenuName	= cgcDesktop;
			RegisterClassEx(&wcx);
		
		
		//////////
		// Create our logical desktop window
		//////
			lnWidth			= XDisplayWidth(gsDesktop.display, gsDesktop.screen);
			lnHeight		= XDisplayHeight(gsDesktop.display, gsDesktop.screen);
			ghWndDesktop	= CreateWindowEx(	0, cgcDesktop, cgcDesktop, WS_POPUP,
												0, 0, lnWidth, lnHeight,
												null0, null0, null0, null0);
		
		
		//////////
		// Return the logical desktop pointer
		//////
			return(iHwndX_findWindow_byHwnd(ghWndDesktop));
	}




//////////
//
// Obtain the current time in milliseconds since startup, or rollover if up for a long, long time.
//
//////
	DWORD iHwndX_getTime(void)
	{
		timespec tp;
		
		
		//////////
		// Grab the time
		//////
			clock_gettime(CLOCK_MONOTONIC, &tp);
		
		
		//////////
		// Convert to milliseconds
		//////
			tp.tv_nsec	/= 1000000;						// Divide nanoseconds by 1 million to get milliseconds
			tp.tv_nsec	+= ((s32)tp.tv_sec * 1000);		// Add (1000*sec) to milliseconds
		
		
		//////////
		// Return our result
		//////
			return((DWORD)tp.tv_nsec);		// (1000*sec) + milliseconds
	}




//////////
//
// Find the indicated window based on its hwnd
//
//////
	SHwndX* iHwndX_findWindow_byHwnd(HWND hWnd)
	{
		u32		lnI;
		SHwndX*	win;
		
		
		// Make sure our environment is sane
		if (gsWindows)
		{
			// Iterate through each window until we find the correct one
			for (lnI = 0, win = (SHwndX*)gsWindows->buffer; lnI < gsWindows->populatedLength; lnI += sizeof(SHwndX), win++)
			{
				// Is this our window?
				if (win->isValid && win->hwnd == hWnd)
					return(win);
			}
			// If we get here, not found
		}
		// If we get here, failure
		return(NULL);
	}




//////////
//
// Find the indicated class based on its name
//
//////
	SClassX* iHwnd_findClass_byName(s8* lpClassName)
	{
		u32			lnI, lnLength;
		SClassX*	cls;
		
		
		// Make sure our environment is sane
		if (lpClassName)
		{
			// Iterate through each class until we find the correct one
			lnLength = strlen(lpszClass);
			for (lnI = 0, cls = (SClassX*)gsClasses->buffer; lnI < gsClasses->populatedLength; lnI += sizeof(SClassX), cls++)
			{
				// If it's valid, and the class maches, we're good
				if (cls->isValid && strlen(cls->wcx.lpszClassName) == lnLength && _memicmp(cls->wcx.lpszClassName, lpszClass, lnLength) == 0)
					return(cls);
			}
			// If we get here, the class was not found
		}
		
		// If we get here, invalid
		return(NULL);
	}




//////////
//
// Called when a new logical Windows window is created to create the associated X-window,
// and also to logically schedule the Windows startup messages
//
//////
	void iHwndX_createWindow(SHwndX* win)
	{
		if (!win->x11)
			win->x11 = iHwndX_createXWindow(win);
	}




//////////
//
// Called to populate the X11 window portion
//
//////
	SXWindow* iHwndX_createXWindow(SHwndX* win)
	{
		XWindow* xwin;
		
		
		// Make sure our environment is sane
		if (win)
		{
			// Allocate the structure
			xwin = (SXWindow*)malloc(sizeof(SXWindow));
			if (xwin)
			{
				// Initialize
				memset(xwin, 0, sizeof(*xwin));
				
				// Initialize X for this window
				if (iHwndX_initializeXWindow(xwin, win->rc.right - win->rc.left, win->rc.bottom - win->rc.top, win->cTitle.data_s8) == ERR_XI_OK)
					return(xwin);
				
				// If we get here, failure
				free(xwin);
			}
		}
		
		// If we get here, invalid
		return(NULL);
	}




//////////
//
// Called to physically create the X11 window which will be drawn on the desktop.
//
//////
	s32 iHwndX_initializeXWindow(SXWindow* xwin, s32 width, s32 height, s8* title)
	{
		XSizeHints Hints;
		
		if (xwin)
		{
			//////////
			// Allocate a display
			//////
				xwin->display = XOpenDisplay(NULL);
				if (!xwin->display)
					return _X11_NO_DISPLAY;
			
			
			//////////
			// Populate our local settings
			//////
				xwin->width		= width;
				xwin->height		= height;
				xwin->screennum	= DefaultScreen(xwin->display);
				xwin->screenptr	= DefaultScreenOfDisplay(xwin->display);
				xwin->visual		= DefaultVisualOfScreen(xwin->screenptr);
				xwin->depth		= DefaultDepth(xwin->display, xwin->screennum);
				xwin->pixelsize	= 4;


			//////////
			// Make sure we have a compatible display
			//////
				if (xwin->depth != 24)
					return _X11_UNSUPPORTED;


			//////////
			// Physically create the window on the desktop
			//////
				xwin->window	= XCreateWindow(xwin->display,
											RootWindowOfScreen(xwin->screenptr),
											0, 0, xwin->width, xwin->height,
											0, xwin->depth,
											InputOutput,
											xwin->visual, 0, NULL);
				
				// Are we valid?
				if (!xwin->window)
					return _X11_NO_WINDOW;
				
				// Raise it to the top
				XMapRaised(xwin->display, xwin->window);


			//////////
			// Provide hints because we do our own resizing internally
			//////
				Hints.flags			= PSize | PMinSize | PMaxSize;
				Hints.min_width		= Hints.max_width	= Hints.base_width	= width;
				Hints.min_height	= Hints.max_height	= Hints.base_height	= height;
				XSetWMNormalHints(XWnd->display, XWnd->window,&Hints);


			//////////
			// Set window title and specify those events we would like to receive
			//////
				XStoreName(xwin->display, xwin->window, title);
				XSelectInput(xwin->display, xwin->window, 		ExposureMask
															|	KeyPressMask
															|	KeyReleaseMask
															|	ButtonPressMask
															|	EnterWindowMask
															|	LeaveWindowMask
															|	PointerMotionMask
															|	FocusChangeMask);
			
			//////////
			// Graphical context
			//////
				xwin->gc = XCreateGC(xwin->display, xwin->window, 0, NULL);


			//////////
			// Primray pixel buffer
			//////
				xwin->screensize		= xwin->height * xwin->width * xwin->pixelsize;
				xwin->virtualscreen	= (SBgra*)malloc(xwin->screensize);
				if (!xwin->virtualscreen)
					return _X11_NO_VIRTUAL_SCREEN;
			
				// Logical image
				xwin->ximage = XCreateImage(xwin->display, xwin->visual, xwin->depth,
											ZPixmap, 0, 
											(s8*)xwin->virtualscreen,
											xwin->width, xwin->height,
											(xwin->pixelsize * 8),
											xwin->width * xwin->pixelsize);
				
				// Did we get the buffer?
				if (!xwin->ximage)
					return _X11_NO_PIXEL_BUFFER;


			//////////
			// Pixel buffer 2
			//////
				xwin->screensize2	= xwin->height * xwin->width * xwin->pixelsize;
				xwin->virtualscreen2	= (SBgra*)malloc(xwin->screensize2);
				if (!xwin->virtualscreen2)
					return _X11_VIRTALLOC;
				
				// Logical image
				xwin->ximage2 = XCreateImage(xwin->display, xwin->visual, xwin->depth,
											ZPixmap, 0, 
											(s8*)xwin->virtualscreen2,
											xwin->width, xwin->height,
											(xwin->pixelsize * 8),
											xwin->width * xwin->pixelsize);
				// Did we get the buffer?
				if (!xwin->ximage2)
					return _X11_NO_PIXEL_BUFFER;


			//////////
			// We're good
			//////
				return _X11_OK;
		}
		
		// If we get here, invalid
		return _X11_GENERAL_FAILURE;
	}




//////////
//
// Called to add a new timer to a window
//
//////
	bool iHwndX_addTimer(SHwndX* win, s32 nIDEvent, UINT uElapse)
	{
		itimerval itv, itvold;
		
		
		// Determine the interval
		itv.it_interval.tv_sec		= (u32)uElapse / 1000;
		itv.it_interval.tv_usec		= (u32)uElapse % 1000;
		
		// Create the timer
		setitimer(ITIMER_REAL, &itv, &itvold);
	}
