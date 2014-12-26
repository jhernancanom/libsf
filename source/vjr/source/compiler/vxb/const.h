//////////
//
// /libsf/source/vjr/source/compiler/vxb/const.h
//
//////
// Version 0.54
// Copyright (c) 2014 by Rick C. Hodgin
//////
// Last update:
//     Jun.29.2014
//////
// Change log:
//     Jun.29.2014 - Initial creation
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
// Known operators to the system
//////
	const u32		_SUB_INSTR_ADD									= 1;			// Pattern of x + y
	const u32		_SUB_INSTR_SUBTRACT								= 2;			// Pattern of x - y
	const u32		_SUB_INSTR_MULTIPLY								= 3;			// Pattern of x * y
	const u32		_SUB_INSTR_DIVIDE								= 4;			// Pattern of x / y
	const u32		_SUB_INSTR_MODULO								= 5;			// Pattern of x % y
	const u32		_SUB_INSTR_EXPONENT								= 6;			// Pattern of x^y or x**y
	const u32		_SUB_INSTR_FUNCTION								= 7;			// Pattern of xyz(....)
	const u32		_SUB_INSTR_ARRAY								= 8;			// Pattern of array[...]
	const u32		_SUB_INSTR_PLUS_PLUS_X							= 9;			// Pattern of ++x (increment, then get value)
	const u32		_SUB_INSTR_X_PLUS_PLUS							= 10;			// Pattern of x++ (get value, then increment)
	const u32		_SUB_INSTR_MINUS_MINUS_X						= 11;			// Pattern of --x (decrement, then get value)
	const u32		_SUB_INSTR_X_MINUS_MINUS						= 12;			// Pattern of x-- (get value, then decrement)
	const u32		_SUB_INSTR_AND									= 13;			// Pattern of x AND y
	const u32		_SUB_INSTR_OR									= 14;			// Pattern of x OR y
	const u32		_SUB_INSTR_NOT									= 15;			// Pattern of NOT x
	const u32		_SUB_INSTR_DOT_EXPANSION						= 16;			// Pattern of x.y
	const u32		_SUB_INSTR_EXCLAMATION_MARK_EXPANSION			= 17;			// Pattern of x!y
	const u32		_SUB_INSTR_LESS_THAN							= 18;			// Pattern of x < y
	const u32		_SUB_INSTR_GREATER_THAN							= 19;			// Pattern of x > y
	const u32		_SUB_INSTR_LESS_THAN_OR_EQUAL_TO				= 20;			// Pattern of x <= y
	const u32		_SUB_INSTR_GREATER_THAN_OR_EQUAL_TO				= 21;			// Pattern of x >= y
	const u32		_SUB_INSTR_NOT_EQUAL_TO							= 22;			// Pattern of x != y
	const u32		_SUB_INSTR_EQUAL_TO								= 23;			// Pattern of x = y
	const u32		_SUB_INSTR_EXACTLY_EQUAL_TO						= 24;			// Pattern of x == y
	const u32		_SUB_INSTR_FOUND_IN								= 25;			// Pattern of x $ y
	const u32		_SUB_INSTR_NOT_FOUND_IN							= 26;			// Pattern of x !$ y
	const u32		_SUB_INSTR_ERROR								= 1000;			// An error was encountered and we stop at this source code line
	const u32		_SUB_INSTR_FLAGS								= 1001;			// A flag was given for this line

	const u32		_OP_TYPE_NULL									= 0;			// A NULL type, indicating a compile error occurred on this control
	const u32		_OP_TYPE_COMP									= 1;			// A component
	const u32		_OP_TYPE_PARAM									= 2;			// A parameter
	const u32		_OP_TYPE_LOCAL									= 3;			// A local variable
	const u32		_OP_TYPE_SCOPED									= 4;			// A scoped / temporary variable
	const u32		_OP_TYPE_RETURNS								= 5;			// A returns variable
	const u32		_OP_TYPE_OTHER									= 6;			// Some other variable which is always referenced
	const u32		_OP_TYPE_FUNCTION								= 7;			// A function
	const u32		_OP_TYPE_OBJECT									= 8;			// An object
	const u32		_OP_TYPE_PARENTHESIS_LEFT						= 9;			// (Temporary) A left parenthesis

	const u32		_NODE_NONE										= 0;
	const u32		_NODE_PARENT									= 1;
	const u32		_NODE_PREV										= 2;
	const u32		_NODE_NEXT										= 3;
	const u32		_NODE_LEFT										= 4;
	const u32		_NODE_RIGHT										= 5;

	const u32		_VAR_TYPE_NULL									= 0;
	const u32		_VAR_TYPE_OBJECT								= 1;			// Object reference
	const u32		_VAR_TYPE_THISCODE								= 2;			// Code reference
	const u32		_VAR_TYPE_CHARACTER								= 3;
	const u32								_VAR_TYPE_NUMERIC_START	= 4;
//	const u32		_VAR_TYPE_INTEGER								= 4;			// Stored as an s32, a 4-byte signed integer
	const u32		_VAR_TYPE_NUMERIC								= 5;			// Stored as a character (like "200.50"), but converted to numeric at each reference.
//	const u32		_VAR_TYPE_FLOAT									= 6;			// Stored as an f32
//	const u32		_VAR_TYPE_DOUBLE								= 7;			// Stored as an f64
	const u32		_VAR_TYPE_CURRENCY								= 8;			// Stored as an s64 with an implied 4-decimals (divide by 10,000 to get the actual floating point value)
	const u32		_VAR_TYPE_S32									= 9;
	const u32		_VAR_TYPE_S64									= 10;
	const u32		_VAR_TYPE_U32									= 11;
	const u32		_VAR_TYPE_U64									= 12;
	const u32		_VAR_TYPE_F32									= 13;
	const u32		_VAR_TYPE_F64									= 14;
	const u32		_VAR_TYPE_BI									= 15;			// Uses the big number library for integers
	const u32		_VAR_TYPE_BFP									= 16;			// Uses the big number library for floating points
	const u32		_VAR_TYPE_S16									= 17;
	const u32		_VAR_TYPE_S8									= 18;
	const u32		_VAR_TYPE_U16									= 19;
	const u32		_VAR_TYPE_U8									= 20;
	const u32								_VAR_TYPE_NUMERIC_END	= 20;
	const u32		_VAR_TYPE_DATE									= 21;
	const u32		_VAR_TYPE_DATETIME								= 22;
	const u32		_VAR_TYPE_LOGICAL								= 23;			// Note:  This includes the logicalx types, but the value stored determines the logicalx setting.
	const u32		_VAR_TYPE_BITMAP								= 24;
// TODO:  Not yet implemented
	const u32		_VAR_TYPE_DATETIMEX								= 25;
	const u32		_VAR_TYPE_ARRAY									= 26;
	const u32		_VAR_TYPE_GUID8									= 27;
	const u32		_VAR_TYPE_GUID16								= 28;
	const u32		_VAR_TYPE_FIELD									= 29;


//////////
// Logical and LogicalX definitions
//////
	const s32		_LOGICAL_FALSE									= 0;
	const s32		_LOGICAL_TRUE									= -1;
	const s32		_LOGICALX_OTHER									= 'O';
	const s32		_LOGICALX_PARTIAL								= 'P';
	const s32		_LOGICALX_EXTRA									= 'X';
	const s32		_LOGICALX_YET_ANOTHER							= 'Y';
	const s32		_LOGICALX_ZATS_ALL_FOLKS						= 'Z';


//////////
// Warnings
//////
	const u32		_WARNING_SPURIOUS_COMPONENTS_IGNORED			= 1;
	const u32		_WARNING_UNSPECIFIED_WARNING					= 2;

	// Messages
	const u8		cgcSpuriousIgnored[]							= "spurious, ignored";
	const u8		cgcUnspecifiedWarning[]							= "warning";


//////////
// Errors
//////
	const u32		_ERROR_OUT_OF_MEMORY							= 1;
	const u32		_ERROR_UNEXPECTED_COMMAND						= 2;
	const u32		_ERROR_CONTEXT_HAS_CHANGED						= 3;
	const u32		_ERROR_FULL_RECOMPILE_REQUIRED					= 4;
	const u32		_ERROR_NOT_A_VARIABLE							= 5;
	const u32		_ERROR_NUMERIC_OVERFLOW							= 6;
	const u32		_ERROR_NOT_NUMERIC								= 7;
	const u32		_ERROR_EMPTY_STRING								= 8;
	const u32		_ERROR_SYNTAX									= 9;
	const u32		_ERROR_UNRECOGNIZED_PARAMETER					= 10;
	const u32		_ERROR_OUT_OF_RANGE								= 11;
	const u32		_ERROR_COMMA_EXPECTED							= 12;
	const u32		_ERROR_TOO_MANY_PARAMETERS						= 13;
	const u32		_ERROR_DATA_TYPE_MISMATCH						= 14;
	const u32		_ERROR_FEATURE_NOT_AVAILABLE					= 15;
	const u32		_ERROR_P1_IS_INCORRECT							= 16;
	const u32		_ERROR_P2_IS_INCORRECT							= 17;
	const u32		_ERROR_P3_IS_INCORRECT							= 18;
	const u32		_ERROR_P4_IS_INCORRECT							= 19;
	const u32		_ERROR_P5_IS_INCORRECT							= 20;
	const u32		_ERROR_P6_IS_INCORRECT							= 21;
	const u32		_ERROR_P7_IS_INCORRECT							= 22;
	const u32		_ERROR_INTERNAL_ERROR							= 23;
	const u32		_ERROR_INVALID_ARGUMENT_TYPE_COUNT				= 24;
	const u32		_ERROR_VARIABLE_NOT_FOUND						= 25;
	const u32		_ERROR_ALIAS_NOT_FOUND							= 26;
	const u32		_ERROR_INVALID_WORK_AREA						= 27;
	const u32		_ERROR_ALIAS_ALREADY_IN_USE						= 28;

	// Messages
	const u8		cgcComponentError[]								= "Error in component, column ";
	const u8		cgcOutOfMemory[]								= "out of memory";
	const u8		cgcUnexpectedCommand[]							= "unexpected command";
	const u8		cgcContextHasChanged[]							= "context has changed";
	const u8		cgcFullRecompileRequired[]						= "full recompile required";
	const u8		cgcNotAVariable[]								= "not a variable";
	const u8		cgcNumericOverflow[]							= "numeric overflow";
	const u8		cgcNotNumeric[]									= "not numeric";
	const u8		cgcEmptyString[]								= "empty string";
	const u8		cgcSyntaxError[]								= "syntax error";
	const u8		cgcUnrecognizedParameter[]						= "unrecognized parameter";
	const u8		cgcOutOfRange[]									= "out of range";
	const u8		cgcCommaExpected[]								= "comma expected";
	const u8		cgcTooManyParameters[]							= "too many parameters";
	const u8		cgcDataTypeMismatch[]							= "data type mismatch";
	const u8		cgcFeatureNotAvailable[]						= "feature not available";
	const u8		cgcP1IsIncorrect[]								= "parameter 1 is incorrect";
	const u8		cgcP2IsIncorrect[]								= "parameter 2 is incorrect";
	const u8		cgcP3IsIncorrect[]								= "parameter 3 is incorrect";
	const u8		cgcP4IsIncorrect[]								= "parameter 4 is incorrect";
	const u8		cgcP5IsIncorrect[]								= "parameter 5 is incorrect";
	const u8		cgcP6IsIncorrect[]								= "parameter 6 is incorrect";
	const u8		cgcP7IsIncorrect[]								= "parameter 7 is incorrect";
	const u8		cgcInternalError[]								= "internal error";
	const u8		cgcInvalidArgumentTypeCountError[]				= "invalid argument, type, or count";
	const u8		cgcVariableNotFoundError[]						= "variable not found";
	const u8		cgcAliasNotFoundError[]							= "alias not found";
	const u8		cgcInvalidWorkArea[]							= "invalid work area";
	const u8		cgcAliasAlreadyInUse[]							= "alias already in use";
	

//////////
// Symbols in token parsing
//////
	const u8		cgcBackslash[]									= "\\";
	const u8		cgcSlash[]										= "/";
	const u8		cgcS[]											= "S";
	const u8		cgcNullString[]									= "";
	const u8		cgcPseudoFunctionName[]							= "__top_of_code_block";
	const u8		cgcNullText[]									= ".NULL.";
	const u8		cgcObjectText[]									= "(object)";
	const u8		cgcThisCodeText[]								= "(thisCode)";
	const u8		cgcTText[]										= ".T.";
	const u8		cgcFText[]										= ".F.";
	const u8		cgcYText[]										= ".Y.";
	const u8		cgcNText[]										= ".N.";
	const u8		cgcUText[]										= ".U.";
	const u8		cgcDText[]										= ".D.";
	const u8		cgcOxText[]										= ".o.";		// Other
	const u8		cgcPxText[]										= ".p.";		// Partial
	const u8		cgcYxText[]										= ".y.";		// Yet another
	const u8		cgcZxText[]										= ".z.";		// Zat's all folks! :-)
	const u8		cgcBigInteger[]									= "(BigInteger)";
	const u8		cgcBigFloatingPoint[]							= "(BigFloatingPoint)";
	const u8		cgcPasswordCharText[]							= "o";
	const u8		cgcFeatureNotYetSupported[]						= "feature not yet supported";


	// Combined items
	const s32		_ICODE_SINGLE_QUOTED_TEXT						= 90;
	const s32		_ICODE_DOUBLE_QUOTED_TEXT						= 91;

	// VJr-specific Keywords
	const s32		_ICODE_VJR										= 200;
	const s32		_ICODE_CMD										= 201;
	const s32		_ICODE_JDEBI									= 202;
	const s32		_ICODE_PROTECTED								= 203;
	const s32		_ICODE_MAIN										= 204;
	const s32		_ICODE_LOAD_LAST_FROM_VJR_USER_DBF				= 205;
	const s32		_ICODE_FLAGS									= 206;
	const s32		_ICODE_META										= 207;
	const s32		_ICODE_MEFA										= 208;
	const s32		_ICODE_MERA										= 209;
	const s32		_ICODE_MEMA										= 210;
	const s32		_ICODE_METAICASE								= 211;
	const s32		_ICODE_MEFAICASE								= 212;
	const s32		_ICODE_MERAICASE								= 213;
	const s32		_ICODE_MEMAICASE								= 214;
	const s32		_ICODE_FLOW										= 215;
	const s32		_ICODE_SUBFLOW									= 216;
	const s32		_ICODE_FLOWTO									= 217;
	const s32		_ICODE_FLOWOUT									= 218;
	const s32		_ICODE_FLOWOF									= 219;
	const s32		_ICODE_RGBA										= 220;
	const s32       _ICODE_LOBJECT								    = 221;
	const s32		_ICODE_PARAMS									= 222;
	const s32		_ICODE_RETURNS									= 223;
	const s32		_ICODE_AS										= 224;
	const s32		_ICODE_CHARACTER								= 225;
	const s32		_ICODE_INTEGER									= 226;
	const s32		_ICODE_FLOAT									= 227;
	const s32		_ICODE_DOUBLE									= 228;
	const s32		_ICODE_LOGICAL									= 229;
	const s32		_ICODE_S32										= 230;
	const s32		_ICODE_S64										= 231;
	const s32		_ICODE_U32										= 232;
	const s32		_ICODE_U64										= 233;
	const s32		_ICODE_F32										= 234;
	const s32		_ICODE_F64										= 235;
	const s32		_ICODE_BI										= 236;
	const s32		_ICODE_BFP										= 237;
	const s32		_ICODE_S16										= 238;
	const s32		_ICODE_S8										= 239;
	const s32		_ICODE_U16										= 240;
	const s32		_ICODE_U8										= 241;
	const s32		_ICODE_ADHOC									= 242;
	const s32		_ICODE_ENDADHOC									= 243;

	// Relatives
	const s32		_ICODE_THISCODE									= 600;
	const s32		_ICODE_THISCLASS								= 601;
	const s32		_ICODE_THISFORM									= 602;
	const s32		_ICODE_PARENT									= 603;

	// Stand-alones
	const s32	    _ICODE_TRUE										= 700;
	const s32	    _ICODE_FALSE									= 701;
	const s32	    _ICODE_YES										= 702;
	const s32	    _ICODE_NO										= 703;
	const s32	    _ICODE_UP										= 704;
	const s32	    _ICODE_DOWN										= 705;
	const s32	    _ICODE_OTHER									= 706;
	const s32	    _ICODE_PARTIAL									= 707;
	const s32		_ICODE_EXTRA									= 708;
	const s32	    _ICODE_YET_ANOTHER								= 709;
	const s32	    _ICODE_ZATS_ALL_FOLKS							= 710;

	// Conversions
	const s32		_ICODE_DOT_VARIABLE								= 800;

	// Functions
	const s32		_ICODE_ABS										= 1000;
	const s32		_ICODE_ACLASS                                   = 1001;
	const s32		_ICODE_ACOPY                                    = 1002;
	const s32		_ICODE_ACOS                                     = 1003;
	const s32		_ICODE_ADATABASES                               = 1004;
	const s32		_ICODE_ADBOBJECTS                               = 1005;
	const s32		_ICODE_ADDBS                                    = 1006;
	const s32		_ICODE_ADDOBJECT								= 1432;
	const s32		_ICODE_ADDPROPERTY                              = 1007;
	const s32		_ICODE_ADEL                                     = 1008;
	const s32		_ICODE_ADIR                                     = 1009;
	const s32		_ICODE_ADLLS                                    = 1010;
	const s32		_ICODE_ADOCKSTATE                               = 1011;
	const s32		_ICODE_AELEMENT                                 = 1012;
	const s32		_ICODE_AERROR                                   = 1013;
	const s32		_ICODE_AEVENTS                                  = 1014;
	const s32		_ICODE_AFIELDS                                  = 1015;
	const s32		_ICODE_AFONT                                    = 1016;
	const s32		_ICODE_AGAIN									= 1439;
	const s32		_ICODE_AGETCLASS                                = 1017;
	const s32		_ICODE_AGETFILEVERSION                          = 1018;
	const s32		_ICODE_AINSTANCE                                = 1019;
	const s32		_ICODE_AINS                                     = 1020;
	const s32		_ICODE_ALANGUAGE                                = 1021;
	const s32		_ICODE_ALEN                                     = 1022;
	const s32		_ICODE_ALIAS                                    = 1023;
	const s32		_ICODE_ALINES                                   = 1024;
	const s32		_ICODE_ALLTRIM                                  = 1025;
	const s32		_ICODE_AMEMBERS                                 = 1026;
	const s32		_ICODE_AMOUSEOBJ                                = 1027;
	const s32		_ICODE_ANETRESOURCES                            = 1028;
	const s32		_ICODE_APRINTERS                                = 1029;
	const s32		_ICODE_APROCINFO                                = 1030;
	const s32		_ICODE_ASCAN                                    = 1031;
	const s32		_ICODE_ASC                                      = 1032;
	const s32		_ICODE_ASCENDING								= 1434;
	const s32		_ICODE_ASELOBJ                                  = 1033;
	const s32		_ICODE_ASESSIONS                                = 1034;
	const s32		_ICODE_ASIN                                     = 1035;
	const s32		_ICODE_ASORT                                    = 1036;
	const s32		_ICODE_ASQLHANDLES                              = 1037;
	const s32		_ICODE_ASTACKINFO                               = 1038;
	const s32		_ICODE_ASUBSCRIPT                               = 1039;
	const s32		_ICODE_AT_C                                     = 1040;
	const s32		_ICODE_AT                                       = 1041;
	const s32		_ICODE_ATAGINFO                                 = 1042;
	const s32		_ICODE_ATAN                                     = 1043;
	const s32		_ICODE_ATCLINE                                  = 1044;
	const s32		_ICODE_ATCC                                     = 1045;
	const s32		_ICODE_ATC                                      = 1046;
	const s32		_ICODE_ATLINE                                   = 1047;
	const s32		_ICODE_ATN2                                     = 1048;
	const s32		_ICODE_AUSED                                    = 1049;
	const s32		_ICODE_AVCXCLASSES                              = 1050;
	const s32		_ICODE_BARPROMPT                                = 1051;
	const s32		_ICODE_BARCOUNT                                 = 1052;
	const s32		_ICODE_BAR                                      = 1053;
	const s32		_ICODE_BETWEEN                                  = 1054;
	const s32		_ICODE_BINDEVENT                                = 1055;
	const s32		_ICODE_BINTOC                                   = 1056;
	const s32		_ICODE_BITAND                                   = 1057;
	const s32		_ICODE_BITCLEAR                                 = 1058;
	const s32		_ICODE_BITLSHIFT                                = 1059;
	const s32		_ICODE_BITNOT                                   = 1060;
	const s32		_ICODE_BITOR                                    = 1061;
	const s32		_ICODE_BITRSHIFT                                = 1062;
	const s32		_ICODE_BITSET                                   = 1063;
	const s32		_ICODE_BITTEST                                  = 1064;
	const s32		_ICODE_BITXOR                                   = 1065;
	const s32		_ICODE_BOF                                      = 1066;
	const s32		_ICODE_CANDIDATE                                = 1067;
	const s32		_ICODE_CAPSLOCK                                 = 1068;
	const s32		_ICODE_CAST                                     = 1069;
	const s32		_ICODE_CDOW                                     = 1070;
	const s32		_ICODE_CDX                                      = 1071;
	const s32		_ICODE_CEILING                                  = 1072;
	const s32		_ICODE_CHR                                      = 1073;
	const s32		_ICODE_CHRSAW                                   = 1074;
	const s32		_ICODE_CHRTRANC									= 1075;
	const s32		_ICODE_CHRTRAN                                  = 1076;
	const s32		_ICODE_CLEARRESULTSET                           = 1077;
	const s32		_ICODE_CMONTH                                   = 1078;
	const s32		_ICODE_CNTBAR                                   = 1079;
	const s32		_ICODE_CNTPAD                                   = 1080;
	const s32		_ICODE_COL                                      = 1081;
	const s32		_ICODE_COMARRAY                                 = 1082;
	const s32		_ICODE_COMCLASSINFO                             = 1083;
	const s32		_ICODE_COMMAND                                  = 1084;
	const s32		_ICODE_COMPOBJ                                  = 1085;
	const s32		_ICODE_COMPROP                                  = 1086;
	const s32		_ICODE_COMRETURNERROR                           = 1087;
	const s32		_ICODE_COMS                                     = 1088;
	const s32		_ICODE_CONNSTRING								= 1441;
	const s32		_ICODE_COS                                      = 1089;
	const s32		_ICODE_CPCONVERT                                = 1090;
	const s32		_ICODE_CPCURRENT                                = 1091;
	const s32		_ICODE_CPDBF                                    = 1092;
	const s32		_ICODE_CREATEBINARY                             = 1093;
	const s32		_ICODE_CREATEOBJECT                             = 1094;
	const s32		_ICODE_CREATEOBJECTEX                           = 1095;
	const s32		_ICODE_CREATEOFFLINE                            = 1096;
	const s32		_ICODE_CTOBIN                                   = 1097;
	const s32		_ICODE_CTOD                                     = 1098;
	const s32		_ICODE_CTOT                                     = 1099;
	const s32		_ICODE_CURDIR                                   = 1100;
	const s32		_ICODE_CURSORGETPROP                            = 1101;
	const s32		_ICODE_CURSORSETPROP                            = 1102;
	const s32		_ICODE_CURSORTOXML                              = 1103;
	const s32		_ICODE_CURVAL                                   = 1104;
	const s32		_ICODE_DATETIME                                 = 1105;
	const s32		_ICODE_DATE                                     = 1106;
	const s32		_ICODE_DAY                                      = 1107;
	const s32		_ICODE_DBC                                      = 1108;
	const s32		_ICODE_DBF                                      = 1109;
	const s32		_ICODE_DBGETPROP                                = 1110;
	const s32		_ICODE_DBSETPROP                                = 1111;
	const s32		_ICODE_DBUSED                                   = 1112;
	const s32		_ICODE_DDEABORTTRANS                            = 1113;
	const s32		_ICODE_DDEADVISE                                = 1114;
	const s32		_ICODE_DDEENABLED                               = 1115;
	const s32		_ICODE_DDEEXECUTE                               = 1116;
	const s32		_ICODE_DDEINITIATE                              = 1117;
	const s32		_ICODE_DDELASTERROR                             = 1118;
	const s32		_ICODE_DDEPOKE                                  = 1119;
	const s32		_ICODE_DDEREQUEST                               = 1120;
	const s32		_ICODE_DDES                                     = 1121;
	const s32		_ICODE_DDESETOPTION                             = 1122;
	const s32		_ICODE_DDESETSERVICE                            = 1123;
	const s32		_ICODE_DDESETTOPIC                              = 1124;
	const s32		_ICODE_DDETERMINATE                             = 1125;
	const s32		_ICODE_DEFAULTEXT                               = 1126;
	const s32		_ICODE_DELETED                                  = 1127;
	const s32		_ICODE_DESCENDING                               = 1128;
	const s32		_ICODE_DIFFERENCE                               = 1129;
	const s32		_ICODE_DIRECTORY                                = 1130;
	const s32		_ICODE_DISKSPACE                                = 1131;
	const s32		_ICODE_DISPLAYPATH                              = 1132;
	const s32		_ICODE_DMY                                      = 1133;
	const s32		_ICODE_DODEFAULT                                = 1134;
	const s32		_ICODE_DOW                                      = 1135;
	const s32		_ICODE_DRIVETYPE                                = 1136;
	const s32		_ICODE_DROPOFFLINE                              = 1137;
	const s32		_ICODE_DTOC                                     = 1138;
	const s32		_ICODE_DTOR                                     = 1139;
	const s32		_ICODE_DTOS                                     = 1140;
	const s32		_ICODE_DTOT                                     = 1141;
	const s32		_ICODE_EDITSOURCE                               = 1142;
	const s32		_ICODE_EMPTY                                    = 1143;
	const s32		_ICODE_EOF                                      = 1144;
	const s32		_ICODE_ERROR                                    = 1145;
	const s32		_ICODE_EVALUATE                                 = 1146;
	const s32		_ICODE_EVENTHANDLER                             = 1147;
	const s32		_ICODE_EVL                                      = 1148;
	const s32		_ICODE_EXECSCRIPT                               = 1149;
	const s32		_ICODE_EXP                                      = 1150;
	const s32		_ICODE_FCHSIZE                                  = 1151;
	const s32		_ICODE_FCLOSE                                   = 1152;
	const s32		_ICODE_FCOUNT                                   = 1153;
	const s32		_ICODE_FCREATE                                  = 1154;
	const s32		_ICODE_FDATE                                    = 1155;
	const s32		_ICODE_FEOF                                     = 1156;
	const s32		_ICODE_FERROR                                   = 1157;
	const s32		_ICODE_FFLUSH                                   = 1158;
	const s32		_ICODE_FGETS                                    = 1159;
	const s32		_ICODE_FIELD                                    = 1160;
	const s32		_ICODE_FILETOSTR                                = 1161;
	const s32		_ICODE_FILE                                     = 1162;
	const s32		_ICODE_FILTER                                   = 1163;
	const s32		_ICODE_FKLABEL                                  = 1164;
	const s32		_ICODE_FKMAX                                    = 1165;
	const s32		_ICODE_FLDLIST                                  = 1166;
	const s32		_ICODE_FLOCK                                    = 1167;
	const s32		_ICODE_FLOOR                                    = 1168;
	const s32		_ICODE_FONTMETRIC                               = 1169;
	const s32		_ICODE_FOPEN                                    = 1170;
	const s32		_ICODE_FOR                                      = 1171;
	const s32		_ICODE_FORCEEXT                                 = 1172;
	const s32		_ICODE_FORCEPATH                                = 1173;
	const s32		_ICODE_FOUND                                    = 1174;
	const s32		_ICODE_FPUTS                                    = 1175;
	const s32		_ICODE_FREAD                                    = 1176;
	const s32		_ICODE_FSEEK                                    = 1177;
	const s32		_ICODE_FSIZE                                    = 1178;
	const s32		_ICODE_FTIME                                    = 1179;
	const s32		_ICODE_FULLPATH                                 = 1180;
	const s32		_ICODE_FV                                       = 1181;
	const s32		_ICODE_FWRITE                                   = 1182;
	const s32		_ICODE_GETAUTOINCVALUE                          = 1183;
	const s32		_ICODE_GETBAR                                   = 1184;
	const s32		_ICODE_GETCOLOR                                 = 1185;
	const s32		_ICODE_GETCP                                    = 1186;
	const s32		_ICODE_GETCURSORADAPTER                         = 1187;
	const s32		_ICODE_GETDIR                                   = 1188;
	const s32		_ICODE_GETENV                                   = 1189;
	const s32		_ICODE_GETFILE                                  = 1190;
	const s32		_ICODE_GETFLDSTATE                              = 1191;
	const s32		_ICODE_GETFONT                                  = 1192;
	const s32		_ICODE_GETINTERFACE                             = 1193;
	const s32		_ICODE_GETNEXTMODIFIED                          = 1194;
	const s32		_ICODE_GETOBJECT                                = 1195;
	const s32		_ICODE_GETPAD                                   = 1196;
	const s32		_ICODE_GETPEM                                   = 1197;
	const s32		_ICODE_GETPICT                                  = 1198;
	const s32		_ICODE_GETPRINTER                               = 1199;
	const s32		_ICODE_GETRESULTSET                             = 1200;
	const s32		_ICODE_GETWORDCOUNT                             = 1201;
	const s32		_ICODE_GETWORDNUM                               = 1202;
	const s32		_ICODE_GOMONTH                                  = 1203;
	const s32		_ICODE_HEADER                                   = 1204;
	const s32		_ICODE_HOME                                     = 1205;
	const s32		_ICODE_HOUR                                     = 1206;
	const s32		_ICODE_ICASE                                    = 1207;
	const s32		_ICODE_IDXCOLLATE                               = 1208;
	const s32		_ICODE_IIF                                      = 1209;
	const s32		_ICODE_IMESTATUS                                = 1210;
	const s32		_ICODE_IN										= 1435;
	const s32		_ICODE_INDBC                                    = 1211;
	const s32		_ICODE_INDEXSEEK                                = 1212;
	const s32		_ICODE_INKEY                                    = 1213;
	const s32		_ICODE_INLIST                                   = 1214;
	const s32		_ICODE_INPUTBOX                                 = 1215;
	const s32		_ICODE_INSMODE                                  = 1216;
	const s32		_ICODE_INT                                      = 1217;
	const s32		_ICODE_ISALPHA                                  = 1218;
	const s32		_ICODE_ISBLANK                                  = 1219;
	const s32		_ICODE_ISCOLOR                                  = 1220;
	const s32		_ICODE_ISDIGIT                                  = 1221;
	const s32		_ICODE_ISEXCLUSIVE                              = 1222;
	const s32		_ICODE_ISFLOCKED                                = 1223;
	const s32		_ICODE_ISLEADBYTE                               = 1224;
	const s32		_ICODE_ISLOWER                                  = 1225;
	const s32		_ICODE_ISMEMOFETCHED                            = 1226;
	const s32		_ICODE_ISMOUSE                                  = 1227;
	const s32		_ICODE_ISNULL                                   = 1228;
	const s32		_ICODE_ISPEN                                    = 1229;
	const s32		_ICODE_ISREADONLY                               = 1230;
	const s32		_ICODE_ISRLOCKED                                = 1231;
	const s32		_ICODE_ISTRANSACTABLE                           = 1232;
	const s32		_ICODE_ISUPPER                                  = 1233;
	const s32		_ICODE_JUSTDRIVE                                = 1234;
	const s32		_ICODE_JUSTEXT                                  = 1235;
	const s32		_ICODE_JUSTFNAME                                = 1236;
	const s32		_ICODE_JUSTPATH                                 = 1237;
	const s32		_ICODE_JUSTSTEM                                 = 1238;
	const s32		_ICODE_KEYMATCH                                 = 1239;
	const s32		_ICODE_KEY                                      = 1240;
	const s32		_ICODE_LASTKEY                                  = 1241;
	const s32		_ICODE_LEFTC                                    = 1242;
	const s32		_ICODE_LEFT                                     = 1243;
	const s32		_ICODE_LENC                                     = 1244;
	const s32		_ICODE_LEN                                      = 1245;
	const s32		_ICODE_LIKEC                                    = 1246;
	const s32		_ICODE_LIKE                                     = 1247;
	const s32		_ICODE_LINENO                                   = 1248;
	const s32		_ICODE_LOADPICTURE                              = 1249;
	const s32		_ICODE_LOCFILE                                  = 1250;
	const s32		_ICODE_LOCK                                     = 1251;
	const s32		_ICODE_LOG10                                    = 1252;
	const s32		_ICODE_LOG                                      = 1253;
	const s32		_ICODE_LOOKUP                                   = 1254;
	const s32		_ICODE_LOWER                                    = 1255;
	const s32		_ICODE_LTRIM                                    = 1256;
	const s32		_ICODE_LUPDATE                                  = 1257;
	const s32		_ICODE_MAKETRANSACTABLE                         = 1258;
	const s32		_ICODE_MAX                                      = 1259;
	const s32		_ICODE_MCOL                                     = 1260;
	const s32		_ICODE_MDOWN                                    = 1261;
	const s32		_ICODE_MDX                                      = 1262;
	const s32		_ICODE_MDY                                      = 1263;
	const s32		_ICODE_MEMLINES                                 = 1264;
	const s32		_ICODE_MEMORY                                   = 1265;
	const s32		_ICODE_MENU                                     = 1266;
	const s32		_ICODE_MESSAGEBOX                               = 1267;
	const s32		_ICODE_MESSAGE                                  = 1268;
	const s32		_ICODE_MINUTE                                   = 1269;
	const s32		_ICODE_MIN                                      = 1270;
	const s32		_ICODE_MLINE                                    = 1271;
	const s32		_ICODE_MOD                                      = 1272;
	const s32		_ICODE_MONTH                                    = 1273;
	const s32		_ICODE_MRKBAR                                   = 1274;
	const s32		_ICODE_MRKPAD                                   = 1275;
	const s32		_ICODE_MROW                                     = 1276;
	const s32		_ICODE_MTON                                     = 1277;
	const s32		_ICODE_MWINDOW                                  = 1278;
	const s32		_ICODE_NDX                                      = 1279;
	const s32		_ICODE_NEWOBJECT                                = 1280;
	const s32		_ICODE_NODATA									= 1437;
	const s32		_ICODE_NOREQUERY								= 1438;
	const s32		_ICODE_NORMALIZE                                = 1281;
	const s32		_ICODE_NOUPDATE									= 1436;
	const s32		_ICODE_NTOM                                     = 1282;
	const s32		_ICODE_NUMLOCK                                  = 1283;
	const s32		_ICODE_NVL                                      = 1284;
	const s32		_ICODE_OBJNUM                                   = 1285;
	const s32		_ICODE_OBJTOCLIENT                              = 1286;
	const s32		_ICODE_OBJVAR                                   = 1287;
	const s32		_ICODE_OCCURSC									= 1431;
	const s32		_ICODE_OCCURS                                   = 1288;
	const s32		_ICODE_OEMTOANSI                                = 1289;
	const s32		_ICODE_OLDVAL                                   = 1290;
	const s32		_ICODE_ON                                       = 1291;
	const s32		_ICODE_ORDER                                    = 1292;
	const s32		_ICODE_OS                                       = 1293;
	const s32		_ICODE_OVERVIEW                                 = 1294;
	const s32		_ICODE_PADC                                     = 1295;
	const s32		_ICODE_PADL                                     = 1296;
	const s32		_ICODE_PADR                                     = 1297;
	const s32		_ICODE_PAD                                      = 1298;
	const s32		_ICODE_PARAMETERS                               = 1299;
	const s32		_ICODE_PAYMENT                                  = 1300;
	const s32		_ICODE_PCOL                                     = 1301;
	const s32		_ICODE_PCOUNT                                   = 1302;
	const s32		_ICODE_PEMSTATUS                                = 1303;
	const s32		_ICODE_PI                                       = 1304;
	const s32		_ICODE_POPUP                                    = 1305;
	const s32		_ICODE_PRIMARY                                  = 1306;
	const s32		_ICODE_PRINTSTATUS                              = 1307;
	const s32		_ICODE_PRMBAR                                   = 1308;
	const s32		_ICODE_PRMPAD                                   = 1309;
	const s32		_ICODE_PROGRAM                                  = 1310;
	const s32		_ICODE_PROMPT                                   = 1311;
	const s32		_ICODE_PROPER                                   = 1312;
	const s32		_ICODE_PROW                                     = 1313;
	const s32		_ICODE_PRTINFO                                  = 1314;
	const s32		_ICODE_PUTFILE                                  = 1315;
	const s32		_ICODE_PV                                       = 1316;
	const s32		_ICODE_QUARTER                                  = 1317;
	const s32		_ICODE_RAISEEVENT                               = 1318;
	const s32		_ICODE_RAND                                     = 1319;
	const s32		_ICODE_RATC                                     = 1320;
	const s32		_ICODE_RAT                                      = 1321;
	const s32		_ICODE_RATLINE                                  = 1322;
	const s32		_ICODE_RDLEVEL                                  = 1323;
	const s32		_ICODE_READKEY                                  = 1324;
	const s32		_ICODE_RECCOUNT                                 = 1325;
	const s32		_ICODE_RECNO                                    = 1326;
	const s32		_ICODE_RECSIZE                                  = 1327;
	const s32		_ICODE_REFRESH                                  = 1328;
	const s32		_ICODE_RELATION                                 = 1329;
	const s32		_ICODE_REPLICATE                                = 1330;
	const s32		_ICODE_REQUERY                                  = 1331;
	const s32		_ICODE_RGB                                      = 1332;
	const s32		_ICODE_RGBSCHEME                                = 1333;
	const s32		_ICODE_RIGHT                                    = 1334;
	const s32		_ICODE_RIGHTC                                   = 1335;
	const s32		_ICODE_RLOCK                                    = 1336;
	const s32		_ICODE_ROUND                                    = 1337;
	const s32		_ICODE_ROW                                      = 1338;
	const s32		_ICODE_RTOD                                     = 1339;
	const s32		_ICODE_RTRIM                                    = 1340;
	const s32		_ICODE_SAVEPICTURE                              = 1341;
	const s32		_ICODE_SCHEME                                   = 1342;
	const s32		_ICODE_SCOLS                                    = 1343;
	const s32		_ICODE_SECONDS                                  = 1344;
	const s32		_ICODE_SEC                                      = 1345;
	const s32		_ICODE_SEEK                                     = 1346;
	const s32		_ICODE_SELECT                                   = 1347;
	const s32		_ICODE_SET                                      = 1348;
	const s32		_ICODE_SETFLDSTATE                              = 1349;
	const s32		_ICODE_SETRESULTSET                             = 1350;
	const s32		_ICODE_SHARED									= 1440;
	const s32		_ICODE_SIGN                                     = 1351;
	const s32		_ICODE_SIN                                      = 1352;
	const s32		_ICODE_SKPBAR                                   = 1353;
	const s32		_ICODE_SKPPAD                                   = 1354;
	const s32		_ICODE_SOUNDEX                                  = 1355;
	const s32		_ICODE_SPACE                                    = 1356;
	const s32		_ICODE_SQLCANCEL                                = 1357;
	const s32		_ICODE_SQLCOLUMNS                               = 1358;
	const s32		_ICODE_SQLCOMMIT                                = 1359;
	const s32		_ICODE_SQLCONNECT                               = 1360;
	const s32		_ICODE_SQLDISCONNECT                            = 1361;
	const s32		_ICODE_SQLEXEC                                  = 1362;
	const s32		_ICODE_SQLGETPROP                               = 1363;
	const s32		_ICODE_SQLIDLEDISCONNECT                        = 1364;
	const s32		_ICODE_SQLMORERESULTS                           = 1365;
	const s32		_ICODE_SQLPREPARE                               = 1366;
	const s32		_ICODE_SQLROLLBACK                              = 1367;
	const s32		_ICODE_SQLSETPROP                               = 1368;
	const s32		_ICODE_SQLSTRINGCONNECT                         = 1369;
	const s32		_ICODE_SQLTABLES                                = 1370;
	const s32		_ICODE_SQRT                                     = 1371;
	const s32		_ICODE_SROWS                                    = 1372;
	const s32		_ICODE_STRCONV                                  = 1373;
	const s32		_ICODE_STREXTRACT                               = 1374;
	const s32		_ICODE_STRTOFILE                                = 1375;
	const s32		_ICODE_STRTRANC									= 1433;
	const s32		_ICODE_STRTRAN                                  = 1376;
	const s32		_ICODE_STR                                      = 1377;
	const s32		_ICODE_STUFFC                                   = 1378;
	const s32		_ICODE_STUFF                                    = 1379;
	const s32		_ICODE_SUBSTRC                                  = 1380;
	const s32		_ICODE_SUBSTR                                   = 1381;
	const s32		_ICODE_SYSMETRIC                                = 1382;
	const s32		_ICODE_SYS                                      = 1383;
	const s32		_ICODE_TABLEREVERT                              = 1384;
	const s32		_ICODE_TABLEUPDATE                              = 1385;
	const s32		_ICODE_TAG                                      = 1386;
	const s32		_ICODE_TAGCOUNT                                 = 1387;
	const s32		_ICODE_TAGNO                                    = 1388;
	const s32		_ICODE_TAN                                      = 1389;
	const s32		_ICODE_TARGET                                   = 1390;
	const s32		_ICODE_TEXTMERGE                                = 1391;
	const s32		_ICODE_TIME                                     = 1392;
	const s32		_ICODE_TRANSFORM                                = 1393;
	const s32		_ICODE_TRIM                                     = 1394;
	const s32		_ICODE_TTOC                                     = 1395;
	const s32		_ICODE_TTOD                                     = 1396;
	const s32		_ICODE_TXNLEVEL                                 = 1397;
	const s32		_ICODE_TXTWIDTH                                 = 1398;
	const s32		_ICODE_TYPE                                     = 1399;
	const s32		_ICODE_UNBINDEVENTS                             = 1400;
	const s32		_ICODE_UNIQUE                                   = 1401;
	const s32		_ICODE_UPDATED                                  = 1402;
	const s32		_ICODE_UPPER                                    = 1403;
	const s32		_ICODE_USED                                     = 1404;
	const s32		_ICODE_VAL                                      = 1405;
	const s32		_ICODE_VARREAD                                  = 1406;
	const s32		_ICODE_VARTYPE                                  = 1407;
	const s32		_ICODE_VERSION                                  = 1408;
	const s32		_ICODE_WBORDER                                  = 1409;
	const s32		_ICODE_WCHILD                                   = 1410;
	const s32		_ICODE_WCOLS                                    = 1411;
	const s32		_ICODE_WDOCKABLE                                = 1412;
	const s32		_ICODE_WEEK                                     = 1413;
	const s32		_ICODE_WEXIST                                   = 1414;
	const s32		_ICODE_WFONT                                    = 1415;
	const s32		_ICODE_WLAST                                    = 1416;
	const s32		_ICODE_WLCOL                                    = 1417;
	const s32		_ICODE_WLROW                                    = 1418;
	const s32		_ICODE_WMAXIMUM                                 = 1419;
	const s32		_ICODE_WMINIMUM                                 = 1420;
	const s32		_ICODE_WONTOP                                   = 1421;
	const s32		_ICODE_WOUTPUT                                  = 1422;
	const s32		_ICODE_WPARENT                                  = 1423;
	const s32		_ICODE_WREAD                                    = 1424;
	const s32		_ICODE_WROWS                                    = 1425;
	const s32		_ICODE_WTITLE                                   = 1426;
	const s32		_ICODE_WVISIBLE                                 = 1427;
	const s32		_ICODE_XMLTOCURSOR                              = 1428;
	const s32		_ICODE_XMLUPDATEGRAM                            = 1429;
	const s32		_ICODE_YEAR                                     = 1430;
	// occursc		= 1431			addobject	= 1432
	// strtranc		= 1433			ascending	= 1434
	// in			= 1435			noupdate	= 1436
	// nodata		= 1437			norequery	= 1438
	// again		= 1439			shared		= 1440
	// connstring	= 1441

// Temporarily added until the processing engine is coded
	const s32		_ICODE_CONCATENATE								= 1900;
	const s32       _ICODE_ADD                                      = 1901;
	const s32       _ICODE_SUB                                      = 1902;
	const s32       _ICODE_MUL                                      = 1903;
	const s32       _ICODE_DIV                                      = 1904;

	// Commands
	const s32       _ICODE_ACTIVATE                                 = 2000;
//	const s32       _ICODE_ADD                                      = 2001;
	const s32       _ICODE_ALTER                                    = 2002;
	const s32       _ICODE_ALTERNATE                                = 2003;
	const s32       _ICODE_ANSI                                     = 2004;
	const s32       _ICODE_APP                                      = 2005;
	const s32       _ICODE_APPEND                                   = 2006;
	const s32       _ICODE_ARRAY                                    = 2007;
	const s32       _ICODE_ASSERTS                                  = 2008;
	const s32       _ICODE_ASSERT                                   = 2009;
	const s32       _ICODE_ASSIST                                   = 2010;
	const s32       _ICODE_AUTOINCERROR                             = 2011;
	const s32       _ICODE_AUTOSAVE                                 = 2012;
	const s32       _ICODE_AVERAGE                                  = 2013;
	const s32       _ICODE_BEGIN                                    = 2014;
	const s32       _ICODE_BELL                                     = 2015;
	const s32       _ICODE_BLANK                                    = 2016;
	const s32       _ICODE_BLOCKSIZE                                = 2017;
	const s32       _ICODE_BORDER                                   = 2018;
	const s32       _ICODE_BOX                                      = 2019;
	const s32       _ICODE_BROWSE                                   = 2020;
	const s32       _ICODE_BROWSEIME                                = 2021;
	const s32       _ICODE_BRSTATUS                                 = 2022;
	const s32       _ICODE_BUILD                                    = 2023;
	const s32       _ICODE_CALCULATE                                = 2024;
	const s32       _ICODE_CALL                                     = 2025;
	const s32       _ICODE_CANCEL                                   = 2026;
	const s32       _ICODE_CARRY                                    = 2027;
	const s32       _ICODE_CASE                                     = 2028;
	const s32       _ICODE_CATCH                                    = 2029;
	const s32       _ICODE_CD                                       = 2030;
	const s32       _ICODE_CENTURY                                  = 2031;
	const s32       _ICODE_CHANGE                                   = 2032;
	const s32       _ICODE_CHDIR                                    = 2033;
	const s32       _ICODE_CLASS                                    = 2034;
	const s32       _ICODE_CLASSLIB                                 = 2035;
	const s32       _ICODE_CLEAR                                    = 2036;
	const s32       _ICODE_CLEARS                                   = 2037;
	const s32       _ICODE_CLOCK                                    = 2038;
	const s32       _ICODE_CLOSE                                    = 2039;
	const s32       _ICODE_CLOSES                                   = 2040;
	const s32       _ICODE_COLLATE                                  = 2041;
	const s32       _ICODE_COLOR                                    = 2042;
	const s32       _ICODE_COMPATIBLE                               = 2043;
	const s32       _ICODE_COMPILE                                  = 2044;
	const s32       _ICODE_CONFIRM                                  = 2045;
	const s32       _ICODE_CONNECTION                               = 2046;
	const s32       _ICODE_CONNECTIONS                              = 2047;
	const s32       _ICODE_CONSOLE                                  = 2048;
	const s32       _ICODE_CONTINUE                                 = 2049;
	const s32       _ICODE_COPY                                     = 2050;
	const s32       _ICODE_COUNT                                    = 2051;
	const s32       _ICODE_COVERAGE                                 = 2052;
	const s32       _ICODE_CPCOMPILE                                = 2053;
	const s32       _ICODE_CPDIALOG                                 = 2054;
	const s32       _ICODE_CREATE                                   = 2055;
	const s32       _ICODE_CURRENCY                                 = 2056;
	const s32       _ICODE_CURSOR                                   = 2057;
	const s32       _ICODE_DATABASE                                 = 2058;
	const s32       _ICODE_DATASESSION                              = 2059;
	const s32       _ICODE_DEACTIVATE                               = 2060;
	const s32       _ICODE_DEBUG                                    = 2061;
	const s32       _ICODE_DEBUGOUT                                 = 2062;
	const s32       _ICODE_DECIMALS                                 = 2063;
	const s32       _ICODE_DECLARE                                  = 2064;
	const s32       _ICODE_DEFAULT                                  = 2065;
	const s32       _ICODE_DELETE                                   = 2066;
	const s32       _ICODE_DELIMITERS                               = 2067;
	const s32       _ICODE_DEVELOPMENT                              = 2068;
	const s32       _ICODE_DEVICE                                   = 2069;
	const s32       _ICODE_DIMENSION                                = 2070;
	const s32       _ICODE_DIR                                      = 2071;
	const s32       _ICODE_DISPLAY                                  = 2072;
	const s32       _ICODE_DLLS                                     = 2073;
	const s32       _ICODE_DLL                                      = 2074;
	const s32       _ICODE_DO                                       = 2075;
	const s32       _ICODE_DOCASE                                   = 2272;
	const s32       _ICODE_DOFORM                                   = 2273;
	const s32       _ICODE_DOPROGRAM                                = 2274;
	const s32       _ICODE_DOWHILE                                  = 2275;
	const s32       _ICODE_DOCK                                     = 2076;
	const s32       _ICODE_DOEVENTS                                 = 2077;
	const s32       _ICODE_DOHISTORY                                = 2078;
	const s32       _ICODE_DROP                                     = 2079;
	const s32       _ICODE_EACH                                     = 2080;
	const s32       _ICODE_ECHO                                     = 2081;
	const s32       _ICODE_EDIT                                     = 2082;
	const s32       _ICODE_EJECT                                    = 2083;
	const s32		_ICODE_ELSE										= 2280;
	const s32       _ICODE_END                                      = 2084;
	const s32       _ICODE_ENDCASE                                  = 2085;
	const s32       _ICODE_ENDDO                                    = 2086;
	const s32       _ICODE_ENDFOR                                   = 2087;
	const s32		_ICODE_ENDFUNCTION								= 2276;
	const s32       _ICODE_ENDIF                                    = 2088;
	const s32       _ICODE_ENDPRINTJOB                              = 2089;
	const s32		_ICODE_ENDPROCEDURE								= 2277;
	const s32       _ICODE_ENDSCAN                                  = 2090;
	const s32       _ICODE_ENDTEXT                                  = 2091;
	const s32       _ICODE_ENDWITH                                  = 2092;
	const s32       _ICODE_ENGINEBEHAVIOR                           = 2093;
	const s32       _ICODE_ERASE                                    = 2094;
	const s32       _ICODE_ESCAPE                                   = 2095;
	const s32       _ICODE_EVENTLIST                                = 2096;
	const s32       _ICODE_EVENTS                                   = 2097;
	const s32       _ICODE_EVENTTRACKING                            = 2098;
	const s32       _ICODE_EXACT                                    = 2099;
	const s32       _ICODE_EXCLUSIVE                                = 2100;
	const s32       _ICODE_EXE                                      = 2101;
	const s32       _ICODE_EXIT                                     = 2102;
	const s32       _ICODE_EXPORT                                   = 2103;
	const s32       _ICODE_EXTENDED                                 = 2104;
	const s32       _ICODE_EXTERNAL                                 = 2105;
	const s32       _ICODE_FDOW                                     = 2106;
	const s32		_ICODE_FELSEIF									= 2283;
	const s32       _ICODE_FIELDS                                   = 2107;
	const s32		_ICODE_FIF										= 2284;
	const s32       _ICODE_FILES                                    = 2108;
	const s32       _ICODE_FILL                                     = 2109;
	const s32       _ICODE_FINALLY                                  = 2110;
	const s32       _ICODE_FIND                                     = 2111;
	const s32       _ICODE_FIXED                                    = 2112;
	const s32       _ICODE_FLUSH                                    = 2113;
	const s32       _ICODE_FORMAT                                   = 2114;
	const s32       _ICODE_FORM                                     = 2115;
	const s32       _ICODE_FREE                                     = 2116;
	const s32       _ICODE_FROM                                     = 2117;
	const s32       _ICODE_FUNCTION                                 = 2118;
	const s32       _ICODE_FWEEK                                    = 2119;
	const s32       _ICODE_GATHER                                   = 2120;
	const s32       _ICODE_GENERAL                                  = 2121;
	const s32       _ICODE_GETEXPR                                  = 2122;
	const s32       _ICODE_GETS                                     = 2123;
	const s32       _ICODE_GET                                      = 2124;
	const s32       _ICODE_GO                                       = 2125;
	const s32       _ICODE_GOTO                                     = 2126;
	const s32       _ICODE_HEADINGS                                 = 2127;
	const s32       _ICODE_HELP                                     = 2128;
	const s32       _ICODE_HIDE                                     = 2129;
	const s32       _ICODE_HOURS                                    = 2130;
	const s32       _ICODE_ID                                       = 2131;
	const s32       _ICODE_IF                                       = 2132;
	const s32       _ICODE_IMPORT                                   = 2133;
	const s32       _ICODE_INDEXES                                  = 2134;
	const s32       _ICODE_INDEX                                    = 2135;
	const s32       _ICODE_INPUT                                    = 2136;
	const s32       _ICODE_INSERT                                   = 2137;
	const s32       _ICODE_INTENSITY                                = 2138;
	const s32       _ICODE_JOIN                                     = 2139;
	const s32       _ICODE_KEYBOARD                                 = 2140;
	const s32       _ICODE_KEYCOMP                                  = 2141;
	const s32       _ICODE_LABEL                                    = 2142;
	const s32		_ICODE_LELSE									= 2281;
	const s32		_ICODE_LELSEIF									= 2282;
	const s32       _ICODE_LIBRARY                                  = 2143;
	const s32		_ICODE_LIF										= 2279;
	const s32       _ICODE_LISTS                                    = 2144;
	const s32       _ICODE_LIST                                     = 2145;
	const s32       _ICODE_LOAD                                     = 2146;
	const s32       _ICODE_LOCAL                                    = 2147;
	const s32       _ICODE_LOCATE                                   = 2148;
	const s32       _ICODE_LOGERRORS                                = 2149;
	const s32       _ICODE_LOOP                                     = 2150;
	const s32       _ICODE_LPARAMETERS                              = 2151;
	const s32       _ICODE_MACKEY                                   = 2152;
	const s32       _ICODE_MACROS                                   = 2153;
	const s32       _ICODE_MACRO                                    = 2154;
	const s32       _ICODE_MARGIN                                   = 2155;
	const s32       _ICODE_MARK                                     = 2156;
	const s32       _ICODE_MD                                       = 2157;
	const s32       _ICODE_MEMOWIDTH                                = 2158;
	const s32       _ICODE_MEMO                                     = 2159;
	const s32       _ICODE_MENUS                                    = 2160;
	const s32       _ICODE_MKDIR                                    = 2161;
	const s32       _ICODE_MODIFY                                   = 2162;
	const s32       _ICODE_MOUSE                                    = 2163;
	const s32       _ICODE_MOVE                                     = 2164;
	const s32       _ICODE_MTDLL                                    = 2165;
	const s32       _ICODE_MULTILOCKS                               = 2166;
	const s32       _ICODE_NEAR                                     = 2167;
// 	const s32       _ICODE_NEXT                                     = 2168;
	const s32       _ICODE_NOCPTRANS                                = 2169;
	const s32       _ICODE_NOTE                                     = 2170;
	const s32       _ICODE_NOTIFY                                   = 2171;
	const s32       _ICODE_NULL                                     = 2172;
	const s32       _ICODE_NULLDISPLAY                              = 2173;
	const s32       _ICODE_OBJECTS                                  = 2174;
	const s32       _ICODE_OBJECT                                   = 2175;
	const s32       _ICODE_ODOMETER                                 = 2176;
	const s32       _ICODE_OFF                                      = 2177;
	const s32       _ICODE_OF                                       = 2178;
	const s32       _ICODE_OLEOBJECT                                = 2179;
	const s32       _ICODE_OPEN                                     = 2180;
	const s32       _ICODE_OPTIMIZE                                 = 2181;
//	const s32       _ICODE_OR                                       = 2182;
	const s32       _ICODE_PACK                                     = 2183;
	const s32       _ICODE_PAGE                                     = 2184;
	const s32       _ICODE_PALETTE                                  = 2185;
	const s32       _ICODE_PATH                                     = 2186;
	const s32       _ICODE_PDSETUP                                  = 2187;
	const s32       _ICODE_PLAY                                     = 2188;
	const s32       _ICODE_POINT                                    = 2189;
	const s32       _ICODE_POP                                      = 2190;
	const s32       _ICODE_POPUPS                                   = 2191;
	const s32       _ICODE_PRINTER                                  = 2192;
	const s32       _ICODE_PRINTJOB                                 = 2193;
	const s32       _ICODE_PRIVATE                                  = 2194;
	const s32       _ICODE_PROCEDURES                               = 2195;
	const s32       _ICODE_PROCEDURE                                = 2196;
	const s32       _ICODE_PROJECT                                  = 2197;
	const s32       _ICODE_PUBLIC                                   = 2198;
	const s32       _ICODE_PUSH                                     = 2199;
	const s32       _ICODE_QUERY                                    = 2200;
	const s32       _ICODE_QUIT                                     = 2201;
	const s32       _ICODE_RD                                       = 2202;
	const s32       _ICODE_READ                                     = 2203;
	const s32       _ICODE_READBORDER                               = 2204;
	const s32       _ICODE_READERROR                                = 2205;
	const s32       _ICODE_RECALL                                   = 2206;
	const s32       _ICODE_REINDEX                                  = 2207;
	const s32       _ICODE_RELEASE                                  = 2208;
	const s32       _ICODE_REMOVE                                   = 2209;
	const s32       _ICODE_RENAME                                   = 2210;
	const s32       _ICODE_REPLACE                                  = 2211;
	const s32       _ICODE_REPORT                                   = 2212;
	const s32       _ICODE_REPROCESS                                = 2213;
	const s32       _ICODE_RESOURCE                                 = 2214;
	const s32       _ICODE_RESTORE                                  = 2215;
	const s32       _ICODE_RESUME                                   = 2216;
	const s32       _ICODE_RETRY                                    = 2217;
	const s32       _ICODE_RETURN                                   = 2218;
	const s32       _ICODE_RMDIR                                    = 2219;
	const s32       _ICODE_ROLLBACK                                 = 2220;
	const s32       _ICODE_RUN                                      = 2221;
	const s32       _ICODE_SAFETY                                   = 2222;
	const s32       _ICODE_SAVE                                     = 2223;
	const s32       _ICODE_SAY                                      = 2224;
	const s32       _ICODE_SCAN                                     = 2225;
	const s32       _ICODE_SCATTER                                  = 2226;
	const s32       _ICODE_SCREEN                                   = 2227;
	const s32       _ICODE_SCROLL                                   = 2228;
	const s32       _ICODE_SELECTION                                = 2229;
	const s32       _ICODE_SEPARATOR                                = 2230;
	const s32       _ICODE_SHOW                                     = 2231;
	const s32       _ICODE_SHUTDOWN                                 = 2232;
	const s32       _ICODE_SIZE                                     = 2233;
	const s32       _ICODE_SKIP                                     = 2234;
	const s32       _ICODE_SORT                                     = 2235;
	const s32       _ICODE_SQL                                      = 2236;
	const s32       _ICODE_STATUS                                   = 2237;
	const s32       _ICODE_STEP                                     = 2238;
	const s32       _ICODE_STORE                                    = 2239;
	const s32       _ICODE_STRICTDATE                               = 2240;
	const s32       _ICODE_STRUCTURE                                = 2241;
	const s32       _ICODE_SUM                                      = 2242;
	const s32       _ICODE_SUSPEND                                  = 2243;
	const s32       _ICODE_SYSFORMATS                               = 2244;
	const s32       _ICODE_SYSMENU                                  = 2245;
	const s32       _ICODE_TABLEVALIDATE                            = 2246;
	const s32       _ICODE_TABLES                                   = 2247;
	const s32       _ICODE_TABLE                                    = 2248;
	const s32       _ICODE_TALK                                     = 2249;
	const s32       _ICODE_TEXT                                     = 2250;
	const s32       _ICODE_TO                                       = 2251;
	const s32       _ICODE_TOPIC                                    = 2252;
	const s32       _ICODE_TOTAL                                    = 2253;
	const s32       _ICODE_TRANSACTION                              = 2254;
	const s32       _ICODE_TRBETWEEN                                = 2255;
	const s32       _ICODE_TRIGGER                                  = 2256;
	const s32       _ICODE_TRY                                      = 2257;
	const s32       _ICODE_TYPEAHEAD                                = 2258;
	const s32       _ICODE_UDFPARMS                                 = 2259;
	const s32       _ICODE_UNLOCK                                   = 2260;
	const s32       _ICODE_UPDATE                                   = 2261;
	const s32       _ICODE_USE                                      = 2262;
	const s32       _ICODE_VALIDATE                                 = 2263;
	const s32       _ICODE_VIEWS                                    = 2264;
	const s32       _ICODE_VIEW                                     = 2265;
	const s32       _ICODE_WAIT                                     = 2266;
	const s32       _ICODE_WHILE                                    = 2267;
	const s32       _ICODE_WINDOWS                                  = 2268;
	const s32       _ICODE_WINDOW                                   = 2269;
	const s32       _ICODE_WITH                                     = 2270;
	const s32       _ICODE_ZAP                                      = 2271;
	// _ICODE_DOCASE												= 2272;
	// _ICODE_DOFORM												= 2273;
	// _ICODE_DOPROGRAM												= 2274;
	// _ICODE_DOWHILE												= 2275;
	// _ICODE_ENDFUNCTION											= 2276;
	// _ICODE_ENDPROCEDURE											= 2277;
	// _ICODE_LELSE													= 2278;
	// _ICODE_LIF													= 2279;
	// _ICODE_ELSE													= 2280;
	// _ICODE_LESLE													= 2281;
	// _ICODE_LESLEIF												= 2282;
	// _ICODE_FELSEIF												= 2283;
	// _ICODE_FIF													= 2284;


//////////
// VXB iCat codes
//////
	const s32		_ICAT_DOT_VARIABLE								= 100;	// The . in thisForm.xyz
	const s32		_ICAT_EXCLAMATION_POINT_VARIABLE				= 101;	// The ! in thisForm!xyz
