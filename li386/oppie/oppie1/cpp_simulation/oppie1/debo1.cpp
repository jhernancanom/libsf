//////////
//
// /libsf/li386/oppie/oppie1/cpp_simulation/debo1.cpp
//
//////
// Version 0.01
// Copyright (c) 2014 by Rick C. Hodgin
//////
// Last update:
//     Nov.26.2014
//////
// Change log:
//     Nov.26.2014 - Initial creation
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
//////
//
//




//////////
// Global variables
//////
	const s8		cgcDebo1Class[]								= "debo1_oppie1_debugger_window";
	const s8		cgcDebo1Title[]								= "Oppie-1 Debugger v0.01";
	bool			glDebo1_executionIsPaused					= false;
	bool			glDebo1_executionIsSingleStepping			= false;


//////////
// Forward declarations
//////
	DWORD WINAPI			iDebo1_threadProc					(LPVOID lpParameter);
	LRESULT CALLBACK		iDebo1_wndProc						(HWND h, UINT m, WPARAM w, LPARAM l);


//////////
//
// Top level for Debo1 (Oppie-1 Debugger)
//
//////
	void iDebo1_launch(void)
	{
		// Spawn our permanent debugger thread
		CreateThread(NULL, 0, &iDebo1_threadProc, 0, 0, 0);
	}




//////////
//
// Main loop for Debo1
//
//////
	DWORD WINAPI iDebo1_threadProc(LPVOID lpParameter)
	{
		WNDCLASSEX	wce;
		HWND		hwnd;
		RECT		lrc, lrcDesktop;
		MSG			msg;


		//////////
		// Create the class
		//////
			memset(&wce, 0, sizeof(wce));
			wce.cbSize				= sizeof(wce);
			wce.hInstance			= GetModuleHandle(NULL);
			wce.style				= CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
			wce.lpszClassName		= cgcDebo1Class;
			wce.hCursor				= LoadCursor(NULL, IDC_ARROW);
			wce.lpfnWndProc			= &iDebo1_wndProc;


		//////////
		// Register the class
		//////
			RegisterClassEx(&wce);


		//////////
		// Center the window
		//////
			GetClientRect(GetDesktopWindow(), &lrcDesktop);
			SetRect(&lrc,	max( (lrcDesktop.right  - lrcDesktop.left - 800) / 2, 0),
							max( (lrcDesktop.bottom - lrcDesktop.top  - 600) / 2, 0),
								((lrcDesktop.right  - lrcDesktop.left - 800) / 2) + 800,
								((lrcDesktop.bottom - lrcDesktop.top  - 600) / 2) + 600);


		//////////
		// Create and show the window
		//////
			hwnd = CreateWindow(cgcDebo1Class, cgcDebo1Title, WS_OVERLAPPED, lrc.left, lrc.top, lrc.right - lrc.left, lrc.bottom - lrc.top, NULL, NULL, GetModuleHandle(NULL), NULL);
			ShowWindow(hwnd, SW_SHOW);


		//////////
		// Enter main loop
		//////
			while (glOppie1_isRunning && GetMessage(&msg, hwnd, 0, 0))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			TerminateThread(GetCurrentThread(), 0);
			return(0);
	}




//////////
//
// Callback for processing the main debo window
//
//////
	LRESULT CALLBACK iDebo1_wndProc(HWND h, UINT m, WPARAM w, LPARAM l)
	{
		PAINTSTRUCT ps;


		switch (m)
		{
			case WM_LBUTTONDOWN:
				glOppie1_isRunning = false;
				break;

			case WM_PAINT:
				BeginPaint(h, &ps);
				FillRect(ps.hdc, &ps.rcPaint, (HBRUSH)GetStockObject(WHITE_BRUSH));
				EndPaint(h, &ps);
				return 0;
				break;
		}
		return(DefWindowProc(h, m, w, l));
	}
