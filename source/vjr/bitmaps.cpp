//////////
//
// /libsf/source/vjr/bitmaps.cpp
//
//////
// Version 0.43
// Copyright (c) 2014 by Rick C. Hodgin
//////
// Last update:
//     Jun.17.2014
//////
// Change log:
//     Jun.17.2014 - Initial creation
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
// Allocates a new structure
//////
	SBitmap* iBmp_allocate(void)
	{
		SBitmap* bmp;


		// Allocate our new structure
		bmp = (SBitmap*)malloc(sizeof(SBitmap));

		// Initialize if successful
		if (bmp)
			memset(bmp, 0, sizeof(SBitmap));

		// Indicate our success or failure
		return(bmp);
	}
;




//////////
//
// Called to copy a bitmap, to duplicate it completely
//
//////
	SBitmap* iBmp_copy(SBitmap* bmpSrc)
	{
		SBitmap*	bmp;
		RECT		lrc;


		// Make sure our environment is sane
		bmp = NULL;
		if (bmpSrc && iBmp_validate(bmpSrc))
		{
			// Allocate a new structure
			bmp = iBmp_allocate();
			if (bmp)
			{
				// Create a bitmap of the target size
				iBmp_createBySize(bmp, bmpSrc->bi.biWidth, bmpSrc->bi.biHeight, bmpSrc->bi.biBitCount);
				
				// Copy the bitmap over
				SetRect(&lrc, 0, 0, bmpSrc->bi.biWidth, bmpSrc->bi.biHeight);
				iBmp_bitBlt(bmp, &lrc, bmpSrc);
			}
		}

		// Indicate our success or failure
		return(bmp);
	}




//////////
//
// Called to make sure there is a copy, and if not it creates it, and if so
// then makes sure they are the same size, and if not then deletes the existing
// one and creates a new copy of the same size.
//
// Note:  It does not bitblt into the copy, but only creates a bmp the same size.
//
//////
	SBitmap* iBmp_verifyCopyIsSameSize(SBitmap* bmpCopy, SBitmap* bmp)
	{
		SBitmap* bmpNew;


		// Make sure we have something that makes sense
		if (bmp)
		{
			if (bmpCopy)
			{
				// Make sure it's the same size
				if (bmp->bi.biWidth == bmpCopy->bi.biWidth && bmp->bi.biHeight == bmpCopy->bi.biHeight)
					return(bmpCopy);		// They're the same already

				// If we get here, we need to delete the copy
				iBmp_delete(&bmpCopy, true, true);
				// Note:  From now on we use bmpNew, and return that
			}

			// When we get here, we need to create a new one
			bmpNew = iBmp_allocate();
			if (bmpNew)
				iBmp_createBySize(bmpNew, bmp->bi.biWidth, bmp->bi.biHeight, bmp->bi.biBitCount);

			// Indicate our success or failure
			return(bmpNew);

		} else {
			// Unknown what the size is, so we just leave it the way it is
			return(bmpCopy);
		}
	}




//////////
//
// Called to verify the bitmap size is correct, and if not then it will create one of
// the correct size and scale this one into it.
//
//////
	SBitmap* iBmp_verifySizeOrResize(SBitmap* bmp, u32 tnWidth, u32 tnHeight, u32 tnBitCount)
	{
		SBitmap* bmpNew;


		// Make sure our environment is sane
		if (!bmp || bmp->bi.biWidth != (s32)tnWidth || bmp->bi.biHeight != (s32)tnHeight)
		{
			// Something has changed
			bmpNew = iBmp_allocate();
			iBmp_createBySize(bmpNew, tnWidth, tnHeight, ((bmp) ? bmp->bi.biBitCount : ((tnBitCount == 32 || tnBitCount == 24) ? tnBitCount : 24)));

			// Process the old
			if (bmp)
			{
				// Scale to the new one
				iBmp_scale(bmpNew, bmp);

				// Delete the old version
				iBmp_delete(&bmp, true, true);
			}
			// All done!

		} else {
			// They're the same
			bmpNew = bmp;
		}

		// Indicate our success
		return(bmpNew);
	}




//////////
//
// Called to load a bitmap file that was loaded from disk, or simulated loaded from disk.
//
//////
	SBitmap* iBmp_rawLoad(cu8* bmpRawFileData)
	{
		BITMAPFILEHEADER*	bh;
		BITMAPINFOHEADER*	bi;
		SBitmap				bmpLoad;
		SBitmap*			bmp;
		RECT				lrc;


		//////////
		// Grab the headers
		//////
			bh = (BITMAPFILEHEADER*)bmpRawFileData;
			bi = (BITMAPINFOHEADER*)(bh + 1);


		//////////
		// Initialize the bitmap, and populate
		//////
			bmp = iBmp_allocate();
			if (bmp)
			{
				// Prepare bmpLoad
				memcpy(&bmpLoad.bh, bh, sizeof(bmp->bh));
				memcpy(&bmpLoad.bi, bi, sizeof(bmp->bi));
				bmpLoad.bd			= (s8*)(bmpRawFileData + bh->bfOffBits);
				bmpLoad.rowWidth	= iBmp_computeRowWidth(&bmpLoad);

				// Create 24x24 icon in 24 bit form
				iBmp_createBySize(bmp, bmpLoad.bi.biWidth, bmpLoad.bi.biHeight, 24);

				// Copy it over
				SetRect(&lrc, 0, 0, bmpLoad.bi.biWidth, bmpLoad.bi.biHeight);
				memcpy(bmp->bd, bmpLoad.bd, bmp->bi.biSizeImage);

				// Convert to 24-bit if need be
				if (bmp->bi.biBitCount == 32)
					iBmp_convertTo24Bits(bmp);
			}

		//////////
		// Indicate our success or failure
		//////
			return(bmp);
	}




//////////
//
// Called to save the indicated bitmap to a disk file.
//
//////
	void iBmp_saveToDisk(SBitmap* bmp, s8* tcPathname)
	{
		FILE* lfh;


		if (bmp)
		{
		//////////
		// Simple disk write
		//////
			lfh = fopen(tcPathname, "wb+");
			if (lfh)
			{
				// Write file header, info header, bitmap bits
				bmp->bh.bfType		= 'MB';
				bmp->bh.bfReserved1	= 0;
				bmp->bh.bfReserved2	= 0;
				bmp->bh.bfOffBits	= sizeof(bmp->bh) + sizeof(bmp->bi);
				bmp->bh.bfSize		= bmp->bh.bfOffBits + bmp->bi.biSizeImage;

				fwrite(&bmp->bh, 1, sizeof(bmp->bh), lfh);
				fwrite(&bmp->bi, 1, sizeof(bmp->bi), lfh);
				fwrite(bmp->bd, 1, bmp->bi.biSizeImage, lfh);

				// Close
				fclose(lfh);
			}
		}
	}




//////////
//
// Called to convert the indicated bitmap to 32-bits if need be
//
//////
	void iBmp_convertTo32Bits(SBitmap* bmp)
	{
		SBitmap bmp32;


		// Are we already there?
		if (bmp && bmp->bi.biBitCount != 32)
		{
			// No, but we only know how to handle 24-bit bitmaps
			if (bmp->bi.biBitCount == 24)
			{
				// We need to convert it
				// Create the 32-bit version
				memset(&bmp32, 0, sizeof(SBitmap));
				iBmp_createBySize(&bmp32, bmp->bi.biWidth, bmp->bi.biHeight, 32);

				// Copy it
				iBmp_copy24To32(&bmp32, bmp);

				// Free the (now old) bitmap
				iBmp_delete(&bmp, true, false);

				// Copy our bitmap to the destination
				memcpy(bmp, &bmp32, sizeof(SBitmap));
			}
		}
	}




//////////
//
// Called to convert the indicated bitmap to 32-bits if need be
//
//////
	void iBmp_convertTo24Bits(SBitmap* bmp)
	{
		SBitmap	bmp24;
		RECT	lrc;


		// Are we already there?
		if (bmp && bmp->bi.biBitCount != 24)
		{
			// No, but we only know how to handle 32-bit bitmaps
			if (bmp->bi.biBitCount == 32)
			{
				// We need to convert it
				// Create the 24-bit version
				memset(&bmp24, 0, sizeof(SBitmap));
				iBmp_createBySize(&bmp24, bmp->bi.biWidth, bmp->bi.biHeight, 24);

				// Copy it
				SetRect(&lrc, 0, 0, bmp->bi.biWidth, bmp->bi.biHeight);
				iBmp_bitBlt(&bmp24, &lrc, bmp);

				// Free the (now old) bitmap
				iBmp_delete(&bmp, true, false);

				// Copy our bitmap to the destination
				memcpy(bmp, &bmp24, sizeof(SBitmap));
			}
		}
	}




//////////
//
// Copies the 24-bit bitmap to a 32-bit bitmap.
// Note:  This function is no longer needed, but may be faster for equal sized
//        bitmaps that are known to be 24-bit and 32-bit.  The iBmp_bitBlt()
//        function now handles arbitrary 24-bit and 32-bit sources and destinations.
//
//////
	void iBmp_copy24To32(SBitmap* bmp32, SBitmap* bmp24)
	{
		s32		lnX, lnY;
		SBgr*	lbgr;
		SBgra*	lbgra;


		if (bmp32 && bmp24)
		{
			// Iterate through every row
			for (lnY = 0; lnY < bmp24->bi.biHeight; lnY++)
			{
				// Grab our pointers
				lbgr	= (SBgr*)(bmp24->bd  + ((bmp24->bi.biHeight - lnY - 1) * bmp24->rowWidth));
				lbgra	= (SBgra*)(bmp32->bd + ((bmp32->bi.biHeight - lnY - 1) * bmp32->rowWidth));

				// Iterate though every column
				for (lnX = 0; lnX < bmp24->bi.biWidth; lnX++, lbgr++, lbgra++)
				{
					// Copy the pixel
					lbgra->alp	= 255;
					lbgra->red	= lbgr->red;
					lbgra->grn	= lbgr->grn;
					lbgra->blu	= lbgr->blu;
				}
			}
		}
	}




//////////
//
// Performs basic tests on the bitmap to see if it appears to be a valid structure.
//
//////
	bool iBmp_validate(SBitmap* bmp)
	{
		// Pointer must exist
		if (!bmp)
			return(false);
		
		// Planes must be 1
		if (bmp->bi.biPlanes != 1)
			return(false);

		// Bits must be 24 or 32
		if (bmp->bi.biBitCount != 24 && bmp->bi.biBitCount != 32)
			return(false);

		// No compression (meaning default BMP file)
		if (bmp->bi.biCompression != 0)
			return(false);

		// Make sure the biSizeImage is accurate
		iBmp_computeRowWidth(bmp);
		if (bmp->rowWidth * bmp->bi.biHeight != bmp->bi.biSizeImage)
			return(false);

		// Make sure the pixels per meter are set
		if (bmp->bi.biXPelsPerMeter <= 0)			bmp->bi.biXPelsPerMeter = 2835;					// Default to 72 pixels per inch, a "twip" as it were
		if (bmp->bi.biYPelsPerMeter <= 0)			bmp->bi.biYPelsPerMeter = 2835;

		// We're good
		return(true);
	}




//////////
//
// Computes the row width of the pixels using BGR format (3 bytes per pixel) then rounded up to
// the nearest DWORD.
//
//////
	s32 iBmp_computeRowWidth(SBitmap* bmp)
	{
		s32 lnWidth;


		// Make sure our environment is sane
		if (bmp)
		{
			// See the bit counts
			if (bmp->bi.biBitCount == 24)
			{
				// 24-bit formats are rounded up to nearest DWORD
				lnWidth = bmp->bi.biWidth * 3;
				if (lnWidth % 4 == 0)
					return(lnWidth);

				// Increase the width
				lnWidth += (4 - (lnWidth % 4));
				return(lnWidth);


			} else if (bmp->bi.biBitCount == 32) {
				// 32-bit formats are also DWORD aligned, but naturally, of course. :-)
				return(bmp->bi.biWidth * 4);


			} else {
				// Uh oh, spaghetti-oh!
				return(bmp->bi.biSizeImage / bmp->bi.biHeight);
			}
		}

		// Invalid
		return(0);
	}




//////////
//
// Called to create a basic bitmap by the indicated size, and initially populate it to white
//
//////
	void iBmp_createBySize(SBitmap* bmp, u32 width, u32 height, u32 tnBitCount)
	{
		if (bmp)
		{
			// Populate the initial structure
			iBmp_populateBitmapStructure(bmp, width, height, tnBitCount);

			// Create the HDC and DIB Section
			bmp->hdc	= CreateCompatibleDC(GetDC(GetDesktopWindow()));
			bmp->hbmp	= CreateDIBSection(bmp->hdc, (BITMAPINFO*)&bmp->bi, DIB_RGB_COLORS, (void**)&bmp->bd, NULL, 0);
			SelectObject(bmp->hdc, bmp->hbmp);

			// Paint it white initially (the fast/easy way)
			memset(bmp->bd, 255, bmp->bi.biSizeImage);
		}
	}




//////////
//
// Called to create an empty 24-bit bitmap
//
//////
	void iBmp_populateBitmapStructure(SBitmap* bmp, u32 tnWidth, u32 tnHeight, u32 tnBitCount)
	{
		if (bmp)
		{
			memset(&bmp->bi, 0, sizeof(bmp->bi));
			bmp->bi.biSize				= sizeof(bmp->bi);
			bmp->bi.biWidth				= tnWidth;
			bmp->bi.biHeight			= tnHeight;
			bmp->bi.biCompression		= 0;
			bmp->bi.biPlanes			= 1;
			bmp->bi.biBitCount			= (u16)((tnBitCount == 24 || tnBitCount == 32) ? tnBitCount : 24);
			bmp->bi.biXPelsPerMeter		= 2835;	// Assume 72 dpi
			bmp->bi.biYPelsPerMeter		= 2835;
			bmp->rowWidth				= iBmp_computeRowWidth(bmp);
			bmp->bi.biSizeImage			= bmp->rowWidth * tnHeight;
		}
//////////
// Note:  The compression formats can be:
// 0	BI_RGB	none (most common)
// 4	BI_JPEG	data bits following need to be fed into a JPG decoder to access bit rows, to save back to disk a JPG encoder is required, lossy compression (always loses bitmap color data)
// 5	BI_PNG	data bits following need to be fed into a PNG decoder to access bit rows, to save back to disk a PNG encoder is required, lossless compression (always maintains original color data)
//////
	}




//////////
//
// Called to delete the indicated bitmap and optionally free all resources.
// Note:  The tlFreeBits flags allows the bitmap data to be copied to something else, with
//        the container SBitmap being deleted, but not the bits and related data within.
//
//////
	void iBmp_delete(SBitmap** bmpRoot, bool tlFreeBits, bool tlDeleteSelf)
	{
		SBitmap* bmp;


		if (bmpRoot && *bmpRoot)
		{
			// Grab the pointer
			bmp = *bmpRoot;

			// Do we need to free the internals?
			if (tlFreeBits)
			{
				// Free the internal/Windows bits
				DeleteObject((HGDIOBJ)bmp->hbmp);
				DeleteDC(bmp->hdc);
			}

			// Release the bitmap
			if (tlDeleteSelf)
			{
				free(bmp);
				*bmpRoot = NULL;
			}
		}
	}




//////////
//
// Called to invert the colors in the indicated block
//
//////
	void iBmp_invert(SBitmap* bmp, s32 tnUlX, s32 tnUlY, s32 tnLrX, s32 tnLrY)
	{
		s32		lnX, lnY;
		SBgr*	lbgr;
		SBgra*	lbgra;


		// Iterate through every row
		for (lnY = tnUlY; lnY < tnLrY && lnY < bmp->bi.biHeight; lnY++)
		{
			if (bmp->bi.biBitCount == 24)
			{
				// Grab our pointers
				lbgr = (SBgr*)(bmp->bd + ((bmp->bi.biHeight - lnY - 1) * bmp->rowWidth) + (tnUlX * 3));

				// Iterate though every column
				for (lnX = tnUlX; lnX < tnLrX && lnX < bmp->bi.biWidth; lnX++, lbgr++)
				{
					// Copy the pixel
					lbgr->red	= 255 - lbgr->red;
					lbgr->grn	= 255 - lbgr->grn;
					lbgr->blu	= 255 - lbgr->blu;
				}

			} else if (bmp->bi.biBitCount == 32) {
				// Grab our pointers
				lbgra	= (SBgra*)(bmp->bd + ((bmp->bi.biHeight - lnY - 1) * bmp->rowWidth) + (tnUlX * 4));

				// Iterate through every column
				for (lnX = tnUlX; lnX < tnLrX && lnX < bmp->bi.biWidth; lnX++, lbgra++)
				{
					// Copy the pixel
					lbgra->alp	= 255;
					lbgra->red	= 255 - lbgra->red;
					lbgra->grn	= 255 - lbgra->grn;
					lbgra->blu	= 255 - lbgra->blu;
				}
			}
		}
	}




//////////
//
// Draw the indicated object
//
//////
	void iBmp_bitBltObject(SBitmap* bmpDst, SObject* objSrc, SBitmap* bmpSrc)
	{
		iBmp_bitBlt(bmpDst, &objSrc->rc, bmpSrc);
	}




//////////
//
// Draws all except bits with the mask color rgb(222,22,222)
//
//////
	void iBmp_bitBltObjectMask(SBitmap* bmpDst, SObject* obj, SBitmap* bmpSrc)
	{
		iBmp_bitBltMask(bmpDst, &obj->rc, bmpSrc);
	}




//////////
//
// Physically render the bitmap atop the bitmap
//
//////
	u32 iBmp_bitBlt(SBitmap* bmpDst, RECT* trc, SBitmap* bmpSrc)
	{
		u32			lnPixelsRendered;
		s32			lnY, lnX, lnYDst, lnXDst;
		f64			lfAlp, lfMalp;
		SBgr*		lbgrDst;
		SBgr*		lbgrSrc;
		SBgra*		lbgraDst;
		SBgra*		lbgraSrc;


		// Use the system bitblt for speed
// 		if (bmpDst && trc && bmpSrc)
// 		{
			BitBlt(bmpDst->hdc, trc->left, trc->top, trc->right - trc->left, trc->bottom - trc->top, bmpSrc->hdc, 0, 0, SRCCOPY);
			return(bmpSrc->bi.biSizeImage);
// 
// 		} else {
// 			return(0);
// 		}


		// Make sure the environment is sane
		lnPixelsRendered = 0;
		if (bmpDst && bmpSrc && trc)
		{
		//////////
		// Draw it
		//////
			for (lnY = 0, lnYDst = trc->top; lnY < bmpSrc->bi.biHeight && lnYDst < trc->bottom; lnYDst++, lnY++)
			{
				// Are we on the image?
				if (lnYDst >= 0 && lnYDst < bmpDst->bi.biHeight)
				{
					// Build the pointer
					lbgrDst		= (SBgr*)((s8*)bmpDst->bd  + ((bmpDst->bi.biHeight - lnYDst - 1) * bmpDst->rowWidth) + (trc->left * (bmpDst->bi.biBitCount / 8)));
					lbgrSrc		= (SBgr*)((s8*)bmpSrc->bd  + ((bmpSrc->bi.biHeight - lnY    - 1) * bmpSrc->rowWidth));
					lbgraDst	= (SBgra*)((s8*)bmpDst->bd + ((bmpDst->bi.biHeight - lnYDst - 1) * bmpDst->rowWidth) + (trc->left * (bmpDst->bi.biBitCount / 8)));
					lbgraSrc	= (SBgra*)((s8*)bmpSrc->bd + ((bmpSrc->bi.biHeight - lnY    - 1) * bmpSrc->rowWidth));

					// What exactly are we copying?
					if (bmpSrc->bi.biBitCount == 24)
					{
						// 24-bit source
						if (bmpDst->bi.biBitCount == 24)
						{
							// 24-bit to 24-bit
							// Iterate through every visible column
							for (lnX = 0, lnXDst = trc->left; lnX < bmpSrc->bi.biWidth && lnXDst < trc->right; lnXDst++, lnX++)
							{
								// Are we on the image?
								if (lnXDst >= 0 && lnXDst < bmpDst->bi.biWidth)
								{
									// Copy the pixel
									lbgrDst->red	= lbgrSrc->red;
									lbgrDst->grn	= lbgrSrc->grn;
									lbgrDst->blu	= lbgrSrc->blu;
									++lnPixelsRendered;
								}

								// Move to next pixel on both
								++lbgrDst;
								++lbgrSrc;
							}

						} else {
							// 24-bit to 32-bit
							// Iterate through every visible column
							for (lnX = 0, lnXDst = trc->left; lnX < bmpSrc->bi.biWidth && lnXDst < trc->right; lnXDst++, lnX++)
							{
								// Are we on the image?
								if (lnXDst >= 0 && lnXDst < bmpDst->bi.biWidth)
								{
									// Copy the pixel
									lbgraDst->alp	= 255;
									lbgraDst->red	= lbgrSrc->red;
									lbgraDst->grn	= lbgrSrc->grn;
									lbgraDst->blu	= lbgrSrc->blu;
									++lnPixelsRendered;
								}

								// Move to next pixel on both
								++lbgraDst;
								++lbgrSrc;
							}
						}

					} else if (bmpSrc->bi.biBitCount == 32) {
						// 32-bit source
						if (bmpDst->bi.biBitCount == 24)
						{
							// 32-bit to 24-bit
							// Iterate through every visible column
							for (lnX = 0, lnXDst = trc->left; lnX < bmpSrc->bi.biWidth && lnXDst < trc->right; lnXDst++, lnX++)
							{
								// Are we on the image?
								if (lnXDst >= 0 && lnXDst < bmpDst->bi.biWidth && lbgraSrc->alp != 0)
								{
									// Copy the pixel
									if (lbgraSrc->alp == 255)
									{
										// Opaque
										lbgrDst->red	= lbgraSrc->red;
										lbgrDst->grn	= lbgraSrc->grn;
										lbgrDst->blu	= lbgraSrc->blu;

									} else {
										// Some degree of transparency
										lfAlp			= ((f64)lbgraSrc->alp / 255.0);
										lfMalp			= 1.0 - lfAlp;
										lbgrDst->red	= (u8)min(max(((f64)lbgrDst->red * lfMalp) + (lbgraSrc->red * lfAlp), 0.0), 255.0);
										lbgrDst->grn	= (u8)min(max(((f64)lbgrDst->grn * lfMalp) + (lbgraSrc->grn * lfAlp), 0.0), 255.0);
										lbgrDst->blu	= (u8)min(max(((f64)lbgrDst->blu * lfMalp) + (lbgraSrc->blu * lfAlp), 0.0), 255.0);
									}
									++lnPixelsRendered;
								}

								// Move to next pixel on both
								++lbgrDst;
								++lbgraSrc;
							}

						} else {
							// 32-bit to 32-bit
							// Iterate through every visible column
							for (lnX = 0, lnXDst = trc->left; lnX < bmpSrc->bi.biWidth && lnXDst < trc->right; lnXDst++, lnX++)
							{
								// Are we on the image?
								if (lnXDst >= 0 && lnXDst < bmpDst->bi.biWidth && lbgraSrc->alp != 0)
								{
									// Copy the pixel
									if (lbgraSrc->alp == 255)
									{
										// Opaque
										lbgraDst->alp	= 255;
										lbgraDst->red	= lbgraSrc->red;
										lbgraDst->grn	= lbgraSrc->grn;
										lbgraDst->blu	= lbgraSrc->blu;

									} else {
										// Some degree of transparency
										lfAlp			= ((f64)lbgraSrc->alp / 255.0);
										lfMalp			= 1.0 - lfAlp;
	 									lbgraDst->alp	= 255;
										lbgraDst->red	= (u8)min(max(((f64)lbgraDst->red * lfMalp) + (lbgraSrc->red * lfAlp), 0.0), 255.0);
										lbgraDst->grn	= (u8)min(max(((f64)lbgraDst->grn * lfMalp) + (lbgraSrc->grn * lfAlp), 0.0), 255.0);
										lbgraDst->blu	= (u8)min(max(((f64)lbgraDst->blu * lfMalp) + (lbgraSrc->blu * lfAlp), 0.0), 255.0);
									}
									++lnPixelsRendered;
								}

								// Move to next pixel on both
								++lbgraDst;
								++lbgraSrc;
							}
						}
					}
				}
			}
		}


		//////////
		// Indicate how many pixels were rendered
		//////
			return(lnPixelsRendered);
	}




//////////
//
// Called to grayscale a bitmap, or a portion of a bitmap
//
//////
	u32 iBmp_grayscale(SBitmap* bmp, RECT* trc)
	{
		u8		gray;
		u32		lnPixelsRendered;
		s32		lnY, lnX;
		SBgr*	lbgr;
		SBgra*	lbgra;


		lnPixelsRendered = 0;
		if (bmp && trc)
		{
		//////////
		// Draw it
		//////
			for (lnY = trc->top; lnY < bmp->bi.biHeight && lnY < trc->bottom; lnY++)
			{
				// Are we on the image?
				if (lnY >= 0)
				{
					// What exactly are we copying?
					if (bmp->bi.biBitCount == 24)
					{
						// Build the pointer
						lbgr = (SBgr*)((s8*)bmp->bd + ((bmp->bi.biHeight - lnY - 1) * bmp->rowWidth));

						// Iterate through every visible column
						for (lnX = trc->left; lnX < bmp->bi.biWidth && lnX < trc->right; lnX++)
						{
							// Are we on the image?
							if (lnX >= 0)
							{
								// Compute the grayscale
								gray = (u8)min(max(((f32)lbgr->red * 0.35f + (f32)lbgr->grn * 0.54f + (f32)lbgr->blu * 0.11f), 0.0f), 255.0f);

								// Copy the pixel
								lbgr->red	= gray;
								lbgr->grn	= gray;
								lbgr->blu	= gray;
								++lnPixelsRendered;
							}

							// Move to next pixel
							++lbgr;
						}

					} else if (bmp->bi.biBitCount == 32) {
						// Build the pointer
						lbgra = (SBgra*)((s8*)bmp->bd + ((bmp->bi.biHeight - lnY - 1) * bmp->rowWidth));

						// Iterate through every visible column
						for (lnX = trc->left; lnX < bmp->bi.biWidth && lnX < trc->right; lnX++)
						{
							// Are we on the image?
							if (lnX >= 0)
							{
								// Compute the grayscale
								gray = (u8)min(max(((f32)lbgra->red * 0.35f + (f32)lbgra->grn * 0.54f + (f32)lbgra->blu * 0.11f), 0.0f), 255.0f);

								// Copy the pixel
								lbgra->red	= gray;
								lbgra->grn	= gray;
								lbgra->blu	= gray;
								++lnPixelsRendered;
							}

							// Move to next pixel
							++lbgra;
						}
					}
				}
			}
		}


		//////////
		// Indicate how many pixels were rendered
		//////
			return(lnPixelsRendered);
	}




//////////
//
// Called to colorize the bitmap, or a portion of the bitmap.  If the color is clamped,
// no scaling from its current RGB() values less than 255 up to 255 takes place, but the
// color is used exactly as it is, meaning the pixel is grayscaled, and then that grayscale
// value is applied to each value of the RGB() component.
//
//////
	u32 iBmp_colorizeMask(SBitmap* bmp, RECT* trc, SBgra colorTemplate, bool clampColor, f32 minColor)
	{
		u32		lnPixelsRendered;
		s32		lnY, lnX;
		f32		lfGray, lfRed, lfGrn, lfBlu, lfDelta;
		SBgr*	lbgr;
		SBgra*	lbgra;


		// Make sure the environment is sane
		lnPixelsRendered = 0;
		if (bmp && trc)
		{
		//////////
		// Build the actual color
		//////
			lfRed = (f32)colorTemplate.red;
			lfGrn = (f32)colorTemplate.grn;
			lfBlu = (f32)colorTemplate.blu;
			if (!clampColor)
			{
				// Compute with the colors being adjusted up toward 255 if any are below
				lfDelta = 0.0f;
				lfDelta = max(lfDelta, lfRed);
				lfDelta = max(lfDelta, lfGrn);
				lfDelta = max(lfDelta, lfBlu);

				// Raise each of them by the difference if need be
				if (lfDelta != 255.0f)
				{
					// Compute our overage percentage
					lfDelta = 1.0f + ((255.0f - lfDelta) / 255.0f);

					// Multiply each other
					lfRed = min(lfRed * lfDelta, 255.0f);
					lfGrn = min(lfGrn * lfDelta, 255.0f);
					lfBlu = min(lfBlu * lfDelta, 255.0f);
				}
			}


		//////////
		// Verify our minColor is in range 0..1
		// If 1.0, then allows 0..255
		// If 0.5, then allows 128..255
		// If 0.0, then allows 0 or 255
		//////
			minColor = min(max(minColor, 0.0f), 1.0f);


		//////////
		// Draw it
		//////
			for (lnY = trc->top; lnY < bmp->bi.biHeight && lnY < trc->bottom; lnY++)
			{
				// Are we on the image?
				if (lnY >= 0)
				{
					// What exactly are we copying?
					if (bmp->bi.biBitCount == 24)
					{
						// Build the pointer
						lbgr = (SBgr*)((s8*)bmp->bd + ((bmp->bi.biHeight - lnY - 1) * bmp->rowWidth) + (trc->left * 3));

						// Iterate through every visible column
						for (lnX = trc->left; lnX < bmp->bi.biWidth && lnX < trc->right; lnX++)
						{
							// Are we on the image?
							if (lnX >= 0)
							{
								if (lbgr->red == 222 && lbgr->grn == 22 && lbgr->blu == 222)
								{
									// Every transparent color gets the colorized color
									lbgr->red = (u8)lfRed;
									lbgr->grn = (u8)lfGrn;
									lbgr->blu = (u8)lfBlu;

								} else {
									// Compute the grayscale
									lfGray = min(max(((f32)lbgr->red * 0.35f + (f32)lbgr->grn * 0.54f + (f32)lbgr->blu * 0.11f), 0.0f), 255.0f) / 255.0f;

									// Apply the color proportionally
									lbgr->red = (u8)iiBmp_squeezeColorChannel(lfGray * lfRed, minColor);
									lbgr->grn = (u8)iiBmp_squeezeColorChannel(lfGray * lfGrn, minColor);
									lbgr->blu = (u8)iiBmp_squeezeColorChannel(lfGray * lfBlu, minColor);
								}
								++lnPixelsRendered;
							}

							// Move to next pixel
							++lbgr;
						}

					} else if (bmp->bi.biBitCount == 32) {
						// Build the pointer
						lbgra = (SBgra*)((s8*)bmp->bd + ((bmp->bi.biHeight - lnY - 1) * bmp->rowWidth) + (trc->left * 4));

						// Iterate through every visible column
						for (lnX = trc->left; lnX < bmp->bi.biWidth && lnX < trc->right; lnX++)
						{
							// Are we on the image?
							if (lnX >= 0)
							{
								if (lbgra->red == 222 && lbgra->grn == 22 && lbgra->blu == 222)
								{
									// Every transparent color gets the colorized color
									lbgra->red = (u8)lfRed;
									lbgra->grn = (u8)lfGrn;
									lbgra->blu = (u8)lfBlu;

								} else {
									// Compute the grayscale
									lfGray = min(max(((f32)lbgra->red * 0.35f + (f32)lbgra->grn * 0.54f + (f32)lbgra->blu * 0.11f), 0.0f), 255.0f) / 255.0f;

									// Apply the color proportionally
									lbgra->red = (u8)iiBmp_squeezeColorChannel(lfGray * lfRed, minColor);
									lbgra->grn = (u8)iiBmp_squeezeColorChannel(lfGray * lfGrn, minColor);
									lbgra->blu = (u8)iiBmp_squeezeColorChannel(lfGray * lfBlu, minColor);
								}
								++lnPixelsRendered;
							}

							// Move to next pixel
							++lbgra;
						}
					}
				}
			}
		}


		//////////
		// Indicate how many pixels were rendered
		//////
			return(lnPixelsRendered);
	}




//////////
//
// Called to apply an alpha
//
//////
	u32 iBmp_alphaColorizeMask(SBitmap* bmp, RECT* trc, SBgra colorAlpha, f32 alpha)
	{
		u32		lnPixelsRendered;
		s32		lnY, lnX;
		f32		lfAlp, lfMalp, lfRed, lfGrn, lfBlu;
		SBgr*	lbgr;
		SBgra*	lbgra;


		// Make sure the environment is sane
		lnPixelsRendered = 0;
		if (bmp && trc)
		{
			// Verify our alpha is in range 0..1
			lfAlp	= min(max(alpha, 0.0f), 1.0f);
			lfMalp	= 1.0f - lfAlp;

			// Grab the color
			lfRed = (f32)colorAlpha.red * lfAlp;
			lfGrn = (f32)colorAlpha.grn * lfAlp;
			lfBlu = (f32)colorAlpha.blu * lfAlp;

			//////////
			// Draw it
			//////
				for (lnY = trc->top; lnY < bmp->bi.biHeight && lnY < trc->bottom; lnY++)
				{
					// Are we on the image?
					if (lnY >= 0)
					{
						// What exactly are we copying?
						if (bmp->bi.biBitCount == 24)
						{
							// Build the pointer
							lbgr = (SBgr*)((s8*)bmp->bd + ((bmp->bi.biHeight - lnY - 1) * bmp->rowWidth));

							// Iterate through every visible column
							for (lnX = trc->left; lnX < bmp->bi.biWidth && lnX < trc->right; lnX++)
							{
								// Are we on the image?
								if (lnX >= 0)
								{
									if (!(lbgr->red == 222 && lbgr->grn == 22 && lbgr->blu == 222))
									{
										// Apply the color proportionally
										lbgr->red = (u8)(((f32)lbgr->red * lfMalp) + lfRed);
										lbgr->grn = (u8)(((f32)lbgr->grn * lfMalp) + lfGrn);
										lbgr->blu = (u8)(((f32)lbgr->blu * lfMalp) + lfBlu);
										++lnPixelsRendered;
									}
								}

								// Move to next pixel
								++lbgr;
							}

						} else if (bmp->bi.biBitCount == 32) {
							// Build the pointer
							lbgra = (SBgra*)((s8*)bmp->bd + ((bmp->bi.biHeight - lnY - 1) * bmp->rowWidth));

							// Iterate through every visible column
							for (lnX = trc->left; lnX < bmp->bi.biWidth && lnX < trc->right; lnX++)
							{
								// Are we on the image?
								if (lnX >= 0)
								{
									if (!(lbgra->red == 222 && lbgra->grn == 22 && lbgra->blu == 222))
									{
										// Apply the color proportionally
										lbgra->red = (u8)(((f32)lbgra->red * lfMalp) + lfRed);
										lbgra->grn = (u8)(((f32)lbgra->grn * lfMalp) + lfGrn);
										lbgra->blu = (u8)(((f32)lbgra->blu * lfMalp) + lfBlu);
										++lnPixelsRendered;
									}
								}

								// Move to next pixel
								++lbgra;
							}
						}
					}
				}
		}


		//////////
		// Indicate how many pixels were rendered
		//////
			return(lnPixelsRendered);
	}




//////////
//
// Physically render the bitmap atop the bitmap, with without the mask bits rgb(222,22,222)
//
//////
	u32 iBmp_bitBltMask(SBitmap* bmpDst, RECT* trc, SBitmap* bmpSrc)
	{
		u32			lnPixelsRendered;
		s32			lnY, lnX, lnYDst, lnXDst;
		f64			lfAlp, lfMalp;
		SBgr*		lbgrDst;
		SBgr*		lbgrSrc;
		SBgra*		lbgraDst;
		SBgra*		lbgraSrc;


// 		// Use the system bitblt for speed
// 		BitBlt(bmpDst->hdc, trc->left, trc->top, trc->right - trc->left, trc->bottom - trc->top, bmpSrc->hdc, 0, 0, SRCCOPY);
// 		return(bmpSrc->bi.biSizeImage);


		lnPixelsRendered = 0;
		if (bmpDst && trc && bmpSrc)
		{
		//////////
		// Draw it
		//////
			for (lnY = 0, lnYDst = trc->top; lnY < bmpSrc->bi.biHeight && lnYDst < trc->bottom; lnYDst++, lnY++)
			{
				// Are we on the image?
				if (lnYDst >= 0 && lnYDst < bmpDst->bi.biHeight)
				{
					// Build the pointer
					lbgrDst		= (SBgr*)((s8*)bmpDst->bd  + ((bmpDst->bi.biHeight - lnYDst - 1) * bmpDst->rowWidth) + (trc->left * (bmpDst->bi.biBitCount / 8)));
					lbgrSrc		= (SBgr*)((s8*)bmpSrc->bd  + ((bmpSrc->bi.biHeight - lnY    - 1) * bmpSrc->rowWidth));
					lbgraDst	= (SBgra*)((s8*)bmpDst->bd + ((bmpDst->bi.biHeight - lnYDst - 1) * bmpDst->rowWidth) + (trc->left * (bmpDst->bi.biBitCount / 8)));
					lbgraSrc	= (SBgra*)((s8*)bmpSrc->bd + ((bmpSrc->bi.biHeight - lnY    - 1) * bmpSrc->rowWidth));

					// What exactly are we copying?
					if (bmpSrc->bi.biBitCount == 24)
					{
						// 24-bit source
						if (bmpDst->bi.biBitCount == 24)
						{
							// 24-bit to 24-bit
							// Iterate through every visible column
							for (lnX = 0, lnXDst = trc->left; lnX < bmpSrc->bi.biWidth && lnXDst < trc->right; lnXDst++, lnX++)
							{
								// Are we on the image?
								if (lnXDst >= 0 && lnXDst < bmpDst->bi.biWidth)
								{
									// Copy the pixel if it's not a mask pixel
									if (!(lbgrSrc->red == 222 && lbgrSrc->grn == 22 && lbgrSrc->blu == 222))
									{
										lbgrDst->red	= lbgrSrc->red;
										lbgrDst->grn	= lbgrSrc->grn;
										lbgrDst->blu	= lbgrSrc->blu;
										++lnPixelsRendered;
									}
								}

								// Move to next pixel on both
								++lbgrDst;
								++lbgrSrc;
							}

						} else {
							// 24-bit to 32-bit
							// Iterate through every visible column
							for (lnX = 0, lnXDst = trc->left; lnX < bmpSrc->bi.biWidth && lnXDst < trc->right; lnXDst++, lnX++)
							{
								// Are we on the image?
								if (lnXDst >= 0 && lnXDst < bmpDst->bi.biWidth)
								{
									// Copy the pixel if it's not a mask pixel
									if (!(lbgrSrc->red == 222 && lbgrSrc->grn == 22 && lbgrSrc->blu == 222))
									{
										lbgraDst->alp	= 255;
										lbgraDst->red	= lbgrSrc->red;
										lbgraDst->grn	= lbgrSrc->grn;
										lbgraDst->blu	= lbgrSrc->blu;
										++lnPixelsRendered;
									}
								}

								// Move to next pixel on both
								++lbgraDst;
								++lbgrSrc;
							}
						}

					} else {
						// 32-bit source
						if (bmpDst->bi.biBitCount == 24)
						{
							// 32-bit to 24-bit
							// Iterate through every visible column
							for (lnX = 0, lnXDst = trc->left; lnX < bmpSrc->bi.biWidth && lnXDst < trc->right; lnXDst++, lnX++)
							{
								// Are we on the image?
								if (lnXDst >= 0 && lnXDst < bmpDst->bi.biWidth && lbgraSrc->alp != 0)
								{
									// Copy the pixel if it's not a mask pixel
									if (!(lbgraSrc->red == 222 && lbgraSrc->grn == 22 && lbgraSrc->blu == 222))
									{
										if (lbgraSrc->alp == 255)
										{
											// Opaque
											lbgrDst->red	= lbgraSrc->red;
											lbgrDst->grn	= lbgraSrc->grn;
											lbgrDst->blu	= lbgraSrc->blu;

										} else {
											// Some degree of transparency
											lfAlp			= ((f64)lbgraSrc->alp / 255.0);
											lfMalp			= 1.0 - lfAlp;
											lbgrDst->red	= (u8)min(max(((f64)lbgrDst->red * lfMalp) + (lbgraSrc->red * lfAlp), 0.0), 255.0);
											lbgrDst->grn	= (u8)min(max(((f64)lbgrDst->grn * lfMalp) + (lbgraSrc->grn * lfAlp), 0.0), 255.0);
											lbgrDst->blu	= (u8)min(max(((f64)lbgrDst->blu * lfMalp) + (lbgraSrc->blu * lfAlp), 0.0), 255.0);
										}
										++lnPixelsRendered;
									}
								}

								// Move to next pixel on both
								++lbgrDst;
								++lbgraSrc;
							}

						} else {
							// 32-bit to 32-bit
							// Iterate through every visible column
							for (lnX = 0, lnXDst = trc->left; lnX < bmpSrc->bi.biWidth && lnXDst < trc->right; lnXDst++, lnX++)
							{
								// Are we on the image?
								if (lnXDst >= 0 && lnXDst < bmpDst->bi.biWidth && lbgraSrc->alp != 0)
								{
									// Copy the pixel if it's not a mask pixel
									if (!(lbgraSrc->red == 222 && lbgraSrc->grn == 22 && lbgraSrc->blu == 222))
									{
										if (lbgraSrc->alp == 255)
										{
											// Opaque
											lbgraDst->alp	= 255;
											lbgraDst->red	= lbgraSrc->red;
											lbgraDst->grn	= lbgraSrc->grn;
											lbgraDst->blu	= lbgraSrc->blu;

										} else {
											// Some degree of transparency
											lfAlp			= ((f64)lbgraSrc->alp / 255.0);
											lfMalp			= 1.0 - lfAlp;
											lbgraDst->alp	= 255;
											lbgraDst->red	= (u8)min(max(((f64)lbgraDst->red * lfMalp) + (lbgraSrc->red * lfAlp), 0.0), 255.0);
											lbgraDst->grn	= (u8)min(max(((f64)lbgraDst->grn * lfMalp) + (lbgraSrc->grn * lfAlp), 0.0), 255.0);
											lbgraDst->blu	= (u8)min(max(((f64)lbgraDst->blu * lfMalp) + (lbgraSrc->blu * lfAlp), 0.0), 255.0);
										}
										++lnPixelsRendered;
									}
								}

								// Move to next pixel on both
								++lbgraDst;
								++lbgraSrc;
							}
						}
					}
				}
			}
		}
		// Indicate how many pixels were drawn
		return(lnPixelsRendered);
	}




//////////
//
// Called to render the indicated image by its grayscale value (not computed, but assumed
// as only red is sampled), with the indicated color applied onto the bmpDst bitmap.
//
//////
	u32 iBmp_bitBlt_byGraymask(SBitmap* bmpDst, RECT* trc, SBitmap* bmpSrc, SBgra color)
	{
		u32			lnPixelsRendered;
		s32			lnY, lnX, lnYDst, lnXDst;
		f64			lfAlp, lfMalp, lfRed, lfGrn, lfBlu;
		SBgr*		lbgrDst;
		SBgr*		lbgrSrc;
		SBgra*		lbgraDst;
		SBgra*		lbgraSrc;


		lnPixelsRendered = 0;
		if (bmpDst && trc && bmpSrc)
		{
		//////////
		// Draw it
		//////
			lfRed = (f64)color.red;
			lfGrn = (f64)color.grn;
			lfBlu = (f64)color.blu;
			for (lnY = 0, lnYDst = trc->top; lnY < bmpSrc->bi.biHeight && lnYDst < trc->bottom; lnYDst++, lnY++)
			{
				// Are we on the image?
				if (lnYDst >= 0 && lnYDst < bmpDst->bi.biHeight)
				{
					// Build the pointer
					lbgrDst		= (SBgr*)((s8*)bmpDst->bd  + ((bmpDst->bi.biHeight - lnYDst - 1) * bmpDst->rowWidth) + (trc->left * (bmpDst->bi.biBitCount / 8)));
					lbgrSrc		= (SBgr*)((s8*)bmpSrc->bd  + ((bmpSrc->bi.biHeight - lnY    - 1) * bmpSrc->rowWidth));
					lbgraDst	= (SBgra*)((s8*)bmpDst->bd + ((bmpDst->bi.biHeight - lnYDst - 1) * bmpDst->rowWidth) + (trc->left * (bmpDst->bi.biBitCount / 8)));
					lbgraSrc	= (SBgra*)((s8*)bmpSrc->bd + ((bmpSrc->bi.biHeight - lnY    - 1) * bmpSrc->rowWidth));

					// What exactly are we copying?
					if (bmpSrc->bi.biBitCount == 24)
					{
						// 24-bit source
						if (bmpDst->bi.biBitCount == 24)
						{
							// 24-bit to 24-bit
							// Iterate through every visible column
							for (lnX = 0, lnXDst = trc->left; lnX < bmpSrc->bi.biWidth && lnXDst < trc->right; lnXDst++, lnX++)
							{
								// Are we on the image?
								if (lnXDst >= 0 && lnXDst < bmpDst->bi.biWidth)
								{
									// Copy the pixel if it's not a mask pixel
									if (!(lbgrSrc->red == 255 && lbgrSrc->grn == 255 && lbgrSrc->blu == 255))
									{
										lfAlp			= (f64)(255 - lbgrSrc->red) / 255.0;
										lfMalp			= 1.0 - lfAlp;
										lbgrDst->red	= (u8)(((f64)lbgrDst->red * lfMalp) + (lfRed * lfAlp));
										lbgrDst->grn	= (u8)(((f64)lbgrDst->grn * lfMalp) + (lfGrn * lfAlp));
										lbgrDst->blu	= (u8)(((f64)lbgrDst->blu * lfMalp) + (lfBlu * lfAlp));
										++lnPixelsRendered;
									}
								}

								// Move to next pixel on both
								++lbgrDst;
								++lbgrSrc;
							}

						} else {
							// 24-bit to 32-bit
							// Iterate through every visible column
							for (lnX = 0, lnXDst = trc->left; lnX < bmpSrc->bi.biWidth && lnXDst < trc->right; lnXDst++, lnX++)
							{
								// Are we on the image?
								if (lnXDst >= 0 && lnXDst < bmpDst->bi.biWidth)
								{
									// Copy the pixel if it's not a mask pixel
									if (!(lbgrSrc->red == 255 && lbgrSrc->grn == 255 && lbgrSrc->blu == 255))
									{
										lfAlp			= (f64)(255 - lbgrSrc->red) / 255.0;
										lfMalp			= 1.0 - lfAlp;
										lbgraDst->alp	= 255;
										lbgraDst->red	= (u8)(((f64)lbgraDst->red * lfMalp) + (lfRed * lfAlp));
										lbgraDst->grn	= (u8)(((f64)lbgraDst->grn * lfMalp) + (lfGrn * lfAlp));
										lbgraDst->blu	= (u8)(((f64)lbgraDst->blu * lfMalp) + (lfBlu * lfAlp));
										++lnPixelsRendered;
									}
								}

								// Move to next pixel on both
								++lbgraDst;
								++lbgrSrc;
							}
						}

					} else {
						// 32-bit source
						if (bmpDst->bi.biBitCount == 24)
						{
							// 32-bit to 24-bit
							// Iterate through every visible column
							for (lnX = 0, lnXDst = trc->left; lnX < bmpSrc->bi.biWidth && lnXDst < trc->right; lnXDst++, lnX++)
							{
								// Are we on the image?
								if (lnXDst >= 0 && lnXDst < bmpDst->bi.biWidth && lbgraSrc->alp != 0)
								{
									// Copy the pixel if it's not a mask pixel
									if (!(lbgraSrc->red == 255 && lbgraSrc->grn == 255 && lbgraSrc->blu == 255))
									{
										lfAlp			= (f64)(255 - lbgraSrc->red) / 255.0;
										lfMalp			= 1.0 - lfAlp;
										lbgrDst->red	= (u8)(((f64)lbgrDst->red * lfMalp) + (lfRed * lfAlp));
										lbgrDst->grn	= (u8)(((f64)lbgrDst->grn * lfMalp) + (lfGrn * lfAlp));
										lbgrDst->blu	= (u8)(((f64)lbgrDst->blu * lfMalp) + (lfBlu * lfAlp));
										++lnPixelsRendered;
									}
								}

								// Move to next pixel on both
								++lbgrDst;
								++lbgraSrc;
							}

						} else {
							// 32-bit to 32-bit
							// Iterate through every visible column
							for (lnX = 0, lnXDst = trc->left; lnX < bmpSrc->bi.biWidth && lnXDst < trc->right; lnXDst++, lnX++)
							{
								// Are we on the image?
								if (lnXDst >= 0 && lnXDst < bmpDst->bi.biWidth && lbgraSrc->alp != 0)
								{
									// Copy the pixel if it's not a mask pixel
									if (!(lbgraSrc->red == 255 && lbgraSrc->grn == 255 && lbgraSrc->blu == 255))
									{
										lfAlp			= (f64)(255 - lbgraSrc->red) / 255.0;
										lfMalp			= 1.0 - lfAlp;
										lbgraDst->alp	= 255;
										lbgraDst->red	= (u8)(((f64)lbgraDst->red * lfMalp) + (lfRed * lfAlp));
										lbgraDst->grn	= (u8)(((f64)lbgraDst->grn * lfMalp) + (lfGrn * lfAlp));
										lbgraDst->blu	= (u8)(((f64)lbgraDst->blu * lfMalp) + (lfBlu * lfAlp));
										++lnPixelsRendered;
									}
								}

								// Move to next pixel on both
								++lbgraDst;
								++lbgraSrc;
							}
						}
					}
				}
			}
		}
		// Indicate how many pixels were drawn
		return(lnPixelsRendered);
	}




//////////
//
// Called to extract the indicated rectangle from the source bitmap.
//
//////
	u32 iBmp_extractRect(SBitmap* bmpDst, RECT* trc, SBitmap* bmpSrc, s32 tnX, s32 tnY)
	{
		s32 lnWidth, lnHeight;


		lnWidth		= trc->right - trc->left;
		lnHeight	= trc->bottom - trc->top;

		StretchBlt(bmpDst->hdc, trc->left, trc->top, lnWidth, lnHeight, bmpSrc->hdc, tnX, tnY, lnWidth, lnHeight, SRCCOPY);
// iBmp_saveToDisk(bmpDst, "c:\\temp\\publish\\extract.bmp");
		return(lnWidth * lnHeight * (bmpDst->bi.biBitCount / 8));
	}




//////////
//
// Called to derive the arbitrary region using the RGB(222,22,222) color as the mask.
// This means all RGB(222,22,222) pixels will be in the region.  To get the opposite
// condition use it and the RGN_XOR operator to derive the opposite.
//
//////
	HRGN iBmp_extractRgnByMask(SBitmap* bmp, RECT* trc)
	{
		s32		lnY, lnX;
		HRGN	lrgnAccumulated, lrgnRemoveArea;
		RECT	lrc;
		SBgr*	lbgr;
		SBgra*	lbgra;


		// Create a region encompassing the entire bitmap
		lrgnAccumulated = CreateRectRgnIndirect(trc);

		// Make sure our environment is sane
		if (bmp)
		{
			// Based on its, process it
			if (bmp->bi.biBitCount == 24)
			{
				// Iterate for every row
				for (lnY = trc->top; lnY < bmp->bi.biHeight && lnY <= trc->bottom; lnY++)
				{
					// Grab the pointer to this row
					lbgr = (SBgr*)(bmp->bd + ((bmp->bi.biHeight - lnY - 1) * bmp->rowWidth) + (trc->left * 3));

					// Iterate for every column, combining where we should
					for (lnX = trc->left; lnX < bmp->bi.biWidth && lnX < trc->right; lnX++, lbgr++)
					{
						// If this is one, remove this part
						if (lbgr->red == 222 && lbgr->grn == 22 && lbgr->blu == 222)
						{
							SetRect(&lrc, lnX, lnY, lnX + 1, lnY + 1);
							lrgnRemoveArea = CreateRectRgnIndirect(&lrc);
							CombineRgn(lrgnAccumulated, lrgnAccumulated, lrgnRemoveArea, RGN_XOR);		// Mask out lrgnRemove from lrgnMain
							DeleteObject((HGDIOBJ)lrgnRemoveArea);
						}
					}
				}

			} else if (bmp->bi.biBitCount == 32) {
				// Iterate for every row
				for (lnY = trc->top; lnY < bmp->bi.biHeight; lnY++)
				{
					// Grab the pointer to this row
					lbgra = (SBgra*)(bmp->bd + ((bmp->bi.biHeight - lnY - 1) * bmp->rowWidth) + (trc->left * 4));

					// Iterate for every column, combining where we should
					for (lnX = trc->left; lnX < bmp->bi.biWidth && lnX <= trc->right; lnX++, lbgra++)
					{
						// If this is one, remove this part
						if (lbgra->red == 222 && lbgra->grn == 22 && lbgra->blu == 222)
						{
							SetRect(&lrc, lnX, lnY, lnX + 1, lnY + 1);
							lrgnRemoveArea = CreateRectRgnIndirect(&lrc);
							CombineRgn(lrgnAccumulated, lrgnAccumulated, lrgnRemoveArea, RGN_XOR);		// Mask out lrgnRemove from lrgnMain
							DeleteObject((HGDIOBJ)lrgnRemoveArea);
						}
					}
				}
			}
		}

		// Return the region
		return(lrgnAccumulated);
	}




//////////
//
// Extracts the color at the indicated point
//
//////
	SBgra iBmp_extractColorAtPoint(SBitmap* bmp, s32 tnX, s32 tnY)
	{
		SBgr*	lbgr;
		SBgra*	lbgra;
		SBgra	color;


		// Make sure our environment is sane
		if (bmp && tnX >= 0 && tnX < bmp->bi.biWidth && tnY >= 0 && tnY < bmp->bi.biHeight)
		{
			// Based on its, process it
			if (bmp->bi.biBitCount == 24)
			{
				// Grab the pointer to this pixel
				lbgr = (SBgr*)(bmp->bd + ((bmp->bi.biHeight - tnY - 1) * bmp->rowWidth) + tnX * 3);

				// Construct the color
				color.alp = 255;
				color.red = lbgr->red;
				color.grn = lbgr->grn;
				color.blu = lbgr->blu;

				// Return the color
				return(color);

			} else if (bmp->bi.biBitCount == 32) {
				// Grab the pointer to this pixel
				lbgra = (SBgra*)(bmp->bd + ((bmp->bi.biHeight - tnY - 1) * bmp->rowWidth) + (tnX * 4));

				// Return directly
				return(*lbgra);
			}
		}

		// If we get here, invalid
		return(black);
	}




//////////
//
// Called to combine the two colors with the ratio of:
//		(color1 * tfAlp) + (color2 * (1.0 - tfAlp)).
//
//////
	SBgra iBmp_colorCombine(SBgra color1, SBgra color2, f32 tfAlp)
	{
		SBgra	color;
		f32		lfMalp;


		// Initialize
		tfAlp	= min(max(tfAlp, 0.0f), 1.0f);
		lfMalp	= 1.0f - tfAlp;

		// Combine
		color.red	= (u8)min(max(((f32)color1.red * tfAlp) + ((f32)color2.red * lfMalp), 0.0f), 255.0f);
		color.grn	= (u8)min(max(((f32)color1.grn * tfAlp) + ((f32)color2.grn * lfMalp), 0.0f), 255.0f);
		color.blu	= (u8)min(max(((f32)color1.blu * tfAlp) + ((f32)color2.blu * lfMalp), 0.0f), 255.0f);

		// Return our value
		return(color);
	}




//////////
//
// Called to locate a marker and return its position, and optionally update the source
// to cover up the marker by mixing the pixels to either side away.  A marker is a tiny
// upper-left coordinate marker which is a pixel, the same pixel to its right, and the
// same pixel on the next row beneath the left-most pixel, all in the indicated red, grn,
// and blu color.
//
//////
	bool iBmp_locateMarker(SBitmap* bmp, u8 red, u8 grn, u8 blu, u32* tnX, u32* tnY, bool tlOverwriteMarker)
	{
		s32		lnY, lnX;
		SBgr*	lbgr;
		SBgr*	lbgrRight;
		SBgr*	lbgrBelow;
		SBgra*	lbgra;
		SBgra*	lbgraRight;
		SBgra*	lbgraBelow;


		// Make sure our environment is sane
		if (bmp)
		{
			// Based on its, process it
			if (bmp->bi.biBitCount == 24)
			{
				// Iterate for every row
				for (lnY = 0; lnY < bmp->bi.biHeight; lnY++)
				{
					// Grab the pointer to this row
					lbgr = (SBgr*)(bmp->bd + ((bmp->bi.biHeight - lnY - 1) * bmp->rowWidth));

					// Iterate for every column, combining where we should
					for (lnX = 0; lnX < bmp->bi.biWidth; lnX++, lbgr++)
					{
						// If this is one, remove this part
						if (lbgr->red == red && lbgr->grn == grn && lbgr->blu == blu)
						{
							// Grab our right pixel, and the one below it
							lbgrRight	= lbgr + 1;
							lbgrBelow	= (SBgr*)((s8*)lbgr - bmp->rowWidth);

							// Do the pixels match?
							if (lbgrRight->red == red && lbgrRight->grn == grn && lbgrRight->blu == blu)
							{
								// Right matches
								if (lbgrBelow->red == red && lbgrBelow->grn == grn && lbgrBelow->blu == blu)
								{
									// And below matches, this is our marker
									// They match, this is our marker
									if (tlOverwriteMarker)
									{
										// Overlay it
										if (lnX >= 1)
										{
											// Grab the pixel to the left of both the lbgr and lbgrBelow
											// Upper-left
											lbgr->red		= (lbgr-1)->red;
											lbgr->grn		= (lbgr-1)->grn;
											lbgr->blu		= (lbgr-1)->blu;

											// Below
											lbgrBelow->red = (lbgrBelow - 1)->red;
											lbgrBelow->grn = (lbgrBelow - 1)->grn;
											lbgrBelow->blu = (lbgrBelow - 1)->blu;

											if (lnX < bmp->bi.biHeight - 1)
											{
												// Grab the pixel to the right of lbgrRight and copy it
												lbgrRight->red	= (lbgrRight + 1)->red;
												lbgrRight->grn	= (lbgrRight + 1)->grn;
												lbgrRight->blu	= (lbgrRight + 1)->blu;

											} else {
												// Duplicate lbgr into lbgrRight
												lbgrRight->red	= lbgr->red;
												lbgrRight->grn	= lbgr->grn;
												lbgrRight->blu	= lbgr->blu;
											}

										} else {
											// Grab the pixel to the right of lbgrRight and copy to all three
											if (lnX < bmp->bi.biHeight - 1)
											{
												// Pixel to the right
												lbgrRight->red	= (lbgrRight + 1)->red;
												lbgrRight->grn	= (lbgrRight + 1)->grn;
												lbgrRight->blu	= (lbgrRight + 1)->blu;

												// Upper left pixel
												lbgr->red		= lbgrRight->red;
												lbgr->grn		= lbgrRight->grn;
												lbgr->blu		= lbgrRight->blu;

												// Pixel on the row below
												lbgrBelow->red	= lbgrRight->red;
												lbgrBelow->grn	= lbgrRight->grn;
												lbgrBelow->blu	= lbgrRight->blu;

											} else {
												// We can't update it.  The image is too narrow
												// We don't do anything.  I just note this condition here in the comments.
											}
										}
									}

									// Set our values
									if (tnX)	*tnX = lnX;
									if (tnY)	*tnY = lnY;

									// Indicate success
									return(true);
								}
							}
						}
					}
				}

			} else if (bmp->bi.biBitCount == 32) {
				// Iterate for every row
				for (lnY = 0; lnY < bmp->bi.biHeight; lnY++)
				{
					// Grab the pointer to this row
					lbgra = (SBgra*)(bmp->bd + ((bmp->bi.biHeight - lnY - 1) * bmp->rowWidth));

					// Iterate for every column, combining where we should
					for (lnX = 0; lnX < bmp->bi.biWidth; lnX++, lbgra++)
					{
						// If this is one, remove this part
						if (lbgra->red == red && lbgra->grn == grn && lbgra->blu == blu)
						{
							// Grab our right pixel, and the one below it
							lbgraRight	= lbgra + 1;
							lbgraBelow	= (SBgra*)((s8*)lbgra - bmp->rowWidth);

							// Do the pixels match?
							if (lbgraRight->red == red && lbgraRight->grn == grn && lbgraRight->blu == blu)
							{
								// Right matches
								if (lbgraBelow->red == red && lbgraBelow->grn == grn && lbgraBelow->blu == blu)
								{
									// And below matches, this is our marker
									// They match, this is our marker
									if (tlOverwriteMarker)
									{
										// Overlay it
										if (lnX >= 1)
										{
											// Grab the pixel to the left of both the lbgra and lbgraBelow
											// Upper-left
											lbgra->red		= (lbgra-1)->red;
											lbgra->grn		= (lbgra-1)->grn;
											lbgra->blu		= (lbgra-1)->blu;

											// Below
											lbgraBelow->red = (lbgraBelow - 1)->red;
											lbgraBelow->grn = (lbgraBelow - 1)->grn;
											lbgraBelow->blu = (lbgraBelow - 1)->blu;

											if (lnX < bmp->bi.biHeight - 1)
											{
												// Grab the pixel to the right of lbgraRight and copy it
												lbgraRight->red	= (lbgraRight + 1)->red;
												lbgraRight->grn	= (lbgraRight + 1)->grn;
												lbgraRight->blu	= (lbgraRight + 1)->blu;

											} else {
												// Duplicate lbgra into lbgraRight
												lbgraRight->red	= lbgra->red;
												lbgraRight->grn	= lbgra->grn;
												lbgraRight->blu	= lbgra->blu;
											}

										} else {
											// Grab the pixel to the right of lbgraRight and copy to all three
											if (lnX < bmp->bi.biHeight - 1)
											{
												// Pixel to the right
												lbgraRight->red	= (lbgraRight + 1)->red;
												lbgraRight->grn	= (lbgraRight + 1)->grn;
												lbgraRight->blu	= (lbgraRight + 1)->blu;

												// Upper left pixel
												lbgra->red		= lbgraRight->red;
												lbgra->grn		= lbgraRight->grn;
												lbgra->blu		= lbgraRight->blu;

												// Pixel on the row below
												lbgraBelow->red	= lbgraRight->red;
												lbgraBelow->grn	= lbgraRight->grn;
												lbgraBelow->blu	= lbgraRight->blu;

											} else {
												// We can't update it.  The image is too narrow
												// We don't do anything.  I just note this condition here in the comments.
											}
										}
									}

									// Set our values
									if (tnX)	*tnX = lnX;
									if (tnY)	*tnY = lnY;

									// Indicate success
									return(true);
								}
							}
						}
					}
				}
			}
		}

		// If we get here, not found
		return(false);
	}




//////////
//
// Called to draw a point
//
//////
	void iBmp_drawPoint(SBitmap* bmp, s32 tnX, s32 tnY, SBgra color)
	{
		SBgr*	lbgr;
		SBgra*	lbgra;


		if (bmp)
		{
			// Make sure our coordinates are valid
			if (tnX >= 0 && tnX < bmp->bi.biWidth && tnY >= 0 && tnY < bmp->bi.biHeight)
			{
				if (bmp->bi.biBitCount == 24)
				{
					// Get our offset
					lbgr = (SBgr*)(bmp->bd + ((bmp->bi.biHeight - tnY - 1) * bmp->rowWidth) + (tnX * 3));

					// Draw it
					lbgr->red	= color.red;
					lbgr->grn	= color.grn;
					lbgr->blu	= color.blu;

				} else if (bmp->bi.biBitCount == 32) {
					// Get our offset
					lbgra = (SBgra*)(bmp->bd + ((bmp->bi.biHeight - tnY - 1) * bmp->rowWidth) + (tnX * 4));

					// Draw it
					lbgra->red	= color.red;
					lbgra->grn	= color.grn;
					lbgra->blu	= color.blu;
				}
			}
		}
	}

	void iBmp_fillRect(SBitmap* bmp, RECT* rc, SBgra colorNW, SBgra colorNE, SBgra colorSW, SBgra colorSE, bool tlUseGradient, RECT* rcClip, bool tluseClip)
	{
		s32		lnY;
		f32		lfRed, lfGrn, lfBlu, lfRedTo, lfGrnTo, lfBluTo, lfRedInc, lfGrnInc, lfBluInc, lfPercent, lfPercentInc, lfHeight, lfWidth;


		if (bmp && rc)
		{
		//////////
		// Fill every row
		//////
			lfWidth			= (f32)(rc->right  - 1 - rc->left);
			lfHeight		= (f32)(rc->bottom - 1 - rc->top);
			lfPercentInc	= 1.0f / lfHeight;
			for (lfPercent = 0.0, lnY = rc->top; lnY < rc->bottom; lnY++, lfPercent += lfPercentInc)
			{
				if (tlUseGradient)
				{
					//////////
					// Compute FROM colors
					//////
						lfRed		= (f32)colorNW.red + (((f32)colorSW.red - (f32)colorNW.red) * lfPercent);
						lfGrn		= (f32)colorNW.grn + (((f32)colorSW.grn - (f32)colorNW.grn) * lfPercent);
						lfBlu		= (f32)colorNW.blu + (((f32)colorSW.blu - (f32)colorNW.blu) * lfPercent);


					//////////
					// Compute TO colors
					//////
						lfRedTo		= (f32)colorNE.red + (((f32)colorSE.red - (f32)colorNE.red) * lfPercent);
						lfGrnTo		= (f32)colorNE.grn + (((f32)colorSE.grn - (f32)colorNE.grn) * lfPercent);
						lfBluTo		= (f32)colorNE.blu + (((f32)colorSE.blu - (f32)colorNE.blu) * lfPercent);


					//////////
					// Compute increment
					//////
						lfRedInc	= (lfRedTo - lfRed) / lfWidth;
						lfGrnInc	= (lfGrnTo - lfGrn) / lfWidth;
						lfBluInc	= (lfBluTo - lfBlu) / lfWidth;


					//////////
					// Draw this line with its gradient
					//////
						iBmp_drawHorizontalLineGradient(bmp, rc->left, rc->right - 1, lnY, lfRed, lfGrn, lfBlu, lfRedInc, lfGrnInc, lfBluInc, rcClip, tluseClip);

				} else {
					// Draw this line with the NW color
					iBmp_drawHorizontalLine(bmp, rc->left, rc->right - 1, lnY, colorNW);
				}
			}
		}
	}

	void iBmp_frameRect(SBitmap* bmp, RECT* rc, SBgra colorNW, SBgra colorNE, SBgra colorSW, SBgra colorSE, bool tlUseGradient, RECT* rcClip, bool tluseClip)
	{
		f32 lfRed, lfGrn, lfBlu, lfRedTo, lfGrnTo, lfBluTo, lfRedInc, lfGrnInc, lfBluInc, lfWidth;


		if (bmp && rc)
		{
			if (tlUseGradient)
			{
				// Compute standards
				lfWidth		= (f32)(rc->right  - 1 - rc->left);
//				lfHeight	= (f32)(rc->bottom - 1 - rc->top);

				//////////
				// Top (NW to NE)
				//////
					// Compute FROM and TO colors
					lfRed = (f32)colorNW.red;			lfRedTo = (f32)colorNE.red;
					lfGrn = (f32)colorNW.grn;			lfGrnTo = (f32)colorNE.grn;
					lfBlu = (f32)colorNW.blu;			lfBluTo = (f32)colorNE.blu;

					// Compute increment
					lfRedInc	= (lfRedTo - lfRed) / lfWidth;
					lfGrnInc	= (lfGrnTo - lfGrn) / lfWidth;
					lfBluInc	= (lfBluTo - lfBlu) / lfWidth;

					// Draw it
					iBmp_drawHorizontalLineGradient(bmp, rc->left, rc->right - 1, rc->top, lfRed, lfGrn, lfBlu, lfRedInc, lfGrnInc, lfBluInc, rcClip, true);


				//////////
				// Bottom (SW to SE)
				//////
					// Compute FROM and TO colors
					lfRed = (f32)colorSW.red;			lfRedTo = (f32)colorSE.red;
					lfGrn = (f32)colorSW.grn;			lfGrnTo = (f32)colorSE.grn;
					lfBlu = (f32)colorSW.blu;			lfBluTo = (f32)colorSE.blu;

					// Compute increment
					lfRedInc	= (lfRedTo - lfRed) / lfWidth;
					lfGrnInc	= (lfGrnTo - lfGrn) / lfWidth;
					lfBluInc	= (lfBluTo - lfBlu) / lfWidth;

					// Draw it
					iBmp_drawHorizontalLineGradient(bmp, rc->left, rc->right - 1, rc->bottom - 1, lfRed, lfGrn, lfBlu, lfRedInc, lfGrnInc, lfBluInc, rcClip, true);


				//////////
				// Left (NW to SW)
				//////
					// Compute FROM and TO colors
					lfRed = (f32)colorNW.red;			lfRedTo = (f32)colorSW.red;
					lfGrn = (f32)colorNW.grn;			lfGrnTo = (f32)colorSW.grn;
					lfBlu = (f32)colorNW.blu;			lfBluTo = (f32)colorSW.blu;

					// Compute increment
					lfRedInc	= (lfRedTo - lfRed) / lfWidth;
					lfGrnInc	= (lfGrnTo - lfGrn) / lfWidth;
					lfBluInc	= (lfBluTo - lfBlu) / lfWidth;

					// Draw it
					iBmp_drawVerticalLineGradient(bmp, rc->top, rc->bottom - 1, rc->left, lfRed, lfGrn, lfBlu, lfRedInc, lfGrnInc, lfBluInc, rcClip, true);


				//////////
				// Right (NE to SE)
				//////
					// Compute FROM and TO colors
					lfRed = (f32)colorNE.red;			lfRedTo = (f32)colorSE.red;
					lfGrn = (f32)colorNE.grn;			lfGrnTo = (f32)colorSE.grn;
					lfBlu = (f32)colorNE.blu;			lfBluTo = (f32)colorSE.blu;

					// Compute increment
					lfRedInc	= (lfRedTo - lfRed) / lfWidth;
					lfGrnInc	= (lfGrnTo - lfGrn) / lfWidth;
					lfBluInc	= (lfBluTo - lfBlu) / lfWidth;

					// Draw it
					iBmp_drawVerticalLineGradient(bmp, rc->top, rc->bottom - 1, rc->right - 1, lfRed, lfGrn, lfBlu, lfRedInc, lfGrnInc, lfBluInc, rcClip, true);

			} else {
				// Just draw in a solid color
				iBmp_drawHorizontalLine(bmp, rc->left, rc->right - 1, rc->top, colorNW);
				iBmp_drawHorizontalLine(bmp, rc->left, rc->right - 1, rc->bottom - 1, colorNW);
				iBmp_drawVerticalLine(bmp, rc->top, rc->bottom - 1, rc->left, colorNW);
				iBmp_drawVerticalLine(bmp, rc->top, rc->bottom - 1, rc->right - 1, colorNW);
			}
		}
	}




//////////
//
// Frame the indicated rectangle using the nine parts of an image:
//
//		 _______________________
//		|       |       |       |
//		|   1   |   2   |   3   |
//		|_______|_______|_______|
//		|       |       |       |
//		|   4   |   5   |   6   |
//		|_______|_______|_______|
//		|       |       |       |
//		|   7   |   8   |   9   |
//		|_______|_______|_______|
//
// Parts 1, 3, 7, and 9, are rendered at the corners.
// Parts 2 and 8 are repeated across the top and bottom.
// Parts 4 and 6 are repeated down the sides.
// The remainder of the image is colorized with the pixel color at the center of 5.
//
//////
	void iiBmp_frameInNineParts(SBitmap* bmpDst, RECT* trc, SBitmap* bmpFrame)
	{
		s32		lnX, lnY, lnWidth, lnHeight, lnDstRight, lnDstBottom;
		u8		lcRed, lcGrn, lcBlu;
		SBgr*	lbgr;


		//////////
		// Determine the coordinates for each part
		//////
			lnWidth		= max(bmpFrame->bi.biWidth  / 3, 1);
			lnHeight	= max(bmpFrame->bi.biHeight / 3, 1);


		//////////
		// Overlay the corners
		//////
			// Top
			iiBmp_bitBltPortion(bmpDst, trc->left,				trc->top, lnWidth, lnHeight, bmpFrame, 0,								0);
			iiBmp_bitBltPortion(bmpDst, trc->right - lnWidth,	trc->top, lnWidth, lnHeight, bmpFrame, bmpFrame->bi.biWidth - lnWidth,	0);
			// Bottom
			iiBmp_bitBltPortion(bmpDst, trc->left,				trc->bottom - lnHeight, lnWidth, lnHeight, bmpFrame, 0,									bmpFrame->bi.biHeight - lnHeight);
			iiBmp_bitBltPortion(bmpDst, trc->right - lnWidth,	trc->bottom - lnHeight, lnWidth, lnHeight, bmpFrame, bmpFrame->bi.biWidth - lnWidth,	bmpFrame->bi.biHeight - lnHeight);


		//////////
		// Repeatedly overlay the middle and sides
		//////
			lnDstRight	= trc->right - trc->left - lnWidth;
			lnDstBottom = trc->bottom - trc->top - lnHeight;
			for (lnX = lnWidth; lnX < lnDstRight; lnX++)
			{
				// Middle top and bottom
				iiBmp_bitBltPortion(bmpDst, trc->left + lnX, trc->top,					1, lnHeight, bmpFrame, lnWidth, 0);
				iiBmp_bitBltPortion(bmpDst, trc->left + lnX, trc->bottom - lnHeight,	1, lnHeight, bmpFrame, lnWidth,	bmpFrame->bi.biHeight - lnHeight);
			}
			for (lnY = lnHeight; lnY < lnDstBottom; lnY++)
			{
				// Sides
				iiBmp_bitBltPortion(bmpDst, trc->left,				trc->top + lnY,	lnWidth, 1, bmpFrame, 0,								lnHeight);
				iiBmp_bitBltPortion(bmpDst, trc->right - lnWidth,	trc->top + lnY,	lnWidth, 1, bmpFrame, bmpFrame->bi.biWidth - lnWidth,	lnHeight);
			}


		//////////
		// Fill the middle completely with the middle-most pixel color
		//////
			lbgr = (SBgr*)(bmpFrame->bd + (((bmpFrame->bi.biHeight / 2) - 1) * bmpFrame->rowWidth) + (((bmpFrame->bi.biWidth / 2) - 1) * 3));
			lcRed	= lbgr->red;
			lcGrn	= lbgr->grn;
			lcBlu	= lbgr->blu;

			// Iterate for the inner portion
			for (lnY = lnHeight; lnY < lnDstBottom; lnY++)
			{
				if (lnY + trc->top + lnHeight >= 0 && lnY + trc->top + lnHeight < bmpDst->bi.biHeight)
				{
					lbgr = (SBgr*)(bmpDst->bd + ((bmpDst->bi.biHeight - trc->top - lnY - 1) * bmpDst->rowWidth) + ((trc->left + lnWidth) * 3));
					for (lnX = lnWidth; lnX < lnDstRight; lnX++, lbgr++)
					{
						if (lnX + trc->left + lnWidth >= 0 && lnX + trc->left + lnWidth < bmpDst->bi.biWidth)
						{
							// Populate this entry
							lbgr->red = lcRed;
							lbgr->grn = lcGrn;
							lbgr->blu = lcBlu;
						}
					}
				}
			}
	}




//////////
//
// Called to bitBlt a portion of a bitmap from source to destination
//
//////
	void iiBmp_bitBltPortion(SBitmap* bmpDst, s32 tnX, s32 tnY, s32 tnWidth, s32 tnHeight, SBitmap* bmpSrc, s32 tnXStart, s32 tnYStart)
	{
		s32			lnY, lnX;
		SBgr*		lbgrd;
		SBgr*		lbgrs;


		// Is there some work to do?
		if (tnX < bmpDst->bi.biWidth && tnXStart + bmpSrc->bi.biWidth >= 0 && tnY < bmpDst->bi.biHeight && tnYStart + bmpSrc->bi.biHeight >= 0)
		{
			// Draw the item
			for (lnY = 0; tnYStart + lnY < bmpSrc->bi.biHeight && lnY < tnHeight; lnY++)
			{
				if (lnY + tnY >= 0 && lnY + tnYStart >= 0 && lnY + tnY < bmpDst->bi.biHeight && lnY + tnYStart < bmpSrc->bi.biHeight)
				{
					// Compute the destination and source
					lbgrd = (SBgr*)(bmpDst->bd + ((bmpDst->bi.biHeight - tnY      - lnY - 1) * bmpDst->rowWidth) + (tnX      * 3));
					lbgrs = (SBgr*)(bmpSrc->bd + ((bmpSrc->bi.biHeight - tnYStart - lnY - 1) * bmpSrc->rowWidth) + (tnXStart * 3));

					// Repeat for every pixel horizontally
					for (lnX = 0; tnXStart + lnX < bmpSrc->bi.biWidth && lnX < tnWidth; lnX++)
					{
						// Will it fit?
						if (lnX + tnX >= 0 && lnX + tnXStart >= 0 && lnX + tnX < bmpDst->bi.biWidth && lnX + tnXStart < bmpSrc->bi.biWidth)
						{
							// Copy it
							lbgrd->red	= lbgrs->red;
							lbgrd->grn	= lbgrs->grn;
							lbgrd->blu	= lbgrs->blu;
						}

						// Move to next pixel
						++lbgrd;
						++lbgrs;
					}
				}
			}
		}
	}

	void iBmp_drawHorizontalLine(SBitmap* bmp, s32 tnX1, s32 tnX2, s32 tnY, SBgra color)
	{
		s32		lnX;
		SBgr*	lbgr;
		SBgra*	lbgra;


		if (bmp)
		{
			if (tnY >= 0 && tnY < bmp->bi.biHeight)
			{
				// Get our starting point
				lbgr	= (SBgr*)(bmp->bd  + ((bmp->bi.biHeight - tnY - 1) * bmp->rowWidth) + (tnX1 * (bmp->bi.biBitCount / 8)));
				lbgra	= (SBgra*)(bmp->bd + ((bmp->bi.biHeight - tnY - 1) * bmp->rowWidth) + (tnX1 * (bmp->bi.biBitCount / 8)));

				if (bmp->bi.biBitCount == 24)
				{
					// Iterate for each column
					for (lnX = tnX1; lnX <= tnX2; lnX++)
					{
						// Are we on the bitmap?
						if (lnX >= 0 && lnX < bmp->bi.biWidth)
						{
							// Draw the pixel
							lbgr->red	= color.red;
							lbgr->grn	= color.grn;
							lbgr->blu	= color.blu;
						}
						// Move to next column
						++lbgr;
					}

				} else if (bmp->bi.biBitCount == 32) {
					// Iterate for each column
					for (lnX = tnX1; lnX <= tnX2; lnX++)
					{
						// Are we on the bitmap?
						if (lnX >= 0 && lnX < bmp->bi.biWidth)
						{
							// Draw the pixel
							lbgra->alp	= 255;
							lbgra->red	= color.red;
							lbgra->grn	= color.grn;
							lbgra->blu	= color.blu;
						}
						// Move to next column
						++lbgra;
					}
				}
			}
		}
	}

	void iBmp_drawVerticalLine(SBitmap* bmp, s32 tnY1, s32 tnY2, s32 tnX, SBgra color)
	{
		s32		lnY;
		SBgr*	lbgr;
		SBgra*	lbgra;


		if (bmp)
		{
			if (tnX >= 0 && tnX < bmp->bi.biWidth)
			{
				// Get our starting point
				lbgr	= (SBgr*)(bmp->bd  + ((bmp->bi.biHeight - tnY1 - 1) * bmp->rowWidth) + (tnX * (bmp->bi.biBitCount / 8)));
				lbgra	= (SBgra*)(bmp->bd + ((bmp->bi.biHeight - tnY1 - 1) * bmp->rowWidth) + (tnX * (bmp->bi.biBitCount / 8)));

				if (bmp->bi.biBitCount == 24)
				{
					// Iterate for each column
					for (lnY = tnY1; lnY <= tnY2; lnY++)
					{
						// Are we on the bitmap?
						if (lnY >= 0 && lnY < bmp->bi.biHeight)
						{
							// Draw the pixel
							lbgr->red	= color.red;
							lbgr->grn	= color.grn;
							lbgr->blu	= color.blu;
						}
						// Move to next row
						lbgr = (SBgr*)((s8*)lbgr - bmp->rowWidth);
					}

				} else if (bmp->bi.biBitCount == 32) {
					// Iterate for each column
					for (lnY = tnY1; lnY <= tnY2; lnY++)
					{
						// Are we on the bitmap?
						if (lnY >= 0 && lnY < bmp->bi.biHeight)
						{
							// Draw the pixel
							lbgra->alp	= 255;
							lbgra->red	= color.red;
							lbgra->grn	= color.grn;
							lbgra->blu	= color.blu;
						}
						// Move to next row
						lbgra = (SBgra*)((s8*)lbgra - bmp->rowWidth);
					}
				}
			}
		}
	}




//////////
//
// Gradient line algorithms
//
//////
	void iBmp_drawHorizontalLineGradient(SBitmap* bmp, s32 tnX1, s32 tnX2, s32 tnY, f32 tfRed, f32 tfGrn, f32 tfBlu, f32 tfRedInc, f32 tfGrnInc, f32 tfBluInc, RECT* rcClip, bool tluseClip)
	{
		s32		lnX;
		SBgr*	lbgr;
		SBgra*	lbgra;


		if (bmp)
		{
			// Get our starting point
			lbgr	= (SBgr*)(bmp->bd  + ((bmp->bi.biHeight - tnY - 1) * bmp->rowWidth) + (tnX1 * (bmp->bi.biBitCount / 8)));
			lbgra	= (SBgra*)(bmp->bd + ((bmp->bi.biHeight - tnY - 1) * bmp->rowWidth) + (tnX1 * (bmp->bi.biBitCount / 8)));

			if (bmp->bi.biBitCount == 24)
			{
				// Iterate for each column
				for (lnX = tnX1; lnX <= tnX2; lnX++, tfRed += tfRedInc, tfGrn += tfGrnInc, tfBlu += tfBluInc)
				{
					// Are we on the bitmap?
					if ((!tluseClip || !(tnY >= rcClip->top && tnY <= rcClip->bottom && lnX >= rcClip->left && lnX <= rcClip->right)) && lnX >= 0 && lnX < bmp->bi.biWidth)
					{
						// Draw the pixel
						lbgr->red	= (u8)tfRed;
						lbgr->grn	= (u8)tfGrn;
						lbgr->blu	= (u8)tfBlu;
					}
					// Move to next column
					++lbgr;
				}

			} else if (bmp->bi.biBitCount == 32) {
				// Iterate for each column
				for (lnX = tnX1; lnX <= tnX2; lnX++, tfRed += tfRedInc, tfGrn += tfGrnInc, tfBlu += tfBluInc)
				{
					// Are we on the bitmap?
					if ((!tluseClip || !(tnY >= rcClip->top && tnY <= rcClip->bottom && lnX >= rcClip->left && lnX <= rcClip->right)) && lnX >= 0 && lnX < bmp->bi.biWidth)
					{
						// Draw the pixel
						lbgra->alp	= 255;
						lbgra->red	= (u8)tfRed;
						lbgra->grn	= (u8)tfGrn;
						lbgra->blu	= (u8)tfBlu;
					}
					// Move to next column
					++lbgra;
				}
			}
		}
	}

	void iBmp_drawVerticalLineGradient(SBitmap* bmp, s32 tnY1, s32 tnY2, s32 tnX, f32 tfRed, f32 tfGrn, f32 tfBlu, f32 tfRedInc, f32 tfGrnInc, f32 tfBluInc, RECT* rcClip, bool tluseClip)
	{
		s32		lnY;
		SBgr*	lbgr;
		SBgra*	lbgra;


		if (bmp)
		{
			// Get our starting point
			lbgr	= (SBgr*)(bmp->bd  + ((bmp->bi.biHeight - tnY1 - 1) * bmp->rowWidth) + (tnX * (bmp->bi.biBitCount / 8)));
			lbgra	= (SBgra*)(bmp->bd + ((bmp->bi.biHeight - tnY1 - 1) * bmp->rowWidth) + (tnX * (bmp->bi.biBitCount / 8)));

			if (bmp->bi.biBitCount == 24)
			{
				// Iterate for each column
				for (lnY = tnY1; lnY <= tnY2; lnY++, tfRed += tfRedInc, tfGrn += tfGrnInc, tfBlu += tfBluInc)
				{
					// Are we on the bitmap?
					if (!(lnY >= rcClip->top && lnY <= rcClip->bottom && tnX >= rcClip->left && tnX <= rcClip->right) && lnY >= 0 && lnY < bmp->bi.biHeight)
					{
						// Draw the pixel
						lbgr->red	= (u8)tfRed;
						lbgr->grn	= (u8)tfGrn;
						lbgr->blu	= (u8)tfBlu;
					}
					// Move to next row
					lbgr = (SBgr*)((s8*)lbgr - bmp->rowWidth);
				}

			} else if (bmp->bi.biBitCount == 32) {
				// Iterate for each column
				for (lnY = tnY1; lnY <= tnY2; lnY++, tfRed += tfRedInc, tfGrn += tfGrnInc, tfBlu += tfBluInc)
				{
					// Are we on the bitmap?
					if (!(lnY >= rcClip->top && lnY <= rcClip->bottom && tnX >= rcClip->left && tnX <= rcClip->right) && lnY >= 0 && lnY < bmp->bi.biHeight)
					{
						// Draw the pixel
						lbgra->alp	= 255;
						lbgra->red	= (u8)tfRed;
						lbgra->grn	= (u8)tfGrn;
						lbgra->blu	= (u8)tfBlu;
					}
					// Move to next row
					lbgra = (SBgra*)((s8*)lbgra - bmp->rowWidth);
				}
			}
		}
	}

	// minimumRatio is in the range 0..1
	f32 iiBmp_squeezeColorChannel(f32 colorChannel, f32 minimumRatio)
	{
		f32 newRatio, colorBase;


//		currentRatio	= colorChannel / 255.0f;
		newRatio		= 1.0f - minimumRatio;
		colorBase		= minimumRatio * 255.0f;

		return(colorBase + (newRatio * colorChannel));
	}




//////////
//
// Called to scale one bitmap into another.
//
// Note:  All of this code was adapted from the Visual FreePro.
// Note:  See https://github.com/RickCHodgin/libsf (in vvm\core\).
//
//////
	u32 iBmp_scale(SBitmap* bmpDst, SBitmap* bmpSrc)
	{
		u32		lnResult;
		f32		lfVertical, lfHorizontal;
		RECT	lrc;


		// Make sure our environment is sane
		lnResult = -1;
		if (bmpDst && bmpSrc)
		{
			if (bmpDst->bi.biBitCount == 24 || bmpDst->bi.biBitCount == 32)
			{
				if (bmpSrc->bi.biBitCount == 24 || bmpSrc->bi.biBitCount == 32)
				{
					// We have valid source and destination bitmaps
					if (bmpSrc->bi.biWidth == bmpDst->bi.biWidth && bmpSrc->bi.biHeight == bmpDst->bi.biHeight)
					{
						// They're the same size
						if (bmpSrc->bi.biBitCount == bmpDst->bi.biBitCount)
						{
							// They're the same bit counts, do a fast copy
							memcpy(bmpDst->bd, bmpSrc->bd, bmpSrc->bi.biSizeImage);

						} else {
							// Do a bitBlt to translate bit counts
							SetRect(&lrc, 0, 0, bmpDst->bi.biWidth, bmpDst->bi.biHeight);
							iBmp_bitBlt(bmpDst, &lrc, bmpSrc);
						}
						// Indicate success
						lnResult = 1;

					} else {
						// We need to scale
						lfVertical		= (f32)bmpSrc->bi.biHeight / (f32)bmpDst->bi.biHeight;
						lfHorizontal	= (f32)bmpSrc->bi.biWidth  / (f32)bmpDst->bi.biWidth;
						lnResult		= iiBmp_scale_Process(bmpDst, bmpSrc, lfVertical, lfHorizontal);
					}
				}
			}
		}

		// Indicate our failure or success
		return(lnResult);
	}




//////////
//
// Takes a 24-bit bitmap, and scales it up or down to the specified size, with a
// minimum of a 1x1 pixel size.
//
// Returns:
//		-1		- Input file could not be opened
//		-2		- Invalid input bitmap
//		-3		- Unable to allocate memory for input bitmap
//		-4		- Error reading input bitmap
//		-5		- Unable to allocate memory for output bitmap
//		-6		- Unable to create the output file
//		-7		- Unable to write to output file
//
//////
	u32 iiBmp_scale_Process(SBitmap* bmpDst, SBitmap* bmpSrc, f32 tfVerticalScaler, f32 tfHorizontalScaler)
	{
		s32				lnY, lnX;
		SBitmapProcess	bp;


		// Being the scaling procedure
		bp.src		= bmpSrc;
		bp.ratioV	= (f32)bmpSrc->bi.biHeight	/ (f32)bmpDst->bi.biHeight;
		bp.ratioH	= (f32)bmpSrc->bi.biWidth	/ (f32)bmpDst->bi.biWidth;
		bp.pixels	= (SBgraf*)malloc(((u32)bp.ratioV + 16) * ((u32)bp.ratioH + 16) * sizeof(SBgraf));

		// Iterate through every pixel
		for (lnY = 0; lnY < bmpDst->bi.biHeight; lnY++)
		{
			// Grab the offset for this line
			if (bmpDst->bi.biBitCount == 24)		bp.optr		= (SBgr*)( bmpDst->bd + ((bmpDst->bi.biHeight - lnY - 1) * bmpDst->rowWidth));
			else									bp.optra	= (SBgra*)(bmpDst->bd + ((bmpDst->bi.biHeight - lnY - 1) * bmpDst->rowWidth));

			// Repeat for every pixel across this row
			for (lnX = 0; lnX < bmpDst->bi.biWidth; lnX++)
			{
				// Compute data for this spanned pixel
				bp.uly	= min((f32)lnY * bp.ratioV, (f32)bmpSrc->bi.biHeight - bp.ratioV);
				bp.ulx	= min((f32)lnX * bp.ratioH, (f32)bmpSrc->bi.biWidth  - bp.ratioH);
				bp.lry	= bp.uly + bp.ratioV;
				bp.lrx	= bp.ulx + bp.ratioH;

				// Get all the color information for this potentially spanned pixel
				iiBmp_scale_processPixels(&bp);

				// Store the color
				if (bmpDst->bi.biBitCount == 24)
				{
					bp.optr->red = (u8)bp.red;
					bp.optr->grn = (u8)bp.grn;
					bp.optr->blu = (u8)bp.blu;
					// Move to the next pixel
					++bp.optr;

				} else {
					bp.optra->red = (u8)bp.red;
					bp.optra->grn = (u8)bp.grn;
					bp.optra->blu = (u8)bp.blu;
					// Move to the next pixel
					++bp.optra;
				}
			}
		}
		// When we get here, we've computed everything

		// Finished, indicate the pixel count
		return(bmpDst->bi.biHeight * bmpDst->bi.biWidth * sizeof(SBgr));
	}




//////////
//
// Get spanned pixel data, meaning the input (bii, bdi) values are scanned based on the
// location of tnY,tnX and the relationship between bii and bio, meaning the input and
// output sizes.  If bii is bigger, then each bio pixel maps to more than one bii pixel.
// If they're identical, it's 1:1.  If bii is smaller, then each bio pixel maps to less
// than one full bii pixel.  There are no other options. :-)  This algorithm should not
// be used for 1:1 ratio conversions.
//
// Note that each of the above conditions applies to both width and height, meaning the
// relationship between bii and bio is analyzed on each axis, resulting in nine possible
// states (wider+taller, wider+equal, wider+shorter, equal+taller, equal+equal, equal+shorter,
// narrower+taller, narrower+equal, narrower+shorter).
//
// This natural relationship breaks down into nine general point forms:
//		Original pixels:			Output pixels span original pixels:
//		 ______________ 			 ______________ 			 ______________
//		|    |    |    |			|    |    |    |			|1   | 2  |   3|
//		|____|____|____|			|__+--------+__|			|__+--------+__|
//		|    |    |    |	==>		|  |        |  |	==>		|4 |   5    | 6|
//		|____|____|____|	==>		|__|        |__|	==>		|__|        |__|
//		|    |    |    |			|  +--------+  |			|7 +---8----+ 9|
//		|____|____|____|			|____|____|____|			|____|____|____|
//
// This form is comprised of 9 general parts, eight of which may not be present in all
// relationships, and five of which may span multiple columns, rows or both.
//
// These are:
//		1	- upper-left	(always,	spans at most one pixel)
//		2	- upper-middle	(optional,	spans at most multiple partial or full pixels)
//		3	- upper-right	(optional,	spans at most one pixel)
//		4	- middle-left	(optional,	spans at most multiple partial or full pixels)
//		5	- middle-middle	(optional,	can span multiple partial or full pixels)
//		6	- middle-right	(optional,	spans at most multiple partial or full pixels)
//		7	- lower-left	(optional,	spans at most one pixel)
//		8	- lower-middle	(optional,	spans at most multiple partial or full pixels)
//		9	- lower-right	(optional,	spans at most one pixel)
//
//////
	void iiBmp_scale_processPixels(SBitmapProcess* bp)
	{
		u32		lnI;
		f32		lfRed, lfGrn, lfBlu, lfAlp, lfAreaAccumulator;


		// Raise the flags for which portions are valid / required
		bp->spans2H		= (iiBmp_scale_processGetIntegersBetween(bp->ulx, bp->lrx) >= 1);		// It occupies at least two pixels horizontally (itself and one more)
		bp->spans3H		= (iiBmp_scale_processGetIntegersBetween(bp->ulx, bp->lrx) >= 2);		// It occupies at least three pixels horizontally (itself, at least one in the middle, and one at the right)
		bp->spans2V		= (iiBmp_scale_processGetIntegersBetween(bp->uly, bp->lry) >= 1);		// It occupies at least two pixels vertically (itself and one more)
		bp->spans3V		= (iiBmp_scale_processGetIntegersBetween(bp->uly, bp->lry) >= 2);		// It occupies at least three pixels vertically (itself, at least one in the middle, and one at the right)

		// Reset the point count
		bp->count		= 0;

		// Indicate the start of this input line
		if (bp->src->bi.biBitCount == 24)
		{
			// 24-bit bitmap
			bp->iptr		= (SBgr*)(bp->src->bd + ((bp->src->bi.biHeight - (s32)bp->uly - 1) * bp->src->rowWidth));	// current line
			bp->iptrAnchor	= (SBgr*)(bp->src->bd + ((bp->src->bi.biHeight                   ) * bp->src->rowWidth));	// root anchor (does not include the conversion from base-1)

		} else {
			// 32-bit bitmap
			bp->iptra		= (SBgra*)(bp->src->bd + ((bp->src->bi.biHeight - (s32)bp->uly - 1) * bp->src->rowWidth));	// current line
			bp->iptrAnchora	= (SBgra*)(bp->src->bd + ((bp->src->bi.biHeight                   ) * bp->src->rowWidth));	// root anchor (does not include the conversion from base-1)
		}


		//////////
		// The following functions (if called) update the number of pieces of picture data to add to the output
		//////
			//////////
			// 1 - upper-left (always, spans at most one pixel)
			//////
				iiBmp_scale_processSpannedPixel1(bp);

			//////////
			// 2 - upper-middle (optional, spans at most multiple partial or full pixels, but only if 1, 2 and 3 exist)
			//////
				if (bp->spans3H)
					iiBmp_scale_processSpannedPixel2(bp);


			//////////
			// 3 - upper-right (optional, spans at most one pixel, but only if 1 and 3 exist (as 1 and 2))
			//////
				if (bp->spans2H || bp->spans3H)
					iiBmp_scale_processSpannedPixel3(bp);


			//////////
			// 4 - middle-left (optional, spans at most multiple partial or full pixels)
			//////
				if (bp->spans3V && bp->spans2V)
					iiBmp_scale_processSpannedPixel4(bp);


			//////////
			// 5 - middle-middle (optional, can span multiple partial or full pixels)
			//////
				if (bp->spans3V && bp->spans3H)
					iiBmp_scale_processSpannedPixel5(bp);


			//////////
			// 6 - middle-right (optional, spans at most multiple partial or full pixels)
			//////
				if (bp->spans3V && (bp->spans2H || bp->spans3H))
					iiBmp_scale_processSpannedPixel6(bp);


			//////////
			// 7 - lower-left (optional, spans at most one pixel)
			//////
				if (bp->spans2V)
					iiBmp_scale_processSpannedPixel7(bp);


			//////////
			// 8 - lower-middle (optional, spans at most multiple partial or full pixels)
			//////
				if (bp->spans2V && bp->spans3H)
					iiBmp_scale_processSpannedPixel8(bp);


			//////////
			// 9 - lower-right (optional, spans at most one pixel)
			//////
				if (bp->spans2V && (bp->spans2H || bp->spans3H))
					iiBmp_scale_processSpannedPixel9(bp);


		//////////
		// Add up all the pixels to compute the specified value
		//////
			lfAreaAccumulator = 0.0;
			for (lnI = 0; lnI < bp->count; lnI++)
				lfAreaAccumulator += bp->pixels[lnI].area;

			// Initialize
			lfRed	= 0;
			lfGrn	= 0;
			lfBlu	= 0;
			lfAlp	= 0;

			// Now, compute each component as its part of the total area
			for (lnI = 0; lnI < bp->count; lnI++)
			{
				// Derive this portion component
				lfRed	+=		bp->pixels[lnI].red	*	(bp->pixels[lnI].area / lfAreaAccumulator);
				lfGrn	+=		bp->pixels[lnI].grn	*	(bp->pixels[lnI].area / lfAreaAccumulator);
				lfBlu	+=		bp->pixels[lnI].blu	*	(bp->pixels[lnI].area / lfAreaAccumulator);
				lfAlp	+=		bp->pixels[lnI].alp	*	(bp->pixels[lnI].area / lfAreaAccumulator);
			}

			// When we get here, we have our values, now create the final summed up output
			bp->red = (u8)(lfRed + 0.5);
			bp->grn = (u8)(lfGrn + 0.5);
			bp->blu = (u8)(lfBlu + 0.5);
			bp->alp = (u8)(lfAlp + 0.5);
	}




//////////
//
// 1 - upper-left (see iGetSpannedPixelColors() above)
// Upper left pixels is ALWAYS computed. It may be the ONLY one computed, but it is always computed.
//
//////
	void iiBmp_scale_processSpannedPixel1(SBitmapProcess* bp)
	{
		// Store left- and right-sides for this spanned pixel
		bp->left			= (s32)min(bp->ulx,			bp->src->bi.biWidth - 1);
		bp->right			= (s32)min(bp->lrx,			bp->src->bi.biWidth - 1);

		// Compute the middle section in pixels
		// Note: -2 is for -1 base 0, and -1 because we want the max value to be one before the width/height
		bp->middleStartH	= (s32)min(bp->ulx + 1,		bp->src->bi.biWidth  - 1);		// next pixel right of upper-left
		bp->middleFinishH	= (s32)min(bp->lrx - 1,		bp->src->bi.biWidth  - 1);		// next pixel left of upper-right (which is actually lower-right, but on this upper line)
		bp->middleStartV	= (s32)min(bp->uly + 1,		bp->src->bi.biHeight - 1);		// next pixel right of left-side pixels
		bp->middleFinishV	= (s32)min(bp->lry - 1,		bp->src->bi.biHeight - 1);		// next pixel left of right-side pixels

		// Find out where this upper-left pixel falls
		if (!bp->spans2H)	bp->widthLeft	=      bp->lrx          - bp->ulx;		// Entire width is within this one pixel, so it's only a portion of the pixel's overall width
		else				bp->widthLeft	= (f32)bp->middleStartH - bp->ulx;		// It spans from where it is to the right of the pixel square

 		if (!bp->spans2V)	bp->height		=      bp->lry          - bp->uly;			// It's entire height is within this one pixel, so it's only a portion of the pixel's overall height
		else				bp->height		= (f32)bp->middleStartV - bp->uly;			// It spans from where it is to the bottom of the pixel square

		// Compute the area for this pixel component
		bp->area = bp->widthLeft * bp->height;

		// Store the colors for this point
		if (bp->src->bi.biBitCount == 24)
		{
			// 24-bit bitmap
			(bp->pixels[bp->count]).red		= (f32)(((SBgr*)((u8*)bp->iptr + (bp->left * 3)))->red);
			(bp->pixels[bp->count]).grn		= (f32)(((SBgr*)((u8*)bp->iptr + (bp->left * 3)))->grn);
			(bp->pixels[bp->count]).blu		= (f32)(((SBgr*)((u8*)bp->iptr + (bp->left * 3)))->blu);
			(bp->pixels[bp->count]).area	= bp->area;

		} else {
			// 32-bit bitmap
			(bp->pixels[bp->count]).red		= (f32)(((SBgra*)((u8*)bp->iptra + (bp->left * 4)))->red);
			(bp->pixels[bp->count]).grn		= (f32)(((SBgra*)((u8*)bp->iptra + (bp->left * 4)))->grn);
			(bp->pixels[bp->count]).blu		= (f32)(((SBgra*)((u8*)bp->iptra + (bp->left * 4)))->blu);
			(bp->pixels[bp->count]).alp		= (f32)(((SBgra*)((u8*)bp->iptra + (bp->left * 4)))->alp);
			(bp->pixels[bp->count]).area	= bp->area;
		}

		// Move over for the next point
		++bp->count;
	}




//////////
//
// 2 - upper-middle (see iGetSpannedPixelColors() above)
// It is known when this function is called that there is at least one, full, middle pixel
//
//////
	void iiBmp_scale_processSpannedPixel2(SBitmapProcess* bp)
	{
		s32 lnPixel;


		// For every middle pixel, apply these values
		for (lnPixel = bp->middleStartH; lnPixel < bp->middleFinishH; lnPixel++)
		{
			// Store this pixel data
			if (bp->src->bi.biBitCount == 24)
			{
				// 24-bit bitmap
				(bp->pixels[bp->count]).red		= (f32)(((SBgr*)((u8*)bp->iptr + (lnPixel * 3)))->red);
				(bp->pixels[bp->count]).grn		= (f32)(((SBgr*)((u8*)bp->iptr + (lnPixel * 3)))->grn);
				(bp->pixels[bp->count]).blu		= (f32)(((SBgr*)((u8*)bp->iptr + (lnPixel * 3)))->blu);
				(bp->pixels[bp->count]).area	= bp->height;

			} else {
				// 32-bit bitmap
				(bp->pixels[bp->count]).red		= (f32)(((SBgra*)((u8*)bp->iptra + (lnPixel * 4)))->red);
				(bp->pixels[bp->count]).grn		= (f32)(((SBgra*)((u8*)bp->iptra + (lnPixel * 4)))->grn);
				(bp->pixels[bp->count]).blu		= (f32)(((SBgra*)((u8*)bp->iptra + (lnPixel * 4)))->blu);
				(bp->pixels[bp->count]).alp		= (f32)(((SBgra*)((u8*)bp->iptra + (lnPixel * 4)))->alp);
				(bp->pixels[bp->count]).area	= bp->height;
			}

			// Move over for the next point
			++bp->count;
		}
	}




//////////
//
// 3 - upper-right (see iGetSpannedPixelColors() above)
// It is known when this function is called that there is at least a second row
//
//////
	void iiBmp_scale_processSpannedPixel3(SBitmapProcess* bp)
	{
		// Find out where this upper-left pixel falls
		bp->widthRight = bp->lrx - (f32)bp->right;		// It spans from the start of the right-most pixel to wherever it falls therein

		// Compute the area for this pixel component
		bp->area = bp->widthRight * bp->height;

		// Store this pixel data
		if (bp->src->bi.biBitCount == 24)
		{
			// 24-bit bitmap
			(bp->pixels[bp->count]).red		= (f32)(((SBgr*)((u8*)bp->iptr + (bp->right * 3)))->red);
			(bp->pixels[bp->count]).grn		= (f32)(((SBgr*)((u8*)bp->iptr + (bp->right * 3)))->grn);
			(bp->pixels[bp->count]).blu		= (f32)(((SBgr*)((u8*)bp->iptr + (bp->right * 3)))->blu);
			(bp->pixels[bp->count]).area	= bp->area;

		} else {
			// 32-bit bitmap
			(bp->pixels[bp->count]).red		= (f32)(((SBgra*)((u8*)bp->iptra + (bp->right * 4)))->red);
			(bp->pixels[bp->count]).grn		= (f32)(((SBgra*)((u8*)bp->iptra + (bp->right * 4)))->grn);
			(bp->pixels[bp->count]).blu		= (f32)(((SBgra*)((u8*)bp->iptra + (bp->right * 4)))->blu);
			(bp->pixels[bp->count]).alp		= (f32)(((SBgra*)((u8*)bp->iptra + (bp->right * 4)))->alp);
			(bp->pixels[bp->count]).area	= bp->area;
		}

		// Move over for the next point
		++bp->count;
	}




//////////
//
// 4 - middle-left (see iGetSpannedPixelColors() above)
// It is known when this function is called that there is at least an entire second row
//
//////
// 	void iValidatePoint(SBitmapProcess* bp, s32 tnX, s32 tnY)
// 	{
// 		if (tnX >= bp->bii->biWidth)
// 			_asm nop;
// 
// 		if (tnY >= bp->bii->biHeight)
// 			_asm nop;
// 	}

	void iiBmp_scale_processSpannedPixel4(SBitmapProcess* bp)
	{
		s32 lnPixelY;


		// Repeat for each middle pixel
		for (lnPixelY = bp->middleStartV; lnPixelY <= bp->middleFinishV; lnPixelY++)
		{
			// Store the colors for this point
			if (bp->src->bi.biBitCount == 24)
			{
				// 24-bit bitmap
				(bp->pixels[bp->count]).red		= (f32)(((SBgr*)((u8*)bp->iptrAnchor - (lnPixelY * bp->src->rowWidth) + (bp->left * 3)))->red);
				(bp->pixels[bp->count]).grn		= (f32)(((SBgr*)((u8*)bp->iptrAnchor - (lnPixelY * bp->src->rowWidth) + (bp->left * 3)))->grn);
				(bp->pixels[bp->count]).blu		= (f32)(((SBgr*)((u8*)bp->iptrAnchor - (lnPixelY * bp->src->rowWidth) + (bp->left * 3)))->blu);
				(bp->pixels[bp->count]).area	= bp->widthLeft;

			} else {
				// 32-bit bitmap
				(bp->pixels[bp->count]).red		= (f32)(((SBgra*)((u8*)bp->iptrAnchora - (lnPixelY * bp->src->rowWidth) + (bp->left * 4)))->red);
				(bp->pixels[bp->count]).grn		= (f32)(((SBgra*)((u8*)bp->iptrAnchora - (lnPixelY * bp->src->rowWidth) + (bp->left * 4)))->grn);
				(bp->pixels[bp->count]).blu		= (f32)(((SBgra*)((u8*)bp->iptrAnchora - (lnPixelY * bp->src->rowWidth) + (bp->left * 4)))->blu);
				(bp->pixels[bp->count]).alp		= (f32)(((SBgra*)((u8*)bp->iptrAnchora - (lnPixelY * bp->src->rowWidth) + (bp->left * 4)))->alp);
				(bp->pixels[bp->count]).area	= bp->widthLeft;
			}

			// Move over for the next point
			++bp->count;
		}
	}




//////////
//
// 5 - middle-middle (see iGetSpannedPixelColors() above)
// It is known when this function is called that there is at least a second row, and at least
// one pixel in the middle
//
//////
	void iiBmp_scale_processSpannedPixel5(SBitmapProcess* bp)
	{
		s32 lnPixelY, lnPixelX;


		// Iterate for each pixel row vertically
		for (lnPixelY = bp->middleStartV; lnPixelY <= bp->middleFinishV; lnPixelY++)
		{
			// And each individual pixel horizontally
			for (lnPixelX = bp->middleStartH; lnPixelX <= bp->middleFinishH; lnPixelX++)
			{
				// Store the colors for this point
				if (bp->src->bi.biBitCount == 24)
				{
					// 24-bit bitmap
					(bp->pixels[bp->count]).red		= (f32)(((SBgr*)((u8*)bp->iptrAnchor - (lnPixelY * bp->src->rowWidth) + (lnPixelX * 3)))->red);
					(bp->pixels[bp->count]).grn		= (f32)(((SBgr*)((u8*)bp->iptrAnchor - (lnPixelY * bp->src->rowWidth) + (lnPixelX * 3)))->grn);
					(bp->pixels[bp->count]).blu		= (f32)(((SBgr*)((u8*)bp->iptrAnchor - (lnPixelY * bp->src->rowWidth) + (lnPixelX * 3)))->blu);
					(bp->pixels[bp->count]).area	= 1.0;

				} else {
					// 32-bit bitmap
					(bp->pixels[bp->count]).red		= (f32)(((SBgra*)((u8*)bp->iptrAnchora - (lnPixelY * bp->src->rowWidth) + (lnPixelX * 4)))->red);
					(bp->pixels[bp->count]).grn		= (f32)(((SBgra*)((u8*)bp->iptrAnchora - (lnPixelY * bp->src->rowWidth) + (lnPixelX * 4)))->grn);
					(bp->pixels[bp->count]).blu		= (f32)(((SBgra*)((u8*)bp->iptrAnchora - (lnPixelY * bp->src->rowWidth) + (lnPixelX * 4)))->blu);
					(bp->pixels[bp->count]).alp		= (f32)(((SBgra*)((u8*)bp->iptrAnchora - (lnPixelY * bp->src->rowWidth) + (lnPixelX * 4)))->alp);
					(bp->pixels[bp->count]).area	= 1.0;
				}

				// Move over for the next point
				++bp->count;
			}
		}
	}




//////////
//
// 6 - middle-right (see iGetSpannedPixelColors() above)
// It is known when this function is called that there is at least a second row, and a right pixel
//
//////
	void iiBmp_scale_processSpannedPixel6(SBitmapProcess* bp)
	{
		s32 lnPixelY;


		// Repeat for each middle pixel
		for (lnPixelY = bp->middleStartV; lnPixelY <= bp->middleFinishV; lnPixelY++)
		{
			// Store the colors for this point
			if (bp->src->bi.biBitCount == 24)
			{
				// 24-bit bitmap
				(bp->pixels[bp->count]).red		= (f32)(((SBgr*)((u8*)bp->iptrAnchor - (lnPixelY * bp->src->rowWidth) + (bp->right * 3)))->red);
				(bp->pixels[bp->count]).grn		= (f32)(((SBgr*)((u8*)bp->iptrAnchor - (lnPixelY * bp->src->rowWidth) + (bp->right * 3)))->grn);
				(bp->pixels[bp->count]).blu		= (f32)(((SBgr*)((u8*)bp->iptrAnchor - (lnPixelY * bp->src->rowWidth) + (bp->right * 3)))->blu);
				(bp->pixels[bp->count]).area	= bp->widthRight;

			} else {
				// 32-bit bitmap
				(bp->pixels[bp->count]).red		= (f32)(((SBgra*)((u8*)bp->iptrAnchora - (lnPixelY * bp->src->rowWidth) + (bp->right * 4)))->red);
				(bp->pixels[bp->count]).grn		= (f32)(((SBgra*)((u8*)bp->iptrAnchora - (lnPixelY * bp->src->rowWidth) + (bp->right * 4)))->grn);
				(bp->pixels[bp->count]).blu		= (f32)(((SBgra*)((u8*)bp->iptrAnchora - (lnPixelY * bp->src->rowWidth) + (bp->right * 4)))->blu);
				(bp->pixels[bp->count]).alp		= (f32)(((SBgra*)((u8*)bp->iptrAnchora - (lnPixelY * bp->src->rowWidth) + (bp->right * 4)))->alp);
				(bp->pixels[bp->count]).area	= bp->widthRight;
			}

			// Move over for the next point
			++bp->count;
		}
	}




//////////
//
// 7 - lower-left (see iGetSpannedPixelColors() above)
// It is known when this function is called that there is at least a second row
//
//////
	void iiBmp_scale_processSpannedPixel7(SBitmapProcess* bp)
	{
		// Compute the area
		bp->height	= bp->lry - (f32)((s32)bp->lry);
		bp->area	= bp->widthLeft * bp->height;

		// Store the colors for this point
		if (bp->src->bi.biBitCount == 24)
		{
			// 24-bit bitmap
			(bp->pixels[bp->count]).red		= (f32)(((SBgr*)((u8*)bp->iptrAnchor - ((bp->middleFinishV + 1) * bp->src->rowWidth) + (bp->left * 3)))->red);
			(bp->pixels[bp->count]).grn		= (f32)(((SBgr*)((u8*)bp->iptrAnchor - ((bp->middleFinishV + 1) * bp->src->rowWidth) + (bp->left * 3)))->grn);
			(bp->pixels[bp->count]).blu		= (f32)(((SBgr*)((u8*)bp->iptrAnchor - ((bp->middleFinishV + 1) * bp->src->rowWidth) + (bp->left * 3)))->blu);
			(bp->pixels[bp->count]).area	= bp->area;

		} else {
			// 32-bit bitmap
			(bp->pixels[bp->count]).red		= (f32)(((SBgra*)((u8*)bp->iptrAnchora - ((bp->middleFinishV + 1) * bp->src->rowWidth) + (bp->left * 4)))->red);
			(bp->pixels[bp->count]).grn		= (f32)(((SBgra*)((u8*)bp->iptrAnchora - ((bp->middleFinishV + 1) * bp->src->rowWidth) + (bp->left * 4)))->grn);
			(bp->pixels[bp->count]).blu		= (f32)(((SBgra*)((u8*)bp->iptrAnchora - ((bp->middleFinishV + 1) * bp->src->rowWidth) + (bp->left * 4)))->blu);
			(bp->pixels[bp->count]).alp		= (f32)(((SBgra*)((u8*)bp->iptrAnchora - ((bp->middleFinishV + 1) * bp->src->rowWidth) + (bp->left * 4)))->alp);
			(bp->pixels[bp->count]).area	= bp->area;
		}

		// Move over for the next point
		++bp->count;
	}




//////////
//
// 8 - lower-middle (see iGetSpannedPixelColors() above)
// It is known when this function is called that there is at least a second row, and at least one
// pixel in the middle
//
//////
	void iiBmp_scale_processSpannedPixel8(SBitmapProcess* bp)
	{
		s32 lnPixelX;


		// For every middle pixel, apply these values
		for (lnPixelX = bp->middleStartH; lnPixelX <= bp->middleFinishH; lnPixelX++)
		{
			// Store the colors for this point
			if (bp->src->bi.biBitCount == 24)
			{
				// 24-bit bitmap
				(bp->pixels[bp->count]).red		= (f32)(((SBgr*)((u8*)bp->iptrAnchor - ((bp->middleFinishV + 1) * bp->src->rowWidth) + (lnPixelX * 3)))->red);
				(bp->pixels[bp->count]).grn		= (f32)(((SBgr*)((u8*)bp->iptrAnchor - ((bp->middleFinishV + 1) * bp->src->rowWidth) + (lnPixelX * 3)))->grn);
				(bp->pixels[bp->count]).blu		= (f32)(((SBgr*)((u8*)bp->iptrAnchor - ((bp->middleFinishV + 1) * bp->src->rowWidth) + (lnPixelX * 3)))->blu);
				(bp->pixels[bp->count]).area	= bp->height;

			} else {
				// 32-bit bitmap
				(bp->pixels[bp->count]).red		= (f32)(((SBgra*)((u8*)bp->iptrAnchora - ((bp->middleFinishV + 1) * bp->src->rowWidth) + (lnPixelX * 4)))->red);
				(bp->pixels[bp->count]).grn		= (f32)(((SBgra*)((u8*)bp->iptrAnchora - ((bp->middleFinishV + 1) * bp->src->rowWidth) + (lnPixelX * 4)))->grn);
				(bp->pixels[bp->count]).blu		= (f32)(((SBgra*)((u8*)bp->iptrAnchora - ((bp->middleFinishV + 1) * bp->src->rowWidth) + (lnPixelX * 4)))->blu);
				(bp->pixels[bp->count]).alp		= (f32)(((SBgra*)((u8*)bp->iptrAnchora - ((bp->middleFinishV + 1) * bp->src->rowWidth) + (lnPixelX * 4)))->alp);
				(bp->pixels[bp->count]).area	= bp->height;
			}

			// Move over for the next point
			++bp->count;
		}
	}




//////////
//
// 9 - lower-right (see iGetSpannedPixelColors() above)
// It is known when this function is called that there is at least a second row, and a right pixel
//
//////
	void iiBmp_scale_processSpannedPixel9(SBitmapProcess* bp)
	{
		// Compute the area
		bp->area = bp->widthRight * bp->height;

		// Store the colors for this point
		if (bp->src->bi.biBitCount == 24)
		{
			// 24-bit bitmap
			(bp->pixels[bp->count]).red		= (f32)(((SBgr*)((u8*)bp->iptrAnchor - ((bp->middleFinishV + 1) * bp->src->rowWidth) + (bp->right * 3)))->red);
			(bp->pixels[bp->count]).grn		= (f32)(((SBgr*)((u8*)bp->iptrAnchor - ((bp->middleFinishV + 1) * bp->src->rowWidth) + (bp->right * 3)))->grn);
			(bp->pixels[bp->count]).blu		= (f32)(((SBgr*)((u8*)bp->iptrAnchor - ((bp->middleFinishV + 1) * bp->src->rowWidth) + (bp->right * 3)))->blu);
			(bp->pixels[bp->count]).area	= bp->area;

		} else {
			// 32-bit bitmap
			(bp->pixels[bp->count]).red		= (f32)(((SBgra*)((u8*)bp->iptrAnchora - ((bp->middleFinishV + 1) * bp->src->rowWidth) + (bp->right * 4)))->red);
			(bp->pixels[bp->count]).grn		= (f32)(((SBgra*)((u8*)bp->iptrAnchora - ((bp->middleFinishV + 1) * bp->src->rowWidth) + (bp->right * 4)))->grn);
			(bp->pixels[bp->count]).blu		= (f32)(((SBgra*)((u8*)bp->iptrAnchora - ((bp->middleFinishV + 1) * bp->src->rowWidth) + (bp->right * 4)))->blu);
			(bp->pixels[bp->count]).alp		= (f32)(((SBgra*)((u8*)bp->iptrAnchora - ((bp->middleFinishV + 1) * bp->src->rowWidth) + (bp->right * 4)))->alp);
			(bp->pixels[bp->count]).area	= bp->area;
		}

		// Move over for the next point
		++bp->count;
	}




//////////
//
// Integers between means which maximum integer is touched?
// Basically, chopping off decimals reveals the range, such that values of
// 1.001 and 2.999 only touch integers 1 and 2, even though with rounding
// they would go from 1 to 3.  Their numerical roots are in only integers
// 1 and 2.
//
//////
	u32 iiBmp_scale_processGetIntegersBetween(f32 p1, f32 p2)
	{
		u32 lfMin, lfMax;


		// Grab the integer values (without rounding)
		lfMin = (u32)min(p1,p2);
		lfMax = (u32)max(p1,p2);

		// Indicate the number between
		return(lfMax - lfMin);
	}
