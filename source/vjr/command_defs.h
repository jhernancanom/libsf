//////////
//
// /libsf/source/vjr/command_defs.h
//
//////
// Version 0.30
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
// STEP1:
//////
	SVariable*			function_asc								(SVariable* p1);
	SVariable*			function_chr								(SVariable* p1);
	SVariable*			function_datetime							(SVariable* pYear, SVariable* pMonth, SVariable* pDay, SVariable* pHour, SVariable* pMinute, SVariable* pSecond, SVariable* pMillisecond);
	SVariable*			function_stuff								(SVariable* p1, SVariable* p2, SVariable* p3, SVariable* p4);


//////////
// Translation
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
		//                      Return										Parameters		Parameter
		//	iCode				Count		Function						Required		Maximum Count
		//  ------------------	------		--------------------------		----------		-------------
		{	_ICODE_ASC,			1,			(u32)&function_asc,				1,				1	},
		{	_ICODE_CHR,			1,			(u32)&function_chr,				1,				1	},
		{	_ICODE_DATETIME,	1,			(u32)&function_datetime,		0,				7	},
		{	_ICODE_STUFF,		1,			(u32)&function_stuff,			2,				4	},
	//////
	// Insert above this step somewhere in the list of functions.
	// STEP2:
	//////////
		// Note:  Do not delete this line, it is used to terminate the search list
		{	0,					NULL,					0	}
	};
