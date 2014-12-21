//////////
//
// /libsf/source/vjr/compiler/common/compiler_common.h
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
// Constant integers
//////
	cu32			_COMMON_START_END_BLOCK_SIZE					= 32;			// Allocate 32 entries/slots at a time (Start/end)
	cu32			_COMMON_START_END_SMALL_BLOCK_SIZE				= 4;			// Allocate 4 entries/slots at a time (Start/end)
	cu32			_COMMON_START_END_BIG_BLOCK_SIZE				= 256;			// Allocate 256 entries/slots at a time (Start/end)
	cu32			_COMMON_BUILDER_BLOCK_SIZE						= 16384;		// Allocate 16KB at a time
	cu32			_COMMON_BUILDER_BLOCK_SIZE_BIG					= 10240000;		// Allocate 1MB at a time


//////////
// iCat values
//////
	const s32		_ICAT_GENERIC									= 1;
	const s32		_ICAT_COMMAND									= 2;
	const s32		_ICAT_FUNCTION									= 3;
	const s32		_ICAT_FLOW										= 4;
	const s32		_ICAT_OPERATOR									= 5;
	const s32		_ICAT_CASK										= 6;
	const s32		_ICAT_OPTION									= 7;	// An option like AGAIN on USE xyz AGAIN


/////////
// iCode values
//////
	cs32			_ICODE_CASK_SIDE_MINIMUM						= 1000001;
	cs32			_ICODE_CASK_ROUND_OPEN_PARAMS					= 1000001;
	cs32			_ICODE_CASK_ROUND_CLOSE_PARAMS					= 1000002;
	cs32			_ICODE_CASK_SQUARE_OPEN_PARAMS					= 1000003;
	cs32			_ICODE_CASK_SQUARE_CLOSE_PARAMS					= 1000004;
	cs32			_ICODE_CASK_TRIANGLE_OPEN_PARAMS				= 1000005;
	cs32			_ICODE_CASK_TRIANGLE_CLOSE_PARAMS				= 1000006;
	cs32			_ICODE_CASK_TILDE_OPEN_PARAMS					= 1000007;
	cs32			_ICODE_CASK_TILDE_CLOSE_PARAMS					= 1000008;
	cs32			_ICODE_CASK_ROUND_OPEN							= 1000009;
	cs32			_ICODE_CASK_ROUND_CLOSE							= 1000010;
	cs32			_ICODE_CASK_SQUARE_OPEN							= 1000011;
	cs32			_ICODE_CASK_SQUARE_CLOSE						= 1000012;
	cs32			_ICODE_CASK_TRIANGLE_OPEN						= 1000013;
	cs32			_ICODE_CASK_TRIANGLE_CLOSE						= 1000014;
	cs32			_ICODE_CASK_TILDE_OPEN							= 1000015;
	cs32			_ICODE_CASK_TILDE_CLOSE							= 1000016;
	cs32			_ICODE_CASK_SIDE_MAXIMUM						= 1000016;

	cs32			_ICODE_CASK_MINIMUM								= 1000101;
	cs32			_ICODE_CASK_ROUND_PARAMS						= 1000101;
	cs32			_ICODE_CASK_SQUARE_PARAMS						= 1000102;
	cs32			_ICODE_CASK_TRIANGLE_PARAMS						= 1000103;
	cs32			_ICODE_CASK_TILDE_PARAMS						= 1000104;
	cs32			_ICODE_CASK_ROUND								= 1000105;
	cs32			_ICODE_CASK_SQUARE								= 1000106;
	cs32			_ICODE_CASK_TRIANGLE							= 1000107;
	cs32			_ICODE_CASK_TILDE								= 1000108;
	cs32			_ICODE_CASK_MAXIMUM								= 1000108;

	// Standard types
	cs32			_ICODE_UNKNOWN									= -1;
	cs32			_ICODE_ALPHA									= 1;
	cs32			_ICODE_NUMERIC									= 2;
	cs32			_ICODE_ALPHANUMERIC								= 3;
	cs32			_ICODE_OPERATOR									= 4;
	cs32			_ICODE_WHITESPACE								= 5;
	cs32			_ICODE_PLUS										= 6;
	cs32			_ICODE_HYPHEN									= 7;
	cs32			_ICODE_ASTERISK								= 8;
	cs32			_ICODE_MULTIPLY								= 8;
	cs32			_ICODE_BACKSLASH								= 9;
	cs32			_ICODE_DOUBLE_QUOTE								= 10;
	cs32			_ICODE_SINGLE_QUOTE								= 11;
	cs32			_ICODE_TILDE									= 12;
	cs32			_ICODE_DOT										= 13;
	cs32			_ICODE_COLON									= 14;
	cs32			_ICODE_COMMA									= 15;
	cs32			_ICODE_UNDERSCORE								= 16;
	cs32			_ICODE_AT_SIGN									= 17;
	cs32			_ICODE_QUESTION_MARK							= 18;
	cs32			_ICODE_EXCLAMATION_POINT						= 19;
	cs32			_ICODE_POUND_SIGN								= 20;
	cs32			_ICODE_PERCENT_SIGN								= 21;
	cs32			_ICODE_EXPONENT									= 22;
	cs32			_ICODE_AMPERSAND								= 23;
	cs32			_ICODE_EQUAL_SIGN								= 24;
	cs32			_ICODE_PIPE_SIGN								= 25;
	cs32			_ICODE_REVERSE_QUOTE							= 26;
	cs32			_ICODE_SEMICOLON								= 27;
	cs32			_ICODE_GREATER_THAN								= 28;
	cs32			_ICODE_LESS_THAN								= 30;
	cs32			_ICODE_PARENTHESIS_LEFT							= 31;
	cs32			_ICODE_PARENTHESIS_RIGHT						= 32;
	cs32			_ICODE_BRACKET_LEFT								= 33;
	cs32			_ICODE_BRACKET_RIGHT							= 34;
	cs32			_ICODE_BRACE_LEFT								= 35;
	cs32			_ICODE_BRACE_RIGHT								= 36;
	cs32			_ICODE_SLASH									= 37;
	cs32			_ICODE_FOUND_IN									= 38;
	cs32			_ICODE_PLUS_PLUS								= 39;
	cs32			_ICODE_MINUS_MINUS								= 40;
	cs32			_ICODE_NOT_EQUAL								= 41;
	cs32			_ICODE_LESS_THAN_OR_EQUAL_TO					= 42;
	cs32			_ICODE_GREATER_THAN_OR_EQUAL_TO					= 43;
	cs32			_ICODE_EXACTLY_EQUAL_TO							= 44;
	cs32			_ICODE_NOT_FOUND_IN								= 45;
	cs32			_ICODE_SHIFT_LEFT								= 46;
	cs32			_ICODE_SHIFT_RIGHT								= 47;
	cs32			_ICODE_SHIFT_LEFT_ASSIGNMENT					= 48;
	cs32			_ICODE_SHIFT_RIGHT_ASSIGNMENT					= 49;
	cs32			_ICODE_RANGE									= 50;
	cs32			_ICODE_ADD_EQUAL								= 51;
	cs32			_ICODE_MINUS_EQUAL								= 52;
	cs32			_ICODE_XOR_EQUAL								= 53;
	cs32			_ICODE_MULTIPLY_EQUAL							= 54;
	cs32			_ICODE_DIVIDE_EQUAL								= 55;
	cs32			_ICODE_MODULO_EQUAL								= 56;
	cs32			_ICODE_OR_ASSIGNMENT							= 57;
	cs32			_ICODE_DOLLAR_SIGN								= 58;

	// Preprocessor
	cs32			_ICODE_DEFINE_PRAGMA							= 101;
	cs32			_ICODE_ELSE_PRAGMA								= 102;
	cs32			_ICODE_ELSEIF_PRAGMA							= 103;
	cs32			_ICODE_IF_PRAGMA								= 104;
	cs32			_ICODE_IFDEF_PRAGMA								= 105;
	cs32			_ICODE_IFNDEF_PRAGMA							= 106;
	cs32			_ICODE_INCLUDE_PRAGMA							= 107;
	cs32			_ICODE_UNDEF_PRAGMA								= 108;
	cs32			_ICODE_ENDIF_PRAGMA								= 109;

	// Miscellaneous
	cs32			_ICODE_COMMENT									= 150;
	cs32			_ICODE_LINE_COMMENT								= 151;
	cs32			_ICODE_COMMENT_START							= 152;
	cs32			_ICODE_COMMENT_END								= 153;

	// Logical operators
	const s32		_ICODE_NOT										= 500;
	const s32		_ICODE_AND										= 501;
	const s32		_ICODE_OR										= 502;




//////////
// Syntax highlight colors
//////
	SBgra			colorSynHi_comment1					= { rgba(0, 148, 0, 255) };				// Green
	SBgra			colorSynHi_comment2					= { rgba(148, 64, 148, 255) };			// Green+Cyan
	SBgra			colorSynHi_comment3					= { rgba(148, 64, 148, 255) };			// Dark purple
	SBgra			colorSynHi_function					= { rgba(164, 128, 0, 255) };			// Golden
	SBgra			colorSynHi_command					= { rgba(64, 128, 245, 255) };			// Pastel cyan-blue
	SBgra			colorSynHi_logical					= { rgba(200, 148, 0, 255) };			// Orange
	SBgra			colorSynHi_numeric					= { rgba(0, 128, 255, 255) };			// Cyan-blue
	SBgra			colorSynHi_operator					= { rgba(128, 0, 164, 255) };			// Purplish
	SBgra			colorSynHi_bracket					= { rgba(128, 0, 0, 255) };				// Red
	SBgra			colorSynHi_pragmas					= { rgba(192, 192, 192, 255) };			// Gray
	SBgra			colorSynHi_variable					= { rgba(255, 128, 0, 255) };			// Orange
	SBgra			colorSynHi_quotedText				= { rgba(235, 128, 128, 255) };			// Reddish




//////////
// Added to identify any tokens in alpha blocks which may have non-breaking-space characters
// The comp->nbspCount allows them to be rendered properly in displayed form
//////
	void ii_onFind_countNbsp(SAsciiCompSearcher* tacs, SComp* comp)
	{
		s32 lnI;


		//////////
		// Iterate through every character counting the nbsp
		//////
			for (lnI = 0; lnI < comp->length; lnI++)
			{
				// If it's a nbsp, increase the count
				if (comp->line->sourceCode->data_u8[comp->start + lnI] == 255)
					++comp->nbspCount;
			}
	}




//////////
// Casks
//////
	cs8			cgcCaskRoundOpenParams[]						= "(||";
	cs8			cgcCaskRoundCloseParams[]						= "||)";
	cs8			cgcCaskSquareOpenParams[]						= "[||";
	cs8			cgcCaskSquareCloseParams[]						= "||]";
	cs8			cgcCaskTriangleOpenParams[]						= "<||";
	cs8			cgcCaskTriangleCloseParams[]					= "||>";
	cs8			cgcCaskTildeOpenParams[]						= "~||";
	cs8			cgcCaskTildeCloseParams[]						= "||~";
	cs8			cgcCaskRoundOpen[]								= "(|";
	cs8			cgcCaskRoundClose[]								= "|)";
	cs8			cgcCaskSquareOpen[]								= "[|";
	cs8			cgcCaskSquareClose[]							= "|]";
	cs8			cgcCaskTriangleOpen[]							= "<|";
	cs8			cgcCaskTriangleClose[]							= "|>";
	cs8			cgcCaskTildeOpen[]								= "~|";
	cs8			cgcCaskTildeClose[]								= "|~";

	cs8			cgcDefinePragma[]								= "#define";
	cs8			cgcElsePragma[]									= "#else";
	cs8			cgcElseifPragma[]								= "#elseif";
	cs8			cgcEndifPragma[]								= "#endif";
	cs8			cgcIfPragma[]									= "#if";
	cs8			cgcIfdefPragma[]								= "#ifdef";
	cs8			cgcIfndefPragma[]								= "#ifndef";
	cs8			cgcIncludePragma[]								= "#include";
	cs8			cgcUndefPragma[]								= "#undef";




//////////
// Basic symbols known to VXB
/////
	SAsciiCompSearcher	cgcFundamentalSymbols[] =
	{
		// keyword					length		repeats?	extra (type)							first on line?		category			syntax highlight color		syntax highlight bold		onFind()
		// (||round params||)
		{ cgcCaskRoundOpenParams,	3,			false,		_ICODE_CASK_ROUND_OPEN_PARAMS,			false,				_ICAT_CASK,			NULL,						false,						null	},
		{ cgcCaskRoundCloseParams,	3,			false,		_ICODE_CASK_ROUND_CLOSE_PARAMS,			false,				_ICAT_CASK,			NULL,						false,						null	},
		// [||square params||]null
		{ cgcCaskSquareOpenParams,	3,			false,		_ICODE_CASK_SQUARE_OPEN_PARAMS,			false,				_ICAT_CASK,			NULL,						false,						null	},
		{ cgcCaskSquareCloseParams,	3,			false,		_ICODE_CASK_SQUARE_CLOSE_PARAMS,		false,				_ICAT_CASK,			NULL,						false,						null	},
		// <||triangle params||>null
		{ cgcCaskTriangleOpenParams,3,			false,		_ICODE_CASK_TRIANGLE_OPEN_PARAMS,		false,				_ICAT_CASK,			NULL,						false,						null	},
		{ cgcCaskTriangleCloseParams,3,			false,		_ICODE_CASK_TRIANGLE_CLOSE_PARAMS,		false,				_ICAT_CASK,			NULL,						false,						null	},
		// ~||tilde params||~null
		{ cgcCaskTildeOpenParams,	3,			false,		_ICODE_CASK_TILDE_OPEN_PARAMS,			false,				_ICAT_CASK,			NULL,						false,						null	},
		{ cgcCaskTildeCloseParams,	3,			false,		_ICODE_CASK_TILDE_CLOSE_PARAMS,			false,				_ICAT_CASK,			NULL,						false,						null	},
		// (|round|)null
		{ cgcCaskRoundOpen,			2,			false,		_ICODE_CASK_ROUND_OPEN,					false,				_ICAT_CASK,			NULL,						false,						null	},
		{ cgcCaskRoundClose,		2,			false,		_ICODE_CASK_ROUND_CLOSE,				false,				_ICAT_CASK,			NULL,						false,						null	},
		// [|square|]null
		{ cgcCaskSquareOpen,		2,			false,		_ICODE_CASK_SQUARE_OPEN,				false,				_ICAT_CASK,			NULL,						false,						null	},
		{ cgcCaskSquareClose,		2,			false,		_ICODE_CASK_SQUARE_CLOSE,				false,				_ICAT_CASK,			NULL,						false,						null	},
		// <|triangle|>null
		{ cgcCaskTriangleOpen,		2,			false,		_ICODE_CASK_TRIANGLE_OPEN,				false,				_ICAT_CASK,			NULL,						false,						null	},
		{ cgcCaskTriangleClose,		2,			false,		_ICODE_CASK_TRIANGLE_CLOSE,				false,				_ICAT_CASK,			NULL,						false,						null	},
		// ~|tilde|~null
		{ cgcCaskTildeOpen,			2,			false,		_ICODE_CASK_TILDE_OPEN,					false,				_ICAT_GENERIC,		NULL,						false,						null	},
		{ cgcCaskTildeClose,		2,			false,		_ICODE_CASK_TILDE_CLOSE,				false,				_ICAT_GENERIC,		NULL,						false,						null	},

		// Native characters and symbols
		// Note:  If it begins with an underscore, it then uses pairs of characters for a range until it reaches trailing nullsnull
		{ "_azAZ\377\377__\000\000",1,			true,		_ICODE_ALPHA,							false,				_ICAT_GENERIC,		NULL,						false,						(uptr)&ii_onFind_countNbsp	},
		{ "_09\000\000",			1,			true,		_ICODE_NUMERIC,							false,				_ICAT_GENERIC,		&colorSynHi_numeric,		false,						(uptr)&ii_onFind_countNbsp	},
		{ " ",						1,			true,		_ICODE_WHITESPACE,						false,				_ICAT_GENERIC,		&colorSynHi_comment1,		false,						null	},
		{ "\t",						1,			true,		_ICODE_WHITESPACE,						false,				_ICAT_GENERIC,		&colorSynHi_comment1,		false,						null	},
		{ "___",					1,			false,		_ICODE_UNDERSCORE,						false,				_ICAT_GENERIC,		NULL,						false,						null	},
		{ "(",						1,			false,		_ICODE_PARENTHESIS_LEFT,				false,				_ICAT_GENERIC,		&colorSynHi_bracket,		true,						null	},
		{ ")",						1,			false,		_ICODE_PARENTHESIS_RIGHT,				false,				_ICAT_GENERIC,		&colorSynHi_bracket,		true,						null	},
		{ "[",						1,			false,		_ICODE_BRACKET_LEFT,					false,				_ICAT_GENERIC,		&colorSynHi_bracket,		true,						null	},
		{ "]",						1,			false,		_ICODE_BRACKET_RIGHT,					false,				_ICAT_GENERIC,		&colorSynHi_bracket,		true,						null	},
		{ "{",						1,			false,		_ICODE_BRACE_LEFT,						false,				_ICAT_GENERIC,		&colorSynHi_bracket,		true,						null	},
		{ "}",						1,			false,		_ICODE_BRACE_RIGHT,						false,				_ICAT_GENERIC,		&colorSynHi_bracket,		true,						null	},
		{ "++",						2,			false,		_ICODE_PLUS_PLUS,						false,				_ICAT_GENERIC,		&colorSynHi_operator,		true,						null	},
		{ "+=",						2,			false,		_ICODE_ADD_EQUAL,						false,				_ICAT_GENERIC,		&colorSynHi_operator,		false,						null	},
		{ "+",						1,			false,		_ICODE_PLUS,							false,				_ICAT_GENERIC,		&colorSynHi_operator,		true,						null	},
		{ "--",						2,			false,		_ICODE_MINUS_MINUS,						false,				_ICAT_GENERIC,		&colorSynHi_operator,		true,						null	},
		{ "-=",						2,			false,		_ICODE_MINUS_EQUAL,						false,				_ICAT_GENERIC,		&colorSynHi_operator,		false,						null	},
		{ "-",						1,			false,		_ICODE_HYPHEN,							false,				_ICAT_GENERIC,		&colorSynHi_operator,		true,						null	},
		{ "^=",						2,			false,		_ICODE_XOR_EQUAL,						false,				_ICAT_GENERIC,		&colorSynHi_operator,		false,						null	},
		{ "^",						1,			false,		_ICODE_EXPONENT,						false,				_ICAT_GENERIC,		&colorSynHi_operator,		true,						null	},
		{ "/*",						2,			true,		_ICODE_COMMENT_START,					false,				_ICAT_GENERIC,		&colorSynHi_comment3,		false,						null	},
		{ "*/",						2,			true,		_ICODE_COMMENT_END,						false,				_ICAT_GENERIC,		&colorSynHi_comment3,		false,						null	},
		{ "//",						2,			true,		_ICODE_COMMENT,							true,				_ICAT_GENERIC,		&colorSynHi_comment1,		false,						null	},
		{ "*=",						2,			false,		_ICODE_MULTIPLY_EQUAL,					false,				_ICAT_GENERIC,		&colorSynHi_operator,		false,						null	},
		{ "*",						1,			true,		_ICODE_COMMENT,							true,				_ICAT_GENERIC,		&colorSynHi_comment1,		false,						null	},
		{ "*",						1,			false,		_ICODE_MULTIPLY,						false,				_ICAT_GENERIC,		&colorSynHi_comment1,		false,						null	},
		{ "*",						1,			true,		_ICODE_ASTERISK,						false,				_ICAT_GENERIC,		&colorSynHi_operator,		true,						null	},
		{ "\\",						1,			true,		_ICODE_BACKSLASH,						false,				_ICAT_GENERIC,		NULL,						false,						null	},
		{ "**",						2,			false,		_ICODE_EXPONENT,						false,				_ICAT_GENERIC,		NULL,						false,						null	},
		{ "/=",						2,			false,		_ICODE_DIVIDE_EQUAL,					false,				_ICAT_GENERIC,		&colorSynHi_operator,		false,						null	},
		{ "/",						1,			true,		_ICODE_SLASH,							false,				_ICAT_GENERIC,		NULL,						false,						null	},
		{ "\"",						1,			false,		_ICODE_DOUBLE_QUOTE,					false,				_ICAT_GENERIC,		NULL,						false,						null	},
		{ "'",						1,			false,		_ICODE_SINGLE_QUOTE,					false,				_ICAT_GENERIC,		NULL,						false,						null	},
		{ "..",						2,			false,		_ICODE_RANGE,							false,				_ICAT_GENERIC,		NULL,						false,						null	},
		{ ".",						1,			false,		_ICODE_DOT,								false,				_ICAT_GENERIC,		NULL,						false,						null	},
		{ ",",						1,			false,		_ICODE_COMMA,							false,				_ICAT_GENERIC,		&colorSynHi_bracket,		true,						null	},
		{ ":=",						2,			false,		_ICODE_EQUAL_SIGN,						false,				_ICAT_GENERIC,		&colorSynHi_operator,		true,						null	},
		{ ":",						1,			false,		_ICODE_COLON,							false,				_ICAT_GENERIC,		NULL,						false,						null	},
		{ "_",						1,			false,		_ICODE_UNDERSCORE,						false,				_ICAT_GENERIC,		NULL,						false,						null	},
		{ "~",						1,			false,		_ICODE_TILDE,							false,				_ICAT_GENERIC,		NULL,						false,						null	},
		{ "@",						1,			false,		_ICODE_AT_SIGN,							false,				_ICAT_GENERIC,		NULL,						false,						null	},
		{ "#",						1,			false,		_ICODE_POUND_SIGN,						false,				_ICAT_GENERIC,		&colorSynHi_operator,		false,						null	},
		{ "$",						1,			false,		_ICODE_DOLLAR_SIGN,						false,				_ICAT_GENERIC,		&colorSynHi_operator,		false,						null	},
		{ "?",						1,			false,		_ICODE_QUESTION_MARK,					false,				_ICAT_GENERIC,		NULL,						false,						null	},
		{ "!=",						2,			false,		_ICODE_NOT_EQUAL,						false,				_ICAT_GENERIC,		&colorSynHi_operator,		true,						null	},
		{ "!<",						2,			false,		_ICODE_GREATER_THAN_OR_EQUAL_TO,		false,				_ICAT_GENERIC,		&colorSynHi_operator,		true,						null	},
		{ "!>",						2,			false,		_ICODE_LESS_THAN_OR_EQUAL_TO,			false,				_ICAT_GENERIC,		&colorSynHi_operator,		true,						null	},
		{ "!<=",					3,			false,		_ICODE_GREATER_THAN,					false,				_ICAT_GENERIC,		&colorSynHi_operator,		true,						null	},
		{ "!>=",					3,			false,		_ICODE_LESS_THAN,						false,				_ICAT_GENERIC,		&colorSynHi_operator,		true,						null	},
		{ "!",						1,			false,		_ICODE_EXCLAMATION_POINT,				false,				_ICAT_GENERIC,		&colorSynHi_logical,		true,						null	},
		{ cgcDefinePragma,			7,			false,		_ICODE_DEFINE_PRAGMA,					true,				_ICAT_GENERIC,		&colorSynHi_pragmas,		false,						null	},
		{ cgcElsePragma,			5,			false,		_ICODE_ELSE_PRAGMA,						true,				_ICAT_GENERIC,		&colorSynHi_pragmas,		false,						null	},
		{ cgcElseifPragma,			7,			false,		_ICODE_ELSEIF_PRAGMA,					true,				_ICAT_GENERIC,		&colorSynHi_pragmas,		false,						null	},
		{ cgcEndifPragma,			6,			false,		_ICODE_ENDIF_PRAGMA,					true,				_ICAT_GENERIC,		&colorSynHi_pragmas,		false,						null	},
		{ cgcIfPragma,				3,			false,		_ICODE_IF_PRAGMA,						true,				_ICAT_GENERIC,		&colorSynHi_pragmas,		false,						null	},
		{ cgcIfdefPragma,			6,			false,		_ICODE_IFDEF_PRAGMA,					true,				_ICAT_GENERIC,		&colorSynHi_pragmas,		false,						null	},
		{ cgcIfndefPragma,			7,			false,		_ICODE_IFNDEF_PRAGMA,					true,				_ICAT_GENERIC,		&colorSynHi_pragmas,		false,						null	},
		{ cgcIncludePragma,			8,			false,		_ICODE_INCLUDE_PRAGMA,					true,				_ICAT_GENERIC,		&colorSynHi_pragmas,		false,						null	},
		{ cgcUndefPragma,			6,			false,		_ICODE_UNDEF_PRAGMA,					true,				_ICAT_GENERIC,		&colorSynHi_pragmas,		false,						null	},
		{ "%=",						2,			false,		_ICODE_MODULO_EQUAL,					false,				_ICAT_GENERIC,		&colorSynHi_operator,		false,						null	},
		{ "%",						1,			false,		_ICODE_PERCENT_SIGN,					false,				_ICAT_GENERIC,		&colorSynHi_operator,		false,						null	},
		{ "&&",						2,			false,		_ICODE_AND,								false,				_ICAT_GENERIC,		&colorSynHi_logical,		false,						null	},
		{ "&",						1,			false,		_ICODE_AMPERSAND,						false,				_ICAT_GENERIC,		&colorSynHi_operator,		false,						null	},
		{ "=<",						2,			false,		_ICODE_LESS_THAN_OR_EQUAL_TO,			false,				_ICAT_GENERIC,		&colorSynHi_operator,		true,						null	},
		{ "=>",						2,			false,		_ICODE_GREATER_THAN_OR_EQUAL_TO,		false,				_ICAT_GENERIC,		&colorSynHi_operator,		true,						null	},
		{ "==",						2,			false,		_ICODE_EXACTLY_EQUAL_TO,				false,				_ICAT_GENERIC,		&colorSynHi_operator,		true,						null	},
		{ "=",						1,			false,		_ICODE_EQUAL_SIGN,						false,				_ICAT_GENERIC,		&colorSynHi_operator,		true,						null	},
		{ "||",						2,			false,		_ICODE_OR,								false,				_ICAT_GENERIC,		&colorSynHi_logical,		false,						null	},
		{ "|=",						2,			false,		_ICODE_OR_ASSIGNMENT,					false,				_ICAT_GENERIC,		&colorSynHi_operator,		false,						null	},
		{ "|",						1,			false,		_ICODE_PIPE_SIGN,						false,				_ICAT_GENERIC,		&colorSynHi_operator,		false,						null	},
		{ "`",						1,			false,		_ICODE_REVERSE_QUOTE,					false,				_ICAT_GENERIC,		NULL,						false,						null	},
		{ ";",						1,			false,		_ICODE_SEMICOLON,						false,				_ICAT_GENERIC,		NULL,						false,						null	},
		{ "<<=",					3,			false,		_ICODE_SHIFT_LEFT_ASSIGNMENT,			false,				_ICAT_GENERIC,		&colorSynHi_operator,		true,						null	},
		{ "<<",						2,			false,		_ICODE_SHIFT_LEFT,						false,				_ICAT_GENERIC,		&colorSynHi_operator,		true,						null	},
		{ ">>=",					3,			false,		_ICODE_SHIFT_RIGHT_ASSIGNMENT,			false,				_ICAT_GENERIC,		&colorSynHi_operator,		true,						null	},
		{ ">>",						2,			false,		_ICODE_SHIFT_RIGHT,						false,				_ICAT_GENERIC,		&colorSynHi_operator,		true,						null	},
		{ "<=",						2,			false,		_ICODE_LESS_THAN_OR_EQUAL_TO,			false,				_ICAT_GENERIC,		&colorSynHi_operator,		true,						null	},
		{ ">=",						2,			false,		_ICODE_GREATER_THAN_OR_EQUAL_TO,		false,				_ICAT_GENERIC,		&colorSynHi_operator,		true,						null	},
		{ "<>",						2,			false,		_ICODE_NOT_EQUAL,						false,				_ICAT_GENERIC,		&colorSynHi_operator,		true,						null	},
		{ ">",						1,			false,		_ICODE_GREATER_THAN,					false,				_ICAT_GENERIC,		&colorSynHi_operator,		true,						null	},
		{ "<",						1,			false,		_ICODE_LESS_THAN,						false,				_ICAT_GENERIC,		&colorSynHi_operator,		true,						null	},

		/* As a last-case condition, we tag every character that we didn't previously identify with the unknown tag */
		{ "_\000\377\000\000",		1,			true,		_ICODE_UNKNOWN,							false,				_ICAT_GENERIC,		NULL,						false,						null	 },
		{ 0,						0,			0,			0,										0,					0,					0,							0,							null	 }
	};
