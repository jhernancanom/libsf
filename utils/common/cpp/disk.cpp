//////////
//
// /libsf/utils/common/cpp/disk.cpp
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
// Version 0.55
// Copyright (c) 2014 by Rick C. Hodgin
//////
// Last update:
//	   Mar.05.2015 - Initial creation
//////
// Change log:
//	   Mar.05.2015 - Initial creation
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
//////
//   _____   _       _
//  |  __ \ (_)     | |
//  | |  | | _  ___ | | __
//  | |  | || |/ __|| |/ /
//  | |__| || |\__ \|   <
//  |_____/ |_||___/|_|\_\
//     Disk Algorithms.
//////////




//////////
//
// Called to open the file using custom share settings, or explicitly shared,
// or explicitly exclusive.
//
//////
	s32 iDisk_open(s8* tcPathname, s32 tnType, s32 tnShare)
	{
		// Attempt to open if valid
		if (tcPathname)
			return(_sopen(tcPathname, tnType, tnShare));


		// If we get here, invalid filename
		return(-1);
	}

	s32 iDisk_openShared(s8* tcPathname, s32 tnType)
	{
		// Attempt to open if valid
		if (tcPathname)
			return(_sopen(tcPathname, tnType, _SH_DENYNO));


		// If we get here, invalid filename
		return(-1);
	}

	s32 iDisk_openExclusive(s8* tcPathname, s32 tnType)
	{
		// Attempt to open if valid
		if (tcPathname)
			return(_sopen(tcPathname, tnType, _SH_DENYRW));


		// If we get here, invalid filename
		return(-1);
	}




//////////
//
// Obtain the file size
//
//////
	s64 iDisk_getFileSize(s32 tnFile)
	{
		return(_filelengthi64(tnFile));
	}




//////////
//
// Called to potentially retry so long as the callback returns true.
//
//////
	SDiskLock* iDisk_lock_range_retryCallback(SThisCode* thisCode, SBuilder* buffRoot, s32 tnFile, s64 tnOffset, s32 tnLength, uptr tnCallbackFunction, uptr tnExtra)
	{
		s32					lnAttempts, lnMillisecondsDelta;
		s64					lnMillisecondsStart;
		SDiskLock*			dl;
		SDiskLockCallback	dcb;


		//////////
		// Initialize
		//////
			memset(&dcb, 0, sizeof(dcb));
			dcb._diskRetryLockCallback	= tnCallbackFunction;
			dcb.extra					= tnExtra;
			lnAttempts = 0;


		//////////
		// Begin the trial
		//////
			GetLocalTime(&dcb.timeStart);
			lnMillisecondsStart = iTime_computeMilliseconds(&dcb.timeStart);
			while (1)
			{

				//////////
				// Try to lock
				//////
					++lnAttempts;
					dl = iDisk_lock_range(thisCode, buffRoot, tnFile, tnOffset, tnLength, tnExtra);


				//////////
				// Were we successful?
				//////
					if (dl && dl->nLength == tnLength)
						return(dl);	// Yes


				//////////
				// When we get here, we need to see if they want to continue waiting or not
				//////
					GetLocalTime(&dcb.timeNow);
					lnMillisecondsDelta = (s32)iTime_computeMillisecondsBetween(&dcb.timeNow, lnMillisecondsStart);


				//////////
				// Inquire politely about our retry
				//////
					if (!dcb._diskRetryLockCallback || !dcb.diskRetryLockCallback(thisCode, &dcb, lnAttempts, lnMillisecondsDelta))
					{
						// They inform us:  "No more waiting!"
						return(dl);	// Failure
					}
					// If we get here, try again

			}
	}




//////////
//
// Called to lock a disk range, and append the information to the buffer.
//
// Note:  It returns a pointer to the SDisk entry that was just added, however
//        it should not generally be modified directly, but only used as a handle.
//
// Note:  Examine success with this test:
//
//				SDiskLock* dl;
//				dl = iDisk_lock_range(..., lnLength...);
//				if (dl && dl->nLength == lnLength)
//				{
//				    // Success
//				} else {
//				    // Failure
//				}
//
// Note:  If success, upon exit, the file will be positioned at the locking address.
//
// Note:  If not success, it may be positioned at the locking address depending on
//                        when the error occurred.
//
//////
	SDiskLock* iDisk_lock_range(SThisCode* thisCode, SBuilder* buffRoot, s32 tnFile, s64 tnOffset, s32 tnLength, uptr tnExtra)
	{
		// Make sure our environment is sane
		if (buffRoot && buffRoot->buffer && buffRoot->populatedLength % sizeof(SDiskLock) == 0)
		{
			// Lock it
			return(iiDisk_lock_range(thisCode, buffRoot, tnFile, tnOffset, tnLength, tnExtra));

		} else {
			// Indicate error
			return(NULL);
		}
	}

	SDiskLock* iiDisk_lock_range(SThisCode* thisCode, SBuilder* buffRoot, s32 tnFile, s64 tnOffset, s32 tnLength, uptr tnExtra)
	{
		u32			lnI;
		SDiskLock*	dl;


		//////////
		// Iterate to find an empty slot
		//////
			for (lnI = 0, dl = (SDiskLock*)buffRoot->buffer; lnI < buffRoot->populatedLength; lnI += sizeof(SDiskLock), dl++)
			{
				// Is this slot empty?
				if (!dl->isValid)
					break;	// Yes
			}


		//////////
		// When we get here, we have a slot or not
		//////
			if (lnI >= buffRoot->populatedLength)
			{
				// Create a new one
				dl = (SDiskLock*)iBuilder_appendData(buffRoot, NULL, sizeof(SDiskLock));
				// Note:  disk members are all initialized to 0s
			}


		//////////
		// Physically try the lock
		//////
			dl->isValid = true;
			dl->nFile	= tnFile;
			dl->nOffset	= tnOffset;
			dl->nLength	= 0;

			// Seek to the offset
			if (_lseeki64(tnFile, tnOffset, SEEK_SET) == tnOffset)
			{
				// Lock the bytes
				if (_locking(tnFile, _LK_NBLCK, tnLength) == 0)
				{
					// Indicate a successful lock
					dl->nLength = tnLength;
				}

			} else {
				// The length being 0 will indicate the lock failed
				// So we just let it fall through
			}


		//////////
		// Indicate success or failure
		//////
			return(dl);
	}




//////////
//
// Called to unlock a previously locked disk range using iDisk_lock().
//
// Note:  After unlocking, the slot in the original buffRoot is freed, available for re-use.
//
//////
	bool iDisk_unlock(SThisCode* thisCode, SBuilder* buffRoot, SDiskLock* dl)
	{
		// Make sure our environment is sane
		if (iiDisk_isValidLockHandle(thisCode, buffRoot, dl))
		{
			// Unlock it
			return(iiDisk_unlock(thisCode, buffRoot, dl));
		}

		// If we get here, failure
		return(false);
	}

	bool iiDisk_unlock(SThisCode* thisCode, SBuilder* buffRoot, SDiskLock* dl)
	{
		bool llResult;


		// If it's a valid lock, unlock it
		llResult = false;
		if (dl->isValid)
		{
			// Seek
			if (_lseeki64(dl->nFile, dl->nOffset, SEEK_SET) == dl->nOffset)
			{
				// Unlock
				llResult = (_locking(dl->nFile, _LK_UNLCK, dl->nLength) == 0);

			} else {
				// If we get here, the file is likely no longer open, so all locks are closed
				// But, we just silently fall through
			}

			// If cleared, indicate the lock is no longer valid
			dl->isValid = !llResult;
		}

		// Indicate success or failure
		return(llResult);
	}




//////////
//
// Called to unlock everything contained within the buffer.
//
// Note:  After use, all locks created by iDisk_lock() will be released, and every
//        slot in the buffRoot buffer is available for re-use.
//
//////
	void iDisk_unlock_all(SThisCode* thisCode, SBuilder* buffRoot)
	{
		// Make sure our environment is sane
		if (buffRoot && buffRoot->buffer && buffRoot->populatedLength % sizeof(SDiskLock) == 0)
		{
			// Unlock it
			iiDisk_unlock_all(thisCode, buffRoot);
		}
	}

	void iiDisk_unlock_all(SThisCode* thisCode, SBuilder* buffRoot)
	{
		u32			lnI;
		SDiskLock*	dl;


		// If it's a valid lock, unlock it
		for (lnI = 0, dl = (SDiskLock*)buffRoot->buffer; lnI < buffRoot->populatedLength; lnI += sizeof(SDiskLock), dl++)
		{
			// Is this one locked?
			if (dl->isValid)
			{
				// Seek
				if (_lseeki64(dl->nFile, dl->nOffset, SEEK_SET) == dl->nOffset)
				{
					// Unlock
					_locking(dl->nFile, _LK_UNLCK, dl->nLength);

				} else {
					// If we get here, the file is likely no longer open, so all locks are closed
					// But, we just silently fall through
				}

				// Indicate the lock is no longer valid
				dl->isValid = false;
			}
		}
	}




//////////
//
// Called to unlock a disk range by using a callback test to determine if the
// unlock should be performed on a case-by-case basis.
//
// Note:  Only those entries which are indicated are released.  The rest remain
//        locked unless they are manually unlocked.
//
//////
	s32 iDisk_unlock_all_byCallback(SThisCode* thisCode, SBuilder* buffRoot, uptr tnFunction, uptr tnExtra)
	{
		// Make sure our environment is sane
		if (buffRoot && buffRoot->buffer && buffRoot->populatedLength % sizeof(SDiskLock) == 0)
		{
			// Unlock it
			return(iiDisk_unlock_all_byCallback(thisCode, buffRoot, tnFunction, tnExtra));

		} else {
			// Something's awry, if we have a valid buffRoot, then indicate 0 records were unlocked
			return(-1);
		}
	}

	s32 iiDisk_unlock_all_byCallback(SThisCode* thisCode, SBuilder* buffRoot, uptr tnFunction, uptr tnExtra)
	{
		u32					lnI, lnUnlockedCount;
		SDiskLock*			dl;
		SDiskLockCallback	dcb;


		// Initialize
		memset(&dcb, 0, sizeof(dcb));
		dcb._diskUnlockCallback	= tnFunction;
		dcb.extra				= tnExtra;

		// If it's a valid lock, unlock it
		for (lnI = 0, lnUnlockedCount = 0, dl = (SDiskLock*)buffRoot->buffer; lnI < buffRoot->populatedLength; lnI += sizeof(SDiskLock), dl++)
		{
			// Is this one locked?  And do they want to release it?
			if (dl->isValid && (!dcb._diskUnlockCallback || !dcb.diskUnlockCallback(thisCode, &dcb)))
			{
				// Seek
				if (_lseeki64(dl->nFile, dl->nOffset, SEEK_SET) == dl->nOffset)
				{
					// Unlock
					_locking(dl->nFile, _LK_UNLCK, dl->nLength);
					++lnUnlockedCount;

				} else {
					// If we get here, the file is likely no longer open, so all locks are closed
					// But, we just silently fall through
				}

				// Indicate the lock is no longer valid
				dl->isValid = false;
			}
		}

		// Indicate our count
		return(lnUnlockedCount);
	}




//////////
//
// Check the handle to make sure it's valid
//
//////
	bool iiDisk_isValidLockHandle(SThisCode* thisCode, SBuilder* buffRoot, SDiskLock* dl)
	{
		//////////
		// Verify the handle is valid
		//////
			if (dl && iBuilder_isPointer(buffRoot, (uptr)dl))
			{
				// It's in range, but the valid condition depends upon its property
				return(dl->isValid);

			} else {
				// Indicate failure
				return(false);
			}
	}
