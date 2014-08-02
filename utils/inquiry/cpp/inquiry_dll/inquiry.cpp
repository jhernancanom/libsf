//////////
//
// /libsf/utils/inquiry/cpp/inquiry_dll/inquiry.cpp
//
//////
//
//
//////
// Version 0.10
// Copyright (c) 2014 by Rick C. Hodgin
//////
// Last update:
//     Aug.02.2013
//////
// Change log:
//     Aug.02.2013	- Initial creation
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




#include "inquiry.h"




//////////
//
// Main DLL entry point
//
//////
	BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
	{
		//////////
		// Store the instance for global use
		//////
			ghInstance = hModule;


		//////////
		// Windows tells us why we're being invoked
		//////
			switch (ul_reason_for_call)
			{
				case DLL_PROCESS_ATTACH:
					ghInstance = hModule;
					initialize();
					break;
				case DLL_THREAD_ATTACH:
				case DLL_THREAD_DETACH:
				case DLL_PROCESS_DETACH:
					break;
			}
			return TRUE;
	}




//////////
//
// Called at process startup to initialize this instance of the DLL
//
//////
	void initialize(void)
	{
		// Initialize our critical section
		InitializeCriticalSection(&gsemUniqueId);

		// Create our own process for self messages (used by encrypt and decrypt mail)
		iCreateNewSProcess(&gsProcSelf);
		gsProcSelf->isRunning = true;

		// Initialize the cliserv semaphore stack
		InitializeCriticalSection(&gcsStoreSemaphoreStack);
	}




//////////
//
// Called to obtain the bitmap of the indicated character.
//
//////
	s32 inquiry_get_applications(s8* cIpAddress, s8* cPort)
	{
		return(0);
	}
	    
	s32 inquiry_login(s8* cUser, s8* cPassword, s8* cAppToken)
	{
		return(0);
	}
	    
	s32 inquiry_logout(s8* cAppToken)
	{
		return(0);
	}
	    
	s32 inquiry_get_status_list(s8* cAppToken)
	{
		return(0);
	}
	    
	s32 inquiry_get_priority_list(s8* cAppToken)
	{
		return(0);
	}
	    
	s32 inquiry_get_reported_list(s8* cAppToken)
	{
		return(0);
	}
	    
	s32 inquiry_get_target_list(s8* cAppToken)
	{
		return(0);
	}
	    
	s32 inquiry_get_by_date(s8* cAppToken, s32 year, s32 month, s32 day, s32 hour, s32 minute, s32 second)
	{
		return(0);
	}
	    
	s32 inquiry_get_by_status(s8* cAppToken, s8* cStatus)
	{
		return(0);
	}
	    
	s32 inquiry_get_by_priority(s8* cAppToken, s8* cPriority)
	{
		return(0);
	}
	    
	s32 inquiry_get_by_reported(s8* cAppToken, s8* cReported)
	{
		return(0);
	}
	    
	s32 inquiry_get_by_target(s8* cAppToken, s8* cTarget)
	{
		return(0);
	}
	    
	s32 inquiry_get_description(s8* cAppToken, s32 nId)
	{
		return(0);
	}
	    
	s32 inquiry_get_comment(s8* cAppToken, s32 nId, s32 nCommentNumber)
	{
		return(0);
	}
	    
	s32 inquiry_update_title(s8* cAppToken, s32 nId, s8* cTitle)
	{
		return(0);
	}
	    
	s32 inquiry_update_description(s8* cAppToken, s32 nId, s8* cDescription)
	{
		return(0);
	}
	    
	s32 inquiry_update_comment(s8* cAppToken, s32 nId, s32 nCommentNumber, s8* cComment)
	{
		return(0);
	}
	    
	s32 inquiry_update_status(s8* cAppToken, s32 nId, s8* cStatus)
	{
		return(0);
	}
	    
	s32 inquiry_update_priority(s8* cAppToken, s32 nId, s8* cPriority)
	{
		return(0);
	}
	    
	s32 inquiry_update_release(s8* cAppToken, s32 nId, s8* cReported, s8* cTarget)
	{
		return(0);
	}
	    
	s32 inquiry_add(s8* cAppToken, s8* cTitle, s8* cDescription, s8* cStatus, s8* cPriority, s8* cReported, s8* cTarget)
	{
		return(0);
	}
	    
	s32 inquiry_add_comment(s8* cAppToken, s32 nId, s8* cComment)
	{
		return(0);
	}
	    
	s32 inquiry_get_change_history(s8* cAppToken, s32 nId)
	{
		return(0);
	}
	    
	s32 inquiry_get_change_history_description(s8* cAppToken, s32 nId)
	{
		return(0);
	}
	    
	s32 inquiry_get_change_history_comment(s8* cAppToken, s32 nId, s32 nCommentNumber)
	{
		return(0);
	}
	    
	s32 inquiry_check_status(s32 nRequestId)
	{
		return(0);
	}
	    
	s32 inquiry_get_mail(s32 nMailId, s8* cText, u32 nDataLength)
	{
		return(0);
	}
