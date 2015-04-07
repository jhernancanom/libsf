//////////
//
// /libsf/source/vjr/commands/commands.cpp
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
//
// To add a new function, see the instructions in command_defs.h.
//
//




//////////
//
// Called to signal an error in the current running program
//
//////
	void iError_signal(SThisCode* thisCode, u32 tnErrorNum, SComp* comp, bool tlInvasive, s8* tcExtraInfo, bool tlFatal)
	{
// TODO:  This will need to potentially break the program execution
		iError_reportByNumber(thisCode, tnErrorNum, comp, tlInvasive);

		if (tlInvasive)
			debug_break;
	}




//////////
//
// Reports an error
//
//////
	void iError_report(SThisCode* thisCode, cu8* constantErrorText, bool tlInvasive)
	{
		iError_report(thisCode, (u8*)constantErrorText, tlInvasive);
	}

	void iError_report(SThisCode* thisCode, u8* errorText, bool tlInvasive)
	{
		if (!tlInvasive)
		{
			// Append the error to the EM
			iSEM_appendLine(thisCode, screenData, errorText, -1, false);
			screen_editbox->isDirtyRender = true;

		} else {
			// Immediate need
			MessageBox(NULL, (cs8*)errorText, (cs8*)cgcVjrError, MB_OK);
		}
	}




//////////
//
// Reports an error by number
//
//////
	void iError_reportByNumber(SThisCode* thisCode, u32 tnErrorNum, SComp* comp, bool tlInvasive)
	{
		switch (tnErrorNum)
		{
			case _ERROR_OUT_OF_MEMORY:						{	iError_report(thisCode, cgcOutOfMemory,						tlInvasive);		break;	}
			case _ERROR_UNEXPECTED_COMMAND:					{	iError_report(thisCode, cgcUnexpectedCommand,				tlInvasive);		break;	}
			case _ERROR_CONTEXT_HAS_CHANGED:				{	iError_report(thisCode, cgcContextHasChanged,				tlInvasive);		break;	}
			case _ERROR_FULL_RECOMPILE_REQUIRED:			{	iError_report(thisCode, cgcFullRecompileRequired,			tlInvasive);		break;	}
			case _ERROR_NOT_A_VARIABLE:						{	iError_report(thisCode, cgcNotAVariable,					tlInvasive);		break;	}
			case _ERROR_NUMERIC_OVERFLOW:					{	iError_report(thisCode, cgcNumericOverflow,					tlInvasive);		break;	}
			case _ERROR_NOT_NUMERIC:						{	iError_report(thisCode, cgcNotNumeric,						tlInvasive);		break;	}
			case _ERROR_EMPTY_STRING:						{	iError_report(thisCode, cgcEmptyString,						tlInvasive);		break;	}
			case _ERROR_SYNTAX:								{	iError_report(thisCode, cgcSyntaxError,						tlInvasive);		break;	}
			case _ERROR_UNRECOGNIZED_PARAMETER:				{	iError_report(thisCode, cgcUnrecognizedParameter,			tlInvasive);		break;	}
			case _ERROR_OUT_OF_RANGE:						{	iError_report(thisCode, cgcOutOfRange,						tlInvasive);		break;	}
			case _ERROR_COMMA_EXPECTED:						{	iError_report(thisCode, cgcCommaExpected,					tlInvasive);		break;	}
			case _ERROR_TOO_MANY_PARAMETERS:				{	iError_report(thisCode, cgcTooManyParameters,				tlInvasive);		break;	}
			case _ERROR_DATA_TYPE_MISMATCH:					{	iError_report(thisCode, cgcDataTypeMismatch,				tlInvasive);		break;	}
			case _ERROR_FEATURE_NOT_AVAILABLE:				{	iError_report(thisCode, cgcFeatureNotAvailable,				tlInvasive);		break;	}
			case _ERROR_P1_IS_INCORRECT:					{	iError_report(thisCode, cgcP1IsIncorrect,					tlInvasive);		break;	}
			case _ERROR_P2_IS_INCORRECT:					{	iError_report(thisCode, cgcP2IsIncorrect,					tlInvasive);		break;	}
			case _ERROR_P3_IS_INCORRECT:					{	iError_report(thisCode, cgcP3IsIncorrect,					tlInvasive);		break;	}
			case _ERROR_P4_IS_INCORRECT:					{	iError_report(thisCode, cgcP4IsIncorrect,					tlInvasive);		break;	}
			case _ERROR_P5_IS_INCORRECT:					{	iError_report(thisCode, cgcP5IsIncorrect,					tlInvasive);		break;	}
			case _ERROR_P6_IS_INCORRECT:					{	iError_report(thisCode, cgcP6IsIncorrect,					tlInvasive);		break;	}
			case _ERROR_P7_IS_INCORRECT:					{	iError_report(thisCode, cgcP7IsIncorrect,					tlInvasive);		break;	}
			case _ERROR_INTERNAL_ERROR:						{	iError_report(thisCode, cgcInternalError,					tlInvasive);		break;	}
			case _ERROR_INVALID_ARGUMENT_TYPE_COUNT:		{	iError_report(thisCode, cgcInvalidArgumentTypeCountError,	tlInvasive);		break;	}
			case _ERROR_VARIABLE_NOT_FOUND:					{	iError_report(thisCode, cgcVariableNotFoundError,			tlInvasive);		break;	}
			case _ERROR_ALIAS_NOT_FOUND:					{	iError_report(thisCode, cgcAliasNotFoundError,				tlInvasive);		break;	}
			case _ERROR_INVALID_WORK_AREA:					{	iError_report(thisCode, cgcInvalidWorkArea,					tlInvasive);		break;	}
			case _ERROR_ALIAS_ALREADY_IN_USE:				{	iError_report(thisCode, cgcAliasAlreadyInUse,				tlInvasive);		break;	}
			case _ERROR_PARENTHESIS_EXPECTED:				{	iError_report(thisCode, cgcParenthesisExpected,				tlInvasive);		break;	}
			case _ERROR_MISSING_PARAMETER:					{	iError_report(thisCode, cgcMissingParameter,				tlInvasive);		break;	}

			case _ERROR_DBF_UNABLE_TO_OPEN_TABLE:			{	iError_report(thisCode, cgcDbfUnableToOpenTable,			tlInvasive);		break;	}
			case _ERROR_DBF_WORK_AREA_ALREADY_IN_USE:		{	iError_report(thisCode, cgcDbfWorkAreaAlreadyInUse,			tlInvasive);		break;	}
			case _ERROR_DBF_ERROR_OPENING_DBC:				{	iError_report(thisCode, cgcDbfErrorOpeningDbc,				tlInvasive);		break;	}
			case _ERROR_DBF_WORK_AREA_NOT_IN_USE:			{	iError_report(thisCode, cgcDbfWorkAreaNotInUse,				tlInvasive);		break;	}
			case _ERROR_DBF_ERROR_READING_HEADER1:			{	iError_report(thisCode, cgcDbfErrorReadingHeader1,			tlInvasive);		break;	}
			case _ERROR_DBF_UNKNOWN_TABLE_TYPE:				{	iError_report(thisCode, cgcDbfUnknownTableType,				tlInvasive);		break;	}
			case _ERROR_DBF_MEMORY_ALLOCATION:				{	iError_report(thisCode, cgcDbfMemoryAllocation,				tlInvasive);		break;	}
			case _ERROR_DBF_ERROR_READING_HEADER2:			{	iError_report(thisCode, cgcDbfErrorReadingHeader2,			tlInvasive);		break;	}
			case _ERROR_DBF_TABLE_NAME_TOO_LONG:			{	iError_report(thisCode, cgcDbfTableNameTooLong,				tlInvasive);		break;	}
			case _ERROR_DBF_MEMORY_ROW:						{	iError_report(thisCode, cgcDbfMemoryRow,					tlInvasive);		break;	}
			case _ERROR_DBF_MEMORY_ORIGINAL:				{	iError_report(thisCode, cgcDbfMemoryOriginal,				tlInvasive);		break;	}
			case _ERROR_DBF_MEMORY_INDEX:					{	iError_report(thisCode, cgcDbfMemoryIndex,					tlInvasive);		break;	}
			case _ERROR_DBF_INVALID_WORK_AREA:				{	iError_report(thisCode, cgcDbfInvalidWorkArea,				tlInvasive);		break;	}
			case _ERROR_DBF_NO_MORE_WORK_AREAS:				{	iError_report(thisCode, cgcDbfNoMoreWorkAreas,				tlInvasive);		break;	}
			case _ERROR_DBF_LOCKING:						{	iError_report(thisCode, cgcDbfLocking,						tlInvasive);		break;	}
			case _ERROR_DBF_WRITING:						{	iError_report(thisCode, cgcDbfWriting,						tlInvasive);		break;	}
			case _ERROR_DBF_SEEKING:						{	iError_report(thisCode, cgcDbfSeeking,						tlInvasive);		break;	}
			case _ERROR_DBF_NO_DATA:						{	iError_report(thisCode, cgcDbfNoData,						tlInvasive);		break;	}
			case _ERROR_DBF_UNKNOWN_MEMO_FORMAT:			{	iError_report(thisCode, cgcDbfUnknownMemoFormat,			tlInvasive);		break;	}

			case _ERROR_CONFLICTING_PARAMETERS:				{	iError_report(thisCode, cgcConflictingParameters,			tlInvasive);		break;	}
			case _ERROR_PARAMETER_IS_INCORRECT:				{	iError_report(thisCode, cgcParameterIsIncorrect,			tlInvasive);		break;	}
			case _ERROR_TABLE_ALREADY_IN_USE:				{	iError_report(thisCode, cgcTableAlreadyInUse,				tlInvasive);		break;	}
			case _ERROR_PARAMETER_TOO_LONG:					{	iError_report(thisCode, cgcParameterTooLong,				tlInvasive);		break;	}
			case _ERROR_UNABLE_TO_OPEN_DBC:					{	iError_report(thisCode, cgcUnableToOpenDbc,					tlInvasive);		break;	}
			case _ERROR_DIVISION_BY_ZERO:					{	iError_report(thisCode, cgcDivisionByZero,					tlInvasive);		break;	}
			case _ERROR_CANNOT_BE_NEGATIVE:					{	iError_report(thisCode, cgcCannotBeNegative,				tlInvasive);		break;	}
			case _ERROR_CANNOT_BE_ZERO_OR_NEGATIVE:			{	iError_report(thisCode, cgcCannotBeZeroOrNegative,			tlInvasive);		break;	}
			case _ERROR_UNABLE_TO_AUTOVALIDATE:				{	iError_report(thisCode, cgcUnableToAutoValidate,			tlInvasive);		break;	}
			case _ERROR_DBF_GENERAL_ERROR:					{	iError_report(thisCode, cgcGeneralErrorDbf,					tlInvasive);		break;	}
			case _ERROR_CANNOT_BE_ZERO:						{	iError_report(thisCode, cgcCannotBeZero,					tlInvasive);		break;	}
			case _ERROR_MUST_BE_LOGICAL:					{	iError_report(thisCode, cgcMustBeLogical,					tlInvasive);		break;	}
			case _ERROR_PARAMETER_MUST_BE_8_16_32_64:		{	iError_report(thisCode, cgcParameterMustBe8_16_32_64,		tlInvasive);		break;	}
			case _ERROR_TOO_BIG_FOR_TARGET:					{	iError_report(thisCode, cgcTooBigForTarget,					tlInvasive);		break;	}
			case _ERROR_NO_INDEX_IS_LOADED:					{	iError_report(thisCode, cgcNoIndexIsLoaded,					tlInvasive);		break;	}
			case _ERROR_INVALID_INDEX_TAG:					{	iError_report(thisCode, cgcInvalidIndextag,					tlInvasive);		break;	}
			case _ERROR_UNABLE_TO_SAVE:						{	iError_report(thisCode, cgcUnableToSave,					tlInvasive);		break;	}
			case _ERROR_INVALID_PARAMETERS:					{	iError_report(thisCode, cgcInvalidParameters,				tlInvasive);		break;	}
			case _ERROR_PARAMETER_MUST_BE_1:				{	iError_report(thisCode, cgcParameterMustBeOne,				tlInvasive);		break;	}

		}

		// Flag the component
		if (comp && comp->line && comp->line->sourceCode && comp->line->sourceCode->data && comp->line->sourceCode_populatedLength != 0)
		{
			// Flag it for error
			comp->isError = true;
		}
	}




//////////
//
// An internal error track that could be used to report information in the runtime
// environment
//
//////
	void iError_track(void)
	{
		debug_nop;
	}




//////////
//
// Called to signal an error if the f32 value is outside the valid range for the target type
//
//////
	f32 iErrorCandidate_signalOutOfRange_f32(SThisCode* thisCode, f32 value, s32 tnVarType, SComp* compRelated, bool tlInvasive, s8* tcExtraInfo)
	{
		switch (tnVarType)
		{
			case _VAR_TYPE_S8:
				if (value <= (f32)_s8_min || value >= (f32)_s8_max)			iError_signal(thisCode, _ERROR_OUT_OF_RANGE, compRelated, tlInvasive, tcExtraInfo, false);
				break;

			case _VAR_TYPE_U8:
				if (value >= (f32)_u8_max)									iError_signal(thisCode, _ERROR_OUT_OF_RANGE, compRelated, tlInvasive, tcExtraInfo, false);
				break;

			case _VAR_TYPE_S16:
				if (value <= (f32)_s16_min || value >= (f32)_s16_max)		iError_signal(thisCode, _ERROR_OUT_OF_RANGE, compRelated, tlInvasive, tcExtraInfo, false);
				break;

			case _VAR_TYPE_U16:
				if (value >= (f32)_u16_max)									iError_signal(thisCode, _ERROR_OUT_OF_RANGE, compRelated, tlInvasive, tcExtraInfo, false);
				break;

			case _VAR_TYPE_S32:
				if (value <= (f32)_s32_min || value >= (f32)_s32_max)		iError_signal(thisCode, _ERROR_OUT_OF_RANGE, compRelated, tlInvasive, tcExtraInfo, false);
				break;

			case _VAR_TYPE_U32:
				if (value >= (f32)_u32_max)									iError_signal(thisCode, _ERROR_OUT_OF_RANGE, compRelated, tlInvasive, tcExtraInfo, false);
				break;

			case _VAR_TYPE_S64:
				if (value <= (f32)_s64_min || value >= (f32)_s64_max)		iError_signal(thisCode, _ERROR_OUT_OF_RANGE, compRelated, tlInvasive, tcExtraInfo, false);
				break;

			case _VAR_TYPE_U64:
				if (value >= (f32)_u64_max)									iError_signal(thisCode, _ERROR_OUT_OF_RANGE, compRelated, tlInvasive, tcExtraInfo, false);
				break;
		}

		// Return the input value
		return(value);
	}




//////////
//
// Called to signal an error if the f64 value is outside the valid range for the target type
//
//////
	f64 iErrorCandidate_signalOutOfRange_f64(SThisCode* thisCode, f64 value, s32 tnVarType, SComp* compRelated, bool tlInvasive, s8* tcExtraInfo)
	{
		switch (tnVarType)
		{
			case _VAR_TYPE_S8:
				if (value <= (f64)_s8_min || value >= (f64)_s8_max)			iError_signal(thisCode, _ERROR_OUT_OF_RANGE, compRelated, tlInvasive, tcExtraInfo, false);
				break;

			case _VAR_TYPE_U8:
				if (value >= (f64)_u8_max)									iError_signal(thisCode, _ERROR_OUT_OF_RANGE, compRelated, tlInvasive, tcExtraInfo, false);
				break;

			case _VAR_TYPE_S16:
				if (value <= (f64)_s16_min || value >= (f64)_s16_max)		iError_signal(thisCode, _ERROR_OUT_OF_RANGE, compRelated, tlInvasive, tcExtraInfo, false);
				break;

			case _VAR_TYPE_U16:
				if (value >= (f64)_u16_max)									iError_signal(thisCode, _ERROR_OUT_OF_RANGE, compRelated, tlInvasive, tcExtraInfo, false);
				break;

			case _VAR_TYPE_S32:
				if (value <= (f64)_s32_min || value >= (f64)_s32_max)		iError_signal(thisCode, _ERROR_OUT_OF_RANGE, compRelated, tlInvasive, tcExtraInfo, false);
				break;

			case _VAR_TYPE_U32:
				if (value >= (f64)_u32_max)									iError_signal(thisCode, _ERROR_OUT_OF_RANGE, compRelated, tlInvasive, tcExtraInfo, false);
				break;

			case _VAR_TYPE_S64:
				if (value <= (f64)_s64_min || value >= (f64)_s64_max)		iError_signal(thisCode, _ERROR_OUT_OF_RANGE, compRelated, tlInvasive, tcExtraInfo, false);
				break;

			case _VAR_TYPE_U64:
				if (value >= (f64)_u64_max)									iError_signal(thisCode, _ERROR_OUT_OF_RANGE, compRelated, tlInvasive, tcExtraInfo, false);
				break;
		}

		// Return the input value
		return(value);
	}




//////////
//
// Called to signal an error if the u16 value is outside the valid range for the target type
//
//////
	u8 iErrorCandidate_signalOutOfRange_u8(SThisCode* thisCode, u8 value, s32 tnVarType, SComp* compRelated, bool tlInvasive, s8* tcExtraInfo)
	{
		switch (tnVarType)
		{
			case _VAR_TYPE_S8:
				if (value >= (u8)_s8_max)			iError_signal(thisCode, _ERROR_OUT_OF_RANGE, compRelated, tlInvasive, tcExtraInfo, false);
				break;
		}

		// Return the input value
		return(value);
	}




//////////
//
// Called to signal an error if the s16 value is outside the valid range for the target type
//
//////
	s16 iErrorCandidate_signalOutOfRange_s16(SThisCode* thisCode, s16 value, s32 tnVarType, SComp* compRelated, bool tlInvasive, s8* tcExtraInfo)
	{
		switch (tnVarType)
		{
			case _VAR_TYPE_S8:
				if (value <= (s16)_s8_min || value >= (s16)_s8_max)			iError_signal(thisCode, _ERROR_OUT_OF_RANGE, compRelated, tlInvasive, tcExtraInfo, false);
				break;

			case _VAR_TYPE_U8:
				if (value >= (s16)_u8_max)									iError_signal(thisCode, _ERROR_OUT_OF_RANGE, compRelated, tlInvasive, tcExtraInfo, false);
				break;
		}

		// Return the input value
		return(value);
	}




//////////
//
// Called to signal an error if the u16 value is outside the valid range for the target type
//
//////
	u16 iErrorCandidate_signalOutOfRange_u16(SThisCode* thisCode, u16 value, s32 tnVarType, SComp* compRelated, bool tlInvasive, s8* tcExtraInfo)
	{
		switch (tnVarType)
		{
			case _VAR_TYPE_S8:
				if (value >= (u16)_s8_max)			iError_signal(thisCode, _ERROR_OUT_OF_RANGE, compRelated, tlInvasive, tcExtraInfo, false);
				break;

			case _VAR_TYPE_U8:
				if (value >= (u16)_u8_max)			iError_signal(thisCode, _ERROR_OUT_OF_RANGE, compRelated, tlInvasive, tcExtraInfo, false);
				break;

			case _VAR_TYPE_S16:
				if (value >= (u16)_s16_max)			iError_signal(thisCode, _ERROR_OUT_OF_RANGE, compRelated, tlInvasive, tcExtraInfo, false);
				break;
		}

		// Return the input value
		return(value);
	}




//////////
//
// Called to signal an error if the s32 value is outside the valid range for the target type
//
//////
	s32 iErrorCandidate_signalOutOfRange_s32(SThisCode* thisCode, s32 value, s32 tnVarType, SComp* compRelated, bool tlInvasive, s8* tcExtraInfo)
	{
		switch (tnVarType)
		{
			case _VAR_TYPE_S8:
				if (value <= (s32)_s8_min || value >= (s32)_s8_max)			iError_signal(thisCode, _ERROR_OUT_OF_RANGE, compRelated, tlInvasive, tcExtraInfo, false);
				break;

			case _VAR_TYPE_U8:
				if (value >= (s32)_u8_max)									iError_signal(thisCode, _ERROR_OUT_OF_RANGE, compRelated, tlInvasive, tcExtraInfo, false);
				break;

			case _VAR_TYPE_S16:
				if (value <= (s32)_s16_min || value >= (s32)_s16_max)		iError_signal(thisCode, _ERROR_OUT_OF_RANGE, compRelated, tlInvasive, tcExtraInfo, false);
				break;

			case _VAR_TYPE_U16:
				if (value >= (s32)_u16_max)									iError_signal(thisCode, _ERROR_OUT_OF_RANGE, compRelated, tlInvasive, tcExtraInfo, false);
				break;
		}

		// Return the input value
		return(value);
	}




//////////
//
// Called to signal an error if the s32 value is outside the valid range for the target type
//
//////
	u32 iErrorCandidate_signalOutOfRange_u32(SThisCode* thisCode, u32 value, s32 tnVarType, SComp* compRelated, bool tlInvasive, s8* tcExtraInfo)
	{
		switch (tnVarType)
		{
			case _VAR_TYPE_S8:
				if (value >= (u32)_s8_max)			iError_signal(thisCode, _ERROR_OUT_OF_RANGE, compRelated, tlInvasive, tcExtraInfo, false);
				break;

			case _VAR_TYPE_U8:
				if (value >= (u32)_u8_max)			iError_signal(thisCode, _ERROR_OUT_OF_RANGE, compRelated, tlInvasive, tcExtraInfo, false);
				break;

			case _VAR_TYPE_S16:
				if (value >= (u32)_s16_max)			iError_signal(thisCode, _ERROR_OUT_OF_RANGE, compRelated, tlInvasive, tcExtraInfo, false);
				break;

			case _VAR_TYPE_U16:
				if (value >= (u32)_u16_max)			iError_signal(thisCode, _ERROR_OUT_OF_RANGE, compRelated, tlInvasive, tcExtraInfo, false);
				break;
		}

		// Return the input value
		return(value);
	}




//////////
//
// Called to signal an error if the s64 value is outside the valid range for the target type
//
//////
	s64 iErrorCandidate_signalOutOfRange_s64(SThisCode* thisCode, s64 value, s32 tnVarType, SComp* compRelated, bool tlInvasive, s8* tcExtraInfo)
	{
		switch (tnVarType)
		{
			case _VAR_TYPE_S8:
				if (value <= (s64)_s8_min || value >= (s64)_s8_max)			iError_signal(thisCode, _ERROR_OUT_OF_RANGE, compRelated, tlInvasive, tcExtraInfo, false);
				break;

			case _VAR_TYPE_U8:
				if (value >= (s64)_u8_max)									iError_signal(thisCode, _ERROR_OUT_OF_RANGE, compRelated, tlInvasive, tcExtraInfo, false);
				break;

			case _VAR_TYPE_S16:
				if (value <= (s64)_s16_min || value >= (s64)_s16_max)		iError_signal(thisCode, _ERROR_OUT_OF_RANGE, compRelated, tlInvasive, tcExtraInfo, false);
				break;

			case _VAR_TYPE_U16:
				if (value >= (s64)_u16_max)									iError_signal(thisCode, _ERROR_OUT_OF_RANGE, compRelated, tlInvasive, tcExtraInfo, false);
				break;

			case _VAR_TYPE_S32:
				if (value <= (s64)_s32_min || value >= (s64)_s32_max)		iError_signal(thisCode, _ERROR_OUT_OF_RANGE, compRelated, tlInvasive, tcExtraInfo, false);
				break;

			case _VAR_TYPE_U32:
				if (value >= (s64)_u32_max)									iError_signal(thisCode, _ERROR_OUT_OF_RANGE, compRelated, tlInvasive, tcExtraInfo, false);
				break;
		}

		// Return the input value
		return(value);
	}




//////////
//
// Called to signal an error if the s64 value is outside the valid range for the target type
//
//////
	u64 iErrorCandidate_signalOutOfRange_u64(SThisCode* thisCode, u64 value, s32 tnVarType, SComp* compRelated, bool tlInvasive, s8* tcExtraInfo)
	{
		switch (tnVarType)
		{
			case _VAR_TYPE_S8:
				if (value >= (u64)_s8_max)			iError_signal(thisCode, _ERROR_OUT_OF_RANGE, compRelated, tlInvasive, tcExtraInfo, false);
				break;

			case _VAR_TYPE_U8:
				if (value >= (u64)_u8_max)			iError_signal(thisCode, _ERROR_OUT_OF_RANGE, compRelated, tlInvasive, tcExtraInfo, false);
				break;

			case _VAR_TYPE_S16:
				if (value >= (u64)_s16_max)			iError_signal(thisCode, _ERROR_OUT_OF_RANGE, compRelated, tlInvasive, tcExtraInfo, false);
				break;

			case _VAR_TYPE_U16:
				if (value >= (u64)_u16_max)			iError_signal(thisCode, _ERROR_OUT_OF_RANGE, compRelated, tlInvasive, tcExtraInfo, false);
				break;

			case _VAR_TYPE_S32:
				if (value >= (u64)_s32_max)			iError_signal(thisCode, _ERROR_OUT_OF_RANGE, compRelated, tlInvasive, tcExtraInfo, false);
				break;

			case _VAR_TYPE_U32:
				if (value >= (u64)_u32_max)			iError_signal(thisCode, _ERROR_OUT_OF_RANGE, compRelated, tlInvasive, tcExtraInfo, false);
				break;

			case _VAR_TYPE_S64:
				if (value >= (u64)_s64_max)			iError_signal(thisCode, _ERROR_OUT_OF_RANGE, compRelated, tlInvasive, tcExtraInfo, false);
				break;
		}

		// Return the input value
		return(value);
	}




//////////
//
// Called to signal an error if the numeric value is outside the valid range for the target type
//
//////
	f64 iErrorCandidate_signalOutOfRange_numeric(SThisCode* thisCode, SDatum* value, s32 tnVarType, SComp* compRelated, bool tlInvasive, s8* tcExtraInfo)
	{
		f64	lfValue;
		s8	buffer[64];


		// Based on the test type, make sure it's in range
		if (value && value->length >= 1 && (u32)value->length <= sizeof(buffer) - 1)
		{
			// Copy text to null-terminate
			memcpy(buffer, value->data, value->length);
			buffer[value->length] = 0;

			// Convert to f64
			lfValue = atof(value->data);

			// Based on the type, check its range
			switch (tnVarType)
			{
				case _VAR_TYPE_S8:
					if (lfValue <= (f64)_s8_min || lfValue >= (f64)_s8_max)			iError_signal(thisCode, _ERROR_OUT_OF_RANGE, compRelated, tlInvasive, tcExtraInfo, false);
					break;

				case _VAR_TYPE_U8:
					if (lfValue >= (f64)_u8_max)									iError_signal(thisCode, _ERROR_OUT_OF_RANGE, compRelated, tlInvasive, tcExtraInfo, false);
					break;

				case _VAR_TYPE_S16:
					if (lfValue <= (f64)_s16_min || lfValue >= (f64)_s16_max)		iError_signal(thisCode, _ERROR_OUT_OF_RANGE, compRelated, tlInvasive, tcExtraInfo, false);
					break;

				case _VAR_TYPE_U16:
					if (lfValue >= (f64)_u16_max)									iError_signal(thisCode, _ERROR_OUT_OF_RANGE, compRelated, tlInvasive, tcExtraInfo, false);
					break;

				case _VAR_TYPE_S32:
					if (lfValue <= (f64) _s32_min || lfValue >= (f64)_s32_max)		iError_signal(thisCode, _ERROR_OUT_OF_RANGE, compRelated, tlInvasive, tcExtraInfo, false);
					break;

				case _VAR_TYPE_U32:
					if (lfValue >= (f64)_u32_max)									iError_signal(thisCode, _ERROR_OUT_OF_RANGE, compRelated, tlInvasive, tcExtraInfo, false);
					break;

				case _VAR_TYPE_S64:
					if (lfValue <= (f64)_s64_min || lfValue >= (f64)_s64_max)		iError_signal(thisCode, _ERROR_OUT_OF_RANGE, compRelated, tlInvasive, tcExtraInfo, false);
					break;

				case _VAR_TYPE_U64:
					if (lfValue >= (f64)_u64_max)									iError_signal(thisCode, _ERROR_OUT_OF_RANGE, compRelated, tlInvasive, tcExtraInfo, false);
					break;

				case _VAR_TYPE_F32:
					if (lfValue <= (f64)_s32_min || lfValue >= (f64)_s32_max)		iError_signal(thisCode, _ERROR_OUT_OF_RANGE, compRelated, tlInvasive, tcExtraInfo, false);
					break;
			}

		} else {
			// Signal the lowest possible value
			lfValue = (f64)_f64_min;
		}

		// Return the input value
		return(lfValue);
	}




//////////
//
// Function: ABS()
// Returns the absolute value of the specified numeric expression.
//
//////
// Version 0.56
// Last update:
//     Mar.18.2015
//////
// Change log:
//     Mar.18.2015 - Initial creation by Stefano D'Amico
//////
// Parameters:
//     p1			-- Numeric or floating point
//
//////
// Returns:
//    ABS(n) of the value in p1
//////
// Example:
//    ? ABS(-10)		&& Display 10
//////
    SVariable* function_abs(SThisCode* thisCode, SReturnsParams* returnsParams)
    {
		SVariable* varNumber = returnsParams->params[0];


		// Return abs
		return(ifunction_numbers_common(thisCode, varNumber, NULL, NULL, _FP_COMMON_ABS, _VAR_TYPE_F64, true, false, returnsParams));
	}




//////////
//
// Function: ACOS()
// Returns the arc cosine of a specified numeric expression.
//
//////
// Version 0.56
// Last update:
//     Mar.18.2015
//////
// Change log:
//     Mar.18.2015 - Initial creation by Stefano D'Amico
//////
// Parameters:
//     p1			-- Numeric or floating point
//
//////
// Returns:
//    ACOS(n) of the value in p1
//////
// Example:
//    ? ACOS(0)		&& Display 1.57
//////
    SVariable* function_acos(SThisCode* thisCode, SReturnsParams* returnsParams)
    {
		SVariable* varNumber = returnsParams->params[0];


		// Return acos
		return(ifunction_numbers_common(thisCode, varNumber, NULL, NULL, _FP_COMMON_ACOS, _VAR_TYPE_F64, false, false, returnsParams));
	}




//////////
//
// Function: ADDBS()
// Adds a backslash to a path if it needs one
//
//////
// Version 0.56
// Last update:
//	   Dec.26.2014
//////
// Change log:
//     Dec.26.2014 - Initial creation
//////
// Parameters:
//     varString		-- Character, the string that needs to end with a backspace
//////
// Returns:
//     Character		-- The string with a trailing backspace added if need be
//////
	SVariable* function_addbs(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable*	varString = returnsParams->params[0];
        SVariable*	result;


		//////////
		// Parameter 1 must be character
		//////
			if (!iVariable_isValid(varString) || !iVariable_isTypeCharacter(varString))
			{
				iError_reportByNumber(thisCode, _ERROR_P1_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varString), false);
				return(NULL);
			}


		//////////
        // Based on its type, process it accordingly
		//////
			result = iVariable_create(thisCode, _VAR_TYPE_CHARACTER, NULL, true);
			if (!result)
			{
				iError_report(thisCode, cgcInternalError, false);
				return(NULL);
			}

			if (varString->value.length >= 1)
			{
				// If the last character is not a backslash, add one
				if (varString->value.data_u8[varString->value.length - 1] != '\\')
				{
					// We need to append the string plus a backslash
					iDatum_allocateSpace(&result->value, varString->value.length + 1);
					memcpy(result->value.data_s8, varString->value.data_s8, varString->value.length);
					result->value.data_u8[result->value.length - 1] = '\\';

				} else {
					// We can copy the string as is
					iDatum_duplicate(&result->value, &varString->value);
				}

			} else {
				// Append a trailing backslash
				iDatum_duplicate(&result->value, (u8*)cgcBackslash, 1);
			}


		//////////
        // Return our converted result
		//////
	        return(result);
	}




//////////
//
// Function: ALLTRIM()
// Trims spaces off the start and end of the string.
//
//////
// Version 0.56
// Last update:
//     Jul.12.2014
//////
// Change log:
//     Jul.12.2014 - Initial creation
//////
// Parameters:
//     pString			-- Character, the string to trim
//     pCaseInsensitive	-- (Optional) Logical,		are the trim characters case insensitive?  Default = .T.
//     pTrimChars1		-- (Optional) Character,	characters to trim
//     pTrimChars2		-- (Optional) Character,	characters to trim
//
//////
// Returns:
//    Character		-- The string with any leading and trailing spaces removed
//////
	SVariable* function_alltrim(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varString			= returnsParams->params[0];
		SVariable* varCaseInsensitive	= returnsParams->params[1];
		SVariable* varTrimChars1		= returnsParams->params[2];
		SVariable* varTrimChars2		= returnsParams->params[3];


		// Return alltrim
		return(ifunction_trim_common(thisCode, varString, varCaseInsensitive, varTrimChars1, varTrimChars2, true, true, returnsParams));
	}




//////////
//
// Logic used for ALLTRIM(), LTRIM(), RTRIM()
//
//////
// Syntax forms supported:
//	    (1)  *TRIM(cString[, cTrimString])
//	    (2)  *TRIM(cString[, nCaseSensitive|lCaseSensitive[, cTrimChar1[, cTrimChar2]]])
//
//////
	SVariable* ifunction_trim_common(SThisCode* thisCode, SVariable* varString, SVariable* varCaseInsensitive, SVariable* varTrimChars1, SVariable* varTrimChars2, bool tlTrimTheStart, bool tlTrimTheEnd, SReturnsParams* returnsParams)
	{
		s32			lnI, lnClipStartPos, lnClipEndPos;
		s8			lc;
		bool		llCaseInsensitive, llSyntaxForm1, llFound;
		s8*			trim1ptr;
		s8*			trim2ptr;
		s32			trim1Length, trim2Length;
        SVariable*	result;


// TODO:  Incomplete function.  Breakpoint, debug, and finish development
//_asm_int3;
		//////////
		// Parameter 1 must be character
		//////
			if (!iVariable_isValid(varString) || !iVariable_isTypeCharacter(varString))
			{
				iError_reportByNumber(thisCode, _ERROR_P1_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varString), false);
				return(NULL);
			}


		//////////
		// Initialize
		//////
			llSyntaxForm1		= false;		// Two syntax forms are available
			llCaseInsensitive	= false;		// By default case-sensitive compare
			trim1ptr		= (s8*)cgc_spaceText;
			trim1Length		= 1;
			trim2ptr		= NULL;
			trim2Length		= 0;


		//////////
        // If pCaseInsensitive is present, indicates case-insensitive
		//////
			if (varCaseInsensitive)
			{
				// See what the parameter is
				if (!iVariable_isValid(varCaseInsensitive))
				{
					iError_reportByNumber(thisCode, _ERROR_P2_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varCaseInsensitive), false);
					return(NULL);

				} else if (iVariable_isTypeNumeric(varCaseInsensitive)) {
					// They are indicating case sensitivity by an integer, should be 1 for case-insensitive, otherwise case-sensitive
					// If 1, case-insensitive
					if (*(s32*)varCaseInsensitive->value.data == 1)
						llCaseInsensitive = true;

				} else if (iVariable_isTypeLogical(varCaseInsensitive)) {
					// They are indicating case sensitivity by a logical flag, should be .t. for case-insensitive, otherwise case-sensitive
					if (varCaseInsensitive->value.data[0] != 0)
						llCaseInsensitive = true;

				} else if (iVariable_isTypeCharacter(varCaseInsensitive)) {
					// They're using the syntax form:
					//		ALLTRIM(cString[, cTrimString])
					trim1ptr		= varCaseInsensitive->value.data;
					trim1Length		= varCaseInsensitive->value.length;
					trim2ptr		= NULL;
					trim2Length		= 0;
					llSyntaxForm1	= true;

				} else {
					iError_reportByNumber(thisCode, _ERROR_P2_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varCaseInsensitive), false);
					return(NULL);
				}
			}


		//////////
		// If they specified trimCharss
		//////
			if (varTrimChars1)
			{
				// If they're using syntax form1, then the presence of this parameter is a syntax error
				if (llSyntaxForm1)
				{
					iError_reportByNumber(thisCode, _ERROR_TOO_MANY_PARAMETERS, iVariable_getRelatedComp(thisCode, varTrimChars1), false);
					return(NULL);

				} else if (iVariable_isTypeCharacter(varTrimChars1)) {
					// They specified characters to scan
					trim1ptr	= varTrimChars1->value.data;
					trim1Length	= varTrimChars1->value.length;

				} else {
					iError_reportByNumber(thisCode, _ERROR_P3_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varTrimChars1), false);
					return(NULL);
				}
			}


		//////////
		// If they specified trimCharss
		//////
			if (varTrimChars2)
			{
				if (iVariable_isTypeCharacter(varTrimChars2))
				{
					// They specified characters to scan
					trim2ptr	= varTrimChars2->value.data;
					trim2Length	= varTrimChars2->value.length;
					if (trim1ptr == (s8*)cgc_spaceText)
					{
						// They gave us the second trim characters, so we'll use it
						trim1ptr		= NULL;
						trim1Length		= 0;
					}

				} else {
					iError_reportByNumber(thisCode, _ERROR_P4_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varTrimChars2), false);
					return(NULL);
				}
			}


		//////////
        // Create our return result
		//////
	        result = iVariable_create(thisCode, _VAR_TYPE_CHARACTER, NULL, true);
			if (!result)
			{
				iError_report(thisCode, cgcInternalError, false);
				return(NULL);
			}


		//////////
        // It must be at least one character long to be adjusted
		//////
			if (varString->value.length >= 1)
			{
				//////////
				// START
				//////
					lnClipStartPos = 0;
					if (tlTrimTheStart)
					{
						// Based on the comparison, we either compare character-by-character, or convert case and compare character-by-character
						if (llCaseInsensitive)
						{
							// Compare character by character exactly as they are
							for ( ; lnClipStartPos < varString->value.length; ++lnClipStartPos)
							{
								// Grab the character
								lc = varString->value.data[lnClipStartPos];

								// Scan the trim1 characters
								// If we're not on a character that we know, we're done
								llFound = false;
								if (trim1ptr)
								{
									for (lnI = 0; lnI < trim1Length; lnI++)
									{
										// If this character matches, we've found a match, which means we're still trimming characters
										if (lc == trim1ptr[lnI])
										{
											llFound = true;
											break;
										}
									}
								}


								// Scan the trim2 characters
								// We still need to search through the trim2 characters list
								if (!llFound && trim2ptr)
								{
									for (lnI = 0; lnI < trim2Length; lnI++)
									{
										// If this character matches, we've found a match, which means we're still trimming characters
										if (lc == trim2ptr[lnI])
										{
											llFound = true;
											break;
										}
									}
								}

								// If we didn't find a trim character, we've reached the end
								if (!llFound)
									break;
							}

						} else {
							// Compare character by character accounting for case
							// Compare character by character exactly as they are
							for ( ; lnClipStartPos < varString->value.length; ++lnClipStartPos)
							{
								// Grab the character
								lc = iLowerCase(varString->value.data[lnClipStartPos]);

								// Scan the trim1 characters
								// If we're not on a character that we know, we're done
								llFound = false;
								if (trim1ptr)
								{
									for (lnI = 0; lnI < trim1Length; lnI++)
									{
										// If this character matches, we've found a match, which means we're still trimming characters
										if (lc == iLowerCase(trim1ptr[lnI]))
										{
											llFound = true;
											break;
										}
									}
								}


								// Scan the trim2 characters
								// We still need to search through the trim2 characters list
								if (!llFound && trim2ptr)
								{
									for (lnI = 0; lnI < trim2Length; lnI++)
									{
										// If this character matches, we've found a match, which means we're still trimming characters
										if (lc == iLowerCase(trim2ptr[lnI]))
										{
											llFound = true;
											break;
										}
									}
								}

								// If we didn't find a trim character, we've reached the end
								if (!llFound)
									break;
							}
						}

						// When we get here, we have determined the number of characters on the left
						if (lnClipStartPos >= varString->value.length)
							return(result);		// The entire character string is empty, so we just return the blank string
					}


				//////////
				// END
				//////
					lnClipEndPos = varString->value.length - 1;
					if (tlTrimTheEnd)
					{
						// Based on the comparison, we either compare character-by-character, or convert case and compare character-by-character
						if (llCaseInsensitive)
						{
							// Compare character by character exactly as they are
							for ( ; lnClipEndPos > 0; lnClipEndPos--)
							{
								// Grab the character
								lc = varString->value.data[lnClipEndPos];

								// Scan the trim1 characters
								// If we're not on a character that we know, we're done
								llFound = false;
								if (trim1ptr)
								{
									for (lnI = 0; lnI < trim1Length; lnI++)
									{
										// If this character matches, we've found a match, which means we're still trimming characters
										if (lc == trim1ptr[lnI])
										{
											llFound = true;
											break;
										}
									}
								}


								// Scan the trim2 characters
								// We still need to search through the trim2 characters list
								if (!llFound && trim2ptr)
								{
									for (lnI = 0; lnI < trim2Length; lnI++)
									{
										// If this character matches, we've found a match, which means we're still trimming characters
										if (lc == trim2ptr[lnI])
										{
											llFound = true;
											break;
										}
									}
								}

								// If we didn't find a trim character, we've reached the end
								if (!llFound)
									break;
							}

						} else {
							// Compare character by character accounting for case
							// Compare character by character exactly as they are
							for ( ; lnClipEndPos > 0; lnClipEndPos--)
							{
								// Grab the character
								lc = iLowerCase(varString->value.data[lnClipEndPos]);

								// Scan the trim1 characters
								// If we're not on a character that we know, we're done
								llFound = false;
								if (trim1ptr)
								{
									for (lnI = 0; lnI < trim1Length; lnI++)
									{
										// If this character matches, we've found a match, which means we're still trimming characters
										if (lc == iLowerCase(trim1ptr[lnI]))
										{
											llFound = true;
											break;
										}
									}
								}


								// Scan the trim2 characters
								// We still need to search through the trim2 characters list
								if (!llFound && trim2ptr)
								{
									for (lnI = 0; lnI < trim2Length; lnI++)
									{
										// If this character matches, we've found a match, which means we're still trimming characters
										if (lc == iLowerCase(trim2ptr[lnI]))
										{
											llFound = true;
											break;
										}
									}
								}

								// If we didn't find a trim character, we've reached the end
								if (!llFound)
									break;
							}
						}
					}


				//////////
				// Copy the portion of the string
				//////
					iDatum_duplicate(&result->value, varString->value.data_u8 + lnClipStartPos, lnClipEndPos - lnClipStartPos + 1);
			}


		//////////
        // Return our converted result
		//////
	        return(result);
	}




//////////
//
// Function: ALP()
// Retrieves the alpha channel from an RGBA or BGRA color.
//
//////
// Version 0.56
// Last update:
//     Mar.16.2015
//////
// Change log:
//     Mar.16.2015 - Initial creation
//////
// Parameters:
//     varColor		-- Numeric, a color (0..(2^32)-1)
//
//////
// Returns:
//    Numeric	-- Input number converted to ASCII value number
//////
	SVariable* function_alp(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varColor = returnsParams->params[0];


		// Return alp
		return(ifunction_color_common(thisCode, varColor, 0xff000000, 24, returnsParams));
	}




//////////
//
// Function: ASC()
// Takes a character input and converts it to its ASCII value.
//
//////
// Version 0.56
// Last update:
//     Jul.05.2014
//////
// Change log:
//     Jul.05.2014 - Initial creation
//////
// Parameters:
//     p1		-- Character, must be at least one character long
//
//////
// Returns:
//    Numeric	-- Input number converted to ASCII value number
//////
    SVariable* function_asc(SThisCode* thisCode, SReturnsParams* returnsParams)
    {
		SVariable*	varString = returnsParams->params[0];
        u8 			value;
        SVariable*	result;


		//////////
		// Parameter 1 must be character
		//////
			if (!iVariable_isValid(varString) || !iVariable_isTypeCharacter(varString))
			{
				iError_reportByNumber(thisCode, _ERROR_P1_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varString), false);
				return(NULL);
			}


		//////////
        // It must be at least one character long
		//////
			if (varString->value.length == 0)
				iError_reportByNumber(thisCode, _ERROR_EMPTY_STRING, iVariable_getRelatedComp(thisCode, varString), false);


		//////////
		// Extract the first character, and convert it to a number
		//////
			value = varString->value.data_u8[0];


		//////////
        // Create our return result
		//////
	        result = iVariable_create(thisCode, _VAR_TYPE_S32, NULL, true);
			if (!result)
			{
				iError_report(thisCode, cgcInternalError, false);
				return(NULL);
			}


		//////////
        // Populate the result as an ASCII character
		//////
	        *result->value.data_s32 = (s32)value;


		//////////
        // Return our converted result
		//////
	        return(result);
    }




//////////
//
// Function: ASIN()
// Returns in radians the arc sine of a numeric expression.
//
//////
// Version 0.56
// Last update:
//     Mar.18.2015
//////
// Change log:
//     Mar.18.2015 - Initial creation by Stefano D'Amico
//////
// Parameters:
//     p1			-- Numeric or floating point
//
//////
// Returns:
//    ASIN(n) of the value in p1
//////
// Example:
//    ? ASIN(1)		&& Display 1.57
//////
    SVariable* function_asin(SThisCode* thisCode, SReturnsParams* returnsParams)
    {
		SVariable* varNumber = returnsParams->params[0];


		// Return asin
		return(ifunction_numbers_common(thisCode, varNumber, NULL, NULL, _FP_COMMON_ASIN, _VAR_TYPE_F64, false, false, returnsParams));
	}




//////////
//
// Function: ATAN()
// Returns in radians the arc tangent of a numeric expression.
//
//////
// Version 0.56
// Last update:
//     Mar.18.2015
//////
// Change log:
//     Mar.18.2015 - Initial creation by Stefano D'Amico
//////
// Parameters:
//     p1			-- Numeric or floating point
//
//////
// Returns:
//    ATAN(n) of the value in p1
//////
// Example:
//    ? ATAN(1.57)		&& Display 1.00
//////
    SVariable* function_atan(SThisCode* thisCode, SReturnsParams* returnsParams)
    {
		SVariable* varNumber = returnsParams->params[0];


		// Return atan
		return(ifunction_numbers_common(thisCode, varNumber, NULL, NULL, _FP_COMMON_ATAN, _VAR_TYPE_F64, false, false, returnsParams));
	}




//////////
//
// Functions:  AT(), ATC(), RAT(), RATC()
// Takes a character input to search for, an expression to search, and an optional occurrence
// to find, with and optionally with regard to case (trailing "C").
//
// Functions:  OCCURS(), OCCURSC()
// Takes a character input to search for, an expression to search, and determines how many
// times the search string is found, and optionally with regard to case (trailing "C").
//
//////
// Version 0.56
// Last update:
//     Aug.03.2014
//////
// Change log:
//     Aug.03.2014 - Initial creation
//////
// Parameters:
//     pNeedle		-- What we're looking for
//     pHaystack	-- Where we're looking
//     pOccurrence	-- An optional instance count within the expression
//
//////
// Returns:
//    u32			-- Location of the find, or 0 if not found
//////
	SVariable* function_at(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varNeedle		= returnsParams->params[0];
		SVariable* varHaystack		= returnsParams->params[1];
		SVariable* varOccurrence	= returnsParams->params[2];


		// Return at
		return(ifunction_at_occurs_common(thisCode, varNeedle, varHaystack, varOccurrence, true, false, NULL, returnsParams));
	}

	SVariable* function_atc(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varNeedle		= returnsParams->params[0];
		SVariable* varHaystack		= returnsParams->params[1];
		SVariable* varOccurrence	= returnsParams->params[2];


		// Return atc
		return(ifunction_at_occurs_common(thisCode, varNeedle, varHaystack, varOccurrence, false, false, NULL, returnsParams));
	}

	SVariable* function_rat(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varNeedle		= returnsParams->params[0];
		SVariable* varHaystack		= returnsParams->params[1];
		SVariable* varOccurrence	= returnsParams->params[2];


		// Return rat
		return(ifunction_at_occurs_common(thisCode, varNeedle, varHaystack, varOccurrence, true, true, NULL, returnsParams));
	}

	SVariable* function_ratc(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varNeedle		= returnsParams->params[0];
		SVariable* varHaystack		= returnsParams->params[1];
		SVariable* varOccurrence	= returnsParams->params[2];


		// Return ratc
		return(ifunction_at_occurs_common(thisCode, varNeedle, varHaystack, varOccurrence, false, true, NULL, returnsParams));
	}

	SVariable* ifunction_at_occurs_common(SThisCode* thisCode, SVariable* varNeedle, SVariable* varHaystack, SVariable* varOccurrence, bool tlCaseSensitive, bool tlScanBackward, u32* tnFoundCount, SReturnsParams* returnsParams)
	{
		u32			errorNum;
		s32			lnI, lnStart, lnInc, lnStopper, lnFoundCount, lnOccurrence;
		bool		error;
		SVariable*	result;


		//////////
		// Parameter 1 must be character
		//////
			if (!iVariable_isValid(varNeedle) || !iVariable_isTypeCharacter(varNeedle))
			{
				iError_reportByNumber(thisCode, _ERROR_P1_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varNeedle), false);
				return(NULL);
			}


		//////////
		// Parameter 2 must be character
		//////
			if (!iVariable_isValid(varHaystack) || !iVariable_isTypeCharacter(varHaystack))
			{
				iError_reportByNumber(thisCode, _ERROR_P2_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varHaystack), false);
				return(NULL);
			}


		//////////
		// Parameter 3 is optional, but if present...
		//////
			if (iVariable_isValid(varOccurrence))
			{
				// ...it must be numeric
				if (!iVariable_isTypeNumeric(varOccurrence))
				{
					iError_reportByNumber(thisCode, _ERROR_P3_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varOccurrence), false);
					return(NULL);
				}

				// Grab the occurrence
				lnOccurrence = iiVariable_getAs_s32(thisCode, varOccurrence, false, &error, &errorNum);
				if (error)	{	iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varOccurrence), false);	return(NULL);	}

				// Validate that the occurrence is
				if (lnOccurrence <= 0)
				{
					iError_report(thisCode, (cu8*)"Parameter 3 must be 1 or greater", false);
					return(NULL);
				}

			} else {
				// The first occurrence is what we're after
				lnOccurrence = 1;
			}


		//////////
		// Create the return variable
		//////
			result = iVariable_create(thisCode, _VAR_TYPE_S32, NULL, true);
			if (!result)
			{
				iError_report(thisCode, cgcInternalError, false);
				return(NULL);
			}


		//////////
		// If either string has a zero length, or the needle is bigger than the haystack, we cannot find it
		//////
			if (varNeedle->value.length == 0 || varHaystack->value.length == 0 || varNeedle->value.length > varHaystack->value.length)
				return(result);


		//////////
		// Determine where
		//////
			if (tnFoundCount)
			{
				// They want to find all of the occurrences
				lnStart			= 0;
				lnInc			= 1;
				lnStopper		= varHaystack->value.length - varNeedle->value.length + 1;
				lnOccurrence	= varHaystack->value.length;

			} else if (tlScanBackward) {
				// Scan from the back of the string to the start
				lnStart		= varHaystack->value.length - varNeedle->value.length;
				lnInc		= -1;
				lnStopper	= -1;

			} else {
				// Scan from the front of the string to the end
				lnStart		= 0;
				lnInc		= 1;
				lnStopper	= varHaystack->value.length - varNeedle->value.length + 1;
			}


		//////////
		// Scan through the text
		//////
			for (lnI = lnStart, lnFoundCount = 0; lnI != lnStopper; lnI += lnInc)
			{
				//////////
				// Compare this portion
				//////
					if (tlCaseSensitive)
					{
						// Case-sensitive
						if (memcmp(varNeedle->value.data, varHaystack->value.data + lnI, varNeedle->value.length) == 0)
							++lnFoundCount;		// Here's a match

					} else {
						// Case-insensitive
						if (_memicmp(varNeedle->value.data, varHaystack->value.data + lnI, varNeedle->value.length) == 0)
							++lnFoundCount;		// Here's a match
					}


				//////////
				// See if we're done
				//////
					if (lnFoundCount == lnOccurrence)
					{
						// Store the found location
						*(s32*)result->value.data_s32 = lnI + 1;

						// We're done, exit
						break;
					}
			}


		//////////
		// Update the found count if it was requested
		//////
			if (tnFoundCount)
				*tnFoundCount = lnFoundCount;


		//////////
		// Indicate our status
		//////
			return(result);
	}




//////////
//
// Function: ATN2()
// Returns in radians the arc tangent of the x,y numeric expression
//
//////
// Version 0.56
// Last update:
//     Mar.18.2015
//////
// Change log:
//     Mar.18.2015 - Initial creation
//////
// Parameters:
//     p1			-- Numeric or floating point
//     p2			-- Numeric or floating point
//
//////
// Returns:
//    ATN2(y,x)
//////
// Example:
//    ? ATN2(5,3)		&& Display 1.03
//////
	SVariable* function_atn2(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varY = returnsParams->params[0];
		SVariable* varX = returnsParams->params[1];


		// Return atn2
		return(ifunction_numbers_common(thisCode, varY, varX, NULL, _FP_COMMON_ATN2, _VAR_TYPE_F64, false, false, returnsParams));
	}




//////////
//
// Function: BETWEEN()
// Determines whether the value of an expression is inclusively
// between the values of two expressions of the same type.
//
//////
// Version 0.57
// Last update:
//     Mar.23.2015
//////
// Change log:
//     Mar.23.2015 - Initial creation by Stefano D'Amico
//////
// Parameters:
//     varValue		-- Specifies an expression to evaluate.
//     varLowValue	-- Specifies the lower value in the range.
//     varHighValue	-- Specifies the upper value in the range.
//
//////
// Returns:
//    Logical		-- .t. if the item is inclusively between the values of two expressions of the same type, .f. otherwise
//////
	SVariable* function_between(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable*	varValue		= returnsParams->params[0];
		SVariable*	varLowValue		= returnsParams->params[1];
		SVariable*	varHighValue	= returnsParams->params[2];
		s32			lnI, lnType, lnComp;
		bool		llInRange;
		SVariable*	result;
		u32			errorNum;
        bool		error;


		//////////
		// Parameters 1, 2 and 3 must be present
		//////
			if (!iVariable_isValid(varValue))
			{
				iError_reportByNumber(thisCode, _ERROR_P1_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varValue), false);
				return(NULL);
			}
			if (!iVariable_isValid(varLowValue))
			{
				iError_reportByNumber(thisCode, _ERROR_P2_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varLowValue), false);
				return(NULL);
			}
			if (!iVariable_isValid(varHighValue))
			{
				iError_reportByNumber(thisCode, _ERROR_P3_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varHighValue), false);
				return(NULL);
			}


		//////////
		// Each type must be fundamentally the same type
		//////
			for (lnI = 1, lnType = iVariable_fundamentalType(thisCode, varValue); lnI <= 3 && returnsParams->params[lnI]; lnI++)
			{
				//////////
				// Make sure this variable type matches the test value
				//////
					if (iVariable_fundamentalType(thisCode, returnsParams->params[lnI]) != lnType)
					{
						// The types do not match
						iError_reportByNumber(thisCode, _ERROR_DATA_TYPE_MISMATCH, iVariable_getRelatedComp(thisCode, returnsParams->params[lnI]), false);
						return(NULL);
					}

			}


		//////////
		// Compare value and low
		//////
			lnComp = iVariable_compare(thisCode, varValue, varLowValue, false, &error, &errorNum);
			if (error)
			{
				iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varLowValue), false);
				return(NULL);
			}

			// If the value is greater than or equal to the low value, we're good
			llInRange = (lnComp == 1/*greater than*/ || lnComp == 0/*equal to*/);


		//////////
		// If we're still in range,
		// compare value and high
		//////
			if (llInRange)
			{
				// Compare value to high
				lnComp = iVariable_compare(thisCode, varValue, varHighValue, false, &error, &errorNum);
				if (error)
				{
					iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varHighValue), false);
					return(NULL);
				}		

				// If value is less than or equal to high, we're good
				llInRange = (lnComp == -1/*less than*/ || lnComp == 0/*equal to*/);
			}


		//////////
		// Based on the result, create the return(result)
		//////
			result = iVariable_createAndPopulate_byText(thisCode, _VAR_TYPE_LOGICAL, ((llInRange) ? (s8*)&_LOGICAL_TRUE : (s8*)&_LOGICAL_FALSE), 1, false);
			if (!result)
				iError_reportByNumber(thisCode, _ERROR_INTERNAL_ERROR, iVariable_getRelatedComp(thisCode, varValue), false);


		//////////
		// Indicate our result
		//////
			return(result);
	}




//////////
//
// Function: BITS()
// Creates the closest larger 2^n numeric value than the size indicated by bits.
//
//////
// Version 0.56
// Last update:
//     Mar.22.2015
//////
// Change log:
//     Mar.22.2015 - Initial creation
//////
// Parameters:
//     varBits		-- A sequence of binary bits
//
//////
// Returns:
//    Numeric		-- Input bits converted to an unsigned integer of the appropriate size (up to 64-bits)
//////
	SVariable* function_bits(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varBits		= returnsParams->params[0];
		SVariable* varBitWidth	= returnsParams->params[1];


		// Return bits
		return(ifunction_bits_common(thisCode, varBits, varBitWidth, returnsParams));
	}

	SVariable* ifunction_bits_common(SThisCode* thisCode, SVariable* varBits, SVariable* varBitWidth, SReturnsParams* returnsParams)
	{
		s8			c;
		u8			lnOrValue;
		s32			lnWidth, lnBit;
		SVariable*	result;
		bool		error;
		u32			errorNum;


		//////////
		// varBits must be character
		//////
			if (!iVariable_isValid(varBits) || !iVariable_isTypeCharacter(varBits) || varBits->value.length > 64)
			{
				iError_reportByNumber(thisCode, _ERROR_P1_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varBits), false);
				return(NULL);
			}


		//////////
		// If present, varBitWidth must be numeric
		//////
			if (varBitWidth)
			{
				if (!iVariable_isValid(varBitWidth) || !iVariable_isTypeNumeric(varBitWidth))
				{
					iError_reportByNumber(thisCode, _ERROR_P2_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varBitWidth), false);
					return(NULL);
				}

				// Grab the width
				lnWidth = iiVariable_getAs_s32(thisCode, varBitWidth, false, &error, &errorNum);
				if (error)
				{
					iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varBitWidth), false);
					return(NULL);
				}

				// Must be 8, 16, 32, or 64
				if (lnWidth != 8 && lnWidth != 16 && lnWidth != 32 && lnWidth != 64)
				{
					iError_reportByNumber(thisCode, _ERROR_PARAMETER_MUST_BE_8_16_32_64, iVariable_getRelatedComp(thisCode, varBitWidth), false);
					return(NULL);
				}

			} else {
				// It will be sized based on what is required for the value it contains
				lnWidth = -1;
			}


		//////////
		// Make sure every digit in the character string is either a '1' or '0', and the total is 
		//////
			for (lnBit = 0; lnBit < varBits->value.length; lnBit++)
			{
				// Grab the character
				c = varBits->value.data_s8[lnBit];

				// Is it anything other than binary digits
				if (c != '0' && c != '1')
				{
					iError_reportByNumber(thisCode, _ERROR_P1_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varBits), false);
					return(NULL);
				}
			}
			// When we get here, we know how wide it is maximum
			if (lnWidth == -1)
			{
				// Always default to 64-bit or 32-bit
				if (lnBit > 32)		lnWidth = 64;
				else				lnWidth = 32;
			}


		//////////
		// Make sure our result will fit
		//////
			if (lnBit > lnWidth)
			{
				iError_reportByNumber(thisCode, _ERROR_TOO_BIG_FOR_TARGET, iVariable_getRelatedComp(thisCode, varBits), false);
				return(NULL);
			}


		//////////
		// Create our result
		//////
			switch (lnWidth)
			{
				case 8:
					result = iVariable_create(thisCode, _VAR_TYPE_U8, NULL, true);
					break;
				case 16:
					result = iVariable_create(thisCode, _VAR_TYPE_U16, NULL, true);
					break;
				case 32:
					result = iVariable_create(thisCode, _VAR_TYPE_U32, NULL, true);
					break;
				case 64:
					result = iVariable_create(thisCode, _VAR_TYPE_U64, NULL, true);
					break;
				default:
					iError_reportByNumber(thisCode, _ERROR_INTERNAL_ERROR, iVariable_getRelatedComp(thisCode, varBits), false);
					return(NULL);
			}
		

		//////////
		// Are we good?
		//////
			if (!result)
				iError_reportByNumber(thisCode, _ERROR_INTERNAL_ERROR, iVariable_getRelatedComp(thisCode, varBits), false);


		//////////
		// Populate
		//////
			if (result)
			{
				// Iterate through each bit loading in its value
				for (lnBit = 0; lnBit < varBits->value.length; lnBit++)
				{

					//////////
					// Grab our OR value
					//////
						lnOrValue = varBits->value.data_u8[lnBit] - (u8)'0';


					//////////
					// Shift our destination
					//////
						switch (result->varType)
						{
							case _VAR_TYPE_U8:
								result->value.data_u8[0] <<= 1;
								result->value.data_u8[0] |= lnOrValue;
								break;

							case _VAR_TYPE_U16:
								result->value.data_u16[0] <<= 1;
								result->value.data_u16[0] |= lnOrValue;
								break;

							case _VAR_TYPE_U32:
								result->value.data_u32[0] <<= 1;
								result->value.data_u32[0] |= lnOrValue;
								break;

							case _VAR_TYPE_U64:
								result->value.data_u64[0] <<= 1;
								result->value.data_u64[0] |= lnOrValue;
								break;
						}

				}
			}


		//////////
		// Return our result
		//////
			return(result);
	}




//////////
//
// Function: BITS8()
// Creates an 8-bit integer populated with the indicated bits.
//
//////
// Version 0.56
// Last update:
//     Mar.22.2015
//////
// Change log:
//     Mar.22.2015 - Initial creation
//////
// Parameters:
//     varBits		-- A sequence of binary bits
//
//////
// Returns:
//    Numeric		-- Input bits converted to an 8-bit unsigned integer
//////
	SVariable* function_bits8(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varBits = returnsParams->params[0];


		// Return bits8()
		return(ifunction_bits_common(thisCode, varBits, varEight, returnsParams));
	}




//////////
//
// Function: BITS16()
// Creates a 16-bit integer populated with the indicated bits.
//
//////
// Version 0.56
// Last update:
//     Mar.22.2015
//////
// Change log:
//     Mar.22.2015 - Initial creation
//////
// Parameters:
//     varBits		-- A sequence of binary bits
//
//////
// Returns:
//    Numeric		-- Input bits converted to an 16-bit unsigned integer
//////
	SVariable* function_bits16(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varBits = returnsParams->params[0];


		// Return bits16()
		return(ifunction_bits_common(thisCode, varBits, varSixteen, returnsParams));
	}




//////////
//
// Function: BITS32()
// Creates a 32-bit integer populated with the indicated bits.
//
//////
// Version 0.56
// Last update:
//     Mar.22.2015
//////
// Change log:
//     Mar.22.2015 - Initial creation
//////
// Parameters:
//     varBits		-- A sequence of binary bits
//
//////
// Returns:
//    Numeric		-- Input bits converted to an 32-bit unsigned integer
//////
	SVariable* function_bits32(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varBits = returnsParams->params[0];


		// Return bits32()
		return(ifunction_bits_common(thisCode, varBits, varThirtyTwo, returnsParams));
	}




//////////
//
// Function: BITS64()
// Creates a 64-bit integer populated with the indicated bits.
//
//////
// Version 0.56
// Last update:
//     Mar.22.2015
//////
// Change log:
//     Mar.22.2015 - Initial creation
//////
// Parameters:
//     varBits		-- A sequence of binary bits
//
//////
// Returns:
//    Numeric		-- Input bits converted to an 64-bit unsigned integer
//////
	SVariable* function_bits64(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varBits = returnsParams->params[0];


		// Return bits64()
		return(ifunction_bits_common(thisCode, varBits, varSixtyFour, returnsParams));
	}




//////////
//
// Function: BITSLICE()
// Extracts a bit portion from a value.
//
//////
// Version 0.56
// Last update:
//     Mar.22.2015
//////
// Change log:
//     Mar.22.2015 - Initial creation
//////
// Parameters:
//     varValue		-- Numeric value from which to extract.
//     varBitStart	-- Starting bit position (little-endian, so starting position will be greatest bit value)
//     varBitEnd    -- Ending bit position (little-endian, so ending position will be lowest bit value)
//
//////
// Returns:
//    Numeric		-- The extracted bits as a numeric unsigned integer of the same size as the original.
//////
	SVariable* function_bitslice(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varValue		= returnsParams->params[0];
		SVariable* varBitStart	= returnsParams->params[1];
		SVariable* varBitEnd	= returnsParams->params[2];


		// Not yet completed
		iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, NULL, false);
		return(NULL);
	}




//////////
//
// Function: BITSTR()
// Converts a value into its bit pattern.
//
//////
// Version 0.56
// Last update:
//     Mar.22.2015
//////
// Change log:
//     Mar.22.2015 - Initial creation
//////
// Parameters:
//     varValue		-- Numeric value from which to extract.
//     varLength	-- Number of bits to extract, including leading 0s
//
//////
// Returns:
//    Character		-- The extracted bits as a character string
//////
	SVariable* function_bitstr(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varValue		= returnsParams->params[0];
		SVariable* varLength	= returnsParams->params[1];


		// Not yet completed
		iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, NULL, false);
		return(NULL);
	}




//////////
//
// Function: BLU()
// Retrieves the blue channel from an RGBA or BGRA color.
//
//////
// Version 0.56
// Last update:
//     Mar.16.2015
//////
// Change log:
//     Mar.16.2015 - Initial creation
//////
// Parameters:
//     varColor		-- Numeric, a color (0..(2^32)-1)
//
//////
// Returns:
//    Numeric	-- Input number converted to ASCII value number
//////
	SVariable* function_blu(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varColor = returnsParams->params[0];


		// Return blu
		return(ifunction_color_common(thisCode, varColor, 0x00ff0000, 16, returnsParams));
	}




//////////
//
// Function: BGR()
// Returns the BGR() of the three input values.
//
//////
// Version 0.56   (Determine the current version from the header in vjr.cpp)
// Last update:
//     Mar.16.2015
//////
// Change log:
//     Mar.16.2015 - Initial creation
//////
// Parameters:
//     pBlu			-- Blue, in the range 0..255, or 0.0..1.0
//     pGrn			-- Green, in the range 0..255, or 0.0..1.0
//     pRed			-- Red, in the range 0..255, or 0.0..1.0
//
//////
// Returns:
//    Numeric		-- Constructed system-wide RGBA() integer
//
//////
	SVariable* function_bgr(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varBlu = returnsParams->params[0];
		SVariable* varGrn = returnsParams->params[1];
		SVariable* varRed = returnsParams->params[2];


		// Return bgr
		return(ifunction_rgba_common(thisCode, varRed, varGrn, varBlu, NULL, returnsParams));
	}




//////////
//
// Function: BGRA()
// Returns the BGRA() of the four input values.
//
//////
// Version 0.56   (Determine the current version from the header in vjr.cpp)
// Last update:
//     Mar.16.2015
//////
// Change log:
//     Mar.16.2015 - Initial creation
//////
// Parameters:
//     pBlu			-- Blue, in the range 0..255, or 0.0..1.0
//     pGrn			-- Green, in the range 0..255, or 0.0..1.0
//     pRed			-- Red, in the range 0..255, or 0.0..1.0
//     pAlp			-- Alpha, in the range 0..255, or 0.0..1.0
//
//////
// Returns:
//    Numeric		-- Constructed system-wide RGBA() integer
//
//////
	SVariable* function_bgra(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varBlu = returnsParams->params[0];
		SVariable* varGrn = returnsParams->params[1];
		SVariable* varRed = returnsParams->params[2];
		SVariable* varAlp = returnsParams->params[3];


		// Return bgra
		return(ifunction_rgba_common(thisCode, varRed, varGrn, varBlu, varAlp, returnsParams));
	}




//////////
//
// Function: CDOW()
// Returns the day of the week from a given Date or DateTime expression.
//
//////
// Version 0.57
// Last update:
//     Apr.04.2015
//////
// Change log:
//     Apr.04.2015 - Initial creation by Stefano D'Amico
//////
// Parameters:
//     p1			-- Date or DateTime
//
//////
// Returns:
//    CDOW() returns the name of the day of the week as a string in proper noun format.
//////
// Example:
//	  dt = datetime()	&& Apr.06.2015
//    ? CDOW(dt)		&& Displays Monday
//    ? CDOW()          && Displays current date's character day of week
//////
	static cs8 cgCdowData[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };

	SVariable* function_cdow(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varParam = returnsParams->params[0];
		
		u32			lnYear, lnMonth, lnDay;
		s8			lnDow;
		SYSTEMTIME	lst;
		SVariable*	result;


		//////////
		// If provided, parameter 1 must be date or datetime
		//////
			if (varParam)
			{
// TODO:  Must also support DATETIMEX at some point
				if (!iVariable_isValid(varParam) || !(iVariable_isTypeDate(varParam) || iVariable_isTypeDatetime(varParam)))
				{
					iError_reportByNumber(thisCode, _ERROR_INVALID_ARGUMENT_TYPE_COUNT, iVariable_getRelatedComp(thisCode, varParam), false);
					return(NULL);
				}

			//////////
			// Grab year, month, day from datetime or date
			//////
				if (iVariable_isTypeDatetime(varParam))			iiVariable_computeYyyyMmDd_fromJulian		(varParam->value.data_dt->julian,	&lnYear, &lnMonth, &lnDay);
				else /* date */									iiVariable_computeYyyyMmDd_fromYYYYMMDD		(varParam->value.data_u8,			&lnYear, &lnMonth, &lnDay);

			} else {
				// Use the current date
				if (_settings)		iTime_getLocalOrSystem(&lst, propGet_settings_TimeLocal(_settings));
				else				GetLocalTime(&lst);
				lnYear	= lst.wYear;
				lnMonth	= lst.wMonth;
				lnDay	= lst.wDay;
			}


		//////////
		// Adjust for leap year calculation
		//////
			if (lnMonth <= 2)
				--lnYear;									// Leap year is in February


		//////////
		// Compute the day of week
		//////
			lnDow	= (		lnYear +						// Base year
							(lnYear / 4)					// Leap years
						-	(lnYear / 100)					// Not centuries not evenly divisible by 100
						+	(lnYear / 400)					// And centuries evenly divisible by 400
						+	cgCdowData[lnMonth - 1]			// Plus the "magic" month number
						+	lnDay			)				// Plus day of month
					/*-------------------------------*/
						%	7;								// Modulo to a day of week


		//////////
		// Create our result
		//////
			result = iVariable_createAndPopulate_byText(thisCode, _VAR_TYPE_CHARACTER, (cs8*)cgcDayOfWeekNames[lnDow], (u32)strlen(cgcDayOfWeekNames[lnDow]), false);
			if (!result)
				iError_reportByNumber(thisCode, _ERROR_INTERNAL_ERROR, iVariable_getRelatedComp(thisCode, varParam), false);


		//////////
		// Indicate our result
		//////
			return(result);

	}




//////////
//
// Function: CEILING()
// Returns the next highest integer that is greater than or equal to the specified numeric expression.
//
//////
// Version 0.56
// Last update:
//     Mar.16.2015
//////
// Change log:
//     Mar.16.2015 - Initial creation by Stefano D'Amico
//////
// Parameters:
//     p1			-- Numeric or floating point
//
//////
// Returns:
//    CEILING(n) of the value in p1
//////
// Example:
//    ? CEILING(2.2)		&& Display 3
//////
    SVariable* function_ceiling(SThisCode* thisCode, SReturnsParams* returnsParams)
    {
		SVariable* varNumber = returnsParams->params[0];


        // Return ceiling
		return(ifunction_numbers_common(thisCode, varNumber, NULL, NULL, _FP_COMMON_CEILING, _VAR_TYPE_S64, propGet_settings_ncset_ceilingFloor(_settings), false, returnsParams));
	}



//////////
//
// Function: CHR()
// Takes a numeric input in the range 0..255, and converts it to its ASCII character.
//
//////
// Version 0.56
// Last update:
//     Jul.05.2014
//////
// Change log:
//     Jul.05.2014 - Initial creation
//////
// Parameters:
//     p1			-- Numeric, in the range 0..255
//
//////
// Returns:
//    Character		-- Input number converted to character
//////
    SVariable* function_chr(SThisCode* thisCode, SReturnsParams* returnsParams)
    {
		SVariable*	varNumber = returnsParams->params[0];
        s32			value;
		u32			errorNum;
        bool		error;
        SVariable*	result;
		u8			buffer[16];


		//////////
		// Parameter 1 must be numeric
		//////
			if (!iVariable_isValid(varNumber) || !iVariable_isTypeNumeric(varNumber))
			{
				iError_reportByNumber(thisCode, _ERROR_P1_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varNumber), false);
				return(NULL);
			}


		//////////
        // It must be in the range 0..255
		//////
			value = iiVariable_getAs_s32(thisCode, varNumber, false, &error, &errorNum);
			if (error)
			{
				// The iVariable_getAs_s32() function reported an error.
				// This means the user is trying to obtain an integer value from a logical, or something similar.
				iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varNumber), false);
				return(NULL);

			} else if (value > 255 || value < 0) {
				// We report our own error
				iError_report(thisCode, (u8*)"Parameter must be in the range 0..255", false);
				return(NULL);
			}


		//////////
        // Create our return result
		//////
	        result = iVariable_create(thisCode, _VAR_TYPE_CHARACTER, NULL, true);
			if (!result)
			{
				iError_report(thisCode, (u8*)"Internal error.", false);
				return(NULL);
			}


		//////////
        // Populate the result as an ASCII character
		//////
	        buffer[0] = (u8)value;
			buffer[1] = 0;
			iDatum_duplicate(&result->value, buffer, 1);


		//////////
        // Return our converted result
		//////
	        return(result);
    }




//////////
//
// Function: CHRTRAN()
// Character transformation
//
//////
// Version 0.56
// Last update:
//     Aug.21.2014
//////
// Change log:
//     Aug.21.2014 - Initial creation
//////
// Parameters:
//     pOriginalString		-- The string being updated
//     pSearch				-- The search characters
//     pReplace             -- The characters to replace when found
//
//////
// Returns:
//    A copy of the pOriginalString with everything converted.
//
//////
	SVariable* function_chrtran(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varString	= returnsParams->params[0];
		SVariable* varSearch	= returnsParams->params[1];
		SVariable* varReplace	= returnsParams->params[2];


		// Return chrtran
		return(ifunction_chrtran_common(thisCode, varString, varSearch, varReplace, true, returnsParams));
	}

	SVariable* function_chrtranc(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varString	= returnsParams->params[0];
		SVariable* varSearch	= returnsParams->params[1];
		SVariable* varReplace	= returnsParams->params[2];


		// Return chrtranc
		return(ifunction_chrtran_common(thisCode, varString, varSearch, varReplace, false, returnsParams));
	}

	SVariable* ifunction_chrtran_common(SThisCode* thisCode, SVariable* varString, SVariable* varSearch, SVariable* varReplace, bool tlCaseSensitive, SReturnsParams* returnsParams)
	{
		s8			c1, c2;
		s32			lnSrc, lnDst, lnSearch;
		bool		llFound;
        SVariable*	result;


		//////////
		// Parameter 1 must be character
		//////
			if (!iVariable_isValid(varString) || !iVariable_isTypeCharacter(varString))
			{
				iError_reportByNumber(thisCode, _ERROR_P1_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varString), false);
				return(NULL);
			}


		//////////
		// Parameter 2 must be character
		//////
			if (!iVariable_isValid(varSearch) || !iVariable_isTypeCharacter(varSearch))
			{
				iError_reportByNumber(thisCode, _ERROR_P2_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varSearch), false);
				return(NULL);
			}


		//////////
		// Parameter 3 is optional, but must be character if present
		//////
			if (!iVariable_isValid(varReplace))
			{
				// They didn't provide a 3rd parameter, so we'll use a pseudo placeholder which is an empty string
				varReplace = varEmptyString;

			} else if (!iVariable_isTypeCharacter(varReplace)) {
				// It is invalid
				iError_reportByNumber(thisCode, _ERROR_P3_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varReplace), false);
				return(NULL);
			}


		//////////
		// Allocate a copy of the original string
		//////
			result = iVariable_createAndPopulate_byText(thisCode, _VAR_TYPE_CHARACTER, varString->value.data_u8, varString->value.length, false);

			// If the original string is empty, or the characters to search for are empty, then we don't need to do anything
			if (varString->value.length == 0 || varSearch->value.length == 0)
				return(result);


		//////////
		// Iterate through the string and update as we go
		//////
			for (lnSrc = 0, lnDst = 0; lnSrc < result->value.length; lnSrc++)
			{
				// Grab this character
				c1 = result->value.data[lnSrc];

				// Adjust the case if need be
				if (!tlCaseSensitive)
				{
					if (c1 >= 'A' && c1 <= 'Z')
						c1 += 0x20;
				}

				// Search the conversion string
				llFound = false;
				for (lnSearch = 0; lnSearch < varSearch->value.length; lnSearch++)
				{
					// Grab this character
					c2 = varSearch->value.data[lnSearch];

					// Adjust the case if necessary
					if (!tlCaseSensitive)
					{
						// Case insensitive, convert if need be
						if (c2 >= 'A' && c2 <= 'Z')
							c2 += 0x20;
					}

					// Is this character a match?
					if (c1 == c2)
					{
						// Indicate we found it
						llFound = true;

						// We need to perform the replace
						if (lnSearch < varReplace->value.length)
						{
							// We replace it with the character that's there
							result->value.data[lnDst] = varReplace->value.data[lnSearch];

						} else {
							// There is no translation character, so we just delete this character
							// To do that, we decrease our lnDst because it will be increased below
							--lnDst;
						}

						// We're done with this one because we found its match
						break;
					}
				}

				// When we get here, we either found the character or not
				if (!llFound && lnSrc != lnDst)
				{
					// We need to copy this character over
					result->value.data[lnDst] = result->value.data[lnSrc];
				}

				// Move our destination forward
				++lnDst;
			}


		//////////
		// When we get here, lnDst indicates how long the output string is
		//////
			result->value.length = lnDst;


		//////////
		// Return our final string
		/////
			return(result);
	}




//////////
//
// Function: CMONTH()
// Returns the name of the month from a given date or DateTime expression.
//
//////
// Version 0.57
// Last update:
//     Apr.05.2015
//////
// Change log:
//     Apr.05.2015 - Initial creation by Stefano D'Amico
//////
// Parameters:
//     p1			-- Date or DateTime
//
//////
// Returns:
//    CMONTH( ) returns the name of the month as a string in proper noun format.
//////
// Example:
//	  dt = datetime()	&& Apr.06.2015
//    ? CMONTH(dt)		&& Displays April
//    ? CMONTH()        && Displays current date's character month
//////
	SVariable* function_cmonth(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varParam = returnsParams->params[0];

		u32			lnYear, lnMonth, lnDay;
		s8			lnMonthIdx;
		SYSTEMTIME	lst;
		SVariable*	result;


		//////////
		// If provided, parameter 1 must be date or datetime
		//////
			if (varParam)
			{
	// TODO:  Must also support DATETIMEX at some point
				if (!iVariable_isValid(varParam) || !(iVariable_isTypeDate(varParam) || iVariable_isTypeDatetime(varParam)))
				{
					iError_reportByNumber(thisCode, _ERROR_INVALID_ARGUMENT_TYPE_COUNT, iVariable_getRelatedComp(thisCode, varParam), false);
					return(NULL);
				}


				//////////
				// Grab year, month, day from datetime or date
				//////
					if (iVariable_isTypeDatetime(varParam))			iiVariable_computeYyyyMmDd_fromJulian		(varParam->value.data_dt->julian,	&lnYear, &lnMonth, &lnDay);
					else /* date */									iiVariable_computeYyyyMmDd_fromYYYYMMDD		(varParam->value.data_u8,			&lnYear, &lnMonth, &lnDay);


			} else {
				// Use the current date
				if (_settings)		iTime_getLocalOrSystem(&lst, propGet_settings_TimeLocal(_settings));
				else				GetLocalTime(&lst);
				lnYear	= lst.wYear;
				lnMonth	= lst.wMonth;
				lnDay	= lst.wDay;
			}


		//////////
		// Compute index
		//////
			lnMonthIdx = max(min(lnMonth, 12), 1) - 1;		// Force into range 1..12, then backoff one for base-0 array reference


		//////////
		// Create our result
		//////
			result = iVariable_createAndPopulate_byText(thisCode, _VAR_TYPE_CHARACTER, (cs8*)cgcMonthNames[lnMonthIdx], (u32)strlen(cgcMonthNames[lnMonthIdx]), false);
			if (!result)
				iError_reportByNumber(thisCode, _ERROR_INTERNAL_ERROR, iVariable_getRelatedComp(thisCode, varParam), false);


		//////////
		// Indicate our result
		//////
			return(result);

	}




//////////
//
// Function: COLORIZE()
// Colorizes an existing color by blending two colors.
//
//////
// Version 0.56
// Last update:
//     Mar.16.2015
//////
// Change log:
//     Mar.16.2015 - Initial creation
//////
// Parameters:
//     varColor			-- The original color
//     varColorTarget	-- The color to blend in
//     varPercentage	-- (Optional) How much to blend
//
//////
// Returns:
//    Numeric			-- The resulting colorized color
//
//////
	SVariable* function_colorize(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varColor			= returnsParams->params[0];
		SVariable* varColorTarget	= returnsParams->params[1];
		SVariable* varPercentage	= returnsParams->params[2];


		// Return colorize
		return(ifunction_colorize_common(thisCode, varColor, varColorTarget, varPercentage, true, returnsParams));
	}

	SVariable* ifunction_colorize_common(SThisCode* thisCode, SVariable* varColor, SVariable* varColorTarget, SVariable* varPercentage, bool tlApplyColorTarget, SReturnsParams* returnsParams)
	{
		u32			lnColor, lnColorTarget, lnColorNew;
		f32			lfRedC, lfGrnC, lfBluC, lfAlpC;		// varColor
		f32			lfRedT, lfGrnT, lfBluT, lfAlpT;		// varColorTarget
		f32			lfAlp, lfMalp, lfGray, lfRedNew, lfGrnNew, lfBluNew, lfAlpNew;
		bool		error;
		u32			errorNum;
		SVariable*	result;


		//////////
		// Color must be numeric
		//////
			if (!iVariable_isValid(varColor) || !iVariable_isTypeNumeric(varColor))
			{
				iError_reportByNumber(thisCode, _ERROR_PARAMETER_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varColor), false);
				return(NULL);
			}


		//////////
		// If present, varColorTarget must be numeric
		//////
			if (tlApplyColorTarget)
			{
				if (!iVariable_isValid(varColorTarget) || !iVariable_isTypeNumeric(varColorTarget))
				{
					iError_reportByNumber(thisCode, _ERROR_PARAMETER_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varColorTarget), false);
					return(NULL);
				}
			}


		//////////
		// Grab the percentage
		//////
			if (varPercentage)
			{
				// Must be floating point
				if (!iVariable_isValid(varPercentage) || !iVariable_isTypeFloatingPoint(varPercentage))
				{
					iError_reportByNumber(thisCode, _ERROR_PARAMETER_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varPercentage), false);
					return(NULL);
				}

				// Grab the value
				lfAlp = iiVariable_getAs_f32(thisCode, varPercentage, false, &error, &errorNum);
				if (error)	{	iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varPercentage), false);	return(NULL);	}

				// Must be in the range 0.0 to 1.0
				if (lfAlp < 0.0f || lfAlp > 1.0f)
				{
					iError_reportByNumber(thisCode, _ERROR_OUT_OF_RANGE, iVariable_getRelatedComp(thisCode, varPercentage), false);
					return(NULL);
				}
				// If we get here, we're good

			} else {
				// They didn't specify a percentage, use default values
				if (tlApplyColorTarget)		lfAlp = 0.5f;		// colorize() 50% / 50%
				else						lfAlp = 1.0f;		// grayscale() 100%
			}

			// Compute our malp
			lfMalp = 1.0f - lfAlp;


		//////////
		// Grab the color
		//////
			// Extract the color
			lnColor = iiVariable_getAs_u32(thisCode, varColor, false, &error, &errorNum);
			if (error)	{	iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varColor), false);	return(NULL);	}

			// Extract channels
			lfRedC = (f32)red(lnColor);
			lfGrnC = (f32)grn(lnColor);
			lfBluC = (f32)blu(lnColor);
			lfAlpC = (f32)alp(lnColor);


		//////////
		// Grab the color target
		//////
			if (tlApplyColorTarget)
			{
				// Extract the color target
				lnColorTarget = iiVariable_getAs_u32(thisCode, varColorTarget, false, &error, &errorNum);
				if (error)	{	iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varColor), false);	return(NULL);	}

				// Extract channels
				lfRedT = (f32)red(lnColorTarget);
				lfGrnT = (f32)grn(lnColorTarget);
				lfBluT = (f32)blu(lnColorTarget);
				lfAlpT = (f32)alp(lnColorTarget);


				//////////
				// Generate the combined color (original color * malp) + (color target * alp)
				//////
					lfRedNew	= (lfRedC * lfMalp) + (lfRedT * lfAlp);
					lfGrnNew	= (lfGrnC * lfMalp) + (lfGrnT * lfAlp);
					lfBluNew	= (lfBluC * lfMalp) + (lfBluT * lfAlp);
					lfAlpNew	= (lfAlpC * lfMalp) + (lfAlpT * lfAlp);


			} else {
				// We are grayscaling
				lfGray		= max(min((lfRedC * 0.35f) + (lfGrnC * 0.54f) + (lfBluC * 0.11f), 1.0f), 0.0f);

				// Generate the new grayscaled color (original color * malp) + (grayscale * alp)
				lfRedNew	= (lfRedC * lfMalp) + (lfGray * lfAlp);
				lfGrnNew	= (lfGrnC * lfMalp) + (lfGray * lfAlp);
				lfBluNew	= (lfBluC * lfMalp) + (lfGray * lfAlp);
				lfAlpNew	= (lfAlpC * lfMalp) + (lfGray * lfAlp);
			}


		//////////
		// Construct the new color into an integer
		//////
			lnColorNew = rgba((u32)lfRedNew, (u32)lfGrnNew, (u32)lfBluNew, (u32)lfAlpNew);


		//////////
		// Construct our result
		//////
			result = iVariable_create(thisCode, _VAR_TYPE_U32, NULL, true);
			if (!result)
			{
				iError_reportByNumber(thisCode, _ERROR_INTERNAL_ERROR, NULL, false);
				return(NULL);
			}


		//////////
		// Populate and return our result
		//////
			*result->value.data_u32 = lnColorNew;
			return(result);
	}




//////////
//
// Function: COS()
// Returns the cosine of a numeric expression.
//
//////
// Version 0.56
// Last update:
//     Mar.17.2015
//////
// Change log:
//     Mar.17.2015 - Initial creation by Stefano D'Amico
//////
// Parameters:
//     p1			-- Numeric or floating point
//
//////
// Returns:
//    COS(n) of the value in p1
//////
// Example:
//    ? COS(0)		&& Display 1.00
//////
    SVariable* function_cos(SThisCode* thisCode, SReturnsParams* returnsParams)
    {
		SVariable* varNumber = returnsParams->params[0];


		// Return cos
		return(ifunction_numbers_common(thisCode, varNumber, NULL, NULL, _FP_COMMON_COS, _VAR_TYPE_F64, false, false, returnsParams));
	}



//////////
//
// Function: CREATEOBJECT()
// Instantiates and instance of the indicated class.
//
//////
// Version 0.56
// Last update:
//     Jul.12.2014
//////
// Change log:
//     Jul.12.2014 - Initial creation
//////
// Parameters:
//     pClassname	-- The name of the class
//     Note:  A future extension will allow parameters passed to the class's init() event
//
//////
// Returns:
//    Object		-- The class instance object is returned
//
//////
	SVariable* function_createobject(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable*	varClass = returnsParams->params[0];
		s32			lnObjType;
		SObject*	obj;
        SVariable*	result;


		//////////
		// Parameter 1 must be character
		//////
			if (!iVariable_isValid(varClass) || !iVariable_isTypeCharacter(varClass))
			{
				iError_reportByNumber(thisCode, _ERROR_P1_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varClass), false);
				return(NULL);
			}


		//////////
        // It must be at least one character long
		//////
			if (varClass->value.length == 0)
				iError_reportByNumber(thisCode, _ERROR_EMPTY_STRING, iVariable_getRelatedComp(thisCode, varClass), false);


		//////////
		// See if we know the class
		//////
			lnObjType = iiObj_getBaseclassType_byName(thisCode, varClass->value.data, varClass->value.length);
			if (lnObjType <= 0)
			{
				iError_report(thisCode, (cu8*)"Unknown class", false);
				return(NULL);
			}

			// Create our object
			obj = iObj_create(thisCode, lnObjType, NULL);
			if (!obj)
			{
				iError_report(thisCode, (cu8*)"Internal error on create object.", false);
				return(NULL);
			}


		//////////
        // Create our return result variable, which is a reference to the new object
		//////
	        result = iVariable_create(thisCode, _VAR_TYPE_OBJECT, NULL, true);
			if (!result)
			{
				iObj_delete(thisCode, &obj, true, true, true);
				iError_report(thisCode, (cu8*)"Internal error on create variable.", false);
				return(NULL);
			}

			// Store the object reference
			result->obj = obj;


		//////////
        // Return our converted result
		//////
	        return(result);
	}




//////////
//
// Function: CURDIR()
// Returns the current directory
//
//////
// Version 0.56
// Last Update:
//		Dec.25.2014
//////
// Change log:
//		Dec.25.2014 - Initial creation
//////
// Parameters:
//		none
//////
// Returns:
//		Character		-- Current directory
//////
	SVariable* function_curdir(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		u8			curdir[_MAX_PATH];
		SVariable*	result;


		// Get the current directory
		memset(curdir, 0, sizeof(curdir));
		GetCurrentDirectory(_MAX_PATH, (s8*)curdir);

		// Create the output variable
		result = iVariable_createAndPopulate_byText(thisCode, _VAR_TYPE_CHARACTER, curdir, (u32)strlen(curdir), false);
		if (!result)
			iError_reportByNumber(thisCode, _ERROR_INTERNAL_ERROR, NULL, false);

		// Indicate our result
		return(result);
	}




//////////
//
// Function: DATE()
// Returns the current local time, or uses the input variables to create the indicated date.
//
//////
// Version 0.57
// Last update:
//     Apr.04.2015
//////
// Change log:
//     Apr.04.2015 - Initial creation by Stefano D'Amico
//////
// Parameters:
//     pYear		-- (optional) Numeric, in the range 1600..2400
//     pMonth		-- (optional) Numeric, in the range 1..12
//     pDay			-- (optional) Numeric, in the range 1..(varies based on month+year, not more than 31)
//
//////
// Returns:
//    Date			-- Current date(), or input converted to date
//////
	SVariable* function_date(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable*	varYear			= returnsParams->params[0];
		SVariable*	varMonth		= returnsParams->params[1];
		SVariable*	varDay			= returnsParams->params[2];

		SVariable*	result;
		u32			errorNum;
		bool		error;
		SYSTEMTIME	lst;
		s8			buffer[16];


		// Have they provided us with data?
		if (!varYear)
		{
			// Nope, we are creating the current system time
			if (_settings)		iTime_getLocalOrSystem(&lst, propGet_settings_TimeLocal(_settings));
			else				GetLocalTime(&lst);

		} else {
			// They have provided us date parameters.
			// Default to 01/01/1600 for any date
			lst.wYear			= 1600;
			lst.wMonth			= 1;
			lst.wDay			= 1;


			//////////
			// pYear must be numeric, and in the range of 1600..2400
			//////
				if (iVariable_isValid(varYear))
				{
					// They gave us a pYear
					if (!iVariable_isTypeNumeric(varYear))
					{
						iError_report(thisCode, (cu8*)"Year must be numeric", false);
						return(NULL);
					}
					lst.wYear = (u16)iiVariable_getAs_s32(thisCode, varYear, false, &error, &errorNum);
					if (!error && (lst.wYear < 1600 || lst.wYear > 2400))
					{
						iError_reportByNumber(thisCode, _ERROR_OUT_OF_RANGE, iVariable_getRelatedComp(thisCode, varYear), false);
						return(NULL);
					}
				}


			//////////
			// pMonth must be numeric, and in the range of 1..12
			//////
				if (iVariable_isValid(varMonth))
				{
					// They gave us a pMonth
					if (!iVariable_isTypeNumeric(varMonth))
					{
						iError_report(thisCode, (cu8*)"Month must be numeric", false);
						return(NULL);
					}
					lst.wMonth = (u16)iiVariable_getAs_s32(thisCode, varMonth, false, &error, &errorNum);
					if (!error && (lst.wMonth < 1 || lst.wMonth > 12))
					{
						iError_reportByNumber(thisCode, _ERROR_OUT_OF_RANGE, iVariable_getRelatedComp(thisCode, varMonth), false);
						return(NULL);
					}
				}


			//////////
			// pDay must be numeric, and in a valid range for the year and month
			//////
				if (iVariable_isValid(varDay))
				{
					// They gave us a pDay
					if (!iVariable_isTypeNumeric(varDay))
					{
						iError_report(thisCode, (cu8*)"Day must be numeric", false);
						return(NULL);
					}
					lst.wDay = (u16)iiVariable_getAs_s32(thisCode, varDay, false, &error, &errorNum);
					if (!error && !iVariable_isDayValidForDate(lst.wYear, lst.wMonth, lst.wDay))
					{
						iError_reportByNumber(thisCode, _ERROR_OUT_OF_RANGE, iVariable_getRelatedComp(thisCode, varDay), false);
						return(NULL);
					}
				}

		}


		//////////
		// Convert lst.* into a VJr date variable
		//////
			// Date is stored as YYYYMMDD
			sprintf(buffer, "%04u%02u%02u\0", lst.wYear, lst.wMonth, lst.wDay);
			result = iVariable_createAndPopulate_byText(thisCode, _VAR_TYPE_DATE, buffer, 8, false);
			if (!result)
				iError_reportByNumber(thisCode, _ERROR_INTERNAL_ERROR, NULL, false);


		//////////
		// Return our converted result
		//////
			return(result);

	}




//////////
//
// Function: DATETIME()
// Returns the current local time, or uses the input variables to create the indicated datetime.
//
//////
// Version 0.56
// Last update:
//     Jul.10.2014
//////
// Change log:
//     Jul.10.2014 - Initial creation
//////
// Parameters:
//     pYear		-- (optional) Numeric, in the range 1600..2400
//     pMonth		-- (optional) Numeric, in the range 1..12
//     pDay			-- (optional) Numeric, in the range 1..(varies based on month+year, not more than 31)
//     pHour		-- (optional) Numeric, in the range 0..23
//     pMinute		-- (optional) Numeric, in the range 0..59
//     pSecond		-- (optional) Numeric, in the range 0..59
//     pMillisecond	-- (optional) Numeric, in the range 0..999
//
//////
// Returns:
//    Datetime		-- Current datetime(), or input converted to datetime
//
//////
	SVariable* function_datetime(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable*	varYear			= returnsParams->params[0];
		SVariable*	varMonth		= returnsParams->params[1];
		SVariable*	varDay			= returnsParams->params[2];
		SVariable*	varHour			= returnsParams->params[3];
		SVariable*	varMinute		= returnsParams->params[4];
		SVariable*	varSecond		= returnsParams->params[5];
		SVariable*	varMillisecond	= returnsParams->params[6];
		SVariable*	result;
		SDateTime*	dt;
		f32			lfJulian;
		u32			errorNum;
		bool		error;
		SYSTEMTIME	lst;


		// Have they provided us with data?
		if (!varYear)
		{
			// Nope, we are creating the current system time
			if (_settings)		iTime_getLocalOrSystem(&lst, propGet_settings_TimeLocal(_settings));
			else				GetLocalTime(&lst);

		} else {
			// They have provided us datetime parameters.
			// Default to 01/01/1600 00:00:00.000 for any
			lst.wYear			= 1600;
			lst.wMonth			= 1;
			lst.wDay			= 1;
			lst.wHour			= 0;
			lst.wMinute			= 0;
			lst.wSecond			= 0;
			lst.wMilliseconds	= 0;


			//////////
			// pYear must be numeric, and in the range of 1600..2400
			//////
				if (iVariable_isValid(varYear))
				{
					// They gave us a pYear
					if (!iVariable_isTypeNumeric(varYear))
					{
						iError_report(thisCode, (cu8*)"Year must be numeric", false);
						return(NULL);
					}
					lst.wYear = (u16)iiVariable_getAs_s32(thisCode, varYear, false, &error, &errorNum);
					if (!error && (lst.wYear < 1600 || lst.wYear > 2400))
					{
						iError_reportByNumber(thisCode, _ERROR_OUT_OF_RANGE, iVariable_getRelatedComp(thisCode, varYear), false);
						return(NULL);
					}
				}


			//////////
			// pMonth must be numeric, and in the range of 1..12
			//////
				if (iVariable_isValid(varMonth))
				{
					// They gave us a pMonth
					if (!iVariable_isTypeNumeric(varMonth))
					{
						iError_report(thisCode, (cu8*)"Month must be numeric", false);
						return(NULL);
					}
					lst.wMonth = (u16)iiVariable_getAs_s32(thisCode, varMonth, false, &error, &errorNum);
					if (!error && (lst.wMonth < 1 || lst.wMonth > 12))
					{
						iError_reportByNumber(thisCode, _ERROR_OUT_OF_RANGE, iVariable_getRelatedComp(thisCode, varMonth), false);
						return(NULL);
					}
				}


			//////////
			// pDay must be numeric, and in a valid range for the year and month
			//////
				if (iVariable_isValid(varDay))
				{
					// They gave us a pDay
					if (!iVariable_isTypeNumeric(varDay))
					{
						iError_report(thisCode, (cu8*)"Day must be numeric", false);
						return(NULL);
					}
					lst.wDay = (u16)iiVariable_getAs_s32(thisCode, varDay, false, &error, &errorNum);
					if (!error && !iVariable_isDayValidForDate(lst.wYear, lst.wMonth, lst.wDay))
					{
						iError_reportByNumber(thisCode, _ERROR_OUT_OF_RANGE, iVariable_getRelatedComp(thisCode, varDay), false);
						return(NULL);
					}
				}


			//////////
			// pHour must be numeric, and in the range of 0..23
			//////
				if (iVariable_isValid(varHour))
				{
					// They gave us a pHour
					if (!iVariable_isTypeNumeric(varHour))
					{
						iError_report(thisCode, (cu8*)"Hours must be numeric", false);
						return(NULL);
					}
					lst.wHour = (u16)iiVariable_getAs_s32(thisCode, varHour, false, &error, &errorNum);
					if (!error && (lst.wHour < 0 || lst.wHour > 23))
					{
						iError_reportByNumber(thisCode, _ERROR_OUT_OF_RANGE, iVariable_getRelatedComp(thisCode, varHour), false);
						return(NULL);
					}
				}


			//////////
			// pMinute must be numeric, and in the range of 0..59
			//////
				if (iVariable_isValid(varMinute))
				{
					// They gave us a pMinute
					if (!iVariable_isTypeNumeric(varMinute))
					{
						iError_report(thisCode, (cu8*)"Minutes must be numeric", false);
						return(NULL);
					}
					lst.wMinute = (u16)iiVariable_getAs_s32(thisCode, varMinute, false, &error, &errorNum);
					if (!error && (lst.wMinute < 0 || lst.wMinute > 59))
					{
						iError_reportByNumber(thisCode, _ERROR_OUT_OF_RANGE, iVariable_getRelatedComp(thisCode, varMinute), false);
						return(NULL);
					}
				}


			//////////
			// pSecond must be numeric, and in the range of 0..59
			//////
				if (iVariable_isValid(varSecond))
				{
					// They gave us a pSecond
					if (!iVariable_isTypeNumeric(varSecond))
					{
						iError_report(thisCode, (cu8*)"Seconds must be numeric", false);
						return(NULL);
					}
					lst.wSecond = (u16)iiVariable_getAs_s32(thisCode, varSecond, false, &error, &errorNum);
					if (!error && (lst.wSecond < 0 || lst.wSecond > 59))
					{
						iError_reportByNumber(thisCode, _ERROR_OUT_OF_RANGE, iVariable_getRelatedComp(thisCode, varSecond), false);
						return(NULL);
					}
				}


			//////////
			// pMillisecond must be numeric, and in the range of 0..999
			//////
				if (iVariable_isValid(varMillisecond))
				{
					// They gave us a pMillisecond
					if (!iVariable_isTypeNumeric(varMillisecond))
					{
						iError_report(thisCode, (cu8*)"Milliseconds must be numeric", false);
						return(NULL);
					}
					lst.wMilliseconds = (u16)iiVariable_getAs_s32(thisCode, varMillisecond, false, &error, &errorNum);
					if (!error && (lst.wMilliseconds < 0 || lst.wMilliseconds > 999))
					{
						iError_reportByNumber(thisCode, _ERROR_OUT_OF_RANGE, iVariable_getRelatedComp(thisCode, varMillisecond), false);
						return(NULL);
					}
				}
		}


		//////////
		// Convert lst.* into a VJr datetime variable
		//////
			result = iVariable_create(thisCode, _VAR_TYPE_DATETIME, NULL, true);
			if (!result)
			{
				iError_report(thisCode, cgcInternalError, false);
				return(NULL);
			}

			dt = (SDateTime*)result->value.data;

			// Date is stored as julian day number
			dt->julian	= iiVariable_julian_fromYyyyMmDd(&lfJulian, lst.wYear, lst.wMonth, lst.wDay);

			// Time is stored as seconds since midnight
			dt->seconds = (f32)(lst.wHour * 60 * 60) + (f32)(lst.wMinute * 60) + (f32)lst.wSecond + ((f32)lst.wMilliseconds / 1000.0f);


		//////////
        // Return our converted result
		//////
	        return(result);
	}

	
	
//////////
//
// Function: DAY()
// Returns the numeric day of the month for a given Date or DateTime expression.
//
//////
// Version 0.57
// Last update:
//     Apr.04.2015
//////
// Change log:
//     Apr.04.2015 - Initial creation by Stefano D'Amico
//////
// Parameters:
//     p1			-- Date or DateTime
//
//////
// Returns:
//    DAY( ) returns a number from 1 through 31.
//////
// Example:
//	  dt = datetime()	&& Apr.06.2015
//    ? DAY(dt)		&& Displays 6
//    ? DAY()       && Displays current date's day of month
//////
	SVariable* function_day(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varParam = returnsParams->params[0];

		// Return day
		return(ifunction_day_month_year_common(thisCode, varParam, _DMY_COMMON_DAY));
	}
	
	// Common date functions used for DAY(), MONTH(), YEAR()
	SVariable* ifunction_day_month_year_common(SThisCode* thisCode, SVariable* varParam, u32 tnFunctionType)
	{
		u32			lnResult, lnYear, lnMonth, lnDay;
		SYSTEMTIME	lst;
		SVariable*	result;


		//////////
		// If Parameter 1 is provided, it must be date or datetime
		//////
// TODO:  Must also support DATETIMEX at some point
			if (varParam)
			{
				if (!iVariable_isValid(varParam) || !(iVariable_isTypeDate(varParam) || iVariable_isTypeDatetime(varParam)))
				{
					iError_reportByNumber(thisCode, _ERROR_INVALID_ARGUMENT_TYPE_COUNT, iVariable_getRelatedComp(thisCode, varParam), false);
					return(NULL);
				}


				//////////
				// Grab year, month, day from datetime or date
				//////
					if (iVariable_isTypeDatetime(varParam))			iiVariable_computeYyyyMmDd_fromJulian		(varParam->value.data_dt->julian,	&lnYear, &lnMonth, &lnDay);
					else /* date */									iiVariable_computeYyyyMmDd_fromYYYYMMDD		(varParam->value.data_u8,			&lnYear, &lnMonth, &lnDay);


			} else {
				// Use the current date
				if (_settings)		iTime_getLocalOrSystem(&lst, propGet_settings_TimeLocal(_settings));
				else				GetLocalTime(&lst);
				lnYear	= lst.wYear;
				lnMonth	= lst.wMonth;
				lnDay	= lst.wDay;
			}


		//////////
		// Create output variable
		//////
			switch (tnFunctionType)
			{
				case _DMY_COMMON_DAY:		lnResult = lnDay;		break;
				case _DMY_COMMON_MONTH:		lnResult = lnMonth;		break;
				case _DMY_COMMON_YEAR:		lnResult = lnYear;		break;

				// Should never happen
				default:
					iError_reportByNumber(thisCode, _ERROR_INTERNAL_ERROR, iVariable_getRelatedComp(thisCode, varParam), false);
					return(NULL);
			}


		//////////
		// Create the value
		//////
			result = iVariable_createAndPopulate_byText(thisCode, _VAR_TYPE_U32, (cs8*)&lnResult, sizeof(lnResult), false);
			if (!result)
				iError_reportByNumber(thisCode, _ERROR_INTERNAL_ERROR, iVariable_getRelatedComp(thisCode, varParam), false);


		//////////
		// Return the result
		//////
			return(result);

	}




//////////
//
// Function: DMY()
// Returns a character expression in day-month-year format (for example, 31 May 1998).
//
//////
// Version 0.57
// Last update:
//     Apr.07.2015
//////
// Change log:
//     Apr.07.2015 - Initial creation by Stefano D'Amico
//////
// Parameters:
//     p1			-- Date or DateTime
//
//////
// Returns:
//    Character - If SET CENTURY is OFF, DMY( ) returns a character string in a dd-Month-yy format (for example, 16 February 98). 
//////
	SVariable* function_dmy(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varParam = returnsParams->params[0];

		return(ifunction_dtoc_common(thisCode, varParam, _DMY_COMMON_DMY));
	}

	SVariable* ifunction_dtoc_common(SThisCode* thisCode, SVariable* varParam, u32 tnFunctionType)
	{
		u32			lnYear, lnMonth, lnDay;
		s8			lnMonthIdx;
		SYSTEMTIME	lst;
		s8			buffer[64];
		SVariable*	result;


		//////////
		// If provided, parameter 1 must be date or datetime
		//////
			if (varParam)
			{
// TODO:  Must also support DATETIMEX at some point
				if (!iVariable_isValid(varParam) || !(iVariable_isTypeDate(varParam) || iVariable_isTypeDatetime(varParam)))
				{
					iError_reportByNumber(thisCode, _ERROR_INVALID_ARGUMENT_TYPE_COUNT, iVariable_getRelatedComp(thisCode, varParam), false);
					return(NULL);
				}


				//////////
				// Grab year, month, day from datetime or date
				//////
					if (iVariable_isTypeDatetime(varParam))			iiVariable_computeYyyyMmDd_fromJulian		(varParam->value.data_dt->julian,	&lnYear, &lnMonth, &lnDay);
					else /* date */									iiVariable_computeYyyyMmDd_fromYYYYMMDD		(varParam->value.data_u8,			&lnYear, &lnMonth, &lnDay);


			} else {
				// Use the current date
				if (_settings)		iTime_getLocalOrSystem(&lst, propGet_settings_TimeLocal(_settings));
				else				GetLocalTime(&lst);
				lnYear	= lst.wYear;
				lnMonth	= lst.wMonth;
				lnDay	= lst.wDay;
			}


		//////////
		// Concatenate string
		//////
			switch(tnFunctionType)
			{
				case _DMY_COMMON_DMY:
				case _DMY_COMMON_MDY:
					lnMonthIdx = max(min(lnMonth, 12), 1) - 1;		// Force into range 1..12, then backoff one for base-0 array reference
					if (_settings && !propGet_settings_Century(_settings))
						// YY
						if (tnFunctionType == _DMY_COMMON_DMY)	sprintf(buffer, "%02u %s %02u\0", lnDay, cgcMonthNames[lnMonthIdx], lnYear % 100);
						else /*MDY*/							sprintf(buffer, "%s %02u, %02u\0", cgcMonthNames[lnMonthIdx], lnDay, lnYear % 100);
					else
						// YYYY
						if (tnFunctionType == _DMY_COMMON_DMY)	sprintf(buffer, "%02u %s %04u\0", lnDay, cgcMonthNames[lnMonthIdx], lnYear);
						else /*MDY*/							sprintf(buffer, "%s %02u, %04u\0", cgcMonthNames[lnMonthIdx], lnDay, lnYear);
				
					break;

				case _DMY_COMMON_DTOS:
					// Date is stored as YYYYMMDD
					sprintf(buffer, "%04u%02u%02u\0", lnYear, lnMonth, lnDay);
					break;

				// Should never happen
				default:
					iError_reportByNumber(thisCode, _ERROR_INTERNAL_ERROR, iVariable_getRelatedComp(thisCode, varParam), false);
					return(NULL);
			}
			
		//////////
		// Create our result
		//////
			result = iVariable_createAndPopulate_byText(thisCode, _VAR_TYPE_CHARACTER, (cs8*)buffer, (u32)strlen(buffer), false);
			if (!result)
				iError_reportByNumber(thisCode, _ERROR_INTERNAL_ERROR, NULL, false);


		//////////
		// Indicate our result
		//////
			return(result);

	}



//////////
//
// Function: DTOR()
// Converts degrees to radians.
//
//////
// Version 0.56
// Last update:
//     Mar.16.2015
//////
// Change log:
//     Mar.16.2015 - Initial creation by Stefano D'Amico
//////
// Parameters:
//     p1			-- Numeric or floating point
//
//////
// Returns:
//    DTOR(n) of the value in p1
//////
// Example:
//    ? DTOR(180)		&& Display 3.14
//////
    SVariable* function_dtor(SThisCode* thisCode, SReturnsParams* returnsParams)
    {
		SVariable* varNumber = returnsParams->params[0];


		// Return dtor
		return(ifunction_numbers_common(thisCode, varNumber, NULL, NULL, _FP_COMMON_DTOR, _VAR_TYPE_F64, false, false, returnsParams));
	}




//////////
//
// Function: DTOC()
// Returns a Character-type date from a Date or DateTime expression.
//
//////
// Version 0.57
// Last update:
//     Apr.07.2015
//////
// Change log:
//     Apr.07.2015 - Initial creation by Stefano D'Amico
//////
// Parameters:
//     p1			-- Date or DateTime
//	   p2			-- If 1 returns the date in a format suitable for indexing
//
//////
// Returns:
//    DTOC( ) returns a character string corresponding to a Date or DateTime expression.
//	  The date format is determined by SET CENTURY and SET DATE. 
//
//////
	SVariable* function_dtoc(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varParam	= returnsParams->params[0];
		SVariable* varFlag	= returnsParams->params[1];

		s32			lnFlag;
		u32			lnYear, lnMonth, lnDay;
		SYSTEMTIME	lst;
		s8			buffer[16];
		SVariable*	varTempDate;
		SVariable*	result;
		bool		error;
		u32			errorNum;


		//////////
		// Parameter 2 must be numeric
		//////
			if (varFlag)
			{
				if (!iVariable_isValid(varFlag) || !iVariable_isTypeNumeric(varFlag))
				{
					iError_reportByNumber(thisCode, _ERROR_P2_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varFlag), false);
					return(NULL);
				}

				// Grab the flag
				lnFlag = iiVariable_getAs_s32(thisCode, varFlag, false, &error, &errorNum);
				if (error)
				{
					// An error extracting the value (should never happen)
					iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varFlag), false);
					return(NULL);
				}		

				// DTOC(--, 1) is DTOS(--)
				if (lnFlag == 1)
					return(ifunction_dtoc_common(thisCode, varParam, _DMY_COMMON_DTOS));

				// If we get here, invalid parameter specified
				iError_reportByNumber(thisCode, _ERROR_INVALID_ARGUMENT_TYPE_COUNT, iVariable_getRelatedComp(thisCode, varFlag), false);
				return(NULL);
			}


		//////////
		// Parameter 1 must be date or datetime
		//////			
			if (varParam)
			{
// TODO:  Must also support DATETIMEX at some point
				if (!iVariable_isValid(varParam) || !(iVariable_isTypeDate(varParam) || iVariable_isTypeDatetime(varParam)))
				{
					iError_reportByNumber(thisCode, _ERROR_INVALID_ARGUMENT_TYPE_COUNT, iVariable_getRelatedComp(thisCode, varParam), false);
					return(NULL);
				}

				// If date we finished
				if (iVariable_isTypeDate(varParam))
					return(iVariable_convertForDisplay(thisCode, varParam));
				

				//////////
				// Grab year, month, day from datetime
				//////
					iiVariable_computeYyyyMmDd_fromJulian (varParam->value.data_dt->julian,	&lnYear, &lnMonth, &lnDay);


			} else {
				// Use the current date
				if (_settings)		iTime_getLocalOrSystem(&lst, propGet_settings_TimeLocal(_settings));
				else				GetLocalTime(&lst);
				lnYear	= lst.wYear;
				lnMonth	= lst.wMonth;
				lnDay	= lst.wDay;
			}
		

		//////////
		// Convert datetime or lst.* into a VJr date variable
		//////
			// Date is stored as YYYYMMDD
			sprintf(buffer, "%04u%02u%02u\0", lnYear, lnMonth, lnDay);
			varTempDate = iVariable_createAndPopulate_byText(thisCode, _VAR_TYPE_DATE, buffer, 8, false);
			if (!varTempDate)
			{
				// Fatal error
				iError_reportByNumber(thisCode, _ERROR_INTERNAL_ERROR, NULL, false);
				return(NULL);
			}


		//////////
		// Create and populate the return variable
		//////
			result = iVariable_convertForDisplay(thisCode, varTempDate);
			if (!result)
				iError_reportByNumber(thisCode, _ERROR_INTERNAL_ERROR, iVariable_getRelatedComp(thisCode, varParam), false);


		//////////
		// Clean house
		//////
			iVariable_delete(thisCode, varTempDate, true);


		//////////
		// Signify our result
		//////
			return(result);

	}




//////////
//
// Function: DTOS()
// Returns a character-string date in a yyyymmdd format from a specified Date or DateTime expression.
//
//////
// Version 0.57
// Last update:
//     Apr.07.2015
//////
// Change log:
//     Apr.07.2015 - Initial creation by Stefano D'Amico
//////
// Parameters:
//     p1			-- Date or DateTime
//
//////
// Returns:
//    Character - This function is useful for indexing tables on a Date or DateTime field.
//	  It is equivalent to DTOC( ) when its optional 1 argument is included. 
//
//////
	SVariable* function_dtos(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varParam = returnsParams->params[0];


		// Return dtos
		return(ifunction_dtoc_common(thisCode, varParam, _DMY_COMMON_DTOS));
	}




//////////
//
// Function: DTOT()
// Returns a DateTime value from a Date expression.
//
//////
// Version 0.57
// Last update:
//     Apr.07.2015
//////
// Change log:
//     Apr.07.2015 - Initial creation by Stefano D'Amico
//////
// Parameters:
//     p1			-- Date
//
//////
// Returns:
//    Datetime	-- DTOT( ) adds a default time of 12:00:00 AM (if SET HOURS is 12) or 00:00:00 (if SET HOURS is 24) to the date to produce a valid DateTime value.
//////
	SVariable* function_dtot(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varParam = returnsParams->params[0];

		u32			lnYear, lnMonth, lnDay;
		f32			lfJulian;
		SVariable*	result;


		//////////
		// Parameter 1 must be date
		//////
			if (!iVariable_isValid(varParam) || !iVariable_isTypeDate(varParam))
			{
				iError_reportByNumber(thisCode, _ERROR_INVALID_ARGUMENT_TYPE_COUNT, iVariable_getRelatedComp(thisCode, varParam), false);
				return(NULL);
			}


		//////////
		// Grab year, month, day from date
		//////
			iiVariable_computeYyyyMmDd_fromYYYYMMDD(varParam->value.data_u8, &lnYear, &lnMonth, &lnDay);


		//////////
		// Convert date into a VJr datetime variable
		//////
			result = iVariable_create(thisCode, _VAR_TYPE_DATETIME, NULL, true);
			if (!result)
			{
				iError_report(thisCode, cgcInternalError, false);
				return(NULL);
			}

			// Date is stored as julian day number
			result->value.data_dt->julian	= iiVariable_julian_fromYyyyMmDd(&lfJulian, lnYear, lnMonth, lnDay);

			// Time is stored as seconds since midnight
			result->value.data_dt->seconds = 0.0f;


		//////////
        // Return our converted result
		//////
	        return(result);

	}




//////////
//
// Function: EMPTY()
// Determines whether an expression evaluates to empty.
//
//////
// Version 0.56
// Last update:
//     Mar.20.2015
//////
// Change log:
//     Mar.20.2015 - Refactoring by Stefano D'Amico
//     Mar.19.2015 - Refactoring by Rick C. Hodgin
//     Mar.19.2015 - Initial creation by Stefano D'Amico
//////
// Parameters:
//     p1	-- Specifies the expression that EMPTY( ) evaluates.
//
//////
// Returns:
//    EMPTY( ) returns True (.T.) if the expression eExpression evaluates to empty;
//    otherwise, EMPTY( ) returns False (.F.)
//////
// Example:
//    ? EMPTY("AA")	&& Display .F.
//    ? EMPTY("  ")	&& Display .T.
//    ? EMPTY(0.0)	&& Display .T.
//////
	SVariable* function_empty(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable*	varExpr = returnsParams->params[0];
		bool		llEmpty;
		SVariable*	result;


		//////////
		// Verify the expression is correct
		//////
			if (!iVariable_isValid(varExpr))
			{
				iError_reportByNumber(thisCode, _ERROR_PARAMETER_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varExpr), false);
				return(NULL);
			}


		//////////
		// Create and populate the return variable
		//////
			llEmpty	= function_isempty_common(thisCode, varExpr, returnsParams);
			result	= iVariable_createAndPopulate_byText(thisCode, _VAR_TYPE_LOGICAL, (cs8*)((llEmpty) ? &_LOGICAL_TRUE : &_LOGICAL_FALSE), 1, false);
			if (!result)
				iError_reportByNumber(thisCode, _ERROR_INTERNAL_ERROR, iVariable_getRelatedComp(thisCode, varExpr), false);


		//////////
		// Signify our result
		//////
			return(result);

	}

	bool function_isempty_common(SThisCode* thisCode, SVariable* varExpr, SReturnsParams* returnsParams)
	{
		s8			c, cPointChar;
		u32			lnI;
		bool		llEmpty;
		SVariable*	varPoint;


		//////////
		// Determine what we're evaluating
		//////
			llEmpty = true;
			switch (varExpr->varType)
			{
				case _VAR_TYPE_NULL:
					// NULL values are considered "not empty" even though they really are.
					llEmpty = false;
					break;

				case _VAR_TYPE_DATE:	// Note:  Dates are stored internally as YYYYMMDD, so they can be directly compared
				case _VAR_TYPE_CHARACTER:
					// Character expressions must have no length, or be completely blank to be considered empty

					//////////
					// Iterate through each character
					//////
						for (lnI = 0; lnI < (u32)varExpr->value.length; lnI++)
						{
							// If we encounter anything other than spaces, not empty
							if (varExpr->value.data[lnI] != 32)
							{
								llEmpty = false;
								break;
							}
						}
						break;


				case _VAR_TYPE_NUMERIC:
					// Numerics are stored as numbers, possibly with a minus sign and the point separator

					//////////
					// Grab the point character
					//////
						if ((varPoint = propGet_settings_Point(_settings)))
						{
							// Extract it
							cPointChar	= varPoint->value.data_s8[0];
							iVariable_delete(thisCode, varPoint, true);

						} else {
							// Default to the standard period
							cPointChar	= cgcPointChar[0];
						}


					//////////
					// Iterate through
					//////
						for (lnI = 0; lnI < (u32)varExpr->value.length; lnI++)
						{
							// If we encounter a non-space, non-zero, or a non-point character, it's then not empty
							c = varExpr->value.data[lnI];
							if (c != 32 && c != '0' && c != cPointChar)
							{
								llEmpty = false;
								break;
							}
						}
						break;


				case _VAR_TYPE_DATETIME:
					llEmpty = ((varExpr->value.data_dt->julian == 0) && (varExpr->value.data_dt->seconds == 0.0f));
					break;

				case _VAR_TYPE_LOGICAL:
					llEmpty = !(varExpr->value.data_s8[0] == _LOGICAL_TRUE);
					break;

				case _VAR_TYPE_S8:
				case _VAR_TYPE_U8:
					llEmpty = (*varExpr->value.data_u8 == 0);
					break;

				case _VAR_TYPE_S16:
				case _VAR_TYPE_U16:
					llEmpty = (*varExpr->value.data_u16 == 0);
					break;

				case _VAR_TYPE_S32:
				case _VAR_TYPE_U32:
					llEmpty = (*varExpr->value.data_u32 == 0);
					break;

				case _VAR_TYPE_S64:
				case _VAR_TYPE_U64:
				case _VAR_TYPE_CURRENCY:
					llEmpty = (*varExpr->value.data_u64 == 0);
					break;

				case _VAR_TYPE_F32:
					llEmpty = (*varExpr->value.data_f32 == 0.0f);
					break;

				case _VAR_TYPE_F64:
					llEmpty = (*varExpr->value.data_f64 == 0.0);
					break;

//				case _VAR_TYPE_BI:
//					// Big integer
//					break;

//				case _VAR_TYPE_BFP:
//					// Big floating point
//					break;

				default:
					iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, NULL, false);
					return(NULL);
			}


		//////////
		// Signify our result
		//////
			return(llEmpty);

	}




//////////
//
// Function: ENDSWITH()
// Determines if the character string ends with the search string.
//
//////
// Version 0.56   (Determine the current version from the header in vjr.cpp)
// Last update:
//     Mar.22.2015
//////
// Change log:
//     Mar.22.2015 - Initial creation (originally proposed by Stefano D'Amico)
//////
// Parameters:
//     varString	-- Original string
//     varSearch	-- Search string to replace
//     varStart		-- Starting location within the string
//     varEnd		-- Ending location within the string
//
//////
// Returns:
//    Logical		-- .t. if the search string is found in the string, .f. otherwise
//
//////
	SVariable* function_endswith(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varString	= returnsParams->params[0];
		SVariable* varSearch	= returnsParams->params[1];
		SVariable* varStart		= returnsParams->params[2];
		SVariable* varEnd		= returnsParams->params[3];


		// Not yet completed
		iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, iVariable_getRelatedComp(thisCode, varString), false);
		return(NULL);
	}




//////////
//
// Function: ENDSWITHC()
// Case-insensitive version of ENDSWITH()
//
//////
	SVariable* function_endswithc(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varString	= returnsParams->params[0];
		SVariable* varSearch	= returnsParams->params[1];
		SVariable* varStart		= returnsParams->params[2];
		SVariable* varEnd		= returnsParams->params[3];


		// Not yet completed
		iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, iVariable_getRelatedComp(thisCode, varString), false);
		return(NULL);
	}




//////////
//
// Function: EVL()
// Returns a non-empty value from two expressions.
//
//////
// Version 0.56
// Last update:
//     Mar.20.2015
//////
// Change log:
//     Mar.20.2015 - Some refactoring by Rick C. Hodgin
//     Mar.20.2015 - Initial creation by Stefano D'Amico
//////
// Parameters:
//     p1	-- Specifies the expression that EMPTY( ) evaluates.
//     p2	-- Specifies the expression to return if p1 is empty.
//
//////
// Returns:
//    EVL( ) returns p1 if it does not evaluate to an empty value; otherwise, it returns p2.
//////
// Example:
//    ? EVL("  ", "None")	&& Display "None"
//////
	SVariable* function_evl(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable*	varExpr1 = returnsParams->params[0];
		SVariable*	varExpr2 = returnsParams->params[1];
		bool		llEmpty;
		SVariable*	result;


		//////////
		// Verify p1 is correct
		//////
			if (!iVariable_isValid(varExpr1))
			{
				iError_reportByNumber(thisCode, _ERROR_P1_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varExpr1), false);
				return(NULL);
			}


		//////////
		// Verify p2 is correct
		//////
			if (!iVariable_isValid(varExpr2))
			{
				iError_reportByNumber(thisCode, _ERROR_P2_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varExpr2), false);
				return(NULL);
			}


		//////////
		// Create our result
		//////
			llEmpty	= function_isempty_common(thisCode, varExpr1, returnsParams);
			result	= iVariable_copy(thisCode, ((llEmpty) ? varExpr2 : varExpr1), false);
			if (!result)
				iError_reportByNumber(thisCode, _ERROR_INTERNAL_ERROR, iVariable_getRelatedComp(thisCode, ((llEmpty) ? varExpr2 : varExpr1)), false);


		//////////
		// Signify our result
		//////
			return(result);
	}




//////////
//
// Function: EXP()
// Returns the value of e^x where x is a specified numeric expression.
//
//////
// Version 0.56
// Last update:
//     Mar.15.2015
//////
// Change log:
//     Mar.15.2015 - Initial creation by Stefano D'Amico
//////
// Parameters:
//     p1			-- Numeric or floating point
//
//////
// Returns:
//    EXP(n) of the value in p1
//////
// Example:
//    ? EXP(2)		&& Display 7.39
//////
    SVariable* function_exp(SThisCode* thisCode, SReturnsParams* returnsParams)
    {
		SVariable* varNumber = returnsParams->params[0];


		// Return exp
		return(ifunction_numbers_common(thisCode, varNumber, NULL, NULL, _FP_COMMON_EXP, _VAR_TYPE_F64, false, false, returnsParams));
	}

	// Common numeric functions used for EXP(), LOG(), LOG10(), PI(), SQRT(), CEILING(), FLOOR(), DTOR(), RTOD(), ...
    SVariable* ifunction_numbers_common(SThisCode* thisCode, SVariable* varNumber1, SVariable* varNumber2, SVariable* varNumber3, u32 tnFunctionType, const u32 tnResultType, bool tlSameInputType, bool tlNoEmptyParam, SReturnsParams* returnsParams)
    {
		f64			lfResult, lfValue1, lfValue2, lfValue3;
		u32			errorNum;
        bool		error;
        SVariable*	result;


		//////////
		// If varNumber1 is provided, must also be numeric
		//////
			if (varNumber1)
			{
				//////////
				// Must be numeric
				//////
					if (!iVariable_isValid(varNumber1) || !iVariable_isTypeNumeric(varNumber1))
					{
						iError_reportByNumber(thisCode, _ERROR_PARAMETER_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varNumber1), false);
						return(NULL);
					}


				//////////
				// Convert to f64
				//////
					lfValue1 = iiVariable_getAs_f64(thisCode, varNumber1, false, &error, &errorNum);
					if (error)
					{
						iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varNumber1), false);
						return(NULL);
					}

				//////////
				// Check empty param
				//////
					if (tlNoEmptyParam && lfValue1 == 0.0)
					{
						iError_reportByNumber(thisCode, _ERROR_CANNOT_BE_ZERO, iVariable_getRelatedComp(thisCode, varNumber1), false);
						return(NULL);
					}

			} else {
				lfValue1 = 0.0;
			}


		//////////
		// If varNumber2 is provided, must also be numeric
		//////
			if (varNumber2)
			{
				//////////
				// Must be numeric
				//////
					if (!iVariable_isValid(varNumber2) || !iVariable_isTypeNumeric(varNumber2))
					{
						iError_reportByNumber(thisCode, _ERROR_PARAMETER_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varNumber2), false);
						return(NULL);
					}


				//////////
				// Convert to f64
				//////
					lfValue2 = iiVariable_getAs_f64(thisCode, varNumber2, false, &error, &errorNum);
					if (error)
					{
						iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varNumber2), false);
						return(NULL);
					}

				//////////
				// Check empty param
				//////
					if (tlNoEmptyParam && lfValue2 == 0.0)
					{
						iError_reportByNumber(thisCode, _ERROR_CANNOT_BE_ZERO, iVariable_getRelatedComp(thisCode, varNumber2), false);
						return(NULL);
					}

			} else {
				lfValue2 = 0.0;
			}


		//////////
		// If varNumber3 is provided, must also be numeric
		//////
			if (varNumber3)
			{
				//////////
				// Must be numeric
				//////
					if (!iVariable_isValid(varNumber3) || !iVariable_isTypeNumeric(varNumber3))
					{
						iError_reportByNumber(thisCode, _ERROR_PARAMETER_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varNumber3), false);
						return(NULL);
					}


				//////////
				// Convert to f64
				//////
					lfValue3 = iiVariable_getAs_f64(thisCode, varNumber3, false, &error, &errorNum);
					if (error)
					{
						iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varNumber3), false);
						return(NULL);
					}

				//////////
				// Check empty param
				//////
					if (tlNoEmptyParam && lfValue3 == 0.0)
					{
						iError_reportByNumber(thisCode, _ERROR_CANNOT_BE_ZERO, iVariable_getRelatedComp(thisCode, varNumber3), false);
						return(NULL);
					}

			} else {
				lfValue3 = 0.0;
			}


		//////////
		// Compute numeric function
		//////
			switch (tnFunctionType)
			{

// SQRT()
				case _FP_COMMON_SQRT:

					//////////
					// Verify p1 >= 0
					//////
						if (lfValue1 < 0.0)
						{
							// Oops!
							iError_reportByNumber(thisCode, _ERROR_CANNOT_BE_NEGATIVE, iVariable_getRelatedComp(thisCode, varNumber1), false);
							return(NULL);
						}


					//////////
					// Compute sqrt
					//////
						lfResult = sqrt(lfValue1);
						break;

// EXP()
				case _FP_COMMON_EXP:
					lfResult = exp(lfValue1);
					break;

// PI()
				case _FP_COMMON_PI:
					lfResult = _MATH_PI;
					break;

// LOG()
// LOG10()
				case _FP_COMMON_LOG:
				case _FP_COMMON_LOG10:

					//////////
					// Verify p1 > 0
					//////
						if (lfValue1 <= 0.0)
						{
							// Oops!
							iError_reportByNumber(thisCode, _ERROR_CANNOT_BE_ZERO_OR_NEGATIVE, iVariable_getRelatedComp(thisCode, varNumber1), false);
							return(NULL);
						}


					//////////
					// Compute
					//////
						if (tnFunctionType == _FP_COMMON_LOG)		lfResult = log(lfValue1);
						else										lfResult = log10(lfValue1);
						break;

// CEILING()
				case _FP_COMMON_CEILING:
					lfResult = ceil(lfValue1);
					break;

// FLOOR()
				case _FP_COMMON_FLOOR:
					lfResult = floor(lfValue1);
					break;

// DTOR()
				case _FP_COMMON_DTOR:
					lfResult = lfValue1 * _MATH_PI180;
					break;

// RTOD()
				case _FP_COMMON_RTOD:
					lfResult = lfValue1 * _MATH_180PI;
					break;

// COS()
				case _FP_COMMON_COS:
					lfResult = cos(lfValue1);
					break;

// SIN()
				case _FP_COMMON_SIN:
					lfResult = sin(lfValue1);
					break;

// ABS()
				case _FP_COMMON_ABS:
					lfResult = abs(lfValue1);
					break;

// ACOS()
// ASIN()
				case _FP_COMMON_ACOS:
				case _FP_COMMON_ASIN:

					//////////
					// Verify p1 > 0
					//////
						if (lfValue1 < -1 || lfValue1 > 1)
						{
							// Oops!
							iError_reportByNumber(thisCode, _ERROR_OUT_OF_RANGE, iVariable_getRelatedComp(thisCode, varNumber1), false);
							return(NULL);
						}

					//////////
					// Compute
					//////
						if (tnFunctionType == _FP_COMMON_ACOS)		lfResult = acos(lfValue1);
						else										lfResult = asin(lfValue1);
						break;

// ATAN()
				case _FP_COMMON_ATAN:

					//////////
					// Verify p1 > 0
					//////
						if (lfValue1 < -_MATH_PI2 || lfValue1 > _MATH_PI2)
						{
							// Oops!
							iError_reportByNumber(thisCode, _ERROR_OUT_OF_RANGE, iVariable_getRelatedComp(thisCode, varNumber1), false);
							return(NULL);
						}

					//////////
					// Compute
					//////
						lfResult = atan(lfValue1);
						break;

// ATN2()
				case _FP_COMMON_ATN2:
					lfResult = atan2(lfValue1, lfValue2);
					break;
// TAN()
				case _FP_COMMON_TAN:
					lfResult = tan(lfValue1);
					break;
// MOD()
				case _FP_COMMON_MOD:

					//////////
					// Verify divisor not 0
					//////
						if (lfValue2 == 0.0)
						{
							// Oops!
							iError_reportByNumber(thisCode, _ERROR_DIVISION_BY_ZERO, iVariable_getRelatedComp(thisCode, varNumber2), false);
							return(NULL);
						}


					//////////
					// Compute
					//////
						lfResult = fmod(lfValue1, abs(lfValue2));
						if (lfValue2 < 0 && lfResult != 0.0)			// Mar.14.2015
							lfResult += lfValue2;

					break;

// FV()
				case _FP_COMMON_FV:

					//////////
					// Future value
					//////
						lfResult = (pow((1 + lfValue2), lfValue3) - 1) / lfValue2 * lfValue1;
						break;

// PV()
				case _FP_COMMON_PV:

					//////////
					// Present value
					//////
						lfResult = lfValue1 * ((1 - pow((1 + lfValue2), -lfValue3)) / lfValue2);
						break;

// PAYMENT()
				case _FP_COMMON_PAYMENT:

					//////////
					// Payment
					//////
						lfValue1 = (lfValue1 * pow(lfValue2 + 1, lfValue3) * lfValue2) / (pow(lfValue2 + 1, lfValue3) - 1);
						break;

				default:
					// Programmer error... this is an internal function and we should never get here
					iError_reportByNumber(thisCode, _ERROR_INTERNAL_ERROR, iVariable_getRelatedComp(thisCode, varNumber1), false);
					return(NULL);
			}


		//////////
		// Create output variable
		//////
			if (tlSameInputType)	result = iVariable_create(thisCode, varNumber1->varType, NULL, true);
			else					result = iVariable_create(thisCode, tnResultType, NULL, true);

			if (!result)
			{
				iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varNumber1), false);
				return(NULL);
			}


		//////////
		// Set the value
		//////
			if (!iVariable_setNumeric_toNumericType(thisCode, result, NULL, &lfResult, NULL, NULL, NULL, NULL))
				iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varNumber1), false);


		//////////
        // return(result)
		//////
	        return(result);
	}




//////////
//
// Function: FLOOR()
// Returns the nearest integer that is less than or equal to the specified numeric expression.
//
//////
// Version 0.56
// Last update:
//     Mar.16.2015
//////
// Change log:
//     Mar.16.2015 - Initial creation by Stefano D'Amico
//////
// Parameters:
//     p1			-- Numeric or floating point
//
//////
// Returns:
//    FLOOR(n) of the value in p1
//////
// Example:
//    ? FLOOR(2.2)		&& Display 2
//////
    SVariable* function_floor(SThisCode* thisCode, SReturnsParams* returnsParams)
    {
		SVariable* varNumber = returnsParams->params[0];


        // Return floor
		return(ifunction_numbers_common(thisCode, varNumber, NULL, NULL, _FP_COMMON_FLOOR, _VAR_TYPE_S64, propGet_settings_ncset_ceilingFloor(_settings), false, returnsParams));
	}




//////////
//
// Function: FORCEEXT()
// Takes a pathname and forces the file extension to the new value
//
//////
// Version 0.56
// Last update:
//     Mar.30.2015
//////
// Change log:
//     Apr.02.2015 - Refactoring by Rick C. Hodgin
//     Mar.30.2015 - Coded by Stefano D'Amico
//     Mar.12.2015 - Framed, incomplete
//////
// Parameters:
//     varPathname		-- The filename or pathname.
//     varNewExtension	-- The new file extension to force.
//////
// Returns:
//    The input pathname with the next extension.
//////
// Example:
//    ? FORCEEXT("c:\mydir\fred.txt",	"prg")		&& Displays "c:\mydir\fred.prg"
//    ? FORCEEXT("c:\mydir\fred.txt",	".prg")		&& Displays "c:\mydir\fred.prg"
//    ? FORCEEXT("c:\mydir\fred.txt ",	"prg")		&& Displays "c:\mydir\fred.prg"
//    ? FORCEEXT("c:\mydir.mydir\foo",	"prg")		&& Displays "c:\mydir.mydir\fred.prg"
//    ? FORCEEXT("c:\mydir\fred.txt",	"")			&& Displays "c:\mydir\fred"
//////
	SVariable* function_forceext(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varPathname		= returnsParams->params[0];
		SVariable* varNewExtension	= returnsParams->params[1];

		s32			lnFNameOffset, lnExtOffset, lnLength;
		s8			newFilename[_MAX_PATH + 1];
		SVariable*	result;
		
		
		//////////
		// Parameter 1 must be character
		//////
			if (!iVariable_isValid(varPathname) || !iVariable_isTypeCharacter(varPathname))
			{
				iError_reportByNumber(thisCode, _ERROR_P1_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varPathname), false);
				return(NULL);
			}

		
		//////////
		// Parameter 2 must be character
		//////
			if (!iVariable_isValid(varNewExtension) || !iVariable_isTypeCharacter(varNewExtension))
			{
				iError_reportByNumber(thisCode, _ERROR_P2_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varNewExtension), false);
				return(NULL);
			}


		//////////
		// Based on its type, process it accordingly
		//////
			if (ifunction_pathname_common(thisCode, varPathname, &lnFNameOffset, &lnExtOffset))
			{

				//////////
				// Initialize our target filename
				//////
					memset(newFilename, 0, sizeof(newFilename));
					memcpy(newFilename, varPathname->value.data_s8, lnExtOffset);


				//////////
				// Copy appropriately
				//////
					if (varNewExtension->value.length >= 1)
					{
						// Does it already have a point?
						if (varNewExtension->value.data_s8[0] == '.')
						{
							// Will the new filename be too big?
							lnLength = lnExtOffset + varNewExtension->value.length;			// pathname up to extension + new extension (which already has a period)
							if (lnLength >= sizeof(newFilename))
							{
								// Too big
								iError_reportByNumber(thisCode, _ERROR_TOO_BIG_FOR_TARGET, iVariable_getRelatedComp(thisCode, varNewExtension), false);
								return(NULL);
							}

							// Copy new extension (which already has a period)
							memcpy(newFilename + lnExtOffset, varNewExtension->value.data_s8, varNewExtension->value.length);

						} else {
							// Will the new filename be too big?
							lnLength = lnExtOffset + 1 + varNewExtension->value.length;		// pathname up to extension + new period + new extension
							if (lnLength >= sizeof(newFilename))
							{
								// Too big
								iError_reportByNumber(thisCode, _ERROR_TOO_BIG_FOR_TARGET, iVariable_getRelatedComp(thisCode, varNewExtension), false);
								return(NULL);
							}

							// Copy new period, and new extension (without period)
							newFilename[lnExtOffset] = '.';
							memcpy(newFilename + lnExtOffset + 1, varNewExtension->value.data_s8, varNewExtension->value.length);
						}

					} else {
						// Copy everything except the extension
						lnLength = lnExtOffset;
					}


				//////////
				// Allocate our result
				//////
					result = iVariable_createAndPopulate_byText(thisCode, _VAR_TYPE_CHARACTER, newFilename, lnLength, false);


			} else {
				// Unable to parse the string properly, so return whatever they supplied
				lnLength	= varPathname->value.length;
				result		= iVariable_copy(thisCode, varPathname, false);
			}


		//////////
		// Are we good?
		//////
			if (!result->value.data || result->value.length != lnLength)
			{
				// Unable to allocate our variable's contents
				iVariable_delete(thisCode, result, true);
				result = NULL;
			}
			
			if (!result)
				iError_report(thisCode, cgcInternalError, false);


		//////////
		// Return our result
		//////
			return(result);
	}

//////////
// varPathname		-- Something like "c:\my\dir\file.ext" or "file.ext"
// tnFNameOffset	-- offset to start of file name
// tnExtOffset		-- offset to start of file extension
//////
	bool ifunction_pathname_common(SThisCode* thisCode, SVariable* varPathname, s32* tnFNameOffset, s32* tnExtOffset)
	{
		s8		lc;
		s32		lnI, lnLookingFor;
		cs32	_PERIOD		= 1;
		cs32	_BACKSLASH	= 2;


		//////////
		// Make sure our environment is sane
		//////
			if (varPathname->value.length >= 1)
			{

				//////////
				// Initialize to the beginning for filename, and end for period
				//////
					*tnFNameOffset	= 0;
					*tnExtOffset	= varPathname->value.length;


				//////////
				// We need to find "\" and period.
				//////
					for (lnI = varPathname->value.length - 1, lnLookingFor = _PERIOD; lnI >= 0; lnI--)
					{

						//////////
						// Grab the character
						//////
							lc = varPathname->value.data_u8[lnI];


						//////////
						// What are we looking for?
						//////
							if (lnLookingFor == _PERIOD)
							{
								// Searching for the file extension
								if (lc == '.')
								{
									// Found the period
									*tnExtOffset	= lnI;
									lnLookingFor	= _BACKSLASH;	// Now looking for backslash

								} else if (lc == '\\') {
									// We've found the backslash before the period
									*tnFNameOffset = lnI + 1;
									return(true);
								}

							} else if (lnLookingFor == _BACKSLASH) {
								// Looking for the backslash
								if (lc == '\\')
								{
									*tnFNameOffset = lnI + 1;
									return(true);
								}
							}

					}
					// If we get here, we didn't find
			}


		//////////
		// varPathname is empty
		//////
			return(false);
	}




//////////
//
// Function: FORCEFNAME()
// Takes a pathname and forces the filename to the new value
//
//////
// Version 0.56
// Last update:
//     Mar.30.2015
//////
// Change log:
//     Apr.02.2015 - Refactoring by Rick C. Hodgin
//     Mar.30.2015 - Coded by Stefano D'Amico
//     Mar.12.2015 - Framed, incomplete
//////
// Parameters:
//     varPathname		-- The filename or pathname.
//     varNewFilename	-- The new filename to force.
//////
// Returns:
//    The input pathname with the filename.
//////
	SVariable* function_forcefname(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varPathname		= returnsParams->params[0];
		SVariable* varNewFilename	= returnsParams->params[1];

		s32			lnFNameOffset, lnExtOffset, lnLength;
		s8			newFilename[_MAX_PATH + 1];
		SVariable*	result;


		//////////
		// Parameter 1 must be character
		//////
			if (!iVariable_isValid(varPathname) || !iVariable_isTypeCharacter(varPathname))
			{
				iError_reportByNumber(thisCode, _ERROR_P1_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varPathname), false);
				return(NULL);
			}


		//////////
		// Parameter 2 must be character
		//////
			if (!iVariable_isValid(varNewFilename) || !iVariable_isTypeCharacter(varNewFilename))
			{
				iError_reportByNumber(thisCode, _ERROR_P2_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varNewFilename), false);
				return(NULL);
			}


		//////////
		// Based on its type, process it accordingly
		//////
			if (ifunction_pathname_common(thisCode, varPathname, &lnFNameOffset, &lnExtOffset))
			{

				//////////
				// Initialize our target filename
				//////
					memset(newFilename, 0, sizeof(newFilename));
					memcpy(newFilename, varPathname->value.data_s8, lnFNameOffset);


				//////////
				// Copy appropriately
				//////
					if (varNewFilename->value.length >= 1)
					{
						// Will the new filename be too big?
						lnLength = lnFNameOffset + varNewFilename->value.length;
						if (lnLength >= sizeof(newFilename))
						{
							// Too big
							iError_reportByNumber(thisCode, _ERROR_TOO_BIG_FOR_TARGET, iVariable_getRelatedComp(thisCode, varNewFilename), false);
							return(NULL);
						}

						// Copy new filename
						memcpy(newFilename + lnFNameOffset, varNewFilename->value.data_s8, varNewFilename->value.length);

					} else {
						// If varNewFilename is empty, we remove filename
						lnLength = lnFNameOffset;
					}			


				//////////
				// Allocate our result
				//////
					result = iVariable_createAndPopulate_byText(thisCode, _VAR_TYPE_CHARACTER, newFilename, lnLength, false);


			} else {
				// Unable to parse the string properly, so return whatever they supplied
				lnLength	= varPathname->value.length;
				result		= iVariable_copy(thisCode, varPathname, false);
			}


		//////////
		// Are we good?
		//////
			if (!result->value.data || result->value.length != lnLength)
			{
				// Unable to allocate our variable's contents
				iVariable_delete(thisCode, result, true);
				result = NULL;
			}
			
			if (!result)
				iError_report(thisCode, cgcInternalError, false);


		//////////
		// Return our result
		//////
			return(result);
	}




//////////
//
// Function: FORCEPATH()
// Takes a pathname and forces the path to the new value
//
//////
// Version 0.56
// Last update:
//     Mar.30.2015
//////
// Change log:
//     Apr.02.2015 - Refactoring by Rick C. Hodgin
//     Mar.30.2015 - Coded by Stefano D'Amico
//     Mar.12.2015 - Framed, incomplete
//////
// Parameters:
//     varPathname		-- The filename or pathname.
//     varNewPathname	-- The new pathname to force.
//////
// Returns:
//    The input pathname with the new path.
//////
	SVariable* function_forcepath(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varPathname		= returnsParams->params[0];
		SVariable* varNewPathname	= returnsParams->params[1];

		s32			lnFNameOffset, lnExtOffset, lnFNameLength, lnLength;
		s8			newFilename[_MAX_PATH + 1];
		SVariable*	result;



		//////////
		// Parameter 1 must be character
		//////
			if (!iVariable_isValid(varPathname) || !iVariable_isTypeCharacter(varPathname))
			{
				iError_reportByNumber(thisCode, _ERROR_P1_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varPathname), false);
				return(NULL);
			}


		//////////
		// Parameter 2 must be character
		//////
		if (!iVariable_isValid(varNewPathname) || !iVariable_isTypeCharacter(varNewPathname))
		{
			iError_reportByNumber(thisCode, _ERROR_P2_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varNewPathname), false);
			return(NULL);
		}

		//////////
		// Based on its type, process it accordingly
		//////
			if (ifunction_pathname_common(thisCode, varPathname, &lnFNameOffset, &lnExtOffset))
			{

				//////////
				// Initialize our target filename
				//////
					memset(newFilename, 0, sizeof(newFilename));


				//////////
				// Compute the length of the non-path portion
				//////
					lnFNameLength = varPathname->value.length - lnFNameOffset;


				//////////
				// Copy appropriately
				//////
					if (varNewPathname->value.length >= 1)
					{
						// Do we need to add a backslash?
						if (varNewPathname->value.data_s8[varNewPathname->value.length - 1] != '\\')
						{
							// Will the new filename be too big?
							lnLength = varNewPathname->value.length + 1 + lnFNameLength;
							if (lnLength >= sizeof(newFilename))
							{
								// Too big
								iError_reportByNumber(thisCode, _ERROR_TOO_BIG_FOR_TARGET, iVariable_getRelatedComp(thisCode, varNewPathname), false);
								return(NULL);
							}

							// Copy new path, plus trailing backslash, plus whatever was there before
							memcpy(newFilename, varNewPathname->value.data_s8, varNewPathname->value.length);
							newFilename[varNewPathname->value.length] = '\\';
							memcpy(newFilename + varNewPathname->value.length + 1, varPathname->value.data_s8 + lnFNameOffset, lnFNameLength);

						} else {
							// Will the new filename be too big?
							lnLength = varNewPathname->value.length + lnFNameLength;
							if (lnLength >= sizeof(newFilename))
							{
								// Too big
								iError_reportByNumber(thisCode, _ERROR_TOO_BIG_FOR_TARGET, iVariable_getRelatedComp(thisCode, varNewPathname), false);
								return(NULL);
							}

							// Copy new path, plus whatever was there before
							memcpy(newFilename, varNewPathname->value.data_s8, varNewPathname->value.length);
							memcpy(newFilename + varNewPathname->value.length, varPathname->value.data_s8 + lnFNameOffset, lnFNameLength);
						}

					} else {
						// Remove path
						lnLength = lnFNameLength;
						memcpy(newFilename, varPathname->value.data_s8 + lnFNameOffset, lnFNameLength);
					}


				//////////
				// Allocate our result
				//////
					result = iVariable_createAndPopulate_byText(thisCode, _VAR_TYPE_CHARACTER, newFilename, lnLength, false);


			} else {
				// Unable to parse the string properly, so return whatever they supplied
				lnFNameLength	= varPathname->value.length;
				result		= iVariable_copy(thisCode, varPathname, false);
			}


		//////////
		// Are we good?
		//////
			if (!result->value.data || result->value.length != lnLength)
			{
				// Unable to allocate our variable's contents
				iVariable_delete(thisCode, result, true);
				result = NULL;
			}
			
			if (!result)
				iError_report(thisCode, cgcInternalError, false);


		//////////
		// Return our result
		//////
			return(result);
	}




//////////
//
// Function: FORCESTEM()
// Takes a pathname and forces the stem to the new value
//
//////
// Version 0.56
// Last update:
//     Mar.30.2015
//////
// Change log:
//     Apr.02.2015 - Refactoring by Rick C. Hodgin
//     Mar.30.2015 - Coded by Stefano D'Amico
//     Mar.12.2015 - Framed, incomplete
//////
// Parameters:
//     varPathname		-- The filename or pathname.
//     varNewStem		-- The new stem to force.
//////
// Returns:
//    The input pathname with the new stem.
//////
	SVariable* function_forcestem(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varPathname	= returnsParams->params[0];
		SVariable* varNewStem	= returnsParams->params[1];

		s32			lnFNameOffset, lnExtOffset, lnLengthStem, lnLengthExt, lnLength;
		s8			newFilename[_MAX_PATH + 1];
		SVariable*	result;


		//////////
		// Parameter 1 must be character
		//////
			if (!iVariable_isValid(varPathname) || !iVariable_isTypeCharacter(varPathname))
			{
				iError_reportByNumber(thisCode, _ERROR_P1_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varPathname), false);
				return(NULL);
			}


		//////////
		// Parameter 2 must be character
		//////
			if (!iVariable_isValid(varNewStem) || !iVariable_isTypeCharacter(varNewStem))
			{
				iError_reportByNumber(thisCode, _ERROR_P2_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varNewStem), false);
				return(NULL);
			}


		//////////
		// Based on its type, process it accordingly
		//////
			if (ifunction_pathname_common(thisCode, varPathname, &lnFNameOffset, &lnExtOffset))
			{

				//////////
				// Initialize our target filename
				//////
					memset(newFilename, 0, sizeof(newFilename));


				//////////
				// Compute the length of the non-path portion
				//////
					lnLengthStem	= varPathname->value.length - lnFNameOffset - lnExtOffset;
					lnLengthExt		= varPathname->value.length - lnExtOffset;


				//////////
				// Copy appropriately
				//////
					if (varNewStem->value.length >= 1)
					{
						// Will the new filename be too big?
						lnLength = lnFNameOffset + varNewStem->value.length + lnLengthExt;
						if (lnLength >= sizeof(newFilename))
						{
							// Too big
							iError_reportByNumber(thisCode, _ERROR_TOO_BIG_FOR_TARGET, iVariable_getRelatedComp(thisCode, varNewStem), false);
							return(NULL);
						}

						// Copy path, plus new stem, plus original extension
						memcpy(newFilename, varPathname->value.data_s8, lnFNameOffset);
						memcpy(newFilename + lnFNameOffset, varNewStem->value.data_s8, varNewStem->value.length);
						memcpy(newFilename + lnFNameOffset + varNewStem->value.length, varPathname->value.data_s8 + lnExtOffset, lnLengthExt);

					} else {
						// Copy original path, plus original extension
						lnLength = lnFNameOffset + lnLengthExt;
						memcpy(newFilename, varPathname->value.data_s8, lnFNameOffset);
						memcpy(newFilename + lnFNameOffset, varPathname->value.data_s8 + lnExtOffset, lnLengthExt);
					}			


				//////////
				// Allocate our result
				//////
					result = iVariable_createAndPopulate_byText(thisCode, _VAR_TYPE_CHARACTER, newFilename, lnLength, false);


			} else {
				// Unable to parse the string properly, so return whatever they supplied
				result = iVariable_copy(thisCode, varPathname, false);
			}


		//////////
		// Are we good?
		//////
			if (!result->value.data || result->value.length != lnLength)
			{
				// Unable to allocate our variable's contents
				iVariable_delete(thisCode, result, true);
				result = NULL;
			}
			
			if (!result)
				iError_report(thisCode, cgcInternalError, false);


		//////////
		// Return our result
		//////
			return(result);
	}




//////////
//
// Function: FV()
// Returns the future value of a financial investment.
//
//////
// Version 0.56
// Last update:
//     Mar.19.2015
//////
// Change log:
//     Mar.19.2015 - Refactoring by Stefano D'Amico
//     Mar.18.2015 - Initial creation by Stefano D'Amico
//////
// Parameters:
//     p1			-- Numeric or floating point
//
//////
// Returns:
//    FV(n) of the value in p1
//////
// Example:
//   ? FV(500, 0.006, 48)	&& Displays 27717.50
//////
	SVariable* function_fv(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varPayment		= returnsParams->params[0];
		SVariable* varInterestRate	= returnsParams->params[1];
		SVariable* varPeriods		= returnsParams->params[2];


		// Return fv
		return(ifunction_numbers_common(thisCode, varPayment, varInterestRate, varPeriods, _FP_COMMON_FV, _VAR_TYPE_F64, false, true, returnsParams));
	}

	
	
	
//////////
//
// Function: GOMONTH()
// Returns the date that is a specified number of months before or after a given Date or DateTime expression.
//
//////
// Version 0.57
// Last update:
//     Apr.06.2015
//////
// Change log:
//     Apr.06.2015 - Initial creation by Stefano D'Amico
//////
// Parameters:
//     p1			-- Date or DateTime
//     p2			-- Specifies the number of months from the date or datetime
//
//////
// Returns:
//    Date or Datetime data type.
//
//////
	static cs8 cgGoMonthData[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	SVariable* function_gomonth(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varParam = returnsParams->params[0];
		SVariable* varMonth = returnsParams->params[1];

		s32			lnNumOfMonths, lnYear, lnMonth;
		u32			lnDay, lnLastDay;
		f32			lfJulian;
		SVariable*	result;
		s8			buffer[16];
		u32			errorNum;
		bool		error;


		//////////
		// Parameter 1 must be date or datetime
		//////
// TODO:  Must also support DATETIMEX at some point
			if (!iVariable_isValid(varParam) || !(iVariable_isTypeDate(varParam) || iVariable_isTypeDatetime(varParam)))
			{
				iError_reportByNumber(thisCode, _ERROR_INVALID_ARGUMENT_TYPE_COUNT, iVariable_getRelatedComp(thisCode, varParam), false);
				return(NULL);
			}


		//////////
		// Grab year, month, day from datetime or date
		//////
			if (iVariable_isTypeDatetime(varParam))			iiVariable_computeYyyyMmDd_fromJulian		(varParam->value.data_dt->julian,	(u32*)&lnYear, (u32*)&lnMonth, &lnDay);
			else /* date */									iiVariable_computeYyyyMmDd_fromYYYYMMDD		(varParam->value.data_u8,			(u32*)&lnYear, (u32*)&lnMonth, &lnDay);



		//////////
		// Parameter 2 must be numeric, positive or negative (GOMONTH( ) does not support dates earlier than 1753.)
		//////
			if (!iVariable_isValid(varMonth) || !iVariable_isTypeNumeric(varMonth))
			{
				// Invalid second parameter
				iError_reportByNumber(thisCode, _ERROR_INVALID_ARGUMENT_TYPE_COUNT, iVariable_getRelatedComp(thisCode, varMonth), false);
				return(NULL);
			}


		//////////
		// Grab the value
		//////
			lnNumOfMonths = iiVariable_getAs_s32(thisCode, varMonth, false, &error, &errorNum);
			if (error)
			{
				iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varMonth), false);
				return(NULL);
			}


		//////////
		// Compute new date
		//////
			if (lnNumOfMonths != 0)
			{

				//////////
				// Adjust year
				//////
					if (lnNumOfMonths > 0)
					{
						// Year may move forward
						lnYear += (lnMonth + lnNumOfMonths - 1) / 12;

					} else {	
						// Year may move backwards
						if (lnMonth + lnNumOfMonths <= 0)
							lnYear += (lnMonth + lnNumOfMonths) / 12 - 1;
					}

					// Is year in range 1600..2400
					if (lnYear < 1600 || lnYear > 2400)
					{
						iError_reportByNumber(thisCode, _ERROR_OUT_OF_RANGE, iVariable_getRelatedComp(thisCode, varParam), false);
						return(NULL);
					}


				//////////
				// Adjust month
				//////
					lnMonth = (lnMonth + lnNumOfMonths) % 12;
					if (lnMonth < 1)
						lnMonth += 12;


				//////////
				// Is day valid for the new date?
				//////
					// Day range 1..28 is always valid
					if (lnDay > 28)
					{
						// Grab last day of month
						if (lnMonth == 2 && iVariable_isLeapYear(lnYear))
						{
							// February leap year
							lnLastDay = 29;

						} else {
							// Get the last day of the month for the indicated month
							lnLastDay = cgGoMonthData[lnMonth - 1];
						}

						// Force the new date's day number into the valid range
						lnDay = min(lnLastDay, lnDay);
					}


				//////////
				// Create our return value
				//////
					if (iVariable_isTypeDatetime(varParam))
					{
						// Datetime
						result = iVariable_create(thisCode, _VAR_TYPE_DATETIME, NULL, true);
						if (result)
						{
							// Date is stored as julian day number
							result->value.data_dt->julian	= iiVariable_julian_fromYyyyMmDd(&lfJulian, lnYear, (u32)lnMonth, lnDay);
							result->value.data_dt->seconds = varParam->value.data_dt->seconds;
						}

					} else {
						// Date is stored as YYYYMMDD
						sprintf(buffer, "%04u%02u%02u\0", lnYear, (u32)lnMonth, lnDay);
						result = iVariable_createAndPopulate_byText(thisCode, _VAR_TYPE_DATE, buffer, 8, false);
					}

			} else {
				// No month movement, copy original
				result	= iVariable_copy(thisCode, varParam, false);
			}


		//////////
		// Are we good?
		//////
			if (!result)
				iError_reportByNumber(thisCode, _ERROR_INTERNAL_ERROR, iVariable_getRelatedComp(thisCode, varParam), false);


		//////////
		// Return the result
		//////
			return(result);

	}




//////////
//
// Function: GRAYSCALE()
// Grayscales a color.
//
//////
// Version 0.56
// Last update:
//     Mar.16.2015
//////
// Change log:
//     Mar.16.2015 - Initial creation
//////
// Parameters:
//     varColor			-- The color to grayscale.
//     varPercentage	-- (Optional) A percentage to grayscale (0.05 leaves almost all the color data, 0.95 is almost completely grayscaled)
//////
// Returns:
//    The input pathname with the new stem.
//////
	SVariable* function_grayscale(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varColor			= returnsParams->params[0];
		SVariable* varPercentage	= returnsParams->params[1];


		// Return grayscale
		return(ifunction_colorize_common(thisCode, varColor, NULL, varPercentage, false, returnsParams));
	}




//////////
//
// Function: GRN()
// Retrieves the green channel from an RGBA or BGRA color.
//
//////
// Version 0.56
// Last update:
//     Mar.16.2015
//////
// Change log:
//     Mar.16.2015 - Initial creation
//////
// Parameters:
//     varColor		-- Numeric, a color (0..(2^32)-1)
//
//////
// Returns:
//    Numeric	-- Input number converted to ASCII value number
//////
	SVariable* function_grn(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varColor = returnsParams->params[0];


		// Return grn
		return(ifunction_color_common(thisCode, varColor, 0x0000ff00, 8, returnsParams));
	}




//////////
//
// Function: HOUR()
// Returns the hour portion from a DateTime expression.
//
//////
// Version 0.57
// Last update:
//     Apr.07.2015
//////
// Change log:
//     Apr.07.2015 - Initial creation by Stefano D'Amico
//////
// Parameters:
//     varParam		-- Specifies a DateTime expression from which HOUR( ) returns the hour
//
//////
// Returns:
//    HOUR( ) returns a numeric value based on a 24 hour format.
//////
	SVariable* function_hour(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable*	varParam	= returnsParams->params[0];

		// Return hour
		return(ifunction_hhmmss_common(thisCode, varParam, _HMS_COMMON_HOUR));
	}

	SVariable* ifunction_hhmmss_common (SThisCode* thisCode, SVariable* varParam, u32 tnFunctionType)
	{

		u32			lnResult, lnHour, lnMinute, lnSecond, lnMillisecond; 
		SYSTEMTIME	lst;
		SVariable*	result;


		//////////
		// If Parameter 1 is provided, it must be datetime
		//////
// TODO:  Must also support DATETIMEX at some point
			if (varParam)
			{
				if (!iVariable_isValid(varParam) || !iVariable_isTypeDatetime(varParam))
				{
					iError_reportByNumber(thisCode, _ERROR_INVALID_ARGUMENT_TYPE_COUNT, iVariable_getRelatedComp(thisCode, varParam), false);
					return(NULL);
				}


				//////////
				// Grab hour, minute, second, millisecond from datetime
				//////
					iiVariable_computeHhMmSsMss_fromf32(varParam->value.data_dt->seconds, &lnHour, &lnMinute, &lnSecond, &lnMillisecond);

			} else {
				// Use the current datetime
				if (_settings)		iTime_getLocalOrSystem(&lst, propGet_settings_TimeLocal(_settings));
				else				GetLocalTime(&lst);
				lnHour			= lst.wHour;
				lnMinute		= lst.wMinute;
				lnSecond		= lst.wSecond;
				lnMillisecond	= lst.wMilliseconds;

			}

		//////////
		// Create output variable
		//////
			switch (tnFunctionType)
			{
				case _HMS_COMMON_HOUR:		lnResult = lnHour;		break;
				case _HMS_COMMON_MINUTE:	lnResult = lnMinute;	break;
				case _HMS_COMMON_SECOND:	lnResult = lnSecond;	break;

				// Should never happen
				default:
					iError_reportByNumber(thisCode, _ERROR_INTERNAL_ERROR, iVariable_getRelatedComp(thisCode, varParam), false);
					return(NULL);
			}


		//////////
		// Create the value
		//////
			result = iVariable_createAndPopulate_byText(thisCode, _VAR_TYPE_U32, (cs8*)&lnResult, sizeof(lnResult), false);
			if (!result)
				iError_reportByNumber(thisCode, _ERROR_INTERNAL_ERROR, iVariable_getRelatedComp(thisCode, varParam), false);


		//////////
		// Return the result
		//////
			return(result);
	}




//////////
//
// Function: IIF()
// Immediate if.
//
//////
// Version 0.56
// Last update:
//     Mar.22.2015
//////
// Change log:
//     Mar.22.2015 - Initial creation
//////
// Parameters:
//     varTest		-- The logical test result
//     varTrue		-- The value to use if true
//     varFalse		-- The value to use if false
//
//////
// Returns:
//    A copy of either varTrue or varFalse.
//////
	SVariable* function_iif(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable*	varTest		= returnsParams->params[0];
		SVariable*	varTrue		= returnsParams->params[1];
		SVariable*	varFalse	= returnsParams->params[2];
		bool		llTest;
		SVariable*	result;
		u32			errorNum;
        bool		error;


		//////////
		// Parameter 1 must be logical
		//////
			if (!iVariable_isValid(varTest) || !iVariable_isFundamentalTypeLogical(varTest))
			{
				iError_reportByNumber(thisCode, _ERROR_MUST_BE_LOGICAL, iVariable_getRelatedComp(thisCode, varTest), false);
				return(NULL);
			}


		//////////
        // Grab the test result
		//////
			llTest = iiVariable_getAs_bool(thisCode, varTest, false, &error, &errorNum);
			if (error)
			{
				iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varTest), false);
				return(NULL);
			}


		//////////
		// Based on the test, copy either varTrue or varFalse
		//////
			if (llTest)
			{
				// Copy true
				result = iVariable_copy(thisCode, varTrue, false);

			} else {
				// Copy false
				result = iVariable_copy(thisCode, varFalse, false);
			}


		//////////
		// Are we good?
		//////
			if (!result)
				iError_reportByNumber(thisCode, _ERROR_INTERNAL_ERROR, iVariable_getRelatedComp(thisCode, ((llTest) ? varTrue : varFalse)), false);


		//////////
        // Return our converted result
		//////
	        return(result);
	}




//////////
//
// Function: INLIST()
// A test if the value is in the list.
//
//////
// Version 0.56
// Last update:
//     Mar.22.2015
//////
// Change log:
//     Mar.22.2015 - Initial creation
//////
// Parameters:
//     varValue		-- The value to compare
//     varList1		-- A value in the list
//     varList2		-- A value in the list
//     ..
//     varList9		-- A value in the list
//
//////
// Returns:
//    Logical		-- .t. if the item is found in the list, .f. otherwise
//////
	SVariable* function_inlist(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable*	varValue = returnsParams->params[0];
		SVariable*	varList1 = returnsParams->params[1];
		bool		llResult;
		s32			lnI, lnType;
		SVariable*	result;
		u32			errorNum;
        bool		error;


		//////////
		// Parameters 1 and 2 must be present, and of equal types
		//////
			if (!iVariable_isValid(varValue))
			{
				iError_reportByNumber(thisCode, _ERROR_MISSING_PARAMETER, iVariable_getRelatedComp(thisCode, varValue), false);
				return(NULL);
			}
			if (!iVariable_isValid(varList1))
			{
				iError_reportByNumber(thisCode, _ERROR_MISSING_PARAMETER, iVariable_getRelatedComp(thisCode, varList1), false);
				return(NULL);
			}


		//////////
		// Each type must be fundamentally the same type
		//////
			for (lnI = 1, lnType = iVariable_fundamentalType(thisCode, varValue); lnI < _MAX_PARAMETER_COUNT && returnsParams->params[lnI]; lnI++)
			{

				//////////
				// Make sure this variable type matches the test value
				//////
					if (iVariable_fundamentalType(thisCode, returnsParams->params[lnI]) != lnType)
					{
						// The types do not match
						iError_reportByNumber(thisCode, _ERROR_DATA_TYPE_MISMATCH, iVariable_getRelatedComp(thisCode, returnsParams->params[lnI]), false);
						return(NULL);
					}

			}


		//////////
		// Iterate through to see if the parameters are equal
		//////
			for (lnI = 1, llResult = false; lnI < _MAX_PARAMETER_COUNT && returnsParams->params[lnI]; lnI++)
			{

				//////////
				// Compare the value with each list item
				//////
					if (iVariable_compare(thisCode, varValue, returnsParams->params[lnI], false, &error, &errorNum) == 0 && !error)
					{
						// We found a match
						llResult = true;
						break;
					}


				//////////
				// Report on errors
				//////
					if (error)
					{
						iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, returnsParams->params[lnI]), false);
						return(NULL);
					}

			}


		//////////
		// Based on the result, create the return(result)
		//////
			result = iVariable_createAndPopulate_byText(thisCode, _VAR_TYPE_LOGICAL, ((llResult) ? (s8*)&_LOGICAL_TRUE : (s8*)&_LOGICAL_FALSE), 1, false);
			if (!result)
				iError_reportByNumber(thisCode, _ERROR_INTERNAL_ERROR, iVariable_getRelatedComp(thisCode, varValue), false);


		//////////
		// Indicate our result
		//////
			return(result);
	}




//////////
//
// Function: INT()
// Takes a value and returns the INT(n) of that value.
//
//////
// Version 0.56
// Last update:
//     Apr.02.2015
//////
// Change log:
//     Apr.02.2015 - Refactoring
//     Jul.13.2014 - Initial creation
//////
// Parameters:
//     p1			-- Numeric or floating point
//
//////
// Returns:
//    INT(n) of the value in p1
//////
    SVariable* function_int(SThisCode* thisCode, SReturnsParams* returnsParams)
    {
		SVariable*	varNumber = returnsParams->params[0];
		f64			fValue;
		u32			errorNum;
        bool		error;
        SVariable*	result;


		//////////
		// Parameter 1 must be numeric
		//////
			if (!iVariable_isValid(varNumber) || !iVariable_isTypeNumeric(varNumber))
			{
				iError_reportByNumber(thisCode, _ERROR_PARAMETER_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varNumber), false);
				return(NULL);
			}


		//////////
        // Based on its type, process it accordingly
		//////
			if (iVariable_isTypeFloatingPoint(varNumber))
			{
				fValue = iiVariable_getAs_f64(thisCode, varNumber, false, &error, &errorNum);
				if (error)	{	iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varNumber), false);	return(NULL);	}

				// Convert to S64
				result = iVariable_create(thisCode, _VAR_TYPE_S64, NULL, true);
				if (result)
					*(s64*)result->value.data = (s64)fValue;

			} else {
				// Copy whatever it already is
				result = iVariable_copy(thisCode, varNumber, false);
			}


		//////////
		// Are we good?
		//////
			if (!result)
			{
				iError_report(thisCode, cgcInternalError, false);
				return(NULL);
			}


		//////////
        // Return our converted result
		//////
	        return(result);
    }




//////////
//
// Function: JUSTDRIVE()
// Returns the drive letter from the input pathname
//
//////
// Version 0.56
// Last update:
//		Dec.25.2014
//////
// Change log:
//		Dec.25.2014 - Initial creation
//////
// Parameters:
//		varString		-- Character, the input pathname
//////
// Returns:
//		Character		-- The drive component of the pathname, or the current drive if it wasn't specified, ("c:" of "c:\path\to\sample.txt")
//////
	SVariable* function_justdrive(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable*	varString = returnsParams->params[0];
		u8*			ptr;
        SVariable*	result;


		//////////
		// Parameter 1 must be character
		//////
			if (!iVariable_isValid(varString) || !iVariable_isTypeCharacter(varString))
			{
				iError_reportByNumber(thisCode, _ERROR_P1_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varString), false);
				return(NULL);
			}


		//////////
        // Based on its type, process it accordingly
		//////
			result = iVariable_create(thisCode, _VAR_TYPE_CHARACTER, NULL, true);
			if (!result)
			{
				iError_report(thisCode, cgcInternalError, false);
				return(NULL);
			}

			if (varString->value.length >= 2)
			{
				// If it is of the form "x:"... then we return the left two-most characters
				if (varString->value.data_s8[1] == ':')
				{
					// We have a drive
					ptr = varString->value.data_u8;
				}

			} else {
				// It's too short and cannot have a drive, so we'll initialize an empty variable
				ptr = NULL;
			}


		//////////
		// Populate if need be
		//////
			if (ptr)
				iDatum_duplicate(&result->value, ptr, 2);


		//////////
        // Return our converted result
		//////
	        return(result);
	}




//////////
//
// Function: JUSTEXT()
// Returns the file extension from the input pathname
//
//////
// Version 0.56
// Last update:
//		Dec.25.2014
//////
// Change log:
//      Apr.02.2015 - Refactoring
//		Dec.25.2014 - Initial creation
//////
// Parameters:
//		varString		-- Character, the input pathname
//////
// Returns:
//		Character		-- The file extension component, or an empty string if one was not specified, ("txt" of "c:\path\to\sample.txt")
//////
	SVariable* function_justext(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable*	varString = returnsParams->params[0];
		s32			lnI, lnLength;
		u8*			ptr;
        SVariable*	result;


		//////////
		// Parameter 1 must be character
		//////
			if (!iVariable_isValid(varString) || !iVariable_isTypeCharacter(varString))
			{
				iError_reportByNumber(thisCode, _ERROR_P1_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varString), false);
				return(NULL);
			}


		//////////
        // Based on its type, process it accordingly
		//////
			ptr = NULL;
			if (varString->value.length >= 1)
			{
				// Iterate backwards until we find a period.
				// If no period is found, use a blank string
				for (lnI = varString->value.length - 1, lnLength = 0; lnI > 0; lnI--, lnLength++)
				{
					if (varString->value.data_u8[lnI] == '.')
					{
						// We found a period
						ptr = varString->value.data_u8 + lnI + 1;
						break;
					}
				}
			}


		//////////
		// Populate if need be
		//////
			if (!ptr)
			{
				// Create a blank string
				result = iVariable_create(thisCode, _VAR_TYPE_CHARACTER, NULL, true);

			} else {
				// Create and copy our portion
				result = iVariable_createAndPopulate_byText(thisCode, _VAR_TYPE_CHARACTER, ptr, lnLength, false);
			}


		//////////
		// Are we good?
		//////
			if (!result)
			{
				iError_report(thisCode, cgcInternalError, false);
				return(NULL);
			}


		//////////
        // Return our converted result
		//////
	        return(result);
	}




//////////
//
// Function: JUSTFNAME()
// Returns the file name from the input pathname
//
//////
// Version 0.56
// Last update:
//		Dec.25.2014
//////
// Change log:
//		Dec.25.2014 - Initial creation
//////
// Parameters:
//		varString		-- Character, the input pathname
//////
// Returns:
//		Character		-- The file name portion of the pathname ("sample.txt" of "c:\path\to\sample.txt")
//////
	SVariable* function_justfname(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable*	varString = returnsParams->params[0];
		s32			lnI, lnLength;
		u8*			ptr;
        SVariable*	result;


		//////////
		// Parameter 1 must be character
		//////
			if (!iVariable_isValid(varString) || !iVariable_isTypeCharacter(varString))
			{
				iError_reportByNumber(thisCode, _ERROR_P1_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varString), false);
				return(NULL);
			}


		//////////
        // Based on its type, process it accordingly
		//////
			ptr = NULL;
			if (varString->value.length >= 1)
			{
				// Iterate backwards until we find a period.
				// If no period is found, use a blank string
				for (lnI = varString->value.length - 1, lnLength = 0; lnI > 0; lnI--, lnLength++)
				{
					if (varString->value.data_u8[lnI] == '\\')
					{
						// We found a backslash
						break;
					}
				}

				// Set our pointer to the filename
				ptr			= varString->value.data_u8 + lnI + ((lnI > 0) ? 1 : 0);
				lnLength	+= ((lnI > 0) ? 0 : 1);
			}


		//////////
		// Populate if need be
		//////
			if (!ptr)
			{
				// Create a blank string
				result = iVariable_create(thisCode, _VAR_TYPE_CHARACTER, NULL, true);

			} else {
				// Create and copy our portion
				result = iVariable_createAndPopulate_byText(thisCode, _VAR_TYPE_CHARACTER, ptr, lnLength, false);
			}


		//////////
		// Are we good?
		//////
			if (!result)
			{
				iError_report(thisCode, cgcInternalError, false);
				return(NULL);
			}


		//////////
        // Return our converted result
		//////
	        return(result);
	}




//////////
//
// Function: JUSTPATH()
// Returns the path from the input pathname
//
//////
// Version 0.56
// Last update:
//		Apr.02.2015
//////
// Change log:
//      Apr.02.2015 - Refactoring
//		Dec.25.2014 - Initial creation
//////
// Parameters:
//		varString		-- Character, the input pathname
//////
// Returns:
//		Character		-- The file path of the pathname ("c:\path\to" of "c:\path\to\sample.txt")
//////
	SVariable* function_justpath(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable*	varString = returnsParams->params[0];
		s32			lnLength;
		u8*			ptr;
        SVariable*	result;


		//////////
		// Parameter 1 must be character
		//////
			if (!iVariable_isValid(varString) || !iVariable_isTypeCharacter(varString))
			{
				iError_reportByNumber(thisCode, _ERROR_P1_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varString), false);
				return(NULL);
			}


		//////////
        // Based on its type, process it accordingly
		//////
			ptr = NULL;
			if (varString->value.length >= 1)
			{
				// Iterate backwards until we find a period.
				// If no period is found, use a blank string
				for (lnLength = varString->value.length - 1; lnLength >= 0; lnLength--)
				{
					if (varString->value.data_u8[lnLength] == '\\')
					{
						// We found a backslash
						ptr = varString->value.data_u8;
						if (lnLength == 0)
							++lnLength;
						break;
					}
				}
			}


		//////////
		// Populate if need be
		//////
			if (!ptr)
			{
				// Create a blank string
				result = iVariable_create(thisCode, _VAR_TYPE_CHARACTER, NULL, true);

			} else {
				// Create and copy our portion
				result = iVariable_createAndPopulate_byText(thisCode, _VAR_TYPE_CHARACTER, ptr, lnLength, false);
			}


		//////////
		// Are we good?
		//////
			if (!result)
			{
				iError_report(thisCode, cgcInternalError, false);
				return(NULL);
			}


		//////////
        // Return our converted result
		//////
	        return(result);
	}




//////////
//
// Function: JUSTSTEM()
// Returns the stem (filename left of dot-extension) from the input pathname
//
//////
// Version 0.56
// Last update:
//		Dec.25.2014
//////
// Change log:
//		Dec.25.2014 - Initial creation
//////
// Parameters:
//		varString		-- Character, the input pathname
//		varPostfixWidth	-- (optional) Numeric, the number of extra spaces to postfix pad the juststem() result with
//////
// Returns:
//		Character		-- The file name portion of the pathname ("sample" of "c:\path\to\sample.txt")
//////
	SVariable* function_juststem(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable*	varString		= returnsParams->params[0];
		SVariable*	varPostfixWidth	= returnsParams->params[1];
		s32			lnI, lnLength, lnPostfixWidth;
		u8*			ptr;
		bool		error;
		u32			errorNum;
        SVariable*	result;


		//////////
		// Parameter 1 must be character
		//////
			if (!iVariable_isValid(varString) || !iVariable_isTypeCharacter(varString))
			{
				iError_reportByNumber(thisCode, _ERROR_P1_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varString), false);
				return(NULL);
			}


		//////////
		// If parameter 2 was specified, it must be numeric
		//////
			if (varPostfixWidth)
			{
				if (!iVariable_isValid(varPostfixWidth) || !iVariable_isTypeNumeric(varPostfixWidth))
				{
					iError_reportByNumber(thisCode, _ERROR_P2_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varPostfixWidth), false);
					return(NULL);
				}
				// Grab the postfix width
				lnPostfixWidth = iiVariable_getAs_s32(thisCode, varPostfixWidth, false, &error, &errorNum);

			} else {
				// No postfix
				lnPostfixWidth = 0;
			}


		//////////
        // Based on its type, process it accordingly
		//////
			ptr		= NULL;
			result	= iVariable_create(thisCode, _VAR_TYPE_CHARACTER, NULL, true);
			if (!result)
			{
				iError_report(thisCode, cgcInternalError, false);
				return(NULL);
			}

			if (varString->value.length >= 1)
			{
				// Iterate backwards until we find a period.
				// If no period is found, use a blank string
				for (lnI = varString->value.length - 1, lnLength = 0; lnI > 0; lnI--)
				{
					if (varString->value.data_u8[lnI] == '\\')
					{
						// We found a period
						break;
					}
				}

				// Set our pointer to the filename
				ptr = varString->value.data_u8 + lnI + ((lnI > 0) ? 1 : 0);
			}


		//////////
		// Populate if need be
		//////
			if (ptr)
			{
				// Search forward until we find a period, or the end
				for (lnLength = ((lnI == 0) ? 0 : -1); lnI < varString->value.length; lnI++, lnLength++)
				{
					if (varString->value.data_u8[lnI] == '.')
						break;
				}

				// Copy the stem portion
				iDatum_allocateSpace(&result->value, lnLength + lnPostfixWidth);
				if (result->value.data && result->value.length == lnLength + lnPostfixWidth)
				{
					// Copy the ptr content
					memcpy(result->value.data_s8, ptr, lnLength);

					// Postfix width is populated with spaces
					if (lnPostfixWidth != 0)
						memset(result->value.data_s8 + lnLength, 32, lnPostfixWidth);
				}
			}


		//////////
        // Return our converted result
		//////
	        return(result);
	}




//////////
//
// Function: LEFT()
// Returns the left N characters of a string.
//
//////
// Version 0.56
// Last update:
//     Jul.12.2014
//////
// Change log:
//     Jul.12.2014 - Initial creation
//////
// Parameters:
//     pString		-- Character, the string to trim
//     pCount		-- Numeric, the number of characters to copy
//
//////
// Returns:
//    Character		-- The string of the left N characters
//////
	SVariable* function_left(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable*	varString	= returnsParams->params[0];
		SVariable*	varCount	= returnsParams->params[1];
		s32			lnLength;
		u32			errorNum;
		bool		error;
        SVariable*	result;


		//////////
		// Parameter 1 must be character
		//////
			if (!iVariable_isValid(varString) || iVariable_getType(varString) != _VAR_TYPE_CHARACTER)
			{
				iError_reportByNumber(thisCode, _ERROR_P1_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varString), false);
				return(NULL);
			}


		//////////
		// Parameter 2 must be numeric
		//////
			if (!iVariable_isValid(varCount) || !iVariable_isTypeNumeric(varCount))
			{
				iError_reportByNumber(thisCode, _ERROR_P2_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varCount), false);
				return(NULL);
			}


		//////////
        // Find out how long they want our string to be
		//////
			lnLength = iiVariable_getAs_s32(thisCode, varCount, false, &error, &errorNum);
			if (error)
			{
				iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varCount), false);
				return(NULL);
			}


		//////////
        // Create our return result
		//////
	        result = iVariable_create(thisCode, _VAR_TYPE_CHARACTER, NULL, true);
			if (!result)
			{
				iError_report(thisCode, cgcInternalError, false);
				return(NULL);
			}


		//////////
        // Copy as much of the source string as will fit
		//////
			if (lnLength > 0)
				iDatum_duplicate(&result->value, varString->value.data_u8, min(varString->value.length, lnLength));


		//////////
        // Return our converted result
		//////
	        return(result);
	}




//////////
//
// Function: LEN()
// Returns the length of the string.
//
//////
// Version 0.56
// Last update:
//     Jul.12.2014
//////
// Change log:
//     Jul.12.2014 - Initial creation
//////
// Parameters:
//     pString		-- Character, the string to return the length from
//
//////
// Returns:
//    Numeric		-- The length of the string
//////
	SVariable* function_len(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varString = returnsParams->params[0];
        SVariable* result;


		//////////
		// Parameter 1 must be character
		//////
			if (!iVariable_isValid(varString) || iVariable_getType(varString) != _VAR_TYPE_CHARACTER)
			{
				iError_reportByNumber(thisCode, _ERROR_P1_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varString), false);
				return(NULL);
			}


		//////////
        // Create our return result
		//////
	        result = iVariable_create(thisCode, _VAR_TYPE_S32, NULL, true);
			if (!result)
			{
				iError_report(thisCode, cgcInternalError, false);
				return(NULL);
			}


		//////////
		// Populate based on the length
		//////
			*(s32*)result->value.data = varString->value.length;


		//////////
        // Return our converted result
		//////
	        return(result);
	}


//////////
//
// Function: LOG()
// Returns the natural logarithm (base e) of the specified numeric expression.
//
//////
// Version 0.56
// Last update:
//     Mar.15.2015
//////
// Change log:
//     Mar.15.2015 - Initial creation by Stefano D'Amico
//////
// Parameters:
//     p1			-- Numeric or floating point
//
//////
// Returns:
//    LOG(n) of the value in p1
//////
// Example:
//    ? LOG(2)		&& Display 0.69
//////
    SVariable* function_log(SThisCode* thisCode, SReturnsParams* returnsParams)
    {
		SVariable* varNumber = returnsParams->params[0];


        // Return log
		return(ifunction_numbers_common(thisCode, varNumber, NULL, NULL, _FP_COMMON_LOG, _VAR_TYPE_F64, false, false, returnsParams));
	}




//////////
//
// Function: LOG10()
// Returns the common logarithm (base 10) of the specified numeric expression.
//
//////
// Version 0.56
// Last update:
//     Mar.15.2015
//////
// Change log:
//     Mar.15.2015 - Initial creation by Stefano D'Amico
//////
// Parameters:
//     p1			-- Numeric or floating point
//
//////
// Returns:
//    LOG10(n) of the value in p1
//////
// Example:
//    ? LOG10(2)		&& Display 0.30
//////
    SVariable* function_log10(SThisCode* thisCode, SReturnsParams* returnsParams)
    {
		SVariable* varNumber = returnsParams->params[0];


        // Return log10
		return(ifunction_numbers_common(thisCode, varNumber, NULL, NULL, _FP_COMMON_LOG10, _VAR_TYPE_F64, false, false, returnsParams));
	}




//////////
//
// Function: LOWER()
// Converts every character in the string to lowercase.
//
//////
// Version 0.56
// Last update:
//     Jul.12.2014
//////
// Change log:
//     Jul.12.2014 - Initial creation
//////
// Parameters:
//     pString		-- Character, the string to lower
//
//////
// Returns:
//    Character		-- The string with all lowercase characters converted to lowercase
//////
	SVariable* function_lower(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable*	varString = returnsParams->params[0];
		s32			lnI;
        SVariable*	result;


		//////////
		// Parameter 1 must be character
		//////
			if (!iVariable_isValid(varString) || iVariable_getType(varString) != _VAR_TYPE_CHARACTER)
			{
				iError_reportByNumber(thisCode, _ERROR_P1_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varString), false);
				return(NULL);
			}


		//////////
        // Create our return result
		//////
	        result = iVariable_create(thisCode, _VAR_TYPE_CHARACTER, NULL, true);
			if (!result)
			{
				iError_report(thisCode, cgcInternalError, false);
				return(NULL);
			}


		//////////
        // Copy the source string
		//////
	        iDatum_duplicate(&result->value, &varString->value);


		//////////
		// Lower every character
		//////
			for (lnI = 0; lnI < result->value.length; lnI++)
			{
				if (result->value.data[lnI] >= 'A' && result->value.data[lnI] <= 'Z')
					result->value.data[lnI] += 0x20;
			}


		//////////
        // Return our converted result
		//////
	        return(result);
	}




//////////
//
// Function: LTRIM()
// Trims spaces off the start of the string.
//
//////
// Version 0.56
// Last update:
//     Jul.12.2014
//////
// Change log:
//     Jul.12.2014 - Initial creation
//////
// Parameters:
//     pString		-- Character, the string to trim
//
//////
// Returns:
//    Character		-- The string with any leading spaces removed
//////
	SVariable* function_ltrim(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varString			= returnsParams->params[0];
		SVariable* varCaseInsensitive	= returnsParams->params[1];
		SVariable* varTrimChars1		= returnsParams->params[2];
		SVariable* varTrimChars2		= returnsParams->params[3];


		// Return ltrim
		return(ifunction_trim_common(thisCode, varString, varCaseInsensitive, varTrimChars1, varTrimChars2, true, false, returnsParams));
	}




//////////
//
// Function: MALP()
// Returns the 1.0 - ((255 - ALP()) / 255) calculation.
//
//////
// Version 0.56   (Determine the current version from the header in vjr.cpp)
// Last update:
//     Mar.16.2015
//////
// Change log:
//     Mar.16.2015 - Initial creation
//////
// Parameters:
//     varColor		-- Color to extract alpha channel from
//
//////
// Returns:
//    Integer in the range 0..255, or floating point in the range 0.0 to 1.0
//
//////
// Usage:
//   ? malp(lnColor)          && Returns floating point
//   ? malp(lnColor, .t.)     && Returns integer
//   ? malp(lnColor, .f.)     && Returns floating point
//////
	SVariable* function_malp(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable*	varColor		= returnsParams->params[0];
		SVariable*	varAsInteger	= returnsParams->params[1];
		u32			lnColor;
		f32			lfMalp;
		bool		llAsInteger;
		bool		error;
		u32			errorNum;
		SVariable*	result;


		//////////
		// Color must be numeric
		//////
			if (!iVariable_isValid(varColor) || !iVariable_isTypeNumeric(varColor))
			{
				iError_reportByNumber(thisCode, _ERROR_P1_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varColor), false);
				return(NULL);
			}


		//////////
		// If varAsInteger exists, it must be logical
		//////
			if (varAsInteger)
			{
				if (!iVariable_isFundamentalTypeLogical(varAsInteger))
				{
					iError_reportByNumber(thisCode, _ERROR_P1_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varColor), false);
					return(NULL);
				}

				// Grab the value
				llAsInteger = iiVariable_getAs_bool(thisCode, varAsInteger, false, &error, &errorNum);
				if (error)	{	iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varColor), false);	return(NULL);	}

			} else {
				// Set it to false
				llAsInteger = false;
			}


		//////////
		// Grab the value
		//////
			lnColor = iiVariable_getAs_u32(thisCode, varColor, false, &error, &errorNum);
			if (error)	{	iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varColor), false);	return(NULL);	}


		//////////
		// Apply the mask and shift
		//////
			lnColor &= 0xff0000000;
			lnColor >>= 24;
			if (llAsInteger)
			{
				// Unsigned 32-bit integer
				lnColor	= 255 - lnColor;
				result	= iVariable_create(thisCode, _VAR_TYPE_U32, NULL, true);
			} else {
				// Floating point
				lfMalp	= 1.0f - ((255.0f - (f32)lnColor) / 255.0f);
				result	= iVariable_create(thisCode, _VAR_TYPE_F32, NULL, true);
			}


		//////////
		// Construct our result
		//////
			if (!result)
			{
				iError_reportByNumber(thisCode, _ERROR_INTERNAL_ERROR, NULL, false);
				return(NULL);
			}


		//////////
		// Populate and return our result
		//////
			if (llAsInteger)		*result->value.data_u32 = lnColor;
			else					*result->value.data_f32 = lfMalp;
			return(result);
	}




//////////
//
// Function: MAX()
// Returns the maximum value of the two inputs.
//
//////
// Version 0.56   (Determine the current version from the header in vjr.cpp)
// Last update:
//     Jul.12.2014
//////
// Change log:
//     Jul.12.2014 - Initial creation
//////
// Parameters:
//     pLeft		-- Left-side value, first parameter
//     pRight		-- Right-side value, second parameter
//
//////
// Returns:
//    Either pLeft or pRight copied, depending on which is greater.
//    If they're equal, a copy of pLeft is returned.
//
//////
	SVariable* function_max(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable*	varLeft		= returnsParams->params[0];
		SVariable*	varRight	= returnsParams->params[1];
		bool		llLeft;
		s32			lnLeft32, lnRight32;
		s64			lnLeft64, lnRight64;
		f64			lfLeft64, lfRight64;
		bool		error;
		u32			errorNum;
		SDateTime*	dtLeft;
		SDateTime*	dtRight;
		SVariable*	result;


		//////////
		// Parameter 1 must be numeric
		//////
			if (!iVariable_isValid(varLeft))
			{
				iError_reportByNumber(thisCode, _ERROR_P1_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varLeft), false);
				return(NULL);
			}


		//////////
		// Parameter 2 must be numeric
		//////
			if (!iVariable_isValid(varRight))
			{
				iError_reportByNumber(thisCode, _ERROR_P2_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varRight), false);
				return(NULL);
			}


		//////////
		// They must be the same type
		//////
			if (iVariable_fundamentalType(thisCode, varLeft) != iVariable_fundamentalType(thisCode, varRight))
			{
				// Operand mismatch
				iError_reportByNumber(thisCode, _ERROR_DATA_TYPE_MISMATCH, iVariable_getRelatedComp(thisCode, varRight), false);
				return(NULL);
			}


		//////////
		// Determine what we're comparing
		//////
			llLeft = false;
			switch (varLeft->varType)
			{
				case _VAR_TYPE_DATE:			// Note:  Dates are stored internally as YYYYMMDD, so they can be directly compared
				case _VAR_TYPE_CHARACTER:
					if (varLeft->value.length == 0 || varRight->value.length == 0)
					{
						// At least one of them is null, return the left
						llLeft = true;

					} else {
						// They both have a non-zero length
						switch (_memicmp(varLeft->value.data, varRight->value.data, min(varLeft->value.length, varRight->value.length)))
						{
							case -1:
							case 0:
								// Left is less than or equal to right
								llLeft = true;
								break;

							default:
								// Right is less
								break;
						}
					}
					break;

				case _VAR_TYPE_DATETIME:
					dtLeft	= (SDateTime*)varLeft->value.data;
					dtRight	= (SDateTime*)varRight->value.data;
					if (dtLeft->julian < dtRight->julian)
					{
						// Left is less
						llLeft = true;

					} else if (dtLeft->julian > dtRight->julian) {
						// Right is less

					} else {
						// They are equal, compare the time
						if (dtLeft->seconds <= dtRight->seconds)
						{
							// Left is less or equal
							llLeft = true;

						} else {
							// Right is less
						}
					}
					break;

				default:
					if (iVariable_isTypeBig(varLeft) || iVariable_isTypeBig(varRight))
					{
						// It's a character compared to a character
						iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, NULL, false);
						return(NULL);

					} else if (iVariable_isTypeFloatingPoint(varLeft) || iVariable_isTypeFloatingPoint(varRight)) {
						// Comparing floating point values
						lfLeft64	= iiVariable_getAs_f64(thisCode, varLeft, false, &error, &errorNum);
						if (error)	{	iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varLeft), false);	return(NULL);	}

						lfRight64	= iiVariable_getAs_f64(thisCode, varRight, false, &error, &errorNum);
						if (error)	{	iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varRight), false);	return(NULL);	}

						// Perform the test
						if (lfLeft64 <= lfRight64)
						{
							// Left is less
							llLeft = true;

						} else {
							// Right is less
						}

					} else if (iVariable_isTypeNumeric(varLeft) || iVariable_isTypeNumeric(varRight)) {
						// Comparing numerics
						if (iVariable_isNumeric64Bit(varLeft) || iVariable_isNumeric64Bit(varRight))
						{
							// It requires a 64-bit signed compare
							lnLeft64	= iiVariable_getAs_s64(thisCode, varLeft, false, &error, &errorNum);
							if (error)	{	iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varLeft), false);	return(NULL);	}

							lnRight64	= iiVariable_getAs_s64(thisCode, varRight, false, &error, &errorNum);
							if (error)	{	iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varRight), false);	return(NULL);	}

							// Perform the test
							if (lnLeft64 <= lnRight64)
							{
								// Left is less
								llLeft = true;

							} else {
								// Right is less
							}

						} else {
							// It can be done in a 32-bit signed compare
							lnLeft32	= iiVariable_getAs_s32(thisCode, varLeft, false, &error, &errorNum);
							if (error)	{	iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varLeft), false);	return(NULL);	}

							lnRight32	= iiVariable_getAs_s32(thisCode, varRight, false, &error, &errorNum);
							if (error)	{	iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varRight), false);	return(NULL);	}

							// Perform the test
							if (lnLeft32 <= lnRight32)
							{
								// Left is less
								llLeft = true;

							} else {
								// Right is less
							}
						}

					} else {
						// We cannot compare these types
						iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, iVariable_getRelatedComp(thisCode, varLeft), false);
						return(NULL);
					}
			}
			// When we get here, llLeft is populated with our intent
			if (llLeft)
			{
				// Left is less, so duplicate right
				result = iVariable_create(thisCode, varRight->varType, NULL, true);
				if (!result)
				{
					iError_report(thisCode, cgcInternalError, false);
					return(NULL);
				}

				// Populate
				iDatum_duplicate(&result->value, &varRight->value);

			} else {
				// Right is less, so duplicate left
				result = iVariable_create(thisCode, varLeft->varType, NULL, true);
				if (!result)
				{
					iError_report(thisCode, cgcInternalError, false);
					return(NULL);
				}

				// Populate
				iDatum_duplicate(&result->value, &varLeft->value);
			}

			// Indicate our result
			return(result);
	}




//////////
//
// Function: MDY()
// Returns the specified date or datetime expression in month-day-year format with the name of the month spelled out.
//
//////
// Version 0.57
// Last update:
//     Apr.07.2015
//////
// Change log:
//     Apr.07.2015 - Initial creation by Stefano D'Amico
//////
// Parameters:
//     p1			-- Date or DateTime
//
//////
// Returns:
//    Character - If SET CENTURY is OFF, the character expression is returned in a month dd, yy format. 
//	  If SET CENTURY is ON, the format is month dd, yyyy.
//////
	SVariable* function_mdy(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varParam = returnsParams->params[0];


		// Return mdy
		return(ifunction_dtoc_common(thisCode, varParam, _DMY_COMMON_MDY));
	}




//////////
//
// Function: MIN()
// Returns the minimum value of the two inputs.
//
//////
// Version 0.56   (Determine the current version from the header in vjr.cpp)
// Last update:
//     Jul.12.2014
//////
// Change log:
//     Jul.12.2014 - Initial creation
//////
// Parameters:
//     pLeft		-- Left-side value, first parameter
//     pRight		-- Right-side value, second parameter
//
//////
// Returns:
//    Either pLeft or pRight copied, depending on which is less.
//    If they're equal, a copy of pLeft is returned.
//
//////
	SVariable* function_min(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable*	varLeft		= returnsParams->params[0];
		SVariable*	varRight	= returnsParams->params[1];
		bool		llLeft;
		s32			lnLeft32, lnRight32;
		s64			lnLeft64, lnRight64;
		f64			lfLeft64, lfRight64;
		bool		error;
		u32			errorNum;
		SDateTime*	dtLeft;
		SDateTime*	dtRight;
		SVariable*	result;


		//////////
		// Parameter 1 must be numeric
		//////
			if (!iVariable_isValid(varLeft))
			{
				iError_reportByNumber(thisCode, _ERROR_P1_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varLeft), false);
				return(NULL);
			}


		//////////
		// Parameter 2 must be numeric
		//////
			if (!iVariable_isValid(varRight))
			{
				iError_reportByNumber(thisCode, _ERROR_P2_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varRight), false);
				return(NULL);
			}


		//////////
		// They must be the same type
		//////
			if (iVariable_fundamentalType(thisCode, varLeft) != iVariable_fundamentalType(thisCode, varRight))
			{
				// Operand mismatch
				iError_reportByNumber(thisCode, _ERROR_DATA_TYPE_MISMATCH, iVariable_getRelatedComp(thisCode, varRight), false);
				return(NULL);
			}


		//////////
		// Determine what we're comparing
		//////
			llLeft = false;
			switch (varLeft->varType)
			{
				case _VAR_TYPE_DATE:			// Note:  Dates are stored internally as YYYYMMDD, so they can be directly compared
				case _VAR_TYPE_CHARACTER:
					if (varLeft->value.length == 0 || varRight->value.length == 0)
					{
						// At least one of them is null, return the left
						llLeft = true;

					} else {
						// They both have a non-zero length
						switch (_memicmp(varLeft->value.data, varRight->value.data, min(varLeft->value.length, varRight->value.length)))
						{
							case -1:
							case 0:
								// Left is less than or equal to right
								llLeft = true;
								break;

							default:
								// Right is less
								break;
						}
					}
					break;

				case _VAR_TYPE_DATETIME:
					dtLeft	= (SDateTime*)varLeft->value.data;
					dtRight	= (SDateTime*)varRight->value.data;
					if (dtLeft->julian < dtRight->julian)
					{
						// Left is less
						llLeft = true;

					} else if (dtLeft->julian > dtRight->julian) {
						// Right is less

					} else {
						// They are equal, compare the time
						if (dtLeft->seconds <= dtRight->seconds)
						{
							// Left is less or equal
							llLeft = true;

						} else {
							// Right is less
						}
					}
					break;

				default:
					if (iVariable_isTypeBig(varLeft) || iVariable_isTypeBig(varRight))
					{
						// It's a character compared to a character
						iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, NULL, false);
						return(NULL);

					} else if (iVariable_isTypeFloatingPoint(varLeft) || iVariable_isTypeFloatingPoint(varRight)) {
						// Comparing floating point values
						lfLeft64	= iiVariable_getAs_f64(thisCode, varLeft, false, &error, &errorNum);
						if (error)	{	iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varLeft), false);	return(NULL);	}

						lfRight64	= iiVariable_getAs_f64(thisCode, varRight, false, &error, &errorNum);
						if (error)	{	iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varRight), false);	return(NULL);	}

						// Perform the test
						if (lfLeft64 <= lfRight64)
						{
							// Left is less
							llLeft = true;

						} else {
							// Right is less
						}

					} else if (iVariable_isTypeNumeric(varLeft)) {
						// Comparing numerics
						if (iVariable_isNumeric64Bit(varLeft) || iVariable_isNumeric64Bit(varRight))
						{
							// It requires a 64-bit signed compare
							lnLeft64	= iiVariable_getAs_s64(thisCode, varLeft, false, &error, &errorNum);
							if (error)	{	iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varLeft), false);	return(NULL);	}

							lnRight64	= iiVariable_getAs_s64(thisCode, varRight, false, &error, &errorNum);
							if (error)	{	iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varRight), false);	return(NULL);	}

							// Perform the test
							if (lnLeft64 <= lnRight64)
							{
								// Left is less
								llLeft = true;

							} else {
								// Right is less
							}

						} else {
							// It can be done in a 32-bit signed compare
							lnLeft32	= iiVariable_getAs_s32(thisCode, varLeft, false, &error, &errorNum);
							if (error)	{	iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varLeft), false);	return(NULL);	}

							lnRight32	= iiVariable_getAs_s32(thisCode, varRight, false, &error, &errorNum);
							if (error)	{	iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varRight), false);	return(NULL);	}

							// Perform the test
							if (lnLeft32 <= lnRight32)
							{
								// Left is less
								llLeft = true;

							} else {
								// Right is less
							}
						}

					} else {
						// We cannot compare these types
						iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, iVariable_getRelatedComp(thisCode, varLeft), false);
						return(NULL);
					}
			}
			// When we get here, llLeft is populated with our intent
			if (llLeft)
			{
				// Left is less, so copy left
				result = iVariable_create(thisCode, varLeft->varType, NULL, true);
				if (!result)
				{
					iError_report(thisCode, cgcInternalError, false);
					return(NULL);
				}

				// Populate
				iDatum_duplicate(&result->value, &varLeft->value);

			} else {
				// Right is less, so copy right
				result = iVariable_create(thisCode, varRight->varType, NULL, true);
				if (!result)
				{
					iError_report(thisCode, cgcInternalError, false);
					return(NULL);
				}

				// Populate
				iDatum_duplicate(&result->value, &varRight->value);
			}

			// Indicate our result
			return(result);
	}




//////////
//
// Function: MINUTE()
// Returns the minute portion from a DateTime expression.
//
//////
// Version 0.57
// Last update:
//     Apr.07.2015
//////
// Change log:
//     Apr.07.2015 - Initial creation by Stefano D'Amico
//////
// Parameters:
//     varParam		-- Specifies a DateTime expression from which MINUTE( ) returns the minute
//
//////
// Returns:
//    MINUTE( ) returns a numeric value.
//////
	SVariable* function_minute(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable*	varParam = returnsParams->params[0];


		// Return minute
		return(ifunction_hhmmss_common(thisCode, varParam, _HMS_COMMON_MINUTE));
	}




//////////
//
// Function: MOD()
// Divides one numeric expression by another numeric expression and returns the remainder.
//
//////
// Version 0.56   (Determine the current version from the header in vjr.cpp)
// Last update:
//     Mar.19.2015
//////
// Change log:
//     Mar.19.2015 - Refactoring by Stefano D'Amico
//     Mar.14.2015 - Fix bug when lfMod = 0 by Stefano D'Amico			// https://github.com/RickCHodgin/libsf/issues/2
//     Mar.08.2015 - Merge into main by Rick C. Hodgin, reformatting
//     Feb.28.2015 - Initial creation by Stefano D'Amico
//////
// Parameters:
//    nDividend		-- Specifies the dividend
//    nDivisor		-- Specifies the divisor
//
//////
// Returns:
//    Numeric		-- Returns the remainder
//////
// Example:
//    ? MOD(5, 2)      && 1
//    ? MOD(5, -2)     && -1
//    ? MOD(5.3, 2)    && 1.3
//    ? MOD(5.3, -2)   && -0.7
//////
	SVariable* function_mod(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable*	varDividend	= returnsParams->params[0];
		SVariable*	varDivisor	= returnsParams->params[1];


		// Return mod
		return(ifunction_numbers_common(thisCode, varDividend, varDivisor, NULL, _FP_COMMON_MOD, _VAR_TYPE_F64, true, false, returnsParams));
	}




//////////
//
// Function: MONTH()
// Returns the number of the month for a given Date or DateTime expression.
//
//////
// Version 0.57
// Last update:
//     Apr.04.2015
//////
// Change log:
//     Apr.04.2015 - Initial creation by Stefano D'Amico
//////
// Parameters:
//     p1			-- Date or DateTime
//
//////
// Returns:
//    MONTH( ) returns a number from 1 through 12. January is month 1, and December is month 12.
//////
// Example:
//	  dt = datetime()	&& Apr.06.2015
//    ? MONTH(dt)		&& Displays 4
//    ? MONTH()			&& Displays current date's month number
//////
	SVariable* function_month(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varParam = returnsParams->params[0];

		// Return month
		return(ifunction_day_month_year_common(thisCode, varParam, _DMY_COMMON_MONTH));
	}




//////////
//
// Function: NCSET()
// Nuance compatibility settings. Used to enable or disable enhancements
// in VXB which may not be present in other xbase languages.
//
//////
// Version 0.56
// Last update:
//     Mar.15.2015
//////
// Change log:
//     Mar.15.2015 -- Initial creation
//////
// Parameters:
//    varIndex		-- The index to set
//    varP1..varP6	-- Various, depends on the indexed function's requirements
//
//////
// Returns:
//    s32			-- The number of times
//////
	SVariable* function_ncset(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable*	varIndex	= returnsParams->params[0];
		SVariable*	varP1		= returnsParams->params[1];

		s32					lnIndex, lnIndexProp;
		bool				llEnabled, llNewValue, llFound;
		SBasePropMap*		baseProp;
		SAsciiCompSearcher*	asciiComp;
		SVariable*			result;
		bool				error;
		u32					errorNum;


		//////////
		// nIndex must be numeric
		//////
			if (!iVariable_isValid(varIndex))
			{
				iError_reportByNumber(thisCode, _ERROR_P1_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varIndex), false);
				return(NULL);
			}
			if (iVariable_isTypeNumeric(varIndex))
			{
				// They have specified an index
				// We'll receive whatever they give, as it will be reported in error below
				lnIndex = iiVariable_getAs_s32(thisCode, varIndex, false, &error, &errorNum);
				if (error)	{	iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varIndex), false);	return(NULL);	}


			//////////
			// What function are they requesting?
			//////
				// Based on the index, set the value
				switch (lnIndex)
				{
					case _NCSET_CEILING_FLOOR:
						lnIndexProp = _INDEX_SET_NCSET_CEILING_FLOOR;
						break;

					case _NCSET_DATETIME_MILLISECONDS:
						lnIndexProp = _INDEX_SET_NCSET_DATETIME_MILLISECONDS;
						break;

					case _NCSET_OPTIMIZE_TABLE_WRITES:
						lnIndexProp = _INDEX_SET_NCSET_OPTIMIZE_TABLE_WRITES;
						break;

					case _NCSET_OPTIMIZE_VARIABLES:
						lnIndexProp = _INDEX_SET_NCSET_OPTIMIZE_VARIABLES;
						break;

					case _NCSET_RGBA_ALPHA_IS_OPAQUE:
						lnIndexProp = _INDEX_SET_NCSET_ALPHA_IS_OPAQUE;
						break;

					case _NCSET_SIGN_SIGN2:
						lnIndexProp = _INDEX_SET_NCSET_SIGN_SIGN2;
						break;

					default:
						// Unrecognized option
						iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, iVariable_getRelatedComp(thisCode, varIndex), false);
						return(NULL);
				}


			} else if (iVariable_isTypeCharacter(varIndex)) {
				// They have specified a character string, so we can lookup the identifying tag
				for (lnIndex = _INDEX_SET_NCSET_START, baseProp = &gsProps_master[_INDEX_SET_NCSET_START - 1], llFound = false; !llFound && lnIndex <= _INDEX_SET_NCSET_END; lnIndex++, baseProp++)
				{
					// Translate the property _INDEX to its related iCode
					for (asciiComp = &cgcKeywordsVxb[0]; asciiComp->iCode != 0; asciiComp++)
					{
						// If this is the component which relates to the indicated iCode...
						if (asciiComp->iCode == baseProp->associated_iCode)
						{
							// It's the right iCode, see if the text they've provided matches up
							if (varIndex->value.length == asciiComp->length && iDatum_compare(&varIndex->value, asciiComp->keyword_s8, asciiComp->length) == 0)
							{
								lnIndexProp	= lnIndex;
								llFound		= true;
								break;
							}
						}
					}
				}

				if (!llFound)
				{
					// They've specified something we don't have
					iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, iVariable_getRelatedComp(thisCode, varIndex), false);
					return(NULL);
				}
				// When we get here, lnIndexProp is set

			} else {
				// Invalid
				iError_reportByNumber(thisCode, _ERROR_INVALID_ARGUMENT_TYPE_COUNT, iVariable_getRelatedComp(thisCode, varIndex), false);
				return(NULL);
			}


		//////////
		// Update
		//////
			// Get the existing value
			llEnabled = propGet_settings_ncset(_settings, lnIndexProp);
			if (varP1)
			{
				// They are setting the value
				if (iVariable_isFundamentalTypeLogical(varP1))
				{
					// Obtain its value as a logical
					llNewValue = iiVariable_getAs_bool(thisCode, varP1, false, &error, &errorNum);
					if (error)	{	iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varIndex), false);	return(NULL);	}

					// Set the new value
					propSet_settings_ncset_fromBool(_settings, lnIndexProp, llNewValue);

				} else {
					// The variable is not a type that can be processed as logical
					iError_reportByNumber(thisCode, _ERROR_P1_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varP1), false);
					return(NULL);
				}
			}


		//////////
		// Create the return variable
		//////
			result = iVariable_createAndPopulate_byText(thisCode, _VAR_TYPE_LOGICAL, (cs8*)((llEnabled) ? &_LOGICAL_TRUE : &_LOGICAL_FALSE), 1, false);
			if (!result)
			{
				iError_reportByNumber(thisCode, _ERROR_INTERNAL_ERROR, iVariable_getRelatedComp(thisCode, varIndex), false);
				return(NULL);
			}
			return(result);
	}




//////////
//
// Function: OCCURS(), and OCCURSC()
// Counts the number of times the first parameter is found in the second, and
// optionally with regards to case.
//
//////
// Version 0.56
// Last update:
//     Aug.03.2014
//////
// Change log:
//     Aug.03.2014 - Initial creation
//////
// Parameters:
//    pNeedle		-- The string they're looking for
//    pHaystack		-- The string being searched
//
//////
// Returns:
//    s32			-- The number of times
//////
	SVariable* function_occurs(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable*	varNeedle	= returnsParams->params[0];
		SVariable*	varHaystack	= returnsParams->params[1];
		u32			lnFoundCount;
		SVariable*	result;


		// Compute the found count
		result = ifunction_at_occurs_common(thisCode, varNeedle, varHaystack, NULL, true, false, &lnFoundCount, returnsParams);
		if (result)
		{
			// Update the return variable
			*(s32*)result->value.data_s32 = lnFoundCount;
		}

		// Return our result
		return(result);
	}

	SVariable* function_occursc(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable*	varNeedle	= returnsParams->params[0];
		SVariable*	varHaystack	= returnsParams->params[1];
		u32			lnFoundCount;
		SVariable*	result;


		// Compute the found count
		result = ifunction_at_occurs_common(thisCode, varNeedle, varHaystack, NULL, false, false, &lnFoundCount, returnsParams);
		if (result)
		{
			// Update the return variable
			*(s32*)result->value.data_s32 = lnFoundCount;
		}

		// Return our result
		return(result);
	}

	
	
	
//////////
//
// Function: OUTSIDE()
// Determines whether the value of an expression is not inclusively
// between the values of two expressions of the same type.
//
//////
// Version 0.57
// Last update:
//     Mar.23.2015
//////
// Change log:
//     Mar.23.2015 - Initial creation by Stefano D'Amico
//////
// Parameters:
//     varValue		-- Specifies an expression to evaluate.
//     varLowValue	-- Specifies the lower value in the range.
//     varHighValue	-- Specifies the upper value in the range.
//
//////
// Returns:
//    Logical		-- .t. if the item is not inclusively between the values of two expressions of the same type, .f. if between
//////
	SVariable* function_outside(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* result;


		//////////
		// Invoke BETWEEN()
		//////
			result = function_between(thisCode, returnsParams);


		//////////
		// OUTSIDE() is reverse of BETWEEN()
		//////
			if (result)
				result->value.data_u8[0] = ~result->value.data_u8[0];


		//////////
		// Indicate our result
		//////
			return(result);

	}




//////////
//
// Function: PADC(), PADL(), and PADR()
//
// and lowercases everything else.
//
//////
// Version 0.56
// Last update:
//     Aug.03.2014
//////
// Change log:
//     Aug.03.2014 - Initial creation
//////
// Parameters:
//     pExpression		-- The input, converted to character, and then aligned
//     pResultSize		-- The size of the result
//     pPadCharacter	-- Optional, the character to use, if unspecified then uses SPACE(1)
//
//////
// Returns:
//    Character         -- The string is converted from whatever it was to character, and
//                         then padded to its destination size. If the string is larger than
//                         the destination, then it remains as it is.
//////
	SVariable* function_padc(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varExpr			= returnsParams->params[0];
		SVariable* varResultSize	= returnsParams->params[1];
		SVariable* varPadCharacter	= returnsParams->params[2];


		// Return padc
		return(ifunction_pad_common(thisCode, varExpr, varResultSize, varPadCharacter, true, true, returnsParams));
	}

	SVariable* function_padl(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varExpr			= returnsParams->params[0];
		SVariable* varResultSize	= returnsParams->params[1];
		SVariable* varPadCharacter	= returnsParams->params[2];


		// Return padl
		return(ifunction_pad_common(thisCode, varExpr, varResultSize, varPadCharacter, true, false, returnsParams));
	}

	SVariable* function_padr(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varExpr			= returnsParams->params[0];
		SVariable* varResultSize	= returnsParams->params[1];
		SVariable* varPadCharacter	= returnsParams->params[2];


		// Return padr
		return(ifunction_pad_common(thisCode, varExpr, varResultSize, varPadCharacter, false, true, returnsParams));
	}

	SVariable* ifunction_pad_common(SThisCode* thisCode, SVariable* varExpr, SVariable* varResultSize, SVariable* varPadCharacter, bool tlPadLeft, bool tlPadRight, SReturnsParams* returnsParams)
	{
		u32			errorNum;
		s32			lnI, lnResultSize, lnCopyStart, lnPadLeftStopper, lnPadRightStart, lnPadRightStopper;
		bool		error;
		SVariable*	tempVar;
		SVariable*	result;


		//////////
        // Make sure our parameters are correct
		//////
			if (!tlPadLeft && !tlPadRight)
			{
				iError_reportByNumber(thisCode, _ERROR_INTERNAL_ERROR, NULL, false);
				return(NULL);
			}


		//////////
		// Parameter 1 must be valid
		//////
			if (!iVariable_isValid(varExpr))
			{
				iError_reportByNumber(thisCode, _ERROR_P1_IS_INCORRECT, NULL, false);
				return(NULL);
			}


		//////////
		// Parameter 2 must be numeric
		//////
			if (!iVariable_isValid(varResultSize) || !iVariable_isTypeNumeric(varResultSize))
			{
				iError_reportByNumber(thisCode, _ERROR_P2_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varResultSize), false);
				return(NULL);
			}
			lnResultSize = iiVariable_getAs_s32(thisCode, varResultSize, false, &error, &errorNum);
			if (error)	{	iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varResultSize), false);	return(NULL);	}


		//////////
		// Parameter 3 is optional, but if present...
		//////
			if (iVariable_isValid(varPadCharacter))
			{
				// ...it must be character
				if (!iVariable_isTypeCharacter(varPadCharacter))
				{
					iError_reportByNumber(thisCode, _ERROR_P3_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varPadCharacter), false);
					return(NULL);
				}

				// Validate the pad character is at least one character long
				if (varPadCharacter->value.length == 0)
				{
					iError_report(thisCode, (cu8*)"Parameter 3 must be at least one character", false);
					return(NULL);
				}

			} else {
				// The first occurrence is what we're after
				varPadCharacter = varConstant_space;
			}


		//////////
		// Create the return variable
		//////
			tempVar = iVariable_convertForDisplay(thisCode, varExpr);

			// If it wasn't created, or it's already as long or longer than its target, return it
			if (!tempVar || tempVar->value.length >= lnResultSize)
				return(tempVar);

			// If we get here, the result will be needed
			result = iVariable_create(thisCode, _VAR_TYPE_CHARACTER, NULL, true);
			if (!result)
			{
				iError_report(thisCode, cgcInternalError, false);
				return(NULL);
			}

			// Populate
			iDatum_allocateSpace(&result->value, lnResultSize);


		//////////
		// Determine where the string should go
		//////
			if (tlPadLeft && tlPadRight)
			{
				// Pad both
				lnCopyStart			= (lnResultSize - tempVar->value.length) / 2;
				lnPadLeftStopper	= lnCopyStart;
				lnPadRightStart		= lnCopyStart + tempVar->value.length;
				lnPadRightStopper	= lnResultSize;

			} else if (tlPadLeft) {
				// Pad left
				lnCopyStart			= lnResultSize - tempVar->value.length;
				lnPadLeftStopper	= lnCopyStart;
				lnPadRightStart		= -1;
				lnPadRightStopper	= -1;

			} else {
				// Pad right
				lnCopyStart			= 0;
				lnPadLeftStopper	= -1;
				lnPadRightStart		= tempVar->value.length;
				lnPadRightStopper	= lnResultSize;
			}


		//////////
		// Pad left
		//////
			if (lnPadLeftStopper >= 1)
			{
				// Iterate through every cycle required to populate the left side
				for (lnI = 0; lnI < lnPadLeftStopper; lnI += varPadCharacter->value.length)
				{
					// Copy this string, or as much of it will fit
					memcpy(result->value.data + lnI, varPadCharacter->value.data, min(lnPadLeftStopper - lnI, varPadCharacter->value.length));
				}
			}


		//////////
		// Pad right
		//////
			if (lnPadRightStopper >= 1)
			{
				// Iterate through every cycle required to populate the right side
				for (lnI = lnPadRightStart; lnI < lnPadRightStopper; lnI += varPadCharacter->value.length)
				{
					// Copy this string, or as much of it will fit
					memcpy(result->value.data + lnI, varPadCharacter->value.data, min(lnPadRightStopper - lnI, varPadCharacter->value.length));
				}
			}


		//////////
		// Copy the source string and delete the source string variable
		//////
			// Copy the string
			memcpy(result->value.data + lnCopyStart, tempVar->value.data, tempVar->value.length);


		//////////
		// Delete our temporary variable
		//////
			iVariable_delete(thisCode, tempVar, true);


		//////////
		// Indicate our status
		//////
			return(result);
	}




//////////
//
// Function: PAYMENT()
// Returns the amount of each periodic payment on a fixed-interest loan.
//
//////
// Version 0.56
// Last update:
//     Mar.19.2015
//////
// Change log:
//     Mar.19.2015 - Initial creation by Stefano D'Amico
//////
// Parameters:
//     p1			-- Specifies the periodic payment amount.
//     p2			-- Specifies the periodic interest rate.
//     p3			-- Specifies the total number of payments.
//
//////
// Returns:
//    PAYMENT( ) assumes a constant periodic interest rate and assumes that payments are made at the end of each period.
//////
// Example:
//   ? PAYMENT(500, 0.006, 48)	&& Displays 12.02
//////
	SVariable* function_payment(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varPayment		= returnsParams->params[0];
		SVariable* varInterestRate	= returnsParams->params[1];
		SVariable* varPeriods		= returnsParams->params[2];


		// Return payment
		return(ifunction_numbers_common(thisCode, varPayment, varInterestRate, varPeriods, _FP_COMMON_PAYMENT, _VAR_TYPE_F64, false, true, returnsParams));
	}




//////////
//
// Function: PI()
// Returns the numeric constant pi.
//
//////
// Version 0.56
// Last update:
//     Mar.15.2015
//////
// Change log:
//     Mar.15.2015 - Initial creation by Stefano D'Amico
//////
// Parameters:
//     none
//////
// Returns:
//    Numeric		-- Returns the numeric constant pi
//////
// Example:
//    ? pi()				&& Displays 3.14
//////
	SVariable* function_pi(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		// Return pi
		return(ifunction_numbers_common(thisCode, NULL, NULL, NULL, _FP_COMMON_PI, _VAR_TYPE_F64, false, false, returnsParams));
	}




//////////
//
// Function: PROPER()
// Converts the first character after every space to upper-case,
// and lowercases everything else.
//
//////
// Version 0.56
// Last update:
//     Jul.12.2014
//////
// Change log:
//     Jul.12.2014 - Initial creation
//////
// Parameters:
//     pString		-- Character, the string to proper
//
//////
// Returns:
//    Character		-- The string with all words proper'd (if I can use that as a verb)
//////
	SVariable* function_proper(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable*	varString = returnsParams->params[0];
		s32			lnI;
		bool		llUpperNext;
        SVariable*	result;


		//////////
		// Parameter 1 must be character
		//////
			if (!iVariable_isValid(varString) || iVariable_getType(varString) != _VAR_TYPE_CHARACTER)
			{
				iError_reportByNumber(thisCode, _ERROR_P1_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varString), false);
				return(NULL);
			}


		//////////
        // Create our return result
		//////
			result = iVariable_create(thisCode, _VAR_TYPE_CHARACTER, NULL, true);
			if (!result)
			{
				iError_report(thisCode, cgcInternalError, false);
				return(NULL);
			}


		//////////
        // Copy the source string
		//////
	        iDatum_duplicate(&result->value, &varString->value);


		//////////
		// Upper every first character after a space, and lower every character
		//////
			llUpperNext = true;
			for (lnI = 0; lnI < result->value.length; lnI++)
			{
				// Spaces are treated differently
				if (result->value.data[lnI] == 32)
				{
					// We've found a space, the next one will be upper-case
					llUpperNext = true;

				} else {
					// We're on data
					if (llUpperNext)
					{
						// Make this one uppercase if it's lower
						llUpperNext = false;
						if (result->value.data[lnI] >= 'a' && result->value.data[lnI] <= 'z')
							result->value.data[lnI] -= 0x20;

					} else {
						// Make this one lowercase if it's upper
						if (result->value.data[lnI] >= 'A' && result->value.data[lnI] <= 'Z')
							result->value.data[lnI] += 0x20;
					}
				}
			}


		//////////
        // Return our converted result
		//////
	        return(result);
	}




//////////
//
// Function: PV()
// Returns the present value of an investment.
//
//////
// Version 0.56
// Last update:
//     Mar.19.2015
//////
// Change log:
//     Mar.19.2015 - Refactoring by Stefano D'Amico
//     Mar.18.2015 - Initial creation by Stefano D'Amico
//////
// Parameters:
//     p1			-- Specifies the periodic payment amount.
//     p2			-- Specifies the periodic interest rate.
//     p3			-- Specifies the total number of payments.
//
//////
// Returns:
//    PV( ) computes the present value of an investment based on a series of equal periodic payments at a constant periodic interest rate.
//////
// Example:
//   ? PV(500, 0.006, 48)	&& Displays 20799.41
//////
	SVariable* function_pv(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varPayment		= returnsParams->params[0];
		SVariable* varInterestRate	= returnsParams->params[1];
		SVariable* varPeriods		= returnsParams->params[2];


		// Return pv
		return(ifunction_numbers_common(thisCode, varPayment, varInterestRate, varPeriods, _FP_COMMON_PV, _VAR_TYPE_F64, false, true, returnsParams));
	}

	
	
	
//////////
//
// Function: QUARTER()
// Returns the quarter of the year in which a date or datetime expression occurs.
//
//////
// Version 0.57
// Last update:
//     Apr.05.2015
//////
// Change log:
//     Apr.05.2015 - Initial creation by Stefano D'Amico
//////
// Parameters:
//     p1			-- Date or DateTime
//     p2			-- Specifies an optional starting month to the examined quarter
//
//////
// Returns:
//    Numeric data type.
//	  QUARTER( ) returns the quarter of the year in which a date occurs, and the values can be 1, 2, 3, or 4.
//
//////
	SVariable* function_quarter(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varParam = returnsParams->params[0];
		SVariable* varMonth = returnsParams->params[1];

		u32			lnYear, lnMonth, lnDay, lnStartingMonth, lnQuarter;
		u32			errorNum;
		bool		error;
		SYSTEMTIME	lst;
		SVariable*	result;


		//////////
		// If provided, parameter 1 must be date or datetime
		//////
			if (varParam)
			{
// TODO:  Must also support DATETIMEX at some point
				if (!iVariable_isValid(varParam) || !(iVariable_isTypeDate(varParam) || iVariable_isTypeDatetime(varParam)))
				{
					iError_reportByNumber(thisCode, _ERROR_INVALID_ARGUMENT_TYPE_COUNT, iVariable_getRelatedComp(thisCode, varParam), false);
					return(NULL);
				}

				//////////
				// Grab year, month, day from datetime or date
				//////
					if (iVariable_isTypeDatetime(varParam))			iiVariable_computeYyyyMmDd_fromJulian		(varParam->value.data_dt->julian,	&lnYear, &lnMonth, &lnDay);
					else /* date */									iiVariable_computeYyyyMmDd_fromYYYYMMDD		(varParam->value.data_u8,			&lnYear, &lnMonth, &lnDay);


			} else {
				// Use the current date
				if (_settings)		iTime_getLocalOrSystem(&lst, propGet_settings_TimeLocal(_settings));
				else				GetLocalTime(&lst);
				lnYear	= lst.wYear;
				lnMonth	= lst.wMonth;
				lnDay	= lst.wDay;
			}


		//////////
		// If provided, parameter 2 must be numeric, and in the range of 1..12
		//////
			if (varMonth)
			{
				// They have provided a month for the starting quarter
				if (iVariable_isValid(varMonth) && iVariable_isTypeNumeric(varMonth))
				{
					// Grab the value
					lnStartingMonth = (u16)iiVariable_getAs_s32(thisCode, varMonth, false, &error, &errorNum);
					if (error)
					{
						iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varMonth), false);
						return(NULL);
					}

					// Make sure it's 1..12
					if (lnStartingMonth < 1 || lnStartingMonth > 12)
					{
						iError_reportByNumber(thisCode, _ERROR_OUT_OF_RANGE, iVariable_getRelatedComp(thisCode, varMonth), false);
						return(NULL);
					}

				} else {
					// Invalid second parameter
					iError_reportByNumber(thisCode, _ERROR_INVALID_ARGUMENT_TYPE_COUNT, iVariable_getRelatedComp(thisCode, varMonth), false);
					return(NULL);
				}

			} else {
				// By default, first quarter begins in January
				lnStartingMonth = 1;
			}


		//////////
		// Compute quarter of the year
		//////
			lnQuarter = (u32)((((lnMonth + 12 - lnStartingMonth) % 12) / 3) + 1);


		//////////
		// Create the value
		//////
			result = iVariable_createAndPopulate_byText(thisCode, _VAR_TYPE_U32, (cs8*)&lnQuarter, sizeof(lnQuarter), false);
			if (!result)
				iError_reportByNumber(thisCode, _ERROR_INTERNAL_ERROR, iVariable_getRelatedComp(thisCode, varParam), false);


		//////////
		// Return the result
		//////
			return(result);

	}




//////////
//
// Function: RANGER()
// Force Into Range.  The function is the equivalent of xResult = MIN(MAX(xVar, xMin), xMax)).
//
//////
// Version 0.56   (Determine the current version from the header in vjr.cpp)
// Last update:
//     Mar.14.2015
//////
// Change log:
//     Mar.14.2015 - GitHub commit by Rick C. Hodgin, refactoring into varExpr type
//     Mar.13.2015 - Initial creation by Stefano D'Amico
//////
// Parameters:
//    varExpr	-- Specifies the expression to valuate
//    varMin		-- Specifies the min range
//    varMin		-- Specifies the max range
//
//////
// Returns:
//   Returns the value forced into the range xMin..xMax
//////
// Example:
//  x = 10
//	? x                            && Displays 10
//	? RANGER(x, 20, 80)            && Displays 20
//	x = RANGER(x, 20, 80)          && Can be used as assignment
//	? x							   && Displays 20
//////
	SVariable* function_ranger(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varExpr	= returnsParams->params[0];
		SVariable* varMin	= returnsParams->params[1];
		SVariable* varMax	= returnsParams->params[2];


		// Return ranger
		return(ifunction_ranger_common(thisCode, varExpr, varMin, varMax, NULL, returnsParams));
	}

	SVariable* function_ranger2(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable*	varExpr	= returnsParams->params[0];
		SVariable*	varMin	= returnsParams->params[1];
		SVariable*	varMax	= returnsParams->params[2];
		bool		llRanged;
		SVariable*	result;


		//////////
		// Range the result
		//////
			result = ifunction_ranger_common(thisCode, varExpr, varMin, varMax, &llRanged, returnsParams);


		//////////
		// If ranged, update varExpr to the new range
		//////
			if (llRanged && result && iVariable_isValid(varExpr))
				iVariable_set(thisCode, varExpr, result);


		//////////
		// Indicate our result
		//////
			return(result);
	}

	SVariable* ifunction_ranger_common(SThisCode* thisCode, SVariable* varExpr, SVariable* varMin, SVariable* varMax, bool* tlRanged, SReturnsParams* returnsParams)
	{
		SVariable*		tempMin;
		SVariable*		tempMax;
		SVariable*		tempResult1;
		SVariable*		tempResult2;
		SVariable*		result;
		SReturnsParams	lsReturnsParams;



		//////////
		// Test Parameter 1
		//////
			if (!iVariable_isValid(varExpr))
			{
				iError_reportByNumber(thisCode, _ERROR_P1_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varExpr), false);
				return(NULL);
			}


		//////////
		// Test Parameter 2
		//////
			if (!iVariable_isValid(varMin))
			{
				iError_reportByNumber(thisCode, _ERROR_P2_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varMin), false);
				return(NULL);
			}


		//////////
		// Test Parameter 3
		//////
			if (!iVariable_isValid(varMax))
			{
				iError_reportByNumber(thisCode, _ERROR_P2_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varMax), false);
				return(NULL);
			}


		//////////
		// They must be the same type
		//////
			if (iVariable_fundamentalType(thisCode, varExpr) != iVariable_fundamentalType(thisCode, varMin))
			{
				// Operand mismatch
				iError_reportByNumber(thisCode, _ERROR_DATA_TYPE_MISMATCH, iVariable_getRelatedComp(thisCode, varMin), false);
				return(NULL);
			}
			if (iVariable_fundamentalType(thisCode, varExpr) != iVariable_fundamentalType(thisCode, varMax))
			{
				// Operand mismatch
				iError_reportByNumber(thisCode, _ERROR_DATA_TYPE_MISMATCH, iVariable_getRelatedComp(thisCode, varMax), false);
				return(NULL);
			}


		//////////
		// Initialize
		//////
			tempMin			= NULL;
			tempMax			= NULL;
			tempResult1		= NULL;
			tempResult2		= NULL;


		//////////
		// Verify we are working with properly ordered min/max
		//////
			do {
				// Loop entered for structured programming
				memcpy(&lsReturnsParams, returnsParams, sizeof(lsReturnsParams));
				lsReturnsParams.params[0] = varMin;
				lsReturnsParams.params[1] = varMax;
				if ((tempMin = function_min(thisCode, &lsReturnsParams)) == NULL)
				{
					iError_reportByNumber(thisCode, _ERROR_INTERNAL_ERROR, iVariable_getRelatedComp(thisCode, varMax), false);
					return(NULL);
				}
				if ((tempMax = function_max(thisCode, &lsReturnsParams)) == NULL)
				{
					iError_reportByNumber(thisCode, _ERROR_INTERNAL_ERROR, iVariable_getRelatedComp(thisCode, varMax), false);
					break;
				}


			//////////
			// RANGER() executed as "result = MIN(MAX(xVar, xMin), xMax))"
			//////
				// Compute first part of result
				lsReturnsParams.params[0] = varExpr;
				lsReturnsParams.params[1] = tempMin;
				if ((tempResult1 = function_max(thisCode, &lsReturnsParams)) == NULL)
				{
					iError_reportByNumber(thisCode, _ERROR_INTERNAL_ERROR, iVariable_getRelatedComp(thisCode, varMax), false);
					break;
				}

				// Compute the final result
				lsReturnsParams.params[0] = tempResult1;
				lsReturnsParams.params[1] = tempMax;
				if ((tempResult2 = function_min(thisCode, &lsReturnsParams)) == NULL)
					iError_reportByNumber(thisCode, _ERROR_INTERNAL_ERROR, iVariable_getRelatedComp(thisCode, varMax), false);

				// Force the result into the same form as varExpr originally was
				if (tempResult2)
				{
					// Create one of the same type, and populate
					result = iVariable_create(thisCode, varExpr->varType, NULL, true);
					if (result)
					{
						// Convert to the target type for propagation through the expression
						if (!iVariable_setNumeric_toDestinationType(thisCode, result, tempResult2))
							iError_reportByNumber(thisCode, _ERROR_INTERNAL_ERROR, iVariable_getRelatedComp(thisCode, varExpr), false);
					}
				}

				// All done
				break;

			} while (1);


		//////////
		// Delete our temporary variables
		/////
			if (tempMin)		iVariable_delete(thisCode, tempMin,		true);
			if (tempMax)		iVariable_delete(thisCode, tempMax,		true);
			if (tempResult1)	iVariable_delete(thisCode, tempResult1,	true);
			if (tempResult2)	iVariable_delete(thisCode, tempResult2,	true);


		//////////
		// Indicate our true result
		//////
			return(result);
	}




//////////
//
// Function: REPLICATE()
// Returns the indicated string replicated N times.
//
//////
// Version 0.56
// Last update:
//     Jul.12.2014
//////
// Change log:
//     Jul.12.2014 - Initial creation
//////
// Parameters:
//     pString		-- Character, the string to replicate
//     pCount		-- Numeric, the number of copies to generate
//
//////
// Returns:
//    Character		-- The string of the input replicated N times
//////
	SVariable* function_replicate(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable*	varString	= returnsParams->params[0];
		SVariable*	varCount	= returnsParams->params[1];
		s32			lnI, lnCopies;
		u32			errorNum;
		bool		error;
        SVariable*	result;


		//////////
		// Parameter 1 must be character
		//////
			if (!iVariable_isValid(varString) || iVariable_getType(varString) != _VAR_TYPE_CHARACTER)
			{
				iError_reportByNumber(thisCode, _ERROR_P1_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varString), false);
				return(NULL);
			}


		//////////
		// Parameter 2 must be nmumeric
		//////
			if (!iVariable_isValid(varCount) || !iVariable_isTypeNumeric(varCount))
			{
				iError_reportByNumber(thisCode, _ERROR_P2_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varCount), false);
				return(NULL);
			}


		//////////
        // Find out how long they want our string to be
		//////
			lnCopies = iiVariable_getAs_s32(thisCode, varCount, false, &error, &errorNum);
			if (error)
			{
				iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varCount), false);
				return(NULL);
			}


		//////////
        // Create our return result
		//////
			result = iVariable_create(thisCode, _VAR_TYPE_CHARACTER, NULL, true);
			if (!result)
			{
				iError_report(thisCode, cgcInternalError, false);
				return(NULL);
			}

			if (lnCopies > 0 && varString->value.length > 0)
			{
				// Repeat the string as many as are indicated
				iDatum_allocateSpace(&result->value, lnCopies * varString->value.length);
				for (lnI = 0; lnI < lnCopies; lnI++)
					memcpy(result->value.data + (lnI * varString->value.length), varString->value.data, varString->value.length);
			}


		//////////
        // Return our converted result
		//////
	        return(result);
	}




//////////
//
// Function: RGB()
// Returns the RGB() of the three input values.
//
//////
// Version 0.56   (Determine the current version from the header in vjr.cpp)
// Last update:
//     Jul.13.2014
//////
// Change log:
//     Jul.13.2014 - Initial creation
//////
// Parameters:
//     pRed			-- Red, in the range 0..255, or 0.0..1.0
//     pGrn			-- Green, in the range 0..255, or 0.0..1.0
//     pBlu			-- Blue, in the range 0..255, or 0.0..1.0
//
//////
// Returns:
//    Numeric		-- Constructed RGB() integer
//
//////
	SVariable* function_rgb(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varRed	= returnsParams->params[0];
		SVariable* varGrn	= returnsParams->params[1];
		SVariable* varBlu	= returnsParams->params[2];


		// Return rgb
		return(ifunction_rgba_common(thisCode, varRed, varGrn, varBlu, NULL, returnsParams));
	}

	SVariable* ifunction_rgba_common(SThisCode* thisCode, SVariable* varRed, SVariable* varGrn, SVariable* varBlu, SVariable* varAlp, SReturnsParams* returnsParams)
	{
		f32			lfRed, lfGrn, lfBlu, lfAlp;
		s32			lnRed, lnGrn, lnBlu, lnAlp;
		bool		error;
		u32			errorNum;
		SVariable*	result;


		//////////
		// Parameter 1 must be numeric
		//////
			if (!iVariable_isValid(varRed) || !iVariable_isTypeNumeric(varRed))
			{
				iError_reportByNumber(thisCode, _ERROR_PARAMETER_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varRed), false);
				return(NULL);
			}


		//////////
		// Parameter 2 must be numeric
		//////
			if (!iVariable_isValid(varGrn) || !iVariable_isTypeNumeric(varGrn))
			{
				iError_reportByNumber(thisCode, _ERROR_PARAMETER_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varGrn), false);
				return(NULL);
			}


		//////////
		// Parameter 3 must be numeric
		//////
			if (!iVariable_isValid(varBlu) || !iVariable_isTypeNumeric(varBlu))
			{
				iError_reportByNumber(thisCode, _ERROR_PARAMETER_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varBlu), false);
				return(NULL);
			}


		//////////
		// Parameter 4 must be numeric
		//////
			if (varAlp)
			{
				if (!iVariable_isValid(varAlp) || !iVariable_isTypeNumeric(varAlp))
				{
					iError_reportByNumber(thisCode, _ERROR_PARAMETER_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varAlp), false);
					return(NULL);
				}

			} else {
				// Default to fully transparent or fully opaque based on its ncset()
				if (propGet_settings_ncset_alphaIsOpaque(_settings))	varAlp = varTwoFiftyFive;
				else													varAlp = varZero;
			}


		//////////
		// Red
		//////
			if (iVariable_isTypeFloatingPoint(varRed))
			{
				// It is a floating point, which means it must be in the range 0..1
				lfRed = iiVariable_getAs_f32(thisCode, varRed, false, &error, &errorNum);
				if (error)	{	iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varRed), false);	return(NULL);	}
				lnRed = (s32)(255.0f * min(max(lfRed, 0.0f), 1.0f));

			} else {
				// It is an integer, which means it must be in the range 0..255
				lnRed = iiVariable_getAs_s32(thisCode, varRed, false, &error, &errorNum);
				if (error)	{	iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varRed), false);	return(NULL);	}
			}
			if (lnRed < 0 || lnRed > 255)
			{
				iError_reportByNumber(thisCode, _ERROR_OUT_OF_RANGE, iVariable_getRelatedComp(thisCode, varRed), false);
				return(NULL);
			}


		//////////
		// Green
		//////
			if (iVariable_isTypeFloatingPoint(varGrn))
			{
				// It is a floating point, which means it must be in the range 0..1
				lfGrn = iiVariable_getAs_f32(thisCode, varGrn, false, &error, &errorNum);
				if (error)	{	iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varGrn), false);	return(NULL);	}
				lnGrn = (s32)(255.0f * min(max(lfGrn, 0.0f), 1.0f));

			} else {
				// It is an integer, which means it must be in the range 0..255
				lnGrn = iiVariable_getAs_s32(thisCode, varGrn, false, &error, &errorNum);
				if (error)	{	iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varGrn), false);	return(NULL);	}
			}
			if (lnGrn < 0 || lnGrn > 255)
			{
				iError_reportByNumber(thisCode, _ERROR_OUT_OF_RANGE, iVariable_getRelatedComp(thisCode, varGrn), false);
				return(NULL);
			}


		//////////
		// Blue
		//////
			if (iVariable_isTypeFloatingPoint(varBlu))
			{
				// It is a floating point, which means it must be in the range 0..1
				lfBlu = iiVariable_getAs_f32(thisCode, varBlu, false, &error, &errorNum);
				if (error)	{	iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varBlu), false);	return(NULL);	}
				lnBlu = (s32)(255.0f * min(max(lfBlu, 0.0f), 1.0f));

			} else {
				// It is an integer, which means it must be in the range 0..255
				lnBlu	= iiVariable_getAs_s32(thisCode, varBlu, false, &error, &errorNum);
				if (error)	{	iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varBlu), false);	return(NULL);	}
			}
			if (lnBlu < 0 || lnBlu > 255)
			{
				iError_reportByNumber(thisCode, _ERROR_OUT_OF_RANGE, iVariable_getRelatedComp(thisCode, varBlu), false);
				return(NULL);
			}


		//////////
		// Alpha
		//////
			if (iVariable_isTypeFloatingPoint(varAlp))
			{
				// It is a floating point, which means it must be in the range 0..1
				lfAlp = iiVariable_getAs_f32(thisCode, varAlp, false, &error, &errorNum);
				if (error)	{	iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varAlp), false);	return(NULL);	}
				lnAlp = (s32)(255.0f * min(max(lfAlp, 0.0f), 1.0f));

			} else {
				// It is an integer, which means it must be in the range 0..255
				lnAlp	= iiVariable_getAs_s32(thisCode, varAlp, false, &error, &errorNum);
				if (error)	{	iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varAlp), false);	return(NULL);	}
			}
			if (lnAlp < 0 || lnAlp > 255)
			{
				iError_reportByNumber(thisCode, _ERROR_OUT_OF_RANGE, iVariable_getRelatedComp(thisCode, varAlp), false);
				return(NULL);
			}


		//////////
        // Create the return(result)
		//////
	        result = iVariable_create(thisCode, _VAR_TYPE_U32, NULL, true);
			if (!result)
			{
				iError_report(thisCode, cgcInternalError, false);
				return(NULL);
			}


		//////////
        // Populate the return value
		//////
			*(u32*)result->value.data = bgra((u32)lnBlu, (u32)lnGrn, (u32)lnRed, (u32)lnAlp);


		//////////
        // Return our converted result
		//////
	        return(result);
	}




//////////
//
// Function: RGBA()
// Returns the RGBA() of the four input values.
//
//////
// Version 0.56   (Determine the current version from the header in vjr.cpp)
// Last update:
//     Jul.13.2014
//////
// Change log:
//     Jul.13.2014 - Initial creation
//////
// Parameters:
//     pRed			-- Red, in the range 0..255, or 0.0..1.0
//     pGrn			-- Green, in the range 0..255, or 0.0..1.0
//     pBlu			-- Blue, in the range 0..255, or 0.0..1.0
//     pAlp			-- Blue, in the range 0..255, or 0.0..1.0
//
//////
// Returns:
//    Numeric		-- Constructed RGBA() integer
//
//////
	SVariable* function_rgba(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varRed	= returnsParams->params[0];
		SVariable* varGrn	= returnsParams->params[1];
		SVariable* varBlu	= returnsParams->params[2];
		SVariable* varAlp	= returnsParams->params[3];


		// Return rgba
		return(ifunction_rgba_common(thisCode, varRed, varGrn, varBlu, varAlp, returnsParams));
	}




//////////
//
// Function: RED()
// Retrieves the red channel from an RGBA or BGRA color.
//
//////
// Version 0.56
// Last update:
//     Mar.16.2015
//////
// Change log:
//     Mar.16.2015 - Initial creation
//////
// Parameters:
//     varColor		-- Numeric, a color (0..(2^32)-1)
//
//////
// Returns:
//    Numeric	-- Input number converted to ASCII value number
//////
	SVariable* function_red(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varColor = returnsParams->params[0];


		// Return red
		return(ifunction_color_common(thisCode, varColor, 0x000000ff, 0, returnsParams));
	}

	SVariable* ifunction_color_common(SThisCode* thisCode, SVariable* varColor, u32 tnMask, u32 tnShift, SReturnsParams* returnsParams)
	{
		u32			lnColor;
		bool		error;
		u32			errorNum;
		SVariable*	result;


		//////////
		// Color must be numeric
		//////
			if (!iVariable_isValid(varColor) || !iVariable_isTypeNumeric(varColor))
			{
				iError_reportByNumber(thisCode, _ERROR_PARAMETER_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varColor), false);
				return(NULL);
			}


		//////////
		// Grab the value
		//////
			lnColor = iiVariable_getAs_u32(thisCode, varColor, false, &error, &errorNum);
			if (error)	{	iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varColor), false);	return(NULL);	}


		//////////
		// Apply the mask and shift
		//////
			lnColor &= tnMask;
			if (tnShift != 0)
				lnColor >>= tnShift;


		//////////
		// Construct our result
		//////
			result = iVariable_create(thisCode, _VAR_TYPE_U32, NULL, true);
			if (!result)
			{
				iError_reportByNumber(thisCode, _ERROR_INTERNAL_ERROR, NULL, false);
				return(NULL);
			}


		//////////
		// Populate and return our result
		//////
			*result->value.data_u32 = lnColor;
			return(result);
	}




//////////
//
// Function: RIGHT()
// Returns the right N characters of a string.
//
//////
// Version 0.56
// Last update:
//     Jul.12.2014
//////
// Change log:
//     Jul.12.2014 - Initial creation
//////
// Parameters:
//     pString		-- Character, the string to trim
//     pCount		-- Numeric, the number of characters to copy
//
//////
// Returns:
//    Character		-- The string of the right N characters
//////
	SVariable* function_right(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable*	varString	= returnsParams->params[0];
		SVariable*	varCount	= returnsParams->params[1];
		s32			lnStart, lnLength;
		u32			errorNum;
		bool		error;
        SVariable*	result;


		//////////
		// Parameter 1 must be character
		//////
			if (!iVariable_isValid(varString) || iVariable_getType(varString) != _VAR_TYPE_CHARACTER)
			{
				iError_reportByNumber(thisCode, _ERROR_P1_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varString), false);
				return(NULL);
			}


		//////////
		// Parameter 2 must be nmumeric
		//////
			if (!iVariable_isValid(varCount) || !iVariable_isTypeNumeric(varCount))
			{
				iError_reportByNumber(thisCode, _ERROR_P2_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varCount), false);
				return(NULL);
			}


		//////////
        // Find out how long they want our string to be
		//////
			lnLength = iiVariable_getAs_s32(thisCode, varCount, false, &error, &errorNum);
			if (error)
			{
				iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varCount), false);
				return(NULL);
			}


		//////////
        // Create our return result
		//////
	        result = iVariable_create(thisCode, _VAR_TYPE_CHARACTER, NULL, true);
			if (!result)
			{
				iError_report(thisCode, cgcInternalError, false);
				return(NULL);
			}


		//////////
        // Copy as much of the source string as will fit
		//////
			if (lnLength >= varString->value.length)
			{
				// Copy only the length of the current string
				iDatum_duplicate(&result->value, &varString->value);

			} else if (lnLength > 0) {
				// We can do an extraction
				lnStart = varString->value.length - lnLength;
				iDatum_duplicate(&result->value, varString->value.data_u8 + lnStart, lnLength);
			}


		//////////
        // Return our converted result
		//////
	        return(result);
	}




//////////
//
// Function: ROUND()
// Returns a numeric expression rounded to a specified number of decimal places.
//
//////
// Version 0.56   (Determine the current version from the header in vjr.cpp)
// Last update:
//     Mar.17.2015
//////
// Change log:
//     Mar.17.2015 - Initial creation by Stefano D'Amico
//////
// Parameters:
//    varNumber			-- Specifies the numeric expression whose value is to be rounded.
//    varDecimalPlaces	-- Specifies the number of decimal places nExpression is rounded to.
//
//////
// Returns:
//    Numeric		-- ROUND( ) returns a value rounded to the nearest decimal position as specified by nDecimalPlaces.
//////
// Example:
//    ? ROUND(53.213, 2)   && 53.21
//    ? ROUND(532, -2)     && 500
//////
	SVariable* function_round(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable*	varNumber			= returnsParams->params[0];
		SVariable*	varDecimalPlaces	= returnsParams->params[1];
		f64			lfValue, lfRounded;
		s32			lnDecimalPlaces;
		bool		error;
		u32			errorNum;
		SVariable*	result;


//TODO: more speed by type checking :-)

		//////////
		// Parameter 1 must be numeric
		//////
			if (!iVariable_isValid(varNumber) || !iVariable_isTypeNumeric(varNumber))
			{
				iError_reportByNumber(thisCode, _ERROR_P1_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varNumber), false);
				return(NULL);
			}


		//////////
		// Parameter 2 must be numeric
		//////
			if (!iVariable_isValid(varDecimalPlaces) || !iVariable_isTypeNumeric(varDecimalPlaces))
			{
				iError_reportByNumber(thisCode, _ERROR_P2_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varDecimalPlaces), false);
				return(NULL);
			}


		//////////
		// Grab the p1, convert to f64
		//////
			lfValue = iiVariable_getAs_f64(thisCode, varNumber, false, &error, &errorNum);
			if (error)
			{
				iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varNumber), false);
				return(NULL);
			}


		//////////
		// Grab the p2, convert to s32
		//////
			lnDecimalPlaces = iiVariable_getAs_s32(thisCode, varDecimalPlaces, false, &error, &errorNum);
			if (error)
			{
				iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varDecimalPlaces), false);
				return(NULL);
			}


		//////////
		// Check -18<=lnDecimalPlaces<=16,  max 16 :-(
		//////
			if (lnDecimalPlaces < -18 || lnDecimalPlaces > 16)
			{
				iError_reportByNumber(thisCode, _ERROR_OUT_OF_RANGE, iVariable_getRelatedComp(thisCode, varDecimalPlaces), false);
				return(NULL);
			}

		//////////
		// Compute round
		//////
			lfRounded = ((s64)(lfValue * pow(10.0, lnDecimalPlaces) + .5) / pow(10.0, lnDecimalPlaces));


		//////////
        // Create the return(result)
		//////
	        result = iVariable_create(thisCode, varNumber->varType, NULL, true);
			if (!result)
			{
				iError_report(thisCode, cgcInternalError, false);
				return(NULL);
			}


		//////////
        // Populate the return value
		//////
			if (!iVariable_setNumeric_toNumericType(thisCode, result, NULL, &lfRounded, NULL, NULL, NULL, NULL))
				iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varNumber), false);


		//////////
        // Return our result
		//////
	        return(result);
	}





//////////
//
// Function: RTOD()
// Converts radians to its equivalent in degrees.
//
//////
// Version 0.56
// Last update:
//     Mar.16.2015
//////
// Change log:
//     Mar.16.2015 - Initial creation by Stefano D'Amico
//////
// Parameters:
//     p1			-- Numeric or floating point
//
//////
// Returns:
//    RTOD(n) of the value in p1
//////
// Example:
//    ? RTOD(PI())		&& Display 180.00
//////
    SVariable* function_rtod(SThisCode* thisCode, SReturnsParams* returnsParams)
    {
		SVariable* varNumber = returnsParams->params[0];


        // Return rtod
		return(ifunction_numbers_common(thisCode, varNumber, NULL, NULL, _FP_COMMON_RTOD, _VAR_TYPE_F64, false, false, returnsParams));
	}




//////////
//
// Function: RTRIM()
// Trims spaces off the end of the string.
//
//////
// Version 0.56
// Last update:
//     Jul.12.2014
//////
// Change log:
//     Jul.12.2014 - Initial creation
//////
// Parameters:
//     pString		-- Character, the string to trim
//
//////
// Returns:
//    Character		-- The string with any trailing spaces removed
//////
	SVariable* function_rtrim(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varString			= returnsParams->params[0];
		SVariable* varCaseInsensitive	= returnsParams->params[1];
		SVariable* varTrimChars1		= returnsParams->params[2];
		SVariable* varTrimChars2		= returnsParams->params[3];


		// Return rtrim
		return(ifunction_trim_common(thisCode, varString, varCaseInsensitive, varTrimChars1, varTrimChars2, false, true, returnsParams));
	}




//////////
//
// Function: SEC()
// Returns the seconds portion from a DateTime expression.
//
//////
// Version 0.57
// Last update:
//     Apr.07.2015
//////
// Change log:
//     Apr.07.2015 - Initial creation by Stefano D'Amico
//////
// Parameters:
//     varParam		-- Specifies a DateTime expression from which SEC( ) returns the seconds
//
//////
// Returns:
//    SEC( ) returns a numeric value.
//////
	SVariable* function_sec(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable*	varParam = returnsParams->params[0];


		// Return second
		return(ifunction_hhmmss_common(thisCode, varParam, _HMS_COMMON_SECOND));
	}




//////////
//
// Function: SECONDS()
// Returns the number of seconds that have elapsed since midnight.
//
//////
// Version 0.57
// Last update:
//     Apr.07.2015
//////
// Change log:
//     Apr.07.2015 - Initial creation by Stefano D'Amico
//////
// Parameters:
//     none
//
//////
// Returns:
//    Numeric. SECONDS( ) returns a numeric value in decimal format with a resolution of 1 millisecond.
//////
	SVariable* function_seconds(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		f64			lfResult;
		SYSTEMTIME	lst;
		SVariable*	result;


		//////////
		// Compute the number of seconds that have elapsed since midnight
		//////
			if (_settings)		iTime_getLocalOrSystem(&lst, propGet_settings_TimeLocal(_settings));
			else				GetLocalTime(&lst);
			lfResult =		((f64)lst.wHour			* 3600.0	)
						+	((f64)lst.wMinute		* 60.0		)
						+	((f64)lst.wSecond					)
						+	((f64)lst.wMilliseconds	* 0.001		);


		//////////
		// Create and populate output variable
		//////
			result = iVariable_createAndPopulate_byText(thisCode, _VAR_TYPE_F64, (s8*)&lfResult, sizeof(lfResult), false);
			if (!result)
			{
				iError_reportByNumber(thisCode, _ERROR_INTERNAL_ERROR, NULL, false);
				return(NULL);
			}


		//////////
        // return(result)
		//////
	        return(result);
	}




//////////
//
// Function: SET()
// Retrieves current settings
//
//////
// Version 0.56
// Last update:
//     Jul.12.2014
//////
// Change log:
//     Jul.12.2014 - Initial creation
//////
// Parameters:
//     pString		-- Character, the string to trim
//
//////
// Returns:
//    Character		-- The string with any trailing spaces removed
//////
	SVariable* function_set(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable*		varIdentifier	= returnsParams->params[0];
		SVariable*		varExtraInfo	= returnsParams->params[1];
		s32				lnIndex;
		SBasePropMap*	baseProp;
		SObjPropMap*	objProp;
		SVariable*		var;
		SVariable*		result;


		//////////
		// Parameter 1 must be character
		//////
			if (!iVariable_isValid(varIdentifier) || !iVariable_isTypeCharacter(varIdentifier))
			{
				iError_reportByNumber(thisCode, _ERROR_PARAMETER_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varIdentifier), false);
				return(NULL);
			}


		//////////
		// Parameter 2 is ignored for now
		//////



		//////////
		// Locate the indicated setting
		//////
			for (lnIndex = _INDEX_SET_FIRST_ITEM; gsProps_master[lnIndex].index != 0; lnIndex++)
			{
				// Does this setting name match?
				if (gsProps_master[lnIndex].propNameLength == varIdentifier->value.length && _memicmp(gsProps_master[lnIndex].propName_s8, varIdentifier->value.data_s8, varIdentifier->value.length) == 0)
				{

					//////////
					// This is the setting
					//////
						var = iObjProp_get_variable_byIndex(thisCode, _settings, gsProps_master[lnIndex].index, &baseProp, &objProp);
						if (!var || !baseProp || !objProp)
						{
							// Should never happen, if it does it means something's not setup properly in the properties, or there's a memory corruption
							iError_signal(thisCode, _ERROR_INTERNAL_ERROR, iVariable_getRelatedComp(thisCode, varIdentifier), false, NULL, false);
							return(NULL);
						}
						// Note:  var is the actual _settings variable, so a copy must be made if returning this value.


					//////////
					// If there's a getter, translate the actual variable into its displayable form
					//////
						if (objProp->_getterObject_get)
							 return(objProp->getterObject_get(thisCode, var, iVariable_getRelatedComp(thisCode, varIdentifier), false));


					//////////
					// If we get here, return a copy of the value
					//////
						result = iVariable_copy(thisCode, var, false);


					//////////
					// Are we good?
					//////
						if (!result)
							iError_reportByNumber(thisCode, _ERROR_INTERNAL_ERROR, iVariable_getRelatedComp(thisCode, varIdentifier), false);


					//////////
					// Indicate the result
					//////
						return(result);

				}
			}


		//////////
		// If we get here, we didn't find that setting
		//////
			iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, NULL, false);
			return(NULL);
	}




//////////
//
// Function: SIGN()
// Returns a numeric value of 1, -1, or 0 if varNumber is positive,
// negative, or 0 value.
//
//////
//
// Function: SIGN2()
// Returns a numeric value of 1 if varNumber >= 0, and -1 otherwise.
//
//////
// Version 0.56
// Last update:
//     Mar.14.2015
//////
// Change log:
//     Mar.15.2015 - Added common() and sign2() functions
//     Mar.14.2015 - Merge into main by Rick C. Hodgin, refactor result to match varNumber varType
//     Mar.14.2015 - Initial creation by Stefano D'Amico
//////
// Parameters:
//     p1			-- Numeric or floating point
//
//////
// Returns:
//    SIGN(n) of the value in p1
//////
// Example:
//    ? sign(2)				&& Displays 1
//    ? sign(-2)			&& Displays -1
//    ? sign(0)				&& Displays 0
//    ? sign(-0.0)			&& Displays 0
//    ? sign(-0.3333)		&& Displays -1
//    ? sign(2.65656)		&& Displays 1
//    ? sign(-2.65656)		&& Displays -1
//////
    SVariable* function_sign(SThisCode* thisCode, SReturnsParams* returnsParams)
    {
		SVariable* varNumber = returnsParams->params[0];


		// Return sign -- returns -1, 0, or 1
		return(ifunction_sign_common(thisCode, varNumber, false, returnsParams));
	}

	SVariable* function_sign2(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varNumber = returnsParams->params[0];


		// Return sign2 -- returns -1 if non-zero negative, 1 otherwise
		return(ifunction_sign_common(thisCode, varNumber, true, returnsParams));
	}

	SVariable* ifunction_sign_common(SThisCode* thisCode, SVariable* varNumber, bool tlIncrementZero, SReturnsParams* returnsParams)
	{
		f64			lfValue;
		bool		error;
		u32			errorNum;
        SVariable*	result;


		//////////
		// Parameter 1 must be numeric
		//////
			if (!iVariable_isValid(varNumber) || !iVariable_isTypeNumeric(varNumber))
			{
				iError_reportByNumber(thisCode, _ERROR_PARAMETER_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varNumber), false);
				return(NULL);
			}


		//////////
		// Parameter 1, Convert to f64
		//////
			lfValue = iiVariable_getAs_f64(thisCode, varNumber, false, &error, &errorNum);
			if (error)
			{
				iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varNumber), false);
				return(NULL);
			}


		//////////
		// Create output variable
		//////
			if (propGet_settings_ncset_signSign2(_settings))
			{
				// They want it to be the input type if possible
				result = iVariable_create(thisCode, varNumber->varType, NULL, true);

			} else {
				// Always an integer return value
				result = iVariable_create(thisCode, _VAR_TYPE_S32, NULL, true);
			}
			if (!result)
			{
				iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varNumber), false);
				return(NULL);
			}


		//////////
		// Compute sign
		//////
			if (lfValue != 0.0)
			{
				// Converting of lfValue to 1 or -1
				lfValue = lfValue / abs(lfValue);

			} else if (tlIncrementZero) {
				// Should we increment a 0 value (so it will be returned as 1 instead of 0)?
				++lfValue;
			}


		//////////
		// Set the value
		//////
			if (!iVariable_setNumeric_toNumericType(thisCode, result, NULL, &lfValue, NULL, NULL, NULL, NULL))
				iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varNumber), false);


		//////////
        // Return sign
		//////
	        return(result);
    }




//////////
//
// Function: SIN()
// Returns the sine of an angle.
//
//////
// Version 0.56
// Last update:
//     Mar.17.2015
//////
// Change log:
//     Mar.17.2015 - Initial creation by Stefano D'Amico
//////
// Parameters:
//     p1			-- Numeric or floating point
//
//////
// Returns:
//    SIN(n) of the value in p1
//////
// Example:
//    ? SIN(0)		&& Display 0.00
//////
    SVariable* function_sin(SThisCode* thisCode, SReturnsParams* returnsParams)
    {
		SVariable* varNumber = returnsParams->params[0];


		// Return sin
		return(ifunction_numbers_common(thisCode, varNumber, NULL, NULL, _FP_COMMON_SIN, _VAR_TYPE_F64, false, false, returnsParams));
	}




//////////
//
// Function: SLICE()
// Extracts a portion of a string.
//
//////
// Version 0.56
// Last update:
//     Mar.22.2015
//////
// Change log:
//     Mar.22.2015 - Initial creation, proposed by Stefano D'Amico.
//////
// Parameters:
//     varString	-- The string to slice into.
//     varStart		-- The offset to start the slice.  If negative, then backs off from LEN(varString).
//     varEnd		-- The offset to end at.  If negative, then backs off from LEN(varString).
//
//////
// Returns:
//    Character		-- The string which was extracted.
//////
	SVariable* function_slice(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varString	= returnsParams->params[0];
		SVariable* varStart		= returnsParams->params[1];
		SVariable* varEnd		= returnsParams->params[2];


		// Not yet completed
		iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, NULL, false);
		return(NULL);
	}




//////////
//
// Function: SPACE()
// Creates a character variable initialized with spaces.
//
//////
// Version 0.56
// Last update:
//     Jul.12.2014
//////
// Change log:
//     Jul.12.2014 - Initial creation
//////
// Parameters:
//     pCount		-- The number of spaces to populate
//
//////
// Returns:
//    Character		-- The string with any leading and trailing spaces removed
//////
	SVariable* function_space(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable*	varCount = returnsParams->params[0];
		s32			lnLength;
		u32			errorNum;
		bool		error;
        SVariable*	result;


		//////////
		// Parameter 1 must be numeric
		//////
			if (!iVariable_isValid(varCount) || !iVariable_isTypeNumeric(varCount))
			{
				iError_reportByNumber(thisCode, _ERROR_P1_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varCount), false);
				return(NULL);
			}


		//////////
        // Find out how long they want our string to be
		//////
			lnLength = iiVariable_getAs_s32(thisCode, varCount, false, &error, &errorNum);
			if (error)
			{
				iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varCount), false);
				return(NULL);
			}


		//////////
        // Create our return result
		//////
			result = iVariable_create(thisCode, _VAR_TYPE_CHARACTER, NULL, true);
			if (!result)
			{
				iError_report(thisCode, cgcInternalError, false);
				return(NULL);
			}


		//////////
        // Create the source string and initialize to spaces
		//////
	        iDatum_allocateSpace(&result->value, lnLength);
			memset(result->value.data, 32, lnLength);


		//////////
        // Return our converted result
		//////
	        return(result);
	}




//////////
//
// Function: SQRT()
// Returns the square root of the specified numeric expression.
//
//////
// Version 0.56
// Last update:
//     Mar.15.2015
//////
// Change log:
//     Mar.15.2015 - Initial creation by Stefano D'Amico
//////
// Parameters:
//     varNumber	-- Numeric or floating point
//
//////
// Returns:
//    SQRT(n) of the value in p1
//////
// Example:
//    ? SQRT(2)		&& Display 1.41
//    ? SQRT(2.0)	&& Display 1.41
//    ? SQRT(-2)	&& Error: argument cannot be negative
//////
    SVariable* function_sqrt(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varNumber = returnsParams->params[0];


		// Return sqrt
		return(ifunction_numbers_common(thisCode, varNumber, NULL, NULL, _FP_COMMON_SQRT, _VAR_TYPE_F64, false, false, returnsParams));
	}




//////////
//
// Function: STARTSWITH()
// Determines if the character string starts with the search string.
//
//////
// Version 0.56   (Determine the current version from the header in vjr.cpp)
// Last update:
//     Mar.22.2015
//////
// Change log:
//     Mar.22.2015 - Initial creation (originally proposed by Stefano D'Amico)
//////
// Parameters:
//     varString	-- Original string
//     varSearch	-- Search string to replace
//     varStart		-- Starting location within the string
//
//////
// Returns:
//    Logical		-- .t. if the search string is found in the string, .f. otherwise
//
//////
	SVariable* function_startswith(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varString	= returnsParams->params[0];
		SVariable* varSearch	= returnsParams->params[1];
		SVariable* varStart		= returnsParams->params[2];


		// Not yet completed
		iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, iVariable_getRelatedComp(thisCode, varString), false);
		return(NULL);
	}




//////////
//
// Function: STARTSWITHC()
// Case-insensitive version of STARTSWITH().
//
//////
	SVariable* function_startswithc(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varString	= returnsParams->params[0];
		SVariable* varSearch	= returnsParams->params[1];
		SVariable* varStart		= returnsParams->params[2];


		// Not yet completed
		iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, iVariable_getRelatedComp(thisCode, varString), false);
		return(NULL);
	}




//////////
//
// Function: STRTRAN()
// Converts the matching portions of the string from one form to another.
//
//////
// Version 0.56   (Determine the current version from the header in vjr.cpp)
// Last update:
//     Aug.21.2014
//////
// Change log:
//     Aug.21.2014 - Initial creation
//////
// Parameters:
//     pString			-- Original string
//     pSearch			-- Search string to replace
//     pReplace			-- String to replace with
//     pRecursiveCount	-- How many times should we recursively parse this string?
//
//////
// Returns:
//    Character		-- The original string with all components replaced
//
//////
	SVariable* function_strtran(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varString			= returnsParams->params[0];
		SVariable* varSearch			= returnsParams->params[1];
		SVariable* varReplace			= returnsParams->params[2];
		SVariable* varRecursiveCount	= returnsParams->params[3];


		// Return strtran
		return(ifunction_strtran_common(thisCode, varString, varSearch, varReplace, varRecursiveCount, true, returnsParams));
	}

	SVariable* function_strtranc(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varString			= returnsParams->params[0];
		SVariable* varSearch			= returnsParams->params[1];
		SVariable* varReplace			= returnsParams->params[2];
		SVariable* varRecursiveCount	= returnsParams->params[3];


		// Return strtranc
		return(ifunction_strtran_common(thisCode, varString, varSearch, varReplace, varRecursiveCount, false, returnsParams));
	}

	SVariable* ifunction_strtran_common(SThisCode* thisCode, SVariable* varString, SVariable* varSearch, SVariable* varReplace, SVariable* varRecursiveCount, bool tlCaseSensitive, SReturnsParams* returnsParams)
	{
		s32			lnI, lnIteration, lnSrc, lnDst, lnLength, lnRecursiveCount, lnFoundCount;
		bool		error;
		u32			errorNum;
        SVariable*	result;
		SVariable*	resultNew;


		//////////
		// Parameter 1 must be character
		//////
			if (!iVariable_isValid(varString) || !iVariable_isTypeCharacter(varString))
			{
				iError_reportByNumber(thisCode, _ERROR_P1_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varString), false);
				return(NULL);
			}


		//////////
		// Parameter 2 must be character
		//////
			if (!iVariable_isValid(varSearch) || !iVariable_isTypeCharacter(varSearch))
			{
				iError_reportByNumber(thisCode, _ERROR_P2_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varSearch), false);
				return(NULL);
			}


		//////////
		// Parameter 3 is optional, but must be character if present
		//////
			if (!iVariable_isValid(varReplace))
			{
				// They didn't provide a 3rd parameter, so we'll use a pseudo placeholder which is an empty string
				varReplace = varEmptyString;

			} else if (!iVariable_isTypeCharacter(varReplace)) {
				// It is invalid
				iError_reportByNumber(thisCode, _ERROR_P3_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varReplace), false);
				return(NULL);
			}


		//////////
		// Parameter 4 is optional, but must be numeric if present
		//////
			if (!iVariable_isValid(varRecursiveCount))
			{
				// They didn't provide a 3rd parameter, so we'll use a pseudo placeholder which is an empty string
				lnRecursiveCount = 1;

			} else if (!iVariable_isTypeNumeric(varRecursiveCount)) {
				// It is invalid
				iError_reportByNumber(thisCode, _ERROR_P4_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varRecursiveCount), false);
				return(NULL);

			} else {
				// Grab the actual value
				lnRecursiveCount = iiVariable_getAs_s32(thisCode, varRecursiveCount, false, &error, &errorNum);
				if (error)	{	iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varRecursiveCount), false);	return(NULL);	}
				if (lnRecursiveCount < 0)
				{
					// It is invalid
					iError_reportByNumber(thisCode, _ERROR_P4_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varRecursiveCount), false);
					return(NULL);
				}
			}


		//////////
		// If we aren't searching for anything, we don't need to go through the rigmarole
		//////
			// If the original string is empty, or the characters to search for are empty, then we don't need to do anything
			if (varSearch->value.length == 0 || varSearch->value.length > varString->value.length)
			{
				// Allocate a full copy of the original string
				result = iVariable_createAndPopulate_byText(thisCode, _VAR_TYPE_CHARACTER, varString->value.data_u8, varString->value.length, false);
				return(result);
			}


		//////////
		// Iterate through the string twice, the first to determine how long the destination will be, the second to copy
		//////
			for (lnIteration = 1, result = varString; lnRecursiveCount == 0 || lnIteration <= lnRecursiveCount; lnIteration++)
			{
				// Search for any matches, and determine the overall length
				for (lnI = 0, lnFoundCount = 0; lnI < result->value.length - varSearch->value.length; )
				{
					// See if this matches the source string
					if (tlCaseSensitive)
					{
						// Case-sensitive compare
						if (memcmp(result->value.data + lnI, varSearch->value.data, varSearch->value.length) == 0)
						{
							// We found a match
							++lnFoundCount;
							lnI += varSearch->value.length;

						} else {
							// Skip to the next character
							++lnI;
						}

					} else {
						// Case-insensitive compare
						if (_memicmp(result->value.data + lnI, varSearch->value.data, varSearch->value.length) == 0)
						{
							// We found a match
							++lnFoundCount;
							lnI += varSearch->value.length;

						} else {
							// Skip to the next character
							++lnI;
						}
					}
				}

				// If we didn't find any, we're done
				if (lnFoundCount == 0)
				{
					// If we haven't made an official copy yet, we need to do so now
					if (result == varString)
						result = iVariable_createAndPopulate_byText(thisCode, _VAR_TYPE_CHARACTER, varString->value.data_u8, varString->value.length, false);

					// Return our result
					return(result);
				}

				// When we get here, we have a new length for our copy
				lnLength = result->value.length - (lnFoundCount * varSearch->value.length) + (lnFoundCount * varReplace->value.length);

				// Allocate a new string of that length
				resultNew = iVariable_create(thisCode, _VAR_TYPE_CHARACTER, NULL, true);
				iDatum_allocateSpace(&resultNew->value, lnLength);

				// Copy the content
				for (lnSrc = 0, lnDst = 0; lnSrc < result->value.length; )
				{
					// See if this matches the source string
					if (tlCaseSensitive)
					{
						// Case-sensitive compare
						if (memcmp(result->value.data + lnSrc, varSearch->value.data, varSearch->value.length) == 0)
						{
							// We found a match
							memcpy(resultNew->value.data + lnDst, varReplace->value.data, varReplace->value.length);
							lnSrc += varSearch->value.length;
							lnDst += varReplace->value.length;

						} else {
							// Skip to the next character
							resultNew->value.data[lnDst] = result->value.data[lnSrc];
							++lnDst;
							++lnSrc;
						}

					} else {
						// Case-insensitive compare
						if (_memicmp(result->value.data + lnSrc, varSearch->value.data, varSearch->value.length) == 0)
						{
							// We found a match
							memcpy(resultNew->value.data + lnDst, varReplace->value.data, varReplace->value.length);
							lnSrc += varSearch->value.length;
							lnDst += varReplace->value.length;

						} else {
							// Skip to the next character
							resultNew->value.data[lnDst] = result->value.data[lnSrc];
							++lnDst;
							++lnSrc;
						}
					}
				}

				// Delete our original (if it wasn't pointing to our source string)
				if (result != varString)
					iVariable_delete(thisCode, result, true);

				// Set the new to our result
				result = resultNew;
				// Continue on for the next iteration
			}


		//////////
		// Return our final string
		/////
			return(result);
	}




//////////
//
// Function: STUFF()
// Returns a string which has been modified, having optionally some characters optionally removed, some optionally inserted.
//
//////
// Version 0.56   (Determine the current version from the header in vjr.cpp)
// Last update:
//     Jul.12.2014
//////
// Change log:
//     Jul.12.2014 - Initial creation
//////
// Parameters:
//     pOriginalString		-- Input string
//     pStartPos			-- Starting position
//     pNumToRemove			-- Number of characters to remove
//     pStuffString			-- String to insert there
//
//////
// Returns:
//    Character		-- String has been modified as per the STUFF() function.
//
//////
	SVariable* function_stuff(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable*	varOriginalString	= returnsParams->params[0];
		SVariable*	varStartPos			= returnsParams->params[1];
		SVariable*	varNumToRemove		= returnsParams->params[2];
		SVariable*	varStuffString		= returnsParams->params[3];
		s32			lnStartPosition, lnRemoveCount, lnBufferLength;
		bool		error;
		u32			errorNum;
		u8*			lcBuffer;
		SVariable*	result;


		//////////
		// Parameter 1 must be character
		//////
			if (!iVariable_isValid(varOriginalString) || !iVariable_isTypeCharacter(varOriginalString))
			{
				iError_reportByNumber(thisCode, _ERROR_P1_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varOriginalString), false);
				return(NULL);
			}


		//////////
		// Parameter 2 must be numeric
		//////
			if (!iVariable_isValid(varStartPos) || !iVariable_isTypeNumeric(varStartPos))
			{
				iError_reportByNumber(thisCode, _ERROR_P2_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varStartPos), false);
				return(NULL);
			}


		//////////
		// Parameter 3 must be numeric
		//////
			if (!iVariable_isValid(varNumToRemove) || !iVariable_isTypeNumeric(varNumToRemove))
			{
				iError_reportByNumber(thisCode, _ERROR_P3_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varNumToRemove), false);
				return(NULL);
			}


		//////////
		// Parameter 4 must be character
		//////
			if (!iVariable_isValid(varStuffString) || !iVariable_isTypeCharacter(varStuffString))
			{
				iError_reportByNumber(thisCode, _ERROR_P4_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varStuffString), false);
				return(NULL);
			}


		//////////
		// Grab the parameters as usable values
		//////
			// Your algorithm code goes here
			lnStartPosition	= iiVariable_getAs_s32(thisCode, varStartPos, false, &error, &errorNum);
			lnRemoveCount	= iiVariable_getAs_s32(thisCode, varNumToRemove, false, &error, &errorNum);


		//////////
		// If they are trying to do negative things, report it
		//////
			if (lnStartPosition < 1)		lnStartPosition		= 1;
			if (lnRemoveCount   < 0)		lnRemoveCount		= 0;


		//////////
		// Adjust them based on real-world observations from the string
		//////
			// Are they trying to start beyond the end of the string?  If so, reduce to the end.
			if (lnStartPosition > varOriginalString->value.length)
				lnStartPosition = varOriginalString->value.length + 1;

			// Are they trying to remove more than can be extracted?
			if (lnStartPosition - 1 + lnRemoveCount > varOriginalString->value.length)
				lnRemoveCount = varOriginalString->value.length - lnStartPosition + 1;


		//////////
		// Construct our destination
		//////
			lnBufferLength	= varOriginalString->value.length - lnRemoveCount + varStuffString->value.length;
			lcBuffer = (u8*)malloc(lnBufferLength);
			if (!lcBuffer)
			{
				iError_reportByNumber(thisCode, _ERROR_OUT_OF_MEMORY, NULL, false);
				return(NULL);
			}

			// Copy the first part of the original string, plus the stuffed in part, plus the end of the last part of the original string
			--lnStartPosition;

			// We only copy the first part if there is something to copy
			if (lnStartPosition > 0)
				memcpy((s8*)lcBuffer, varOriginalString->value.data, lnStartPosition);

			// We only insert our stuff string if there is something to put there
			if (varStuffString->value.length > 0)
				memcpy((s8*)lcBuffer + lnStartPosition, varStuffString->value.data, varStuffString->value.length);

			// We only copy over the last part if there's something there
			if (varOriginalString->value.length - lnStartPosition - lnRemoveCount > 0)
				memcpy((s8*)lcBuffer + lnStartPosition + varStuffString->value.length, varOriginalString->value.data + lnStartPosition + lnRemoveCount, varOriginalString->value.length - lnStartPosition - lnRemoveCount);


		//////////
        // Create the return(result)
		//////
	        result = iVariable_create(thisCode, _VAR_TYPE_CHARACTER, NULL, true);
			if (!result)
			{
				iError_report(thisCode, (u8*)"Internal error.", false);
				return(NULL);
			}


		//////////
        // Populate the return value
		//////
			iDatum_duplicate(&result->value, lcBuffer, lnBufferLength);


		//////////
		// Release the temporary buffer
		//////
			free(lcBuffer);


		//////////
        // Return our converted result
		//////
	        return(result);
	}




//////////
//
// Function: SYS()
// SYS function support (Dec.27.2014 incomplete)
//
///////
// Version 0.56
// Last update:
//     Dec.27.2014
//////
// Change log:
//     Dec.27.2014 - Initial creation
//////
// Parameters:
//		2015			-- none
//////
// Returns:
//		2015			-- Character, unique procedure name
//////
	SVariable* function_sys(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable*	varIndex	= returnsParams->params[0];
		SVariable*	varP1		= returnsParams->params[1];
		SVariable*	varP2		= returnsParams->params[2];
		s32			lnIndex;
		u32			lnExtraPrefixWidth, lnExtraPostfixWidth;
		s64			ln2015;
		u32			errorNum;
        bool		error;
		SYSTEMTIME	lst;
		SVariable*	result;


// TODO:  Untested function, breakpoint and examine
// debug_break;
		//////////
		// Parameter 1 must be numeric
		//////
			if (!iVariable_isValid(varIndex) || !iVariable_isTypeNumeric(varIndex))
			{
				iError_reportByNumber(thisCode, _ERROR_P1_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varIndex), false);
				return(NULL);
			}

			// Grab the index
			lnIndex = iiVariable_getAs_s32(thisCode, varIndex, false, &error, &errorNum);
			if (error)
			{
				// An error extracting the value (should never happen)
				iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varIndex), false);
				return(NULL);
			}


		//////////
		// Based on the function...
		//////
			switch (lnIndex)
			{
				case 2015:
					// Unique procedure names take on the form YYYYMMDDHHMMSSmmm converted to base-36, prefixed with an underscore
					if (_settings)		iTime_getLocalOrSystem(&lst, propGet_settings_TimeLocal(_settings));
					else				GetLocalTime(&lst);
					ln2015 =	(lst.wYear		* 10000000000000) +
								(lst.wMonth		* 100000000000) +
								(lst.wDay		* 1000000000) +
								(lst.wHour		* 10000000) +
								(lst.wMinute	* 100000) +
								(lst.wSecond	* 1000) +
								lst.wMilliseconds;

					// Optional 2nd and 3rd parameter indicate how many extra prefix and postfix characters to insert
					if (iVariable_isValid(varP1))
					{
						//////////
						// Since P1 was provided, it must be numeric
						//////
							if (!iVariable_isTypeNumeric(varP1))
							{
								iError_reportByNumber(thisCode, _ERROR_P2_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varP1), false);
								goto clean_exit;
							}


						//////////
						// Get the prefix width
						//////
							lnExtraPrefixWidth = iiVariable_getAs_s32(thisCode, varP1, false, &error, &errorNum);
							if (error)
							{
								iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varP1), false);
								goto clean_exit;
							}
							// Right now, we have lnExtraPrefixWidth


						/////////
						// Did they also provide a 3rd parameter?
						//////
							if (iVariable_isValid(varP2))
							{
								//////////
								// Since P2 was provided, it must be numeric
								//////
									if (!iVariable_isTypeNumeric(varP2))
									{
										iError_reportByNumber(thisCode, _ERROR_P2_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varP2), false);
										goto clean_exit;
									}


								//////////
								// Get the postfix width
								//////
									lnExtraPostfixWidth = iiVariable_getAs_s32(thisCode, varP2, false, &error, &errorNum);
									if (error)
									{
										iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varP2), false);
										goto clean_exit;
									}
									// Right now, we have lnExtraPostfixWidth

							} else {
								// Nope, just assign it to 0
								lnExtraPostfixWidth = 0;
							}

					} else {
						lnExtraPrefixWidth	= 0;
						lnExtraPostfixWidth	= 0;
					}

					// Create a variable in base-36 (uses 0..9, A..Z)
					result = iVariable_createByRadix(thisCode, ln2015, 36, 1 + lnExtraPrefixWidth, lnExtraPostfixWidth);

					// Prefix with an underscore
					if (result)
						result->value.data_u8[lnExtraPrefixWidth] = '_';

					// Right now, the variable looks something like:  _19B2L483
					break;

				default:
					// Not currently supported
					iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, iVariable_getRelatedComp(thisCode, varIndex), false);
					result = iVariable_create(thisCode, _VAR_TYPE_LOGICAL, varFalse, true);
					break;
			}

clean_exit:
		//////////
		// Clean house
		//////
			// Currently nothing to clean


		//////////
		// Indicate our result
		//////
			return(result);
	}

	// Note:  Helper function.  iFunction_sys2015() is a shortcut function for accessing the oft-used get-unique-procedure-name feature
	SVariable* iFunction_sys2015(SThisCode* thisCode, u32 tnPrefixWidth, u32 tnPostfixWidth)
	{
		s32				ln2015;
		SVariable*		varSys2015;
		SReturnsParams	returnsParams;


// TODO:  Untested function, breakpoint and examine
debug_break;
		//////////
		// Setup the function call variables
		//////
			memset(&returnsParams, 0, sizeof(returnsParams));
			ln2015 = 2015;
			returnsParams.params[0/*2015*/]		= iVariable_createAndPopulate_byText(thisCode, _VAR_TYPE_S32,	(cu8*)&ln2015,			sizeof(ln2015),			false);
			returnsParams.params[1/*prefix*/]	= iVariable_createAndPopulate_byText(thisCode, _VAR_TYPE_S32,	(cu8*)&tnPrefixWidth,	sizeof(tnPrefixWidth),	false);
			returnsParams.params[2/*postfix*/]	= iVariable_createAndPopulate_byText(thisCode, _VAR_TYPE_S32,	(cu8*)&tnPostfixWidth,	sizeof(tnPostfixWidth), false);


		//////////
		// Call the function
		//////
			varSys2015 = function_sys(thisCode, &returnsParams);


		//////////
		// Clean house
		//////
			iVariable_delete(thisCode, returnsParams.params[0], true);
			iVariable_delete(thisCode, returnsParams.params[1], true);
			iVariable_delete(thisCode, returnsParams.params[2], true);


		//////////
		// Return our value
		//////
			return(varSys2015);
	}




//////////
//
// Function: SYSMETRIC()
// Based on the index, returns a wide array of information.
//
//////
// Version 0.56
// Last update:
//     Jul.13.2014
//////
// Change log:
//     Jul.13.2014 - Initial creation
//////
// Parameters:
//     pIndex		-- Numeric, in the range 1..34
//
//////
// Returns:
//    Numeric		-- Depending on index, various value ranges are returned
//////
    SVariable* function_sysmetric(SThisCode* thisCode, SReturnsParams* returnsParams)
    {
		SVariable*	varIndex = returnsParams->params[0];
        s32			index;
		RECT		lrc;
		u32			errorNum;
        bool		error;
        SVariable*	result;


		//////////
		// Parameter 1 must be numeric
		//////
			if (!iVariable_isValid(varIndex) || !iVariable_isTypeNumeric(varIndex))
			{
				iError_reportByNumber(thisCode, _ERROR_P1_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varIndex), false);
				return(NULL);
			}


		//////////
        // It must be in the range 1..34
		//////
			index = iiVariable_getAs_s32(thisCode, varIndex, false, &error, &errorNum);
			if (error)
			{
				iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varIndex), false);
				return(NULL);

			} else if (index > 34 || index < 1) {
				// We report our own error
				iError_report(thisCode, (cu8*)"Parameter must be in the range 1..34", false);
				return(NULL);
			}


		//////////
        // Create our return result
		//////
	        result = iVariable_create(thisCode, _VAR_TYPE_S32, NULL, true);
			if (!result)
			{
				iError_report(thisCode, cgcInternalError, false);
				return(NULL);
			}


		//////////
        // Populate the result with its sysmetric()
		//////
			GetWindowRect(GetDesktopWindow(), &lrc);
			switch (index)
			{
				case 1:
					// Screen width
					*(s32*)result->value.data = (lrc.right - lrc.left);
					break;
				case 2:
					// Screen height
					*(s32*)result->value.data = (lrc.bottom - lrc.top);
					break;
				case 3:
					// Width of a sizable window frame
					*(s32*)result->value.data = bmpVjrIcon->bi.biWidth;
					break;
				case 4:
					// Height of a sizable window frame
					*(s32*)result->value.data = bmpVjrIcon->bi.biHeight;
					break;
				case 5:
					// Width of scroll arrows on a vertical scroll bar
					*(s32*)result->value.data = 0;
					break;
				case 6:
					// Height of scroll arrows on a vertical scroll bar
					*(s32*)result->value.data = 0;
					break;
				case 7:
					// Width of scroll arrows on a horizontal scroll bar
					*(s32*)result->value.data = 0;
					break;
				case 8:
					// Height of scroll arrows on a horizontal scroll bar
					*(s32*)result->value.data = 0;
					break;
				case 9:
					// Height of form caption
					*(s32*)result->value.data = bmpVjrIcon->bi.biHeight;
					break;
				case 10:
					// Width of non-sizable window frame
					*(s32*)result->value.data = bmpVjrIcon->bi.biWidth;
					break;
				case 11:
					// Height of a non-sizable window frame
					*(s32*)result->value.data = bmpVjrIcon->bi.biHeight;
					break;
				case 12:
					// Width of a double or panel window frame
					*(s32*)result->value.data = bmpVjrIcon->bi.biWidth;
					break;
				case 13:
					// Height of a double or panel window frame
					*(s32*)result->value.data = bmpVjrIcon->bi.biHeight;
					break;
				case 14:
					// Scroll box width on horizontal scroll bars in text editing windows
					*(s32*)result->value.data = 0;
					break;
				case 15:
					// Scroll box height on horizontal scroll bars in text editing windows
					*(s32*)result->value.data = 0;
					break;
				case 16:
					// Minimized window icon width
					*(s32*)result->value.data = bmpVjrIcon->bi.biWidth;
					break;
				case 17:
					// Minimized window icon height
					*(s32*)result->value.data = bmpVjrIcon->bi.biHeight;
					break;
				case 18:
					// Maximum insertion point width
					*(s32*)result->value.data = 0;
					break;
				case 19:
					// Maximum insertion point height
					*(s32*)result->value.data = 0;
					break;
				case 20:
					// Single-line menu bar height
					*(s32*)result->value.data = _MENU_BAR_HEIGHT;
					break;
				case 21:
					// Maximized window width
					*(s32*)result->value.data = (lrc.right - lrc.left);
					break;
				case 22:
					// Maximized window height
					*(s32*)result->value.data = (lrc.bottom - lrc.top);
					break;
				case 23:
					// Kanji window height
					*(s32*)result->value.data = ((GetSystemMetrics(SM_CYKANJIWINDOW) != 0) ? 1 : 0);
					break;
				case 24:
					// Minimum sizable window width
					*(s32*)result->value.data = 2 * bmpVjrIcon->bi.biWidth;
					break;
				case 25:
					// Minimum sizable window height
					*(s32*)result->value.data = 2 * bmpVjrIcon->bi.biHeight;
					break;
				case 26:
					// Minimum window width
					*(s32*)result->value.data = 2 * bmpVjrIcon->bi.biWidth;
					break;
				case 27:
					// Minimum window height
					*(s32*)result->value.data = 2 * bmpVjrIcon->bi.biHeight;
					break;
				case 28:
					// Window controls width
					*(s32*)result->value.data = 2 * bmpClose->bi.biWidth;
					break;
				case 29:
					// Window controls height
					*(s32*)result->value.data = 2 * bmpClose->bi.biHeight;
					break;
				case 30:
					// 1 if mouse hardware present, 0 otherwise
					*(s32*)result->value.data = ((GetSystemMetrics(SM_MOUSEPRESENT) != 0) ? 1 : 0);
					break;
				case 31:
					// 1 for Microsoft Windows debugging version, 0 otherwise
					*(s32*)result->value.data = ((GetSystemMetrics(SM_DEBUG) != 0) ? 1 : 0);
					break;
				case 32:
					// 1 if mouse buttons are swapped, 0 otherwise
					*(s32*)result->value.data = ((GetSystemMetrics(SM_SWAPBUTTON) != 0) ? 1 : 0);
					break;
				case 33:
					// width of a button in a half-height title bar
					*(s32*)result->value.data = bmpClose->bi.biWidth;
					break;
				case 34:
					// Height of half-height caption area
					*(s32*)result->value.data = bmpClose->bi.biHeight;
					break;
			}


		//////////
        // Return our converted result
		//////
	        return(result);
    }




//////////
//
// Function: TAN()
// This trigonometric function returns the tangent of an angle.
//
//////
// Version 0.56
// Last update:
//     Mar.19.2015
//////
// Change log:
//     Mar.19.2015 - Initial creation by Stefano D'Amico
//////
// Parameters:
//     p1			-- Numeric or floating point
//
//////
// Returns:
//    TAN(n) of the value in p1
//////
// Example:
//    ? TAN(0)		&& Display 0.00
//////
    SVariable* function_tan(SThisCode* thisCode, SReturnsParams* returnsParams)
    {
		SVariable* varNumber = returnsParams->params[0];


		// Return sin
		return(ifunction_numbers_common(thisCode, varNumber, NULL, NULL, _FP_COMMON_TAN, _VAR_TYPE_F64, false, false, returnsParams));
	}



//////////
// Rick's test code functionality using the _test() function
//////
	SVariable* function__test(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable*	varIndex = returnsParams->params[0];
		s32			lnIndex;
		bool		llValid;
		SVariable*	result;


		//////////
		// Parameter 1 must be valid
		//////
			if (!iVariable_isValid(varIndex) || !iVariable_isTypeNumeric(varIndex))
			{
				iError_reportByNumber(thisCode, _ERROR_P1_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varIndex), false);
				return(NULL);
			}


		//////////
		// Execute the function
		//////
			llValid	= false;
			lnIndex	= iiVariable_getAs_s32(thisCode, varIndex, false, NULL, NULL);
			switch (lnIndex)
			{
				case 1:
					iTest1(thisCode, returnsParams);
					break;

				default:
					iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, iVariable_getRelatedComp(thisCode, varIndex), false);
					break;
			}


		//////////
		// Create our return variable
		/////
			result = iVariable_createAndPopulate_byText(thisCode, _VAR_TYPE_LOGICAL, (cs8*)((llValid) ? &_LOGICAL_TRUE : &_LOGICAL_FALSE), 1, true);
			return(result);
	}




//////////
//
// Function: TRANSFORM()
// Converts any variable input to a character form, and applies formatting based on codes.
//
//////
// Version 0.56
// Last update:
//     Aug.03.2014
//////
// Change log:
//     Aug.03.2014 - Initial creation
//////
// Parameters:
//     pString		-- Character, the variable to transform
//     pformat		-- Character, the format codes
//
//////
// Returns:
//    Character		-- The string after the variable was converted and formatted
//////
	SVariable* function_transform(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varVariable	= returnsParams->params[0];
		SVariable* varFormat	= returnsParams->params[1];
		SVariable* result;


		//////////
		// Parameter 1 must be valid
		//////
			if (!iVariable_isValid(varVariable))
			{
				iError_reportByNumber(thisCode, _ERROR_P1_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varVariable), false);
				return(NULL);
			}


		//////////
		// Parameter 2 is optional, but if present...
		//////
			if (iVariable_isValid(varFormat))
			{
				// ...it must be character
				if (!iVariable_isTypeCharacter(varFormat))
				{
					iError_reportByNumber(thisCode, _ERROR_P2_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varFormat), false);
					return(NULL);
				}
			}


		//////////
		// Create the return variable
		//////
			result = iVariable_convertForDisplay(thisCode, varVariable);


		//////////
		// Formatters:
		//		@D		date,		convert using SET DATE
		//		@E		date,		convert using BRITISH
		//		@YL		date,		convert using LONG
		//		@YS		date,		convert using SHORT
		//		Y		logical,	use Y and N
		//		@T		character,	ALLTRIM() input before conversion
		//		@!		character,	UPPER() input
		//		!		character,	UPPER() on the character in this position
		//		.		Use decimal point
		//		,		Use 1000s separator
		//		X		Specifies output width by character count
		//
		// Output formats:
		//		@B		numeric,	left-justify
		//		@$		numeric,	append based on SET CURRENCY symbol
		//		@C		numeric,	append "CR" after if zero or positive
		//		@X		numeric,	appends "DB" after if negative
		//		@L		numeric,	prefix with leading 0s
		//		@Z		numeric,	if zero display CHR(32) instead of "0"
		//		@(		numeric,	surround with () if negative
		//		@^		numeric,	scientific notation
		//		@0		numeric,	convert to hexadecimal equivalent
		//		@R		format around other characters encountered using 9,#,! for source data
		//////


		//////////
		// Indicate our status
		//////
			return(result);
	}




//////////
//
// Function: TTOC()
// Converts a DateTime expression to a Character value with the specified format.
//
//////
// Version 0.57
// Last update:
//     Apr.07.2015
//////
// Change log:
//     Apr.07.2015 - Initial creation by Stefano D'Amico
//////
// Parameters:
//     p1			-- Datetime
//	   p2			-- Numeric: 
//						1 -- yyyymmddhhmmss
//						2 -- only the time portion of p1
//						3 -- yyyy-mm-ddThh:mm:ss 
//////
// Returns:
//    Character. TTOC( ) returns a DateTime expression as a character string.
//////
	SVariable* function_ttoc(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varParam = returnsParams->params[0];
		SVariable* varFlag = returnsParams->params[1];

		u32			lnYear, lnMonth, lnDay, lnFlag;
		s8			buffer[16];
		u32			errorNum;
		bool		error;

		SVariable*	result;


		//////////
		// Parameter 1 must be datetime
		//////
// TODO:  Must also support DATETIMEX at some point
			if (!iVariable_isValid(varParam) || !iVariable_isTypeDatetime(varParam))
			{
				iError_reportByNumber(thisCode, _ERROR_INVALID_ARGUMENT_TYPE_COUNT, iVariable_getRelatedComp(thisCode, varParam), false);
				return(NULL);
			}

		//////////
		// If Parameter 2 is provided, it must be numeric
		//////
			if (varFlag)
			{
				if (!iVariable_isValid(varFlag) || !iVariable_isTypeNumeric(varFlag))
				{
					iError_reportByNumber(thisCode, _ERROR_INVALID_ARGUMENT_TYPE_COUNT, iVariable_getRelatedComp(thisCode, varFlag), false);
					return(NULL);
				}

				// Grab the flag
				lnFlag = iiVariable_getAs_s32(thisCode, varFlag, false, &error, &errorNum);
				if (error)
				{
					// An error extracting the value (should never happen)
					iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varFlag), false);
					return(NULL);
				}	

				switch(lnFlag)
				{
					case 1:
						//	yyyymmddhhmmss 
						// TODO
					case 2:
						//	HH:MM
						// TODO
					case 3:
						// yyyy-mm-ddThh:mm:ss 
						// TODO
					default:
						// If we get here, invalid parameter specified
						iError_reportByNumber(thisCode, _ERROR_INVALID_ARGUMENT_TYPE_COUNT, iVariable_getRelatedComp(thisCode, varFlag), false);
						return(NULL);
				}
			}


		//////////
		// Create and populate the return variable
		//////
			result = iVariable_convertForDisplay(thisCode, varParam);
			if (!result)
				iError_reportByNumber(thisCode, _ERROR_INTERNAL_ERROR, iVariable_getRelatedComp(thisCode, varParam), false);


		//////////
		// Signify our result
		//////
			return(result);

	}




//////////
//
// Function: TTOD()
// Returns a Date value from a Datetime expression.
//
//////
// Version 0.57
// Last update:
//     Apr.07.2015
//////
// Change log:
//     Apr.07.2015 - Initial creation by Stefano D'Amico
//////
// Parameters:
//     p1			-- Datetime
//
//////
// Returns:
//    Datetime	-- DTOT( ) adds a default time of 12:00:00 AM (if SET HOURS is 12) or 00:00:00 (if SET HOURS is 24) to the date to produce a valid DateTime value.
//////
	SVariable* function_ttod(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varParam = returnsParams->params[0];

		u32			lnYear, lnMonth, lnDay;
		s8			buffer[16];

		SVariable*	result;


		//////////
		// Parameter 1 must be datetime
		//////
			if (!iVariable_isValid(varParam) || !iVariable_isTypeDatetime(varParam))
			{
				iError_reportByNumber(thisCode, _ERROR_INVALID_ARGUMENT_TYPE_COUNT, iVariable_getRelatedComp(thisCode, varParam), false);
				return(NULL);
			}


		//////////
		// Grab year, month, day from datetime
		//////
			iiVariable_computeYyyyMmDd_fromJulian(varParam->value.data_dt->julian, (u32*)&lnYear, (u32*)&lnMonth, &lnDay);


		//////////
		// Convert datetime into a VJr date variable
		//////
			// Date is stored as YYYYMMDD
			sprintf(buffer, "%04u%02u%02u\0", lnYear, lnMonth, lnDay);
			result = iVariable_createAndPopulate_byText(thisCode, _VAR_TYPE_DATE, buffer, 8, false);


		//////////
        // Return our converted result
		//////
	        return(result);

	}




//////////
//
// Function: TYPE()
// Returns the TYPE() for the indicated variable
//
//////
// Version 0.57
// Last update:
//     Apr.05.2015
//////
// Change log:
//     Apr.05.2015 - Initial creation
//////
// Parameters:
//     p1			-- The variable to examine
//     p2			-- (Optional) If present, must be 1, indicating extended TYPE() information
//
//////
// Returns:
//    Character		-- A one-digit code indicating the type
//////
	SVariable* function_type(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varLookup	= returnsParams->params[0];
		SVariable* varExtraInfo	= returnsParams->params[1];

		s32				lnExtraInfo;
		bool			llExtraInfo, llManufactured;
		SComp*			compVarLookup;
		SVariable*		var;
		SVariable*		result;
		bool			error;
		u32				errorNum;


		//////////
		// varLookup must be character
		//////
			if (!iVariable_isValid(varLookup) || !iVariable_isTypeCharacter(varLookup))
			{
				iError_reportByNumber(thisCode, _ERROR_P1_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varLookup), false);
				return(NULL);
			}
		

		//////////
		// If varExtraInfo is specified, must be numeric, and 1
		//////
			if (varExtraInfo)
			{

				//////////
				// Must be numeric
				//////
					if (!iVariable_isValid(varExtraInfo) || !iVariable_isTypeNumeric(varExtraInfo))
					{
						iError_reportByNumber(thisCode, _ERROR_P2_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varExtraInfo), false);
						return(NULL);
					}


				//////////
				// Grab the value
				//////
					lnExtraInfo = iiVariable_getAs_s32(thisCode, varExtraInfo, false, &error, &errorNum);
					if (error)
					{
						iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varExtraInfo), false);
						return(NULL);
					}


				//////////
				// Must be 1
				//////
					if (lnExtraInfo != 1)
					{
						iError_reportByNumber(thisCode, _ERROR_PARAMETER_MUST_BE_1, iVariable_getRelatedComp(thisCode, varExtraInfo), false);
						return(NULL);
					}


				//////////
				// If we get here, we're good
				//////
					llExtraInfo = true;


			} else {
				// No extra info
				llExtraInfo = false;
			}


		//////////
		// The varLookup points to something that needs to be looked up indirectly
		//////
			compVarLookup			= iVariable_getRelatedComp(thisCode, varLookup);
// TODO:  Need to modify this to examine dot-based variables
			compVarLookup->iCode	= _ICODE_ALPHANUMERIC;
			compVarLookup->start	+= 1;		// Skip leading quote for start
			compVarLookup->length	-= 2;		// Back off for both quotes for length
			var = iEngine_get_variableName_fromComponent(thisCode, compVarLookup, &llManufactured);
			if (!var)
			{
				iError_reportByNumber(thisCode, _ERROR_VARIABLE_NOT_FOUND, iVariable_getRelatedComp(thisCode, varLookup), false);
				return(NULL);
			}


		//////////
		// Compute our result
		//////
			result = ifunction_type_common(thisCode, var, llExtraInfo, false, false);


		//////////
		// Clean house
		//////
			if (llManufactured)
				iVariable_delete(thisCode, var, true);


		//////////
		// Return our result
		//////
			return(result);

	}

	// Handles type() and vartype()
	SVariable* ifunction_type_common(SThisCode* thisCode, SVariable* var, bool tlExtraInfo, bool tlIsVartype, bool tlNullIsType)
	{
		s8				c;
		SBaseClassMap*	baseClassMap;
		SVariable*		result;


		//////////
		// var holds the actual type we're testing
		//////
			if (tlExtraInfo)
			{
				// Returning extra information
				if (var->varType == _VAR_TYPE_OBJECT)
				{
					// It is a collection class?
					baseClassMap = iiObj_getBaseclass_byType(thisCode, var->obj->objType);
					if (baseClassMap && baseClassMap->objProps == &gsProps_collection[0])
					{
						// It is a collection
						c = 'C';

					} else {
						// Unknown
						c = 'U';
					}

				} else if (var->varType == _VAR_TYPE_ARRAY) {
					// It's an array
					c = 'A';

				} else {
					// Unknown
					c = 'U';
				}

			} else {
				// Standard
				switch (var->varType)
				{
					case _VAR_TYPE_CHARACTER:
						c = 'C';
						break;

					case _VAR_TYPE_LOGICAL:
						c = 'L';
						break;

					case _VAR_TYPE_DATE:
						c = 'D';
						break;

					case _VAR_TYPE_DATETIME:
					case _VAR_TYPE_DATETIMEX:
						c = 'T';
						break;

					case _VAR_TYPE_FIELD:
						// Based on the associated field type
						switch(var->field->fr2->type)
						{
							case 'D':	// Date
							case 'T':	// Datetime
							case 'L':	// Logical
							case 'N':	// Numeric
							case 'Y':	// currency, which is technically an 8-byte integer (s64)
							case 'C':	// Character
								c = var->field->fr2->type;

							case 'I':	// 4-byte integer (s32)
							case 'F':	// Float
							case 'B':	// Double (f64)
								c = 'N';
								break;

							case 'M':	// Memo
								c = 'C';
								break;

// Unsupported in VJr:
// 							case 'W':	// Blob
// 							case 'G':	// General
// 							case 'Q':	// Varbinary
// 							case 'V':	// Varchar
							default:
								c = 'U';
								break;
						}
						break;

					case _VAR_TYPE_OBJECT:
						c = 'O';
						break;

					default:
						if (var->varType == _VAR_TYPE_CURRENCY)
						{
							// Currency
							c = 'Y';

						} else if (var->varType >= _VAR_TYPE_NUMERIC_START && var->varType <= _VAR_TYPE_NUMERIC_END) {
							// Numeric
							c = 'N';

						} else {
							// Unknown
							c = 'U';
						}
						break;
				}
			}


		//////////
		// For vartype(), if nulls are to return x then we need to possibly adjust it
		//////
			if (tlIsVartype && !tlNullIsType && (var->varType == _VAR_TYPE_NULL || !var->value.data || var->value.length == 0))
				c = 'X';	// It is NULL


		//////////
		// Create our return result
		//////
			result = iVariable_createAndPopulate_byText(thisCode, _VAR_TYPE_CHARACTER, &c, 1, false);
			if (!result)
				iError_reportByNumber(thisCode, _ERROR_INTERNAL_ERROR, NULL, false);


		//////////
		// Indicate our result
		//////
			return(result);

	}




//////////
//
// Function: TYPEDETAIL()
// Returns the detailed TYPE() information.
//
//////
// Version 0.57
// Last update:
//     Apr.05.2015
//////
// Change log:
//     Apr.05.2015 - Initial creation
//////
// Parameters:
//     p1			-- The variable to examine
//
//////
// Returns:
//    Character		-- The expanded detail type string
//////
	SVariable* function_typedetail(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* var = returnsParams->params[0];


		// Return the typedetail
		return(iVariable_get_typeDetail(thisCode, var));
	}





//////////
//
// Function: UPPER()
// Converts every character in the string to uppercase.
//
//////
// Version 0.56
// Last update:
//     Jul.12.2014
//////
// Change log:
//     Jul.12.2014 - Initial creation
//////
// Parameters:
//     pString		-- Character, the string to upper
//
//////
// Returns:
//    Character		-- The string with all lowercase characters converted to uppercase
//////
	SVariable* function_upper(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable*	varString = returnsParams->params[0];
		s32			lnI;
        SVariable*	result;


		//////////
		// Parameter 1 must be character
		//////
			if (!iVariable_isValid(varString) || iVariable_getType(varString) != _VAR_TYPE_CHARACTER)
			{
				iError_reportByNumber(thisCode, _ERROR_P1_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varString), false);
				return(NULL);
			}


		//////////
        // Create our return result
		//////
			result = iVariable_create(thisCode, _VAR_TYPE_CHARACTER, NULL, true);
			if (!result)
			{
				iError_report(thisCode, cgcInternalError, false);
				return(NULL);
			}


		//////////
        // Copy the source string
		//////
	        iDatum_duplicate(&result->value, &varString->value);


		//////////
		// Lower every character
		//////
			for (lnI = 0; lnI < result->value.length; lnI++)
			{
				if (result->value.data[lnI] >= 'a' && result->value.data[lnI] <= 'z')
					result->value.data[lnI] -= 0x20;
			}


		//////////
        // Return our converted result
		//////
	        return(result);
	}




//////////
//
// Function: VAL()
// Returns a numeric or currency value from a expression.
//
//////
// Version 0.56
// Last update:
//     Mar.22.2015
//////
// Change log:
//     Mar.21.2015 - Initial creation by Stefano D'Amico
//////
// Parameters:
//     varExpr			-- Any, to convert
//	   varIgnoreList	-- Characters to ignore
//
//////
// Returns:
//    Numeric		--	VAL( ) returns the numbers in the character expression from left to right until a non-numeric character is encountered.
//						Leading blanks are ignored.
//						VAL( ) returns 0 if the first character of the character expression is not a number, a dollar sign ($), a plus sign (+), or minus sign (-).
//////
	SVariable* function_val(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable*	varExpr			= returnsParams->params[0];
		SVariable*	varIgnoreChars	= returnsParams->params[1];
		s8			c, cCurrency, cPoint, cSeparator;
		s32			lnI, lnJ, lnBuffOffset;
		s64			lnValue;
		f64			lfValue;
		bool		llAsInteger, llStillGoing, llCurrency;
		SVariable*	varCurrency;
		SVariable*	varPoint;
		SVariable*	varSeparator;
		SVariable*	result;
		u32			errorNum;
        bool		error;
		s8			buffer[64];


		//////////
		// Parameter 1 must be valid
		//////
			if (!iVariable_isValid(varExpr))
			{
				iError_reportByNumber(thisCode, _ERROR_P1_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varExpr), false);
				return(NULL);
			}

		//////////
		// If numeric, copy whatever's already there
		//////
			if (varExpr->varType >= _VAR_TYPE_NUMERIC_START && varExpr->varType <= _VAR_TYPE_NUMERIC_END)
			{
				// Copy The existing variable
				result = iVariable_copy(thisCode, varExpr, false);
				if (!result)
					iError_reportByNumber(thisCode, _ERROR_INTERNAL_ERROR, iVariable_getRelatedComp(thisCode, varExpr), false);

				// Success or failure, return our result
				return(result);
			}



		//////////
		// Determine what we're evaluating
		//////
			switch (varExpr->varType)
			{
				case _VAR_TYPE_NULL:
					iError_reportByNumber(thisCode, _ERROR_P1_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varExpr), false);
					return(NULL);
					break;

				case _VAR_TYPE_LOGICAL:		// 0=.F., 1=.T.
				case _VAR_TYPE_DATE:		// YYYYMMDD
					result = iVariable_create(thisCode, _VAR_TYPE_S32, NULL, true);
					if (result)
					{
						// Populate the s32
						*result->value.data_s32 = iiVariable_getAs_s32(thisCode, varExpr, true, &error, &errorNum);
						if (error)
							iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varExpr), false);
					}
					break;

				case _VAR_TYPE_DATETIME:
					// YYYYMMDDHHMMSSMss as s64
					result = iVariable_create(thisCode, _VAR_TYPE_S64, NULL, true);
					if (result)
					{
						// Populate the s64
						*result->value.data_s64 = iiVariable_getAs_s64(thisCode, varExpr, true, &error, &errorNum);
						if (error)
							iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varExpr), false);
					}
					break;

				case _VAR_TYPE_CHARACTER:

					//////////
					// If present, parameter 2 must be valid
					//////
						if (varIgnoreChars)
						{
							if (!iVariable_isValid(varIgnoreChars) || !iVariable_isTypeCharacter(varIgnoreChars))
							{
								iError_reportByNumber(thisCode, _ERROR_P2_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varIgnoreChars), false);
								return(NULL);
							}
						}


					//////////
					// Prepare our characters
					//////
						varCurrency		= propGet_settings_Currency(_settings);
						varPoint		= propGet_settings_Point(_settings);
						varSeparator	= propGet_settings_Separator(_settings);
						if (!varCurrency || !varPoint || !varSeparator)
						{
							// Should never happen
							iError_reportByNumber(thisCode, _ERROR_INTERNAL_ERROR, NULL, false);
							return(NULL);
						}


					//////////
					// Create single characters
					//////
						cCurrency	= varCurrency->value.data_s8[0];
						cPoint		= varPoint->value.data_s8[0];
						cSeparator	= varSeparator->value.data_s8[0];


					//////////
					// Iterate through each character
					//////
						for (lnI = 0, lnBuffOffset = 0, llStillGoing = true, llCurrency = false; llStillGoing && lnI < (s32)varExpr->value.length && lnBuffOffset < (s32)sizeof(buffer) - 1; lnI++)
						{

							//////////
							// Grab this character
							//////
								c = varExpr->value.data[lnI];


							//////////
							// Is it a character we're including in our buffer (a number, or natural number-related symbol)?
							//////
								if ((c >= '0' && c <= '9' ) || c == '+' || c == '-' || c == cPoint)
								{
									// Yes, Copy this character
									buffer[lnBuffOffset++] = c;

								} else {
									// Are we still in a valid sequence of characters to skip?
									if (c == ' ' || c == cSeparator)
									{
										// It's a character we're skipping naturally (space, separator symbol)
										// We don't do anything here ... it's just more clear to keep this logic visible rather than inverting it. :-)

									} else if (c == cCurrency) {
										// We encountered the currency symbol, so the output will be currency
										llCurrency = true;

									} else if (varIgnoreChars) {
										// We won't continue unless we're sitting on a character in the varIgnoreChars
										for (lnJ = 0, llStillGoing = false; lnJ < varIgnoreChars->value.length; lnJ++)
										{
											// Is this one of our skip characters?
											if (c == varIgnoreChars->value.data_s8[lnJ])
											{
												llStillGoing = true;
												break;
											}
										}

									} else {
										// We're done
										break;
									}
								}

						}

						// NULL terminate
						buffer[lnBuffOffset] = 0;


					//////////
					// Convert to f64, and s64
					//////
						lfValue = atof(buffer);
#ifdef __GNUC__
						lnValue = strtoll(buffer, NULL, 10);
#else
						lnValue = _strtoi64(buffer, NULL, 10);
#endif


					//////////
					// Is currency or not? If it's an integer value, store it as the same, otherwise use floating point
					//////
						if ((f64)lnValue == lfValue)
						{
							// We can return as an integer
							llAsInteger = true;
							if (llCurrency)
							{
								// Multiply by 10000 to obtain the 4 implied decimal places
								lnValue = lnValue * 10000;
								result	= iVariable_create(thisCode, _VAR_TYPE_CURRENCY, NULL, true);

							} else {
								if (lnValue < (s64)_s32_max)
								{
									// We can create as an s32
									result = iVariable_create(thisCode, _VAR_TYPE_S32, NULL, true);

								} else {
									// Create as an s64
									result = iVariable_create(thisCode, _VAR_TYPE_S64, NULL, true);
								}
							}

						} else {
							// Must return as f64
							llAsInteger	= false;
							if (llCurrency)
							{
								// As currency
								lfValue	*= 10000.0;
								result	= iVariable_create(thisCode, _VAR_TYPE_CURRENCY, NULL, true);

							} else {
								// As is
								result	= iVariable_create(thisCode, _VAR_TYPE_F64, NULL, true);
							}
						}


					//////////
					// Store the result
					//////
						if (result)
						{
							if (llAsInteger)	iVariable_setNumeric_toNumericType(thisCode, result, NULL, NULL, NULL, NULL, &lnValue, NULL);
							else				iVariable_setNumeric_toNumericType(thisCode, result, NULL, &lfValue, NULL, NULL, NULL, NULL);
						}
						break;

				default:
					// Unrecognized type
					iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, iVariable_getRelatedComp(thisCode, varExpr), false);
					return(NULL);
			}


		//////////
		// Are we good?
		//////
			if (!result)
				iError_reportByNumber(thisCode, _ERROR_INTERNAL_ERROR, iVariable_getRelatedComp(thisCode, varExpr), false);


		//////////
        // Return our converted result
		//////
	        return(result);
	}




//////////
//
// Function: VARTYPE()
// Returns the variable type, parsing NULL values.
//
//////
// Version 0.56
// Last update:
//     Apr.06.2015
//////
// Change log:
//     Apr.06.2015 - Initial creation
//////
// Parameters:
//     P1			-- The variable to examine
//     P2			-- (Optional) If provided, .t. or .f. indicating if NULL values should return the type (default to .f.)
//
//////
// Returns:
//    Character		-- A one-digit value indicating the type
//////
	SVariable* function_vartype(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* var		= returnsParams->params[0];
		SVariable* varNull	= returnsParams->params[1];

		bool	llNullIsType;
		bool	error;
		u32		errorNum;


		//////////
		// varLookup must exist
		//////
			if (!iVariable_isValid(var))
			{
				iError_reportByNumber(thisCode, _ERROR_P1_IS_INCORRECT, iVariable_getRelatedComp(thisCode, var), false);
				return(NULL);
			}
		

		//////////
		// If varNull is specified, must be logical
		//////
			if (varNull)
			{

				//////////
				// Must be logical
				//////
					if (!iVariable_isValid(varNull) || !iVariable_isTypeLogical(varNull))
					{
						iError_reportByNumber(thisCode, _ERROR_P2_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varNull), false);
						return(NULL);
					}


				//////////
				// Grab the value
				//////
					llNullIsType = iiVariable_getAs_bool(thisCode, varNull, false, &error, &errorNum);
					if (error)
					{
						iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varNull), false);
						return(NULL);
					}


			} else {
				// Do not report on NULL types
				llNullIsType = false;
			}


		//////////
		// Compute our result
		//////
			return(ifunction_type_common(thisCode, var, false, true, llNullIsType));

	}




//////////
//
// Function: VEC()
// Creates a vector.
//
//////
// Version 0.56
// Last update:
//     Mar.21.2015
//////
// Change log:
//     Mar.21.2015 - Initial creation
//////
// Parameters (example: vec(5,8,9) has three vectors, v1, v2, and v3 are the 5, 8, and 9 portions):
//     varV1		- Vector 1
//     varV2		- Vector 2
//     ...
//     varV10		- Vector 10
//
//////
// Returns:
//    Vector		-- The concatenated value, assumes the current SET VECSEPARATOR symbol
//////
	SVariable* function_vec(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varV1 = returnsParams->params[0];


		// Not yet completed
		iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, iVariable_getRelatedComp(thisCode, varV1), false);
		return(NULL);
	}




//////////
//
// Function: VECCOUNT()
// The vector element count.
//
//////
// Version 0.56
// Last update:
//     Mar.21.2015
//////
// Change log:
//     Mar.21.2015 - Initial creation
//////
// Parameters:
//     varVec		- Vector
//
//////
// Returns:
//     Numeric, the number of elements in the vector.
//////
	SVariable* function_veccount(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varVec = returnsParams->params[0];


		// Not yet completed
		iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, iVariable_getRelatedComp(thisCode, varVec), false);
		return(NULL);
	}




//////////
//
// Function: VECEL()
// Accesses or updates a vector element.
//
//////
// Version 0.56
// Last update:
//     Mar.21.2015
//////
// Change log:
//     Mar.21.2015 - Initial creation
//////
// Parameters:
//     varVec		- Vector
//     varEl		- Element number within (1-based)
//     varNewValue	- (Optional) Sets the new value. If the new value is a vector, it replaces other vectors which are there.
//
//////
// Returns:
//    if varNewValue was specified, returns the new vector
//    else                          returns the value of that element
//////
	SVariable* function_vecel(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varVec		= returnsParams->params[0];
		SVariable* varEl		= returnsParams->params[1];
		SVariable* varNewValue	= returnsParams->params[2];


		// Not yet completed
		iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, iVariable_getRelatedComp(thisCode, varVec), false);
		return(NULL);
	}




//////////
//
// Function: VECSLICE()
// Extracts elements from a vector.
//
//////
// Version 0.56
// Last update:
//     Mar.22.2015
//////
// Change log:
//     Mar.22.2015 - Initial creation
//////
// Parameters:
//     varVec			- Vector
//     varStartEl		- Element to start the operation at.
//     varEndEl			- The number of elements to remove
//
//////
// Returns:
//     The extracted element or elements as a vector.
//////
	SVariable* function_vecslice(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varVec		= returnsParams->params[0];
		SVariable* varStartEl	= returnsParams->params[1];
		SVariable* varEndEl		= returnsParams->params[2];


		// Not yet completed
		iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, NULL, false);
		return(NULL);
	}




//////////
//
// Function: VECSTR()
// Generates a character string containing the vectors.
//
//////
// Version 0.56
// Last update:
//     Mar.21.2015
//////
// Change log:
//     Mar.21.2015 - Initial creation
//////
// Parameters:
//     varVec				- Vector
//     varSymbolOverride	- A symbol to use between vectors
//
//////
// Returns:
//     A character string containing the vector values interspersed with symbol space, or the varSymbolOverride
//////
	SVariable* function_vecstr(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varVec				= returnsParams->params[0];
		SVariable* varSymbolOverride	= returnsParams->params[1];


		// Not yet completed
		iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, NULL, false);
		return(NULL);
	}




//////////
//
// Function: VECSTUFF()
// Updates or resizes a vector element. Works like STUFF().
//
//////
// Version 0.56
// Last update:
//     Mar.21.2015
//////
// Change log:
//     Mar.21.2015 - Initial creation
//////
// Parameters:
//     varVec			- Vector
//     varStartEl		- Element to start the operation at.
//     varRemoveCount	- The number of elements to remove
//     varVecStuff		- (Optional) The new vector to stuff in there after varStartEl
//
//////
// Returns:
//    if varNewValue was specified, returns the new vector
//    else                          returns the value of that element
//////
	SVariable* function_vecstuff(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varVec			= returnsParams->params[0];
		SVariable* varStartEl		= returnsParams->params[1];
		SVariable* varRemoveCount	= returnsParams->params[2];
		SVariable* varVecStuff		= returnsParams->params[3];


		// Not yet completed
		iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, iVariable_getRelatedComp(thisCode, varVec), false);
		return(NULL);
	}




//////////
//
// Function: VECSYMBOL()
// Access or updates the symbol used after a vector element.
//
//////
// Version 0.56
// Last update:
//     Mar.21.2015
//////
// Change log:
//     Mar.21.2015 - Initial creation
//////
// Parameters:
//     varVec		- Vector
//     varEl		- Element to access or update.
//     varNewSymbol	- (Optional) The new symbol to put there.
//
//////
// Returns:
//    if varNewSymbol was specified, returns the old symbol
//    else                           returns the current symbol
//////
	SVariable* function_vecsymbol(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varVec		= returnsParams->params[0];
		SVariable* varEl		= returnsParams->params[1];
		SVariable* varNewSymbol	= returnsParams->params[2];


		// Not yet completed
		iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, iVariable_getRelatedComp(thisCode, varVec), false);
		return(NULL);
	}




//////////
//
// Function: VERSION()
// Based on input, retrieves various version information.
//
//////
// Version 0.56
// Last update:
//     Jul.13.2014
//////
// Change log:
//     Jul.13.2014 - Initial creation
//////
// Parameters:
//     pIndex		-- (Optional) If present, Numeric, in the range 1..5
//
//////
// Returns:
//    Numeric or Character	-- Depending on index, various values are returned
//////
    SVariable* function_version(SThisCode* thisCode, SReturnsParams* returnsParams)
    {
		SVariable*	varIndex = returnsParams->params[0];
        s32			index;
		u32			errorNum;
        bool		error;
		u8*			lptr;
        SVariable*	result;


		//////////
		// Parameter 1 must be numeric
		//////
			lptr = NULL;
			if (!iVariable_isValid(varIndex))
			{
				// They are requesting the default information
				lptr = (u8*)cgcVersionText;

			} else if (!iVariable_isTypeNumeric(varIndex)) {
				// The parameter is not numeric
				iError_reportByNumber(thisCode, _ERROR_P1_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varIndex), false);
				return(NULL);

			} else {
				// It must be in the range 1..5
				index = iiVariable_getAs_s32(thisCode, varIndex, false, &error, &errorNum);
				if (error)
				{
					iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varIndex), false);
					return(NULL);

				} else if (index < 1 || index > 5) {
					// We report our own error
					iError_report(thisCode, (cu8*)"Parameter must be in the range 1..5", false);
					return(NULL);
				}
			}


		//////////
        // Create our return result
		//////
			if (lptr || index == 1 || index == 4)
			{
				// Character return
				result = iVariable_create(thisCode, _VAR_TYPE_CHARACTER, NULL, true);
				if (lptr)
				{
					// Copy the version info
					iDatum_duplicate(&result->value, lptr, -1);

				} else if (index == 1) {
					// Copy the version1 info
					iDatum_duplicate(&result->value, cgcVersion1Text, -1);

				} else {
					// Copy the version4 info
					iDatum_duplicate(&result->value, cgcVersion4Text, -1);
				}

			} else {
				result = iVariable_create(thisCode, _VAR_TYPE_S32, NULL, true);
				if (index == 2)
				{
					// 0=runtime, 1=standard, 2=professional
					*(s32*)result->value.data = gnVersion2;	// Oh yeah!

				} else if (index == 3) {
					// Localized version
					*(s32*)result->value.data = gnVersion3;	// English

				} else {
					// Version in a form like Major.Minor as M.mm, or 123 for version 1.23
					*(s32*)result->value.data = gnVersion5;
				}
			}
			if (!result)
			{
				iError_report(thisCode, cgcInternalError, false);
				return(NULL);
			}


		//////////
        // Return our converted result
		//////
	        return(result);
    }

//////////
//
// Function: YEAR()
// Returns the number of the month for a given Date or DateTime expression.
//
//////
// Version 0.57
// Last update:
//     Apr.04.2015
//////
// Change log:
//     Apr.04.2015 - Initial creation by Stefano D'Amico
//////
// Parameters:
//     p1			-- Date or DateTime
//
//////
// Returns:
//    YEAR() always returns the year with the century.
//////
// Example:
//	  dt = datetime()	&& Apr.06.2015
//    ? YEAR(dt)		&& Displays 2015
//    ? YEAR()			&& Displays current date's year number
//////
	SVariable* function_year(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable* varParam = returnsParams->params[0];

		// Return year
		return(ifunction_day_month_year_common(thisCode, varParam, _DMY_COMMON_YEAR));
	}




//////////
//
// Function: CONCATENATE()
// Note:  This is a temporary function until the main compiler engine is coded.
// Concatenates two strings together.
//
//////
// Version 0.56   (Determine the current version from the header in vjr.cpp)
// Last update:
//     Jul.13.2014
//////
// Change log:
//     Jul.13.2014 - Initial creation
//////
// Parameters:
//     p1		-- String1
//     p2		-- String2
//
//////
// Returns:
//    The sum of p1 + p2
//
//////
	SVariable* function_concatenate(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable*	varString1	= returnsParams->params[0];
		SVariable*	varString2	= returnsParams->params[1];
		SVariable*	result;


		//////////
		// Parameter 1 must be character
		//////
			if (!iVariable_isValid(varString1) || !iVariable_isTypeCharacter(varString1))
			{
				iError_reportByNumber(thisCode, _ERROR_P1_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varString1), false);
				return(NULL);
			}


		//////////
		// Parameter 2 must be character
		//////
			if (!iVariable_isValid(varString2) || !iVariable_isTypeCharacter(varString2))
			{
				iError_reportByNumber(thisCode, _ERROR_P2_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varString2), false);
				return(NULL);
			}


		//////////
		// Allocate enough space for the assemblage
		//////
			result = iVariable_create(thisCode, _VAR_TYPE_CHARACTER, NULL, true);
			if (!result)
			{
				iError_report(thisCode, cgcInternalError, false);
				return(NULL);
			}

			// Populate
			iDatum_allocateSpace(&result->value, varString1->value.length + varString2->value.length);

			// Create the concatenated string
			memcpy(result->value.data,								varString1->value.data,		varString1->value.length);
			memcpy(result->value.data + varString1->value.length,	varString2->value.data,		varString2->value.length);


		//////////
		// Indicate our result
		//////
			return(result);
	}




//////////
//
// Function: ADD()
// Note:  This is a temporary function until the main compiler engine is coded.
// Adds two values and returns the result.
//
//////
// Version 0.56   (Determine the current version from the header in vjr.cpp)
// Last update:
//     Jul.13.2014
//////
// Change log:
//     Jul.13.2014 - Initial creation
//////
// Parameters:
//     p1		-- Value1 to add
//     p2		-- Value2 to add
//
//////
// Returns:
//    The sum of p1 + p2
//
//////
	SVariable* function_add(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable*	varNum1	= returnsParams->params[0];
		SVariable*	varNum2	= returnsParams->params[1];
		s64			lnValue1, lnValue2;
		f64			lfValue1, lfValue2;
		bool		error;
		u32			errorNum;
		SVariable*	result;


		//////////
		// Parameter 1 must be numeric
		//////
			if (!iVariable_isValid(varNum1) || !iVariable_isTypeNumeric(varNum1))
			{
				iError_reportByNumber(thisCode, _ERROR_P1_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varNum1), false);
				return(NULL);
			}


		//////////
		// Parameter 2 must be numeric
		//////
			if (!iVariable_isValid(varNum2) || !iVariable_isTypeNumeric(varNum2))
			{
				iError_reportByNumber(thisCode, _ERROR_P2_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varNum2), false);
				return(NULL);
			}


		//////////
		// Determine what we're comparing
		//////
			if (iVariable_isTypeFloatingPoint(varNum1))
			{
				// p1 is floating point, meaning the result will be too
				lfValue1 = iiVariable_getAs_f64(thisCode, varNum1, false, &error, &errorNum);
				if (error)	{	iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varNum1), false);	return(NULL);	}

				// Create our floating point result
				result = iVariable_create(thisCode, _VAR_TYPE_F64, NULL, true);
				if (result)
				{
					// Grab p2
					if (iVariable_isTypeFloatingPoint(varNum2))
					{
						// p2 is floating point
						lfValue2 = iiVariable_getAs_f64(thisCode, varNum2, false, &error, &errorNum);
						if (error)	{	iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varNum2), false);	return(NULL);	}

						// Store the result
						*(f64*)result->value.data = lfValue1 + lfValue2;

					} else  {
						// p2 is not floating point, so we'll get it as an integer
						lnValue2 = iiVariable_getAs_s64(thisCode, varNum2, false, &error, &errorNum);
						if (error)	{	iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varNum2), false);	return(NULL);	}

						// Store the result
						*(f64*)result->value.data = lfValue1 + (f64)lnValue2;
					}
				}

			} else {
				// p1 is integer, result is determined by what p2 is, either integer or floating point
				lnValue1 = iiVariable_getAs_s64(thisCode, varNum1, false, &error, &errorNum);
				if (error)	{	iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varNum1), false);	return(NULL);	}

				// Grab p2
				if (iVariable_isTypeFloatingPoint(varNum2))
				{
					// p2 is floating point
					lfValue2 = iiVariable_getAs_f64(thisCode, varNum2, false, &error, &errorNum);
					if (error)	{	iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varNum2), false);	return(NULL);	}

					// Create our floating point result
					result = iVariable_create(thisCode, _VAR_TYPE_F64, NULL, true);
					if (result)
						*(f64*)result->value.data = (f64)lnValue1 + lfValue2;

				} else  {
					// p2 is not floating point, so we'll get it as an integer
					lnValue2 = iiVariable_getAs_s64(thisCode, varNum2, false, &error, &errorNum);
					if (error)	{	iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varNum2), false);	return(NULL);	}

					// Create our floating point result
					result = iVariable_create(thisCode, _VAR_TYPE_S64, NULL, true);
					if (result)
						*(s64*)result->value.data = lnValue1 + lnValue2;
				}
			}


		//////////
		// Are we good?
		//////
			if (!result)
				iError_report(thisCode, cgcInternalError, false);


		//////////
		// Indicate our result
		//////
			return(result);
	}




//////////
//
// Function: SUB()
// Note:  This is a temporary function until the main compiler engine is coded.
// Subtracts two values and returns the result.
//
//////
// Version 0.56   (Determine the current version from the header in vjr.cpp)
// Last update:
//     Jul.13.2014
//////
// Change log:
//     Jul.13.2014 - Initial creation
//////
// Parameters:
//     p1		-- Value1 to subtract value2 from
//     p2		-- Value2
//
//////
// Returns:
//    The sum of p1 - p2
//
//////
	SVariable* function_sub(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable*	varNum1	= returnsParams->params[0];
		SVariable*	varNum2	= returnsParams->params[1];
		s64			lnValue1, lnValue2;
		f64			lfValue1, lfValue2;
		bool		error;
		u32			errorNum;
		SVariable*	result;


		//////////
		// Parameter 1 must be numeric
		//////
			if (!iVariable_isValid(varNum1) || !iVariable_isTypeNumeric(varNum1))
			{
				iError_reportByNumber(thisCode, _ERROR_P1_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varNum1), false);
				return(NULL);
			}


		//////////
		// Parameter 2 must be numeric
		//////
			if (!iVariable_isValid(varNum2) || !iVariable_isTypeNumeric(varNum2))
			{
				iError_reportByNumber(thisCode, _ERROR_P2_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varNum2), false);
				return(NULL);
			}


		//////////
		// Determine what we're comparing
		//////
			if (iVariable_isTypeFloatingPoint(varNum1))
			{
				// p1 is floating point, meaning the result will be too
				lfValue1 = iiVariable_getAs_f64(thisCode, varNum1, false, &error, &errorNum);
				if (error)	{	iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varNum1), false);	return(NULL);	}

				// Create our floating point result
				result = iVariable_create(thisCode, _VAR_TYPE_F64, NULL, true);
				if (result)
				{
					// Grab p2
					if (iVariable_isTypeFloatingPoint(varNum2))
					{
						// p2 is floating point
						lfValue2 = iiVariable_getAs_f64(thisCode, varNum2, false, &error, &errorNum);
						if (error)	{	iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varNum2), false);	return(NULL);	}

						// Store the result
						*(f64*)result->value.data = lfValue1 - lfValue2;

					} else  {
						// p2 is not floating point, so we'll get it as an integer
						lnValue2 = iiVariable_getAs_s64(thisCode, varNum2, false, &error, &errorNum);
						if (error)	{	iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varNum2), false);	return(NULL);	}

						// Store the result
						*(f64*)result->value.data = lfValue1 - (f64)lnValue2;
					}
				}

			} else {
				// p1 is integer, result is determined by what p2 is, either integer or floating point
				lnValue1 = iiVariable_getAs_s64(thisCode, varNum1, false, &error, &errorNum);
				if (error)	{	iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varNum1), false);	return(NULL);	}

				// Grab p2
				if (iVariable_isTypeFloatingPoint(varNum2))
				{
					// p2 is floating point
					lfValue2 = iiVariable_getAs_f64(thisCode, varNum2, false, &error, &errorNum);
					if (error)	{	iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varNum2), false);	return(NULL);	}

					// Create our floating point result
					result = iVariable_create(thisCode, _VAR_TYPE_F64, NULL, true);
					if (result)
						*(f64*)result->value.data = (f64)lnValue1 - lfValue2;

				} else  {
					// p2 is not floating point, so we'll get it as an integer
					lnValue2 = iiVariable_getAs_s64(thisCode, varNum2, false, &error, &errorNum);
					if (error)	{	iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varNum2), false);	return(NULL);	}

					// Create our floating point result
					result = iVariable_create(thisCode, _VAR_TYPE_S64, NULL, true);
					if (result)
						*(s64*)result->value.data = lnValue1 - lnValue2;
				}
			}


		//////////
		// Are we good?
		//////
			if (!result)
				iError_report(thisCode, cgcInternalError, false);


		//////////
		// Indicate our result
		//////
			return(result);
	}




//////////
//
// Function: MUL()
// Note:  This is a temporary function until the main compiler engine is coded.
// Multiplies two values and returns the result.
//
//////
// Version 0.56   (Determine the current version from the header in vjr.cpp)
// Last update:
//     Jul.13.2014
//////
// Change log:
//     Jul.13.2014 - Initial creation
//////
// Parameters:
//     p1		-- Value1 to multiply
//     p2		-- Value2 to multiply
//
//////
// Returns:
//    The sum of p1 * p2
//
//////
	SVariable* function_mul(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable*	varNum1	= returnsParams->params[0];
		SVariable*	varNum2	= returnsParams->params[1];
		s64			lnValue1, lnValue2;
		f64			lfValue1, lfValue2;
		bool		error;
		u32			errorNum;
		SVariable*	result;


		//////////
		// Parameter 1 must be numeric
		//////
			if (!iVariable_isValid(varNum1) || !iVariable_isTypeNumeric(varNum1))
			{
				iError_reportByNumber(thisCode, _ERROR_P1_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varNum1), false);
				return(NULL);
			}


		//////////
		// Parameter 2 must be numeric
		//////
			if (!iVariable_isValid(varNum2) || !iVariable_isTypeNumeric(varNum2))
			{
				iError_reportByNumber(thisCode, _ERROR_P2_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varNum2), false);
				return(NULL);
			}


		//////////
		// Determine what we're comparing
		//////
			if (iVariable_isTypeFloatingPoint(varNum1))
			{
				// p1 is floating point, meaning the result will be too
				lfValue1 = iiVariable_getAs_f64(thisCode, varNum1, false, &error, &errorNum);
				if (error)	{	iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varNum1), false);	return(NULL);	}

				// Create our floating point result
				result = iVariable_create(thisCode, _VAR_TYPE_F64, NULL, true);
				if (result)
				{
					// Grab p2
					if (iVariable_isTypeFloatingPoint(varNum2))
					{
						// p2 is floating point
						lfValue2 = iiVariable_getAs_f64(thisCode, varNum2, false, &error, &errorNum);
						if (error)	{	iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varNum2), false);	return(NULL);	}

						// Store the result
						*(f64*)result->value.data = lfValue1 * lfValue2;

					} else  {
						// p2 is not floating point, so we'll get it as an integer
						lnValue2 = iiVariable_getAs_s64(thisCode, varNum2, false, &error, &errorNum);
						if (error)	{	iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varNum2), false);	return(NULL);	}

						// Store the result
						*(f64*)result->value.data = lfValue1 * (f64)lnValue2;
					}
				}

			} else {
				// p1 is integer, result is determined by what p2 is, either integer or floating point
				lnValue1 = iiVariable_getAs_s64(thisCode, varNum1, false, &error, &errorNum);
				if (error)	{	iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varNum1), false);	return(NULL);	}

				// Grab p2
				if (iVariable_isTypeFloatingPoint(varNum2))
				{
					// p2 is floating point
					lfValue2 = iiVariable_getAs_f64(thisCode, varNum2, false, &error, &errorNum);
					if (error)	{	iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varNum2), false);	return(NULL);	}

					// Create our floating point result
					result = iVariable_create(thisCode, _VAR_TYPE_F64, NULL, true);
					if (result)
						*(f64*)result->value.data = (f64)lnValue1 * lfValue2;

				} else  {
					// p2 is not floating point, so we'll get it as an integer
					lnValue2 = iiVariable_getAs_s64(thisCode, varNum2, false, &error, &errorNum);
					if (error)	{	iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varNum2), false);	return(NULL);	}

					// Create our floating point result
					result = iVariable_create(thisCode, _VAR_TYPE_S64, NULL, true);
					if (result)
						*(s64*)result->value.data = lnValue1 * lnValue2;
				}
			}


		//////////
		// Are we good?
		//////
			if (!result)
				iError_report(thisCode, cgcInternalError, false);


		//////////
		// Indicate our result
		//////
			return(result);
	}




//////////
//
// Function: DIV()
// Note:  This is a temporary function until the main compiler engine is coded.
// Divides two values and returns the result.
//
//////
// Version 0.56   (Determine the current version from the header in vjr.cpp)
// Last update:
//     Jul.13.2014
//////
// Change log:
//     Jul.13.2014 - Initial creation
//////
// Parameters:
//     p1		-- Value1 to divide by value2
//     p2		-- Value2
//
//////
// Returns:
//    The sum of p1 / p2
//
//////
	SVariable* function_div(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		SVariable*	varNum1	= returnsParams->params[0];
		SVariable*	varNum2	= returnsParams->params[1];
		s64			lnValue1, lnValue2;
		f64			lfValue1, lfValue2;
		bool		error;
		u32			errorNum;
		SVariable*	result;


		//////////
		// Parameter 1 must be numeric
		//////
			if (!iVariable_isValid(varNum1) || !iVariable_isTypeNumeric(varNum1))
			{
				iError_reportByNumber(thisCode, _ERROR_P1_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varNum1), false);
				return(NULL);
			}


		//////////
		// Parameter 2 must be numeric
		//////
			if (!iVariable_isValid(varNum2) || !iVariable_isTypeNumeric(varNum2))
			{
				iError_reportByNumber(thisCode, _ERROR_P2_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varNum2), false);
				return(NULL);
			}


		//////////
		// Parameter 2 cannot be 0
		//////
			lfValue1 = iiVariable_getAs_f64(thisCode, varNum2, false, &error, &errorNum);
			if (lfValue1 == 0.0 || error)
			{
				iError_reportByNumber(thisCode, _ERROR_P2_IS_INCORRECT, iVariable_getRelatedComp(thisCode, varNum2), false);
				return(NULL);
			}


		//////////
		// Determine what we're comparing
		//////
			if (iVariable_isTypeFloatingPoint(varNum1))
			{
				// p1 is floating point, meaning the result will be too
				lfValue1 = iiVariable_getAs_f64(thisCode, varNum1, false, &error, &errorNum);
				if (error)	{	iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varNum1), false);	return(NULL);	}

				// Create our floating point result
				result = iVariable_create(thisCode, _VAR_TYPE_F64, NULL, true);
				if (result)
				{
					// Grab p2
					if (iVariable_isTypeFloatingPoint(varNum2))
					{
						// p2 is floating point
						lfValue2 = iiVariable_getAs_f64(thisCode, varNum2, false, &error, &errorNum);
						if (error)	{	iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varNum2), false);	return(NULL);	}

						// Store the result
						*(f64*)result->value.data = lfValue1 / lfValue2;

					} else  {
						// p2 is not floating point, so we'll get it as an integer
						lnValue2 = iiVariable_getAs_s64(thisCode, varNum2, false, &error, &errorNum);
						if (error)	{	iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varNum2), false);	return(NULL);	}

						// Store the result
						*(f64*)result->value.data = lfValue1 / (f64)lnValue2;
					}
				}

			} else {
				// p1 is integer, result is determined by what p2 is, either integer or floating point
				lnValue1 = iiVariable_getAs_s64(thisCode, varNum1, false, &error, &errorNum);
				if (error)	{	iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varNum1), false);	return(NULL);	}

				// Create our floating point result
				result = iVariable_create(thisCode, _VAR_TYPE_F64, NULL, true);
				if (result)
				{
					// Grab p2
					if (iVariable_isTypeFloatingPoint(varNum2))
					{
						// p2 is floating point
						lfValue2 = iiVariable_getAs_f64(thisCode, varNum2, false, &error, &errorNum);
						if (error)	{	iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varNum2), false);	return(NULL);	}

						// Store the result
						*(f64*)result->value.data = (f64)lnValue1 / lfValue2;

					} else  {
						// p2 is not floating point, so we'll get it as an integer
						lnValue2 = iiVariable_getAs_s64(thisCode, varNum2, false, &error, &errorNum);
						if (error)	{	iError_reportByNumber(thisCode, errorNum, iVariable_getRelatedComp(thisCode, varNum2), false);	return(NULL);	}

						// Store the result
						*(f64*)result->value.data = (f64)lnValue1 / (f64)lnValue2;
					}
				}
			}


		//////////
		// Are we good?
		//////
			if (!result)
				iError_report(thisCode, cgcInternalError, false);


		//////////
		// Indicate our result
		//////
			return(result);
	}




//////////
//
// Command:  CLEAR
// Clears various things.
//
//////
// Version 0.56
// Last update:
//     Mar.15.2015
//////
// Change log:
//     Mar.15.2015
//////
// Parameters:
//		compClear -- The [CLEAR] component
//////
// Returns:
//		Nothing, but whatever it is that's being modified may be open for modifying.
//////
	void command_clear(SThisCode* thisCode, SComp* compCommand, SReturnsParams* returnsParams)
	{
		SComp*			compClear = compCommand;
		s32				lnClearLines, lnSaveLines;
		bool			llManufactured;
		SEM_callback	ecb;
		SVariable*		var;
		bool			error;
		u32				errorNum;


// 		SComp*	compAll				= iComps_findNextBy_iCode(thisCode, compModify, _ICODE_ALL,			NULL);
// 		SComp*	compClass			= iComps_findNextBy_iCode(thisCode, compModify, _ICODE_CLASS,		NULL);
// 		SComp*	compClassName		= iComps_getNth(thisCode, compClass, 1);
// 		SComp*	compClassLib		= iComps_findNextBy_iCode(thisCode, compModify, _ICODE_CLASSLIB,	NULL);
// 		SComp*	compClassLibName	= iComps_getNth(thisCode, compClassLib, 1);
		SComp*	compKeep			= iComps_findNextBy_iCode(thisCode, compClear, _ICODE_KEEP,			NULL);
		SComp*	compKeepCount		= iComps_getNth(thisCode, compKeep, 1);
		SComp*	compLast			= iComps_findNextBy_iCode(thisCode, compClear, _ICODE_LAST,			NULL);
		SComp*	compLastCount		= iComps_getNth(thisCode, compLast, 1);
// 		SComp*	compDebug			= iComps_findNextBy_iCode(thisCode, compModify, _ICODE_DEBUG,		NULL);
// 		SComp*	compDlls			= iComps_findNextBy_iCode(thisCode, compModify, _ICODE_DLLS,		NULL);
// 		SComp*	compDllAlias		= iComps_getNth(thisCode, compDlls, 1);
// 		SComp*	compEvents			= iComps_findNextBy_iCode(thisCode, compModify, _ICODE_EVENTS,		NULL);
// 		SComp*	compError			= iComps_findNextBy_iCode(thisCode, compModify, _ICODE_ERROR,		NULL);
// 		SComp*	compFields			= iComps_findNextBy_iCode(thisCode, compModify, _ICODE_FIELDS,		NULL);
// 		SComp*	compGets			= iComps_findNextBy_iCode(thisCode, compModify, _ICODE_GETS,		NULL);
// 		SComp*	compMacros			= iComps_findNextBy_iCode(thisCode, compModify, _ICODE_MACROS,		NULL);
// 		SComp*	compMemory			= iComps_findNextBy_iCode(thisCode, compModify, _ICODE_MEMORY,		NULL);
// 		SComp*	compMenus			= iComps_findNextBy_iCode(thisCode, compModify, _ICODE_MENUS,		NULL);
// 		SComp*	compPopups			= iComps_findNextBy_iCode(thisCode, compModify, _ICODE_POPUPS,		NULL);
// 		SComp*	compProgram			= iComps_findNextBy_iCode(thisCode, compModify, _ICODE_PROGRAM,		NULL);
// 		SComp*	compPrompt			= iComps_findNextBy_iCode(thisCode, compModify, _ICODE_PROMPT,		NULL);
// 		SComp*	compRead			= iComps_findNextBy_iCode(thisCode, compModify, _ICODE_READ,		NULL);
// 		SComp*	compResources		= iComps_findNextBy_iCode(thisCode, compModify, _ICODE_RESOURCES,	NULL);
// 		SComp*	compTypeahead		= iComps_findNextBy_iCode(thisCode, compModify, _ICODE_TYPEAHEAD,	NULL);
// 		SComp*	compWindows			= iComps_findNextBy_iCode(thisCode, compModify, _ICODE_WINDOWS,		NULL);
// 		SComp*	compFilename		= iComps_getNth(compWindows, 1);

		if (compLast)
		{
			// CLEAR LAST -- Clears the last few lines at the end of a buffer
			if (compLastCount)
			{
				//////////
				// CLEAR LAST nCount
				//////
					var = iEngine_get_variableName_fromComponent(thisCode, compLastCount, &llManufactured);
					if (!var)
					{
						// Unknown parameter
						iError_reportByNumber(thisCode, _ERROR_UNRECOGNIZED_PARAMETER, compLastCount, false);
						return;
					}


				//////////
				// Find out how many lines
				//////
					lnClearLines = iiVariable_getAs_s32(thisCode, var, false, &error, &errorNum);
					if (error)
					{
						iError_reportByNumber(thisCode, errorNum, compLastCount, false);
						return;
					}


				//////////
				// Clean house
				//////
					if (llManufactured)
						iVariable_delete(thisCode, var, true);


				//////////
				// Validate the number is in range
				//////
					if (lnClearLines < 0)
					{
						iError_reportByNumber(thisCode, _ERROR_CANNOT_BE_NEGATIVE, compLastCount, false);
						return;
					}

			} else {
				// Clear them all
				lnClearLines = 0;
			}


			//////////
			// Prepare for the clear
			//////
				memset(&ecb, 0, sizeof(ecb));
				ecb._callback = (uptr)&iiCommand_clear_last_callback;
				ecb.extra1 = (uptr)lnClearLines;
				ecb.extra2 = (uptr)iSEM_renumber(thisCode, screenData, 1);


			//////////
			// Clear
			//////
				iSEM_deleteChainWithCallback(thisCode, &screenData, false, &ecb);


			//////////
			// Count what remains, and set _tally
			//////
				iEngine_update_tally(thisCode, iSEM_renumber(thisCode, screenData, 1));


			//////////
			// Redraw what remains
			//////
				iSEM_navigateToEndLine(thisCode, screenData, _screen);
				screen_editbox->isDirtyRender = true;
				iWindow_render(NULL, gWinJDebi, false);

			//////////
			// All done
			//////
				return;


		} else if (compKeep) {
			// CLEAR KEEP -- Keeps a certain number of lines at the end of the buffer, and clears the rest
			if (compKeepCount)
			{
				//////////
				// CLEAR KEEP nCount
				//////
					var = iEngine_get_variableName_fromComponent(thisCode, compKeepCount, &llManufactured);
					if (!var)
					{
						// Unknown parameter
						iError_reportByNumber(thisCode, _ERROR_UNRECOGNIZED_PARAMETER, compKeepCount, false);
						return;
					}


				//////////
				// Find out how many lines
				//////
					lnSaveLines = iiVariable_getAs_s32(thisCode, var, false, &error, &errorNum);
					if (error)
					{
						iError_reportByNumber(thisCode, errorNum, compKeepCount, false);
						return;
					}


				//////////
				// Clean house
				//////
					if (llManufactured)
						iVariable_delete(thisCode, var, true);


				//////////
				// Validate the number is in range
				//////
					if (lnSaveLines < 0)
					{
						iError_reportByNumber(thisCode, _ERROR_CANNOT_BE_NEGATIVE, compKeepCount, false);
						return;
					}

			} else {
				// Clear them all
				lnSaveLines = 0;
			}

		} else {
			// Clear them all
			lnSaveLines = 0;
		}


		//////////
		// Prepare for the clear
		//////
			memset(&ecb, 0, sizeof(ecb));
			ecb._callback = (uptr)&iiCommand_clear_keep_callback;
			ecb.extra1 = (uptr)lnSaveLines;
			ecb.extra2 = (uptr)iSEM_renumber(thisCode, screenData, 1);


		//////////
		// Clear
		//////
			iSEM_deleteChainWithCallback(thisCode, &screenData, false, &ecb);


		//////////
		// Count what remains, and set _tally
		//////
			iEngine_update_tally(thisCode, iSEM_renumber(thisCode, screenData, 1));


		//////////
		// Redraw what remains
		//////
			iSEM_navigateToEndLine(thisCode, screenData, _screen);
			screen_editbox->isDirtyRender = true;
			iWindow_render(NULL, gWinJDebi, false);
			// All done
	}

	// Tests the line number, only deletes the tail
	bool iiCommand_clear_last_callback(SEM_callback* ecb)
	{
		// If lineNum >= (endNum - clearCount) ... delete it
		return(ecb->line->lineNumber > ecb->sem->lastLine->lineNumber - ecb->extra1);
	}

	// Tests the line number, only saves the tail
	bool iiCommand_clear_keep_callback(SEM_callback* ecb)
	{
		// If (endNum - saveCount) > lineNum ... delete it
		return(ecb->sem->lastLine->lineNumber - ecb->extra1 >= ecb->line->lineNumber);
	}




//////////
//
// Command:  MODIFY
// Modifies various things.
//
//////
// Version 0.56
// Last update:
//     Jan.09.2015
//////
// Change log:
//     Jan.09.2015
//////
// Parameters:
//		compModify	-- The [MODIFY] component
//////
// Returns:
//		Nothing, but whatever it is that's being modified may be open for modifying.
//////
	void command_modify(SThisCode* thisCode, SComp* compCommand, SReturnsParams* returnsParams)
	{
		SComp*	compModify = compCommand;
		SComp*	compType;
//		SComp*	compTarget;


		//////////
		// Make sure there's something after the modify command
		//////
			if (!(compType = iComps_getNth(thisCode, compModify, 1)))
			{
				// There was nothing after, which means syntax error
				iError_reportByNumber(thisCode, _ERROR_MISSING_PARAMETER, compModify, false);
				return;
			}


		//////////
		// Based on what's after, validate the syntaxes
		//////
// TODO:  Working on here ... the thing after MODIFY should be a fully qualified thing as per the compiler engine
//			compTarget = iComps_getNth(compType, 1);
			switch (compType->iCode)
			{
				case _ICODE_CLASS:
					// MODIFY CLASS
					break;

				case _ICODE_COMMAND:
					// MODIFY COMMAND
					break;

				case _ICODE_CONNECTION:
					// MODIFY CONNECTION
					break;

				case _ICODE_DATABASE:
					// MODIFY DATABASE
					break;

				case _ICODE_FILE:
					// MODIFY FILE
					break;

				case _ICODE_FORM:
					// MODIFY FORM
					break;

				case _ICODE_GENERAL:
					// MODIFY GENERAL
					break;

				case _ICODE_LABEL:
					// MODIFY LABEL
					break;

				case _ICODE_MEMO:
					// MODIFY MEMO
					break;

				case _ICODE_MENU:
					// MODIFY MENU
					break;

				case _ICODE_PROCEDURE:
					// MODIFY PROCEDURE
					break;

				case _ICODE_PROJECT:
					// MODIFY PROJECT
					break;

				case _ICODE_QUERY:
					// MODIFY QUERY
					break;

				case _ICODE_REPORT:
					// MODIFY REPORT
					break;

				case _ICODE_STRUCTURE:
					// MODIFY STRUCTURE
					break;

				case _ICODE_VIEW:
					// MODIFY VIEW
					break;

				case _ICODE_WINDOW:
					// MODIFY WINDOW
					break;
			}


		//////////
		// If we get here, syntax error
		//////
			iError_reportByNumber(thisCode, _ERROR_SYNTAX, compType, false);
	}




//////////
//
// Command:  OPEN
// Multiple forms.  Opens a database container.
//
//////
// Version 0.56
// Last update:
//     Jan.06.2015
//////
// Change log:
//     Jan.06.2015 - Initial creation
//////
// Parameters:
//		compOpen		-- The [OPEN] component
//////
// Returns:
//		Nothing, but the environment may be changed.
//////
	void command_open(SThisCode* thisCode, SComp* compCommand, SReturnsParams* returnsParams)
	{
		SComp*	compOpen = compCommand;
		s32		lnLength;
		sptr	lnDbcArea;
		bool	llIsExclusive;
		SComp*	compPathname;
		SComp*	compDatabase;
		SComp*	compExclusive;
		SComp*	compShared;
		SComp*	compValidate;
		SComp*	compRecover;
		s8		dbcNameBuffer[_MAX_PATH];


		//////////
		// Access the options which are available for this command
		//////
			compDatabase	= iComps_findNextBy_iCode(thisCode, compOpen, _ICODE_DATABASE,	NULL);
			compExclusive	= iComps_findNextBy_iCode(thisCode, compOpen, _ICODE_EXCLUSIVE,	NULL);
			compShared		= iComps_findNextBy_iCode(thisCode, compOpen, _ICODE_SHARED,		NULL);
			compValidate	= iComps_findNextBy_iCode(thisCode, compOpen, _ICODE_VALIDATE,	NULL);
			compRecover		= iComps_findNextBy_iCode(thisCode, compOpen, _ICODE_RECOVER,		NULL);


		//////////
		// Make sure the syntax was OPEN DATABASE
		//////
			if (!compDatabase)
			{
				// Syntax error
				iError_reportByNumber(thisCode, _ERROR_SYNTAX, compOpen, false);
				return;
			}
			if (!compDatabase->ll.next)
			{
				// Syntax error
				iError_reportByNumber(thisCode, _ERROR_SYNTAX, compDatabase, false);
				return;
			}
			// Grab the component after [database]
			compPathname = iComps_getNth(thisCode, compDatabase, 1);


		//////////
		// Extract the DBC name
		//////
			lnLength = iComps_getContiguousLength(thisCode, compPathname, NULL, 0, NULL);
			if (lnLength >= (s32)sizeof(dbcNameBuffer))
			{
				// Parameter is too long
				iError_reportByNumber(thisCode, _ERROR_PARAMETER_TOO_LONG, compPathname, false);
				return;
			}
			memset(dbcNameBuffer, 0, sizeof(dbcNameBuffer));
			memcpy(dbcNameBuffer, compPathname->line->sourceCode->data + compPathname->start, lnLength);


		//////////
		// Cannot have both SHARED and EXCLUSIVE
		//////
			if (compShared && compExclusive)
			{
				iError_reportByNumber(thisCode, _ERROR_CONFLICTING_PARAMETERS, ((compShared->ll.uniqueId < compExclusive->ll.uniqueId) ? compExclusive : compShared), false);
				return;
			}

			// Determine shared or exclusive status
			if (compShared)
			{
				// Explicitly shared
				llIsExclusive	= false;

			} else if (compExclusive) {
				// Explicitly exclusive
				llIsExclusive	= true;

			} else {
				// Use the current SET default
				llIsExclusive	= propGet_settings_Exclusive(_settings);
			}


		//////////
		// Try to open it
		//////
			lnDbcArea = iDbf_open(thisCode, (cs8*)dbcNameBuffer, (cs8*)cgcDbcKeyName, llIsExclusive, false, false, false, false, false);
			if (lnDbcArea < 0)
			{
				// Unable to open
				iError_reportByNumber(thisCode, _ERROR_UNABLE_TO_OPEN_DBC, compPathname, false);
				return;
			}


		//////////
		// If we need to validate, do so
		//////
			// Pass it our output screen
			if (compValidate)
				iDbc_validate(thisCode, &gsDbcArea[lnDbcArea], (compRecover != NULL), ((propGet_settings_Talk(_settings)) ? screen_editbox->p.sem : NULL), gWinJDebi);
	}




//////////
//
// Command: SET
// Sets various components within the current _settings object.
//
//////
// Version 0.56   (Determine the current version from the header in vjr.cpp)
// Last update:
//     Mar.15.2015
//////
// Change log:
//     Mar.15.2015 - Initial creation
//////
// Parameters:
//     comp		-- The [SET] component
//////
// Returns:
//    Nothing, but the environment may be changed.
//////
	void command_set(SThisCode* thisCode, SComp* compCommand, SReturnsParams* returnsParams)
	{
		SComp*			compSet = compCommand;
		s32				lnIndex;
		bool			llManufactured;
		SComp*			compSetTarget;
		SComp*			compSetValue;
		SObjPropMap*	objProp;
		SBasePropMap*	baseProp;
		SVariable*		varSet;
		SVariable*		varSetNewValue;

// iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, compSet, false);
// return;

		//////////
		// Get the next component
		//////
			compSetTarget = iComps_getNth(thisCode, compSet, 1);
			if (compSetTarget)
			{
				// SET SOMETHING


				//////////
				// The thing after should be the value, or the keyword TO
				//////
					compSetValue = iComps_getNth(thisCode, compSetTarget, 1);

					// TO is superfluous, so if it exists, skip it
					if (compSetValue && compSetValue->iCode == _ICODE_TO)
						compSetValue = iComps_getNth(thisCode, compSetValue, 1);


				//////////
				// Is there anything there?
				//////
					if (!compSetValue)
					{
						// Syntax error
						iError_reportByNumber(thisCode, _ERROR_SYNTAX, compSetTarget, false);
						return;
					}


				//////////
				// Translate the xyz part of the SET xyz TO abcc into the actual _INDEX_SET_* value
				/////
					lnIndex = iObjProp_settingsTranslate(thisCode, compSetTarget->iCode);
					if (lnIndex <= 0)
					{
						iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, compSetTarget, false);
						return;
					}


				//////////
				// Find out what the xyz is for SET xyz TO ...
				//////
					varSet = iObjProp_get_variable_byIndex(thisCode, _settings, lnIndex, &baseProp, &objProp);
					if (varSet && objProp && baseProp)
					{
						// We found the setting and the default variable type
						varSetNewValue = iEngine_get_variableName_fromComponent(thisCode, compSetValue, &llManufactured);
//////////
// Note:
//		Settings are handled a little differently compared to other objects.
//		They are only ever referenced as a settings object, so their values are
//		only ever set through the setter settings, which use the setterObject_set()
//		function instead of the standard setterObject() function.
//////////

						// Try to set the value using our special set values
						if (objProp->_setterObject_set)
						{
							// We have our own value, use it
							if (objProp->setterObject_set(thisCode, varSet, compSetValue, varSetNewValue, llManufactured))
								return;		// If we get here, we're good

							// If we get here, it couldn't be set
							iError_reportByNumber(thisCode, _ERROR_SYNTAX, compSetValue, false);
							return;
						}

						// If we get here, try the standard method
						if (!iObjProp_set(thisCode, _settings, compSetTarget->iCode, varSetNewValue))
						{
							iError_reportByNumber(thisCode, _ERROR_PARAMETER_IS_INCORRECT, compSetTarget, false);
							return;
						}
					}
					// If we get here, invalid setting
					// Fall through
			}


		//////////
		// If we get here, syntax error
		//////
			iError_reportByNumber(thisCode, _ERROR_SYNTAX, compSet, false);
	}




//////////
//
// Command: USE
// Multiple forms.  Opens or close a table or view in the current or another area.
//
//////
// Version 0.56   (Determine the current version from the header in vjr.cpp)
// Last update:
//     Nov.02.2014
//////
// Change log:
//     Nov.02.2014 - Initial creation
//////
// Parameters:
//     comp		-- The [USE] component
//////
// Returns:
//    Nothing, but the environment may be changed.
//////
	void command_use(SThisCode* thisCode, SComp* compCommand, SReturnsParams* returnsParams)
	{
		SComp*		compUse = compCommand;
		sptr		lnWorkArea, lnWorkAreaAlias;
		bool		llIsInUse, llIsValidWorkArea, llManufacturedTableName, llManufacturedAliasName, llIsExclusive;
		SComp*		comp2;
		SComp*		comp3;
		SComp*		comp4;
		SVariable*	varInWorkArea;
		SVariable*	varTableName;
		SVariable*	varAliasName;
		u32			errorNum;
		bool		error;


		//////////
		// Initialize
		//////
			varInWorkArea					= NULL;
			varTableName				= 0;
			varAliasName				= 0;
			llManufacturedTableName		= false;
			llManufacturedAliasName		= false;
			llIsExclusive				= false;


		//////////
		// Access the options which are available for this command
		//////
			SComp*	compAgain				= iComps_findNextBy_iCode(thisCode, compUse, _ICODE_AGAIN,				NULL);
//			SComp*	compNoRequery			= iComps_findNextBy_iCode(thisCode, compUse, _ICODE_NOREQUERY,			NULL);
//			SComp*	compNoData				= iComps_findNextBy_iCode(thisCode, compUse, _ICODE_NODATA,				NULL);
//			SComp*	compNoUpdate			= iComps_findNextBy_iCode(thisCode, compUse, _ICODE_NOUPDATE,			NULL);
//			SComp*	compExclamationPoint	= iComps_findNextBy_iCode(thisCode, compUse, _ICODE_EXCLAMATION_POINT,	NULL);
			SComp*	compIn					= iComps_findNextBy_iCode(thisCode, compUse, _ICODE_IN,					NULL);
//			SComp*	compIndex				= iComps_findNextBy_iCode(thisCode, compUse, _ICODE_INDEX,				NULL);
//			SComp*	compOrder				= iComps_findNextBy_iCode(thisCode, compUse, _ICODE_ORDER,				NULL);
//			SComp*	compTag					= iComps_findNextBy_iCode(thisCode, compUse, _ICODE_TAG,				NULL);
			SComp*	compAscending			= iComps_findNextBy_iCode(thisCode, compUse, _ICODE_ASCENDING,			NULL);
			SComp*	compDescending			= iComps_findNextBy_iCode(thisCode, compUse, _ICODE_DESCENDING,			NULL);
			SComp*	compAlias				= iComps_findNextBy_iCode(thisCode, compUse, _ICODE_ALIAS,				NULL);
			SComp*	compExclusive			= iComps_findNextBy_iCode(thisCode, compUse, _ICODE_EXCLUSIVE,			NULL);
			SComp*	compShared				= iComps_findNextBy_iCode(thisCode, compUse, _ICODE_SHARED,				NULL);
//			SComp*	compConnString			= iComps_findNextBy_iCode(thisCode, compUse, _ICODE_CONNSTRING,			NULL);
			SComp*	compValidate			= iComps_findNextBy_iCode(thisCode, compUse, _ICODE_VALIDATE,			NULL);
			SComp*	compVisualize			= iComps_findNextBy_iCode(thisCode, compUse, _ICODE_VISUALIZE,			NULL);		// USE fred.dbf VISUALIZE	&& Creates disk-defrag-like display of table and index
			SComp*	compJournal				= iComps_findNextBy_iCode(thisCode, compUse, _ICODE_JOURNAL,			NULL);		// USE fred.dbf JOURNAL		&& Creates fred.jrn with every write change made to table or index


		//////////
		// Report any conflicts
		//////
			//////////
			// Cannot have both ASCENDING and DESCENDING
			//////
				if (compAscending && compDescending)
				{
					iError_reportByNumber(thisCode, _ERROR_CONFLICTING_PARAMETERS, ((compAscending->ll.uniqueId < compDescending->ll.uniqueId) ? compDescending : compAscending), false);
					goto clean_exit;
				}


			//////////
			// Cannot have both SHARED and EXCLUSIVE
			//////
				if (compShared && compExclusive)
				{
					iError_reportByNumber(thisCode, _ERROR_CONFLICTING_PARAMETERS, ((compShared->ll.uniqueId < compExclusive->ll.uniqueId) ? compExclusive : compShared), false);
					goto clean_exit;
				}

				// Determine shared or exclusive status
				if (compShared)
				{
					// Explicitly shared
					llIsExclusive	= false;

				} else if (compExclusive) {
					// Explicitly exclusive
					llIsExclusive	= true;

				} else {
					// Use the current SET default
					llIsExclusive	= propGet_settings_Exclusive(_settings);
				}


			//////////
			// If they specify IN, they must specify something after it
			//////
// TODO:  Untested function, breakpoint and examine
// debug_break;
				if (compIn && !compIn->ll.next)
				{
					iError_reportByNumber(thisCode, _ERROR_SYNTAX, compIn, false);
					goto clean_exit;
				}

				// Go ahead and point to what's after it
				if (compIn)
					compIn = compIn->ll.nextComp;


			//////////
			// If they specified an alias, they must specify something after it
			//////
				if (compAlias && !compAlias->ll.next)
				{
					iError_reportByNumber(thisCode, _ERROR_SYNTAX, compAlias, false);
					goto clean_exit;
				}

				// Go ahead and point to what's after it
				if (compAlias)
					compAlias = compAlias->ll.nextComp;


			//////////
			// What type of USE are we pursuing?
			//////
				if (compUse && !compUse->ll.next)
				{
					// USE ... They have specified USE by itself, closing the current work area
					if ((lnWorkArea = iDbf_get_workArea_current(thisCode, cgcDbfKeyName)) >= 0)
					{
						// Close it
						iDbf_close(thisCode, &gsWorkArea[lnWorkArea]);

					} else {
						// The current work area is invalid
						// Hmmm... this shouldn't ever happen. Ever. :-)
						iError_reportByNumber(thisCode, _ERROR_INTERNAL_ERROR, compUse, false);
					}

					// We're good
					goto clean_exit;
				}

				// Go ahead and point to what's after it
				compUse = compUse->ll.nextComp;


		//////////
		// Find out if they specified a workarea
		//////
			// Note:  Right now, compIn is already pointing to the thing after "IN"
			if (compIn)
			{
				// Get what comes after the IN
				comp3 = NULL;
				comp4 = NULL;
				if ((comp2 = iComps_getNth(thisCode, compIn, 1)) && (comp3 = iComps_getNth(thisCode, comp2, 1)) && (comp4 = iComps_getNth(thisCode, comp3, 1)))
				{
					// Placeholder to allow engagement through the if expression as far as it will go
				}

				// Find out what they're selecting
				if (compIn->iCode == _ICODE_SELECT)
				{
					// They've specified USE IN SELECT something
					// Perform tests on what comes after SELECT()
					if (!comp2) {
						// Syntax error
						iError_reportByNumber(thisCode, _ERROR_SYNTAX, compIn, false);
						goto clean_exit;

					} else if (comp2->iCode != _ICODE_PARENTHESIS_LEFT) {
						// Syntax error missing parenthesis
						iError_reportByNumber(thisCode, _ERROR_SYNTAX, comp2, false);
						goto clean_exit;

					} else if (!comp3) {
						// Syntax error missing parameter
						iError_reportByNumber(thisCode, _ERROR_MISSING_PARAMETER, comp2, false);
						goto clean_exit;

					} else if (!(comp4 = iComps_getNth(thisCode, comp3, 1))) {
						// Syntax error
						iError_reportByNumber(thisCode, _ERROR_SYNTAX, comp3, false);
						goto clean_exit;

					} else if (comp4->iCode != _ICODE_PARENTHESIS_RIGHT) {
						// Syntax error parenthesis expected
						iError_reportByNumber(thisCode, _ERROR_PARENTHESIS_EXPECTED, comp4, false);
						goto clean_exit;
					}
					// Once we get here, we know we have SELECT(...something

					// They've specified USE IN SELECT(something)
					varInWorkArea = iEngine_get_variableName_fromComponent(thisCode, comp3, &llManufacturedAliasName);

				} else {
					// They must've specified a number or alias name
					varInWorkArea = iEngine_get_variableName_fromComponent(thisCode, compIn, &llManufacturedAliasName);
				}
			}


		//////////
		// See if they specified an integer or character for the SELECT()
		//////
			if (varInWorkArea)
			{
				//////////
				// See what they specified
				//////
					if (iVariable_isTypeNumeric(varInWorkArea))
					{
						// They're are specifying a number
						lnWorkArea = iiVariable_getAs_s32(thisCode, varInWorkArea, false, &error, &errorNum);
						if (error)	{ iError_reportByNumber(thisCode, errorNum, compIn, false); return; }

					} else if (iVariable_isTypeCharacter(varInWorkArea)) {
						// They specified something character (could be a work area letter, or alias)
						if (iDbf_isWorkAreaLetter(thisCode, varInWorkArea))
						{
							// Work area letter
							lnWorkArea = (s32)iUpperCase(varInWorkArea->value.data_s8[0]) - (s32)'A' + 1;

						} else {
							// Alias name
							lnWorkArea = (s32)iDbf_get_workArea_byAlias(thisCode, varInWorkArea, null);
						}

						// Did we get a valid work area?
						if (lnWorkArea < 0)
						{
							iError_reportByNumber(thisCode, _ERROR_ALIAS_NOT_FOUND, iVariable_getRelatedComp(thisCode, varInWorkArea), false);
							goto clean_exit;
						}
						// If we get here, we have our work area number

					} else {
						// Unrecognized syntax
						iError_reportByNumber(thisCode, _ERROR_SYNTAX, compIn->ll.nextComp, false);
						goto clean_exit;
					}

			} else {
				// Just grab the current work area
				lnWorkArea = (s32)iDbf_get_workArea_current(thisCode, cgcDbfKeyName);
			}


		//////////
		// Was "USE IN..." specified?
		//////
			// Note:  Right now, compUse is already pointing to the thing after "USE"
			if (compUse->iCode == _ICODE_IN)
			{
				// Yes, close that work area and we're done
				iDbf_close(thisCode, &gsWorkArea[lnWorkArea]);
				goto clean_exit;
			}


		//////////
		// Get the table name
		//////
			// Note:  compUse is actually pointing to whatever was after USE by this point
			if ((varTableName = iEngine_get_variableName_fromComponent(thisCode, compUse, &llManufacturedTableName))) {
				// Placeholder, we were able to obtain a variable name
				// Note:  The variable is checked for sanity below

			} else if ((varTableName = iEngine_get_contiguousComponents(thisCode, compUse, &llManufacturedTableName, NULL, 0))) {
					// Placeholder, we were able to obtain a contiguous stream of characters
//////////
// TODO:	Enhancement consideration.  May not ever be needed.
//
//			For the contiguous components grab, it may be desirable to pass an array through to obtain only
//			those components that are known to be part of a valid pathname for the target OS.  This could
//			also be setup to be specified by a SET VALID_PATHNAME_CHARS TO cString to allow that string to
//			be parsed out and the components derived obtained therein.  Such a creature would generally look
//			like this:
//
// 				#define _VALID_PATHNAME_ICODE_ARRAY_COUNT 7
// 				s32 gnValidPathname_iCodeArray[_VALID_PATHNAME_ICODE_ARRAY_COUNT];
//
// 				gnValidPathname_iCodeArray[0] = _ICODE_ALPHA;
// 				gnValidPathname_iCodeArray[1] = _ICODE_NUMERIC;
// 				gnValidPathname_iCodeArray[2] = _ICODE_ALPHANUMERIC;
// 				gnValidPathname_iCodeArray[3] = _ICODE_COLON;
// 				gnValidPathname_iCodeArray[4] = _ICODE_BACKSLASH;
// 				gnValidPathname_iCodeArray[5] = _ICODE_DOT;
// 				gnValidPathname_iCodeArray[6] = _ICODE_UNDERSCORE;
// 				// Plus any other characters to add
//
//			And in use:
//				iEngine_get_contiguousComponents(compUse, &llManufacturedTableName, &gnValidPathname_iCodeArray[0], _VALID_PATHNAME_ICODE_ARRAY_COUNT)
//////
			}

			// Is it valid?
			if (!varTableName || !iVariable_isTypeCharacter(varTableName))
			{
				// We didn't get what we needed
				iError_reportByNumber(thisCode, _ERROR_UNRECOGNIZED_PARAMETER, compUse, false);
				goto clean_exit;
			}
			// Note:	The parameter, while character, may still be incorrect.
			//			It may be an invalid filename.  That will be sorted out on the open.


		//////////
		// If they didn't specify AGAIN, make sure it's not already open
		//////
			if (!compAgain)
			{
				// No AGAIN clause was specified, so make sure it isn't already found as being in use
// TODO:  Need FULLPATH() here
				if (iDbf_get_workArea_byTablePathname(thisCode, varTableName, null) >= 0)
				{
					// It was found, which means it's already in use
					iError_reportByNumber(thisCode, _ERROR_TABLE_ALREADY_IN_USE, compUse, false);
					goto clean_exit;
				}
			}


		//////////
		// Get the alias name, making sure it's unique amongst the other alias name
		//////
			if (compAlias)
			{
				// They've specified an alias
				varAliasName	= iEngine_get_variableName_fromComponent(thisCode, compAlias->ll.nextComp, &llManufacturedTableName);
				lnWorkAreaAlias	= iDbf_get_workArea_byAlias(thisCode, varAliasName, null);
				if (lnWorkAreaAlias > 0)
				{
					// They've specified an alias name
					// If it's the current work area, or the one they specified with the "IN xyz" clause, then we're okay
					if (lnWorkArea != lnWorkAreaAlias)
					{
						// Nope, they're trying to re-use an alias already in use
						iError_reportByNumber(thisCode, _ERROR_ALIAS_ALREADY_IN_USE, compAlias, false);
						goto clean_exit;
					}
					// If we get here, the work area is okay

				} else {
					// Unknown alias
					iError_reportByNumber(thisCode, _ERROR_ALIAS_NOT_FOUND, compAlias, false);
					goto clean_exit;
				}

			} else {
				// We need to construct the alias from the table name
				varAliasName = iDbf_get_alias_fromPathname(thisCode, varTableName, null);
			}
			if (!varAliasName)
			{
				iError_reportByNumber(thisCode, _ERROR_INTERNAL_ERROR, compUse, false);
				goto clean_exit;
			}


		//////////
		// See if the current work area already has a table open
		//////
			llIsInUse = iDbf_isWorkAreaUsed(thisCode, &gsWorkArea[lnWorkArea], &llIsValidWorkArea);
			if (!llIsValidWorkArea)
			{
				// They specified an invalid work area number
				iError_reportByNumber(thisCode, _ERROR_INVALID_WORK_AREA, compIn, false);
				goto clean_exit;

			} else if (llIsInUse) {
				// If it's already open, close it
				iDbf_close(thisCode, &gsWorkArea[lnWorkArea]);
			}


		//////////
		// Get the alias
		//////
			iDbf_set_workArea_current(thisCode, (u32)lnWorkArea, null);
			lnWorkArea = iDbf_open(thisCode, varTableName, varAliasName, llIsExclusive, (compAgain != NULL), (compValidate != NULL), (compDescending != NULL), (compVisualize != NULL), (compJournal != NULL));
			if (lnWorkArea < 0)
			{
				// The negative work area number indicates the error
				iError_signal(thisCode, iDbf_translateError(thisCode, (s32)lnWorkArea), compUse, false, NULL, false);

			} else {
				// Set any meta data about the table
//				SComp*	compAgain				= iComps_findNextBy_iCode(compUse, _ICODE_AGAIN,				NULL);
//				SComp*	compNoRequery			= iComps_findNextBy_iCode(compUse, _ICODE_NOREQUERY,			NULL);
//				SComp*	compNoData				= iComps_findNextBy_iCode(compUse, _ICODE_NODATA,				NULL);
//				SComp*	compNoUpdate			= iComps_findNextBy_iCode(compUse, _ICODE_NOUPDATE,				NULL);
//				SComp*	compExclamationPoint	= iComps_findNextBy_iCode(compUse, _ICODE_EXCLAMATION_POINT,	NULL);
//				SComp*	compIn					= iComps_findNextBy_iCode(compUse, _ICODE_IN,					NULL);
//				SComp*	compIndex				= iComps_findNextBy_iCode(compUse, _ICODE_INDEX,				NULL);
//				SComp*	compOrder				= iComps_findNextBy_iCode(compUse, _ICODE_ORDER,				NULL);
//				SComp*	compTag					= iComps_findNextBy_iCode(compUse, _ICODE_TAG,					NULL);
//				SComp*	compAscending			= iComps_findNextBy_iCode(compUse, _ICODE_ASCENDING,			NULL);
//				SComp*	compDescending			= iComps_findNextBy_iCode(compUse, _ICODE_DESCENDING,			NULL);
//				SComp*	compAlias				= iComps_findNextBy_iCode(compUse, _ICODE_ALIAS,				NULL);
//				SComp*	compExclusive			= iComps_findNextBy_iCode(compUse, _ICODE_EXCLUSIVE,			NULL);
//				SComp*	compShared				= iComps_findNextBy_iCode(compUse, _ICODE_SHARED,				NULL);
//				SComp*	compConnString			= iComps_findNextBy_iCode(compUse, _ICODE_CONNSTRING,			NULL);
			}

clean_exit:
			// Release variables
			if (varInWorkArea)		iVariable_delete(thisCode, varInWorkArea,	true);
			if (varTableName)		iVariable_delete(thisCode, varTableName,	true);
			if (varAliasName)		iVariable_delete(thisCode, varAliasName,	true);
	}
