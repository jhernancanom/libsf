//////////
//
// /libsf/source/vjr/source/engine.cpp
//
//////
//    _     _ _     _____ _____ 
//   | |   (_) |__ / ____|  ___|
//   | |   | | '_ \\___ \|  __|
//   | |___| | |_) |___) | |
//   |_____|_|_.__/_____/|_|
//
//   Liberty Software Foundation
// and the Village Freedom Project
//   __     _______     ____  
//   \ \   / /  ___| __|  _ \ 
//    \ \ / /| |_ | '__| |_) |
//     \ V / |  _|| |  |  __/ 
//      \_/  |_|  |_|  |_|
//
//////
// Version 0.56
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
// Called to execute a stand-alone command, such as from the command window.
//
//////
	bool iEngine_executeStandaloneCommand(SThisCode* thisCode, SLine* line)
	{
		bool			llManufactured;
		SComp*			comp;
		SComp*			compNext;
		SComp*			compThird;
		SVariable*		var;	// Ignore the GCC warning message here... I don't know why it's throwing a warning.  var is used correctly below.
		SVariable*		varExisting;
		SVariable*		varText;
		SCommandData*	cmd;


		// Make sure our environment is sane
		if (line && line->sourceCode && line->sourceCode->data && line->sourceCode_populatedLength > 0)
		{
			//////////
			// Parse it
			//////
				comp = iEngine_parseSourceCodeLine(thisCode, line);


			//////////
			// Do we have anything to do?
			//////
				if (!comp || comp->iCode == _ICODE_COMMENT || comp->iCode == _ICODE_LINE_COMMENT)
					return(false);


			//////////
			// Based on the first keyword, process it
			//////
				comp		= line->compilerInfo->firstComp;
				compNext	= comp->ll.nextComp;
				switch (comp->iCode)
				{
					case _ICODE_QUIT:
						// They want to quit
						iVjr_shutdown(thisCode);
						break;
// 
// 					case _ICODE_CLEAR:
// 						// They want to clear the screen
// 						iSEM_navigateToTopLine(screenData, _screen);
// 						iSEM_deleteChain(&screenData, false);
// 						screen_editbox->isDirtyRender = true;
// 						iWindow_render(NULL, gWinJDebi, false);
// 						break;

					case _ICODE_QUESTION_MARK:
						// It is a "? something" command
						if (!compNext)
						{
							// Syntax error, expected "? something" got only "?"
							iSEM_appendLine(thisCode, screenData, (u8*)cgcSyntaxError, -1, false);
							iSEM_navigateToEndLine(thisCode, screenData, _screen);
							screen_editbox->isDirtyRender = true;
							iWindow_render(NULL, gWinJDebi, false);
							return(false);

						} else {
							// It's a number, display it
							if (compNext->iCat == _ICAT_FUNCTION)
							{
								// It is something like "? func(x)"
								llManufactured = true;
								var = iEngine_get_functionResult(thisCode, compNext);
								if (!var)
								{
									// Unknown function, or parameters were not correct
									// In any case, the iEngine_getFunctionResult() has reported the error
									screen_editbox->isDirtyRender |= iSEM_navigateToEndLine(thisCode, screenData, _screen);
									iWindow_render(NULL, gWinJDebi, false);
									return(false);
								}

							} else if (compNext->iCat == _ICAT_GENERIC) {
								// It is something like "? k" or "? 29"
								var = iEngine_get_variableName_fromComponent(thisCode, compNext, &llManufactured);
								if (!var)
								{
									// Unknown parameter
									iError_report(thisCode, cgcUnrecognizedParameter, false);
									screen_editbox->isDirtyRender |= iSEM_navigateToEndLine(thisCode, screenData, _screen);
									iWindow_render(NULL, gWinJDebi, false);
									return(false);
								}
							}
							// We have a variable we can display its contents
							varText = iVariable_convertForDisplay(NULL, var);

							// Add its contents to _screen
							iSEM_appendLine(thisCode, screenData, varText->value.data_u8, varText->value.length, false);
							iSEM_navigateToEndLine(thisCode, screenData, _screen);
							screen_editbox->isDirtyRender = true;
							iWindow_render(NULL, gWinJDebi, false);

							// Release the variable if it was manufactured
							iVariable_delete(NULL, varText, true);
							if (llManufactured)
								iVariable_delete(NULL, var, true);
						}
						break;

					default:
						if ((comp->iCode == _ICODE_ALPHA || comp->iCode == _ICODE_ALPHANUMERIC) && compNext && compNext->iCode == _ICODE_EQUAL_SIGN)
						{
							// It is an assignment
							compThird = compNext->ll.nextComp;
							if (compThird->iCat == _ICAT_FUNCTION)
							{
								// It is something like "? func(x)"
								var = iEngine_get_functionResult(thisCode, compThird);
								if (!var)
								{
									// Unknown function, or parameters were not correct
									// In any case, the iEngine_getFunctionResult() has reported the error
									screen_editbox->isDirtyRender |= iSEM_navigateToEndLine(thisCode, screenData, _screen);
									iWindow_render(NULL, gWinJDebi, false);
									return(false);
								}

							} else if (compThird->iCat == _ICAT_GENERIC) {
								// It is something like "x = y" or "x = 29"
								if (!(var = iEngine_get_variableName_fromComponent(thisCode, compThird, &llManufactured)))
								{
									// Unknown parameter
									iError_report(thisCode, cgcUnrecognizedParameter, false);
									screen_editbox->isDirtyRender |= iSEM_navigateToEndLine(thisCode, screenData, _screen);
									iWindow_render(NULL, gWinJDebi, false);
									return(false);
								}
							}

							// If we get here, we have the variable they're storing
							// Based on the name from comp, see if it's a variable we already possess
							varExisting = iVariable_searchForName(thisCode, comp->line->sourceCode->data + comp->start, comp->length, comp, true);
							if (varExisting)
							{
								// We are updating the value
								iVariable_copy(NULL, varExisting, var);
								iVariable_delete(NULL, var, true);

							} else {
								// We are creating a new variable
								iDatum_duplicate(&var->name, comp->line->sourceCode->data_u8 + comp->start, comp->length);
								iLl_appendExistingNodeAtBeginning((SLL**)&varGlobals, (SLL*)var);
							}

						} else if (comp->iCode == _ICODE_DOT_VARIABLE) {
							// It's something like thisForm.
							debug_nop;

						} else {
							// See if it's a known command
							for (cmd = &gsKnownCommands[0]; cmd->iCode != 0; cmd++)
							{
								// Is this our command?
								if (cmd->iCode == comp->iCode)
								{
									// Yes, execute it (self-contained execution and error reporting on every command)
									cmd->command(thisCode, comp);
									break;
								}
							}
							
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
	SComp* iEngine_parseSourceCodeLine(SThisCode* thisCode, SLine* line)
	{
		//////////
		// If we have existing compiler data, get rid of it
		//////
			if (line->compilerInfo)		iCompiler_delete(thisCode, &line->compilerInfo, false);
			else						line->compilerInfo = iCompiler_allocate(thisCode, line);		// Allocate a new one


		//////////
		// Parse out the line
		//////
			iComps_translateSourceLineTo(thisCode, &cgcFundamentalSymbols[0], line);
			if (!line->compilerInfo->firstComp)
				return(NULL);		// Nothing to compile on this line

			// Remove whitespaces [use][whitespace][foo] becomes [use][foo]
			iComps_removeLeadingWhitespaces(thisCode, line);


		//////////
		// If it's a line comment, we don't need to process it
		//////
			if (line->compilerInfo->firstComp && (line->compilerInfo->firstComp->iCode == _ICODE_COMMENT || line->compilerInfo->firstComp->iCode == _ICODE_LINE_COMMENT))
			{
				// Combine every item after this to a single comment
// TODO:  This algorithm will need to be changed so casks in comments show up graphically, rather than as raw text
				iComps_combineN(thisCode, line->compilerInfo->firstComp, 99999, line->compilerInfo->firstComp->iCode, line->compilerInfo->firstComp->iCat, line->compilerInfo->firstComp->color);

				// Return the first component
				return(line->compilerInfo->firstComp);
			}


		//////////
		// Perform natural source code fixups
		//////
			iComps_removeStartEndComments(thisCode, line);		// Remove /* comments */
			iComps_combineCasks(thisCode, line);				// Replace [(|][alpha][|)] with [(|alpha|)]
			iComps_fixupNaturalGroupings(thisCode, line);		// Fixup natural groupings [_][aaa][999] becomes [_aaa999], [999][.][99] becomes [999.99], etc.
			iComps_combineAdjacentDotForms(thisCode, line);		// Fixup [thisForm][.][width] into [thisForm.width]
			iComps_removeWhitespaces(thisCode, line);			// Remove all whitespaces after everything else was parsed [use][whitespace][foo] becomes [use][foo]


		//////////
		// Translate sequences to known keywords
		//////
			iComps_translateToOthers(thisCode, (SAsciiCompSearcher*)&cgcKeywordsVxb[0], line);


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
	SVariable* iEngine_get_variableName_fromComponent(SThisCode* thisCode, SComp* comp, bool* tlManufactured)
	{
		s32			lnI;
		s64			lnValue;
		f64			lfValue;
		bool		llDot;
		SVariable*	var;
		SVariable*	varCopy;


//////////
// TODO:  We currently have no context as to what this relates to.
//        We need to pass something here so it can look to a function definition for parameters, locals, return variables
//////////
		// Make sure our environment is sane
		if (!tlManufactured)
		{
			// This error should only exist during development when something is left off by the developer
			debug_break;
			return(NULL);
		}

		// Initially lower the flag
		*tlManufactured = false;
		if (comp)
		{
			switch (comp->iCode)
			{
				case _ICODE_NUMERIC:
					// It's a raw number
					// See if it has a dot/period in it
					for (lnI = 0, llDot = false; lnI < comp->length; lnI++)
					{
						if (comp->line->sourceCode->data[comp->start + lnI] == '.')
						{
							llDot = true;
							break;
						}
					}

					// Is it integer or floating point?
					if (!llDot)
					{
						// Integer
						lnValue = iiVariable_getCompAs_s64(comp);


						//////////
						// Create and populate our output variable
						//////
							*tlManufactured = true;
							if (lnValue >= (s64)_s32_min && lnValue <= (s64)_s32_max)
							{
								// Store as 32-bits
								var = iVariable_create(NULL, _VAR_TYPE_S32, NULL, true);
								if (var)
									*var->value.data_s32 = (s32)lnValue;

							} else {
								// Store as 64-bits
								var = iVariable_create(NULL, _VAR_TYPE_S64, NULL, true);
								if (var)
									*var->value.data_s64 = lnValue;
							}

					} else {
						// Floating point
						lfValue = iiVariable_getCompAs_f64(comp);


						//////////
						// Create and populate our output variable
						//////
							*tlManufactured = true;
							if (lfValue >= (f64)_f32_min && lfValue <= (f64)_f32_max)
							{
								// Store as 32-bits
								var = iVariable_create(NULL, _VAR_TYPE_F32, NULL, true);
								if (var)
									*var->value.data_f32 = (f32)lfValue;

							} else {
								// Store as 64-bits
								var = iVariable_create(NULL, _VAR_TYPE_F64, NULL, true);
								if (var)
									*var->value.data_f64 = lfValue;
							}
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
					var = iVariable_create(NULL, _VAR_TYPE_LOGICAL, NULL, true);
					if (var)
					{
						*tlManufactured		= true;
						var->value.data[0]	= _LOGICAL_TRUE;
						var->compRelated	= comp;
					}
					return(var);


				case _ICODE_FALSE:
				case _ICODE_NO:
				case _ICODE_DOWN:
					// It's a .F. or some equivalent
					var = iVariable_create(NULL, _VAR_TYPE_LOGICAL, NULL, true);
					if (var)
					{
						*tlManufactured		= true;
						var->value.data[0]	= _LOGICAL_FALSE;
						var->compRelated	= comp;
					}
					return(var);


				case _ICODE_EXTRA:
					// It's a .X.
					var = iVariable_create(NULL, _VAR_TYPE_LOGICAL, NULL, true);
					if (var)
					{
						*tlManufactured		= true;
						var->value.data[0]	= _LOGICALX_EXTRA;
						var->compRelated	= comp;
					}
					return(var);


				case _ICODE_YET_ANOTHER:
					// It's a .Y.
					var = iVariable_create(NULL, _VAR_TYPE_LOGICAL, NULL, true);
					if (var)
					{
						*tlManufactured		= true;
						var->value.data[0]	= _LOGICALX_YET_ANOTHER;
						var->compRelated	= comp;
					}
					return(var);


				case _ICODE_ZATS_ALL_FOLKS:
					// It's a .X.
					var = iVariable_create(NULL, _VAR_TYPE_LOGICAL, NULL, true);
					if (var)
					{
						*tlManufactured		= true;
						var->value.data[0]	= _LOGICALX_ZATS_ALL_FOLKS;
						var->compRelated	= comp;
					}
					return(var);


				case _ICODE_ALPHANUMERIC:
				case _ICODE_ALPHA:
					// It's some kind of text, could be a field or variable

debug_nop;
// TODO:  Working here, making the retrieve variable logic smarter ...
// In the component parser, needs to recognize filename patterns (drive:\...\... and \\server\...\... forms) before further processing so they do not hit as alpha or alphanumeric
					if (propGet_settings_VariablesFirst(_settings))
					{
						// Searching variables first, field names last.
						if ((var = iVariable_searchForName(thisCode, comp->line->sourceCode->data + comp->start, comp->length, comp, true)))
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

						} else*/ if ((var = iVariable_searchForName(thisCode, comp->line->sourceCode->data + comp->start, comp->length, comp, true))) {
							// It was found in the global variables
						}
					}

					if (var)
					{
						// Create a copy of the variable
						if (var->varType == _VAR_TYPE_NULL)
						{
							// It's a null variable
							varCopy = iVariable_create(NULL, _VAR_TYPE_CHARACTER, NULL, true);
							if (varCopy)
								iDatum_duplicate(&varCopy->value, cgcNullText, -1);

						} else if (var->varType == _VAR_TYPE_OBJECT) {
							// It's an object
							varCopy = iVariable_create(NULL, _VAR_TYPE_CHARACTER, NULL, true);
							if (varCopy)
								iDatum_duplicate(&varCopy->value, cgcObjectText, -1);

						} else if (var->varType == _VAR_TYPE_THISCODE) {
							// It's a thisCode reference
							varCopy = iVariable_create(NULL, _VAR_TYPE_CHARACTER, NULL, true);
							if (varCopy)
								iDatum_duplicate(&varCopy->value, cgcThisCodeText, -1);

						} else {
							// It's a traditional variable
							varCopy = iVariable_create(NULL, var->varType, NULL, true);
							if (varCopy)
								iDatum_duplicate(&varCopy->value, &var->value);
						}
						varCopy->compRelated = comp;
						return(varCopy);
					}
					break;


				case _ICODE_SINGLE_QUOTED_TEXT:
				case _ICODE_DOUBLE_QUOTED_TEXT:		// It's quoted text
					//////////
					// Create and populate our output variable
					//////
						*tlManufactured	= true;
						var = iVariable_create(NULL, _VAR_TYPE_CHARACTER, NULL, true);
						if (var)
							iDatum_duplicate(&var->value, comp->line->sourceCode->data_u8 + comp->start + 1, comp->length - 2);


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
// Gets the contiguous components, comprised of every consecutive component hereafter,
// or the quoted content.
//
//////
	SVariable* iEngine_get_contiguousComponents(SThisCode* thisCode, SComp* comp, bool* tlManufactured, s32 valid_iCodeArray[], s32 tnValid_iCodeArrayCount)
	{
		SVariable* varPathname;


		// Make sure our environment is sane
		varPathname = NULL;
		if (comp && comp->line && comp->line->sourceCode && comp->line->sourceCode->data)
		{
			// Find out what the component is
			switch (comp->iCode)
			{
				case _ICODE_DOUBLE_QUOTED_TEXT:
				case _ICODE_SINGLE_QUOTED_TEXT:
					// By definition, quoted content is its own independent thing
					varPathname = iVariable_createAndPopulate_byText(thisCode, _VAR_TYPE_CHARACTER, comp->line->sourceCode->data_u8 + comp->start, comp->length, true);
					break;

				default:
					// Get every contiguous component
					varPathname	= iVariable_createAndPopulate_byText(thisCode, _VAR_TYPE_CHARACTER, comp->line->sourceCode->data_u8 + comp->start, iComps_getContiguousLength(thisCode, comp, valid_iCodeArray, tnValid_iCodeArrayCount, NULL), true);
					break;
			}
		}

		// Indicate where we are
		return(varPathname);
	}




//////////
//
// Called to find the function, execute it, and return the result
//
//////
	SVariable* iEngine_get_functionResult(SThisCode* thisCode, SComp* comp)
	{
		u32				lnI, lnParamsFound;
		SFunctionData*	lfl;
		SReturnsParams	returnsParams;
		SComp*			compLeftParen;
		
		
		// Make sure our environment is sane
		if (comp && (compLeftParen = comp->ll.nextComp) && compLeftParen->iCode == _ICODE_PARENTHESIS_LEFT)
		{
			// Right now, we know we have something like:  xyz(


			//////////
			// Initialize our parameters and return variables
			//////
				for (lnI = 0; lnI < _MAX_RETURN_COUNT; lnI++)
					returnsParams.returns[lnI] = NULL;

				for (lnI = 0; lnI < _MAX_PARAMETER_COUNT; lnI++)
					returnsParams.params[lnI] = NULL;


			//////////
			// Iterate through each function for matches
			//////
				lfl = &gsKnownFunctions[0];
				while (lfl && lfl->_func != 0)
				{
					// Is this the named function?
					if (lfl->iCode == comp->iCode)
					{
						//////////
						// We need to find the minimum number of parameters between)
						//////
							if (!iiEngine_getParametersBetween(thisCode, compLeftParen, &lnParamsFound, lfl->requiredCount, lfl->parameterCount, &returnsParams.params[0]))
								return(NULL);


						//////////
						// Perform the function
						//////
							returnsParams.returns[0] = lfl->func(NULL, &returnsParams);


						//////////
						// Free every parameter we created
						//////
							for (lnI = 0; lnI < _MAX_PARAMETER_COUNT; lnI++)
							{
								// Delete if populated
								if (returnsParams.params[lnI])
									iVariable_delete(thisCode, returnsParams.params[lnI], true);
							}


						//////////
						// Indicate our return value
						//////
							return(returnsParams.returns[0]);
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
	void iEngine_executeSetter(SThisCode* thisCode, cs8* name, SVariable* varOld, SVariable* varNew)
	{
// TODO:  When the engine is developed and working, a found setter will suspend execution and branch to that location
	}




//////////
//
// Called to report the indicated error and relate it to the indicated variable (if any)
//
//////
	void iEngine_error(SThisCode* thisCode, u32 tnErrorNumber, SVariable* varRelated)
	{
// TODO:  Report the error and relate the variable
	}




///////////
//
// Signaled repeatedly during VALIDATE and ON VALIDATE from SET AUTOVALIDATE ON to
// convey both meta data as well as 
//
//////
	bool iEngine_signal_onValidate(SThisCode* thisCode, SVariable* varTableName, SVariable* varAlias, SVariable* varCdxName, SVariable* varTag, SVariable* varcMessage, SVariable* varIsError, SVariable* varRebuildIndexRequired)
	{
		// Returns the return variable, if we should continue
		// For now, simulate continuing
		return(true);
	}




//////////
//
// Called to update the global _tally value
//
//////
	s64 iEngine_update_tally(SThisCode* thisCode, s64 tnValue)
	{
		s64			lnOldValue;
		SVariable*	varTally;


		//////////
		// Locate the variable
		//////
			varTally = iiVariable_searchForName_variables(thisCode, varGlobals, (s8*)cgcName_tally, sizeof(cgcName_tally) - 1, NULL, true);
			if (!varTally)
			{
				// This should never happen
				iError_signal(thisCode, _ERROR_INTERNAL_ERROR, NULL, true, (s8*)cgcFatalSystemError_tally, true);
				// Control will never return here
			}


		//////////
		// Grab the old value
		//////
			lnOldValue = *varTally->value.data_s64;


		//////////
		// Update with the new value
		//////
			*varTally->value.data_s64 = tnValue;


		//////////
		// Return the old value
		//////
			return(lnOldValue);
	}




//////////
//
// Called to obtain the parameters between the indicated parenthesis.
//
//////
	bool iiEngine_getParametersBetween(SThisCode* thisCode, SComp* compLeftParen, u32* paramsFound, u32 requiredCount, u32 maxCount, SVariable* params[])
	{
		u32			lnI, lnParamCount;
		bool		llManufactured;
		SComp*		comp;
		SComp*		compComma;


		//////////
		// Initialize the parameters to null
		//////
			for (lnI = 0; lnI < _MAX_PARAMETER_COUNT; lnI++)
				params[lnI] = 0;


		//////////
		// Begin to the thing to the right of the left parenthesis
		//////
			lnParamCount	= 1;
			comp			= compLeftParen->ll.nextComp;
			for (lnI = 0; comp && comp->iCode != _ICODE_PARENTHESIS_RIGHT; lnI++)
			{
				//////////
				// See if we've gone over our limit
				//////
					if (lnParamCount > maxCount)
					{
						// Too many parameters
						iError_reportByNumber(thisCode, _ERROR_TOO_MANY_PARAMETERS, comp, false);
						return(NULL);
					}


				//////////
				// The component after this must be a comma
				//////
					compComma = comp->ll.nextComp;
					if (!compComma || (compComma->iCode != _ICODE_COMMA && compComma->iCode != _ICODE_PARENTHESIS_RIGHT && lnParamCount > requiredCount))
					{
						// Comma expected error
						iError_reportByNumber(thisCode, _ERROR_COMMA_EXPECTED, comp, false);
						return(NULL);
					}


				//////////
				// Derive whatever this is as a variable
				//////
					params[lnI] = iEngine_get_variableName_fromComponent(thisCode, comp, &llManufactured);


				// Move to next component
				++lnParamCount;
				comp = compComma->ll.nextComp;
			}


		//////////
		// Indicate how many we found
		//////
			*paramsFound = --lnParamCount;


		//////////
		// Indicate success
		//////
			return(lnParamCount >= requiredCount && lnParamCount <= maxCount);
	}




//////////
//
// Called to delete the indicated breakpoint
//
//////
	void iBreakpoint_delete(SThisCode* thisCode, SBreakpoint** breakpoint)
	{
		SBreakpoint* bp;


		// Make sure our environment is sane
		if (breakpoint && *breakpoint && (*breakpoint)->isUsed && 
			(uptr)*breakpoint >= gBreakpoints->_data && 
			(uptr)*breakpoint <= gBreakpoints->_data + gBreakpoints->populatedLength - sizeof(SBreakpoint))
		{
			// Get a local copy of our pointer
			bp = *breakpoint;

			// Reset the remote
			*breakpoint = NULL;

			// Delete the items as they are
			bp->isUsed = true;

			// Delete any source code for this breakpoint
			if (bp->executeCode)
				iSourceCode_delete(thisCode, &bp->executeCode);
		}
	}




//////////
//
// Called to add a new breakpoint.  It only creates the entry and populates the type.
// For conditional breakpoints, or breakpoints with code they will need to be created
// and added manually by the code in the calling algorithm.
//
//////
	SBreakpoint* iBreakpoint_add(SThisCode* thisCode, SBreakpoint** breakpoint, u32 tnType)
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
					bp = (SBreakpoint*)(gBreakpoints->data_u8 + lnI);

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
	void iSourceCode_delete(SThisCode* thisCode, SSourceCode** sourceCode)
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
			iFunction_politelyDeleteChain(thisCode, &sc->firstFunction);
			iVariable_politelyDeleteChain(thisCode, &sc->params,		true);
			iVariable_politelyDeleteChain(thisCode, &sc->returns,		true);
			iVariable_politelyDeleteChain(thisCode, &sc->privates,		true);
			iVariable_politelyDeleteChain(thisCode, &sc->locals,		true);
			iVariable_politelyDeleteChain(thisCode, &sc->scoped,		true);
		}
	}
