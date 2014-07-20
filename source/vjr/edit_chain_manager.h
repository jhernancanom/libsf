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
	SEM*		iEditChainManager_allocate				(void);
	SBuilder*				iEditChainManager_accumulateBuilder		(SEM* ecm, SEdit* ecHintStart, SEdit* ecHintEnd);
	bool					iEditChainManager_saveToDisk			(SEM* ecm, s8* tcPathname);
	bool					iEditChainManager_loadFromDisk			(SEM* ecm, SEdit* ecHint, s8* tcPathname, bool tlInsertAfter);
	bool					iEditChainManager_duplicate				(SEM** root, SEM* chain, bool tlIncludeUndoHistory);
	void					iEditChainManager_delete				(SEM** root, bool tlDeleteSelf);
	void					iEditChainManager_deleteChain			(SEM** root, bool tlDeleteSelf);
	void					iEditChainManager_deleteChainWithCallback(SEM** root, bool tlDeleteSelf, SEcCallback* ecb);
	SEdit*					iEditChainManager_appendLine			(SEM* ecm, s8* tcText, s32 tnTextLength);
	SEdit*					iEditChainManager_insertLine			(SEM* ecm, s8* tcText, s32 tnTextLength, SEdit* line, bool tlInsertAfter);
	void					iEditChainManager_deleteLine			(SEM* ecm);
	SFont*					iEditChainManager_getRectAndFont		(SEM* ecm, SObject* obj, RECT* rc);
	void					iEditChainManager_getColors				(SEM* ecm, SObject* obj, SBgra& backColor, SBgra& foreColor);
	void					iEditChainManager_render				(SEM* ecm, SObject* obj);
	bool					iEditChainManager_verifyCursorIsVisible	(SEM* ecm, SObject* obj);


	// Editor movements
	bool					iEditChainManager_keystroke				(SEM* ecm, SObject* obj, u8 asciiChar);
	bool					iEditChainManager_navigate				(SEM* ecm, SObject* obj, s32 deltaY, s32 deltaX);
	bool					iEditChainManager_navigatePages			(SEM* ecm, SObject* obj, s32 deltaY);
	bool					iEditChainManager_clearLine				(SEM* ecm, SObject* obj);
	bool					iEditChainManager_clearToEndOfLine		(SEM* ecm, SObject* obj);
	bool					iEditChainManager_clearToBeginningOfLine(SEM* ecm, SObject* obj);
	bool					iEditChainManager_toggleInsert			(SEM* ecm, SObject* obj);
	bool					iEditChainManager_tabIn					(SEM* ecm, SObject* obj);
	bool					iEditChainManager_tabOut				(SEM* ecm, SObject* obj);
	bool					iEditChainManager_returnKey				(SEM* ecm, SObject* obj);
	bool					iEditChainManager_selectAll				(SEM* ecm, SObject* obj);
	bool					iEditChainManager_cut					(SEM* ecm, SObject* obj);
	bool					iEditChainManager_copy					(SEM* ecm, SObject* obj);
	bool					iEditChainManager_paste					(SEM* ecm, SObject* obj);
	bool					iEditChainManager_navigateWordLeft		(SEM* ecm, SObject* obj);
	bool					iEditChainManager_navigateWordRight		(SEM* ecm, SObject* obj);
	bool					iEditChainManager_navigateTop			(SEM* ecm, SObject* obj);
	bool					iEditChainManager_navigateEnd			(SEM* ecm, SObject* obj);
	bool					iEditChainManager_selectLineUp			(SEM* ecm, SObject* obj);
	bool					iEditChainManager_selectLineDown		(SEM* ecm, SObject* obj);
	bool					iEditChainManager_selectLeft			(SEM* ecm, SObject* obj);
	bool					iEditChainManager_selectRight			(SEM* ecm, SObject* obj);
	bool					iEditChainManager_selectToEndOfLine		(SEM* ecm, SObject* obj);
	bool					iEditChainManager_selectToBeginOfLine	(SEM* ecm, SObject* obj);
	bool					iEditChainManager_selectColumnToggle	(SEM* ecm, SObject* obj);
	bool					iEditChainManager_selectLineToggle		(SEM* ecm, SObject* obj);
	bool					iEditChainManager_selectWordLeft		(SEM* ecm, SObject* obj);
	bool					iEditChainManager_selectWordRight		(SEM* ecm, SObject* obj);
	bool					iEditChainManager_deleteLeft			(SEM* ecm, SObject* obj);
	bool					iEditChainManager_deleteRight			(SEM* ecm, SObject* obj);
	bool					iEditChainManager_deleteWordLeft		(SEM* ecm, SObject* obj);
	bool					iEditChainManager_deleteWordRight		(SEM* ecm, SObject* obj);
