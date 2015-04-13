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
*     Apr.13.2015
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




SET STEP ON
DO load_class WITH "classname", "c:\path\to\classlib.vcx"




FUNCTION load_class
LPARAMETERS tcClass, tcLibrary
LOCAL laInitEvents

	DIMENSION laInitEvents[1]
	iload_class(tcClass, tcLibrary, .NULL., @laInitEvents, .f.)




FUNCTION iload_class
LPARAMETERS tcClass, tcLibrary, toParent, taInitEvents, tlAugmentProperties
LOCAL lnI, lcAlias, loNew, loClass, lcPropName, lcPropNameDescent, lcThisName, lcValue, lnEqualPos, llError, lcLibraryNext
EXTERNAL ARRAY taInitEvents


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


	**********
	* Create the instance
	*****
		lcName = &lcAlias..objName
		IF tlAugmentProperties
			* We are augmenting the parent class with our properties
			loNew = toParent

		ELSE
			IF ISNULL(toParent)
				* Creating the initial instance
				loNew		= CREATEOBJECT(&lcAlias..baseclass)
				loNew.Name	= lcName

			ELSE
				* Appending this class to the parent
				toParent.ADDOBJECT(lcName, &lcAlias..baseClass)
				loNew = toParent.&lcName
			ENDIF
		ENDIF
	
	
	**********
	* Append any parent classes
	*****
		lcClassNext		= &lcAlias..class
		lcLibraryNext	= FULLPATH(ADDBS(JUSTPATH(tcLibrary)) + ALLTRIM(&lcAlias..classloc))
		IF NOT EMPTY(&lcAlias..classloc) AND (lcClassNext != tcClass OR lcLibraryNext != tcLibrary)
			* Add all parent classes
			iload_class(lcClassNext, lcLibraryNext, loNew, @taInitEvents, .t.)
		ENDIF
	
	
	**********
	* Append any siblings
	*****
		SELECT (lcAlias)
		SCAN FOR parent = tcClass
			lcClassNext		= &lcAlias..class
			lcLibraryNext	= FULLPATH(ADDBS(JUSTPATH(tcLibrary)) + ALLTRIM(&lcAlias..classloc))
			IF NOT EMPTY(&lcAlias..classloc)
				* Add this sibling
				iload_class(lcClassNext, lcLibraryNext, loNew, @taInitEvents, .f.)
			ENDIF
		ENDSCAN
	
	
	**********
	* Parse out the method code and prepend it to the stack
	*****
		* Incomplete
	
	
	**********
	* Append this class to the list of events to signal for init
	*****
		IF NOT tlAugmentProperties
			* Only signal the init event on highest-level objects
			* They will propagate down automatically
			IF TYPE("taInitEvents[ALEN(taInitEvents, 1)]") != "L"
				DECLARE taInitEvents[ALEN(taInitEvents, 1) + 1]
			ENDIF
			taInitEvents[ALEN(taInitEvents, 1)] = lcName + ".init()"
		ENDIF


	**********
	* Set the properties
	*****
		SELECT (lcAlias)
		lnLines = ALINES(laLines, &lcalias..properties)
		FOR lnI = 1 TO lnLines
			lnEqualPos = AT("=", laLines[lnI])
			IF lnEqualPos > 0
				* Get the name = value for this line
				lcPropName	= ALLTRIM(LEFT(laLines[lnI], lnEqualPos - 1))
				lcValue		= ALLTRIM(SUBSTR(laLines[lnI], lnEqualPos + 1))
				
				* Set all properties except name
				IF LOWER(lcPropName) != "name"
				
					**********
					* Get to the property's location
					*****
						loClass = loNew
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
									? "Error accessing " + lcThisName + " on " + loClass.name + " of " + loNew.name + "." + lcPropName
									SET STEP ON
								ENDIF
							ENDDO
							lcPropName = lcPropNameDescent
						ENDIF
					
					
					**********
					* Add the property if need be
					*****
						IF !PEMSTATUS(loClass, lcPropName, 5)
							* Property does not exist, add it
							loClass.ADDPROPERTY(lcPropName)
						ENDIF
						
					
					**********
					* Assign it
					*****
						llError = .t.
						TRY
							loClass.&lcPropName	= iiload_class_determine_varType(lcValue)
							llError = .f.
						CATCH
						ENDTRY
						
						IF llError
							? "Error assigning [" + lcValue + "] to " + loClass.Name + "." + lcPropName
							SET STEP ON
						ENDIF

				ENDIF
			ENDIF
		NEXT
	
	
	**********
	* Clean house
	*****
		USE IN (lcAlias)




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
					IF NOT SUBSTR(lcValue, lnI, 1) $ "0123456789"
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
