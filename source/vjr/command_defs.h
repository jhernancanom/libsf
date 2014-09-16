//////////
//
// /libsf/source/vjr/command_defs.h
//
//////
// Version 0.53
// Copyright (c) 2014 by Rick C. Hodgin
//////
// Last update:
//     Jul.05.2014
//////
// Change log:
//     Jul.05.2014 - Initial creation
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
//     http://www.visual-freepro.org/wiki/index.php/Repeat_License
//
// Thank you.  And may The Lord bless you richly as you lift up your life, your
// talents, your gifts, your praise, unto Him.  In Jesus' name I pray.  Amen.
//
//////
// Steps to add a new function:
//		(1)  STEP1:  Add the function definition to the "Functions" section below (search for "STEP1:").
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
	void				iError_report								(cs8* constantErrorText);
	void				iError_report								(s8* errorText);
	void				iError_reportByNumber						(u32 tnErrorNum, SComp* comp);


//////////
// Functions
// STEP1: Define your function
//////
	SVariable*			function_alltrim							(SVariable* pString, SVariable* pCaseInsensitive, SVariable* pTrimChars1, SVariable* pTrimChars2);
	SVariable*			ifunction_trimCommon						(SVariable* pString, SVariable* pCaseInsensitive, SVariable* pTrimChars1, SVariable* pTrimChars2, bool trimStart, bool trimEnd);
	SVariable*			function_asc								(SVariable* p1);
	SVariable*			function_at									(SVariable* pNeedle, SVariable* pHaystack, SVariable* pOccurrence);
	SVariable*			function_atc								(SVariable* pNeedle, SVariable* pHaystack, SVariable* pOccurrence);
	SVariable*			ifunction_atOccursCommon					(SVariable* pNeedle, SVariable* pHaystack, SVariable* pOccurrence, bool tlCaseSensitive, bool tlScanBackward, u32* tnFoundCount);
	SVariable*			function_chr								(SVariable* p1);
	SVariable*			function_chrtran							(SVariable* pString, SVariable* pSearch, SVariable* pReplace);
	SVariable*			function_chrtranc							(SVariable* pString, SVariable* pSearch, SVariable* pReplace);
	SVariable*			ifunction_chrtranCommon						(SVariable* pString, SVariable* pSearch, SVariable* pReplace, bool tlCaseSensitive);
	SVariable*			function_createobject						(SVariable* p1);
	SVariable*			function_datetime							(SVariable* pYear, SVariable* pMonth, SVariable* pDay, SVariable* pHour, SVariable* pMinute, SVariable* pSecond, SVariable* pMillisecond);
	SVariable*			function_int								(SVariable* p1);
	SVariable*			function_left								(SVariable* pString, SVariable* pCount);
	SVariable*			function_len								(SVariable* pString);
	SVariable*			function_lower								(SVariable* pString);
	SVariable*			function_ltrim								(SVariable* pString, SVariable* pCaseInsensitive, SVariable* pTrimChars1, SVariable* pTrimChars2);
	SVariable*			function_max								(SVariable* pLeft, SVariable* pRight);
	SVariable*			function_min								(SVariable* pLeft, SVariable* pRight);
	SVariable*			function_occurs								(SVariable* pNeedle, SVariable* pHaystack);
	SVariable*			function_occursc							(SVariable* pNeedle, SVariable* pHaystack);
	SVariable*			function_padc								(SVariable* pExpression, SVariable* pResultSize, SVariable* pPadCharacter);
	SVariable*			function_padl								(SVariable* pExpression, SVariable* pResultSize, SVariable* pPadCharacter);
	SVariable*			function_padr								(SVariable* pExpression, SVariable* pResultSize, SVariable* pPadCharacter);
	SVariable*			ifunction_padCommon							(SVariable* pExpression, SVariable* pResultSize, SVariable* pPadCharacter, bool tlPadLeft, bool tlPadRight);
	SVariable*			function_proper								(SVariable* pString);
	SVariable*			function_rat								(SVariable* pNeedle, SVariable* pHaystack, SVariable* pOccurrence);
	SVariable*			function_ratc								(SVariable* pNeedle, SVariable* pHaystack, SVariable* pOccurrence);
	SVariable*			function_replicate							(SVariable* pString, SVariable* pCount);
	SVariable*			function_rgb								(SVariable* pRed, SVariable* pGrn, SVariable* pBlu);
	SVariable*			function_rgba								(SVariable* pRed, SVariable* pGrn, SVariable* pBlu, SVariable* pAlp);
	SVariable*			function_right								(SVariable* pString, SVariable* pCount);
	SVariable*			function_rtrim								(SVariable* pString, SVariable* pCaseInsensitive, SVariable* pTrimChars1, SVariable* pTrimChars2);
	SVariable*			function_space								(SVariable* pCount);
	SVariable*			function_strtran							(SVariable* pString, SVariable* pSearch, SVariable* pReplace, SVariable* pRecursiveCount);
	SVariable*			function_strtranc							(SVariable* pString, SVariable* pSearch, SVariable* pReplace, SVariable* pRecursiveCount);
	SVariable*			ifunction_strtranCommon						(SVariable* pString, SVariable* pSearch, SVariable* pReplace, SVariable* pRecursiveCount, bool tlCaseSensitive);
	SVariable*			function_stuff								(SVariable* pOriginalString, SVariable* pStartPos, SVariable* pNumToRemove, SVariable* pStuffString);
	SVariable*			function_sysmetric							(SVariable* pIndex);
	SVariable*			function_transform							(SVariable* pVariable, SVariable* pFormat);
	SVariable*			function_upper								(SVariable* pString);
	SVariable*			function_version							(SVariable* pIndex);
// Added temporarily until the processing engine is coded
	SVariable*			function_concatenate						(SVariable* p1, SVariable* p2);
	SVariable*			function_add								(SVariable* p1, SVariable* p2);
	SVariable*			function_sub								(SVariable* p1, SVariable* p2);
	SVariable*			function_mul								(SVariable* p1, SVariable* p2);
	SVariable*			function_div								(SVariable* p1, SVariable* p2);
	// transform (partial support, only converts to character, does not do any formatting ... yet)
//////
// STEP3: Copy the code above near one of the other functions in commands.cpp.
//        You may be able to right-click on one of the functions and choose "go to definition".
//////////




	struct SSourceLightData
	{
		u32			key;									// Refer to _SOURCELIGHT_* constants

		// Data, varies based on _SOURCELIGHT_* constants
		u32			data1;
		u32			data2;
		u32			data3;
		u32			data4;
		u32			data5;
	};

	const u32	_SOURCELIGHT_P1								= 1;
	const u32	_SOURCELIGHT_P2								= 2;
	const u32	_SOURCELIGHT_P3								= 3;
	const u32	_SOURCELIGHT_P4								= 4;
	const u32	_SOURCELIGHT_P5								= 5;
	const u32	_SOURCELIGHT_P6								= 6;
	const u32	_SOURCELIGHT_P7								= 7;
	const u32	_SOURCELIGHT_P8								= 8;
	const u32	_SOURCELIGHT_P9								= 9;
	const u32	_SOURCELIGHT_P10							= 10;
	const u32	_SOURCELIGHT_P11							= 11;
	const u32	_SOURCELIGHT_P12							= 12;
	const u32	_SOURCELIGHT_P13							= 13;
	const u32	_SOURCELIGHT_P14							= 14;
	const u32	_SOURCELIGHT_P15							= 15;
	const u32	_SOURCELIGHT_P16							= 16;
	const u32	_SOURCELIGHT_P17							= 17;
	const u32	_SOURCELIGHT_P18							= 18;
	const u32	_SOURCELIGHT_P19							= 19;
	const u32	_SOURCELIGHT_P20							= 20;

	const u32	_SOURCELIGHT_P1_OPTIONAL					= 101;
	const u32	_SOURCELIGHT_P2_OPTIONAL					= 102;
	const u32	_SOURCELIGHT_P3_OPTIONAL					= 103;
	const u32	_SOURCELIGHT_P4_OPTIONAL					= 104;
	const u32	_SOURCELIGHT_P5_OPTIONAL					= 105;
	const u32	_SOURCELIGHT_P6_OPTIONAL					= 106;
	const u32	_SOURCELIGHT_P7_OPTIONAL					= 107;
	const u32	_SOURCELIGHT_P8_OPTIONAL					= 108;
	const u32	_SOURCELIGHT_P9_OPTIONAL					= 109;
	const u32	_SOURCELIGHT_P10_OPTIONAL					= 110;
	const u32	_SOURCELIGHT_P11_OPTIONAL					= 111;
	const u32	_SOURCELIGHT_P12_OPTIONAL					= 112;
	const u32	_SOURCELIGHT_P13_OPTIONAL					= 113;
	const u32	_SOURCELIGHT_P14_OPTIONAL					= 114;
	const u32	_SOURCELIGHT_P15_OPTIONAL					= 115;
	const u32	_SOURCELIGHT_P16_OPTIONAL					= 116;
	const u32	_SOURCELIGHT_P17_OPTIONAL					= 117;
	const u32	_SOURCELIGHT_P18_OPTIONAL					= 118;
	const u32	_SOURCELIGHT_P19_OPTIONAL					= 119;
	const u32	_SOURCELIGHT_P20_OPTIONAL					= 120;

	const u32	_SOURCELIGHT_P1_REQUIRED					= 201;
	const u32	_SOURCELIGHT_P2_REQUIRED					= 202;
	const u32	_SOURCELIGHT_P3_REQUIRED					= 203;
	const u32	_SOURCELIGHT_P4_REQUIRED					= 204;
	const u32	_SOURCELIGHT_P5_REQUIRED					= 205;
	const u32	_SOURCELIGHT_P6_REQUIRED					= 206;
	const u32	_SOURCELIGHT_P7_REQUIRED					= 207;
	const u32	_SOURCELIGHT_P8_REQUIRED					= 208;
	const u32	_SOURCELIGHT_P9_REQUIRED					= 209;
	const u32	_SOURCELIGHT_P10_REQUIRED					= 210;
	const u32	_SOURCELIGHT_P11_REQUIRED					= 211;
	const u32	_SOURCELIGHT_P12_REQUIRED					= 212;
	const u32	_SOURCELIGHT_P13_REQUIRED					= 213;
	const u32	_SOURCELIGHT_P14_REQUIRED					= 214;
	const u32	_SOURCELIGHT_P15_REQUIRED					= 215;
	const u32	_SOURCELIGHT_P16_REQUIRED					= 216;
	const u32	_SOURCELIGHT_P17_REQUIRED					= 217;
	const u32	_SOURCELIGHT_P18_REQUIRED					= 218;
	const u32	_SOURCELIGHT_P19_REQUIRED					= 219;
	const u32	_SOURCELIGHT_P20_REQUIRED					= 220;

	const u32	_SOURCELIGHT_R1								= 51;
	const u32	_SOURCELIGHT_R2								= 52;
	const u32	_SOURCELIGHT_R3								= 53;
	const u32	_SOURCELIGHT_R4								= 54;
	const u32	_SOURCELIGHT_R5								= 55;
	const u32	_SOURCELIGHT_R6								= 56;
	const u32	_SOURCELIGHT_R7								= 57;
	const u32	_SOURCELIGHT_R8								= 58;
	const u32	_SOURCELIGHT_R9								= 59;
	const u32	_SOURCELIGHT_R10							= 60;

	const u32	_SOURCELIGHT_FUNCTION_NAME					= 100;
	const u32	_SOURCELIGHT_FUNCTION_DESCRIPTION			= 101;

	const s8	cgc_date[]									= "Date";
	const s8	cgc_datetime[]								= "DateTime";
	const s8	cgc_numeric[]								= "Numeric";
	const s8	cgc_logical[]								= "Logical";
	const s8	cgc_character[]								= "Character";
	const s8	cgc_cString[]								= "cString";

	SSourceLightData gsSourceLight_alltrim[] =
	{
		// lcResult = ALLTRIM(cString, lIgnoreCase|nIgnoreCase, cTrimChars1, cTrimChars2)
		{	_SOURCELIGHT_FUNCTION_NAME,				0,	0,	0,	0,	0	},
		{	_SOURCELIGHT_FUNCTION_DESCRIPTION,		(u32)"Four parameter variation. Converts the input string to a form where the cTrimChars are removed off the left and right sides.", 0,	0, 0, 0 },
		{	_SOURCELIGHT_P1_REQUIRED,				(u32)&cgc_cString,			(u32)&cgc_character,	(u32)&"Input string",																	_VAR_TYPE_CHARACTER,	0	},
		{	_SOURCELIGHT_P2_OPTIONAL,				(u32)&"lIgnoreCase",		(u32)&cgc_logical,		(u32)&"Default = .T.. Should the cTrimChar variables ignore case?",						_VAR_TYPE_LOGICAL,		_LOGICAL_TRUE},
		{	_SOURCELIGHT_P2_OPTIONAL,				(u32)&"nIgnoreCase",		(u32)&cgc_numeric,		(u32)&"Default = 1. Should the cTrimChar variables ignore case? 0=no, others=yes.",		_VAR_TYPE_S32,			1	},
		{	_SOURCELIGHT_P3_OPTIONAL,				(u32)&"cTrimChars1",		(u32)&cgc_character,	(u32)&"String 1 containing characters to trim",											_VAR_TYPE_CHARACTER,	0	},
		{	_SOURCELIGHT_P4_OPTIONAL,				(u32)&"cTrimChars2",		(u32)&cgc_character,	(u32)&"String 2 containing characters to trim",											_VAR_TYPE_CHARACTER,	0	},
		{	_SOURCELIGHT_R1,						(u32)&"cResult",			(u32)&cgc_character,	(u32)&"Input string trimmed",															_VAR_TYPE_CHARACTER,	0	},
		// lcResult = ALLTRIM(cString, cTrimChars)
		{	_SOURCELIGHT_FUNCTION_NAME,				0,	0,	0,	0,	0	},
		{	_SOURCELIGHT_FUNCTION_DESCRIPTION,		(u32)"Two parameter variation. Converts the input string to a form where the cTrimChars are removed off the left and right sides.",	0, 0, 0, 0 },
		{	_SOURCELIGHT_P1_REQUIRED,				(u32)&cgc_cString,			(u32)&cgc_character,	(u32)&"Input string",																	_VAR_TYPE_CHARACTER,	0	},
		{	_SOURCELIGHT_P2_OPTIONAL,				(u32)&"cTrimChars",			(u32)&cgc_character,	(u32)&"String containing characters to trim",											_VAR_TYPE_CHARACTER,	0	},
		{	_SOURCELIGHT_R1,						(u32)&"cResult",			(u32)&cgc_character,	(u32)&"Input string trimmed",															_VAR_TYPE_CHARACTER,	0	},
		{	0,										0,	0,	0,	0,	0	},
	};

	SSourceLightData gsSourceLight_asc[] =
	{
		{	0,										0,	0,	0,	0,	0	}
	};

	SSourceLightData gsSourceLight_at[] =
	{
		{	0,										0,	0,	0,	0,	0	}
	};

	SSourceLightData gsSourceLight_atc[] =
	{
		{	0,										0,	0,	0,	0,	0	}
	};

	SSourceLightData gsSourceLight_chr[] =
	{
		{	0,										0,	0,	0,	0,	0	}
	};

	SSourceLightData gsSourceLight_chrtran[] =
	{
		{	0,										0,	0,	0,	0,	0	}
	};

	SSourceLightData gsSourceLight_chrtranc[] =
	{
		{	0,										0,	0,	0,	0,	0	}
	};

	SSourceLightData gsSourceLight_createobject[] =
	{
		{	0,										0,	0,	0,	0,	0	}
	};

	SSourceLightData gsSourceLight_datetime[] =
	{
		{	0,										0,	0,	0,	0,	0	}
	};

	SSourceLightData gsSourceLight_int[] =
	{
		{	0,										0,	0,	0,	0,	0	}
	};

	SSourceLightData gsSourceLight_left[] =
	{
		{	0,										0,	0,	0,	0,	0	}
	};

	SSourceLightData gsSourceLight_len[] =
	{
		{	0,										0,	0,	0,	0,	0	}
	};

	SSourceLightData gsSourceLight_lower[] =
	{
		{	0,										0,	0,	0,	0,	0	}
	};

	SSourceLightData gsSourceLight_ltrim[] =
	{
		{	0,										0,	0,	0,	0,	0	}
	};

	SSourceLightData gsSourceLight_max[] =
	{
		{	0,										0,	0,	0,	0,	0	}
	};

	SSourceLightData gsSourceLight_min[] =
	{
		{	0,										0,	0,	0,	0,	0	}
	};

	SSourceLightData gsSourceLight_occurs[] =
	{
		{	0,										0,	0,	0,	0,	0	}
	};

	SSourceLightData gsSourceLight_occursc[] =
	{
		{	0,										0,	0,	0,	0,	0	}
	};

	SSourceLightData gsSourceLight_padc[] =
	{
		{	0,										0,	0,	0,	0,	0	}
	};

	SSourceLightData gsSourceLight_padl[] =
	{
		{	0,										0,	0,	0,	0,	0	}
	};

	SSourceLightData gsSourceLight_padr[] =
	{
		{	0,										0,	0,	0,	0,	0	}
	};

	SSourceLightData gsSourceLight_proper[] =
	{
		{	0,										0,	0,	0,	0,	0	}
	};

	SSourceLightData gsSourceLight_rat[] =
	{
		{	0,										0,	0,	0,	0,	0	}
	};

	SSourceLightData gsSourceLight_ratc[] =
	{
		{	0,										0,	0,	0,	0,	0	}
	};

	SSourceLightData gsSourceLight_replicate[] =
	{
		{	0,										0,	0,	0,	0,	0	}
	};

	SSourceLightData gsSourceLight_rgb[] =
	{
		{	0,										0,	0,	0,	0,	0	}
	};

	SSourceLightData gsSourceLight_rgba[] =
	{
		{	0,										0,	0,	0,	0,	0	}
	};

	SSourceLightData gsSourceLight_right[] =
	{
		{	0,										0,	0,	0,	0,	0	}
	};

	SSourceLightData gsSourceLight_rtrim[] =
	{
		{	0,										0,	0,	0,	0,	0	}
	};

	SSourceLightData gsSourceLight_space[] =
	{
		{	0,										0,	0,	0,	0,	0	}
	};

	SSourceLightData gsSourceLight_strtran[] =
	{
		{	0,										0,	0,	0,	0,	0	}
	};

	SSourceLightData gsSourceLight_strtranc[] =
	{
		{	0,										0,	0,	0,	0,	0	}
	};

	SSourceLightData gsSourceLight_stuff[] =
	{
		{	0,										0,	0,	0,	0,	0	}
	};

	SSourceLightData gsSourceLight_sysmetric[] =
	{
		{	0,										0,	0,	0,	0,	0	}
	};

	SSourceLightData gsSourceLight_transform[] =
	{
		{	0,										0,	0,	0,	0,	0	}
	};

	SSourceLightData gsSourceLight_trim[] =
	{
		{	0,										0,	0,	0,	0,	0	}
	};

	SSourceLightData gsSourceLight_upper[] =
	{
		{	0,										0,	0,	0,	0,	0	}
	};

	SSourceLightData gsSourceLight_version[] =
	{
		{	0,										0,	0,	0,	0,	0	}
	};

	SSourceLightData gsSourceLight_concatenate[] =
	{
		{	0,										0,	0,	0,	0,	0	}
	};

	SSourceLightData gsSourceLight_add[] =
	{
		{	0,										0,	0,	0,	0,	0	}
	};

	SSourceLightData gsSourceLight_sub[] =
	{
		{	0,										0,	0,	0,	0,	0	}
	};

	SSourceLightData gsSourceLight_mul[] =
	{
		{	0,										0,	0,	0,	0,	0	}
	};

	SSourceLightData gsSourceLight_div[] =
	{
		{	0,										0,	0,	0,	0,	0	}
	};




//////////
// Translation between iCodes and function definitions.
//////
	struct SFunctionData
	{
		//////////
		// The iCode relates to the known commands.
		// See cgcFundamentalSymbols and cgcKeywordKeywords in compiler_globals.h
		//////
			s32		iCode;


		//////////
		// Return variables this function generates
		//////
			s32		returnCount;


		//////////
		// Function prototype to call internally
		//////
			union {
				u32			_func;
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

	SFunctionData gsKnownFunctions[] = {
		//							Return										Parameters		Parameter
		//	iCode					Count		Function						Required		Maximum Count	SourceLight data
		//  ------------------		------		--------------------------		----------		-------------	-----------------------------
		{	_ICODE_ALLTRIM,			1,			(u32)&function_alltrim,			1,				4,				&gsSourceLight_alltrim[0]		},
		{	_ICODE_ASC,				1,			(u32)&function_asc,				1,				1,				&gsSourceLight_asc[0]			},
		{	_ICODE_AT,				1,			(u32)&function_at,				2,				3,				&gsSourceLight_at[0]			},
		{	_ICODE_ATC,				1,			(u32)&function_atc,				2,				3,				&gsSourceLight_atc[0]			},
		{	_ICODE_CHR,				1,			(u32)&function_chr,				1,				1,				&gsSourceLight_chr[0]			},
		{	_ICODE_CHRTRAN,			1,			(u32)&function_chrtran,			2,				3,				&gsSourceLight_chrtran[0]		},
		{	_ICODE_CHRTRANC,		1,			(u32)&function_chrtranc,		2,				3,				&gsSourceLight_chrtranc[0]		},
		{	_ICODE_CREATEOBJECT,	1,			(u32)&function_createobject,	1,				1,				&gsSourceLight_createobject[0]	},
		{	_ICODE_DATETIME,		1,			(u32)&function_datetime,		0,				7,				&gsSourceLight_datetime[0]		},
		{	_ICODE_INT,				1,			(u32)&function_int,				1,				1,				&gsSourceLight_int[0]			},
		{	_ICODE_LEFT,			1,			(u32)&function_left,			2,				2,				&gsSourceLight_left[0]			},
		{	_ICODE_LEN,				1,			(u32)&function_len,				1,				1,				&gsSourceLight_len[0]			},
		{	_ICODE_LOWER,			1,			(u32)&function_lower,			1,				1,				&gsSourceLight_lower[0]			},
		{	_ICODE_LTRIM,			1,			(u32)&function_ltrim,			1,				1,				&gsSourceLight_ltrim[0]			},
		{	_ICODE_MAX,				1,			(u32)&function_max,				2,				2,				&gsSourceLight_max[0]			},
		{	_ICODE_MIN,				1,			(u32)&function_min,				2,				2,				&gsSourceLight_min[0]			},
		{	_ICODE_OCCURS,			1,			(u32)&function_occurs,			2,				2,				&gsSourceLight_occurs[0]		},
		{	_ICODE_OCCURSC,			1,			(u32)&function_occursc,			2,				2,				&gsSourceLight_occursc[0]		},
		{	_ICODE_PADC,			1,			(u32)&function_padc,			2,				3,				&gsSourceLight_padc[0]			},
		{	_ICODE_PADL,			1,			(u32)&function_padl,			2,				3,				&gsSourceLight_padl[0]			},
		{	_ICODE_PADR,			1,			(u32)&function_padr,			2,				3,				&gsSourceLight_padr[0]			},
		{	_ICODE_PROPER,			1,			(u32)&function_proper,			1,				1,				&gsSourceLight_proper[0]		},
		{	_ICODE_RAT,				1,			(u32)&function_rat,				2,				3,				&gsSourceLight_rat[0]			},
		{	_ICODE_RATC,			1,			(u32)&function_ratc,			2,				3,				&gsSourceLight_ratc[0]			},
		{	_ICODE_REPLICATE,		1,			(u32)&function_replicate,		2,				2,				&gsSourceLight_replicate[0]		},
		{	_ICODE_RGB,				1,			(u32)&function_rgb,				3,				3,				&gsSourceLight_rgb[0]			},
		{	_ICODE_RGBA,			1,			(u32)&function_rgba,			4,				4,				&gsSourceLight_rgba[0]			},
		{	_ICODE_RIGHT,			1,			(u32)&function_right,			2,				2,				&gsSourceLight_right[0]			},
		{	_ICODE_RTRIM,			1,			(u32)&function_rtrim,			1,				1,				&gsSourceLight_rtrim[0]			},
		{	_ICODE_SPACE,			1,			(u32)&function_space,			1,				1,				&gsSourceLight_space[0]			},
		{	_ICODE_STRTRAN,			1,			(u32)&function_strtran,			2,				4,				&gsSourceLight_strtran[0]		},
		{	_ICODE_STRTRANC,		1,			(u32)&function_strtranc,		2,				4,				&gsSourceLight_strtranc[0]		},
		{	_ICODE_STUFF,			1,			(u32)&function_stuff,			3,				4,				&gsSourceLight_stuff[0]			},
		{	_ICODE_SYSMETRIC,		1,			(u32)&function_sysmetric,		1,				1,				&gsSourceLight_sysmetric[0]		},
		{	_ICODE_TRANSFORM,		1,			(u32)&function_transform,		1,				2,				&gsSourceLight_transform[0]		},
		{	_ICODE_TRIM,			1,			(u32)&function_rtrim,			1,				1,				&gsSourceLight_rtrim[0]			},
		{	_ICODE_UPPER,			1,			(u32)&function_upper,			1,				1,				&gsSourceLight_upper[0]			},
		{	_ICODE_VERSION,			1,			(u32)&function_version,			0,				1,				&gsSourceLight_version[0]		},
// Added temporarily until the processing engine is coded
		{	_ICODE_CONCATENATE,		1,			(u32)&function_concatenate,		2,				2,				&gsSourceLight_concatenate[0]	},
		{	_ICODE_ADD,				1,			(u32)&function_add,				2,				2,				&gsSourceLight_add[0]			},
		{	_ICODE_SUB,				1,			(u32)&function_sub,				2,				2,				&gsSourceLight_sub[0]			},
		{	_ICODE_MUL,				1,			(u32)&function_mul,				2,				2,				&gsSourceLight_mul[0]			},
		{	_ICODE_DIV,				1,			(u32)&function_div,				2,				2,				&gsSourceLight_div[0]			},
	//////
	// Insert above this step somewhere in the list of functions.
	// STEP2:
	//////////
		// Note:  Do not delete this line, it is used to terminate the search list
		{	0,						0,					0,						0,				0,				NULL	}
	};
