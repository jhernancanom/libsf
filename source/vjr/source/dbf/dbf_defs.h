//////////
//
// /libsf/source/vjr/source/dbf/dbf_defs.h
//
//////
// Version 0.55
// Copyright (c) 2014 by Rick C. Hodgin
//////
// Last update:
//     Nov.02.2014
//////
// Change log:
//     Nov.02.2014 - Initial creation
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
// Note:  All CDX related functions are defined in cdx_defs.h
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
	sptr				iDbf_isWorkAreaUsed								(u32 tnWorkArea);
	bool				iDbf_isWorkAreaLetter							(SVariable* var);
	sptr				iDbf_getWorkArea_current						(void);
	sptr				iDbf_getWorkArea_lowestFree						(void);
	sptr				iDbf_getWorkArea_highestFree					(void);
	sptr				iDbf_getWorkArea_byAlias						(SVariable* varAlias);
	SVariable*			iDbf_getAlias_fromPathname						(SVariable* varPathname);

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
// Miscellaneous DBF/CDX upport functions
//
/////
	u32					iiGetIndexNodeType								(u32 tnNode);
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
