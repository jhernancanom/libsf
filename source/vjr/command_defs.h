//////////
//
// /libsf/source/vjr/command_defs.h
//
//////
// Version 0.43
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

#define get_s64(a)		*a->value.data_s64
#define get_u64(a)		*a->value.data_u64
#define get_s32(a)		*a->value.data_s32
#define get_u32(a)		*a->value.data_u32
#define get_s16(a)		*a->value.data_s16
#define get_u16(a)		*a->value.data_u16
#define get_s8(a)		*a->value.data
#define get_u8(a)		*a->value.udata


//////////
// commands.cpp
// Note:  This source file contains both commands and functions.  Each will be
//        given by its name, such as "function_chr()" being a function.
//////
	// Temporary error reporting until the proper engine is constructed.
	void				iError_report								(cs8* constantErrorText);
	void				iError_report								(s8* errorText);
	void				iiError_reportComp							(SComp* comp);
	void				iError_reportByNumber						(u32 tnErrorNum, SComp* comp);


//////////
// Functions
// STEP1: Define your function
//////
	SVariable*			function_alltrim							(SVariable* pString, SVariable* pCaseInsensitive, SVariable* pTrimChars1, SVariable* pTrimChars2);
	SVariable*			iFunction_trimCommon						(SVariable* pString, SVariable* pCaseInsensitive, SVariable* pTrimChars1, SVariable* pTrimChars2, bool trimStart, bool trimEnd);
	SVariable*			function_asc								(SVariable* p1);
	SVariable*			function_at									(SVariable* pNeedle, SVariable* pHaystack, SVariable* pOccurrence);
	SVariable*			function_atc								(SVariable* pNeedle, SVariable* pHaystack, SVariable* pOccurrence);
	SVariable*			iFunction_atOccursCommon					(SVariable* pNeedle, SVariable* pHaystack, SVariable* pOccurrence, bool tlCaseSensitive, bool tlScanBackward, u32* tnFoundCount);
	SVariable*			function_chr								(SVariable* p1);
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
	SVariable*			iFunction_padCommon							(SVariable* pExpression, SVariable* pResultSize, SVariable* pPadCharacter, bool tlPadLeft, bool tlPadRight);
	SVariable*			function_proper								(SVariable* pString);
	SVariable*			function_rat								(SVariable* pNeedle, SVariable* pHaystack, SVariable* pOccurrence);
	SVariable*			function_ratc								(SVariable* pNeedle, SVariable* pHaystack, SVariable* pOccurrence);
	SVariable*			function_replicate							(SVariable* pString, SVariable* pCount);
	SVariable*			function_rgb								(SVariable* pRed, SVariable* pGrn, SVariable* pBlu);
	SVariable*			function_rgba								(SVariable* pRed, SVariable* pGrn, SVariable* pBlu, SVariable* pAlp);
	SVariable*			function_right								(SVariable* pString, SVariable* pCount);
	SVariable*			function_rtrim								(SVariable* pString, SVariable* pCaseInsensitive, SVariable* pTrimChars1, SVariable* pTrimChars2);
	SVariable*			function_space								(SVariable* pCount);
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
	// strtran
	// chrtran
	// transform (partial support, only converts to character, does not do any formatting ... yet)
//////
// STEP3: Copy the code above near one of the other functions in commands.cpp.
//        You may be able to right-click on one of the functions and choose "go to definition".
//////////




//////////
// Translation between iCodes and function definitions.
//////
	struct SFunctionList
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
	};

	SFunctionList gsKnownFunctions[] = {
		//							Return										Parameters		Parameter
		//	iCode					Count		Function						Required		Maximum Count
		//  ------------------		------		--------------------------		----------		-------------
		{	_ICODE_ALLTRIM,			1,			(u32)&function_alltrim,			1,				4	},
		{	_ICODE_ASC,				1,			(u32)&function_asc,				1,				1	},
		{	_ICODE_AT,				1,			(u32)&function_at,				2,				3	},
		{	_ICODE_ATC,				1,			(u32)&function_atc,				2,				3	},
		{	_ICODE_CHR,				1,			(u32)&function_chr,				1,				1	},
		{	_ICODE_CREATEOBJECT,	1,			(u32)&function_createobject,	1,				1	},
		{	_ICODE_DATETIME,		1,			(u32)&function_datetime,		0,				7	},
		{	_ICODE_INT,				1,			(u32)&function_int,				1,				1	},
		{	_ICODE_LEFT,			1,			(u32)&function_left,			2,				2	},
		{	_ICODE_LEN,				1,			(u32)&function_len,				1,				1	},
		{	_ICODE_LOWER,			1,			(u32)&function_lower,			1,				1	},
		{	_ICODE_LTRIM,			1,			(u32)&function_ltrim,			1,				1	},
		{	_ICODE_MAX,				1,			(u32)&function_max,				2,				2	},
		{	_ICODE_MIN,				1,			(u32)&function_min,				2,				2	},
		{	_ICODE_OCCURS,			1,			(u32)&function_occurs,			2,				2	},
		{	_ICODE_OCCURSC,			1,			(u32)&function_occursc,			2,				2	},
		{	_ICODE_PADC,			1,			(u32)&function_padc,			2,				3	},
		{	_ICODE_PADL,			1,			(u32)&function_padl,			2,				3	},
		{	_ICODE_PADR,			1,			(u32)&function_padr,			2,				3	},
		{	_ICODE_PROPER,			1,			(u32)&function_proper,			1,				1	},
		{	_ICODE_RAT,				1,			(u32)&function_rat,				2,				3	},
		{	_ICODE_RATC,			1,			(u32)&function_ratc,			2,				3	},
		{	_ICODE_REPLICATE,		1,			(u32)&function_replicate,		2,				2	},
		{	_ICODE_RGB,				1,			(u32)&function_rgb,				3,				3	},
		{	_ICODE_RGBA,			1,			(u32)&function_rgba,			4,				4	},
		{	_ICODE_RIGHT,			1,			(u32)&function_right,			2,				2	},
		{	_ICODE_RTRIM,			1,			(u32)&function_rtrim,			1,				1	},
		{	_ICODE_SPACE,			1,			(u32)&function_space,			1,				1	},
		{	_ICODE_STUFF,			1,			(u32)&function_stuff,			3,				4	},
		{	_ICODE_SYSMETRIC,		1,			(u32)&function_sysmetric,		1,				1	},
		{	_ICODE_TRANSFORM,		1,			(u32)&function_transform,		1,				2	},
		{	_ICODE_TRIM,			1,			(u32)&function_rtrim,			1,				1	},
		{	_ICODE_UPPER,			1,			(u32)&function_upper,			1,				1	},
		{	_ICODE_VERSION,			1,			(u32)&function_version,			0,				1	},
// Added temporarily until the processing engine is coded
		{	_ICODE_CONCATENATE,		1,			(u32)&function_concatenate,		2,				2	},
		{	_ICODE_ADD,				1,			(u32)&function_add,				2,				2	},
		{	_ICODE_SUB,				1,			(u32)&function_sub,				2,				2	},
		{	_ICODE_MUL,				1,			(u32)&function_mul,				2,				2	},
		{	_ICODE_DIV,				1,			(u32)&function_div,				2,				2	},
	//////
	// Insert above this step somewhere in the list of functions.
	// STEP2:
	//////////
		// Note:  Do not delete this line, it is used to terminate the search list
		{	0,						0,					0,						0,				0	}
	};
