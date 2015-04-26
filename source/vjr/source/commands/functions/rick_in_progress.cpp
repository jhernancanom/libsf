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
// Function: TIMETOSECONDS()
// Converts a TIME() into a SECONDS().
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
//     p1			-- Character, in the format of TIME()
//
//////
// Returns:
//    f64			-- A 64-bit floating point of the equivalent SECONDS().
//////
// Example:
//    k = TIME()
//    ? TIMETOSECONDS(k)
//////
	SVariable* function_timetoseconds(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, NULL, false);
		return(NULL);
	}




//////////
//
// Function: TIMEXTOSECONDS()
// Converts a TIMEX() into a SECONDS().
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
//     p1			-- Character, in the format of TIMEX()
//
//////
// Returns:
//    f64			-- A 64-bit floating point of the equivalent SECONDS().
//////
// Example:
//    k = TIMEX()
//    ? TIMEXTOSECONDS(k)
//////
	SVariable* function_timextoseconds(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, NULL, false);
		return(NULL);
	}




//////////
//
// Function: TIMEXTOSECONDSX()
// Converts a TIMEX() into a SECONDSX().
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
//     p1			-- Character, in the format of TIMEX()
//
//////
// Returns:
//    f64			-- A 64-bit floating point of the equivalent SECONDSX().
//////
// Example:
//    k = TIMEX()
//    ? TIMEXTOSECONDSX(k)
//////
	SVariable* function_timextosecondsx(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, NULL, false);
		return(NULL);
	}




//////////
//
// Function: SECONDSTOTIME()
// Converts a SECONDS() into a TIME().
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
//     p1			-- Numeric or floating point
//
//////
// Returns:
//    Character		-- Equivalent of SECONDS() as a TIME()
//////
// Example:
//    k = SECONDS()
//    ? SECONDSTOTIME(k)
//////
	SVariable* function_secondstotime(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, NULL, false);
		return(NULL);
	}




//////////
//
// Function: SECONDSTOTIMEX()
// Converts a SECONDS() into a TIMEX().
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
//     p1			-- Numeric or floating point
//
//////
// Returns:
//    Character		-- Equivalent of SECONDS() as a TIMEX()
//////
// Example:
//    k = SECONDS()
//    ? SECONDSTOTIMEX(k)
//////
	SVariable* function_secondstotimex(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, NULL, false);
		return(NULL);
	}




//////////
//
// Function: SECONDSXTOTIMEX()
// Converts a SECONDSX() into a TIMEX().
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
//     p1			-- Numeric or floating point
//
//////
// Returns:
//    Character		-- Equivalent of SECONDSX() as a TIMEX()
//////
// Example:
//    k = SECONDSX()
//    ? SECONDSTOTIMEX(k)
//////
	SVariable* function_secondsxtotimex(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, NULL, false);
		return(NULL);
	}




//////////
//
// Function: TTOSECONDS()
// Converts a DATETIME() into a SECONDS().
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
//     p1			-- Datetime or DatetimeX
//
//////
// Returns:
//    f64			-- A 64-bit floating point number equivalent to the SECONDS() component
//////
// Example:
//    k = DATETIME()
//    ? TTOSECONDS(k)
//////
	SVariable* function_ttoseconds(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, NULL, false);
		return(NULL);
	}




//////////
//
// Function: TTOSECONDSX()
// Converts a DATETIME() into a SECONDSX().
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
//     p1			-- Datetime or DatetimeX
//
//////
// Returns:
//    f64			-- A 64-bit floating point number equivalent to the SECONDSX() component
//////
// Example:
//    k = DATETIME()
//    ? TTOSECONDSX(k)
//////
	SVariable* function_ttosecondsx(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, NULL, false);
		return(NULL);
	}




//////////
//
// Function: TTOTIME()
// Converts a DATETIME() into a TIME().
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
//     p1			-- Datetime or DatetimeX
//
//////
// Returns:
//    Character		-- A conversion into the TIME() format.
//////
// Example:
//    k = DATETIME()
//    ? TTOTIME(k)
//////
	SVariable* function_ttotime(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, NULL, false);
		return(NULL);
	}




//////////
//
// Function: TTOTIMEX()
// Converts a DATETIME() into a TIMEX().
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
//     p1			-- Datetime or DatetimeX
//
//////
// Returns:
//    Character		-- A conversion into the TIMEX() format.
//////
// Example:
//    k = DATETIME()
//    ? TTOTIMEX(k)
//////
	SVariable* function_ttotimex(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, NULL, false);
		return(NULL);
	}




//////////
//
// Function: XTOSECONDS()
// Converts a DATETIMEX() into a SECONDS().
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
//     p1			-- DatetimeX
//
//////
// Returns:
//    Character		-- A conversion into the SECONDS() format.
//////
// Example:
//    k = DATETIMEX()
//    ? XTOSECONDS(k)
//////
	SVariable* function_xtoseconds(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, NULL, false);
		return(NULL);
	}




//////////
//
// Function: XTOSECONDSX()
// Converts a DATETIMEX() into a SECONDSX().
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
//     p1			-- DatetimeX
//
//////
// Returns:
//    Character		-- A conversion into the SECONDSX() format.
//////
// Example:
//    k = DATETIMEX()
//    ? XTOSECONDSX(k)
//////
	SVariable* function_xtosecondsx(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, NULL, false);
		return(NULL);
	}




//////////
//
// Function: XTOTIME()
// Converts a DATETIMEX() into a TIME().
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
//     p1			-- DatetimeX
//
//////
// Returns:
//    Character		-- A conversion into the TIME() format.
//////
// Example:
//    k = DATETIMEX()
//    ? XTOTIME(k)
//////
	SVariable* function_xtotime(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, NULL, false);
		return(NULL);
	}




//////////
//
// Function: XTOTIMEX()
// Converts a DATETIMEX() into a TIMEX().
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
//     p1			-- DatetimeX
//
//////
// Returns:
//    Character		-- A conversion into the TIMEX() format.
//////
// Example:
//    k = DATETIMEX()
//    ? XTOTIMEX(k)
//////
	SVariable* function_xtotimex(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, NULL, false);
		return(NULL);
	}




//////////
//
// Function: DTOX()
// Converts a DATE() into a DATETIMEX().
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
//     p1			-- Date
//
//////
// Returns:
//    DatetimeX		-- A conversion into the DATETIMEX() format.
//////
// Example:
//    k = DATE()
//    ? DTOX(k)
//////
	SVariable* function_dtox(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, NULL, false);
		return(NULL);
	}




//////////
//
// Function: TTOX()
// Converts a DATETIME() into a DATETIMEX().
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
//     p1			-- Datetime
//
//////
// Returns:
//    DatetimeX		-- A conversion into the DATETIMEX() format.
//////
// Example:
//    k = DATETIME()
//    ? TTOX(k)
//////
	SVariable* function_ttox(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, NULL, false);
		return(NULL);
	}




//////////
//
// Function: XTOD()
// Converts a DATETIMEX() into a DATE().
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
//     p1			-- DatetimeX
//
//////
// Returns:
//    Date			-- A conversion into the DATE() format.
//////
// Example:
//    k = DATETIMEX()
//    ? XTOD(k)
//////
	SVariable* function_xtod(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, NULL, false);
		return(NULL);
	}




//////////
//
// Function: XTOT()
// Converts a DATETIMEX() into a DATETIME().
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
//     p1			-- Datetime
//
//////
// Returns:
//    Datetime		-- A conversion into the DATETIME() format.
//////
// Example:
//    k = DATETIMEX()
//    ? XTOT(k)
//////
	SVariable* function_xtot(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, NULL, false);
		return(NULL);
	}




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
	SVariable* function_cxlatd(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, NULL, false);
		return(NULL);
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
	SVariable* function_cxlatt(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, NULL, false);
		return(NULL);
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
	SVariable* function_cxlatx(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, NULL, false);
		return(NULL);
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
//     p1			-- (Optional) YEAR() to use.
//     p2			-- (Optional) MONTH() to use.
//     p3			-- (Optional) DAY() to use.
//
//////
// Format 2 parameters:
//     no return
//     p1			-- Output DATE() variable
//     p2			-- (Optional) YEAR() to use.
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
// Example:
//    DBUNDLE(ldDate, 2015, 4, 26)
//    ldDate = DBUNDLE(2015, 4, 26)		&& Identical to DATE()
//////
	SVariable* function_dbundle(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		//////////
		// If it's ldDate = DBUNDLE(lnYear, lnMonth, lnDay), then it's the same as DATE()
		//////
			if (returnsParams->rcount == 1)
				return(function_date(thisCode, returnsParams));


		//////////
		// If we get here, they're bundling on-the-fly
		//////
			iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, NULL, false);
			return(NULL);
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
	SVariable* function_dunbundle(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, NULL, false);
		return(NULL);
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
	SVariable* function_tbundle(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		//////////
		// If it's lsDatetime = TBUNDLE(lnYear, lnMonth, lnDay, lnHour, lnMinute, lnSecond, lnMillisecond), then it's the same as DATETIME()
		//////
			if (returnsParams->rcount == 1)
				return(function_date(thisCode, returnsParams));


		//////////
		// If we get here, they're bundling on-the-fly
		//////
			iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, NULL, false);
			return(NULL);
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
	SVariable* function_tunbundle(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, NULL, false);
		return(NULL);
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
	SVariable* function_xbundle(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		//////////
		// If it's lsDatetime = TBUNDLE(lnYear, lnMonth, lnDay, lnHour, lnMinute, lnSecond, lnMillisecond), then it's the same as DATETIME()
		//////
			if (returnsParams->rcount == 1)
				return(function_date(thisCode, returnsParams));


		//////////
		// If we get here, they're bundling on-the-fly
		//////
			iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, NULL, false);
			return(NULL);
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
	SVariable* function_xunbundle(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, NULL, false);
		return(NULL);
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
	SVariable* function_timebundle(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, NULL, false);
		return(NULL);
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
	SVariable* function_timeunbundle(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, NULL, false);
		return(NULL);
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
	SVariable* function_timexbundle(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, NULL, false);
		return(NULL);
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
	SVariable* function_timexunbundle(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, NULL, false);
		return(NULL);
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
	SVariable* function_secondsbundle(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, NULL, false);
		return(NULL);
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
	SVariable* function_secondsunbundle(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, NULL, false);
		return(NULL);
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
	SVariable* function_secondsxbundle(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, NULL, false);
		return(NULL);
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
	SVariable* function_secondsxunbundle(SThisCode* thisCode, SReturnsParams* returnsParams)
	{
		iError_reportByNumber(thisCode, _ERROR_FEATURE_NOT_AVAILABLE, NULL, false);
		return(NULL);
	}
