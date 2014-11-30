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
	#include "keywords.h"


//////////
// Forward declarations
//////
	SComp*		iParseSourceCodeLine						(SLine* line);
	void		iCompileSourceCodeLine						(SLine* line, s32* tnErrors, s32* tnWarnings);




//////////
//
// Top level lasm1 assembler
//
//////
	int main(int argc, char* argv[])
	{
		s32		lnErrors, lnWarnings;
		SEM*	asmFile;
		SLine*	line;


		//////////
		// Identify ourself
		//////
			printf("LibSF Oppie-1 Assembler v0.02\n");


		//////////
		// lasm1 only takes one parameter, the input filename
		//////
			if (argc != 1)
			{
				// Display syntax
				printf("Usage:  lasm1 myfile.asm\n");

			} else {
				// Allocate our load manager
				asmFile = iSEM_allocate(true);
				if (!asmFile)
				{
					// Internal error
					printf("Internal error allocating load buffer\n");

				} else {
					// Try to physically load it
					if (!iSEM_loadFromDisk(asmFile, argv[1], true))
					{
						// Error opening
						printf("Unable to open %s\n", argv[1]);

					} else {
						//////////
						// Parse every line into known components
						//////
							for (line = asmFile->firstLine; line; line = (SLine*)line->ll.next)
								iParseSourceCodeLine(line);


						//////////
						// Compile every line that can be compiled, report any errors
						//////
							for (	line = asmFile->firstLine, lnErrors = 0, lnWarnings = 0;
									line && lnErrors == 0;
									line = (SLine*)line->ll.next	)
							{
								iCompileSourceCodeLine(line, &lnErrors, &lnWarnings);
							}
					}
				}
			}


		//////////
		// Task completed (one way or another :-))
		//////
			return 0;
	}




//////////
//
// Parses the text of the line into any known tokens
//
//////
	SComp* iParseSourceCodeLine(SLine* line)
	{
		SComp* compNext;


		//////////
		// Parse out the line
		//////
			iComps_translateSourceLineTo(&cgcFundamentalSymbols[0], line);
			if (!line->compilerInfo->firstComp)
				return(NULL);	// Nothing to compile on this blank line

			// Remove whitespaces [x][whitespace][y] becomes [x][y]
			iComps_removeLeadingWhitespaces(line);
			if (!line->compilerInfo->firstComp)
				return(NULL);	// Nothing to compile on this line with only whitespaces


		//////////
		// We don't need to process comment-only lines
		//////
			if (line->compilerInfo->firstComp && (line->compilerInfo->firstComp->iCode == _ICODE_COMMENT || line->compilerInfo->firstComp->iCode == _ICODE_LINE_COMMENT))
			{
				//////////
				// Combine every item after this to a single comment component or easy parsing and handling
				//////
					iComps_combineNextN(line->compilerInfo->firstComp, 99999, line->compilerInfo->firstComp->iCode, line->compilerInfo->firstComp->iCat, line->compilerInfo->firstComp->color);

			} else {
				//////////
				// Perform natural source code fixups
				//////
					iComps_removeStartEndComments(line);		// Remove /* comments */
					iComps_fixupNaturalGroupings(line);			// Fixup natural groupings [_][aaa][999] becomes [_aaa999], [999][.][99] becomes [999.99], etc.
					iComps_removeWhitespaces(line);				// Remove all whitespaces after everything else was parsed [use][whitespace][foo] becomes [use][foo]


				//////////
				// Translate sequences to known keywords
				//////
					iComps_translateToOthers((SAsciiCompSearcher*)&cgcKeywordsOppie1[0], line);


				//////////
				// Perform fixups that are unique to Oppie-1
				//////
					// .org
					// [.][org] becomes [.org]
					if ((compNext = (SComp*)line->compilerInfo->firstComp->ll.next) && line->compilerInfo->firstComp->iCode == _ICODE_DOT && compNext->iCode == _ICODE_ORG)
						iComps_combineNextN(line->compilerInfo->firstComp, 1, compNext->iCode, compNext->iCat, compNext->color);

					// label:
					// [label][:] becomes [label:]
					if ((compNext = (SComp*)line->compilerInfo->firstComp->ll.next) && (line->compilerInfo->firstComp->iCode == _ICODE_ALPHA || line->compilerInfo->firstComp->iCode == _ICODE_ALPHANUMERIC) && compNext->iCode == _ICODE_COLON)
						iComps_combineNextN(line->compilerInfo->firstComp, 1, _ICODE_LABEL, compNext->iCat, compNext->color);
			}


		//////////
		// Return the first component
		//////
			return(line->compilerInfo->firstComp);
	}




//////////
//
// Called to parse the indicated line of source code
//
//////
	void iCompileSourceCodeLine(SLine* line, s32* tnErrors, s32* tnWarnings)
	{
		SComp*	comp;
		SComp*	compNext1;
		SComp*	compNext2;
		SComp*	compNext3;
		SComp*	compNext4;
		SComp*	compNext5;


		// Make sure we have something to do
		if ((comp = line->compilerInfo->firstComp) && comp->iCode != _ICODE_COMMENT)
		{
			// Populate as many components as follow
			if ((compNext1 = (SComp*)comp->ll.next) && (compNext2 = (SComp*)compNext1->ll.next) && (compNext3 = (SComp*)compNext2->ll.next) && (compNext4 = (SComp*)compNext3->ll.next) && (compNext5 = (SComp*)compNext4->ll.next))
			{
				// Placeholder
			}

			// See what's there
			switch (comp->iCode)
			{
				case _ICODE_MOV:
					// mov instruction
					if (compNext1 && compNext2 && compNext3)
					{
						if (compNext1->iCat == _ICAT_REGISTER && compNext2->iCode == _ICODE_COMMA)
						{
							// mov reg,
							if (compNext3->iCat == _ICAT_REGISTER) {
								// mov reg,reg

							} else if (compNext3->iCode == _ICODE_BRACKET_LEFT && compNext4 && compNext4->iCode == _ICODE_ALPHANUMERIC && compNext5 && compNext5->iCode == _ICODE_BRACKET_RIGHT) {
								// mov reg,[99]

							} else if (compNext3->iCode == _ICODE_ALPHA || compNext3->iCode == _ICODE_ALPHANUMERIC) {
								// mov reg,label

							} else {
								// Syntax error
								printf("Syntax error on line %u, column %u\n", line->lineNumber, compNext3->start + 1);
							}

						} else if (compNext1->iCode == _ICODE_BRACKET_LEFT && compNext4) {
							// mov [
							if (compNext2->iCode == _ICODE_NUMERIC && compNext3->iCode == _ICODE_BRACKET_RIGHT && compNext4 && compNext4->iCode == _ICODE_COMMA && compNext5 && compNext5->iCat == _ICAT_REGISTER) {
								// mov [99],reg

							} else {
								// Syntax error
								printf("Syntax error on line %u, column %u\n", line->lineNumber, compNext2->start + 1);
							}

						} else if ((compNext1->iCode == _ICODE_ALPHA || compNext1->iCode == _ICODE_ALPHANUMERIC) && compNext2->iCode == _ICODE_COMMA && compNext3->iCat == _ICAT_REGISTER) {
							// mov label,reg

						} else {
							// Syntax error
							printf("Syntax error on line %u, column %u\n", line->lineNumber, compNext1->start + 1);
						}

					} else {
						// Syntax error
						printf("Syntax error on line %u, column %u\n", line->lineNumber, comp->start + 1);
					}
					break;

				case _ICODE_ADD:
					// add instruction
					if (compNext1 && compNext2 && compNext3 && compNext1->iCat == _ICAT_REGISTER && compNext2->iCode == _ICODE_COMMA && compNext3->iCat == _ICAT_REGISTER)
					{
						// add reg,reg

					} else {
						// Syntax error
						printf("Syntax error on ADD on line %u, column %u\n", line->lineNumber, compNext1->start + 1);
					}
					break;

				case _ICODE_ADC:
					// adc instruction
					if (compNext1 && compNext2 && compNext3 && compNext1->iCat == _ICAT_REGISTER && compNext2->iCode == _ICODE_COMMA && compNext3->iCat == _ICAT_REGISTER)
					{
						// add reg,reg

					} else {
						// Syntax error
						printf("Syntax error on ADC on line %u, column %u\n", line->lineNumber, compNext1->start + 1);
					}
					break;

				case _ICODE_SUB:
					// sub instruction
					if (compNext1 && compNext2 && compNext3 && compNext1->iCat == _ICAT_REGISTER && compNext2->iCode == _ICODE_COMMA && compNext3->iCat == _ICAT_REGISTER)
					{
						// add reg,reg

					} else {
						// Syntax error
						printf("Syntax error on SUB on line %u, column %u\n", line->lineNumber, compNext1->start + 1);
					}
					break;

				case _ICODE_SBB:
					// sbb instruction
					if (compNext1 && compNext2 && compNext3 && compNext1->iCat == _ICAT_REGISTER && compNext2->iCode == _ICODE_COMMA && compNext3->iCat == _ICAT_REGISTER)
					{
						// add reg,reg

					} else {
						// Syntax error
						printf("Syntax error on SBB on line %u, column %u\n", line->lineNumber, compNext1->start + 1);
					}
					break;

				case _ICODE_CMP:
					// cmp instruction
					if (compNext1 && compNext2 && compNext3 && compNext1->iCat == _ICAT_REGISTER && compNext2->iCode == _ICODE_COMMA && compNext3->iCat == _ICAT_REGISTER)
					{
						// add reg,reg

					} else {
						// Syntax error
						printf("Syntax error on CMP on line %u, column %u\n", line->lineNumber, compNext1->start + 1);
					}
					break;

				case _ICODE_JNC:
					// jnc instruction
					break;

				case _ICODE_JC:
					// jc instruction
					break;

				case _ICODE_JNZ:
					// jnz instruction
					break;

				case _ICODE_JZ:
					// jz instruction
					break;

				case _ICODE_JMP:
					// jnc instruction
					break;

				case _ICODE_ORG:
					// .org preprocessor
					break;

				case _ICODE_DB:
					// db prefix for data initialization
					break;

				case _ICODE_LABEL:
					// It's a label
					break;

				default:
					// It's was not recognized
					if (tnErrors)
						++*tnErrors;

					// Display the error
					printf("Syntax error on line %u, column %u\n", line->lineNumber, comp->start + 1);
			}
		}
	}
