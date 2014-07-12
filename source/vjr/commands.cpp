//////////
//
// /libsf/source/vjr/commands.cpp
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
//




//////////
//
// Reports an error.
//
//////
	void iError_report(cs8* constantErrorText)
	{
		iError_report((s8*)constantErrorText);
	}

	void iError_report(s8* errorText)
	{
		// Append the error to the ECM
		iEditChainManager_appendLine(screenData, errorText, -1);
	}

	void iiError_reportComp(SComp* comp)
	{
		s8 buffer[256];

		memset(buffer, 0, sizeof(buffer));
		memcpy(buffer, cgcComponentError, sizeof(cgcComponentError) - 1);
		sprintf(buffer + strlen(buffer), "%u:", comp->start);
		memcpy(buffer + strlen(buffer), comp->line->sourceCode->data + comp->start, comp->length);

		// Append the error to the ECM
		iEditChainManager_appendLine(screenData, buffer, -1);
	}




//////////
//
// Reports an error by number.
//
//////
	void iError_reportByNumber(u32 tnErrorNum, SComp* comp)
	{
		switch (tnErrorNum)
		{
			case _ERROR_OUT_OF_MEMORY:						{	iError_report((s8*)cgcOutOfMemory);					break;	}
			case _ERROR_UNEXPECTED_COMMAND:					{	iError_report((s8*)cgcUnexpectedCommand);			break;	}
			case _ERROR_CONTEXT_HAS_CHANGED:				{	iError_report((s8*)cgcContextHasChanged);			break;	}
			case _ERROR_FULL_RECOMPILE_REQUIRED:			{	iError_report((s8*)cgcFullRecompileRequired);		break;	}
			case _ERROR_NOT_A_VARIABLE:						{	iError_report((s8*)cgcNotAVariable);				break;	}
			case _ERROR_NUMERIC_OVERFLOW:					{	iError_report((s8*)cgcNumericOverflow);				break;	}
			case _ERROR_NOT_NUMERIC:						{	iError_report((s8*)cgcNotNumeric);					break;	}
			case _ERROR_EMPTY_STRING:						{	iError_report((s8*)cgcEmptyString);					break;	}
			case _ERROR_SYNTAX:								{	iError_report((s8*)cgcSyntaxError);					break;	}
			case _ERROR_UNRECOGNIZED_PARAMETER:				{	iError_report((s8*)cgcUnrecognizedParameter);		break;	}
			case _ERROR_OUT_OF_RANGE:						{	iError_report((s8*)cgcOutOfRange);					break;	}
			case _ERROR_COMMA_EXPECTED:						{	iError_report((s8*)cgcCommaExpected);				break;	}
			case _ERROR_TOO_MANY_PARAMETERS:				{	iError_report((s8*)cgcTooManyParameters);			break;	}
		}

		// Display the component
		if (comp && comp->line && comp->line->sourceCode && comp->line->sourceCode->data && comp->line->sourceCodePopulated != 0)
			iiError_reportComp(comp);
	}




//////////
//
// Function: ASC()
// Takes a character input and converts it to its ASCII value.
//
//////
// Version 0.30
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
    SVariable* function_asc(SVariable* p1)
    {
        u8 			value;
        SVariable*	result;


		//////////
        // Parameter 1 must be character
		//////
			if (!iVariable_isValid(p1) || iVariable_getType(p1) != _VAR_TYPE_CHARACTER)
			{
				iError_report("Parameter 1 is not correct");
				return(NULL);
			}


		//////////
        // It must be at least one character long
		//////
			if (p1->value.length == 0)
				iError_reportByNumber(_ERROR_EMPTY_STRING, NULL);


		//////////
		// Extract the first character, and convert it to a number
		//////
			value = p1->value.udata[0];


		//////////
        // Create our return result
		//////
	        result = iVariable_create(_VAR_TYPE_INTEGER, NULL);
			if (!result)
			{
				iError_report("Internal error.");
				return(NULL);
			}


		//////////
        // Populate the result as an ASCII character
		//////
	        *(s32*)result->value.data = value;


		//////////
        // Return our converted result
		//////
	        return result;
    }




//////////
//
// Function: CHR()
// Takes a numeric input in the range 0..255, and converts it to its ASCII character.
//
//////
// Version 0.30
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
    SVariable* function_chr(SVariable* p1)
    {
        s32			value;
		u32			errorNum;
        bool		error;
        SVariable*	result;
		s8			buffer[16];


		//////////
        // Parameter 1 must be numeric
		//////
			if (!iVariable_isValid(p1))
			{
				iError_report("Parameter 1 is not correct");
				return(NULL);
			}


		//////////
        // It must be in the range 0..255
		//////
			value = iiVariable_getAs_s32(p1, false, &error, &errorNum);
			if (error)
			{
				// The iVariable_getAs_s32() function reported an error.
				// This means the user is trying to obtain an integer value from a logical, or something similar.
				iError_reportByNumber(errorNum, NULL);
				return(NULL);

			} else if (value > 255 || value < 0) {
				// We report our own error
				iError_report("Parameter must be in the range 0..255");
				return(NULL);
			}


		//////////
        // Create our return result
		//////
	        result = iVariable_create(_VAR_TYPE_CHARACTER, NULL);
			if (!result)
			{
				iError_report("Internal error.");
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
	        return result;
    }




//////////
//
// Function: DATETIME()
// Returns the current local time, or uses the input variables to create the indicated datetime.
//
//////
// Version 0.30
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
	SVariable* function_datetime(SVariable* pYear, SVariable* pMonth, SVariable* pDay, SVariable* pHour, SVariable* pMinute, SVariable* pSecond, SVariable* pMillisecond)
	{
		SVariable*	result;
		SDateTime*	dt;
		f32			lfJulian;
		u32			errorNum;
		bool		error;
		SYSTEMTIME	lst;


		// Have they provided us with data?
		if (!pYear)
		{
			// Nope, we are creating the current system time
			GetLocalTime(&lst);

		} else {
			// They have provided us at least something
// TODO:  Incomplete feature
return(NULL);
// 			// Default to 01/01/1600 00:00:00.000
// 			lst.wYear		= 1600;
// 			lst.wMonth		= 1;
// 			lst.wDay		= 1;
// 			lst.wHour		= 0;
// 			lst.wMinute		= 0;
// 			lst.wSecond		= 0;
// 			lst.wMilliseconds	= 0;
// 
// 
// 			//////////
// 			// pYear must be numeric, and in the range of 1600..2400
// 			//////
// 				if (!iVariable_isValid(pYear) || iVariable_getType(pYear) != _VAR_TYPE_NUMERIC)
// 				{
// 					iError_report("Parameter 1 is not correct");
// 					return(NULL);
// 				}
// 				lst.wYear = (u16)iiVariable_getAs_s32(pYear, false, &error, &errorNum);
// 				if (!error && (lst.wYear < 1600 || lst.wYear > 2400))
// 				{
// 					iError_reportByNumber(_ERROR_OUT_OF_RANGE);
// 					return(NULL);
// 				}
		}


		//////////
		// Convert lst.* into a VJr datetime variable
		//////
			result = iVariable_create(_VAR_TYPE_DATETIME, NULL);
			dt = (SDateTime*)result->value.data;

			// Date is stored as julian day number
			dt->julian	= iiVariable_julianDayNumber_fromYyyyMmDd(&lfJulian, lst.wYear, lst.wMonth, lst.wDay);

			// Time is stored as seconds since midnight
			dt->seconds = (f32)(lst.wHour * 60 * 60) + (f32)(lst.wMinute * 60) + (f32)lst.wSecond + ((f32)lst.wMilliseconds / 1000.0f);


		//////////
        // Return our converted result
		//////
	        return result;
	}




//////////
//
// Your new function will go here.  Uncomment only the definition with the appropriate number of input parameters.
// If you are creating more than one function, duplicate this block, including this comment section and the blank
// before this comment section below.
//
// STEP3:
// Code away! :-)
//
//////
	// After you have chosen the function template, delete the other lines
	SVariable* function_your_new_function1(SVariable* p1)
	// SVariable* function_your_new_function2(SVariable* p1, SVariable* p2)
	// SVariable* function_your_new_function3(SVariable* p1, SVariable* p2, SVariable* p3)
	// SVariable* function_your_new_function4(SVariable* p1, SVariable* p2, SVariable* p3, SVariable* p4)
	// SVariable* function_your_new_function5(SVariable* p1, SVariable* p2, SVariable* p3, SVariable* p4, SVariable* p5)
	{
		SVariable* result;


		//////////
        // Parameter 1 must be ... (choose the correct one, repeat for each parameter)
		//////
			if (!iVariable_isValid(p1) || iVariable_getType(p1) != _VAR_TYPE_NUMERIC)
			// if (!iVariable_isValid(p1) || iVariable_getType(p1) != _VAR_TYPE_CHARACTER)
			// if (!iVariable_isValid(p1) || iVariable_getType(p1) != _VAR_TYPE_LOGICAL)
			{
				iError_report("Parameter 1 is not correct");
				return(NULL);
			}


		//////////
		// Carry out the logic of your function here
		//////
			// Code here


		//////////
        // Create the return result
		//////
	        result = iVariable_create(_VAR_TYPE_CHARACTER, NULL);
			if (!result)
			{
				iError_report("Internal error.");
				return(NULL);
			}


		//////////
        // Populate the return value in whatever way
		//////
			// Code here


		//////////
        // Return our converted result
		//////
	        return result;
	}
//////
// END
//////////
