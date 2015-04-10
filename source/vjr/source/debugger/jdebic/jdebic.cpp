//////////
//
// /libsf/source/vjr/source/debugger/jdebic/jdebic.cpp
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
// Version 0.57
// Copyright (c) 2015 by Rick C. Hodgin
//////
// Last update:
//     Apr.10.2015
//////
// Change log:
//     Apr.10.2015 - Initial creation
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
//	       _  _____         _      _   _____ 
//	      | ||  __ \       | |    (_) / ____|
//	      | || |  | |  ___ | |__   _ | |     
//	  _   | || |  | | / _ \| '_ \ | || |     
//	 | |__| || |__| ||  __/| |_) || || |____ 
//	  \____/ |_____/  \___||_.__/ |_| \_____|
//				JDebi Companion
//			A Remote Debug Assist Tool
//




//////////
//
// Called to send over debugging information for the current context
//
//////
	void JDebiC_debug(SThisCode* thisCode, SWindow* win, SObject* obj)
	{
		SDatum		data;
		SBuilder*	builder;


		// Are we connected?
		if (iJDebiC_connect() && thisCode || win || obj)
		{

			//////////
			// Initialize
			//////
				iBuilder_createAndInitialize(&builder, -1);
				data.data = builder->buffer;


			//////////
			// thisCode
			//////
				if (thisCode)
				{
					iJDebiC_thisCode(thisCode, builder);
					data.length = builder->populatedLength;
					iJDebiC_transmit_viaPipe(&data, NULL, _WMJDEBIC_DATA_TYPE_THISCODE);
					iBuilder_rewind(builder);
				}


			//////////
			// win
			//////
				if (win)
				{
					iJDebiC_win(win, builder);
					data.length = builder->populatedLength;
					iJDebiC_transmit_viaPipe(&data, NULL, _WMJDEBIC_DATA_TYPE_WIN);
					iBuilder_rewind(builder);
				}


			//////////
			// obj
			//////
				if (obj)
				{
					iJDebiC_obj(obj, builder);
					data.length = builder->populatedLength;
					iJDebiC_transmit_viaPipe(&data, NULL, _WMJDEBIC_DATA_TYPE_OBJ);
					iBuilder_rewind(builder);
				}


			//////////
			// Clean house
			//////
				iBuilder_freeAndRelease(&builder);

		}
	}




//////////
//
// Called to send over some text
//
//////
	void JDebiC_text(s8* tcText)
	{
		SDatum data;


		data.data	= tcText;
		data.length	= strlen(tcText);
		iJDebiC_transmit_viaPipe(&data, NULL, _WMJDEBIC_DATA_TYPE_TEXT);
	}




//////////
//
// Called to send over some data
//
//////
	void JDebiC_data(s8* tcData, s32 tnDataLength)
	{
		SDatum data;


		data.data	= tcData;
		data.length	= tnDataLength;
		iJDebiC_transmit_viaPipe(&data, NULL, _WMJDEBIC_DATA_TYPE_DATA);
	}




//////////
//
// Called to send over some data for a bitmap
//
//////
	void JDebiC_hexdump(SBitmap* bmp)
	{
		SDatum data1, data2;


		data1.data		= (s8*)bmp;
		data1.length	= sizeof(*bmp);
		data2.data		= bmp->bd;
		data2.length	= bmp->bi.biSizeImage;
		iJDebiC_transmit_viaPipe(&data1, &data2, _WMJDEBIC_DATA_TYPE_BITMAP);
	}




//////////
//
// Called to send over some data for a hex dump
//
//////
	void JDebiC_hexdump(s8* tcData, s32 tnDataLength)
	{
		SDatum data;


		data.data	= tcData;
		data.length	= tnDataLength;
		iJDebiC_transmit_viaPipe(&data, NULL, _WMJDEBIC_DATA_TYPE_HEXDUMP);
	}




//////////
//
// Called to verify we're online, and if not then try to connect
//
//////
	HANDLE iJDebiC_createPipeHandle(cs8* lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, HANDLE hTemplateFile)
	{
//		s32		lnError1, lnError2;
		HANDLE	hPipe;


		//////////
		// Create the indicated pipe
		//////
			hPipe		= CreateFile(lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile);
//			lnError1	= GetLastError();
			if (hPipe != INVALID_HANDLE_VALUE)
			{
				ConnectNamedPipe(hPipe, NULL);
//				lnError2 = GetLastError();
			}


		//////////
		// Indicate our status
		//////
			return(hPipe);

	}




//////////
//
// Validates we're still connected to JDebiC, or tries to connect to it
//
//////
	bool iJDebiC_connect(void)
	{
		bool	llNeedHandles;
		s8		pipeNameOut[_MAX_PATH];


		//////////
		// Locate the existing JDebiC window
		//////
			// Is the window (still) known and viable?
			if (!hwndJDebiC || !IsWindow(hwndJDebiC))
			{
				// Our reference needs updated ... try to find it
				hwndJDebiC		= FindWindow(cgcJDebiCClassName, NULL);
				llNeedHandles	= true;		// If it was found, our handles are now invalid and must be re-requested

			} else {
				// It is known ... see if we have the handles
				llNeedHandles = (handleJDebiCOut == null);
			}


		//////////
		// Are we still viable?
		//////
			if (!hwndJDebiC)
				return(false);	// Nope


		//////////
		// We are viable, but do we need handles?
		//////
			if (llNeedHandles)
			{
				// Request our number to use for our named pipes
				gnJDebiCOutPipeNumber = SendMessage(hwndJDebiC, _WMJDEBIC_PIPE_REQUEST, 0, 0);

				// Create the pipe names
				sprintf(pipeNameOut, "\\\\.\\pipe\\JDebiC_pipe_%08x\0", gnJDebiCOutPipeNumber);

				// Non-owners connect to an existing pipe
				handleJDebiCOut = (u32)iJDebiC_createPipeHandle(pipeNameOut, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
			}


		//////////
		// Check values
		//////
			if (handleJDebiCOut == (u32)INVALID_HANDLE_VALUE)
				handleJDebiCOut = NULL;


		//////////
		// Write the output data
		//////
			return((handleJDebiCOut != NULL));
	}




//////////
//
// Called to transmit the data to the remote
//
//////
	s32 iJDebiC_transmit_viaPipe(SDatum* data1, SDatum* data2, u32 tnDataType)
	{
		DWORD lnNumwritten1, lnNumwritten2;


		//////////
		// Make sure we're connected
		//////
			lnNumwritten1 = 0;
			lnNumwritten2 = 0;
			if (iJDebiC_connect())
			{
				// Transmit and signal the transmission
				if (data1)		WriteFile((HANDLE)handleJDebiCOut, data1->data, data1->length, &lnNumwritten1, NULL);
				if (data2)		WriteFile((HANDLE)handleJDebiCOut, data2->data, data2->length, &lnNumwritten2, NULL);

				// Did we write anything?
				if (lnNumwritten1 + lnNumwritten2 > 0)
					SendMessage(hwndJDebiC, tnDataType, lnNumwritten1 + lnNumwritten2, gnJDebiCOutPipeNumber);
			}


		//////////
		// Clean house
		//////
			if (data1)		data1->length = 0;
			if (data2)		data2->length = 0;


		//////////
		// Indicate how many bytes were transmitted
		//////
			return((s32)(lnNumwritten1 + lnNumwritten2));

	}




//////////
//
// Called to process a thisCode object into its call stack hierarchy
//
//////
	void iJDebiC_thisCode(SThisCode* thisCode, SBuilder* data)
	{
// 		struct SSourceCode
// 		{
// 			SFunction*		firstFunction;			// First function in the program
// 
// 			SVariable*		params;					// The first parameter in the function
// 			SVariable*		returns;				// The first return variable declared
// 			SVariable*		privates;				// The first private variable declared
// 			SVariable*		locals;					// The first local variable declared
// 			SVariable*		scoped;					// The first scoped/temporary variable used by the function
// 
// 			SEM*			sourceCode;				// The source code for this program
// 		};
// 
// 		struct SThisCode
// 		{
// 			SLL				ll;
// 
// 			SWindow*		win;					// Current window
// 			SSourceCode*	definition;				// As defined at compile time
// 			SSourceCode*	live;					// As exists live in this instance at this level
// 		};
	}




//////////
//
// Called to process a windows object into text
//
//////
	void iJDebiC_win(SWindow* win, SBuilder* data)
	{
		s8 buffer[4096];


		// Make sure our environment is sane
		if (win && data)
		{
// Must sync up with the SWindow structure
			iBuilder_append_label_logical(data, "isValid", win->isValid);
			iBuilder_append_label_uptr(data, "hwnd", (uptr)win->hwnd);
			iBuilder_append_label_uptr(data, "bmp", (uptr)win->bmp);

			iiJDebiC_decode_Rect(buffer, &win->rc);
			iBuilder_append_label_text(data, "rc", buffer);

			iBuilder_append_label_uptr(data, "obj", (uptr)win->obj);

			iiJDebiC_decode_SMouseData(buffer, &win->mousePrior);
			iBuilder_append_label_text(data, "mousePrior", buffer);

			iiJDebiC_decode_SMouseData(buffer, &win->mouseCurrent);
			iBuilder_append_label_text(data, "mousePrior", buffer);

			iBuilder_append_label_logical(data, "isMoving", win->isMoving);
			iBuilder_append_label_logical(data, "isResizing", win->isResizing);

			iiJDebiC_decode_SMouseData(buffer, &win->mouseMoveResizeStart);
			iBuilder_append_label_text(data, "mouseMoveResizeStart", buffer);

			iiJDebiC_decode_Rect(buffer, &win->rcMoveResizeStart);
			iBuilder_append_label_text(data, "rcMoveResizeStart", buffer);

			iBuilder_append_label_sptr(data, "movingLastDeltaX", (uptr)win->movingLastDeltaX);
			iBuilder_append_label_sptr(data, "movingLastDeltaY", (uptr)win->movingLastDeltaY);

			iiJDebiC_decode_POINT(buffer, win->mousePositionClick);
			iBuilder_append_label_text(data, "mousePositionClick", buffer);

			iiJDebiC_decode_POINT(buffer, win->mousePositionClickScreen);
			iBuilder_append_label_text(data, "mousePositionClickScreen", buffer);
		}
	}




//////////
//
// Called to process an object, and all its poems, into text
//
//////
	void iJDebiC_obj(SObject* obj, SBuilder* data)
	{
// 			SLL			ll;													// Linked list
// 			SObject*	parent;												// Pointer to parent object for this instance
// 			SObject*	firstChild;											// Pointer to child objects (all objects are containers)
// 
// 	#ifdef _EXTRA_DEBUGGING_DATA
// 			SDatum		dbgClass;
// 			SDatum		dbgName;
// 	#endif
// 
// 			// Defined class, class information
// 			s32			objType;											// Object base type/class (see _OBJECT_TYPE_* constants)
// 
// 			// Object flags
// 			bool		isRendered;											// Is it rendered (can be rendered even if it's not visible)?
// 			bool		isPublished;										// Should this control be published?  Every object has a .lockScreen property which allows it to not be published while changes are made.
// 			bool		isDirtyRender;										// Is set if this or any child object needs re-rendered
// 			bool		isDirtyPublish;										// Is set if this or any child object needs re-published
// 
// 
// 			//////////
// 			// Object size in pixels, per the .Left, .Top, .Width, and .Height properties
// 			//////
// 				RECT		rc;												// Object's current position in its parent
// 				RECT		rco;											// Object's original position in its parent
// 				RECT		rcp;											// Original size of parent at creation
// 				RECT		rcClient;										// Client portion within the size of the object
// 				RECT		rcExtra;										// An extra portion used for object-specific components, such as rider tab location on carousels
// 
// 
// 			//////////
// 			// Common properties that are literal(p) and allocated(pa) values
// 			//////
// 				SProperties		p;											// Common object properties
// 				SVariable**		props;										// An allocated array of properties (varies in size by object)
// 				s32				propsCount;									// The number of property variables allocated
// 
// 				// Related position in the member hierarchy
// 				SVariable*	firstProperty;									// User-defined property (design time and runtime)
// 				SEM*		firstMethod;									// User-defined methods (design time and runtime)
// 
// 				// Related access and assign methods
// 				bool		anyPropertyHasAccessOrAssignMethods;
// 				SEM*		firstAccess;									// User-defined property access methods (design time and runtime)
// 				SEM*		firstAssign;									// User-defined property assignment methods (design time and runtime)
// 
// 				// Events
// 				SEvents		ev;												// Events for this object
// 
// 
// 			//////////
// 			// Base drawing canvas
// 			//////
// 				SBitmap*	bmp;											// If exists, canvas for the content
// 				SBitmap*	bmpPriorRendered;								// Used for speedups when not isDirty
// 				SBmpCache*	bc;												// For certain compute intensive operations (color gradient controls), the bitmap is only drawn/computed once and then copied thereafter, unless any of eight data points change
// 				// If not scaled:
// 				s32			scrollOffsetX;									// If the bmp->bi coordinates are larger than its display area, the upper-left X coordinate
// 				s32			scrollOffsetY;									// ...the upper-left Y coordinate
// 				// If scaled, updated only during publish():
// 				bool		isScaled;										// If the bmp->bi coordinates are larger than its display area, should it be scaled?
// 				SBitmap*	bmpScaled;										// The bmp scaled into RC's size

	}




//////////
//
// Helper functions for decoding sub-variables
//
//////
	void iiJDebiC_decode_Rect(s8* buffer, RECT* rc)
	{
		sprintf(buffer, "{ left = %u, top = %u, right = %u, bottom = %u }\0", rc->left, rc->top, rc->right, rc->bottom);
	}

	void iiJDebiC_decode_POINT(s8* buffer, POINT pt)
	{
		sprintf(buffer, "{ x = %u, y = %u }\0", pt.x, pt.y);
	}

	void iiJDebiC_decode_SMouseData(s8* buffer, SMouseData* md)
	{
		sprintf(buffer,   "{ positionInOsDesktop = { x = %u, y = %u }, "
							"position = { x = %u, y = %u }, "
							"whelDeltaV = %u, wheelDeltaH = %u, "

							"buttonLeft = %u, buttonMiddle = %u, buttonRight = %u, buttonAnyDown = %u, "
							"isCaps = %s, isCtrl = %s, isAlt = %s, isShift = % }\0",

							md->positionInOsDesktop.x,	md->positionInOsDesktop.y,
							md->position.x,				md->position.y,
							md->wheelDeltaV,			md->wheelDeltaH,

							md->buttonLeft,		md->buttonMiddle,	md->buttonRight,	md->buttonAnyDown,
							md->isCaps,			md->isCtrl,			md->isAlt,			md->isShift);
	}
