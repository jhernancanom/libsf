//////////
//
// /libsf/source/vjr/commands/funcs/rick_in_progress.cpp
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
// Version 0.57
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
// Function: CXLATD()
// Converts a loose character date expression into a DATE().
//
//////
// Version 0.57
// Last update:
//     Apr.26.2015
//////
// Change log:
//     Apr.26.2015 - Initial creation by Rick C. Hodgin
//////
// Parameters:
//     p1			-- Character
//
//////
// Returns:
//    Date			-- A conversion into the DATE() format.
//////
// Example:
//    k = "Apr.26.2015, 8:15p"
//    ? CXLATD(k)
//////
	void function_cxlatd(SThisCode* thisCode, SFunctionParms* rpar)
	{
		iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, NULL, false);
		rpar->returns[0] = NULL;
	}




//////////
//
// Function: CXLATT()
// Converts a loose character date expression into a DATETIME().
//
//////
// Version 0.57
// Last update:
//     Apr.26.2015
//////
// Change log:
//     Apr.26.2015 - Initial creation by Rick C. Hodgin
//////
// Parameters:
//     p1			-- Character
//
//////
// Returns:
//    Datetime		-- A conversion into the DATETIME() format.
//////
// Example:
//    k = "Apr.26.2015, 8:15p"
//    ? CXLATT(k)
//////
	void function_cxlatt(SThisCode* thisCode, SFunctionParms* rpar)
	{
		iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, NULL, false);
		rpar->returns[0] = NULL;
	}




//////////
//
// Function: CXLATX()
// Converts a loose character date expression into a DATETIMEX().
//
//////
// Version 0.57
// Last update:
//     Apr.26.2015
//////
// Change log:
//     Apr.26.2015 - Initial creation by Rick C. Hodgin
//////
// Parameters:
//     p1			-- Character
//
//////
// Returns:
//    DatetimeX		-- A conversion into the DATETIMEX() format.
//////
// Example:
//    k = "Apr.26.2015, 8:15p"
//    ? CXLATX(k)
//////
	void function_cxlatx(SThisCode* thisCode, SFunctionParms* rpar)
	{
		iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, NULL, false);
		rpar->returns[0] = NULL;
	}




//////////
//
// Function: DBUNDLE()
// Assembles components of a date into a date.
// Note:  DBUNDLE() is identical to DATE() if a return parameter is specified.
//
//////
// Version 0.57
// Last update:
//     Apr.26.2015
//////
// Change log:
//     Apr.26.2015 - Initial creation by Rick C. Hodgin
//
//////
// Format 1 parameters (identical to DATE()):
//     r1			-- Output DATE() variable
//     p1			-- (Optional) YEAR(), nJulian, tDatetime, or sDatetimex to use.
//     p2			-- (Optional) MONTH() to use.
//     p3			-- (Optional) DAY() to use.
//
//////
// Format 2 parameters:
//     no return
//     p1			-- Output DATE() variable
//     p2			-- (Optional) YEAR(), nJulian, tDatetime, or sDatetimex to use.
//     p3			-- (Optional) MONTH() to use.
//     p4			-- (Optional) DAY() to use.
//
//////
// Format 1 returns:
//    Date			-- A conversion into the DATE() format.
//
//////
// Format 2 returns:
//    Nothing		-- The source contents of p1 are updated as though it had been passed by reference.
//
//////
// Examples:
//    DBUNDLE(ldDate, 2015, 4, 26)
//    DBUNDLE(ldDate, nJulian)
//    DBUNDLE(ldDate, tDatetime)
//    DBUNDLE(ldDate, sDatetimex)
//
//    ldDate = DBUNDLE(2015, 4, 26)		&& Identical to DATE()
//    ldDate = DBUNDLE(nJulian)
//    ldDate = DBUNDLE(tDatetime)
//    ldDate = DBUNDLE(sDatetimex)
//////
	void function_dbundle(SThisCode* thisCode, SFunctionParms* rpar)
	{
		SVariable*	varR1;
		SVariable*	varP1;
		SVariable*	varP2;
		SVariable*	varP3;

		bool		llCreateResult;
		u32			lnJulian, lnYear, lnMonth, lnDay, lnP1Error, lnP2Error, lnP3Error;
		SYSTEMTIME	lst;
		SVariable*	varResult;
		bool		error;
		u32			errorNum;


		//////////
		// What format are we?
		//////
// TODO:  Need to set the return parameter count so we know what's happening
			rpar->returns[0] = NULL;
			if (rpar->rcount == 1)
			{
				// ldDate = DBUNDLE(p1[, p2][, p3])
				llCreateResult	= true;
				varP1			= rpar->params[0];		// p1
				varP2			= rpar->params[1];		// p2
				varP3			= rpar->params[2];		// p3
				lnP1Error		= _ERROR_P1_IS_INCORRECT;
				lnP2Error		= _ERROR_P2_IS_INCORRECT;
				lnP3Error		= _ERROR_P3_IS_INCORRECT;

			} else {
				// DBUNDLE(r, p1, p2, p3)
				llCreateResult	= false;
				varR1			= rpar->params[0];		// p1
				varP1			= rpar->params[1];		// p2
				varP2			= rpar->params[2];		// p3
				varP3			= rpar->params[3];		// p4
				lnP1Error		= _ERROR_P2_IS_INCORRECT;
				lnP2Error		= _ERROR_P3_IS_INCORRECT;
				lnP3Error		= _ERROR_P4_IS_INCORRECT;
			}


		//////////
		// If we get here, they're bundling on-the-fly
		//////
			// Default to the current date
			if (_settings)		iTime_getLocalOrSystem(&lst, propGet_settings_TimeLocal(_settings));
			else				GetLocalTime(&lst);


		//////////
		// If provided, p1 is the year
		//////
			if (varP1)
			{
				// Validate P1
				validateVariable(varP1, lnP1Error);

				// If they only provided one parameter, we process it differently
				if (rpar->pcount == 2)
				{
					// It must be a julian, datetime, or datetimex
					if (iVariable_isTypeDatetimeX(varP1))
					{
						// DatetimeX
						iiDateMath_get_YyyyMmDdHhMmSsMssNss_from_jseconds(varP1->value.data_dtx->jseconds, NULL, &lnYear, &lnMonth, &lnDay, NULL, NULL, NULL, NULL, NULL);
						lst.wYear	= (u16)lnYear;
						lst.wMonth	= (u16)lnMonth;
						lst.wDay	= (u16)lnDay;

					} else if (iVariable_isTypeDatetime(varP1)) {
						// Datetime
						iiDateMath_get_YyyyMmDd_from_julian(varP1->value.data_dt->julian, &lnYear, &lnMonth, &lnDay);
						lst.wYear	= (u16)lnYear;
						lst.wMonth	= (u16)lnMonth;
						lst.wDay	= (u16)lnDay;

					} else if (iVariable_isTypeNumeric(varP1)) {
						// Julian
						getAs_s32(lnJulian, varP1);

						// When we get here, the year is good
						iiDateMath_get_YyyyMmDd_from_julian(lnJulian, &lnYear, &lnMonth, &lnDay);
						lst.wYear	= (u16)lnYear;
						lst.wMonth	= (u16)lnMonth;
						lst.wDay	= (u16)lnDay;

					} else {
						// Invalid
						iError_reportByNumber(thisCode, lnP1Error, iVariable_getRelatedComp(thisCode, varP1), false);
						return;
					}

				} else {
					// The year must be numeric
					validateNumeric(varP1, lnP1Error);

					// At this point, we know they've given us a number
					getAs_s32(lnYear, varP1);
					
					// It needs to be 1600 <= year <= 9999
					if (lnYear < 1600 || lnYear > 9999)
					{
						iError_reportByNumber(thisCode, _ERROR_OUT_OF_RANGE, iVariable_getRelatedComp(thisCode, varP1), false);
						return;
					}
					// When we get here, the year is good
					lst.wYear = (u16)lnYear;
				}
			}


		//////////
		// If provided, p2 is the month
		//////
			if (varP2)
			{
				// The month must be numeric
				validateVariable(varP2, lnP2Error);
				validateNumeric(varP2, lnP2Error);

				// At this point, we know they've given us a number
				getAs_s32(lnMonth, varP2);
				
				// It needs to be 1 <= month <= 12, and we'll test later the validity of the indicated date
				if (lnMonth < 1 || lnMonth > 12)
				{
					iError_reportByNumber(thisCode, _ERROR_OUT_OF_RANGE, iVariable_getRelatedComp(thisCode, varP2), false);
					return;
				}
				// When we get here, the year is good
				lst.wMonth = (u16)lnMonth;
			}


		//////////
		// If provided, p3 is the day
		//////
			if (varP3)
			{
				// The day must be numeric
				validateVariable(varP3, lnP3Error);
				validateNumeric(varP3, lnP3Error);

				// At this point, we know they've given us a number
				getAs_s32(lnDay, varP3);
				
				// It needs to be 1 <= day <= 31, and we'll test later the validity of the indicated date
				if (lnMonth < 1 || lnMonth > 31)
				{
					iError_reportByNumber(thisCode, _ERROR_OUT_OF_RANGE, iVariable_getRelatedComp(thisCode, varP3), false);
					return;
				}
				// When we get here, the year is good
				lst.wDay = (u16)lnDay;
			}


		//////////
		// Validate the date is valid
		//////
			if (!iDateMath_isValidDate(lst.wYear, lst.wMonth, lst.wDay))
			{
				iError_reportByNumber(thisCode, _ERROR_INVALID_ARGUMENT_TYPE_COUNT, iVariable_getRelatedComp(thisCode, varP1), false);
				return;
			}


		//////////
		// The date is valid, so we can store it to the destination
		//////
			if (llCreateResult)
			{
				// Create our result
				varR1 = iVariable_create(thisCode, _VAR_TYPE_DATE, NULL, true);
				if (!varR1)
				{
					iError_reportByNumber(thisCode, _ERROR_INTERNAL_ERROR, NULL, false);
					return;
				}

			} else {
				// Use whatever's there, and force it into a date type
				if (varR1->varType != _VAR_TYPE_DATE)
					iVariable_setVarType(thisCode, varR1, _VAR_TYPE_DATE);
			}


		//////////
		// Terminate any indirect variable to its source for the update
		//////
			varResult = iiVariable_terminateIndirect(thisCode, varR1);
			if (!varResult->value.data || varResult->value.length == 0)
			{
				iError_reportByNumber(thisCode, _ERROR_INTERNAL_ERROR, iVariable_getRelatedComp(thisCode, varR1), false);
				return;
			}


		//////////
		// Set the date as indicated
		//////
			iiDateMath_get_YYYYMMDD_from_YyyyMmDd(varResult->value.data_s8, (u32)lst.wYear, (u32)lst.wMonth, (u32)lst.wDay);


		//////////
		// No return value in this function
		//////
// TODO:  I am debating create an indirect reference to the varR1 value so that it is returned
			return;

	}




//////////
//
// Function: DUNBUNDLE()
// Disassembles components of a date from a date.
//
//////
// Version 0.57
// Last update:
//     Apr.26.2015
//////
// Change log:
//     Apr.26.2015 - Initial creation by Rick C. Hodgin
//
//////
// Format 1 parameters:
//     r1			-- Output YEAR() variable
//     r2			-- Output MONTH() variable
//     r3			-- Output DAY() variable
//     p1			-- DATE() to use.
//
//////
// Format 2 parameters:
//     no return
//     p1			-- DATE() to use.
//     p2			-- (Optional) Output YEAR() variable
//     p3			-- (Optional) Output MONTH() variable
//     p4			-- (Optional) Output DAY() variable
//
//////
// Format 1 returns:
//    Numeric,Numeric,Numeric	-- A conversion into their numeric components
//
//////
// Format 2 returns:
//    Nothing		-- The source contents of p2,p3,p4 are updated as though they had been passed by reference.
//
//////
// Example:
//    k = DATE()
//    DUNBUNDLE(k, lnYear, lnMonth, lnDay)
//    lnYear, lnMonth, lnDay = DUNBUNDLE(k)
//////
	void function_dunbundle(SThisCode* thisCode, SFunctionParms* rpar)
	{
		iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, NULL, false);
		return;
	}




//////////
//
// Function: TBUNDLE()
// Assembles components of a datetime into a datetime.
// Note:  TBUNDLE() is identical to DATETIME() if a return parameter is specified.
//
//////
// Version 0.57
// Last update:
//     Apr.26.2015
//////
// Change log:
//     Apr.26.2015 - Initial creation by Rick C. Hodgin
//
//////
// Format 1 parameters (identical to DATETIME()):
//     r1			-- Output DATETIME() variable
//     p1			-- (Optional) YEAR() to use
//     p2			-- (Optional) MONTH() to use
//     p3			-- (Optional) DAY() to use
//     p4			-- (Optional) HOUR() to use
//     p5			-- (Optional) MINUTE() to use
//     p6			-- (Optional) SEC() to use
//     p7			-- (Optional) MILLISECOND() to use
//
//////
// Format 2 parameters:
//     no return
//     p1			-- Output DATETIME() variable
//     p2			-- (Optional) YEAR() to use.
//     p3			-- (Optional) MONTH() to use.
//     p4			-- (Optional) DAY() to use.
//     p5			-- (Optional) HOUR() to use
//     p6			-- (Optional) MINUTE() to use
//     p7			-- (Optional) SEC() to use
//     p8			-- (Optional) MILLISECOND() to use
//
//////
// Format 1 returns:
//    Datetime		-- A conversion into the DATETIME() format.
//
//////
// Format 2 returns:
//    Nothing		-- The source contents of p1 are updated as though it had been passed by reference.
//
//////
// Example:
//    TBUNDLE(ltDatetime, 2015, 4, 26, 12, 15, 04, 291)
//    ltDatetime = DBUNDLE(2015, 4, 26, 12, 15, 04, 291)		&& Identical to DATETIME()
//////
	void function_tbundle(SThisCode* thisCode, SFunctionParms* rpar)
	{
		//////////
		// If we get here, they're bundling on-the-fly
		//////
			iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, NULL, false);
			return;
	}




//////////
//
// Function: TUNBUNDLE()
// Disassembles components of a datetime from a datetime.
//
//////
// Version 0.57
// Last update:
//     Apr.26.2015
//////
// Change log:
//     Apr.26.2015 - Initial creation by Rick C. Hodgin
//
//////
// Format 1 parameters:
//     r1			-- Output YEAR() variable
//     r2			-- Output MONTH() variable
//     r3			-- Output DAY() variable
//     r4			-- Output HOUR() variable
//     r5			-- Output MINUTE() variable
//     r6			-- Output SECONDS() variable
//     r7			-- Output MILLISECOND() variable
//     p1			-- DATETIME() to use.
//
//////
// Format 2 parameters:
//     no return
//     p1			-- DATETIME() to use.
//     p2			-- (Optional) Output YEAR() variable
//     p3			-- (Optional) Output MONTH() variable
//     p4			-- (Optional) Output DAY() variable
//     p5			-- (Optional) Output HOUR() variable
//     p6			-- (Optional) Output MINUTE() variable
//     p7			-- (Optional) Output SECONDS() variable
//     p8			-- (Optional) Output MILLISECOND() variable
//
//////
// Format 1 returns:
//    Numeric,Numeric,Numeric,Numeric,Numeric,Numeric,Numeric	-- A conversion into their numeric components
//
//////
// Format 2 returns:
//    Nothing		-- The source contents of p2,p3,p4,p5,p6,p7,p8 are updated as though they had been passed by reference.
//
//////
// Example:
//    k = DATETIME()
//    TUNBUNDLE(k, lnYear, lnMonth, lnDay, lnHour, lnMinute, lnSecond, lnMillisecond)
//    lnYear, lnMonth, lnDay, lnHour, lnMinute, lnSecond, lnMillisecond = TUNBUNDLE(k)
//////
	void function_tunbundle(SThisCode* thisCode, SFunctionParms* rpar)
	{
		iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, NULL, false);
		return;
	}




//////////
//
// Function: XBUNDLE()
// Assembles components of a datetimeX into a datetimeX.
// Note:  XBUNDLE() is identical to DATETIMEX() if a return parameter is specified.
//
//////
// Version 0.57
// Last update:
//     Apr.26.2015
//////
// Change log:
//     Apr.26.2015 - Initial creation by Rick C. Hodgin
//
//////
// Format 1 parameters (identical to DATETIMEX()):
//     r1			-- Output DATETIME() variable
//     p1			-- (Optional) YEAR() to use
//     p2			-- (Optional) MONTH() to use
//     p3			-- (Optional) DAY() to use
//     p4			-- (Optional) HOUR() to use
//     p5			-- (Optional) MINUTE() to use
//     p6			-- (Optional) SEC() to use
//     p7			-- (Optional) MILLISECOND() to use
//     p8			-- (Optional) MICROSECOND() to use
//
//////
// Format 2 parameters:
//     no return
//     p1			-- Output DATETIME() variable
//     p2			-- (Optional) YEAR() to use.
//     p3			-- (Optional) MONTH() to use.
//     p4			-- (Optional) DAY() to use.
//     p5			-- (Optional) HOUR() to use
//     p6			-- (Optional) MINUTE() to use
//     p7			-- (Optional) SEC() to use
//     p8			-- (Optional) MILLISECOND() to use
//     p9			-- (Optional) MICROSECOND() to use
//
//////
// Format 1 returns:
//    DatetimeX		-- A conversion into the DATETIMEX() format.
//
//////
// Format 2 returns:
//    Nothing		-- The source contents of p1 are updated as though it had been passed by reference.
//
//////
// Example:
//    XBUNDLE(lsDatetime, 2015, 4, 26, 12, 15, 04, 291, 291393)
//    lsDatetimex = XBUNDLE(2015, 4, 26, 12, 15, 04, 291, 291393)		&& Identical to DATETIMEX()
//////
	void function_xbundle(SThisCode* thisCode, SFunctionParms* rpar)
	{
		//////////
		// If we get here, they're bundling on-the-fly
		//////
			iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, NULL, false);
			return;
	}




//////////
//
// Function: XUNBUNDLE()
// Disassembles components of a datetimex from a datetimex.
//
//////
// Version 0.57
// Last update:
//     Apr.26.2015
//////
// Change log:
//     Apr.26.2015 - Initial creation by Rick C. Hodgin
//
//////
// Format 1 parameters:
//     r1			-- Output YEAR() variable
//     r2			-- Output MONTH() variable
//     r3			-- Output DAY() variable
//     r4			-- Output HOUR() variable
//     r5			-- Output MINUTE() variable
//     r6			-- Output SECONDS() variable
//     r7			-- Output MILLISECOND() variable
//     r8			-- Output MICROSECOND() variable
//     p1			-- DATETIME() to use.
//
//////
// Format 2 parameters:
//     no return
//     p1			-- DATETIME() to use.
//     p2			-- (Optional) Output YEAR() variable
//     p3			-- (Optional) Output MONTH() variable
//     p4			-- (Optional) Output DAY() variable
//     p5			-- (Optional) Output HOUR() variable
//     p6			-- (Optional) Output MINUTE() variable
//     p7			-- (Optional) Output SECONDS() variable
//     p8			-- (Optional) Output MILLISECOND() variable
//     p9			-- (Optional) Output MICROSECOND() variable
//
//////
// Format 1 returns:
//    Numeric,Numeric,Numeric,Numeric,Numeric,Numeric,Numeric,Numeric	-- A conversion into their numeric components
//
//////
// Format 2 returns:
//    Nothing		-- The source contents of p2,p3,p4,p5,p6,p7,p8,p9 are updated as though they had been passed by reference.
//
//////
// Example:
//    k = DATETIMEX()
//    XUNBUNDLE(k, lnYear, lnMonth, lnDay, lnHour, lnMinute, lnSecond, lnMillisecond, lnMicrosecond)
//    lnYear, lnMonth, lnDay, lnHour, lnMinute, lnSecond, lnMillisecond, lnMicrosecond = XUNBUNDLE(k)
//////
	void function_xunbundle(SThisCode* thisCode, SFunctionParms* rpar)
	{
		iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, NULL, false);
		return;
	}




//////////
//
// Function: TIMEBUNDLE()
// Assembles components of a time into a time.
//
//////
// Version 0.57
// Last update:
//     Apr.26.2015
//////
// Change log:
//     Apr.26.2015 - Initial creation by Rick C. Hodgin
//
//////
// Format 1 parameters:
//     r1			-- Output TIME() variable
//     p1			-- (Optional) HOUR() to use
//     p2			-- (Optional) MINUTE() to use
//     p3			-- (Optional) SEC() to use
//     p4			-- (Optional) MILLISECOND() to use
//
//////
// Format 2 parameters:
//     no return
//     p1			-- Output TIME() variable
//     p2			-- (Optional) HOUR() to use
//     p3			-- (Optional) MINUTE() to use
//     p4			-- (Optional) SEC() to use
//     p5			-- (Optional) MILLISECOND() to use
//
//////
// Format 1 returns:
//    Character		-- A conversion into the TIME() format.
//
//////
// Format 2 returns:
//    Nothing		-- The source contents of p1 are updated as though it had been passed by reference.
//
//////
// Example:
//    TIMEBUNDLE(lcTime, 12, 15, 04, 291)
//    lcTime = TIMEBUNDLE(12, 15, 04, 291)
//////
	void function_timebundle(SThisCode* thisCode, SFunctionParms* rpar)
	{
		iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, NULL, false);
		return;
	}




//////////
//
// Function: TIMEUNBUNDLE()
// Disassembles components of a time from a time.
//
//////
// Version 0.57
// Last update:
//     Apr.26.2015
//////
// Change log:
//     Apr.26.2015 - Initial creation by Rick C. Hodgin
//
//////
// Format 1 parameters:
//     r1			-- Output HOUR() variable
//     r2			-- Output MINUTE() variable
//     r3			-- Output SECONDS() variable
//     r4			-- Output MILLISECOND() variable
//     p1			-- TIME() to use.
//
//////
// Format 2 parameters:
//     no return
//     p1			-- TIME() to use.
//     p2			-- (Optional) Output HOUR() variable
//     p3			-- (Optional) Output MINUTE() variable
//     p4			-- (Optional) Output SECONDS() variable
//     p5			-- (Optional) Output MILLISECOND() variable
//
//////
// Format 1 returns:
//    Numeric,Numeric,Numeric,Numeric	-- A conversion into their numeric components
//
//////
// Format 2 returns:
//    Nothing		-- The source contents of p2,p3,p4,p5 are updated as though they had been passed by reference.
//
//////
// Example:
//    k = TIME(.t.)
//    TIMEUNBUNDLE(k, lnHour, lnMinute, lnSecond, lnMillisecond)
//    lnHour, lnMinute, lnSecond, lnMillisecond = TIMEUNBUNDLE(k)
//////
	void function_timeunbundle(SThisCode* thisCode, SFunctionParms* rpar)
	{
		iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, NULL, false);
		return;
	}




//////////
//
// Function: TIMEXBUNDLE()
// Assembles components of a timex into a timex.
//
//////
// Version 0.57
// Last update:
//     Apr.26.2015
//////
// Change log:
//     Apr.26.2015 - Initial creation by Rick C. Hodgin
//
//////
// Format 1 parameters:
//     r1			-- Output TIMEX() variable
//     p1			-- (Optional) HOUR() to use
//     p2			-- (Optional) MINUTE() to use
//     p3			-- (Optional) SEC() to use
//     p4			-- (Optional) MILLISECOND() to use
//     p5			-- (Optional) MICROSECOND() to use
//
//////
// Format 2 parameters:
//     no return
//     p1			-- Output TIMEX() variable
//     p2			-- (Optional) HOUR() to use
//     p3			-- (Optional) MINUTE() to use
//     p4			-- (Optional) SEC() to use
//     p5			-- (Optional) MILLISECOND() to use
//     p6			-- (Optional) MICROSECOND() to use
//
//////
// Format 1 returns:
//    Character		-- A conversion into the TIMEX() format.
//
//////
// Format 2 returns:
//    Nothing		-- The source contents of p1 are updated as though it had been passed by reference.
//
//////
// Example:
//    TIMEXBUNDLE(lcTime, 12, 15, 04, 291, 291393)
//    lcTime = TIMEXBUNDLE(12, 15, 04, 291, 291393)
//////
	void function_timexbundle(SThisCode* thisCode, SFunctionParms* rpar)
	{
		iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, NULL, false);
		return;
	}




//////////
//
// Function: TIMEXUNBUNDLE()
// Disassembles components of a timex from a timex.
//
//////
// Version 0.57
// Last update:
//     Apr.26.2015
//////
// Change log:
//     Apr.26.2015 - Initial creation by Rick C. Hodgin
//
//////
// Format 1 parameters:
//     r1			-- Output HOUR() variable
//     r2			-- Output MINUTE() variable
//     r3			-- Output SECONDS() variable
//     r4			-- Output MILLISECOND() variable
//     r5			-- Output MICROSECOND() variable
//     p1			-- TIMEX() to use.
//
//////
// Format 2 parameters:
//     no return
//     p1			-- TIMEX() to use.
//     p2			-- (Optional) Output HOUR() variable
//     p3			-- (Optional) Output MINUTE() variable
//     p4			-- (Optional) Output SECONDS() variable
//     p5			-- (Optional) Output MILLISECOND() variable
//     p6			-- (Optional) Output MICROSECOND() variable
//
//////
// Format 1 returns:
//    Numeric,Numeric,Numeric,Numeric,Numeric	-- A conversion into their numeric components
//
//////
// Format 2 returns:
//    Nothing		-- The source contents of p2,p3,p4,p5,p6 are updated as though they had been passed by reference.
//
//////
// Example:
//    k = TIMEX()
//    TIMEXUNBUNDLE(k, lnHour, lnMinute, lnSecond, lnMillisecond, lnMicrosecond)
//    lnHour, lnMinute, lnSecond, lnMillisecond, lnMicrosecond = TIMEXUNBUNDLE(k)
//////
	void function_timexunbundle(SThisCode* thisCode, SFunctionParms* rpar)
	{
		iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, NULL, false);
		return;
	}




//////////
//
// Function: SECONDSBUNDLE()
// Assembles components of a time into a seconds.
//
//////
// Version 0.57
// Last update:
//     Apr.26.2015
//////
// Change log:
//     Apr.26.2015 - Initial creation by Rick C. Hodgin
//
//////
// Format 1 parameters:
//     r1			-- Output SECONDS() variable
//     p1			-- (Optional) HOUR() to use
//     p2			-- (Optional) MINUTE() to use
//     p3			-- (Optional) SEC() to use
//     p4			-- (Optional) MILLISECOND() to use
//
//////
// Format 2 parameters:
//     no return
//     p1			-- Output SECONDS() variable
//     p2			-- (Optional) HOUR() to use
//     p3			-- (Optional) MINUTE() to use
//     p4			-- (Optional) SEC() to use
//     p5			-- (Optional) MILLISECOND() to use
//
//////
// Format 1 returns:
//    f64			-- A 64-bit floating point conversion into the SECONDS() format.
//
//////
// Format 2 returns:
//    Nothing		-- The source contents of p1 are updated as though it had been passed by reference.
//
//////
// Example:
//    SECONDSBUNDLE(lfTime, 12, 15, 04, 291)
//    lfTime = SECONDSBUNDLE(12, 15, 04, 291)
//////
	void function_secondsbundle(SThisCode* thisCode, SFunctionParms* rpar)
	{
		iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, NULL, false);
		return;
	}




//////////
//
// Function: SECONDSUNBUNDLE()
// Disassembles components of a time from a seconds.
//
//////
// Version 0.57
// Last update:
//     Apr.26.2015
//////
// Change log:
//     Apr.26.2015 - Initial creation by Rick C. Hodgin
//
//////
// Format 1 parameters:
//     r1			-- Output HOUR() variable
//     r2			-- Output MINUTE() variable
//     r3			-- Output SECONDS() variable
//     r4			-- Output MILLISECOND() variable
//     p1			-- SECONDS() to use.
//
//////
// Format 2 parameters:
//     no return
//     p1			-- SECONDS() to use.
//     p2			-- (Optional) Output HOUR() variable
//     p3			-- (Optional) Output MINUTE() variable
//     p4			-- (Optional) Output SECONDS() variable
//     p5			-- (Optional) Output MILLISECOND() variable
//
//////
// Format 1 returns:
//    Numeric,Numeric,Numeric,Numeric	-- A conversion into their numeric components
//
//////
// Format 2 returns:
//    Nothing		-- The source contents of p2,p3,p4,p5 are updated as though they had been passed by reference.
//
//////
// Example:
//    k = SECONDS()
//    SECONDSUNBUNDLE(k, lnHour, lnMinute, lnSecond, lnMillisecond)
//    lnHour, lnMinute, lnSecond, lnMillisecond = SECONDSUNBUNDLE(k)
//////
	void function_secondsunbundle(SThisCode* thisCode, SFunctionParms* rpar)
	{
		iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, NULL, false);
		return;
	}




//////////
//
// Function: SECONDSXBUNDLE()
// Assembles components of a timex into a secondsx.
//
//////
// Version 0.57
// Last update:
//     Apr.26.2015
//////
// Change log:
//     Apr.26.2015 - Initial creation by Rick C. Hodgin
//
//////
// Format 1 parameters:
//     r1			-- Output SECONDSX() variable
//     p1			-- (Optional) HOUR() to use
//     p2			-- (Optional) MINUTE() to use
//     p3			-- (Optional) SEC() to use
//     p4			-- (Optional) MILLISECOND() to use
//     p5			-- (Optional) MICROSECOND() to use
//
//////
// Format 2 parameters:
//     no return
//     p1			-- Output SECONDSX() variable
//     p2			-- (Optional) HOUR() to use
//     p3			-- (Optional) MINUTE() to use
//     p4			-- (Optional) SEC() to use
//     p5			-- (Optional) MILLISECOND() to use
//     p6			-- (Optional) MICROSECOND() to use
//
//////
// Format 1 returns:
//    f64			-- A 64-bit floating point conversion into the SECONDSX() format.
//
//////
// Format 2 returns:
//    Nothing		-- The source contents of p1 are updated as though it had been passed by reference.
//
//////
// Example:
//    SECONDSXBUNDLE(lfTime, 12, 15, 04, 291, 291393)
//    lfTime = SECONDSXBUNDLE(12, 15, 04, 291, 291393)
//////
	void function_secondsxbundle(SThisCode* thisCode, SFunctionParms* rpar)
	{
		iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, NULL, false);
		return;
	}




//////////
//
// Function: SECONDSXUNBUNDLE()
// Disassembles components of a timex from a secondsx.
//
//////
// Version 0.57
// Last update:
//     Apr.26.2015
//////
// Change log:
//     Apr.26.2015 - Initial creation by Rick C. Hodgin
//
//////
// Format 1 parameters:
//     r1			-- Output HOUR() variable
//     r2			-- Output MINUTE() variable
//     r3			-- Output SECONDS() variable
//     r4			-- Output MILLISECOND() variable
//     r5			-- Output MICROSECOND() variable
//     p1			-- SECONDSX() to use.
//
//////
// Format 2 parameters:
//     no return
//     p1			-- SECONDSX() to use.
//     p2			-- (Optional) Output HOUR() variable
//     p3			-- (Optional) Output MINUTE() variable
//     p4			-- (Optional) Output SECONDS() variable
//     p5			-- (Optional) Output MILLISECOND() variable
//     p6			-- (Optional) Output MICROSECOND() variable
//
//////
// Format 1 returns:
//    Numeric,Numeric,Numeric,Numeric,Numeric	-- A conversion into their numeric components
//
//////
// Format 2 returns:
//    Nothing		-- The source contents of p2,p3,p4,p5,p6 are updated as though they had been passed by reference.
//
//////
// Example:
//    k = SECONDSX()
//    SECONDSXUNBUNDLE(k, lnHour, lnMinute, lnSecond, lnMillisecond, lnMicrosecond)
//    lnHour, lnMinute, lnSecond, lnMillisecond, lnMicrosecond = SECONDSXUNBUNDLE(k)
//////
	void function_secondsxunbundle(SThisCode* thisCode, SFunctionParms* rpar)
	{
		iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, NULL, false);
		return;
	}
