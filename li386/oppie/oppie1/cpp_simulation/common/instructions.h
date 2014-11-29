//////////
//
// /libsf/li386/oppie/oppie1/cpp_simulation/oppie/oppie1.cpp
//
//////
// Version 0.01
// Copyright (c) 2014 by Rick C. Hodgin
//////
// Last update:
//     Nov.26.2014
//////
// Change log:
//     Nov.24.2014 - Initial creation
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
// Template instructions
//////
	struct SOra	// Ora = Operation, register, address
	{
		// ooo.rr.aaa:aaaaaaaa
		union {
			struct {
				u8		i_data1;			// Opcode byte 1
				u8		i_data2;			// Opcode byte 2
			};
			struct {
				u8		ooo			: 3;
				u8		rd			: 2;
				u8		aaa			: 3;
				u8		aaaaaaaa	: 8;
			};
		};
	};

	struct SOrr // Orr = Operation, register, register
	{
		// ooo.x.rd.rs		-- 3-bit form
		// oooo.rd.rs		-- 4-bit form
		union {
			struct {
				u8		i_data1;			// Opcode byte 1
			};
			struct {
				u8		ignore		: 4;
				u8		rd			: 2;
				u8		rs			: 2;
			};
			struct {
				u8		ooo			: 3;
				u8		x			: 1;
				u8		rd1			: 2;
				u8		rs1			: 2;
			};
			struct {
				u8		oooo		: 4;
				u8		rd2			: 2;
				u8		rs2			: 2;
			};
		};
	};

	struct SBsa	// Bsa = Branch, sign, address
	{
		// ooooo.s.aa:aaaaaaaa
		union {
			struct {
				u8		i_data1;			// Opcode byte 1
				u8		i_data2;			// Opcode byte 2
			};
			struct {
				u8		ooooo		: 5;
				u8		s			: 1;
				u8		aa			: 2;
				u8		aaaaaaaa	: 8;
			};
		};
	};
