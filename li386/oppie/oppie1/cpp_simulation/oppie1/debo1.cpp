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
	cs8				cgcDebo1Class[]								= "debo1_oppie1_debugger_window";
	cs8				cgcDebo1Title[]								= "Oppie-1 Debugger v0.02";
	cs8				cgcAppTitle[]								= "Debo1 -- Oppie-1 Debugger";
	cs8				cgcStage1Top[]								= "Stage 1";
	cs8				cgcStage1Bottom[]							= "i-fetch";
	cs8				cgcStage2Top[]								= "Stage 2";
	cs8				cgcStage2Bottom[]							= "i-decode";
	cs8				cgcStage3Top[]								= "Stage 3";
	cs8				cgcStage3Bottom[]							= "d-read";
	cs8				cgcStage4Top[]								= "Stage 4";
	cs8				cgcStage4Bottom[]							= "i-process";
	cs8				cgcStage5Top[]								= "Stage 5";
	cs8				cgcStage5Bottom[]							= "d-write";
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
// Render colors
//////
//	#define			rgba(r,g,b,a)								(((a & 0xff) << 24) + ((r & 0xff) << 16) + ((g & 0xff) <<  8) + ((b & 0xff)))
	SBgra			stage1LowColor								= { rgba(255,225,172,255) };		// Orange-ish
	SBgra			stage1HighColor								= { rgba(255,244,224,255) };
	SBgra			stage2LowColor								= { rgba(216,255,255,255) };		// Cyan-ish
	SBgra			stage2HighColor								= { rgba(237,255,255,255) };
	SBgra			stage3LowColor								= { rgba(192,255,192,255) };		// Green-ish
	SBgra			stage3HighColor								= { rgba(235,255,235,255) };
	SBgra			stage4LowColor								= { rgba(231,204,255,255) };		// Purple-ish
	SBgra			stage4HighColor								= { rgba(245,235,255,255) };
	SBgra			stage5LowColor								= { rgba(255,191,255,255) };		// Pinkish
	SBgra			stage5HighColor								= { rgba(255,235,255,255) };
	SBgra			disabledLowColor							= { rgba(205,205,205,255) };		// Grayish
	SBgra			disabledHighColor							= { rgba(235,235,235,255) };
	SBgra			invalidLowColor								= { rgba(255,191,191,255) };		// Reddish
	SBgra			invalidHighColor							= { rgba(255,235,235,255) };
	SBgra			memoryFillColor								= { rgba(242,247,255,255) };		// Blue-ish
	SBgra			memoryBorderColor							= { rgba(217,232,235,255) };		// Darker blue-ish
	SBgra			memoryOptionColor							= { rgba(64,140,255,255) };			// Darkest blue-ish
	SBgra			memoryOptionHighlightColor					= { rgba(255-64,255-140,255-255,255) };
	SBgra			registerColor								= { rgba(245,235,255,255) };		// Purple-ish
	SBgra			disassemblyColor							= { rgba(245,245,245,255) };		// Off-white-ish
	SBgra			blackColor									= { rgba(0,0,0,255) };
	SBgra			whiteColor									= { rgba(255,255,255,255) };


//////////
// Fonts in use
//////
	SBuilder*		gFonts										= NULL;
	s8				cgcUbuntu[]									= "Ubuntu";
	s8				cgcUbuntuMono[]								= "Ubuntu Mono";
	SFont*			fontUbuntuMono8							= NULL;
	SFont*			fontUbuntu14								= NULL;


//////////
// Forward declarations
//////
	//void					iDebo1_launch						(void);
	void					iiDebo1_render						(void);
	void					iiDebo1_initialize					(void);
	void					iiDebo1_renderStageBackground		(SBitmap* bmp, RECT* rc, SBgra lowColor, SBgra highColor, cs8* tcTextTop, cs8* tcTextBottom);
	void					iiDebo1_renderTextCentered			(s8* tcText, RECT* rc, bool tlCenterHorizontally);
	s32						iiDebo1_decodeAssembly				(s8* tcText, s32 ip_address);
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
			fontUbuntuMono8	= iFont_create(cgcUbuntuMono,	8,	FW_NORMAL, 0, 0);
			fontUbuntu14	= iFont_create(cgcUbuntu,		14,	FW_NORMAL, 0, 0);
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
		RECT lrc;


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
		// Title
		//////
			CopyRect(&lrc, &bmpDebo1->rc);
			lrc.left += 8;
			SelectObject(bmpDebo1->hdc, fontUbuntu14->hfont);
			SetBkMode(bmpDebo1->hdc, TRANSPARENT);
			SetTextColor(bmpDebo1->hdc, RGB(memoryOptionColor.red, memoryOptionColor.grn, memoryOptionColor.blu));
			DrawText(bmpDebo1->hdc, cgcAppTitle, strlen(cgcAppTitle), &lrc, DT_LEFT);


		//////////
		//  Pipeline stages
		//////
			BitBlt(bmpDebo1->hdc, 5, 28,	bmpStage1->bi.biWidth, bmpStage1->bi.biHeight, bmpStage1->hdc, 0, 0, SRCCOPY);
			BitBlt(bmpDebo1->hdc, 78, 28,	bmpStage2->bi.biWidth, bmpStage2->bi.biHeight, bmpStage2->hdc, 0, 0, SRCCOPY);
			BitBlt(bmpDebo1->hdc, 178, 28,	bmpStage3->bi.biWidth, bmpStage3->bi.biHeight, bmpStage3->hdc, 0, 0, SRCCOPY);
			BitBlt(bmpDebo1->hdc, 278, 9,	bmpStage4->bi.biWidth, bmpStage4->bi.biHeight, bmpStage4->hdc, 0, 0, SRCCOPY);
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
			BitBlt(bmpDebo1->hdc, 0, 173,	bmpMemory->bi.biWidth, bmpMemory->bi.biHeight, bmpMemory->hdc, 0, 0, SRCCOPY);
	}




//////////
//
// Generic pipeline render background
//
//////
	void iiDebo1_renderStageBackground(SBitmap* bmp, RECT* rc, SBgra lowColor, SBgra highColor, cs8* tcTextTop, cs8* tcTextBottom)
	{
		RECT lrcTop, lrcBot, lrcIn;


		//////////
		// Background
		//////
			SetRect(&lrcIn,		rc->left + 3,	rc->top + 16,	rc->right - 3,	rc->bottom - 16);
			iBmp_fillRect(bmp, rc,		lowColor,	lowColor,	lowColor,	lowColor,	false, &lrcIn,	true);
			iBmp_fillRect(bmp, &lrcIn,	highColor,	highColor,	highColor,	highColor,	false, NULL,	false);


		//////////
		// Text
		//////
			if (tcTextTop)
			{
				// Upper 16-pixel block
				SetRect(&lrcTop, rc->left, rc->top, rc->right, rc->top + 16);
				SelectObject(bmp->hdc, fontUbuntuMono8->hfont);
				SetBkMode(bmp->hdc, TRANSPARENT);
				SetTextColor(bmp->hdc, RGB(0,0,0));
				DrawText(bmp->hdc, tcTextTop, strlen(tcTextTop), &lrcTop, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			}

			if (tcTextBottom)
			{
				// Lower 16-pixel block
				SetRect(&lrcBot, rc->left, rc->bottom - 16, rc->right, rc->bottom);
				SelectObject(bmp->hdc, fontUbuntuMono8->hfont);
				SetBkMode(bmp->hdc, TRANSPARENT);
				SetTextColor(bmp->hdc, RGB(0,0,0));
				DrawText(bmp->hdc, tcTextBottom, strlen(tcTextBottom), &lrcBot, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			}
	}




//////////
//
// Draws the indicated buffer of text centered vertically and left-aligned
//
//////
	void iiDebo1_renderTextCentered(SBitmap* bmp, s8* tcText, RECT* rc, bool tlCenterHorizontally)
	{
		s32		lnI, lnILast, lnLength, lnPass, lnTotalHeight, lnMaxWidth, lnFontHeight;
		RECT	lrc, lrcSize;


		// Iterate 
		lnLength = strlen(tcText);
		for (lnPass = 0; lnPass < 2; lnPass++)
		{
			if (lnPass == 0)
			{
				// First pass we're computing
				for (lnI = 0, lnILast = 0, lnTotalHeight = 0, lnMaxWidth = 0, lnFontHeight = 0; lnI < lnLength; lnI++)
				{
					if (tcText[lnI] == '\n' || tcText[lnI + 1] == 0)
					{
						// We've reached the end of the line (so to speak)
						DrawText(bmp->hdc, tcText + lnILast, lnI - lnILast + ((tcText[lnI + 1] == 0) ? 1 : 0), &lrcSize, DT_CALCRECT);

						// Increase the height
						lnTotalHeight	+= (lrcSize.bottom - lrcSize.top);
						lnFontHeight	= max((lrcSize.bottom - lrcSize.top), lnFontHeight);

						// Set the max width
						lnMaxWidth = max(lnMaxWidth, (lrcSize.right - lrcSize.left));

						// Indicate the last part
						lnILast = lnI + 1;
					}
				}

			} else {
				// Establish our rectangle
				SetRect(&lrc,	((tlCenterHorizontally) ? 0 : ((rc->right - rc->left - lnMaxWidth) / 2)),
								((rc->bottom - rc->top - lnTotalHeight) / 2),
								rc->right, rc->bottom);

				// Second pass we're drawing
				for (lnI = 0, lnILast = 0; lnI < lnLength; lnI++)
				{
					if (tcText[lnI] == '\n' || tcText[lnI + 1] == 0)
					{
						// Draw it
						DrawText(bmp->hdc, tcText + lnILast, lnI - lnILast + ((tcText[lnI + 1] == 0) ? 1 : 0), &lrc, DT_LEFT | ((tlCenterHorizontally) ? DT_CENTER : 0));


						// Move down for the next go
						lrc.top += lnFontHeight;

						// Indicate the last part
						lnILast = lnI + 1;
					}
				}
			}
		}
	}




//////////
//
// Disassemble the instruction into text form
//
//////
	s32 iiDebo1_decodeAssembly(s8* tcText, s32 ip_address)
	{
		s32		lnOpcodeCount;
		SOra	iora;		// ooo.xx.aaa.aaaaaaaa
		SOrr	iorr;		// ooo.x.rd.rs, oooo.rd.rs
		SBsa	ibsa;		// ooo.x.s.aaa.aaaaaaaa


		//////////
		// Fill the instruction patterns for testing
		//////
			iora.i_data1 = ram[ip_address];
			iorr.i_data1 = ram[ip_address];
			ibsa.i_data1 = ram[ip_address];
			iora.i_data2 = ram[ip_address + 1];
			ibsa.i_data2 = ram[ip_address + 1];

			// Decode the bits
			if (iora.ooo == _MOV_R8_ADDR)
			{
				// mov   reg8,[address]		2			000.00.000:00000000
				lnOpcodeCount = 2;
				sprintf(tcText, "mov r%u,[%03x]\0", (u32)iora.rd + 1, ((u16)iora.aaa << 8) | (u16)iora.aaaaaaaa);

			} else if (iorr.ooo == _MOV_R8_R8) {
				// mov   reg8,reg8			1			001.x.00.00	(dest,src)
				lnOpcodeCount = 1;
				sprintf(tcText, "mov r%u,r%u\0", (u32)iorr.rd + 1, (u32)iorr.rs + 1);

			} else if (iorr.oooo == _ADD_R8_R8) {
				// add   reg8,reg8			1			0100.00.00
				lnOpcodeCount = 1;
				sprintf(tcText, "add r%u,r%u\0", (u32)iorr.rd + 1, (u32)iorr.rs + 1);

			} else if (iorr.oooo == _ADC_R8_R8) {
				// adc   reg8,reg8			1			0110.00.00
				lnOpcodeCount = 1;
				sprintf(tcText, "adc r%u,r%u\0", (u32)iorr.rd + 1, (u32)iorr.rs + 1);

			} else if (iorr.oooo == _SUB_R8_R8) {
				// sub   reg8,reg8			1			0101.00.00
				lnOpcodeCount = 1;
				sprintf(tcText, "sub r%u,r%u\0", (u32)iorr.rd + 1, (u32)iorr.rs + 1);

			} else if (iorr.oooo == _SBB_R8_R8) {
				// sbb   reg8,reg8			1			0111.00.00
				lnOpcodeCount = 1;
				sprintf(tcText, "sbb r%u,r%u\0", (u32)iorr.rd + 1, (u32)iorr.rs + 1);

			} else if (iora.ooo == _MOV_ADDR_R8) {
				// mov   [address],reg8		2			100.00.000:00000000
				lnOpcodeCount = 2;
				sprintf(tcText, "mov [%03x],r%u\0", ((u16)iora.aaa << 8) | (u16)iora.aaaaaaaa, (u32)iora.rd + 1);

			} else if (iorr.ooo == _CMP_R8_R8) {
				// cmp   reg8,reg8			1			101.x.00.00	(left,right)
				lnOpcodeCount = 1;
				sprintf(tcText, "cmp r%u,r%u\0", (u32)iorr.rd + 1, (u32)iorr.rs + 1);

			} else if (ibsa.ooo == _JZ_REL_ADDR) {
				// jz    +/- 1KB			2			110.xx.s.00:00000000
				lnOpcodeCount = 2;
				if (ibsa.s)
				{
					// Jumping negative
					sprintf(tcText, "jz  -%03x\0", ((u16)ibsa.aa << 8) | (u16)ibsa.aaaaaaaa);

				} else {
					// Jumping positive
					sprintf(tcText, "jz  +%03x\0", ((u16)ibsa.aa << 8) | (u16)ibsa.aaaaaaaa);
				}

			} else if (ibsa.ooo == _JMP_REL_ADDR) {
				// jmp   +/- 1KB			2			111.xx.s.00:00000000 
				lnOpcodeCount = 2;
				if (ibsa.s)
				{
					// Jumping negative
					sprintf(tcText, "jmp -%03x\0", ((u16)ibsa.aa << 8) | (u16)ibsa.aaaaaaaa);

				} else {
					// Jumping positive
					sprintf(tcText, "jmp +%03x\0", ((u16)ibsa.aa << 8) | (u16)ibsa.aaaaaaaa);
				}

			} else {
				// Invalid opcode
				lnOpcodeCount = 1;
				sprintf(tcText, "??? %02x\0", ram[ip_address]);
			}


		//////////
		// Indicate how many bytes were used in the opcode
		//////
			return(lnOpcodeCount);
	}




//////////
//
// Pipe stage 1 is i-fetch, reads opcodes ahead in the instruction stream
//
//////
	void iiDebo1_renderStage1(void)
	{
		s8 buffer[64];


		//////////
		// Standard background coloring
		//////
			if (state.pipeStage >= _STAGE1)
			{
				// Valid
				iiDebo1_renderStageBackground(bmpStage1, &bmpStage1->rc, stage1LowColor, stage1HighColor, cgcStage1Top, cgcStage1Bottom);

			} else {
				// Invalid
				iiDebo1_renderStageBackground(bmpStage1, &bmpStage1->rc, invalidLowColor, invalidHighColor, cgcStage1Top, cgcStage1Bottom);
			}


		//////////
		// Stage 1 specific content
		//////
			sprintf(buffer, "ip %03x\nip+0 %02x\nip+1 %02x\nip+2 %02x\0", pipe1.ip, pipe1.i_data1, pipe1.i_data2, pipe1.i_data3);
			SetBkMode(bmpStage1->hdc, TRANSPARENT);
			SetTextColor(bmpStage1->hdc, RGB(0,0,0));
			iiDebo1_renderTextCentered(bmpStage1, buffer, &bmpStage1->rc, true);
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
		s8 buffer[64];


		//////////
		// Standard background coloring
		//////
			if (state.pipeStage >= _STAGE2)
			{
				// Valid
				iiDebo1_renderStageBackground(bmpStage2, &bmpStage2->rc, stage2LowColor, stage2HighColor, cgcStage2Top, cgcStage2Bottom);

			} else {
				// Invalid
				iiDebo1_renderStageBackground(bmpStage2, &bmpStage2->rc, invalidLowColor, invalidHighColor, cgcStage2Top, cgcStage2Bottom);
			}


		//////////
		// Stage 2 specific content
		//////
			if (pipe2.p2_increment2)
			{
				// Two-byte opcode
				sprintf(buffer, "ip %03x\nop %02x.02x\0", pipe2.ip, pipe2.i_data1, pipe2.i_data2);

			} else {
				// One-byte opcode
				sprintf(buffer, "ip %03x\nop %02x\0", pipe2.ip, pipe2.i_data1);
			}

			if (pipe2.p3_d_read)
				sprintf(buffer + strlen(buffer), "\nread [%03x]\0", pipe2.p3_d_read_address);

			if (pipe2.p5_d_write)
				sprintf(buffer + strlen(buffer), "\nwrite [%03x]\0", pipe2.p5_d_write_address);

			// Indicate the instruction
			sprintf(buffer + strlen(buffer), "\n\n\0");
			iiDebo1_decodeAssembly(buffer + strlen(buffer), pipe2.ip);

			// Draw
			SetBkMode(bmpStage2->hdc, TRANSPARENT);
			SetTextColor(bmpStage2->hdc, RGB(0,0,0));
			iiDebo1_renderTextCentered(bmpStage2, buffer, &bmpStage2->rc, true);
	}




//////////
//
// Pipe stage 3 is d-read, to read any memory required by the instruction.
//
//////
	void iiDebo1_renderStage3(void)
	{
		s8 buffer[64];


		//////////
		// Standard background coloring
		//////
			if (state.pipeStage >= _STAGE3)
			{
				// Valid
				if (pipe3.p3_d_read)
				{
					// There is a read at this point
					iiDebo1_renderStageBackground(bmpStage3, &bmpStage3->rc, stage3LowColor, stage3HighColor, cgcStage3Top, cgcStage3Bottom);

				} else {
					// No read
					iiDebo1_renderStageBackground(bmpStage3, &bmpStage3->rc, disabledLowColor, disabledHighColor, cgcStage3Top, cgcStage3Bottom);
				}

			} else {
				// Invalid
				iiDebo1_renderStageBackground(bmpStage3, &bmpStage3->rc, invalidLowColor, invalidHighColor, cgcStage3Top, cgcStage3Bottom);
			}


		//////////
		// Stage 3 specific content
		//////
			sprintf(buffer, "ip %03x\n\0", pipe3.ip);
			if (pipe3.p3_d_read)
			{
				// Data to read
				sprintf(buffer + strlen(buffer), "read [%03x]\0", pipe3.p3_d_read_address);

			} else {
				// No data t read
				sprintf(buffer + strlen(buffer), "no read\0");
			}
			SetBkMode(bmpStage3->hdc, TRANSPARENT);
			SetTextColor(bmpStage3->hdc, RGB(0,0,0));
			iiDebo1_renderTextCentered(bmpStage3, buffer, &bmpStage3->rc, true);
	}




//////////
//
// Pipe stage 4 is i-process, performs the operation specified by the opcode.
//
//////
	void iiDebo1_renderStage4(void)
	{
		RECT	lrc;
		s8		buffer[64];


		//////////
		// Standard background coloring
		//////
			SetRect(&lrc, 0, 19, bmpStage4->bi.biWidth - 1, bmpStage4->bi.biHeight - 1);
			if (state.pipeStage >= _STAGE4)
			{
				// Valid
				iiDebo1_renderStageBackground(bmpStage4, &lrc, stage4LowColor, stage4HighColor, cgcStage4Top, cgcStage4Bottom);

			} else {
				// Invalid
				iiDebo1_renderStageBackground(bmpStage4, &lrc, invalidLowColor, invalidHighColor, cgcStage4Top, cgcStage4Bottom);
			}


		//////////
		// Stage 4 specific content
		//////
			iiDebo1_decodeAssembly(&buffer[0], pipe4.ip);
			SetBkMode(bmpStage4->hdc, TRANSPARENT);
			SetTextColor(bmpStage4->hdc, RGB(0,0,0));
			iiDebo1_renderTextCentered(bmpStage4, buffer, &bmpStage4->rc, true);
	}




//////////
//
// Pipe stage 5 is d-write, writes updates back out to main memory
//
//////
	void iiDebo1_renderStage5(void)
	{
		s8 buffer[64];


		//////////
		// Standard background coloring
		//////
			if (state.pipeStage >= _STAGE5)
			{
				// Valid
				if (pipe5.p5_d_write)
				{
					// There is a write at this point
					iiDebo1_renderStageBackground(bmpStage5, &bmpStage5->rc, stage5LowColor, stage5HighColor, cgcStage5Top, cgcStage5Bottom);

				} else {
					// No write
					iiDebo1_renderStageBackground(bmpStage5, &bmpStage5->rc, disabledLowColor, disabledHighColor, cgcStage5Top, cgcStage5Bottom);
				}

			} else {
				// Invalid
				iiDebo1_renderStageBackground(bmpStage5, &bmpStage5->rc, invalidLowColor, invalidHighColor, cgcStage5Top, cgcStage5Bottom);
			}


		//////////
		// Stage 5 specific content
		//////
			sprintf(buffer, "ip %03x\n\0", pipe5.ip);
			if (pipe5.p5_d_write)
			{
				// Data to write
				sprintf(buffer + strlen(buffer), "write [%03x]\0", pipe5.p5_d_write_address);

			} else {
				// No data t read
				sprintf(buffer + strlen(buffer), "no write\0");
			}
			SetBkMode(bmpStage5->hdc, TRANSPARENT);
			SetTextColor(bmpStage5->hdc, RGB(0,0,0));
			iiDebo1_renderTextCentered(bmpStage5, buffer, &bmpStage3->rc, true);
	}




//////////
//
// Register window holds r1,r2,r3,r4, as well as carry? and zero? flags
//
//////
	void iiDebo1_renderRegisters(void)
	{
		iBmp_fillRect(bmpRegisters, &bmpRegisters->rc, registerColor, registerColor, registerColor, registerColor, false, NULL, false);
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
		iBmp_fillRect(bmpDisassembly, &bmpDisassembly->rc, disassemblyColor, disassemblyColor, disassemblyColor, disassemblyColor, false, NULL, false);
	}




//////////
//
// The Oppie-1 memory block is one of two banks, either showing the first
// 1KB of its 2KB RAM, or the second.
//
//////
	void iiDebo1_renderMemory(void)
	{
		RECT lrcIn;


		SetRect(&lrcIn, 35, 23, bmpMemory->bi.biWidth - 1, bmpMemory->bi.biHeight - 1);
		iBmp_fillRect(bmpMemory, &bmpMemory->rc, memoryBorderColor, memoryBorderColor, memoryBorderColor, memoryBorderColor, false, &lrcIn, true);
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
		// Create a 50ms timer (20x per second)
		//////
			SetTimer(hwnd, NULL, 50, NULL);


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
				glDebo1_updateDisplay = true;
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
