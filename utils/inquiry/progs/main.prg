**********
*
* /libsf/vvm/utils/inquiry/progs/main.prg
*
*****
* Version 0.10
* Copyright (c) 2014 by Rick C. Hodgin
*****
* Last update:
*     Aug.02.2013
*****
* Change log:
*     Aug.02.2013	- Initial creation
*****
*
* Top-level program for the Inquiry "Issue Tracker" application.  It was created to
* allow a simple GUI for maintaining a list of issues and their resolutions on the
* various applications which have been setup.
*
* It communicates with a remote server, but uses client-side processing to handle
* searches and all I/O.  It can operate stand-alone, or online and will auto-sync when
* next online.
*
*****
*
* This software is released as Liberty Software under a Repeat License, as governed
* by the Public Benefit License v1.0 or later (PBL).
*
* You are free to use, copy, modify and share this software.  However, it can only
* be released under the PBL version indicated, and every project must include a copy
* of the pbl.txt document for its version as is at http:*www.libsf.org/licenses/.
*
* For additional information about this project, or to view the license, see:
*
*     http:*www.libsf.org/
*     http:*www.libsf.org/licenses/
*     http:*www.visual-freepro.org
*     http:*www.visual-freepro.org/blog/
*     http:*www.visual-freepro.org/forum/
*     http:*www.visual-freepro.org/wiki/
*     http:*www.visual-freepro.org/wiki/index.php/PBL
*     http:*www.visual-freepro.org/wiki/index.php/Repeat_License
*
* Thank you.  And may The Lord bless you richly as you lift up your life, your
* talents, your gifts, your praise, unto Him.  In Jesus' name I pray.  Amen.
*
*****
LPARAMETERS p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18, p19, p20

SET STATUS			OFF
SET BELL			OFF
SET DOHISTORY		OFF
SET TALK			OFF
SET ENGINEBEHAVIOR	70
SET STATUS BAR		ON
SET SAFETY			OFF


**********
* Set the app paths
*****
	SET PROCEDURE	TO inquiry_dll.prg		ADDITIVE
	SET PROCEDURE	TO main.prg				ADDITIVE
*	SET CLASSLIB	TO helper.vcx			ADDITIVE
	SET CLASSLIB	TO inquiry.vcx			ADDITIVE


**********
* Load global variables
*****
	PUBLIC gcStartupDirectory
	gcStartupDirectory = FULLPATH(CURDIR())


**********
* Declare the extension DLLs
*****
	DO declare_inquiry_dll				&& inquiry.dll


**********
* Display the main launcher screen.
*****
	_vfp.Visible = .f.
	DO FORM frmMain


**********
* Wait until we're done
*****
	READ EVENTS


**********
* Upon termination, restore things
*****
	_vfp.Visible = .t.
	SET TALK ON
