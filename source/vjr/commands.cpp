//////////
//
// /libsf/source/vjr/commands.cpp
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
// To add a new function, see the instructions in command_defs.h.
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
		// Append the error to the EM
		iSEM_appendLine(screenData, errorText, -1);
		screen_editbox->isDirtyRender = true;
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
			case _ERROR_OUT_OF_MEMORY:						{	iError_report((s8*)cgcOutOfMemory);						break;	}
			case _ERROR_UNEXPECTED_COMMAND:					{	iError_report((s8*)cgcUnexpectedCommand);				break;	}
			case _ERROR_CONTEXT_HAS_CHANGED:				{	iError_report((s8*)cgcContextHasChanged);				break;	}
			case _ERROR_FULL_RECOMPILE_REQUIRED:			{	iError_report((s8*)cgcFullRecompileRequired);			break;	}
			case _ERROR_NOT_A_VARIABLE:						{	iError_report((s8*)cgcNotAVariable);					break;	}
			case _ERROR_NUMERIC_OVERFLOW:					{	iError_report((s8*)cgcNumericOverflow);					break;	}
			case _ERROR_NOT_NUMERIC:						{	iError_report((s8*)cgcNotNumeric);						break;	}
			case _ERROR_EMPTY_STRING:						{	iError_report((s8*)cgcEmptyString);						break;	}
			case _ERROR_SYNTAX:								{	iError_report((s8*)cgcSyntaxError);						break;	}
			case _ERROR_UNRECOGNIZED_PARAMETER:				{	iError_report((s8*)cgcUnrecognizedParameter);			break;	}
			case _ERROR_OUT_OF_RANGE:						{	iError_report((s8*)cgcOutOfRange);						break;	}
			case _ERROR_COMMA_EXPECTED:						{	iError_report((s8*)cgcCommaExpected);					break;	}
			case _ERROR_TOO_MANY_PARAMETERS:				{	iError_report((s8*)cgcTooManyParameters);				break;	}
			case _ERROR_DATA_TYPE_MISMATCH:					{	iError_report((s8*)cgcDataTypeMismatch);				break;	}
			case _ERROR_FEATURE_NOT_AVAILABLE:				{	iError_report((s8*)cgcFeatureNotAvailable);				break;	}
			case _ERROR_P1_IS_INCORRECT:					{	iError_report((s8*)cgcP1IsIncorrect);					break;	}
			case _ERROR_P2_IS_INCORRECT:					{	iError_report((s8*)cgcP2IsIncorrect);					break;	}
			case _ERROR_P3_IS_INCORRECT:					{	iError_report((s8*)cgcP3IsIncorrect);					break;	}
			case _ERROR_P4_IS_INCORRECT:					{	iError_report((s8*)cgcP4IsIncorrect);					break;	}
			case _ERROR_P5_IS_INCORRECT:					{	iError_report((s8*)cgcP5IsIncorrect);					break;	}
			case _ERROR_P6_IS_INCORRECT:					{	iError_report((s8*)cgcP6IsIncorrect);					break;	}
			case _ERROR_P7_IS_INCORRECT:					{	iError_report((s8*)cgcP7IsIncorrect);					break;	}
			case _ERROR_INTERNAL_ERROR:						{	iError_report((s8*)cgcInternalError);					break;	}
			case _ERROR_INVALID_ARGUMENT_TYPE_COUNT:		{	iError_report((s8*)cgcInvalidArgumentTypeCountError);	break;	}
			case _ERROR_VARIABLE_NOT_FOUND:					{	iError_report((s8*)cgcVariableNotFoundError);			break;	}
		}

		// Flag the component
		if (comp && comp->line && comp->line->sourceCode && comp->line->sourceCode->data && comp->line->sourceCodePopulated != 0)
		{
			// Flag it for error
			comp->isError = true;
		}
	}




//////////
//
// Function: ALLTRIM()
// Trims spaces off the start and end of the string.
//
//////
// Version 0.53
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
	SVariable* function_alltrim(SVariable* varString, SVariable* varCaseInsensitive, SVariable* varTrimChars1, SVariable* varTrimChars2)
	{
		return(ifunction_trimCommon(varString, varCaseInsensitive, varTrimChars1, varTrimChars2, true, true));
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
	SVariable* ifunction_trimCommon(SVariable* varString, SVariable* varCaseInsensitive, SVariable* varTrimChars1, SVariable* varTrimChars2, bool tlTrimTheStart, bool tlTrimTheEnd)
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
				iError_reportByNumber(_ERROR_P1_IS_INCORRECT, varString->compRelated);
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
					iError_reportByNumber(_ERROR_P2_IS_INCORRECT, varCaseInsensitive->compRelated);
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
					iError_reportByNumber(_ERROR_P2_IS_INCORRECT, varCaseInsensitive->compRelated);
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
					iError_reportByNumber(_ERROR_TOO_MANY_PARAMETERS, varTrimChars1->compRelated);
					return(NULL);

				} else if (iVariable_isTypeCharacter(varTrimChars1)) {
					// They specified characters to scan
					trim1ptr	= varTrimChars1->value.data;
					trim1Length	= varTrimChars1->value.length;

				} else {
					iError_reportByNumber(_ERROR_P3_IS_INCORRECT, varTrimChars1->compRelated);
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
					iError_reportByNumber(_ERROR_P4_IS_INCORRECT, varTrimChars2->compRelated);
					return(NULL);
				}
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
					iDatum_duplicate(&result->value, varString->value.data + lnClipStartPos, lnClipEndPos - lnClipStartPos + 1);
			}


		//////////
        // Return our converted result
		//////
	        return result;
	}




//////////
//
// Function: ASC()
// Takes a character input and converts it to its ASCII value.
//
//////
// Version 0.53
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
    SVariable* function_asc(SVariable* varString)
    {
        u8 			value;
        SVariable*	result;


		//////////
        // Parameter 1 must be character
		//////
			if (!iVariable_isValid(varString) || !iVariable_isTypeCharacter(varString))
			{
				iError_reportByNumber(_ERROR_P1_IS_INCORRECT, varString->compRelated);
				return(NULL);
			}


		//////////
        // It must be at least one character long
		//////
			if (varString->value.length == 0)
				iError_reportByNumber(_ERROR_EMPTY_STRING, varString->compRelated);


		//////////
		// Extract the first character, and convert it to a number
		//////
			value = varString->value.data_u8[0];


		//////////
        // Create our return result
		//////
	        result = iVariable_create(_VAR_TYPE_S32, NULL);
			if (!result)
			{
				iError_report("Internal error.");
				return(NULL);
			}


		//////////
        // Populate the result as an ASCII character
		//////
	        *result->value.data_s32 = (s32)value;


		//////////
        // Return our converted result
		//////
	        return result;
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
// Version 0.53
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
	SVariable* function_at(SVariable* varNeedle, SVariable* varHaystack, SVariable* varOccurrence)
	{
		return(ifunction_atOccursCommon(varNeedle, varHaystack, varOccurrence, true, false, NULL));
	}

	SVariable* function_atc(SVariable* varNeedle, SVariable* varHaystack, SVariable* varOccurrence)
	{
		return(ifunction_atOccursCommon(varNeedle, varHaystack, varOccurrence, false, false, NULL));
	}

	SVariable* function_rat(SVariable* varNeedle, SVariable* varHaystack, SVariable* varOccurrence)
	{
		return(ifunction_atOccursCommon(varNeedle, varHaystack, varOccurrence, true, true, NULL));
	}

	SVariable* function_ratc(SVariable* varNeedle, SVariable* varHaystack, SVariable* varOccurrence)
	{
		return(ifunction_atOccursCommon(varNeedle, varHaystack, varOccurrence, false, true, NULL));
	}

	SVariable* ifunction_atOccursCommon(SVariable* varNeedle, SVariable* varHaystack, SVariable* varOccurrence, bool tlCaseSensitive, bool tlScanBackward, u32* tnFoundCount)
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
				iError_reportByNumber(_ERROR_P1_IS_INCORRECT, varNeedle->compRelated);
				return(NULL);
			}


		//////////
        // Parameter 2 must be character
		//////
			if (!iVariable_isValid(varHaystack) || !iVariable_isTypeCharacter(varHaystack))
			{
				iError_reportByNumber(_ERROR_P2_IS_INCORRECT, varHaystack->compRelated);
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
					iError_reportByNumber(_ERROR_P3_IS_INCORRECT, varOccurrence->compRelated);
					return(NULL);
				}

				// Grab the occurrence
				lnOccurrence = iiVariable_getAs_s32(varOccurrence, false, &error, &errorNum);
				if (error)	{	iError_reportByNumber(errorNum, varOccurrence->compRelated);	return(NULL);	}

				// Validate that the occurrence is
				if (lnOccurrence <= 0)
				{
					iError_report("Parameter 3 must be 1 or greater");
					return(NULL);
				}

			} else {
				// The first occurrence is what we're after
				lnOccurrence = 1;
			}


		//////////
		// Create the return variable
		//////
			result = iVariable_create(_VAR_TYPE_S32, NULL);


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
// Function: CHR()
// Takes a numeric input in the range 0..255, and converts it to its ASCII character.
//
//////
// Version 0.53
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
    SVariable* function_chr(SVariable* varNumer)
    {
        s32			value;
		u32			errorNum;
        bool		error;
        SVariable*	result;
		s8			buffer[16];


		//////////
        // Parameter 1 must be numeric
		//////
			if (!iVariable_isValid(varNumer) || !iVariable_isTypeNumeric(varNumer))
			{
				iError_reportByNumber(_ERROR_P1_IS_INCORRECT, varNumer->compRelated);
				return(NULL);
			}


		//////////
        // It must be in the range 0..255
		//////
			value = iiVariable_getAs_s32(varNumer, false, &error, &errorNum);
			if (error)
			{
				// The iVariable_getAs_s32() function reported an error.
				// This means the user is trying to obtain an integer value from a logical, or something similar.
				iError_reportByNumber(errorNum, varNumer->compRelated);
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
// Function: CHRTRAN()
// Character transformation
//
//////
// Version 0.53
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
	SVariable* function_chrtran(SVariable* varString, SVariable* varSearch, SVariable* varReplace)
	{
		return(ifunction_chrtranCommon(varString, varSearch, varReplace, true));
	}

	SVariable* function_chrtranc(SVariable* varString, SVariable* varSearch, SVariable* varReplace)
	{
		return(ifunction_chrtranCommon(varString, varSearch, varReplace, false));
	}

	SVariable* ifunction_chrtranCommon(SVariable* varString, SVariable* varSearch, SVariable* varReplace, bool tlCaseSensitive)
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
				iError_reportByNumber(_ERROR_P1_IS_INCORRECT, varString->compRelated);
				return(NULL);
			}


		//////////
        // Parameter 2 must be character
		//////
			if (!iVariable_isValid(varSearch) || !iVariable_isTypeCharacter(varSearch))
			{
				iError_reportByNumber(_ERROR_P2_IS_INCORRECT, varSearch->compRelated);
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
				iError_reportByNumber(_ERROR_P3_IS_INCORRECT, varReplace->compRelated);
				return(NULL);
			}
		

		//////////
		// Allocate a copy of the original string
		//////
			result = iVariable_createAndPopulate(_VAR_TYPE_CHARACTER, varString->value.data, varString->value.length);
			
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
// Function: CREATEOBJECT()
// Instantiates and instance of the indicated class.
//
//////
// Version 0.53
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
	SVariable* function_createobject(SVariable* varClass)
	{
		s32			lnObjType;
		SObject*	obj;
        SVariable*	result;


		//////////
        // Parameter 1 must be character
		//////
			if (!iVariable_isValid(varClass) || !iVariable_isTypeCharacter(varClass))
			{
				iError_reportByNumber(_ERROR_P1_IS_INCORRECT, varClass->compRelated);
				return(NULL);
			}


		//////////
        // It must be at least one character long
		//////
			if (varClass->value.length == 0)
				iError_reportByNumber(_ERROR_EMPTY_STRING, varClass->compRelated);


		//////////
		// See if we know the class
		//////
			lnObjType = iiObj_getBaseclassType_byName(varClass->value.data, varClass->value.length);
			if (lnObjType <= 0)
			{
				iError_report("Unknown class");
				return(NULL);
			}

			// Create our object
			obj = iObj_create(lnObjType, NULL);
			if (!obj)
			{
				iError_report("Internal error on create object.");
				return(NULL);
			}


		//////////
        // Create our return result variable, which is a reference to the new object
		//////
	        result = iVariable_create(_VAR_TYPE_OBJECT, NULL);
			if (!result)
			{
				iObj_delete(&obj, true, true, true);
				iError_report("Internal error on create variable.");
				return(NULL);
			}

			// Store the object reference
			result->obj = obj;


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
// Version 0.53
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
	SVariable* function_datetime(SVariable* varYear, SVariable* varMonth, SVariable* varDay, SVariable* varHour, SVariable* varMinute, SVariable* varSecond, SVariable* varMillisecond)
	{
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
			GetLocalTime(&lst);

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
						iError_report("Year must be numeric");
						return(NULL);
					}
					lst.wYear = (u16)iiVariable_getAs_s32(varYear, false, &error, &errorNum);
					if (!error && (lst.wYear < 1600 || lst.wYear > 2400))
					{
						iError_reportByNumber(_ERROR_OUT_OF_RANGE, varYear->compRelated);
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
						iError_report("Month must be numeric");
						return(NULL);
					}
					lst.wMonth = (u16)iiVariable_getAs_s32(varMonth, false, &error, &errorNum);
					if (!error && (lst.wMonth < 1 || lst.wMonth > 12))
					{
						iError_reportByNumber(_ERROR_OUT_OF_RANGE, varMonth->compRelated);
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
						iError_report("Day must be numeric");
						return(NULL);
					}
					lst.wDay = (u16)iiVariable_getAs_s32(varDay, false, &error, &errorNum);
					if (!error && !iVariable_isDayValidForDate(lst.wYear, lst.wMonth, lst.wDay))
					{
						iError_reportByNumber(_ERROR_OUT_OF_RANGE, varDay->compRelated);
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
						iError_report("Hours must be numeric");
						return(NULL);
					}
					lst.wHour = (u16)iiVariable_getAs_s32(varHour, false, &error, &errorNum);
					if (!error && (lst.wHour < 0 || lst.wHour > 23))
					{
						iError_reportByNumber(_ERROR_OUT_OF_RANGE, varHour->compRelated);
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
						iError_report("Minutes must be numeric");
						return(NULL);
					}
					lst.wMinute = (u16)iiVariable_getAs_s32(varMinute, false, &error, &errorNum);
					if (!error && (lst.wMinute < 0 || lst.wMinute > 59))
					{
						iError_reportByNumber(_ERROR_OUT_OF_RANGE, varMinute->compRelated);
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
						iError_report("Seconds must be numeric");
						return(NULL);
					}
					lst.wSecond = (u16)iiVariable_getAs_s32(varSecond, false, &error, &errorNum);
					if (!error && (lst.wSecond < 0 || lst.wSecond > 59))
					{
						iError_reportByNumber(_ERROR_OUT_OF_RANGE, varSecond->compRelated);
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
						iError_report("Milliseconds must be numeric");
						return(NULL);
					}
					lst.wMilliseconds = (u16)iiVariable_getAs_s32(varMillisecond, false, &error, &errorNum);
					if (!error && (lst.wMilliseconds < 0 || lst.wMilliseconds > 999))
					{
						iError_reportByNumber(_ERROR_OUT_OF_RANGE, varMillisecond->compRelated);
						return(NULL);
					}
				}
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
// Function: INT()
// Takes a value and returns the INT(n) of that value.
//
//////
// Version 0.53
// Last update:
//     Jul.13.2014
//////
// Change log:
//     Jul.13.2014 - Initial creation
//////
// Parameters:
//     p1			-- Numeric or floating point
//
//////
// Returns:
//    INT(n) of the value in p1
//////
    SVariable* function_int(SVariable* varNumber)
    {
		f64			fValue;
		u32			errorNum;
        bool		error;
        SVariable*	result;


		//////////
        // Parameter 1 must be numeric
		//////
			if (!iVariable_isValid(varNumber) || !iVariable_isTypeNumeric(varNumber))
			{
				iError_reportByNumber(_ERROR_P1_IS_INCORRECT, varNumber->compRelated);
				return(NULL);
			}


		//////////
        // Based on its type, process it accordingly
		//////
			if (iVariable_isTypeFloatingPoint(varNumber))
			{
				fValue = iiVariable_getAs_f64(varNumber, false, &error, &errorNum);
				if (error)	{	iError_reportByNumber(errorNum, varNumber->compRelated);	return(NULL);	}

				// Convert to S64
				result = iVariable_create(_VAR_TYPE_S64, NULL);
				*(s64*)result->value.data = (s64)fValue;

			} else {
				// Copy whatever it already is
				result = iVariable_create(varNumber->varType, NULL);
				iDatum_duplicate(&result->value, &varNumber->value);
			}


		//////////
        // Return our converted result
		//////
	        return result;
    }




//////////
//
// Function: LEFT()
// Returns the left N characters of a string.
//
//////
// Version 0.53
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
	SVariable* function_left(SVariable* varString, SVariable* varCount)
	{
		s32			lnLength;
		u32			errorNum;
		bool		error;
        SVariable*	result;


		//////////
        // Parameter 1 must be character
		//////
			if (!iVariable_isValid(varString) || iVariable_getType(varString) != _VAR_TYPE_CHARACTER)
			{
				iError_reportByNumber(_ERROR_P1_IS_INCORRECT, varString->compRelated);
				return(NULL);
			}


		//////////
        // Parameter 2 must be nmumeric
		//////
			if (!iVariable_isValid(varCount) || !iVariable_isTypeNumeric(varCount))
			{
				iError_reportByNumber(_ERROR_P2_IS_INCORRECT, varCount->compRelated);
				return(NULL);
			}


		//////////
        // Find out how long they want our string to be
		//////
			lnLength = iiVariable_getAs_s32(varCount, false, &error, &errorNum);
			if (error)
			{
				iError_reportByNumber(errorNum, varCount->compRelated);
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
        // Copy as much of the source string as will fit
		//////
			if (lnLength > 0)
				iDatum_duplicate(&result->value, varString->value.data, min(varString->value.length, lnLength));


		//////////
        // Return our converted result
		//////
	        return result;
	}




//////////
//
// Function: LEN()
// Returns the length of the string.
//
//////
// Version 0.53
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
	SVariable* function_len(SVariable* varString)
	{
        SVariable* result;


		//////////
        // Parameter 1 must be character
		//////
			if (!iVariable_isValid(varString) || iVariable_getType(varString) != _VAR_TYPE_CHARACTER)
			{
				iError_reportByNumber(_ERROR_P1_IS_INCORRECT, varString->compRelated);
				return(NULL);
			}


		//////////
        // Create our return result
		//////
	        result = iVariable_create(_VAR_TYPE_S32, NULL);
			if (!result)
			{
				iError_report("Internal error.");
				return(NULL);
			}


		//////////
		// Populate based on the length
		//////
			*(s32*)result->value.data = varString->value.length;


		//////////
        // Return our converted result
		//////
	        return result;
	}




//////////
//
// Function: LOWER()
// Converts every character in the string to lowercase.
//
//////
// Version 0.53
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
	SVariable* function_lower(SVariable* varString)
	{
		s32			lnI;
        SVariable*	result;


		//////////
        // Parameter 1 must be character
		//////
			if (!iVariable_isValid(varString) || iVariable_getType(varString) != _VAR_TYPE_CHARACTER)
			{
				iError_reportByNumber(_ERROR_P1_IS_INCORRECT, varString->compRelated);
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
	        return result;
	}




//////////
//
// Function: LTRIM()
// Trims spaces off the start of the string.
//
//////
// Version 0.53
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
	SVariable* function_ltrim(SVariable* varString, SVariable* varCaseInsensitive, SVariable* varTrimChars1, SVariable* varTrimChars2)
	{
		return(ifunction_trimCommon(varString, varCaseInsensitive, varTrimChars1, varTrimChars2, true, false));
	}




//////////
//
// Function: MAX()
// Returns the maximum value of the two inputs.
//
//////
// Version 0.53   (Determine the current version from the header in vjr.cpp)
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
	SVariable* function_max(SVariable* varLeft, SVariable* varRight)
	{
		bool		llLeft;
		s32			lnLeft32, lnRight32;
		s64			lnLeft64, lnRight64;
		f64			lfLeft64, lfRight64;
		bool		error;
		u32			errorNum;
		SDateTime*	dtLeft;
		SDateTime*	dtRight;
		SVariable*	result;
// TODO:  We need to add support for comparable types, such as numeric that are integer, and float, which can still be compared


		//////////
        // Parameter 1 must be numeric
		//////
			if (!iVariable_isValid(varLeft))
			{
				iError_reportByNumber(_ERROR_P1_IS_INCORRECT, varLeft->compRelated);
				return(NULL);
			}


		//////////
        // Parameter 2 must be numeric
		//////
			if (!iVariable_isValid(varRight))
			{
				iError_reportByNumber(_ERROR_P2_IS_INCORRECT, varRight->compRelated);
				return(NULL);
			}


		//////////
		// They must be the same type
		//////
			if (varLeft->varType != varRight->varType)
			{
				// Operand mismatch
				iError_reportByNumber(_ERROR_DATA_TYPE_MISMATCH, varRight->compRelated);
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
					if (iVariable_isTypeBig(varLeft))
					{
						// It's a character compared to a character
						iError_reportByNumber(_ERROR_FEATURE_NOT_AVAILABLE, NULL);
						return(NULL);

					} else if (iVariable_isTypeFloatingPoint(varLeft)) {
						// Comparing floating point values
						lfLeft64	= iiVariable_getAs_f64(varLeft, false, &error, &errorNum);
						if (error)	{	iError_reportByNumber(errorNum, varLeft->compRelated);	return(NULL);	}

						lfRight64	= iiVariable_getAs_f64(varRight, false, &error, &errorNum);
						if (error)	{	iError_reportByNumber(errorNum, varRight->compRelated);	return(NULL);	}

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
							lnLeft64	= iiVariable_getAs_s64(varLeft, false, &error, &errorNum);
							if (error)	{	iError_reportByNumber(errorNum, varLeft->compRelated);	return(NULL);	}

							lnRight64	= iiVariable_getAs_s64(varRight, false, &error, &errorNum);
							if (error)	{	iError_reportByNumber(errorNum, varRight->compRelated);	return(NULL);	}

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
							lnLeft32	= iiVariable_getAs_s32(varLeft, false, &error, &errorNum);
							if (error)	{	iError_reportByNumber(errorNum, varLeft->compRelated);	return(NULL);	}

							lnRight32	= iiVariable_getAs_s32(varRight, false, &error, &errorNum);
							if (error)	{	iError_reportByNumber(errorNum, varRight->compRelated);	return(NULL);	}

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
						iError_reportByNumber(_ERROR_FEATURE_NOT_AVAILABLE, varLeft->compRelated);
						return(NULL);
					}
			}
			// When we get here, llLeft is populated with our intent
			result = iVariable_create(varLeft->varType, NULL);
			if (llLeft)
			{
				// Left is less, so duplicate right
				iDatum_duplicate(&result->value, &varRight->value);

			} else {
				// Right is less, so duplicate left
				iDatum_duplicate(&result->value, &varLeft->value);
			}

			// Indicate our result
			return(result);
	}




//////////
//
// Function: MIN()
// Returns the minimum value of the two inputs.
//
//////
// Version 0.53   (Determine the current version from the header in vjr.cpp)
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
	SVariable* function_min(SVariable* varLeft, SVariable* varRight)
	{
		bool		llLeft;
		s32			lnLeft32, lnRight32;
		s64			lnLeft64, lnRight64;
		f64			lfLeft64, lfRight64;
		bool		error;
		u32			errorNum;
		SDateTime*	dtLeft;
		SDateTime*	dtRight;
		SVariable*	result;
// TODO:  We need to add support for comparable types, such as numeric that are integer, and float, which can still be compared


		//////////
        // Parameter 1 must be numeric
		//////
			if (!iVariable_isValid(varLeft))
			{
				iError_reportByNumber(_ERROR_P1_IS_INCORRECT, varLeft->compRelated);
				return(NULL);
			}


		//////////
        // Parameter 2 must be numeric
		//////
			if (!iVariable_isValid(varRight))
			{
				iError_reportByNumber(_ERROR_P2_IS_INCORRECT, varRight->compRelated);
				return(NULL);
			}


		//////////
		// They must be the same type
		//////
			if (varLeft->varType != varRight->varType)
			{
				// Operand mismatch
				iError_reportByNumber(_ERROR_DATA_TYPE_MISMATCH, varRight->compRelated);
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
					if (iVariable_isTypeBig(varLeft))
					{
						// It's a character compared to a character
						iError_reportByNumber(_ERROR_FEATURE_NOT_AVAILABLE, NULL);
						return(NULL);

					} else if (iVariable_isTypeFloatingPoint(varLeft)) {
						// Comparing floating point values
						lfLeft64	= iiVariable_getAs_f64(varLeft, false, &error, &errorNum);
						if (error)	{	iError_reportByNumber(errorNum, varLeft->compRelated);	return(NULL);	}

						lfRight64	= iiVariable_getAs_f64(varRight, false, &error, &errorNum);
						if (error)	{	iError_reportByNumber(errorNum, varRight->compRelated);	return(NULL);	}

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
							lnLeft64	= iiVariable_getAs_s64(varLeft, false, &error, &errorNum);
							if (error)	{	iError_reportByNumber(errorNum, varLeft->compRelated);	return(NULL);	}

							lnRight64	= iiVariable_getAs_s64(varRight, false, &error, &errorNum);
							if (error)	{	iError_reportByNumber(errorNum, varRight->compRelated);	return(NULL);	}

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
							lnLeft32	= iiVariable_getAs_s32(varLeft, false, &error, &errorNum);
							if (error)	{	iError_reportByNumber(errorNum, varLeft->compRelated);	return(NULL);	}

							lnRight32	= iiVariable_getAs_s32(varRight, false, &error, &errorNum);
							if (error)	{	iError_reportByNumber(errorNum, varRight->compRelated);	return(NULL);	}

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
						iError_reportByNumber(_ERROR_FEATURE_NOT_AVAILABLE, varLeft->compRelated);
						return(NULL);
					}
			}
			// When we get here, llLeft is populated with our intent
			result = iVariable_create(varLeft->varType, NULL);
			if (llLeft)
			{
				// Left is less
				iDatum_duplicate(&result->value, &varLeft->value);

			} else {
				// Right is less
				iDatum_duplicate(&result->value, &varRight->value);
			}

			// Indicate our result
			return(result);
	}




//////////
//
// Function: OCCURS(), and OCCURSC()
// Counts the number of times the first parameter is found in the second, and
// optionally with regards to case.
//
//////
// Version 0.53
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
	SVariable* function_occurs(SVariable* varNeedle, SVariable* varHaystack)
	{
		u32			lnFoundCount;
		SVariable*	result;


		// Compute the found count
		result = ifunction_atOccursCommon(varNeedle, varHaystack, NULL, true, false, &lnFoundCount);
		if (result)
		{
			// Update the return variable
			*(s32*)result->value.data_s32 = lnFoundCount;
		}

		// Return our result
		return(result);
	}

	SVariable* function_occursc(SVariable* varNeedle, SVariable* varHaystack)
	{
		u32			lnFoundCount;
		SVariable*	result;


		// Compute the found count
		result = ifunction_atOccursCommon(varNeedle, varHaystack, NULL, false, false, &lnFoundCount);
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
// Function: PADC(), PADL(), and PADR()
// 
// and lowercases everything else.
//
//////
// Version 0.53
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
	SVariable* function_padc(SVariable* varExpression, SVariable* varResultSize, SVariable* varPadCharacter)
	{
		return(ifunction_padCommon(varExpression, varResultSize, varPadCharacter, true, true));
	}

	SVariable* function_padl(SVariable* varExpression, SVariable* varResultSize, SVariable* varPadCharacter)
	{
		return(ifunction_padCommon(varExpression, varResultSize, varPadCharacter, true, false));
	}

	SVariable* function_padr(SVariable* varExpression, SVariable* varResultSize, SVariable* varPadCharacter)
	{
		return(ifunction_padCommon(varExpression, varResultSize, varPadCharacter, false, true));
	}

	SVariable* ifunction_padCommon(SVariable* varExpression, SVariable* varResultSize, SVariable* varPadCharacter, bool tlPadLeft, bool tlPadRight)
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
				iError_reportByNumber(_ERROR_INTERNAL_ERROR, NULL);
				return(NULL);
			}


		//////////
        // Parameter 1 must be valid
		//////
			if (!iVariable_isValid(varExpression))
			{
				iError_reportByNumber(_ERROR_P1_IS_INCORRECT, NULL);
				return(NULL);
			}


		//////////
        // Parameter 2 must be numeric
		//////
			if (!iVariable_isValid(varResultSize) || !iVariable_isTypeNumeric(varResultSize))
			{
				iError_reportByNumber(_ERROR_P2_IS_INCORRECT, varResultSize->compRelated);
				return(NULL);
			}
			lnResultSize = iiVariable_getAs_s32(varResultSize, false, &error, &errorNum);
			if (error)	{	iError_reportByNumber(errorNum, varResultSize->compRelated);	return(NULL);	}


		//////////
        // Parameter 3 is optional, but if present...
		//////
			if (iVariable_isValid(varPadCharacter))
			{
				// ...it must be character
				if (!iVariable_isTypeCharacter(varPadCharacter))
				{
					iError_reportByNumber(_ERROR_P3_IS_INCORRECT, varPadCharacter->compRelated);
					return(NULL);
				}

				// Validate the pad character is at least one character long
				if (varPadCharacter->value.length == 0)
				{
					iError_report("Parameter 3 must be at least one character");
					return(NULL);
				}

			} else {
				// The first occurrence is what we're after
				varPadCharacter = varConstant_space;
			}


		//////////
		// Create the return variable
		//////
			tempVar = iVariable_convertForDisplay(varExpression);

			// If it wasn't created, or it's already as long or longer than its target, return it
			if (!tempVar || tempVar->value.length >= lnResultSize)
				return(tempVar);
			
			// If we get here, the result will be needed
			result = iVariable_create(_VAR_TYPE_CHARACTER, NULL);
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

			// Delete our temporary variable
			iVariable_delete(tempVar, true);


		//////////
		// Indicate our status
		//////
			return(result);
	}




//////////
//
// Function: PROPER()
// Converts the first character after every space to upper-case,
// and lowercases everything else.
//
//////
// Version 0.53
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
	SVariable* function_proper(SVariable* varString)
	{
		s32			lnI;
		bool		llUpperNext;
        SVariable*	result;


		//////////
        // Parameter 1 must be character
		//////
			if (!iVariable_isValid(varString) || iVariable_getType(varString) != _VAR_TYPE_CHARACTER)
			{
				iError_reportByNumber(_ERROR_P1_IS_INCORRECT, varString->compRelated);
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
	        return result;
	}




//////////
//
// Function: REPLICATE()
// Returns the indicated string replicated N times.
//
//////
// Version 0.53
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
	SVariable* function_replicate(SVariable* varString, SVariable* varCount)
	{
		s32			lnI, lnCopies;
		u32			errorNum;
		bool		error;
        SVariable*	result;


		//////////
        // Parameter 1 must be character
		//////
			if (!iVariable_isValid(varString) || iVariable_getType(varString) != _VAR_TYPE_CHARACTER)
			{
				iError_reportByNumber(_ERROR_P1_IS_INCORRECT, varString->compRelated);
				return(NULL);
			}


		//////////
        // Parameter 2 must be nmumeric
		//////
			if (!iVariable_isValid(varCount) || !iVariable_isTypeNumeric(varCount))
			{
				iError_reportByNumber(_ERROR_P2_IS_INCORRECT, varCount->compRelated);
				return(NULL);
			}


		//////////
        // Find out how long they want our string to be
		//////
			lnCopies = iiVariable_getAs_s32(varCount, false, &error, &errorNum);
			if (error)
			{
				iError_reportByNumber(errorNum, varCount->compRelated);
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
	        return result;
	}




//////////
//
// Function: RGB()
// Returns the RGB() of the three input values.
//
//////
// Version 0.53   (Determine the current version from the header in vjr.cpp)
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
	SVariable* function_rgb(SVariable* varRed, SVariable* varGrn, SVariable* varBlu)
	{
		f32			lfRed, lfGrn, lfBlu;
		s32			lnRed, lnGrn, lnBlu;
		bool		error;
		u32			errorNum;
		SVariable*	result;


		//////////
        // Parameter 1 must be numeric
		//////
			if (!iVariable_isValid(varRed) || !iVariable_isTypeNumeric(varRed))
			{
				iError_reportByNumber(_ERROR_P1_IS_INCORRECT, varRed->compRelated);
				return(NULL);
			}


		//////////
        // Parameter 2 must be numeric
		//////
			if (!iVariable_isValid(varGrn) || !iVariable_isTypeNumeric(varGrn))
			{
				iError_reportByNumber(_ERROR_P2_IS_INCORRECT, varGrn->compRelated);
				return(NULL);
			}


		//////////
        // Parameter 3 must be numeric
		//////
			if (!iVariable_isValid(varBlu) || !iVariable_isTypeNumeric(varBlu))
			{
				iError_reportByNumber(_ERROR_P3_IS_INCORRECT, varBlu->compRelated);
				return(NULL);
			}


		//////////
		// Grab the parameters as usable values
		//////
			if (iVariable_isTypeFloatingPoint(varRed))
			{
				// It is a floating point, which means it must be in the range 0..1
				lfRed = iiVariable_getAs_f32(varRed, false, &error, &errorNum);
				if (error)	{	iError_reportByNumber(errorNum, varRed->compRelated);	return(NULL);	}
				lnRed = (s32)(255.0f * min(max(lfRed, 0.0f), 1.0f));
				
			} else {
				// It is an integer, which means it must be in the range 0..255
				lnRed = iiVariable_getAs_s32(varRed, false, &error, &errorNum);
				if (error)	{	iError_reportByNumber(errorNum, varRed->compRelated);	return(NULL);	}
			}
			if (lnRed < 0 || lnRed > 255)
			{
				iError_reportByNumber(_ERROR_OUT_OF_RANGE, varRed->compRelated);
				return(NULL);
			}

			if (iVariable_isTypeFloatingPoint(varGrn))
			{
				// It is a floating point, which means it must be in the range 0..1
				lfGrn = iiVariable_getAs_f32(varGrn, false, &error, &errorNum);
				if (error)	{	iError_reportByNumber(errorNum, varGrn->compRelated);	return(NULL);	}
				lnGrn = (s32)(255.0f * min(max(lfGrn, 0.0f), 1.0f));

			} else {
				// It is an integer, which means it must be in the range 0..255
				lnGrn = iiVariable_getAs_s32(varGrn, false, &error, &errorNum);
				if (error)	{	iError_reportByNumber(errorNum, varGrn->compRelated);	return(NULL);	}
			}
			if (lnGrn < 0 || lnGrn > 255)
			{
				iError_reportByNumber(_ERROR_OUT_OF_RANGE, varGrn->compRelated);
				return(NULL);
			}

			if (iVariable_isTypeFloatingPoint(varBlu))
			{
				// It is a floating point, which means it must be in the range 0..1
				lfBlu = iiVariable_getAs_f32(varBlu, false, &error, &errorNum);
				if (error)	{	iError_reportByNumber(errorNum, varBlu->compRelated);	return(NULL);	}
				lnBlu = (s32)(255.0f * min(max(lfBlu, 0.0f), 1.0f));

			} else {
				// It is an integer, which means it must be in the range 0..255
				lnBlu	= iiVariable_getAs_s32(varBlu, false, &error, &errorNum);
				if (error)	{	iError_reportByNumber(errorNum, varBlu->compRelated);	return(NULL);	}
			}
			if (lnBlu < 0 || lnBlu > 255)
			{
				iError_reportByNumber(_ERROR_OUT_OF_RANGE, varBlu->compRelated);
				return(NULL);
			}


		//////////
        // Create the return result
		//////
	        result = iVariable_create(_VAR_TYPE_U32, NULL);
			if (!result)
			{
				iError_report("Internal error.");
				return(NULL);
			}


		//////////
        // Populate the return value
		//////
			*(u32*)result->value.data = bgra((u32)lnBlu, (u32)lnGrn, (u32)lnRed, 0);


		//////////
        // Return our converted result
		//////
	        return result;
	}




//////////
//
// Function: RGBA()
// Returns the RGBA() of the four input values.
//
//////
// Version 0.53   (Determine the current version from the header in vjr.cpp)
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
	SVariable* function_rgba(SVariable* varRed, SVariable* varGrn, SVariable* varBlu, SVariable* varAlp)
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
				iError_reportByNumber(_ERROR_P1_IS_INCORRECT, varRed->compRelated);
				return(NULL);
			}


		//////////
        // Parameter 2 must be numeric
		//////
			if (!iVariable_isValid(varGrn) || !iVariable_isTypeNumeric(varGrn))
			{
				iError_reportByNumber(_ERROR_P2_IS_INCORRECT, varGrn->compRelated);
				return(NULL);
			}


		//////////
        // Parameter 3 must be numeric
		//////
			if (!iVariable_isValid(varBlu) || !iVariable_isTypeNumeric(varBlu))
			{
				iError_reportByNumber(_ERROR_P3_IS_INCORRECT, varBlu->compRelated);
				return(NULL);
			}


		//////////
        // Parameter 4 must be numeric
		//////
			if (!iVariable_isValid(varAlp) || !iVariable_isTypeNumeric(varAlp))
			{
				iError_reportByNumber(_ERROR_P3_IS_INCORRECT, varAlp->compRelated);
				return(NULL);
			}


		//////////
		// Grab the parameters as usable values
		//////
			if (iVariable_isTypeFloatingPoint(varRed))
			{
				// It is a floating point, which means it must be in the range 0..1
				lfRed = iiVariable_getAs_f32(varRed, false, &error, &errorNum);
				if (error)	{	iError_reportByNumber(errorNum, varRed->compRelated);	return(NULL);	}
				lnRed = (s32)(255.0f * min(max(lfRed, 0.0f), 1.0f));
				
			} else {
				// It is an integer, which means it must be in the range 0..255
				lnRed = iiVariable_getAs_s32(varRed, false, &error, &errorNum);
				if (error)	{	iError_reportByNumber(errorNum, varRed->compRelated);	return(NULL);	}
			}
			if (lnRed < 0 || lnRed > 255)
			{
				iError_reportByNumber(_ERROR_OUT_OF_RANGE, varRed->compRelated);
				return(NULL);
			}

			if (iVariable_isTypeFloatingPoint(varGrn))
			{
				// It is a floating point, which means it must be in the range 0..1
				lfGrn = iiVariable_getAs_f32(varGrn, false, &error, &errorNum);
				if (error)	{	iError_reportByNumber(errorNum, varGrn->compRelated);	return(NULL);	}
				lnGrn = (s32)(255.0f * min(max(lfGrn, 0.0f), 1.0f));

			} else {
				// It is an integer, which means it must be in the range 0..255
				lnGrn = iiVariable_getAs_s32(varGrn, false, &error, &errorNum);
				if (error)	{	iError_reportByNumber(errorNum, varGrn->compRelated);	return(NULL);	}
			}
			if (lnGrn < 0 || lnGrn > 255)
			{
				iError_reportByNumber(_ERROR_OUT_OF_RANGE, varGrn->compRelated);
				return(NULL);
			}

			if (iVariable_isTypeFloatingPoint(varBlu))
			{
				// It is a floating point, which means it must be in the range 0..1
				lfBlu = iiVariable_getAs_f32(varBlu, false, &error, &errorNum);
				if (error)	{	iError_reportByNumber(errorNum, varBlu->compRelated);	return(NULL);	}
				lnBlu = (s32)(255.0f * min(max(lfBlu, 0.0f), 1.0f));

			} else {
				// It is an integer, which means it must be in the range 0..255
				lnBlu	= iiVariable_getAs_s32(varBlu, false, &error, &errorNum);
				if (error)	{	iError_reportByNumber(errorNum, varBlu->compRelated);	return(NULL);	}
			}
			if (lnBlu < 0 || lnBlu > 255)
			{
				iError_reportByNumber(_ERROR_OUT_OF_RANGE, varBlu->compRelated);
				return(NULL);
			}

			if (iVariable_isTypeFloatingPoint(varAlp))
			{
				// It is a floating point, which means it must be in the range 0..1
				lfAlp = iiVariable_getAs_f32(varAlp, false, &error, &errorNum);
				if (error)	{	iError_reportByNumber(errorNum, varAlp->compRelated);	return(NULL);	}
				lnAlp = (s32)(255.0f * min(max(lfAlp, 0.0f), 1.0f));

			} else {
				// It is an integer, which means it must be in the range 0..255
				lnAlp	= iiVariable_getAs_s32(varAlp, false, &error, &errorNum);
				if (error)	{	iError_reportByNumber(errorNum, varAlp->compRelated);	return(NULL);	}
			}
			if (lnAlp < 0 || lnAlp > 255)
			{
				iError_reportByNumber(_ERROR_OUT_OF_RANGE, varAlp->compRelated);
				return(NULL);
			}


		//////////
        // Create the return result
		//////
	        result = iVariable_create(_VAR_TYPE_U32, NULL);
			if (!result)
			{
				iError_report("Internal error.");
				return(NULL);
			}


		//////////
        // Populate the return value
		//////
			*(u32*)result->value.data = bgra((u32)lnBlu, (u32)lnGrn, (u32)lnRed, (u32)lnAlp);


		//////////
        // Return our converted result
		//////
	        return result;
	}




//////////
//
// Function: RIGHT()
// Returns the right N characters of a string.
//
//////
// Version 0.53
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
	SVariable* function_right(SVariable* varString, SVariable* varCount)
	{
		s32			lnStart, lnLength;
		u32			errorNum;
		bool		error;
        SVariable*	result;


		//////////
        // Parameter 1 must be character
		//////
			if (!iVariable_isValid(varString) || iVariable_getType(varString) != _VAR_TYPE_CHARACTER)
			{
				iError_reportByNumber(_ERROR_P1_IS_INCORRECT, varString->compRelated);
				return(NULL);
			}


		//////////
        // Parameter 2 must be nmumeric
		//////
			if (!iVariable_isValid(varCount) || !iVariable_isTypeNumeric(varCount))
			{
				iError_reportByNumber(_ERROR_P2_IS_INCORRECT, varCount->compRelated);
				return(NULL);
			}


		//////////
        // Find out how long they want our string to be
		//////
			lnLength = iiVariable_getAs_s32(varCount, false, &error, &errorNum);
			if (error)
			{
				iError_reportByNumber(errorNum, varCount->compRelated);
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
        // Copy as much of the source string as will fit
		//////
			if (lnLength >= varString->value.length)
			{
				// Copy only the length of the current string
				iDatum_duplicate(&result->value, &varString->value);

			} else if (lnLength > 0) {
				// We can do an extraction
				lnStart = varString->value.length - lnLength;
				iDatum_duplicate(&result->value, varString->value.data + lnStart, lnLength);
			}


		//////////
        // Return our converted result
		//////
	        return result;
	}




//////////
//
// Function: RTRIM()
// Trims spaces off the end of the string.
//
//////
// Version 0.53
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
	SVariable* function_rtrim(SVariable* varString, SVariable* varCaseInsensitive, SVariable* varTrimChars1, SVariable* varTrimChars2)
	{
		return(ifunction_trimCommon(varString, varCaseInsensitive, varTrimChars1, varTrimChars2, false, true));
	}




//////////
//
// Function: SPACE()
// Creates a character variable initialized with spaces.
//
//////
// Version 0.53
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
	SVariable* function_space(SVariable* varCount)
	{
		s32			lnLength;
		u32			errorNum;
		bool		error;
        SVariable*	result;


		//////////
        // Parameter 1 must be numeric
		//////
			if (!iVariable_isValid(varCount) || !iVariable_isTypeNumeric(varCount))
			{
				iError_reportByNumber(_ERROR_P1_IS_INCORRECT, varCount->compRelated);
				return(NULL);
			}


		//////////
        // Find out how long they want our string to be
		//////
			lnLength = iiVariable_getAs_s32(varCount, false, &error, &errorNum);
			if (error)
			{
				iError_reportByNumber(errorNum, varCount->compRelated);
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
        // Create the source string and initialize to spaces
		//////
	        iDatum_allocateSpace(&result->value, lnLength);
			memset(result->value.data, 32, lnLength);


		//////////
        // Return our converted result
		//////
	        return result;
	}




//////////
//
// Function: STRTRAN()
// Converts the matching portions of the string from one form to another.
//
//////
// Version 0.53   (Determine the current version from the header in vjr.cpp)
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
	SVariable* function_strtran(SVariable* varString, SVariable* varSearch, SVariable* varReplace, SVariable* varRecursiveCount)
	{
		return(ifunction_strtranCommon(varString, varSearch, varReplace, varRecursiveCount, true));
	}

	SVariable* function_strtranc(SVariable* varString, SVariable* varSearch, SVariable* varReplace, SVariable* varRecursiveCount)
	{
		return(ifunction_strtranCommon(varString, varSearch, varReplace, varRecursiveCount, false));
	}

	SVariable* ifunction_strtranCommon(SVariable* varString, SVariable* varSearch, SVariable* varReplace, SVariable* varRecursiveCount, bool tlCaseSensitive)
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
				iError_reportByNumber(_ERROR_P1_IS_INCORRECT, varString->compRelated);
				return(NULL);
			}


		//////////
        // Parameter 2 must be character
		//////
			if (!iVariable_isValid(varSearch) || !iVariable_isTypeCharacter(varSearch))
			{
				iError_reportByNumber(_ERROR_P2_IS_INCORRECT, varSearch->compRelated);
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
				iError_reportByNumber(_ERROR_P3_IS_INCORRECT, varReplace->compRelated);
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
				iError_reportByNumber(_ERROR_P4_IS_INCORRECT, varRecursiveCount->compRelated);
				return(NULL);

			} else {
				// Grab the actual value
				lnRecursiveCount = iiVariable_getAs_s32(varRecursiveCount, false, &error, &errorNum);
				if (error)	{	iError_reportByNumber(errorNum, varRecursiveCount->compRelated);	return(NULL);	}
				if (lnRecursiveCount < 0)
				{
					// It is invalid
					iError_reportByNumber(_ERROR_P4_IS_INCORRECT, varRecursiveCount->compRelated);
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
				result = iVariable_createAndPopulate(_VAR_TYPE_CHARACTER, varString->value.data, varString->value.length);
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
						result = iVariable_createAndPopulate(_VAR_TYPE_CHARACTER, varString->value.data, varString->value.length);

					// Return our result
					return(result);
				}

				// When we get here, we have a new length for our copy
				lnLength = result->value.length - (lnFoundCount * varSearch->value.length) + (lnFoundCount * varReplace->value.length);

				// Allocate a new string of that length
				resultNew = iVariable_create(_VAR_TYPE_CHARACTER, NULL);
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
					iVariable_delete(result, true);

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
// Version 0.53   (Determine the current version from the header in vjr.cpp)
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
	SVariable* function_stuff(SVariable* varOriginalString, SVariable* varStartPos, SVariable* varNumToRemove, SVariable* varStuffString)
	{
		s32			lnStartPosition, lnRemoveCount, lnBufferLength;
		bool		error;
		u32			errorNum;
		s8*			lcBuffer;
		SVariable*	result;


		//////////
        // Parameter 1 must be character
		//////
			if (!iVariable_isValid(varOriginalString) || !iVariable_isTypeCharacter(varOriginalString))
			{
				iError_reportByNumber(_ERROR_P1_IS_INCORRECT, varOriginalString->compRelated);
				return(NULL);
			}


		//////////
        // Parameter 2 must be numeric
		//////
			if (!iVariable_isValid(varStartPos) || !iVariable_isTypeNumeric(varStartPos))
			{
				iError_reportByNumber(_ERROR_P2_IS_INCORRECT, varStartPos->compRelated);
				return(NULL);
			}


		//////////
        // Parameter 3 must be numeric
		//////
			if (!iVariable_isValid(varNumToRemove) || !iVariable_isTypeNumeric(varNumToRemove))
			{
				iError_reportByNumber(_ERROR_P3_IS_INCORRECT, varNumToRemove->compRelated);
				return(NULL);
			}


		//////////
        // Parameter 4 must be character
		//////
			if (!iVariable_isValid(varStuffString) || !iVariable_isTypeCharacter(varStuffString))
			{
				iError_reportByNumber(_ERROR_P4_IS_INCORRECT, varStuffString->compRelated);
				return(NULL);
			}


		//////////
		// Grab the parameters as usable values
		//////
			// Your algorithm code goes here
			lnStartPosition	= iiVariable_getAs_s32(varStartPos, false, &error, &errorNum);
			lnRemoveCount	= iiVariable_getAs_s32(varNumToRemove, false, &error, &errorNum);


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
			lcBuffer = (s8*)malloc(lnBufferLength);
			if (!lcBuffer)
			{
				iError_reportByNumber(_ERROR_OUT_OF_MEMORY, NULL);
				return(NULL);
			}

			// Copy the first part of the original string, plus the stuffed in part, plus the end of the last part of the original string
			--lnStartPosition;

			// We only copy the first part if there is something to copy
			if (lnStartPosition > 0)
				memcpy(lcBuffer, varOriginalString->value.data, lnStartPosition);

			// We only insert our stuff string if there is something to put there
			if (varStuffString->value.length > 0)
				memcpy(lcBuffer + lnStartPosition, varStuffString->value.data, varStuffString->value.length);

			// We only copy over the last part if there's something there
			if (varOriginalString->value.length - lnStartPosition - lnRemoveCount > 0)
				memcpy(lcBuffer + lnStartPosition + varStuffString->value.length, varOriginalString->value.data + lnStartPosition + lnRemoveCount, varOriginalString->value.length - lnStartPosition - lnRemoveCount);


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
	        return result;
	}




//////////
//
// Function: SYSMETRIC()
// Based on the index, returns a wide array of information.
//
//////
// Version 0.53
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
    SVariable* function_sysmetric(SVariable* varIndex)
    {
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
				iError_reportByNumber(_ERROR_P1_IS_INCORRECT, varIndex->compRelated);
				return(NULL);
			}


		//////////
        // It must be in the range 1..34
		//////
			index = iiVariable_getAs_s32(varIndex, false, &error, &errorNum);
			if (error)
			{
				iError_reportByNumber(errorNum, varIndex->compRelated);
				return(NULL);

			} else if (index > 34 || index < 1) {
				// We report our own error
				iError_report("Parameter must be in the range 1..34");
				return(NULL);
			}


		//////////
        // Create our return result
		//////
	        result = iVariable_create(_VAR_TYPE_S32, NULL);
			if (!result)
			{
				iError_report("Internal error.");
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
	        return result;
    }




//////////
//
// Function: TRANSFORM()
// Converts any variable input to a character form, and applies formatting based on codes.
//
//////
// Version 0.53
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
	SVariable* function_transform(SVariable* varVariable, SVariable* varFormat)
	{
		SVariable* result;


		//////////
        // Parameter 1 must be valid
		//////
			if (!iVariable_isValid(varVariable))
			{
				iError_reportByNumber(_ERROR_P1_IS_INCORRECT, varVariable->compRelated);
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
					iError_reportByNumber(_ERROR_P2_IS_INCORRECT, varFormat->compRelated);
					return(NULL);
				}
			}


		//////////
		// Create the return variable
		//////
			result = iVariable_convertForDisplay(varVariable);


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
// Function: UPPER()
// Converts every character in the string to uppercase.
//
//////
// Version 0.53
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
	SVariable* function_upper(SVariable* varString)
	{
		s32			lnI;
        SVariable*	result;


		//////////
        // Parameter 1 must be character
		//////
			if (!iVariable_isValid(varString) || iVariable_getType(varString) != _VAR_TYPE_CHARACTER)
			{
				iError_reportByNumber(_ERROR_P1_IS_INCORRECT, varString->compRelated);
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
	        return result;
	}




//////////
//
// Function: VERSION()
// Based on input, retrieves various version information.
//
//////
// Version 0.53
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
    SVariable* function_version(SVariable* varIndex)
    {
        s32			index;
		u32			errorNum;
        bool		error;
		s8*			lptr;
        SVariable*	result;


		//////////
        // Parameter 1 must be numeric
		//////
			lptr = NULL;
			if (!iVariable_isValid(varIndex))
			{
				// They are requesting the default information
				lptr = (s8*)cgcVersionText;

			} else if (!iVariable_isTypeNumeric(varIndex)) {
				// The parameter is not numeric
				iError_reportByNumber(_ERROR_P1_IS_INCORRECT, varIndex->compRelated);
				return(NULL);

			} else {
				// It must be in the range 1..5
				index = iiVariable_getAs_s32(varIndex, false, &error, &errorNum);
				if (error)
				{
					iError_reportByNumber(errorNum, varIndex->compRelated);
					return(NULL);

				} else if (index < 1 || index > 5) {
					// We report our own error
					iError_report("Parameter must be in the range 1..5");
					return(NULL);
				}
			}


		//////////
        // Create our return result
		//////
			if (lptr || index == 1 || index == 4)
			{
				// Character return
				result = iVariable_create(_VAR_TYPE_CHARACTER, NULL);
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
				result = iVariable_create(_VAR_TYPE_S32, NULL);
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
				iError_report("Internal error.");
				return(NULL);
			}


		//////////
        // Return our converted result
		//////
	        return result;
    }




//////////
//
// Function: CONCATENATE()
// Note:  This is a temporary function until the main compiler engine is coded.
// Concatenates two strings together.
//
//////
// Version 0.53   (Determine the current version from the header in vjr.cpp)
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
	SVariable* function_concatenate(SVariable* varString1, SVariable* varString2)
	{
		SVariable*	result;


		//////////
        // Parameter 1 must be character
		//////
			if (!iVariable_isValid(varString1) || !iVariable_isTypeCharacter(varString1))
			{
				iError_reportByNumber(_ERROR_P1_IS_INCORRECT, varString1->compRelated);
				return(NULL);
			}


		//////////
        // Parameter 2 must be character
		//////
			if (!iVariable_isValid(varString2) || !iVariable_isTypeCharacter(varString2))
			{
				iError_reportByNumber(_ERROR_P2_IS_INCORRECT, varString2->compRelated);
				return(NULL);
			}


		//////////
		// Allocate enough space for the assemblage
		//////
			result = iVariable_create(_VAR_TYPE_CHARACTER, NULL);
			iDatum_allocateSpace(&result->value, varString1->value.length + varString2->value.length);
			// Create the concatenated string
			memcpy(result->value.data,						varString1->value.data,		varString1->value.length);
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
// Version 0.53   (Determine the current version from the header in vjr.cpp)
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
	SVariable* function_add(SVariable* varNum1, SVariable* varNum2)
	{
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
				iError_reportByNumber(_ERROR_P1_IS_INCORRECT, varNum1->compRelated);
				return(NULL);
			}


		//////////
        // Parameter 2 must be numeric
		//////
			if (!iVariable_isValid(varNum2) || !iVariable_isTypeNumeric(varNum2))
			{
				iError_reportByNumber(_ERROR_P2_IS_INCORRECT, varNum2->compRelated);
				return(NULL);
			}


		//////////
		// Determine what we're comparing
		//////
			if (iVariable_isTypeFloatingPoint(varNum1))
			{
				// p1 is floating point, meaning the result will be too
				lfValue1 = iiVariable_getAs_f64(varNum1, false, &error, &errorNum);
				if (error)	{	iError_reportByNumber(errorNum, varNum1->compRelated);	return(NULL);	}

				// Create our floating point result
				result = iVariable_create(_VAR_TYPE_F64, NULL);

				// Grab p2
				if (iVariable_isTypeFloatingPoint(varNum2))
				{
					// p2 is floating point
					lfValue2 = iiVariable_getAs_f64(varNum2, false, &error, &errorNum);
					if (error)	{	iError_reportByNumber(errorNum, varNum2->compRelated);	return(NULL);	}

					// Store the result
					*(f64*)result->value.data = lfValue1 + lfValue2;

				} else  {
					// p2 is not floating point, so we'll get it as an integer
					lnValue2 = iiVariable_getAs_s64(varNum2, false, &error, &errorNum);
					if (error)	{	iError_reportByNumber(errorNum, varNum2->compRelated);	return(NULL);	}

					// Store the result
					*(f64*)result->value.data = lfValue1 + (f64)lnValue2;
				}

			} else {
				// p1 is integer, result is determined by what p2 is, either integer or floating point
				lnValue1 = iiVariable_getAs_s64(varNum1, false, &error, &errorNum);
				if (error)	{	iError_reportByNumber(errorNum, varNum1->compRelated);	return(NULL);	}

				// Grab p2
				if (iVariable_isTypeFloatingPoint(varNum2))
				{
					// p2 is floating point
					lfValue2 = iiVariable_getAs_f64(varNum2, false, &error, &errorNum);
					if (error)	{	iError_reportByNumber(errorNum, varNum2->compRelated);	return(NULL);	}

					// Create our floating point result
					result = iVariable_create(_VAR_TYPE_F64, NULL);

					// Store the result
					*(f64*)result->value.data = (f64)lnValue1 + lfValue2;

				} else  {
					// p2 is not floating point, so we'll get it as an integer
					lnValue2 = iiVariable_getAs_s64(varNum2, false, &error, &errorNum);
					if (error)	{	iError_reportByNumber(errorNum, varNum2->compRelated);	return(NULL);	}

					// Create our floating point result
					result = iVariable_create(_VAR_TYPE_S64, NULL);

					// Store the result
					*(s64*)result->value.data = lnValue1 + lnValue2;
				}
			}


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
// Version 0.53   (Determine the current version from the header in vjr.cpp)
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
	SVariable* function_sub(SVariable* varSub1, SVariable* varSub2)
	{
		s64			lnValue1, lnValue2;
		f64			lfValue1, lfValue2;
		bool		error;
		u32			errorNum;
		SVariable*	result;


		//////////
        // Parameter 1 must be numeric
		//////
			if (!iVariable_isValid(varSub1) || !iVariable_isTypeNumeric(varSub1))
			{
				iError_reportByNumber(_ERROR_P1_IS_INCORRECT, varSub1->compRelated);
				return(NULL);
			}


		//////////
        // Parameter 2 must be numeric
		//////
			if (!iVariable_isValid(varSub2) || !iVariable_isTypeNumeric(varSub2))
			{
				iError_reportByNumber(_ERROR_P2_IS_INCORRECT, varSub2->compRelated);
				return(NULL);
			}


		//////////
		// Determine what we're comparing
		//////
			if (iVariable_isTypeFloatingPoint(varSub1))
			{
				// p1 is floating point, meaning the result will be too
				lfValue1 = iiVariable_getAs_f64(varSub1, false, &error, &errorNum);
				if (error)	{	iError_reportByNumber(errorNum, varSub1->compRelated);	return(NULL);	}

				// Create our floating point result
				result = iVariable_create(_VAR_TYPE_F64, NULL);

				// Grab p2
				if (iVariable_isTypeFloatingPoint(varSub2))
				{
					// p2 is floating point
					lfValue2 = iiVariable_getAs_f64(varSub2, false, &error, &errorNum);
					if (error)	{	iError_reportByNumber(errorNum, varSub2->compRelated);	return(NULL);	}

					// Store the result
					*(f64*)result->value.data = lfValue1 - lfValue2;

				} else  {
					// p2 is not floating point, so we'll get it as an integer
					lnValue2 = iiVariable_getAs_s64(varSub2, false, &error, &errorNum);
					if (error)	{	iError_reportByNumber(errorNum, varSub2->compRelated);	return(NULL);	}

					// Store the result
					*(f64*)result->value.data = lfValue1 - (f64)lnValue2;
				}

			} else {
				// p1 is integer, result is determined by what p2 is, either integer or floating point
				lnValue1 = iiVariable_getAs_s64(varSub1, false, &error, &errorNum);
				if (error)	{	iError_reportByNumber(errorNum, varSub1->compRelated);	return(NULL);	}

				// Grab p2
				if (iVariable_isTypeFloatingPoint(varSub2))
				{
					// p2 is floating point
					lfValue2 = iiVariable_getAs_f64(varSub2, false, &error, &errorNum);
					if (error)	{	iError_reportByNumber(errorNum, varSub2->compRelated);	return(NULL);	}

					// Create our floating point result
					result = iVariable_create(_VAR_TYPE_F64, NULL);

					// Store the result
					*(f64*)result->value.data = (f64)lnValue1 - lfValue2;

				} else  {
					// p2 is not floating point, so we'll get it as an integer
					lnValue2 = iiVariable_getAs_s64(varSub2, false, &error, &errorNum);
					if (error)	{	iError_reportByNumber(errorNum, varSub2->compRelated);	return(NULL);	}

					// Create our floating point result
					result = iVariable_create(_VAR_TYPE_S64, NULL);

					// Store the result
					*(s64*)result->value.data = lnValue1 - lnValue2;
				}
			}


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
// Version 0.53   (Determine the current version from the header in vjr.cpp)
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
	SVariable* function_mul(SVariable* varNum1, SVariable* varNum2)
	{
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
				iError_reportByNumber(_ERROR_P1_IS_INCORRECT, varNum1->compRelated);
				return(NULL);
			}


		//////////
        // Parameter 2 must be numeric
		//////
			if (!iVariable_isValid(varNum2) || !iVariable_isTypeNumeric(varNum2))
			{
				iError_reportByNumber(_ERROR_P2_IS_INCORRECT, varNum2->compRelated);
				return(NULL);
			}


		//////////
		// Determine what we're comparing
		//////
			if (iVariable_isTypeFloatingPoint(varNum1))
			{
				// p1 is floating point, meaning the result will be too
				lfValue1 = iiVariable_getAs_f64(varNum1, false, &error, &errorNum);
				if (error)	{	iError_reportByNumber(errorNum, varNum1->compRelated);	return(NULL);	}

				// Create our floating point result
				result = iVariable_create(_VAR_TYPE_F64, NULL);

				// Grab p2
				if (iVariable_isTypeFloatingPoint(varNum2))
				{
					// p2 is floating point
					lfValue2 = iiVariable_getAs_f64(varNum2, false, &error, &errorNum);
					if (error)	{	iError_reportByNumber(errorNum, varNum2->compRelated);	return(NULL);	}

					// Store the result
					*(f64*)result->value.data = lfValue1 * lfValue2;

				} else  {
					// p2 is not floating point, so we'll get it as an integer
					lnValue2 = iiVariable_getAs_s64(varNum2, false, &error, &errorNum);
					if (error)	{	iError_reportByNumber(errorNum, varNum2->compRelated);	return(NULL);	}

					// Store the result
					*(f64*)result->value.data = lfValue1 * (f64)lnValue2;
				}

			} else {
				// p1 is integer, result is determined by what p2 is, either integer or floating point
				lnValue1 = iiVariable_getAs_s64(varNum1, false, &error, &errorNum);
				if (error)	{	iError_reportByNumber(errorNum, varNum1->compRelated);	return(NULL);	}

				// Grab p2
				if (iVariable_isTypeFloatingPoint(varNum2))
				{
					// p2 is floating point
					lfValue2 = iiVariable_getAs_f64(varNum2, false, &error, &errorNum);
					if (error)	{	iError_reportByNumber(errorNum, varNum2->compRelated);	return(NULL);	}

					// Create our floating point result
					result = iVariable_create(_VAR_TYPE_F64, NULL);

					// Store the result
					*(f64*)result->value.data = (f64)lnValue1 * lfValue2;

				} else  {
					// p2 is not floating point, so we'll get it as an integer
					lnValue2 = iiVariable_getAs_s64(varNum2, false, &error, &errorNum);
					if (error)	{	iError_reportByNumber(errorNum, varNum2->compRelated);	return(NULL);	}

					// Create our floating point result
					result = iVariable_create(_VAR_TYPE_S64, NULL);

					// Store the result
					*(s64*)result->value.data = lnValue1 * lnValue2;
				}
			}


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
// Version 0.53   (Determine the current version from the header in vjr.cpp)
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
	SVariable* function_div(SVariable* varNum1, SVariable* varNum2)
	{
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
				iError_reportByNumber(_ERROR_P1_IS_INCORRECT, varNum1->compRelated);
				return(NULL);
			}


		//////////
        // Parameter 2 must be numeric
		//////
			if (!iVariable_isValid(varNum2) || !iVariable_isTypeNumeric(varNum2))
			{
				iError_reportByNumber(_ERROR_P2_IS_INCORRECT, varNum2->compRelated);
				return(NULL);
			}


		//////////
		// Determine what we're comparing
		//////
			if (iVariable_isTypeFloatingPoint(varNum1))
			{
				// p1 is floating point, meaning the result will be too
				lfValue1 = iiVariable_getAs_f64(varNum1, false, &error, &errorNum);
				if (error)	{	iError_reportByNumber(errorNum, varNum1->compRelated);	return(NULL);	}

				// Create our floating point result
				result = iVariable_create(_VAR_TYPE_F64, NULL);

				// Grab p2
				if (iVariable_isTypeFloatingPoint(varNum2))
				{
					// p2 is floating point
					lfValue2 = iiVariable_getAs_f64(varNum2, false, &error, &errorNum);
					if (error)	{	iError_reportByNumber(errorNum, varNum2->compRelated);	return(NULL);	}

					// Store the result
					*(f64*)result->value.data = lfValue1 / lfValue2;

				} else  {
					// p2 is not floating point, so we'll get it as an integer
					lnValue2 = iiVariable_getAs_s64(varNum2, false, &error, &errorNum);
					if (error)	{	iError_reportByNumber(errorNum, varNum2->compRelated);	return(NULL);	}

					// Store the result
					*(f64*)result->value.data = lfValue1 / (f64)lnValue2;
				}

			} else {
				// p1 is integer, result is determined by what p2 is, either integer or floating point
				lnValue1 = iiVariable_getAs_s64(varNum1, false, &error, &errorNum);
				if (error)	{	iError_reportByNumber(errorNum, varNum1->compRelated);	return(NULL);	}

				// Create our floating point result
				result = iVariable_create(_VAR_TYPE_F64, NULL);

				// Grab p2
				if (iVariable_isTypeFloatingPoint(varNum2))
				{
					// p2 is floating point
					lfValue2 = iiVariable_getAs_f64(varNum2, false, &error, &errorNum);
					if (error)	{	iError_reportByNumber(errorNum, varNum2->compRelated);	return(NULL);	}

					// Store the result
					*(f64*)result->value.data = (f64)lnValue1 / lfValue2;

				} else  {
					// p2 is not floating point, so we'll get it as an integer
					lnValue2 = iiVariable_getAs_s64(varNum2, false, &error, &errorNum);
					if (error)	{	iError_reportByNumber(errorNum, varNum2->compRelated);	return(NULL);	}

					// Store the result
					*(f64*)result->value.data = (f64)lnValue1 / (f64)lnValue2;
				}
			}


		//////////
		// Indicate our result
		//////
			return(result);
	}
