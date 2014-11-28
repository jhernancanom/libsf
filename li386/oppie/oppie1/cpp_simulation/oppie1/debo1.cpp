//////////
//
// /libsf/li386/oppie/oppie1/cpp_simulation/debo1.cpp
//
//////
// Version 0.02
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
// bitmaps.cpp
//////
	#include "\libsf\utils\common\cpp\common_types.h"
	#include "\libsf\utils\common\cpp\ll.h"
	#include "\libsf\source\vjr\vjr_structs0.h"
	#include "\libsf\source\vjr\vjr_structs.h"
	#include "\libsf\utils\common\cpp\builder.h"
	#include "\libsf\source\vjr\fonts.h"
	#include "\libsf\source\vjr\datum.h"
	#include "\libsf\source\vjr\bitmaps.h"


//////////
// Global variables
//////
	const s8		cgcDebo1Class[]								= "debo1_oppie1_debugger_window";
	const s8		cgcDebo1Title[]								= "Oppie-1 Debugger v0.02";
	bool			glDebo1_executionIsPaused					= true;
	bool			glDebo1_executionIsSingleStepping			= false;
	bool			glDebo1_executionIsThrottled				= false;
	bool			glDebo1_updateDisplay						= true;
	s32				gnWidth										= 800;
	s32				gnHeight									= 600;


//////////
// Render buckets
//////
	SBitmap*		bmpDebo1									= NULL;			// Entire main window
	SBitmap*		bmpStage1									= NULL;			// Stage 1 pipe, i-fetch
	SBitmap*		bmpStage2									= NULL;			// Stage 2 pipe, i-decode
	SBitmap*		bmpStage3									= NULL;			// Stage 3 pipe, d-read
	SBitmap*		bmpStage4									= NULL;			// Stage 4 pipe, i-process
	SBitmap*		bmpStage5									= NULL;			// Stage 5 pipe, d-write
	SBitmap*		bmpMemory									= NULL;			// Memory window
	SBitmap*		bmpRegisters								= NULL;			// Registers window
	SBitmap*		bmpDisassembly								= NULL;			// Disassembly window
	SBitmap*		bmp1Kb										= NULL;			// First KB memory range selection
	SBitmap*		bmp2Kb										= NULL;			// Second KB memory range selection
	SBitmap*		bmp8Bits									= NULL;			// Display memory in 8-bit values
	SBitmap*		bmp16Bits									= NULL;			// Display memory in 16-bit values
	SBitmap*		bmp32Bits									= NULL;			// Display memory in 32-bit values
	SBitmap*		bmp64Bits									= NULL;			// Display memory in 64-bit values
	SBitmap*		bmpF5Run									= NULL;			// For "F5:Run" text
	SBitmap*		bmpF8Step									= NULL;			// For "F8:Step" text
	SBitmap*		bmpF12Throttle								= NULL;			// For "F12:Throttle" text


//////////
// Fonts in use
//////
	SBuilder*		gFonts										= NULL;
	s8				cgcUbuntu[]									= "Ubuntu";
	s8				cgcUbuntuMono[]								= "Ubuntu Mono";
	SFont*			fontUbuntuMono12							= NULL;
	SFont*			fontUbuntu20								= NULL;


//////////
// Forward declarations
//////
	//void					iDebo1_launch						(void);
	void					iiDebo1_render						(void)
	void					iiDebo1_initialize					(void);
	void					iiDebo1_renderStage1				(void);
	void					iiDebo1_renderStage2				(void);
	void					iiDebo1_renderStage3				(void);
	void					iiDebo1_renderStage4				(void);
	void					iiDebo1_renderStage5				(void);
	void					iiDebo1_renderRegisters				(void);
	void					iiDebo1_renderDisassembly			(void);
	void					iiDebo1_renderMemory				(void);
	DWORD WINAPI			iDebo1_threadProc					(LPVOID lpParameter);
	LRESULT CALLBACK		iDebo1_wndProc						(HWND h, UINT m, WPARAM w, LPARAM l);


//////////
// Include files
//////
	#include "\libsf\utils\common\cpp\builder.cpp"
	#include "\libsf\source\vjr\fonts.cpp"
	#include "\libsf\source\vjr\datum.cpp"
	#include "\libsf\source\vjr\bitmaps.cpp"




//////////
//
// Top level for Debo1 (Oppie-1 Debugger)
//
//////
	void iDebo1_launch(void)
	{
		// Initialize our bitmaps
		iiDebo1_initialize();

		// Spawn our permanent debugger thread
		CreateThread(NULL, 0, &iDebo1_threadProc, 0, 0, 0);
	}

	void iiDebo1_initialize(void)
	{
		//////////
		// Create the base bitmaps
		//////
			iBmp_createBySize(bmpDebo1			= iBmp_allocate(),			gnWidth,	gnHeight,	24);
			iBmp_createBySize(bmpStage1			= iBmp_allocate(),			67,			114,		24);
			iBmp_createBySize(bmpStage2			= iBmp_allocate(),			94,			114,		24);
			iBmp_createBySize(bmpStage3			= iBmp_allocate(),			94,			114,		24);
			iBmp_createBySize(bmpStage4			= iBmp_allocate(),			244,		133,		24);
			iBmp_createBySize(bmpStage5			= iBmp_allocate(),			83,			114,		24);
			iBmp_createBySize(bmpMemory			= iBmp_allocate(),			616,		449,		24);
			iBmp_createBySize(bmpRegisters		= iBmp_allocate(),			179,		171,		24);
			iBmp_createBySize(bmpDisassembly	= iBmp_allocate(),			181,		427,		24);
			iBmp_createBySize(bmp1Kb			= iBmp_allocate(),			74,			22,			24);
			iBmp_createBySize(bmp2Kb			= iBmp_allocate(),			74,			22,			24);
			iBmp_createBySize(bmp8Bits			= iBmp_allocate(),			64,			22,			24);
			iBmp_createBySize(bmp16Bits			= iBmp_allocate(),			64,			22,			24);
			iBmp_createBySize(bmp32Bits			= iBmp_allocate(),			64,			22,			24);
			iBmp_createBySize(bmp64Bits			= iBmp_allocate(),			64,			22,			24);
			iBmp_createBySize(bmpF5Run			= iBmp_allocate(),			50,			19,			24);
			iBmp_createBySize(bmpF8Step			= iBmp_allocate(),			54,			19,			24);
			iBmp_createBySize(bmpF12Throttle	= iBmp_allocate(),			84,			19,			24);


		//////////
		// Create the base fonts
		//////
			iBuilder_createAndInitialize(&gFonts, -1);
			fontUbuntuMono12	= iFont_create(cgcUbuntuMono,	12, FW_SEMIBOLD, 0, 0);
			fontUbuntu20		= iFont_create(cgcUbuntu,		20, FW_SEMIBOLD, 0, 0);
	}




//////////
//
// Called to render the Debo1 window.
// Note:  Renders into the bmpDebo1->hdc bitmap for later copying with BitBlt().
// Note:  The file debo-1.png was used as a template for this construction.
//
//////
	void iiDebo1_render(void)
	{
		//////////
		// Render the sub-components
		//////
			iiDebo1_renderStage1();
			iiDebo1_renderStage2();
			iiDebo1_renderStage3();
			iiDebo1_renderStage4();
			iiDebo1_renderStage5();
			iiDebo1_renderRegisters();
			iiDebo1_renderDisassembly();
			iiDebo1_renderMemory();


		//////////
		// The main window has a white background, and then each component is rendered atop
		//////
			FillRect(bmpDebo1->hdc, &bmpDebo1->rc, (HBRUSH)GetStockObject(WHITE_BRUSH));

		//////////
		//  Pipeline stages
		//////
			BitBlt(bmpDebo1->hdc, 5, 28,	bmpStage1->bi.biWidth, bmpStage1->bi.biHeight, bmpStage1->hdc, 0, 0, SRCCOPY);
			BitBlt(bmpDebo1->hdc, 78, 28,	bmpStage2->bi.biWidth, bmpStage2->bi.biHeight, bmpStage2->hdc, 0, 0, SRCCOPY);
			BitBlt(bmpDebo1->hdc, 178, 28,	bmpStage3->bi.biWidth, bmpStage3->bi.biHeight, bmpStage3->hdc, 0, 0, SRCCOPY);
			BitBlt(bmpDebo1->hdc, 278, 28,	bmpStage4->bi.biWidth, bmpStage4->bi.biHeight, bmpStage4->hdc, 0, 0, SRCCOPY);
			BitBlt(bmpDebo1->hdc, 528, 28,	bmpStage5->bi.biWidth, bmpStage5->bi.biHeight, bmpStage5->hdc, 0, 0, SRCCOPY);


		//////////
		// Registers
		//////
			BitBlt(bmpDebo1->hdc, 618, 2,	bmpRegisters->bi.biWidth, bmpRegisters->bi.biHeight, bmpRegisters->hdc, 0, 0, SRCCOPY);


		//////////
		// Disassembly
		//////
			BitBlt(bmpDebo1->hdc, 618, 173,	bmpDisassembly->bi.biWidth, bmpDisassembly->bi.biHeight, bmpDisassembly->hdc, 0, 0, SRCCOPY);


		//////////
		// Memory
		//////
			BitBlt(bmpDebo1->hdc, 616, 449,	bmpMemory->bi.biWidth, bmpMemory->bi.biHeight, bmpMemory->hdc, 0, 0, SRCCOPY);
	}




//////////
//
// Pipe stage 1 is i-fetch, reads opcodes ahead in the instruction stream
//
//////
	void iiDebo1_renderStage1(void)
	{
	}




//////////
//
// Pipe stage 2 is i-decode, which interprets the opcode, determining
// if it is 1-byte or 2-byte, extracts addresses, and source and target
// registers.
//
//////
	void iiDebo1_renderStage2(void)
	{
	}




//////////
//
// Pipe stage 3 is d-read, to read any memory required by the instruction.
//
//////
	void iiDebo1_renderStage3(void)
	{
	}




//////////
//
// Pipe stage 4 is i-process, performs the operation specified by the opcode.
//
//////
	void iiDebo1_renderStage4(void)
	{
	}




//////////
//
// Pipe stage 5 is d-write, writes updates back out to main memory
//
//////
	void iiDebo1_renderStage5(void)
	{
	}




//////////
//
// Register window holds r1,r2,r3,r4, as well as carry? and zero? flags
//
//////
	void iiDebo1_renderRegisters(void)
	{
	}




//////////
//
// Disassembly contains multiple streams, one for each of stage 1 through 5.
// It disassembles two or three upcoming opcodes for each, allowing the
// parallel view through the stages to be examined.
//
//////
	void iiDebo1_renderDisassembly(void)
	{
	}




//////////
//
// The Oppie-1 memory block is one of two banks, either showing the first
// 1KB of its 2KB RAM, or the second.
//
//////
	void iiDebo1_renderMemory(void)
	{
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
			SetRect(&lrc,	max( (lrcDesktop.right  - lrcDesktop.left - gnWidth)  / 2, 0),
							max( (lrcDesktop.bottom - lrcDesktop.top  - gnHeight) / 2, 0),
								((lrcDesktop.right  - lrcDesktop.left - gnWidth)  / 2) + gnWidth,
								((lrcDesktop.bottom - lrcDesktop.top  - gnHeight) / 2) + gnHeight);

			// Adjust for the borders
			AdjustWindowRect(&lrc, WS_OVERLAPPEDWINDOW, FALSE);


		//////////
		// Create and show the window
		//////
			hwnd = CreateWindow(cgcDebo1Class, cgcDebo1Title, WS_OVERLAPPEDWINDOW, lrc.left, lrc.top, lrc.right - lrc.left, lrc.bottom - lrc.top, NULL, NULL, GetModuleHandle(NULL), NULL);
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
			case WM_CLOSE:
				exit(0);
				break;

			case WM_TIMER:
				// Timer fires 20x per second
				if (glDebo1_executionIsThrottled)
					glDebo1_executionIsPaused = false;

				// If we have anything to update in the debugger, signal it
				if (glDebo1_updateDisplay)
					InvalidateRect(h, NULL, FALSE);

				break;

			case WM_KEYUP:
				switch (w)
				{
					case VK_ESCAPE:
						glDebo1_executionIsPaused = true;
						break;

					case VK_F5:
						// Run
						glDebo1_executionIsSingleStepping	= false;
						glDebo1_executionIsPaused			= false;
						break;

					case VK_F8:
						// Single-step
						glDebo1_executionIsSingleStepping	= true;
						glDebo1_executionIsPaused			= false;
						break;

					case VK_F12:
						// Throttle;
						glDebo1_executionIsThrottled		= true;
						glDebo1_executionIsSingleStepping	= false;
						glDebo1_executionIsPaused			= false;
						break;
				}
				break;

			case WM_LBUTTONDOWN:
				glOppie1_isRunning = false;
				break;

			case WM_PAINT:
				BeginPaint(h, &ps);
				if (glDebo1_updateDisplay)
				{
					// Lower the flag
					glDebo1_updateDisplay = false;

					// Rebuild the display
					iiDebo1_render();
				}

				// BitBlt our content from the buffer
				BitBlt(ps.hdc, 0, 0, gnWidth, gnHeight, bmpDebo1->hdc, 0, 0, SRCCOPY);

				EndPaint(h, &ps);
				return 0;
				break;
		}
		return(DefWindowProc(h, m, w, l));
	}
