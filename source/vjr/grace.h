//////////
//
// /libsf/source/vjr/grace.h
//
//////
// Version 0.54
// Copyright (c) 2014 by Rick C. Hodgin
//////
// Last update:
//     Nov.05.2014
//////
// Change log:
//     Nov.05.2014 - Initial creation
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




#include <GL/glew.h>
#include <GL/freeglut.h>

struct SObjNode;
struct SGraceVec;
struct SGraceRect;
struct SGraceVecLine;
struct SGraceXy;
struct SGraceLine;

#ifndef _PI2
	#define _PI2 1.570796327
#endif


//////////
// Forward declarations
//////
	void			iGrace_initGl_engine					(void);
	void			iGrace_reshape							(GLsizei w, GLsizei h);
	void			iGrace_motion							(s32 x, s32 y);
	void			iGrace_projectMousePositionToScreen		(int x, int y, f64* tfX, f64* tfY, f64* tfZ);;
	void			iGrace_passiveMotion					(s32 x, s32 y);
	void			iGrace_mouse							(s32 button, s32 state, s32 x, s32 y);
	void			iGrace_Key								(unsigned char key, s32 x, s32 y);
	void			iGrace_special							(s32 key, s32 x, s32 y);
	void			iGrace_idle								(void);
	void			iGrace_assignCoordinates				(SObject* obj, RECT* rc, f32 tfZ);

	// Render functions
	void			iGrace_display							(void);
	void			iGrace_renderBegin						(f32 tfZ);
	void			iGrace_renderEnd						(void);

	void			iGrace_animate_childrenAndSiblings		(SObject* obj, RECT* rc, bool tlRenderChildren, bool tlRenderSiblings, f32 tfZ, s64 tnMs);
	void			iiGrace_animate							(SObject* obj, s64 tnMs);

	void			iGrace_renderNode_childrenAndSiblings	(SObject* obj, bool tlRenderChildren, bool tlRenderSiblings, f32 tfZ);
	SGraceRect*		iiGrace_computeNodeLine					(SGraceVec* tsV1, SGraceVec* tsV2, f32 tfNodeWidth, bool tlIsP1East, bool tlIsP2West, s32* tnReturnVecCount);
	void			iiGrace_positionNodeVectors				(SObjNode* objNode, SGraceVec* vFrom, SGraceVec* vTo);
	void			iiGrace_computeNodeLine_fivePoints		(SGraceVec* tsV1, SGraceVec* tsV2, SGraceVec* v1, SGraceVec* v2, SGraceVec* v3, SGraceVec* v4, SGraceVec* v5, bool tlIsP1East, bool tlIsP2West);
	void			iiGrace_renderNode						(SObjNode* objNode, f32 tfNodeWidth);

	void			iGrace_renderObj_childrenAndSiblings	(SObject* obj, bool tlRenderChildren, bool tlRenderSiblings, f32 tfZ);
	void			iiGrace_renderObj						(SObject* obj);

	// Helper functions
	void			iiGrace_copyAndComputeVecLine			(SGraceVecLine* line, SGraceVec* p1, SGraceVec* p2);
	void			iiGrace_copyAndComputeLine				(SGraceLine* line, SGraceXy* p1, SGraceXy* p2);
	SGraceVec*		iiGrace_computeVecBezier3				(s32 tnSegmentCount, SGraceVec* tsV1, SGraceVec* tsV2, SGraceVec* tsV3);




//////////
// Missing from freeglut.h for some reason
//////
	#define GL_BGR			0x80E0
	#define GL_BGRA			0x80E1
	#define GLUT_WHEEL_UP	3
	#define GLUT_WHEEL_DOWN	4




//////////
// Constants to access data in vectors
//////
	#define XVEC	0
	#define YVEC	1
	#define ZVEC	2

	#define V1		0
	#define V2		1
	#define V3		2
	#define V4		3




//////////
// Structures
//////
	struct SGraceXy
	{
		f32		x;
		f32		y;
	};

	struct SGraceLine
	{
		SGraceXy	p1;							// Point 1
		SGraceXy	p2;							// Point 2

		SGraceXy	delta;						// Delta between start and end
		SGraceXy	mid;						// Midpoint

		f32			length;						// Length
		f32			m;							// Slope
		f32			mp;							// Perpendicular slope
		f32			theta;						// Theta
	};

	struct SGraceVec
	{
		f32		x;
		f32		y;
		f32		z;
	};

	struct SGraceUv
	{
		f32		s;		
		f32		t;
	};

	struct SGraceColor
	{
		f32		r;		// Red
		f32		g;		// Grn
		f32		b;		// Blu
		f32		a;		// Alpha
	};

	struct SGraceRect
	{
		// Image data
		u32				mipmap;

		// One for each corner
		SGraceColor		c[4];		// Colors
		SGraceUv		t[4];		// Texture coordinates
		SGraceVec		n[4];		// Normals
		SGraceVec		v[4];		// Vector coordinates
	};

	struct SGraceAnim
	{
		s32				msInterval;		// Number of milliseconds between frames
		s64				msNext;			// Milliseconds where next sequence happens

		SGraceRect		delta;
		SGraceRect		start;
		SGraceRect		end;
	};

	struct SGraceOgl
	{
		SGraceRect		quad;
		SGraceAnim		anim;
	};

	// This structure computes the line only on the x,y values
	struct SGraceVecLine
	{
		SGraceVec	v1;							// Vector 1
		SGraceVec	v2;							// Vector 2

		SGraceVec	delta;						// Delta between start and end
		SGraceVec	mid;						// Midpoint

		f32			length;						// Length in 3D
		f32			lengthXy;					// Length of X,Y line
		f32			lengthXz;					// Length of X,Z line
		f32			lengthYz;					// Length of Y,Z line

		f32			mXy;						// Slope of X,Y line
		f32			mXz;						// Slope of X,Z line
		f32			mYz;						// Slope of Y,Z line

		f32			mpXy;						// Perpendicular slope of X,Y line
		f32			mpXz;						// Perpendicular slope of X,Z line
		f32			mpYz;						// Perpendicular slope of Y,Z line

		f32			thetaXy;					// Theta (from p1 to p2 on X,Y line, note: add _PI to reverse the angle from p2 to p1)
		f32			thetaXz;					// Theta (from p1 to p2 on X,Z line, note: add _PI to reverse the angle from p2 to p1)
		f32			thetaYz;					// Theta (from p1 to p2 on Y,Z line, note: add _PI to reverse the angle from p2 to p1)
	};




//////////
// Variables used by Grace
//////
	s32			gnMouseX						= 400;
	s32			gnMouseY						= 400;
	bool		glMouse_leftButtonDown			= false;
	bool		glMouse_middleButtonDown		= false;
	bool		glMouse_rightButtonDown			= false;
	
	f32			gfLightViewX					= 0.0;
	f32			gfLightViewY					= 0.0;
	f32			gfLightViewZ					= 0.0;
	bool		glLighting						= false;
	GLfloat		gfv4LightFixture[]				= {  0.0, 0.0, 50.0, 1.0 };

	// Used for event tracking on when to redraw a glut loop
	s64			gnGraceEventCount				= -1;
	s64			gnFpsMilliseconds				= 1000 / 33;		// 33 fps

	// Camera position and origin
	f32			gfX								= 0.0f;
	f32			gfY								= 0.0f;
	f32			gfZ								= 15.0f;
	f32			gfZBase							= 15.0f;
	f32			gfZBase_over_2					= 7.50;

	// Used during load, indicating
	s32			gnWidth							= 800;
	s32			gnHeight						= 800;
	f32			gfPerspective					= 1.0f;
