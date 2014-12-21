//////////
//
// /libsf/source/vjr/fonts.h
//
//////
// Version 0.55
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




	SFont*					iFont_duplicate							(SFont* fontSource);
	SFont*					iFont_create							(cs8* tcFontName, u32 tnFontSize, u32 tnFontWeight, u32 tnItalics, u32 tnUnderline);
	SFont*					iFont_bigger							(SFont* font, bool tlDeleteAfterCreateNew);
	SFont*					iFont_smaller							(SFont* font, bool tlDeleteAfterCreateNew);
	void					iiFont_refresh							(SFont* font);
	void					iFont_delete							(SFont** font, bool tlDeleteSelf);
	void					iFont_releaseAll						(SBuilder* fontRoot, bool tlDeleteSelf);
	u32						iFont_findClosestSizeMatch				(s8* tcText, s8* tcFontName, u32 tnFontSize, u32 tnFontBold, u32 tnFontItalic, u32 tnFontUnderline, u32 tnWidth, u32 tnHeight, u32 tnWidthDesired, u32 tnHeightDesired);
