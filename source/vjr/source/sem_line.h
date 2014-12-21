//////////
//
// /libsf/source/vjr/sem_line.h
//
//////
// Version 0.55
// Copyright (c) 2014 by Rick C. Hodgin
//////
// Last update:
//     Jul.06.2014
//////
// Change log:
//     Jul.06.2014 - Initial creation
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




//////////
// Forward declarations
//////
	void					iEditChain_free							(SLine** root, bool tlDeleteSelf);
	void					iEditChain_ensureLineLength				(SLine* em, s32 newLineLength);

	// For editing
	bool					iEditChain_characterInsert				(SEM* sem, u8 asciiChar);
	bool					iEditChain_characterOverwrite			(SEM* sem, u8 asciiChar);
	bool					iEditChain_characterDelete				(SEM* sem);
	SBreakpoint*			iEditChain_toggleBreakpoint				(SEM* sem);

	// For reporting on a line's state
	bool					iEditChain_hasChanged					(SLine* ec);
