//////////
//
// /libsf/vvm/vvm/vvm_vvmmc.cpp
//
//////
// Version 0.60
// Copyright (c) 2012, 2013 by Rick C. Hodgin
//////
// Last update:
//     Mar.02.2013
//////
// Change log:
//     Mar.02.2013	- Initial creation
//////
// See devhelp.txt.
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




//////////
//
// Called to load the VVMOSS.DLL stuff, following the startup protocol.
//
//////
	bool ivvm_loadAndInitializeVvmmc(void)
	{
		// Load the DLL
		if (!iLoadVvmmcFunctionsFromDll())
			return(false);

		// Let it initialize itself
		vvmmc_firstCallback((u64)&vvm_debuggerInterfaceCallback);
		vvmmc_bootstrapInitialization((u64)&vvm_debuggerInterfaceCallback);

		// We're good
		return(true);
	}
