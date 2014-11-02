//////////
//
// /libsf/source/vjr/compiler.h
//
//////
// Version 0.54
// Copyright (c) 2014 by Rick C. Hodgin
//////
// Last update:
//     Jun.29.2014
//////
// Change log:
//     Jun.29.2014 - Initial creation
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




struct SEM;
struct SLine;
struct SFunction;
struct SNode;
struct SLL;
struct SLLCallback;
struct SComp;
struct SCompCallback;
struct SCompiler;
struct SCompileStats;
struct SCompileNote;
struct SAsciiCompSearcher;
struct SStartEnd;
struct SStartEndCallback;
struct SOp;
struct SMasterList;
struct SVariable;


//////////
// compiler.cpp
//////////
	u32						compile_vxb									(SEM* codeBlock, SCompileVxbContext* vxbParam, SCompileStats* stats);
	void					iiCompile_vxb_precompile					(SCompileVxbContext* vxb);
	void					iiCompile_vxb_compile						(SCompileVxbContext* vxb);
	void					iiCompile_vxb_postcompile					(SCompileVxbContext* vxb);

	SFunction*				iiComps_decodeSyntax_function				(SCompileVxbContext* vxb);
	SFunction*				iiComps_decodeSyntax_adhoc					(SCompileVxbContext* vxb);
	void					iiComps_decodeSyntax_params					(SCompileVxbContext* vxb);
	void					iiComps_decodeSyntax_lobject				(SCompileVxbContext* vxb);
	void					iiComps_decodeSyntax_lparameters			(SCompileVxbContext* vxb);
	void					iiComps_decodeSyntax_returns				(SCompileVxbContext* vxb);

	bool					iiComps_xlatToNodes							(SLine* line, SCompiler* compiler);
	SNode*					iiComps_xlatToNodes_parenthesis_left		(SNode** root, SNode* active, SComp* comp);
	SNode*					iiComps_xlatToNodes_parenthesis_right		(SNode** root, SNode* active, SComp* comp);

	void					iComps_deleteAll_byLine						(SLine* line);
	void					iComps_deleteAll_byFirstComp				(SComp** firstComp);
	void					iComps_delete								(SComp* comp, bool tlDeleteSelf);
 	SComp*					iComps_translateSourceLineTo				(SAsciiCompSearcher* tsComps, SLine* line);
 	bool					iComps_translateToOthers					(SAsciiCompSearcher* tsComps, SLine* line);
	bool					iComps_areAllPrecedingCompsWhitespaces		(SComp* comp);
	s32						iComps_translateToOthers_testIfMatch		(s8* tcHaystack, s8* tcNeedle, s32 tnLength);
	SComp*					iComps_findNextBy_iCode						(SComp* comp, s32 tniCode, SComp** compLastScanned);
	SComp*					iComps_activeComp_inSEM						(SEM* sem);
	bool					iComps_getMateDirection						(SComp* comp, s32* tnMateDirection);
	bool					iComps_findClosest_parensBracketsBraces		(SComp* compRelative, SComp* compStart, SComp** compPBBLeft, SComp** compPBBRight);
	bool					iComps_isParensBracketsBraces				(SComp* comp);
	bool					iComps_isMateOf								(SComp* compTest, s32 tniCodeMate);
	SComp*					iComps_skipPast_iCode						(SComp* comp, s32 tniCode);
	SComp*					iComps_skipTo_iCode							(SComp* comp, s32 tniCode);
	u32						iComps_combineNextN							(SComp* comp, u32 tnCount, s32 tnNewICode, s32 tnNewICat, SBgra* newColor);
	u32						iComps_combineAdjacentAlphanumeric			(SLine* line);
	u32						iComps_combineAdjacentNumeric				(SLine* line);
	u32						iComps_combineAdjacentDotForms				(SLine* line);
	u32						iComps_combineAllBetween					(SLine* line, s32 tniCodeNeedle,		s32 tniCodeCombined,											SBgra* syntaxHighlightColor);
	u32						iComps_combineAllBetween2					(SLine* line, s32 tniCodeNeedleLeft,	s32 tniCodeNeedleRight,		s32 tniCodeCombined,	s32 tniCat, SBgra* syntaxHighlightColor, bool tlUseBoldFont);
	u32						iComps_combineAllAfter						(SLine* line, s32 tniCodeNeedle);
	u32						iComps_deleteAllAfter						(SLine* line, s32 tniCodeNeedle);
	u32						iComps_removeLeadingWhitespaces				(SLine* line);
	u32						iComps_removeWhitespaces					(SLine* line);
	void					iComps_removeStartEndComments				(SLine* line);
	void					iComps_combineCasks							(SLine* line);
	void					iComps_fixupNaturalGroupings				(SLine* line);
	s32						iiComps_charactersBetween					(SComp* compLeft, SComp* compRight);

//////////
// Jun.25.2014 -- This block of code was originally created before I began working on
// iiTranslateSOpsToSubInstr() above.  As such, it is stale and will probably be
// refactored or deleted.
// BEGIN
//////
	void					iiComps_xlatToSubInstr						(SLine* line);
	SComp*					iiComps_xlatToSubInstr_findInmostExpression	(SNode* si, SLine* line);
	void					iiComps_xlatToSubInstr_findStartOfComponent	(SComp* compRoot, SOp* op);
	void					iiComps_xlatToSubInstr_findFullComponent	(SComp* compRoot, SOp* op);
	bool					iiComps_xlatToSubInstr_isEqualAssignment	(SLine* line);
//////
// END
//////////

	u32						iBreakoutAsciiTextDataIntoLines_ScanLine	(s8* tcData, u32 tnMaxLength, u32* tnLength, u32* tnWhitespaces);
	bool					iFindFirstOccurrenceOfAsciiCharacter		(s8* tcHaystack, u32 tnHaystackLength, s8 tcNeedle, u32* tnPosition);
	u32						iGetNextUid									(void);

	void*					iSEChain_prepend							(SStartEnd* ptrSE, u32 tnUniqueId, u32 tnUniqueIdExtra, u32 tnSize, u32 tnBlockSizeIfNewBlockNeeded, bool* tlResult);
	void*					iSEChain_append								(SStartEnd* ptrSE, u32 tnUniqueId, u32 tnUniqueIdExtra, u32 tnSize, u32 tnBlockSizeIfNewBlockNeeded, bool* tlResult);
	void*					iSEChain_appendOrPrepend					(SStartEnd* ptrSE, u32 tnUniqueId, u32 tnUniqueIdExtra, u32 tnSize, u32 tnBlockSizeIfNewBlockNeeded, bool tlPrepend, bool* tlResult);
	u32						iSkipWhitespaces							(s8* tcData, u32 tnMaxLength);
	u32						iSkipToCarriageReturnLineFeed				(s8* tcData, u32 tnMaxLength, u32* tnCRLF_Length);
	void					iSEChain_appendMasterList					(SStartEnd* ptrSE, SMasterList* ptrNew, u32 tnHint, u32 tnBlockSizeIfNewBlockNeeded);
	bool					iSEChain_allocateAdditionalMasterSlots		(SStartEnd* ptrSE, u32 tnBlockSize);

	s32						iTranslateToCompsTest						(s8* tcHaystack, s8* tcNeedle, s32 tnLength);
	bool					iioss_translateCompsToOthersCallback		(SStartEndCallback* cb);
	void*					iSEChain_searchByCallback					(SStartEnd* ptrSE, SStartEndCallback* cb);
	void*					iSEChain_searchByUniqueId					(SStartEnd* ptrSE, u64 tnUniqueId);
	void					iSEChain_iterateThroughForCallback			(SStartEnd* ptrSE, SStartEndCallback* cb);
	void					iiComps_xlatToOthersCallback__insertCompByCompCallback		(SComp* compRef, SComp* compNew, bool tlInsertAfter);
	void					iiComps_xlatToOthersCallback__insertCompByParamsCallback	(SComp* compRef, SLine* line, u32 tniCode, u32 tnStart, s32 tnLength, bool tlInsertAfter);
	void					iiComps_xlatToOthersCallback__deleteCompsCallback			(SComp* comp, SLine* line);
	SComp*					iiComps_xlatToOthersCallback__cloneCompsCallback			(SComp* comp, SLine* line);
	SComp*					iiComps_xlatToOthersCallback__mergeCompsCallback			(SComp* comp, SLine* line, u32 tnCount, u32 tniCodeNew);
	void					iSEChain_deleteFrom							(SStartEnd* ptrSE, void* ptrCaller, bool tlDeletePointers);
	SLL*					iSEChain_completelyMigrateSLLByPtr			(SStartEnd* ptrSEDst, SStartEnd* ptrSESrc, SLL* ptr, u32 tnHint, u32 tnBlockSize);
	SLL*					iSEChain_completelyMigrateSLLByNum			(SStartEnd* ptrSEDst, SStartEnd* ptrSESrc, u32 lnSrcNum, u32 tnHint, u32 tnBlockSize);
	SMasterList*			iSEChain_migrateByNum						(SStartEnd* ptrSEDst, SStartEnd* ptrSESrc, u32 lnSrcNum, u32 tnHint, u32 tnBlockSize);

	// Callbacks on SComp finds
	void					ii_onFind_countNbsp							(SAsciiCompSearcher* tacs, SComp* comp);

	// Node functions
	SNode*					iNode_create								(SNode** root, SNode* hint, u32 tnDirection, SNode* parent, SNode* prev, SNode* next, SNode* left, SNode* right);
	SNode*					iNode_insertBetween							(SNode** root, SNode* node1, SNode* node2, u32 tnNode1Direction, u32 tnNode2Direction);
	void					iNode_politelyDeleteAll						(SNode** root, bool tlDeleteSelf, bool tlTraverseParent, bool tlTraversePrev, bool tlTraverseNext, bool tlTraverseLeft, bool tlTraverseRight);

	// Function functions (LOL)
	SFunction*				iFunction_allocate							(SComp* compName);
	SFunction*				iFunction_allocate							(s8* tcFuncName);
	SVariable*				iFunction_addVariable_scoped				(SFunction* func);
	void					iFunction_politelyDeleteCompiledInfo		(SFunction* func, bool tlDeleteSelf);
	void					iFunction_politelyDeleteChain				(SFunction** rootFunc);

	// Variable functions
	SVariable*				iiVariable_terminateIndirect				(SVariable* var);
	SVariable*				iVariable_create							(s32 tnVarType, SVariable* varIndirect);
	SVariable*				iVariable_createAndPopulate					(s32 tnVarType, SDatum* datum);
	SVariable*				iVariable_createAndPopulate					(s32 tnVarType, s8*  tcData, u32 tnDataLength);
	SVariable*				iVariable_createAndPopulate					(s32 tnVarType, cs8* tcData, u32 tnDataLength);
	SVariable*				iVariable_searchForName						(SVariable* varRoot, s8* tcVarName, u32 tnVarNameLength, SComp* comp);
	bool					iVariable_setDefaultVariableValue			(s32 tnVarType);
	void					iVariable_createDefaultValues				(void);
	void					iVariable_createPropsMaster					(void);
	bool					iVariable_isVarTypeValid					(s32 tnVarType, SVariable** varDefaultValue);
	bool					iVariable_areTypesCompatible				(SVariable* var1, SVariable* var2);
	bool					iVariable_copy								(SVariable* varDst, SVariable* varSrc);
	SVariable*				iVariable_copy								(SVariable* varSrc, bool tlMakeReference);
	bool					iVariable_set								(SVariable* varDst, SVariable* varSrc);
	bool					iVariable_set_s32							(SVariable* var, s32 value);
	bool					iVariable_set_u32							(SVariable* var, u32 value);
	bool					iVariable_set_f32							(SVariable* var, f32 value);
	bool					iVariable_set_f64							(SVariable* var, f64 value);
	bool					iVariable_set_logical						(SVariable* var, bool tlValue);
	bool					iVariable_set_logical						(SVariable* var, s32 value);
	bool					iVariable_set_bitmap						(SVariable* var, SBitmap* bmp);
	bool					iVariable_set_character						(SVariable* var, s8* tcData, u32 tnDataLength);
	bool					iVariable_set_character						(SVariable* var, SDatum* datum);
	void					iVariable_reset								(SVariable* var);
	SVariable*				iVariable_convertForDisplay					(SVariable* var);
	void					iVariable_delete							(SVariable* var, bool tlDeleteSelf);
	void					iVariable_politelyDeleteChain				(SVariable** root, bool tlDeleteSelf);
	void					iVariable_politelyDeleteChain_callback		(SLLCallback* cb);
	s32						iiVariable_getAs_s32						(SVariable* var, bool tlForceConvert, bool* tlError, u32* tnErrorNum);
	s64						iiVariable_getAs_s64						(SVariable* var, bool tlForceConvert, bool* tlError, u32* tnErrorNum);
	f32						iiVariable_getAs_f32						(SVariable* var, bool tlForceConvert, bool* tlError, u32* tnErrorNum);
	f64						iiVariable_getAs_f64						(SVariable* var, bool tlForceConvert, bool* tlError, u32* tnErrorNum);
	s64						iiVariable_getCompAs_s64					(SComp* comp);

	// Support functions
	s32						iiVariable_julianDayNumber_fromYyyyMmDd			(f32* tnJulianDayNumber, u32  year, u32  month, u32  day);
	void					iiVariable_computeYyyyMmDd_fromJulianDayNumber	(u32  tnJulianDayNumber, u32* year, u32* month, u32* day);
	void					iiVariable_computeHhMmSsMss_fromf32			(f32 tfSeconds, u32* hour, u32* minute, u32* second, u32* millisecond);
	s64						iiVariable_computeDatetimeDifference		(SVariable* dtVar1, SVariable* dtVar2);
	bool					iVariable_isDayValidForDate					(u32 year, u32 month, u32 day);

	// Op functions
	bool					iOp_setNull									(SOp* op);
	bool					iOp_setVariable_param						(SOp* op, SVariable* var, bool isOpAllocated);
	bool					iOp_setVariable_local						(SOp* op, SVariable* var, bool isOpAllocated);
	bool					iOp_setVariable_scoped						(SOp* op, SVariable* var, bool isOpAllocated);
	bool					iOp_setVariable_return						(SOp* op, SVariable* var, bool isOpAllocated);
	void					iOp_politelyDelete							(SOp* op, bool tlDeleteSelf);

	// Error and warning functions
	void					iComp_appendError							(SComp* comp, u32 tnErrorNum,   s8* tcMessage);
	void					iComp_appendWarning							(SComp* comp, u32 tnWarningNum, s8* tcMessage);
	void					iComp_reportWarningsOnRemainder				(SComp* comp, u32 tnWarningNum, s8* tcMessage);


	// Line functions
	void					iLine_appendError							(SLine* line, u32 tnErrorNum,   s8* tcMessage, u32 tnStartColumn, u32 tnLength);
	void					iLine_appendWarning							(SLine* line, u32 tnWarningNum, s8* tcMessage, u32 tnStartColumn, u32 tnLength);

	// Compiler functions
	SCompiler*				iCompiler_allocate							(SLine* parent);
	void					iCompiler_delete							(SCompiler** root, bool tlDeleteSelf);

	// Compile note functions
	SCompileNote*			iCompileNote_create							(SCompileNote** noteRoot, u32 tnStart, u32 tnEnd, u32 tnNumber, s8* tcMessage);
	SCompileNote*			iCompileNote_appendMessage					(SCompileNote** noteRoot, u32 tnStartColumn, u32 tnEndColumn, u32 tnNumber, s8* tcMessage);
	void					iCompileNote_removeAll						(SCompileNote** noteRoot);
