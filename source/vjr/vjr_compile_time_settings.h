//////////
//
// /libsf/source/vjr/vjr_compile_time_settings.h
//
//////
// Version 0.54
// Copyright (c) 2014 by Rick C. Hodgin
//////
// Last update:
//     Nov.05.2014
//////
// Change log:
//     Nov.05.2014 - Initial creation
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
// See: https://vld.codeplex.com/
// Install to:  c:\program files\visual leak detector\
// Un-comment this line to find memory leaks
// BEGIN
//////
	//#include "vld.h"	// Visual (memory) Leak Detector
//////
// END
//////////


//////////
// For debugging, the splash screen gets in the way if you're doing debugging
// on a single monitor machine (like a notebook) during the initial startup.
// You can set this property to false and prevent the splash screen from appearing.
//////
	bool glShowSplash = false;


//////////
// Compiler-specific settings
//////
	#if !defined(_MSC_VER)
		// gcc
		#define debug_break			asm("int $3")
		#define debug_nop			asm("nop")
	#else
		// visual studio
		#ifdef _M_IX86
			#define debug_break		_asm int 3
			#define debug_nop		_asm nop
		#else
			void debugBreak(void)	{	int i = 4;	}
			void debugNop(void)		{	int i = 4;	}
			#define debug_break		debugBreak();
			#define debug_nop		debugNop();
		#endif
	#endif


//////////
// Aug.11.2014 -- Added to track down functions that were slowing down the system
//#define _VJR_LOG_ALL
//////
	#ifdef _VJR_LOG_ALL
		#define logfunc(x)		iVjr_appendSystemLog((s8*)x)
	#else
		#define logfunc(x)
	#endif


//////////
// Force the bitmaps to be declared external for linking
//////
	#ifndef _BMP_LOCALITY
		#define _BMP_LOCALITY 0
	#endif
