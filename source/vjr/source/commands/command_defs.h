//////////
//
// /libsf/source/vjr/commands/command_defs.h
//
//////
//    _     _ _     _____ _____ 
//   | |   (_) |__ / ____|  ___|
//   | |   | | '_ \\___ \|  __|
//   | |___| | |_) |___) | |
//   |_____|_|_.__/_____/|_|
//
//   Liberty Software Foundation
// and the Village Freedom Project
//   __     _______     ____  
//   \ \   / /  ___| __|  _ \ 
//    \ \ / /| |_ | '__| |_) |
//     \ V / |  _|| |  |  __/ 
//      \_/  |_|  |_|  |_|
//
//////
// Version 0.54
// Copyright (c) 2014 by Rick C. Hodgin
//////
// Last update:
//     Jul.05.2014
//////
// Change log:
//     Jul.05.2014 - Initial creation
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
//////
// Steps to add a new function:
//		(1a) STEP1A:  Add the function definition to the "Functions" section below (search for "STEP1A:").
//		(1b) STEP1B:  Add the command definition to the "Commands" section below (search for "STEP1B:").
//		(2)  STEP2:  Add the function information to the "Translation" gsKnownFunctions data by inserting it where it should go (search for "STEP2:").
//		(3)  STEP3:  Add the function to commands.cpp (search for "STEP3").
//		(4)  Code, debug, and test the function thoroughly.
//		(5)  Email your changes to Rick C. Hodgin at the address on the www.visual-freepro.org/vjr/indexmain.html web page.
//		(6)  Happy coding!
//
//




struct SVariable;

#define get_s64(a)		(*a->value.data_s64)
#define get_u64(a)		(*a->value.data_u64)
#define get_s32(a)		(*a->value.data_s32)
#define get_u32(a)		(*a->value.data_u32)
#define get_s16(a)		(*a->value.data_s16)
#define get_u16(a)		(*a->value.data_u16)
#define get_s8(a)		(*a->value.data_s8)
#define get_u8(a)		(*a->value.data_u8)
#define get_f32(a)		(*a->value.data_f32)
#define get_f64(a)		(*a->value.data_f64)
#define get_bool(a)		(*a->value.data_u8 != 0)
#define get_bgra(a)		(*a->value.data_bgra)
#define get_bgr(a)		(*a->value.data_bgr)




//////////
// commands.cpp
// Note:  This source file contains both commands and functions.  Each will be
//        given by its name, such as "function_chr()" being a function.
//////
	// Temporary error reporting until the proper engine is constructed.
	void				iError_signal								(u32 tnErrorNum, s8* tcExtraInfo);
	void				iError_report								(cu8* constantErrorText, bool tlInvasive);
	void				iError_report								(u8* errorText, bool tlInvasive);
	void				iError_reportByNumber						(u32 tnErrorNum, SComp* comp, bool tlInvasive);




//////////
//
// SourceLight
//
//////
	struct SSourceLightData
	{
		u32			key;									// Refer to _SOURCELIGHT_* constants

		// Data, varies based on _SOURCELIGHT_* constants
		uptr		data1;
		uptr		data2;
		uptr		data3;
		uptr		data4;
		uptr		data5;
	};

	#include "command_sourcelight.h"




//////////
//
// Functions
// STEP1A: Define your function
//
//////
	SVariable*			function_addbs								(SVariable* varString);
	SVariable*			function_alltrim							(SVariable* varString, SVariable* varCaseInsensitive, SVariable* varTrimChars1, SVariable* varTrimChars2);
	SVariable*			ifunction_trimCommon						(SVariable* varString, SVariable* varCaseInsensitive, SVariable* varTrimChars1, SVariable* varTrimChars2, bool trimStart, bool trimEnd);
	SVariable*			function_asc								(SVariable* varString);
	SVariable*			function_at									(SVariable* varNeedle, SVariable* varHaystack, SVariable* varOccurrence);
	SVariable*			function_atc								(SVariable* varNeedle, SVariable* varHaystack, SVariable* varOccurrence);
	SVariable*			ifunction_atOccursCommon					(SVariable* varNeedle, SVariable* varHaystack, SVariable* varOccurrence, bool tlCaseSensitive, bool tlScanBackward, u32* tnFoundCount);
	SVariable*			function_chr								(SVariable* varNumber);
	SVariable*			function_chrtran							(SVariable* varString, SVariable* varSearch, SVariable* varReplace);
	SVariable*			function_chrtranc							(SVariable* varString, SVariable* varSearch, SVariable* varReplace);
	SVariable*			ifunction_chrtranCommon						(SVariable* varString, SVariable* varSearch, SVariable* varReplace, bool tlCaseSensitive);
	SVariable*			function_createobject						(SVariable* varClass);
	SVariable*			function_curdir								(void);
	SVariable*			function_datetime							(SVariable* varYear, SVariable* varMonth, SVariable* varDay, SVariable* varHour, SVariable* varMinute, SVariable* varSecond, SVariable* varMillisecond);
	SVariable*			function_int								(SVariable* varNumber);
	SVariable*			function_justdrive							(SVariable* varString);
	SVariable*			function_justext							(SVariable* varString);
	SVariable*			function_justfname							(SVariable* varString);
	SVariable*			function_justpath							(SVariable* varString);
	SVariable*			function_juststem							(SVariable* varString, SVariable* varPostfixWidth);
	SVariable*			function_left								(SVariable* varString, SVariable* varCount);
	SVariable*			function_len								(SVariable* varString);
	SVariable*			function_lower								(SVariable* varString);
	SVariable*			function_ltrim								(SVariable* varString, SVariable* varCaseInsensitive, SVariable* varTrimChars1, SVariable* varTrimChars2);
	SVariable*			function_max								(SVariable* varLeft, SVariable* varRight);
	SVariable*			function_min								(SVariable* varLeft, SVariable* varRight);
	SVariable*			function_mod								(SVariable* varDividend, SVariable* varDivisor);
	SVariable*			function_occurs								(SVariable* varNeedle, SVariable* varHaystack);
	SVariable*			function_occursc							(SVariable* varNeedle, SVariable* varHaystack);
	SVariable*			function_padc								(SVariable* varExpression, SVariable* varResultSize, SVariable* varPadCharacter);
	SVariable*			function_padl								(SVariable* varExpression, SVariable* varResultSize, SVariable* varPadCharacter);
	SVariable*			function_padr								(SVariable* varExpression, SVariable* varResultSize, SVariable* varPadCharacter);
	SVariable*			ifunction_padCommon							(SVariable* varExpression, SVariable* varResultSize, SVariable* varPadCharacter, bool tlPadLeft, bool tlPadRight);
	SVariable*			function_proper								(SVariable* varString);
	SVariable*			function_rat								(SVariable* varNeedle, SVariable* varHaystack, SVariable* varOccurrence);
	SVariable*			function_ratc								(SVariable* varNeedle, SVariable* varHaystack, SVariable* varOccurrence);
	SVariable*			function_replicate							(SVariable* varString, SVariable* varCount);
	SVariable*			function_rgb								(SVariable* varRed, SVariable* varGrn, SVariable* varBlu);
	SVariable*			function_rgba								(SVariable* varRed, SVariable* varGrn, SVariable* varBlu, SVariable* varAlp);
	SVariable*			function_right								(SVariable* varString, SVariable* varCount);
	SVariable*			function_rtrim								(SVariable* varString, SVariable* varCaseInsensitive, SVariable* varTrimChars1, SVariable* varTrimChars2);
	SVariable*			function_space								(SVariable* varCount);
	SVariable*			function_strtran							(SVariable* varString, SVariable* varSearch, SVariable* varReplace, SVariable* varRecursiveCount);
	SVariable*			function_strtranc							(SVariable* varString, SVariable* varSearch, SVariable* varReplace, SVariable* varRecursiveCount);
	SVariable*			ifunction_strtranCommon						(SVariable* varString, SVariable* varSearch, SVariable* varReplace, SVariable* varRecursiveCount, bool tlCaseSensitive);
	SVariable*			function_stuff								(SVariable* varOriginalString, SVariable* varStartPos, SVariable* varNumToRemove, SVariable* varStuffString);
	SVariable*			function_sys								(SVariable* varIndex, SVariable* varP1, SVariable* varP2, SVariable* varP3, SVariable* varP4, SVariable* varP5, SVariable* varP6);
	SVariable*			iFunction_sys2015							(u32 tnPrefixWidth, u32 tnPostfixWidth);
	SVariable*			function_sysmetric							(SVariable* varIndex);
	SVariable*			function_transform							(SVariable* varVariable, SVariable* varFormat);
	SVariable*			function_upper								(SVariable* varString);
	SVariable*			function_version							(SVariable* varIndex);
// Added temporarily until the processing engine is coded
	SVariable*			function_concatenate						(SVariable* varString1, SVariable* varString2);
	SVariable*			function_add								(SVariable* varNum1, SVariable* varNum2);
	SVariable*			function_sub								(SVariable* varNum1, SVariable* varNum2);
	SVariable*			function_mul								(SVariable* varNum1, SVariable* varNum2);
	SVariable*			function_div								(SVariable* varNum1, SVariable* varNum2);
	// transform (partial support, only converts to character, does not do any formatting ... yet)
//////
// STEP3: Copy the code above near one of the other functions in commands.cpp.
//        You may be able to right-click on one of the functions and choose "go to definition".
//////////




//////////
//
// Commands
// STEP1B: Define your command
//
//////
	void				command_modify								(SComp* compModify);
	void				command_open								(SComp* compOpen);
	void				command_use									(SComp* compUse);




//////////
// Translation between iCodes and function definitions.
//////
	struct SFunctionData
	{
		//////////
		// The iCode relates to the known functions.
		// See cgcFundamentalSymbols and cgcKeywordKeywords in compiler_globals.h
		//////
			s32		iCode;


		//////////
		// Return variables this function generates
		//////
			s32		returnCount;


		//////////
		// Function prototypes to call internally
		//////
			union {
				uptr		_func;
				SVariable*	(*func_0p)		(void);
				SVariable*	(*func_1p)		(SVariable* p1);
				SVariable*	(*func_2p)		(SVariable* p1, SVariable* p2);
				SVariable*	(*func_3p)		(SVariable* p1, SVariable* p2, SVariable* p3);
				SVariable*	(*func_4p)		(SVariable* p1, SVariable* p2, SVariable* p3, SVariable* p4);
				SVariable*	(*func_5p)		(SVariable* p1, SVariable* p2, SVariable* p3, SVariable* p4, SVariable* p5);
				SVariable*	(*func_6p)		(SVariable* p1, SVariable* p2, SVariable* p3, SVariable* p4, SVariable* p5, SVariable* p6);
				SVariable*	(*func_7p)		(SVariable* p1, SVariable* p2, SVariable* p3, SVariable* p4, SVariable* p5, SVariable* p6, SVariable* p7);
			};


		//////////
		// Input parameters this function handles
		//////
			s32		requiredCount;
			s32		parameterCount;


		//////////
		// SourceLight information
		//////
			SSourceLightData*	data;
	};

// TODO:  Need to add a compile-time test to verify that the maximum parameter count is representative of the function definition's actual parameters because the function is referenced through the union struct above in SFunctionData
	SFunctionData gsKnownFunctions[] = {
		//							Return										Parameters		Parameter
		//	iCode					Count		Function Algorithm				Required		Maximum Count	SourceLight data
		//  ------------------		------		--------------------------		----------		-------------	----------------------------------
		{	_ICODE_ADDBS,			1,			(uptr)&function_addbs,			1,				4,				&gsSourceLight_alltrim[0]		},
		{	_ICODE_ALLTRIM,			1,			(uptr)&function_alltrim,		1,				4,				&gsSourceLight_alltrim[0]		},
		{	_ICODE_ASC,				1,			(uptr)&function_asc,			1,				1,				&gsSourceLight_asc[0]			},
		{	_ICODE_AT,				1,			(uptr)&function_at,				2,				3,				&gsSourceLight_at[0]			},
		{	_ICODE_ATC,				1,			(uptr)&function_atc,			2,				3,				&gsSourceLight_atc[0]			},
		{	_ICODE_CHR,				1,			(uptr)&function_chr,			1,				1,				&gsSourceLight_chr[0]			},
		{	_ICODE_CHRTRAN,			1,			(uptr)&function_chrtran,		2,				3,				&gsSourceLight_chrtran[0]		},
		{	_ICODE_CHRTRANC,		1,			(uptr)&function_chrtranc,		2,				3,				&gsSourceLight_chrtranc[0]		},
		{	_ICODE_CREATEOBJECT,	1,			(uptr)&function_createobject,	1,				1,				&gsSourceLight_createobject[0]	},
		{	_ICODE_CURDIR,			1,			(uptr)&function_curdir,			0,				0,				&gsSourceLight_curdir[0]		},
		{	_ICODE_DATETIME,		1,			(uptr)&function_datetime,		0,				7,				&gsSourceLight_datetime[0]		},
		{	_ICODE_INT,				1,			(uptr)&function_int,			1,				1,				&gsSourceLight_int[0]			},
		{	_ICODE_JUSTDRIVE,		1,			(uptr)&function_justdrive,		1,				1,				&gsSourceLight_justdrive[0]		},
		{	_ICODE_JUSTEXT,			1,			(uptr)&function_justext,		1,				1,				&gsSourceLight_justext[0]		},
		{	_ICODE_JUSTFNAME,		1,			(uptr)&function_justfname,		1,				1,				&gsSourceLight_justfname[0]		},
		{	_ICODE_JUSTPATH,		1,			(uptr)&function_justpath,		1,				1,				&gsSourceLight_justpath[0]		},
		{	_ICODE_JUSTSTEM,		1,			(uptr)&function_juststem,		1,				2,				&gsSourceLight_juststem[0]		},
		{	_ICODE_LEFT,			1,			(uptr)&function_left,			2,				2,				&gsSourceLight_left[0]			},
		{	_ICODE_LEN,				1,			(uptr)&function_len,			1,				1,				&gsSourceLight_len[0]			},
		{	_ICODE_LOWER,			1,			(uptr)&function_lower,			1,				1,				&gsSourceLight_lower[0]			},
		{	_ICODE_LTRIM,			1,			(uptr)&function_ltrim,			1,				1,				&gsSourceLight_ltrim[0]			},
		{	_ICODE_MAX,				1,			(uptr)&function_max,			2,				2,				&gsSourceLight_max[0]			},
		{	_ICODE_MIN,				1,			(uptr)&function_min,			2,				2,				&gsSourceLight_min[0]			},
		{	_ICODE_MOD,				1,			(uptr)&function_mod,			2,				2,				&gsSourceLight_mod[0]			},	// MOD() by Stefano D'Amico, VJr 0.56, Mar.08.2015
		{	_ICODE_OCCURS,			1,			(uptr)&function_occurs,			2,				2,				&gsSourceLight_occurs[0]		},
		{	_ICODE_OCCURSC,			1,			(uptr)&function_occursc,		2,				2,				&gsSourceLight_occursc[0]		},
		{	_ICODE_PADC,			1,			(uptr)&function_padc,			2,				3,				&gsSourceLight_padc[0]			},
		{	_ICODE_PADL,			1,			(uptr)&function_padl,			2,				3,				&gsSourceLight_padl[0]			},
		{	_ICODE_PADR,			1,			(uptr)&function_padr,			2,				3,				&gsSourceLight_padr[0]			},
		{	_ICODE_PROPER,			1,			(uptr)&function_proper,			1,				1,				&gsSourceLight_proper[0]		},
		{	_ICODE_RAT,				1,			(uptr)&function_rat,			2,				3,				&gsSourceLight_rat[0]			},
		{	_ICODE_RATC,			1,			(uptr)&function_ratc,			2,				3,				&gsSourceLight_ratc[0]			},
		{	_ICODE_REPLICATE,		1,			(uptr)&function_replicate,		2,				2,				&gsSourceLight_replicate[0]		},
		{	_ICODE_RGB,				1,			(uptr)&function_rgb,			3,				3,				&gsSourceLight_rgb[0]			},
		{	_ICODE_RGBA,			1,			(uptr)&function_rgba,			4,				4,				&gsSourceLight_rgba[0]			},
		{	_ICODE_RIGHT,			1,			(uptr)&function_right,			2,				2,				&gsSourceLight_right[0]			},
		{	_ICODE_RTRIM,			1,			(uptr)&function_rtrim,			1,				1,				&gsSourceLight_rtrim[0]			},
		{	_ICODE_SPACE,			1,			(uptr)&function_space,			1,				1,				&gsSourceLight_space[0]			},
		{	_ICODE_STRTRAN,			1,			(uptr)&function_strtran,		2,				4,				&gsSourceLight_strtran[0]		},
		{	_ICODE_STRTRANC,		1,			(uptr)&function_strtranc,		2,				4,				&gsSourceLight_strtranc[0]		},
		{	_ICODE_STUFF,			1,			(uptr)&function_stuff,			3,				4,				&gsSourceLight_stuff[0]			},
		{	_ICODE_SYS,				1,			(uptr)&function_sys,			1,				7,				&gsSourceLight_sys[0]			},
		{	_ICODE_SYSMETRIC,		1,			(uptr)&function_sysmetric,		1,				1,				&gsSourceLight_sysmetric[0]		},
		{	_ICODE_TRANSFORM,		1,			(uptr)&function_transform,		1,				2,				&gsSourceLight_transform[0]		},
		{	_ICODE_TRIM,			1,			(uptr)&function_rtrim,			1,				1,				&gsSourceLight_rtrim[0]			},
		{	_ICODE_UPPER,			1,			(uptr)&function_upper,			1,				1,				&gsSourceLight_upper[0]			},
		{	_ICODE_VERSION,			1,			(uptr)&function_version,		0,				1,				&gsSourceLight_version[0]		},
// Added temporarily until the processing engine is coded
		{	_ICODE_CONCATENATE,		1,			(uptr)&function_concatenate,	2,				2,				&gsSourceLight_concatenate[0]	},
		{	_ICODE_ADD,				1,			(uptr)&function_add,			2,				2,				&gsSourceLight_add[0]			},
		{	_ICODE_SUB,				1,			(uptr)&function_sub,			2,				2,				&gsSourceLight_sub[0]			},
		{	_ICODE_MUL,				1,			(uptr)&function_mul,			2,				2,				&gsSourceLight_mul[0]			},
		{	_ICODE_DIV,				1,			(uptr)&function_div,			2,				2,				&gsSourceLight_div[0]			},
	//////
	// Insert above this step somewhere in the list of functions.
	// STEP2:
	//////////
		// Note:  Do not delete this line, it is used to terminate the function list
		{	0,						0,					0,						0,				0,				NULL	}
	};




//////////
// Translation between iCodes and Command definitions.
//////
	struct SCommandData
	{
		//////////
		// The iCode relates to the known commands.
		// See cgcFundamentalSymbols and cgcKeywordKeywords in compiler_globals.h
		//////
			s32		iCode;


		//////////
		// Command prototype to call internally
		//////
			union {
				uptr		_command;
				void		(*command)		(SComp* comp);
			};


		//////////
		// SourceLight information
		//////
			SSourceLightData*	data;
	};

	SCommandData gsKnownCommands[] = {
		//	iCode					Command Algorithm
		//  ------------------		--------------------------
		{	_ICODE_MODIFY,			(uptr)&command_modify		},
		{	_ICODE_OPEN,			(uptr)&command_open			},
		{	_ICODE_USE,				(uptr)&command_use			},

		// Note:  Do not delete this line, it is used to terminate the command list
		{	0,						0							}
	};
