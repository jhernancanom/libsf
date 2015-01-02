//////////
//
// /libsf/source/vjr/source/dbf/cdx_defs.h
//
//////
// Version 0.55
// Copyright (c) 2014 by Rick C. Hodgin
//////
// Last update:
//     Dec.22.2014
//////
// Change log:
//     Dec.22.2014 - Initial creation
//////
//
// This document is released as Liberty Software under a Repeat License, as governed
// by the Public Benefit License v1.0 or later (PBL).
//
// The PBL is a public domain license with a caveat:  self accountability unto God.
// You are free to use, copy, modify and share this software for any purpose, however,
// it is the desire of those working on this project that the software remain open.
// It is our request that you maintain it that way.  This is not a legal request unto
// our court systems, but rather a personal matter between you and God.  Our talents
// were received from God, and given to you through this forum.  And it is our wish
// that those talents reach out to as many as possible in a form allowing them to wield
// this content for their own betterment, as you are now considering doing.  And whereas
// we could've forced the issue through something like a copyleft-protected release, the
// truth is we are all giving an account of our lives unto God continually by the daily
// choices we make.  And here again is another case where you get to demonstrate your
// character unto God, and unto your fellow man.
//
// Jesus came to this Earth to set the captives free, to save men's eternal souls from
// the punishment demanded by our sin.  Each one of us is given the opportunity to
// receive Him in this world and be saved.  Whether we choose to receive Him, and follow
// Him, and purpose our lives on the goals He has for each of us (all of which are
// beneficial for all involved), is one way we reveal our character continually.  God
// sees straight through to the heart, bypassing all of the words, all of the facades.
// He is our Creator, and He knows who we are truly.
//
// Jesus is called "Christ" because He saves men from the eternal flames of Hell, the
// just punishment of rebellion against God (rebellion against truth) by eternal beings,
// which each of us are.
//
// Do not let His free gift escape you because of some desire to shortcut what is right
// in your life. Instead, do what is right, and do it because He is who He is, and what
// He has done to save us from such a fate.  Demonstrate to Him, to me, and to all of
// mankind, and to all of the Heavenly hosts, exactly who you are on the inside.  Receive
// Jesus Christ into your heart, learn of Him, of how He came here to guide us into that
// which is of His Kingdom and will be forever hereafter we leave this world.  Do this,
// and live.
//
// Every project released by Liberty Software Foundation will include a copy of the
// pbl.txt document, which can be found at http://www.libsf.org/licenses/.
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
//
// CDX related
// Note:  Many of the functions referred to in these functions are defined in dbf_defs.h.
//
//////
	u32					cdx_open										(u32 tntnWorkArea, s8* tcCdxFilename, u32 tnCdxFilenameLength, bool tlExclusive);
	u32					cdx_close										(u32 tntnWorkArea);
	u32					cdx_get_tag										(u32 tntnWorkArea,		u32 tnTagIndex,
																			s8* tcTagName,		u32 tnTagNameLength,
																			s8* tcExpression,	u32 tnExpressionLength,
																			s8* tcForClause,	u32 tnForClauseLength,
																			s8* tcKeyLength4,
																			s8* tcUnique1,
																			s8* tcCompact1,
																			s8* tcCompound1,
																			s8* tcOrder1);

	u32					cdx_find_key									(u32 tntnWorkArea, s32 tnTagIndex, u32 tnKeyLength);
	u32					cdx_skip_n										(u32 tntnWorkArea, s32 tnTagIndex, s32 tnDelta);
	u32					cdx_top											(u32 tntnWorkArea, s32 tnTagIndex);
	u32					cdx_bottom										(u32 tntnWorkArea, s32 tnTagIndex);

	u32					cdx_validate_tag								(u32 tntnWorkArea,		s32 tnTagIndex,
																			s8* tcMetaData,		u32 tnMetaDataLength,
																			s8* tcErrorsFound,	u32 tnErrorsFoundLength);

	u32					cdx_validate_keys								(u32 tntnWorkArea,			s32 tnTagIndex,
																			s8* tcMetaData,			u32 tnMetaDataLength,
																			s8* tcErrorsFound,		u32 tnErrorsFoundLength);

	u32					cdx_get_all_keys								(u32 tnDbfHandle,				s32 tnTagIndex,
																			u8* tcKeySpace,				u32 tnKeySpaceLength,
																			u8* tcDecodeExpression,		u32 tnDecodeExpressionLength,
																			s8* tcKeyLength4);

	bool				iCdx_validateIdx								(SWorkArea* wa, s8* tcMetaData, u32 tnMetaDataLength, s8* tcErrorsFound, u32 tnErrorsFoundLength);
	bool				iCdx_validateIdx_compact						(SWorkArea* wa, s8* tcMetaData, u32 tnMetaDataLength, s8* tcErrorsFound, u32 tnErrorsFoundLength);
	bool				iCdx_validateIdx_standard						(SWorkArea* wa, s8* tcMetaData, u32 tnMetaDataLength, s8* tcErrorsFound, u32 tnErrorsFoundLength);
	s32					iCdx_validateCdx								(SWorkArea* wa, s32 tnTagIndex, s8* tcMetaData, u32 tnMetaDataLength, s8* tcErrorsFound, u32 tnErrorsFoundLength);
	s32					iCdx_validateCdxKeys							(SWorkArea* wa, u32 tntnWorkArea, s32 tnTagIndex, s8* tcMetaData, u32 tnMetaDataLength, s8* tcErrorsFound, u32 tnErrorsFoundLength);
	int					iKeys_sortDescending							(const void* l, const void* r);
	int					iKeys_sortAscending								(const void* l, const void* r);
	s32					iCdx_validateIdxKeys							(SWorkArea* wa,                                  s8* tcMetaData, u32 tnMetaDataLength, s8* tcErrorsFound, u32 tnErrorsFoundLength);
//////////
// These are for generating new keys from DBF data, or from manual data loaded for index finds
// BEGIN
//////
	SCdxKeyOp*			iiCdx_generateKey_buildOps						(SWorkArea* wa, u8* keyExpression, s32* tnKeyOpCount);
	bool				iiCdx_generateKey_buildOps_markClosingParenthesis(u8* leftParenthesis, u8 fixupAscii);
	u32					iiCdx_generateKey								(SWorkArea* wa, SCdxHeader* head, u8* keyStorageArea);
	void				iiCdx_generateKey_byOps							(SWorkArea* wa, SCdxKeyOp* keyOps, s32 tnKeyOpCount, u8* keyStorageArea, bool tlBuildFromIndexData);
	void				iiCdx_generateKey_byOps_fixup_swapEndian		(SCdxKeyOp* lko, u8* keyPart);
	void				iiCdx_generateKey_byOps_fixup_date				(SCdxKeyOp* lko, u8* keyPart);
	void				iiCdx_generateKey_byOps_fixup_double			(SCdxKeyOp* lko, u8* keyPart);
	void				iiCdx_generateKey_byOps_fixup_numeric			(SCdxKeyOp* lko, u8* keyPart, SWorkArea* wa);
	bool				iiCdx_generateKey_byOps_fixup					(SWorkArea* wa, SCdxKeyOp* keyOps, s32 tnKeyOpCount, u8* keyStorageArea, bool tlIsCdxKey);
	bool				iiCdx_get_buildOps								(SWorkArea* wa, u32 tnTagIndex, SCdxHeader* tagHeader, SForClause** tsFor, SCdxKeyOp** tsKeyOp, u32* tnKeyOpCount, u32* tnResult);
//////
// END
//////////
	u32					iiCdx_findKey									(SWorkArea* wa, STagRoot* tagRoot, u8* keyBuffer, u32 tnKeyLength);
	s32					iiCdx_translateActualResultThroughIndexOrder	(STagRoot* tagRoot, u8* keyLeft, u8* keyRight, u32 tnKeyLength);
	u32					iCdx_getAllKeysCdx								(SWorkArea* wa, s32 tnTagIndex, u8* tcKeySpace, u32 tnKeySpaceLength, u8* tcDecodeExpression, u32 tnDecodeExpressionLength, s8* tcKeyLength4);
	u32					iCdx_getAllKeysIdx								(SWorkArea* wa,                 u8* tcKeySpace, u32 tnKeySpaceLength, u8* tcDecodeExpression, u32 tnDecodeExpressionLength, s8* tcKeyLength4);
	bool				iCdx_getCompoundTagRoot							(SWorkArea* wa, SCdxHeader* head, SCdxNode* node, u32 lnTagNum, STagRoot* tagRoot);
	bool				iCdx_getCompactRootNode							(SWorkArea* wa, SCdxHeader* head, SCdxNode* node,               STagRoot* tagRoot);
	bool				iCdx_getStandardRootNode						(SWorkArea* wa, SIdxHeader* head, SIdxNode* node,               STagRoot* tagRoot);
	bool				iCdx_isCompact									(SCdxHeader* head);
	bool				iCdx_isCompound									(SCdxHeader* head);
	bool				iCdx_isUnique									(SCdxHeader* head);
	bool				iCdx_isDescending								(SCdxHeader* head);
	bool				iCdx_isForClauseComplex							(SWorkArea* wa, SCdxHeader* head, SForClause** tsFor);
	SIdxNode*			iCdx_getStandardIdxNode_byNumber				(               SIdxHeader* head, u32 tnNodeNumber);
	SIdxNode*			iCdx_getStandardIdxNode_byOffset				(               SIdxHeader* head, u32 tnOffset);
	bool				iCdx_getStandardIdxKey_byNumber					(               SIdxHeader* head, u8 tcFillChar, u32 tnNumber, SIdxNode* node, SIdxKey* key, STagRoot* tagRoot, bool tlFixupEndian, bool tlFixupSignBit);
	SCdxNode*			iCdx_getCompactIdxNode_byNumber					(               SCdxHeader* head, u32 tnNodeNumber);
	SCdxNode*			iCdx_getCompactIdxNode_byOffset					(               SCdxHeader* head, u32 tnOffset);
	bool				iCdx_getCompactIdxKey_byNumber					(               SCdxHeader* head, u32 keyLength, u8 tcFillChar, u32 tnKeyNumber, u32 tnKeyNumberThis, SCdxNode* node, SCdxKey* key, STagRoot* tagRoot, bool tlFixupEndian, bool tlFixupSignBit);
	bool				iiCdx_checkNodeCache							(SCdxNode* node, u32 tnKeyNumber, SCdxKey* key);
	int					iiCdx_checkNodeCache_callback_bsearchAndQsort	(const void* l, const void* r);
	void				iiCdx_addToNodeCache							(SCdxNode* node, u32 tnKeyNumber, SCdxKey* key);
	u32					iCdx_descendToLeftmostNode						(               SCdxHeader* head, u32 keyLength, SCdxNode* node, STagRoot* tagRoot);
	// Internal functions that do not have special testing
	void				iiCdx_extractExteriorNode_nodeKeyAccessData		(SCdxNode* node, u32 tnNumber, SCdxKeyTrail* keyTrail);
