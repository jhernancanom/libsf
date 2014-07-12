//////////
//
// /libsf/source/vjr/engine.cpp
//
//////
// Version 0.30
// Copyright (c) 2014 by Rick C. Hodgin
//////
// Last update:
//     Jul.05.2014
//////
// Change log:
//     Jul.05.2014 - Initial creation
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
//
// Called to execute a stand-alone command, such as from the command window.
//
//////
	bool iEngine_executeStandaloneCommand(SEditChain* line)
	{
		bool		llManufactured;
		SComp*		comp;
		SComp*		compNext;
		SComp*		compThird;
		SVariable*	var;
		SVariable*	varExisting;
		SVariable*	varText;


		// Make sure our environment is sane
		if (line && line->sourceCode && line->sourceCode->data && line->sourceCodePopulated > 0)
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
					return(false);		// Nothing to compile on this line


			//////////
			// Get the first component
			//////
				comp = line->compilerInfo->firstComp;


			//////////
			// If it's a line comment, we don't need to process it
			//////
				if (comp->iCode == _ICODE_COMMENT || comp->iCode == _ICODE_LINE_COMMENT)
					return(false);


			//////////
			// Perform natural source code fixups
			//////
				iComps_removeStartEndComments(line);		// Remove /* comments */
				iComps_fixupNaturalGroupings(line);			// Fixup natural groupings [_][aaa][999] becomes [_aaa999], [999][.][99] becomes [999.99], etc.
				iComps_removeWhitespaces(line);				// Remove whitespaces [use][whitespace][foo] becomes [use][foo]


			//////////
			// Translate sequences to known keywords
			//////
				iComps_translateToOthers(&cgcKeywordKeywords[0], line);
				if (!line->compilerInfo->firstComp)
					return(false);		// Nothing to compile on this line


			//////////
			// Based on the first keyword, process it
			//////
				comp		= line->compilerInfo->firstComp;
				compNext	= (SComp*)comp->ll.next;
				switch (comp->iCode)
				{
					case _ICODE_QUIT:
						// They want to quit
						iEditChainManager_saveToDisk(screenData,		(s8*)cgcScreenDataFilename);
						iEditChainManager_saveToDisk(commandHistory,	(s8*)cgcCommandHistoryFilename);
						PostQuitMessage(0);
						break;

					case _ICODE_CLEAR:
						// They want to clear the screen
						iEditChainManager_navigateTop(screenData, gobj_screen);
						iEditChainManager_deleteChain(&screenData, false);
						iWindow_render(gWinScreen);
						break;

					case _ICODE_QUESTION_MARK:
						// It is a "? something" command
						if (!compNext)
						{
							// Syntax error, expected "? something" got only "?"
							iEditChainManager_appendLine(screenData, (s8*)cgcSyntaxError, -1);
							iEditChainManager_navigateEnd(screenData, gobj_screen);
							iWindow_render(gWinScreen);
							return(false);

						} else {
							// It's a number, display it
							if (compNext->iCat == _ICAT_FUNCTION)
							{
								// It is something like "? func(x)"
								if (!(var = iEngine_getFunctionResult(compNext, llManufactured)))
								{
									// Unknown function, or parameters were not correct
									// In any case, the iEngine_getFunctionResult() has reported the error
									iEditChainManager_navigateEnd(screenData, gobj_screen);
									iWindow_render(gWinScreen);
									return(false);
								}

							} else if (compNext->iCat == _ICAT_GENERIC) {
								// It is something like "? k" or "? 29"
								if (!(var = iEngine_getVariableFromComponent(compNext, llManufactured)))
								{
									// Unknown parameter
									iError_report(cgcUnrecognizedParameter);
									iEditChainManager_navigateEnd(screenData, gobj_screen);
									iWindow_render(gWinScreen);
									return(false);
								}
							}
							// We have a variable we can display its contents
							varText = iVariable_convertForDisplay(var);

							// Add its contents to _screen
							iEditChainManager_appendLine(screenData, varText->value.data, varText->value.length);
							iEditChainManager_navigateEnd(screenData, gobj_screen);

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
								if (!(var = iEngine_getFunctionResult(compThird, llManufactured)))
								{
									// Unknown function, or parameters were not correct
									// In any case, the iEngine_getFunctionResult() has reported the error
									iEditChainManager_navigateEnd(screenData, gobj_screen);
									iWindow_render(gWinScreen);
									return(false);
								}

							} else if (compThird->iCat == _ICAT_GENERIC) {
								// It is something like "x = y" or "x = 29"
								if (!(var = iEngine_getVariableFromComponent(compThird, llManufactured)))
								{
									// Unknown parameter
									iError_report(cgcUnrecognizedParameter);
									iEditChainManager_navigateEnd(screenData, gobj_screen);
									iWindow_render(gWinScreen);
									return(false);
								}
							}

							// If we get here, we have the variable they're storing
							// Based on the name from comp, see if it's a variable we already possess
							varExisting = iVariable_searchForName(varGlobals, comp->line->sourceCode->data + comp->start, comp->length);
							if (varExisting)
							{
								// We are updating the value
								iVariable_copyVariable(varExisting, var);
								iVariable_delete(var, true);

							} else {
								// We are creating a new variable
								iDatum_duplicate(&var->name, comp->line->sourceCode->data + comp->start, comp->length);
								iLl_appendExistingNodeAtBeginning((SLL**)&varGlobals, (SLL*)var);
							}

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
// Called to obtain a variable from the component.  It will translate a literal
// into a variable, or if it's already a variable reference it will copy the
// reference.
//
//////
	SVariable* iEngine_getVariableFromComponent(SComp* comp, bool& tlManufactured)
	{
		SVariable*	var;
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
						return(var);


				case _ICODE_TRUE:
				case _ICODE_YES:
				case _ICODE_UP:
					// It's a .T. or some equivalent
					var					= iVariable_create(_VAR_TYPE_LOGICAL, NULL);
					tlManufactured		= true;
					var->value.data[0]	= _LOGICAL_TRUE;
					return(var);


				case _ICODE_FALSE:
				case _ICODE_NO:
				case _ICODE_DOWN:
					// It's a .F. or some equivalent
					var					= iVariable_create(_VAR_TYPE_LOGICAL, NULL);
					tlManufactured		= true;
					var->value.data[0]	= _LOGICAL_FALSE;
					return(var);


				case _ICODE_EXTRA:
					// It's a .X.
					var					= iVariable_create(_VAR_TYPE_LOGICAL, NULL);
					tlManufactured		= true;
					var->value.data[0]	= _LOGICALX_EXTRA;
					return(var);


				case _ICODE_YET_ANOTHER:
					// It's a .Y.
					var					= iVariable_create(_VAR_TYPE_LOGICAL, NULL);
					tlManufactured		= true;
					var->value.data[0]	= _LOGICALX_YET_ANOTHER;
					return(var);


				case _ICODE_ZATS_ALL_FOLKS:
					// It's a .X.
					var					= iVariable_create(_VAR_TYPE_LOGICAL, NULL);
					tlManufactured		= true;
					var->value.data[0]	= _LOGICALX_ZATS_ALL_FOLKS;
					return(var);


				case _ICODE_ALPHANUMERIC:
				case _ICODE_ALPHA:
					// It's some kind of text, could be a field or variable
					if (_set_variablesFirst)
					{
						// Searching variables first, field names last.
						if (var = iVariable_searchForName(varGlobals, comp->line->sourceCode->data + comp->start, comp->length))
						{
							// It was found in the global variables
							return(var);

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

						} else*/ if (var = iVariable_searchForName(varGlobals, comp->line->sourceCode->data + comp->start, comp->length)) {
							// It was found in the global variables
							return(var);
						}
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
		SFunctionList*	lfl;
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
// Called to obtain the parameters between the indicated parenthesis.
//
//////
	bool iiEngine_getParametersBetween(SComp* compLeftParen, u32* paramsFound, u32 requiredCount, u32 maxCount, SVariable** p1, SVariable** p2, SVariable** p3, SVariable** p4, SVariable** p5, SVariable** p6, SVariable** p7)
	{
		u32			lnParamCount;
		bool		llManufactured;
		SVariable*	var;
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
				if (compComma->iCode != _ICODE_COMMA && compComma->iCode != _ICODE_PARENTHESIS_RIGHT && lnParamCount > requiredCount)
				{
					// Comma expected error
					iError_reportByNumber(_ERROR_COMMA_EXPECTED, comp);
					return(NULL);
				}


			//////////
			// Derive whatever this is as a variable
			//////
				     if (lnParamCount == 1)		{	var = (*p1 = iEngine_getVariableFromComponent(comp, llManufactured));		}
				else if (lnParamCount == 2)		{	var = (*p2 = iEngine_getVariableFromComponent(comp, llManufactured));		}
				else if (lnParamCount == 3)		{	var = (*p3 = iEngine_getVariableFromComponent(comp, llManufactured));		}
				else if (lnParamCount == 4)		{	var = (*p4 = iEngine_getVariableFromComponent(comp, llManufactured));		}
				else if (lnParamCount == 5)		{	var = (*p5 = iEngine_getVariableFromComponent(comp, llManufactured));		}
				else if (lnParamCount == 6)		{	var = (*p6 = iEngine_getVariableFromComponent(comp, llManufactured));		}
				else if (lnParamCount == 7)		{	var = (*p7 = iEngine_getVariableFromComponent(comp, llManufactured));		}


			// Move to next component
			++lnParamCount;
			comp = (SComp*)compComma->ll.next;
		}

		// Indicate how many we found
		*paramsFound = --lnParamCount;

		// Indicate success
		return(lnParamCount >= requiredCount && lnParamCount <= maxCount);
	}
