//////////
//
// /libsf/utils/common/cpp/linux/windows.cpp
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
// For HWND-to-X translation
//////
	// SHwndX listing
	SBuilder*		gsWindows				= NULL;




//////////
//
// Find the indicated window based on its hwnd
//
//////
	SHwndX* iWindows_findWindow_byHwnd(HWND hWnd)
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
// Called to create a window
//
//////
	WINUSERAPI HWND WINAPI CreateWindowEx(	__in DWORD dwExStyle,
											__in_opt cs8* lpClassName, __in_opt cs8* lpWindowName,
											__in DWORD dwStyle,
											__in int X, __in int Y, __in int nWidth, __in int nHeight,
											__in_opt HWND hWndParent, __in_opt HMENU hMenu, __in_opt HINSTANCE hInstance,
											__in_opt LPVOID lpParam)
	{
		union {
			uptr	_win;
			SHwndX* win;
		};
		
		
		// Make sure we have our gsWindows builder allocated
		if (!gsWindows)
			iBuilder_createAndInitialize(&gsWindows, -1);
		
		
		// Make sure our environment is sane
		if (lpClassName && nWidth > 0 && nHeight > 0)
		{
			// Allocate a new window
			win = (SHwndX*)iBuilder_appendData(gsWindows, NULL, sizeof(SHwndX));
			if (win)
			{
				//////////
				// Populate
				//////
					win->hwnd		= (uptr)_win;
					win->isValid	= true;
					win->isVisible	= false;
					win->isEnabled	= true;
					
					SetRect(&win->rc, X, Y, X + nWidth, Y + nHeight);
					CopyRect(&win->rcClient, &win->rc);
					iBuilder_createAndInitialize(&win->msgQueue, -1);

					iDatum_duplicate(&win->cClass, (cu8*)lpClassName,	strlen(lpClassName)		+ 1);
					iDatum_duplicate(&win->cTitle, (cu8*)lpWindowName,	strlen(lpWindowName)	+ 1);

					// Createstruct used for callback
					win->data.lpCreateParams	= lpParam;
					win->data.style				= dwStyle;
					win->data.dwExStyle			= dwExStyle;
					win->data.x					= X;
					win->data.y					= Y;
					win->data.cx				= nWidth;
					win->data.cy				= nHeight;
					win->data.hwndParent		= hWndParent;
					win->data.hMenu				= hMenu;
					win->data.hInstance			= hInstance;
					win->data.lpszClass			= win->cClass.data_cs8;
					win->data.lpszName			= win->cTitle.data_cs8;
				
				
				//////////
				// Ask HwndX to send out the CreateWindow() messages into the msgQueue
				//////
					iHwndX_createWindow(win);
				
				
				//////////
				// If it's initially visible, go ahead and show it
				//////
					if ((dwStyle & WS_VISIBLE) != 0)
						ShowWindow(win->hwnd, SW_SHOW);
			}
		}
		
		// If we get here, the window could not be created
		return(0);
	}




//////////
//
// Sets a callback timer for a window, or for an indicated function
//
//////
	WINUSERAPI UINT_PTR WINAPI SetTimer(__in_opt HWND hWnd, __in s32 nIDEvent, __in UINT uElapse, sptr lpTimerFunc)
	{
		SHwndX*		win;
		itimerval	itv;
		union {
			s32			_eventId;
			UINT_PTR	eventId;
		};
		
		
		// The timer is either for the window, or in general
		if (hWnd)
		{
			// They are applying the timer directly to the hWnd as a message in queue
			// Locate the window
			win = iWindows_findWindow_byHwnd(hWnd);
			if (win && win->isValid)
				if (iHwndX_addTimer(win, nIDEvent, uElapse))
				{
					_eventId = nIDEvent;
					return(eventId);
				}
			
			// If we get here, the window is not found, not valid, or the timer could not be added
		
		} else {
			// It is a general timer that goes to a specific function address
			debug_break;
			memset(&itv, 0, sizeof(itv));
			itv.it_interval.tv_usec	= uElapse;
// TODO:  Need to append an entry to our timer handler, and then dispatch as necessary
//			return(setitimer(ITIMER_REAL, &itv, NULL));
		}
		
		// If we get here, failure
		return(NULL);
	}




//////////
//
// Called to display a message box
//
//////
    const SDL_MessageBoxButtonData mb_buttons_ok[] =
	{
        { SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, 0, "ok" }
    };
	const int mb_buttons_ok_choice[] = { IDOK };
	
    const SDL_MessageBoxButtonData mb_buttons_ok_cancel[] =
	{
        { SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, 0, "ok" },
        { SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT, 1, "cancel" }
    };
	const int mb_buttons_ok_cancel_choice[] = { IDOK, IDCANCEL };

    const SDL_MessageBoxButtonData mb_buttons_yes_no_cancel[] =
	{
        { /* .flags, .buttonid, .text */        0, 0, "no" },
        { SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, 1, "yes" },
        { SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT, 2, "cancel" }
    };
	const int mb_buttons_yes_no_cancel_choice[] = { IDNO, IDYES, IDCANCEL };

    const SDL_MessageBoxButtonData mb_buttons_abort_retry_ignore[] =
	{
        { SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT, 0, "abort" },
        { SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, 1, "retry" },
        { /* .flags, .buttonid, .text */        0, 2, "ignore" }
    };
	const int mb_buttons_abort_retry_ignore_choice[] = { IDABORT, IDRETRY, IDIGNORE };
	
    const SDL_MessageBoxButtonData mb_buttons_yes_no[] =
	{
        { SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, 0, "yes" },
        { SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT, 1, "no" }
    };
	const int mb_buttons_yes_no_choice[] = { IDYES, IDNO };
	
    const SDL_MessageBoxButtonData mb_buttons_retry_cancel[] =
	{
        { SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, 0, "retry" },
        { SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT, 1, "cancel" }
    };
	const int mb_buttons_retry_cancel_choice[] = { IDRETRY, IDCANCEL };

    const SDL_MessageBoxButtonData mb_buttons_cancel_retry_continue[] =
	{
        { SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT, 0, "cancel" },
        { SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, 1, "retry" },
        { /* .flags, .buttonid, .text */        0, 2, "continue" }
    };
	const int mb_buttons_cancel_retry_continue_choice[] = { IDCANCEL, IDRETRY, IDCONTINUE };
	
    const SDL_MessageBoxColorScheme mb_colorScheme_information =
	{
        { /* .colors (.r, .g, .b) */
            { 255, 255, 255 },		// [SDL_MESSAGEBOX_COLOR_BACKGROUND]
            {   0,   0,   0 },		// [SDL_MESSAGEBOX_COLOR_TEXT]
            {   0,   0, 255 },		// [SDL_MESSAGEBOX_COLOR_BUTTON_BORDER]
            { 112, 164, 255 },		// [SDL_MESSAGEBOX_COLOR_BUTTON_BACKGROUND]
            { 255, 255, 128 }		// [SDL_MESSAGEBOX_COLOR_BUTTON_SELECTED]
        }
    };
	
    const SDL_MessageBoxColorScheme mb_colorScheme_warning =
	{
        { /* .colors (.r, .g, .b) */
            { 255, 255, 192 },		// [SDL_MESSAGEBOX_COLOR_BACKGROUND]
            {   0,   0,   0 },		// [SDL_MESSAGEBOX_COLOR_TEXT]
            {   0,   0, 255 },		// [SDL_MESSAGEBOX_COLOR_BUTTON_BORDER]
            { 112, 164, 255 },		// [SDL_MESSAGEBOX_COLOR_BUTTON_BACKGROUND]
            { 128, 255, 255 }		// [SDL_MESSAGEBOX_COLOR_BUTTON_SELECTED]
        }
    };
	
    const SDL_MessageBoxColorScheme mb_colorScheme_error =
	{
        { /* .colors (.r, .g, .b) */
            { 255, 128, 128 },		// [SDL_MESSAGEBOX_COLOR_BACKGROUND]
            {   0,   0,   0 },		// [SDL_MESSAGEBOX_COLOR_TEXT]
            {   0,   0, 255 },		// [SDL_MESSAGEBOX_COLOR_BUTTON_BORDER]
            { 112, 164, 255 },		// [SDL_MESSAGEBOX_COLOR_BUTTON_BACKGROUND]
            { 255, 255, 255 }		// [SDL_MESSAGEBOX_COLOR_BUTTON_SELECTED]
        }
    };

	WINUSERAPI int WINAPI MessageBox(__in_opt HWND hWnd, __in_opt cs8* lpText, __in_opt cs8* lpCaption, __in UINT uType)
	{
		int					lnChoice;
		const int*			buttonChoiceTranslation;
		SDL_MessageBoxData	messageboxdata;
		
		
		// Initialize
		memset(&messageboxdata, 0, sizeof(messageboxdata));
		messageboxdata.title		= lpCaption;
		messageboxdata.message		= lpText;
		
		
		//////////
		// Establish the expected values
		//////
			switch (uType)
			{
				default:
				case MB_OK:
					messageboxdata.buttons		= &mb_buttons_ok[0];
					messageboxdata.numbuttons	= 1;
					buttonChoiceTranslation		= &mb_buttons_ok_choice[0];
					break;
				case MB_OKCANCEL:
					messageboxdata.buttons		= &mb_buttons_ok_cancel[0];
					messageboxdata.numbuttons	= 2;
					buttonChoiceTranslation		= &mb_buttons_ok_cancel_choice[0];
					break;
				case MB_ABORTRETRYIGNORE:
					messageboxdata.buttons		= &mb_buttons_abort_retry_ignore[0];
					messageboxdata.numbuttons	= 3;
					buttonChoiceTranslation		= &mb_buttons_abort_retry_ignore_choice[0];
					break;
				case MB_YESNOCANCEL:
					messageboxdata.buttons		= &mb_buttons_yes_no_cancel[0];
					messageboxdata.numbuttons	= 3;
					buttonChoiceTranslation		= &mb_buttons_yes_no_cancel_choice[0];
					break;
				case MB_YESNO:
					messageboxdata.buttons		= &mb_buttons_yes_no[0];
					messageboxdata.numbuttons	= 2;
					buttonChoiceTranslation		= &mb_buttons_yes_no_choice[0];
					break;
				case MB_RETRYCANCEL:
					messageboxdata.buttons		= &mb_buttons_retry_cancel[0];
					messageboxdata.numbuttons	= 2;
					buttonChoiceTranslation		= &mb_buttons_retry_cancel_choice[0];
					break;
				case MB_CANCELTRYCONTINUE:
					messageboxdata.buttons		= &mb_buttons_cancel_retry_continue[0];
					messageboxdata.numbuttons	= 3;
					buttonChoiceTranslation		= &mb_buttons_cancel_retry_continue_choice[0];
					break;
			}
		
		
		//////////
		// Establish the message box type
		//////
			switch (uType & 0x70)
			{
				default:
					messageboxdata.flags		= SDL_MESSAGEBOX_INFORMATION;
					messageboxdata.colorScheme	= &mb_colorScheme_information;
					break;
				case MB_ICONWARNING:
					messageboxdata.flags		= SDL_MESSAGEBOX_WARNING;
					messageboxdata.colorScheme	= &mb_colorScheme_warning;
					break;
				case MB_ICONERROR:
					messageboxdata.flags		= SDL_MESSAGEBOX_ERROR;
					messageboxdata.colorScheme	= &mb_colorScheme_error;
					break;
			}

		
		//////////
		// Display the message box
		//////
			lnChoice = -2;	// Default to an error code
			if (SDL_ShowMessageBox(&messageboxdata, &lnChoice) < 0)
			{
				// Error
				return(lnChoice);
			}
		
		
		//////////
		// Indicate their choice
		//////
			return(buttonChoiceTranslation[lnChoice]);
	}




WINBASEAPI HANDLE WINAPI CreateThread(__in_opt LPSECURITY_ATTRIBUTES lpThreadAttributes, __in SIZE_T dwStackSize, __in LPTHREAD_START_ROUTINE lpStartAddress, __in_opt __deref __drv_aliasesMem LPVOID lpParameter, __in DWORD dwCreationFlags, __out_opt LPDWORD lpThreadId)
{
	return(0);
}




WINBASEAPI VOID WINAPI ExitThread(__in DWORD dwExitCode)
{
}




WINUSERAPI BOOL WINAPI GetClassInfoExA(__in_opt HINSTANCE hInstance, __in cs8* lpszClass, __out WNDCLASSEXA* lpwcx)
{
	return(FALSE);
}




WINUSERAPI ATOM WINAPI RegisterClassExA(__in CONST WNDCLASSEXA* lpwcx)
{
	return(0);
}




WINUSERAPI BOOL WINAPI GetMessage(__out LPMSG lpMsg, __in_opt HWND hWnd, __in UINT wMsgFilterMin, __in UINT wMsgFilterMax)
{
	return(FALSE);
}




WINUSERAPI BOOL WINAPI TranslateMessage(__in CONST MSG *lpMsg)
{
	return(FALSE);
}




WINUSERAPI LRESULT WINAPI DispatchMessage(__in CONST MSG *lpMsg)
{
	return(0);
}




WINUSERAPI BOOL WINAPI PeekMessage(__out LPMSG lpMsg, __in_opt HWND hWnd, __in UINT wMsgFilterMin, __in UINT wMsgFilterMax, __in UINT wRemoveMsg)
{
	return(FALSE);
}




LRESULT CALLBACK DefWindowProc(__in HWND hWnd, __in UINT Msg, __in WPARAM wParam, __in LPARAM lParam)
{
	return(0);
}




WINUSERAPI BOOL WINAPI PostMessage(__in_opt HWND hWnd, __in UINT Msg, __in WPARAM wParam, __in LPARAM lParam)
{
	return(FALSE);
}




WINUSERAPI HWND WINAPI GetDesktopWindow(VOID)
{
	return(0);
}




//////////
//
// Called to obtain the client rectangle for the specified window
//
//////
	WINUSERAPI BOOL WINAPI GetClientRect(__in HWND hWnd, __out LPRECT lpRect)
	{
		SHwndX* win;
		
		
		// Locate the window
		win = iWindows_findWindow_byHwnd(hWnd);
		
		// Is it valid?
		if (win && win->isValid)
		{
			// Yes, indicate success
			CopyRect(lpRect, &win->rcClient);
			return(TRUE);
		}
		
		// If we get here, failure
		return(FALSE);
	}




//////////
//
// Called to obtain the window rectangle for the specified window
//
//////
	WINUSERAPI BOOL WINAPI GetWindowRect(__in HWND hWnd, __out LPRECT lpRect)
	{
		SHwndX* win;
		
		
		// Locate the window
		win = iWindows_findWindow_byHwnd(hWnd);
		
		// Is it valid?
		if (win && win->isValid)
		{
			// Yes, indicate success
			CopyRect(lpRect, &win->rc);
			return(TRUE);
		}
		
		// If we get here, failure
		return(FALSE);
	}




//////////
//
// Defines a Windows rectangle
//
//////
	WINUSERAPI BOOL WINAPI SetRect(__out LPRECT lprc, __in int xLeft, __in int yTop, __in int xRight, __in int yBottom)
	{
		// Make sure our environment is sane
		if (lprc)
		{
			// Set the coordinates
			lprc->left		= xLeft;
			lprc->top		= yTop;
			lprc->right		= xRight;
			lprc->bottom	= yBottom;
			
			// If we get here, success
			return(TRUE);
		}
		// If we get here, failure
		return(FALSE);
	}




WINGDIAPI HGDIOBJ WINAPI SelectObject(__in HDC hdc, __in HGDIOBJ h)
{
	return(0);
}




WINGDIAPI COLORREF WINAPI SetTextColor(__in HDC hdc, __in COLORREF color)
{
	return(0);
}




WINGDIAPI int WINAPI SetBkMode(__in HDC hdc, __in int mode)
{
	return(0);
}




WINUSERAPI int WINAPI DrawText(__in HDC hdc, cs8* lpchText, __in int cchText, __inout LPRECT lprc, __in UINT format)
{
	return(0);
}




WINBASEAPI DWORD WINAPI GetTickCount(VOID)
{
	return(0);
}




WINBASEAPI VOID WINAPI InitializeCriticalSection(__out LPCRITICAL_SECTION lpCriticalSection)
{
}




WINBASEAPI VOID WINAPI EnterCriticalSection(__inout LPCRITICAL_SECTION lpCriticalSection)
{
}




WINBASEAPI BOOL WINAPI TryEnterCriticalSection(__inout LPCRITICAL_SECTION lpCriticalSection)
{
	return(FALSE);
}




WINBASEAPI VOID WINAPI LeaveCriticalSection(__inout LPCRITICAL_SECTION lpCriticalSection)
{
}




WINBASEAPI VOID WINAPI DeleteCriticalSection(__inout LPCRITICAL_SECTION lpCriticalSection)
{
}




WINUSERAPI VOID WINAPI PostQuitMessage(__in int nExitCode)
{
}




WINUSERAPI HCURSOR WINAPI LoadCursor(__in_opt HINSTANCE hInstance, __in uptr lpCursorName)
{
	return(0);
}




WINBASEAPI HMODULE WINAPI GetModuleHandle(__in_opt cs8* lpModuleName)
{
	return(0);
}




WINUSERAPI int WINAPI SetWindowRgn(__in HWND hWnd, __in_opt HRGN hRgn, __in BOOL bRedraw)
{
	return(0);
}




WINUSERAPI BOOL WINAPI KillTimer(__in_opt HWND hWnd,__in s64 uIDEvent)
{
	return(FALSE);
}




WINGDIAPI BOOL WINAPI DeleteDC( __in HDC hdc)
{
	return(FALSE);
}




WINGDIAPI BOOL WINAPI DeleteObject( __in HGDIOBJ ho)
{
	return(FALSE);
}




WINUSERAPI BOOL WINAPI DestroyWindow(__in HWND hWnd)
{
	return(FALSE);
}




WINUSERAPI BOOL WINAPI ShowWindow(__in HWND hWnd, __in int nCmdShow)
{
	return(FALSE);
}




WINBASEAPI VOID WINAPI Sleep(__in DWORD dwMilliseconds)
{
}




WINUSERAPI BOOL WINAPI SetWindowPos(__in HWND hWnd, __in_opt HWND hWndInsertAfter, __in int X, __in int Y, __in int cx, __in int cy, __in UINT uFlags)
{
	return(FALSE);
}




WINUSERAPI BOOL WINAPI GetCursorPos(__out LPPOINT lpPoint)
{
	return(FALSE);
}




WINGDIAPI HRGN WINAPI CreateRectRgn(__in int x1, __in int y1, __in int x2, __in int y2)
{
	return(0);
}




WINUSERAPI int WINAPI GetWindowRgn(__in HWND hWnd, __in HRGN hRgn)
{
	return(0);
}




WINGDIAPI BOOL WINAPI PtInRegion(__in HRGN hrgn, __in int x, __in int y)
{
	return(FALSE);
}




WINUSERAPI HDC WINAPI BeginPaint(__in HWND hWnd, __out LPPAINTSTRUCT lpPaint)
{
	return(0);
}




WINUSERAPI BOOL WINAPI EndPaint(__in HWND hWnd, __in CONST PAINTSTRUCT *lpPaint)
{
	return(FALSE);
}




WINGDIAPI BOOL WINAPI BitBlt( __in HDC hdc, __in int x, __in int y, __in int cx, __in int cy, __in_opt HDC hdcSrc, __in int x1, __in int y1, __in DWORD rop)
{
	return(FALSE);
}




WINUSERAPI HICON WINAPI LoadIcon(__in_opt HINSTANCE hInstance, __in uptr lpIconName)
{
	return(0);
}




//////////
//
// Copies one rectangel to another
//
//////
	WINUSERAPI BOOL WINAPI CopyRect(__out RECT* lprcDst, __in CONST RECT *lprcSrc)
	{
		// Make sure our environment is sane
		if (lprcDst && lprcSrc)
		{
			// 
			memcpy(lprcDst, lprcSrc, sizeof(RECT));
			return(TRUE);
		}
		
		// If we get here, failure
		return(FALSE);
	}




//////////
//
// Makes a Windows rect bigger or smaller
//
//////
	WINUSERAPI BOOL WINAPI InflateRect(__inout RECT* lprc, __in int dx, __in int dy)
	{
		// Make sure our environment is sane
		if (lprc)
		{
			// Adjust horizontally
			lprc->left		-= dx;
			lprc->right		+= dx;
			
			// Adjust vertically
			lprc->top		-= dy;
			lprc->bottom	+= dy;
			
			// If we get here, success
			return(TRUE);
		}
		
		// If we get here, failure
		return(FALSE);
	}




WINUSERAPI LONG WINAPI GetWindowLongA(__in HWND hWnd, __in int nIndex)
{
	return(0);
}




WINUSERAPI LONG WINAPI SetWindowLongA(__in HWND hWnd, __in int nIndex,__in LONG dwNewLong)
{
	return(0);
}




WINUSERAPI BOOL WINAPI InvalidateRect(__in_opt HWND hWnd, __in_opt CONST RECT *lpRect, __in BOOL bErase)
{
	return(FALSE);
}




WINUSERAPI HMENU WINAPI GetMenu(__in HWND hWnd)
{
	return(0);
}




WINUSERAPI BOOL WINAPI SetMenu(__in HWND hWnd, __in_opt HMENU hMenu)
{
	return(FALSE);
}




WINGDIAPI HRGN WINAPI CreateRectRgnIndirect( __in CONST RECT *lprect)
{
	return(0);
}




WINUSERAPI BOOL WINAPI PtInRect(__in CONST RECT *lprc, __in POINT pt)
{
	return(FALSE);
}




WINUSERAPI SHORT WINAPI GetAsyncKeyState(__in int vKey)
{
	return(0);
}




WINUSERAPI SHORT WINAPI GetKeyState(__in int nVirtKey)
{
	return(0);
}




WINUSERAPI BOOL WINAPI AdjustWindowRect(__inout LPRECT lpRect, __in DWORD dwStyle, __in BOOL bMenu)
{
	return(FALSE);
}




WINUSERAPI BOOL WINAPI GetKeyboardState(BYTE lpKeyState[256])
{
	return(FALSE);
}




WINUSERAPI int WINAPI ToAscii(__in UINT uVirtKey, __in UINT uScanCode, CONST BYTE lpKeyState[256], __out LPWORD lpChar, __in UINT uFlags)
{
	return(0);
}




WINGDIAPI int WINAPI CombineRgn(__in_opt HRGN hrgnDst, __in_opt HRGN hrgnSrc1, __in_opt HRGN hrgnSrc2, __in int iMode)
{
	return(0);
}




WINGDIAPI HBRUSH WINAPI CreateSolidBrush(__in COLORREF color)
{
	return(0);
}




WINUSERAPI int WINAPI FillRect(__in HDC hDC, __in CONST RECT *lprc, __in HBRUSH hbr)
{
	return(0);
}




WINUSERAPI int WINAPI FrameRect(__in HDC hDC, __in CONST RECT *lprc,__in HBRUSH hbr)
{
	return(0);
}




WINBASEAPI VOID WINAPI GetSystemTime(__out LPSYSTEMTIME lpSystemTime)
{
}




WINBASEAPI VOID WINAPI GetSystemTimeAsFileTime(__out LPFILETIME lpSystemTimeAsFileTime)
{
}




WINBASEAPI BOOL WINAPI SetSystemTime(__in CONST SYSTEMTIME *lpSystemTime)
{
	return(FALSE);
}




WINBASEAPI VOID WINAPI GetLocalTime(__out LPSYSTEMTIME lpSystemTime)
{
}




WINBASEAPI BOOL WINAPI SetLocalTime(__in CONST SYSTEMTIME *lpSystemTime)
{
	return(FALSE);
}




WINUSERAPI HWND WINAPI GetActiveWindow(VOID)
{
	return(0);
}




WINGDIAPI COLORREF WINAPI SetBkColor(__in HDC hdc, __in COLORREF color)
{
	return(0);
}




WINUSERAPI HDC WINAPI GetDC(__in_opt HWND hWnd)
{
	return(0);
}




WINGDIAPI HDC WINAPI CreateCompatibleDC( __in_opt HDC hdc)
{
	return(0);
}




WINGDIAPI HBITMAP WINAPI CreateDIBSection(__in_opt HDC hdc, __in CONST BITMAPINFO* lpbmi, __in UINT usage, VOID **ppvBits, __in_opt HANDLE hSection, __in DWORD offset)
{
	return(0);
}




s64 _atoi64(cs8* string)
{
	return(0);
}




WINUSERAPI int WINAPI GetSystemMetrics(__in int nIndex)
{
	return(0);
}




WINUSERAPI BOOL WINAPI OffsetRect(__inout LPRECT lprc, __in int dx, __in int dy)
{
	return(FALSE);
}




WINBASEAPI DWORD WINAPI GetCurrentDirectory(__in DWORD nBufferLength, s8 lpBuffer[_MAX_PATH])
{
	return(0);
}




int sopen(cs8* tcPathname, s32 mode, s32 sharing)
{
	return(0);
}




s64 telli64(s32 fileno)
{
	return(0);
}




WINBASEAPI HANDLE WINAPI FindFirstFile(__in cs8* lpFileName, __out LPWIN32_FIND_DATA lpFindFileData)
{
	return(0);
}




WINBASEAPI BOOL WINAPI FindNextFile(__in HANDLE hFindFile, __out LPWIN32_FIND_DATA lpFindFileData)
{
	return(FALSE);
}




WINBASEAPI DWORD WINAPI GetFullPathName(__in cs8* lpFileName, __in DWORD nBufferLength, s8 lpBuffer[_MAX_PATH], s8** lpFilePart)
{
	return(0);
}




WINBASEAPI DWORD WINAPI GetTempPath(__in DWORD nBufferLength, s8 lpBuffer[_MAX_PATH])
{
	return(0);
}




WINBASEAPI UINT WINAPI GetTempFileName(__in cs8* lpPathName, __in cs8* lpPrefixString, __in UINT uUnique, s8 lpTempFileName[_MAX_PATH])
{
	return(0);
}




WINGDIAPI int WINAPI GetDeviceCaps(__in_opt HDC hdc, __in int index)
{
	return(0);
}




WINBASEAPI int WINAPI MulDiv(__in int nNumber, __in int nNumerator, __in int nDenominator)
{
	return(0);
}




WINGDIAPI HFONT WINAPI CreateFont(	__in int cHeight, __in int cWidth, __in int cEscapement, __in int cOrientation, __in int cWeight, __in DWORD bItalic,
									__in DWORD bUnderline, __in DWORD bStrikeOut, __in DWORD iCharSet, __in DWORD iOutPrecision, __in DWORD iClipPrecision,
									__in DWORD iQuality, __in DWORD iPitchAndFamily, __in_opt cs8* pszFaceName)
{
	return(0);
}




WINGDIAPI BOOL WINAPI GetTextMetricsA(__in HDC hdc, __out LPTEXTMETRIC lptm)
{
	return(FALSE);
}
