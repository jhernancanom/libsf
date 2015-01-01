//////////
//
// /libsf/source/vjr/source/engine.h
//
//////
// Version 0.55
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
//




//////////
// Constants for .T. and .F. settings using LOGICALX()
//
//////
	const u32	_LOGICAL_TF						= 1;
	const u32	_LOGICAL_YN						= 2;
	const u32	_LOGICAL_UD						= 3;


//////////
// Constants for date formats
//////
	const u32	_SET_DATE_AMERICAN				= 1;			// mm/dd/yy
	const u32	_SET_DATE_ANSI					= 2;			// yy.mm.dd
	const u32	_SET_DATE_BRITISH				= 3;			// dd/mm/yy
	const u32	_SET_DATE_FRENCH				= 4;			// dd/mm/yy
	const u32	_SET_DATE_GERMAN				= 5;			// dd.mm.yy
	const u32	_SET_DATE_ITALIAN				= 6;			// dd-mm-yy
	const u32	_SET_DATE_JAPAN					= 7;			// yy/mm/dd
	const u32	_SET_DATE_TAIWAN				= 8;			// yy/mm/dd
	const u32	_SET_DATE_LONG					= 9;			// Dayofweek, Month dd, yyyy
	const u32	_SET_DATE_SHORT					= 10;			// m/d/yy
	const u32	_SET_DATE_USA					= 11;			// mm-dd-yy
	const u32	_SET_DATE_DMY					= 12;			// dd/mm/yy
	const u32	_SET_DATE_MDY					= 13;			// mm/dd/yy
	const u32	_SET_DATE_YMD					= 14;			// yy/mm/dd


//////////
// SET settings. :-)
// http://www.visual-freepro.org/wiki/index.php/VFrP_changes#SET_Options
//////
	struct SSettings
	{
		SLL			ll;

		// Settings at this level
		bool		_set_autoConvert;
		bool		_set_caseSensitiveCompares;
		bool		_set_caseSensitiveNames;
		bool		_set_century;
		s32			_set_date;
		s32			_set_decimals;
		bool		_set_exclusive;
		s32			_set_focus_highlight_border_pixels;
		s32			_set_focus_highlight_pixels;
		bool		_set_honorBarriers;
		bool		_set_implicitParams;
		bool		_set_indexMetaData;
		SDatum		_set_languageTo;
		s32			_set_logical;
		bool		_set_namingConventions;
		bool		_set_sloppyPrinting;
		bool		_set_stickyParameters;
		bool		_set_tableEqualAssignments;
		bool		_set_tableObjects;
		bool		_set_variablesFirst;

		// Default variable type for uninitialized variables
		s32			_set_initializeDefault;
		SVariable*	varInitializeDefault_value;
	};
	// First entry
	SSettings* gsFirstSettings								= NULL;
	SSettings* gsCurrentSetting								= NULL;


//////////
// Forward declarations
//////
	bool					iEngine_executeStandaloneCommand		(SLine* line);
	SComp*					iEngine_parseSourceCodeLine				(SLine* line);
	SVariable*				iEngine_get_variableName_fromComponent	(SComp* comp, bool* tlManufactured);
	SVariable*				iEngine_get_contiguousComponents		(SComp* comp, bool* tlManufactured, s32 valid_iCodeArray[], s32 tnValid_iCodeArrayCount);
	SVariable*				iEngine_get_functionResult				(SComp* comp);
	void					iEngine_executeSetter					(cs8* name, SVariable* varOld, SVariable* varNew);
	void					iEngine_executeSetter					(s8*  name, SVariable* varOld, SVariable* varNew);
	void					iEngine_error							(u32 tnErrorNumber, SVariable* varRelated);
	bool					iiEngine_getParametersBetween			(SComp* compLeftParen, u32* paramsFound, u32 requiredCount, u32 maxCount, SVariable** p1, SVariable** p2, SVariable** p3, SVariable** p4, SVariable** p5, SVariable** p6, SVariable** p7);

	SSettings*				iSettings_push							(void);
	SSettings*				iSettings_pop							(void);

	void					iBreakpoint_delete						(SBreakpoint** breakpoint);
	SBreakpoint* 			iBreakpoint_add							(SBreakpoint** breakpoint, u32 tnType);

	void					iSourceCode_delete						(SSourceCode** sourceCode);