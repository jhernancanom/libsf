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
	void jdebic_debug(SThisCode* thisCode, SWindow* win, SObject* obj)
	{
		SBuilder*	tcBuilder;
		SBuilder*	wBuilder;
		SBuilder*	oBuilder;


		// Are we connected?
		if (ijdebic_connect())
		{

			//////////
			// thisCode
			//////
				if (thisCode)
				{
					iBuilder_createAndInitialize(&tcBuilder, -1);
					ijdebic_thisCode(thisCode, tcBuilder);
					ijdebic_transmit(tcBuilder);
					iBuilder_freeAndRelease(&tcBuilder);
				}


			//////////
			// win
			//////
				if (win)
				{
					iBuilder_createAndInitialize(&wBuilder, -1);
					ijdebic_win(win, wBuilder);
					ijdebic_transmit(wBuilder);
					iBuilder_freeAndRelease(&wBuilder);
				}


			//////////
			// obj
			//////
				if (obj)
				{
					iBuilder_createAndInitialize(&oBuilder, -1);
					ijdebic_obj(obj, oBuilder);
					ijdebic_transmit(oBuilder);
					iBuilder_freeAndRelease(&oBuilder);
				}

		}
	}




//////////
//
// Called to send over some text
//
//////
	void jdebic_text(s8* tcText)
	{
		if (ijdebic_connect())
		{
		}
	}




//////////
//
// Called to send over some data
//
//////
	void jdebic_data(s8* tcDescription, SDatum* data, u32 tnDataType)
	{
		if (ijdebic_connect())
		{
		}
	}




//////////
//
// Called to verify we're online, and if not then try to connect
//
//////
	bool ijdebic_connect(void)
	{
// TODO:  Named pipe connection
		return(true);
	}




//////////
//
// Called to transmit the data to the remote
//
//////
	void ijdebic_transmit(SBuilder* data)
	{
	}




//////////
//
// Called to process a thisCode object into its call stack hierarchy
//
//////
	void ijdebic_thisCode(SThisCode* thisCode, SBuilder* data)
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
	void ijdebic_win(SWindow* win, SBuilder* data)
	{
// 		bool				isValid;										// When windows fall out of scope they are marked not valid
// 
// 		HWND				hwnd;											// The window's hwnd
// 		SBitmap*			bmp;											// Accumulation buffer for drawing
// 		RECT				rc;												// Rectangle of window's physical position
// 		SObject*			obj;											// The top-level object being rendered in this window
// 
// 		// Mouse data
// 		SMouseData			mousePrior;										// Mouse activity before the most recent mouse activity
// 		SMouseData			mouseCurrent;									// Current mouse activity
// 
// 		// For manual movement
// 		bool				isMoving;										// Is this window moving?
// 		bool				isResizing;										// Is this window resizing?
// 		SMouseData			mouseMoveResizeStart;							// The mouse data within the window when the move or resize started
// 		RECT				rcMoveResizeStart;								// The location and size of the window when the move or resize started
// 		u32					resizingFrom;									// If resizing, the arrow (upper-left, upper-right, lower-left, lower-right)
// 		s32					movingLastDeltaX;								// When moving, this was the last delta-X for the last redraw
// 		s32					movingLastDeltaY;								// When moving, this was the last delta-Y for the last redraw
// 
// 		// Updated as the mouse moves across the form
// 		POINT				mousePositionClick;								// When the mouse was last left-clicked, this is where it was clicked
// 		POINT				mousePositionClickScreen;						// In screen coordinates, the location where the mouse was last left-button clicked down
	}




//////////
//
// Called to process an object, and all its poems, into text
//
//////
	void ijdebic_obj(SObject* obj, SBuilder* data)
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
