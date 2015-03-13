*****
*
* /libsf/source/vjr/source/sourcelight/compile.prg
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
*     Mar.13.2015
***
* Change log:
*     Mar.13.2015 - Initial creation
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


LOCAL lnErrorCount, lcErrors
LOCAL laLines, lcHFile, lcConstants, lcCmdFunc




**********
* Clear all errors
*****
	REPLACE ALL cErrors WITH SPACE(0)


**********
* Do some initial sanity checking, reporting formatting errors
*****
	SELECT sourcelight
	lnErrorCount = 0
	SCAN FOR NOT isValidRecord(.t.)
		* Store our error information
		lnErrorCount	= lnErrorCount + 1
		lcErrors		= lcErrors + ALLTRIM(cErrors) + CHR(13)
	ENDSCAN
	IF lnErrorCount != 0
		* Errors are preventing compilation
		MESSAGEBOX(	"Errors were encountered that must" + CHR(13) + ;
					"be resolved before continuing. Sorry.", ;
					0+16, ;
					"SourceLight Precompile Errors")
		RETURN .F.
	ENDIF
	* If we get here, the content is valid


**********
* Output files
*****
	lcHFile		= SPACE(0)
	lcConstants	= SPACE(0)


**********
* Iterate through each record building the output
*****
	SELECT sourcelight
	SCAN
	
		**********
		* Grab the command definitions
		*****
			lcCmdFunc = ALLTRIM(sourcelight.cCmdFunc)
		
		
		**********
		* Extract out the lines one-by-one
		*****
			DIMENSION laLines[1]
			ALINES(laLines, lcCmdFunc)
			
		
		**********
		* Is it a command, function, or flow control?
		*****
			DO CASE
				CASE nCmdFunc = 1		&& Command
				CASE nCmdFunc = 2		&& Function
				CASE nCmdFunc = 3
			ENDCASE

			FOR lnI = 1 TO ALEN(laLines, 1)

				**********
				* Parse out each expression
				*****
					

			NEXT

	ENDSCAN




**********
* Performs sanity checks looking for invalid data
*****
FUNCTION isValidRecord
LPARAMETERS tlRecordErrors
LOCAL llIsValid, lc


**********
* Optimism!
*****
	llIsValid = .T.


**********
* #1
* Every nCmdFunc is 1..3
*****
	SCAN FOR NOT BETWEEN(nCmdFunc, 1, 3)
		llIsValid = .f.
		REPLACE cError WITH cError + "Needs to be set to Command, Function, or Flow." + CHR(13)
	ENDSCAN


**********
* #2
* All functions have an equal sign on every line
*****
	SCAN FOR nCmdFunc = 2		&& Functions only

		**********
		* Get rid of blank lines
		*****
			lcCmdFunc = CHRTRAN(ALLTRIM(cCmdFunc), CHR(10), SPACE(0))
			DO WHILE CHR(13)+CHR(13) $ lcCmdFunc
				lcCmdFunc = STRTRAN(ALLTRIM(cCmdFunc), CHR(13)+CHR(13), CHR(13))
			ENDDO
			lcCmdFunc = ALLTRIM(lcCmdFunc, 0, CHR(13)) + CHR(13)


		**********
		* Verify there's an equal sign for every line
		*****
			IF OCCURS("=", lcCmdFunc) != OCCURS(CHR(13), lcCmdFunc)
				llIsValid = .f.
				REPLACE cError WITH cError + "The function equal sign count does not match the populated line count." + CHR(13)
			ENDIF

	ENDSCAN


**********
* #3
* All names on each function line is found in the parameters
*****
	* Working here


**********
* Indicate success or failure
*****
	RETURN llIsValid
