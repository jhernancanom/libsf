//////////
//
// /libsf/source/vjr/source/compiler/vxb/vxb_compiler.cpp
//
//////
// Version 0.54
// Copyright (c) 2014 by Rick C. Hodgin
//////
// Last update:
//     Jun.17.2014
//////
// Change log:
//     Jun.17.2014 - Initial creation
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
// Compiles a VXB source code block.  If tlEditAndContinue is true, then only those
// lines which have differing line->compilerInfo->sourceCode and line->sourceCode are
// compiled.  If the current debug environment is operating on this line, the debugger
// will need to take special note about the before and after sub-instructions to
// to determine if the current location can be maintained, or if the line needs to
// start over.
//
//////
	u32 compile_vxb(SEM* codeBlock, SCompileVxbContext* vxbParam, SCompileStats* stats)
	{
		SCompileVxbContext*	vxb;
		SCompileVxbContext	vxbLocal;


		//////////
		// Use their, or our, compile context
		//////
			if (vxbParam)
			{
				// Theirs
				vxb = vxbParam;

			} else {
				// Ours
				vxb = &vxbLocal;
			}


		//////////
		// Initialize our compile context
		//////
			memset(vxb, 0, sizeof(SCompileVxbContext));
			vxb->codeBlock	= codeBlock;
			vxb->stats		= stats;

			// If they provided stats, then we'll use those
			if (!vxb->stats)
				vxb->stats = &vxb->statsLocal;

			// Reset all our stats
			memset(vxb->stats, 0, sizeof(SCompileStats));


		//////////
		// Make sure our environment is sane
		//////
			if (vxb->codeBlock && vxb->codeBlock->firstLine)
			{
				// Before compilation, we need to remove any dependencies on things that have changed
				iiCompile_vxb_precompile_forEditAndContinue(vxb);

				// Physically compile
				iiCompile_vxb_compile_forEditAndContinue(vxb);		// Note:  Compilation compiles source code, and generates executable ops

				// After compilation, clean up anything that's dead
				iiCompile_vxb_postcompile_forEditAndContinue(vxb);
			}


		//////////
		// Indicate our result
		//////
			return(vxb->stats->sourceLineCount);
	}




//////////
//
// Called before compilation to remove any references to any lines that have
// changed, so all of those lines will be recompiled as well.  The references
// are things like FUNCTION definitions, PARAMS, LOBJECT, LPARAMETERS, LOCALS,
// RETURNS, ADHOC, anything that defines functions or variables.  As each of
// those are removed a list is built, and then each source code line is searched
// exhaustively to find out if any component on those lines references the now
// removed variable.  If so, it will be marked for recompilation as well so it
// references what will become the new function, new adhoc, or new variable.
//
//////
	void iiCompile_vxb_precompile_forEditAndContinue(SCompileVxbContext* vxb)
	{
		// Make a full deep copy of the current codeBlock
	}




//////////
//
// Called to physically compile each line of source code.
//
//////
	void iiCompile_vxb_compile_forEditAndContinue(SCompileVxbContext* vxb)
	{
		// Begin compiling
		vxb->currentFunction	= NULL;
		vxb->currentAdhoc		= NULL;
		vxb->currentFlowof		= NULL;

		// Iterate through every line in this codeBlock
		for (
				vxb->line = vxb->codeBlock->firstLine;		// Init
				vxb->line;									// Test
				vxb->line = (SLine*)vxb->line->ll.next		// Increment
			)
		{
			// Increase our line count
			++vxb->stats->sourceLineCount;

			// Make sure we have a compilerInfo object
			if (!vxb->line->compilerInfo)
				vxb->line->compilerInfo = iCompiler_allocate(vxb->line);

			// Is there anything to parse on this line?
			if (vxb->line->sourceCode && vxb->line->sourceCode_populatedLength > 0)
			{
				//////////
				// Determine if this line needs compiled
				//////
					// We are in edit-and-continue mode, which means we only process this line
					// if its contents have changed.  Otherwise, we use what was already compiled.
					if (!vxb->line->compilerInfo->sourceCode || vxb->line->forceRecompile || !vxb->line->compilerInfo->firstComp)
					{
						// This line has not yet been compiled
						vxb->processThisLine = true;

					} else if (vxb->line->sourceCode->length != vxb->line->compilerInfo->sourceCode->length) {
						// The lines are no longer the same length
						vxb->processThisLine = true;

					} else if (iDatum_compare(vxb->line->sourceCode, vxb->line->compilerInfo->sourceCode) != 0) {
						// The source code contents vary
						vxb->processThisLine = true;

					} else if (vxb->line->compilerInfo->firstWarning || vxb->line->compilerInfo->firstError) {
						// Warnings or errors are attached to it, so it needs recompiled to see if those will have been resolved by other source code lines having changed
						vxb->processThisLine = true;

					} else {
						// Lines are identical.  Does not need re-compiled.
						vxb->processThisLine = false;
					}


				//////////
				// If we're not processing, synchronize movement through the source file
				//////
					if (!vxb->processThisLine)
					{
						// In an edit-and-continue environment, we have to track functions so we maintain the
						// current function we are in, even if the source code for those functions didn't change.
						if (vxb->line->compilerInfo->firstComp)
						{
							// We need to track certain things through on non-compiled lines

							//////////
							// FUNCTION
							//////
								if (vxb->line->compilerInfo->firstComp->iCode == _ICODE_FUNCTION)
								{
									// We've moved into another function


							//////////
							// ADHOC
							//////
								} else if (vxb->line->compilerInfo->firstComp->iCode == _ICODE_ADHOC) {
									// We've moved into an adhoc

								} else if (vxb->line->compilerInfo->firstComp->iCode == _ICODE_ENDADHOC) {
									// We've moved out of the adhoc
									vxb->currentAdhoc = NULL;
								}
						}
						// Move on to next line
						continue;
					}


				//////////
				// Note:  This while block exists so it can be exited structurally.
				// Note:  It does not loop.
				//////
					while (1)
					{
						//////////
						// We need to clear out anything from any prior compile
						//////
							iComps_deleteAll_byLine(vxb->line);
							iCompiler_delete(&vxb->line->compilerInfo, false);


						//////////
						// Convert raw source code to known character sequences
						//////
							iComps_translateSourceLineTo(&cgcFundamentalSymbols[0], vxb->line);
							if (!vxb->line->compilerInfo->firstComp)
							{
								++vxb->stats->blankLineCount;
								break;		// Nothing to compile on this line
							}
							vxb->comp = vxb->line->compilerInfo->firstComp;


						//////////
						// If it's a line comment, we don't need to process it
						//////
							if (vxb->line->compilerInfo->firstComp->iCode == _ICODE_COMMENT || vxb->line->compilerInfo->firstComp->iCode == _ICODE_LINE_COMMENT)
							{
								++vxb->stats->commentLineCount;
								break;
							}


						//////////
						// Perform fixups
						//////
							iComps_removeStartEndComments(vxb->line);			// Remove /* comments */
							iComps_fixupNaturalGroupings(vxb->line);			// Fixup natural groupings [_][aaa][999] becomes [_aaa999], [999][.][99] becomes [999.99], etc.
							iComps_removeWhitespaces(vxb->line);				// Remove whitespaces [use][whitespace][foo] becomes [use][foo]


						//////////
						// Translate sequences to known keywords
						//////
							iComps_translateToOthers(&cgcKeywordsVxb[0], vxb->line);


						//////////
						// Process this line based upon what it is
						//////
							if (vxb->comp->iCode == _ICODE_FUNCTION)
							{
								// They are adding another function
								vxb->currentFunction = iiComps_decodeSyntax_function(vxb);


							} else if (vxb->comp->iCode == _ICODE_ADHOC) {
								// They are adding an adhoc function
								iiComps_decodeSyntax_adhoc(vxb);


							} else if (vxb->comp->iCode == _ICODE_PARAMS) {
								// They are adding parameters
								// Process the PARAMS line
// TODO:  working here
								iiComps_decodeSyntax_params(vxb);


							} else if (vxb->comp->iCode == _ICODE_LOBJECT) {
								// They are adding parameters via an object
								// Process the LOBJECT line
// TODO:  working here
								iiComps_decodeSyntax_lobject(vxb);


							} else if (vxb->comp->iCode == _ICODE_LPARAMETERS) {
								// They are adding lparameters
								// Process the LPARAMETERS line
// TODO:  working here
								iiComps_decodeSyntax_lparameters(vxb);


							} else if (vxb->comp->iCode == _ICODE_RETURNS) {
								// They are specifying returns
								// Process the RETURNS line
// TODO:  working here
								iiComps_decodeSyntax_returns(vxb);


							} else {
								// Translate into operations
								iiComps_xlatToNodes(vxb->line, vxb->line->compilerInfo);
								// Note:  Right now, line->errors and line->warnings have notes attached to them about the compilation of this line
							}


						// All done with this line
						break;
					}
			}
		}
	}




//////////
//
// Called to post-compile, primarily to flag variables that are not referenced
// 
//////
	void iiCompile_vxb_postcompile_forEditAndContinue(SCompileVxbContext* vxb)
	{
	}




//////////
//
// Called to handle a FUNCTION source code line.
//
// Syntax:	FUNCTION cFunctionName
//
//////
	SFunction* iiComps_decodeSyntax_function(SCompileVxbContext* vxb)
	{
		SComp*		comp;
		SComp*		compName;
		SFunction*	func;


		// Make sure our environment is sane
		func = NULL;
		if (vxb->codeBlock && vxb->line && vxb->line->compilerInfo)
		{
			// The syntax must be [FUNCTION][cFunctionName]
			if ((comp = vxb->line->compilerInfo->firstComp) && comp->iCode == _ICODE_FUNCTION)
			{
				// [FUNCTION]
				if (comp->ll.next)
				{
					// [FUNCTION][something after]
					if ((compName = (SComp*)comp->ll.next) && (compName->iCode == _ICODE_ALPHA || compName->iCode == _ICODE_ALPHANUMERIC))
					{
						// [FUNCTION][cFuncionName]
// TODO:  We need to do a lookup on this name to see if we're replacing a function, or adding a new one

						// Create the new function
						func = iFunction_allocate(compName);

						// Indicate information about this function
						func->firstLine	= vxb->line;
						func->lastLine	= vxb->line;

// TODO:  Needs added to the current function chain

						// Generate warnings for ignored components if any appear after
						iComp_reportWarningsOnRemainder((SComp*)compName->ll.next, _WARNING_SPURIOUS_COMPONENTS_IGNORED, (cu8*)cgcSpuriousIgnored);
					}
				}
			}
		}

		// Indicate our status
		return(func);
	}




//////////
//
// Called to handle an ADHOC source code line.
//
// Syntax:	ADHOC cAdhocName
//
//////
	SFunction* iiComps_decodeSyntax_adhoc(SCompileVxbContext* vxb)
	{
		SComp*		comp;
		SComp*		compName;
		SFunction*	adhoc;


		// Make sure our environment is sane
		adhoc = NULL;
		if (vxb->codeBlock && vxb->line && vxb->line->compilerInfo)
		{
			// The syntax must be [ADHOC][cAdhocName]
			if ((comp = vxb->line->compilerInfo->firstComp) && comp->iCode == _ICODE_ADHOC)
			{
				// [ADHOC]
				if (comp->ll.next)
				{
					// [ADHOC][something after]
					if ((compName = (SComp*)comp->ll.next) && (compName->iCode == _ICODE_ALPHA || compName->iCode == _ICODE_ALPHANUMERIC))
					{
						// [ADHOC][cAdhocName]
// TODO:  We need to do a lookup on this name to see if we're replacing an adhoc, or adding a new one

						// Create the new adhoc
						adhoc = iFunction_allocate(compName);

						// Indicate information about this adhoc
						adhoc->firstLine	= vxb->line;
						adhoc->lastLine		= vxb->line;

// TODO:  Needs added to the current function

						// Generate warnings for ignored components if any appear after
						iComp_reportWarningsOnRemainder((SComp*)compName->ll.next, _WARNING_SPURIOUS_COMPONENTS_IGNORED, cgcSpuriousIgnored);
					}
				}
			}
		}

		// Indicate our status
		return(adhoc);
	}




void iiComps_decodeSyntax_params(SCompileVxbContext* vxb)
{
// TODO:  write this function
}

void iiComps_decodeSyntax_lobject(SCompileVxbContext* vxb)
{
// TODO:  write this function
}

void iiComps_decodeSyntax_lparameters(SCompileVxbContext* vxb)
{
// TODO:  write this function
}

void iiComps_decodeSyntax_returns(SCompileVxbContext* vxb)
{
// TODO:  write this function
}




//////////
//
// Translates components into a sequence of sub-instruction operations.
//
/////
	bool iiComps_xlatToNodes(SLine* line, SCompiler* compiler)
	{
		SComp*		comp;
		SNode*		nodeActive;			// Current active node


		// Iterate through every component building the operations as we go
		comp		= line->compilerInfo->firstComp;
//		compLast	= comp;
		nodeActive	= iNode_create(&compiler->firstNode, NULL, 0, NULL, NULL, NULL, NULL, NULL);
		while (comp)
		{
			//////////
			// If it's an operand we're looking for, then we process it
			//////
				switch (comp->iCode)
				{
					// (
					case _ICODE_PARENTHESIS_LEFT:
						nodeActive = iiComps_xlatToNodes_parenthesis_left(&compiler->firstNode, nodeActive, comp);
						break;

					// )
					case _ICODE_PARENTHESIS_RIGHT:
						nodeActive = iiComps_xlatToNodes_parenthesis_right(&compiler->firstNode, nodeActive, comp);
						break;

					// [
					case _ICODE_BRACKET_LEFT:
						break;

					// ]
					case _ICODE_BRACKET_RIGHT:
						break;

					// {
					case _ICODE_BRACE_LEFT:
						break;

					// }
					case _ICODE_BRACE_RIGHT:
						break;

					// <<
					case _ICODE_SHIFT_LEFT:
						break;

					// >>
					case _ICODE_SHIFT_RIGHT:
						break;

					// ^ or **
					case _ICODE_EXPONENT:
						break;

					// ++
					case _ICODE_PLUS_PLUS:
						break;

					// --
					case _ICODE_MINUS_MINUS:
						break;

					// *
					case _ICODE_ASTERISK:
						break;

					// /
					case _ICODE_SLASH:
						break;

					// %
					case _ICODE_PERCENT_SIGN:
						break;

					// +
					case _ICODE_PLUS:
						break;

					// -
					case _ICODE_HYPHEN:
						break;

					// $
					case _ICODE_FOUND_IN:
						break;

					// !$
					case _ICODE_NOT_FOUND_IN:
						break;

					// NOT or !
					case _ICODE_NOT:
					case _ICODE_EXCLAMATION_POINT:
						break;

					// AND
					case _ICODE_AND:
						break;

					// OR
					case _ICODE_OR:
						break;

					// <<=
					case _ICODE_SHIFT_LEFT_ASSIGNMENT:
						break;

					// >>=
					case _ICODE_SHIFT_RIGHT_ASSIGNMENT:
						break;

					// =
					case _ICODE_EQUAL_SIGN:
						break;

					// <
					case _ICODE_LESS_THAN:
						break;

					// >
					case _ICODE_GREATER_THAN:
						break;

					// <>, #, !=
					case _ICODE_NOT_EQUAL:
					case _ICODE_POUND_SIGN:
						break;

					// <= or =<
					case _ICODE_LESS_THAN_OR_EQUAL_TO:
						break;

					// >= or =>
					case _ICODE_GREATER_THAN_OR_EQUAL_TO:
						break;

					// ==
					case _ICODE_EXACTLY_EQUAL_TO:
						break;

					// FLAGS
					case _ICODE_FLAGS:
						break;
				}


			//////////
			// Are we in error?  If so, we stop compiling this line.
			//////
				if (nodeActive->opData->op.opType == _OP_TYPE_NULL)
				{
					// We are in error
					return(false);
				}


			//////////
			// Move to next component
			//////
//				compLast	= comp;
				comp		= (SComp*)comp->ll.next;
		}

		// If we get here everything was processed properly
		return(true);
	}




//////////
//
// Processes the left parenthesis.  Takes an existing item like this (note the [?] is the active node):
//     x = (a + b) + c
//      / \
//     x  [?]
//
// And translates it into this:
//     x = (a + b) + c
//      / \
//     x   (
//          \
//          [?]
//
//////
	SNode* iiComps_xlatToNodes_parenthesis_left(SNode** root, SNode* active, SComp* comp)
	{
		SNode*		node;
		SVariable*	var;


		// Insert a parenthesis node at the active node, and direct the active node to the right
		node = iNode_insertBetween(root, active->parent, active, _NODE_PARENT, _NODE_RIGHT);
		if (node)
		{
			//////////
			// Update its operation to our parenthesis
			//////
				node->opData->op.opType	= _OP_TYPE_PARENTHESIS_LEFT;
				node->opData->op.comp		= comp;


			//////////
			// Indicate we'll need a temporary variable for our result
			//////
				var = iVariable_create(_VAR_TYPE_NULL, NULL);
				if (var)
				{
					// Append the temporary variable
					iOp_setVariable_scoped(&node->opData->op, var, true);

				} else {
					// Internal compile error
					iComp_appendError(comp, _ERROR_OUT_OF_MEMORY, (u8*)cgcOutOfMemory);
					iOp_setNull(&node->opData->op);
				}
		}

		// Indicate our status
		return(node);
	}




//////////
//
// Process the right parenthesis.
//
//////
	SNode* iiComps_xlatToNodes_parenthesis_right(SNode** root, SNode* active, SComp* comp)
	{
// TODO:  Working here
		return(NULL);
	}




//////////
//
// Called to remove all components for this line
//
//////
	void iComps_deleteAll_byLine(SLine* line)
	{
		SComp*	comp;
		SComp*	compNext;


		// Make sure our environment is sane
		if (line && line->compilerInfo)
		{
			// Delete all components
			comp = line->compilerInfo->firstComp;
			while (comp)
			{
				// Grab the next comp
				compNext = (SComp*)comp->ll.next;

				// Delete this one
				iComps_delete(comp, true);

				// Move to the next one
				comp = compNext;
			}

			// Reset the pointer
			line->compilerInfo->firstComp = NULL;

			// Clear the compilerInfo
			iCompiler_delete(&line->compilerInfo, true);
		}
	}




//////////
//
// Deletes everything from this first component
//
//////
	void iComps_deleteAll_byFirstComp(SComp** firstComp)
	{
		SComp* comp;
		SComp* compNext;


		// Make sure the environment is sane
		if (firstComp && *firstComp)
		{
			comp = *firstComp;
			while (comp)
			{
				// Grab the next comp
				compNext = (SComp*)comp->ll.next;

				// Delete this one
				iComps_delete(comp, true);

				// Move to the next one
				comp = compNext;
			}

			// Reset the pointer
			*firstComp = NULL;
		}
	}




//////////
//
// Called to delete the indicated comp
//
//////
	void iComps_delete(SComp* comp, bool tlDeleteSelf)
	{
		// If there is a bitmap cache, delete it
		if (comp->bc)
			iBmp_deleteCache(&comp->bc);

		// Delete this node
		iLl_deleteNode((SLL*)comp, tlDeleteSelf);
	}




//////////
//
// Called to search the SAsciiCompSearcher format list of text item keywords.
//
// Note:  If the length column of the SAsciiCompSearcher entry is negative, it is a case-sensitive search.
//
// Returns:
//		The first component created (if any)
//
//////
	SComp* iComps_translateSourceLineTo(SAsciiCompSearcher* tsComps, SLine* line)
	{
		s32						lnI, lnMaxLength, lnStart, lnLength, lnLacsLength;
		SComp*					compFirst;
		SComp*					compLast;
		SComp*					comp;
		u8*						lcData;
		SAsciiCompSearcher*		lacs;


		// Make sure the environment's sane
		compFirst = NULL;
		if (tsComps && line)
		{
			// Scan starting at the beginning of the line
			lcData = line->sourceCode->data_u8;

			// Iterate through every byte identifying every component we can
			compLast	= line->compilerInfo->firstComp;
			lnMaxLength	= line->sourceCode_populatedLength;
			for (lnI = 0; lnI < lnMaxLength; )
			{
				// Search through the tsComps list one by one
				for (	lacs = tsComps;
						lacs->length != 0;
						lacs++)
				{
					// Find out our signed status and get normalized length
//					llSigned		= (lacs->length < 0);
					lnLacsLength	= abs(lacs->length);

					// Process through this entry
					if ((!lacs->firstOnLine || lnI == 0 || iComps_areAllPrecedingCompsWhitespaces(compLast)) && lnLacsLength <= lnMaxLength - lnI)
					{
						// There is enough room for this component to be examined
						// See if it matches
						if (iTranslateToCompsTest(lacs->keyword_u8, lcData + lnI, lacs->length) == 0)
						{
							// It matches
							// mark its current condition
							lnStart		= lnI;
							lnLength	= lnLacsLength;
							// See if it's allowed to repeat
							if (lacs->repeats)
							{
								while (	lnStart + lnLength + lnLacsLength <= lnMaxLength
										&& iTranslateToCompsTest(lacs->keyword_u8, lcData + lnStart + lnLength, lacs->length) == 0)
								{
									// We found another repeated entry
									lnLength += lnLacsLength;
								}
								// When we get here, every repeated entry has been found (if any)
							}
							// When we get here, we have the starting point and the full length (including any repeats)


							//////////
							// Allocate this entry
							///////
								comp = (SComp*)iLl_appendNewNode((SLL**)&line->compilerInfo->firstComp, (SLL*)compLast, NULL, (SLL*)compLast, iGetNextUid(), sizeof(SComp));


							//////////
							// Populate the component with specified information
							//////
								//
								//////
									if (comp)
									{
										// Update the back links
										if (compLast)
											compLast->ll.next = (SLL*)comp;			// Previous one points to this one

										// This one points back to previous one
										comp->ll.prev		= (SLL*)compLast;

										// Update the component's information
										comp->line			= line;
										comp->start			= lnStart;
										comp->length		= lnLength;
										comp->iCode			= lacs->iCode;
										comp->iCat			= lacs->iCat;
										comp->color			= lacs->syntaxHighlightColor;
										comp->useBoldFont	= lacs->useBoldFont;

										// Update our first component (if it's not updated already)
										if (!compFirst)
											compFirst = comp;

										// All done
									}

									// Make sure we're setup for the next go-round
									compLast = comp;
								//////
								//
							//////
							// END
							//////////


							//////////
							// Execute
							//////
								if (lacs->_onFind)
									lacs->onFind(lacs, comp);


							//////////
							// Move beyond this entry, and continue on search again afterward
							//////
								lnI += lnLength;
								break;		// leaves lnJ loop, continues with lnI loop
						}
					}
				}
				// When we get here, we've processed through everything here
				if (lacs->length == 0)
					lnI++;			// We didn't find anything at that character, continue on to the next
			}
			// When we get here, lnI has been updated to its new location,
			// and any indicated components have been added
		}
		// Return the count
		return(compFirst);
	}




//////////
//
// Called to search the already parsed SAsciiCompSearcher list of components, looking for
// combinations which relate to other component types.  The primary translations here are
// alpha/alphanumeric/numeric forms to other forms.
//
//////
	bool iComps_translateToOthers(SAsciiCompSearcher* tacsRoot, SLine* line)
	{
		bool					llResult;
		s32						lnTacsLength;
		SComp*					comp;
		SAsciiCompSearcher*		tacs;


		// Make sure the environment is sane
		llResult = false;
		if (tacsRoot && line)
		{
			// Grab our pointers into recognizable thingamajigs
			comp = line->compilerInfo->firstComp;
			while (comp)
			{
				// Iterate through this item to see if any match
				tacs = tacsRoot;
				for (/* tacs is initialize above */; tacs->length != 0; tacs++)
				{
					// Grab the normalized length
					lnTacsLength = abs(tacs->length);

					// We only test if they're the same length
					if (lnTacsLength == comp->length || (tacs->repeats && lnTacsLength <= comp->length))
					{
						// We only test if this item is not the first item on line, or if must be the first
						// item on the line, then this component must be the first component on the line.  Simple, yes? :-)
						if (!tacs->firstOnLine || !comp->ll.prev || iComps_areAllPrecedingCompsWhitespaces(comp))
						{
							// Physically conduct the exact comparison
							if (iComps_translateToOthers_testIfMatch(tacs->keyword_u8, comp->line->sourceCode->data_cu8 + comp->start, tacs->length) == 0)
							{
								// This is a match
								llResult			= true;
								
								// Convert it, translate it, whatever you want to call it, just make it be the new code, per the user's request, got it? :-)
								comp->iCode			= tacs->iCode;
								comp->iCat			= tacs->iCat;
								comp->color			= tacs->syntaxHighlightColor;
								comp->useBoldFont	= tacs->useBoldFont;


								//////////
								// Execute
								//////
									if (tacs->_onFind)
										tacs->onFind(tacs, comp);

								
								// All done with this component
								break;
							}
						}
					}
				}

				// Move to next component
				comp = (SComp*)comp->ll.next;
			}
		}
		
		// Indicate our status
		return(llResult);
	}




//////////
//
// If every component from here on back is a whitespace, this is then the first
// component on the line.
//
//////
	bool iComps_areAllPrecedingCompsWhitespaces(SComp* comp)
	{
		while (comp)
		{
			// If this isn't a whitespace, the test fails
			if (comp->iCode != _ICODE_WHITESPACE)
				return(false);

			// Move to previous component
			comp = (SComp*)comp->ll.prev;
		}
		// If we get here, true
		return(true);
	}




//////////
//
// Search the haystack for the needle, the haystack can be tupels, as in "_az" meaning
// (is it between "a" and "z" inclusive?)  To set this condition, use a length of 1,
// a leading "_" in tcHaystack, and two characters (one of which must NOT be NULL) after.
//
// Examples:
//		_az		= lower-case a to z inclusive
//		_AZ		= upper-case a to z inclusive
//		_09		= numeric 0 to 9 inclusive
//
// Note:  If length is negative, it is a signed compare.
//
// Returns:
//		0		= matches
//		!0		= does not tmach
//
//////
	s32 iComps_translateToOthers_testIfMatch(cu8* tcHaystack, cu8* tcNeedle, s32 tnLength)
	{
		u32		lnI;
		bool	llSigned;


		// Make sure our environment is sane
		if (tnLength != 0)
		{
			// See if we're a signed or unsigned compare
			if (tnLength < 0)
			{
				// Case sensitive compare
				tnLength	= -tnLength;
				llSigned	= true;

			} else {
				// Case insensitive compare
				llSigned = false;
			}

			// See if we're looking for a tuple, or a regular compare
			if (tcHaystack[0] == '_' && tnLength == 1)
			{
				// It's an explicit match of a range (this is ALWAYS subject to case as it is an explicit range)
				for (lnI = 1; tcHaystack[lnI] != 0 || tcHaystack[lnI + 1] != 0; lnI += 2)
				{
					//		within the range low			.........			up to the range high
					if (tcNeedle[0] >= tcHaystack[lnI]			&&		tcNeedle[0] <= tcHaystack[lnI + 1])
						return(0);		// It's a match, needle is in the range
				}
				// Not a match, will fall through to below

			} else {
				// Just a regular compare
				if (llSigned)	return(  memcmp(tcHaystack, tcNeedle, tnLength));
				else			return(_memicmp(tcHaystack, tcNeedle, tnLength));
			}
		}
		// If we get here, no match
		return(-1);
	}




//////////
//
// Search for the indicated record in the chain by using a user-defined callback on the pointer.
// Callback function should return true when found, false to continue sending other items back.
//
// Returns:
//		NULL if error
//		The associated pointer if found
//
//////
	void* vvm_SEChain_searchByCallback(SStartEnd* ptrSE, SStartEndCallback* cb)
	{
		u32 lnI;


		// Make sure the environment is sane
		if (ptrSE)
		{
			// Iterate through the master list until we find the associated entry
			for (lnI = 0; lnI < ptrSE->masterCount; lnI++)
			{
				// Ask the caller if this is it
				if (ptrSE->master[lnI] && ptrSE->master[lnI]->used)
				{
					// Store the pointer for the caller
					cb->ptr = ptrSE->master[lnI]->ptr;

					// Perform the call
					if (cb->funcBool(cb))
						return(ptrSE->master[lnI]->ptr);	// We've found our man
				}
			}
		}
		// If we get here, failure
		return(NULL);
	}




//////////
//
// Searches forward to find the indicated component by the indicated type.
//
// Returns:
//		The matching component
//		If NULL, the compLastScanned indicates the last component that was searched where it wasn't found
//
//////
	SComp* iComps_findNextBy_iCode(SComp* comp, s32 tniCode, SComp** compLastScanned)
	{
		// Initially indicate failure
		if (compLastScanned)
			*compLastScanned = comp;

		// Continue while the environment is sane
		while (comp)
		{
			// Store the component we're scanning
			if (compLastScanned)
				*compLastScanned = comp;

			// See if this is it
			if (comp->iCode == tniCode)
				break;		// It is, we're done

			// Move to the next component
			comp = (SComp*)comp->ll.next;
		}
		// When we get here, we either found it or not
		// Store our results
		return(comp);
	}




//////////
//
// Returns which component the cursor is currently on
//
//////
	SComp* iComps_activeComp_inSEM(SEM* sem)
	{
		SComp* comp;


		// Make sure our environment is sane
		if (sem && sem->isSourceCode && sem->line_cursor && sem->line_cursor->compilerInfo && sem->line_cursor->compilerInfo->firstComp)
		{
			// Begin at the beginning
			comp = sem->line_cursor->compilerInfo->firstComp;
			while (comp)
			{
				// Is this the active component?
				if (sem->columnEdit >= comp->start && sem->columnEdit <= comp->start + comp->length)
					return(comp);

				// Move to next component
				comp = (SComp*)comp->ll.next;
			}
		}
		
		// If we get here, invalid or not found
		return(NULL);
	}




//////////
//
// If this is something that has a mate, indicate the mate's direction (forward
// or backward in source code).
//
//////
	bool iComps_getMateDirection(SComp* comp, s32* tnMateDirection)
	{
		if (comp && tnMateDirection)
		{
			switch (comp->iCode)
			{
				case _ICODE_PARENTHESIS_LEFT:
					// Is (, so what is the direction to )?
					*tnMateDirection = 1;
					return(true);

				case _ICODE_PARENTHESIS_RIGHT:
					// Is ), so what is the direction to (?
					*tnMateDirection = -1;
					return(true);

				case _ICODE_BRACKET_LEFT:
					*tnMateDirection = 1;
					return(true);
				case _ICODE_BRACKET_RIGHT:
					*tnMateDirection = -1;
					return(true);

				case _ICODE_BRACE_LEFT:
					*tnMateDirection = 1;
					return(true);
				case _ICODE_BRACE_RIGHT:
					*tnMateDirection = -1;
					return(true);

				case _ICODE_SCAN:
					*tnMateDirection = 1;
					return(true);
				case _ICODE_ENDSCAN:
					*tnMateDirection = -1;
					return(true);

				case _ICODE_DOWHILE:
					*tnMateDirection = 1;
					return(true);
				case _ICODE_ENDDO:
					*tnMateDirection = -1;
					return(true);

				case _ICODE_IF:
					*tnMateDirection = 1;
					return(true);
				case _ICODE_ENDIF:
					*tnMateDirection = -1;
					return(true);

				case _ICODE_LIF:
					*tnMateDirection = 1;
					return(true);
				case _ICODE_LELSE:
					*tnMateDirection = -1;
					return(true);

				case _ICODE_FOR:
					*tnMateDirection = 1;
					return(true);
				case _ICODE_ENDFOR:
					*tnMateDirection = -1;
					return(true);

				case _ICODE_DOCASE:
					*tnMateDirection = 1;
					return(true);
				case _ICODE_ENDCASE:
					*tnMateDirection = -1;
					return(true);

				case _ICODE_ADHOC:
					*tnMateDirection = 1;
					return(true);
				case _ICODE_ENDADHOC:
					*tnMateDirection = -1;
					return(true);

				case _ICODE_FUNCTION:
					*tnMateDirection = 1;
					return(true);
				case _ICODE_ENDFUNCTION:
					*tnMateDirection = -1;
					return(true);

				case _ICODE_PROCEDURE:
					*tnMateDirection = 1;
					return(true);
				case _ICODE_ENDPROCEDURE:
					*tnMateDirection = -1;
					return(true);
			}
		}

		// If we get here, no mate
		*tnMateDirection = 0;
		return(false);
	}




//////////
//
// Called to search the comp and forward for a parenthesis, bracket, or brace, and then to
// search the appropriate direction and find the matching one, and return those components.
//
//////
	bool iComps_findClosest_parensBracketsBraces(SComp* compRelative, SComp* compStart, SComp** compPBBLeft, SComp** compPBBRight)
	{
		s32		lnDirection, lniCodeNeedle, lniCodeNeedleMate, lnLevel;


		// Make sure our environment is sane
		if (compStart && compPBBLeft && compPBBRight)
		{
			// Reset our receivers
			*compPBBLeft	= NULL;
			*compPBBRight	= NULL;

			// Are we already on a target?
			if (compStart->iCode == _ICODE_PARENTHESIS_LEFT)
			{
				// We're on (
				lnDirection			= 1;
				*compPBBLeft		= compStart;
				lniCodeNeedle		= _ICODE_PARENTHESIS_RIGHT;
				lniCodeNeedleMate	= _ICODE_PARENTHESIS_LEFT;

			} else if (compStart->iCode == _ICODE_PARENTHESIS_RIGHT) {
				// We're on )
				lnDirection			= -1;
				*compPBBRight		= compStart;
				lniCodeNeedle		= _ICODE_PARENTHESIS_LEFT;
				lniCodeNeedleMate	= _ICODE_PARENTHESIS_RIGHT;

			} else if (compStart->iCode == _ICODE_BRACKET_LEFT) {
				// We're on [
				lnDirection			= 1;
				*compPBBLeft		= compStart;
				lniCodeNeedle		= _ICODE_BRACKET_RIGHT;
				lniCodeNeedleMate	= _ICODE_BRACKET_LEFT;

			} else if (compStart->iCode == _ICODE_BRACKET_RIGHT) {
				// We're on ]
				lnDirection			= -1;
				*compPBBRight		= compStart;
				lniCodeNeedle		= _ICODE_BRACKET_LEFT;
				lniCodeNeedleMate	= _ICODE_BRACKET_RIGHT;

			} else if (compStart->iCode == _ICODE_BRACE_LEFT) {
				// We're on {
				lnDirection			= 1;
				*compPBBLeft		= compStart;
				lniCodeNeedle		= _ICODE_BRACE_RIGHT;
				lniCodeNeedleMate	= _ICODE_BRACE_LEFT;

			} else if (compStart->iCode == _ICODE_BRACE_RIGHT) {
				// We're on }
				lnDirection			= -1;
				*compPBBRight		= compStart;
				lniCodeNeedle		= _ICODE_BRACE_LEFT;
				lniCodeNeedleMate	= _ICODE_BRACE_RIGHT;

			} else {
				// We need to search forward to find the closest one
				do
				{
					// Move to next comp
					compStart = (SComp*)compStart->ll.next;

					// Is this a target?
					if (compStart)
					{
						switch (compStart->iCode)
						{
							case _ICODE_PARENTHESIS_RIGHT:
							case _ICODE_BRACKET_RIGHT:
							case _ICODE_BRACE_RIGHT:
								if (!iComps_findClosest_parensBracketsBraces(compRelative, compStart, compPBBLeft, compPBBRight))
									return(false);

								// If the left component begins before our reference component we're good, otherwise we're still looking
								if ((*compPBBLeft)->start < compRelative->start)
									return(true);

								// If we get here, still looking
								break;
						}
					}

				} while (compStart);

				// If we get here, no find
				return(false);
			}

			// When we get here we are processing for the indicated form
			lnLevel = 0;
			do {
				// Move to next comp
				if (lnDirection == -1)			compStart = (SComp*)compStart->ll.prev;
				else							compStart = (SComp*)compStart->ll.next;

				// Is this our match?
				if (compStart)
				{
					if (compStart->iCode == lniCodeNeedle)
					{
						if (lnLevel == 0)
						{
							// We're there, note our findings
							if (lnDirection == -1)		*compPBBLeft	= compStart;
							else						*compPBBRight	= compStart;

							// Report success
							return(true);
						}

						// Going deeper, decrease our level
						--lnLevel;

					} else if (compStart->iCode == lniCodeNeedleMate) {
						// It's the mate of what we're searching for, increase our level another level deep for nesting, going shallow
						++lnLevel;
					}
				}

			} while (compStart);

			// When we get here, no find
			return(false);
		}
		// If we get here, invalid
		return(false);
	}




//////////
//
// Called to see if a component is a parenthesis, bracket, or brace
//
//////
	bool iComps_isParensBracketsBraces(SComp* comp)
	{
		// Make sure our environment is sane
		if (comp)
		{
			switch (comp->iCode)
			{
				case _ICODE_PARENTHESIS_LEFT:
				case _ICODE_PARENTHESIS_RIGHT:
				case _ICODE_BRACKET_LEFT:
				case _ICODE_BRACKET_RIGHT:
				case _ICODE_BRACE_LEFT:
				case _ICODE_BRACE_RIGHT:
					return(true);
			}
			// If we get here, no match
		}

		// If we get here, invalid
		return(false);
	}




//////////
//
// Is the reference the mate of iCodeMate
//
//////
	bool iComps_isMateOf(SComp* compTest, s32 tniCodeMate)
	{
		switch (tniCodeMate)
		{
			case _ICODE_PARENTHESIS_LEFT:
				return(compTest->iCode == _ICODE_PARENTHESIS_RIGHT);

			case _ICODE_PARENTHESIS_RIGHT:
				return(compTest->iCode == _ICODE_PARENTHESIS_LEFT);

			case _ICODE_BRACKET_LEFT:
				return(compTest->iCode == _ICODE_BRACKET_RIGHT);

			case _ICODE_BRACKET_RIGHT:
				return(compTest->iCode == _ICODE_BRACKET_LEFT);

			case _ICODE_BRACE_LEFT:
				return(compTest->iCode == _ICODE_BRACE_RIGHT);

			case _ICODE_BRACE_RIGHT:
				return(compTest->iCode == _ICODE_BRACE_LEFT);

			case _ICODE_ADHOC:
				return(compTest->iCode == _ICODE_ENDADHOC);

			case _ICODE_ENDADHOC:
				return(compTest->iCode == _ICODE_ADHOC);

			case _ICODE_IF:
				return(compTest->iCode == _ICODE_ENDIF);

			case _ICODE_ENDIF:
				return(compTest->iCode == _ICODE_IF);

			case _ICODE_LIF:
				return(compTest->iCode == _ICODE_LELSE);

			case _ICODE_LELSE:
				return(compTest->iCode == _ICODE_LIF);

			case _ICODE_FOR:
				return(compTest->iCode == _ICODE_ENDFOR);

			case _ICODE_ENDFOR:
				return(compTest->iCode == _ICODE_FOR);

			case _ICODE_SCAN:
				return(compTest->iCode == _ICODE_ENDSCAN);

			case _ICODE_ENDSCAN:
				return(compTest->iCode == _ICODE_SCAN);

			case _ICODE_ENDDO:
				return(compTest->iCode == _ICODE_DOWHILE);

			case _ICODE_DOWHILE:
				return(compTest->iCode == _ICODE_ENDDO);
		}
		// If we get here, unknown
		return(false);
	}




//////////
//
// Searches for the next component that is not of type tniIcode, including itself
//
//////
	SComp* iComps_skipPast_iCode(SComp* comp, s32 tniCode)
	{
		while (comp && comp->iCode == tniCode)
		{
			// Move to next component
			comp = (SComp*)comp->ll.next;
		}
		// When we get here, we're sitting on either no valid component, or the one which does not match the specified type
		return(comp);
	}




//////////
//
// Searches beyond this component until we find the indicated component
//
//////
	SComp* iComps_skipTo_iCode(SComp* comp, s32 tniCode)
	{
		// Skip to next comp
		comp = (SComp*)comp->ll.next;

		// Repeat until we find our match
		while (comp && comp->iCode != tniCode)
		{
			// Move to next component
			comp = (SComp*)comp->ll.next;
		}

		// When we get here, we're sitting on the iCode, or we've exhausted our comps and it's NULL
		return(comp);
	}




//////////
//
// Returns the Nth component beyond the current one
//
//////
	SComp* iComps_getNth(SComp* comp, s32 tnCount)
	{
		s32 lnI;


		// Iterate until we find it
		for (lnI = 0; comp && lnI < tnCount; lnI++)
			comp = (SComp*)comp->ll.next;

		// Indicate success or failure
		return(comp);
	}




//////////
//
// Called to combine two components into one.  If tnNewICode is > 0 then the
// iCode is updated as well.
//
//////
	u32 iComps_combineN(SComp* comp, u32 tnCount, s32 tnNewICode, s32 tnNewICat, SBgra* newColor)
	{
		u32		lnCount;
		SComp*	compNext;


		// Make sure our environment is sane
		if (comp)
		{
			//////////
			// Combine the next N items
			//////
				for (lnCount = 1; lnCount < tnCount; lnCount++)
				{
					// Grab the next component
					compNext = (SComp*)comp->ll.next;

					// Combine it into this one
					if (compNext)
					{
						// Add in the length of the next component, plus any spaces between them
						comp->length	+= (compNext->length + iiComps_get_charactersBetween(comp, compNext));
						comp->nbspCount	+= compNext->nbspCount;

						// Delete the next component
						iLl_deleteNode((SLL*)compNext, true);

					} else {
						// We're done, perhaps prematurely, but there are no more components
						break;
					}
				}


			//////////
			// Mark it as the new iCode
			//////
				if (tnNewICode > 0)
				{
					comp->iCode = tnNewICode;
					comp->iCat	= tnNewICat;
					comp->color	= newColor;
				}


			//////////
			// Indicate how many we merged
			//////
				return(lnCount - 1);

		} else {
			// Indicate failure
			return(0);
		}
	}




//////////
//
// Called to combine all immediately adjacent components into a single one.
// This is typically done to aggegate things that should be something like
// a filename, such as [c][:][\][some][\][dir][\][file][.][txt], into one
// component of [c:\some\dir\file.txt].
//
//////
	u32 iComps_combineAdjacent(SComp* compLeftmost, s32 tniCode, s32 tniCat, SBgra* tnColor)
	{
		u32 lnCombined;


		// Make sure the environment is sane
		lnCombined = 0;
		if (compLeftmost)
		{
			// Repeat so long as there is a component to the right
			for ( ; compLeftmost->ll.next; lnCombined++)
			{
				// And continue so long as they are immediately adjacent
				if (iiComps_get_charactersBetween(compLeftmost, (SComp*)compLeftmost->ll.next) != 0)
					return(lnCombined);	// All done

				// Combine these two...
				iComps_combineN(compLeftmost, 2, tniCode, tniCat, tnColor);
				// ...and continue on to the next component after
			}
		}

		// Indicate how many were combined
		return(lnCombined);
	}




//////////
//
// Called to combine adjacent combinations of underscore, alpha, numeric, or alphanumeric,
// which begin with an underscore, alpha, or alphanumeric, into one component that is then
// branded as alphanumeric.
//
//////
	u32 iComps_combineAdjacentAlphanumeric(SLine* line)
	{
		u32		lnCombined;
		SComp*	comp;
		SComp*	compNext;


		// Make sure our environment is sane
		lnCombined = 0;
		if (line && line->compilerInfo)
		{
			// Begin at the beginning and check across all components
			comp = line->compilerInfo->firstComp;
			while (comp)
			{
				// Grab the next component
				compNext = (SComp*)comp->ll.next;
				if (compNext)
				{
					// Is this an underscore, alpha, or alphanumeric?
					if (comp->iCode == _ICODE_UNDERSCORE || comp->iCode == _ICODE_ALPHA || comp->iCode == _ICODE_ALPHANUMERIC)
					{
						// Combine so long as the following are immediately adjacent, and are one of underscore, alpha, numeric, alphanumeric
						while (	(compNext = (SComp*)comp->ll.next)
								&& iiComps_get_charactersBetween(comp, compNext) == 0
								&& (	compNext->iCode == _ICODE_UNDERSCORE
									||	compNext->iCode == _ICODE_ALPHA
									||	compNext->iCode == _ICODE_NUMERIC
									||	compNext->iCode == _ICODE_ALPHANUMERIC
								)
							)
						{
							// Combine this comp and the next one into one
							iComps_combineN(comp, 2, _ICODE_ALPHANUMERIC, comp->iCat, comp->color);
							++lnCombined;
						}
					}
				}


				// Move to the next component
				comp = (SComp*)comp->ll.next;
			}
		}

		// Indicate how many we combined
		return(lnCombined);
	}




//////////
//
// Called to combine numeric combinations, such as [999][.][99] into [999.99] as
// a single numeric.  In addition, if a leading plus or negative is immediately
// adjacent, it is included as well.
//
//////
	u32 iComps_combineAdjacentNumeric(SLine* line)
	{
		u32		lnCombined;
		SComp*	comp;
		SComp*	compNext1;
		SComp*	compNext2;
		SComp*	compNext3;


		// Make sure our environment is sane
		lnCombined = 0;
		if (line && line->compilerInfo)
		{
			// Begin at the beginning and check across all components
			comp = line->compilerInfo->firstComp;
			while (comp)
			{
				// Grab the next component
				if ((compNext1 = (SComp*)comp->ll.next) && iiComps_get_charactersBetween(comp, compNext1) == 0)
				{
					// Is this an underscore, alpha, or alphanumeric?
					if ((comp->iCode == _ICODE_PLUS || comp->iCode == _ICODE_HYPHEN) && compNext1->iCode == _ICODE_NUMERIC)
					{
						// We have +-999
						if ((compNext2 = (SComp*)compNext1->ll.next) && compNext2->iCode == _ICODE_DOT)
						{
							// We have +-999.
							if ((compNext3 = (SComp*)compNext2->ll.next) && compNext3->iCode == _ICODE_NUMERIC)
							{
								// We have +-999.99
								iComps_combineN(comp, 4, _ICODE_NUMERIC, comp->iCat, comp->color);
								lnCombined += 3;

							} else {
								// Combine the +- with the 999 and the .
								iComps_combineN(comp, 3, _ICODE_NUMERIC, comp->iCat, comp->color);
								lnCombined += 2;
							}

						} else {
							// Combine the +- with the 999 into one
							iComps_combineN(comp, 2, _ICODE_NUMERIC, comp->iCat, comp->color);
							++lnCombined;
						}

					} else if (comp->iCode == _ICODE_NUMERIC) {
						// We have 999
						if ((compNext2 = (SComp*)compNext1->ll.next) && compNext2->iCode == _ICODE_DOT)
						{
							// We have 999.
							if ((compNext3 = (SComp*)compNext2->ll.next) && compNext3->iCode == _ICODE_NUMERIC)
							{
								// We have 999.99
								iComps_combineN(comp, 3, _ICODE_NUMERIC, comp->iCat, comp->color);
								lnCombined += 2;

							} else {
								// We just have 999.
								iComps_combineN(comp, 2, _ICODE_NUMERIC, comp->iCat, comp->color);
								++lnCombined;
							}
						}
					}
				}


				// Move to the next component
				comp = (SComp*)comp->ll.next;
			}
		}

		// Indicate how many we combined
		return(lnCombined);
	}




//////////
//
// Called to combine things like [.][t][.] into [.t.], [xyz][.][abc] into [xyz.abc]
//
//////
	u32 iComps_combineAdjacentDotForms(SLine* line)
	{
		u32		lnCombined;
		u8		c;
		bool	llProcessed;
		SComp*	compThis;
		SComp*	compFirst;
		SComp*	compSecond;
		SComp*	compThird;
		SComp*	compFourth;


		// Make sure our environment is sane
		lnCombined = 0;
		if (line && line->compilerInfo)
		{
			// Begin at the beginning and check across all components
			compThis = line->compilerInfo->firstComp;
			while (compThis)
			{
				// Grab the thing after
				compFirst = (SComp*)compThis->ll.next;
				if (!compFirst)
					break;

				// Grab any components hereafter
				compSecond	= NULL;
				compThird	= NULL;
				compFourth	= NULL;
				if ((compSecond = (SComp*)compFirst->ll.next) && (compThird = (SComp*)compSecond->ll.next) && (compFourth = (SComp*)compThird->ll.next))
				{
					// Placeholder for the early-out if statement above
				}

				// Dots begin the things we're searching for
				llProcessed = false;
				if (compFirst->iCode == _ICODE_DOT)
				{
					// Grab the next two components, they must all be adjacent, and the third one must also be a dot
					if (	compSecond	&&	compThird
						&&	compThird->iCode == _ICODE_DOT
						&&	iiComps_get_charactersBetween(compFirst, compSecond) == 0
						&&	iiComps_get_charactersBetween(compSecond, compThird) == 0)
					{
						// What is the component in the middle?
						if (compSecond->iCode == _ICODE_ALPHA)
						{
							switch (compSecond->length)
							{
								case 1:
									// Could be .t., .f., .o., .p., .x., .y., .z.
									c = compSecond->line->sourceCode->data[compSecond->start];

									// Which one is it?
										 if (c == 't' || c == 'T')				{ iComps_combineN(compFirst, 3, _ICODE_TRUE,			compFirst->iCat, compFirst->color);		lnCombined += 3; }
									else if (c == 'f' || c == 'F')				{ iComps_combineN(compFirst, 3, _ICODE_FALSE,			compFirst->iCat, compFirst->color);		lnCombined += 3; }
									else if (c == 'o' || c == 'O')				{ iComps_combineN(compFirst, 3, _ICODE_OTHER,			compFirst->iCat, compFirst->color);		lnCombined += 3; }
									else if (c == 'p' || c == 'P')				{ iComps_combineN(compFirst, 3, _ICODE_PARTIAL,			compFirst->iCat, compFirst->color);		lnCombined += 3; }
									else if (c == 'x' || c == 'X')				{ iComps_combineN(compFirst, 3, _ICODE_EXTRA,			compFirst->iCat, compFirst->color);		lnCombined += 3; }
									else if (c == 'y' || c == 'Y')				{ iComps_combineN(compFirst, 3, _ICODE_YET_ANOTHER,		compFirst->iCat, compFirst->color);		lnCombined += 3; }
									else if (c == 'z' || c == 'Z')				{ iComps_combineN(compFirst, 3, _ICODE_ZATS_ALL_FOLKS,	compFirst->iCat, compFirst->color);		lnCombined += 3; }
									llProcessed = true;
									break;

								case 2:
									// Could be .or.
									if (_memicmp(compSecond->line->sourceCode->data, "or", 2) == 0)
									{
										iComps_combineN(compFirst, 3, _ICODE_OR, compFirst->iCat, compFirst->color);
										lnCombined += 3;
									}
									llProcessed = true;
									break;

								case 3:
									// Could be .and., .not.
									if (_memicmp(compSecond->line->sourceCode->data, "and", 3) == 0)
									{
										// AND
										iComps_combineN(compFirst, 3, _ICODE_AND, compFirst->iCat, compFirst->color);
										lnCombined += 3;

									} else if (_memicmp(compSecond->line->sourceCode->data, "not", 3) == 0) {
										// NOT
										iComps_combineN(compFirst, 3, _ICODE_NOT, compFirst->iCat, compFirst->color);
										lnCombined += 3;
									}
									llProcessed = true;
									break;

								case 4:
									// Could be .null.
									if (_memicmp(compSecond->line->sourceCode->data, "null", 4) == 0)
									{
										// NULL
										iComps_combineN(compFirst, 3, _ICODE_NULL, compFirst->iCat, compFirst->color);
										lnCombined += 3;
									}
									llProcessed = true;
									break;
							}
						}

					}

					if (llProcessed)
					{
						// It was processed above
						// Move to the next component
						compThis = (SComp*)compThis->ll.next;

					} else if (compThird && iiComps_get_charactersBetween(compFirst, compThird) == 0 && (compThird->iCode == _ICODE_ALPHA || compThird->iCode == _ICODE_ALPHANUMERIC)) {
						// It's a dot variable of some kind
						iComps_combineN(compThis, 3, _ICODE_DOT_VARIABLE, _ICAT_DOT_VARIABLE, &colorSynHi_dotVariable);

					} else {
						// Nothing, skip to the next component
						compThis = (SComp*)compThis->ll.next;
					}

				} else {
					// It's not a dot command, so skip to the next one
					compThis = (SComp*)compThis->ll.next;
				}
			}
		}

		// Indicate how many we combined
		return(lnCombined);
	}




//////////
//
// Called to combine everything between two components
//
// Source:		u8 name[] = "foo"
// Example:		[u8][whitespace][name][left bracket][right bracket][whitespace][equal][whitespace][double quote][foo][double quote]
// Search:		[double quote], replace with [double quoted text]
// After:		[u8][whitespace][name][left bracket][right bracket][whitespace][equal][whitespace][double quote text]
//
//////
	u32 iComps_combineAllBetween(SLine* line, s32 tniCodeNeedle, s32 tniCodeCombined, SBgra* syntaxHighlightColor)
	{
		u32		lnCount;
		SComp*	compNext;
		SComp*	comp;
		SComp*	compSearcher;


		// Make sure our environment is sane
		lnCount = 0;
		if (line && line->compilerInfo && line->compilerInfo->firstComp)
		{
			// Grab the first component
			comp = line->compilerInfo->firstComp;

			// Continue until we get ... to ... the ... end ... (imagine you were reading that like in a baseball stadium with lots of loud echoes)
			while (comp)
			{
				// Grab the next component sequentially
				compNext = (SComp*)comp->ll.next;

				// Make sure there's something to do
				if (!compNext)
					return(lnCount);	// We're done

				// Is this our intended?
				if (comp->iCode == tniCodeNeedle)
				{
					// Search forward to see if there is a matching entry
					compSearcher = compNext;
					while (compSearcher)
					{
						if (compSearcher->iCode == tniCodeNeedle)
						{
							// This is the match, combine everything between
							comp->length	= (compSearcher->start + compSearcher->length) - comp->start;
							comp->iCode		= tniCodeCombined;
							comp->color		= syntaxHighlightColor;
							comp->nbspCount	+= compSearcher->nbspCount;

							// Iterate and merge in
							while (compNext)
							{
								// Increase our count
								++lnCount;

								// Delete this one (as it was technically merged above with the comp->length = line)
								iLl_deleteNode((SLL*)compNext, true);

								// See if we're done
								if (compNext == compSearcher)
									break;		// This was the last one, we're done

								// Move to the next component (which is the comp->ll.next component again, because we just migrated the previous compNext
								compNext = (SComp*)comp->ll.next;
							}
							// When we get here, everything's migrated

							// Grab the new next, which is the one after the matched entry
							compNext = (SComp*)comp->ll.next;

							// Continue looking for more combinations on this line
							break;
						}

						// Move to the next component
						compSearcher = (SComp*)compSearcher->ll.next;
					}
				}
				// Move to the next component
				comp = compNext;
			}
			// When we get here, we're good
		}
		// Indicate the success rate at which we operated hitherto
		return(lnCount);
	}




//////////
//
// Called to search for unmatched codes, a left and right, and combines everything between
//
//////
	u32 iComps_combineAllBetween2(SLine* line, s32 tniCodeNeedleLeft, s32 tniCodeNeedleRight, s32 tniCodeCombined, s32 tniCat, SBgra* syntaxHighlightColor, bool tlUseBoldFont)
	{
		u32		lnCount;
		SComp*	compNext;
		SComp*	comp;
		SComp*	compSearcher;


		// Make sure our environment is sane
		lnCount = 0;
		if (line && line->compilerInfo && line->compilerInfo->firstComp)
		{
			// Grab the first component
			comp = line->compilerInfo->firstComp;

			// Continue until we get ... to ... the ... end ... (imagine you were reading that like in a baseball stadium with lots of loud echoes)
			while (comp)
			{
				// Grab the next component sequentially
				compNext = (SComp*)comp->ll.next;

				// Make sure there's something to do
				if (!compNext)
					return(lnCount);	// We're done

				// Is this our intended?
				if (comp->iCode == tniCodeNeedleLeft)
				{
					// Search forward to see if there is a matching entry
					compSearcher = compNext;
					while (compSearcher)
					{
						if (compSearcher->iCode == tniCodeNeedleRight)
						{
							// This is the match, combine everything between
							comp->length		= (compSearcher->start + compSearcher->length) - comp->start;
							comp->iCode			= tniCodeCombined;
							comp->iCat			= tniCat;
							comp->color			= syntaxHighlightColor;
							comp->useBoldFont	= tlUseBoldFont;

							// Iterate and merge in
							while (compNext)
							{
								// Increase our count
								++lnCount;

								// Add in our count
								comp->nbspCount += compNext->nbspCount;

								// Delete this one (as it was technically merged above with the comp->length = line)
								iLl_deleteNode((SLL*)compNext, true);

								// See if we're done
								if (compNext == compSearcher)
									break;		// This was the last one, we're done

								// Move to the next component (which is the comp->ll.next component again, because we just migrated the previous compNext
								compNext = (SComp*)comp->ll.next;
							}
							// When we get here, everything's migrated

							// Grab the new next, which is the one after the matched entry
							compNext = (SComp*)comp->ll.next;

							// Continue looking for more combinations on this line
							break;
						}

						// Move to the next component
						compSearcher = (SComp*)compSearcher->ll.next;
					}
				}
				// Move to the next component
				comp = compNext;
			}
			// When we get here, we're good
		}
		// Indicate the success rate at which we operated hitherto
		return(lnCount);
	}




//////////
//
// Called to combine everything after the indicated component into that one component.
//
//////
	u32 iComps_combineAllAfter(SLine* line, s32 tniCodeNeedle)
	{
		u32		lnCombined;
		SComp*	comp;


		// Make sure our environment is sane
		lnCombined = 0;
		if (line && line->compilerInfo && line->compilerInfo->firstComp)
		{
			// Grab the first component
			comp = (SComp*)line->compilerInfo->firstComp;

			// Iterate forward through all components
			while (comp)
			{
				// Is this our intended?
				if (comp->iCode == tniCodeNeedle)
				{
					// Combine from here on out
					while (comp->ll.next)
					{
						// Combine
						iComps_combineN(comp, 2, tniCodeNeedle, comp->iCat, comp->color);

						// Indicate the number combined
						++lnCombined;
					}
				}

				// Move to the next component
				comp = (SComp*)comp->ll.next;
			}
			// When we get here, we're good
		}
		// Indicate the success rate at which we operated hitherto
		return(lnCombined);
	}




//////////
//
// Called to delete everything after the indicated component
//
//////
	u32 iComps_deleteAllAfter(SLine* line, s32 tniCodeNeedle)
	{
		u32		lnDeleted;
		SComp*	comp;
		SComp**	compLast;


		// Make sure our environment is sane
		lnDeleted = 0;
		if (line && line->compilerInfo && line->compilerInfo->firstComp)
		{
			// Grab the first component
			comp		= (SComp*)line->compilerInfo->firstComp;
			compLast	= (SComp**)&line->compilerInfo->firstComp;

			// Iterate forward through all components
			while (comp)
			{
				// Is this our intended?
				if (comp->iCode == tniCodeNeedle)
				{
					// Combine from here on out
					while (comp)
					{
						// Indicate the number combined
						++lnDeleted;

						// Move to the next component
						comp = (SComp*)comp->ll.next;
					}

					// Delete from here on out
					iComps_deleteAll_byFirstComp(compLast);
					break;
				}

				// Move to the next component
				compLast	= (SComp**)&comp->ll.next;
				comp		= (SComp*)comp->ll.next;
			}
			// When we get here, we're good
		}
		// Indicate the success rate at which we operated hitherto
		return(lnDeleted);
	}




//////////
//
// Called to remove leading whitespaces
// Note:  This function can be called at any time.
//
//////
	u32 iComps_removeLeadingWhitespaces(SLine* line)
	{
		u32		lnRemoved;
		SComp*	comp;


		// Make sure our environment is sane
		lnRemoved = 0;
		if (line && line->compilerInfo)
		{
			// Iterate through all looking for _ICODE_COMMENT_START
			comp = line->compilerInfo->firstComp;
			while (comp && comp->iCode == _ICODE_WHITESPACE)
			{
				// Migrate this whitespace from firstComp to firstWhitespace
				comp = (SComp*)iLl_migrateNodeToOther((SLL**)&line->compilerInfo->firstComp, (SLL**)&line->compilerInfo->firstWhitespace, (SLL*)comp, true);
				++lnRemoved;

				// comp is now pointing to what would've been comp->ll.next
				line->compilerInfo->firstComp = comp;
			}
		}

		// Indicate how many we removed
		return(lnRemoved);
	}




//////////
//
// Called to remove whitespaces.
// Note:  By the time this function is called, natural groupings should've already been
//        processed, such that all quoted text items are already combined into a single icode.
//
//////
	u32 iComps_removeWhitespaces(SLine* line)
	{
		u32		lnRemoved;
		SComp*	comp;


		// Make sure our environment is sane
		lnRemoved = 0;
		if (line && line->compilerInfo)
		{
			// Iterate through all looking for _ICODE_COMMENT_START
			comp = line->compilerInfo->firstComp;
			while (comp)
			{
				//////////
				// Is this a whitespace?
				//////
					while (comp && comp->iCode == _ICODE_WHITESPACE)
					{
						// Is it at the head of the class?
						if (line->compilerInfo->firstComp == comp)
							line->compilerInfo->firstComp = (SComp*)comp->ll.next;

						// Migrate this whitespace to the whitespace area
						comp = (SComp*)iLl_migrateNodeToOther((SLL**)&line->compilerInfo->firstComp, (SLL**)&line->compilerInfo->firstWhitespace, (SLL*)comp, true);

						// Increase our counter
						++lnRemoved;
					}


				//////////
				// Continue on to next component
				//////
					if (comp)
						comp = (SComp*)comp->ll.next;
			}
		}

		// Indicate how many we removed
		return(lnRemoved);
	}




//////////
//
// Called to remove any /* comments */ from the current chain of comps.
//
//////
	void iComps_removeStartEndComments(SLine* line)
	{
		SComp*	comp;
		SComp*	compNext;


		// Make sure our environment is sane
		if (line && line->compilerInfo)
		{
			// Iterate through all looking for _ICODE_COMMENT_START
			comp = line->compilerInfo->firstComp;
			while (comp)
			{
				//////////
				// Is this a start?
				//////
					if (comp->iCode == _ICODE_COMMENT_START)
					{
						// Delete everything forward until we reach _ICODE_COMMENT_END or the last comp
						while ((compNext = (SComp*)comp->ll.next) && compNext->iCode != _ICODE_COMMENT_END)
							iComps_combineN(comp, 2, comp->iCode, comp->iCat, comp->color);

						// When we get here, we're sitting on the _ICODE_COMMENT_END
						if ((compNext = (SComp*)comp->ll.next) && compNext->iCode == _ICODE_COMMENT_END)
							iComps_combineN(comp, 2, comp->iCode, comp->iCat, comp->color);
					}


				//////////
				// Continue on to next component
				//////
					if (comp)
						comp = (SComp*)comp->ll.next;
			}
		}
	}




//////////
//
// Called to combine casks
//
//////
	void iComps_combineCasks(SLine* line)
	{
		SComp* comp;


		// Make sure our environment is sane
		if (line && line->compilerInfo && line->compilerInfo->firstComp)
		{
			// See if there are any cask components on this line
			comp = line->compilerInfo->firstComp;
			while (comp)
			{
				// Is this a cask?
				if (comp->iCode >= _ICODE_CASK_SIDE_MINIMUM && comp->iCode <= _ICODE_CASK_SIDE_MAXIMUM)
				{
					// Try normal forms without parameters
					iComps_combineAllBetween2(line,		_ICODE_CASK_ROUND_OPEN,				_ICODE_CASK_ROUND_CLOSE,				_ICODE_CASK_ROUND,				_ICAT_CASK, (SBgra*)&blackColor, false);
					iComps_combineAllBetween2(line,		_ICODE_CASK_SQUARE_OPEN,			_ICODE_CASK_SQUARE_CLOSE,				_ICODE_CASK_SQUARE,				_ICAT_CASK, (SBgra*)&blackColor, false);
					iComps_combineAllBetween2(line,		_ICODE_CASK_TRIANGLE_OPEN,			_ICODE_CASK_TRIANGLE_CLOSE,				_ICODE_CASK_TRIANGLE,			_ICAT_CASK, (SBgra*)&blackColor, false);
					iComps_combineAllBetween2(line,		_ICODE_CASK_TILDE_OPEN,				_ICODE_CASK_TILDE_CLOSE,				_ICODE_CASK_TILDE,				_ICAT_CASK, (SBgra*)&blackColor, false);

					// Try normal forms with parameters
					iComps_combineAllBetween2(line,		_ICODE_CASK_ROUND_OPEN_PARAMS,		_ICODE_CASK_ROUND_CLOSE_PARAMS,			_ICODE_CASK_ROUND_PARAMS,		_ICAT_CASK, (SBgra*)&blackColor, false);
					iComps_combineAllBetween2(line,		_ICODE_CASK_SQUARE_OPEN_PARAMS,		_ICODE_CASK_SQUARE_CLOSE_PARAMS,		_ICODE_CASK_SQUARE_PARAMS,		_ICAT_CASK, (SBgra*)&blackColor, false);
					iComps_combineAllBetween2(line,		_ICODE_CASK_TRIANGLE_OPEN_PARAMS,	_ICODE_CASK_TRIANGLE_CLOSE_PARAMS,		_ICODE_CASK_TRIANGLE_PARAMS,	_ICAT_CASK, (SBgra*)&blackColor, false);
					iComps_combineAllBetween2(line,		_ICODE_CASK_TILDE_OPEN_PARAMS,		_ICODE_CASK_TILDE_CLOSE_PARAMS,			_ICODE_CASK_TILDE_PARAMS,		_ICAT_CASK, (SBgra*)&blackColor, false);

					// Done
					return;
				}

				// Move to next comp
				comp = (SComp*)comp->ll.next;
			}
		}
	}




//////////
//
// Fixes up common things found in VXB source code.
//
//////
	void iComps_fixupNaturalGroupings(SLine* line)
	{
		if (line && line->compilerInfo && line->compilerInfo->firstComp)
		{
			//////////
			// Fixup quotes, comments
			//////
				iComps_combineAllBetween(line, _ICODE_SINGLE_QUOTE,		_ICODE_SINGLE_QUOTED_TEXT,	&colorSynHi_quotedText);
				iComps_combineAllBetween(line, _ICODE_DOUBLE_QUOTE,		_ICODE_DOUBLE_QUOTED_TEXT,	&colorSynHi_quotedText);
				iComps_combineAllAfter(line, _ICODE_LINE_COMMENT);


			//////////
			// Search for combinations which are adjacent sequences beginning with an underscore or alpha,
			// which then alternate in some form of alpha, numeric, underscore, etc., and translate to
			// alphanumeric.  For numeric it looks for +-999.99 completely adjacent, and combines into one.
			//////
				iComps_combineAdjacentAlphanumeric(line);
				iComps_combineAdjacentNumeric(line);
				iComps_combineAdjacentDotForms(line);
		}
	}




//////////
//
// Returns the number of characters between two components.
//
//////
	s32 iiComps_get_charactersBetween(SComp* compLeft, SComp* compRight)
	{
		// Start of right component and end of left component
		return(compRight->start - (compLeft->start + compLeft->length));
	}




//////////
//
// Called to convert the value in this component to an s32 integer
//
//////
	s32 iComps_getAs_s32(SComp* comp)
	{
		s8 buffer[16];


		if (comp && comp->line && comp->line->sourceCode && comp->line->sourceCode->data_s8 && comp->line->sourceCode_populatedLength > 0)
		{
			// Copy to a buffer
			memset(buffer, 0, sizeof(buffer));
			memcpy(buffer, comp->line->sourceCode->data_s8 + comp->start, min(comp->length, (s32)sizeof(buffer) - 1));
			return(atoi(buffer));

		} else {
			// Component is not valid
			return(-1);
		}
	}




//////////
//
// Called to get the length of the contiguous components
//
//////
	s32 iComps_getContiguousLength(SComp* comp, s32 valid_iCodeArray[], s32 tnValid_iCodeArrayCount, s32* tnCount)
	{
		s32		lnCount, lnLength, lnThisSpacing;
		bool	llAtLeastOne, llIsValid;


		// Make sure our environment is sane
		lnCount		= 0;
		lnLength	= 0;
		if (comp)
		{
			//////////
			// Iterate so long as there are components after it
			//////
				lnThisSpacing	= -1;
				llIsValid		= true;
				llAtLeastOne	= false;
				while (comp->ll.next)
				{
					//////////
					// See if it's contiguously adjoined
					//////
						if ((lnThisSpacing = iiComps_get_charactersBetween(comp, (SComp*)comp->ll.next)) != 0)
							break;		// We're done


					//////////
					// Validate if need be
					//////
						if (tnValid_iCodeArrayCount > 0 && valid_iCodeArray)
						{
							// We do need to validate
							if (!iiComps_validate(comp, valid_iCodeArray, tnValid_iCodeArrayCount))
							{
								// If we get here, it did not pass validation
								llIsValid = false;
								break;
							}
						}


					//////////
					// Increase our length
					//////
						lnLength += comp->length;


					//////////
					// Raise our flag and increase our count
					//////
						llAtLeastOne = true;
						++lnCount;


					//////////
					// Move to next comp
					//////
						comp = (SComp*)comp->ll.next;
				}


			//////////
			// Do we need to add in the last component?
			//////
				if (!comp->ll.next && llAtLeastOne && llIsValid && lnThisSpacing == 0)
				{
					// Validate if need be
					if (tnValid_iCodeArrayCount > 0 && valid_iCodeArray)
					{
						// If it's valid, add it
						if (iiComps_validate(comp, valid_iCodeArray, tnValid_iCodeArrayCount))
						{
							lnLength += comp->length;	// It's valid
							++lnCount;
						}

					} else {
						// No validation, just add it in
						lnLength += comp->length;
						++lnCount;
					}
				}

		}

		// Store the count if need be
		if (tnCount)
			*tnCount = lnCount;

		// Indicate where we are
		return(lnLength);
	}




//////////
//
// Called to validate the indicated component against a valid array list
//
//////
	bool iiComps_validate(SComp* comp, s32 valid_iCodeArray[], s32 tnValid_iCodeArrayCount)
	{
		s32 lnI;


		// Iterate through the valid list
		for (lnI = 0; lnI < tnValid_iCodeArrayCount; lnI++)
		{
			// Does it match this one?
			if (comp->iCode == valid_iCodeArray[lnI])
				return(true);	// It matches
		}

		// If we get here, no match
		return(false);
	}




//////////
//
// Visualizes the components in text form
//
//////
	s8* iComps_visualize(SComp* comp, s32 tnCount, s8* outputBuffer, s32 tnBufferLength, bool tlUseDefaultCompSearcher, SAsciiCompSearcher* tsComps1, SAsciiCompSearcher* tsComps2)
	{
		s32						lnI, lnJ, lnLength, lnOffset;
		bool					llFound;
		SAsciiCompSearcher*		lacs;
		s8						accumBuffer[256];


		//////////
		// Iterate through the comps one-by-one
		//////
			if (comp && outputBuffer && tnBufferLength > 0 && (tlUseDefaultCompSearcher || tsComps1 || tsComps2))
			{
				// Reset the display buffer
				memset(outputBuffer, 0, tnBufferLength);

				// Iterate through the comps
				for (lnI = 0, lnOffset = 0; lnI < tnCount && comp && lnOffset < tnBufferLength; comp = (SComp*)comp->ll.next)
				{
					//////////
					// Lookup this comp
					//////
						for (lnJ = 0, llFound = false; lnJ < 3 && !llFound; lnJ++)
						{
							if (lnJ == 0 && tlUseDefaultCompSearcher)
							{
								// Search the standard complement
								lacs = &cgcFundamentalSymbols[0];

							} else if (lnJ == 1 && tsComps1) {
								// Search the primary components
								lacs = tsComps1;

							} else if (lnJ == 2 && tsComps2) {
								// Search the second custom components
								lacs = tsComps2;

							} else {
								// This one is not valid
								lacs = NULL;
							}


							//////////
							// Search for a match
							//////
								for ( ; lacs && lacs->iCode != 0 && lacs->length != 0; lacs++)
								{
									// Is this a match?
									if (comp->iCode == lacs->iCode && comp->iCat == lacs->iCat)
									{
										// This is a match, visualize it as:  [text]
										memset(accumBuffer, 0, sizeof(accumBuffer));
										sprintf(accumBuffer, "[%d:", comp->iCode);
										memcpy(accumBuffer+ strlen(accumBuffer), comp->line->sourceCode->data_s8 + comp->start, min(comp->length, (s32)sizeof(accumBuffer) - 20));
										sprintf(accumBuffer + strlen(accumBuffer), ":%u]", comp->length);

										// Copy to our output
										lnLength		= min(tnBufferLength - lnOffset, (s32)strlen(accumBuffer));
										memcpy(outputBuffer + lnOffset, accumBuffer, lnLength);
										lnOffset				+= lnLength;

										// All done
										llFound = true;
										break;
									}
								}

						}


						//////////
						// If it wasn't found, we need to visualize it like this:  [iCode:text:length], like [5:hi:2]
						//////
							if (!llFound)
							{
								// Visualize the raw text as an unknown form
								memset(accumBuffer, 0, sizeof(accumBuffer));
								sprintf(accumBuffer, "[%d:", comp->iCode);
								memcpy(accumBuffer+ strlen(accumBuffer), comp->line->sourceCode->data_s8 + comp->start, min(comp->length, (s32)sizeof(accumBuffer) - 20));
								sprintf(accumBuffer + strlen(accumBuffer), ":%u]", comp->length);

								// Copy to our output
								lnLength		= min(tnBufferLength - lnOffset, (s32)strlen(accumBuffer));
								memcpy(outputBuffer + lnOffset, accumBuffer, lnLength);
								lnOffset				+= lnLength;
							}

				}
			}


		//////////
		// Return the pointer
		//////
			return(outputBuffer);
	}




//////////
//
// Scans from the indicated location forward until finding CR/LF or any combination thereof,
// nothing whitespaces, content, and total line length (including cr/lf combinations at the end)
//
//////
	u32 iBreakoutAsciiTextDataIntoLines_ScanLine(s8* tcData, u32 tnMaxLength, u32* tnLength, u32* tnWhitespaces)
	{
		u32 lnLength, lnWhitespaces, lnCRLF_Length;


		// Make sure we have something to do
		lnLength		= 0;
		lnWhitespaces	= 0;
		lnCRLF_Length	= 0;
		if (tcData && tnMaxLength > 0)
		{
			// Skip past any whitespaces
			lnWhitespaces = iSkipWhitespaces(tcData, tnMaxLength);
			if (tnWhitespaces)
				*tnWhitespaces = lnWhitespaces;


			// Skip to the ending carriage return / line feed
			lnLength = iSkipToCarriageReturnLineFeed(tcData + lnWhitespaces, tnMaxLength - lnWhitespaces, &lnCRLF_Length);
			if (tnLength)
				*tnLength = lnLength;
		}
		// Return the total length
		return(lnWhitespaces + lnLength + lnCRLF_Length);
	}




//////////
//
// Searches the haystack for the indicated needle, and reports the position if found
//
// Returns:
//		true	- found, tnPosition is updated
//		false	- not found, tnPosition unchanged
//
//////
	bool iFindFirstOccurrenceOfAsciiCharacter(s8* tcHaystack, u32 tnHaystackLength, s8 tcNeedle, u32* tnPosition)
	{
		u32		lnI;
		bool	llFound;


		// Make sure our environment is sane
		llFound = false;
		if (tcHaystack && tnHaystackLength != 0)
		{
			// Repeat for the length of the string
			for (lnI = 0; lnI < tnHaystackLength; lnI++)
			{
				// See if this is the character we're after
				if (tcHaystack[lnI] == tcNeedle)
				{
					// We found it
					llFound = true;

					// Update caller's pointer if need be
					if (tnPosition)
						*tnPosition = lnI;

					// All done
					break;
				}
			}
			// When we get here, either found or not
		}
		// Indicate our found condition
		return(llFound);
	}




//////////
//
// Called to translate the indicated keywords into their corresponding operation.
//
//////
	void iiComps_xlatToSubInstr(SLine* line)
	{
		SNode	si;


		//////////
		// Copy the comps
		//////
//			saveComps = line->compilerInfo->firstComp;


		//////////
		// Find the inmost expression
		//////
			while (iiComps_xlatToSubInstr_findInmostExpression(&si, line))
			{
				// Was it a valid operation?
				if (si.opData->subInstr >= 0)
				{
					// We found the operation
					// Did we find appropriate components?
// TODO:  Working here

				} else {
					// The sub_instruction is not valid, which means were done
					break;
				}

				// When we get here, try to find another
			}


		//////////
		// There are no more "inner" expressions.
		// Now we parse out by keyword.
		//////
			if (iiComps_xlatToSubInstr_isEqualAssignment(line))
			{
				// It's something like x = y, but it could be x,y,z = a(b,c)

			} else {
				// Based upon keyword, process it
			}
	}




//////////
//
// Called to search for the thing that needs to be done next.  Order of searching:
//
// First level:
//		(1)		exponents
//		(2)		multiply, divide
//		(3)		add, subtract
//
// Second level:
//		(4)		parenthetical expressions
//		(5)		bracket expressions (arrays)
//		(6)		
//
//////
	SComp* iiComps_xlatToSubInstr_findInmostExpression(SNode* si, SLine* line)
	{
		bool	llFound;
		SComp*	comp;


		//////////
		// Initially indicate that we did not find an inmost expression
		//////
			memset(si, 0, sizeof(SNode));
			si->opData->subInstr	= -1;			// Indicate failure initially (until something is found)
			si->opData->subLevel	= -1;			// Unused during parsing


		//////////
		// Search for exponents
		//////
			comp	= line->compilerInfo->firstComp;
			llFound	= true;
			while (comp)
			{
				//////////
				// Is it an exponent?
				//////
					if (comp->iCode == _ICODE_EXPONENT)
					{
						// Exponent
						si->opData->subInstr	= _SUB_INSTR_EXPONENT;
						llFound					= true;

					} else if (comp->iCode == _ICODE_SLASH) {
						// Division
						si->opData->subInstr	= _SUB_INSTR_DIVIDE;
						llFound					= true;

					} else if (comp->iCode == _ICODE_ASTERISK) {
						// Multiplication
						si->opData->subInstr	= _SUB_INSTR_MULTIPLY;
						llFound					= true;

					} else if (comp->iCode == _ICODE_PLUS) {
						// Addition
						si->opData->subInstr	= _SUB_INSTR_ADD;
						llFound					= true;

					} else if (comp->iCode == _ICODE_HYPHEN) {
						// Subtraction
						si->opData->subInstr	= _SUB_INSTR_SUBTRACT;
						llFound					= true;
					}


				//////////
				// Was it found?
				//////
					if (llFound)
					{
						// Search for something to the left of the exponent, like the "someTable.someField" in "k = someTable.someField ^ xyz"
						// Search for something to the right of the exponent, like the "thisForm.someObject.someProperty" in "k = xyz ^ thisForm.someObject.someProperty"
// TODO:  Refactor for left and right nodes
// 						iiComps_xlatToSubInstr_findStartOfComponent	((SComp*)comp->ll.prev, si->op);
// 						iiComps_xlatToSubInstr_findFullComponent	((SComp*)comp->ll.next, si->op);

						// When we get here, si has been populated if there are operations there.
						// If they are null, then it is a syntax error
						break;
					}


				// Move to next component
				comp = (SComp*)comp->ll.next;
			}

		// Indicate our result
		return(comp);
	}




//////////
//
// We scan backwards until we get to any component other than a period or exclamation point.
//
//////
	void iiComps_xlatToSubInstr_findStartOfComponent(SComp* compRoot, SOp* op)
	{
		SComp*	comp;
		SComp*	compPrev;


		//////////
		// Iterate through
		//////
			comp		= compRoot;
			op->count	= 0;
			while (comp && comp->ll.prev && iiComps_get_charactersBetween((SComp*)comp->ll.prev, comp) == 0)
			{
				//////////
				// Previous component
				//////
					compPrev = (SComp*)comp->ll.prev;


				//////////
				// Is the component before this one still immediately adjacent?
				//////
					if (comp->iCode != _ICODE_DOT && comp->iCode != _ICODE_EXCLAMATION_POINT)
						break;		// We've reached the end, the previous component is not a continuation


				//////////
				// If we get here, we're continuing through this component at least
				//////
					comp = compPrev;
					++op->count;
			}


		//////////
		// If we get here, we will return the starting point
		//////
			op->comp = comp;
	}




//////////
//
// We scan forward so long as we are hitting a period or exclamation point which is
// immediately adjacent.
//
//////
	void iiComps_xlatToSubInstr_findFullComponent(SComp* compRoot, SOp* op)
	{
		SComp*	comp;
		SComp*	compNext;


		//////////
		// Iterate through
		//////
			comp		= compRoot;
			op->count	= 0;
			while (comp && comp->ll.next && iiComps_get_charactersBetween(comp, (SComp*)comp->ll.next) == 0)
			{
				//////////
				// Next component
				//////
					compNext = (SComp*)comp->ll.next;


				//////////
				// Is the component before this one still immediately adjacent?
				//////
					if (comp->iCode != _ICODE_DOT && comp->iCode != _ICODE_EXCLAMATION_POINT)
						break;	// We've reached the end, the next component is not a continuation


				//////////
				// If we get here, we're continuing through this component at least
				//////
					comp = compNext;
					++op->count;
			}


		//////////
		// At this point comp indicates the last component
		//////
			op->comp = comp;
	}




//////////
//
// Called to see if the instruction is an assignment:
//		x = y
//
//////
	bool iiComps_xlatToSubInstr_isEqualAssignment(SLine* line)
	{
// TODO:  Write this function :-)
		return(false);
	}




//////////
//
// Scans from the indicated location forward until finding a non-whitespace character
//
//////
	u32 iSkipWhitespaces(s8* tcData, u32 tnMaxLength)
	{
		u32 lnLength;


		// Make sure our environment's sane
		lnLength = 0;		// Initially indicate no whitespaces
		if (tcData && tnMaxLength > 0)
		{
			// While we encounter spaces or tabs, count them
			while (lnLength < tnMaxLength && (tcData[lnLength] == 32 || tcData[lnLength] == 9))
				++lnLength;
			// When we get here, lnLength is the number of whitespaces (if any)
		}
		// Indicate the total length encountered
		return(lnLength);
	}




//////////
//
// Scans from the indicated location forward until finding CR/LF or any combination thereof
//
//////
	u32 iSkipToCarriageReturnLineFeed(s8* tcData, u32 tnMaxLength, u32* tnCRLF_Length)
	{
		u32 lnLength, lnCRLF_Length;


		// Make sure our environment's sane
		lnLength		= 0;		// Initially indicate a line length of 0
		lnCRLF_Length	= 0;		// Same for CR/LF length
		if (tcData && tnMaxLength > 0)
		{
			// While we do not counter a CR or LF, continue
			while (lnLength < tnMaxLength && tcData[lnLength] != 13 && tcData[lnLength] != 10)
				++lnLength;

			// See if we are done
			if (lnLength < tnMaxLength)
			{
				// We did not reach the end of the entire data available to us to search
				// So, when we get here, we're sitting on a CR or LF, which is the end of line
				if (tcData[lnLength] == 13)
				{
					// We're sitting on a carriage return
					// If the next character is a line feed, we count it
					if (tcData[lnLength + 1] == 10)		lnCRLF_Length = 2;		// We have a pair
					else								lnCRLF_Length = 1;		// Just the one

				} else {
					// We know we're sitting on a line feed
					// If the next character is a carriage return, we count it
					if (tcData[lnLength + 1] == 13)		lnCRLF_Length = 2;		// We have a pair
					else								lnCRLF_Length = 1;		// Just the one
				}

			} else {
				// We reached the end
				// We don't do anything here, but just return the length
			}
		}
		// When we get here, return the lengths
		// The CR/LF length
		if (tnCRLF_Length)
			*tnCRLF_Length = lnCRLF_Length;

		// The stuff before length :-)
		return(lnLength);
	}




//////////
//
// Get the next Unique ID
//
//////
	u32 iGetNextUid(void)
	{
		u32 lnValue;

		// Synchronized access
		EnterCriticalSection(&cs_uniqueIdAccess);

		// Get our value and increment
		lnValue = gnNextUniqueId;
		++gnNextUniqueId;

		// All done
		LeaveCriticalSection(&cs_uniqueIdAccess);

		// Return that value
		return(lnValue);
	}



	void* iSEChain_prepend(SStartEnd* ptrSE, u32 tnUniqueId, u32 tnUniqueIdExtra, u32 tnSize, u32 tnBlockSizeIfNewBlockNeeded, bool* tlResult)
	{
		return(iSEChain_appendOrPrepend(ptrSE, tnUniqueId, tnUniqueIdExtra, tnSize, tnBlockSizeIfNewBlockNeeded, true, tlResult));
	}

	void* iSEChain_append(SStartEnd* ptrSE, u32 tnUniqueId, u32 tnUniqueIdExtra, u32 tnSize, u32 tnBlockSizeIfNewBlockNeeded, bool* tlResult)
	{
		return(iSEChain_appendOrPrepend(ptrSE, tnUniqueId, tnUniqueIdExtra, tnSize, tnBlockSizeIfNewBlockNeeded, false, tlResult));
	}

	// Prepends or appends to the Start/end chain
	void* iSEChain_appendOrPrepend (SStartEnd* ptrSE, u32 tnUniqueId, u32 tnUniqueIdExtra, u32 tnSize, u32 tnBlockSizeIfNewBlockNeeded, bool tlPrepend, bool* tlResult)
	{
		SLL*			ptrCaller;
		SMasterList*	ptrNew;
		SMasterList*	ptrPrev;
		SMasterList**	prev;


// TODO:  untested code, breakpoint and examine
// Note:  This code has been tested, but it is truly essential to operations of the VVM, and needs thoroughly tested many, many, many times. :-)
		// See where we are
		ptrCaller = NULL;
		if (ptrSE)
		{
			if (!ptrSE->root)
			{
				// This is the first item
				ptrPrev	= NULL;
				prev	= &ptrSE->root;

			} else {
				// We're appending
				if (tlPrepend)
				{
					// We go to the beginning
					ptrPrev	= ptrSE->root;
					prev	= &ptrSE->root;

				} else {
					// We are appending to the end
					ptrPrev	= ptrSE->last;
					prev	= (SMasterList**)&ptrSE->last->ll.next;
				}
			}

			// Allocate for our SMasterList pointer
			ptrNew = (SMasterList*)malloc(sizeof(SMasterList));
			if (ptrNew)
			{
				// We have our new pointer, initialize the structure
				memset(ptrNew, 0, sizeof(SMasterList));

				// Create the new caller structure
				ptrCaller = (SLL*)malloc(tnSize);
				if (ptrCaller)
				{
					// Initialize the structure
					memset(ptrCaller, 0, tnSize);

					// Indicate its unique ID
					ptrCaller->uniqueId	= tnUniqueId;

					// Store the memory variable for the caller memory block
					ptrNew->ptr			= ptrCaller;

					// Update the back-link
					*prev				= ptrNew;

					// Update the other part of the back link
					ptrNew->ll.uniqueId	= tnUniqueIdExtra;
					if (tlPrepend)
					{
						// Previous ptrSE->root points backward to ptrNew, which is now the entry pointed to by ptrSE->root
						ptrPrev->ll.prev	= (SLL*)ptrNew;		// Old first entry points backward to new first entry
						ptrNew->ll.next		= (SLL*)ptrPrev;	// New first entry points forward to old first entry
						ptrSE->root			= ptrNew;			// New first entry

					} else {
						// We are appending to the end
						ptrNew->ll.prev		= (SLL*)ptrPrev;	// Previous last entry pointing forward to new last entry
						ptrSE->last			= ptrNew;			// New last entry
					}

					// Store it in the master list (so when VM is suspended, this data gets saved)
					iSEChain_appendMasterList(ptrSE, ptrNew, 0, tnBlockSizeIfNewBlockNeeded);

					// All done!
				}
				// When we get here, ptrCaller is either populated or NULL
			}
		}
		// Indicate our success or failure explicitly if required
		if (tlResult)
			*tlResult = !(ptrCaller == NULL);

		// Return our pointer
		return(ptrCaller);
	}

	// NOTE!  Do not call this function directly!  Call iAppendToStarEndChain() only.
	void iSEChain_appendMasterList(SStartEnd* ptrSE, SMasterList* ptrNew, u32 tnHint, u32 tnBlockSizeIfNewBlockNeeded)
	{
		// This function should not be called directly.  It is automatically called from
		// iAppendToStarEndChain().  It stores pointers in the master list, pointers
		// which are part of the chain in ptrSE->root..ptrSE->last.
		u32 lnI;


// UNTESTED CODE:  Breakpoint and examine!
		lnI = tnHint;
		while (1)
		{
			// Search for first unused item
			if (ptrSE->master)
			{
				// Check to see if there is an unused slot
				for ( ; lnI < ptrSE->masterCount; lnI++)
				{
					if (!ptrSE->master[lnI])
					{
						// This slot is unused, store it
						ptrSE->master[lnI] = ptrNew;

						// Update it
						ptrNew->used = true;

						// All done
						return;
					}
				}
				// If we get here, there were no unused slots
			}
			// If we get here, no slots are available, add some more

			// Allocate some pointer space
			iSEChain_allocateAdditionalMasterSlots(ptrSE, tnBlockSizeIfNewBlockNeeded);
			// We never break out of this loop because we will always return above from it
		}
	}

	
	bool iSEChain_allocateAdditionalMasterSlots(SStartEnd* ptrSE, u32 tnBlockSize)
	{
		bool			llResult;
		SMasterList**	lml;


		// Indicate failure initially
		llResult = false;

		// Make sure our environment is sane
		if (ptrSE)
		{
			// Make sure we're really doing something
			tnBlockSize = max(tnBlockSize, 1);

			// See where we are
			if (ptrSE->master)
			{
				// Allocate another _COMMON_START_END_BLOCK_SIZE pointers
				lml = (SMasterList**)realloc(ptrSE->master, sizeof(SMasterList*) * (ptrSE->masterCount + tnBlockSize));
				if (lml)
				{
					// We're good, initialize the new section
					ptrSE->master = lml;
					memset(&ptrSE->master[ptrSE->masterCount], 0, sizeof(SMasterList*) * tnBlockSize);
					ptrSE->masterCount += tnBlockSize;
					llResult = true;

				} else {
					// It failed here
// TODO:  Something major needs to happen here.  This is more or less a catastrophic failure.  It could require shutting down the VVM.
debug_break;
					ptrSE->masterCount += tnBlockSize;
				}

			} else {
				// Allocate the first N pointers
				ptrSE->master = (SMasterList**)malloc(sizeof(SMasterList*) * tnBlockSize);
				if (ptrSE->master)
				{
					// We're good, initialize the new section
					memset(&ptrSE->master[0], 0, sizeof(SMasterList*) * tnBlockSize);
					ptrSE->masterCount	= tnBlockSize;
					llResult = true;
				}
			}
		}
		// If we get here, failure
		return(llResult);
	}




//////////
//
// Search the haystack for the needle, the haystack can be tupels, as in "_az" meaning
// (is it between "a" and "z" inclusive?)  To set this condition, use a length of 1,
// a leading "_" in tcHaystack, and two characters (one of which must NOT be NULL) after.
//
// Examples:
//		_az			= lower-case a to z inclusive
//		_AZ			= upper-case a to z inclusive
//		_09			= numeric 0 to 9 inclusive
//		_azAZ09		= any of the above in a single succession
//		_azAZ09__	= any of the above plus an underscore character (it must be done twice because of the from/to pattern
//
// Returns:
//		0		= matches
//		!0		= does not tmach
//
//////
	s32 iTranslateToCompsTest(cu8* tcHaystack, cu8* tcNeedle, s32 tnLength)
	{
		u32		lnI;
		bool	llCase;


		// Make sure our environment is sane
		if (tnLength != 0)
		{
			// See if we're a signed or unsigned compare
			if (tnLength < 0)
			{
				// Case-sensitive compare
				tnLength	= -tnLength;
				llCase		= true;

			} else {
				// Case-insensitive compare
				llCase		= false;
			}

			// See if we're looking for a tuple, or a regular compare
			if (tcHaystack[0] == '_' && tnLength == 1)
			{
				// It's an explicit match of a range (this is ALWAYS subject to case as it is an explicit range)
				for (lnI = 1; tcHaystack[lnI] != 0 && tcHaystack[lnI + 1] != 0; lnI += 2)
				{
					//		within the range low			.........			up to the range high
					if (tcNeedle[0] >= tcHaystack[lnI]			&&		tcNeedle[0] <= tcHaystack[lnI + 1])
						return(0);		// It's a match, needle is in the range
				}
				// Not a match, will fall through to below

			} else {
				// Just a regular compare
				if (llCase)		return(  memcmp((s8*)tcHaystack, (s8*)tcNeedle, tnLength));
				else			return(_memicmp((s8*)tcHaystack, (s8*)tcNeedle, tnLength));
			}
		}
		// If we get here, no match
		return(-1);
	}




//////////
//
// Callback, used to translate existing components into other components
// Note:  Always returns false, so it will continue being fed every component
//
//////
	bool iioss_translateCompsToOthersCallback(SStartEndCallback* cb)
	{
		s32						lnLacsLength;
		SComp*					comp;
		SAsciiCompSearcher*		lacs;


		// Make sure the environment is sane
		if (cb && cb->ptr)
		{
			// Grab our pointers into recognizable thingamajigs
			comp	= (SComp*)cb->ptr;
			lacs	= (SAsciiCompSearcher*)cb->extra;

			// Iterate through this item to see if any match
			for (	/* lacs is initialize above */;
					lacs->length != 0;
					lacs++		)
			{
				// Grab the normalized length
				lnLacsLength = abs(lacs->length);

				// We only test if they're the same length
				if (lnLacsLength == comp->length || (lacs->repeats && lnLacsLength <= comp->length))
				{
					// We only test if this item is not the first item on line, or if must be the first
					// item on the line, then this component must be the first component on the line.  Simple, yes? :-)
					if (!lacs->firstOnLine || !comp->ll.prev)
					{
						// Physically conduct the exact comparison
						if (iTranslateToCompsTest(lacs->keyword_u8, 
													comp->line->sourceCode->data_u8 + comp->start, 
													lacs->length) == 0)
						{
							// This is a match
							// Convert it, translate it, whatever you want to call it, just make it be the new code, per the user's request, got it? :-)
							comp->iCode = lacs->iCode;
							// All done with this component
							break;
						}
					}
				}
			}

		}
		// We always simulate a false condition so we'll keep receiving each item
		return(false);
	}




//////////
//
// Search for the indicated record in the chain by using a user-defined callback on the pointer.
// Callback function should return true when found, false to continue sending other items back.
//
// Returns:
//		NULL if error
//		The associated pointer if found
//
//////
	void* iSEChain_searchByCallback(SStartEnd* ptrSE, SStartEndCallback* cb)
	{
		u32 lnI;


		// Make sure the environment is sane
		if (ptrSE)
		{
			// Iterate through the master list until we find the associated entry
			for (lnI = 0; lnI < ptrSE->masterCount; lnI++)
			{
				// Ask the caller if this is it
				if (ptrSE->master[lnI] && ptrSE->master[lnI]->used)
				{
					// Store the pointer for the caller
					cb->ptr = ptrSE->master[lnI]->ptr;

					// Perform the call
					if (cb->funcBool(cb))
						return(ptrSE->master[lnI]->ptr);	// We've found our man
				}
			}
		}
		// If we get here, failure
		return(NULL);
	}




//////////
//
// Search for the indicated uniqueId in the chain.
//
// Returns:
//		NULL if error
//		The associated pointer if found
//
//////
	void* iSEChain_searchByUniqueId(SStartEnd* ptrSE, u64 tnUniqueId)
	{
		u32 lnI;


		// Make sure the environment is sane
		if (ptrSE)
		{
			// Iterate through the master list until we find the associated entry
			for (lnI = 0; lnI < ptrSE->masterCount; lnI++)
			{
				if (ptrSE->master[lnI] && ptrSE->master[lnI]->used && ((SLL*)(ptrSE->master[lnI]->ptr))->uniqueId == tnUniqueId)
				{
					// We've found our man
					return(ptrSE->master[lnI]->ptr);
				}
			}
		}
		// If we get here, failure
		return(NULL);
	}




//////////
//
// Iterates through the indicated Start/End list, calling back the callback function for every item.
//
//////
	void iSEChain_iterateThroughForCallback(SStartEnd* ptrSE, SStartEndCallback* cb)
	{
		u32 lnI;


		// Make sure the environment is sane
		if (ptrSE)
		{
			// Iterate through the master list calling every valid entry
			for (lnI = 0; lnI < ptrSE->masterCount; lnI++)
			{
				// Give this to the caller for their processing
				if (ptrSE->master[lnI] && ptrSE->master[lnI]->used)
				{
					// Store the pointer for the caller
					cb->ptr = ptrSE->master[lnI]->ptr;

					// Perform the call
					cb->funcVoid(cb);
				}
			}
		}
	}





//////////
//
// Called as a callback from the custom handler callback function, to do some manual insertion.
// Note:  If a rogue component is inserted here, one not already defined in the ref's SOssLine parent,
//        then it will need to be either manually added to the line->comps, or manually tended to.
//
//////
	void iiComps_xlatToOthersCallback__insertCompByCompCallback(SComp* compRef, SComp* compNew, bool tlInsertAfter)
	{
// TODO:  untested code, breakpoint and examine
debug_break;
		// Make sure our environment is sane
		if (compRef && compNew)
		{
			// Before or after?
			if (tlInsertAfter)
			{
				// Add the new comp after the reference comp
				if (compRef->ll.next)
					compRef->ll.next->prev	= (SLL*)compNew;	// One originally after ref points back to new

				compNew->ll.next	= compRef->ll.next;			// New points forward to the one originally after ref
				compNew->ll.prev	= (SLL*)compRef;			// New points back to ref
				compRef->ll.next	= (SLL*)compNew;			// Ref points forward to new

			} else {
				// Add the new comp before the reference comp
				if (compRef->ll.prev)
					compRef->ll.prev->next	= (SLL*)compNew;	// One originally before ref points forward to new

				compNew->ll.next	= (SLL*)compRef;			// New points forward to ref
				compNew->ll.prev	= compRef->ll.prev;			// New points back to the one originally before ref
				compRef->ll.prev	= (SLL*)compNew;			// Ref points back to new
			}
		}
	}




//////////
//
// Called as a callback from the custom handler callback function, to do some manual insertion.
//
//////
	void iiComps_xlatToOthersCallback__insertCompByParamsCallback(SComp* compRef, SLine* line, u32 tniCode, u32 tnStart, s32 tnLength, bool tlInsertAfter)
	{
		SComp* compNew;


// TODO:  untested code, breakpoint and examine
debug_break;
		// Make sure our environment is sane
		if (compRef && line && line->compilerInfo)
		{
			// Allocate a new pointer
			compNew = (SComp*)iLl_appendNewNode((SLL**)&line->compilerInfo->firstComp, NULL, NULL, NULL, iGetNextUid(), sizeof(SComp));
			if (compNew)
			{
				// Initialize it
				memset(compNew, 0, sizeof(SComp));

				// Populate it
				compNew->line		= line;
				compNew->iCode		= tniCode;
				compNew->start		= tnStart;
				compNew->length		= tnLength;

				// Add the new component as a component
				iiComps_xlatToOthersCallback__insertCompByCompCallback(compRef, compNew, tlInsertAfter);
			}
		}
	}




//////////
//
// Called as a callback from the custom handler callback function, to do delete the
// indicated component.
//
//////
	void iiComps_xlatToOthersCallback__deleteCompsCallback(SComp* comp, SLine* line)
	{
// TODO:  untested code, breakpoint and examine
debug_break;
		//////////
		// Disconnect the component from its siblings
		//////
			// Make the one before point forward to one after
			if (comp->ll.prev)
				comp->ll.prev->next = comp->ll.next;

			// Make the one after point back to the one before
			if (comp->ll.next)
				comp->ll.next->prev = comp->ll.prev;


		//////////
		// Delete it from the list of known components.
		// Component go bye bye. :-)
		//////
			if (line)
			{
				// Delete the entry from line->comps
				iLl_deleteNode((SLL*)comp, true);

			} else {
				// Free the rogue entry
				free(comp);
			}
	}




//////////
//
// Called as a callback from the custom handler callback function, to clone the indicated
// component.  If line is not NULL, the component is automatically added to line->comps;
//
//////
	SComp* iiComps_xlatToOthersCallback__cloneCompsCallback(SComp* comp, SLine* line)
	{
		SComp* compNew;


// TODO:  untested code, breakpoint and examine
debug_break;
		// Make sure our environment is sane
		compNew = NULL;
		if (comp)
		{
			// Are we adding to to a line?
			if (line && line->compilerInfo)
			{
				// Add the new component to line->comps
				compNew = (SComp*)iLl_appendNewNode((SLL**)&line->compilerInfo->firstComp, NULL, NULL, NULL, iGetNextUid(), sizeof(SComp));

			} else {
				// Just create a rogue one
				compNew = (SComp*)malloc(sizeof(SComp));
			}

			// Was it valid?
			if (compNew)
			{
				// Initialize it
				memset(compNew, 0, sizeof(SComp));

				// Populate it
				compNew->line		= line;
				compNew->iCode		= comp->iCode;
				compNew->start		= comp->start;
				compNew->length		= comp->length;

				// All done!
			}
		}

		// Return our new one, no matter if it was a success or not
		return(compNew);
	}




//////////
//
// Called as a callback from the custom handler callback function, to do merge components into
// a new one, and delete the one(s) which were merged.
//
// NOTE:  It's theoretically possible that there could be a gap here, such as a component next to
//        another component where there used to be a whitespace inbetween (or anything else), so
//        the components are no longer right by each other.  The caller will have to manually
//        handle that condition.
//
//////
	SComp* iiComps_xlatToOthersCallback__mergeCompsCallback(SComp* comp, SLine* line, u32 tnCount, u32 tniCodeNew)
	{
		u32			lnI;
		SComp*	compThis;


// TODO:  untested code, breakpoint and examine
debug_break;
		// Make sure our environment is sane
		if (comp)
		{
			// Iterate for each merging
			for (lnI = 1, compThis = (SComp*)comp->ll.next; compThis && lnI < tnCount; lnI++, compThis = (SComp*)comp->ll.next)
			{
				// Absorb compThis's length into comp's "collective"
				comp->length += compThis->length;

				// Delete this component
				iiComps_xlatToOthersCallback__deleteCompsCallback(compThis, comp->line);

				// Note:  compThis is always assigned comp->ll.next, because its next component keeps being updated after the delete
			}
			// When we get here, everything's merged
		}
		// Return the original component as a pass through (in case this is used as an intermediate function)
		return(comp);
	}




//////////
//
// Delete the indicated item from the chain
//
//////
	void iSEChain_deleteFrom(SStartEnd* ptrSE, void* ptrCaller, bool tlDeletePointers)
	{
		u32				lnI;
		SMasterList*	ptrDel;
		SMasterList**	master;


		// See where we are
// UNTESTED CODE:  Breakpoint and examine!
		if (ptrSE)
		{
			if (!ptrSE->root)
			{
				// There are no existing items, nothing to do, why are they messing around with our brains? :-)
				return;
			}

			// Iterate through the master list to find the matching record to delete in the chain
			master = ptrSE->master;
			for (lnI = 0; lnI < ptrSE->masterCount; lnI++)
			{
				// See if this item matches
				ptrDel = master[lnI];
				if (ptrDel && ptrDel->used && ptrDel->ptr == ptrCaller)
				{
					// Mark it as not being used
					ptrDel->used = false;

					// Remove it from its chain
					if (ptrDel == ptrSE->root)
					{
//////////
// This is the first item
//////
						// We are deleting the first item in the list
						if (ptrDel == ptrSE->last)
						{
							// Which is also the last item in the list
							ptrSE->root = NULL;
							ptrSE->last = NULL;
							// No items exist after this

						} else {
							// It's just the first item in a chain
							ptrSE->root = (SMasterList*)ptrDel->ll.next;
						}


					} else if (ptrDel == ptrSE->last) {
//////////
// This is the last item
//////
						// We are deleting the last item in the list
						ptrSE->last									= (SMasterList*)ptrDel->ll.prev;	// This will never be NULL because we've already checked the first condition
						((SMasterList*)(ptrDel->ll.prev))->ll.next	= NULL;								// Make the one before this point to nothing, because it is now the last item


					} else {
//////////
// This is an entry in the middle somewhere
//////
						// We are deleting an entry in the middle somewhere
						((SMasterList*)(ptrDel->ll.prev))->ll.next	= ptrDel->ll.next;		// Make the one before this point to the one after this
						((SMasterList*)(ptrDel->ll.next))->ll.prev	= ptrDel->ll.prev;		// Make the one after this point to the one before this
					}
					// When we get here, the start/end chain is updated


					// Release our SMasterList pointer
					free(ptrDel);
					master[lnI] = NULL;


					// Release the caller's memory (or not if they want to keep it)
					if (tlDeletePointers)
						free(ptrCaller);		// Delete this pointer
					// All done
				}
			}
		}
		//else not found
	}




//////////
//
// Migrate the existing SMasterList item, and its associated SLL item, from one Start/end chain
// to another, by either pointer or physical position number.
//
//////
	SLL* iSEChain_completelyMigrateSLLByPtr(SStartEnd* ptrSEDst, SStartEnd* ptrSESrc, SLL* ptr, u32 tnHint, u32 tnBlockSize)
	{
		u32 lnI;


		// Make sure our environment is sane
		if (ptrSEDst && ptrSESrc && ptrSESrc->masterCount >= 1)
		{
			for (lnI = 0; lnI < ptrSESrc->masterCount; lnI++)
			{
				// Is this our pointer?
				if (ptrSESrc->master[lnI] && ptrSESrc->master[lnI]->ptr == (void*)ptr)
				{
					// This is our man, migrate it
// TODO:  (enhancement) we want some kind of better hinting algorithm here, such as the end of the list - common block size, for now we'll just pass 0
					return(iSEChain_completelyMigrateSLLByNum(ptrSEDst, ptrSESrc, lnI, 0, tnBlockSize));
				}
			}
			// If we get here, not found
		}
		// Indicate failure
		return(NULL);
	}

	SLL* iSEChain_completelyMigrateSLLByNum(SStartEnd* ptrSEDst, SStartEnd* ptrSESrc, u32 lnSrcNum, u32 tnHint, u32 tnBlockSize)
	{
		SLL*			lllPrev;
		SLL*			lllNext;
		SLL*			lll;
		SMasterList*	lml;


		// Make sure our environment is sane
		if (ptrSEDst && ptrSESrc && lnSrcNum < ptrSESrc->masterCount && lnSrcNum <= ptrSESrc->masterCount)
		{
			// Migrate it, and get its SMasterList entry
			lml = iSEChain_migrateByNum(ptrSEDst, ptrSESrc, lnSrcNum, tnHint, tnBlockSize);
			if (lml && lml->ptr)
			{
				// Grab the pointer to the SLL entry
				lll = (SLL*)lml->ptr;
				// Right now, lll points to the SLL* object from ptrSESrc

				// Grab ptrSESrc's preceding, and following objects (if any)
				lllPrev	= lll->prev;
				lllNext = lll->next;


				//////////
				// Update the ptrSESrc entry, to remove this lll entry from its lists
				//////
					// Update the pointer for the preceding entry
					if (lllPrev)
						lllPrev->next = lllNext;
					// Update the pointer for the following entry
					if (lllNext)
						lllNext->prev = lllPrev;
					// Right now, lllPrev points forward past lll, and lllNext points backward past lll


				//////////
				// lll is currently an orphan entry that thinks it's not orphaned because it still has prev and next pointers potentially pointing off somewhere
				//////
					// Update lll's prev and next entries to point nowhere
					lll->next = NULL;
					lll->prev = NULL;
					// At this point, lll is only pointed to by its lml entry.


				// All done!
				return(lll);
			}
		}
		// If we get here, invalid environment
		return(NULL);
	}

	SMasterList* iSEChain_migrateByNum(SStartEnd* ptrSEDst, SStartEnd* ptrSESrc, u32 lnSrcNum, u32 tnHint, u32 tnBlockSize)
	{
		u32				lnI;
		SMasterList*	lml;


		// Make sure our environment is sane
		if (ptrSEDst && ptrSESrc && lnSrcNum < ptrSESrc->masterCount && lnSrcNum <= ptrSESrc->masterCount)
		{
			// We enter an infinite loop in case we have to
			while (1)
			{
				// Find an empty slot in the destination
				for (lnI = tnHint; lnI < ptrSEDst->masterCount; lnI++)
				{
					if (!ptrSEDst->master[lnI] || !ptrSEDst->master[lnI]->used)
					{
						// We found an empty slot, migrate it
						lml							= ptrSESrc->master[lnSrcNum];
						ptrSEDst->master[lnI]		= lml;

						// Clear out the source slot
						ptrSESrc->master[lnSrcNum]	= NULL;

						// See if the thing that was pointed to was the first or last entry (or both (only entry))
						if (ptrSESrc->root == lml)
						{
							// This was the first entry
							if (ptrSESrc->last == lml)
							{
								// And it was the last entry, making it the ONLY entry
								ptrSESrc->root = NULL;
								ptrSESrc->last = NULL;

							} else {
								// It was just the first entry
								ptrSESrc->root = (SMasterList*)lml->ll.next;
							}

						} else if (ptrSESrc->last == lml) {
							// It was the last entry
							ptrSESrc->last = (SMasterList*)lml->ll.prev;
						}
						//else it's just one in the middle, so no worries

						// Detach from its former list (former's previous points to former's next, former's next points to former's previous, basically they both skip over this item)
						if (lml->ll.prev)	((SMasterList*)(lml->ll.prev))->ll.next = lml->ll.next;
						if (lml->ll.next)	((SMasterList*)(lml->ll.next))->ll.prev = lml->ll.prev;
						// Right now, lml is an orphan, but it has pointers to its old slots

						// Append it to the new list, and update its pointers to its new home
						if (!ptrSEDst->root)
						{
							// This is the first item in the destination
							ptrSEDst->root	= lml;
							ptrSEDst->last	= lml;
							lml->ll.prev	= NULL;

						} else {
							// Append it to the end of the chain
							ptrSEDst->last->ll.next = (SLL*)lml;
							lml->ll.prev			= (SLL*)ptrSEDst->last;
							ptrSEDst->last			= lml;
						}
						// Make the newly migrated item now point to nothing, because it is the last item
						lml->ll.next = NULL;

						// All done!
						return(lml);
					}
				}
				// If we get here, no empty slots. Allocate some, rinse, and repeat. :-)
				iSEChain_allocateAdditionalMasterSlots(ptrSEDst, tnBlockSize);

				// Process through again beginning at the newly added portion
				tnHint = lnI;
				// We'll never break out of this loop because we will always return above
			}
			// Control will never get here
		}
		// If we get here, error
		return(NULL);
	}




//////////
//
// Called to create a new node and attach it to the hint as indicated.
//
//////
	SNode* iNode_create(SNode** root, SNode* hint, u32 tnDirection, SNode* parent, SNode* prev, SNode* next, SNode* left, SNode* right)
	{
		SNode*		nodeNew;
		SNode**		nodePrev;
		SNode*		nodeOrphan;


		// Make sure our environment is sane
		nodeNew = NULL;
		if (root)
		{
			if (!*root)
			{
				// This is the first item
				nodePrev = root;

			} else {
				// We're adding to the hint
				if (!hint)
				{
					// No hint, we are creating an orphan
					nodePrev = &nodeOrphan;

				} else {
					// Relates to hint in some way
					switch (tnDirection)
					{
						default:
						case _NODE_NONE:
							// Create an orphan node
							nodePrev = &nodeOrphan;
							break;

						case _NODE_PARENT:
							// Connecting to hint->parent
							nodePrev = &hint->parent;
							break;

						case _NODE_PREV:
							// Connecting to hint->prev
							nodePrev = &hint->prev;
							break;

						case _NODE_NEXT:
							// Connecting to hint->next
							nodePrev = &hint->next;
							break;

						case _NODE_LEFT:
							// Connecting to hint->left
							nodePrev = &hint->left;
							break;

						case _NODE_RIGHT:
							// Connecting to hint->right
							nodePrev = &hint->right;
							break;
					}
				}
			}


			//////////
			// Add the new node
			//////
				nodeNew = (SNode*)malloc(sizeof(SNode));
				if (nodeNew)
				{
					// Initialize
					memset(nodeNew, 0, sizeof(SNode));

					// Update the link from previous
					*nodePrev			= nodeNew;

					// Connect our new node
					nodeNew->parent		= parent;
					nodeNew->prev		= prev;
					nodeNew->next		= next;
					nodeNew->left		= left;
					nodeNew->right		= right;
				}


		}

		// Indicate our status
		return(nodeNew);
	}




//////////
//
// Creates a new node and inserts it where node1 currently points to node2.
//
//////
	SNode* iNode_insertBetween(SNode** root, SNode* node1, SNode* node2, u32 tnNode1Direction, u32 tnNode2Direction)
	{
		u32		lnNode1Direction, lnNode2Direction;
		SNode*	nodeNew;


		// Make sure our environment is sane
		nodeNew = NULL;
		if (root)
		{
			//////////
			// Find out where we're going node1 to node2
			//////
				if (node1)
				{
					if (node1->parent == node2)			lnNode1Direction = _NODE_PARENT;		// We're going up
					else if (node1->prev == node2)		lnNode1Direction = _NODE_PREV;			// We're going to previous
					else if (node1->next == node2)		lnNode1Direction = _NODE_NEXT;			// We're going to next
					else if (node1->left == node2)		lnNode1Direction = _NODE_LEFT;			// We're going left
					else if (node1->right == node2)		lnNode1Direction = _NODE_RIGHT;			// We're going to right
					else								lnNode1Direction = _NODE_NONE;			// Failure, they are not connected

				} else {
					// No node1
					lnNode1Direction = tnNode1Direction;
				}


			//////////
			// Find out where we're going node2 to node1
			//////
				if (node2)
				{
					if (node2->parent == node1)			lnNode2Direction = _NODE_PARENT;		// We're going up
					else if (node2->prev == node1)		lnNode2Direction = _NODE_PREV;			// We're going to previous
					else if (node2->next == node1)		lnNode2Direction = _NODE_NEXT;			// We're going to next
					else if (node2->left == node1)		lnNode2Direction = _NODE_LEFT;			// We're going left
					else if (node2->right == node1)		lnNode2Direction = _NODE_RIGHT;			// We're going to right
					else								lnNode2Direction = _NODE_NONE;			// They are not connected in this direction

				} else {
					// No node2
					lnNode2Direction = tnNode2Direction;
				}


			// Create an orphan node
			nodeNew = iNode_create(root, NULL, 0, NULL, NULL, NULL, NULL, NULL);
			if (nodeNew)
			{
				//////////
				// Hook it up to node1
				//////
					switch (lnNode1Direction)
					{
						case _NODE_PARENT:
							// It's going up from node1 to node2
							nodeNew->parent	= node2;		// Hook the new node up to where node1 used to point (node2)
							node1->parent	= nodeNew;		// Make node1 now point to our inserted node (nodeNew)
							break;

						case _NODE_PREV:
							// It's going up from node1 to node2
							nodeNew->prev	= node2;		// Hook the new node up to where node1 used to point (node2)
							node1->prev		= nodeNew;		// Make node1 now point to our inserted node (nodeNew)
							break;

						case _NODE_NEXT:
							// It's going up from node1 to node2
							nodeNew->next	= node2;		// Hook the new node up to where node1 used to point (node2)
							node1->next		= nodeNew;		// Make node1 now point to our inserted node (nodeNew)
							break;

						case _NODE_LEFT:
							// It's going up from node1 to node2
							nodeNew->left	= node2;		// Hook the new node up to where node1 used to point (node2)
							node1->left		= nodeNew;		// Make node1 now point to our inserted node (nodeNew)
							break;

						case _NODE_RIGHT:
							// It's going up from node1 to node2
							nodeNew->right	= node2;		// Hook the new node up to where node1 used to point (node2)
							node1->right	= nodeNew;		// Make node1 now point to our inserted node (nodeNew)
							break;
					}


				//////////
				// Hook it up to node2
				//////
					switch (lnNode2Direction)
					{
						case _NODE_PARENT:
							// It's going up from node2 to node1
							nodeNew->parent	= node1;		// Hook the new node up to where node2 used to point (node1)
							node2->parent	= nodeNew;		// Make node2 now point to our inserted node (nodeNew)
							break;

						case _NODE_PREV:
							// It's going prev from node2 to node1
							nodeNew->prev	= node1;		// Hook the new node up to where node2 used to point (node1)
							node2->prev		= nodeNew;		// Make node2 now point to our inserted node (nodeNew)
							break;

						case _NODE_NEXT:
							// It's going next from node2 to node1
							nodeNew->next	= node1;		// Hook the new node up to where node2 used to point (node1)
							node2->next		= nodeNew;		// Make node2 now point to our inserted node (nodeNew)
							break;

						case _NODE_LEFT:
							// It's going left from node2 to node1
							nodeNew->left	= node1;		// Hook the new node up to where node2 used to point (node1)
							node2->left		= nodeNew;		// Make node2 now point to our inserted node (nodeNew)
							break;

						case _NODE_RIGHT:
							// It's going right from node2 to node1
							nodeNew->right	= node1;		// Hook the new node up to where node2 used to point (node1)
							node2->right	= nodeNew;		// Make node2 now point to our inserted node (nodeNew)
							break;
					}
			}
		}

		// Indicate our status
		return(nodeNew);
	}




//////////
//
// Called to delete the entire node change recursively
//
//////
	void iNode_politelyDeleteAll(SNode** root, bool tlDeleteSelf, bool tlTraverseParent, bool tlTraversePrev, bool tlTraverseNext, bool tlTraverseLeft, bool tlTraverseRight)
	{
		SNode* node;


		if (root && *root)
		{
			//////////
			// Grab the node
			//////
				node = *root;


			//////////
			// Traverse parent
			//////
				if (tlTraverseParent && node->parent)
				{
					iNode_politelyDeleteAll(&node->parent, true, node->parent->parent != node, node->prev->prev != node, node->prev->next != node, node->prev->left != node, node->prev->right != node);
					node->prev = NULL;
				}


			//////////
			// Traverse prev
			//////
				if (tlTraversePrev && node->prev)
				{
					iNode_politelyDeleteAll(&node->prev, true, node->parent->parent != node, node->prev->prev != node, node->prev->next != node, node->prev->left != node, node->prev->right != node);
					node->prev = NULL;
				}


			//////////
			// Traverse next
			//////
				if (tlTraverseNext && node->next)
				{
					iNode_politelyDeleteAll(&node->next, true, node->parent->parent != node, node->next->prev != node, node->next->next != node, node->next->left != node, node->next->right != node);
					node->next = NULL;
				}


			//////////
			// Traverse left
			//////
				if (tlTraverseLeft && node->left)
				{
					iNode_politelyDeleteAll(&node->left, true, node->parent->parent != node, node->left->prev != node, node->left->next != node, node->left->left != node, node->left->right != node);
					node->left = NULL;
				}


			//////////
			// Traverse right
			//////
				if (tlTraverseRight && node->right)
				{
					iNode_politelyDeleteAll(&node->right, true, node->parent->parent != node, node->right->prev != node, node->right->next != node, node->right->left != node, node->right->right != node);
					node->right = NULL;
				}


			//////////
			// Delete the op if need be
			//////
				iOp_politelyDelete(&node->opData->op, false);


			//////////
			// Delete the variable chain
			//////
				if (node->opData->firstVariable)
					iVariable_politelyDeleteChain(&node->opData->firstVariable, true);


			//////////
			// Delete self
			//////
				if (tlDeleteSelf)
				{
					// Free self
					free(node);
					*root = NULL;
				}
		}
	}




//////////
//
// Called to create an empty function with a name.
//
//////
	SFunction* iFunction_allocate(SComp* compName)
	{
		SFunction* funcNew;


		// Create the function
		funcNew = (SFunction*)malloc(sizeof(SFunction));
		if (funcNew)
		{
			// Initialize
			memset(funcNew, 0, sizeof(SFunction));

			// Store name if provided
			if (compName && compName->line && compName->line->sourceCode && compName->line->sourceCode->data)
			{
				// There is a component, a line, and source code exists
				// Does the component exist properly?
				if (compName->start + compName->length <= compName->line->sourceCode_populatedLength)
				{
					// Yes, store the name
					iDatum_duplicate(	&funcNew->name, 
										compName->line->sourceCode->data_u8 + compName->start,
										compName->length);
				}
			}
		}

		// Indicate our status
		return(funcNew);
	}

	SFunction* iFunction_allocate(u8* tcFuncName)
	{
		SFunction* funcNew;


		// Create the function
		funcNew = (SFunction*)malloc(sizeof(SFunction));
		if (funcNew)
		{
			// Initialize
			memset(funcNew, 0, sizeof(SFunction));

			// Store name if provided
			if (tcFuncName)
				iDatum_duplicate(&funcNew->name, tcFuncName, -1);
		}

		// Indicate our status
		return(funcNew);
	}




//////////
//
// Called to add a scoped variable to the function
//
//////
	SVariable* iFunction_addVariable_scoped(SFunction* func)
	{
		SVariable*	varNew;


		// Make sure our environment is sane
		varNew = NULL;
		if (func)
		{
			// We create an empty variable slot, one which will receive the variable content/value at some later time during computation
			varNew = (SVariable*)iLl_appendNewNodeAtEnd((SLL**)&func->scoped, sizeof(SVariable));		// Create a new variable
		}

		// Indicate our status
		return(varNew);
	}




//////////
//
// Politely deletes everything contained in a function definition.  This also mandates
// that every line be marked for a forced recompile as it will lose all previously compiled
// information, including all variables that were found.
//
//////
	void iFunction_politelyDeleteCompiledInfo(SFunction* func, bool tlDeleteSelf)
	{
		bool	llContinue;
		SLine*	line;


		// Make sure our environment is sane
		if (func && func->firstLine)
		{
			// Disconnect everything in its source code lines from the function
			line		= func->firstLine;
			llContinue	= true;

			// Iterate through every line between first and last inclusive
			while (line && llContinue)
			{
				// Delete every node if need be
				if (line->compilerInfo && line->compilerInfo->firstNode)
				{
					// Delete from regular components, and whitespaces
					iComps_deleteAll_byFirstComp(&line->compilerInfo->firstComp);
					iComps_deleteAll_byFirstComp(&line->compilerInfo->firstWhitespace);
				}

				// Mark it so that it will be force-re-compiled
				line->forceRecompile = true;

				// Move to next line
				llContinue	= (line != func->lastLine);
				line		= (SLine*)line->ll.next;
			}

			// Should we delete self?
			if (tlDeleteSelf)
				free(func);
		}
	}




//////////
//
// Called to politely delete everything contained within the function
//
//////
	void iFunction_politelyDeleteChain(SFunction** rootFunc)
	{
		SFunction* func;


		// Make sure our environment is sane
		if (rootFunc && *rootFunc)
		{
			// Delete the items
			func = *rootFunc;

			// Clear this item
			*rootFunc = NULL;

			// Orphanize this item
			iLl_orphanizeNode((SLL*)func);

			// Delete the name
			iDatum_delete(&func->name, false);

			// Delete this function's variables
			iVariable_politelyDeleteChain(&func->params, true);
			iVariable_politelyDeleteChain(&func->locals, true);
			iVariable_politelyDeleteChain(&func->returns, true);
			iVariable_politelyDeleteChain(&func->scoped, true);
			iVariable_politelyDeleteChain(&func->params, true);

			// Delete the adhocs for this function
			iFunction_politelyDeleteChain(&func->firstAdhoc);
		}
	}




//////////
//
// Called to terminate the indirect references to the point of
//
//////
	SVariable* iiVariable_terminateIndirect(SVariable* var)
	{
		// Is there an indirect reference?
		if (var && var->indirect)
			return(iiVariable_terminateIndirect(var->indirect));

		// We're done
		return(var);
	}




//////////
//
// Called to create a new variable.  It is an orphan and initialized, but has
// no identity.
//
//////
	SVariable* iVariable_create(s32 tnVarType, SVariable* varIndirect)
	{
		SVariable* varNew;


		//////////
		// Create it
		//////
			varNew = (SVariable*)malloc(sizeof(SVariable));


		//////////
		// Initialize, populate it, and for some types go ahead and allocate it
		//////
			if (varNew)
			{
				// Initialize
				memset(varNew, 0, sizeof(SVariable));

				// Populate
				varNew->indirect		= varIndirect;
				varNew->isVarAllocated	= true;
				varNew->varType			= tnVarType;

				// If it's not an indirect reference, we need to initialize the data
				if (!varNew->indirect)
				{
					// Initially allocate for certain fixed variable types
					switch (tnVarType)
					{
						case _VAR_TYPE_NULL:
							// NULL variables do not get any allocation, but are something like temporary placeholders to be later changed into some valid form
							break;

						case _VAR_TYPE_S32:
						case _VAR_TYPE_U32:
						case _VAR_TYPE_F32:
							// Allocate 4 bytes
							varNew->isValueAllocated = true;
							iDatum_allocateSpace(&varNew->value, 4);
							break;

						case _VAR_TYPE_NUMERIC:
							// Allocate 10 bytes for 18 digits plus sign in BCD
							varNew->isValueAllocated = true;
							iDatum_duplicate(&varNew->value, cgc_defaultNumeric, sizeof(cgc_defaultNumeric));	// Include the trailing NULL
							break;

						case _VAR_TYPE_S64:
						case _VAR_TYPE_U64:
						case _VAR_TYPE_F64:
						case _VAR_TYPE_DATE:
						case _VAR_TYPE_DATETIME:
						case _VAR_TYPE_CURRENCY:
							// Allocate 8 bytes
							varNew->isValueAllocated = true;
							iDatum_allocateSpace(&varNew->value, 8);
							break;

						case _VAR_TYPE_S16:
						case _VAR_TYPE_U16:
							// Allocate 2 bytes
							varNew->isValueAllocated = true;
							iDatum_allocateSpace(&varNew->value, 2);
							break;

						case _VAR_TYPE_S8:
						case _VAR_TYPE_U8:
						case _VAR_TYPE_LOGICAL:
							// Allocate 1 byte
							varNew->isValueAllocated = true;
							iDatum_allocateSpace(&varNew->value, 1);
							break;

						case _VAR_TYPE_BITMAP:
							varNew->bmp = iBmp_copy(bmpNoImage);
							break;

						case _VAR_TYPE_CHARACTER:
							// We do not initially allocate anything, but rather this variable can be populated later.
							// Right now it will be a .NULL. variable.
							break;

						default:
							// Unspecified.  Default to the system default.
							if (gsCurrentSetting->varInitializeDefault_value)		varNew = iVariable_copy(gsCurrentSetting->varInitializeDefault_value, false);
							else													varNew = iVariable_create(_VAR_TYPE_LOGICAL, NULL);
					}
				}
			}


		//////////
		// Indicate our status
		//////
			return(varNew);
	}




//////////
//
// Called to create and populate a new variable in one go
//
//////
	SVariable* iVariable_createAndPopulate(s32 tnVarType, SDatum* datum)
	{
		if (datum)		return(iVariable_createAndPopulate(tnVarType, datum->data_u8, datum->length));
		else			return(NULL);
	}

	SVariable* iVariable_createAndPopulate(s32 tnVarType, u8* tcData, u32 tnDataLength)
	{
		SVariable* var;


		// Create the variable
		var = iVariable_create(tnVarType, NULL);
		if (var && tcData && tnDataLength > 0)
		{
			// Populate it
			if (var)
			{
				// Allocate the SDatum
				if (tcData && tnDataLength > 0)
					iDatum_duplicate(&var->value, tcData, tnDataLength);

// TODO:  We may need to add a validation here to indicate that for the specific types it should remain the length it must be for the type

				// Indicate the content within this variable has been allocated
				var->isValueAllocated = true;
			}
		}

		// Indicate our status
		return(var);
	}

	SVariable* iVariable_createAndPopulate(s32 tnVarType, cu8* tcData, u32 tnDataLength)
	{
		return(iVariable_createAndPopulate(tnVarType, (u8*)tcData, tnDataLength));
	}




//////////
//
// Called to create a character variable using the indicated base/radix
//
//////
	SVariable* iVariable_createByRadix(u64 tnValue, u64 tnBase, u32 tnPrefixChars, u32 tnPostfixChars)
	{
		s32			lnI;
		SVariable*	result;
		cu8*		base;
		u8			buffer[256];


		//////////
		// Make sure our environment is sane
		//////
			if (tnBase >= 2 && tnBase <= 256)
			{
				//////////
				// Based on the base, we use different characters for the conversion
				//////
					if (tnBase <= 10)
					{
						// Force into the range 0..9
						base = &cgcBase10[0];

					} else if (tnBase == 26) {
						// Force into the range A..Z
						base = &cgcBase26[0];

					} else if (tnBase <= 36) {
						// Force into the range 0..9, A..Z
						base = &cgcBase36[0];

					} else if (tnBase == 52) {
						// Force into the range A..Z, a..z
						base = &cgcBase52[0];

					} else if (tnBase <= 62) {
						// Force into the range 0..9, A..Z, a..z
						base = &cgcBase62[0];

					} else {
						// Use ASCII and extended ASCII characters
						base = &cgcBase256[0];
					}

				//////////
				// Extract out the radix "digits"
				//////
					for (lnI = 0, memset(buffer, 0, sizeof(buffer)); tnValue != 0; lnI++)
					{
						// Store this digit
						buffer[lnI] = base[(u32)(tnValue % tnBase)];

						// Divide it out
						tnValue /= tnBase;
					}


				//////////
				// If the value was 0, force a zero in there
				//////
					if (lnI == 0)
					{
						++lnI;
						buffer[0] = '0';
					}


				//////////
				// Create the variable
				//////
					result = iVariable_createAndPopulate(_VAR_TYPE_CHARACTER, buffer, lnI + tnPrefixChars + tnPostfixChars);
					if (result)
					{
						// Reset everything
						memset(result->value.data_s8, 32, result->value.length);

						// Copy the radix content to its proper location in the prefix and postfix areas
						memcpy(result->value.data_s8 + tnPrefixChars, buffer, lnI);
					}


			} else {
				// Nope.  No, sir.  Uh uh.
				result = NULL;
			}


		//////////
		// Indicate our result
		//////
			return(result);
	}




//////////
//
// Called to search the chain and find the indicated variable name.
//
// Note:  VJr does not require variables have names.  Also, their names can be duplicated.
//        This is by design and relates to the data-driven model of its internal engine,
//        rather than a name-driven model.  However, names are still used nearly everywhere. :-)
//
//////
	SVariable* iVariable_searchForName(SVariable* varRoot, s8* tcVarName, u32 tnVarNameLength, SComp* comp)
	{
		SVariable*	var;
		SComp*		compNext;
		SComp*		compNext2;


		// Make sure our environment is sane
		var = NULL;
		if (varRoot)
		{
			// Iterate from beginning through
			var = varRoot;
			while (var)
			{
				// Is the name the same length?  And if so, does it match?
				if (var->name.length == (s32)tnVarNameLength && _memicmp(tcVarName, var->name.data, tnVarNameLength) == 0)
				{
					// This is the name, but for certain types we can reference sub-properties below
					switch (var->varType)
					{
						case _VAR_TYPE_OBJECT:
							// If the next component is a ., and the one after that is an alpha or alphanumeric, then they are referencing an object property
							if ((compNext = (SComp*)comp->ll.next) && compNext->iCode == _ICODE_DOT && (compNext2 = (SComp*)compNext->ll.next) && (compNext2->iCode == _ICODE_ALPHA || compNext2->iCode == _ICODE_ALPHANUMERIC))
							{
								// We've found something like "lo." where lo is an object, and there is a name reference after it
								var = iObj_getPropertyAsVariable(var->obj, compNext2->line->sourceCode->data + compNext2->start, compNext2->length, compNext2);
							}
							// If we get here, then they did not have a "." after the the object reference, and are referencing the object directly
							break;

						case _VAR_TYPE_THISCODE:
							// They could be referencing a variable from that location
							if ((compNext = (SComp*)comp->ll.next) && compNext->iCode == _ICODE_DOT)
							{
								// We've found something like "fred." where fred is a thisCode, and there is a name reference after it
// TODO:  We need to search the thisCode object for the indicated name
debug_break;
							}
							// If we get here, then they did not have a "." after the thisCode reference, and are referencing it directly
							break;
					}
					// If we get here, this is our variable
					return(var);
				}

				// Move to next variable
				var = (SVariable*)var->ll.next;
			}
		}

		// Indicate our status
		return(var);
	}




//////////
//
// Called to 
//
//////
	bool iVariable_setDefaultVariableValue(s32 tnVarType)
	{
		SVariable* varDefaultValue;


		// Set the indicated type
		if (iVariable_isVarTypeValid(tnVarType, &varDefaultValue))
		{
			if (gsCurrentSetting->_set_initializeDefault != tnVarType)
			{
				// Indicate our current default variable type
				gsCurrentSetting->_set_initializeDefault = tnVarType;

				// Set the new value
				if (varDefaultValue)		gsCurrentSetting->varInitializeDefault_value = iVariable_copy(varDefaultValue, false);
				else						gsCurrentSetting->varInitializeDefault_value = iVariable_create(tnVarType, NULL);
			}

			// Indicate success
			return(true);
		}

		// Indicate failure
		return(false);
	}




//////////
//
// Called to create all of the default variable values
//
//////
	void iVariable_createDefaultValues(void)
	{
		varDefault_null			= iVariable_create(_VAR_TYPE_NULL,		NULL);
		varDefault_numeric		= iVariable_create(_VAR_TYPE_NUMERIC,	NULL);
		varDefault_s32			= iVariable_create(_VAR_TYPE_S32,		NULL);
		varDefault_u32			= iVariable_create(_VAR_TYPE_U32,		NULL);
		varDefault_f32			= iVariable_create(_VAR_TYPE_F32,		NULL);
		varDefault_s64			= iVariable_create(_VAR_TYPE_S64,		NULL);
		varDefault_u64			= iVariable_create(_VAR_TYPE_U64,		NULL);
		varDefault_f64			= iVariable_create(_VAR_TYPE_F64,		NULL);
		varDefault_date			= iVariable_create(_VAR_TYPE_DATE,		NULL);
		varDefault_datetime		= iVariable_create(_VAR_TYPE_DATETIME,	NULL);
		varDefault_currency		= iVariable_create(_VAR_TYPE_CURRENCY,	NULL);
		varDefault_s16			= iVariable_create(_VAR_TYPE_S16,		NULL);
		varDefault_u16			= iVariable_create(_VAR_TYPE_U16,		NULL);
		varDefault_s8			= iVariable_create(_VAR_TYPE_S8,		NULL);
		varDefault_u8			= iVariable_create(_VAR_TYPE_U8,		NULL);
		varDefault_logical		= iVariable_create(_VAR_TYPE_LOGICAL,	NULL);
		varDefault_bitmap		= iVariable_create(_VAR_TYPE_BITMAP,	NULL);
		varDefault_thiscode		= iVariable_create(_VAR_TYPE_THISCODE,	NULL);
	}




//////////
//
// Called to initialize all of the gsProps_master[] variables
//
//////
	void iVariable_createPropsMaster(void)
	{
		s32 lnI;


		for (lnI = 0; lnI < gsProps_masterSize; lnI++)
		{
			// Create the variable
// if (gsProps_master[lnI].varType == _VAR_TYPE_BITMAP)
// 	debug_break;
			gsProps_master[lnI].varInit = iVariable_create(gsProps_master[lnI].varType, NULL);

			// If a valid variable was created, initialize it to the static baseclass values
			if (gsProps_master[lnI].varInit)
			{
				// Give it its name
				iDatum_duplicate(&gsProps_master[lnI].varInit->name, gsProps_master[lnI].propName, gsProps_master[lnI].propLength);

				// Populate it
				switch (gsProps_master[lnI].varType)
				{
					case _VAR_TYPE_S8:
						*gsProps_master[lnI].varInit->value.data_s8 = gsProps_master[lnI]._s8;
						break;
					case _VAR_TYPE_S16:
						*gsProps_master[lnI].varInit->value.data_s16 = gsProps_master[lnI]._s16;
						break;
					case _VAR_TYPE_S32:
						*gsProps_master[lnI].varInit->value.data_s32 = gsProps_master[lnI]._s32;
						break;
					case _VAR_TYPE_S64:
						*gsProps_master[lnI].varInit->value.data_s64 = gsProps_master[lnI]._s64;
						break;
					case _VAR_TYPE_U8:
						*gsProps_master[lnI].varInit->value.data_u8 = gsProps_master[lnI]._u8;
						break;
					case _VAR_TYPE_U16:
						*gsProps_master[lnI].varInit->value.data_u16 = gsProps_master[lnI]._u16;
						break;
					case _VAR_TYPE_U32:
						*gsProps_master[lnI].varInit->value.data_u32 = gsProps_master[lnI]._u32;
						break;
					case _VAR_TYPE_U64:
						*gsProps_master[lnI].varInit->value.data_u64 = gsProps_master[lnI]._u64;
						break;
					case _VAR_TYPE_F32:
						*gsProps_master[lnI].varInit->value.data_f32 = gsProps_master[lnI]._f32;
						break;
					case _VAR_TYPE_F64:
						*gsProps_master[lnI].varInit->value.data_f64 = gsProps_master[lnI]._f64;
						break;

					case _VAR_TYPE_NULL:
						// NULL variables are not populated, but simply created
						break;

					case _VAR_TYPE_CHARACTER:
						iVariable_set_character(gsProps_master[lnI].varInit, gsProps_master[lnI]._u8p, -1);
						break;

					case _VAR_TYPE_BITMAP:
						if (gsProps_master[lnI]._bmp)		iVariable_set_bitmap(gsProps_master[lnI].varInit, gsProps_master[lnI]._bmp);
						else								iVariable_set_bitmap(gsProps_master[lnI].varInit, bmpNoImage);
						break;

					case _VAR_TYPE_LOGICAL:
						*gsProps_master[lnI].varInit->value.data_s8 = gsProps_master[lnI]._s8;
						break;

					case _VAR_TYPE_OBJECT:
						// Objects are not initialized at this time, but an object placeholder is created for later population
						break;

					default:
// TODO: Whatever type is added that's not defined above needs added
						debug_break;
				}

// Should never happen
if (!gsProps_master[lnI].varInit)
	debug_break;
			}
		}
	}




//////////
//
// Called to see if the indicated variable type is valid, and to obtain the
// associated default value for the variable type.
//
//////
	bool iVariable_isVarTypeValid(s32 tnVarType, SVariable** varDefaultValue)
	{
		SVariable* holder;


		// If they don't want the default value, just put it to a temporary holder
		if (!varDefaultValue)
			varDefaultValue = &holder;

		// What is the variable type they're testing?
		switch (tnVarType)
		{
			case _VAR_TYPE_NULL:
				*varDefaultValue = varDefault_null;
				break;

			case _VAR_TYPE_NUMERIC:
				*varDefaultValue = varDefault_numeric;
				break;

			case _VAR_TYPE_S32:
				*varDefaultValue = varDefault_s32;
				break;

			case _VAR_TYPE_U32:
				*varDefaultValue = varDefault_u32;
				break;

			case _VAR_TYPE_F32:
				*varDefaultValue = varDefault_f32;
				break;

			case _VAR_TYPE_S64:
				*varDefaultValue = varDefault_s64;
				break;

			case _VAR_TYPE_U64:
				*varDefaultValue = varDefault_u64;
				break;

			case _VAR_TYPE_F64:
				*varDefaultValue = varDefault_f64;
				break;

			case _VAR_TYPE_DATE:
				*varDefaultValue = varDefault_date;
				break;

			case _VAR_TYPE_DATETIME:
				*varDefaultValue = varDefault_datetime;
				break;

			case _VAR_TYPE_CURRENCY:
				*varDefaultValue = varDefault_currency;
				break;

			case _VAR_TYPE_S16:
				*varDefaultValue = varDefault_s16;
				break;

			case _VAR_TYPE_U16:
				*varDefaultValue = varDefault_u16;
				break;

			case _VAR_TYPE_S8:
				*varDefaultValue = varDefault_s8;
				break;

			case _VAR_TYPE_U8:
				*varDefaultValue = varDefault_u8;
				break;

			case _VAR_TYPE_LOGICAL:
				*varDefaultValue = varDefault_logical;
				break;

			case _VAR_TYPE_BITMAP:
				*varDefaultValue = varDefault_bitmap;
				break;

			case _VAR_TYPE_THISCODE:
				*varDefaultValue = varDefault_thiscode;
				break;

			default:
				return(false);;
		}
		// Indicate success
		return(true);
	}




//////////
//
// Are the two variable types comparable?  This function is used to relate numeric forms
// which can be in a wide variety of internal storage mechanisms, but are all still numeric.
//
//////
	bool iVariable_areTypesCompatible(SVariable* var1, SVariable* var2)
	{
		if (var1 && var2)
		{
			// Are they the same?  If so, they're compatible. :-)
			if (var1->varType == var2->varType)
				return(true);

			// Are they both numeric?
			if (iVariable_isTypeNumeric(var1) && iVariable_isTypeNumeric(var2))
				return(true);

			// Are they all logical

			// If we get here, they're not compatible
		}

		// Indicate failure
		return(false);
	}




//////////
//
// Called to replace the varDst with the varSrc.
//
//////
	bool iVariable_copy(SVariable* varDst, SVariable* varSrc)
	{
		bool llResult;


		// Make sure our environment is sane
		llResult = false;
		if (varDst && varSrc)
		{
			//////////
			// Make sure we're dealing with the actual variable
			//////
				varDst = iiVariable_terminateIndirect(varDst);
				varSrc = iiVariable_terminateIndirect(varSrc);


			//////////
			// Are they being goofballs?
			//////
				if (varDst == varSrc)
					return(true);	// Yes


			//////////
			// Delete the existing variable contents
			//////
				iVariable_delete(varDst, false);


			//////////
			// Make the contents of varDst be that of varSrc
			//////
				varDst->varType = varSrc->varType;
				switch (varSrc->varType)
				{
					case _VAR_TYPE_NULL:
						// Nothing is allocated
						break;

					case _VAR_TYPE_THISCODE:
						// Indirect references only
						varDst->indirect = varSrc;
						iDatum_duplicate(&varDst->value, &varSrc->value);
						break;

					default:
						// Copy whatever content is there
						varDst->isValueAllocated = true;

						// If it's an object or bitmap, we need to make a real copy
						switch (varSrc->varType)
						{
							case _VAR_TYPE_OBJECT:
								// Copy the object
								varDst->obj = iObj_copy(varSrc->obj, NULL, NULL, true, true);
								break;

							case _VAR_TYPE_BITMAP:
								// Copy the bitmap
								varDst->bmp = iBmp_copy(varSrc->bmp);
								break;

							default:
								iDatum_duplicate(&varDst->value, &varSrc->value);
								break;
						}
				}

				// Indicate success
				return(true);
		}

		// Indicate our status
		return(llResult);
	}




//////////
//
// Called to copy the variable to a new variable
//
//////
	SVariable* iVariable_copy(SVariable* varSrc, bool tlMakeReference)
	{
		SVariable* varDst;


		// De-reference the variable
		varSrc = iiVariable_terminateIndirect(varSrc);

		// Are we still valid?
		if (varSrc)
		{
			// Should we create a real variable? Or a reference?
			if (tlMakeReference)
			{
				// Just create a reference to the variable
				varDst = iVariable_create(varSrc->varType, varSrc);

			} else {
				// Create a new real variable, a full copy of the original
				varDst = iVariable_create(varSrc->varType, NULL);
				iVariable_copy(varDst, varSrc);
			}

			// Success or failure ... it's in the allocation
			return(varDst);

		} else {
			// Failure
			return(NULL);
		}
	}




//////////
//
// Called to set the variable to the value of the other variable
//
//////
	bool iVariable_set(SVariable* varDst, SVariable* varSrc)
	{
		// De-reference the variable
		varDst = iiVariable_terminateIndirect(varDst);
		varSrc = iiVariable_terminateIndirect(varSrc);

		// Are we still valid?
// TODO:  Need to check the variable type before performing the varDst->value test
		if (varDst && varSrc && varDst->value.data && varSrc->value.data && varDst->varType != _VAR_TYPE_NULL && varSrc->varType != _VAR_TYPE_NULL)
		{
			// See if they're the same type
			if (varDst->varType == varSrc->varType && varDst->value.length == varSrc->value.length)
			{
				// They are the same, so we can do a direct copy
				switch (varDst->value.length)
				{
					case 1:		// Do a fast copy
						*varDst->value.data_u8 = *varSrc->value.data_u8;
						break;

					case 2:		// Do a fast copy
						*varDst->value.data_u16 = *varSrc->value.data_u16;
						break;

					case 4:		// Do a fast copy
						*varDst->value.data_u32 = *varSrc->value.data_u32;
						break;

					default:	// Do a full copy
						memcpy(varDst->value.data, varSrc->value.data, varDst->value.length);
						break;
				}

			} else {
				// Copy the content the long way
				iVariable_copy(varDst, varSrc);
			}

			// Success
			return(true);

		} else {
			// Failure
			iEngine_error(_ERROR_VARIABLE_NOT_FOUND, ((varDst) ? varDst : varSrc));
			return(false);
		}
	}




//////////
//
// Called to set the value to an s32 value
//
//////
	bool iVariable_set_s32(SVariable* var, s32 value)
	{
		// De-reference the variable
		var = iiVariable_terminateIndirect(var);

		// Are we still valid?
		if (var && var->varType == _VAR_TYPE_S32 && var->value.data_s32)
		{
			// Set it
			*var->value.data_s32 = value;

			// Success
			return(true);

		} else {
			// Failure
			return(false);
		}
	}




//////////
//
// Called to set the value to a u32 value
//
//////
	bool iVariable_set_u32(SVariable* var, u32 value)
	{
		// De-reference the variable
		var = iiVariable_terminateIndirect(var);

		// Are we still valid?
		if (var && var->varType == _VAR_TYPE_U32 && var->value.data_u32)
		{
			// Set it
			*var->value.data_u32 = value;

			// Success
			return(true);

		} else {
			// Failure
			return(false);
		}
	}




//////////
//
// Called to set the value to a f32 value
//
//////
	bool iVariable_set_f32(SVariable* var, f32 value)
	{
		// De-reference the variable
		var = iiVariable_terminateIndirect(var);

		// Are we still valid?
		if (var && var->varType == _VAR_TYPE_F32 && var->value.data_f32)
		{
			// Set it
			*var->value.data_f32 = value;

			// Success
			return(true);

		} else {
			// Failure
			return(false);
		}
	}




//////////
//
// Called to set the value to a f64 value
//
//////
	bool iVariable_set_f64(SVariable* var, f64 value)
	{
		// De-reference the variable
		var = iiVariable_terminateIndirect(var);

		// Are we still valid?
		if (var && var->varType == _VAR_TYPE_F64 && var->value.data_f64)
		{
			// Set it
			*var->value.data_f64 = value;

			// Success
			return(true);

		} else {
			// Failure
			return(false);
		}
	}




//////////
//
// Called to set the bool value
//
//////
	bool iVariable_set_logical(SVariable* var, bool tlValue)
	{
		// Translate bool to logical true or false
		return(iVariable_set_logical(var, ((tlValue) ? _LOGICAL_TRUE : _LOGICAL_FALSE)));
	}

	bool iVariable_set_logical(SVariable* var, s32 value)
	{
		// De-reference the variable
		var = iiVariable_terminateIndirect(var);

		// Are we still valid?
		if (var && var->varType == _VAR_TYPE_LOGICAL && var->value.data_s8)
		{
			// Set it
			*var->value.data_s8 = (s8)value;

			// Success
			return(true);

		}

		// Failure
		return(false);
	}




//////////
//
// Called to set the bitmap value for the indicated variable
//
//////
	bool iVariable_set_bitmap(SVariable* var, SBitmap* bmp)
	{
		// Make sure the environment is sane
		if (var && bmp)
		{
			// De-reference the variable
			var = iiVariable_terminateIndirect(var);

			// Are we still valid?
			if (var)
			{
				// Is the variable type already bitmap/
				if (var->varType != _VAR_TYPE_BITMAP)
				{
					// We need to refactor this variable into a bitmap
					// Delete the old contents
					iVariable_delete(var, false);

					// At this point, var->varType = _VAR_TYPE_NULL
					var->varType = _VAR_TYPE_BITMAP;

				} else {
					// Delete the old bitmap (if any)
					iBmp_delete(&var->bmp, true, true);
				}

				// Copy the bitmap to the destination
				var->bmp = iBmp_copy(bmp);
				
				// Indicate success
				return(true);
			}
		}

		// If we get here, failure
		return(false);
	}




//////////
//
// Called to set the character value for the indicated variable
//
//////
	bool iVariable_set_character(SVariable* var, u8* tcData, u32 tnDataLength)
	{
		// Make sure our environment is sane
		if (var && tcData && tnDataLength != 0)
		{
			// De-reference the variable
			var = iiVariable_terminateIndirect(var);

			// Are we still valid?
			if (var)
			{
				// Is the variable type already character
				if (var->varType != _VAR_TYPE_CHARACTER)
				{
					// We need to refactor this variable into a character
					// Delete the old contents
					iVariable_delete(var, false);

					// At this point, var->varType = _VAR_TYPE_NULL
					var->varType = _VAR_TYPE_CHARACTER;

				} else {
					// Delete the old datum
					iDatum_delete(&var->value, false);
				}

				// Set the new value
				iDatum_duplicate(&var->value, tcData, tnDataLength);
			}
		}

		// If we get here, failure
		return(false);
	}

	bool iVariable_set_character(SVariable* var, SDatum* datum)
	{
		// Make sure our environment is sane
		if (var && datum)
		{
debug_break;
			// De-reference the variable
			var = iiVariable_terminateIndirect(var);

			// Are we still valid?
			if (var)
			{
				// Is the variable type already character
				if (var->varType != _VAR_TYPE_CHARACTER)
				{
					// We need to refactor this variable into a character
					// Delete the old contents
					iVariable_delete(var, false);

					// At this point, var->varType = _VAR_TYPE_NULL
					var->varType = _VAR_TYPE_CHARACTER;

				} else {
					// Delete the old datum
					iDatum_delete(&var->value, false);
				}

				// Set the new value
				iDatum_duplicate(&var->value, datum);
			}
		}

		// If we get here, failure
		return(false);
	}




//////////
//
// Reset the variables to their default types
//
//////
	void iVariable_reset(SVariable* var)
	{
		// De-reference the variable
		var = iiVariable_terminateIndirect(var);

		// Are we still valid?
		if (var)
		{
			switch (var->varType)
			{
				case _VAR_TYPE_NUMERIC:
					iDatum_duplicate(&var->value, cgc_defaultNumeric, sizeof(cgc_defaultNumeric) - 1);
					break;

				case _VAR_TYPE_CHARACTER:
					iDatum_delete(&var->value, false);
					break;

				case _VAR_TYPE_LOGICAL:
					var->value.data_s8[0] = _LOGICAL_FALSE;
					break;

				case _VAR_TYPE_S8:
				case _VAR_TYPE_U8:
					var->value.data_s8[0] = 0;
					break;

				case _VAR_TYPE_S16:
				case _VAR_TYPE_U16:
					*(u16*)var->value.data = 0;
					break;

				case _VAR_TYPE_F32:
				case _VAR_TYPE_S32:
				case _VAR_TYPE_U32:
				case _VAR_TYPE_OBJECT:
				case _VAR_TYPE_THISCODE:
					*(u32*)var->value.data = (u32)0;
					break;

				case _VAR_TYPE_F64:
				case _VAR_TYPE_S64:
				case _VAR_TYPE_U64:
				case _VAR_TYPE_CURRENCY:
					*(u64*)var->value.data = (u64)0;
					break;

				case _VAR_TYPE_DATE:
					iDatum_duplicate(&var->value, cgc_defaultDate, sizeof(cgc_defaultDate) - 1);
					break;

				case _VAR_TYPE_DATETIME:
				case _VAR_TYPE_DATETIMEX:
// Not yet supported
debug_break;
					break;

				case _VAR_TYPE_BI:
				case _VAR_TYPE_BFP:
// Not yet supported
debug_break;
					break;

				case _VAR_TYPE_ARRAY:
				case _VAR_TYPE_GUID8:
				case _VAR_TYPE_GUID16:
				case _VAR_TYPE_FIELD:
// Not yet supported
debug_break;
					break;
			}
		}
	}




//////////
//
// Converts the indicated variable to a form suitable for display.
//
//////
	SVariable* iVariable_convertForDisplay(SVariable* var)
	{
		s32			lnI, lnYearOffset;
		u32			lnYear, lnMonth, lnDay, lnHour, lnMinute, lnSecond, lnMillisecond;
		f64			lfValue64;
		SVariable*	varDisp;
		SDateTime*	dt;
		u8			buffer[64];
		s8			formatter[16];


		// Make sure our environment is sane
		varDisp = iVariable_create(_VAR_TYPE_CHARACTER, NULL);
		if (var && varDisp)
		{
			// Initialize
			memset(buffer, 0, sizeof(buffer));

			// Based on the type, convert to a form for display
			switch (var->varType)
			{
				case _VAR_TYPE_NUMERIC:
				case _VAR_TYPE_CHARACTER:
					// Numeric and character forms are already stored as text
					varDisp->isValueAllocated = true;
					iDatum_duplicate(&varDisp->value, &var->value);
					break;

				case _VAR_TYPE_S32:
					// Convert to integer form, then store text
					sprintf((s8*)buffer, "%d\0", *(s32*)var->value.data);
					varDisp->isValueAllocated = true;
					iDatum_duplicate(&varDisp->value, buffer, -1);
					break;

				case _VAR_TYPE_U32:
					// Convert to unsigned integer form, then store text
					sprintf((s8*)buffer, "%u\0", *(u32*)var->value.data);
					varDisp->isValueAllocated = true;
					iDatum_duplicate(&varDisp->value, buffer, -1);
					break;

				case _VAR_TYPE_U64:
					// Convert to unsigned integer form, then store text
					sprintf((s8*)buffer, "%I64u\0", *(u64*)var->value.data);
					varDisp->isValueAllocated = true;
					iDatum_duplicate(&varDisp->value, buffer, -1);
					break;

				case _VAR_TYPE_S64:
					// Convert to unsigned integer form, then store text
					sprintf((s8*)buffer, "%I64d\0", *(s64*)var->value.data);
					varDisp->isValueAllocated = true;
					iDatum_duplicate(&varDisp->value, buffer, -1);
					break;

				case _VAR_TYPE_S16:
					// Convert to integer form, then store text
					sprintf((s8*)buffer, "%d\0", (s32)*(s16*)var->value.data);
					varDisp->isValueAllocated = true;
					iDatum_duplicate(&varDisp->value, buffer, -1);
					break;

				case _VAR_TYPE_S8:
					// Convert to integer form, then store text
					sprintf((s8*)buffer, "%d\0", (s32)*(s8*)var->value.data);
					varDisp->isValueAllocated = true;
					iDatum_duplicate(&varDisp->value, buffer, -1);
					break;

				case _VAR_TYPE_U16:
					// Convert to unsigned integer form, then store text
					sprintf((s8*)buffer, "%u\0", (u32)*(u16*)var->value.data);
					varDisp->isValueAllocated = true;
					iDatum_duplicate(&varDisp->value, buffer, -1);
					break;

				case _VAR_TYPE_U8:
					// Convert to unsigned integer form, then store text
					sprintf((s8*)buffer, "%u\0", (u32)*(u8*)var->value.data);
					varDisp->isValueAllocated = true;
					iDatum_duplicate(&varDisp->value, buffer, -1);
					break;

				case _VAR_TYPE_F32:
					// Convert to floating point form, then store text after leading zeros
					sprintf(formatter, "%%020.%df\0", gsCurrentSetting->_set_decimals);
					sprintf((s8*)buffer, formatter, *(f32*)var->value.data);

					// Skip past leading zeros
					for (lnI = 0; buffer[lnI] == '0'; )
						++lnI;

					// Append its form
					varDisp->isValueAllocated = true;
					iDatum_duplicate(&varDisp->value, buffer + lnI, -1);
					break;

				case _VAR_TYPE_F64:
					// Convert to floating point form, then store text after leading zeros
					sprintf(formatter, "%%020.%dlf\0", gsCurrentSetting->_set_decimals);
					sprintf((s8*)buffer, formatter, *(f64*)var->value.data);

					// Skip past leading zeros
					for (lnI = 0; buffer[lnI] == '0'; )
						++lnI;

					// Append its form
					varDisp->isValueAllocated = true;
					iDatum_duplicate(&varDisp->value, buffer + lnI, -1);
					break;

				case _VAR_TYPE_BI:
// TODO:  BI needs coded
					varDisp->isValueAllocated = true;
					iDatum_duplicate(&varDisp->value, cgcBigInteger, -1);
					break;

				case _VAR_TYPE_BFP:
// TODO:  BFP needs coded
					varDisp->isValueAllocated = true;
					iDatum_duplicate(&varDisp->value, cgcBigFloatingPoint, -1);
					break;

				case _VAR_TYPE_DATE:
					// We can convert this from its text form into numeric if we're auto-converting
// TODO:  This needs to go into a DTOC() function
					// Prepare for our year
					if (gsCurrentSetting->_set_century)		lnYearOffset = 0;
					else									lnYearOffset = 2;

					// Based on type, convert
					switch (gsCurrentSetting->_set_date)
					{
						case _SET_DATE_MDY:
						case _SET_DATE_AMERICAN:		// mm/dd/yy
							memcpy(buffer + 0, var->value.data + 4, 2);
							buffer[2] = '/';
							memcpy(buffer + 3, var->value.data + 6, 2);
							buffer[5] = '/';
							memcpy(buffer + 6, var->value.data + lnYearOffset, 4 - lnYearOffset);
							break;

						case _SET_DATE_ANSI:			// yy.mm.dd
							memcpy(buffer + 0, var->value.data + 4, 2);
							buffer[2] = '.';
							memcpy(buffer + 3, var->value.data + 6, 2);
							buffer[5] = '.';
							memcpy(buffer + 6, var->value.data + lnYearOffset, 4 - lnYearOffset);
							break;

						case _SET_DATE_BRITISH:			// dd/mm/yy
						case _SET_DATE_FRENCH:			// dd/mm/yy
						case _SET_DATE_DMY:				// dd/mm/yy
							memcpy(buffer + 0, var->value.data + 6, 2);
							buffer[2] = '/';
							memcpy(buffer + 3, var->value.data + 4, 2);
							buffer[5] = '/';
							memcpy(buffer + 6, var->value.data + lnYearOffset, 4 - lnYearOffset);
							break;

						case _SET_DATE_GERMAN:			// dd.mm.yy
							memcpy(buffer + 0, var->value.data + 6, 2);
							buffer[2] = '.';
							memcpy(buffer + 3, var->value.data + 4, 2);
							buffer[5] = '.';
							memcpy(buffer + 6, var->value.data + lnYearOffset, 4 - lnYearOffset);
							break;

						case _SET_DATE_ITALIAN:			// dd-mm-yy
							memcpy(buffer + 0, var->value.data + 6, 2);
							buffer[2] = '-';
							memcpy(buffer + 3, var->value.data + 4, 2);
							buffer[5] = '-';
							memcpy(buffer + 6, var->value.data + lnYearOffset, 4 - lnYearOffset);
							break;

						case _SET_DATE_TAIWAN:			// yy/mm/dd
						case _SET_DATE_YMD:				// yy/mm/dd
						case _SET_DATE_JAPAN:			// yy/mm/dd
							memcpy(buffer + 0, var->value.data + lnYearOffset, 4 - lnYearOffset);
							buffer[4 - lnYearOffset] = '-';
							memcpy(buffer + 5 - lnYearOffset, var->value.data + 4, 2);
							buffer[7 - lnYearOffset] = '-';
							memcpy(buffer + 8 - lnYearOffset, var->value.data + 6, 2);
							break;

						case _SET_DATE_LONG:			// Dayofweek, Month dd, yyyy
							iDatum_duplicate(&varDisp->value, cgcFeatureNotYetSupported, -1);
							break;

						case _SET_DATE_SHORT:			// m/d/yy
							if (var->value.data[4] == '0')		memcpy(buffer + strlen(buffer), var->value.data + 5, 1);
							else								memcpy(buffer + strlen(buffer), var->value.data + 4, 2);

							buffer[strlen(buffer)] = '/';

							if (var->value.data[6] == '0')		memcpy(buffer + strlen(buffer), var->value.data + 7, 1);
							else								memcpy(buffer + strlen(buffer), var->value.data + 6, 2);

							buffer[strlen(buffer)] = '/';

							memcpy(buffer + strlen(buffer), var->value.data + lnYearOffset, 4 - lnYearOffset);
							break;

						case _SET_DATE_USA:				// mm-dd-yy
							memcpy(buffer + 0, var->value.data + 4, 2);
							buffer[2] = '-';
							memcpy(buffer + 3, var->value.data + 6, 2);
							buffer[5] = '-';
							memcpy(buffer + 6, var->value.data + lnYearOffset, 4 - lnYearOffset);
							break;
					}
					break;

				case _VAR_TYPE_LOGICAL:
					// Based on setting, display as indicated
					if (gsCurrentSetting->_set_logical == _LOGICAL_TF)
					{
						// True/False
						varDisp->isValueAllocated = true;
						if (var->value.data[0] == 0)		iDatum_duplicate(&varDisp->value, cgcFText, -1);
						else								iDatum_duplicate(&varDisp->value, cgcTText, -1);

					} else if (gsCurrentSetting->_set_logical == _LOGICAL_YN) {
						// Yes/No
						varDisp->isValueAllocated = true;
						if (var->value.data[0] == 0)		iDatum_duplicate(&varDisp->value, cgcNText, -1);
						else								iDatum_duplicate(&varDisp->value, cgcYText, -1);

					} else {
						// Up/Down
						var->isValueAllocated = true;
						if (var->value.data[0] == 0)		iDatum_duplicate(&varDisp->value, cgcDText, -1);
						else								iDatum_duplicate(&varDisp->value, cgcUText, -1);
					}
					break;

				case _VAR_TYPE_DATETIME:
					// Translate from encoded form to components, then assemble as MM/DD/YYYY HH:MM:SS AM/PM
// TODO:  We need to honor the _set_date settings.  For now we use MM/DD/YYYY HH:MM:SS.Mss
// TODO:  We need to add the AM/PM settings.  For now we just use military time.
					dt = (SDateTime*)var->value.data;
					iiVariable_computeYyyyMmDd_fromJulianDayNumber(dt->julian, &lnYear, &lnMonth, &lnDay);
					iiVariable_computeHhMmSsMss_fromf32(dt->seconds, &lnHour, &lnMinute, &lnSecond, &lnMillisecond);
					sprintf((s8*)buffer, "%02u/%02u/%04u %02u:%02u:%02u.%03u", lnMonth, lnDay, lnYear, lnHour, lnMinute, lnSecond, lnMillisecond);
					varDisp->isValueAllocated = true;
					iDatum_duplicate(&varDisp->value, buffer, -1);
					break;

				case _VAR_TYPE_CURRENCY:
					// Translate to f64, then use fixed 4 decimals
					lfValue64 = ((f64)*(s64*)var->value.data / 10000.0);
					sprintf((s8*)buffer, "%020.4lf\0", lfValue64);

					// Skip past leading zeros
					for (lnI = 0; buffer[lnI] == '0'; )
						++lnI;

					// Append its form
					varDisp->isValueAllocated = true;
					iDatum_duplicate(&varDisp->value, buffer + lnI, -1);
					break;
			}

		} else {
			// Nothing was defined.
			// Populate a ".null." variable display
			if (varDisp)
			{
				varDisp->isValueAllocated = true;
				iDatum_duplicate(&varDisp->value, cgcNullText, -1);
			}
		}

		// Indicate our status
		return(varDisp);
	}




//////////
//
// Called to delete the indicated variable
//
//////
	void iVariable_delete(SVariable* var, bool tlDeleteSelf)
	{
		// Make sure our environment is sane
		if (var)
		{
			//////////
			// Delete the name (if populated)
			//////
				if (tlDeleteSelf)
					iDatum_delete(&var->name, false);


			//////////
			// Do we need to delete this item?
			//////
				if (!var->indirect && var->isValueAllocated)
				{
					// We only delete the empty objects, or hard values
					switch (var->varType)
					{
						case _VAR_TYPE_OBJECT:
							// Delete the object
							iObj_delete(&var->obj, true, true, true);
							var->obj = NULL;
							break;

						case _VAR_TYPE_BITMAP:
							// Delete the bitmap
							iBmp_delete(&var->bmp, true, true);
							var->bmp = NULL;

						default:
							// Delete the datum
							if (var->isValueAllocated)
							{
								iDatum_delete(&var->value, false);
								memset(&var->value, 0, sizeof(SDatum));
							}
							break;
					}
					// Lower the value allocated flag
					var->isValueAllocated = false;
				}


			//////////
			// Remote the self if need be
			//////
				if (tlDeleteSelf)
				{
					// "Bye bye, Hathaway."
					iLl_deleteNode((SLL*)var, true);

				} else {
					// We just need to reset its values as this variable slot will persist
					var->varType = _VAR_TYPE_NULL;
				}
		}
	}




//////////
//
// Called to delete the variable, and if it has any other variables in the chain,
// to delete all of them
//
//////
	void iVariable_politelyDeleteChain(SVariable** root, bool tlDeleteSelf)
	{
		SVariable*		var;
		SLLCallback		cb;


		// Make sure our environment is sane
		if (root && *root)
		{
// TODO:  Untested code.  Breakpoint and examine.
// Remember var->isValueAllocated
debug_break;
			// Use the linked list functions, which will callback repeatedly for every entry
			var			= *root;
			cb._func	= (uptr)&iVariable_politelyDeleteChain_callback;

			// Mark the variables there empty
			if (tlDeleteSelf)
			{
				// Delete all of them, and reset the first
				cb.node	= (SLL*)var;
				iLl_deleteNodeChainWithCallback(&cb);
				*root	= NULL;

			} else {
				// We are only freeing everything after this
				// Delete the first one, but don't free it
				var = (SVariable*)iLl_deleteNode((SLL*)var, false);
				if (var)
				{
					// Delete the rest in the chain
					cb.node	= (SLL*)var;
					iLl_deleteNodeChainWithCallback(&cb);
				}
			}
		}
	}

	// Note:  cb->node is the SVariable* we're deleting
	void iVariable_politelyDeleteChain_callback(SLLCallback* cb)
	{
		// Delete this variable appropriately
		iVariable_delete((SVariable*)cb->node, false);
	}




//////////
//
// Called to return the value of the indicated variable as an s32 (signed 32-bit integer).
//
// Uses:
//		_set_autoConvert
//
//////
	s32 iiVariable_getAs_s32(SVariable* var, bool tlForceConvert, bool* tlError, u32* tnErrorNum)
	{
		s8		buffer[16];
		union {
			s8			lnValue_s8;
			s16			lnValue_s16;
			u8			lnValue_u8;
			u16			lnValue_u16;
			u32			lnValue_u32;
			s64			lnValue_s64;
			u64			lnValue_u64;
			f32			lnValue_f32;
			f64			lnValue_f64;
			SDateTime	dt;
		};


		*tlError	= false;
		*tnErrorNum	= 0;
		// Based on the type of variable it is, return the value
		switch (var->varType)
		{
			case _VAR_TYPE_NUMERIC:
				//////////
				// We can convert this from its text form into numeric, and if it's in the range of an s32 then we're good to go
				//////
					lnValue_s64 = _atoi64(var->value.data);
					if (lnValue_s64 > (s64)_s32_min && lnValue_s64 < (s64)_s32_max)
						return((s32)lnValue_s64);


				//////////
				// If we get here, it's not in range
				//////
					*tlError	= true;
					*tnErrorNum	= _ERROR_NUMERIC_OVERFLOW;
					return(0);


			case _VAR_TYPE_S32:
				//////////
				// We can directly return the value
				//////
					return(*(u32*)var->value.data);


			case _VAR_TYPE_U32:
				//////////
				// We can return the value after verifying it is not out of range for a 32-bit signed integer
				//////
					lnValue_u32 = *(u32*)var->value.data;
					if (lnValue_u32 <= (u32)_s32_max)
						return((s32)lnValue_u32);


				//////////
				// If we get here, it's not in range
				//////
					*tlError	= true;
					*tnErrorNum	= _ERROR_NUMERIC_OVERFLOW;
					return(0);


			case _VAR_TYPE_U64:
				//////////
				// We can return the value after verifying it is not out of range for a 32-bit signed integer
				//////
					lnValue_u64 = *(u64*)var->value.data;
					if (lnValue_u64 > (u64)_s32_max)
						return((s32)lnValue_u64);


				//////////
				// If we get here, it's not in range
				//////
					*tlError	= true;
					*tnErrorNum	= _ERROR_NUMERIC_OVERFLOW;
					return(0);


			case _VAR_TYPE_S64:
				//////////
				// We can return the value after verifying it is not out of range for a 32-bit signed integer
				//////
					lnValue_s64 = *(s64*)var->value.data;
					if (lnValue_s64 < (s64)_s32_min || lnValue_s64 > (s64)_s32_max)
						return((s32)lnValue_s64);


				//////////
				// If we get here, it's not in range
				//////
					*tlError	= true;
					*tnErrorNum	= _ERROR_NUMERIC_OVERFLOW;
					return(0);


			case _VAR_TYPE_S16:
				//////////
				// We can directly return the value after upsizing to 32-bits
				//////
					return((s32)*(s16*)var->value.data);


			case _VAR_TYPE_S8:
				//////////
				// We can directly return the value after upsizing to 32-bits
				//////
					return((s32)*(s8*)var->value.data);


			case _VAR_TYPE_U16:
				//////////
				// We can directly return the value after upsizing to 32-bits
				//////
					return((s32)*(u16*)var->value.data);


			case _VAR_TYPE_U8:
				//////////
				// We can directly return the value after upsizing to 32-bits
				//////
					return((s32)*(u8*)var->value.data);


			case _VAR_TYPE_F32:
				//////////
				// We can return the value after verifying it is not out of range for a 32-bit signed integer
				//////
					lnValue_f32 = *(f32*)var->value.data;
					if (lnValue_f32 < (f32)_s32_min || lnValue_f32 > (f32)_s32_max)
						return((s32)lnValue_f32);


				//////////
				// If we get here, it's not in range
				//////
					*tlError	= true;
					*tnErrorNum	= _ERROR_NUMERIC_OVERFLOW;
					return(0);


			case _VAR_TYPE_F64:
				//////////
				// We can return the value after verifying it is not out of range for a 32-bit signed integer
				//////
					lnValue_f64 = *(f64*)var->value.data;
					if (lnValue_f64 < (f64)_s32_min || lnValue_f64 > (f64)_s32_max)
						return((s32)lnValue_f64);


				//////////
				// If we get here, it's not in range
				//////
					*tlError	= true;
					*tnErrorNum	= _ERROR_NUMERIC_OVERFLOW;
					return(0);


			case _VAR_TYPE_BI:
// TODO:  BI needs coded
				break;

			case _VAR_TYPE_BFP:
// TODO:  BFP needs coded
				break;

			case _VAR_TYPE_CHARACTER:
				// We can convert it to s32 if autoconvert is on, or if it has been force converted
				if (tlForceConvert || gsCurrentSetting->_set_autoConvert)
				{
					//////////
					// We can convert this from its text form into numeric, and if it's in the range of an s32 then we're good to go
					//////
						lnValue_s64 = _atoi64(var->value.data);
						if (lnValue_s64 > (s64)_s32_min && lnValue_s64 < (s64)_s32_max)
							return((s32)lnValue_s64);


					//////////
					// If we get here, it's not in range
					//////
						*tlError	= true;
						*tnErrorNum	= _ERROR_NUMERIC_OVERFLOW;
						return(0);
				}
				// If we get here, an invalid variable type was encountered
				break;

			case _VAR_TYPE_DATE:
				// We can convert this from its text form into numeric if we're auto-converting
				if (tlForceConvert || gsCurrentSetting->_set_autoConvert)
				{
					//////////
					// Dates are stored internally in text form as YYYYMMDD.
					// This will produce an integer suitable for sorting, comparing, etc.
					//////
						buffer[8] = 0;
						memcpy(buffer, var->value.data, 8);
						lnValue_s64 = _atoi64(buffer);
						return((s32)lnValue_s64);
				}


			case _VAR_TYPE_LOGICAL:
				//////////
				// Convert this from its logiacl form into numeric
				//////
					if (var->value.data[0] == _LOGICAL_FALSE)	return(_LOGICAL_FALSE);
					else										return(_LOGICAL_TRUE);
				// If we get here, an invalid variable type was encountered


			case _VAR_TYPE_DATETIME:
				// We can convert it to s32 if autoconvert is on, or if it has been force converted
				if (tlForceConvert || gsCurrentSetting->_set_autoConvert)
				{
					//////////
					// We can convert this from its text form into numeric, and if it's in the range of an s32 then we're good to go
					//////
						lnValue_s64 = iiVariable_computeDatetimeDifference(var, _datetime_Jan_01_2000);
						if (lnValue_s64 > (s64)_s32_min && lnValue_s64 < (s64)_s32_max)
							return((s32)lnValue_s64);


					//////////
					// If we get here, it's not in range
					//////
						*tlError	= true;
						*tnErrorNum	= _ERROR_NUMERIC_OVERFLOW;
						return(0);
				}
				break;

			case _VAR_TYPE_CURRENCY:
				// We can convert it to s32 if autoconvert is on, or if it has been force converted
				if (tlForceConvert || gsCurrentSetting->_set_autoConvert)
				{
					//////////
					// We can return the value after verifying it is not out of range for a 32-bit signed integer
					//////
						lnValue_s64 = (*(s64*)var->value.data / 10000);
						if (lnValue_s64 < (s64)_s32_min || lnValue_s64 > (s64)_s32_max)
							return((s32)lnValue_s64);


					//////////
					// If we get here, it's not in range
					//////
						*tlError	= true;
						*tnErrorNum	= _ERROR_NUMERIC_OVERFLOW;
						return(0);
				}
				break;
		}

		// If we get here, we could not convert it
		*tlError	= true;
		*tnErrorNum	= _ERROR_NOT_NUMERIC;
		return(0);
	}




//////////
//
// Called to return the value of the indicated variable as an s64 (signed 64-bit integer).
//
// Uses:
//		_set_autoConvert
//
//////
	s64 iiVariable_getAs_s64(SVariable* var, bool tlForceConvert, bool* tlError, u32* tnErrorNum)
	{
		s8		buffer[16];
		union {
			s8			lnValue_s8;
			s16			lnValue_s16;
			u8			lnValue_u8;
			u16			lnValue_u16;
			u32			lnValue_u32;
			s64			lnValue_s64;
			u64			lnValue_u64;
			f32			lnValue_f32;
			f64			lnValue_f64;
			SDateTime	dt;
		};


		*tlError	= false;
		*tnErrorNum	= 0;
		// Based on the type of variable it is, return the value
		switch (var->varType)
		{
			case _VAR_TYPE_NUMERIC:
				//////////
				// We can convert this from its text form into numeric, and if it's in the range of an s32 then we're good to go
				//////
					return(_atoi64(var->value.data));


			case _VAR_TYPE_S32:
				//////////
				// We can directly return the value
				//////
					return((s64)*(u32*)var->value.data);


			case _VAR_TYPE_U32:
				//////////
				// We can return the value after verifying it is not out of range for a 32-bit signed integer
				//////
					return((s64)*(u32*)var->value.data);


			case _VAR_TYPE_U64:
				//////////
				// We can return the value after verifying it is not out of range for a 32-bit signed integer
				//////
					lnValue_u64 = *(u64*)var->value.data;
					if (lnValue_u64 <= (u64)_s64_max)
						return((s64)lnValue_u64);


				//////////
				// If we get here, it's not in range
				//////
					*tlError	= true;
					*tnErrorNum	= _ERROR_NUMERIC_OVERFLOW;
					return(0);


			case _VAR_TYPE_S64:
				//////////
				// We can return the value after verifying it is not out of range for a 32-bit signed integer
				//////
					return(*(s64*)var->value.data);


			case _VAR_TYPE_S16:
				//////////
				// We can directly return the value after upsizing to 32-bits
				//////
					return((s64)*(s16*)var->value.data);


			case _VAR_TYPE_S8:
				//////////
				// We can directly return the value after upsizing to 32-bits
				//////
					return((s64)*(s8*)var->value.data);


			case _VAR_TYPE_U16:
				//////////
				// We can directly return the value after upsizing to 32-bits
				//////
					return((s64)*(u16*)var->value.data);


			case _VAR_TYPE_U8:
				//////////
				// We can directly return the value after upsizing to 32-bits
				//////
					return((s64)*(u8*)var->value.data);


			case _VAR_TYPE_F32:
				//////////
				// We can return the value after verifying it is not out of range for a 32-bit signed integer
				//////
					lnValue_f32 = *(f32*)var->value.data;
					if (lnValue_f32 < (f32)_s64_min || lnValue_f32 > (f32)_s64_max)
						return((s64)lnValue_f32);


				//////////
				// If we get here, it's not in range
				//////
					*tlError	= true;
					*tnErrorNum	= _ERROR_NUMERIC_OVERFLOW;
					return(0);


			case _VAR_TYPE_F64:
				//////////
				// We can return the value after verifying it is not out of range for a 32-bit signed integer
				//////
					lnValue_f64 = *(f64*)var->value.data;
					if (lnValue_f64 < (f64)_s64_min || lnValue_f64 > (f64)_s64_max)
						return((s64)lnValue_f64);


				//////////
				// If we get here, it's not in range
				//////
					*tlError	= true;
					*tnErrorNum	= _ERROR_NUMERIC_OVERFLOW;
					return(0);


			case _VAR_TYPE_BI:
// TODO:  BI needs coded
				break;

			case _VAR_TYPE_BFP:
// TODO:  BFP needs coded
				break;

			case _VAR_TYPE_CHARACTER:
				// We can convert it to s32 if autoconvert is on, or if it has been force converted
				if (tlForceConvert || gsCurrentSetting->_set_autoConvert)
				{
					//////////
					// We can convert this from its text form into numeric
					//////
						return(_atoi64(var->value.data));
				}
				// If we get here, an invalid variable type was encountered
				break;

			case _VAR_TYPE_DATE:
				// We can convert this from its text form into numeric if we're auto-converting
				if (tlForceConvert || gsCurrentSetting->_set_autoConvert)
				{
					//////////
					// Dates are stored internally in text form as YYYYMMDD.
					// This will produce an integer suitable for sorting, comparing, etc.
					//////
						buffer[8] = 0;
						memcpy(buffer, var->value.data, 8);
						return(_atoi64(buffer));
				}


			case _VAR_TYPE_LOGICAL:
				// We can convert it to s32 if autoconvert is on, or if it has been force converted
				if (tlForceConvert || gsCurrentSetting->_set_autoConvert)
				{
					//////////
					// We can convert this from its text form into numeric, and if it's in the range of an s32 then we're good to go
					//////
						if (var->value.data[0] == 0)	return(0);
						else							return(1);
				}
				// If we get here, an invalid variable type was encountered


			case _VAR_TYPE_DATETIME:
				// We can convert it to s32 if autoconvert is on, or if it has been force converted
				if (tlForceConvert || gsCurrentSetting->_set_autoConvert)
				{
					//////////
					// We can convert this from its text form into numeric, and if it's in the range of an s32 then we're good to go
					//////
						return(iiVariable_computeDatetimeDifference(var, _datetime_Jan_01_2000));
				}
				break;

			case _VAR_TYPE_CURRENCY:
				// We can convert it to s32 if autoconvert is on, or if it has been force converted
				if (tlForceConvert || gsCurrentSetting->_set_autoConvert)
				{
					//////////
					// We can return the value after verifying it is not out of range for a 32-bit signed integer
					//////
						return((*(s64*)var->value.data / 10000));
				}
				break;
		}

		// If we get here, we could not convert it
		*tlError	= true;
		*tnErrorNum	= _ERROR_NOT_NUMERIC;
		return(0);
	}




//////////
//
// Called to return the value of the indicated variable as an f32 (32-bit floating point).
//
// Uses:
//		_set_autoConvert
//
//////
	f32 iiVariable_getAs_f32(SVariable* var, bool tlForceConvert, bool* tlError, u32* tnErrorNum)
	{
		s8		buffer[16];
		union {
			s8			lnValue_s8;
			s16			lnValue_s16;
			u8			lnValue_u8;
			u16			lnValue_u16;
			u32			lnValue_u32;
			s64			lnValue_s64;
			u64			lnValue_u64;
			f32			lnValue_f32;
			f64			lnValue_f64;
			SDateTime	dt;
		};


		*tlError	= false;
		*tnErrorNum	= 0;
		// Based on the type of variable it is, return the value
		switch (var->varType)
		{
			case _VAR_TYPE_NUMERIC:
				//////////
				// We can convert this from its text form into numeric, and if it's in the range of an s32 then we're good to go
				//////
					return((f32)_atoi64(var->value.data));


			case _VAR_TYPE_S32:
				//////////
				// We can directly return the value
				//////
					return((f32)*var->value.data_s32);


			case _VAR_TYPE_U32:
				//////////
				// We can return the value after verifying it is not out of range for a 32-bit signed integer
				//////
					return((f32)*var->value.data_u32);


			case _VAR_TYPE_U64:
				//////////
				// We can return the value after verifying it is not out of range for a 32-bit signed integer
				//////
					if (*var->value.data_u64 <= _s64_max)
						return((f32)*var->value.data_s64);
					
				//////////
				// If we get here, it's not in range
				//////
					*tlError	= true;
					*tnErrorNum	= _ERROR_NUMERIC_OVERFLOW;
					return(0);


			case _VAR_TYPE_S64:
				//////////
				// We can return the value after verifying it is not out of range for a 32-bit signed integer
				//////
					return((f32)*var->value.data_s64);


			case _VAR_TYPE_S16:
				//////////
				// We can directly return the value after upsizing to 32-bits
				//////
					return((f32)*var->value.data_s16);


			case _VAR_TYPE_S8:
				//////////
				// We can directly return the value after upsizing to 32-bits
				//////
					return((f32)*var->value.data_s8);


			case _VAR_TYPE_U16:
				//////////
				// We can directly return the value after upsizing to 32-bits
				//////
					return((f32)*var->value.data_u16);


			case _VAR_TYPE_U8:
				//////////
				// We can directly return the value after upsizing to 32-bits
				//////
					return((f32)*var->value.data_u8);


			case _VAR_TYPE_F32:
				//////////
				// We can return the value after verifying it is not out of range for a 32-bit signed integer
				//////
					return(*var->value.data_f32);


			case _VAR_TYPE_F64:
				//////////
				// We can return the value after verifying it is not out of range for a 32-bit signed integer
				//////
					lnValue_f64 = *(f64*)var->value.data;
					if (lnValue_f64 < (f64)_f32_min || lnValue_f64 > (f64)_f32_max)
						return((f32)lnValue_f64);


				//////////
				// If we get here, it's not in range
				//////
					*tlError	= true;
					*tnErrorNum	= _ERROR_NUMERIC_OVERFLOW;
					return(0);


			case _VAR_TYPE_BI:
// TODO:  BI needs coded
				break;

			case _VAR_TYPE_BFP:
// TODO:  BFP needs coded
				break;

			case _VAR_TYPE_CHARACTER:
				// We can convert it to s32 if autoconvert is on, or if it has been force converted
				if (tlForceConvert || gsCurrentSetting->_set_autoConvert)
				{
					//////////
					// We can convert this from its text form into numeric
					//////
						return((f32)_atoi64(var->value.data));
				}
				// If we get here, an invalid variable type was encountered
				break;

			case _VAR_TYPE_DATE:
				// We can convert this from its text form into numeric if we're auto-converting
				if (tlForceConvert || gsCurrentSetting->_set_autoConvert)
				{
					//////////
					// Dates are stored internally in text form as YYYYMMDD.
					// This will produce an integer suitable for sorting, comparing, etc.
					//////
						buffer[8] = 0;
						memcpy(buffer, var->value.data, 8);
						return((f32)_atoi64(buffer));
				}


			case _VAR_TYPE_LOGICAL:
				// We can convert it to s32 if autoconvert is on, or if it has been force converted
				if (tlForceConvert || gsCurrentSetting->_set_autoConvert)
				{
					//////////
					// We can convert this from its text form into numeric, and if it's in the range of an s32 then we're good to go
					//////
						if (var->value.data[0] == 0)	return(0.0f);
						else							return(1.0f);
				}
				// If we get here, an invalid variable type was encountered


			case _VAR_TYPE_DATETIME:
				// We can convert it to s32 if autoconvert is on, or if it has been force converted
				if (tlForceConvert || gsCurrentSetting->_set_autoConvert)
				{
					//////////
					// We can convert this from its text form into numeric, and if it's in the range of an s32 then we're good to go
					//////
						return((f32)iiVariable_computeDatetimeDifference(var, _datetime_Jan_01_2000));
				}
				break;

			case _VAR_TYPE_CURRENCY:
				// We can convert it to s32 if autoconvert is on, or if it has been force converted
				if (tlForceConvert || gsCurrentSetting->_set_autoConvert)
				{
					//////////
					// We can return the value after verifying it is not out of range for a 32-bit signed integer
					//////
						return((f32)(*(s64*)var->value.data / 10000));
				}
				break;
		}

		// If we get here, we could not convert it
		*tlError	= true;
		*tnErrorNum	= _ERROR_NOT_NUMERIC;
		return(0);
	}




//////////
//
// Called to return the value of the indicated variable as an f64 (64-bit floating point).
//
// Uses:
//		_set_autoConvert
//
//////
	f64 iiVariable_getAs_f64(SVariable* var, bool tlForceConvert, bool* tlError, u32* tnErrorNum)
	{
		s8		buffer[16];
		union {
			s8			lnValue_s8;
			s16			lnValue_s16;
			u8			lnValue_u8;
			u16			lnValue_u16;
			u32			lnValue_u32;
			s64			lnValue_s64;
			u64			lnValue_u64;
			f32			lnValue_f32;
			f64			lnValue_f64;
			SDateTime	dt;
		};


		*tlError	= false;
		*tnErrorNum	= 0;
		// Based on the type of variable it is, return the value
		switch (var->varType)
		{
			case _VAR_TYPE_NUMERIC:
				//////////
				// We can convert this from its text form into numeric, and if it's in the range of an s32 then we're good to go
				//////
					return((f64)_atoi64(var->value.data));


			case _VAR_TYPE_S32:
				//////////
				// We can directly return the value
				//////
					return((f64)*var->value.data_s32);


			case _VAR_TYPE_U32:
				//////////
				// We can return the value after verifying it is not out of range for a 32-bit signed integer
				//////
					return((f64)*var->value.data_u32);


			case _VAR_TYPE_U64:
				//////////
				// We can return the value after verifying it is not out of range for a 32-bit signed integer
				//////
					if (*var->value.data_u64 < _s64_max)
						return((f64)*var->value.data_s64);


				//////////
				// If we get here, we could not convert it
				//////
					*tlError	= true;
					*tnErrorNum	= _ERROR_NOT_NUMERIC;
					return(0);


			case _VAR_TYPE_S64:
				//////////
				// We can return the value after verifying it is not out of range for a 32-bit signed integer
				//////
					return((f64)*var->value.data_s64);


			case _VAR_TYPE_S16:
				//////////
				// We can directly return the value after upsizing to 32-bits
				//////
					return((f64)*var->value.data_s16);


			case _VAR_TYPE_S8:
				//////////
				// We can directly return the value after upsizing to 32-bits
				//////
					return((f64)*var->value.data_s8);


			case _VAR_TYPE_U16:
				//////////
				// We can directly return the value after upsizing to 32-bits
				//////
					return((f64)*var->value.data_u16);


			case _VAR_TYPE_U8:
				//////////
				// We can directly return the value after upsizing to 32-bits
				//////
					return((f64)*var->value.data_u8);


			case _VAR_TYPE_F32:
				//////////
				// We can return the value after verifying it is not out of range for a 32-bit signed integer
				//////
					return((f64)*var->value.data_f32);


			case _VAR_TYPE_F64:
				//////////
				// We can return the value after verifying it is not out of range for a 32-bit signed integer
				//////
					return(*var->value.data_f64);


			case _VAR_TYPE_BI:
// TODO:  BI needs coded
				break;

			case _VAR_TYPE_BFP:
// TODO:  BFP needs coded
				break;

			case _VAR_TYPE_CHARACTER:
				// We can convert it to s32 if autoconvert is on, or if it has been force converted
				if (tlForceConvert || gsCurrentSetting->_set_autoConvert)
				{
					//////////
					// We can convert this from its text form into numeric
					//////
						return((f64)_atoi64(var->value.data));
				}
				// If we get here, an invalid variable type was encountered
				break;

			case _VAR_TYPE_DATE:
				// We can convert this from its text form into numeric if we're auto-converting
				if (tlForceConvert || gsCurrentSetting->_set_autoConvert)
				{
					//////////
					// Dates are stored internally in text form as YYYYMMDD.
					// This will produce an integer suitable for sorting, comparing, etc.
					//////
						buffer[8] = 0;
						memcpy(buffer, var->value.data, 8);
						return((f64)_atoi64(buffer));
				}


			case _VAR_TYPE_LOGICAL:
				// We can convert it to s32 if autoconvert is on, or if it has been force converted
				if (tlForceConvert || gsCurrentSetting->_set_autoConvert)
				{
					//////////
					// We can convert this from its text form into numeric, and if it's in the range of an s32 then we're good to go
					//////
						if (var->value.data[0] == 0)	return(0.0);
						else							return(1.0);
				}
				// If we get here, an invalid variable type was encountered


			case _VAR_TYPE_DATETIME:
				// We can convert it to s32 if autoconvert is on, or if it has been force converted
				if (tlForceConvert || gsCurrentSetting->_set_autoConvert)
				{
					//////////
					// We can convert this from its text form into numeric, and if it's in the range of an s32 then we're good to go
					//////
						return((f64)iiVariable_computeDatetimeDifference(var, _datetime_Jan_01_2000));
				}
				break;

			case _VAR_TYPE_CURRENCY:
				// We can convert it to s32 if autoconvert is on, or if it has been force converted
				if (tlForceConvert || gsCurrentSetting->_set_autoConvert)
				{
					//////////
					// We can return the value after verifying it is not out of range for a 32-bit signed integer
					//////
						return((f64)(*(s64*)var->value.data / 10000));
				}
				break;
		}

		// If we get here, we could not convert it
		*tlError	= true;
		*tnErrorNum	= _ERROR_NOT_NUMERIC;
		return(0);
	}




//////////
//
// Called to get the value stored in the component as an s64.
// Note:  We simply process the component's content here.  No type checking.
// Note:  We expect that the component has been identified appropriately as a numeric type, and that
//        there is some character after which will cease its conversion, and thereby make it convert
//        without forcing a NULL in there at the end before converting.
//
//////
	s64 iiVariable_getCompAs_s64(SComp* comp)
	{
		return(_atoi64(comp->line->sourceCode->data + comp->start));
	}




//////////
//
// Computes the julian day number from a day, month, year.
// Algorithm used from:
//		https://en.wikipedia.org/wiki/Julian_day#Calculation
//
// Summary:
//	a = floor((14 - month) / 12)		Note:  Using 1 for both January and February, 0 for other months
//	y = year + 4800 - a
//	m = month + 12 * a - 3				Note:  Using 0 for March, 11 for February
//
// For Gregorian calendar dates:
//		jg = day + floor((153*m + 2) / 5) + (365 * y) + floor(y/4) - floor(y/100) + floor(y/400) - 32045
//		Note:  The value in VFP matches this calculation if the month adjustment notes are not performed above.
//
// For Julian calendar dates:
//		jj = day + floor((153*m + 2) / 5) + (365 * y) + floor(y/4) - 32083
//
// Input:
//		year		-- 1600..2400
//		month		-- 1..12
//		day			-- 1..31 (not validated, as this is an iiFunction)
//
// Returns:
//		julian		-- The julian day number
//
//////
	s32 iiVariable_julianDayNumber_fromYyyyMmDd(f32* tfJulianDayNumber, u32 year, u32 month, u32 day)
	{
		s32		monthAdjust1, monthAdjust2;
		f64		a, y, m;


		//////////
		// Adjust the months
		// Note:  To provide compatibility with VFP, we do not perform the month adjustments.
		//////
			monthAdjust1	= month;	// not performed:  ((month <= 2) ? 1 : 0);
			monthAdjust2	= month;	// not performed:  ((month == 3) ? 0 : ((month == 2) ? 11 : month));


		//////////
		// Compute a, y, m
		//////
			a = floor((14.0 - (f64)monthAdjust1) / 12.0);
			y = (f64)year + 4800.0 - a;
			m = (f64)monthAdjust2 + (12.0 * a) - 3.0;


		//////////
		// For Gregorian calendar dates (dates after October 15, 1582):
		//////
			*tfJulianDayNumber = (f32)((f64)day + 
									floor(((153.0 * m) + 2.0) / 5.0) + 
									(365.0 * y) +
									floor(y / 4.0) -
									floor(y / 100.0) +
									floor(y / 400.0) -
									32045.0);


// 		//////////
// 		// For Julian calendar dates (dates before October 15, 1582):
// 		//////
// 			*tfJulianDayNumber = (f32)((f64)day + 
// 									floor(((153.0 * m) + 2.0) / 5.0) + 
// 									(365.0 * y) +
// 									floor(y / 4.0) -
// 									32083.0);


		// Return the rounded result
		return((s32)*tfJulianDayNumber);
	}




//////////
//
// Computes the day, month, and year from a julian day number.
//
// Taken from:
//		http://stason.org/TULARC/society/calendars/2-15-1-Is-there-a-formula-for-calculating-the-Julian-day-nu.html
//
// Returns:
//		year		-- The year
//		month		-- The month
//		day			-- The day
//
//////
	void iiVariable_computeYyyyMmDd_fromJulianDayNumber(u32 tnJulianDayNumber, u32* year, u32* month, u32* day)
	{
		u32 a, b, c, d, e, m;

		a		= tnJulianDayNumber + 32044;
		b		= ((4 * a) + 3) / 146097;
		c		= a - ((b * 146097) / 4);
		d		= ((4 * c) + 3) / 1461;
		e		= c - ((1461 * d) / 4);
		m		= ((5 * e) + 2) / 153;
		*day	= e - (((153 * m) + 2) / 5) + 1;
		*month	= m + 3 - (12 * (m / 10));
		*year	= (b * 100) + d - 4800 + (m / 10);
	}




//////////
//
// Takes the number of seconds elapsed since midnight and computes the time.
//
//////
	void iiVariable_computeHhMmSsMss_fromf32(f32 tfSeconds, u32* hour, u32* minute, u32* second, u32* millisecond)
	{
		// Compute hour
		*hour			= (u32)tfSeconds / (60 * 60);
		tfSeconds		= tfSeconds - (f32)(*hour * 60 * 60);

		// Compute minute
		*minute			= (u32)tfSeconds / 60;
		tfSeconds		= tfSeconds - (f32)(*minute * 60);

		// Compute seconds
		*second			= (u32)tfSeconds;
		tfSeconds		= tfSeconds - (f32)*second;

		// Compute milliseconds
		*millisecond	= (u32)(tfSeconds * 999.0);
	}




//////////
//
// Called to compute the number of seconds between the two datetimes using the
// formula:  result = (dt1 - dt2).
//
//////
	s64 iiVariable_computeDatetimeDifference(SVariable* dtVar1, SVariable* dtVar2)
	{
		SDateTime*	dt1;
		SDateTime*	dt2;
		f64			diffJulian, diffSeconds;
		s64			result;


		//////////
		// Setup the pointers
		//////
			dt1 = (SDateTime*)dtVar1->value.data;
			dt2 = (SDateTime*)dtVar2->value.data;


		//////////
		// Compute the differences
		//////
// TODO:  This is not a proper algorithm for converting days into a floating point value.
// Note:  It needs to be hard computed using references.
			diffJulian	= (f64)((s64)dt1->julian - (s64)dt2->julian) * 365.25 * 24.0 * 60.0 * 60.0;
			diffSeconds	= (f64)(dt1->seconds - dt2->seconds) * 24.0 * 60.0 * 60.0;


		//////////
		// Compute the result
		//////
			result = (s64)(diffJulian + diffSeconds);


		//////////
		// Return the result truncated to nearest integer (nearest second)
		//////
			return(result);
	}




//////////
//
// Called to calculate if the indicated day number is appropriate for the month.
//
//////
	bool iVariable_isDayValidForDate(u32 year, u32 month, u32 day)
	{
		// The only valid days are 1..31
		if (day < 1 || day > 31)
			return(false);

		// Days 1..28 are always valid
		if (day <= 28)
			return(true);

		// Days 29 and 30 are valid in months all months except february
		if (day <= 30 && month != 2)
			return(true);

		// Day 31 is valid in jan, mar, may, jul, aug, oct, dec
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
			return(true);

		// If we're not in February at this point, it is a failure
		if (month == 4 || month == 6 || month == 9 || month == 11)
			return(false);

		// Now, for february we have to compute if we're in a leap year
		// Leap years occur every 4 years, except in century years, except for centuries evenly divisible by 400
		if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0) && day <= 29)
			return(true);		// We are in a leap year

		// If we get here, it's not a leap year
		return(false);
	}




//////////
//
// Called to set the op type.
//
//////
	bool iOp_setNull(SOp* op)
	{
		if (op)
		{
			op->opType = _OP_TYPE_NULL;
			return(true);
		}

		// If we get here, failure
		return(false);
	}

	bool iOp_setVariable_param(SOp* op, SVariable* var, bool isOpAllocated)
	{
		if (op)
		{
			op->variable		= var;
			op->opType			= _OP_TYPE_PARAM;
			op->isOpDataAllocated	= isOpAllocated;
			return(true);
		}

		// If we get here, failure
		return(false);
	}

	bool iOp_setVariable_local(SOp* op, SVariable* var, bool isOpAllocated)
	{
		if (op)
		{
			op->variable		= var;
			op->opType			= _OP_TYPE_LOCAL;
			op->isOpDataAllocated	= isOpAllocated;
			return(true);
		}

		// If we get here, failure
		return(false);
	}

	bool iOp_setVariable_scoped(SOp* op, SVariable* var, bool isOpAllocated)
	{
		if (op)
		{
			op->variable		= var;
			op->opType			= _OP_TYPE_SCOPED;
			op->isOpDataAllocated	= isOpAllocated;
			return(true);
		}

		// If we get here, failure
		return(false);
	}

	bool iOp_setVariable_return(SOp* op, SVariable* var, bool isOpAllocated)
	{
		if (op)
		{
			op->variable		= var;
			op->opType			= _OP_TYPE_RETURNS;
			op->isOpDataAllocated	= isOpAllocated;
			return(true);
		}

		// If we get here, failure
		return(false);
	}




//////////
//
// Called to delete anything on the op, and optionally the op itself.
//
//////
	void iOp_politelyDelete(SOp* op, bool tlDeleteSelf)
	{
		// Make sure our environment is sane
		if (op && op->isOpDataAllocated)
		{
			//////////
			// Is it something to delete?
			//////
				if (op->_opData != 0 && op->isOpDataAllocated)
				{
					// Based on the type, delete it appropriately
					switch (op->opType)
					{
						case _OP_TYPE_PARAM:
							iVariable_delete(op->param, true);
							break;

						case _OP_TYPE_LOCAL:
							iVariable_delete(op->local, true);
							break;

						case _OP_TYPE_SCOPED:
							iVariable_delete(op->scoped, true);
							break;

						case _OP_TYPE_RETURNS:
							iVariable_delete(op->returns, true);
							break;

						case _OP_TYPE_OBJECT:
							iObj_delete(&op->obj, true, true, true);
							break;

// These types are only referenced
						case _OP_TYPE_COMP:
						case _OP_TYPE_OTHER:
						case _OP_TYPE_FUNCTION:
							break;
					}
				}


			//////////
			// Delete self if need be
			//////
				if (tlDeleteSelf)
					free(op);
		}
	}




//////////
//
// Called to append an error to the indicated component
//
//////
	void iComp_appendError(SComp* comp, u32 tnErrorNum, cu8* tcMessage)
	{
		if (comp && comp->line)
			iLine_appendError(comp->line, tnErrorNum, tcMessage, comp->start, comp->length);
	}




//////////
//
// Called to append a warning to the indicated component
//
//////
	void iComp_appendWarning(SComp* comp, u32 tnWarningNum, cu8* tcMessage)
	{
		if (comp && comp->line)
			iLine_appendWarning(comp->line, tnWarningNum, tcMessage, comp->start, comp->length);
	}




//////////
//
// Called to report the indicated message 
//
//////
	void iComp_reportWarningsOnRemainder(SComp* comp, u32 tnWarningNum, cu8* tcMessage)
	{
		while (comp)
		{
			// Append the warning
			iComp_appendWarning(comp, tnWarningNum, ((tcMessage) ? tcMessage : (u8*)cgcUnspecifiedWarning));

			// Move to next component
			comp = (SComp*)comp->ll.next;
		}
	}




//////////
//
// Called to append an error the indicated source code line
//
//////
	void iLine_appendError(SLine* line, u32 tnErrorNum, cu8* tcMessage, u32 tnStartColumn, u32 tnLength)
	{
		if (line && line->compilerInfo)
		{
			iCompileNote_appendMessage(&line->compilerInfo->firstError, tnStartColumn, tnStartColumn + tnLength, tnErrorNum, tcMessage);
		}
	}




//////////
//
// Called to append a warning to the indicated source code line
//
//////
	void iLine_appendWarning(SLine* line, u32 tnWarningNum, cu8* tcMessage, u32 tnStartColumn, u32 tnLength)
	{
		if (line && line->compilerInfo)
		{
			iCompileNote_appendMessage(&line->compilerInfo->firstError, tnStartColumn, tnStartColumn + tnLength, tnWarningNum, tcMessage);
		}
	}




//////////
//
// Allocates an SCompiler structure.  Initializes it to all NULLs.
//
//////
	SCompiler* iCompiler_allocate(SLine* parent)
	{
		SCompiler* compilerNew;


		//////////
		// Allocate
		//////
			compilerNew = (SCompiler*)malloc(sizeof(SCompiler));


		//////////
		// Initialize
		//////
			if (compilerNew)
			{
				// Initialize
				memset(compilerNew, 0, sizeof(SCompiler));

				// Populate
				compilerNew->parent = parent;
			}


		//////////
		// Indicate our status
		//////
			return(compilerNew);
	}




//////////
//
// Called to delete the previous allocated compiler data
//
//////
	void iCompiler_delete(SCompiler** root, bool tlDeleteSelf)
	{
		SCompiler* compilerInfo;


		// Make sure our environment is sane
		if (root && *root)
		{
			// Grab the pointer
			compilerInfo = *root;

			// Delete the items here
			iCompileNote_removeAll(&compilerInfo->firstWarning);
			iCompileNote_removeAll(&compilerInfo->firstError);

			// Delete from regular components, and whitespaces
			iComps_deleteAll_byFirstComp(&compilerInfo->firstComp);
			iComps_deleteAll_byFirstComp(&compilerInfo->firstWhitespace);

			// Delete self if need be
			if (tlDeleteSelf)
			{
				*root = NULL;
				free(compilerInfo);
			}
		}
	}




//////////
//
// Called to create a new note
//
//////
	SCompileNote* iCompileNote_create(SCompileNote** noteRoot, u32 tnStart, u32 tnEnd, u32 tnNumber, cu8* tcMessage)
	{
		SCompileNote* note;


		// Create the new note
		note = (SCompileNote*)iLl_appendNewNodeAtEnd((SLL**)noteRoot, sizeof(SCompileNote));
		if (note)
		{
			// Initialize it
			memset(note, 0, sizeof(SCompileNote));

			// Populate it
			note->start		= tnStart;
			note->end		= tnEnd;
			note->number	= tnNumber;
			note->msg		= iDatum_allocate(tcMessage, -1);
		}

		// Indicate our status
		return(note);
	}



//////////
//
// Called to append a compiler note
//
//////
	SCompileNote* iCompileNote_appendMessage(SCompileNote** noteRoot, u32 tnStartColumn, u32 tnEndColumn, u32 tnNumber, cu8* tcMessage)
	{
		SCompileNote* noteNew;


		// Make sure our environment is sane
		noteNew = NULL;
		if (noteRoot && tcMessage)
		{
			// Create the new note
			noteNew = iCompileNote_create(noteRoot, tnStartColumn, tnEndColumn, tnNumber, tcMessage);
		}

		// Indicate our status
		return(noteNew);
	}




//////////
//
// Called to remove all compile notes in the chain
//
//////
	void iCompileNote_removeAll(SCompileNote** noteRoot)
	{
		// Make sure our environment is sane
		if (noteRoot && *noteRoot)
			iLl_deleteNodeChain((SLL**)noteRoot);
	}