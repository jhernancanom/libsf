//////////
//
// /libsf/vvm/vvmoss/vo_glob.h
//
//////
// Version 0.60
// Copyright (c) 2012, 2013 by Rick C. Hodgin
//////
// Last update:
//     November 07, 2012
//////
// Change log:
//     September 20, 2012 - Initial creation
//     September 29, 2012 - PBL v1.0 license included directly in source files.
//     November 07, 2012 - 0.60 development begins
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
// Global variables
//////
	HINSTANCE			ghInstance				= NULL;					// Instance handle
	HWND				ghWndMsg				= NULL;					// Message window
	u64					gnNextUniqueId			= 1000;					// Increments after each reference (see oss_getNextUniqueId() and iGetNextUniqueId())
	bool				gbBreakpoints			= false;				// Used for debugging, should special breakpoints be enabled?
	UINT_PTR			ghTimer10ms				= NULL;					// Used for non-message windows to trigger UI events
	HANDLE				ghTimer1ms				= NULL;					// Used for maintaining a referenceable internal tick

	// Timers
	u64					gnTickCount				= 0;					// Allocated as a millisecond resolution timer at startup in the ioss_wndProc_Message()
	u64					gnExternallyVisibleTickCount = 0;				// A copy of the gnTickCount value, but in case a caller destroys it, then it won't be so bad as we will just update it next tick. :-)

	// Semaphores
	u64					gsemBuildScreen			= 0;					// Used for accessing visible windows in a synchronized manner
	u64					gsemForeignThreadAccess	= 0;					// Atomic access to gseRootForeignThreads
	// Semaphores for synchronized access to master lists
	u64					gsemScreenAccess		= 0;					// Master screen inventory
	u64					gsemCanvasAccess		= 0;					// Master canvas inventory
	u64					gsemRegionAccess		= 0;					// Master region inventory

	// The root objects
	SStartEnd	gseRootScreen					= { NULL, NULL };		// Master screen list
	SStartEnd	gseRootCanvas					= { NULL, NULL };		// Master canvas list
	SStartEnd	gseRootRegion					= { NULL, NULL };		// Master region list

	// BXML last error
	u64					gnLastErrorOffset		= -1;					// Initially indicate no prior error offset
	u64					gnLastErrorCode			= 0;					// Initially indicate no prior error code
	SBxmlError			gsLastErrorInfo =	{
												{ NULL, 0 },			// Description (initially set to no error)
												0,						// Last error offset
												0,						// Last error code
												NULL,					// Last BXML in error
												NULL					// Last BxmlA in error
											};

	// Start/end structs
	SStartEnd			gseRootWindows			= { NULL, NULL };		// Initially, no windows are defined
	SStartEnd			gseRootFonts			= { NULL, NULL };		// Initially, no fonts are defined
	SStartEnd			gseRootForeignThreads	= { NULL, NULL };		// Initially, no foreign threads are defined
	SStartEnd			gseRootForeignFiles		= { NULL, NULL };		// Files that have been requested open with oss_sharedAsciiOpenFile() or oss_sharedUnicodeOpenFile()
	SStartEnd			gseRootMemoryBlocks		= { NULL, NULL };		// Any memory blocks that need to persist beyond termination of the VMM

	// Separate debugger instances can request unique color schemes if they want to visually identify themselves
	u32					gnDebuggerNumber		= 0;					// Current color index for loaded debugger
	u32					gnDebuggerColorList[8]	=	{
														rgba(255,255,255,255),			// White
														rgba(255,255,225,255),			// Yellow pastel
														rgba(255,225,255,255),			// Pink pastel
														rgba(225,255,255,255),			// Cyan pastel
														rgba(255,225,192,255),			// Orange pastel
														rgba(192,225,255,255),			// Blue pastel
														rgba(225,255,225,255),			// Green pastel
														rgba(225,225,225,255)			// Grey
													};


//////////
// Critical sections for synchronized access
//////
	CRITICAL_SECTION	gcsUniqueIdAccess;							// Next Unique ID access


//////////
// Data specifically relative to the sound plugin
//////
	_isSSoundPlugin		gsSoundPlugin;
