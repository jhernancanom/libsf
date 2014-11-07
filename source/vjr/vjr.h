//////////
//
// /libsf/source/vjr/vjr.h
//
//////
// Version 0.54
// Copyright (c) 2014 by Rick C. Hodgin
//////
// Last update:
//     Feb.12.2014
//////
// Change log:
//     Feb.12.2014 - Initial creation
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

#ifndef WINVER                  // Specifies that the minimum required platform is Windows XP.
#define WINVER 0x0501           // Change this to the appropriate value to target other versions of Windows.
#endif

#ifndef _WIN32_WINNT            // Specifies that the minimum required platform is Windows XP.
#define _WIN32_WINNT 0x0501     // Change this to the appropriate value to target other versions of Windows.
#endif

#ifndef _WIN32_WINDOWS          // Specifies that the minimum required platform is Windows XP.
#define _WIN32_WINDOWS 0x0501   // Change this to the appropriate value to target Windows Me or later.
#endif

#ifndef _WIN32_IE               // Specifies that the minimum required platform is Internet Explorer 6.0.
#define _WIN32_IE 0x0600        // Change this to the appropriate value to target other versions of IE.
#endif

#ifdef __GNUC__
	#define debugbreak asm("int $3")
#else
	#define debugbreak _asm int 3;
#endif


//////////
// Aug.11.2014 -- Added to track down functions that were slowing down the system
//#define _VJR_LOG_ALL
//////
	#ifdef _VJR_LOG_ALL
		#define logfunc(x)		iVjr_appendSystemLog((s8*)x)
	#else
		#define logfunc(x)
	#endif

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <share.h>
//#include <Shobjidl.h>
#include "resource.h"
#include "settings.h"


#define _USE_MATH_DEFINES
#include <math.h>
#include "sound\SDL-1.2.15\include\sdl\SDL.h"
#include "sound\SDL-1.2.15\include\sdl\SDL_audio.h"

#include "vjr_const.h"
#include "\libsf\utils\common\cpp\builder.cpp"
#include "\libsf\utils\common\cpp\ll.cpp"
#include "vjr_structs0.h"

#include "compiler\common\compiler_common.h"

#include "compiler\vxb\const.h"
#include "compiler\vxb\structs.h"
#include "compiler\vxb\defs.h"
#include "compiler\vxb\globals.h"

#include "compiler\rdc\const.h"
#include "compiler\rdc\structs.h"
#include "compiler\rdc\defs.h"
#include "compiler\rdc\globals.h"

#include "compiler\asm\const.h"
#include "compiler\asm\structs.h"
#include "compiler\asm\defs.h"
#include "compiler\asm\globals.h"

#include "dbf\dbf.h"
#include "dbf\dbf_defs.h"

#include "grace.h"

#include "vjr_structs.h"
#include "vjr_defs.h"
#include "vjr_globals.h"

#include "command_defs.h"
#include "sound\sound.h"
#include "sem.h"
#include "sem_line.h"
#include "engine.h"
#include "object_accessors.h"
#include "graphics\bitmaps.h"




//////////
//
// Called to compute the midpoint, slope, and perpendicular slope of a line
//
//////
	struct SXYF32
	{
		f32			x;
		f32			y;
	};

	struct SLineF32
	{
		union {
			SXYF32	start;						// [input] Starting point
			SXYF32	p1;
		};

		union {
			SXYF32	end;						// [input] Ending point
			SXYF32	p2;
		};

		// The following are computed with vvm_math_computeLine()
		SXYF32		delta;						// Delta between start and end
		SXYF32		mid;						// Midpoint
		union {
			f32		length;						// Length
			f32		radius;						// Radius for the trig function
		};
		f32			m;							// Slope
		f32			mp;							// Perpendicular slope

		// Only used and computed if trig is true
		bool		trig;						// Should trig functions be computed?
		f32			theta;						// Theta (from p1 to p2, note: add _PI to reverse the angle from p2 to p1)

		// Only used and computed if ints is true
		bool		ints;						// Should integer approximations be calculated?
		union {
			SXYS32	starti;						// Starting x,y
			SXYS32	p1i;
		};
		union {
			SXYS32	endi;						// Ending x,y
			SXYS32	p2i;
		};

		// Only used and computed if quads is true
		bool		quads;						// Should we compute quadrants?
		union {
			s32		start_quad;					// What quadrant is start/p1 in?
			s32		p1_quad;
		};
		union {
			s32		end_quad;					// What quadrant is end/p2 in?
			s32		p2_quad;
		};
	};

	f32 iivvm_math_adjustTheta(f32 tfTheta)
	{
		// Validate theta is positive
		while (tfTheta < 0.0)
			tfTheta += _2PI;

		// Validate theta is 0..2pi
		while (tfTheta > _2PI)
			tfTheta -= _2PI;

		return(tfTheta);
	}

	s32 iivvm_math_computeQuad(SXYF32* p)
	{
		if (p->x >= 0.0)
		{
			// Either 1 or 4
			if (p->y >= 0.0)		return(1);		// X is positive, Y is positive
			else					return(4);		// X is positive, Y is negative

		} else {
			// Either 2 or 3
			if (p->y >= 0.0)		return(2);		// X is negative, Y is positive
			else					return(3);		// X is negative, Y is negative
		}
	}

	void iivvm_math_computeLine(SLineF32* line)
	{
		// Midpoint = (x2-x1)/2, (y2-y1)/2
		line->mid.x		= (line->p1.x + line->p2.x) / 2.0f;
		line->mid.y		= (line->p1.y + line->p2.y) / 2.0f;

		// Compute our deltas
		line->delta.x		= line->p2.x - line->p1.x;
		line->delta.y		= line->p2.y - line->p1.y;

		// Length
		line->length		= sqrt(line->delta.x*line->delta.x + line->delta.y*line->delta.y);

		// Slope = rise over run
		line->m				= line->delta.y / ((line->delta.x == 0.0f) ? 0.000001f : line->delta.x);

		// Perpendicular slope = -1/m
		line->mp			= -1.0f / ((line->m == 0.0) ? 0.000001f : line->m);


		//////////
		// Compute theta if need be (radius is same as length)
		/////
			if (line->trig)
				line->theta		= iivvm_math_adjustTheta(atan2(line->delta.y, line->delta.x));


		//////////
		// Compute the integer roundings if need be
		//////
			if (line->ints)
			{
				// Start
				line->p1i.x		= (s32)line->p1.x;
				line->p1i.y		= (s32)line->p1.y;
				// End
				line->p2i.x		= (s32)line->p2.x;
				line->p2i.y		= (s32)line->p2.y;
			}


		//////////
		// Compute the quadrants if need be
		//////
			if (line->quads)
			{
				// Quads 1..4
				line->p1_quad	= iivvm_math_computeQuad(&line->p1);
				line->p2_quad	= iivvm_math_computeQuad(&line->p2);
			}
	}

	void iivvm_copyLine(SLineF32* line, SXYF32* p1, SXYF32* p2, bool tlComputeLine)
	{
		// Copy
		memcpy(&line->p1, p1, sizeof(line->p1));
		memcpy(&line->p2, p2, sizeof(line->p2));

		// Compute if need be
		if (tlComputeLine)
			iivvm_math_computeLine(line);
	}




//////////
//
// Called to draw or generate the bezier using 3 points
//
//////
	SXYF32* iivvm_canvasBezier3(s32 tnSegments, SXYF32* tfP1, SXYF32* tfP2, SXYF32* tfP3)
	{
		s32				lnI;
		f32				lfPercent, lfCosTheta1, lfSinTheta1, lfCosTheta2, lfSinTheta2;
		SXYF32			p1, p2, pbez;
		SLineF32		l1, l2;		// Lines from bez->p1 to bez->p2, and bez->p2 to bez->p3
		SLineF32		lmid;		// Line from l1 to l2
		SXYF32*			points;


		// Allocate our return buffer
		points = (SXYF32*)malloc(tnSegments * sizeof(SXYF32));
		memset(points, 0, tnSegments * sizeof(SXYF32));


		//////////
		// Copy and compute our lines
		//////
			iivvm_copyLine(&l1, tfP1, tfP2, true);
			iivvm_copyLine(&l2, tfP2, tfP3, true);


		//////////
		// Compute our thetas for rapid use
		//////
			// L1
			lfCosTheta1		= cos(l1.theta);
			lfSinTheta1		= sin(l1.theta);
			// L2
			lfCosTheta2		= cos(l2.theta);
			lfSinTheta2		= sin(l2.theta);


		//////////
		// Now, iterate through the bezier building the points
		//////
			for (lnI = 0; lnI < tnSegments; lnI++)
			{
				//////////
				// Get our percentage
				//////
					lfPercent = (f32)lnI / (f32)tnSegments;


				//////////
				// Determine the two points for l1 and l2
				//////
					// P1, L1
					p1.x = tfP1->x + (lfPercent * l1.radius * lfCosTheta1);
					p1.y = tfP1->y + (lfPercent * l1.radius * lfSinTheta1);
					// P2, L2
					p2.x = tfP2->x + (lfPercent * l2.radius * lfCosTheta2);
					p2.y = tfP2->y + (lfPercent * l2.radius * lfSinTheta2);


				//////////
				// Construct the line between
				//////
					iivvm_copyLine(&lmid, &p1, &p2, true);


				//////////
				// Derive the position of this bezier point
				//////
					// PBEZ
					pbez.x = lmid.p1.x + (lfPercent * lmid.radius * cos(lmid.theta));
					pbez.y = lmid.p1.y + (lfPercent * lmid.radius * sin(lmid.theta));


				//////////
				// Store the point
				//////
					points[lnI].x = pbez.x;
					points[lnI].y = pbez.y;
			}

		return(points);
	}


#include "vjr_sup.cpp"
#include "objects.cpp"
#include "object_accessors.cpp"
#include "callbacks.cpp"
#include "events.cpp"
#include "bitmaps.cpp"
#include "compiler\vxb\vxb_compiler.cpp"
#include "compiler\rdc\rdc_compiler.cpp"
#include "compiler\asm\asm_compiler.cpp"
#include "commands.cpp"
#include "engine.cpp"
#include "sem.cpp"
#include "sem_line.cpp"
#include "sound\sound.cpp"
#include "dbf\dbc.cpp"
#include "dbf\dbf.cpp"
#include "dbf\cdx.cpp"
#include "grace.cpp"
