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
//				mov   r1,[512]			; Load memory contents to a register by symbolic name
//				mov   r3,r2				; Move contents from one register to another
//				add   r4,r1				; Add the contents from one register to another
//				adc   r1,r3				; Add with carry? the contents from one register to another
//				sub   r2,r1				; Subtract the contents from one register to another
//				sbb   r4,r3				; Subtract with borrow (carry?) the contents from one register to another
//				mov   value2,r4			; Move the value from one register to memory by symbolic name
//				mov   [513],r4			; Move the value from one register to memory by symbolic name
//				cmp   r4,r1				; Compare the value of one register to value
//				jnc   done				; Jump to the indicated address by symbolic name
//				jc    done				; Jump to the indicated address by symbolic name
//				jnz   done				; Jump to the indicated address by symbolic name
//				jz    done				; Jump to the indicated address by symbolic name
//				jmp   top				; Jump unconditionally to the indicatedaddress
//		 done:
//				jmp   done				; Stop processing
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
					// [alpha][:] becomes [label]
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
	cs32	_MOV_REG_REG						= 1;
	cs32	_MOV_REG_LABEL						= 2;
	cs32	_MOV_REG_99							= 3;
	cs32	_MOV_LABEL_REG						= 4;
	cs32	_MOV_99_REG							= 5;
	cs32	_ADD_REG_REG						= 6;
	cs32	_ADC_REG_REG						= 7;
	cs32	_SUB_REG_REG						= 8;
	cs32	_SBB_REG_REG						= 9;
	cs32	_CMP_REG_REG						= 10;
	cs32	_JNC_LABEL							= 11;
	cs32	_JNC_PLUS_99						= 12;
	cs32	_JNC_NEGATIVE_99					= 13;
	cs32	_JC_LABEL							= 14;
	cs32	_JC_PLUS_99							= 15;
	cs32	_JC_NEGATIVE_99						= 16;
	cs32	_JNZ_LABEL							= 17;
	cs32	_JNZ_PLUS_99						= 18;
	cs32	_JNZ_NEGATIVE_99					= 19;
	cs32	_JZ_LABEL							= 20;
	cs32	_JZ_PLUS_99							= 21;
	cs32	_JZ_NEGATIVE_99						= 22;
	cs32	_JMP_LABEL							= 23;
	cs32	_JMP_PLUS_99						= 24;
	cs32	_JMP_NEGATIVE_99					= 25;
	cs32	_ORG_99								= 26;
	cs32	_DB_DUP								= 27;

	struct SCmdPattern
	{
		s32		iCode;
		s32		iCode2;
		s32		iCat;
	};

	struct SCommand
	{
		s32			cmdType;
		SCmdPattern	comp[6];
	};

	SCommand gsCommands[] = {
		{ // mov reg,reg
			_MOV_REG_REG,
			{
				{ _ICODE_MOV, -1, -1 },
				{ -1, -1, _ICAT_REGISTER },
				{ _ICODE_COMMA, -1, -1 },
				{ -1, -1, _ICAT_REGISTER },
				{ -1, -1, -1 },
				{ -1, -1, -1 }
			}
		},

		{ // mov reg,label
			_MOV_REG_LABEL,
			{
				{ _ICODE_MOV, -1, -1 },
				{ -1, -1, _ICAT_REGISTER },
				{ _ICODE_COMMA, -1, -1 },
				{ _ICODE_ALPHA, _ICODE_ALPHANUMERIC, -1 },
				{ -1, -1, -1 },
				{ -1, -1, -1 }
			}
		},

		{ // mov reg,[99]
			_MOV_REG_99,
			{
				{ _ICODE_MOV, -1, -1 },
				{ -1, -1, _ICAT_REGISTER },
				{ _ICODE_COMMA, -1, -1 },
				{ _ICODE_BRACKET_LEFT, -1, -1 },
				{ _ICODE_NUMERIC, -1, -1 },
				{ _ICODE_BRACKET_RIGHT, -1, -1 }
			}
		},

		{ // mov label,reg
			_MOV_LABEL_REG,
			{
				{ _ICODE_MOV, -1, -1 },
				{ _ICODE_ALPHA, _ICODE_ALPHANUMERIC, -1 },
				{ _ICODE_COMMA, -1, -1 },
				{ -1, -1, _ICAT_REGISTER },
				{ -1, -1, -1 },
				{ -1, -1, -1 }
			}
		},

		{ // mov [99],reg
			_MOV_99_REG,
			{
				{ _ICODE_MOV, -1, -1 },
				{ _ICODE_BRACKET_LEFT, -1, -1 },
				{ _ICODE_NUMERIC, -1, -1 },
				{ _ICODE_BRACKET_RIGHT, -1, -1 },
				{ _ICODE_COMMA, -1, -1 },
				{ -1, -1, _ICAT_REGISTER }
			}
		},

		{ // add reg,reg
			_ADD_REG_REG,
			{
				{ _ICODE_ADD, -1, -1 },
				{ -1, -1, _ICAT_REGISTER },
				{ _ICODE_COMMA, -1, -1 },
				{ -1, -1, _ICAT_REGISTER },
				{ -1, -1, -1 },
				{ -1, -1, -1 }
			}
		},

		{ // adc reg,reg
			_ADC_REG_REG,
			{
				{ _ICODE_ADC, -1, -1 },
				{ -1, -1, _ICAT_REGISTER },
				{ _ICODE_COMMA, -1, -1 },
				{ -1, -1, _ICAT_REGISTER },
				{ -1, -1, -1 },
				{ -1, -1, -1 }
			}
		},

		{ // sub reg,reg
			_SUB_REG_REG,
			{
				{ _ICODE_SUB, -1, -1 },
				{ -1, -1, _ICAT_REGISTER },
				{ _ICODE_COMMA, -1, -1 },
				{ -1, -1, _ICAT_REGISTER },
				{ -1, -1, -1 },
				{ -1, -1, -1 }
			}
		},

		{ // sbb reg,reg
			_SBB_REG_REG,
			{
				{ _ICODE_SBB, -1, -1 },
				{ -1, -1, _ICAT_REGISTER },
				{ _ICODE_COMMA, -1, -1 },
				{ -1, -1, _ICAT_REGISTER },
				{ -1, -1, -1 },
				{ -1, -1, -1 }
			}
		},

		{ // cmp reg,reg
			_CMP_REG_REG,
			{
				{ _ICODE_CMP, -1, -1 },
				{ -1, -1, _ICAT_REGISTER },
				{ _ICODE_COMMA, -1, -1 },
				{ -1, -1, _ICAT_REGISTER },
				{ -1, -1, -1 },
				{ -1, -1, -1 }
			}
		},

		{ // jnc label
			_JNC_LABEL,
			{
				{ _ICODE_JNC, -1, -1 },
				{ _ICODE_ALPHA, _ICODE_ALPHANUMERIC, -1 },
				{ -1, -1, -1 },
				{ -1, -1, -1 },
				{ -1, -1, -1 },
				{ -1, -1, -1 }
			}
		},

		{ // jnc +99
			_JNC_PLUS_99,
			{
				{ _ICODE_JNC, -1, -1 },
				{ _ICODE_PLUS, -1, -1 },
				{ _ICODE_NUMERIC, -1, -1 },
				{ -1, -1, -1 },
				{ -1, -1, -1 },
				{ -1, -1, -1 }
			}
		},

		{ // jnc -99
			_JNC_NEGATIVE_99,
			{
				{ _ICODE_JNC, -1, -1 },
				{ _ICODE_HYPHEN, -1, -1 },
				{ _ICODE_NUMERIC, -1, -1 },
				{ -1, -1, -1 },
				{ -1, -1, -1 },
				{ -1, -1, -1 }
			}
		},

		{ // jc label
			_JC_LABEL,
			{
				{ _ICODE_JC, -1, -1 },
				{ _ICODE_ALPHA, _ICODE_ALPHANUMERIC, -1 },
				{ -1, -1, -1 },
				{ -1, -1, -1 },
				{ -1, -1, -1 },
				{ -1, -1, -1 }
			}
		},

		{ // jc +99
			_JC_PLUS_99,
			{
				{ _ICODE_JC, -1, -1 },
				{ _ICODE_PLUS, -1, -1 },
				{ _ICODE_NUMERIC, -1, -1 },
				{ -1, -1, -1 },
				{ -1, -1, -1 },
				{ -1, -1, -1 }
			}
		},

		{ // jc -99
			_JC_NEGATIVE_99,
			{
				{ _ICODE_JC, -1, -1 },
				{ _ICODE_HYPHEN, -1, -1 },
				{ _ICODE_NUMERIC, -1, -1 },
				{ -1, -1, -1 },
				{ -1, -1, -1 },
				{ -1, -1, -1 }
			}
		},

		{ // jnz label
			_JNZ_LABEL,
			{
				{ _ICODE_JNZ, -1, -1 },
				{ _ICODE_ALPHA, _ICODE_ALPHANUMERIC, -1 },
				{ -1, -1, -1 },
				{ -1, -1, -1 },
				{ -1, -1, -1 },
				{ -1, -1, -1 }
			}
		},

		{ // jnz +99
			_JNZ_PLUS_99,
			{
				{ _ICODE_JNZ, -1, -1 },
				{ _ICODE_PLUS, -1, -1 },
				{ _ICODE_NUMERIC, -1, -1 },
				{ -1, -1, -1 },
				{ -1, -1, -1 },
				{ -1, -1, -1 }
			}
		},

		{ // jnz -99
			_JNZ_NEGATIVE_99,
			{
				{ _ICODE_JNZ, -1, -1 },
				{ _ICODE_HYPHEN, -1, -1 },
				{ _ICODE_NUMERIC, -1, -1 },
				{ -1, -1, -1 },
				{ -1, -1, -1 },
				{ -1, -1, -1 }
			}
		},

		{ // jz label
			_JZ_LABEL,
			{
				{ _ICODE_JZ, -1, -1 },
				{ _ICODE_ALPHA, _ICODE_ALPHANUMERIC, -1 },
				{ -1, -1, -1 },
				{ -1, -1, -1 },
				{ -1, -1, -1 },
				{ -1, -1, -1 }
			}
		},

		{ // jz +99
			_JZ_PLUS_99,
			{
				{ _ICODE_JZ, -1, -1 },
				{ _ICODE_PLUS, -1, -1 },
				{ _ICODE_NUMERIC, -1, -1 },
				{ -1, -1, -1 },
				{ -1, -1, -1 },
				{ -1, -1, -1 }
			}
		},

		{ // jz -99
			_JZ_NEGATIVE_99,
			{
				{ _ICODE_JZ, -1, -1 },
				{ _ICODE_HYPHEN, -1, -1 },
				{ _ICODE_NUMERIC, -1, -1 },
				{ -1, -1, -1 },
				{ -1, -1, -1 },
				{ -1, -1, -1 }
			}
		},

		{ // jmp label
			_JMP_LABEL,
			{
				{ _ICODE_JMP, -1, -1 },
				{ _ICODE_ALPHA, _ICODE_ALPHANUMERIC, -1 },
				{ -1, -1, -1 },
				{ -1, -1, -1 },
				{ -1, -1, -1 },
				{ -1, -1, -1 }
			}
		},

		{ // jmp +99
			_JMP_PLUS_99,
			{
				{ _ICODE_JMP, -1, -1 },
				{ _ICODE_PLUS, -1, -1 },
				{ _ICODE_NUMERIC, -1, -1 },
				{ -1, -1, -1 },
				{ -1, -1, -1 },
				{ -1, -1, -1 }
			}
		},

		{ // jmp -99
			_JMP_NEGATIVE_99,
			{
				{ _ICODE_JMP, -1, -1 },
				{ _ICODE_HYPHEN, -1, -1 },
				{ _ICODE_NUMERIC, -1, -1 },
				{ -1, -1, -1 },
				{ -1, -1, -1 },
				{ -1, -1, -1 }
			}
		},

		{ // .org 99
			_ORG_99,
			{
				{ _ICODE_ORG, -1, -1 },
				{ _ICODE_NUMERIC, -1, -1 },
				{ -1, -1, -1 },
				{ -1, -1, -1 },
				{ -1, -1, -1 },
				{ -1, -1, -1 }
			}
		},

		{ // db dup
			_DB_DUP,
			{
				{ _ICODE_DB, -1, -1 },
				{ _ICODE_NUMERIC, -1, -1 },
				{ _ICODE_DUP, -1, -1 },
				{ _ICODE_NUMERIC, -1, -1 },
				{ -1, -1, -1 },
				{ -1, -1, -1 }
			}
		},

		{ // End marker
			-1,
			{
				{ -1, -1, -1 },
				{ -1, -1, -1 },
				{ -1, -1, -1 },
				{ -1, -1, -1 },
				{ -1, -1, -1 },
				{ -1, -1, -1 }
			}
		}
	};
	void iCompileSourceCodeLine(SLine* line, s32* tnErrors, s32* tnWarnings)
	{
		s32			lnI;
		bool		llFailure;
		SOra		iora;
		SOrr		iorr;
		SBsa		ibsa;
		SCommand*	cmd;
		SComp*		comp[6];


		//////////
		// Grab as many components as there are
		//////
			// Reset to NULLs
			for (lnI = 0; lnI < 6; lnI++)
				comp[lnI] = NULL;

			// Load whatever's possible
			if ((comp[0] = line->compilerInfo->firstComp) && (comp[1] = (SComp*)comp[0]->ll.next) && (comp[2] = (SComp*)comp[1]->ll.next) && (comp[3] = (SComp*)comp[2]->ll.next) && (comp[4] = (SComp*)comp[3]->ll.next) && (comp[5] = (SComp*)comp[4]->ll.next))
			{
				// Placeholder, just used to load as many as are available up to five
			}


		//////////
		// Make sure we have something to do
		//////
			if (comp[1] && comp[1]->iCode != _ICODE_COMMENT)
			{
				// Populate as many components as follow
				for (cmd = (SCommand*)&gsCommands[0]; cmd && cmd->cmdType != -1; cmd++)
				{
					// Iterate for any matching components
					for (lnI = 0, llFailure = false; lnI < 6; lnI++)
					{
						// Is this line valid?
						if (cmd->comp[lnI].iCode == -1 && cmd->comp[lnI].iCode2 == -1 && cmd->comp[lnI].iCat == -1)
						{
							// Nothing on this line

						} else {
							// This line has something, does it match up?
							if (		(cmd->comp[lnI].iCode	== -1 || cmd->comp[lnI].iCode	== comp[lnI]->iCode)
									&&	(cmd->comp[lnI].iCode2	== -1 || cmd->comp[lnI].iCode2	== comp[lnI]->iCode)
									&&	(cmd->comp[lnI].iCat	== -1 || cmd->comp[lnI].iCat	== comp[lnI]->iCode)	)
							{
								// A full match
								// No code, just capture the block without awkward logic above

							} else {
								llFailure = true;
								break;
							}
						}
					}

					// When we get here, we either have a match or a failure
					if (!llFailure)
					{
						// A match
						switch (cmd->cmdType)
						{
							case _MOV_REG_REG:
							case _ADD_REG_REG:
							case _ADC_REG_REG:
							case _SUB_REG_REG:
							case _SBB_REG_REG:
							case _CMP_REG_REG:
								break;

							case _MOV_REG_LABEL:
								break;

							case _MOV_LABEL_REG:
								break;

							case _MOV_REG_99:
								break;

							case _MOV_99_REG:
								break;

							case _JNC_LABEL:
							case _JC_LABEL:
							case _JNZ_LABEL:
							case _JZ_LABEL:
							case _JMP_LABEL:
								break;

							case _JNC_PLUS_99:
							case _JC_PLUS_99:
							case _JNZ_PLUS_99:
							case _JZ_PLUS_99:
							case _JMP_PLUS_99:
								break;

							case _JNC_NEGATIVE_99:
							case _JC_NEGATIVE_99:
							case _JNZ_NEGATIVE_99:
							case _JZ_NEGATIVE_99:
							case _JMP_NEGATIVE_99:
								break;

							case _ORG_99:
								break;

							case _DB_DUP:
								break;

							default:
								// Should never happen
								// Internal consistency error
_asm int 3;
						}
					}
				}
			}
	}
