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
// Version 0.56
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
struct SThisCode;

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
	void				iError_signal								(SThisCode* thisCode, u32 tnErrorNum, SComp* comp, bool tlInvasive, s8* tcExtraInfo, bool tlFatal);
	void				iError_report								(cu8* constantErrorText, bool tlInvasive);
	void				iError_report								(u8* errorText, bool tlInvasive);
	void				iError_reportByNumber						(SThisCode* thisCode, u32 tnErrorNum, SComp* comp, bool tlInvasive);

	// Called to check if potential errors exist
	f32					iErrorCandidate_signalOutOfRange_f32		(SThisCode* thisCode, f32 value, s32 tnVarType, SComp* compRelated, bool tlInvasive, s8* tcExtraInfo);
	f64					iErrorCandidate_signalOutOfRange_f64		(SThisCode* thisCode, f64 value, s32 tnVarType, SComp* compRelated, bool tlInvasive, s8* tcExtraInfo);
	u8					iErrorCandidate_signalOutOfRange_u8			(SThisCode* thisCode, u8  value, s32 tnVarType, SComp* compRelated, bool tlInvasive, s8* tcExtraInfo);
	s16					iErrorCandidate_signalOutOfRange_s16		(SThisCode* thisCode, s16 value, s32 tnVarType, SComp* compRelated, bool tlInvasive, s8* tcExtraInfo);
	u16					iErrorCandidate_signalOutOfRange_u16		(SThisCode* thisCode, u16 value, s32 tnVarType, SComp* compRelated, bool tlInvasive, s8* tcExtraInfo);
	s32					iErrorCandidate_signalOutOfRange_s32		(SThisCode* thisCode, s32 value, s32 tnVarType, SComp* compRelated, bool tlInvasive, s8* tcExtraInfo);
	u32					iErrorCandidate_signalOutOfRange_u32		(SThisCode* thisCode, u32 value, s32 tnVarType, SComp* compRelated, bool tlInvasive, s8* tcExtraInfo);
	s64					iErrorCandidate_signalOutOfRange_s64		(SThisCode* thisCode, s64 value, s32 tnVarType, SComp* compRelated, bool tlInvasive, s8* tcExtraInfo);
	u64					iErrorCandidate_signalOutOfRange_u64		(SThisCode* thisCode, u64 value, s32 tnVarType, SComp* compRelated, bool tlInvasive, s8* tcExtraInfo);
	f64					iErrorCandidate_signalOutOfRange_numeric	(SThisCode* thisCode, SDatum* value, s32 tnVarType, SComp* compRelated, bool tlInvasive, s8* tcExtraInfo);




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
	SVariable*			function_abs		/* Stefano D'Amico */	(SThisCode* thisCode, SVariable* varNumber);
	SVariable*			function_acos		/* Stefano D'Amico */	(SThisCode* thisCode, SVariable* varNumber);
	SVariable*			function_addbs								(SThisCode* thisCode, SVariable* varString);
	SVariable*			function_alltrim							(SThisCode* thisCode, SVariable* varString, SVariable* varCaseInsensitive, SVariable* varTrimChars1, SVariable* varTrimChars2);
	SVariable*			ifunction_trim_common						(SThisCode* thisCode, SVariable* varString, SVariable* varCaseInsensitive, SVariable* varTrimChars1, SVariable* varTrimChars2, bool trimStart, bool trimEnd);
	SVariable*			function_alp								(SThisCode* thisCode, SVariable* varColor);
	SVariable*			function_asc								(SThisCode* thisCode, SVariable* varString);
	SVariable*			function_asin		/* Stefano D'Amico */	(SThisCode* thisCode, SVariable* varNumber);
	SVariable*			function_at									(SThisCode* thisCode, SVariable* varNeedle, SVariable* varHaystack, SVariable* varOccurrence);
	SVariable*			function_atan		/* Stefano D'Amico */	(SThisCode* thisCode, SVariable* varNumber);
	SVariable*			function_atc								(SThisCode* thisCode, SVariable* varNeedle, SVariable* varHaystack, SVariable* varOccurrence);
	SVariable*			ifunction_at_occurs_common					(SThisCode* thisCode, SVariable* varNeedle, SVariable* varHaystack, SVariable* varOccurrence, bool tlCaseSensitive, bool tlScanBackward, u32* tnFoundCount);
	SVariable*			function_blu								(SThisCode* thisCode, SVariable* varColor);
	SVariable*			function_bgr								(SThisCode* thisCode, SVariable* varBlu, SVariable* varGrn, SVariable* varRed);
	SVariable*			function_bgra								(SThisCode* thisCode, SVariable* varBlu, SVariable* varGrn, SVariable* varRed, SVariable* varAlp);
	SVariable*			function_ceiling	/* Stefano D'Amico */	(SThisCode* thisCode, SVariable* varNumber);
	SVariable*			function_chr								(SThisCode* thisCode, SVariable* varNumber);
	SVariable*			function_chrtran							(SThisCode* thisCode, SVariable* varString, SVariable* varSearch, SVariable* varReplace);
	SVariable*			function_chrtranc							(SThisCode* thisCode, SVariable* varString, SVariable* varSearch, SVariable* varReplace);
	SVariable*			ifunction_chrtran_common					(SThisCode* thisCode, SVariable* varString, SVariable* varSearch, SVariable* varReplace, bool tlCaseSensitive);
	SVariable*			function_colorize							(SThisCode* thisCode, SVariable* varColor, SVariable* varColorTarget, SVariable* varPercentage);
	SVariable*			ifunction_colorize_common					(SThisCode* thisCode, SVariable* varColor, SVariable* varColorTarget, SVariable* varPercentage, bool tlApplyColorTarget);
	SVariable*			function_cos								(SThisCode* thisCode, SVariable* varNumber);
	SVariable*			function_createobject						(SThisCode* thisCode, SVariable* varClass);
	SVariable*			function_curdir								(SThisCode* thisCode);
	SVariable*			function_datetime							(SThisCode* thisCode, SVariable* varYear, SVariable* varMonth, SVariable* varDay, SVariable* varHour, SVariable* varMinute, SVariable* varSecond, SVariable* varMillisecond);
	SVariable*			function_dtor		/* Stefano D'Amico */	(SThisCode* thisCode, SVariable* varNumber);
	SVariable*			function_exp		/* Stefano D'Amico */	(SThisCode* thisCode, SVariable* varNumber);
	SVariable*			ifunction_numbers_common					(SThisCode* thisCode, SVariable* varNumber, u32 tnFunctionType, const u32 tnResultType, bool tlSameInputType);
	SVariable*			function_floor		/* Stefano D'Amico */	(SThisCode* thisCode, SVariable* varNumber);
	SVariable*			function_forceext							(SThisCode* thisCode, SVariable* varPathname, SVariable varNewExtension);
	SVariable*			function_forcefname							(SThisCode* thisCode, SVariable* varPathname, SVariable varNewFilename);
	SVariable*			function_forcepath							(SThisCode* thisCode, SVariable* varPathname, SVariable varNewPathname);
	SVariable*			function_forcestem							(SThisCode* thisCode, SVariable* varPathname, SVariable varNewStem);
	SVariable*			function_fv			/* Stefano D'Amico */	(SThisCode* thisCode, SVariable* nPayment, SVariable* nInterestRate, SVariable* nPeriods);
	SVariable*			ifunction_fv_pv_common						(SThisCode* thisCode, SVariable* nPayment, SVariable* nInterestRate, SVariable* nPeriods, bool tlFV);
	SVariable*			function_grayscale							(SThisCode* thisCode, SVariable* varColor, SVariable* varPercentage);
	SVariable*			function_grn								(SThisCode* thisCode, SVariable* varColor);
	SVariable*			function_int								(SThisCode* thisCode, SVariable* varNumber);
	SVariable*			function_justdrive							(SThisCode* thisCode, SVariable* varString);
	SVariable*			function_justext							(SThisCode* thisCode, SVariable* varString);
	SVariable*			function_justfname							(SThisCode* thisCode, SVariable* varString);
	SVariable*			function_justpath							(SThisCode* thisCode, SVariable* varString);
	SVariable*			function_juststem							(SThisCode* thisCode, SVariable* varString, SVariable* varPostfixWidth);
	SVariable*			function_left								(SThisCode* thisCode, SVariable* varString, SVariable* varCount);
	SVariable*			function_len								(SThisCode* thisCode, SVariable* varString);
	SVariable*			function_log		/* Stefano D'Amico */	(SThisCode* thisCode, SVariable* varNumber);
	SVariable*			function_log10		/* Stefano D'Amico */	(SThisCode* thisCode, SVariable* varNumber);
	SVariable*			function_lower								(SThisCode* thisCode, SVariable* varString);
	SVariable*			function_ltrim								(SThisCode* thisCode, SVariable* varString, SVariable* varCaseInsensitive, SVariable* varTrimChars1, SVariable* varTrimChars2);
	SVariable*			function_malp								(SThisCode* thisCode, SVariable* varColor, SVariable* varAsInteger);
	SVariable*			function_max								(SThisCode* thisCode, SVariable* varLeft, SVariable* varRight);
	SVariable*			function_min								(SThisCode* thisCode, SVariable* varLeft, SVariable* varRight);
	SVariable*			function_mod		/* Stefano D'Amico */	(SThisCode* thisCode, SVariable* varDividend, SVariable* varDivisor);
	SVariable*			function_ncset								(SThisCode* thisCode, SVariable* varIndex, SVariable* varP1, SVariable* varP2, SVariable* varP3, SVariable* varP4, SVariable* varP5, SVariable* varP6);
	SVariable*			function_occurs								(SThisCode* thisCode, SVariable* varNeedle, SVariable* varHaystack);
	SVariable*			function_occursc							(SThisCode* thisCode, SVariable* varNeedle, SVariable* varHaystack);
	SVariable*			function_padc								(SThisCode* thisCode, SVariable* varExpression, SVariable* varResultSize, SVariable* varPadCharacter);
	SVariable*			function_padl								(SThisCode* thisCode, SVariable* varExpression, SVariable* varResultSize, SVariable* varPadCharacter);
	SVariable*			function_padr								(SThisCode* thisCode, SVariable* varExpression, SVariable* varResultSize, SVariable* varPadCharacter);
	SVariable*			ifunction_pad_common						(SThisCode* thisCode, SVariable* varExpression, SVariable* varResultSize, SVariable* varPadCharacter, bool tlPadLeft, bool tlPadRight);
	SVariable*			function_pi			/* Stefano D'Amico */	(SThisCode* thisCode);
	SVariable*			function_proper								(SThisCode* thisCode, SVariable* varString);
	SVariable*			function_pv			/* Stefano D'Amico */	(SThisCode* thisCode, SVariable* nPayment, SVariable* nInterestRate, SVariable* nPeriods);
	SVariable*			function_ranger		/* Stefano D'Amico */	(SThisCode* thisCode, SVariable* varExpression, SVariable* varMin, SVariable* varMax);
	SVariable*			function_rat								(SThisCode* thisCode, SVariable* varNeedle, SVariable* varHaystack, SVariable* varOccurrence);
	SVariable*			function_ratc								(SThisCode* thisCode, SVariable* varNeedle, SVariable* varHaystack, SVariable* varOccurrence);
	SVariable*			function_replicate							(SThisCode* thisCode, SVariable* varString, SVariable* varCount);
	SVariable*			function_rgb								(SThisCode* thisCode, SVariable* varRed, SVariable* varGrn, SVariable* varBlu);
	SVariable*			ifunction_rgba_common						(SThisCode* thisCode, SVariable* varRed, SVariable* varGrn, SVariable* varBlu, SVariable* varAlp);
	SVariable*			function_rgba								(SThisCode* thisCode, SVariable* varRed, SVariable* varGrn, SVariable* varBlu, SVariable* varAlp);
	SVariable*			function_red								(SThisCode* thisCode, SVariable* varColor);
	SVariable*			ifunction_color_common						(SThisCode* thisCode, SVariable* varColor, u32 tnMask, u32 tnShift);
	SVariable*			function_right								(SThisCode* thisCode, SVariable* varString, SVariable* varCount);
	SVariable*			function_round		/* Stefano D'Amico */	(SThisCode* thisCode, SVariable* varNumber, SVariable* varDecimalPlaces);
	SVariable*			function_rtod		/* Stefano D'Amico */	(SThisCode* thisCode, SVariable* varNumber);
	SVariable*			function_rtrim								(SThisCode* thisCode, SVariable* varString, SVariable* varCaseInsensitive, SVariable* varTrimChars1, SVariable* varTrimChars2);
	SVariable*			function_sign		/* Stefano D'Amico */	(SThisCode* thisCode, SVariable* varNumber);
	SVariable*			function_sign2								(SThisCode* thisCode, SVariable* varNumber);
	SVariable*			ifunction_sign_common						(SThisCode* thisCode, SVariable* varNumber, bool tlIncrementZero);
	SVariable*			function_sin								(SThisCode* thisCode, SVariable* varNumber);
	SVariable*			function_space								(SThisCode* thisCode, SVariable* varCount);
	SVariable*			function_sqrt		/* Stefano D'Amico */	(SThisCode* thisCode, SVariable* varNumber);
	SVariable*			function_strtran							(SThisCode* thisCode, SVariable* varString, SVariable* varSearch, SVariable* varReplace, SVariable* varRecursiveCount);
	SVariable*			function_strtranc							(SThisCode* thisCode, SVariable* varString, SVariable* varSearch, SVariable* varReplace, SVariable* varRecursiveCount);
	SVariable*			ifunction_strtran_common					(SThisCode* thisCode, SVariable* varString, SVariable* varSearch, SVariable* varReplace, SVariable* varRecursiveCount, bool tlCaseSensitive);
	SVariable*			function_stuff								(SThisCode* thisCode, SVariable* varOriginalString, SVariable* varStartPos, SVariable* varNumToRemove, SVariable* varStuffString);
	SVariable*			function_sys								(SThisCode* thisCode, SVariable* varIndex, SVariable* varP1, SVariable* varP2, SVariable* varP3, SVariable* varP4, SVariable* varP5, SVariable* varP6);
	SVariable*			iFunction_sys2015							(SThisCode* thisCode, u32 tnPrefixWidth, u32 tnPostfixWidth);
	SVariable*			function_sysmetric							(SThisCode* thisCode, SVariable* varIndex);
	SVariable*			function__test								(SThisCode* thisCode, SVariable* varIndex);
	SVariable*			function_transform							(SThisCode* thisCode, SVariable* varVariable, SVariable* varFormat);
	SVariable*			function_upper								(SThisCode* thisCode, SVariable* varString);
	SVariable*			function_version							(SThisCode* thisCode, SVariable* varIndex);
// Added temporarily until the processing engine is coded
	SVariable*			function_concatenate						(SThisCode* thisCode, SVariable* varString1, SVariable* varString2);
	SVariable*			function_add								(SThisCode* thisCode, SVariable* varNum1, SVariable* varNum2);
	SVariable*			function_sub								(SThisCode* thisCode, SVariable* varNum1, SVariable* varNum2);
	SVariable*			function_mul								(SThisCode* thisCode, SVariable* varNum1, SVariable* varNum2);
	SVariable*			function_div								(SThisCode* thisCode, SVariable* varNum1, SVariable* varNum2);
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
	void				command_clear								(SThisCode* thisCode, SComp* compClear);
	bool				iiCommand_clear_last_callback				(SEM_callback* ecb);
	bool				iiCommand_clear_keep_callback				(SEM_callback* ecb);
	void				command_modify								(SThisCode* thisCode, SComp* compModify);
	void				command_open								(SThisCode* thisCode, SComp* compOpen);
	void				command_set									(SThisCode* thisCode, SComp* compSet);
	void				command_use									(SThisCode* thisCode, SComp* compUse);




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
				SVariable*	(*func_0p)		(SThisCode* thisCode);
				SVariable*	(*func_1p)		(SThisCode* thisCode, SVariable* p1);
				SVariable*	(*func_2p)		(SThisCode* thisCode, SVariable* p1, SVariable* p2);
				SVariable*	(*func_3p)		(SThisCode* thisCode, SVariable* p1, SVariable* p2, SVariable* p3);
				SVariable*	(*func_4p)		(SThisCode* thisCode, SVariable* p1, SVariable* p2, SVariable* p3, SVariable* p4);
				SVariable*	(*func_5p)		(SThisCode* thisCode, SVariable* p1, SVariable* p2, SVariable* p3, SVariable* p4, SVariable* p5);
				SVariable*	(*func_6p)		(SThisCode* thisCode, SVariable* p1, SVariable* p2, SVariable* p3, SVariable* p4, SVariable* p5, SVariable* p6);
				SVariable*	(*func_7p)		(SThisCode* thisCode, SVariable* p1, SVariable* p2, SVariable* p3, SVariable* p4, SVariable* p5, SVariable* p6, SVariable* p7);
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
		{	_ICODE_ABS,				1,			(uptr)&function_abs,			1,				1,				&gsSourceLight_abs[0]			},	// ABS() by Stefano D'Amico, VJr 0.56, Mar.18.2015
		{	_ICODE_ACOS,			1,			(uptr)&function_acos,			1,				1,				&gsSourceLight_acos[0]			},	// ACOS() by Stefano D'Amico, VJr 0.56, Mar.18.2015
		{	_ICODE_ADDBS,			1,			(uptr)&function_addbs,			1,				4,				&gsSourceLight_alltrim[0]		},
		{	_ICODE_ALLTRIM,			1,			(uptr)&function_alltrim,		1,				4,				&gsSourceLight_alltrim[0]		},
		{	_ICODE_ALP,				1,			(uptr)&function_alp,			1,				1,				&gsSourceLight_alp[0]			},
		{	_ICODE_ASC,				1,			(uptr)&function_asc,			1,				1,				&gsSourceLight_asc[0]			},
		{	_ICODE_ASIN,			1,			(uptr)&function_asin,			1,				1,				&gsSourceLight_asin[0]			},	// ASIN() by Stefano D'Amico, VJr 0.56, Mar.18.2015
		{	_ICODE_AT,				1,			(uptr)&function_at,				2,				3,				&gsSourceLight_at[0]			},
		{	_ICODE_ATAN,			1,			(uptr)&function_atan,			1,				1,				&gsSourceLight_atan[0]			},	// ATAN() by Stefano D'Amico, VJr 0.56, Mar.18.2015
		{	_ICODE_ATC,				1,			(uptr)&function_atc,			2,				3,				&gsSourceLight_atc[0]			},
		{	_ICODE_BGR,				1,			(uptr)&function_bgr,			3,				3,				&gsSourceLight_bgr[0]			},
		{	_ICODE_BGRA,			1,			(uptr)&function_bgra,			4,				4,				&gsSourceLight_bgra[0]			},
		{	_ICODE_BLU,				1,			(uptr)&function_blu,			1,				1,				&gsSourceLight_blu[0]			},
		{	_ICODE_CEILING,			1,			(uptr)&function_ceiling,		1,				1,				&gsSourceLight_ceiling[0]		},	// CEILING() by Stefano D'Amico, VJr 0.56, Mar.15.2015
		{	_ICODE_CHR,				1,			(uptr)&function_chr,			1,				1,				&gsSourceLight_chr[0]			},
		{	_ICODE_CHRTRAN,			1,			(uptr)&function_chrtran,		2,				3,				&gsSourceLight_chrtran[0]		},
		{	_ICODE_CHRTRANC,		1,			(uptr)&function_chrtranc,		2,				3,				&gsSourceLight_chrtranc[0]		},
		{	_ICODE_COLORIZE,		1,			(uptr)&function_colorize,		2,				3,				&gsSourceLight_colorize[0]		},
		{	_ICODE_COS,				1,			(uptr)&function_cos,			1,				1,				&gsSourceLight_cos[0]			},	// COS() by Stefano D'Amico, VJr 0.56, Mar.17.2015
		{	_ICODE_CREATEOBJECT,	1,			(uptr)&function_createobject,	1,				1,				&gsSourceLight_createobject[0]	},
		{	_ICODE_CURDIR,			1,			(uptr)&function_curdir,			0,				0,				&gsSourceLight_curdir[0]		},
		{	_ICODE_DATETIME,		1,			(uptr)&function_datetime,		0,				7,				&gsSourceLight_datetime[0]		},
		{	_ICODE_DTOR,			1,			(uptr)&function_dtor,			1,				1,				&gsSourceLight_dtor[0]			},	// DTOR() by Stefano D'Amico, VJr 0.56, Mar.16.2015
		{	_ICODE_EXP,				1,			(uptr)&function_exp,			1,				1,				&gsSourceLight_exp[0]			},	// EXP() by Stefano D'Amico, VJr 0.56, Mar.15.2015
		{	_ICODE_FLOOR,			1,			(uptr)&function_floor,			1,				1,				&gsSourceLight_floor[0]			},	// FLOOR() by Stefano D'Amico, VJr 0.56, Mar.15.2015
		{	_ICODE_FORCEEXT,		1,			(uptr)&function_forceext,		2,				2,				&gsSourceLight_forceext[0]		},
		{	_ICODE_FORCEFNAME,		1,			(uptr)&function_forcefname,		2,				2,				&gsSourceLight_forcefname[0]	},
		{	_ICODE_FORCEPATH,		1,			(uptr)&function_forcepath,		2,				2,				&gsSourceLight_forcepath[0]		},
		{	_ICODE_FORCESTEM,		1,			(uptr)&function_forcestem,		2,				2,				&gsSourceLight_forcestem[0]		},
		{	_ICODE_FV,				1,			(uptr)&function_fv,				3,				3,				&gsSourceLight_fv[0]			},	// FV() by Stefano D'Amico, VJr 0.56, Mar.18.2015
		{	_ICODE_GRAYSCALE,		1,			(uptr)&function_grayscale,		1,				2,				&gsSourceLight_grayscale[0]		},
		{	_ICODE_GRN,				1,			(uptr)&function_grn,			1,				1,				&gsSourceLight_grn[0]			},
		{	_ICODE_INT,				1,			(uptr)&function_int,			1,				1,				&gsSourceLight_int[0]			},
		{	_ICODE_JUSTDRIVE,		1,			(uptr)&function_justdrive,		1,				1,				&gsSourceLight_justdrive[0]		},
		{	_ICODE_JUSTEXT,			1,			(uptr)&function_justext,		1,				1,				&gsSourceLight_justext[0]		},
		{	_ICODE_JUSTFNAME,		1,			(uptr)&function_justfname,		1,				1,				&gsSourceLight_justfname[0]		},
		{	_ICODE_JUSTPATH,		1,			(uptr)&function_justpath,		1,				1,				&gsSourceLight_justpath[0]		},
		{	_ICODE_JUSTSTEM,		1,			(uptr)&function_juststem,		1,				2,				&gsSourceLight_juststem[0]		},
		{	_ICODE_LEFT,			1,			(uptr)&function_left,			2,				2,				&gsSourceLight_left[0]			},
		{	_ICODE_LEN,				1,			(uptr)&function_len,			1,				1,				&gsSourceLight_len[0]			},
		{	_ICODE_LOG,				1,			(uptr)&function_log,			1,				1,				&gsSourceLight_log[0]			},	// LOG() by Stefano D'Amico, VJr 0.56, Mar.15.2015
		{	_ICODE_LOG10,			1,			(uptr)&function_log10,			1,				1,				&gsSourceLight_log10[0]			},	// LOG10() by Stefano D'Amico, VJr 0.56, Mar.15.2015
		{	_ICODE_LOWER,			1,			(uptr)&function_lower,			1,				1,				&gsSourceLight_lower[0]			},
		{	_ICODE_LTRIM,			1,			(uptr)&function_ltrim,			1,				1,				&gsSourceLight_ltrim[0]			},
		{	_ICODE_MALP,			1,			(uptr)&function_malp,			1,				2,				&gsSourceLight_malp[0]			},
		{	_ICODE_MAX,				1,			(uptr)&function_max,			2,				2,				&gsSourceLight_max[0]			},
		{	_ICODE_MIN,				1,			(uptr)&function_min,			2,				2,				&gsSourceLight_min[0]			},
		{	_ICODE_MOD,				1,			(uptr)&function_mod,			2,				2,				&gsSourceLight_mod[0]			},	// MOD() by Stefano D'Amico, VJr 0.56, Mar.08.2015
		{	_ICODE_NCSET,			1,			(uptr)&function_ncset,			1,				7,				&gsSourceLight_ncset[0]			},
		{	_ICODE_OCCURS,			1,			(uptr)&function_occurs,			2,				2,				&gsSourceLight_occurs[0]		},
		{	_ICODE_OCCURSC,			1,			(uptr)&function_occursc,		2,				2,				&gsSourceLight_occursc[0]		},
		{	_ICODE_PADC,			1,			(uptr)&function_padc,			2,				3,				&gsSourceLight_padc[0]			},
		{	_ICODE_PADL,			1,			(uptr)&function_padl,			2,				3,				&gsSourceLight_padl[0]			},
		{	_ICODE_PADR,			1,			(uptr)&function_padr,			2,				3,				&gsSourceLight_padr[0]			},
		{	_ICODE_PI,				1,			(uptr)&function_pi,				0,				0,				&gsSourceLight_pi[0]			},	// PI() by Stefano D'Amico, VJr 0.56, Mar.15.2015
		{	_ICODE_PROPER,			1,			(uptr)&function_proper,			1,				1,				&gsSourceLight_proper[0]		},
		{	_ICODE_PV,				1,			(uptr)&function_pv,				3,				3,				&gsSourceLight_pv[0]			},	// PV() by Stefano D'Amico, VJr 0.56, Mar.18.2015
		{	_ICODE_RANGER,			1,			(uptr)&function_ranger,			3,				3,				&gsSourceLight_ranger[0]		},	// RANGER() by Stefano D'Amico, VJr 0.56, Mar.14.2015
		{	_ICODE_RAT,				1,			(uptr)&function_rat,			2,				3,				&gsSourceLight_rat[0]			},
		{	_ICODE_RATC,			1,			(uptr)&function_ratc,			2,				3,				&gsSourceLight_ratc[0]			},
		{	_ICODE_RED,				1,			(uptr)&function_red,			1,				1,				&gsSourceLight_red[0]			},
		{	_ICODE_REPLICATE,		1,			(uptr)&function_replicate,		2,				2,				&gsSourceLight_replicate[0]		},
		{	_ICODE_RGB,				1,			(uptr)&function_rgb,			3,				3,				&gsSourceLight_rgb[0]			},
		{	_ICODE_RGBA,			1,			(uptr)&function_rgba,			4,				4,				&gsSourceLight_rgba[0]			},
		{	_ICODE_RIGHT,			1,			(uptr)&function_right,			2,				2,				&gsSourceLight_right[0]			},
		{	_ICODE_ROUND,			1,			(uptr)&function_round,			2,				2,				&gsSourceLight_round[0]			},	// ROUND() by Stefano D'Amico, VJr 0.56, Mar.16.2015
		{	_ICODE_RTOD,			1,			(uptr)&function_rtod,			1,				1,				&gsSourceLight_rtod[0]			},	// RTOD() by Stefano D'Amico, VJr 0.56, Mar.16.2015
		{	_ICODE_RTRIM,			1,			(uptr)&function_rtrim,			1,				1,				&gsSourceLight_rtrim[0]			},
		{	_ICODE_SIGN,			1,			(uptr)&function_sign,			1,				1,				&gsSourceLight_sign[0]			},	// SIGN() by Stefano D'Amico, VJr 0.56, Mar.14.2015
		{	_ICODE_SIN,				1,			(uptr)&function_sin,			1,				1,				&gsSourceLight_sin[0]			},	// SIN() by Stefano D'Amico, VJr 0.56, Mar.17.2015
		{	_ICODE_SPACE,			1,			(uptr)&function_space,			1,				1,				&gsSourceLight_space[0]			},
		{	_ICODE_SQRT,			1,			(uptr)&function_sqrt,			1,				1,				&gsSourceLight_sqrt[0]			},	// SQRT() by Stefano D'Amico, VJr 0.56, Mar.15.2015
		{	_ICODE_STRTRAN,			1,			(uptr)&function_strtran,		2,				4,				&gsSourceLight_strtran[0]		},
		{	_ICODE_STRTRANC,		1,			(uptr)&function_strtranc,		2,				4,				&gsSourceLight_strtranc[0]		},
		{	_ICODE_STUFF,			1,			(uptr)&function_stuff,			3,				4,				&gsSourceLight_stuff[0]			},
		{	_ICODE_SYS,				1,			(uptr)&function_sys,			1,				7,				&gsSourceLight_sys[0]			},
		{	_ICODE_SYSMETRIC,		1,			(uptr)&function_sysmetric,		1,				1,				&gsSourceLight_sysmetric[0]		},
		{	_ICODE__TEST,			1,			(uptr)&function__test,			1,				1,				NULL							},
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
				void		(*command)		(SThisCode* thisCode, SComp* comp);
			};


		//////////
		// SourceLight information
		//////
			SSourceLightData*	data;
	};

	SCommandData gsKnownCommands[] = {
		//	iCode					Command Algorithm
		//  ------------------		--------------------------
		{	_ICODE_CLEAR,			(uptr)&command_clear		},
		{	_ICODE_MODIFY,			(uptr)&command_modify		},
		{	_ICODE_OPEN,			(uptr)&command_open			},
		{	_ICODE_SET,				(uptr)&command_set			},
		{	_ICODE_USE,				(uptr)&command_use			},

		// Note:  Do not delete this line, it is used to terminate the command list
		{	0,						0							}
	};
