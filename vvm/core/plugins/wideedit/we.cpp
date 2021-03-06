//////////
//
// /libsf/vvm/core/plugins/wideedit/wideedit.cpp
//
//////
//    _     _ _     _____ _____ 
//   | |   (_) |__ / ____|  ___|
//   | |   | | '_ \\___ \|  __|
//   | |___| | |_) |___) | |
//   |_____|_|_.__/_____/|_|
//
//   Liberty Software Foundation
// and the Village Freedom Project
//   __     _______     ____  
//   \ \   / /  ___| __|  _ \ 
//    \ \ / /| |_ | '__| |_) |
//     \ V / |  _|| |  |  __/ 
//      \_/  |_|  |_|  |_|
//
//////
// Version 0.70
// Copyright (c) 2013 by Rick C. Hodgin
//////
// Last update:
//     Feb.25.2014
//////
// Change log:
//     Feb.25.2014 - Development on 0.70 begins
//     Oct.19.2013 - Initial creation
//////
// Note:  The function names in here are identified by the VVMOSS as plugins, and are part of a
//        list of available services during runtime to the runtime engine.  They are created in
//        this way so that the algorithms within can be ported more easily from external projects,
//        yet be converted to be used by the VVM.  In that way, this plugin acts as a go-between.
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
//




#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#define _NATIVE_CALLS					// We use native function calls here
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include "\libsf\vvm\core\common\common.h"
#include "\libsf\vvm\core\common\common_oss.h"
#include "we_const.h"
#include "we.h"




//////////
// Forward declarations
//////
	u64 CALLTYPE	iwe_editorCallback			(u64 tnSubfunction, u64 extra, u64 extra2);




//////////
//
// Dll entry point
//
//////
	BOOL APIENTRY DllMain( HMODULE	hModule,
						   DWORD	ul_reason_for_call,
						   LPVOID	lpReserved	)
	{
		switch (ul_reason_for_call)
		{
			case DLL_PROCESS_ATTACH:
				break;

			case DLL_THREAD_ATTACH:
				break;

			case DLL_THREAD_DETACH:
				break;

			case DLL_PROCESS_DETACH:
				break;
		}
		return TRUE;
	}




//////////
//
// Called one time at startup to initialize the SDL library to handle the sound requests.
//
//////
	void CALLTYPE vvmoss_plugin_requestor(u64 tnDebuggerInterfaceAddress, u64 tnInstanceId)
	{
		//////////
		// Retrieve the necessary callbacks into the VVMOSS itself
		//////
			iLoadOssFunctionsFromDll();


		//////////
		// Tell the VVM exactly what it is we offer
		//////
			oss_plugin_registerFunction(tnInstanceId, _VVMOSS_PLUGIN_EDITOR, cgfVersion, cgnBuild, (u8*)cgcWideEditVersion, (u64)iwe_editorCallback);
	}




//////////
//
// Callback for this function
//
//////
	u64 CALLTYPE iwe_editorCallback(u64 tnSubfunction, u64 extra, u64 extra2)
	{
		switch (tnSubfunction)
		{
			case _VVMOSS_PLUGIN_EDITOR_CREATE_CONTEXT:
				break;

			case _VVMOSS_PLUGIN_EDITOR_ASSOCIATE_WITH_SCREEN:
				break;
		}
		return(-1);
	}
