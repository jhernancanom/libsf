//////////
//
// /libsf/utils/common/cpp/common_types.h
//
//////
// Version 0.55
// Copyright (c) 2014 by Rick C. Hodgin
//////
// Last update:
//     Nov.13.2014
//////
// Change log:
//     Nov.13.2014 - Initial creation
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


// Unsigned
#ifdef __GNUC__
	// gcc
	// Used for pointer sizes that mate up with pointers, but are actually integers
	#ifndef __amd64
		#define uptr uint32_t
		#define sptr int32_t
	#else
		#define uptr uint64_t
		#define sptr int64_t
	#endif
	#define u64 uint64_t
	#define u32 uint32_t
	#define u16 uint16_t
	#define u8 unsigned char

	#define s64 int64_t
	#define s32 int32_t
	#define s16 int16_t
	#define s8 char

#else
	// Used for pointer sizes that mate up with pointers, but are actually integers
	#ifndef _M_X64
		#define uptr unsigned int
		#define sptr int
	#else
		#define uptr unsigned __int64
		#define sptr __int64
	#endif
	#define u64 unsigned __int64
	#define u32 unsigned int
	#define u16 unsigned short
	#define u8 unsigned char

	// Signed
	#define s64 __int64
	#define s32 int
	#define s16 short
	#define s8 char
#endif

// Floating point
#define f32 float
#define f64 double

// Constant signed
#define cs8 const s8
#define cs16 const s16
#define cs32 const s32
#define cs64 const s64

// Constant unsigned
#define cu8 const u8
#define cu16 const u16
#define cu32 const u32
#define cu64 const u64

// Constant floating point
#define cf32 const f32
#define cf64 const f64

#ifndef null
	// For a null that is not considered a pointer
	#define null NULL
#endif

#define	_NO		0
#define _YES	1
