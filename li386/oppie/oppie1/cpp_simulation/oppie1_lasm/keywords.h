//////////
//
// /libsf/li386/oppie/oppie1/cpp_simulation/oppie1_lasm/keywords.h
//
//////
// Version 0.02
// Copyright (c) 2014 by Rick C. Hodgin
//////
// Last update:
//     Nov.29.2014
//////
// Change log:
//     Nov.29.2014 - Initial creation
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
// Codes unique to Oppie-1
//////
	cs32		_ICAT_REGISTER					= -1;
	SBgra		colorSynHi_register				= { rgba(92,92,225,255) };
	SBgra		colorSynHi_preprocessor			= { rgba(255,92,92,255) };
	cs32		_ICODE_MOV						= -1;
	cs32		_ICODE_ADC						= -2;
	cs32		_ICODE_SBB						= -3;
	cs32		_ICODE_CMP						= -4;
	cs32		_ICODE_JNC						= -5;
	cs32		_ICODE_JC						= -6;
	cs32		_ICODE_JNZ						= -7;
	cs32		_ICODE_JZ						= -8;
	cs32		_ICODE_JMP						= -9;
	cs32		_ICODE_R1						= -10;
	cs32		_ICODE_R2						= -11;
	cs32		_ICODE_R3						= -12;
	cs32		_ICODE_R4						= -13;
	cs32		_ICODE_ORG						= -14;
	cs32		_ICODE_DB						= -15;


//////////
// Keywords for Oppie-1's assembler
//////
	SAsciiCompSearcher	cgcKeywordsOppie1[] =
	{
		// keyword					length		repeats?	extra (type)							first on line?		category			syntax highlight color		syntax highlight bold
		{ "mov",					3,			false,		_ICODE_MOV,								false,				_ICAT_COMMAND,		&colorSynHi_command,		false,						null },
		{ "add",					3,			false,		_ICODE_ADD,								false,				_ICAT_COMMAND,		&colorSynHi_command,		false,						null },
		{ "adc",					3,			false,		_ICODE_ADC,								false,				_ICAT_COMMAND,		&colorSynHi_command,		false,						null },
		{ "sub",					3,			false,		_ICODE_SUB,								false,				_ICAT_COMMAND,		&colorSynHi_command,		false,						null },
		{ "sbb",					3,			false,		_ICODE_SBB,								false,				_ICAT_COMMAND,		&colorSynHi_command,		false,						null },
		{ "cmp",					3,			false,		_ICODE_CMP,								false,				_ICAT_COMMAND,		&colorSynHi_command,		false,						null },
		{ "jnc",					3,			false,		_ICODE_JNC,								false,				_ICAT_COMMAND,		&colorSynHi_command,		false,						null },
		{ "jc",						2,			false,		_ICODE_JC,								false,				_ICAT_COMMAND,		&colorSynHi_command,		false,						null },
		{ "jnz",					3,			false,		_ICODE_JNZ,								false,				_ICAT_COMMAND,		&colorSynHi_command,		false,						null },
		{ "jz",						2,			false,		_ICODE_JZ,								false,				_ICAT_COMMAND,		&colorSynHi_command,		false,						null },
		{ "jmp",					3,			false,		_ICODE_JMP,								false,				_ICAT_COMMAND,		&colorSynHi_command,		false,						null },
		{ "r1",						2,			false,		_ICODE_R1,								false,				_ICAT_REGISTER,		&colorSynHi_register,		false,						null },
		{ "r2",						2,			false,		_ICODE_R2,								false,				_ICAT_REGISTER,		&colorSynHi_register,		false,						null },
		{ "r3",						2,			false,		_ICODE_R3,								false,				_ICAT_REGISTER,		&colorSynHi_register,		false,						null },
		{ "r4",						2,			false,		_ICODE_R4,								false,				_ICAT_REGISTER,		&colorSynHi_register,		false,						null },
		{ "org",					3,			false,		_ICODE_ORG,								false,				_ICAT_COMMAND,		&colorSynHi_preprocessor,	false,						null },
		{ "db",						2,			false,		_ICODE_DB,								false,				_ICAT_COMMAND,		&colorSynHi_command,		false,						null },
		{ 0,						0,			0,			0,										0,					0,					0,							0,							0 }
	};
