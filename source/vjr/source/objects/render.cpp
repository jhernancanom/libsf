//////////
//
// /libsf/source/vjr/source/objects/render.cpp
//
//////
// Version 0.54
// Copyright (c) 2014 by Rick C. Hodgin
//////
// Last update:
//     Dec.18.2014
//////
// Change log:
//     Dec.18.2014 - Initial creation
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
// Renders an empty.  However, empty objects are not actually rendered.
// But they serve as placeholders for anything contained within.
//
//////
	u32 iSubobj_renderEmpty(SObject* empty)
	{
// 		SWindow*	win;
// 		SObject*	objRoot;


		logfunc(__FUNCTION__);
		//////////
		// Indicate we're no longer dirty, that we have everything rendered, but it needs publishing
		//////
			empty->isDirtyRender	= false;
			empty->isDirtyPublish	= true;
			return(0);		// Indicate that nothing was rendered which will affect the screen
	}




//////////
//
// Renders the form.
//
// Note:  The object rendering is independent of the publication of the constructed
//        bitmap.  The render operation only populates the bit buffer.  It will be
//        published at a later time, if indeed it is visible, however, it can after
//        rendering be re-directed to some other source, a disk file, or over a
//        network resource.
//
//////
	u32 iSubobj_renderForm(SObject* obj)
	{
		u32			lnPixelsRendered;
		RECT		lrc, lrc2;
		SBgra		backColor, borderColor, nwRgba, neRgba, swRgba, seRgba;
		SBitmap*	bmp;


		// Make sure our environment is sane
		logfunc(__FUNCTION__);
		lnPixelsRendered = 0;
		if (obj && obj->isRendered)
		{
			//////////
			// If we need re-rendering, re-render
			//////
				// The entire bmp
				SetRect(&lrc, 0, 0, obj->bmp->bi.biWidth, obj->bmp->bi.biHeight);

				// Do we need to redraw?  Or can we just copy?
				if (obj->isDirtyRender)
				{
					// Grab the colors
					borderColor = propBorderColor(obj);
					backColor	= propBackColor(obj);
					nwRgba		= propNwRgba(obj);
					neRgba		= propNeRgba(obj);
					swRgba		= propSwRgba(obj);
					seRgba		= propSeRgba(obj);

					//////////
					// Frame it
					//////
						if (!obj->bc || !iBmp_isValidCache(&obj->bc, nwRgba.color, neRgba.color, swRgba.color, seRgba.color, obj->rc.right - obj->rc.left, obj->rc.bottom - obj->rc.top, obj->bmp->bi.biWidth, obj->bmp->bi.biHeight, 0))
						{
							// The bitmap cache is no longer valid
							iBmp_deleteCache(&obj->bc);

							// Draw the window border
							if (propBorderStyle(obj) != _BORDER_STYLE_NONE)		iBmp_fillRect(obj->bmp, &lrc, nwRgba, neRgba, swRgba, seRgba, true, &obj->rcClient,	true);
							else												iBmp_fillRect(obj->bmp, &lrc, nwRgba, neRgba, swRgba, seRgba, true, NULL,			false);

							// Apply a dappling
							iBmp_dapple(obj->bmp, bmpDapple1, 215.0f, 3);

							// Save the cache
							iBmp_createCache(&obj->bc, obj->bmp, nwRgba.color, neRgba.color, swRgba.color, seRgba.color, obj->rc.right - obj->rc.left, obj->rc.bottom - obj->rc.top, obj->bmp->bi.biWidth, obj->bmp->bi.biHeight, 0, true);

						} else {
							// Copy everything over from the cache
							memcpy(obj->bmp->bd, obj->bc->bmpCached->bd, obj->bc->bmpCached->bi.biSizeImage);
						}

						// Frame it
						iBmp_frameRect(obj->bmp, &lrc, borderColor, borderColor, borderColor, borderColor, false, NULL, false);

						// Draw the client area
						bmp = bmpVjrIcon;
						SetRect(&lrc2, 8, bmp->bi.biHeight + 2, lrc.right - bmp->bi.biHeight - 2, lrc.bottom - bmp->bi.biHeight - 1);
						if (propBackStyle(obj) == _BACK_STYLE_OPAQUE)
							iBmp_fillRect(obj->bmp, &lrc2, backColor, backColor, backColor, backColor, false, NULL, false);

						// Put a border around the client area
						if (propBorderStyle(obj) != _BORDER_STYLE_NONE)
						{
							InflateRect(&lrc2, 1, 1);
							iBmp_frameRect(obj->bmp, &lrc2, borderColor, borderColor, borderColor, borderColor, false, NULL, false);
						}


					//////////
					// Copy to prior rendered bitmap
					//////
						// Make sure our bmpPriorRendered exists
						obj->bmpPriorRendered = iBmp_verifyCopyIsSameSize(obj->bmpPriorRendered, obj->bmp);

						// Copy to the prior rendered version
						memcpy(obj->bmpPriorRendered->bd, obj->bmp->bd, obj->bmpPriorRendered->bi.biSizeImage);
						// Right now, we can use the bmpPriorRendered for a fast copy rather than 

				} else {
					// Render from its prior rendered version
					lnPixelsRendered += iBmp_bitBlt(obj->bmp, &lrc, obj->bmpPriorRendered);
				}


			//////////
			// Indicate we're no longer dirty, that we have everything rendered, but it needs publishing
			//////
				obj->isDirtyRender	= false;
				obj->isDirtyPublish	= true;
		}


		// Indicate how many pixels were drawn
		return(lnPixelsRendered);
	}




//////////
//
// Renders the subform.
//
//////
	u32 iSubobj_renderSubform(SObject* obj)
	{
		u32		lnPixelsRendered;
		bool	llIsFocusSubform;
		SBgra	backColor, borderColor, nwRgba, neRgba, swRgba, seRgba;
		RECT	lrc, lrc2;


		// Make sure our environment is sane
		logfunc(__FUNCTION__);
		lnPixelsRendered = 0;
		if (obj && obj->isRendered && obj->rc.right > 0 && obj->rc.bottom > 0 && obj->rc.right >= obj->rc.left && obj->rc.bottom >= obj->rc.bottom && obj->rc.right - obj->rc.left < 4400 && obj->rc.bottom - obj->rc.top < 4400)
		{
			// Grab our colors
			backColor	= propBackColor(obj);
			borderColor	= propBorderColor(obj);
			nwRgba		= propNwRgba(obj);
			neRgba		= propNeRgba(obj);
			swRgba		= propSwRgba(obj);
			seRgba		= propSeRgba(obj);

			//////////
			// If we need re-rendering, re-render
			//////
				// The entire bmp
				SetRect(&lrc, 0, 0, obj->bmp->bi.biWidth, obj->bmp->bi.biHeight);

				// Do we need to redraw?  Or can we just copy?
				if (obj->isDirtyRender)
				{
					//////////
					// Frame it
					//////
						// Determine if a control on this subform has focus
						llIsFocusSubform = iObj_focus_descentCheck(obj, true, false);
						if (!obj->bc || !iBmp_isValidCache(&obj->bc, nwRgba.color, neRgba.color, swRgba.color, seRgba.color, obj->rc.right - obj->rc.left, obj->rc.bottom - obj->rc.top, obj->bmp->bi.biWidth, obj->bmp->bi.biHeight, (u32)llIsFocusSubform))
						{
							// The bitmap cache is no longer valid
							iBmp_deleteCache(&obj->bc);

							// Draw the window border
							if (propBackStyle(obj) == _BACK_STYLE_OPAQUE)
							{
								// Render the subform and client area
								if (llIsFocusSubform)		iBmp_fillRect(obj->bmp, &lrc, NwFocusColor,		NeFocusColor,	SwFocusColor,	SeFocusColor,	true, &obj->rcClient,	true);
								else						iBmp_fillRect(obj->bmp, &lrc, nwRgba,			neRgba,			swRgba,			seRgba,			true, &obj->rcClient,	true);

								// Make the client area white
								iBmp_fillRect(obj->bmp, &obj->rcClient, backColor, backColor, backColor, backColor, false, NULL, false);

							} else {
								// Render the subform
								if (llIsFocusSubform)		iBmp_fillRect(obj->bmp, &lrc, NwFocusColor,		NeFocusColor,	SwFocusColor,	SeFocusColor,	true, NULL, false);
								else						iBmp_fillRect(obj->bmp, &lrc, nwRgba,			neRgba,			swRgba,			seRgba,			true, NULL, false);
							}

							// Apply a dappling
							iBmp_dapple(obj->bmp, bmpDapple2, 225.0f, 3);

							// Save the cache
							iBmp_createCache(&obj->bc, obj->bmp, nwRgba.color, neRgba.color, swRgba.color, seRgba.color, obj->rc.right - obj->rc.left, obj->rc.bottom - obj->rc.top, obj->bmp->bi.biWidth, obj->bmp->bi.biHeight, (u32)llIsFocusSubform, true);

						} else {
							// Copy everything over from the cache
							memcpy(obj->bmp->bd, obj->bc->bmpCached->bd, obj->bc->bmpCached->bi.biSizeImage);
						}

						// Frame the client area
						if (propBorderStyle(obj) != _BORDER_STYLE_NONE)
						{
							CopyRect(&lrc2, &obj->rcClient);
							InflateRect(&lrc2, 1, 1);
							iBmp_frameRect(obj->bmp, &lrc2,	borderColor, borderColor, borderColor, borderColor, false, NULL, false);
							iBmp_frameRect(obj->bmp, &lrc,	borderColor, borderColor, borderColor, borderColor, false, NULL, false);
						}


					//////////
					// Copy to prior rendered bitmap
					//////
						// Make sure our bmpPriorRendered exists
						obj->bmpPriorRendered = iBmp_verifyCopyIsSameSize(obj->bmpPriorRendered, obj->bmp);

						// Copy to the prior rendered version
						memcpy(obj->bmpPriorRendered->bd, obj->bmp->bd, obj->bmpPriorRendered->bi.biSizeImage);
						// Right now, we can use the bmpPriorRendered for a fast copy rather than 

				} else {
					// Render from its prior rendered version
					lnPixelsRendered += iBmp_bitBlt(obj->bmp, &lrc, obj->bmpPriorRendered);
				}


			//////////
			// Indicate we're no longer dirty, that we have everything rendered, but it needs publishing
			//////
				obj->isDirtyRender = false;
				obj->isDirtyPublish	= true;
		}

		// Indicate how many pixels were drawn
		return(lnPixelsRendered);
	}




//////////
//
// Renders the carousel.  Note that carousels are not normally displayed.  The only time
// they'll be displayed by their rendered nature below is if they do not possess any riders.
//
//////
	u32 iSubobj_renderCarousel(SObject* obj)
	{
		u32			lnPixelsRendered;
		bool		llIsFocusCarousel;
		SBgra		nwRgba, neRgba, swRgba, seRgba;
		RECT		lrc;
		SObject*	objFocus;


		// Make sure our environment is sane
		logfunc(__FUNCTION__);
		lnPixelsRendered = 0;
		if (obj && obj->isRendered)
		{
			//////////
			// If we need re-rendering, re-render
			//////
				// The entire bmp
				SetRect(&lrc, 0, 0, obj->bmp->bi.biWidth, obj->bmp->bi.biHeight);

				// Re-render
				if (obj->isDirtyRender)
				{
					// Grab colors
					nwRgba = propNwRgba(obj);
					neRgba = propNeRgba(obj);
					swRgba = propSwRgba(obj);
					seRgba = propSeRgba(obj);


					//////////
					// Frame it
					//////
						// Determine if a control on this subform has focus
						objFocus			= iObj_focus_descentCheckObj(obj, true, false);
						llIsFocusCarousel	= (objFocus != NULL);
						if (!obj->bc || !iBmp_isValidCache(&obj->bc, nwRgba.color, neRgba.color, swRgba.color, seRgba.color, obj->rc.right - obj->rc.left, obj->rc.bottom - obj->rc.top, obj->bmp->bi.biWidth, obj->bmp->bi.biHeight, (u32)llIsFocusCarousel))
						{
							// The bitmap cache is no longer valid
							iBmp_deleteCache(&obj->bc);

							// Draw the default background
							if (llIsFocusCarousel)		iBmp_fillRect(obj->bmp, &lrc, NwFocusColor,		NeFocusColor,	SwFocusColor,	SeFocusColor,	true, NULL, false);
							else						iBmp_fillRect(obj->bmp, &lrc, nwRgba,			neRgba,			swRgba,			seRgba,			true, NULL, false);

							// Apply a dappling
							iBmp_dapple(obj->bmp, bmpDapple2, 225.0f, 3);

							// Save the cache
							iBmp_createCache(&obj->bc, obj->bmp, nwRgba.color, neRgba.color, swRgba.color, seRgba.color, obj->rc.right - obj->rc.left, obj->rc.bottom - obj->rc.top, obj->bmp->bi.biWidth, obj->bmp->bi.biHeight, (u32)llIsFocusCarousel, true);

						} else {
							// Copy everything over from the cache
							memcpy(obj->bmp->bd, obj->bc->bmpCached->bd, obj->bc->bmpCached->bi.biSizeImage);
						}


					//////////
					// Copy to prior rendered bitmap
					//////
						// Make sure our bmpPriorRendered exists
						obj->bmpPriorRendered = iBmp_verifyCopyIsSameSize(obj->bmpPriorRendered, obj->bmp);

						// Copy to the prior rendered version
						memcpy(obj->bmpPriorRendered->bd, obj->bmp->bd, obj->bmpPriorRendered->bi.biSizeImage);
						// Right now, we can use the bmpPriorRendered for a fast copy rather than 

				} else {
					// Render from its prior rendered version
					lnPixelsRendered += iBmp_bitBlt(obj->bmp, &lrc, obj->bmpPriorRendered);
				}


			//////////
			// Indicate we're no longer dirty, that we have everything rendered, but it needs publishing
			//////
				obj->isDirtyRender = false;
				obj->isDirtyPublish	= true;
		}

		// Indicate status
		return(lnPixelsRendered);
	}




//////////
//
// Renders the rider.
//
//////
	u32 iSubobj_renderRider(SObject* obj)
	{
		u32		lnPixelsRendered;
		RECT	lrc;


		// Make sure our environment is sane
		logfunc(__FUNCTION__);
		lnPixelsRendered = 0;
		if (obj && obj->isRendered)
		{
			if (obj->isDirtyRender)
			{
				//////////
				// Fill in the background
				//////
					SetRect(&lrc, 0, 0, obj->bmp->bi.biWidth, obj->bmp->bi.biHeight);
					iBmp_fillRect(obj->bmp, &lrc, whiteColor, whiteColor, whiteColor, whiteColor, false, NULL, false);


				//////////
				// Copy to prior rendered bitmap
				//////
					// Make sure our bmpPriorRendered exists
					obj->bmpPriorRendered = iBmp_verifyCopyIsSameSize(obj->bmpPriorRendered, obj->bmp);

					// Copy to the prior rendered version
					memcpy(obj->bmpPriorRendered->bd, obj->bmp->bd, obj->bmpPriorRendered->bi.biSizeImage);
					// Right now, we can use the bmpPriorRendered for a fast copy rather than 

			} else {
				// Render from its prior rendered version
				lnPixelsRendered += iBmp_bitBlt(obj->bmp, &lrc, obj->bmpPriorRendered);
			}


			// Indicate we're no longer dirty, that we have everything rendered, but it needs publishing
			obj->isDirtyRender = false;
			obj->isDirtyPublish	= true;
		}

		// Indicate status
		return(lnPixelsRendered);
	}




//////////
//
// Renders the label.
//
//////
	u32 iSubobj_renderLabel(SObject* obj)
	{
		s32			backStyle;
		u32			lnPixelsRendered, lnFormat;
		SBgra		backColor, foreColor, borderColor;
		SVariable*	caption;
		SVariable*	value;
		RECT		lrc, lrc2;


		// Make sure our environment is sane
		logfunc(__FUNCTION__);
		lnPixelsRendered = 0;
		if (obj && obj->isRendered)
		{
			if (obj->isDirtyRender)
			{
				borderColor	= propBorderColor(obj);
				backColor	= propBackColor(obj);
				foreColor	= propForeColor(obj);
				backStyle	= propBackStyle(obj);
				if (backStyle == _BACK_STYLE_OPAQUE)
				{
					// Use the back color
					SetBkColor(obj->bmp->hdc,	RGB(backColor.red, backColor.grn, backColor.blu));
					SetTextColor(obj->bmp->hdc,	RGB(foreColor.red, foreColor.grn, foreColor.blu));

				} else {
					// Use a black and white creation
					SetBkColor(obj->bmp->hdc, RGB(255,255,255));
					SetTextColor(obj->bmp->hdc, RGB(0,0,0));
				}

				// Fill in the background
				SetRect(&lrc, 0, 0, obj->bmp->bi.biWidth, obj->bmp->bi.biHeight);
				iBmp_fillRect(obj->bmp, &lrc, whiteColor, whiteColor, whiteColor, whiteColor, false, NULL, false);

				// Set the text parameters
				SetBkMode(obj->bmp->hdc, TRANSPARENT);
				SelectObject(obj->bmp->hdc, obj->p.font->hfont);

				// Determine our orientation
				switch (propAlignment(obj))
				{
					default:
					case _ALIGNMENT_LEFT:
						lnFormat = DT_LEFT;
						break;

					case _ALIGNMENT_RIGHT:
						lnFormat = DT_RIGHT;
						break;

					case _ALIGNMENT_CENTER:
						lnFormat = DT_CENTER;
						break;
				}

				// Copy the rectangle
				CopyRect(&lrc2, &lrc);

				// Adjust if need be
				if (obj->parent && obj->parent->objType == _OBJ_TYPE_CHECKBOX)
					lrc.left += 4;

				// Draw the text
				caption = iObjProp_get_variable_byIndex(obj, _INDEX_CAPTION);
				value	= iObjProp_get_variable_byIndex(obj, _INDEX_VALUE);
				DrawText(obj->bmp->hdc, caption->value.data, caption->value.length, &lrc, lnFormat | DT_VCENTER | DT_END_ELLIPSIS);

				// And adjust back if need be
				if (obj->parent && obj->parent->objType == _OBJ_TYPE_CHECKBOX)
					lrc.left -= 4;

				// Frame rectangle
				if (propBorderStyle(obj) != _BORDER_STYLE_NONE)
					iBmp_frameRect(obj->bmp, &lrc, borderColor, borderColor, borderColor, borderColor, false, NULL, false);

				// For checkbox labels, we handle them differently
				if (obj->parent && obj->parent->objType == _OBJ_TYPE_CHECKBOX)
				{
					// Append the color marker at the end of the label
					SetRect(&lrc2, lrc.right - ((lrc.bottom - lrc.top) / 2), 0, lrc.right, lrc.bottom);
					if (get_s32(value) == 0)
					{
						// It's off, so color it red
						iBmp_fillRect(obj->bmp, &lrc2, NwCheckboxOffColor, NeCheckboxOffColor, SwCheckboxOffColor, SeCheckboxOffColor, true, NULL, false);

					} else {
						// It's on, so color it green
						iBmp_fillRect(obj->bmp, &lrc2, NwCheckboxOnColor, NeCheckboxOnColor, SwCheckboxOnColor, SeCheckboxOnColor, true, NULL, false);
					}

					// Colorize the area
					SetRect(&lrc2, lrc.left, lrc.top, lrc.right - ((lrc.bottom - lrc.top) / 2), lrc.bottom);
					     if (obj->ev.mouse.isMouseDown)		iBmp_colorize(obj->bmp, &lrc2, colorMouseDown,	false, 0.0f);
					else if (obj->ev.mouse.isMouseOver)		iBmp_colorize(obj->bmp, &lrc2, colorMouseOver,	false, 0.0f);

				} else if (backStyle == _BACK_STYLE_OPAQUE) {
					// Colorize the area
					     if (obj->ev.mouse.isMouseDown)		iBmp_colorize(obj->bmp, &lrc, colorMouseDown,	false, 0.0f);
					else if (obj->ev.mouse.isMouseOver)		iBmp_colorize(obj->bmp, &lrc, colorMouseOver,	false, 0.0f);
				}


				//////////
				// Copy to prior rendered bitmap
				//////
					// Make sure our bmpPriorRendered exists
					obj->bmpPriorRendered = iBmp_verifyCopyIsSameSize(obj->bmpPriorRendered, obj->bmp);

					// Copy to the prior rendered version
					memcpy(obj->bmpPriorRendered->bd, obj->bmp->bd, obj->bmpPriorRendered->bi.biSizeImage);
					// Right now, we can use the bmpPriorRendered for a fast copy rather than 

			} else {
				// Render from its prior rendered version
				lnPixelsRendered += iBmp_bitBlt(obj->bmp, &lrc, obj->bmpPriorRendered);
			}


			// Indicate we're no longer dirty, that we have everything rendered, but it needs publishing
			obj->isDirtyRender = false;
			obj->isDirtyPublish	= true;
		}

		// Indicate status
		return(lnPixelsRendered);
	}




//////////
//
// Renders the textbox.
//
//////
	u32 iSubobj_renderTextbox(SObject* obj)
	{
		u32			lnPixelsRendered, lnFormat;
		SBgra		backColor, foreColor, borderColor;
		SVariable*	value;
		RECT		lrc, lrc2;


		// Make sure our environment is sane
		logfunc(__FUNCTION__);
		lnPixelsRendered = 0;
		if (obj && obj->isRendered)
		{
			if (obj->isDirtyRender)
			{
				// Fill in the background
				SetRect(&lrc, 0, 0, obj->bmp->bi.biWidth, obj->bmp->bi.biHeight);
				iiBmp_frameInNineParts(obj->bmp, &lrc, bmpTextbox);

				// Grab the colors
				backColor	= propBackColor(obj);
				foreColor	= propForeColor(obj);
				borderColor	= propBorderColor(obj);

				// Colorize
				     if (obj->ev.mouse.isMouseDown)		iBmp_colorize(obj->bmp, &lrc, colorMouseDown,		false, 0.0f);
				else if (obj->ev.mouse.isMouseOver)		iBmp_colorize(obj->bmp, &lrc, colorMouseOver,		false, 0.0f);
				else									iBmp_colorize(obj->bmp, &lrc, propBackColor(obj),	false, 0.0f);

				// Inset slightly for the text part
				CopyRect(&lrc2, &lrc);
				InflateRect(&lrc2, -4, -4);

				// If we're opaque, draw the text inset by a margin, otherwise just overlay
				if (propBackStyle(obj) == _BACK_STYLE_OPAQUE)
				{
					// Opaque
					SetBkColor(obj->bmp->hdc, RGB(backColor.red, backColor.grn, backColor.blu));
					SetBkMode(obj->bmp->hdc, OPAQUE);

				} else {
					// Transparent
					SetBkMode(obj->bmp->hdc, TRANSPARENT);
				}

				// Set the text parameters
				SetTextColor(obj->bmp->hdc, RGB(foreColor.red, foreColor.grn, foreColor.blu));
				SelectObject(obj->bmp->hdc, obj->p.font->hfont);

				// Determine our orientation
				switch (propAlignment(obj))
				{
					default:
					case _ALIGNMENT_LEFT:
						lnFormat = DT_LEFT;
						break;

					case _ALIGNMENT_RIGHT:
						lnFormat = DT_RIGHT;
						break;

					case _ALIGNMENT_CENTER:
						lnFormat = DT_CENTER;
						break;
				}

				// Draw the text
				value = iObjProp_get_variable_byIndex(obj, _INDEX_VALUE);
				DrawText(obj->bmp->hdc, value->value.data, value->value.length, &lrc2, lnFormat | DT_VCENTER | DT_END_ELLIPSIS);

				// Frame rectangle
				if (propBorderStyle(obj) != _BORDER_STYLE_NONE)
					iBmp_frameRect(obj->bmp, &lrc, borderColor, borderColor, borderColor, borderColor, false, NULL, false);


				//////////
				// Copy to prior rendered bitmap
				//////
					// Make sure our bmpPriorRendered exists
					obj->bmpPriorRendered = iBmp_verifyCopyIsSameSize(obj->bmpPriorRendered, obj->bmp);

					// Copy to the prior rendered version
					memcpy(obj->bmpPriorRendered->bd, obj->bmp->bd, obj->bmpPriorRendered->bi.biSizeImage);
					// Right now, we can use the bmpPriorRendered for a fast copy rather than 

			} else {
				// Render from its prior rendered version
				lnPixelsRendered += iBmp_bitBlt(obj->bmp, &lrc, obj->bmpPriorRendered);
			}


			// Indicate we're no longer dirty, that we have everything rendered, but it needs publishing
			obj->isDirtyRender = false;
			obj->isDirtyPublish	= true;
		}

		// Indicate status
		return(lnPixelsRendered);
	}




//////////
//
// Renders the button.
//
//////
	u32 iSubobj_renderButton(SObject* obj)
	{
		u32			lnPixelsRendered, lnFormat;
		SBgra		backColor, foreColor, borderColor;
		SVariable*	caption;
		RECT		lrc, lrc2;


		// Make sure our environment is sane
		logfunc(__FUNCTION__);
		lnPixelsRendered = 0;
		if (obj && obj->isRendered)
		{
			if (obj->isDirtyRender)
			{
				// Fill in the background
				SetRect(&lrc, 0, 0, obj->bmp->bi.biWidth, obj->bmp->bi.biHeight);
				iiBmp_frameInNineParts(obj->bmp, &lrc, bmpButton);

				// Get the colors
				backColor	= propBackColor(obj);
				foreColor	= propForeColor(obj);
				borderColor	= propBorderColor(obj);

				// Colorize
				     if (obj->ev.mouse.isMouseDown)		iBmp_colorize(obj->bmp, &lrc, colorMouseDown,		false, 0.0f);
				else if (obj->ev.mouse.isMouseOver)		iBmp_colorize(obj->bmp, &lrc, colorMouseOver,		false, 0.0f);
				else									iBmp_colorize(obj->bmp, &lrc, propBackColor(obj),	false, 0.0f);

				// Inset slightly for the text part
				CopyRect(&lrc2, &lrc);
				InflateRect(&lrc2, -4, -4);

				// If we're opaque, draw the text inset by a margin, otherwise just overlay
				if (propBackStyle(obj) == _BACK_STYLE_OPAQUE)
				{
					// Opaque
					SetBkColor(obj->bmp->hdc, RGB(backColor.red, backColor.grn, backColor.blu));
					SetBkMode(obj->bmp->hdc, OPAQUE);

				} else {
					// Transparent
					SetBkMode(obj->bmp->hdc, TRANSPARENT);
				}

				// Set the text parameters
				SetTextColor(obj->bmp->hdc, RGB(foreColor.red, foreColor.grn, foreColor.blu));
				SelectObject(obj->bmp->hdc, obj->p.font->hfont);

				// Determine our orientation
				switch (propAlignment(obj))
				{
					default:
					case _ALIGNMENT_LEFT:
						lnFormat = DT_LEFT;
						break;

					case _ALIGNMENT_RIGHT:
						lnFormat = DT_RIGHT;
						break;

					case _ALIGNMENT_CENTER:
						lnFormat = DT_CENTER;
						break;
				}

				// Draw the text
				caption = iObjProp_get_variable_byIndex(obj, _INDEX_CAPTION);
				DrawText(obj->bmp->hdc, caption->value.data, caption->value.length, &lrc2, lnFormat | DT_VCENTER | DT_END_ELLIPSIS);

				// Frame rectangle
				if (propBorderStyle(obj) != _BORDER_STYLE_NONE)
					iBmp_frameRect(obj->bmp, &lrc, borderColor, borderColor, borderColor, borderColor, false, NULL, false);


				//////////
				// Copy to prior rendered bitmap
				//////
					// Make sure our bmpPriorRendered exists
					obj->bmpPriorRendered = iBmp_verifyCopyIsSameSize(obj->bmpPriorRendered, obj->bmp);

					// Copy to the prior rendered version
					memcpy(obj->bmpPriorRendered->bd, obj->bmp->bd, obj->bmpPriorRendered->bi.biSizeImage);
					// Right now, we can use the bmpPriorRendered for a fast copy rather than 

			} else {
				// Render from its prior rendered version
				lnPixelsRendered += iBmp_bitBlt(obj->bmp, &lrc, obj->bmpPriorRendered);
			}


			// Indicate we're no longer dirty, that we have everything rendered, but it needs publishing
			obj->isDirtyRender = false;
			obj->isDirtyPublish	= true;
		}

		// Indicate status
		return(lnPixelsRendered);
	}




//////////
//
// Renders the editbox.
//
//////
	u32 iSubobj_renderEditbox(SObject* obj)
	{
		u32		lnPixelsRendered;
		SBgra	borderColor;
		RECT	lrc;


		// Make sure our environment is sane
		logfunc(__FUNCTION__);
		lnPixelsRendered = 0;
		if (obj && obj->isRendered)
		{
			// Grab the rectangle
			iSEM_getRectAndFont(obj->p.sem, obj, &lrc);

			// Are we rendering?
			if (obj->isDirtyRender)
			{
				// Re-render
				lnPixelsRendered = iSEM_render(obj->p.sem, obj, obj->p.hasFocus);

				// Get colors
				borderColor = propBorderColor(obj);

				if (propBorderStyle(obj) != _BORDER_STYLE_NONE)
					iBmp_frameRect(obj->bmp, &lrc, borderColor, borderColor, borderColor, borderColor, false, NULL, false);

				//////////
				// Copy to prior rendered bitmap
				//////
					// Make sure our bmpPriorRendered exists
					obj->bmpPriorRendered = iBmp_verifyCopyIsSameSize(obj->bmpPriorRendered, obj->bmp);

					// Copy to the prior rendered version
					memcpy(obj->bmpPriorRendered->bd, obj->bmp->bd, obj->bmpPriorRendered->bi.biSizeImage);
					// Right now, we can use the bmpPriorRendered for a fast copy rather than 

			} else {
				// Render from its prior rendered version
				lnPixelsRendered += iBmp_bitBlt(obj->bmp, &lrc, obj->bmpPriorRendered);
			}


			// Indicate we're no longer dirty, that we have everything rendered, but it needs publishing
			obj->isDirtyRender = false;
			obj->isDirtyPublish	= true;
		}

		// Indicate status
		return(lnPixelsRendered);
	}




//////////
//
// Renders the image.
//
//////
	u32 iSubobj_renderImage(SObject* obj)
	{
		u32			lnPixelsRendered;
		SBitmap*	bmp;
		RECT		lrc;


		// Make sure our environment is sane
		logfunc(__FUNCTION__);
		lnPixelsRendered = 0;
		if (obj && obj->isRendered)
		{
			// Compute our rectangle for drawing
			SetRect(&lrc, 0, 0, obj->bmp->bi.biWidth, obj->bmp->bi.biHeight);
			if (obj->isDirtyRender)
			{
				// Based on the current conditions, render the appropriate image
				if (obj->ev.mouse.isMouseDown)
				{
					// Mouse is down on this item
					bmp = iObjProp_get_bitmap(obj, _INDEX_PICTUREBMP_DOWN);

				} else if (obj->ev.mouse.isMouseOver) {
					// Mouse is over this item
					bmp = iObjProp_get_bitmap(obj, _INDEX_PICTUREBMP_OVER);

				} else {
					// Render normally
					bmp = iObjProp_get_bitmap(obj, _INDEX_PICTUREBMP);
				}

				// Render it
				lnPixelsRendered += iBmp_bitBlt(obj->bmp, &lrc, bmp);

				// For checkbox images, we colorize them differently
				if (obj->parent && obj->parent->objType == _OBJ_TYPE_CHECKBOX)
				{
					// Colorize
						 if (obj->ev.mouse.isMouseDown)		iBmp_colorize(obj->bmp, &lrc, colorMouseDown,	false, 0.0f);
					else if (obj->ev.mouse.isMouseOver)		iBmp_colorize(obj->bmp, &lrc, colorMouseOver,	false, 0.0f);
				}


				//////////
				// Copy to prior rendered bitmap
				//////
					// Make sure our bmpPriorRendered exists
					obj->bmpPriorRendered = iBmp_verifyCopyIsSameSize(obj->bmpPriorRendered, obj->bmp);

					// Copy to the prior rendered version
					memcpy(obj->bmpPriorRendered->bd, obj->bmp->bd, obj->bmpPriorRendered->bi.biSizeImage);
					// Right now, we can use the bmpPriorRendered for a fast copy rather than 

			} else {
				// Render from its prior rendered version
				lnPixelsRendered += iBmp_bitBlt(obj->bmp, &lrc, obj->bmpPriorRendered);
			}

			// Indicate we're no longer dirty, that we have everything rendered, but it needs publishing
			obj->isDirtyRender = false;
			obj->isDirtyPublish	= true;
		}

		// Indicate status
		return(lnPixelsRendered);
	}




//////////
//
// Renders the logical checkbox control.  The checkbox is not actually rendered, but
// rather it reads from the parent whatever is underneath its rectangle at the point
// of the render request, then it draws the child objects atop itself.
//
//////
	u32 iSubobj_renderCheckbox(SObject* obj)
	{
		u32		lnPixelsRendered;
		RECT	lrc;


		// Make sure our environment is sane
		logfunc(__FUNCTION__);
		lnPixelsRendered = 0;
		if (obj && obj->isRendered)
		{
			// Compute our rectangle for drawing
			SetRect(&lrc, 0, 0, obj->bmp->bi.biWidth, obj->bmp->bi.biHeight);

			// There is nothing actually rendered here, but the child renders into it
			if (obj->isDirtyRender)
			{
				//////////
				// Copy to prior rendered bitmap
				//////
					// Make sure our bmpPriorRendered exists
					obj->bmpPriorRendered = iBmp_verifyCopyIsSameSize(obj->bmpPriorRendered, obj->bmp);

					// Copy to the prior rendered version
					memcpy(obj->bmpPriorRendered->bd, obj->bmp->bd, obj->bmpPriorRendered->bi.biSizeImage);
					// Right now, we can use the bmpPriorRendered for a fast copy rather than 

			} else {
				// Render from its prior rendered version
				lnPixelsRendered += iBmp_bitBlt(obj->bmp, &lrc, obj->bmpPriorRendered);
			}

			// Indicate we're no longer dirty, that we have everything rendered, but it needs publishing
			obj->isDirtyRender = false;
			obj->isDirtyPublish	= true;
		}

		// Indicate status
		return(lnPixelsRendered);
	}




//////////
//
// Renders the option.
//
//////
	u32 iSubobj_renderOption(SObject* obj)
	{
		logfunc(__FUNCTION__);


			//////////
			// Indicate we're no longer dirty, that we have everything
			//////
				obj->isDirtyRender = false;
		return(0);
	}




//////////
//
// Renders the radio.
//
//////
	u32 iSubobj_renderRadio(SObject* obj)
	{
		u32			lnPixelsRendered, lnXCenter, lnYCenter, lnSkip;
		f32			lfTheta, lfRadius;
		f64			lfValue, lfMin, lfMax;
		SBitmap*	bmpRadioScale;
		SBgra		foreColor;
		RECT		lrc, lrc2;
		s8*			lcSprintfFormat;
		s8			buffer[64];


		// Make sure our environment is sane
		logfunc(__FUNCTION__);
		lnPixelsRendered = 0;
		if (obj && obj->isRendered)
		{
			// Compute our rectangle for drawing
			SetRect(&lrc, 0, 0, obj->bmp->bi.biWidth, obj->bmp->bi.biHeight);

			if (obj->isDirtyRender)
			{
				//////////
				// Get the values
				//////
					lfValue	= iObjProp_get_f64_direct(obj, _INDEX_VALUE);
					lfMin	= iObjProp_get_f64_direct(obj, _INDEX_VALUE_MINIMUM);
					lfMax	= iObjProp_get_f64_direct(obj, _INDEX_VALUE_MAXIMUM);

					// Make sure max is greater than or equal to min, and value is in range
					lfMax	= max(lfMin, lfMax);
					lfValue	= min(max(lfValue, lfMin), lfMax);

					// Determine the percentage
					lfTheta	= (f32)((lfValue - lfMin) / (lfMax - lfMin)) * (f32)(M_PI * 2.0);

					// Color
					foreColor = propForeColor(obj);


				//////////
				// Determine the scaling ratio for the dial indicator
				//////
					// Create a copy for later scaling
					bmpRadioScale = iBmp_allocate();
					iBmp_createBySize(bmpRadioScale, bmpRadio->bi.biWidth, bmpRadio->bi.biHeight, 24);
					bmpRadioScale = iBmp_copy(bmpRadio);


				//////////
				// Compute the position the dial indicator based on settings, and build the lrc2 on it
				//////
					lfRadius	= (f32)bmpRadioScale->bi.biWidth * 0.225f;
					lnXCenter	= (u32)(((f32)bmpRadioScale->bi.biWidth  / 2.0f));
					lnYCenter	= (u32)(((f32)bmpRadioScale->bi.biHeight / 2.0f));

					// Build the rect
					SetRect(&lrc2,	(u32)(lnXCenter + (lfRadius * cos(lfTheta)) - (bmpRadioDot->bi.biWidth / 2)),
									(u32)(lnYCenter - (lfRadius * sin(lfTheta)) - (bmpRadioDot->bi.biHeight / 2)),
									0, 0);
					
					lrc2.right	= lrc2.left	+ bmpRadioDot->bi.biWidth;
					lrc2.bottom	= lrc2.top	+ bmpRadioDot->bi.biHeight;
					iBmp_bitBltMask(bmpRadioScale, &lrc2, bmpRadioDot);


				// Scale the base into it
				iBmp_scale(obj->bmp, bmpRadioScale);

				// Delete the scaled dot
				iBmp_delete(&bmpRadioScale, true, true);


				//////////
				// Draw the text of the value into the center
				//////
					lcSprintfFormat = iMath_roundTo(&lfValue, iObjProp_get_f64_direct(obj, _INDEX_ROUND_TO));
					sprintf(buffer, lcSprintfFormat, lfValue);

					if (buffer[strlen(buffer)] == '.')
						buffer[strlen(buffer)] = 0;

					lnSkip = iSkipWhitespaces(buffer, (u32)strlen(buffer));

					SetRect(&lrc2,	obj->bmp->bi.biWidth / 7,
									(obj->bmp->bi.biHeight / 2) - (obj->bmp->bi.biHeight / 7),
									obj->bmp->bi.biWidth * 6 / 7,
									(obj->bmp->bi.biHeight / 2) + (obj->bmp->bi.biHeight / 7));
					
					SetTextColor(obj->bmp->hdc, RGB(foreColor.red, foreColor.grn, foreColor.blu));
					SetBkMode(obj->bmp->hdc, TRANSPARENT);
					SelectObject(obj->bmp->hdc, ((obj->p.font) ? obj->p.font : gsFontDefault));
					DrawText(obj->bmp->hdc, buffer + lnSkip, (int)strlen(buffer + lnSkip), &lrc2, DT_CENTER | DT_SINGLELINE | DT_VCENTER);


				// Colorize
				     if (obj->ev.mouse.isMouseDown)		iBmp_colorize(obj->bmp, &lrc, colorMouseDown,	false, 0.0f);
				else if (obj->ev.mouse.isMouseOver)		iBmp_colorize(obj->bmp, &lrc, colorMouseOver,	false, 0.0f);
				else									iBmp_colorize(obj->bmp, &lrc, propBackColor(obj),	false, 0.0f);


				//////////
				// Copy to prior rendered bitmap
				//////
					// Make sure our bmpPriorRendered exists
					obj->bmpPriorRendered = iBmp_verifyCopyIsSameSize(obj->bmpPriorRendered, obj->bmp);

					// Copy to the prior rendered version
					memcpy(obj->bmpPriorRendered->bd, obj->bmp->bd, obj->bmpPriorRendered->bi.biSizeImage);
					// Right now, we can use the bmpPriorRendered for a fast copy rather than 

			} else {
				// Render from its prior rendered version
				lnPixelsRendered += iBmp_bitBlt(obj->bmp, &lrc, obj->bmpPriorRendered);
			}

			// Indicate we're no longer dirty, that we have everything rendered, but it needs publishing
			obj->isDirtyRender = false;
			obj->isDirtyPublish	= true;
		}

		// Indicate status
		return(lnPixelsRendered);
	}




//////////
//
// Renders the cmdGroup.
//
//////
	u32 iSubobj_renderCmdGroup(SObject* obj)
	{
		u32		lnPixelsRendered;
		RECT	lrc;


		// Make sure our environment is sane
		logfunc(__FUNCTION__);
		lnPixelsRendered = 0;
		if (obj && obj->isRendered)
		{
			// Compute our rectangle for drawing
			SetRect(&lrc, 0, 0, obj->bmp->bi.biWidth, obj->bmp->bi.biHeight);
			if (obj->isDirtyRender)
			{
				// Render a white box as a placeholder
				iBmp_fillRect(obj->bmp, &lrc, whiteColor, whiteColor, whiteColor, whiteColor, false, NULL, false);


				//////////
				// Copy to prior rendered bitmap
				//////
					// Make sure our bmpPriorRendered exists
					obj->bmpPriorRendered = iBmp_verifyCopyIsSameSize(obj->bmpPriorRendered, obj->bmp);

					// Copy to the prior rendered version
					memcpy(obj->bmpPriorRendered->bd, obj->bmp->bd, obj->bmpPriorRendered->bi.biSizeImage);
					// Right now, we can use the bmpPriorRendered for a fast copy rather than 

			} else {
				// Render from its prior rendered version
				lnPixelsRendered += iBmp_bitBlt(obj->bmp, &lrc, obj->bmpPriorRendered);
			}

			// Indicate we're no longer dirty, that we have everything rendered, but it needs publishing
			obj->isDirtyRender = false;
			obj->isDirtyPublish	= true;
		}

		// Indicate status
		return(lnPixelsRendered);
	}




//////////
//
// Renders the optGroup.
//
//////
	u32 iSubobj_renderOptGroup(SObject* obj)
	{
		u32		lnPixelsRendered;
		RECT	lrc;


		// Make sure our environment is sane
		logfunc(__FUNCTION__);
		lnPixelsRendered = 0;
		if (obj && obj->isRendered)
		{
			// Compute our rectangle for drawing
			SetRect(&lrc, 0, 0, obj->bmp->bi.biWidth, obj->bmp->bi.biHeight);
			if (obj->isDirtyRender)
			{
				// Render a white box as a placeholder
				iBmp_fillRect(obj->bmp, &lrc, whiteColor, whiteColor, whiteColor, whiteColor, false, NULL, false);


				//////////
				// Copy to prior rendered bitmap
				//////
					// Make sure our bmpPriorRendered exists
					obj->bmpPriorRendered = iBmp_verifyCopyIsSameSize(obj->bmpPriorRendered, obj->bmp);

					// Copy to the prior rendered version
					memcpy(obj->bmpPriorRendered->bd, obj->bmp->bd, obj->bmpPriorRendered->bi.biSizeImage);
					// Right now, we can use the bmpPriorRendered for a fast copy rather than 

			} else {
				// Render from its prior rendered version
				lnPixelsRendered += iBmp_bitBlt(obj->bmp, &lrc, obj->bmpPriorRendered);
			}

			// Indicate we're no longer dirty, that we have everything rendered, but it needs publishing
			obj->isDirtyRender = false;
			obj->isDirtyPublish	= true;
		}

		// Indicate status
		return(lnPixelsRendered);
	}




//////////
//
// Renders the listbox.
//
//////
	u32 iSubobj_renderListbox(SObject* obj)
	{
		u32		lnPixelsRendered;
		RECT	lrc;


		// Make sure our environment is sane
		logfunc(__FUNCTION__);
		lnPixelsRendered = 0;
		if (obj && obj->isRendered)
		{
			// Compute our rectangle for drawing
			SetRect(&lrc, 0, 0, obj->bmp->bi.biWidth, obj->bmp->bi.biHeight);
			if (obj->isDirtyRender)
			{
				// Render a white box as a placeholder
				iBmp_fillRect(obj->bmp, &lrc, whiteColor, whiteColor, whiteColor, whiteColor, false, NULL, false);


				//////////
				// Copy to prior rendered bitmap
				//////
					// Make sure our bmpPriorRendered exists
					obj->bmpPriorRendered = iBmp_verifyCopyIsSameSize(obj->bmpPriorRendered, obj->bmp);

					// Copy to the prior rendered version
					memcpy(obj->bmpPriorRendered->bd, obj->bmp->bd, obj->bmpPriorRendered->bi.biSizeImage);
					// Right now, we can use the bmpPriorRendered for a fast copy rather than 

			} else {
				// Render from its prior rendered version
				lnPixelsRendered += iBmp_bitBlt(obj->bmp, &lrc, obj->bmpPriorRendered);
			}

			// Indicate we're no longer dirty, that we have everything rendered, but it needs publishing
			obj->isDirtyRender = false;
			obj->isDirtyPublish	= true;
		}

		// Indicate status
		return(lnPixelsRendered);
	}




//////////
//
// Renders the combobox.
//
//////
	u32 iSubobj_renderCombobox(SObject* obj)
	{
		u32		lnPixelsRendered;
		RECT	lrc;


		// Make sure our environment is sane
		logfunc(__FUNCTION__);
		lnPixelsRendered = 0;
		if (obj && obj->isRendered)
		{
			// Compute our rectangle for drawing
			SetRect(&lrc, 0, 0, obj->bmp->bi.biWidth, obj->bmp->bi.biHeight);
			if (obj->isDirtyRender)
			{
				// Render a white box as a placeholder
				iBmp_fillRect(obj->bmp, &lrc, whiteColor, whiteColor, whiteColor, whiteColor, false, NULL, false);


				//////////
				// Copy to prior rendered bitmap
				//////
					// Make sure our bmpPriorRendered exists
					obj->bmpPriorRendered = iBmp_verifyCopyIsSameSize(obj->bmpPriorRendered, obj->bmp);

					// Copy to the prior rendered version
					memcpy(obj->bmpPriorRendered->bd, obj->bmp->bd, obj->bmpPriorRendered->bi.biSizeImage);
					// Right now, we can use the bmpPriorRendered for a fast copy rather than 

			} else {
				// Render from its prior rendered version
				lnPixelsRendered += iBmp_bitBlt(obj->bmp, &lrc, obj->bmpPriorRendered);
			}

			// Indicate we're no longer dirty, that we have everything rendered, but it needs publishing
			obj->isDirtyRender = false;
			obj->isDirtyPublish	= true;
		}

		// Indicate status
		return(lnPixelsRendered);
	}




//////////
//
// Renders the formset.
//
//////
	u32 iSubobj_renderFormset(SObject* obj)
	{
		u32		lnPixelsRendered;
		RECT	lrc;


		// Make sure our environment is sane
		logfunc(__FUNCTION__);
		lnPixelsRendered = 0;
		if (obj && obj->isRendered)
		{
			// Compute our rectangle for drawing
			SetRect(&lrc, 0, 0, obj->bmp->bi.biWidth, obj->bmp->bi.biHeight);
			if (obj->isDirtyRender)
			{
				// Render a white box as a placeholder
				iBmp_fillRect(obj->bmp, &lrc, whiteColor, whiteColor, whiteColor, whiteColor, false, NULL, false);


				//////////
				// Copy to prior rendered bitmap
				//////
					// Make sure our bmpPriorRendered exists
					obj->bmpPriorRendered = iBmp_verifyCopyIsSameSize(obj->bmpPriorRendered, obj->bmp);

					// Copy to the prior rendered version
					memcpy(obj->bmpPriorRendered->bd, obj->bmp->bd, obj->bmpPriorRendered->bi.biSizeImage);
					// Right now, we can use the bmpPriorRendered for a fast copy rather than 

			} else {
				// Render from its prior rendered version
				lnPixelsRendered += iBmp_bitBlt(obj->bmp, &lrc, obj->bmpPriorRendered);
			}

			// Indicate we're no longer dirty, that we have everything rendered, but it needs publishing
			obj->isDirtyRender = false;
			obj->isDirtyPublish	= true;
		}

		// Indicate status
		return(lnPixelsRendered);
	}




//////////
//
// Renders the toolbar.
//
//////
	u32 iSubobj_renderToolbar(SObject* obj)
	{
		u32		lnPixelsRendered;
		RECT	lrc;


		// Make sure our environment is sane
		logfunc(__FUNCTION__);
		lnPixelsRendered = 0;
		if (obj && obj->isRendered)
		{
			// Compute our rectangle for drawing
			SetRect(&lrc, 0, 0, obj->bmp->bi.biWidth, obj->bmp->bi.biHeight);
			if (obj->isDirtyRender)
			{
				// Render a white box as a placeholder
				iBmp_fillRect(obj->bmp, &lrc, whiteColor, whiteColor, whiteColor, whiteColor, false, NULL, false);


				//////////
				// Copy to prior rendered bitmap
				//////
					// Make sure our bmpPriorRendered exists
					obj->bmpPriorRendered = iBmp_verifyCopyIsSameSize(obj->bmpPriorRendered, obj->bmp);

					// Copy to the prior rendered version
					memcpy(obj->bmpPriorRendered->bd, obj->bmp->bd, obj->bmpPriorRendered->bi.biSizeImage);
					// Right now, we can use the bmpPriorRendered for a fast copy rather than 

			} else {
				// Render from its prior rendered version
				lnPixelsRendered += iBmp_bitBlt(obj->bmp, &lrc, obj->bmpPriorRendered);
			}

			// Indicate we're no longer dirty, that we have everything rendered, but it needs publishing
			obj->isDirtyRender = false;
			obj->isDirtyPublish	= true;
		}

		// Indicate status
		return(lnPixelsRendered);
	}




//////////
//
// Renders the separator.
//
//////
	u32 iSubobj_renderSeparator(SObject* obj)
	{
		u32		lnPixelsRendered;
		RECT	lrc;


		// Make sure our environment is sane
		logfunc(__FUNCTION__);
		lnPixelsRendered = 0;
		if (obj && obj->isRendered)
		{
			// Compute our rectangle for drawing
			SetRect(&lrc, 0, 0, obj->bmp->bi.biWidth, obj->bmp->bi.biHeight);
			if (obj->isDirtyRender)
			{
				// Render a white box as a placeholder
				iBmp_fillRect(obj->bmp, &lrc, whiteColor, whiteColor, whiteColor, whiteColor, false, NULL, false);


				//////////
				// Copy to prior rendered bitmap
				//////
					// Make sure our bmpPriorRendered exists
					obj->bmpPriorRendered = iBmp_verifyCopyIsSameSize(obj->bmpPriorRendered, obj->bmp);

					// Copy to the prior rendered version
					memcpy(obj->bmpPriorRendered->bd, obj->bmp->bd, obj->bmpPriorRendered->bi.biSizeImage);
					// Right now, we can use the bmpPriorRendered for a fast copy rather than 

			} else {
				// Render from its prior rendered version
				lnPixelsRendered += iBmp_bitBlt(obj->bmp, &lrc, obj->bmpPriorRendered);
			}

			// Indicate we're no longer dirty, that we have everything rendered, but it needs publishing
			obj->isDirtyRender = false;
			obj->isDirtyPublish	= true;
		}

		// Indicate status
		return(lnPixelsRendered);
	}




//////////
//
// Renders the line.
//
//////
	u32 iSubobj_renderLine(SObject* obj)
	{
		u32		lnPixelsRendered;
		RECT	lrc;


		// Make sure our environment is sane
		logfunc(__FUNCTION__);
		lnPixelsRendered = 0;
		if (obj && obj->isRendered)
		{
			// Compute our rectangle for drawing
			SetRect(&lrc, 0, 0, obj->bmp->bi.biWidth, obj->bmp->bi.biHeight);
			if (obj->isDirtyRender)
			{
				// Render a white box as a placeholder
				iBmp_fillRect(obj->bmp, &lrc, whiteColor, whiteColor, whiteColor, whiteColor, false, NULL, false);


				//////////
				// Copy to prior rendered bitmap
				//////
					// Make sure our bmpPriorRendered exists
					obj->bmpPriorRendered = iBmp_verifyCopyIsSameSize(obj->bmpPriorRendered, obj->bmp);

					// Copy to the prior rendered version
					memcpy(obj->bmpPriorRendered->bd, obj->bmp->bd, obj->bmpPriorRendered->bi.biSizeImage);
					// Right now, we can use the bmpPriorRendered for a fast copy rather than 

			} else {
				// Render from its prior rendered version
				lnPixelsRendered += iBmp_bitBlt(obj->bmp, &lrc, obj->bmpPriorRendered);
			}

			// Indicate we're no longer dirty, that we have everything rendered, but it needs publishing
			obj->isDirtyRender = false;
			obj->isDirtyPublish	= true;
		}

		// Indicate status
		return(lnPixelsRendered);
	}




//////////
//
// Renders the shape.
//
//////
	u32 iSubobj_renderShape(SObject* obj)
	{
		u32		lnPixelsRendered;
		RECT	lrc;


		// Make sure our environment is sane
		logfunc(__FUNCTION__);
		lnPixelsRendered = 0;
		if (obj && obj->isRendered)
		{
			// Compute our rectangle for drawing
			SetRect(&lrc, 0, 0, obj->bmp->bi.biWidth, obj->bmp->bi.biHeight);
			if (obj->isDirtyRender)
			{
				// Render a white box as a placeholder
				iBmp_fillRect(obj->bmp, &lrc, whiteColor, whiteColor, whiteColor, whiteColor, false, NULL, false);


				//////////
				// Copy to prior rendered bitmap
				//////
					// Make sure our bmpPriorRendered exists
					obj->bmpPriorRendered = iBmp_verifyCopyIsSameSize(obj->bmpPriorRendered, obj->bmp);

					// Copy to the prior rendered version
					memcpy(obj->bmpPriorRendered->bd, obj->bmp->bd, obj->bmpPriorRendered->bi.biSizeImage);
					// Right now, we can use the bmpPriorRendered for a fast copy rather than 

			} else {
				// Render from its prior rendered version
				lnPixelsRendered += iBmp_bitBlt(obj->bmp, &lrc, obj->bmpPriorRendered);
			}

			// Indicate we're no longer dirty, that we have everything rendered, but it needs publishing
			obj->isDirtyRender = false;
			obj->isDirtyPublish	= true;
		}

		// Indicate status
		return(lnPixelsRendered);
	}




//////////
//
// Renders the container.
//
//////
	u32 iSubobj_renderContainer(SObject* obj)
	{
		u32		lnPixelsRendered;
		RECT	lrc;


		// Make sure our environment is sane
		logfunc(__FUNCTION__);
		lnPixelsRendered = 0;
		if (obj && obj->isRendered)
		{
			// Compute our rectangle for drawing
			SetRect(&lrc, 0, 0, obj->bmp->bi.biWidth, obj->bmp->bi.biHeight);
			if (obj->isDirtyRender)
			{
				// Render a white box as a placeholder
				iBmp_fillRect(obj->bmp, &lrc, whiteColor, whiteColor, whiteColor, whiteColor, false, NULL, false);


				//////////
				// Copy to prior rendered bitmap
				//////
					// Make sure our bmpPriorRendered exists
					obj->bmpPriorRendered = iBmp_verifyCopyIsSameSize(obj->bmpPriorRendered, obj->bmp);

					// Copy to the prior rendered version
					memcpy(obj->bmpPriorRendered->bd, obj->bmp->bd, obj->bmpPriorRendered->bi.biSizeImage);
					// Right now, we can use the bmpPriorRendered for a fast copy rather than 

			} else {
				// Render from its prior rendered version
				lnPixelsRendered += iBmp_bitBlt(obj->bmp, &lrc, obj->bmpPriorRendered);
			}

			// Indicate we're no longer dirty, that we have everything rendered, but it needs publishing
			obj->isDirtyRender = false;
			obj->isDirtyPublish	= true;
		}

		// Indicate status
		return(lnPixelsRendered);
	}




//////////
//
// Renders the control.
//
//////
	u32 iSubobj_renderControl(SObject* obj)
	{
		u32		lnPixelsRendered;
		RECT	lrc;


		// Make sure our environment is sane
		logfunc(__FUNCTION__);
		lnPixelsRendered = 0;
		if (obj && obj->isRendered)
		{
			// Compute our rectangle for drawing
			SetRect(&lrc, 0, 0, obj->bmp->bi.biWidth, obj->bmp->bi.biHeight);
			if (obj->isDirtyRender)
			{
				// Render a white box as a placeholder
				iBmp_fillRect(obj->bmp, &lrc, whiteColor, whiteColor, whiteColor, whiteColor, false, NULL, false);


				//////////
				// Copy to prior rendered bitmap
				//////
					// Make sure our bmpPriorRendered exists
					obj->bmpPriorRendered = iBmp_verifyCopyIsSameSize(obj->bmpPriorRendered, obj->bmp);

					// Copy to the prior rendered version
					memcpy(obj->bmpPriorRendered->bd, obj->bmp->bd, obj->bmpPriorRendered->bi.biSizeImage);
					// Right now, we can use the bmpPriorRendered for a fast copy rather than 

			} else {
				// Render from its prior rendered version
				lnPixelsRendered += iBmp_bitBlt(obj->bmp, &lrc, obj->bmpPriorRendered);
			}

			// Indicate we're no longer dirty, that we have everything rendered, but it needs publishing
			obj->isDirtyRender = false;
			obj->isDirtyPublish	= true;
		}

		// Indicate status
		return(lnPixelsRendered);
	}




//////////
//
// Renders the grid.
//
//////
	u32 iSubobj_renderGrid(SObject* obj)
	{
		u32		lnPixelsRendered;
		RECT	lrc;


		// Make sure our environment is sane
		logfunc(__FUNCTION__);
		lnPixelsRendered = 0;
		if (obj && obj->isRendered)
		{
			// Compute our rectangle for drawing
			SetRect(&lrc, 0, 0, obj->bmp->bi.biWidth, obj->bmp->bi.biHeight);
			if (obj->isDirtyRender)
			{
				// Render a white box as a placeholder
				iBmp_fillRect(obj->bmp, &lrc, whiteColor, whiteColor, whiteColor, whiteColor, false, NULL, false);


				//////////
				// Copy to prior rendered bitmap
				//////
					// Make sure our bmpPriorRendered exists
					obj->bmpPriorRendered = iBmp_verifyCopyIsSameSize(obj->bmpPriorRendered, obj->bmp);

					// Copy to the prior rendered version
					memcpy(obj->bmpPriorRendered->bd, obj->bmp->bd, obj->bmpPriorRendered->bi.biSizeImage);
					// Right now, we can use the bmpPriorRendered for a fast copy rather than 

			} else {
				// Render from its prior rendered version
				lnPixelsRendered += iBmp_bitBlt(obj->bmp, &lrc, obj->bmpPriorRendered);
			}

			// Indicate we're no longer dirty, that we have everything rendered, but it needs publishing
			obj->isDirtyRender = false;
			obj->isDirtyPublish	= true;
		}

		// Indicate status
		return(lnPixelsRendered);
	}




//////////
//
// Renders the column.
//
//////
	u32 iSubobj_renderColumn(SObject* obj)
	{
		u32		lnPixelsRendered;
		RECT	lrc;


		// Make sure our environment is sane
		logfunc(__FUNCTION__);
		lnPixelsRendered = 0;
		if (obj && obj->isRendered)
		{
			// Compute our rectangle for drawing
			SetRect(&lrc, 0, 0, obj->bmp->bi.biWidth, obj->bmp->bi.biHeight);
			if (obj->isDirtyRender)
			{
				// Render a white box as a placeholder
				iBmp_fillRect(obj->bmp, &lrc, whiteColor, whiteColor, whiteColor, whiteColor, false, NULL, false);


				//////////
				// Copy to prior rendered bitmap
				//////
					// Make sure our bmpPriorRendered exists
					obj->bmpPriorRendered = iBmp_verifyCopyIsSameSize(obj->bmpPriorRendered, obj->bmp);

					// Copy to the prior rendered version
					memcpy(obj->bmpPriorRendered->bd, obj->bmp->bd, obj->bmpPriorRendered->bi.biSizeImage);
					// Right now, we can use the bmpPriorRendered for a fast copy rather than 

			} else {
				// Render from its prior rendered version
				lnPixelsRendered += iBmp_bitBlt(obj->bmp, &lrc, obj->bmpPriorRendered);
			}

			// Indicate we're no longer dirty, that we have everything rendered, but it needs publishing
			obj->isDirtyRender = false;
			obj->isDirtyPublish	= true;
		}

		// Indicate status
		return(lnPixelsRendered);
	}




//////////
//
// Renders the header.
//
//////
	u32 iSubobj_renderHeader(SObject* obj)
	{
		u32		lnPixelsRendered;
		RECT	lrc;


		// Make sure our environment is sane
		logfunc(__FUNCTION__);
		lnPixelsRendered = 0;
		if (obj && obj->isRendered)
		{
			// Compute our rectangle for drawing
			SetRect(&lrc, 0, 0, obj->bmp->bi.biWidth, obj->bmp->bi.biHeight);
			if (obj->isDirtyRender)
			{
				// Render a white box as a placeholder
				iBmp_fillRect(obj->bmp, &lrc, whiteColor, whiteColor, whiteColor, whiteColor, false, NULL, false);


				//////////
				// Copy to prior rendered bitmap
				//////
					// Make sure our bmpPriorRendered exists
					obj->bmpPriorRendered = iBmp_verifyCopyIsSameSize(obj->bmpPriorRendered, obj->bmp);

					// Copy to the prior rendered version
					memcpy(obj->bmpPriorRendered->bd, obj->bmp->bd, obj->bmpPriorRendered->bi.biSizeImage);
					// Right now, we can use the bmpPriorRendered for a fast copy rather than 

			} else {
				// Render from its prior rendered version
				lnPixelsRendered += iBmp_bitBlt(obj->bmp, &lrc, obj->bmpPriorRendered);
			}

			// Indicate we're no longer dirty, that we have everything rendered, but it needs publishing
			obj->isDirtyRender = false;
			obj->isDirtyPublish	= true;
		}

		// Indicate status
		return(lnPixelsRendered);
	}




//////////
//
// Renders the oleBound.
//
//////
	u32 iSubobj_renderOleBound(SObject* obj)
	{
		u32		lnPixelsRendered;
		RECT	lrc;


		// Make sure our environment is sane
		logfunc(__FUNCTION__);
		lnPixelsRendered = 0;
		if (obj && obj->isRendered)
		{
			// Compute our rectangle for drawing
			SetRect(&lrc, 0, 0, obj->bmp->bi.biWidth, obj->bmp->bi.biHeight);
			if (obj->isDirtyRender)
			{
				// Render a white box as a placeholder
				iBmp_fillRect(obj->bmp, &lrc, whiteColor, whiteColor, whiteColor, whiteColor, false, NULL, false);


				//////////
				// Copy to prior rendered bitmap
				//////
					// Make sure our bmpPriorRendered exists
					obj->bmpPriorRendered = iBmp_verifyCopyIsSameSize(obj->bmpPriorRendered, obj->bmp);

					// Copy to the prior rendered version
					memcpy(obj->bmpPriorRendered->bd, obj->bmp->bd, obj->bmpPriorRendered->bi.biSizeImage);
					// Right now, we can use the bmpPriorRendered for a fast copy rather than 

			} else {
				// Render from its prior rendered version
				lnPixelsRendered += iBmp_bitBlt(obj->bmp, &lrc, obj->bmpPriorRendered);
			}

			// Indicate we're no longer dirty, that we have everything rendered, but it needs publishing
			obj->isDirtyRender = false;
			obj->isDirtyPublish	= true;
		}

		// Indicate status
		return(lnPixelsRendered);
	}




//////////
//
// Renders the oleContain.
//
//////
	u32 iSubobj_renderOleContain(SObject* obj)
	{
		u32		lnPixelsRendered;
		RECT	lrc;


		// Make sure our environment is sane
		logfunc(__FUNCTION__);
		lnPixelsRendered = 0;
		if (obj && obj->isRendered)
		{
			// Compute our rectangle for drawing
			SetRect(&lrc, 0, 0, obj->bmp->bi.biWidth, obj->bmp->bi.biHeight);
			if (obj->isDirtyRender)
			{
				// Render a white box as a placeholder
				iBmp_fillRect(obj->bmp, &lrc, whiteColor, whiteColor, whiteColor, whiteColor, false, NULL, false);


				//////////
				// Copy to prior rendered bitmap
				//////
					// Make sure our bmpPriorRendered exists
					obj->bmpPriorRendered = iBmp_verifyCopyIsSameSize(obj->bmpPriorRendered, obj->bmp);

					// Copy to the prior rendered version
					memcpy(obj->bmpPriorRendered->bd, obj->bmp->bd, obj->bmpPriorRendered->bi.biSizeImage);
					// Right now, we can use the bmpPriorRendered for a fast copy rather than 

			} else {
				// Render from its prior rendered version
				lnPixelsRendered += iBmp_bitBlt(obj->bmp, &lrc, obj->bmpPriorRendered);
			}

			// Indicate we're no longer dirty, that we have everything rendered, but it needs publishing
			obj->isDirtyRender = false;
			obj->isDirtyPublish	= true;
		}

		// Indicate status
		return(lnPixelsRendered);
	}




//////////
//
// Renders the spinner.
//
//////
	u32 iSubobj_renderSpinner(SObject* obj)
	{
		u32		lnPixelsRendered;
		RECT	lrc;


		// Make sure our environment is sane
		logfunc(__FUNCTION__);
		lnPixelsRendered = 0;
		if (obj && obj->isRendered)
		{
			// Compute our rectangle for drawing
			SetRect(&lrc, 0, 0, obj->bmp->bi.biWidth, obj->bmp->bi.biHeight);
			if (obj->isDirtyRender)
			{
				// Render a white box as a placeholder
				iBmp_fillRect(obj->bmp, &lrc, whiteColor, whiteColor, whiteColor, whiteColor, false, NULL, false);


				//////////
				// Copy to prior rendered bitmap
				//////
					// Make sure our bmpPriorRendered exists
					obj->bmpPriorRendered = iBmp_verifyCopyIsSameSize(obj->bmpPriorRendered, obj->bmp);

					// Copy to the prior rendered version
					memcpy(obj->bmpPriorRendered->bd, obj->bmp->bd, obj->bmpPriorRendered->bi.biSizeImage);
					// Right now, we can use the bmpPriorRendered for a fast copy rather than 

			} else {
				// Render from its prior rendered version
				lnPixelsRendered += iBmp_bitBlt(obj->bmp, &lrc, obj->bmpPriorRendered);
			}

			// Indicate we're no longer dirty, that we have everything rendered, but it needs publishing
			obj->isDirtyRender = false;
			obj->isDirtyPublish	= true;
		}

		// Indicate status
		return(lnPixelsRendered);
	}




//////////
//
// Renders the timer.
//
//////
	u32 iSubobj_renderTimer(SObject* obj)
	{
		u32		lnPixelsRendered;
		RECT	lrc;


		// Make sure our environment is sane
		logfunc(__FUNCTION__);
		lnPixelsRendered = 0;
		if (obj && obj->isRendered)
		{
			// Compute our rectangle for drawing
			SetRect(&lrc, 0, 0, obj->bmp->bi.biWidth, obj->bmp->bi.biHeight);
			if (obj->isDirtyRender)
			{
				// Render a white box as a placeholder
				iBmp_fillRect(obj->bmp, &lrc, whiteColor, whiteColor, whiteColor, whiteColor, false, NULL, false);


				//////////
				// Copy to prior rendered bitmap
				//////
					// Make sure our bmpPriorRendered exists
					obj->bmpPriorRendered = iBmp_verifyCopyIsSameSize(obj->bmpPriorRendered, obj->bmp);

					// Copy to the prior rendered version
					memcpy(obj->bmpPriorRendered->bd, obj->bmp->bd, obj->bmpPriorRendered->bi.biSizeImage);
					// Right now, we can use the bmpPriorRendered for a fast copy rather than 

			} else {
				// Render from its prior rendered version
				lnPixelsRendered += iBmp_bitBlt(obj->bmp, &lrc, obj->bmpPriorRendered);
			}

			// Indicate we're no longer dirty, that we have everything rendered, but it needs publishing
			obj->isDirtyRender = false;
			obj->isDirtyPublish	= true;
		}

		// Indicate status
		return(lnPixelsRendered);
	}




//////////
//
// Renders the hyperlink.
//
//////
	u32 iSubobj_renderHyperlink(SObject* obj)
	{
		u32		lnPixelsRendered;
		RECT	lrc;


		// Make sure our environment is sane
		logfunc(__FUNCTION__);
		lnPixelsRendered = 0;
		if (obj && obj->isRendered)
		{
			// Compute our rectangle for drawing
			SetRect(&lrc, 0, 0, obj->bmp->bi.biWidth, obj->bmp->bi.biHeight);
			if (obj->isDirtyRender)
			{
				// Render a white box as a placeholder
				iBmp_fillRect(obj->bmp, &lrc, whiteColor, whiteColor, whiteColor, whiteColor, false, NULL, false);


				//////////
				// Copy to prior rendered bitmap
				//////
					// Make sure our bmpPriorRendered exists
					obj->bmpPriorRendered = iBmp_verifyCopyIsSameSize(obj->bmpPriorRendered, obj->bmp);

					// Copy to the prior rendered version
					memcpy(obj->bmpPriorRendered->bd, obj->bmp->bd, obj->bmpPriorRendered->bi.biSizeImage);
					// Right now, we can use the bmpPriorRendered for a fast copy rather than 

			} else {
				// Render from its prior rendered version
				lnPixelsRendered += iBmp_bitBlt(obj->bmp, &lrc, obj->bmpPriorRendered);
			}

			// Indicate we're no longer dirty, that we have everything rendered, but it needs publishing
			obj->isDirtyRender = false;
			obj->isDirtyPublish	= true;
		}

		// Indicate status
		return(lnPixelsRendered);
	}




//////////
//
// Renders the collection.
//
//////
	u32 iSubobj_renderCollection(SObject* obj)
	{
		u32		lnPixelsRendered;
		RECT	lrc;


		// Make sure our environment is sane
		logfunc(__FUNCTION__);
		lnPixelsRendered = 0;
		if (obj && obj->isRendered)
		{
			// Compute our rectangle for drawing
			SetRect(&lrc, 0, 0, obj->bmp->bi.biWidth, obj->bmp->bi.biHeight);
			if (obj->isDirtyRender)
			{
				// Render a white box as a placeholder
				iBmp_fillRect(obj->bmp, &lrc, whiteColor, whiteColor, whiteColor, whiteColor, false, NULL, false);


				//////////
				// Copy to prior rendered bitmap
				//////
					// Make sure our bmpPriorRendered exists
					obj->bmpPriorRendered = iBmp_verifyCopyIsSameSize(obj->bmpPriorRendered, obj->bmp);

					// Copy to the prior rendered version
					memcpy(obj->bmpPriorRendered->bd, obj->bmp->bd, obj->bmpPriorRendered->bi.biSizeImage);
					// Right now, we can use the bmpPriorRendered for a fast copy rather than 

			} else {
				// Render from its prior rendered version
				lnPixelsRendered += iBmp_bitBlt(obj->bmp, &lrc, obj->bmpPriorRendered);
			}

			// Indicate we're no longer dirty, that we have everything rendered, but it needs publishing
			obj->isDirtyRender = false;
			obj->isDirtyPublish	= true;
		}

		// Indicate status
		return(lnPixelsRendered);
	}




//////////
//
// Renders the page.
//
//////
	u32 iSubobj_renderPage(SObject* obj)
	{
		u32		lnPixelsRendered;
		RECT	lrc;


		// Make sure our environment is sane
		logfunc(__FUNCTION__);
		lnPixelsRendered = 0;
		if (obj && obj->isRendered)
		{
			// Compute our rectangle for drawing
			SetRect(&lrc, 0, 0, obj->bmp->bi.biWidth, obj->bmp->bi.biHeight);
			if (obj->isDirtyRender)
			{
				// Render a white box as a placeholder
				iBmp_fillRect(obj->bmp, &lrc, whiteColor, whiteColor, whiteColor, whiteColor, false, NULL, false);


				//////////
				// Copy to prior rendered bitmap
				//////
					// Make sure our bmpPriorRendered exists
					obj->bmpPriorRendered = iBmp_verifyCopyIsSameSize(obj->bmpPriorRendered, obj->bmp);

					// Copy to the prior rendered version
					memcpy(obj->bmpPriorRendered->bd, obj->bmp->bd, obj->bmpPriorRendered->bi.biSizeImage);
					// Right now, we can use the bmpPriorRendered for a fast copy rather than 

			} else {
				// Render from its prior rendered version
				lnPixelsRendered += iBmp_bitBlt(obj->bmp, &lrc, obj->bmpPriorRendered);
			}

			// Indicate we're no longer dirty, that we have everything rendered, but it needs publishing
			obj->isDirtyRender = false;
			obj->isDirtyPublish	= true;
		}

		// Indicate status
		return(lnPixelsRendered);
	}




//////////
//
// Renders the pageFrame.
//
//////
	u32 iSubobj_renderPageFrame(SObject* obj)
	{
		u32		lnPixelsRendered;
		RECT	lrc;


		// Make sure our environment is sane
		logfunc(__FUNCTION__);
		lnPixelsRendered = 0;
		if (obj && obj->isRendered)
		{
			// Compute our rectangle for drawing
			SetRect(&lrc, 0, 0, obj->bmp->bi.biWidth, obj->bmp->bi.biHeight);
			if (obj->isDirtyRender)
			{
				// Render a white box as a placeholder
				iBmp_fillRect(obj->bmp, &lrc, whiteColor, whiteColor, whiteColor, whiteColor, false, NULL, false);


				//////////
				// Copy to prior rendered bitmap
				//////
					// Make sure our bmpPriorRendered exists
					obj->bmpPriorRendered = iBmp_verifyCopyIsSameSize(obj->bmpPriorRendered, obj->bmp);

					// Copy to the prior rendered version
					memcpy(obj->bmpPriorRendered->bd, obj->bmp->bd, obj->bmpPriorRendered->bi.biSizeImage);
					// Right now, we can use the bmpPriorRendered for a fast copy rather than 

			} else {
				// Render from its prior rendered version
				lnPixelsRendered += iBmp_bitBlt(obj->bmp, &lrc, obj->bmpPriorRendered);
			}

			// Indicate we're no longer dirty, that we have everything rendered, but it needs publishing
			obj->isDirtyRender = false;
			obj->isDirtyPublish	= true;
		}

		// Indicate status
		return(lnPixelsRendered);
	}




//////////
//
// Renders the session.
//
//////
	u32 iSubobj_renderSession(SObject* obj)
	{
		u32		lnPixelsRendered;
		RECT	lrc;


		// Make sure our environment is sane
		logfunc(__FUNCTION__);
		lnPixelsRendered = 0;
		if (obj && obj->isRendered)
		{
			// Compute our rectangle for drawing
			SetRect(&lrc, 0, 0, obj->bmp->bi.biWidth, obj->bmp->bi.biHeight);
			if (obj->isDirtyRender)
			{
				// Render a white box as a placeholder
				iBmp_fillRect(obj->bmp, &lrc, whiteColor, whiteColor, whiteColor, whiteColor, false, NULL, false);


				//////////
				// Copy to prior rendered bitmap
				//////
					// Make sure our bmpPriorRendered exists
					obj->bmpPriorRendered = iBmp_verifyCopyIsSameSize(obj->bmpPriorRendered, obj->bmp);

					// Copy to the prior rendered version
					memcpy(obj->bmpPriorRendered->bd, obj->bmp->bd, obj->bmpPriorRendered->bi.biSizeImage);
					// Right now, we can use the bmpPriorRendered for a fast copy rather than 

			} else {
				// Render from its prior rendered version
				lnPixelsRendered += iBmp_bitBlt(obj->bmp, &lrc, obj->bmpPriorRendered);
			}

			// Indicate we're no longer dirty, that we have everything rendered, but it needs publishing
			obj->isDirtyRender = false;
			obj->isDirtyPublish	= true;
		}

		// Indicate status
		return(lnPixelsRendered);
	}




//////////
//
// Renders the custom.
//
//////
	u32 iSubobj_renderCustom(SObject* obj)
	{
		u32		lnPixelsRendered;
		RECT	lrc;


		// Make sure our environment is sane
		logfunc(__FUNCTION__);
		lnPixelsRendered = 0;
		if (obj && obj->isRendered)
		{
			// Compute our rectangle for drawing
			SetRect(&lrc, 0, 0, obj->bmp->bi.biWidth, obj->bmp->bi.biHeight);
			if (obj->isDirtyRender)
			{
				// Render a white box as a placeholder
				iBmp_fillRect(obj->bmp, &lrc, whiteColor, whiteColor, whiteColor, whiteColor, false, NULL, false);


				//////////
				// Copy to prior rendered bitmap
				//////
					// Make sure our bmpPriorRendered exists
					obj->bmpPriorRendered = iBmp_verifyCopyIsSameSize(obj->bmpPriorRendered, obj->bmp);

					// Copy to the prior rendered version
					memcpy(obj->bmpPriorRendered->bd, obj->bmp->bd, obj->bmpPriorRendered->bi.biSizeImage);
					// Right now, we can use the bmpPriorRendered for a fast copy rather than 

			} else {
				// Render from its prior rendered version
				lnPixelsRendered += iBmp_bitBlt(obj->bmp, &lrc, obj->bmpPriorRendered);
			}

			// Indicate we're no longer dirty, that we have everything rendered, but it needs publishing
			obj->isDirtyRender = false;
			obj->isDirtyPublish	= true;
		}

		// Indicate status
		return(lnPixelsRendered);
	}




//////////
//
// Renders the exception.
//
//////
	u32 iSubobj_renderException(SObject* obj)
	{
		u32		lnPixelsRendered;
		RECT	lrc;


		// Make sure our environment is sane
		logfunc(__FUNCTION__);
		lnPixelsRendered = 0;
		if (obj && obj->isRendered)
		{
			// Compute our rectangle for drawing
			SetRect(&lrc, 0, 0, obj->bmp->bi.biWidth, obj->bmp->bi.biHeight);
			if (obj->isDirtyRender)
			{
				// Render a white box as a placeholder
				iBmp_fillRect(obj->bmp, &lrc, whiteColor, whiteColor, whiteColor, whiteColor, false, NULL, false);


				//////////
				// Copy to prior rendered bitmap
				//////
					// Make sure our bmpPriorRendered exists
					obj->bmpPriorRendered = iBmp_verifyCopyIsSameSize(obj->bmpPriorRendered, obj->bmp);

					// Copy to the prior rendered version
					memcpy(obj->bmpPriorRendered->bd, obj->bmp->bd, obj->bmpPriorRendered->bi.biSizeImage);
					// Right now, we can use the bmpPriorRendered for a fast copy rather than 

			} else {
				// Render from its prior rendered version
				lnPixelsRendered += iBmp_bitBlt(obj->bmp, &lrc, obj->bmpPriorRendered);
			}

			// Indicate we're no longer dirty, that we have everything rendered, but it needs publishing
			obj->isDirtyRender = false;
			obj->isDirtyPublish	= true;
		}

		// Indicate status
		return(lnPixelsRendered);
	}




//////////
//
// Renders the settings.
//
//////
	u32 iSubobj_renderSettings(SObject* obj)
	{
		u32		lnPixelsRendered;
		RECT	lrc;


		// Make sure our environment is sane
		logfunc(__FUNCTION__);
		lnPixelsRendered = 0;
		if (obj && obj->isRendered)
		{
			// Compute our rectangle for drawing
			SetRect(&lrc, 0, 0, obj->bmp->bi.biWidth, obj->bmp->bi.biHeight);
			if (obj->isDirtyRender)
			{
				// Render a white box as a placeholder
				iBmp_fillRect(obj->bmp, &lrc, whiteColor, whiteColor, whiteColor, whiteColor, false, NULL, false);


				//////////
				// Copy to prior rendered bitmap
				//////
					// Make sure our bmpPriorRendered exists
					obj->bmpPriorRendered = iBmp_verifyCopyIsSameSize(obj->bmpPriorRendered, obj->bmp);

					// Copy to the prior rendered version
					memcpy(obj->bmpPriorRendered->bd, obj->bmp->bd, obj->bmpPriorRendered->bi.biSizeImage);
					// Right now, we can use the bmpPriorRendered for a fast copy rather than 

			} else {
				// Render from its prior rendered version
				lnPixelsRendered += iBmp_bitBlt(obj->bmp, &lrc, obj->bmpPriorRendered);
			}

			// Indicate we're no longer dirty, that we have everything rendered, but it needs publishing
			obj->isDirtyRender = false;
			obj->isDirtyPublish	= true;
		}

		// Indicate status
		return(lnPixelsRendered);
	}
