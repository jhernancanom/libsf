//////////
//
// /libsf/source/vjr/datum.h
//
//////
// Version 0.54
// Copyright (c) 2014 by Rick C. Hodgin
//////
// Last update:
//     Nov.27.2014
//////
// Change log:
//     Nov.27.2014 - Initial creation
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




	void					iDatum_allocateSpace					(SDatum* datum,            s32 dataLength);
	SDatum*					iDatum_allocate							(                s8* data, s32 dataLength);
	void					iDatum_duplicate						(SDatum* datum,  s8* data, s32 dataLength);
	void					iDatum_duplicate						(SDatum* datum, cs8* data, s32 dataLength);
	void					iDatum_duplicate						(SDatum* datumDst, SDatum* datumSrc);
	bool					iDatum_resize							(SDatum* datum, s32 newDataLength);
	s32						iDatum_compare							(SDatum* datumLeft, SDatum* datumRight);
	s32						iDatum_compare							(SDatum* datumLeft, s8*  data, s32 dataLength);
	s32						iDatum_compare							(SDatum* datumLeft, cs8* data, s32 dataLength);
	void					iDatum_delete							(SDatum* datum, bool tlDeleteSelf);
	void					iiDatum_delete							(SDatum* datum);
