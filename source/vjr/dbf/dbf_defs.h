//////////
//
// /libsf/source/vjr/dbf_defs.h
//
//////
// Version 0.54
// Copyright (c) 2014 by Rick C. Hodgin
//////
// Last update:
//     Nov.02.2014
//////
// Change log:
//     Nov.02.2014 - Initial creation
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



struct SFieldRecord1;
struct SFieldRecord2;


//////////
//
// Used in index FOR clause processing
//
//////
	const u32		_FOR_CLAUSE_OPS_EQUAL_ROW_DATA						= (1 << 0);
	const u32		_FOR_CLAUSE_OPS_LESS_THAN_ROW_DATA					= (1 << 1);
	const u32		_FOR_CLAUSE_OPS_GREATER_THAN_ROW_DATA				= (1 << 2);

	const u32		_FOR_CLAUSE_OPS_EQUAL_TEMPORARY						= (1 << 3);
	const u32		_FOR_CLAUSE_OPS_LESS_THAN_TEMPORARY					= (1 << 4);
	const u32		_FOR_CLAUSE_OPS_GREATER_THAN_TEMPORARY				= (1 << 5);

	const u32		_FOR_CLAUSE_OPS_TEMPORARY_COPY_TO					= (1 << 27);
	const u32		_FOR_CLAUSE_OPS_TEMPORARY_SWAP_ENDIAN				= (1 << 28);
	const u32		_FOR_CLAUSE_OPS_TEMPORARY_SIGN_FLIP_F32				= (1 << 29);
	const u32		_FOR_CLAUSE_OPS_TEMPORARY_SIGN_FLIP_F64				= (1 << 30);
	const u32		_FOR_CLAUSE_OPS_NOT									= (1 << 31);
	// Note:  See iCdx_isForClauseComplex() for their setup through parsing, and iiDbf_forClause_isRowIncluded() for their use in filtering rows

	const u32		_FOR_CLAUSE_SUBITEM_TYPE_ALPHANUMERIC				= 1;	// a_zA_Z0_9
	const u32		_FOR_CLAUSE_SUBITEM_TYPE_NUMERIC					= 2;	// 0_9.+-
	const u32		_FOR_CLAUSE_SUBITEM_TYPE_COMPARATOR					= 3;	// =<>!#
	const u32		_FOR_CLAUSE_SUBITEM_TYPE_QUOTE						= 4;	// " or ' at start with a mated " or ' at end
	const u32		_FOR_CLAUSE_SUBITEM_TYPE_NOT						= 5;	// !, NOT, or .NOT.
	const u32		_FOR_CLAUSE_SUBITEM_TYPE_AND						= 6;	// .AND. or AND
	const u32		_FOR_CLAUSE_SUBITEM_TYPE_OR							= 7;	// .OR. or OR
	const u32		_FOR_CLAUSE_SUBITEM_TYPE_CONSTANT					= 8;	// A constant value
	const u32		_FOR_CLAUSE_SUBITEM_TYPE_LOGICAL_CONSTANT			= 9;	// A .t. or .f.
	const u32		_FOR_CLAUSE_SUBITEM_TYPE_INVALID					= 999;	// Who knows? :-)

	const u32		_FOR_CLAUSE_SUBITEM_ALLOCATION_BLOCK_SIZE			= 20;
	const u32		_FOR_CLAUSE_OP_ALLOCATION_BLOCK_SIZE				= 20;
	const u32		_FOR_CLAUSE_TEMP_ALLOCATION_BLOCK_SIZE				= 20;

	// For index keys
	const u32		_DBF_INDEX_FIXUP_NONE								= 0;
	const u32		_DBF_INDEX_FIXUP_SWAP_ENDIAN						= 1;
	const u32		_DBF_INDEX_FIXUP_FLOAT_DOUBLE						= 2;
	const u32		_DBF_INDEX_FIXUP_DATETIME							= 3;
	const u32		_DBF_INDEX_FIXUP_DATE								= 4;
	const u32		_DBF_INDEX_FIXUP_LOGICAL							= 5;
	const u32		_DBF_INDEX_FIXUP_DELETED							= 6;
	const u32		_DBF_INDEX_FIXUP_NUMERIC							= 8;
	// Upper 4 bits are allocated for additive operations
	const u32		_DBF_INDEX_FIXUP_MASK								= 0x0fffffff;
	const u32		_DBF_INDEX_FIXUP_NULL								= 1 << 29;
	const u32		_DBF_INDEX_FIXUP_UPPER								= 1 << 30;
	const u32		_DBF_INDEX_FIXUP_LOWER								= 1 << 31;




//////////
//
// DBF related
//
/////
	// Startup and shutdown
	void 				iDbf_startup									(void);
	void 				iDbf_shutdown									(void);


	// DBF functions
	uptr				iDbf_open										(s8* table, s8* alias);
	uptr				iDbf_cacheAllRowData							(u32 tnWorkArea);
	uptr				iDbf_close										(u32 tnWorkArea);
	uptr				iDbf_hasCdx										(u32 tnWorkArea);
	sptr				iDbf_isWorkAreaUsed								(u32 tnWorkArea, bool& tlIsDbc);
	sptr				iDbf_getWorkArea_current						(void);
	sptr				iDbf_getWorkArea_lowestFree						(void);
	sptr				iDbf_getWorkArea_highestFree					(void);
	sptr				iDbf_getWorkArea_byAlias						(s8* alias, u32 aliasLength);
	SVariable*			iDbf_getAlias_fromPathname						(s8* tcTablePathname, u32 tnTablePathnameLenth);

	sptr				iDbf_gotoRecord									(u32 tnWorkArea, s32 recordNumber);
	uptr				iDbf_writeChanges								(u32 tnWorkArea);

	uptr				iDbf_getFieldCount								(u32 tnWorkArea);
	uptr				iDbf_getReccount								(u32 tnWorkArea);
	uptr				iDbf_getField_number1							(u32 tnWorkArea, s8* fieldName);
	uptr				iDbf_getField_name								(u32 tnWorkArea, u32 fieldNumber, s8* dest, u32 destLength);
	uptr				iDbf_getField_type								(u32 tnWorkArea, u32 fieldNumber, s8* dest, u32 destLength);
	uptr				iDbf_getField_type_verbose						(u32 tnWorkArea, u32 fieldNumber, s8* dest, u32 destLength);
	uptr				iDbf_getField_type_extended						(u32 tnWorkArea, u32 fieldNumber, s8* dest, u32 destLength);
	uptr				iDbf_getField_length							(u32 tnWorkArea, u32 fieldNumber, s8* dest, u32 destLength);
	uptr				iDbf_getIndex_length							(u32 tnWorkArea, u32 fieldNumber, s8* dest, u32 destLength);
	uptr				iDbf_getField_decimals							(u32 tnWorkArea, u32 fieldNumber, s8* dest, u32 destLength);
	uptr				iDbf_getField_isBinary							(u32 tnWorkArea, u32 fieldNumber, s8* dest, u32 destLength);
	uptr				iDbf_getField_allowNulls						(u32 tnWorkArea, u32 fieldNumber, s8* dest, u32 destLength);
	uptr				iDbf_getNull_flag								(u32 tnWorkArea, u32 fieldNumber, s8* dest, u32 destLength);
	bool				iDbf_getNull_offsetAndMask						(u32 tnWorkArea, u32 fieldNumber, u32* nullOffset, u8* nullMask);
	uptr				iDbf_getField_autoinc_next						(u32 tnWorkArea, u32 fieldNumber, s8* dest, u32 destLength);
	uptr				iDbf_getField_autoinc_step						(u32 tnWorkArea, u32 fieldNumber, s8* dest, u32 destLength);
	uptr				iDbf_getField_data								(u32 tnWorkArea, u32 fieldNumber, s8* dest, u32 destLength);
	uptr				iiDbf_getField_data2							(SWorkArea* wa, u32 fieldNumber, s8* dest, u32 destLength, bool tlRetrieveAsIndexKey);
	uptr				iDbf_getField_dataOffset						(u32 tnWorkArea, u32 fieldNumber);
	uptr				iDbf_getIndexFixupOp							(u32 tnWorkArea, u32 fieldNumber);
	uptr				iDbf_setField_data								(u32 tnWorkArea, s32 fieldNumber, s8* dest, u32 destLength);
	uptr				iDbf_getField_validateContents					(u32 tnWorkArea, u32 fieldNumber, s8* src, u32 srcLength);

	SFieldRecord1*		iDbf_getField_number1							(SWorkArea* wa, u32 fieldNumber);
	SFieldRecord2*		iDbf_getField_number2							(SWorkArea* wa, u32 fieldNumber);
	u8					iDbf_getField_type								(SWorkArea* wa, s8* keyExpression, bool* swapEndians, bool* needsSignBitToggled);
	uptr				iDbf_getField_name								(s8* expression, s8* foundFieldName);

	// Container information
	void				iiDbc_lookupTableField							(SWorkArea* wa, bool* tlIsValid);
	void				iiDbf_getRelativeDbc							(SWorkArea* wa, s8* dbcName);

	// FOR clauses used to test row data for inclusion in various operations
	SForClause*			iDbf_forClause_allocate							(SForClause** tsFor);
	void				iDbf_forClause_delete							(SForClause** tsFor);
	bool				iiDbf_forClause_isRowIncluded					(SWorkArea* wa, SForClause* tsFor);
	bool				iiDbf_forClause_subitems_parse					(SCdxHeader* head, SForClause* tsFor);
	SForSubItem* 		iiDbf_forClause_subitems_appendItem				(SForClause* tsFor);
	SForOp* 			iiDbf_forClause_ops_appendItem					(SForClause* tsFor);
	uptr				iiDbf_forClause_temp_appendConstant				(SForClause* tsFor, s8* tcData, u32 tnDataLength);


//////////
//
// CDX related
//
//////
	u32					cdx_open										(u32 tntnWorkArea, s8* tcCdxFilename, u32 tnCdxFilenameLength);
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

	u32					cdx_find_key									(u32 tntnWorkArea, s32 tnTagIndex);
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
																			s8* tcKeySpace,				u32 tnKeySpaceLength,
																			s8* tcDecodeExpression,		u32 tnDecodeExpressionLength,
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
	SCdxKeyOp*			iiCdx_generateKey_buildOps						(SWorkArea* wa, s8* keyExpression, s32* tnKeyOpCount);
	bool				iiCdx_generateKey_buildOps_markClosingParenthesis(s8* leftParenthesis, s8 fixupAscii);
	u32					iiCdx_generateKey								(SWorkArea* wa, SCdxHeader* head, s8* keyStorageArea);
	void				iiCdx_generateKey_byOps							(SWorkArea* wa, SCdxKeyOp* keyOps, s32 tnKeyOpCount, s8* keyStorageArea, bool tlBuildFromIndexData);
	void				iiCdx_generateKey_byOps_fixup_swapEndian		(SCdxKeyOp* lko, s8* keyPart);
	void				iiCdx_generateKey_byOps_fixup_date				(SCdxKeyOp* lko, s8* keyPart);
	void				iiCdx_generateKey_byOps_fixup_double			(SCdxKeyOp* lko, s8* keyPart);
	void				iiCdx_generateKey_byOps_fixup_numeric			(SCdxKeyOp* lko, s8* keyPart, SWorkArea* wa);
	bool				iiCdx_generateKey_byOps_fixup					(SWorkArea* wa, SCdxKeyOp* keyOps, s32 tnKeyOpCount, s8* keyStorageArea, bool tlIsCdxKey);
	bool				iiCdx_get_buildOps								(SWorkArea* wa, u32 tnTagIndex, SCdxHeader* tagHeader, SForClause** tsFor, SCdxKeyOp** tsKeyOp, u32* tnKeyOpCount, u32* tnResult);
//////
// END
//////////
	u32					iiCdx_findKey									(SWorkArea* wa, STagRoot* tagRoot, s8* keyBuffer);
	u32					iCdx_getAllKeysCdx								(SWorkArea* wa, s32 tnTagIndex, s8* tcKeySpace, u32 tnKeySpaceLength, s8* tcDecodeExpression, u32 tnDecodeExpressionLength, s8* tcKeyLength4);
	u32					iCdx_getAllKeysIdx								(SWorkArea* wa,                 s8* tcKeySpace, u32 tnKeySpaceLength, s8* tcDecodeExpression, u32 tnDecodeExpressionLength, s8* tcKeyLength4);
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
	void				iiCdx_extractExteriorNode_keyAccessMetaData	(SCdxNode* node, u32 tnNumber, SCdxKeyTrail* keyTrail);
	u32					iiXdx_getNodeType								(u32 tnNode);




//////////
//
// Miscellaneous DBF/CDX upport functions
//
/////
	void				iiFreeAndSetToNull								(void** ptr);
	void				iiGetTemporaryFilename							(s8 *temp_file, s8 *prefix);
	void				iiLowerCaseString								(s8 *string, u32 length);
	void				iiJuststem										(SWorkArea* wa, s8* alias);
	void				iiUpperCase										(s8* cptr);
	void				iiLowerCase										(s8* cptr);
	s8					iiLowerCase_char								(s8 c);
	u32					iiBswap32										(u32 tnBigEndian);		// Big-endian to little-endian
	u64					iiBswap64										(u64 tnBigEndian);		// Big-endian to little-endian
	void				iiShiftBlockRight								(u8* data, u32 tnBytes, s32 tnBits);
	void				iiPtrSwap										(void** p1, void** p2);
	s8*					iResetThenCopyString							(s8* tcDest, s32 tnDestLength, s8* tcSource, s32 tnSourceLength);

	// Julian date support
	u32					iiJulianDayNumber_fromYyyyMmDd_s8				(s8* year4,  s8* month2,  s8* day2);
	u32					iiJulianDayNumber_fromYyyyMmDd_u32				(u32 year,  u32  month,  u32  day);
	void				iiYyyyMmDd_fromJulianDayNumber					(u32  tnJulianDayNumber, s8* year4, s8* month2, s8* day2);
	void				iiHhMmSsMss_fromf32								(f32 tfSeconds, u32* hour, u32* minute, u32* second, u32* millisecond);

	// Character tests
	bool				isAlpha											(s8 c);
	bool				isNumeric										(s8 c);
	bool				isDotExpression									(s8 c);
	bool				isComparator									(s8 c);
	bool				isQuote											(s8 c);
	bool				isNotSymbol										(s8 c);
	bool				isParenthesis									(s8 c);
	bool				isBracket										(s8 c);
	bool				isBrace											(s8 c);
	bool				isWhitespace									(s8 c);
