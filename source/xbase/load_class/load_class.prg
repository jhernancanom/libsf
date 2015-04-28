*****
*
* /libsf/source/xbase/load_class/load_class.prg
*
*****
*    _     _ _     _____ _____
*   | |   (_) |__ / ____|  ___|
*   | |   | | '_ \\___ \|  __|
*   | |___| | |_) |___) | |
*   |_____|_|_.__/_____/|_|
*
*   Liberty Software Foundation
* and the Village Freedom Project
*   __     _______     ____  
*   \ \   / /  ___| __|  _ \
*    \ \ / /| |_ | '__| |_) |
*     \ V / |  _|| |  |  __/
*      \_/  |_|  |_|  |_|
*
***
* Version 0.10
* Copyright (c) 2015 by Rick C. Hodgin
***
* Last update:
*     Apr.14.2015
***
* Change log:
*     Apr.13.2015 - Initial creation
***
*
* This document is released as Liberty Software under a Repeat License, as governed
* by the Public Benefit License v1.0 or later (PBL).
*
* The PBL is public domain license with a caveat:  self accountability unto God.
* You are free to use, copy, modify and share this software for any purpose, however,
* it is the desire of those working on this project that the software remain open.
* It is our request that you maintain it that way.  This is not a legal request unto
* our court systems, but rather a personal matter between you and God.  Our talents
* were received from God, and given to you through this forum.  And it is our wish
* that those talents reach out to as many as possible in a form allowing them to wield
* this content for their own betterment, as you are now considering doing.  And whereas
* we could've forced the issue through something like a copyleft-protected release, the
* truth is we are all giving an account of our lives unto God continually by the daily
* choices we make.  And here again is another case where you get to demonstrate your
* character unto God, and unto your fellow man.
*
* Jesus came to this Earth to set the captives free, to save men's eternal souls from
* the punishment demanded by our sin.  Each one of us is given the opportunity to
* receive Him in this world and be saved.  Whether we choose to receive Him, and follow
* Him, and purpose our lives on the goals He has for each of us (all of which are
* beneficial for all involved), is one way we reveal our character continually.  God
* sees straight through to the heart, bypassing all of the words, all of the facades.
* He is our Creator, and He knows who we are truly.
*
* Jesus is called "Christ" because He saves men from the eternal flames of Hell, the
* just punishment of rebellion against God (rebellion against truth) by eternal beings,
* which each of us are.
*
* Do not let His free gift escape you because of some desire to shortcut what is right
* in your life. Instead, do what is right, and do it because He is who He is, and what
* He has done to save us from such a fate.  Demonstrate to Him, to me, and to all of
* mankind, and to all of the Heavenly hosts, exactly who you are on the inside.  Receive
* Jesus Christ into your heart, learn of Him, of how He came here to guide us into that
* which is of His Kingdom and will be forever hereafter we leave this world.  Do this,
* and live.
*
* Every project released by Liberty Software Foundation will include a copy of the
* pbl.txt document, which can be found at http:*www.libsf.org/licenses/.
*
* For additional information about this project, or to view the license, see:
*
*     http:*www.libsf.org/
*     http:*www.libsf.org/licenses/
*     http:*www.visual-freepro.org/vjr/indexmain.html
*     http:*www.visual-freepro.org/wiki/index.php/PBL
*
* Thank you.  And may The Lord bless you richly as you lift up your life, your
* talents, your gifts, your praise, unto Him.  In Jesus' name I pray.  Amen.
*
*




CLOSE DATABASES all
CLEAR ALL
RELEASE ALL
CLEAR
_screen.FontName = "Ubuntu Mono"
_screen.FontSize = 9

IF TYPE("_screen.laFiles[1,5]") = "U"
	_screen.AddProperty("laFiles[1,5]")
ENDIF
IF TYPE("_screen.lni") = "U"
	_screen.AddProperty("lni")
ENDIF

CD \vfp\libs\
ADIR(_screen.laFiles, "*.vcx")

CD \vfp\apps\
FOR _screen.lnI = 1 TO ALEN(_screen.laFiles, 1)
	USE ("libs\" + _screen.laFiles[_screen.lnI, 1]) ALIAS _vcx AGAIN
	SCAN FOR "class" $ LOWER(reserved1) AND objname = "account_appr_gridform"
*SET STEP ON
		? "********** Loading " + objname + " in " + FULLPATH(DBF())
		load_class(objName, FULLPATH(DBF()))
		CLEAR MEMORY
		RELEASE ALL
	ENDSCAN
	USE IN _vcx
NEXT
SET STEP ON
SET STEP ON




FUNCTION load_class
LPARAMETERS tcClass, tcLibrary

	return(iload_class(tcClass, tcClass, tcLibrary, .NULL., .f., 1, .f., SPACE(0)))




**********
* A property is added to each class as new code is added:
*	this.__MethodCode
*****
* The layers of this.__MethodCode[n] relate to the loaded class layer.
* The actual class that was loaded is this.__MethodCode[1], with the class
* it was based on being this.__MethodCode[2], and so on.  Every child or
* sibling class that's loaded also has its own this.__MethodCode.  Base
* class objects do not have these, as they are applied to the loaded class
* layer, rather than the base class layer.
*****
*	this.__MethodCode[n, 1]		-- Event or method name (init, activate, etc.)
*	this.__MethodCode[n, 2]		-- 		laCode[m, 1] -- Class this code relates to
*										laCode[m, 2] -- Source code lines
*****
FUNCTION iload_class
LPARAMETERS tcName, tcClass, tcLibrary, toParent, tlAugmentProperties, tnLevel, tlSubSubCreated, tcParentRecnos
LOCAL lnI, lnJ, lcAlias, loNew, loNewSib, loClass, lcPropName, lcPropNameDescent, lcThisName
LOCAL lcValue, lnEqualPos, llError, lcNameNext, lcClassNext, lcLibraryNext, lcCodeArrayName, lnFoundRecno
LOCAL llSubSubCreated

IF NOT "base_" $ LOWER(tcClass)
	? REPLICATE("|   ", tnLevel) + " ---- Sub-loading " + tcClass + " in " + tcLibrary + " called " + tcName
ENDIF
	**********
	* Locate the library
	*****
		IF NOT FILE(tcLibrary)
			? "Error accessing file: " + tcLibrary
			SET STEP ON
		ENDIF
	
	
	**********
	* Open it
	*****
		lcAlias = SYS(2015)
		SELECT 0
		USE (tcLibrary)  ALIAS (lcAlias) SHARED AGAIN

	
	**********
	* Locate the class
	*****
		LOCATE FOR LOWER(objName) = LOWER(tcClass) AND LOWER(reserved1) = "class"
		IF EOF()
			? "Error accessing class " + tcClass + " in " + tcLibrary
			SET STEP ON
		ENDIF
		lnFoundRecno = RECNO()


	**********
	* Create the instance
	*****
		IF tlAugmentProperties
			* We are augmenting the parent class with our properties
			loNew = toParent

		ELSE
			IF ISNULL(toParent)
				* Creating the initial instance
				loNew		= CREATEOBJECT(&lcAlias..baseclass)
				loNew.Name	= tcName

			ELSE
				* Appending this class to the parent
				toParent.ADDOBJECT(tcName, &lcAlias..baseClass)
				loNew = toParent.&tcName
			ENDIF
		ENDIF
	
	
	**********
	* Append any parent classes
	*****
*IF "test1" $ LOWER(&lcAlias..parent)
*	SET STEP ON
*ENDIF
*		lcObjParent = &lcAlias..parent
*		SCAN FOR EMPTY(&lcAlias..reserved1) AND LOWER(&lcAlias..objName) = LOWER(lcObjParent) AND NOT EMPTY(&lcAlias..parent) AND NOT "." $ &lcAlias..parent
*			IF RECNO() != lnFoundRecno AND NOT TRANSFORM(RECNO()) $ tcParentRecnos AND LOWER(tcClass) != &lcAlias..class
*SET STEP ON
*				iload_class("[parent augment for class]", &lcAlias..parent, tcLibrary, loNew, .t., tnLevel + 1, @llSubSubCreated, tcParentRecnos + CHR(13) + TRANSFORM(RECNO()))
*				IF llSubSubCreated
*					IF NOT "base_" $ tcClass
*						? REPLICATE("|   ", tnLevel + 1) + " ---- Loaded parent " + lcClassNext + " in " + lcLibraryNext + " called " + lcNameNext
*					ENDIF
*				ENDIF
*			ENDIF
*		ENDSCAN
*		GOTO lnFoundRecno


	**********
	* Add any named classes
	*****
		lcNameNext		= &lcAlias..objName
		lcClassNext		= &lcAlias..class
		lcLibraryNext	= FULLPATH(ADDBS(JUSTPATH(tcLibrary)) + ALLTRIM(&lcAlias..classloc))
		IF NOT EMPTY(&lcAlias..classloc) AND (lcClassNext != tcClass OR lcLibraryNext != tcLibrary)
			* Add all parent classes
			llSubSubCreated	= .t.
			llSubSubCreated	= .f.
			iload_class(lcNameNext, lcClassNext, lcLibraryNext, loNew, .t., tnLevel + 1, @llSubSubCreated, SPACE(0))
			IF llSubSubCreated
				IF NOT "base_" $ tcClass
					? REPLICATE("|   ", tnLevel + 1) + " ---- Finished on " + lcClassNext + " in " + lcLibraryNext + " called " + lcNameNext
				ENDIF
			ENDIF
		ENDIF
	
	
	**********
	* Non-base class siblings
	*****
		SELECT (lcAlias)
		SCAN FOR LOWER(parent) == LOWER(tcClass) AND NOT EMPTY(classloc)

			* Create the object
			lcNameNext		= &lcAlias..objName
			lcClassNext		= &lcAlias..class
			lcLibraryNext	= FULLPATH(ADDBS(JUSTPATH(tcLibrary)) + ALLTRIM(&lcAlias..classloc))
			tlSubSubCreated	= .t.
			llSubSubCreated	= .f.
			iload_class(lcNameNext, lcClassNext, lcLibraryNext, loNew, .f., tnLevel + 1, @llSubSubCreated, SPACE(0))
			IF llSubSubCreated
				* Note:  Their methods are added when they are added
				IF NOT "base_" $ tcClass
					? REPLICATE("|   ", tnLevel + 1) + " ---- Finished on " + lcClassNext + " in " + lcLibraryNext + " called " + lcNameNext
				ENDIF
			ENDIF

		ENDSCAN


	**********
	* Base class siblings
	*****
		SCAN FOR LOWER(parent) == LOWER(tcClass) AND EMPTY(classloc)
		
			* Create the object
			lcName			= &lcAlias..objName
			lcClassNext		= LOWER(&lcAlias..class)
			loNew.ADDOBJECT(lcName, lcClassNext)
			loNewSib		= loNew.&lcName
			tlSubSubCreated	= .t.
			
			* Add any events or methods, and their code
			iiload_class_set_properties(loNewSib, &lcAlias..properties)
			iiload_class_add_methods(loNewSib)
			iiload_class_populate_methods(loNewSib, &lcAlias..methods)

		ENDSCAN
		GOTO lnFoundRecno
	
	
	**********
	* Set any properties, events or methods, and their code
	*****
		iiload_class_set_properties(loNew, &lcAlias..properties)
		iiload_class_add_methods(loNew)
		iiload_class_populate_methods(loNew, &lcAlias..methods)


	**********
	* Indicate the fruits of our labor
	*****
		RETURN loNew



FUNCTION iiload_class_determine_varType
LPARAMETERS lcValue
LOCAL llIsNumeric

	**********
	* Determine the type based on its design
	*****
		DO CASE
			CASE EMPTY(lcValue)
				* Return it as is, which will be an empty character string
				RETURN lcValue
			
			CASE LEFT(lcValue,1) = CHR(34) AND RIGHT(lcValue,1) = CHR(34)
				* Character
				RETURN SUBSTR(lcValue, 2, LEN(lcValue) - 2)
			
			CASE LEFT(lcValue,1) = "(" AND RIGHT(lcValue,1) = ")"
				* It needs to be processed to return
				RETURN EVALUATE(lcValue)
			
			CASE LEFT(lcValue,1) = "." AND RIGHT(lcValue,1) = "."
				* It needs to be processed to return
				RETURN EVALUATE(lcValue)
			
			OTHERWISE
				* See if every character is numeric
				llIsNumeric = .t.
				FOR lnI = 1 TO LEN(lcValue)
					IF NOT SUBSTR(lcValue, lnI, 1) $ "-0123456789."
						llIsNumeric = .f.
						EXIT
					ENDIF
				NEXT
				
				* Was it entirely numeric?
				IF llIsNumeric
					* It is numeric
					RETURN VAL(lcValue)
				ENDIF
		ENDCASE


	**********
	* If we get here, return it as it is (as character)
	*****
		RETURN lcValue




FUNCTION iiload_class_add_methods
LPARAMETERS toObj
LOCAL lnI, lnJ, llFound, laMems, lcCodeArrayName

IF LOWER(toObj.baseclass) = "grid"
	SET STEP ON
ENDIF
	**********
	* Make sure it has a __MethodCode[] array
	*****
		IF TYPE(toObj.name + "__MethodCode[1,2]") = "U"
			toObj.addProperty("__MethodCode[1,2]")
		ENDIF


	**********
	* Populate it with its members
	*****
		DIMENSION laMems[1]
		AMEMBERS(laMems, toObj, 1)
		FOR lnI = 1 TO ALEN(laMems, 1)
			IF INLIST(LOWER(laMems[lnI, 2]), "method", "event")
			
				**********
				* Make sure this one exists in our methods array
				*****
					llFound = .f.
					IF TYPE("toObj.__MethodCode[1, 1]") != "L"
						* Search the existing ones to see if it's found
						FOR lnJ = 1 TO ALEN(toObj.__MethodCode, 1)
							IF LOWER(toObj.__MethodCode[lnJ, 1]) = LOWER(laMems[lnI, 1])
								* We've found a match
								llFound = .t.
								EXIT
							ENDIF
						NEXT
					ENDIF

				
				**********
				* If it wasn't found, add it
				*****
					IF llFound

						**********
						* Insert this reference at the top
						*****
							lcCodeArrayName	= toObj.__MethodCode[ALEN(toObj.__MethodCode, 1), 2]

							iiload_class_bump_array_down(@&lcCodeArrayName)

							&lcCodeArrayName[1, 1] = toObj
							&lcCodeArrayName[1, 2] = SPACE(0)	&& No code yet
						

					ELSE
					
						**********
						* Add this new method
						*****
							lcCodeArrayName	= SYS(2015)
							PUBLIC &lcCodeArrayName
							DIMENSION &lcCodeArrayName[1, 2]


						**********
						* Add a slot for the new item if need be
						*****
							IF TYPE("toObj.__MethodCode[1, 1]") != "L"
								DIMENSION toObj.__MethodCode[ALEN(toObj.__MethodCode, 1) + 1, ALEN(toObj.__MethodCode, 2)]
							ENDIF


						**********
						* Store the method name, and its associated array
						*****
							toObj.__MethodCode[ALEN(toObj.__MethodCode, 1), 1] = LOWER(laMems[lnI, 1])
							toObj.__MethodCode[ALEN(toObj.__MethodCode, 1), 2] = lcCodeArrayName


						**********
						* Insert the reference for this class at this level
						*****
							&lcCodeArrayName[1, 1] = toObj
							&lcCodeArrayName[1, 2] = SPACE(0)	&& No code yet

					ENDIF

			ENDIF
		NEXT




FUNCTION iiload_class_populate_methods
LPARAMETERS toObj, lcMethodCode
LOCAL laSourceCode, lnI, lcProcName, lniStart, lniEnd, lcCodeBlock, llFound
LOCAL lcCodeArrayName, loObjProp, lcProcName, lcProcNameDescent


	**********
	* There are procedures within
	* Parse and add/append as encountered
	*****
		DIMENSION laSourceCode[1]
		ALINES(laSourceCode, lcMethodCode)
		FOR lnI = 1 TO ALEN(laSourceCode, 1) STEP 0

			**********
			* Look for procedures or functions
			*****
				IF UPPER(LEFT(laSourceCode[lnI], 4)) = "PROC" OR UPPER(LEFT(laSourceCode[lnI], 4)) = "FUNC"

					**********
					* Beginning of a procedure or function
					*****
						lcProcName	= LOWER(ALLTRIM(SUBSTR(laSourceCode[lnI], AT(SPACE(1), laSourceCode[lnI]) + 1)))
						lniStart	= lnI


					**********
					* Look for the end
					*****
						lcCodeBlock = SPACE(0)
						FOR lniEnd = lniStart + 1 TO ALEN(laSourceCode, 1)
							IF UPPER(LEFT(laSourceCode[lniEnd], 4)) = "ENDP" OR UPPER(LEFT(laSourceCode[lniEnd], 4)) = "ENDF"
								* End of the procedure or function
								EXIT
							ENDIF
							lcCodeBlock = lcCodeBlock + laSourceCode[lniEnd] + CHR(13)
						NEXT
						* When we get here, lniStart..lniEnd is the source code range, and lcCodeBlock is the actual source code


					**********
					* See if this method name already exists
					*****
*						llDescentObj	= .f.
						loObjProp		= toObj
						llBigError		= .f.
						IF "." $ lcProcName
							* It is code added to a nested class
*							llDescentObj		= .t.
							llFound				= .t.
							lcProcNameDescent	= lcProcName
							DO WHILE !llBigError AND "." $ lcProcNameDescent
								lcThisName = LEFT(lcProcNameDescent, AT(".", lcProcNameDescent) - 1)
								IF PEMSTATUS(loObjProp, lcThisName, 5)
									* Continue downward
									loObjProp			= loObjProp.&lcThisName
									lcProcNameDescent	= SUBSTR(lcProcNameDescent, LEN(lcThisName) + 2)
								ELSE
									? "Error accessing " + lcThisName + " on " + loObjProp.name + " of " + toObj.name + "." + lcProcName
									llBigError			= .t.
									llFound				= .f.
									SET STEP ON
								ENDIF
							ENDDO
							lcProcName = lcProcNameDescent
						ENDIF
							* It is code added directly to this class


					**********
					* If we're still good, continue
					*****
						IF NOT llBigError
						
							**********
							* Search for the existing method
							*****
								llFound = .f.
								FOR lnJ = 1 TO ALEN(toObj.__MethodCode, 1)
									IF LOWER(loObjProp.__MethodCode[lnJ, 1]) == lcProcName
										* We found the existing
										llFound			= .t.
										lcCodeArrayName = loObjProp.__MethodCode[lnJ, 2]
										EXIT
									ENDIF
								NEXT


							**********
							* If it was found, update it
							*****
								IF llFound
									IF &lcCodeArrayName[1, 1] != toObj && OR llDescentObj
										**********
										* It is a different object, so we insert new code before what exists
										* Bump everything down one and assign this layer of code to itself
										*****
											IF NOT EMPTY(&lcCodeArrayName[1, 2])
												* Move down the code that's already here
												iiload_class_bump_array_down(@&lcCodeArrayName)
											ENDIF
											&lcCodeArrayName[1, 1] = toObj

									ELSE
										* This method relates to this class
										* There shouldn't already be any code here
										* If there is, it means the method name appears
										* twice in the class definition.
										IF NOT EMPTY(&lcCodeArrayName[1, 2])
											? "Duplicate method code found in " + toObj.Name + "." + lcProcName
*											SET STEP ON
										ENDIF
										* If we get here, we're good... we can add it
									ENDIF

								ELSE
									**********
									* Not found, add new method to the class
									*****
										lcCodeArrayName	= SYS(2015)
										PUBLIC &lcCodeArrayName
										DIMENSION &lcCodeArrayName[1, 2]

										DIMENSION toObj.__MethodCode[ALEN(toObj.__MethodCode, 1) + 1, ALEN(toObj.__MethodCode, 2)]
										toObj.__MethodCode[ALEN(toObj.__MethodCode, 1), 1] = lcProcName
										toObj.__MethodCode[ALEN(toObj.__MethodCode, 1), 2] = lcCodeArrayName


									**********
									* Insert the reference for this class at this level
									*****
										&lcCodeArrayName[1, 1] = toObj
										&lcCodeArrayName[1, 2] = SPACE(0)	&& No code yet

								ENDIF


								**********
								* Append the method code
								*****
									&lcCodeArrayName[1, 2] = lcCodeBlock

						ENDIF


					**********
					* Get ready for the next block
					*****
						lnI = lniEnd + 1

				ELSE
					* Increase to next line
					lnI = lnI + 1
				ENDIF

		NEXT
		RELEASE laSourceCode




FUNCTION iiload_class_set_properties
LPARAMETERS toObj, tcPropertyCode
LOCAL lnI, lnJ, lnPageCount, lnButtonCount, lnEqualPos, lcNewName, loNewObj
LOCAL laLines, lnLines, lcPropName, lcValue, loClass, lcPropNameDescent, lcThisName, llError

	**********
	* Break out the lines
	*****
		DIMENSION laLines[1]
		lnLines = ALINES(laLines, tcPropertyCode)
	
	
	**********
	* Some classes require that their subordinate members be added mechanically
	*****
		DO CASE
			CASE LOWER(toObj.baseclass) = "pageframe"
				FOR lnI = 1 TO lnLines
					lnEqualPos = AT("=", laLines[lnI])
					IF lnEqualPos > 0

						* Get the name = value for this line
						lcPropName	= ALLTRIM(LEFT(laLines[lnI], lnEqualPos - 1))
						lcValue		= ALLTRIM(SUBSTR(laLines[lnI], lnEqualPos + 1))

						* If it's pagecount, we need to add that many pages
						IF LOWER(lcPropName) == "pagecount"
						
							* Add every page
							lnPageCount = VAL(lcValue)
							FOR lnJ = 1 TO lnPageCount
								lcNewName = "page" + TRANSFORM(lnJ)
								IF NOT PEMSTATUS(toObj, lcNewName, 5)
								
									* Add the object
									toObj.ADDOBJECT(lcNewName, "page")
									loNewObj = toObj.&lcNewName

									* Add its default methods
									iiload_class_add_methods(loNewObj)

								ENDIF
							NEXT
							
							* All done
							EXIT
						ENDIF

					ENDIF
				NEXT

			CASE LOWER(toObj.baseclass) = "optiongroup"
				FOR lnI = 1 TO lnLines
					lnEqualPos = AT("=", laLines[lnI])
					IF lnEqualPos > 0

						* Get the name = value for this line
						lcPropName	= ALLTRIM(LEFT(laLines[lnI], lnEqualPos - 1))
						lcValue		= ALLTRIM(SUBSTR(laLines[lnI], lnEqualPos + 1))

						* If it's buttonCount, we need to add that many buttons
						IF LOWER(lcPropName) == "buttoncount"
						
							* Add every button
							lnButtonCount = MAX(VAL(lcValue), 2)
							FOR lnJ = 1 TO lnButtonCount
								lcNewName = "option" + TRANSFORM(lnJ)
								IF NOT PEMSTATUS(toObj, lcNewName, 5)
								
									* Add the object
									toObj.ADDOBJECT(lcNewName, "optionbutton")
									loNewObj = toObj.&lcNewName

									* Add its default methods
									iiload_class_add_methods(loNewObj)

								ENDIF
							NEXT
							
							* All done
							EXIT
						ENDIF

					ENDIF
				NEXT

			CASE LOWER(toObj.baseclass) = "commandgroup"
				FOR lnI = 1 TO lnLines
					lnEqualPos = AT("=", laLines[lnI])
					IF lnEqualPos > 0

						* Get the name = value for this line
						lcPropName	= ALLTRIM(LEFT(laLines[lnI], lnEqualPos - 1))
						lcValue		= ALLTRIM(SUBSTR(laLines[lnI], lnEqualPos + 1))

						* If it's buttonCount, we need to add that many buttons
						IF LOWER(lcPropName) == "buttoncount"
						
							* Add every button
							lnButtonCount = MAX(VAL(lcValue), 2)
							FOR lnJ = 1 TO lnButtonCount
								lcNewName = "command" + TRANSFORM(lnJ)
								IF NOT PEMSTATUS(toObj, lcNewName, 5)
								
									* Add the object
									toObj.ADDOBJECT(lcNewName, "commandbutton")
									loNewObj = toObj.&lcNewName

									* Add its default methods
									iiload_class_add_methods(loNewObj)

								ENDIF
							NEXT
							
							* All done
							EXIT
						ENDIF

					ENDIF
				NEXT

		ENDCASE


	**********
	* Assign properties
	*****
		FOR lnI = 1 TO lnLines
			lnEqualPos = AT("=", laLines[lnI])
			IF lnEqualPos > 0
				* Get the name = value for this line
				lcPropName	= ALLTRIM(LEFT(laLines[lnI], lnEqualPos - 1))
				lcValue		= ALLTRIM(SUBSTR(laLines[lnI], lnEqualPos + 1))
				
				* Set all properties except name
				IF LOWER(RIGHT(lcPropName, 5)) != ".name"
				
					**********
					* Get to the property's location
					*****
						llBigError	= .f.
						loClass		= toObj
						IF "." $ lcPropName
							* Iterate downward until we get to the final object
							lcPropNameDescent = lcPropName
							DO WHILE "." $ lcPropNameDescent
								lcThisName = LEFT(lcPropNameDescent, AT(".", lcPropNameDescent) - 1)
								IF PEMSTATUS(loClass, lcThisName, 5)
									* Continue downward
									loClass				= loClass.&lcThisName
									lcPropNameDescent	= SUBSTR(lcPropNameDescent, LEN(lcThisName) + 2)
								ELSE
									? "Error accessing " + lcThisName + " on " + loClass.name + " of " + toObj.name + "." + lcPropName
									llBigError = .t.
									SET STEP ON
									EXIT
								ENDIF
							ENDDO
							lcPropName = lcPropNameDescent
						ENDIF


						IF NOT llBigError
							**********
							* Add the property if need be
							*****
								llError = .t.
								IF !PEMSTATUS(loClass, lcPropName, 5)
									TRY
										* Property does not exist, add it
										loClass.ADDPROPERTY(lcPropName)
										llError = .f.

									CATCH
										* Read-only properties generate errors when you try to add them
									ENDTRY
								ENDIF


							**********
							* Assign it
							*****
								IF NOT llError
									llError = .t.
									TRY
										loClass.&lcPropName	= iiload_class_determine_varType(lcValue)
										llError = .f.
									CATCH
									ENDTRY
									
									IF llError
*										? "Error assigning [" + lcValue + "] to " + loClass.Name + "." + lcPropName
*										SET STEP ON
									ENDIF
								ENDIF
								
						ENDIF

				ENDIF
			ENDIF
		NEXT




FUNCTION iiload_class_bump_array_down
LPARAMETERS taArray
LOCAL lnI, lnJ

	**********
	* Add a new slot to the laCode
	*****
		EXTERNAL ARRAY taArray
		DIMENSION taArray[ALEN(taArray, 1) + 1, ALEN(taArray, 2)]
	
	
	**********
	* Bump everything down ... x[i+1, j] = x[i, j]
	*****
		FOR lnI = ALEN(taArray, 1) - 1 TO 1 STEP -1
			FOR lnJ = 1 TO ALEN(taArray, 2)
				taArray[lnI + 1, lnJ] = taArray[lnI, lnJ]
			NEXT
		NEXT
