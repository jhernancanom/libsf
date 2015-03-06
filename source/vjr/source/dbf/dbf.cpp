//////////
//
// /libsf/source/vjr/source/dbf/dbf.cpp
//
//////
// Version 0.55
// Copyright (c) 2014 by Rick C. Hodgin
//////
// Last update:
//	   Nov.02.2014
//////
// Change log:
//	   Nov.02.2014 - Initial creation
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
// Called to initialize DBF.
//
/////
	void iDbf_startup(bool tlFirstRun)
	{
		u32 lnI;


		// Store the temporary path
		GetTempPath(sizeof(gcDbf_temporaryPath), (s8*)&gcDbf_temporaryPath);

		// Shut down anything that's currently open or used
		if (!tlFirstRun)
			iDbf_shutdown();

		// Initialize all of the DBF entries (this also means close any that are already open)
		memset((s8*)&gsWorkArea, -1, sizeof(gsWorkArea));


		//////////
		// Initialize table and cursor work areas
		//////
			for (lnI = 0; lnI < _MAX_DBF_SLOTS; lnI++)
			{
				// Initialize everything
				memset(&gsWorkArea[lnI], 0, sizeof(gsWorkArea[lnI]));

				// Set its number
				gsWorkArea[lnI].thisWorkArea = lnI;
			}


		//////////
		// Initialize container work areas
		//////
			for (lnI = 0; lnI < _MAX_DBC_SLOTS; lnI++)
			{
				// Initialize everything
				memset(&gsDbcArea[lnI], 0, sizeof(gsDbcArea[lnI]));

				// Set its number
				gsDbcArea[lnI].thisWorkArea = lnI;
			}
	}









//////////
//
// Called to de-initialize DBF, i.e. to close it down and close all the files, etc.
//
/////
	void iDbf_shutdown(void)
	{
		u32 lnI;


		// Initialize all of the DBF entries (this also means close any that are already open)
		for (lnI=0; lnI<_MAX_DBF_SLOTS; lnI++)
		{
			if (gsWorkArea[lnI].isUsed == _YES)
			{
				// This slot is used
				if (gsWorkArea[lnI].dirty == _YES)
				{
					// And changes need to be written to disk
					iDbf_close(&gsWorkArea[lnI]);
				}
			}
			// Initialize this entry
		}
	}




/////////
//
// Called to see if the particular lock operation should continue
//
//////
	bool iiDbf_continueWithLockOperation(SDiskLockCallback* dcb, s32 tnAttempts, s32 tnMillisecondsSpentThusFar)
	{
		s32			lnType, lnValue, lnMaxAttempts, lnRetryInterval;
		SVariable*	varReprocess;
		s8			buffer[1024];
		SDiskLock*	dl;


		//////////
		// Find out how we're reprocessing
		//////
			dl		= (SDiskLock*)dcb->extra;
			lnType	= iObjProp_getVarAndType(_settings, _INDEX_SET_REPROCESS, &varReprocess);
			if (varReprocess)
			{
				// Grab our interval and max attempts
				lnRetryInterval	= max(min(iObjProp_get_s32_direct(_settings, _INDEX_SET_REPROCESSINTERVAL), _MAX_SLEEP_INTERVAL_BETWEEN_LOCK_FILE_RETRY_ATTEMPTS), _MIN_SLEEP_INTERVAL_BETWEEN_LOCK_FILE_RETRY_ATTEMPTS);
				lnMaxAttempts	= iObjProp_get_s32_direct(_settings, _INDEX_SET_REPROCESSATTEMPTS);

				// Increase our attempted count
				++dl->extra2;

				// Is it logical (automatic reprocessing?)
				switch (lnType)
				{
					case _VAR_TYPE_LOGICAL:
						// SET REPROCESS TO AUTOMATIC
						// Are we beyond our max?
						if (dl->extra2 > lnMaxAttempts)
							return(false);	// We're done retrying, now we fail

						// If we get here, we are retrying again
						Sleep(lnRetryInterval);

						// Retry
						return(true);


					case _VAR_TYPE_S32:
						// SET REPROCESS TO [N|N SECONDS]
						lnValue = iObjProp_get_s32_direct(_settings, _INDEX_SET_REPROCESS);
						if (lnValue < 0)
						{
							// SET REPROCESS TO 30
							// Are we beyond our max?
							if (dl->extra2 > lnMaxAttempts)
								return(false);	// We're done retrying, now we fail

						} else {
							// SET REPROCESS TO 30 SECONDS
							if (dl->extra2 > lnMaxAttempts)
								return(false);	// We're done retrying, now we fail

							// Sleep for our sleep interval
							Sleep(lnRetryInterval);
						}
						// We succeed, retrying immediately
						return(true);
				}
				// Control SHOULD never reach here, if it does it falls through to the internal system error
			}


		//////////
		// Internal system error
		//////
			// Build the error string "_settings.reprocess not found or invalid"
			sprintf(buffer, "%s.%s %s\0", cgc__settings, cgc_reprocess, cgc_notFoundOrInvalidDataType);
			iError_signal(_ERROR_INTERNAL_ERROR, buffer);

			// Indicate no retry
			return(false);
	}




//////////
//
// Open a DBF, its associated memo file, associated CDX if present,
// and associated DBC if not already open.
//
/////
//
// Called to open the specified table, and assign an optional alias name to the table.
// Note:  This feature only opens in shared mode presently.
//
// Parameters:
//		table				-- full path to the table
//		alias				-- alias handle to use (if any)
//
// Returns:
//		work area number			-- Any value BETWEEN(0, _MAX_DBF_SLOTS) indicates success
//		_DBF_ERROR_PROGRAMMER		-- Programmer error, something that should only happen during development
//		_DBF_ERROR_NO_MORE_SLOTS	-- no more slots
//		-3							-- DBC is invalid
//		-4							-- DBF not found
//		-5							-- associated memo file not found
//		Errors below -100			-- CDX errors
//		Errors below -200			-- DBC errors
//
/////
	uptr iDbf_open(SVariable* table, SVariable* alias, bool tlExclusive, bool tlAgain)
	{
		s8 tableBuffer[_MAX_PATH + 1];
		s8 aliasBuffer[_MAX_PATH + 1];


		// Make sure our environment is sane
		if (table && alias && table->value.data && alias->value.data && table->value.length >= 1 && alias->value.length >= 1)
		{
			//////////
			// Initialize
			//////
				// Null
				memset(tableBuffer, 0, sizeof(tableBuffer));
				memset(aliasBuffer, 0, sizeof(aliasBuffer));

				// Copy
				memcpy(tableBuffer, table->value.data_s8, min(_MAX_PATH, table->value.length));
				memcpy(aliasBuffer, alias->value.data_s8, min(_MAX_PATH, alias->value.length));


			//////////
			// Open
			//////
				return(iDbf_open(tableBuffer, aliasBuffer, tlExclusive, tlAgain));
		}

		// Should never happen
		// If we get here, something was not provided properly by the developer working on writing VJr C/C++ code
		return(_DBF_ERROR__INTERNAL_PROGRAMMER);
	}


	// Note:  table and alias must be NULL-terminated
	// Note:  an alias is not required
	uptr iDbf_open(cs8* table, cs8* alias, bool tlExclusive, bool tlAgain)
	{
		s32				lnI, lnI_max;
		sptr			lnWorkArea, lnLength;
		u32				lnField, lnFieldNameLength, lShareFlag, lStructure_size, numread;
		s32*			lnCurrentWorkArea;
		bool			llDbcIsValid;
		SFieldRecord1*	lfrPtr;
		SFieldRecord2*	lfr2Ptr;
		SWorkArea*		waBase;
		SWorkArea*		wa;
		union {
			uptr		_validateStruture;
			bool		(*validateStructure)(SWorkArea* wa);
		};


		//////////
		// Based on the type of table, it goes into its own area
		//////
			lnLength = strlen(alias);
			if (lnLength == sizeof(cgcDbcKeyName) - 1 && _memicmp(alias, cgcDbcKeyName, lnLength) == 0)
			{
				// It's a DBC
				lnI					= gnDbc_currentWorkArea;
				lnCurrentWorkArea	= &gnDbc_currentWorkArea;
				lnI_max				= _MAX_DBC_SLOTS;
				waBase				= &gsDbcArea[0];
				_validateStruture	= (uptr)&iiDbf_validate_isDbc;

			} else if (lnLength == sizeof(cgcScxKeyName) - 1 && _memicmp(alias, cgcScxKeyName, lnLength) == 0) {
				// It's an SCX
				lnI					= gnScx_currentWorkArea;
				lnCurrentWorkArea	= &gnScx_currentWorkArea;
				lnI_max				= _MAX_SCX_SLOTS;
				waBase				= &gsScxArea[0];
				_validateStruture	= (uptr)&iiDbf_validate_isScx;

			} else if (lnLength == sizeof(cgcVcxKeyName) - 1 && _memicmp(alias, cgcVcxKeyName, lnLength) == 0) {
				// It's an VCX
				lnI					= gnVcx_currentWorkArea;
				lnCurrentWorkArea	= &gnVcx_currentWorkArea;
				lnI_max				= _MAX_VCX_SLOTS;
				waBase				= &gsVcxArea[0];
				_validateStruture	= (uptr)&iiDbf_validate_isVcx;

			} else if (lnLength == sizeof(cgcFrxKeyName) - 1 && _memicmp(alias, cgcFrxKeyName, lnLength) == 0) {
				// It's an FRX
				lnI					= gnFrx_currentWorkArea;
				lnCurrentWorkArea	= &gnFrx_currentWorkArea;
				lnI_max				= _MAX_FRX_SLOTS;
				waBase				= &gsFrxArea[0];
				_validateStruture	= (uptr)&iiDbf_validate_isFrx;

			} else if (lnLength == sizeof(cgcMnxKeyName) - 1 && _memicmp(alias, cgcMnxKeyName, lnLength) == 0) {
				// It's an MNX
				lnI					= gnMnx_currentWorkArea;
				lnCurrentWorkArea	= &gnMnx_currentWorkArea;
				lnI_max				= _MAX_MNX_SLOTS;
				waBase				= &gsMnxArea[0];
				_validateStruture	= (uptr)&iiDbf_validate_isMnx;

			} else {
				// It's a table
				lnI					= gnDbf_currentWorkArea;
				lnCurrentWorkArea	= &gnDbf_currentWorkArea;
				lnI_max				= _MAX_DBF_SLOTS;
				waBase				= &gsWorkArea[0];
				_validateStruture	= (uptr)0;
			}



		//////////
		// If we need to select the lowest work area, do so
		//////
			if (lnI == -1)
			{
				// Search for the first free open one
				for (lnI = 0; lnI < lnI_max; lnI++)
				{
					if (waBase[lnI].isUsed == _NO)
					{
						// Update the current work area
						*lnCurrentWorkArea = lnI;
						break;
					}
				}

				// When we get here, we're either good or not good. :-)
				if (lnI >= lnI_max)
				{
					// Not good, no unused work areas were found
					return(_DBF_ERROR_NO_MORE_WORK_AREAS);
				}
			}

			
		//////////
		// We can only populate into the indicated work area
		//////
			if (waBase[lnI].isUsed != _NO)
			{
				// This slot is already in use, and therefore invalid
				return(_DBF_ERROR_WORK_AREA_ALREADY_IN_USE);
			}
			wa = waBase + lnI;


		//////////
		// Valid slot
		//////
			wa->thisWorkArea = lnI;


		//////////
		// Initialize
		//////
			memset(wa->tablePathname,	0, sizeof(wa->tablePathname));
			memset(wa->alias,			0, sizeof(wa->alias));
			memset(wa->indexPathname,	0, sizeof(wa->indexPathname));


		//////////
		// Copy the user portion of the names
		//////
			wa->tablePathnameLength = (s32)strlen(table);
			if (wa->tablePathnameLength >= (s32)sizeof(wa->tablePathname))
			{
				// Table filename is too long
				return(_DBF_ERROR_TABLE_NAME_TOO_LONG);
			}
			memcpy(wa->tablePathname, table, wa->tablePathnameLength);
			if (alias != NULL)
			{
				// The alias is allowed to be as long as the alias space is, or shorter
				wa->aliasLength = (((s32)strlen(alias) >= (s32)sizeof(wa->alias)) ? (s32)sizeof(wa->alias) : (u32)strlen(alias));
				memcpy(wa->alias, alias, wa->aliasLength);
			}


		//////////
		// Set the flags based on shared or exclusive
		//////
			if (tlExclusive)
			{
				// Exclusive
				lShareFlag = _SH_DENYRW;	// Deny reads and writes

			} else {
				// Shared
				lShareFlag = _SH_DENYNO;	// Deny none
			}


		//////////
		// Open the table based on the shared/exclusive mode
		//////
			wa->fhDbf = _sopen(table, _O_BINARY | _O_RDWR, lShareFlag);
			if (wa->fhDbf == null0)
			{
				// Unable to open
				// See if it's already open and if we can use it again
				if (tlAgain && (lnWorkArea = iDbf_get_workArea_byTablePathname(table, null)) >= 0)
				{
					// We found the work area where this table is already open ... share its file handle
					wa->fhDbf = _dup(gsWorkArea[lnWorkArea].fhDbf);
				}
				
				if (wa->fhDbf == null0)
				{
					// Unable to open the specified table
					return(_DBF_ERROR_TABLE_NOT_FOUND);
				}
			}


		//////////
		// Read the header
		//////
			numread = (u32)_read(wa->fhDbf, &wa->header, sizeof(wa->header));
			if (numread != sizeof(wa->header))
			{
				// Unable to read the header
				_close(wa->fhDbf);
				return(_DBF_ERROR_ERROR_READING_HEADER1);
			}


//////////
// Recognized DBF types:
// 		0x02   FoxBASE
// 		0x03   FoxBASE+/dBASE III plus, no memo
// 		0x30   Visual FoxPro
// 		0x31   Visual FoxPro, auto-increment enabled
// 		0x83   FoxBASE+/dBASE III PLUS, with memo
// 		0xf5   FoxPro 2.x (or earlier) with memo
// 		0xfb   FoxBASE
//
// Not currently supported:
// 		0x43   dBASE IV SQL table files, no memo
// 		0x63   dBASE IV SQL system files, no memo
// 		0x8B   dBASE IV with memo
// 		0xcb   dBASE IV SQL table files, with memo
//////
		//////////
		// Parse the header
		//////
			wa->isVisualTable = false;
			switch (wa->header.type)
			{
				case 0x30:		// Visual FoxPro 3.0 or higher
				case 0x31:		// Visual FoxPro 3.0 or higher, with autoincrement enabled
					wa->isVisualTable = true;
					break;

				case 0x02:		// FoxBASE, no memo
				case 0x03:		// FoxBASE+, no memo
					break;

				case 0x83:		// FoxBASE+, with memo
				case 0xf5:		// FoxPro 2.x (or earlier), with memo
				case 0xfb:		// FoxBASE, with memo
					break;

				default:
					// No idea.	 So, we'll say it's a bad, bad table.
					_close(wa->fhDbf);
					return(_DBF_ERROR_UNKNOWN_TABLE_TYPE);
			}


		//////////
		// Allocate enough memory for the table structure
		//////
			lStructure_size		= wa->header.firstRecord - sizeof(STableHeader);
			wa->fieldPtr1		= (SFieldRecord1*)malloc(lStructure_size);
			if (wa->fieldPtr1 == NULL)
			{
				_close(wa->fhDbf);
				return(_DBF_ERROR_MEMORY);
			}


		//////////
		// Read in the fields
		//////
			_lseek(wa->fhDbf, sizeof(STableHeader), SEEK_SET);
			numread = (u32)_read(wa->fhDbf, wa->fieldPtr1, lStructure_size);
			if (numread != lStructure_size)
			{
				_close(wa->fhDbf);
				return(_DBF_ERROR_ERROR_READING_HEADER2);
			}


		//////////
		// Parse the fields to determine the count
		//////
			lfrPtr			= wa->fieldPtr1;
			wa->fieldCount	= 0;
			while (lfrPtr->name[0] != 0 && lfrPtr->name[0] != 13)
			{
				//////////
				// Increase the field count
				//////
					++wa->fieldCount;


				//////////
				// Set the index fixup for this field (if any)
				//////
					switch (lfrPtr->type)
					{
						case 'I':	// 4-byte integer (s32)
						case 'Y':	// currency, which is technically an 8-byte integer (s64)
							lfrPtr->indexFixup	= _DBF_INDEX_FIXUP_SWAP_ENDIAN;
							lfrPtr->fillChar	= 0;
							break;

						case 'B':	// Double (f64)
							lfrPtr->indexFixup	= _DBF_INDEX_FIXUP_FLOAT_DOUBLE;
							lfrPtr->fillChar	= 0;
							break;

						case 'D':	// Date
							lfrPtr->indexFixup	= _DBF_INDEX_FIXUP_DATE;
							lfrPtr->fillChar	= 32;
							break;

						case 'T':	// Datetime, needs 2nd DWORD fixed up as it is a float (f32)
							lfrPtr->indexFixup	= _DBF_INDEX_FIXUP_DATETIME;
							lfrPtr->fillChar	= 0;
							break;

						case 'L':	// Logical
							lfrPtr->indexFixup	= _DBF_INDEX_FIXUP_LOGICAL;
							lfrPtr->fillChar	= 32;
							break;

						case 'F':	// Float
						case 'N':	// Numeric
							lfrPtr->indexFixup	= _DBF_INDEX_FIXUP_NUMERIC;
							lfrPtr->indexFixup_lengthOverride = 8;										// 8 for f64, and -1 to indicate it's valid
							lfrPtr->fillChar	= 32;
							break;

						case 'M':	// Memo
						case 'W':	// Blob
						case 'G':	// General
						case 'Q':	// Varbinary
						case 'V':	// Varchar
							lfrPtr->indexFixup	= _DBF_INDEX_FIXUP_NONE;
							lfrPtr->fillChar	= 0;
							break;

						case 'C':	// Character
							lfrPtr->indexFixup	= _DBF_INDEX_FIXUP_NONE;
							lfrPtr->fillChar	= 32;

						default:
							lfrPtr->indexFixup	= _DBF_INDEX_FIXUP_NONE;
							lfrPtr->fillChar	= 32;
							break;
					}

					// Add in the flag for NULL if possible
					if (lfrPtr->flags & _DBF_FIELD_NULLS)
						lfrPtr->indexFixup |= _DBF_INDEX_FIXUP_NULL;


				// Move to the next field in the field structure
				++lfrPtr;
			}
			// When we get here, lfrPtr is pointing to the structure termination byte.
			// If this table has a container, the next byte will be the start of the relative backlink to the table
			wa->backlink = (s8*)lfrPtr + 1;	// +1 skips past the trailing CHR(13) which terminates the structure list


		//////////
		// If it's a visual table, it might have a DBC backlink
		//////
			if (wa->isVisualTable)
			{
				// Backlink is specified
				wa->backlinkLength	= (u32)strlen(wa->backlink);

			} else {
				// No backlink
				wa->backlinkLength	= 0;
			}


		//////////
		// For each field, determine its name length
		//////
			lfrPtr = wa->fieldPtr1;
			for (lnField = 0; lnField < wa->fieldCount; lnField++, lfrPtr++)
			{
// TODO:  We could possibly use strlen() here ... I don't remember for sure if it's always NULL terminated at 11th char.
				lfrPtr->fieldName_length = 0;
				for (lnFieldNameLength = 0; lnFieldNameLength < 10 && lfrPtr->name[lnFieldNameLength] != 0; lnFieldNameLength++)
					++lfrPtr->fieldName_length;
			}
			// When we get here, all of the fields have their field length as well


		//////////
		// Copy to the SFieldRecord2.  If it's part of a container, flush out the full name.
		//////
			wa->field2Ptr = (SFieldRecord2*)malloc(wa->fieldCount * sizeof(SFieldRecord2));
			memset(wa->field2Ptr, 0, wa->fieldCount * sizeof(SFieldRecord2));

			lfrPtr	= wa->fieldPtr1;
			lfr2Ptr	= wa->field2Ptr;
			for (lnField = 1; lnField <= wa->fieldCount; lnField++, lfrPtr++, lfr2Ptr++)
			{
				//////////
				// Copy the short names over
				//////
					memcpy(lfr2Ptr->name,	lfrPtr->name, 11);		// Copy the full short name
					memcpy(lfr2Ptr->name2,	lfrPtr->name, 11);		// Copy the full short name
					lfr2Ptr->fieldName_length = (s32)strlen((s8*)lfrPtr->name);


				//////////
				// Copy normal attributes
				//////
					lfr2Ptr->type			= lfrPtr->type;
					lfr2Ptr->offset			= lfrPtr->offset;
					lfr2Ptr->length			= lfrPtr->length;
					lfr2Ptr->decimals		= lfrPtr->decimals;
					lfr2Ptr->flags			= lfrPtr->flags;
					lfr2Ptr->fieldNumber	= lnField;
					lfr2Ptr->autoIncNext	= lfrPtr->autoIncNext;
					lfr2Ptr->autoIncStep	= lfrPtr->autoIncStep;
					lfr2Ptr->indexFixup		= lfrPtr->indexFixup;
					lfr2Ptr->fillChar		= lfrPtr->fillChar;
			}


		//////////
		// Reset the pointers
		//////
			lfrPtr	= wa->fieldPtr1;
			lfr2Ptr	= wa->field2Ptr;


		//////////
		// See if there's an entry in the container for this table,
		// and if so update the field names to their longer form
		//////
			if (wa->isVisualTable && wa->backlinkLength != 0)
			{
				// Try to open the backlink
				iiDbc_lookupTableField(&gsWorkArea[lnI], &llDbcIsValid, tlExclusive);
				// llDbcIsValid is populated as a passed-in return parameter

			} else {
				// Simulate true in the absence of a DBC backlink
				llDbcIsValid = true;
			}


		//////////
		// Allocate enough space for one row of data
		// Active data changed per current row
		//////
			wa->data = (s8*)malloc(wa->header.recordLength);
			if (wa->data == NULL)
			{
				_close(wa->fhDbf);
				return(_DBF_ERROR_MEMORY_ROW);
			}
			memset(wa->data, 0, wa->header.recordLength);


		//////////
		// Allocate enough space for one row of data
		// Original data
		//////
			wa->odata = (s8*)malloc(wa->header.recordLength);
			if (wa->odata == NULL)
			{
				_close(wa->fhDbf);
				return(_DBF_ERROR_MEMORY_ORIGINAL);
			}
			memset(wa->odata, 0, wa->header.recordLength);		// For original copy of loaded data (allows reversion)


		//////////
		// Allocate enough space for one row of data
		// Index data (for the creation of index keys, population of a data source for key generation, without affecting the current row's record data)
		//////
			wa->idata = (s8*)malloc(wa->header.recordLength);
			if (wa->idata == NULL)
			{
				_close(wa->fhDbf);
				return(_DBF_ERROR_MEMORY_INDEX);
			}
			memset(wa->idata, 0, wa->header.recordLength);		// For original copy of loaded data (allows reversion)


		//////////
		// We're done!
		// Right now, the structure has been loaded into gsWorkArea[i].fieldPtr1, and gsWorkArea[i].field2ptr
		//////////


		//////////
		// Move to the first record
		//////
// TODO:  If CDX is populated, and a primary key is specified, we need to position to that tag's first index key's record
			iDbf_gotoRecord(wa, 1);


		//////////
		// If it wasn't valid, we need to now close it
		//////
			if (!llDbcIsValid)
			{
				// Close what we've opened, and un-allocate what we've allocated
				iDbf_close(wa);
				return(_DBF_ERROR_DBC);
			}


		//////////
		// Success.
		// Set initial flags
		//////
			wa->isIndexLoaded	= _NO;
			wa->isCached		= _NO;
			wa->currentRecord	= 0;
			wa->isUsed			= _YES;


		//////////
		// Return the current work area number
		//////
			return(lnI);
	}




//////////
//
// open remote
//
/////
//
// Called to open the specified table from a remote ODBC data source, and allocate
// a local cursor to handle data storage, indexing, etc., and assign an optional
// alias name to the table.
//
// Parameters:
//		table	   - full path to the table
//		alias	   - alias handle to use (if any)
//
// Returns:
//		slot number used to access the entry they created,
//		or -1 if error
//		or -2 if no more slots
//		or -3 if DBC is invalid
//
//////
	uptr iDbf_openRemote(s8* connString)
	{
		return(0);
// Note: This is a placeholder function outlining the steps necessary to access and retrieve remote content
// #define	SQL_QUERY_SIZE 4096
// 		SQLRETURN		lnResult;
// 		SQLHANDLE		lpEnv;
// 		SQLHANDLE		lpDbc;
// 		SQLHANDLE		lpStmt;
// 		SQLHDBC			handle;
// 		SQLCHAR			serverName[128], userName[128], password[128];
// 		SQLSMALLINT		serverNameLength, userNameLength, passwordLength, cchDisplay, cchColumnNameLength, ssType;
// 		SQLUSMALLINT	lnCol, colCount;
// 		SQLINTEGER		lnRow, rowCount;
// 		s8				expression[SQL_QUERY_SIZE + 1];
// 		SQLPOINTER		field;
// 		SQLINTEGER		fieldLength;
// 
// 
// 		lnResult = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &lpEnv);
// 		if (lnResult == SQL_ERROR)
// 			return(-1);
// 
// 		SQLSetEnvAttr(lpEnv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0);
// 		SQLAllocHandle(SQL_HANDLE_DBC, lpEnv, &lpDbc);
// 		SQLDriverConnect(lpDbc, GetDesktopWindow(), (SQLCHAR*)connString, SQL_NTS, NULL, 0, NULL, SQL_DRIVER_COMPLETE);
// 		SQLConnect(handle, serverName, serverNameLength, userName, userNameLength, password, passwordLength);
// 		SQLAllocHandle(SQL_HANDLE_STMT, lpDbc, &lpStmt);
// 
// 		lnResult = SQLExecDirect(lpStmt, (SQLCHAR*)expression, SQL_NTS);
// 		switch (lnResult)
// 		{
// 			case SQL_SUCCESS_WITH_INFO:
// 				// An error
// 				break;
// 
// 			case SQL_SUCCESS:
// 				// Success
// 				SQLNumResultCols(lpStmt, (SQLSMALLINT*)&colCount);		// Columns
// 				SQLRowCount		(lpStmt, &rowCount);					// Rows
// 
// 
// 				//////////
// 				// For each column
// 				//////
// 					for (lnCol = 0; lnCol < colCount; lnCol++)
// 					{
// 						SQLColAttribute	(lpStmt, lnCol, SQL_DESC_DISPLAY_SIZE,	NULL, 0, NULL, &cchDisplay);
// 						SQLColAttribute	(lpStmt, lnCol, SQL_DESC_CONCISE_TYPE,	NULL, 0, NULL, &ssType);
// 						SQLColAttribute	(lpStmt, lnCol, SQL_DESC_NAME,			NULL, 0, &cchColumnNameLength, NULL);
// 
// 						// Content for each column
// 						SQLBindCol		(lpStmt, lnCol, SQL_C_CHAR,				field, (cchDisplay + 1), &fieldLength);
// 					}
// 
// 
// 				//////////
// 				// For each row
// 				//////
// 					for (lnRow = 0; lnRow < rowCount; lnRow++)
// 					{
// 						SQLFetch(lpStmt);
// 
// 						// Content is pulled into the field values from the SQLBindCol content
// 					}
// 				break;
// 
// 			case SQL_ERROR:
// 				// Error
// 				break;
// 
// 			default:
// 				// Unexpected error
// 				break;
// 		}
// 
//		SQLGetDiagRec(hType, hHandle, ++iRec, szState, &iError, szMessage, (SQLSMALLINT)(sizeof(szMessage) / sizeof(TCHAR)), (SQLSMALLINT *)NULL);
//		SQLFreeStmt(lpStmt, SQL_CLOSE);
// 		SQLDisconnect(lpDbc);
// 		SQLFreeConnect(lpDbc);
// 		SQLFreeEnv(lpEnv);
	}




//////////
//
// Called to cache the table into memory for fast processing.
// Note:  If the row has changed content, it will be lost in this operation.  Must flush first.
//
//////
	uptr iDbf_cacheAllRowData(SWorkArea* wa)
	{
		u64 lnCacheSize, lnOriginalFilePosition, lnNumread;


		// Make sure it's valid
		if (!iDbf_isWorkAreaValid(wa, NULL))
			return(_DBF_ERROR__INTERNAL_PROGRAMMER);
		if (wa->isUsed != _YES)
			return(_DBF_ERROR_WORK_AREA_NOT_IN_USE);


		// Find out how big the file is
		lnOriginalFilePosition = _telli64(wa->fhDbf);
		_lseeki64(wa->fhDbf, 0, SEEK_END);
		lnCacheSize = _telli64(wa->fhDbf) - (u32)wa->header.firstRecord;
		_lseeki64(wa->fhDbf, wa->header.firstRecord, SEEK_SET);


		// If we're smaller than 200 MB we'll go ahead and cache, otherwise ... not so much
		if (lnCacheSize > 200 * 1024 * 1000)
			return(-5);		// Too big to cache


		// Allocate that much space
		wa->cachedTable = (s8*)malloc((size_t)lnCacheSize);
		if (wa->cachedTable)
		{
			// Read in the table
			lnNumread = _read(wa->fhDbf, wa->cachedTable, (u32)lnCacheSize);
			if (lnNumread != lnCacheSize)
				return(-1);

			// Raise the flag
			wa->isCached = true;

			// Free data
			iiFreeAndSetToNull((void **)&wa->data);

			// Reset the file pointer to where it was
			_lseeki64(wa->fhDbf, lnOriginalFilePosition, SEEK_SET);

			// Set data to where it should be in the cache
			iDbf_gotoRecord(wa, wa->currentRecord);

			// Indicate success
			return((u32)lnCacheSize);
		}
		// If we get here, unable to allocate
		return(-4);
	}




//////////
//
// Called to close the specified table/slot
//
// Parameters:
//	slot	- Slot to access
//
// Returns:
//	slot number used to access the entry they created, or -1 if error
//
/////
	uptr iDbf_close(SWorkArea* wa)
	{
		// Make sure it's valid
		if (!iDbf_isWorkAreaValid(wa, NULL))
			return(_DBF_ERROR__INTERNAL_PROGRAMMER);
		if (wa->isUsed != _YES)
			return(_DBF_OKAY);	// Already closed


		// Close the file handle
		_close(wa->fhDbf);				// Note:  No non-null checking here because: a) It should never be non-null and b) if it is, we don't care because we're making it that way anyway
		wa->fhDbf = 0;


		// Release the memory
		iiFreeAndSetToNull((void **)&wa->fieldPtr1);

		// For data we either use it as a pointer into the cache, or as a real holder of line data
		if (wa->isCached)
		{
			// Free cacheData
			iiFreeAndSetToNull((void **)&wa->cachedTable);

		} else {
			// Free data
			iiFreeAndSetToNull((void **)&wa->data);
		}

		// Release our original record buffer
		if (wa->odata != NULL && wa->odata != (s8*)-1)
			iiFreeAndSetToNull((void **)&wa->odata);

		// Release our buffer for building index keys
		if (wa->idata != NULL && wa->idata != (s8*)-1)
			iiFreeAndSetToNull((void **)&wa->idata);


		// Close the slot
		wa->isUsed = _NO;
		return(0);
	}




//////////
//
// Returns 1 if the DBF has an associated CDX file based upon its name.	 Note that this test
// does not already look to see if the CDX is open, but rather looks for a CDX which is its
// full pathname with the .CDX extension, if that file exists on disk.	It also does not do
// a sanity check to see if the CDX is actually valid or not.
//
//////
	uptr iDbf_hasCdx(SWorkArea* wa)
	{
		WIN32_FIND_DATA		ffd;
		HANDLE				hFind;
		s8					cdxName[_MAX_PATH];


		//////////
		// Check for errors
		//////
			// Make sure it's valid
			if (!iDbf_isWorkAreaValid(wa, NULL))
				return(_DBF_ERROR__INTERNAL_PROGRAMMER);
			if (wa->isUsed != _YES)
				return(_DBF_ERROR_WORK_AREA_NOT_IN_USE);


		//////////
		// Get the CDX filename
		//////
// TODO:  Since JUSTPATH() and JUSTSTEM() have been written, this can be modified to use those functions
			memset(cdxName, 0, sizeof(cdxName));
			memcpy(cdxName, wa->tablePathname, wa->tablePathnameLength);
			memcpy(cdxName + wa->tablePathnameLength - 4, ".cdx", 4);


		//////////
		// See if that file exists
		//////
			hFind = FindFirstFile(cdxName, &ffd);
			if (hFind == INVALID_HANDLE_VALUE)		return(0);		// Not found
			else									return(1);		// Found
	}




//////////
//
// Called to see if the indicated work area is valid, and also to identify which
// type of work area it is.
//
//////
	bool iDbf_isWorkAreaValid(SWorkArea* wa, cu8** tcSpecialWorkAreaKeyName)
	{
		// Make sure our environment is sane
		if (wa)
		{
			// DBF?
			if (wa >= &gsWorkArea[0] && wa < &gsWorkArea[_MAX_DBF_SLOTS])
			{
				// It is a DBF
				if (tcSpecialWorkAreaKeyName)
				{
					// Is it a cursor?
					if (wa->isCursor)		*tcSpecialWorkAreaKeyName = &cgcDbfKeyName[0];		// Cursor
					else					*tcSpecialWorkAreaKeyName = NULL;					// Regular table
				}

				// It is valid
				return(true);

			} else if (wa >= &gsDbcArea[0]	&& wa < &gsDbcArea[_MAX_DBC_SLOTS]) {
				// It is a DBC
				if (tcSpecialWorkAreaKeyName)
					*tcSpecialWorkAreaKeyName	= &cgcDbcKeyName[0];

				// It is valid
				return(true);

			} else if (wa >= &gsScxArea[0]	&& wa < &gsScxArea[_MAX_SCX_SLOTS]) {
				// It is an SCX
				if (tcSpecialWorkAreaKeyName)
					*tcSpecialWorkAreaKeyName	= &cgcScxKeyName[0];

				// It is valid
				return(true);

			} else if (wa >= &gsVcxArea[0]	&& wa < &gsVcxArea[_MAX_VCX_SLOTS]) {
				// It is a VCX
				if (tcSpecialWorkAreaKeyName)
					*tcSpecialWorkAreaKeyName	= &cgcVcxKeyName[0];

				// It is valid
				return(true);

			} else if (wa >= &gsFrxArea[0]	&& wa < &gsFrxArea[_MAX_FRX_SLOTS]) {
				// It is a FRX
				if (tcSpecialWorkAreaKeyName)
					*tcSpecialWorkAreaKeyName	= &cgcFrxKeyName[0];

				// It is valid
				return(true);

			} else if (wa >= &gsMnxArea[0]	&& wa < &gsMnxArea[_MAX_MNX_SLOTS]) {
				// It is a MNX
				if (tcSpecialWorkAreaKeyName)
					*tcSpecialWorkAreaKeyName	= &cgcMnxKeyName[0];

				// It is valid
				return(true);
			}
		}


		//////////
		// If we get here, it's not valid
		//////
			return(false);
	}




//////////
//
// Called to verify the pointer is valid
//
//////
	bool iDbf_isWorkAreaUsed(SWorkArea* wa, bool* tlIsValidWorkArea)
	{
		// Make sure it's valid
		if (!iDbf_isWorkAreaValid(wa, NULL))
		{
			// Invalid work area
			if (tlIsValidWorkArea)
				*tlIsValidWorkArea = false;

			// Obviously not used. :-)
			return(false);
		}

		// Valid work area
		if (tlIsValidWorkArea)
			*tlIsValidWorkArea = true;

		// Is it used?
		return(wa->isUsed == _YES);
	}




//////////
//
// Valid letters are A..J, work areas 1..10
//
//////
	bool iDbf_isWorkAreaLetter(SVariable* var)
	{
		s8 c;


		// It must be character, length=1, and A..J
		if (var && var->varType == _VAR_TYPE_CHARACTER && var->value.data_s8 && var->value.length == 1)
		{
			// Indicate if it is A..J
			c = iUpperCase(var->value.data_s8[0]);
			return(c >= 'A' && c <= 'J');
		}

		// Indicate nope
		return(false);
	}




//////////
//
// Called to obtain a work area.
//
//////
	sptr iDbf_set_workArea_current(u32 tnWorkArea, cu8* tcSpecialKeyName)
	{
		// See what they're searching for
		if (!tcSpecialKeyName || tcSpecialKeyName == cgcDbfKeyName)
		{
			// It's a standard DBF
			if (tnWorkArea < _MAX_DBF_SLOTS)
				gnDbf_currentWorkArea = tnWorkArea;

			// Indicate the (potentially) new work area number
			return(gnDbf_currentWorkArea);

		} else if (tcSpecialKeyName == cgcDbcKeyName) {
			// It's a DBC
			if (tnWorkArea < _MAX_DBC_SLOTS)
				gnDbc_currentWorkArea = tnWorkArea;

			// Indicate the (potentially) new work area number
			return(gnDbc_currentWorkArea);

		} else if (tcSpecialKeyName == cgcScxKeyName) {
			// It's an SCX
			if (tnWorkArea < _MAX_SCX_SLOTS)
				gnScx_currentWorkArea = tnWorkArea;

			// Indicate the (potentially) new work area number
			return(gnScx_currentWorkArea);

		} else if (tcSpecialKeyName == cgcVcxKeyName) {
			// It's a VCX
			if (tnWorkArea < _MAX_VCX_SLOTS)
				gnVcx_currentWorkArea = tnWorkArea;

			// Indicate the (potentially) new work area number
			return(gnVcx_currentWorkArea);

		} else if (tcSpecialKeyName == cgcFrxKeyName) {
			// It's an FRX
			if (tnWorkArea < _MAX_FRX_SLOTS)
				gnFrx_currentWorkArea = tnWorkArea;

			// Indicate the (potentially) new work area number
			return(gnFrx_currentWorkArea);

		} else if (tcSpecialKeyName == cgcMnxKeyName) {
			// It's an MNX
			if (tnWorkArea < _MAX_MNX_SLOTS)
				gnMnx_currentWorkArea = tnWorkArea;

			// Indicate the (potentially) new work area number
			return(gnMnx_currentWorkArea);
		}

		// If we get here, it's an unknown type
		return(-1);
	}

	sptr iDbf_get_workArea_current(cu8* tcSpecialKeyName)
	{
		// See what they're searching for
		if (!tcSpecialKeyName || tcSpecialKeyName == cgcDbfKeyName)
		{
			// It's a standard DBF
			return(gnDbf_currentWorkArea);

		} else if (tcSpecialKeyName == cgcDbcKeyName) {
			// It's a DBC
			return(gnDbc_currentWorkArea);

		} else if (tcSpecialKeyName == cgcScxKeyName) {
			// It's an SCX
			return(gnScx_currentWorkArea);

		} else if (tcSpecialKeyName == cgcVcxKeyName) {
			// It's a VCX
			return(gnVcx_currentWorkArea);

		} else if (tcSpecialKeyName == cgcFrxKeyName) {
			// It's an FRX
			return(gnFrx_currentWorkArea);

		} else if (tcSpecialKeyName == cgcMnxKeyName) {
			// It's an MNX
			return(gnMnx_currentWorkArea);
		}

		// If we get here, it's an unknown type
		return(-1);
	}

	sptr iDbf_get_workArea_lowestFree(cu8* tcSpecialKeyName)
	{
		s32			lnI, lnI_max;
		SWorkArea*	wa;


		// See what they're searching for
		if (!tcSpecialKeyName || tcSpecialKeyName == cgcDbfKeyName)
		{
			// It's a standard DBF
			lnI_max	= _MAX_DBF_SLOTS;
			wa		= &gsWorkArea[0];

		} else if (tcSpecialKeyName == cgcDbcKeyName) {
			// It's a DBC
			lnI_max	= _MAX_DBC_SLOTS;
			wa		= &gsDbcArea[0];

		} else if (tcSpecialKeyName == cgcScxKeyName) {
			// It's an SCX
			lnI_max	= _MAX_SCX_SLOTS;
			wa		= &gsScxArea[0];

		} else if (tcSpecialKeyName == cgcVcxKeyName) {
			// It's a VCX
			lnI_max	= _MAX_VCX_SLOTS;
			wa		= &gsVcxArea[0];

		} else if (tcSpecialKeyName == cgcFrxKeyName) {
			// It's an FRX
			lnI_max	= _MAX_FRX_SLOTS;
			wa		= &gsFrxArea[0];

		} else if (tcSpecialKeyName == cgcMnxKeyName) {
			// It's an MNX
			lnI_max	= _MAX_MNX_SLOTS;
			wa		= &gsMnxArea[0];

		} else {
			// If we get here, it's an unknown type
			return(-1);
		}


		//////////
		// Iterate through every work area finding the lowest number
		//////
			for (lnI = 0; lnI < lnI_max; lnI++)
			{
				// If it's free, return it
				if (wa->isUsed == _NO)
					return(lnI);
			}


		// If we get here, they're all used
		return(-1);
	}

	sptr iDbf_get_workArea_highestFree(cu8* tcSpecialKeyName)
	{
		s32			lnI, lnI_max;
		SWorkArea*	wa;


		// See what they're searching for
		if (!tcSpecialKeyName || tcSpecialKeyName == cgcDbfKeyName)
		{
			// It's a standard DBF
			lnI_max	= _MAX_DBF_SLOTS;
			wa		= &gsWorkArea[0];

		} else if (tcSpecialKeyName == cgcDbcKeyName) {
			// It's a DBC
			lnI_max	= _MAX_DBC_SLOTS;
			wa		= &gsDbcArea[0];

		} else if (tcSpecialKeyName == cgcScxKeyName) {
			// It's an SCX
			lnI_max	= _MAX_SCX_SLOTS;
			wa		= &gsScxArea[0];

		} else if (tcSpecialKeyName == cgcVcxKeyName) {
			// It's a VCX
			lnI_max	= _MAX_VCX_SLOTS;
			wa		= &gsVcxArea[0];

		} else if (tcSpecialKeyName == cgcFrxKeyName) {
			// It's an FRX
			lnI_max	= _MAX_FRX_SLOTS;
			wa		= &gsFrxArea[0];

		} else if (tcSpecialKeyName == cgcMnxKeyName) {
			// It's an MNX
			lnI_max	= _MAX_MNX_SLOTS;
			wa		= &gsMnxArea[0];

		} else {
			// If we get here, it's an unknown type
			return(-1);
		}


		//////////
		// Iterate backward through every work area finding the lowest number
		//////
			for (lnI = lnI_max - 1; lnI >= 0; lnI++)
			{
				// If it's free, return it
				if (wa->isUsed == _NO)
					return(lnI);
			}


		// Indicate the slot
		return(lnI);
	}

	// Note:  This algorithm can be fooled, such as mapping a network location to K: and J:
	sptr iDbf_get_workArea_byTablePathname(SVariable* varTablePathname, cu8* tcSpecialKeyName)
	{
//		SWorkArea*	wa;
		s8			table[_MAX_PATH];


		// Make sure our environment is sane
		if (varTablePathname && varTablePathname->varType == _VAR_TYPE_CHARACTER && varTablePathname->value.data_s8 && varTablePathname->value.length >= 1 && varTablePathname->value.length < (s32)sizeof(gsWorkArea[0].tablePathname))
		{
			// See what they're searching for
			if (!tcSpecialKeyName || tcSpecialKeyName == cgcDbfKeyName)
			{
				// It's a standard DBF
//				wa = &gsWorkArea[0];

			} else if (tcSpecialKeyName == cgcDbcKeyName) {
				// It's a DBC
//				wa = &gsDbcArea[0];

			} else if (tcSpecialKeyName == cgcScxKeyName) {
				// It's an SCX
//				wa = &gsScxArea[0];

			} else if (tcSpecialKeyName == cgcVcxKeyName) {
				// It's a VCX
//				wa = &gsVcxArea[0];

			} else if (tcSpecialKeyName == cgcFrxKeyName) {
				// It's an FRX
//				wa = &gsFrxArea[0];

			} else if (tcSpecialKeyName == cgcMnxKeyName) {
				// It's an MNX
//				wa = &gsMnxArea[0];

			} else {
				// If we get here, it's an unknown type
				return(-1);
			}


			//////////
			// Initialize and copy the pathname
			//////
				memset(table, 0, sizeof(table));
				memcpy(table, varTablePathname->value.data_s8, varTablePathname->value.length);


			//////////
			// Search for it
			//////
				return(iDbf_get_workArea_byTablePathname((cs8*)table, tcSpecialKeyName));

		} else {
			// Invalid parameters
			return(-1);
		}
	}

	sptr iDbf_get_workArea_byTablePathname(cs8* tcTablePathname, cu8* tcSpecialKeyName)
	{
		s32			lnI, lnI_max, lnLength;
		SWorkArea*	wa;


		// Make sure our environment is sane
		if (tcTablePathname && (lnLength = (s32)strlen(tcTablePathname)) < (s32)sizeof(gsWorkArea[0].tablePathname))
		{
			// See what they're searching for
			if (!tcSpecialKeyName || tcSpecialKeyName == cgcDbfKeyName)
			{
				// It's a standard DBF
				lnI_max	= _MAX_DBF_SLOTS;
				wa		= &gsWorkArea[0];

			} else if (tcSpecialKeyName == cgcDbcKeyName) {
				// It's a DBC
				lnI_max	= _MAX_DBC_SLOTS;
				wa		= &gsDbcArea[0];

			} else if (tcSpecialKeyName == cgcScxKeyName) {
				// It's an SCX
				lnI_max	= _MAX_SCX_SLOTS;
				wa		= &gsScxArea[0];

			} else if (tcSpecialKeyName == cgcVcxKeyName) {
				// It's a VCX
				lnI_max	= _MAX_VCX_SLOTS;
				wa		= &gsVcxArea[0];

			} else if (tcSpecialKeyName == cgcFrxKeyName) {
				// It's an FRX
				lnI_max	= _MAX_FRX_SLOTS;
				wa		= &gsFrxArea[0];

			} else if (tcSpecialKeyName == cgcMnxKeyName) {
				// It's an MNX
				lnI_max	= _MAX_MNX_SLOTS;
				wa		= &gsMnxArea[0];

			} else {
				// If we get here, it's an unknown type
				return(-1);
			}

			// Iterate through every work area searching tables
			for (lnI = 0; lnI < lnI_max; lnI++)
			{
				// If it's a table, and the alias name is the same length, continue checking the name
				if (wa->isUsed == _YES && wa->aliasLength == lnLength)
				{
					// Check the name
					if (_memicmp(wa->tablePathname, tcTablePathname, lnLength) == 0)
						return(lnI);	// It is a match
				}
			}
		}

		// If we get here, not found
		return(-1);
	}

	sptr iDbf_get_workArea_byAlias(SVariable* varAlias, cu8* tcSpecialKeyName)
	{
		s32			lnI, lnI_max;
//		SWorkArea*	wa;


		// Make sure our environment is sane
		if (varAlias && varAlias->varType == _VAR_TYPE_CHARACTER && varAlias->value.data_s8 && varAlias->value.length >= 1)
		{
			// See what they're searching for
			if (!tcSpecialKeyName || tcSpecialKeyName == cgcDbfKeyName)
			{
				// It's a standard DBF
				lnI_max	= _MAX_DBF_SLOTS;
//				wa		= &gsWorkArea[0];

			} else if (tcSpecialKeyName == cgcDbcKeyName) {
				// It's a DBC
				lnI_max	= _MAX_DBC_SLOTS;
//				wa		= &gsDbcArea[0];

			} else if (tcSpecialKeyName == cgcScxKeyName) {
				// It's an SCX
				lnI_max	= _MAX_SCX_SLOTS;
//				wa		= &gsScxArea[0];

			} else if (tcSpecialKeyName == cgcVcxKeyName) {
				// It's a VCX
				lnI_max	= _MAX_VCX_SLOTS;
//				wa		= &gsVcxArea[0];

			} else if (tcSpecialKeyName == cgcFrxKeyName) {
				// It's an FRX
				lnI_max	= _MAX_FRX_SLOTS;
//				wa		= &gsFrxArea[0];

			} else if (tcSpecialKeyName == cgcMnxKeyName) {
				// It's an MNX
				lnI_max	= _MAX_MNX_SLOTS;
//				wa		= &gsMnxArea[0];

			} else {
				// If we get here, it's an unknown type
				return(-1);
			}

			// Iterate through every work area searching tables
			for (lnI = 0; lnI < lnI_max; lnI++)
			{
				// If it's a table, and the alias name is the same length, continue checking the name
				if (gsWorkArea[lnI].isUsed == _YES && gsWorkArea[lnI].aliasLength == varAlias->value.length)
				{
					// Check the name
					if (_memicmp(gsWorkArea[lnI].alias, varAlias->value.data_s8, gsWorkArea[lnI].aliasLength) == 0)
						return(lnI);	// It is a match
				}
			}
		}

		// If we get here, not found
		return(-1);
	}




//////////
//
// Note:	This basically duplicates the JUSTSTEM() logic, except that if the JUSTSTEM() name is
//			already in use, then it appends a SYS(2015), iterating up until it's not one in use.
//
//////
	SVariable* iDbf_get_alias_fromPathname(SVariable* varPathname, cu8* tcSpecialKeyName)
	{
		u32			lnI_max, lnAppendValue;
		bool		llAppendedSix;
		SVariable*	varAlias;


		//////////
		// Grab just the stem
		//////
			varAlias = NULL;
			if (varPathname)
			{
				// Grab the stem part of the name
				varAlias = function_juststem(varPathname, varSix);

				// If it's invalid, or unreachable, then just use a default alias name
				if (!iVariable_isTypeCharacter(varAlias) || iVariable_isEmpty(varAlias))
				{
					// Allocate with an extra six characters afterward
					varAlias = iFunction_sys2015(0, 6);
				}

				if (iVariable_isValid(varAlias) && iVariable_isTypeCharacter(varAlias))
				{
					// Reduce the length by the trailing 6 characters if need be
					varAlias->value.length -= 6;
				}
			}


			// See what they're searching for
			if (!tcSpecialKeyName || tcSpecialKeyName == cgcDbfKeyName)
			{
				// It's a standard DBF
				lnI_max	= _MAX_DBF_SLOTS;

			} else if (tcSpecialKeyName == cgcDbcKeyName) {
				// It's a DBC
				lnI_max	= _MAX_DBC_SLOTS;

			} else if (tcSpecialKeyName == cgcScxKeyName) {
				// It's an SCX
				lnI_max	= _MAX_SCX_SLOTS;

			} else if (tcSpecialKeyName == cgcVcxKeyName) {
				// It's a VCX
				lnI_max	= _MAX_VCX_SLOTS;

			} else if (tcSpecialKeyName == cgcFrxKeyName) {
				// It's an FRX
				lnI_max	= _MAX_FRX_SLOTS;

			} else if (tcSpecialKeyName == cgcMnxKeyName) {
				// It's an MNX
				lnI_max	= _MAX_MNX_SLOTS;

			} else {
				// If we get here, it's an unknown type
				// We'll just let whatever they're in pursuit of pass through
				lnI_max = -1;
			}

		//////////
		// So long as there is an alias of this name, append a 6-digit integer
		//////
			if (varAlias)
			{
				// Make sure the alias name doesn't exist
				llAppendedSix	= false;
				lnAppendValue	= 1;
				while (iDbf_get_workArea_byAlias(varAlias, tcSpecialKeyName) >= 0 && lnAppendValue < lnI_max)
				{
					// Append a six-digit number onto the alias name
					if (!llAppendedSix)
					{
						// Add on the space for the 
						varAlias->value.length	+= 6;
						llAppendedSix			= true;
					}

					// Store the current iteration of the appended value
					sprintf(varAlias->value.data_s8 + varAlias->value.length - 6, "_%05u", lnAppendValue++);
				}

			} else {
				// Just use SYS(2015)
				varAlias = iFunction_sys2015(0, 0);
			}


		//////////
		// Indicate our status
		//////
			return(varAlias);
	}




//////////
//
// Called to goto a record and read in the contents.
//
//////
	sptr iDbf_gotoRecord(SWorkArea* wa, s32 recordNumber)
	{
		u64 lnNumread;


		//////////
		// Check for errors
		//////
			// Make sure it's valid
			if (!iDbf_isWorkAreaValid(wa, NULL))
				return(_DBF_ERROR__INTERNAL_PROGRAMMER);
			if (wa->isUsed != _YES)
				return(_DBF_ERROR_WORK_AREA_NOT_IN_USE);


		//////////
		// Make sure the record they want to go to exists
		//////
			if (recordNumber <= (s32)wa->header.records)
			{
				if (wa->isCached)
				{
					// We have it cached, so just change .data to point to the right place
					wa->data = wa->cachedTable + ((recordNumber - 1) * wa->header.recordLength);

				} else {
					// Manual seek in the table, and a manual read
					// Seek to the indicated offset, and read in the record
					_lseeki64(	wa->fhDbf, 
								wa->header.firstRecord + ((recordNumber - 1) * wa->header.recordLength),
								SEEK_SET);

					// Read in the record
					lnNumread = _read(wa->fhDbf, wa->data, wa->header.recordLength);
					if (lnNumread != wa->header.recordLength)
						return(-1);
				}

				// Set the current record, and lower the dirty flag
				wa->currentRecord	= recordNumber;
				wa->dirty			= 0;

				// Copy to the original record
				memcpy(wa->odata, wa->data, wa->header.recordLength);
			}
			// Indicate where we are
			return(wa->currentRecord);
	}




//////////
//
// Called to write any changes to the fields to disk
//
//////
	uptr iDbf_writeChanges(SWorkArea* wa)
	{
		u32 lnNumread;


		//////////
		// Check for errors
		//////
			// Make sure it's valid
			if (!iDbf_isWorkAreaValid(wa, NULL))
				return(_DBF_ERROR__INTERNAL_PROGRAMMER);
			if (wa->isUsed != _YES)
				return(_DBF_ERROR_WORK_AREA_NOT_IN_USE);


		//////////
		// Make sure the record they want to go to exists
		//////
			if (wa->currentRecord <= wa->header.records && wa->dirty != 0)
			{
				// Write the record
				// Seek to the indicated offset, and read in the record
				_lseeki64(	wa->fhDbf,
							wa->header.firstRecord + ((wa->currentRecord - 1) * wa->header.recordLength),
							SEEK_SET);

				// Write the record
				lnNumread = _write(wa->fhDbf, wa->data, wa->header.recordLength);
				if (lnNumread != wa->header.recordLength)
					return(-1);

				// Set the current record, and lower the dirty flag
				wa->dirty = 0;

				// Copy what is now the disk record to the original record
				memcpy(wa->odata, wa->data, wa->header.recordLength);
			}
			// If we get here, nothing to do
			return(0);
	}




//////////
//
// Called to return the field name for the specified handle and field number.
//
// Parameters:
//		handle			- Slot for the previously opened table
//		fieldNumber		- Number of field to return name for within the header structure
//		dest			- Where to store the name (up to 10 bytes)
//		destLength		- Length of the memory area at dest
//
// Returns:
//	  u32		-1 if failure
//				-2 if field is invalid
//				N = length of name
//
//////
	uptr iDbf_getFieldCount(SWorkArea* wa)
	{
		//////////
		// Check for errors
		//////
			// Make sure it's valid
			if (!iDbf_isWorkAreaValid(wa, NULL))
				return(_DBF_ERROR__INTERNAL_PROGRAMMER);
			if (wa->isUsed != _YES)
				return(_DBF_ERROR_WORK_AREA_NOT_IN_USE);


		// Iterate through the fields until we find the one they want
		return(wa->fieldCount);
	}

	uptr iDbf_getReccount(SWorkArea* wa)
	{
		//////////
		// Check for errors
		//////
			// Make sure it's valid
			if (!iDbf_isWorkAreaValid(wa, NULL))
				return(_DBF_ERROR__INTERNAL_PROGRAMMER);
			if (wa->isUsed != _YES)
				return(_DBF_ERROR_WORK_AREA_NOT_IN_USE);
		

		// Iterate through the fields until we find the one they want
		return(wa->header.records);
	}

	// Returns 10-digit field name
	uptr iDbf_getField_name(SWorkArea* wa, u32 fieldNumber, u8* dest, u32 destLength)
	{
		u32				lnI;
		SFieldRecord2*	lfr2Ptr;


		//////////
		// Check for errors
		//////
			// Make sure it's valid
			if (!iDbf_isWorkAreaValid(wa, NULL))
				return(_DBF_ERROR__INTERNAL_PROGRAMMER);
			if (wa->isUsed != _YES)
				return(_DBF_ERROR_WORK_AREA_NOT_IN_USE);


		// Grab the indicated field number
		lfr2Ptr = iDbf_getField_byNumber2(wa, fieldNumber);
		if (lfr2Ptr)
		{
			// Store the name (or as much of it as will fit)
			for (lnI = 0; lnI < destLength && lnI < sizeof(lfr2Ptr->name2) - 1; lnI++)
				dest[lnI] = lfr2Ptr->name2[lnI];

			// NULL terminate
			dest[min(lnI, destLength - 1)] = 0;

			// Return the length of the name
			return((u32)strlen(dest));
		}
		// If we get here, failure
		return(-1);
	}

	// Returns 1-digit field type:
	//		C - Character		Y - Currency		D - Date		T - DateTime
	//		B - Double			F - Float			G - General		I - Integer
	//		L - Logical			M - Memo			N - Numeric		P - Picture
	//		Q - Varbinary		V - Varchar (binary)
	uptr iDbf_getField_type(SWorkArea* wa, u32 fieldNumber, u8* dest, u32 destLength)
	{
		SFieldRecord1* lfrp;


		//////////
		// Check for errors
		//////
			// Make sure it's valid
			if (!iDbf_isWorkAreaValid(wa, NULL))
				return(_DBF_ERROR__INTERNAL_PROGRAMMER);
			if (wa->isUsed != _YES)
				return(_DBF_ERROR_WORK_AREA_NOT_IN_USE);


		// Grab the indicated field number
		lfrp = iDbf_getField_byNumber1(wa, fieldNumber);
		if (lfrp)
		{
			// Store the type
			if (dest && destLength >= 1)
			{
				// As is
				*dest = lfrp->type;
				return(1);

			} else {
				// Just return the type as it's ASC() form
				return((u32)lfrp->type);
			}
		}

		// If we get here, failure
		return(-1);
	}

	uptr iDbf_getField_type_verbose(SWorkArea* wa, u32 fieldNumber, u8* dest, u32 destLength)
	{
		s8*				name;
		u32				length;
		SFieldRecord1*	lfrp;
		s8				buffer[32];


		//////////
		// Check for errors
		//////
			// Make sure it's valid
			if (!iDbf_isWorkAreaValid(wa, NULL))
				return(_DBF_ERROR__INTERNAL_PROGRAMMER);
			if (wa->isUsed != _YES)
				return(_DBF_ERROR_WORK_AREA_NOT_IN_USE);


		// Grab the indicated field number
		lfrp = iDbf_getField_byNumber1(wa, fieldNumber);
		if (lfrp)
		{
			// Store the type's related name
			switch (lfrp->type)
			{
				case 'C':	name = "Character";		break;
				case 'Y':	name = "Currency";		break;
				case 'D':	name = "Date";			break;
				case 'T':	name = "DateTime";		break;
				case 'B':	name = "Double";		break;
				case 'F':	name = "Float";			break;
				case 'G':	name = "General";		break;
				case 'I':	name = "Integer";		break;
				case 'L':	name = "Logical";		break;
				case 'M':	name = "Memo";			break;
				case 'N':	name = "Numeric";		break;
				case 'P':	name = "Picture";		break;
				case 'Q':	name = "Varbinary";		break;
				case 'V':	name = "Varchar";		break;
				default:
					sprintf(buffer, "Unknown '%c'\000", lfrp->type);
					name = (s8*)buffer;
					break;
			}
			length = (u32)strlen(name);
			memcpy(dest, name, min(destLength, length));
			return(length);
		}

		// If we get here, failure
		return(-1);
	}

	// Returns extended field type, such as:
	//		C(5)
	//		N(10,2)
	uptr iDbf_getField_type_extended(SWorkArea* wa, u32 fieldNumber, u8* dest, u32 destLength)
	{
		u32				length;
		SFieldRecord1*	lfrp;
		s8				buffer[32];


		//////////
		// Check for errors
		//////
			// Make sure it's valid
			if (!iDbf_isWorkAreaValid(wa, NULL))
				return(_DBF_ERROR__INTERNAL_PROGRAMMER);
			if (wa->isUsed != _YES)
				return(_DBF_ERROR_WORK_AREA_NOT_IN_USE);


		// Grab the indicated field number
		lfrp = iDbf_getField_byNumber1(wa, fieldNumber);
		if (lfrp)
		{	// Store the type
			if (lfrp->type == 'N' ||	// Numeric
				lfrp->type == 'Y' ||	// Currency
				lfrp->type == 'B' ||	// Double
				lfrp->type == 'F')		// Float
			{
				// Numeric, Currency, Double and Float all have decimals
				if (lfrp->decimals == 0)
				{
					// No decimals
					sprintf(buffer, "%c(%u)\000", lfrp->type, (u32)lfrp->length);

				} else {
					// Has decimals
					sprintf(buffer, "%c(%u,%u)\000", lfrp->type, (u32)lfrp->length, (u32)lfrp->decimals);
				}

			} else if (lfrp->type == 'M' ||		// Memo
					   lfrp->type == 'D' ||		// Date
					   lfrp->type == 'T' ||		// DateTime
					   lfrp->type == 'I' ||		// Integer
					   lfrp->type == 'L' ||		// Logical
					   lfrp->type == 'P' ||		// Picture
					   lfrp->type == 'Q' ||		// Varbinary
					   lfrp->type == 'V')		// Varchar
			{
				// Memo, Date, DateTime, General, Integer, Logical, Picture, Varbinary and Varchar all have fixed sizes
				sprintf(buffer, "%c\000", lfrp->type);

			} else {
				// It has type and length
				sprintf(buffer, "%c(%u)\000", lfrp->type, (u32)lfrp->length);

			}
			length = (u32)strlen(buffer);
			memcpy(dest, buffer, min(destLength, length));

			// Return the length of the name
			return(length);
		}

		// If we get here, failure
		return(-1);
	}

	// Returns field length, "10" as in "N(10,2)"
	uptr iDbf_getField_length(SWorkArea* wa, u32 fieldNumber, u8* dest, u32 destLength)
	{
		u32				length;
		SFieldRecord1*	lfrp;
		s8				buffer[32];


		//////////
		// Check for errors
		//////
			// Make sure it's valid
			if (!iDbf_isWorkAreaValid(wa, NULL))
				return(_DBF_ERROR__INTERNAL_PROGRAMMER);
			if (wa->isUsed != _YES)
				return(_DBF_ERROR_WORK_AREA_NOT_IN_USE);


		// Grab the indicated field
		lfrp = iDbf_getField_byNumber1(wa, fieldNumber);
		if (lfrp)
		{
			// Store the length
			if (dest)
			{
				sprintf(buffer, "%u\000", (u32)lfrp->length);
				length = (u32)strlen(buffer);
				memcpy(dest, buffer, min(destLength, length));

				// Return the length of the length in ASCII text
				return(length);

			} else {
				// Just return the length
				return(lfrp->length);
			}
		}

		// If we get here, failure
		return(-1);
	}

	// Returns the index override length
	uptr iDbf_getIndex_length(SWorkArea* wa, u32 fieldNumber, u8* dest, u32 destLength)
	{
		u32				length;
		SFieldRecord1*	lfrp;
		s8				buffer[32];


		//////////
		// Check for errors
		//////
			// Make sure it's valid
			if (!iDbf_isWorkAreaValid(wa, NULL))
				return(_DBF_ERROR__INTERNAL_PROGRAMMER);
			if (wa->isUsed != _YES)
				return(_DBF_ERROR_WORK_AREA_NOT_IN_USE);


		// Grab the indicated field
		lfrp = iDbf_getField_byNumber1(wa, fieldNumber);
		if (lfrp)
		{
			// Store the length
			if (dest)
			{
				// Length as-is or fixup length
				if (lfrp->indexFixup_lengthOverride != 0)		sprintf(buffer, "%u\000", (u32)lfrp->indexFixup_lengthOverride);
				else											sprintf(buffer, "%u\000", (u32)lfrp->length);

				// Copy
				length = (u32)strlen(buffer);
				memcpy(dest, buffer, min(destLength, length));

				// Return the length of the length in ASCII text
				return(length);

			} else {
				// Just return the length
				if (lfrp->indexFixup_lengthOverride != 0)		return(lfrp->indexFixup_lengthOverride);
				else											return(lfrp->length);
			}
		}

		// If we get here, failure
		return(-1);
	}

	// Returns decimals, "2" as in "N(10,2)"
	uptr iDbf_getField_decimals(SWorkArea* wa, u32 fieldNumber, u8* dest, u32 destLength)
	{
		u32				length;
		SFieldRecord1*	lfrp;
		s8				buffer[32];


		//////////
		// Check for errors
		//////
			// Make sure it's valid
			if (!iDbf_isWorkAreaValid(wa, NULL))
				return(_DBF_ERROR__INTERNAL_PROGRAMMER);
			if (wa->isUsed != _YES)
				return(_DBF_ERROR_WORK_AREA_NOT_IN_USE);


		// Grab the indicated field
		lfrp = iDbf_getField_byNumber1(wa, fieldNumber);
		if (lfrp)
		{
			// Store the decimals
			if (dest)
			{
				sprintf(buffer, "%u\000", (u32)lfrp->decimals);
				length = (u32)strlen(buffer);
				memcpy(dest, buffer, min(destLength, length));

				// Return the length of the decimals in ASCII text
				return(length);

			} else {
				// Indicate how many decimals
				return(lfrp->decimals);
			}
		}
		// If we get here, failure
		return(-1);
	}

	// Returns "Y" or "N" indicating whether or not the field is binary
	uptr iDbf_getField_isBinary(SWorkArea* wa, u32 fieldNumber, u8* dest, u32 destLength)
	{
		SFieldRecord1* lfrp;


		//////////
		// Check for errors
		//////
			// Make sure it's valid
			if (!iDbf_isWorkAreaValid(wa, NULL))
				return(_DBF_ERROR__INTERNAL_PROGRAMMER);
			if (wa->isUsed != _YES)
				return(_DBF_ERROR_WORK_AREA_NOT_IN_USE);


		// Grab the indicated field
		lfrp = iDbf_getField_byNumber1(wa, fieldNumber);
		if (lfrp)
		{
			// Store the binary condition
			if (dest && destLength >= 1)
				*dest = ((lfrp->flags & _DBF_FIELD_BINARY) ? 'Y' : 'N');

			// Indicate numerically
			return((lfrp->flags & _DBF_FIELD_BINARY) ? 1 : 0);
		}

		// If we get here, failure
		return(-1);
	}

	// Returns "Y" or "N" indicating whether or not the field can store NULLs
	uptr iDbf_getField_allowNulls(SWorkArea* wa, u32 fieldNumber, u8* dest, u32 destLength)
	{
		SFieldRecord1* lfrp;


		//////////
		// Check for errors
		//////
		// Make sure it's valid
		if (!iDbf_isWorkAreaValid(wa, NULL))
			return(_DBF_ERROR__INTERNAL_PROGRAMMER);
		if (wa->isUsed != _YES)
			return(_DBF_ERROR_WORK_AREA_NOT_IN_USE);


		// Grab the indicated field
		lfrp = iDbf_getField_byNumber1(wa, fieldNumber);
		if (lfrp)
		{
			// Store the allow nulls condition
			if (dest && destLength >= 1)
				*dest = (lfrp->flags & _DBF_FIELD_NULLS) ? 'Y' : 'N';

			// Indicate numerically
			return((lfrp->flags & _DBF_FIELD_NULLS) ? 1 : 0);
		}

		// If we get here, failure
		return(-1);
	}

	// Returns "Y", "N", or "X" (if invalid) indicating whether or not the field is NULL
	uptr iDbf_getNull_flag(SWorkArea* wa, u32 fieldNumber, u8* dest, u32 destLength)
	{
		u32				lnNull, lnOffset;
		u8				lnBitMask;
		SFieldRecord1*	lfrp;


		//////////
		// Check for errors
		//////
			// Make sure it's valid
			if (!iDbf_isWorkAreaValid(wa, NULL))
				return(_DBF_ERROR__INTERNAL_PROGRAMMER);
			if (wa->isUsed != _YES)
				return(_DBF_ERROR_WORK_AREA_NOT_IN_USE);


		// Grab the indicated field
		lfrp = iDbf_getField_byNumber1(wa, fieldNumber);
		if (lfrp)
		{
			// Store the type
			if (!(lfrp->flags & _DBF_FIELD_NULLS))
			{
				// NULLs are not allowed
				lnNull = -1;
				if (dest)
					*dest = 'X';

			} else {
				// NULLs are allowed, but we must check the condition for this field
				// Get the offset and bitmask into the row
				if (iDbf_getNull_offsetAndMask(wa, fieldNumber, &lnOffset, &lnBitMask))
				{
					// See if this field is actually null
					if ((wa->data[lnOffset] & lnBitMask) != 0)
					{
						// It's .NULL.
						lnNull = 1;
						if (dest)
							*dest = 'Y';

					} else {
						// Not .NULL.
						lnNull = 0;
						if (dest)
							*dest = 'N';
					}

				} else {
					// Did not find the field, which means the table is providing conflicting information
					lnNull = -1;
					if (dest)
						*dest = 'X';
				}
			}

			// Indicate the value, 0 or 1 indicates null (0=no, 1=.null.)
			return(lnNull);
		}
		// If we get here, failure
		return(-1);
	}

	// Gets the NULL offset into the row, and the byte mask
	bool iDbf_getNull_offsetAndMask(SWorkArea* wa, u32 fieldNumber, u32* nullOffset, u8* nullMask)
	{
		s32				lnI, lnNullFieldNum;
		SFieldRecord1*	lfrpNull;


		//////////
		// Check for errors
		//////
			// Make sure it's valid
			if (!iDbf_isWorkAreaValid(wa, NULL) || wa->isUsed != _YES)
			{
				if (nullOffset)		*nullOffset = -1;
				if (nullMask)		*nullMask	= -1;
				return(false);
			}


		//////////
		// It's based on the NULL field within the line
		//////
			for (lnI = 0, lnNullFieldNum = 0, lfrpNull = wa->fieldPtr1; lnI <= (s32)wa->fieldCount; lnI++, lfrpNull++)
			{
				// If this is a NULL field, increase its number up until we find our own field
				if ((lfrpNull->flags & _DBF_FIELD_NULLS) && lnI < (s32)fieldNumber)
					++lnNullFieldNum;

				// Looking for the NULL field, called _NullFlags, type "0"
				if (lfrpNull->type == '0')
					break;
			}


		//////////
		// If we found it, go ahead
		//////
			if (lfrpNull->type == '0')
			{
				// We now have the offset, obtain the bit
				*nullOffset		= lfrpNull->offset + (fieldNumber / 8);
				*nullMask		= 1 << ((lnNullFieldNum % 8) - 1);
				return(true);
			}


		//////////
		// If we get here, not found
		//////
			*nullOffset		= 0;
			*nullMask		= 0;
			return(false);
	}

	// Returns a value if the field is auto-incrementing, blank otherwise
	uptr iDbf_getField_autoinc_next(SWorkArea* wa, u32 fieldNumber, u8* dest, u32 destLength)
	{
		u32				length;
		SFieldRecord1*	lfrp;
		s8				buffer[32];


		//////////
		// Check for errors
		//////
			// Make sure it's valid
			if (!iDbf_isWorkAreaValid(wa, NULL))
				return(_DBF_ERROR__INTERNAL_PROGRAMMER);
			if (wa->isUsed != _YES)
				return(_DBF_ERROR_WORK_AREA_NOT_IN_USE);


		// Grab the indicated field
		lfrp = iDbf_getField_byNumber1(wa, fieldNumber);
		if (lfrp)
		{
			// Store the auto-incrementing next value
			if (lfrp->flags & _DBF_FIELD_AUTO_INC)
			{
				// Store the length
				sprintf(buffer, "%u\000", (u32)lfrp->autoIncNext);
				length = (u32)strlen(buffer);
				if (dest && destLength >= 1)
					memcpy(dest, buffer, min(destLength, length));

				// Return the length of the auto-increment next value in ASCII text
				return(length);
			}

			// Not auto-incrementing
			return(0);
		}

		// If we get here, failure
		return(-1);
	}

	// Returns a value if the field is auto-incrementing, blank otherwise
	uptr iDbf_getField_autoinc_step(SWorkArea* wa, u32 fieldNumber, u8* dest, u32 destLength)
	{
		u32				length;
		SFieldRecord1*	lfrp;
		s8				buffer[32];


		//////////
		// Check for errors
		//////
			// Make sure it's valid
			if (!iDbf_isWorkAreaValid(wa, NULL))
				return(_DBF_ERROR__INTERNAL_PROGRAMMER);
			if (wa->isUsed != _YES)
				return(_DBF_ERROR_WORK_AREA_NOT_IN_USE);


		// Grab the indicated field
		lfrp = iDbf_getField_byNumber1(wa, fieldNumber);
		if (lfrp)
		{
			// Store the auto-incrementing next value
			if (lfrp->flags & _DBF_FIELD_AUTO_INC)
			{
				// Store the length
				sprintf(buffer, "%u\000", (u32)lfrp->autoIncStep);
				length = (u32)strlen(buffer);
				if (dest && destLength >= 1)
					memcpy(dest, buffer, min(destLength, length));

				// Return the length of the auto-increment stepvalue in ASCII text
				return(length);
			}

			// Not auto-incrementing
			return(0);
		}

		// If we get here, failure
		return(-1);
	}

	s8* iDbf_getField_data(SWorkArea* wa, u32 fieldNumber, u8* dest, u32 destLength)
	{
		SFieldRecord1*	lfrp;
		union {
			s32		_value;
			s8*		value;
		};


		//////////
		// Check for errors
		//////
			// Make sure it's valid
			if (!iDbf_isWorkAreaValid(wa, NULL))
				return((s8*)_DBF_ERROR__INTERNAL_PROGRAMMER);
			if (wa->isUsed != _YES)
				return((s8*)_DBF_ERROR_WORK_AREA_NOT_IN_USE);


		// Grab the indicated field
		lfrp = iDbf_getField_byNumber1(wa, fieldNumber);
		if (lfrp)
		{
			// Store the reserved bytes
			if (dest)
			{
				// Copy the data
				memcpy(dest, wa->data + lfrp->offset, min(lfrp->length, destLength));

				// Return the length
				_value = min(lfrp->length, destLength);
				return(value);

			} else {
				// Return the offset to the actual data
				return(wa->data_s8 + lfrp->offset);
			}
		}
		// If we get here, failure
		_value = -1;
		return(value);
	}

	s8* iiDbf_getField_data2(SWorkArea* wa, u32 fieldNumber, u8* dest, u32 destLength, bool tlRetrieveAsIndexKey)
	{
		s32				lnI, lnLength;
		union {
			s32			_value;
			s8*			value;
		};
		SFieldRecord1*	lfrp;
		s8				julianBuffer[16];


		// Grab our field
		lfrp = iDbf_getField_byNumber1(wa, fieldNumber);
		if (lfrp)
		{
			// Store the reserved bytes
			if (dest)
			{
				// If we're creating an index key, and the field is null, it must be prefixed by it
				if (tlRetrieveAsIndexKey && (lfrp->flags & _DBF_FIELD_NULLS))
				{
					// Obtain the null value
					lnLength	= 1;
					*dest++		= ((iDbf_getNull_flag(wa, fieldNumber, NULL, 0) == 1) ? 0x80 : 0x00);

				} else {
					lnLength = 0;
				}

				// Copy the data
				lnLength += min(lfrp->length, destLength);
				memcpy(dest, wa->data + lfrp->offset, lnLength);

				// Fixup if need be
				if (tlRetrieveAsIndexKey && lfrp->indexFixup != 0)
				{
					switch (lfrp->indexFixup & _DBF_INDEX_FIXUP_MASK)
					{
						case _DBF_INDEX_FIXUP_SWAP_ENDIAN:
							// Fixup integers stored as 4-byte or 8-byte (currency)
							switch (lfrp->length)
							{
								case 4:	// s32 4-byte conversion
									*(u32*)dest = iiBswap32(*(u32*)dest);
									break;

								case 8:	// s64 8-byte conversion
									*(u64*)dest = iiBswap64(*(u64*)dest);
									break;
							}

							// Fixup the sign bit
							if ((dest[0] & 0x80) != 0)
							{
								// It is negative, make it positive
								switch (lfrp->length)
								{
									case 4:	// s32 4-byte conversion
										*(u32*)dest = ~(*(u32*)dest);
										break;

									case 8:	// s64 8-byte conversion
										*(u64*)dest = ~(*(u64*)dest);
										break;
								}
								dest[0] &= 0x7f;

							} else {
								// Just make it positive, but with the sign bit flipped
								dest[0] |= 0x80;
							}

							break;

						case _DBF_INDEX_FIXUP_FLOAT_DOUBLE:
							// Fixup float or double
							if ((dest[lfrp->length - 1] & 0x80) != 0)
							{
								// It is signed, flip all bits
									 if (lfrp->length == 4)		*(u32*)dest = ~(*(u32*)dest);
								else if (lfrp->length == 8)		*(u64*)dest = ~(*(u64*)dest);

								// Mask off sign bit
								dest[lfrp->length - 1] &= 0x7f;

							} else {
								// It is unsigned, flip only the sign it
								dest[lfrp->length - 1] |= 0x80;
							}
							break;

						case _DBF_INDEX_FIXUP_DATETIME:
							// Fixup embedded float in datetime
							if ((dest[0] & 0x80) != 0)		dest[4] &= 0x7f;		// It is unsigned
							else							dest[4] |= 0x80;		// It is signed
							break;

						case _DBF_INDEX_FIXUP_LOGICAL:
							// Spaces stored on disk are converted to "F" because... that's how VFP does it
							if (dest[0] == 32)
								dest[0] = 'F';
							break;

						case _DBF_INDEX_FIXUP_DATE:
							// Dates are stored as Julian day numbers
							sprintf(julianBuffer, "%08u\0", iiJulianDayNumber_fromYyyyMmDd_s8(&dest[0], &dest[4], &dest[6]));
							*(f64*)&julianBuffer[0] = atof(julianBuffer);
							if ((julianBuffer[7] & 0x80) != 0)
							{
								// It is negative, make it positive
								julianBuffer[7] &= 0x7f;

								// Reverse the string to store in big-endian format, while flipping all bits
								for (lnI = 0; lnI < 8; lnI++)
									dest[lnI] = !julianBuffer[7 - lnI];

							} else {
								// Just make it negative
								julianBuffer[7] |= 0x80;

								// Reverse the string to store in big-endian format
								for (lnI = 0; lnI < 8; lnI++)
									dest[lnI] = julianBuffer[7 - lnI];
							}

						case _DBF_INDEX_FIXUP_DELETED:
							// Spaces stored on disk are converted to "F" for comparison in indexes because... that's how VFP does it
							if (dest[0] == 32 || dest[0] == 'F')	dest[0] = 'F';
							else									dest[0] = 'T';
					}

					//////////
					// Work with any additive masks
					//////
						// UPPER()
						if (lfrp->indexFixup & _DBF_INDEX_FIXUP_UPPER)
						{
							// Convert everything here to upper-case
							for (lnI = 0; lnI < lnLength; lnI++)
								iiUpperCase(&dest[lnI]);
						}

						// LOWER()
						if (lfrp->indexFixup & _DBF_INDEX_FIXUP_LOWER)
						{
							// Convert everything here to lower-case
							for (lnI = 0; lnI < lnLength; lnI++)
								iiLowerCase(&dest[lnI]);
						}
				}

				// Return the length of the reserved bytes
				_value = min(lfrp->length, destLength);
				return(value);

			} else {
				// Return the offset to the actual data
				return(wa->data_s8 + lfrp->offset);
			}
		}
		// If we get here, failure
		_value = -1;
		return(value);
	}

	uptr iDbf_getField_dataOffset(SWorkArea* wa, u32 fieldNumber)
	{
		SFieldRecord1* lfrp;


		//////////
		// Check for errors
		//////
			// Make sure it's valid
			if (!iDbf_isWorkAreaValid(wa, NULL))
				return(_DBF_ERROR__INTERNAL_PROGRAMMER);
			if (wa->isUsed != _YES)
				return(_DBF_ERROR_WORK_AREA_NOT_IN_USE);


		// Grab the indicated field number
		lfrp = iDbf_getField_byNumber1(wa, fieldNumber);
		if (lfrp)
		{
			// Return the offset to the actual data
			return(lfrp->offset);
		}

		// If we get here, failure
		return(-1);
	}

	uptr iDbf_getIndexFixupOp(SWorkArea* wa, u32 fieldNumber)
	{
		SFieldRecord1* lfrp;


		//////////
		// Check for errors
		//////
			// Make sure it's valid
			if (!iDbf_isWorkAreaValid(wa, NULL))
				return(_DBF_ERROR__INTERNAL_PROGRAMMER);
			if (wa->isUsed != _YES)
				return(_DBF_ERROR_WORK_AREA_NOT_IN_USE);


		// Grab the indicated field number
		lfrp = iDbf_getField_byNumber1(wa, fieldNumber);
		if (lfrp)
		{
			// Return the offset to the actual data
			return(lfrp->indexFixup);
		}

		// If we get here, failure
		return(-1);
	}




//////////
//
// Updates data in the table
//
//////
	uptr iDbf_setField_data(SWorkArea* wa, s32 fieldNumber, s8* src, u32 srcLength)
	{
		SFieldRecord1* lfrp;


		//////////
		// Check for errors
		//////
			// Make sure it's valid
			if (!iDbf_isWorkAreaValid(wa, NULL))
				return(_DBF_ERROR__INTERNAL_PROGRAMMER);
			if (wa->isUsed != _YES)
				return(_DBF_ERROR_WORK_AREA_NOT_IN_USE);


		// Grab the indicated field number
		lfrp = iDbf_getField_byNumber1(wa, ((fieldNumber < 0) ? -fieldNumber : fieldNumber));
		if (lfrp)
		{
			// Store the reserved bytes
			if (src)
			{
				// Copy the data
				if (fieldNumber < 0)
				{
					// They're updating the idata (index data) field
					if (lfrp->length > srcLength)
						memset(wa->idata + lfrp->offset, lfrp->fillChar, lfrp->length);

					// Update the portion
					memcpy(wa->idata + lfrp->offset, src, min(lfrp->length, srcLength));

				} else {
					// They're updating the real data
					if (lfrp->length > srcLength)
						memset(wa->data + lfrp->offset, lfrp->fillChar, lfrp->length);

					// Update the portion
					memcpy(wa->data + lfrp->offset, src, min(lfrp->length, srcLength));

					// Indicate the record is dirty
					wa->dirty = _YES;

					// Flush the row to disk
					iDbf_writeChanges(wa);
				}

				// Return the number of bytes written/updated.
				return(min(lfrp->length, srcLength));

			} else {
				// They have to specify data to update
				return(-2);
			}
		}
		// If we get here, failure
		return(-1);
	}




//////////
//
// Makes sure the field contents contain only what they should.
//
//////
	uptr iDbf_getField_validateContents(SWorkArea* wa, u32 fieldNumber, u8* src, u32 srcLength)
	{
		u32				lnI, lnErrors;
		bool			llAllowAllStd;
		u8				c;
		SFieldRecord1*	lfrp;


		//////////
		// Check for errors
		//////
			// Make sure it's valid
			if (!iDbf_isWorkAreaValid(wa, NULL))
				return(_DBF_ERROR__INTERNAL_PROGRAMMER);
			if (wa->isUsed != _YES)
				return(_DBF_ERROR_WORK_AREA_NOT_IN_USE);


		// Is there anything to do?
		if (wa->header.records == 0 || wa->currentRecord > wa->header.records)
			return(0);	// No data, so everything's correct. :-)


		// Get the field
		lfrp = iDbf_getField_byNumber1(wa, fieldNumber);
		if (lfrp)
		{
			//////////
			// Based on the field type, we can expect certain things
			//////
				llAllowAllStd = false;
				switch (lfrp->type)
				{
					case 'C':	// Character
						if ((lfrp->flags & _DBF_FIELD_BINARY) != 0)
							return(0);	// Binary character fields allow anything

						// Regular character fields allow all characters
						llAllowAllStd = true;
						break;

					case 'D':	// Date
						// Numbers only
						break;

					case 'L':	// Logical
						// Space, T and F
						break;

					case 'N':	// Numeric
						// Numbers and . , - +
						break;

					case 'M':	// Memo
					case 'Y':	// Currency
					case 'T':	// DateTime
					case 'B':	// Double
					case 'F':	// Float
					case 'G':	// General
					case 'I':	// Integer
					case 'P':	// Picture
					case 'Q':	// Varbinary
					case 'V':	// Varchar
						// Allow anything, so we keep whatever's there
						return(0);

					default:
						// An unknown field
						return(-3);
						break;
				}


			//////////
			// Examine the data
			//////
				for (lnErrors = 0, lnI = lfrp->offset; lnI < lfrp->offset + lfrp->length; lnI++)
				{
					// Grab the character
					c = wa->data[lnI];

					// Are all ASCII characters allowed
					if (llAllowAllStd)
					{
						// We allow everything, except for non-printable characters
						// For brevity sake we consider everything that is generally printable in English or a few other languages like French, German, Spanish, etc.
						// See http://www.theasciicode.com.ar/ascii-control-characters/delete-ascii-code-127.html
						if (c < 32/*space*/ || c > 174/*upside down !*/ || c == 127/*delete symbol -- looks like a little house*/)
							++lnErrors;

					} else {
						// Only specific things are allowed
						if (lfrp->type == 'D' || lfrp->type == 'N')
						{
							// It can be numbers
							if (lfrp->type == 'N')
							{
								// And it can have .,-+ in it
								if (!((c >= '0' && c <= '9') || c == 32 || c == '.' || c == ',' || c == '-' || c == '+'))
									++lnErrors;

							} else {
								// Just numbers
								if ((c < '0' || c > '9') && c != 32)
									++lnErrors;
							}

						} else {
							// Logical
							if (c != 32 && c != 'T' && c != 'F')
								++lnErrors;
						}
					}
				}


			//////////
			// Return the number of errors encountered
			//////
				return(lnErrors);

		} else {
			// They have to specify data to update
			return(-2);
		}
		// If we get here, failure
		return(-1);
	}

	// Returns the field number by field name
	SFieldRecord1* iDbf_getField_byName1(SWorkArea* wa, const u8* fieldName)
	{
		s32				lnI, lnLength;
		SFieldRecord1*	lfr1Ptr;


		//////////
		// Check for errors
		//////
			// Make sure it's valid
			if (!iDbf_isWorkAreaValid(wa, NULL))
				return(null);
			if (wa->isUsed != _YES)
				return(null);


		// Retrieve the first field
		lfr1Ptr = iDbf_getField_byNumber1(wa, 1);
		if (lfr1Ptr)
		{
			// Search for the name
			lnLength = (s32)strlen((u8*)fieldName);
			for (lnI = 1; lnI <= (s32)wa->fieldCount; lnI++, lfr1Ptr++)
			{
				// Length must match, and the field name must match
				if (lnLength == lfr1Ptr->fieldName_length && _memicmp((u8*)fieldName, lfr1Ptr->name, lnLength) == 0)
					return(lfr1Ptr);
			}
		}

		// If we get here, failure
		return(null);
	}

	// Called to retrieve the field for the indicated field number.
	SFieldRecord1* iDbf_getField_byNumber1(SWorkArea* wa, u32 fieldNumber)
	{
		u32				lnI;
		SFieldRecord1*	lfrp;


		//////////
		// Check for errors
		//////
			// Make sure it's valid
			if (!iDbf_isWorkAreaValid(wa, NULL))
				return(null);
			if (wa->isUsed != _YES)
				return(null);

		
		// Iterate through the fields until we find the one they want
		lfrp = wa->fieldPtr1;
		for (lnI = 1; lnI <= wa->fieldCount; lnI++)
		{
			// Is this the field?
			if (lnI == fieldNumber)
				return(lfrp);		// This is the field they want

			// Move to next field
			++lfrp;
		}
		// If we get here, it wasn't found
		return(NULL);
	}

	SFieldRecord2* iDbf_getField_byName2(SWorkArea* wa, cu8* fieldName)
	{
		s32				lnI, lnLength;
		SFieldRecord2*	lfr2Ptr;


		//////////
		// Check for errors
		//////
			// Make sure it's valid
			if (!iDbf_isWorkAreaValid(wa, NULL))
				return(null);
			if (wa->isUsed != _YES)
				return(null);


		// Retrieve the first field
		lfr2Ptr = iDbf_getField_byNumber2(wa, 1);
		if (lfr2Ptr)
		{
			// Search for the name
			lnLength = (s32)strlen((u8*)fieldName);
			for (lnI = 1; lnI <= (s32)wa->fieldCount; lnI++, lfr2Ptr++)
			{
				// Length must match, and the field name must match
				if (lnLength == lfr2Ptr->fieldName_length && _memicmp((u8*)fieldName, lfr2Ptr->name2, lnLength) == 0)
					return(lfr2Ptr);
			}
		}

		// If we get here, failure
		return(null);
	}

	SFieldRecord2* iDbf_getField_byNumber2(SWorkArea* wa, u32 fieldNumber)
	{
		u32				lnI;
		SFieldRecord2*	lfr2Ptr;


		//////////
		// Check for errors
		//////
			// Make sure it's valid
			if (!iDbf_isWorkAreaValid(wa, NULL))
				return(null);
			if (wa->isUsed != _YES)
				return(null);


		// Iterate through the fields until we find the one they want
		lfr2Ptr = wa->field2Ptr;
		for (lnI = 1; lnI <= wa->fieldCount; lnI++)
		{
			// Is this the field?
			if (lnI == fieldNumber)
				return(lfr2Ptr);		// This is the field they want

			// Move to next field
			++lfr2Ptr;
		}
		// If we get here, it wasn't found
		return(NULL);
	}




//////////
//
// Called to find out what type the expression is.	This test is incomplete, but works only
// on the first field.
//
//////
	u8 iDbf_getField_type(SWorkArea* wa, u8* keyExpression, bool* swapEndians, bool* needsSignBitToggled)
	{
		u32				lnI, len;
		SFieldRecord2*	lfrp2;


		//////////
		// Check for errors
		//////
			// Make sure it's valid
			if (!iDbf_isWorkAreaValid(wa, NULL) || wa->isUsed != _YES)
			{
				if (*swapEndians)			*swapEndians			= false;
				if (*needsSignBitToggled)	*needsSignBitToggled	= false;
				return(-1);
			}
			if (keyExpression == NULL)
				return(32);	// Unknown, assume a space


		// Iterate through the fields until we find the one they want
		len		= (u32)strlen(keyExpression);
		lfrp2	= wa->field2Ptr;
		for (lnI = 1; lnI <= wa->fieldCount; lnI++)
		{
			// If this is the field, then accept it
			if (lfrp2->name2[len] == 0 && _memicmp(&lfrp2->name2[0], keyExpression, len) == 0)
			{
				// This field matches
				*swapEndians			= false;
				*needsSignBitToggled	= false;
				switch (lfrp2->type)
				{
					case 'N':	// Numeric
					case 'M':	// Memo
					case 'C':	// Character
						return(32);

					case 'I':	// Integer
					case 'F':	// Float
					case 'B':	// Double
						*swapEndians			= true;
						*needsSignBitToggled	= true;
					case 'G':	// General
					case 'P':	// Picture
					case 'Q':	// Varbinary
					case 'V':	// Varchar
						return(0);

					case 'L':	// Logical
						return('F');

					case 'D':	// Date
					case 'T':	// DateTime
					default:
						return('0');
				}
			}

			// Move to next field
			++lfrp2;
		}
		// If we get here, it wasn't found
		return(32);		// Assume a space
	}




//////////
//
// Called to parse the input and grab only the field name portion.
// It does not validate the field name against any table, but will
// only extract characters which can be in a field name, stopping
// at plus signs, parenthesis, etc.
//
//////
	uptr iDbf_getField_name(u8* sourceExpression, u8* foundFieldName)
	{
		u32		lnLength;
		s8		c;
		bool	llFirstChar;


		// Make sure our environment is sane
		lnLength = 0;
		if (sourceExpression && foundFieldName)
		{
			// Iterate until we find the first inappropriate character
			llFirstChar = true;
			while (1)
			{
				// Grab this character
				c = *sourceExpression;

				// If it's a character or underscore, we're always good
				if (!(c == '_' || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')))
				{
					// 2nd and later characters can also be numeric
					if (llFirstChar)
						return(-1);	// Invalid leading character

					// Can be numeric
					if (!(c >= '0' && c <= '9'))
						break;	// We're done
					// If we get here, it was numeric
				}


				// Store the character
				*foundFieldName++ = c;

				// Move to next character
				llFirstChar = false;
				++lnLength;
				++sourceExpression;
			}

			// NULL terminate
			*foundFieldName = 0;
		}

		// Indicate our status
		return(lnLength);
	}




//////////
//
// Called to lookup the indicated field in the container (if any).	If not, then it simply
// copies over the frPtr field name to the fr2Ptr field.
//
//////
	void iiDbc_lookupTableField(SWorkArea* wa, bool* tlIsValid, bool tlExcusive)
	{
		u32				lnI, lnDbcHandle, lnRecno, lnAliasLength, lnField;
		sptr			lnObjectId, lnParentId, lnObjectType, lnObjectName;
		s32				lnDbcLength;
		bool			llSearchingForTable, llFoundFirstField;
		s8*				lcObjectId;
		s8*				lcParentId;
		s8*				lcObjectType;
		s8*				lcObjectName;
		s8				alias[_MAX_PATH];
		s8				dbcName[_MAX_PATH];
		cu8*			workAreaKeyName;
		SFieldRecord1*	frPtr;
		SFieldRecord2*	fr2Ptr;


		//////////
		// Initialize
		//////
			// Get the full path for what would be the container
			iiDbf_getRelativeDbc(wa, &dbcName[0]);
			lnDbcLength = (s32)strlen(dbcName);

			// Get the alias
			iiJuststem(wa, &alias[0]);
			lnAliasLength = (u32)strlen(alias);

			// If it has no backlink, we're done
			if (wa->backlink[0] == 0)
				return;
//return;

		//////////
		// Is the DBC already open?
		//////
			if (!wa->dbc)
			{
				// Is there a DBC?
				for (lnI = 0; lnI < _MAX_DBC_SLOTS; lnI++)
				{
					// Check if this table/slot is a dbc
					if (gsDbcArea[lnI].isUsed == _YES && gsDbcArea[lnI].tablePathnameLength == lnDbcLength)
					{
						// See if it's OUR dbc
						if (_memicmp(gsDbcArea[lnI].tablePathname, dbcName, wa->tablePathnameLength) == 0)
						{
							// This is our container
							lnDbcHandle = gsDbcArea[lnI].thisWorkArea;
							wa->dbc = &gsDbcArea[lnI];
							break;
						}
					}
				}

				// It is not already open, so we need to open it
				lnDbcHandle = (u32)iDbf_open((cs8*)dbcName, (cs8*)cgcDbcKeyName, tlExcusive, false);
				if ((s32)lnDbcHandle >= 0)
				{
					// We're good
					wa->dbc = &gsWorkArea[lnDbcHandle];
				}
			}


		//////////
		// When we get here, we have the DBC open, or not
		//////
			if (iDbf_isWorkAreaValid(wa->dbc, &workAreaKeyName) || workAreaKeyName != cgcDbcKeyName)
			{
				// Get the offsets to the fields
				lnObjectId		= (sptr)iDbf_getField_byName2(wa->dbc, cgcObjectId);
				lnParentId		= (sptr)iDbf_getField_byName2(wa->dbc, cgcParentId);
				lnObjectType	= (sptr)iDbf_getField_byName2(wa->dbc, cgcObjectType);
				lnObjectName	= (sptr)iDbf_getField_byName2(wa->dbc, cgcObjectName);

				// Did we find every field?
				if (lnObjectId <= 0 || lnParentId <= 0 || lnObjectType <= 0 || lnObjectName <= 0)
				{
					// We found a DBC backlink, but it backed into an invalid DBC
					*tlIsValid = false;
					return;
				}

				lcObjectId		= iDbf_getField_data(wa->dbc, (u32)lnObjectId, NULL, 0);
				lcParentId		= iDbf_getField_data(wa->dbc, (u32)lnParentId, NULL, 0);
				lcObjectType	= iDbf_getField_data(wa->dbc, (u32)lnObjectType, NULL, 0);
				lcObjectName	= iDbf_getField_data(wa->dbc, (u32)lnObjectName, NULL, 0);

				// Locate the long filename
				llSearchingForTable	= true;
				llFoundFirstField	= false;
				for (lnRecno = 1; lnRecno < wa->dbc->header.records; lnRecno++)
				{
					// Go to that record
					iDbf_gotoRecord(wa->dbc, lnRecno);

					// Is it deleted?
					if (wa->dbc->data[0] == 32)
					{
						// Not deleted
						if (llSearchingForTable)
						{
							// Looking for "Table" entries
							if (_memicmp(lcObjectType, "table", 5) == 0)
							{
								// We found a table entry.	Is it ours?
								if (lcObjectName[lnAliasLength] == 32 && _memicmp(lcObjectName, alias, lnAliasLength) == 0)
								{
									// Yes, grab the objectId
									wa->dbc_parentRecno		= lnRecno;
									wa->dbc_parentId		= *(u32*)lcObjectId;	// objectId on this record becomes the parentId we're looking for on all of its child records
									llSearchingForTable		= false;
								}
							}

						} else {
							// Looking for "Field" entries on a parentId
							if (*(u32*)lcParentId == wa->dbc_parentId)
							{
								// Populate the RECNO() for the first child if it is on
								if (!wa->dbc_firstChildRecno)
									wa->dbc_firstChildRecno = lnRecno;	// We found the first child for this table

								// Is this a field entry?
								if (_memicmp(lcObjectType, "field", 5) == 0)
								{
									// We found the first field entry
									wa->dbc_firstFieldRecno	= lnRecno;
									llFoundFirstField		= true;
									break;
								}
							}
						}
					}
				}
				// When we get here, we've either not found the table, or we're good
				if (!llSearchingForTable && llFoundFirstField)
				{
					for (	lnField = 1, lnRecno = wa->dbc_firstFieldRecno, frPtr = wa->fieldPtr1, fr2Ptr = wa->field2Ptr;
							lnField <= wa->fieldCount && lnRecno < wa->dbc->header.records;
							lnField++, lnRecno++, frPtr++, fr2Ptr++		)
					{
						// Go to that record
						iDbf_gotoRecord(wa->dbc, lnRecno);

						// Is it deleted?
						if (gsWorkArea[lnDbcHandle].odata[0] == 32)
						{
							// Not deleted
							// Looking for "Field" entries
							if (_memicmp(lcObjectType, "field", 5) == 0)
							{
								// Store the record number for this field
								fr2Ptr->dbcRecno = lnRecno;
								memcpy(fr2Ptr->name2, lcObjectName, 128);
								for (fr2Ptr->fieldName_length = 127; fr2Ptr->fieldName_length >= 0 && fr2Ptr->name2[fr2Ptr->fieldName_length] == 32; fr2Ptr->fieldName_length--)
									fr2Ptr->name2[fr2Ptr->fieldName_length] = 0;

								// Increase for the character we just found
								++fr2Ptr->fieldName_length;
							}
						}
					}
					// Success
					*tlIsValid = true;
					return;
				}
			}
			// We found a DBC backlink, but it backed into a non-existent record
			*tlIsValid = false;
	}

	void iiDbf_getRelativeDbc(SWorkArea* wa, s8* dbcName)
	{
		s32		lnI;
		s8*		name;
		s8		fullPathname[_MAX_PATH];


		//////////
		// Get the path
		//////
			// Begin at the end
			name = wa->tablePathname;

			// Back off until we reach the directory indicator, or the beginning
			for (lnI = wa->tablePathnameLength - 1; lnI >= 0; lnI--)
			{
				// Have we reached the backslash?
				if (name[lnI] == '\\')
				{
					++lnI;
					break;
				}
			}
			if (lnI < 0)
				lnI = 0;

			// When we get here, we are ready to copy
			if (lnI == 0)
			{
				// NULL terminate
				dbcName[0] = 0;

			} else {
				// Copy the part of the name
				memcpy(dbcName, name, lnI);

				// If the last character is not a backslash, append one
				if (dbcName[lnI - 1] != '\\')
					dbcName[lnI++ - 1] = '\\';

				// NULL terminate
				dbcName[lnI] = 0;
			}


		//////////
		// Copy the name
		//////
			memcpy(dbcName + lnI, wa->backlink, wa->backlinkLength + 1);


		//////////
		// Determine the actual path
		//////
			s8** lptr;
			lptr = NULL;
			memset(fullPathname, 0, sizeof(fullPathname));
			GetFullPathName(dbcName, _MAX_PATH, fullPathname, lptr);
			memset(dbcName, 0, lnI + wa->backlinkLength);
			memcpy(dbcName, fullPathname, strlen(fullPathname) + 1);
	}




//////////
//
// Allocates a FOR clause, and initializes it to an empty state
//
//////
	SForClause* iDbf_forClause_allocate(SForClause** tsFor)
	{
		// Make sure our environment is sane
		if (tsFor)
		{
			// Allocate the pointer
			*tsFor = (SForClause*)malloc(sizeof(SForClause));
			if (*tsFor)
			{
				// Initialize
				memset(*tsFor, 0, sizeof(SForClause));

				// Allocate the space for FOR operations
				(*tsFor)->ops				= (SForOp*)malloc(sizeof(SForOp) * _FOR_CLAUSE_OP_ALLOCATION_BLOCK_SIZE);
				(*tsFor)->opAllocated		= _FOR_CLAUSE_OP_ALLOCATION_BLOCK_SIZE;
				memset((*tsFor)->ops, 0, sizeof(SForOp) * _FOR_CLAUSE_OP_ALLOCATION_BLOCK_SIZE);

				// Allocate the space for TEMP variables
				(*tsFor)->subitems			= (SForSubItem*)malloc(sizeof(SForSubItem) * _FOR_CLAUSE_SUBITEM_ALLOCATION_BLOCK_SIZE);
				(*tsFor)->subitemAllocated	= _FOR_CLAUSE_SUBITEM_ALLOCATION_BLOCK_SIZE;
				memset((*tsFor)->subitems, 0, sizeof(SForTemp) * _FOR_CLAUSE_SUBITEM_ALLOCATION_BLOCK_SIZE);

				// Allocate the space for TEMP variables
				(*tsFor)->temps				= (SForTemp*)malloc(sizeof(SForTemp) * _FOR_CLAUSE_TEMP_ALLOCATION_BLOCK_SIZE);
				(*tsFor)->tempAllocated		= _FOR_CLAUSE_TEMP_ALLOCATION_BLOCK_SIZE;
				memset((*tsFor)->temps, 0, sizeof(SForTemp) * _FOR_CLAUSE_TEMP_ALLOCATION_BLOCK_SIZE);

				// Indicate our new pointer
				return(*tsFor);
			}
		}
		// If we get here, invalid
		return(NULL);
	}




//////////
//
// Delete the FOR clause, release all variables internally
//
//////
	void iDbf_forClause_delete(SForClause** tsFor)
	{
		s32				lnI;
		SForClause*		lsFor;


		// Make sure our environment is sane
		if (tsFor && *tsFor)
		{
			//////////
			// Grab the pointer locally, and reset
			//////
				lsFor	= *tsFor;
				*tsFor	= NULL;


			//////////
			// Any operations to delete?
			//////
				if (lsFor->ops)
				{
					// Delete operations
					free(lsFor->ops);
					lsFor->ops		= NULL;
					lsFor->opCount	= 0;
				}


			//////////
			// Any temporary items to delete?
			//////
				if (lsFor->temps)
				{
					//////////
					// Delete constant data within each
					//////
						for (lnI = 0; lnI < lsFor->tempCount; lnI++)
							free(lsFor->temps[lnI].data);


					//////////
					// Delete temporary itself
					//////
						free(lsFor->temps);
						lsFor->temps		= NULL;
						lsFor->tempCount	= 0;
				}
		}
	}




/////////
//
// Called to test the current row of data to see if it matches the FOR clause
//
//////
	bool iiDbf_forClause_isRowIncluded(SWorkArea* wa, SForClause* tsFor)
	{
		s32			lnI;
		SForOp*		lfo;
		SForTemp*	lftl;
		SForTemp*	lftr;


		// Make sure our environment is sane
		if (wa && tsFor)
		{
			// Iterate through ops
			for (lnI = 0, lfo = &tsFor->ops[0]; lnI < tsFor->opCount; lnI++, lfo++)
			{
				// See what should be done
				lftl = &tsFor->temps[lfo->tempIndexL];
				lftr = &tsFor->temps[lfo->tempIndexR];
				switch (lfo->op)
				{
					case _FOR_CLAUSE_OPS_EQUAL_ROW_DATA:
						// It's equal to something
						if (memcmp(wa->data + lfo->offsetL, wa->data + lfo->offsetR, lfo->lengthL) != 0)
							return(false);		// Is not equal
						break;

					case _FOR_CLAUSE_OPS_NOT | _FOR_CLAUSE_OPS_EQUAL_ROW_DATA:
						// It's not equal to something
						if (memcmp(wa->data + lfo->offsetL, wa->data + lfo->offsetR, lfo->lengthL) == 0)
							return(false);		// Is equal
						break;

					case _FOR_CLAUSE_OPS_LESS_THAN_ROW_DATA:
						// It's less than row data
						if (memcmp(wa->data + lfo->offsetL, wa->data + lfo->offsetR, lfo->lengthL) >= 0)
							return(false);		// Is greater than or equal to
						break;

					case _FOR_CLAUSE_OPS_NOT | _FOR_CLAUSE_OPS_LESS_THAN_ROW_DATA:
						// It's not less than row data
						if (memcmp(wa->data + lfo->offsetL, wa->data + lfo->offsetR, lfo->lengthL) < 0)
							return(false);		// Is less than
						break;

					case _FOR_CLAUSE_OPS_GREATER_THAN_ROW_DATA:
						// It's greater than row data
						if (memcmp(wa->data + lfo->offsetL, wa->data + lfo->offsetR, lfo->lengthL) <= 0)
							return(false);		// Is less than or equal to
						break;

					case _FOR_CLAUSE_OPS_NOT | _FOR_CLAUSE_OPS_GREATER_THAN_ROW_DATA:
						// It's not greater than row data
						if (memcmp(wa->data + lfo->offsetL, wa->data + lfo->offsetR, lfo->lengthL) > 0)
							return(false);		// Is greater than
						break;

					case _FOR_CLAUSE_OPS_EQUAL_TEMPORARY:
						// It's equal to a temporary
						if (memcmp(wa->data + lfo->offsetL, lftr->data, min(lfo->lengthL, lftr->length)) != 0)
							return(false);		// Is not equal
						break;

					case _FOR_CLAUSE_OPS_NOT | _FOR_CLAUSE_OPS_EQUAL_TEMPORARY:
						// It's not equal to a temporary
						if (memcmp(wa->data + lfo->offsetL, lftr->data, min(lfo->lengthL, lftr->length)) == 0)
							return(false);		// Is equal
						break;

					case _FOR_CLAUSE_OPS_LESS_THAN_TEMPORARY:
						// It's less than a temporary
						if (memcmp(wa->data + lfo->offsetL, lftr->data, min(lfo->lengthL, lftr->length)) >= 0)
							return(false);		// Is greater than or equal to
						break;

					case _FOR_CLAUSE_OPS_NOT | _FOR_CLAUSE_OPS_LESS_THAN_TEMPORARY:
						// It's not less than a temporary
						if (memcmp(wa->data + lfo->offsetL, lftr->data, min(lfo->lengthL, lftr->length)) < 0)
							return(false);		// Is less than
						break;

					case _FOR_CLAUSE_OPS_GREATER_THAN_TEMPORARY:
						// It's greater than a temporary
						if (memcmp(wa->data + lfo->offsetL, lftr->data, min(lfo->lengthL, lftr->length)) >= 0)
							return(false);		// Is greater than or equal to
						break;

					case _FOR_CLAUSE_OPS_NOT | _FOR_CLAUSE_OPS_GREATER_THAN_TEMPORARY:
						// It's not greater than a temporary
						if (memcmp(wa->data + lfo->offsetL, lftr->data, min(lfo->lengthL, lftr->length)) > 0)
							return(false);		// Is greater than
						break;

					case _FOR_CLAUSE_OPS_TEMPORARY_COPY_TO:
						// Copy row data to another temporary
						memcpy(lftl->data, lftr->data, lfo->lengthL);
						break;

					case _FOR_CLAUSE_OPS_TEMPORARY_SWAP_ENDIAN:
						// Swap an endian in a temporary
						*(u32*)lftl->data = iiBswap32(*(u32*)lftl->data);
						break;

					case _FOR_CLAUSE_OPS_TEMPORARY_SIGN_FLIP_F32:
						// Flip an F32 in a temporary
						*(f32*)lftl->data = *(f32*)lftl->data * -1.0f;
						break;

					case _FOR_CLAUSE_OPS_TEMPORARY_SIGN_FLIP_F64:
						// Flip an F64 in a temporary
						*(f64*)lftl->data = *(f64*)lftl->data * -1.0;
						break;
				}
			}
		}
		// If we get here, failure, nothing to test
		return(true);
	}




//////////
//
// Called to take an expression like "lDeleted=.T." and break it out into
// the [lDeleted][=][.T.] sub-items.
//
//////
	bool iiDbf_forClause_subitems_parse(SCdxHeader* head, SForClause* tsFor)
	{
		s32				lnI, lnK, lnLength;
		SForSubItem*	lfsi;
		s8				c;


		// Iterate through the expression
		lnK =  head->keyExpressionLength;
		for (lnI = 0, tsFor->subitemCount = 0, lnLength = 0; lnI < head->forClauseLength - 1; )
		{
			// We skip past whitespaces between things, such as in "NOT lDeleted"
			c = head->keyExpression[lnI + lnK];
			if (!isWhitespace(c))
			{
				//////////
				// Grab this character, create the sub-item, and indicate where we're starting
				//////
					lfsi			= iiDbf_forClause_subitems_appendItem(tsFor);
					lfsi->start		= &head->keyExpression[lnI + lnK];


				//////////
				// Find out where we're starting
				//////
					if (isParenthesis(c) || isBracket(c) || isBrace(c))
					{
						// Unsupported, as it likely refers to a stored procedure, or some runtime context in VFP ... unless it's a brace, and then they're just looney :-)
						lfsi->type = _FOR_CLAUSE_SUBITEM_TYPE_INVALID;
						return(false);

					} else if (isNotSymbol(c)) {
						// Exclamation point, which means it's an operator on the thing that comes after
						lfsi->type = _FOR_CLAUSE_SUBITEM_TYPE_NOT;
						++lnI;

					} else if (isQuote(c)) {
						// Quote character, everything between this and its mate is taken as is
						lfsi->type = _FOR_CLAUSE_SUBITEM_TYPE_QUOTE;
						for (++lnI, lnLength = 1; head->keyExpression[lnI + lnK] != c; lnLength++)
							++lnI;

					} else if (isAlpha(c)) {
						// Alpha, continue so long as it's alpha or numeric
						lfsi->type = _FOR_CLAUSE_SUBITEM_TYPE_ALPHANUMERIC;
						for (lnLength = 0; isAlpha(head->keyExpression[lnI + lnK]) || isNumeric(head->keyExpression[lnI + lnK]); lnLength++)
							++lnI;

						// See if it's a known keyword, OR, NOT, or AND
						if (lnLength == 2)
						{
							if (_memicmp(lfsi->start, "or", 2) == 0)
							{
								// Change it to OR
								lfsi->type = _FOR_CLAUSE_SUBITEM_TYPE_OR;							// OR
							}

						} else if (lnLength == 3) {
							if (_memicmp(lfsi->start, "not", 3) == 0)
							{
								// Change it to NOT
								lfsi->type = _FOR_CLAUSE_SUBITEM_TYPE_NOT;							// NOT

							} else if (_memicmp(lfsi->start, "and", 3) == 0) {
								// Change it to AND
								lfsi->type = _FOR_CLAUSE_SUBITEM_TYPE_AND;							// AND
							}
						}

					} else if (isNumeric(c)) {
						// Numeric, continue so long as it's numeric
						lfsi->type = _FOR_CLAUSE_SUBITEM_TYPE_NUMERIC;
						for (lnLength = 0; isNumeric(head->keyExpression[lnI + lnK]); lnLength++)
							++lnI;

					} else if (isDotExpression(c)) {
						// A dot-expression
						// Must be .t. or .f. or else we fail
						if (lnI + 2 < head->forClauseLength - 1)
						{
							// There's enough room for the test
							if (_memicmp(head->keyExpression + lnI + lnK, ".t.", 3) == 0 || _memicmp(head->keyExpression + lnI + lnK, ".f.", 3) == 0)
							{
								// We're good, it's .t. or .f.
								lfsi->type = _FOR_CLAUSE_SUBITEM_TYPE_LOGICAL_CONSTANT;
								lnLength = 3;
								// Note:  If they're indexing for .T., we will later completely ignore the test as it is, at that point, merely a placeholder
								lnI += lnLength;

							// Is it an .or. ?
							} else if (lnI + 4 < head->forClauseLength - 1) {
								if (_memicmp(head->keyExpression + lnI + lnK, ".not.", 5) == 0)
								{
									// If we get here, it's a .or.
									lfsi->type = _FOR_CLAUSE_SUBITEM_TYPE_NOT;
									lnLength = 5;
									lnI += lnLength;

								} else {
									// Unknown
									return(false);	// We fail
								}

							// Is it a .not. or .and. ?
							} else if (lnI + 5 < head->forClauseLength - 1) {
								if (_memicmp(head->keyExpression + lnI + lnK, ".not.", 5) == 0)
								{
									// If we get here, it's a .not.
									lfsi->type = _FOR_CLAUSE_SUBITEM_TYPE_NOT;
									lnLength = 5;
									lnI += lnLength;

								} else if (_memicmp(head->keyExpression + lnI + lnK, ".and.", 5) == 0) {
									// If we get here, it's a .and.
									lfsi->type = _FOR_CLAUSE_SUBITEM_TYPE_AND;
									lnLength = 5;
									lnI += lnLength;

								} else {
									// Unknown
									return(false);	// We fail
								}

							// It's unknown
							} else {
								return(false);	// We fail
							}

						} else {
							// We fail
							return(false);
						}

					} else if (isComparator(c)) {
						// A comparison expression, continue so long as it's a comparison expression
						lfsi->type = _FOR_CLAUSE_SUBITEM_TYPE_COMPARATOR;
						for (lnLength = 0; isComparator(head->keyExpression[lnI + lnK]); lnLength++)
							++lnI;

					} else {
						// Unknown type encountered
						lfsi->type = _FOR_CLAUSE_SUBITEM_TYPE_INVALID;
						return(false);
					}


				//////////
				// Store the end and length
				//////
					lfsi->end		= lfsi->start + lnLength - 1;
					lfsi->length	= lnLength;
				}
		}
		// If we get here, we're good
		return(true);
	}




//////////
//
// Called to allocate the next subitem block within an SForClause.
// We allocate a group at a time so we don't have to keep reallocating.
//
//////
	SForSubItem* iiDbf_forClause_subitems_appendItem(SForClause* tsFor)
	{
		s32 lnLastAllocated;


		//////////
		// Do we need to add more
		//////
			lnLastAllocated = tsFor->subitemAllocated;
			if (tsFor->subitemAllocated == 0)
			{
				// First allocation
				tsFor->subitems			= (SForSubItem*)malloc(_FOR_CLAUSE_SUBITEM_ALLOCATION_BLOCK_SIZE * sizeof(SForSubItem));
				tsFor->subitemAllocated	= _FOR_CLAUSE_SUBITEM_ALLOCATION_BLOCK_SIZE;

			} else if (tsFor->subitemCount + 1 >= tsFor->subitemAllocated) {
				// We need to allocate another block
				tsFor->subitems			= (SForSubItem*)realloc(tsFor->subitems, (tsFor->subitemAllocated + _FOR_CLAUSE_SUBITEM_ALLOCATION_BLOCK_SIZE) * sizeof(SForSubItem));
				tsFor->subitemAllocated	+= _FOR_CLAUSE_SUBITEM_ALLOCATION_BLOCK_SIZE;
			}


		//////////
		// Indicate we have one more in use
		//////
			++tsFor->subitemCount;


		//////////
		// Initialize the new block
		//////
			if (tsFor->subitemAllocated != lnLastAllocated)
				memset(tsFor->subitems + (lnLastAllocated * _FOR_CLAUSE_SUBITEM_ALLOCATION_BLOCK_SIZE), 0, ((tsFor->subitemAllocated - lnLastAllocated) * _FOR_CLAUSE_SUBITEM_ALLOCATION_BLOCK_SIZE));


		//////////
		// Indicate the active index item
		//////
			return(&tsFor->subitems[tsFor->subitemCount - 1]);
	}




//////////
//
// Called to append an op to the SForClause
//
//////
	SForOp* iiDbf_forClause_ops_appendItem(SForClause* tsFor)
	{
		s32 lnLastAllocated;


		//////////
		// Do we need to add more
		//////
			lnLastAllocated = tsFor->opAllocated;
			if (tsFor->opAllocated == 0)
			{
				// First allocation
				tsFor->ops			= (SForOp*)malloc(_FOR_CLAUSE_OP_ALLOCATION_BLOCK_SIZE* sizeof(SForOp));
				tsFor->opAllocated	= _FOR_CLAUSE_OP_ALLOCATION_BLOCK_SIZE;

			} else if (tsFor->opCount + 1 >= tsFor->opAllocated) {
				// We need to allocate another block
				tsFor->ops			= (SForOp*)realloc(tsFor->ops, (tsFor->opAllocated + _FOR_CLAUSE_OP_ALLOCATION_BLOCK_SIZE) * sizeof(SForOp));
				tsFor->opAllocated	+= _FOR_CLAUSE_OP_ALLOCATION_BLOCK_SIZE;
			}


		//////////
		// Indicate we have one more in use
		//////
			++tsFor->opCount;


		//////////
		// Initialize the new block
		//////
			if (tsFor->opAllocated != lnLastAllocated)
				memset(tsFor->ops + (lnLastAllocated * _FOR_CLAUSE_OP_ALLOCATION_BLOCK_SIZE), 0, ((tsFor->opAllocated - lnLastAllocated) * _FOR_CLAUSE_OP_ALLOCATION_BLOCK_SIZE));


		//////////
		// Indicate the active index item
		//////
			return(&tsFor->ops[tsFor->opCount - 1]);
	}




//////////
//
// Called to append some index data to the SForClause (used for constant comparisons)
//
//////
	uptr iiDbf_forClause_temp_appendConstant(SForClause* tsFor, s8* tcData, u32 tnDataLength)
	{
		s32			lnLastAllocated;
		SForTemp*	lft;


		// Make sure our environment is sane
		if (!tcData || tnDataLength == 0)
			return(-1);


		//////////
		// Do we need to add more
		//////
			lnLastAllocated = tsFor->tempAllocated;
			if (tsFor->tempAllocated == 0)
			{
				// First allocation
				tsFor->temps			= (SForTemp*)malloc(_FOR_CLAUSE_TEMP_ALLOCATION_BLOCK_SIZE * sizeof(SForTemp));
				tsFor->tempAllocated	= _FOR_CLAUSE_TEMP_ALLOCATION_BLOCK_SIZE;

			} else if (tsFor->tempCount + 1 >= tsFor->tempAllocated) {
				// We need to allocate another block
				tsFor->temps			= (SForTemp*)realloc(tsFor->temps, (tsFor->tempAllocated + _FOR_CLAUSE_TEMP_ALLOCATION_BLOCK_SIZE) * sizeof(SForTemp));
				tsFor->tempAllocated	+= _FOR_CLAUSE_TEMP_ALLOCATION_BLOCK_SIZE;
			}


		//////////
		// Grab the current
		//////
			lft = &tsFor->temps[tsFor->tempCount];


		//////////
		// Initialize the new block
		//////
			if (tsFor->tempAllocated != lnLastAllocated)
				memset(tsFor->temps + (lnLastAllocated * _FOR_CLAUSE_TEMP_ALLOCATION_BLOCK_SIZE), 0, ((tsFor->tempAllocated - lnLastAllocated) * _FOR_CLAUSE_TEMP_ALLOCATION_BLOCK_SIZE));


		//////////
		// Populate the data into the new entry
		//////
			lft->data	= (s8*)malloc(tnDataLength);
			if (lft->data)
			{
				// Copy the content
				memcpy(lft->data, tcData, tnDataLength);
				lft->length	= tnDataLength;
			}


		//////////
		// Indicate the active index item, and increase for the next slot
		//////
			return(tsFor->tempCount++);
	}




///////////
//
// Called to validate that the indicated table types have the correct structures
//
//////
	SFieldRecord2* iiDbf_validate_fieldExists(SWorkArea* wa, cu8* tcFieldName, cs8* tcFieldType, s32 length, s32 decimals)
	{
		SFieldRecord2* lfptr2;


		//////////
		// Locate the field by name
		//////
// TODO:  Untested code, breakpoint and examine
debug_break;
			lfptr2 = iDbf_getField_byName2(wa, tcFieldName);
			if (lfptr2)
			{
				// The field name exists
				if (iUpperCase(tcFieldType[0]) == iUpperCase(lfptr2->type))
				{
					// The type is correct
					if (lfptr2->length == length && lfptr2->decimals == decimals)
					{
						// We're good
						return(lfptr2);
					}
				}
			}


		//////////
		// If we get here, failure on this field
		//////
			return(null);
	}

	bool iiDbf_validate_isDbc(SWorkArea* wa)
	{
		SFieldRecord2* lfptr2;


		//////////
		//
		// DBC required structure:
		//
		//		objectId		i
		//		parentId		i
		//		objectType		c(10)
		//		objectName		c(128)
		//		property		m nocptran
		//		code			m nocptran
		//		riInfo			c(6)
		//		user			m
		//
		//////
			return(
								iiDbf_validate_fieldExists(wa,	cgcObjectId,		"i",	4,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcParentId,		"i",	4,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcObjectType,		"c",	10,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcObjectName,		"c",	128,	0)
				&&	((lfptr2 =	iiDbf_validate_fieldExists(wa,	cgcCode,			"m",	4,		0))		&&	(lfptr2->flags & _DBF_FIELD_BINARY) != 0)
				&&				iiDbf_validate_fieldExists(wa,	cgcRiInfo,			"c",	6,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcUser,			"m",	4,		0)
			);
	}

	bool iiDbf_validate_isScx(SWorkArea* wa)
	{
		// Same as VCX
		return(iiDbf_validate_isVcx(wa));
	}

	bool iiDbf_validate_isVcx(SWorkArea* wa)
	{
		SFieldRecord2* lfptr2;


		//////////
		//
		// VCX and SCX required structure:
		//
		// 	platform		c(8)
		// 	uniqueId		c(10)
		// 	timeStamp		n(10)
		// 	class			m
		// 	classLoc		m
		// 	baseClass		m
		// 	objname			m
		// 	parent			m
		// 	properties		m
		// 	protected		m
		// 	methods			m
		// 	objCode			m nocptran
		// 	ole				m
		// 	ole2			m
		// 	reserved1		m
		// 	reserved2		m
		// 	reserved3		m
		// 	reserved4		m
		// 	reserved5		m
		// 	reserved6		m
		// 	reserved7		m
		// 	reserved8		m
		// 	user			m
		//
		//////
			return(
								iiDbf_validate_fieldExists(wa,	cgcPlatform,		"c",	8,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcUniqueId,		"c",	10,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcTimeStamp,		"n",	10,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcClass,			"m",	4,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcClassLoc,		"m",	4,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcBaseClass,		"m",	4,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcObjName,			"m",	4,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcParent,			"m",	4,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcProperties,		"m",	4,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcProtected,		"m",	4,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcMethods,			"m",	4,		0)
				&&	((lfptr2 =	iiDbf_validate_fieldExists(wa,	cgcObjCode,			"m",	4,		0))		&&	(lfptr2->flags & _DBF_FIELD_BINARY) != 0)
				&&				iiDbf_validate_fieldExists(wa,	cgcOle,				"m",	4,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcOle2,			"m",	4,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcReserved1,		"m",	4,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcReserved2,		"m",	4,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcReserved3,		"m",	4,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcReserved4,		"m",	4,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcReserved5,		"m",	4,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcReserved6,		"m",	4,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcReserved7,		"m",	4,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcReserved8,		"m",	4,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcUser,			"m",	4,		0)
			);
	}

	bool iiDbf_validate_isFrx(SWorkArea* wa)
	{
		SFieldRecord2* lfptr2;

		//////////
		//
		// FRX required structure:
		//
		//	platform		c(8)
		//	uniqueId		c(10)
		//	timeStamp		n(10)
		//	objType			n(2)
		//	objCode			n(3)
		//	name			m
		//	expr			m
		//	vpos			n(9,3)
		//	hpos			n(9,3)
		//	height			n(9,3)
		//	width			n(9,3)
		//	style			m
		//	picture			m
		//	order			m nocptran
		//	unique			l
		//	comment			m
		//	environ			l
		//	boxchar			c(1)
		//	fillchar		c(1)
		//	tag				m
		//	tag2			m nocptran
		//	penred			n(5)
		//	pengreen		n(5)
		//	penblue			n(5)
		//	fillred			n(5)
		//	fillgreen		n(5)
		//	fillblue		n(5)
		//	pensize			n(5)
		//	penpat			n(5)
		//	fillpat			n(5)
		//	fontface		m
		//	fontstyle		n(3)
		//	fontsize		n(3)
		//	mode			n(3)
		//	ruler			n(1)
		//	rulerlines		n(1)
		//	grid			l
		//	gridv			n(2)
		//	gridh			n(2)
		//	float			l
		//	stretch			l
		//	stretchtop		l
		//	top				l
		//	bottom			l
		//	suptype			n(1)
		//	suprest			n(1)
		//	norepeat		l
		//	resetrpt		n(2)
		//	pagebreak		l
		//	colbreak		l
		//	resetpage		l
		//	general			n(3)
		//	spacing			n(3)
		//	double			l
		//	swapheader		l
		//	swapfooter		l
		//	ejectbefor		l
		//	ejectafter		l
		//	plain			l
		//	summary			l
		//	addalias		l
		//	offset			n(3)
		//	topmargin		n(3)
		//	botmargin		n(3)
		//	totaltype		n(2)
		//	resettotal		n(2)
		//	resoid			n(3)
		//	curpos			l
		//	supalways		l
		//	supovflow		l
		//	suprpcol		n(1)
		//	supgroup		n(2)
		//	supvalchng		l
		//	supexpr			m
		//	user			m
		//
		//////
			return(
								iiDbf_validate_fieldExists(wa,	cgcPlatform,		"c",	8,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcUniqueId,		"c",	10,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcTimeStamp,		"n",	10,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcObjType,			"n",	2,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcObjCode,			"n",	3,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcName,			"m",	4,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcExpr,			"m",	4,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcVpos,			"n",	9,		3)
				&&				iiDbf_validate_fieldExists(wa,	cgcHpos,			"n",	9,		3)
				&&				iiDbf_validate_fieldExists(wa,	cgcHeight,			"n",	9,		3)
				&&				iiDbf_validate_fieldExists(wa,	cgcWidth,			"n",	9,		3)
				&&				iiDbf_validate_fieldExists(wa,	cgcStyle,			"m",	4,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcPicture,			"m",	4,		0)
				&&	((lfptr2 =	iiDbf_validate_fieldExists(wa,	cgcOrder,			"m",	4,		0))		&&	(lfptr2->flags & _DBF_FIELD_BINARY) != 0)
				&&				iiDbf_validate_fieldExists(wa,	cgcUnique,			"l",	1,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcComment,			"m",	4,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcEnviron,			"l",	1,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcBoxChar,			"c",	1,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcFillChar,		"c",	1,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcTag,				"m",	4,		0)
				&&	((lfptr2 =	iiDbf_validate_fieldExists(wa,	cgcTag2,			"m",	4,		0))		&&	(lfptr2->flags & _DBF_FIELD_BINARY) != 0)
				&&				iiDbf_validate_fieldExists(wa,	cgcPenRed,			"n",	5,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcPenGreen,		"n",	5,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcPenBlue,			"n",	5,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcFillRed,			"n",	5,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcFillGreen,		"n",	5,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcFillBlue,		"n",	5,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcPenSize,			"n",	5,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcPenPat,			"n",	5,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcFillPat,			"n",	5,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcFontFace,		"m",	4,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcFontStyle,		"n",	3,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcFontSize,		"n",	3,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcMode,			"n",	3,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcRuler,			"n",	1,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcRulerLines,		"n",	3,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcGrid,			"l",	1,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcGridY,			"n",	2,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcGridH,			"n",	2,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcFloat,			"l",	1,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcStretch,			"l",	1,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcStretchTop,		"l",	1,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcTop,				"l",	1,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcBottom,			"l",	1,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcSubType,			"n",	1,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcSubRest,			"n",	1,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcNoRepeat,		"l",	1,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcResetRpt,		"n",	2,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcPageBreak,		"l",	1,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcColBreak,		"l",	1,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcResetPage,		"l",	1,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcGeneral,			"n",	1,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcSpacing,			"n",	1,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcDouble,			"l",	1,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcSwapHeader,		"l",	1,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcSwapFooter,		"l",	1,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcEjectBefore,		"l",	1,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcEjectAfter,		"l",	1,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcPlain,			"l",	1,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcSummary,			"l",	1,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcAddAlias,		"l",	1,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcOffset,			"n",	3,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcTopMargin,		"n",	3,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcBotMargin,		"n",	3,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcTotalType,		"n",	2,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcResetTotal,		"n",	2,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcResoId,			"n",	3,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcCurPos,			"l",	1,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcSupAlways,		"l",	1,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcSupOvflow,		"l",	1,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcSupRpcol,		"n",	1,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcGroup,			"n",	2,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcSupValChng,		"l",	1,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcSupExpr,			"m",	4,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcUser,			"m",	4,		0)
			);
	}

	bool iiDbf_validate_isMnx(SWorkArea* wa)
	{
		//////////
		// MNX required structure:
		//
		// 	objtype			n(2)
		// 	objcode			n(2)
		// 	name			m
		// 	prompt			m
		// 	command			m
		// 	message			m
		// 	proctype		n(1)
		// 	procedure		m
		// 	setuptype		n(1)
		// 	setup			m
		// 	cleantype		n(1)
		// 	cleanup			m
		// 	mark			c(1)
		// 	keyname			m
		// 	keylabel		m
		// 	skipfor			m
		// 	namechange		l
		// 	numitems		n(2)
		// 	levelname		c(10)
		// 	itemnum			c(3)
		// 	comment			m
		// 	location		n(2)
		// 	scheme			n(2)
		// 	sysres			n(1)
		// 	resname			m
		//
		//////
			return(
								iiDbf_validate_fieldExists(wa,	cgcObjType,			"n",	2,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcObjCode,			"n",	2,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcName,			"m",	4,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcPrompt,			"m",	4,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcCommand,			"m",	4,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcMessage,			"m",	4,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcProcType,		"n",	1,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcProcedure,		"m",	4,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcSetupType,		"n",	1,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcSetup,			"m",	4,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcCleanType,		"n",	1,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcCleanup,			"m",	4,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcMark,			"c",	1,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcKeyName,			"m",	4,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcKeyLabel,		"m",	4,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcSkipFor,			"m",	4,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcNameChange,		"l",	1,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcNumItems,		"m",	4,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcLevelName,		"c",	10,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcItemNum,			"c",	3,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcComment,			"m",	4,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcLocation,		"n",	2,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcScheme,			"n",	2,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcSysRes,			"n",	1,		0)
				&&				iiDbf_validate_fieldExists(wa,	cgcResName,			"m",	4,		0)
			);
	}




//////////
//
// Called to return the entire FoxPro header to the specified buffer
//
// Parameters:
//		handle			- Slot for the previously opened table
//		dest			- Memory location for storing the header
//		dest_length		- Length of the dest memory area
//		* Note:	 If -1, then the returned value will be the number of bytes for the buffer size
//
// Returns:
//		-1			- Invalid handle
//		-2			- Insufficient dest_length
//		others		- Size, in bytes, of the header
//
/////
	u32 dbf_get_header(u32 tnWorkArea, s8 *dest, u32 dest_length)
	{
		u32 lTotal_size;


		// Check for errors
		if (tnWorkArea >= _MAX_DBF_SLOTS)
		{
			// Invalid slot number
			return(-1);
		}

		if (gsWorkArea[tnWorkArea].isUsed != _YES)
		{
			// Invalid slot
			return(-1);
		}

		// Return the record count
		lTotal_size = sizeof(STableHeader) + (gsWorkArea[tnWorkArea].fieldCount * sizeof(SFieldRecord1));
		if (dest_length < lTotal_size)
		{
			// Not enough space for the copy
			return(-2);
		}


		// We're good, see what they want us to do
		if (dest_length == (u32)-1)
		{
			// They want to know how many bytes to allocate
			return(lTotal_size);
		}


		// Copy the actual data
		memcpy(dest, (s8*)&gsWorkArea[tnWorkArea].header, sizeof(STableHeader));
		memcpy(dest + sizeof(STableHeader), (s8*)gsWorkArea[tnWorkArea].fieldPtr1, gsWorkArea[tnWorkArea].fieldCount * sizeof(SFieldRecord1));


		// All done!
		return(lTotal_size);
	}




//////////
//
// Called to get the node type with only the lower 2-bits being pulled through
//
//////
	u32 iiGetIndexNodeType(u32 tnNode)
	{
		return(tnNode & 0x3);
	}




//////////
//
// Called to free and NULL a memory pointer.
// Checking is performed prior-to to make sure the pointer isn't already NULL.
//
/////
	void iiFreeAndSetToNull(void** ptr)
	{
		if (*ptr != NULL)
		{
			// Free the memory
			free(*ptr);
			*ptr = NULL;
		}
	}




//////////
//
// Called to create a temporary filename
//
/////
	void iiGetTemporaryFilename(s8 *temp_file, s8 *prefix)
	{
		GetTempFileName(gcDbf_temporaryPath, prefix, gnDbf_temporaryFileNumber++, temp_file);
		iiLowerCaseString(temp_file, (u32)strlen(temp_file));
	}




//////////
//
// Called to convert all of the s8acters inside of a string to lower-case
//
/////
	void iiLowerCaseString(s8 *string, u32 length)
	{
		while (length > 0)
		{
			if (*string >= 'A' && *string <= 'Z')
			{
				*string += 0x20;
			}
			++string;
			--length;
		}
	}




//////////
//
// Called to extract "vendor" from "c:\some\path\vendor.dbf"
//
//////
	void iiJuststem(SWorkArea* wa, s8* alias)
	{
		s32		lnI, lnJ;
		s8*		name;


		//////////
		// Get the path
		//////
		// Begin at the end
		name = wa->tablePathname;

		// Back off until we reach the directory indicator, or the beginning
		for (lnI = wa->tablePathnameLength - 1; lnI >= 0; lnI--)
		{
			// Have we reached the backslash?
			if (name[lnI] == '\\')
			{
				++lnI;
				break;
			}
		}
		if (lnI < 0)
			lnI = 0;

		// Copy the part of the name
		memcpy(alias, name + lnI, wa->tablePathnameLength - lnI + 1);

		// Search forward and null-terminate at the period
		for (lnJ = 0; alias[lnJ] != 0 && lnJ < wa->tablePathnameLength - lnI; lnJ++)
		{
			// Is this the period?
			if (alias[lnJ] == '.')
				break;
		}

		// NULL terminate at that point
		alias[lnJ] = 0;
	}




//////////
//
// Called to force the specified s8acter to lower-case
//
// Parameters:
//		s8 c	  - s8acter
//
// Returns:
//		s8 c	  - Lower-cased version of c (such that "A" = "a", and "Z" = "z", but "a" = "a" and "z" = "z", etc.)
//
/////
	void iiUpperCase(u8* cptr)
	{
		u8 c = *cptr;

		if (c >= 'a' && c <= 'z')
			*cptr -= 0x20;
	}

	void iiLowerCase(u8* cptr)
	{
		u8 c = *cptr;

		if (c >= 'A' && c <= 'Z')
			*cptr += 0x20;
	}

	u8 iiLowerCase_char(u8 c)
	{
		if (c >= 'A' && c <= 'Z')
			c |= 0x20;			// Turn on the 0x20 bit, which moves it from the 0x40+ range to the 0x60+ range (lower-case)
		
		return(c);
	}




//////////
//
// Support for Julian dates.
//
//////
	// Note:  Expecting a full date format, as in "20140201" for Feb.01.2014
	u32 iiJulianDayNumber_fromYyyyMmDd_s8(u8* year4, u8* month2, u8* day2)
	{
		u32 lnYear, lnMonth, lnDay;
		s8 buffer[16];


		//////////
		// Translate text form into numeric form
		//////
			// Year
			memcpy(buffer, (s8*)year4, 4);
			buffer[4] = 0;
			lnYear = atoi(buffer);

			// Month
			memcpy(buffer, (s8*)month2, 2);
			buffer[2] = 0;
			lnMonth = atoi(buffer);

			// Day
			memcpy(buffer, (s8*)day2, 2);
			lnDay = atoi(buffer);

		// Convert by value
		return(iiJulianDayNumber_fromYyyyMmDd_u32(lnYear, lnMonth, lnDay));
	}

	u32 iiJulianDayNumber_fromYyyyMmDd_u32(u32 year, u32 month, u32 day)
	{
		s32		monthAdjust1, monthAdjust2;
		f64		a, y, m, lfJulianDayNumber;


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
			lfJulianDayNumber =	(f64)day +
									floor(((153.0 * m) + 2.0) / 5.0) +
									(365.0 * y) +
									floor(y / 4.0) -
									floor(y / 100.0) +
									floor(y / 400.0) -
									32045.0;


//		//////////
//		// For Julian calendar dates (dates before October 15, 1582):
//		//////
//			lfJulianDayNumber = (f64)day +
//									floor(((153.0 * m) + 2.0) / 5.0) +
//									(365.0 * y) +
//									floor(y / 4.0) -
//									32083.0;


		// Return the rounded result
		return((s32)lfJulianDayNumber);
	}

	void iiYyyyMmDd_fromJulianDayNumber(u32	 tnJulianDayNumber, u8* year4, u8* month2, u8* day2)
	{
		u32 a, b, c, d, e, m;
		u32 day, month, year;

		a		= tnJulianDayNumber + 32044;
		b		= ((4 * a) + 3) / 146097;
		c		= a - ((b * 146097) / 4);
		d		= ((4 * c) + 3) / 1461;
		e		= c - ((1461 * d) / 4);
		m		= ((5 * e) + 2) / 153;
		day		= e - (((153 * m) + 2) / 5) + 1;
		month	= m + 3 - (12 * (m / 10));
		year	= (b * 100) + d - 4800 + (m / 10);

		// Store in text form
		sprintf((s8*)year4,		"%04u", year);
		sprintf((s8*)month2,	"%02u", month);
		sprintf((s8*)day2,		"%02u", day);
	}

	void iiHhMmSsMss_fromf32(f32 tfSeconds, u32* hour, u32* minute, u32* second, u32* millisecond)
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
// Character test helpers
//
//////
	bool isAlpha(s8 c)
	{
		// Alpha?
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_')		return(true);
		else																	return(false);
	}

	bool isNumeric(s8 c)
	{
		// Numeric?
		if ((c >= '0' && c <= '9') || c == '-' || c == '+')						return(true);
		else																	return(false);
	}

	bool isDotExpression(s8 c)
	{
		// A dot-expression?
		if (c == '.')															return(true);
		else																	return(false);
	}

	bool isComparator(s8 c)
	{
		// A comparison expression?
		if (c == '=' || c == '!' || c == '>' || c == '<' || c == '#')			return(true);
		else																	return(false);
	}

	bool isQuote(s8 c)
	{
		// A quote?
		if (c == 34/* " */ || c == 39/* ' */)									return(true);
		else																	return(false);
	}

	bool isNotSymbol(s8 c)
	{
		// An exclamation point?
		if (c == '!')															return(true);
		else																	return(false);
	}

	bool isParenthesis(s8 c)
	{
		// A parenthesis?
		if (c == '(' || c == ')')												return(true);
		else																	return(false);
	}

	bool isBracket(s8 c)
	{
		// A bracket?
		if (c == '[' || c == ']')												return(true);
		else																	return(false);
	}

	bool isBrace(s8 c)
	{
		// A brace?
		if (c == '{' || c == '}')												return(true);
		else																	return(false);
	}

	bool isWhitespace(s8 c)
	{
		// A brace?
		if (c == 32 || c == 9)													return(true);
		else																	return(false);
	}
