**********
*
* /libsf/source/unsorted/dna_project_butterfly/loadcube.cpp
*
*****
* Version 0.01
* Copyright (c) 2015 by Rick C. Hodgin
*****
* Last update:
*     Feb.25.2015 - ButterflyCube8a analysis logic in Visual FoxPro
*****
* Change log:
*     Feb.25.2015 - Initial creation
*****
*
* This document is released as Liberty Software under a Repeat License, as governed
* by the Public Benefit License v1.0 or later (PBL).
*
* The PBL is a public domain license with a caveat:  self accountability unto God.
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
*****




**********
* Uses the output files generated from the butterfly.cpp program in this GitHub push:
*		https://github.com/RickCHodgin/libsf/commit/89cbbf26dbf6cd047c41bda2d7b9fb491ed4a69f
*****
	SET DOHISTORY off
	SET TALK off
	CLEAR
	CLOSE DATABASES ALL


**********
* Process through all 39 files, one by one.
* Note:  Each file takes 10s of minutes to process, and there are a lot of assumptions in this.
*****
	FOR lnI = 0 TO 38
		lcIter = PADL(ALLTRIM(STR(lnI,2,0)),2,"0")
		loadCube8a("butterflyCube8a_" + lcIter + ".dbf", "butterfly_cubes_" + lcIter + ".txt")
	NEXT




FUNCTION loadCube8a
LPARAMETERS tcTable, tcLoadFile

	**********
	* Put quotes around the files
	*****
		tcTable		= CHR(34) + tcTable + CHR(34)
		tcLoadFile	= CHR(34) + tcLoadFile + CHR(34)


	**********
	* Create the load cursor.
	* This file matches the text file on disk.
	*****
		CREATE CURSOR c_butterflyCube8a ;
		( ;
			cT			c(5), ;		&& Top
			cSpacer1	c(1), ;
			c1L			c(5), ;		&& Arm1 left
			cSpacer2	c(1), ;
			c1R			c(5), ;		&& Arm1 right
			cSpacer3	c(1), ;
			c2L			c(5), ;		&& Arm2 left
			cSpacer4	c(1), ;
			c2R			c(5), ;		&& Arm2 right
			cSpacer5	c(1), ;
			cB			c(5) ;		&& Bottom
		)


	**********
	* Master butteflyCube8a table
	*****
		SET SAFETY OFF
		CREATE TABLE &tcTable ;
		( ;
			iid			i, ;		&& Unique ID for row (equivalent to RECNO())
		;
			cT			c(5), ;		&& Top
			c1L			c(5), ;		&& Arm1 left
			c1R			c(5), ;		&& Arm1 right
			c2L			c(5), ;		&& Arm2 left
			c2R			c(5), ;		&& Arm2 right
			cB			c(5), ;		&& Bottom
		;
			nCountT		i, ;		&& Number of keys matching top
			nCountL		i, ;		&& Number of keys matching left
			nCountR		i, ;		&& Number of keys matching right
			nCountB		i, ;		&& Number of keys matching bottom
			cSpacer1	c(1), ;
		;
			nDeltaT		i, ;		&& Relative distance to the nearest cB which aligns with this cT
			nDeltaL		i, ;		&& Relative distance to the nearest c1L+c2L which aligns with this c1R+c2R
			nDeltaR		i, ;		&& Relative distance to the nearest c1R+c2R which aligns with this c1L+c2L
			nDeltaB		i, ;		&& Relative distance to the nearest cT which aligns with this cT
			cSpacer2	c(1), ;
		;
			nAvgDelT	i, ;		&& Average records away for first 10 matches for top
			nAvgDelL	i, ;		&& Average records away for first 10 matches for left
			nAvgDelR	i, ;		&& Average records away for first 10 matches for right
			nAvgDelB	i, ;		&& Average records away for first 10 matches for bottom
			cSpacer3	c(1), ;
		;
			cKeyT		c(5), ;		&& Index key for top
			cKeyL		c(10), ;	&& Index key for left
			cKeyR		c(10), ;	&& Index key for right
			cKeyB		c(5) ;		&& Index key for bottom
		)
		USE &tcTable ALIAS butterflyCube8a EXCLUSIVE
		SET SAFETY ON


	*********
	* Load the file
	*****
		SELECT c_butterflyCube8a
		APPEND FROM &tcLoadFile SDF


	**********
	* Back off except for the NSEW counts found in Numbers (does not include center/Levi)
	*****
		* Book of Numbers:  186,400 + 157,600 + 151,450 + 108,100
		DELETE ALL FOR RECNO() <= (RECCOUNT() - 603550)


	**********
	* Copy to permanent form
	*****
		SELECT butterflyCube8a
		APPEND FROM FULLPATH(DBF("c_butterflyCube8a")) FOR NOT DELETED()


	**********
	* Delete the cursor
	*****
		USE IN c_butterflyCube8a
	
	
	**********
	* Disregard incomplete data
	*****
		DELETE ALL FOR "N" $ cT+c1L+c1R+c2L+c2R+cB


	**********
	* Update the keys
	*****
		REPLACE ALL iid		WITH RECNO(), ;
					cKeyT	WITH cT, ;
					cKeyL	WITH c1L + c2L, ;
					cKeyR	WITH c1R + c2R, ;
					cKeyB	WITH cB


	**********
	* Create cursors of each key
	*****
		**********
		* Top
		*****
			* Cursor
			SELECT iid, cKeyT as cT ;
				FROM butterflyCube8a ;
				INTO CURSOR c_t READWRITE
			
			* Index
			INDEX ON cT TAG main


		**********
		* Left
		*****
			* Cursor
			SELECT iid, cKeyL as cL;
				FROM butterflyCube8a ;
				INTO CURSOR c_l READWRITE
			
			* Index
			INDEX ON cL TAG main


		**********
		* Right
		*****
			* Cursor
			SELECT iid, cKeyR AS cR ;
				FROM butterflyCube8a ;
				INTO CURSOR c_r READWRITE
			
			* Index
			INDEX ON cR TAG main


		**********
		* Bottom
		*****
			* Cursor
			SELECT iid, cKeyB as cB ;
				FROM butterflyCube8a ;
				INTO CURSOR c_b READWRITE
			
			* Index
			INDEX ON cB TAG main


	**********
	* Establish relationships
	*****
		SELECT butterflyCube8a
		SET RELATION TO cKeyT	INTO c_b, ;		&& Top links into bottom
						cKeyL	INTO c_r, ;		&& Left links into right
						cKeyR	INTO c_l, ;		&& Right links into left
						cKeyB	INTO c_t		&& Bottom links into top


	**********
	* Process through for each key
	*****
		lnCount = 0
		SCAN FOR NOT DELETED()		&& AND RECNO() < 200	&& For debugging
			**********
			* Update our odometer every 100 records
			*****
				IF (RECNO() - 1) % 100 = 0
					WAIT WINDOW TRANSFORM(STR(RECNO() * 100 / RECCOUNT(),6,2)) + "% completed" NOWAIT
				ENDIF

			
			**********
			* Process the sides
			*****
				llIgnoreRest = .F.
				lnCount = lnCount + processThisLink("b", "T", @llIgnoreRest)			&& Top links into bottom
				IF !llIgnoreRest
					lnCount = lnCount + processThisLink("r", "L", @llIgnoreRest)		&& Left links to right
				ENDIF
				IF !llIgnoreRest
					lnCount = lnCount + processThisLink("l", "R", @llIgnoreRest)		&& Right links to left
				ENDIF
				IF !llIgnoreRest
					lnCount = lnCount + processThisLink("t", "B", @llIgnoreRest)		&& Bottom links to top
				ENDIF
		ENDSCAN
	
	
	**********
	* When we get here, we have our metrics
	*****
		? "Found " + TRANSFORM(lnCount) + " in " + tcTable




FUNCTION processThisLink
LPARAMETERS tcLink, tcTable, tlIgnoreRest
LOCAL lnReturn

	**********
	* Grab our data set
	*****
		DO CASE
			CASE LOWER(tcLink+tcTable) = "bt"
				SELECT *, CAST(iid - butterflyCube8a.iid AS Integer) AS nDelta ;
					FROM c_b ;
					WHERE	cB = butterflyCube8a.cKeyT ;		&& Keys match
						AND iid != butterflyCube8a.iid ;		&& Exclude self
					ORDER BY nDelta DESC ;
					INTO CURSOR c_result

			CASE LOWER(tcLink+tcTable) = "rl"
				SELECT *, CAST(iid - butterflyCube8a.iid AS Integer) AS nDelta ;
					FROM c_r ;
					WHERE	cR = butterflyCube8a.cKeyL ;		&& Keys match
						AND iid != butterflyCube8a.iid ;		&& Exclude self
					ORDER BY nDelta DESC ;
					INTO CURSOR c_result

			CASE LOWER(tcLink+tcTable) = "lr"
				SELECT *, CAST(iid - butterflyCube8a.iid AS Integer) AS nDelta ;
					FROM c_l ;
					WHERE	cL = butterflyCube8a.cKeyR ;		&& Keys match
						AND iid != butterflyCube8a.iid ;		&& Exclude self
					ORDER BY nDelta DESC ;
					INTO CURSOR c_result

			CASE LOWER(tcLink+tcTable) = "tb"
				SELECT *, CAST(iid - butterflyCube8a.iid AS Integer) AS nDelta ;
					FROM c_t ;
					WHERE	cT = butterflyCube8a.cKeyB;			&& Keys match
						AND iid != butterflyCube8a.iid ;		&& Exclude self
					ORDER BY nDelta DESC ;
					INTO CURSOR c_result
			OTHERWISE
				* Programming error
				* Need to code for the tcLink+tcTable option...
SET STEP ON
		ENDCASE
		
		* Is the well dry?
		IF _TALLY = 0
			RETURN 0
		ENDIF
		lnReturn = _TALLY


	**********
	* Update our cube
	*****
		SELECT butterflyCube8a
		DO CASE
			CASE LOWER(tcLink+tcTable) = "bt"
				REPLACE nDeltaT		WITH c_result.nDelta, ;
						nCountT		WITH RECCOUNT('c_result')

			CASE LOWER(tcLink+tcTable) = "rl"
				REPLACE nDeltaL		WITH c_result.nDelta, ;
						nCountL		WITH RECCOUNT('c_result')

			CASE LOWER(tcLink+tcTable) = "lr"
				REPLACE nDeltaR		WITH c_result.nDelta, ;
						nCountR		WITH RECCOUNT('c_result')

			CASE LOWER(tcLink+tcTable) = "tb"
				REPLACE nDeltaB		WITH c_result.nDelta, ;
						nCountB		WITH RECCOUNT('c_result')
		ENDCASE


	**********
	* Grab the top 10
	*****
		SELECT TOP 10 ABS(nDelta) AS nDelta ;
			FROM c_result ;
			ORDER BY 1 ASC ;
			INTO CURSOR c_result
		

	**********
	* Average
	*****
		SELECT AVG(nDelta) as nDeltaAvg ;
			FROM c_result ;
			INTO CURSOR c_result


	**********
	* Update our cube
	*****
		SELECT butterflyCube8a
		DO CASE
			CASE LOWER(tcLink+tcTable) = "bt"
				REPLACE nAvgDelT	WITH c_result.nDeltaAvg

			CASE LOWER(tcLink+tcTable) = "rl"
				REPLACE nAvgDelL	WITH c_result.nDeltaAvg

			CASE LOWER(tcLink+tcTable) = "lr"
				REPLACE nAvgDelR	WITH c_result.nDeltaAvg

			CASE LOWER(tcLink+tcTable) = "tb"
				REPLACE nAvgDelB	WITH c_result.nDeltaAvg
		ENDCASE
		IF c_result.nDeltaAvg > RECCOUNT() * 0.01
			* Too far out of range, so we ignore this one
			DELETE IN butterflyCube8a
			tlIgnoreRest = .t.
		ENDIF


	**********
	* Indicate our findings count
	*****
		RETURN lnReturn
