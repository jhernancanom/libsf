//////////
//
// /libsf/utils/inquiry/cpp/inquiry_dll/inquiry.h
//
//////
//
//
//////
// Version 0.10
// Copyright (c) 2014 by Rick C. Hodgin
//////
// Last update:
//     Aug.02.2014
//////
// Change log:
//     Aug.02.2014	- Initial creation
//////
//
// Top-level program for INQUIRY.DLL.
//
//////////
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
//     http://www.visual-freepro.org
//     http://www.visual-freepro.org/blog/
//     http://www.visual-freepro.org/forum/
//     http://www.visual-freepro.org/wiki/
//     http://www.visual-freepro.org/wiki/index.php/PBL
//     http://www.visual-freepro.org/wiki/index.php/Repeat_License
//
// Thank you.  And may The Lord bless you richly as you lift up your life, your
// talents, your gifts, your praise, unto Him.  In Jesus' name I pray.  Amen.
//
//////




#pragma once

// Modify the following defines if you have to target a platform prior to the ones specified below.
// Refer to MSDN for the latest info on corresponding values for different platforms.
#ifndef WINVER                  // Specifies that the minimum required platform is Windows Vista.
#define WINVER 0x0600           // Change this to the appropriate value to target other versions of Windows.
#endif

#ifndef _WIN32_WINNT            // Specifies that the minimum required platform is Windows Vista.
#define _WIN32_WINNT 0x0600     // Change this to the appropriate value to target other versions of Windows.
#endif

#ifndef _WIN32_WINDOWS          // Specifies that the minimum required platform is Windows 98.
#define _WIN32_WINDOWS 0x0410   // Change this to the appropriate value to target Windows Me or later.
#endif

#ifndef _WIN32_IE               // Specifies that the minimum required platform is Internet Explorer 7.0.
#define _WIN32_IE 0x0700        // Change this to the appropriate value to target other versions of IE.
#endif

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <shlobj.h>
#include <WinSock2.h>
#include <io.h>
#include <fcntl.h>
#include <share.h>
#include <sys\stat.h>
#include <Shobjidl.h>


// Unsigned
#if !defined(_MSC_VER)
	// gcc
	typedef unsigned long long	u64;
	typedef unsigned			u32;
	typedef unsigned short		u16;
	typedef unsigned char		u8;

	typedef long long			s64;
	typedef int					s32;
	typedef short				s16;
	typedef char				s8;

#else
	typedef	unsigned __int64	u64;
	typedef	unsigned long		u32;
	typedef	unsigned short		u16;
	typedef	unsigned char		u8;

	// Signed
	typedef	__int64				s64;
	typedef	long				s32;
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

// For hard breaks
#if !defined(_MSC_VER)
	// gcc
	#define int3_break						asm("int $3")
#else
	#define int3_break						_asm int 3
#endif



//////////
// Source code files to include
//////
	#include "\libsf\utils\common\cpp\builder.cpp"
	#include "\libsf\utils\common\cpp\ll.cpp"
	#include "\libsf\utils\common\cpp\xml\xml.h"
	#include "\libsf\utils\common\cpp\xml\xml.cpp"
	#include "\libsf\utils\common\cpp\cliserv\cscommon.h"
	#include "\libsf\utils\common\cpp\cliserv\client.h"
	#include "\libsf\utils\common\cpp\cliserv\server.h"
	#include "\libsf\utils\common\cpp\cliserv\cscommon.cpp"
	#include "\libsf\utils\common\cpp\cliserv\client.cpp"
	#include "\libsf\utils\common\cpp\cliserv\server.cpp"
	#include "\libsf\utils\common\cpp\cliserv\cliserv_sup.cpp"




//////////
// Global variables
//////
	HINSTANCE		ghInstance;




//////////
// Forward declarations
//////
	// inquiry.cpp
	void				initialize								(void);

	// inquiry
	s32					inquiry_get_applications				(s8* cIpAddress, s8* cPort);
	
	s32					inquiry_login							(s8* cUser, s8* cPassword, s8* cAppToken);
	s32					inquiry_logout							(s8* cAppToken);
	
	s32					inquiry_get_status_list					(s8* cAppToken);
	s32					inquiry_get_priority_list				(s8* cAppToken);
	s32					inquiry_get_reported_list				(s8* cAppToken);
	s32					inquiry_get_target_list					(s8* cAppToken);
	
	s32					inquiry_get_by_date						(s8* cAppToken, s32 year, s32 month, s32 day, s32 hour, s32 minute, s32 second);
	s32					inquiry_get_by_status					(s8* cAppToken, s8* cStatus);
	s32					inquiry_get_by_priority					(s8* cAppToken, s8* cPriority);
	s32					inquiry_get_by_reported					(s8* cAppToken, s8* cReported);
	s32					inquiry_get_by_target					(s8* cAppToken, s8* cTarget);
	
	s32					inquiry_get_description					(s8* cAppToken, s32 nId);
	s32					inquiry_get_comment						(s8* cAppToken, s32 nId, s32 nCommentNumber);
	
	s32					inquiry_update_title					(s8* cAppToken, s32 nId, s8* cTitle);
	s32					inquiry_update_description				(s8* cAppToken, s32 nId, s8* cDescription);
	s32					inquiry_update_comment					(s8* cAppToken, s32 nId, s32 nCommentNumber, s8* cComment);
	s32					inquiry_update_status					(s8* cAppToken, s32 nId, s8* cStatus);
	s32					inquiry_update_priority					(s8* cAppToken, s32 nId, s8* cPriority);
	s32					inquiry_update_release					(s8* cAppToken, s32 nId, s8* cReported, s8* cTarget);
	
	s32					inquiry_add								(s8* cAppToken, s8* cTitle, s8* cDescription, s8* cStatus, s8* cPriority, s8* cReported, s8* cTarget);
	s32					inquiry_add_comment						(s8* cAppToken, s32 nId, s8* cComment);
	
	s32					inquiry_get_change_history				(s8* cAppToken, s32 nId);
	s32					inquiry_get_change_history_description	(s8* cAppToken, s32 nId);
	s32					inquiry_get_change_history_comment		(s8* cAppToken, s32 nId, s32 nCommentNumber);
	
	s32					inquiry_check_status					(s32 nRequestId);
	s32					inquiry_get_mail						(s32 nMailId, s8* cText, u32 nDataLength);
