*****
*
* /libsf/source/vjr/sourcelight/main.prg
*
***
* Version 0.10
* Copyright (c) 2014 by Rick C. Hodgin
***
* Last update:
*     Sep.24.2014
***
* Change log:
*     Sep.24.2014 - Initial creation
***
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
*     http://www.libsf.org/
*     http://www.libsf.org/licenses/
*     http://www.visual-freepro.org/vjr/indexmain.html
*     http://www.visual-freepro.org/wiki/index.php/PBL
*     http://www.visual-freepro.org/wiki/index.php/Repeat_License
*
* Thank you.  And may The Lord bless you richly as you lift up your life, your
* talents, your gifts, your praise, unto Him.  In Jesus' name I pray.  Amen.
*
*
SET STATUS OFF
SET BELL OFF
SET DOHISTORY OFF
SET TALK OFF
SET ENGINEBEHAVIOR 70
SET STATUS BAR ON
SET SAFETY OFF

* Set the app paths
SET CLASSLIB TO sourcelight.vcx ADDITIVE

* Engage
DO FORM frmMain

* Wait until we're done
READ EVENTS

* Upon termination, restore things
_vfp.Visible = .t.
SET TALK ON
