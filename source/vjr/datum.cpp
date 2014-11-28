//////////
//
// /libsf/source/vjr/datum.cpp
//
//////
// Version 0.54
// Copyright (c) 2014 by Rick C. Hodgin
//////
// Last update:
//     Nov.27.2014
//////
// Change log:
//     Nov.27.2014 - Initial creation
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
// Datum storage
//
//////
	void iDatum_allocateSpace(SDatum* datum, s32 dataLength)
	{
		// Make sure our environment is sane
		if (datum)
		{
			if (datum->data && datum->length != dataLength)
			{
				// Release anything that's already there
				iiDatum_delete(datum);
			}

			// Allocate the space
			if (dataLength > 0)
				datum->data = (s8*)malloc(dataLength);

			// Set the length
			datum->length = dataLength;

			// Initialize
			if (datum->data)
				memset(datum->data, 0, dataLength);
		}
	}

	SDatum* iDatum_allocate(s8* data, s32 dataLength)
	{
		SDatum* datumNew;


		// Allocate our new datum
		datumNew = (SDatum*)malloc(sizeof(SDatum));
		if (datumNew)
		{
			// Initialize
			memset(datumNew, 0, sizeof(SDatum));

			// Copy over the content
			if (data && dataLength)
			{
				// We may need to set the length
				if (dataLength < 0)
					dataLength = strlen(data);

				// Initialize
				memset(datumNew, 0, sizeof(SDatum));

				// Populate
				iDatum_duplicate(datumNew, data, dataLength);
			}
		}

		// Indicate our status
		return(datumNew);
	}

	void iDatum_duplicate(SDatum* datum, s8* data, s32 dataLength)
	{
		// Make sure our environment is sane
		if (datum && data)
		{
			// We may need to set the length
			if (dataLength < 0)
				dataLength = strlen(data);

			// Release anything that's already there
			iiDatum_delete(datum);

			// Store the new data
			if (dataLength > 0)
			{
				datum->data = (s8*)malloc(dataLength);

				// Copy over if we were successful
				if (datum->data)
					memcpy(datum->data, data, dataLength);

			} else {
				// There is no data here
				datum->data = NULL;
			}

			// Store the new length
			datum->length = dataLength;
		}
	}

	void iDatum_duplicate(SDatum* datum, cs8* data, s32 dataLength)
	{
		iDatum_duplicate(datum, (s8*)data, dataLength);
	}

	void iDatum_duplicate(SDatum* datumDst, SDatum* datumSrc)
	{
		// Make sure our environment is sane
		if (datumDst && datumSrc && datumSrc->data)
			iDatum_duplicate(datumDst, datumSrc->data, datumSrc->length);
	}

	bool iDatum_resize(SDatum* datum, s32 newDataLength)
	{
		s8* ptr;


		// Make sure our environment is sane
		if (datum && newDataLength != 0)
		{
			if (datum->length == newDataLength)
				return(true);		// It's already the same length

			// Allocate our new block
			ptr = (s8*)malloc(newDataLength);
			if (ptr)
			{
				// Copy everything that will fit
				memcpy(ptr, datum->data, min(newDataLength, datum->length));

				// Fill the remainder with NULLs if any
				if (newDataLength > datum->length)
					memset(ptr + datum->length, 0, newDataLength - datum->length);

				// Delete the old data
				if (datum->data)
					free(datum->data);

				// And populate with the new data
				datum->data		= ptr;
				datum->length	= newDataLength;

				// All done
				return(true);

			} else {
				// Failure
				return(false);
			}

		} else {
			// No data to work with
			return(false);
		}
	}

	// Returns -1, 0, or 1 (indicating left is less than, equal to, or greater than right)
	s32 iDatum_compare(SDatum* datumLeft, SDatum* datumRight)
	{
		s32 lnResult;


		// Default to invalid data
		lnResult = -2;

		// Make sure our environment is sane
		if (datumLeft && datumLeft->data && datumLeft->length != 0 && datumRight && datumRight->data && datumRight->length > 0)
		{
			// Do a standard compare
			lnResult = _memicmp(datumLeft->data, datumRight->data, min(datumLeft->length, datumRight->length));
		}

		// Indicate our result
		return(lnResult);
	}

	s32 iDatum_compare(SDatum* datumLeft, s8* data, s32 dataLength)
	{
		s32 lnResult;


		// Default to invalid data
		lnResult = -2;

		// Make sure our environment is sane
		if (datumLeft && datumLeft->data && datumLeft->length != 0 && data)
		{
			// Make sure our length is set
			if (dataLength < 0)
				dataLength = strlen(data);

			// Do a standard compare
			lnResult = _memicmp(datumLeft->data, data, min(datumLeft->length, dataLength));
		}

		// Indicate our result
		return(lnResult);
	}

	s32 iDatum_compare(SDatum* datumLeft, cs8* data, s32 dataLength)
	{
		return(iDatum_compare(datumLeft, (s8*)data, dataLength));
	}

	void iDatum_delete(SDatum* datum, bool tlDeleteSelf)
	{
		// Make sure our environment is sane
		if (datum)
		{
			// Delete the content
			iiDatum_delete(datum);

			// Delete self if need be
			if (tlDeleteSelf)
				free(datum);
		}
	}

	void iiDatum_delete(SDatum* datum)
	{
		// Make sure our environment is sane
		if (datum->data)
		{
			free(datum->data);
			datum->data = NULL;
		}

		// Reset the length to zero
		datum->length = 0;
	}
