//////////
//
// /libsf/source/vjr/commands/funcs/p.cpp
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
				varPadCharacter = cvarSpace1;
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
