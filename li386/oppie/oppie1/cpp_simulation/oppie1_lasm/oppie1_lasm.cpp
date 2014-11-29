//////////
//
// /libsf/li386/oppie/oppie1/cpp_simulation/oppie1_lasm/oppie1_lasm.cpp
//
//////
// Version 0.01
// Copyright (c) 2014 by Rick C. Hodgin
//////
// Last update:
//     Nov.29.2014
//////
// Change log:
//     Nov.29.2014 - Initial creation
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
// Oppie-1 is a CPU design.  See oppie1.sv for the equivalent verilog source code.
// It is known to compile and synthesize in Altera Quartus-II.
//
// Oppie-1 LASM is the LibSF Assembler for Oppie-1 source code.  It has no linker
// and reads a simple source file with the following syntax, creates the output
// to a file with the same name with the .img extension.
//
// $ lasm myfile.asm
// LibSF Oppie-1 Assembler v0.02
// Assembling myfile.asm
// Write 2048 bytes to myfile.img
//
// ----------
//		 ; START myfile.asm				; Comment regarding start-of-file
//		 top:							; Give this address in memory a symbolic name
//				mov   r1,value1			; Load memory contents to a register by symbolic name
//				mov   r3,r2				; Move contents from one register to another
//				add   r4,r1				; Add the contents from one register to another
//				adc   r1,r3				; Add with carry? the contents from one register to another
//				sub   r2,r1				; Subtract the contents from one register to another
//				sbb   r4,r3				; Subtract with borrow (carry?) the contents from one register to another
//				mov   value2,r4			; Move the value from one register to memory by symbolic name
//				cmp   r4,r1				; Compare the value of one register to value
//				jz    @done				; Jump to the indicated address by symbolic name
//				jmp   @top				; Jump unconditionally to the indicatedaddress
//		 done:
//				halt					; Stop processing
//		
//			.org 200					; Indicate the following begins explicitly at offset 200 decimal
//		 value1:						; Give a symbolic name to this address
//				db 4 dup 0				; Store 32-bits of 0
//		 value2:						; Give a symbolic name to this address
//				db 4 dup 0				; Store 32-bits of 0
//		 ; END myfile.asm				; Comment regarding the end-of-file
// ----------
//
//////


//////////
// Uses Visual FreePro, Jr's existing parsing facilities to simplify our processing
//////
	#define _OPPIE1_COMPILE		// Turns off some features in VJr that fail on compilation from here
	#include "\libsf\source\vjr\vjr.h"
	#undef main


//////////
// Instruction encoding
//////
	#include "..\common\instructions.h"


//////////
//
// Top level lasm1 assembler
//
//////
	int main(int argc, char* argv[])
	{
		return 0;
	}
