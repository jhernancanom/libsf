//////////
//
// /libsf/source/vjr/sem_line.cpp
//
//////
// Version 0.54
// Copyright (c) 2014 by Rick C. Hodgin
//////
// Last update:
//     Jul.06.2014
//////
// Change log:
//     Jul.06.2014 - Initial creation
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




//////////
//
// Called to make sure enough information is populated currently in the sem->ecCursorLine->sourceCode
// buffer for the new indicated line length.
//
//////
	bool iEditChain_ensureLineLength(SEM* sem, s32 newLineLength)
	{
		SLine* line;


		// Make sure the environment is sane
		if (sem && sem->line_cursor)
		{
			// Has this line had its data allocated?
			line = sem->line_cursor;
			if (!line->sourceCode)
			{
				// We need to allocate the initial data block
				iDatum_allocateSpace(line->sourceCode, max((s32)_ECM_MINIMUM_LINE_ALLOCATION_LENGTH, newLineLength));
				line->sourceCode_populatedLength	= 0;
			}

			// Is there room from where we are to the new line length?
			if (line->sourceCode->length > newLineLength)
				return(true);		// We're good

			// If we get here, we need to reallocate
			return(iDatum_resize(line->sourceCode, newLineLength + _ECM_MINIMUM_LINE_ALLOCATION_LENGTH));
		}
		// If we get here, failure
		return(false);
	}




//////////
//
// Free the edit chain
//
//////
	void iEditChain_free(SLine** root, bool tlDeleteSelf)
	{
		SLine*		line;
		SLine*		lineNext;


		// Make sure our environment is sane
		if (root && *root)
		{
			//////////
			// Repeat throughout the entire chain
			//////
				line = *root;
				while (line)
				{
					//////////
					// Note next item in chain
					//////
						lineNext = (SLine*)line->ll.next;


					//////////
					// Delete any extra information associated with this chain entry
					//////
						iExtraInfo_free(NULL, line, &line->extra_info, true);


					//////////
					// Delete this item's components and source code references
					//////
						iComps_deleteAll_byLine(line);
						iDatum_delete(line->sourceCode, true);


					//////////
					// Free self
					//////
						if (tlDeleteSelf)
							free(line);


					//////////
					// Move to next item in the chain
					//////
						line = lineNext;
				}


			//////////
			// Free self
			//////
				if (tlDeleteSelf)
					*root = NULL;	// It would've been freed above, so we just update the pointer
		}
	}




//////////
//
// Called to insert a character
//
//////
	bool iEditChain_characterInsert(SEM* sem, u8 asciiChar)
	{
		s32			lnI;
		SLine*		line;


		// Make sure our environment is sane
		if (sem && !sem->isReadOnly && sem->line_cursor && sem->line_cursor->sourceCode)
		{
			// Make sure there's room enough for the keystroke
			line = sem->line_cursor;
			if (iEditChain_ensureLineLength(sem, sem->line_cursor->sourceCode_populatedLength + 1))
			{
				// They could've been beyond the end of line, and if so then we need to insert spaces between the end and here
				if (sem->columnEdit > line->sourceCode_populatedLength)
				{
					// Fill with spaces
					for (lnI = line->sourceCode_populatedLength; lnI < sem->columnEdit; lnI++)
						line->sourceCode->data[lnI] = ' ';
				}

				// Move everything from the end of the line to where we are right one character
				for (lnI = line->sourceCode_populatedLength + 1; lnI > sem->columnEdit && lnI > 0; lnI--)
					line->sourceCode->data[lnI] = line->sourceCode->data[lnI - 1];

				// Insert the character
				line->sourceCode->data[sem->columnEdit] = asciiChar;

				// Move to the next column
				++sem->columnEdit;

				// Increase the populated length
				++line->sourceCode_populatedLength;

				// If we're past the end, we need to indicate our populated line length
				if (sem->columnEdit > line->sourceCode_populatedLength)
					line->sourceCode_populatedLength = sem->columnEdit;

				// Indicate success
				return(true);
			}
		}

		// If we get here, we could not insert it
		return(false);
	}




//////////
//
// Called to overwrite the existing character wherever we are
//
//////
	bool iEditChain_characterOverwrite(SEM* sem, u8 asciiChar)
	{
		s32			lnI;
		SLine*		line;


		// Make sure our environment is sane
		if (sem && !sem->isReadOnly && sem->line_cursor && sem->line_cursor->sourceCode)
		{
			// Is there room to inject it?
			line = sem->line_cursor;
			if (iEditChain_ensureLineLength(sem, sem->line_cursor->sourceCode_populatedLength + 1))
			{
				if (sem->columnEdit > line->sourceCode_populatedLength)
				{
					// We need to insert it because we're at the end of the populated length
					return(iEditChain_characterInsert(sem, asciiChar));

				} else {
					// We can overwrite it

					// They could've been beyond the end of line, and if so then we need to insert spaces between the end and here
					if (sem->columnEdit > line->sourceCode_populatedLength)
					{
						// Fill with spaces
						for (lnI = line->sourceCode_populatedLength; lnI < sem->columnEdit; lnI++)
							line->sourceCode->data[lnI] = ' ';
					}

					// Overwrite the character
					line->sourceCode->data[sem->columnEdit] = asciiChar;

					// Move to the next column
					++sem->columnEdit;

					// If we're past the end, we need to indicate our populated line length
					if (sem->columnEdit > line->sourceCode_populatedLength)
						line->sourceCode_populatedLength = sem->columnEdit;

					// Indicate success
					return(true);
				}
			}
		}

		// If we get here, we could not overwrite
		return(false);
	}




//////////
//
// Called to delete the character where we are, which, depending on insert mode,
// will affect the line in different ways.
//
//////
	bool iEditChain_characterDelete(SEM* sem)
	{
		s32		lnI;
		SLine*	line;


		// Make sure our environment is sane
		if (sem && !sem->isReadOnly && sem->line_cursor && sem->line_cursor->sourceCode)
		{
			// Grab the line
			line = sem->line_cursor;

			// If we're in the populated area
			if (sem->columnEdit < line->sourceCode_populatedLength)
			{
				// Move everything left one character
				for (lnI = sem->columnEdit; lnI < line->sourceCode_populatedLength; lnI++)
					line->sourceCode->data[lnI] = line->sourceCode->data[lnI + 1];

				// Reduce the length of the populated portion of the line by one
				--line->sourceCode_populatedLength;

				// Put a space there
				line->sourceCode->data[line->sourceCode_populatedLength] = 32;

				// Indicate success
				return(true);
			}
		}

		// If we get here, we could not overwrite
		return(false);
	}




//////////
//
// Called to toggle the breakpoint on the current line
//
//////
	SBreakpoint* iEditChain_toggleBreakpoint(SEM* sem)
	{
		SBreakpoint* bp;


		// Make sure our environment is sane
		if (sem && sem->line_cursor)
		{
			// Grab the line
			if (sem->line_cursor->breakpoint)
			{
				// Delete the existing breakpoint
				iBreakpoint_delete(&sem->line_cursor->breakpoint);
				bp = NULL;

			} else {
				// Adding a new always-stop breakpoint
				bp = iBreakpoint_add(&sem->line_cursor->breakpoint, _BREAKPOINT_ALWAYS);
			}

			// Indicate our statuts
			return(bp);
		}

		// If we get here, invalid
		return(NULL);
	}




//////////
//
// Called to see if a line has changed
//
//////
	bool iEditChain_hasChanged(SLine* ec)
	{
		// Make sure our environment is sane
		if (ec && ec->sourceCode && ec->sourceCodeOriginal)
		{
			// Test lengths
			if (ec->sourceCode_populatedLength != ec->sourceCodeOriginal->length)
				return(true);		// They are different lengths

			// Test content
			if (memcmp(ec->sourceCode->data, ec->sourceCodeOriginal->data, ec->sourceCode_populatedLength) != 0)
				return(true);		// The content is different
		}
		// If we get here, not changed
		return(false);
	}
