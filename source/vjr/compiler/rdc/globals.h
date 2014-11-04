//////////
//
// /libsf/source/vjr/compiler/rdc/globals.h
//
//////
// Version 0.54
// Copyright (c) 2014 by Rick C. Hodgin
//////
// Last update:
//     Nov.02.2014
//////
// Change log:
//     Nov.02.2014 - Initial creation
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
//	   http://www.libsf.org/
//	   http://www.libsf.org/licenses/
//	   http://www.visual-freepro.org/vjr/indexmain.html
//	   http://www.visual-freepro.org/wiki/index.php/PBL
//
// Thank you.  And may The Lord bless you richly as you lift up your life, your
// talents, your gifts, your praise, unto Him.	In Jesus' name I pray.	Amen.
//
//




//////////
// Syntax highlight colors for RDC
//////
	SBgra			colorSynHi_type					= { rgba(0, 128, 192, 255) };			// Cyanish




//////////
// iCodes specific to RDC
//////
	cs32		_ICODE_VOID				    = 200000;
	cs32		_ICODE_BOOL				    = 200001;
	cs32		_ICODE_CHAR				    = 200002;
	cs32		_ICODE_DATUM				= 200003;
	cs32		_ICODE_THREAD				= 200004;
	cs32		_ICODE_PROCESS				= 200005;
	cs32		_ICODE_READONLY				= 200006;
	cs32		_ICODE_READONLY				= 200007;
	cs32		_ICODE_READWRITE			= 200008;
	cs32		_ICODE_VOLATILE				= 200009;
	cs32		_ICODE_UNSIGNED				= 200010;
	cs32		_ICODE_STATIC				= 200011;
	cs32		_ICODE_EXTERN				= 200012;
	cs32		_ICODE_SIZEOF				= 200013;
	cs32		_ICODE_OFFSETOF				= 200014;
	cs32		_ICODE_NULL_POINTER			= 200015;
	cs32		_ICODE_NULL_VALUE			= 200016;
	cs32		_ICODE_PRAGMA_DEFINE		= 200017;
	cs32		_ICODE_PRAGMA_UNDEFINE		= 200018;
	cs32		_ICODE_PRAGMA_IF			= 200019;
	cs32		_ICODE_PRAGMA_IFDEF			= 200020;
	cs32		_ICODE_PRAGMA_IFNDEF		= 200021;
	cs32		_ICODE_PRAGMA_ELSE			= 200022;
	cs32		_ICODE_PRAGMA_ELSEIF		= 200023;
	cs32		_ICODE_PRAGMA_ENDIF			= 200024;
	cs32		_ICODE_PRAGMA_ALIGN			= 200025;
	cs32		_ICODE_PRAGMA_PUSH			= 200026;
	cs32		_ICODE_PRAGMA_POP			= 200027;
	cs32		_ICODE_PRAGMA_TYPEDEF		= 200028;
	cs32		_ICODE_STRUCT				= 200029;
	cs32		_ICODE_EXTENDS				= 200030;
	cs32		_ICODE_CHILD				= 200031;
	cs32		_ICODE_UNION				= 200032;
	cs32		_ICODE_ENUM				    = 200033;
	cs32		_ICODE_NEW					= 200034;
	cs32		_ICODE_UNTIL				= 200035;
	cs32		_ICODE_ITERATE				= 200036;
	cs32		_ICODE_UNLESS				= 200037;
	cs32		_ICODE_ELSEIF				= 200038;
	cs32		_ICODE_SWITCH				= 200039;
	cs32		_ICODE_ANDIN				= 200040;
	cs32		_ICODE_OUT					= 200041;
	cs32		_ICODE_TIMEOUT				= 200042;
	cs32		_ICODE_OKAY					= 200043;
	cs32		_ICODE_ENGAGE				= 200044;
	cs32		_ICODE_UNENGAGE				= 200045;
	cs32		_ICODE_BREAK				= 200046;
	cs32		_ICODE_BREAK_TO				= 200047;
	cs32		_ICODE_CONTINUE_TO			= 200048;
	cs32		_ICODE_EXIT_TO              = 200049;
	cs32		_ICODE_LOOP_TO				= 200050;
	cs32		_ICODE_FLOWOUT_TO			= 200051;
	cs32		_ICODE_DLLMAIN				= 200052;




//////////
// Keywords for RDC
//////
	SAsciiCompSearcher	cgcKeywordsRdc[] =
	{
		// keyword					length		repeats?	extra (type)							first on line?		category			syntax highlight color		syntax highlight bold
		{ "void",					4,			false,		_ICODE_VOID,							false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },
		{ "bool",					4,			false,		_ICODE_BOOL,							false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },
		{ "char",					4,			false,		_ICODE_CHAR,							false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },
		{ "int",					3,			false,		_ICODE_INT,								false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },
		{ "float",					5,			false,		_ICODE_FLOAT,							false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },
		{ "double",					6,			false,		_ICODE_DOUBLE,							false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },
		{ "bool",					4,			false,		_ICODE_LOGICAL,							false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },

		{ "s8",						2,			false,		_ICODE_S8,								false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },
		{ "u8",						2,			false,		_ICODE_U8,								false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },
		{ "s16",					3,			false,		_ICODE_S16,								false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },
		{ "u16",					3,			false,		_ICODE_U16,								false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },
		{ "s32",					3,			false,		_ICODE_S32,								false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },
		{ "u32",					3,			false,		_ICODE_U32,								false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },
		{ "s64",					3,			false,		_ICODE_S64,								false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },
		{ "u64",					3,			false,		_ICODE_U64,								false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },
		{ "f32",					3,			false,		_ICODE_F32,								false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },
		{ "f64",					3,			false,		_ICODE_F64,								false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },

		{ "bi",						2,			false,		_ICODE_BI,								false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },
		{ "bfp",					3,			false,		_ICODE_BFP,								false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },
		{ "datum",					5,			false,		_ICODE_DATUM,							false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },
		{ "date",					4,			false,		_ICODE_DATE,							false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },
		{ "datetime",				8,			false,		_ICODE_DATETIME,						false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },
		{ "thread",					6,			false,		_ICODE_THREAD,							false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },
		{ "process",				7,			false,		_ICODE_PROCESS,							false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },

		{ "const",					5,			false,		_ICODE_READONLY,						false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },
		{ "ro",						2,			false,		_ICODE_READONLY,						false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },
		{ "rw",						2,			false,		_ICODE_READWRITE,						false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },
		{ "volatile",				8,			false,		_ICODE_VOLATILE,						false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },
		{ "unsigned",				8,			false,		_ICODE_UNSIGNED,						false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },
		{ "static",					5,			false,		_ICODE_STATIC,							false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },
		{ "extern",					5,			false,		_ICODE_EXTERN,							false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },
		{ "sizeof",					5,			false,		_ICODE_SIZEOF,							false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },
		{ "offsetof",				7,			false,		_ICODE_OFFSETOF,						false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },

		// Signed compare on these tokens, so length is negative
		{ "NULL",					-4,			false,		_ICODE_NULL_POINTER,					false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },
		{ "null",					-4,			false,		_ICODE_NULL_VALUE,						false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },

		{ "true",					4,			false,		_ICODE_TRUE,							false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },
		{ "false",					4,			false,		_ICODE_FALSE,							false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },

		{ "and",					3,			false,		_ICODE_AND,								false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },
		{ "or",						2,			false,		_ICODE_OR,								false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },
		{ "not",					3,			false,		_ICODE_NOT,								false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },

		{ "#define",				7,			false,		_ICODE_PRAGMA_DEFINE,					false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },
		{ "#undefine",				9,			false,		_ICODE_PRAGMA_UNDEFINE,					false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },
		{ "#if",					3,			false,		_ICODE_PRAGMA_IF,						false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },
		{ "#ifdef",					6,			false,		_ICODE_PRAGMA_IFDEF,					false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },
		{ "#ifndef",				7,			false,		_ICODE_PRAGMA_IFNDEF,					false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },
		{ "#else",					5,			false,		_ICODE_PRAGMA_ELSE,						false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },
		{ "#elseif",				7,			false,		_ICODE_PRAGMA_ELSEIF,					false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },
		{ "#endif",					6,			false,		_ICODE_PRAGMA_ENDIF,					false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },
		{ "#align",					6,			false,		_ICODE_PRAGMA_ALIGN,					false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },
		{ "#push",					5,			false,		_ICODE_PRAGMA_PUSH,						false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },
		{ "#pop",					4,			false,		_ICODE_PRAGMA_POP,						false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },
		{ "typedef",				7,			false,		_ICODE_PRAGMA_TYPEDEF,					false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },

		{ "struct",					6,			false,		_ICODE_STRUCT,							false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },
		{ "class",					5,			false,		_ICODE_CLASS,							false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },
		{ "operator",				8,			false,		_ICODE_OPERATOR,						false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },
		{ "extends",				7,			false,		_ICODE_EXTENDS,							false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },
		{ "parent",					6,			false,		_ICODE_PARENT,							false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },
		{ "child",					5,			false,		_ICODE_CHILD,							false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },
		{ "union",					5,			false,		_ICODE_UNION,							false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },
		{ "enum",					4,			false,		_ICODE_ENUM,							false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },
		{ "new",					3,			false,		_ICODE_NEW,								false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },
		{ "delete",					6,			false,		_ICODE_DELETE,							false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },

		{ "adhoc",					5,			false,		_ICODE_DELETE,							false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },
		{ "function",				8,			false,		_ICODE_DELETE,							false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },
		{ "params",					6,			false,		_ICODE_DELETE,							false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },
		{ "returns",				7,			false,		_ICODE_DELETE,							false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },
		{ "inline",					6,			false,		_ICODE_DELETE,							false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },
		{ "optimize",				8,			false,		_ICODE_DELETE,							false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },
		{ "nodebug",				7,			false,		_ICODE_DELETE,							false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },
		{ "breakpoint",				10,			false,		_ICODE_DELETE,							false,				_ICAT_TYPE,			&colorSynHi_type,			false,						null },

		{ "do",						2,			false,		_ICODE_DO,								false,				_ICAT_GENERIC,		&colorSynHi_command,		true,						null },
		{ "while",					5,			false,		_ICODE_WHILE,							false,				_ICAT_GENERIC,		&colorSynHi_command,		true,						null },
		{ "until",					5,			false,		_ICODE_UNTIL,							false,				_ICAT_GENERIC,		&colorSynHi_command,		true,						null },
		{ "iterate",				8,			false,		_ICODE_ITERATE,							false,				_ICAT_GENERIC,		&colorSynHi_command,		true,						null },
		{ "for",					3,			false,		_ICODE_FOR,								false,				_ICAT_GENERIC,		&colorSynHi_command,		true,						null },
		{ "unless",					6,			false,		_ICODE_UNLESS,							false,				_ICAT_GENERIC,		&colorSynHi_command,		true,						null },
		{ "if",						2,			false,		_ICODE_IF,								false,				_ICAT_GENERIC,		&colorSynHi_command,		true,						null },
		{ "else",					4,			false,		_ICODE_ELSE,							false,				_ICAT_GENERIC,		&colorSynHi_command,		true,						null },
		{ "elseif",					6,			false,		_ICODE_ELSEIF,							false,				_ICAT_GENERIC,		&colorSynHi_command,		true,						null },
		{ "switch",					6,			false,		_ICODE_SWITCH,							false,				_ICAT_GENERIC,		&colorSynHi_command,		true,						null },
		{ "case",					4,			false,		_ICODE_CASE,							false,				_ICAT_GENERIC,		&colorSynHi_command,		true,						null },
		{ "meta",					4,			false,		_ICODE_META,							false,				_ICAT_GENERIC,		&colorSynHi_command,		true,						null },
		{ "mefa",					4,			false,		_ICODE_MEFA,							false,				_ICAT_GENERIC,		&colorSynHi_command,		true,						null },
		{ "quit",					4,			false,		_ICODE_QUIT,							false,				_ICAT_GENERIC,		&colorSynHi_command,		true,						null },

		{ "in",						2,			false,		_ICODE_IN,								false,				_ICAT_GENERIC,		&colorSynHi_command,		true,						null },
		{ "andin",					5,			false,		_ICODE_ANDIN,							false,				_ICAT_GENERIC,		&colorSynHi_command,		true,						null },
		{ "out",					3,			false,		_ICODE_OUT,								false,				_ICAT_GENERIC,		&colorSynHi_command,		true,						null },
		{ "join",					4,			false,		_ICODE_JOIN,							false,				_ICAT_GENERIC,		&colorSynHi_command,		true,						null },
		{ "timeout",				7,			false,		_ICODE_TIMEOUT,							false,				_ICAT_GENERIC,		&colorSynHi_command,		true,						null },
		{ "okay",					4,			false,		_ICODE_OKAY,							false,				_ICAT_GENERIC,		&colorSynHi_command,		true,						null },

		{ "engage",					6,			false,		_ICODE_ENGAGE,							false,				_ICAT_GENERIC,		&colorSynHi_command,		true,						null },
		{ "unengage",				8,			false,		_ICODE_UNENGAGE,						false,				_ICAT_GENERIC,		&colorSynHi_command,		true,						null },

		{ "default",				7,			false,		_ICODE_DEFAULT,							false,				_ICAT_GENERIC,		&colorSynHi_command,		true,						null },
		{ "break",					5,			false,		_ICODE_BREAK,							false,				_ICAT_GENERIC,		&colorSynHi_command,		true,						null },
		{ "breakto",				7,			false,		_ICODE_BREAK_TO,						false,				_ICAT_GENERIC,		&colorSynHi_command,		true,						null },
		{ "continue",				8,			false,		_ICODE_CONTINUE,						false,				_ICAT_GENERIC,		&colorSynHi_command,		true,						null },
		{ "continueto",				10,			false,		_ICODE_CONTINUE_TO,						false,				_ICAT_GENERIC,		&colorSynHi_command,		true,						null },
		{ "exit",					4,			false,		_ICODE_EXIT,							false,				_ICAT_GENERIC,		&colorSynHi_command,		true,						null },
		{ "exitto",					6,			false,		_ICODE_EXIT_TO,							false,				_ICAT_GENERIC,		&colorSynHi_command,		true,						null },
		{ "loop",					4,			false,		_ICODE_LOOP,							false,				_ICAT_GENERIC,		&colorSynHi_command,		true,						null },
		{ "loopto",					6,			false,		_ICODE_LOOP_TO,							false,				_ICAT_GENERIC,		&colorSynHi_command,		true,						null },
		{ "goto",					4,			false,		_ICODE_GOTO,							false,				_ICAT_GENERIC,		&colorSynHi_command,		true,						null },
		{ "return",					4,			false,		_ICODE_RETURN,							false,				_ICAT_GENERIC,		&colorSynHi_command,		true,						null },

		{ "flow",					4,			false,		_ICODE_FLOW,							false,				_ICAT_GENERIC,		&colorSynHi_command,		true,						null },
		{ "flowout",				7,			false,		_ICODE_FLOWOUT,							false,				_ICAT_GENERIC,		&colorSynHi_command,		true,						null },
		{ "flowoutto",				9,			false,		_ICODE_FLOWOUT_TO,						false,				_ICAT_GENERIC,		&colorSynHi_command,		true,						null },
		{ "flowto",					6,			false,		_ICODE_FLOWTO,							false,				_ICAT_GENERIC,		&colorSynHi_command,		true,						null },
		{ "subflow",				7,			false,		_ICODE_SUBFLOW,							false,				_ICAT_GENERIC,		&colorSynHi_command,		true,						null },
		{ "meia",					4,			false,		_ICODE_MERA,							false,				_ICAT_GENERIC,		&colorSynHi_command,		true,						null },
		{ "mema",					4,			false,		_ICODE_MEMA,							false,				_ICAT_GENERIC,		&colorSynHi_command,		true,						null },

		{ "flowof",					6,			false,		_ICODE_FLOWOF,							false,				_ICAT_GENERIC,		&colorSynHi_command,		true,						null },

		{ "main",					4,			false,		_ICODE_MAIN,							false,				_ICAT_GENERIC,		&colorSynHi_command,		false,						null },
		{ "dllmain",				4,			false,		_ICODE_DLLMAIN,							false,				_ICAT_GENERIC,		&colorSynHi_command,		false,						null },

	};
