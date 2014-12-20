//////////
//
// /libsf/utils/common/cpp/common_types.h
//
//////
// Version 0.54
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
	#ifdef __i386__
		typedef uint32_t		uptr;
	#else
		typedef uint64_t		uptr;
	#endif
	typedef uint64_t			u64;
	typedef uint32_t			u32;
	typedef uint16_t			u16;
	typedef uint8_t				u8;

	typedef int64_t				s64;
	typedef int32_t				s32;
	typedef int16_t				s16;
	typedef int8_t				s8;

#else
	// Used for pointer sizes that mate up with pointers, but are actually integers
	#ifdef _M_IX86
		typedef	unsigned int	uptr;		// Used for pointer sizes that mate up with pointers, but are actually integers
	#else
		typedef	unsigned __int64 uptr;
	#endif
	typedef	unsigned __int64	u64;
	typedef	unsigned int		u32;
	typedef	unsigned short		u16;
	typedef	unsigned char		u8;

	// Signed
	typedef	__int64				s64;
	typedef	int					s32;
	typedef	short				s16;
	typedef	char				s8;
#endif

// Floating point
typedef		float				f32;
typedef		double				f64;

// Constant signed
typedef		const s8			cs8;
typedef		const s16			cs16;
typedef		const s32			cs32;
typedef		const s64			cs64;

// Constant unsigned
typedef		const u8			cu8;
typedef		const u16			cu16;
typedef		const u32			cu32;
typedef		const u64			cu64;

// Constant floating point
typedef		const f64			cf64;
typedef		const f64			cf64;

#ifndef null
	// For a null that is not considered a pointer
	#define null 0
#endif
