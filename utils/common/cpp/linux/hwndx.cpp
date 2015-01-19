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
// Called when a new window is created to schedule the startup messages
//
//////
	void iHwndX_createWindow(SHwndX* win)
	{
		// Schedule the messages for new window creation
// TOOD:  Determine which messages from Windows are sent in which order, and replicate here
//		iHwndX_postMessage_byWin(win, WM_CREATE, 0, 0);
	}




//////////
//
// Called to add a new timer to a window
//
//////
	bool iHwndX_addTimer(SHwndX* win, s32 nIDEvent, UINT uElapse)
	{
		return(false);
	}
