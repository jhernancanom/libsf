//////////
//
// /libsf/source/vjr/source/engine.cpp
//
//////
// Version 0.54
// Copyright (c) 2014 by Rick C. Hodgin
//////
// Last update:
//     Jul.05.2014
//////
// Change log:
//     Jul.05.2014 - Initial creation
//////
//
// This document is released as Liberty Software under a Repeat License, as governed
// by the Public Benefit License v1.0 or later (PBL).
//
// The PBL is public domain license with a caveat:  self accountability unto God.
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
// Called to execute a stand-alone command, such as from the command window.
//
//////
	bool iEngine_executeStandaloneCommand(SLine* line)
	{
		bool		llManufactured;
		SComp*		comp;
		SComp*		compNext;
		SComp*		compThird;
		SVariable*	var;	// Ignore the GCC warning message here... I don't know why it's throwing a warning.  var is used correctly below.
		SVariable*	varExisting;
		SVariable*	varText;


		// Make sure our environment is sane
		if (line && line->sourceCode && line->sourceCode->data && line->sourceCode_populatedLength > 0)
		{
			//////////
			// Parse it
			//////
				comp = iEngine_parseSourceCodeLine(line);


			//////////
			// Do we have anything to do?
			//////
				if (!comp || comp->iCode == _ICODE_COMMENT || comp->iCode == _ICODE_LINE_COMMENT)
					return(false);


			//////////
			// Based on the first keyword, process it
			//////
				comp		= line->compilerInfo->firstComp;
				compNext	= (SComp*)comp->ll.next;
				switch (comp->iCode)
				{
					case _ICODE_QUIT:
						// They want to quit
						iVjr_shutdown();
						break;

					case _ICODE_CLEAR:
						// They want to clear the screen
						iSEM_navigateToTopLine(screenData, _screen);
						iSEM_deleteChain(&screenData, false);
						screen_editbox->isDirtyRender = true;
						iWindow_render(gWinJDebi, false);
						break;

					case _ICODE_QUESTION_MARK:
						// It is a "? something" command
						if (!compNext)
						{
							// Syntax error, expected "? something" got only "?"
							iSEM_appendLine(screenData, (s8*)cgcSyntaxError, -1, false);
							iSEM_navigateToEndLine(screenData, _screen);
							screen_editbox->isDirtyRender = true;
							iWindow_render(gWinJDebi, false);
							return(false);

						} else {
							// It's a number, display it
							if (compNext->iCat == _ICAT_FUNCTION)
							{
								// It is something like "? func(x)"
								var = iEngine_getFunctionResult(compNext, llManufactured);
								if (!var)
								{
									// Unknown function, or parameters were not correct
									// In any case, the iEngine_getFunctionResult() has reported the error
									screen_editbox->isDirtyRender |= iSEM_navigateToEndLine(screenData, _screen);
									iWindow_render(gWinJDebi, false);
									return(false);
								}

							} else if (compNext->iCat == _ICAT_GENERIC) {
								// It is something like "? k" or "? 29"
								var = iEngine_getVariableFromComponent(compNext, llManufactured);
								if (!var)
								{
									// Unknown parameter
									iError_report(cgcUnrecognizedParameter);
									screen_editbox->isDirtyRender |= iSEM_navigateToEndLine(screenData, _screen);
									iWindow_render(gWinJDebi, false);
									return(false);
								}
							}
							// We have a variable we can display its contents
							varText = iVariable_convertForDisplay(var);

							// Add its contents to _screen
							iSEM_appendLine(screenData, varText->value.data, varText->value.length, false);
							iSEM_navigateToEndLine(screenData, _screen);
							screen_editbox->isDirtyRender = true;
							iWindow_render(gWinJDebi, false);

							// Release the variable if it was manufactured
							iVariable_delete(varText, true);
							if (llManufactured)
								iVariable_delete(var, true);
						}
						break;

					default:
						if ((comp->iCode == _ICODE_ALPHA || comp->iCode == _ICODE_ALPHANUMERIC) && compNext && compNext->iCode == _ICODE_EQUAL_SIGN)
						{
							// It is an assignment
							compThird = (SComp*)compNext->ll.next;
							if (compThird->iCat == _ICAT_FUNCTION)
							{
								// It is something like "? func(x)"
								var = iEngine_getFunctionResult(compThird, llManufactured);
								if (!var)
								{
									// Unknown function, or parameters were not correct
									// In any case, the iEngine_getFunctionResult() has reported the error
									screen_editbox->isDirtyRender |= iSEM_navigateToEndLine(screenData, _screen);
									iWindow_render(gWinJDebi, false);
									return(false);
								}

							} else if (compThird->iCat == _ICAT_GENERIC) {
								// It is something like "x = y" or "x = 29"
								if (!(var = iEngine_getVariableFromComponent(compThird, llManufactured)))
								{
									// Unknown parameter
									iError_report(cgcUnrecognizedParameter);
									screen_editbox->isDirtyRender |= iSEM_navigateToEndLine(screenData, _screen);
									iWindow_render(gWinJDebi, false);
									return(false);
								}
							}

							// If we get here, we have the variable they're storing
							// Based on the name from comp, see if it's a variable we already possess
							varExisting = iVariable_searchForName(varGlobals, comp->line->sourceCode->data + comp->start, comp->length, comp);
							if (varExisting)
							{
								// We are updating the value
								iVariable_copy(varExisting, var);
								iVariable_delete(var, true);

							} else {
								// We are creating a new variable
								iDatum_duplicate(&var->name, comp->line->sourceCode->data + comp->start, comp->length);
								iLl_appendExistingNodeAtBeginning((SLL**)&varGlobals, (SLL*)var);
							}

						} else if (comp->iCode == _ICODE_DOT_VARIABLE) {
							// It's something like thisForm.
							debug_nop;

						} else {
							// Not a currently supported command
							return(false);
						}
				}
				// If we get here, we're good
				return(true);

		} else {
			// Failure
			return(false);
		}
	}




//////////
//
// Parse the source code line into VJr's fixed, known, component parts.
// This process does not process variables, table names, fields, etc.
//
//////
	SComp* iEngine_parseSourceCodeLine(SLine* line)
	{
		//////////
		// If we have existing compiler data, get rid of it
		//////
			if (line->compilerInfo)		iCompiler_delete(&line->compilerInfo, false);
			else						line->compilerInfo = iCompiler_allocate(line);		// Allocate a new one


		//////////
		// Parse out the line
		//////
			iComps_translateSourceLineTo(&cgcFundamentalSymbols[0], line);
			if (!line->compilerInfo->firstComp)
				return(NULL);		// Nothing to compile on this line

			// Remove whitespaces [use][whitespace][foo] becomes [use][foo]
			iComps_removeLeadingWhitespaces(line);


		//////////
		// If it's a line comment, we don't need to process it
		//////
			if (line->compilerInfo->firstComp && (line->compilerInfo->firstComp->iCode == _ICODE_COMMENT || line->compilerInfo->firstComp->iCode == _ICODE_LINE_COMMENT))
			{
				// Combine every item after this to a single comment
// TODO:  This algorithm will need to be changed so casks in comments show up graphically, rather than as raw text
				iComps_combineN(line->compilerInfo->firstComp, 99999, line->compilerInfo->firstComp->iCode, line->compilerInfo->firstComp->iCat, line->compilerInfo->firstComp->color);

				// Return the first component
				return(line->compilerInfo->firstComp);
			}


		//////////
		// Perform natural source code fixups
		//////
			iComps_removeStartEndComments(line);		// Remove /* comments */
			iComps_combineCasks(line);					// Replace [(|][alpha][|)] with [(|alpha|)]
			iComps_fixupNaturalGroupings(line);			// Fixup natural groupings [_][aaa][999] becomes [_aaa999], [999][.][99] becomes [999.99], etc.
			iComps_combineAdjacentDotForms(line);		// Fixup [thisForm][.][width] into [thisForm.width]
			iComps_removeWhitespaces(line);				// Remove all whitespaces after everything else was parsed [use][whitespace][foo] becomes [use][foo]


		//////////
		// Translate sequences to known keywords
		//////
			iComps_translateToOthers((SAsciiCompSearcher*)&cgcKeywordsVxb[0], line);


		//////////
		// Return the first component
		//////
			return(line->compilerInfo->firstComp);
	}




//////////
//
// Called to obtain a variable from the component.  It will translate a literal
// into a variable, or if it's already a variable reference it will copy the
// reference.
//
//////
	SVariable* iEngine_getVariableFromComponent(SComp* comp, bool& tlManufactured)
	{
		SVariable*	var;
		SVariable*	varCopy;
		s64			value;


//////////
// TODO:  We currently have no context as to what this relates to.
//        We need to pass something here so it can look to a function definition for parameters, locals, return variables
//////////
		// Make sure our environment is sane
		tlManufactured = false;
		if (comp)
		{
			switch (comp->iCode)
			{
				case _ICODE_NUMERIC:
					// It's a raw number
					// Grab its value
					value = iiVariable_getCompAs_s64(comp);


					//////////
					// Create and populate our output variable
					//////
						tlManufactured = true;
						if (value >= (s64)_s32_min && value <= (s64)_s32_max)
						{
							// Store as 32-bits
							var						= iVariable_create(_VAR_TYPE_S32, NULL);
							*(s32*)var->value.data	= (s32)value;

						} else {
							// Store as 64-bits
							var						= iVariable_create(_VAR_TYPE_S64, NULL);
							*(s64*)var->value.data	= value;
						}


					//////////
					// Return our result
					//////
						var->compRelated = comp;
						return(var);


				case _ICODE_TRUE:
				case _ICODE_YES:
				case _ICODE_UP:
					// It's a .T. or some equivalent
					var					= iVariable_create(_VAR_TYPE_LOGICAL, NULL);
					tlManufactured		= true;
					var->value.data[0]	= _LOGICAL_TRUE;
					var->compRelated	= comp;
					return(var);


				case _ICODE_FALSE:
				case _ICODE_NO:
				case _ICODE_DOWN:
					// It's a .F. or some equivalent
					var					= iVariable_create(_VAR_TYPE_LOGICAL, NULL);
					tlManufactured		= true;
					var->value.data[0]	= _LOGICAL_FALSE;
					var->compRelated	= comp;
					return(var);


				case _ICODE_EXTRA:
					// It's a .X.
					var					= iVariable_create(_VAR_TYPE_LOGICAL, NULL);
					tlManufactured		= true;
					var->value.data[0]	= _LOGICALX_EXTRA;
					var->compRelated	= comp;
					return(var);


				case _ICODE_YET_ANOTHER:
					// It's a .Y.
					var					= iVariable_create(_VAR_TYPE_LOGICAL, NULL);
					tlManufactured		= true;
					var->value.data[0]	= _LOGICALX_YET_ANOTHER;
					var->compRelated	= comp;
					return(var);


				case _ICODE_ZATS_ALL_FOLKS:
					// It's a .X.
					var					= iVariable_create(_VAR_TYPE_LOGICAL, NULL);
					tlManufactured		= true;
					var->value.data[0]	= _LOGICALX_ZATS_ALL_FOLKS;
					var->compRelated	= comp;
					return(var);


				case _ICODE_ALPHANUMERIC:
				case _ICODE_ALPHA:
					// It's some kind of text, could be a field or variable
					if (gsCurrentSetting->_set_variablesFirst)
					{
						// Searching variables first, field names last.
						if ((var = iVariable_searchForName(varGlobals, comp->line->sourceCode->data + comp->start, comp->length, comp)))
						{
							// It was found in the global variables

/* We do not have work areas setup yet, so we cannot search them. :-)
						} else if (var = iWorkarea_searchFieldName(comp->line->sourceCode->data + comp->start, comp->length)) {
							// It was found in a table field
							return(var);*/
						}

					} else {
						// Search field names first, variables last.
/*						if (var = iWorkarea_searchFieldName(comp->line->sourceCode->data + comp->start, comp->length))
						{
							// It was found in a table field
							return(var);

						} else*/ if ((var = iVariable_searchForName(varGlobals, comp->line->sourceCode->data + comp->start, comp->length, comp))) {
							// It was found in the global variables
						}
					}

					if (var)
					{
						// Create a copy of the variable
						if (var->varType == _VAR_TYPE_NULL)
						{
							// It's a null variable
							varCopy = iVariable_create(_VAR_TYPE_CHARACTER, NULL);
							iDatum_duplicate(&varCopy->value, cgcNullText, -1);

						} else if (var->varType == _VAR_TYPE_OBJECT) {
							// It's an object
							varCopy = iVariable_create(_VAR_TYPE_CHARACTER, NULL);
							iDatum_duplicate(&varCopy->value, cgcObjectText, -1);

						} else if (var->varType == _VAR_TYPE_THISCODE) {
							// It's a thisCode reference
							varCopy = iVariable_create(_VAR_TYPE_CHARACTER, NULL);
							iDatum_duplicate(&varCopy->value, cgcThisCodeText, -1);

						} else {
							// It's a traditional variable
							varCopy = iVariable_create(var->varType, NULL);
							iDatum_duplicate(&varCopy->value, &var->value);
						}
						varCopy->compRelated = comp;
						return(varCopy);
					}
					break;


				case _ICODE_SINGLE_QUOTED_TEXT:
				case _ICODE_DOUBLE_QUOTED_TEXT:		// It's quoted text
					//////////
					// Create our output variable
					//////
						var				= iVariable_create(_VAR_TYPE_CHARACTER, NULL);
						tlManufactured	= true;


					//////////
					// Populate
					//////
						iDatum_duplicate(&var->value, comp->line->sourceCode->data + comp->start + 1, comp->length - 2);


					//////////
					// Return our result
					//////
						var->compRelated = comp;
						return(var);


				default:
					// Unknown
					break;
			}
		}
		// If we get here, failure
		return(NULL);
	}




//////////
//
// Called to find the function, execute it, and return the result
//
//////
	SVariable* iEngine_getFunctionResult(SComp* comp, bool& tlManufactured)
	{
		u32				lnParamsFound;
		SFunctionData*	lfl;
		SVariable*		p1;
		SVariable*		p2;
		SVariable*		p3;
		SVariable*		p4;
		SVariable*		p5;
		SVariable*		p6;
		SVariable*		p7;
		SVariable*		result;
		SComp*			compLeftParen;
		
		
		// Make sure our environment is sane
		if (comp && (compLeftParen = (SComp*)comp->ll.next) && compLeftParen->iCode == _ICODE_PARENTHESIS_LEFT)
		{
			// Right now, we know we have something like:  xyz(

			// Iterate through each function for matches
			lfl = &gsKnownFunctions[0];
			while (lfl && lfl->_func != 0)
			{
				// Is this the named function?
				if (lfl->iCode == comp->iCode)
				{
					// We need to find the minimum number of parameters between)
					if (!iiEngine_getParametersBetween(compLeftParen, &lnParamsFound, lfl->requiredCount, lfl->parameterCount, &p1, &p2, &p3, &p4, &p5, &p6, &p7))
						return(NULL);

					// When we get here we found the correct number of parameters
					switch (lfl->parameterCount)
					{
						case 0:			// Zero parameters for this function
							result = lfl->func_0p();
							break;

						case 1:			// One parameter max
							result = lfl->func_1p(p1);
							break;

						case 2:			// Two parameters max
							result = lfl->func_2p(p1, p2);
							break;

						case 3:			// Two parameters max
							result = lfl->func_3p(p1, p2, p3);
							break;

						case 4:			// Two parameters max
							result = lfl->func_4p(p1, p2, p3, p4);
							break;

						case 5:			// Two parameters max
							result = lfl->func_5p(p1, p2, p3, p4, p5);
							break;

						case 6:			// Two parameters max
							result = lfl->func_6p(p1, p2, p3, p4, p5, p6);
							break;

						case 7:			// Two parameters max
							result = lfl->func_7p(p1, p2, p3, p4, p5, p6, p7);
							break;

						default:
							MessageBox(NULL, "Need to add more parameter functions to iEngine_getFunctionResult()", "VJr Programmer Error", MB_OK);
							return(NULL);
					}
					// We need to free anything that needs freed
					if (p1)		iVariable_delete(p1, true);
					if (p2)		iVariable_delete(p2, true);
					if (p3)		iVariable_delete(p3, true);
					if (p4)		iVariable_delete(p4, true);
					if (p5)		iVariable_delete(p5, true);
					if (p6)		iVariable_delete(p6, true);
					if (p7)		iVariable_delete(p7, true);

					// Indicate our return value
					return(result);
				}

				// Move to next function
				++lfl;
			}
		}
		return(NULL);
	}




//////////
//
// Called to find the indicated setter, and execute it if found
//
//////
	void iEngine_executeSetter(cs8* name, SVariable* varOld, SVariable* varNew)
	{
// TODO:  When the engine is developed and working, a found setter will suspend execution and branch to that location
	}




//////////
//
// Called to report the indicated error and relate it to the indicated variable (if any)
//
//////
	void iEngine_error(u32 tnErrorNumber, SVariable* varRelated)
	{
// TODO:  Report the error and relate the variable
	}




//////////
//
// Called to obtain the parameters between the indicated parenthesis.
//
//////
	bool iiEngine_getParametersBetween(SComp* compLeftParen, u32* paramsFound, u32 requiredCount, u32 maxCount, SVariable** p1, SVariable** p2, SVariable** p3, SVariable** p4, SVariable** p5, SVariable** p6, SVariable** p7)
	{
		u32			lnParamCount;
		bool		llManufactured;
		SComp*		comp;
		SComp*		compComma;


		// Initialize the parameters to null
		*p1 = NULL;
		*p2 = NULL;
		*p3 = NULL;
		*p4 = NULL;
		*p5 = NULL;
		*p6 = NULL;
		*p7 = NULL;

		// Begin to the thing to the right of the left parenthesis
		lnParamCount	= 1;
		comp			= (SComp*)compLeftParen->ll.next;
		while (comp && comp->iCode != _ICODE_PARENTHESIS_RIGHT)
		{
			//////////
			// See if we've gone over our limit
			//////
				if (lnParamCount > maxCount)
				{
					// Too many parameters
					iError_reportByNumber(_ERROR_TOO_MANY_PARAMETERS, comp);
					return(NULL);
				}

			//////////
			// The component after this must be a comma
			//////
				compComma = (SComp*)comp->ll.next;
				if (!compComma || (compComma->iCode != _ICODE_COMMA && compComma->iCode != _ICODE_PARENTHESIS_RIGHT && lnParamCount > requiredCount))
				{
					// Comma expected error
					iError_reportByNumber(_ERROR_COMMA_EXPECTED, comp);
					return(NULL);
				}


			//////////
			// Derive whatever this is as a variable
			//////
/*SVariable* var;*/
				     if (lnParamCount == 1)		{	/*var =*/ (*p1 = iEngine_getVariableFromComponent(comp, llManufactured));		}
				else if (lnParamCount == 2)		{	/*var =*/ (*p2 = iEngine_getVariableFromComponent(comp, llManufactured));		}
				else if (lnParamCount == 3)		{	/*var =*/ (*p3 = iEngine_getVariableFromComponent(comp, llManufactured));		}
				else if (lnParamCount == 4)		{	/*var =*/ (*p4 = iEngine_getVariableFromComponent(comp, llManufactured));		}
				else if (lnParamCount == 5)		{	/*var =*/ (*p5 = iEngine_getVariableFromComponent(comp, llManufactured));		}
				else if (lnParamCount == 6)		{	/*var =*/ (*p6 = iEngine_getVariableFromComponent(comp, llManufactured));		}
				else if (lnParamCount == 7)		{	/*var =*/ (*p7 = iEngine_getVariableFromComponent(comp, llManufactured));		}


			// Move to next component
			++lnParamCount;
			comp = (SComp*)compComma->ll.next;
		}

		// Indicate how many we found
		*paramsFound = --lnParamCount;

		// Indicate success
		return(lnParamCount >= requiredCount && lnParamCount <= maxCount);
	}




//////////
//
// Push a copy of the current settings onto the stack, and it to the current.
// If this is the first one, create it and initialize it to VJr defaults.
//
//////
	SSettings* iSettings_push(void)
	{
		SSettings*	lSettingsLast;


		// Is this the first one?
		if (!gsFirstSettings)
		{
			// Create the first entry
			gsCurrentSetting = (SSettings*)iLl_appendNewNodeAtEnd((SLL**)&gsFirstSettings, sizeof(SSettings));

			// Default settings
			gsCurrentSetting->_set_indexMetaData					= false;
			gsCurrentSetting->_set_honorBarriers					= true;
			gsCurrentSetting->_set_variablesFirst					= false;
			gsCurrentSetting->_set_autoConvert						= false;
			gsCurrentSetting->_set_caseSensitiveNames				= false;
			gsCurrentSetting->_set_caseSensitiveCompares			= true;
			gsCurrentSetting->_set_namingConventions				= false;
			gsCurrentSetting->_set_logical							= _LOGICAL_TF;
			gsCurrentSetting->_set_implicitParams					= false;
			gsCurrentSetting->_set_stickyParameters					= true;
			gsCurrentSetting->_set_tableEqualAssignments			= false;
			gsCurrentSetting->_set_tableObjects						= false;
			gsCurrentSetting->_set_sloppyPrinting					= false;
			iDatum_duplicate(&gsCurrentSetting->_set_languageTo, cgcEnglish, -1);
			gsCurrentSetting->_set_decimals							= 2;
			gsCurrentSetting->_set_date								= _SET_DATE_AMERICAN;
			gsCurrentSetting->_set_century							= true;
			gsCurrentSetting->_set_focus_highlight_pixels			= 4;
			gsCurrentSetting->_set_focus_highlight_border_pixels	= 0;

			// Default variable type for uninitialized variables
			iVariable_setDefaultVariableValue(_VAR_TYPE_LOGICAL);

		} else {
			// Add another copy
			lSettingsLast		= gsCurrentSetting;
			gsCurrentSetting	= (SSettings*)iLl_appendNewNodeAtEnd((SLL**)&gsFirstSettings, sizeof(SSettings));

			// Copy the last one over this one
			memcpy(gsCurrentSetting, lSettingsLast, sizeof(SSettings));

			// Create a copy of the default initialization variable for this level
			gsCurrentSetting->varInitializeDefault_value = NULL;
			iVariable_setDefaultVariableValue(gsCurrentSetting->_set_initializeDefault);
		}

		// Right now, we have our current stack level
		return(gsCurrentSetting);
	}




//////////
//
// Pop the current level off the settings stack.
//
//////
	SSettings* iSettings_pop(void)
	{
		// If there's one before this, we can pop
		if (gsCurrentSetting->ll.prev)
		{
			// Delete the initialization variable
			iVariable_delete(gsCurrentSetting->varInitializeDefault_value, true);

			// Delete the entire node
			iLl_deleteNode((SLL*)gsCurrentSetting, true);

			// Grab the last node
			gsCurrentSetting = (SSettings*)iLl_getLastNode((SLL*)gsFirstSettings);
		}

		// Indicate our current stack level
		return(gsCurrentSetting);
	}




//////////
//
// Called to delete the indicated breakpoint
//
//////
	void iBreakpoint_delete(SBreakpoint** breakpoint)
	{
		SBreakpoint* bp;


		// Make sure our environment is sane
		if (breakpoint && *breakpoint && (*breakpoint)->isUsed && 
			(uptr)*breakpoint >= (uptr)gBreakpoints->data && 
			(uptr)*breakpoint <= (uptr)gBreakpoints->data + gBreakpoints->populatedLength - sizeof(SBreakpoint))
		{
			// Get a local copy of our pointer
			bp = *breakpoint;

			// Reset the remote
			*breakpoint = NULL;

			// Delete the items as they are
			bp->isUsed = true;

			// Delete any source code for this breakpoint
			if (bp->executeCode)
				iSourceCode_delete(&bp->executeCode);
		}
	}




//////////
//
// Called to add a new breakpoint.  It only creates the entry and populates the type.
// For conditional breakpoints, or breakpoints with code they will need to be created
// and added manually by the code in the calling algorithm.
//
//////
	SBreakpoint* iBreakpoint_add(SBreakpoint** breakpoint, u32 tnType)
	{
		u32				lnI;
		SBreakpoint*	bp;


		// Make sure our environment is sane
		if (breakpoint)
		{
			//////////
			// Validate it's a known type
			//////
				switch (tnType)
				{
					case _BREAKPOINT_ALWAYS:
					case _BREAKPOINT_CONDITIONAL_TRUE:
					case _BREAKPOINT_CONDITIONAL_FALSE:
					case _BREAKPOINT_CONDITIONAL_TRUE_COUNTDOWN:
					case _BREAKPOINT_CONDITIONAL_FALSE_COUNTDOWN:
						break;

					default:
						// We don't know what to do here... silently fail
						return(NULL);
				}
				// If we get here, we're valid


			//////////
			// Make sure we've initialized our breakpoint structure
			//////
				if (!gBreakpoints)
					iBuilder_createAndInitialize(&gBreakpoints, -1);


			//////////
			// Try to find an empty slot
			//////
				for (lnI = 0; lnI < gBreakpoints->populatedLength; lnI += sizeof(SBreakpoint))
				{
					// Grab this pointer
					bp = (SBreakpoint*)(gBreakpoints->data + lnI);

					// Is this an empty slot?
					if (!bp->isUsed)
						break;	// Yes, we can reuse it
				}


			//////////
			// Allocate if we didn't find an empty slot
			//////
				if (lnI >= gBreakpoints->populatedLength)
					bp = (SBreakpoint*)iBuilder_allocateBytes(gBreakpoints, sizeof(SBreakpoint));


			//////////
			// Populate it with the basic info
			//////
				if (bp)
				{
					bp->isUsed	= true;
					bp->type	= tnType;
				}


			// Indicate our success or failure
			*breakpoint	= bp;
			return(bp);
		}

		// If we get here, failure
		return(NULL);
	}




//////////
//
// Called to delete the source code item
//
//////
	void iSourceCode_delete(SSourceCode** sourceCode)
	{
		SSourceCode* sc;


		// Make sure our environment is sane
		if (sourceCode && *sourceCode)
		{
			// Get a copy of the pointer
			sc = *sourceCode;

			// Clear the pointer
			*sourceCode = NULL;

			// Delete the items
			iFunction_politelyDeleteChain(&sc->firstFunction);
			iVariable_politelyDeleteChain(&sc->params,	true);
			iVariable_politelyDeleteChain(&sc->globals,	true);
			iVariable_politelyDeleteChain(&sc->locals,	true);
			iVariable_politelyDeleteChain(&sc->returns,	true);
			iVariable_politelyDeleteChain(&sc->scoped,	true);
		}
	}
