//////////
//
// /libsf/source/vjr/edit_chain_manager.h
//
//////
// Version 0.33
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
//     http://www.visual-freepro.org/wiki/index.php/Repeat_License
//
// Thank you.  And may The Lord bless you richly as you lift up your life, your
// talents, your gifts, your praise, unto Him.  In Jesus' name I pray.  Amen.
//
//




//////////
// Constants
//////
	const u32				_ECM_MINIMUM_LINE_ALLOCATION_LENGTH		= 96;		// Allocate data in 96 byte blocks


//////////
// Forward declarations
//////
	SEM*					iEditManager_allocate				(void);
	SBuilder*				iEditManager_accumulateBuilder		(SEM* em, SEdit* ecHintStart, SEdit* ecHintEnd);
	bool					iEditManager_saveToDisk				(SEM* em, s8* tcPathname);
	bool					iEditManager_loadFromDisk			(SEM* em, SEdit* ecHint, s8* tcPathname, bool tlInsertAfter);
	bool					iEditManager_duplicate				(SEM** root, SEM* chain, bool tlIncludeUndoHistory);
	void					iEditManager_delete					(SEM** root, bool tlDeleteSelf);
	void					iEditManager_deleteChain			(SEM** root, bool tlDeleteSelf);
	void					iEditManager_deleteChainWithCallback(SEM** root, bool tlDeleteSelf, SEcCallback* ecb);
	SEdit*					iEditManager_appendLine				(SEM* em, s8* tcText, s32 tnTextLength);
	SEdit*					iEditManager_insertLine				(SEM* em, s8* tcText, s32 tnTextLength, SEdit* line, bool tlInsertAfter);
	void					iEditManager_deleteLine				(SEM* em);
	SFont*					iEditManager_getRectAndFont			(SEM* em, SObject* obj, RECT* rc);
	void					iEditManager_getColors				(SEM* em, SObject* obj, SBgra& backColor, SBgra& foreColor);
	u32						iEditManager_render					(SEM* em, SObject* obj);
	bool					iEditManager_verifyCursorIsVisible	(SEM* em, SObject* obj);
	bool					iEditManager_onKeyDown_sourceCode	(SWindow* win, SObject* obj, bool tlCtrl, bool tlAlt, bool tlShift, bool tlCaps, s16 tcAscii, u16 tnVKey, bool tlIsCAS, bool tlIsAscii);
	bool					iEditManager_onKeyDown				(SWindow* win, SObject* obj, bool tlCtrl, bool tlAlt, bool tlShift, bool tlCaps, s16 tcAscii, u16 tnVKey, bool tlIsCAS, bool tlIsAscii);


	// Editor movements
	bool					iEditManager_keystroke				(SEM* em, SObject* obj, u8 asciiChar);
	bool					iEditManager_navigate				(SEM* em, SObject* obj, s32 deltaY, s32 deltaX);
	bool					iEditManager_navigatePages			(SEM* em, SObject* obj, s32 deltaY);
	bool					iEditManager_clearLine				(SEM* em, SObject* obj);
	bool					iEditManager_clearToEndOfLine		(SEM* em, SObject* obj);
	bool					iEditManager_clearToBeginningOfLine	(SEM* em, SObject* obj);
	bool					iEditManager_toggleInsert			(SEM* em, SObject* obj);
	bool					iEditManager_tabIn					(SEM* em, SObject* obj);
	bool					iEditManager_tabOut					(SEM* em, SObject* obj);
	bool					iEditManager_returnKey				(SEM* em, SObject* obj);
	bool					iEditManager_selectAll				(SEM* em, SObject* obj);
	bool					iEditManager_cut					(SEM* em, SObject* obj);
	bool					iEditManager_copy					(SEM* em, SObject* obj);
	bool					iEditManager_paste					(SEM* em, SObject* obj);
	bool					iEditManager_navigateWordLeft		(SEM* em, SObject* obj);
	bool					iEditManager_navigateWordRight		(SEM* em, SObject* obj);
	bool					iEditManager_navigateTop			(SEM* em, SObject* obj);
	bool					iEditManager_navigateEnd			(SEM* em, SObject* obj);
	bool					iEditManager_selectLineUp			(SEM* em, SObject* obj);
	bool					iEditManager_selectLineDown			(SEM* em, SObject* obj);
	bool					iEditManager_selectLeft				(SEM* em, SObject* obj);
	bool					iEditManager_selectRight			(SEM* em, SObject* obj);
	bool					iEditManager_selectToEndOfLine		(SEM* em, SObject* obj);
	bool					iEditManager_selectToBeginOfLine	(SEM* em, SObject* obj);
	bool					iEditManager_selectColumnToggle		(SEM* em, SObject* obj);
	bool					iEditManager_selectLineToggle		(SEM* em, SObject* obj);
	bool					iEditManager_selectWordLeft			(SEM* em, SObject* obj);
	bool					iEditManager_selectWordRight		(SEM* em, SObject* obj);
	bool					iEditManager_deleteLeft				(SEM* em, SObject* obj);
	bool					iEditManager_deleteRight			(SEM* em, SObject* obj);
	bool					iEditManager_deleteWordLeft			(SEM* em, SObject* obj);
	bool					iEditManager_deleteWordRight		(SEM* em, SObject* obj);
