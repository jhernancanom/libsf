//////////
//
// /libsf/source/vjr/grace.cpp
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
	// x, y, z
	#define XVEC	0
	#define YVEC	1
	#define ZVEC	2

	// Red, green, blue, alpha
	#define RVEC	0
	#define GVEC	1
	#define BVEC	2
	#define AVEC	3
	#define CTOTAL	16

	// Offset to reach the vectors stored successively inside the array
	#define T1		0		// 0th position (t1x=0  t1y=1)
	#define T2		2		// 2nd position (t1x=2  t1y=3)
	#define T3		4		// 4th position (t1x=4  t1y=5)
	#define T4		6		// 6th position (t1x=6  t1y=7)
	#define THANDLE	8		// 8th position (holds the handle (memory pointer) to STexData structure
	#define TTOTAL	9
	#define TSTEP	2

	#define V1		0		// 0th position (v1x=0   v1x=1   v1z=2)
	#define V2		3		// 3rd position (v2x=3   v2y=4   v2z=5)
	#define V3		6		// 6th position (v3x=6   v3y=7   v3z=8)
	#define V4		9		// 9th position (v4x=9   v4y=10  v4z=11)
	#define VTOTAL	12
	#define VSTEP	3

	#define N1		0		// 0th position (n1x=0   n1x=1   n1z=2)
	#define N2		3		// 3rd position (n2x=3   n2y=4   n2z=5)
	#define N3		6		// 6th position (n3x=6   n3y=7   n3z=8)
	#define N4		9		// 9th position (n4x=9   n4y=10  n4z=11)
	#define NTOTAL	12
	#define NSTEP	3




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
	u32			texture							= 0;
	s32			gnWidth							= 800;
	s32			gnHeight						= 800;
	f32			gfPerspective					= 1.0f;


////////
// Pointer for vector arrays
//////
	GLfloat*	c								= NULL;		// color
	GLfloat*	t								= NULL;		// texture
	GLfloat*	n								= NULL;		// normals
	GLfloat*	v								= NULL;		// vector
	GLfloat*	vo								= NULL;		// vector original




//////////
// Added to create and debug a basic 3D rendering screen
//////
	DWORD WINAPI iGrace(LPVOID param)
	{
		RECT		lrc;
		s64			lnLastUpdateCount;
		s32			argc;
		s8*			argv[1];
		s64			lnLastMilliseconds, lnNowMilliseconds;
		SYSTEMTIME	timeNow;


		// Create fake startups for glut
		argc = 1;
		argv[0] = (s8*)&"vjr.exe";

		GetWindowRect(GetDesktopWindow(), &lrc);
		gnWidth		= (lrc.right - lrc.left) * 3 / 4;
		gnHeight	= (lrc.bottom - lrc.top) * 3 / 4;
		glutInitWindowSize(gnWidth, gnHeight);
		glutInitWindowPosition(0, 0);
		glutInit(&argc, argv);
		glewInit();
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_MULTISAMPLE);
		glutCreateWindow("Grace");

		// Initialize
		iGrace_reshape(gnWidth, gnHeight);

		// Setup
		glutMouseFunc			(iGrace_mouse);
		glutMotionFunc			(iGrace_motion);
		glutPassiveMotionFunc	(iGrace_passiveMotion);
		glutKeyboardFunc		(iGrace_Key);
		glutSpecialFunc			(iGrace_special);
		glutReshapeFunc			(iGrace_reshape);
		glutDisplayFunc			(iGrace_display);
		glutIdleFunc			(iGrace_idle);

		// See if we can load the file they've specified
		Sleep(100);
		iGrace_createOpenGlVisualization();


		//////////
		// Main loop
		//////
			GetSystemTime(&timeNow);
			lnLastMilliseconds	= iTime_computeMilliseconds(&timeNow);
			lnLastUpdateCount	= 0;
			while (!glShuttingDown)
			{
				// If it's time, execute a loop
				if (gnGraceEventCount != lnLastUpdateCount)
				{
					lnLastUpdateCount = gnGraceEventCount;
					glutMainLoopEvent();

				} else {
					// Fire at our fps
					GetSystemTime(&timeNow);
					lnNowMilliseconds	= iTime_computeMilliseconds(&timeNow);
					if (lnNowMilliseconds - lnLastMilliseconds > gnFpsMilliseconds)
					{
						lnLastMilliseconds = lnNowMilliseconds;
						++gnGraceEventCount;
					}
				}

				// Sleep for 1 ms
				Sleep(1);
			}

		// Control will never return here
		return(0);
	}



	void iGrace_initGl_engine(void)
	{
		glMatrixMode	(GL_SMOOTH);

//////////
// We do not presently compute normals, so lighting is disabledd
// 		if (glLighting)
// 		{
// 			glEnable	(GL_LIGHTING);
// 			glEnable	(GL_LIGHT0);
// 			glMatrixMode(GL_LIGHT_MODEL_AMBIENT);
// 
// 		} else {
			glDisable	(GL_LIGHTING);
// 		}
//////////

		glEnable		(GL_DEPTH_TEST);
		glEnable		(GL_COLOR);
		glEnable		(GL_COLOR_MATERIAL);
		glEnable		(GL_ALPHA_TEST);
		glAlphaFunc		(GL_GREATER, 0.016f);
		glEnable		(GL_BLEND);
		glBlendFunc		(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glEnable		(GL_TEXTURE_2D);
		glTexEnvf		(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_SPHERE_MAP/*GL_DECAL*//*GL_MODULATE*/);
		glTexParameterf	(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
		glTexParameterf	(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameterf	(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameterf	(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		// White
		glClearColor(1.0, 1.0, 1.0, 1.0);
	}



	void iGrace_reshape(GLsizei w, GLsizei h)
	{
		gnWidth			= w;
		gnHeight		= h;
		//gfPerspective	= (GLfloat)w / (GLfloat)h;
		// Decided to use a fixed perspective for this app.  May change this later.
		gfPerspective = 1.0f;
		glViewport		(0, 0, w, h);
		glMatrixMode	(GL_PROJECTION);
		glLoadIdentity	();
		gluPerspective	(45.0, gfPerspective, 1.0, 10000.0);
		iGrace_initGl_engine();
	}



	// Mouse motion with buttons down in the window
	void iGrace_motion(s32 tnMouseX, s32 tnMouseY)
	{
		f32		lfPixelsX, lfPixelsY;
		f64		lfX_new, lfY_new, lfZ_new, lfX_old, lfY_old, lfZ_old;
		bool	llRedisplay;


		//////////
		// Initialize
		//////
			lfPixelsX	= (f32)(gnMouseX - tnMouseX) / 50.0f;
			lfPixelsY	= (f32)(gnMouseY - tnMouseY) / 50.0f;
			llRedisplay	= false;


		//////////
		// Based on the current view, pixels on-screen correlate to different visible deltas
		//////
			iGrace_projectMousePositionToScreen(gnMouseX, gnMouseY, &lfX_new, &lfY_new, &lfZ_new);
			iGrace_projectMousePositionToScreen(tnMouseX, tnMouseY, &lfX_old, &lfY_old, &lfZ_old);


		/////////
		// Left button
		//////
			if (glMouse_leftButtonDown && !glMouse_rightButtonDown)
			{
				// Left-mouse only
				llRedisplay = true;
				gfX += (f32)(lfX_new - lfX_old);
				gfY += (f32)(lfY_new - lfY_old);


		//////////
		// Right button
		//////
			} else if (!glMouse_leftButtonDown && glMouse_rightButtonDown) {
				// Right-mouse only


		//////////
		// Both buttons
		//////
			} else {
				// Both-buttons down
			}


		//////////
		// Store the new mouse position
		//////
			gnMouseX = tnMouseX;
			gnMouseY = tnMouseY;


		//////////
		// Redraw if need be
		//////
			if (llRedisplay)
			{
				++gnGraceEventCount;
				glutPostRedisplay();
			}
	}




	// Called to project window mouse coordinates into the GL buffer and obtain the object at those coordinates
	// Note:  To prevent it from returning something invalid, I always use a background behind everything.
	void iGrace_projectMousePositionToScreen(int x, int y, f64* tfX, f64* tfY, f64* tfZ)
	{
		//////////
		// Code refactored from source, but generally used as is:
		// Adpated from a post on this thread:
		//		https://www.opengl.org/discussion_boards/showthread.php/138411-Mouse-Coordinates
		// START
		//////
			f32		winX, winY, winZ;
			s32		viewport[4];
			f64		modelview[16];
			f64		projection[16];

			glGetDoublev(GL_MODELVIEW_MATRIX,	modelview);
			glGetDoublev(GL_PROJECTION_MATRIX,	projection);
			glGetIntegerv(GL_VIEWPORT,			viewport);

			winX = (float)x;
			winY = (float)gnHeight - (float)y; //(float)viewport[3] - (float)mouse.y;
			winZ;

			glReadPixels((int)winX, int(winY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ);
			if (winZ == 1.0)
			{
				// No ojbect at that location
				*tfX = 0.0f;
				*tfY = 0.0f;
				*tfZ = 0.0f;

			} else {
				// Obtain the translated form
				gluUnProject(winX, winY, winZ, modelview, projection, viewport, tfX, tfY, tfZ);
			}
		//////
		// END
		//////////
	}




	void iGrace_passiveMotion(s32 x, s32 y)
	{
		bool llRedisplay;


		llRedisplay = false;

		// Mouse motion without buttons down over the window
		// Note currently processed


		if (llRedisplay)
		{
			++gnGraceEventCount;
			glutPostRedisplay();
		}
	}



	void iGrace_mouse(s32 button, s32 state, s32 x, s32 y)
	{
		bool llRedisplay;


		llRedisplay = false;
		if (state == GLUT_DOWN)
		{
			gnMouseX = x;
			gnMouseY = y;
			switch (button)
			{
				case GLUT_LEFT_BUTTON:
					glMouse_leftButtonDown	= true;
					break;

				case GLUT_MIDDLE_BUTTON:
					glMouse_middleButtonDown = true;
					break;

				case GLUT_RIGHT_BUTTON:
					glMouse_rightButtonDown	= true;
					break;

				case GLUT_WHEEL_UP:		// Wheel up, moving in
					gfZ			-= (gfZ / gfZBase);		// Decelerates the closer in we get
					llRedisplay = true;
					break;

				case GLUT_WHEEL_DOWN:	// Wheel down, moving out
					gfZ			+= (gfZ / gfZBase);		// Accelerates the further out we get
					llRedisplay	= true;
					break;
			}
			gfZ = min(max(gfZ, 4.0f), 200.0f);

		} else {	
			glMouse_leftButtonDown		= false;
			glMouse_middleButtonDown	= false;
			glMouse_rightButtonDown		= false;
		}

		if (llRedisplay)
		{
			++gnGraceEventCount;
			glutPostRedisplay();
		}
	}



	void iGrace_Key(unsigned char key, s32 x, s32 y)
	{
		bool llRedisplay;


		llRedisplay = false;
		switch (key)
		{
			case 27:	// Escape
			case 'q':
			case 'Q':
///				exit(0);
				break;

			case 'z':
			case 'Z':
				gfZ			= gfZBase;
				llRedisplay	= true;
				break;
		}

		if (llRedisplay)
		{
			++gnGraceEventCount;
			glutPostRedisplay();
		}
	}


	void iGrace_special(s32 key, s32 x, s32 y)
	{
		bool llRedisplay;


		// Special keystroke processing
		llRedisplay = false;
		switch(key)
		{
			case  GLUT_KEY_F1:
			case  GLUT_KEY_F2:
			case  GLUT_KEY_F3:
			case  GLUT_KEY_F4:
			case  GLUT_KEY_F5:
			case  GLUT_KEY_F6:
			case  GLUT_KEY_F7:
			case  GLUT_KEY_F8:
			case  GLUT_KEY_F9:
			case  GLUT_KEY_F10:
			case  GLUT_KEY_F11:
			case  GLUT_KEY_F12:
			case  GLUT_KEY_LEFT:
			case  GLUT_KEY_UP:
			case  GLUT_KEY_RIGHT:
			case  GLUT_KEY_DOWN:
			case  GLUT_KEY_PAGE_UP:
			case  GLUT_KEY_PAGE_DOWN:
			case  GLUT_KEY_HOME:
			case  GLUT_KEY_END:
			case  GLUT_KEY_INSERT:
				break;
		}

		if (llRedisplay)
		{
			++gnGraceEventCount;
			glutPostRedisplay();
		}
	}




	void iGrace_idle(void)
	{
		// Not really used any longer because we no longer use glutMainLoop() but rather glutMainLoopEvent()
	}




	void iGrace_createOpenGlVisualization(void)
	{
		s32		lnBitDepth, lnWidth, lnHeight;
		u32		lnRecno, lcBase, lvBase, ltBase;
		RECT	lrc;


		// Get the desktop size
		GetWindowRect(GetDesktopWindow(), &lrc);
		lnWidth		= lrc.right - lrc.left;
		lnHeight	= lrc.bottom - lrc.top;

		// c  = colors
		// t  = texture coordinates
		// n  = normals
		// v  = vector coordinates
		// vo = vector coordinates original (before animation)
		gnReccount = 2;
		if (c == NULL)
		{
			c	= (GLfloat*)malloc(gnReccount * sizeof(GLfloat*) * CTOTAL);
			t	= (GLfloat*)malloc(gnReccount * sizeof(GLfloat*) * TTOTAL);
			n	= (GLfloat*)malloc(gnReccount * sizeof(GLfloat*) * NTOTAL);
			v	= (GLfloat*)malloc(gnReccount * sizeof(GLfloat*) * VTOTAL);
			vo	= (GLfloat*)malloc(gnReccount * sizeof(GLfloat*) * VTOTAL);

			memset(c,  0, gnReccount * sizeof(GLfloat*) * CTOTAL);
			memset(t,  0, gnReccount * sizeof(GLfloat*) * TTOTAL);
			memset(n,  0, gnReccount * sizeof(GLfloat*) * NTOTAL);
			memset(v,  0, gnReccount * sizeof(GLfloat*) * VTOTAL);
			memset(vo, 0, gnReccount * sizeof(GLfloat*) * VTOTAL);
		}


		//////////
		// Drop a large background for the virtual desktop
		//////
			//////////
			// Create offsets for base of each group
			//////
				lvBase = 0;
				lcBase = 0;
				ltBase = 0;


			//////////
			// Vectors
			//////
				v[lvBase + V1 + XVEC]	= gfZBase * -100.0f * gfPerspective;
				v[lvBase + V1 + YVEC]	= gfZBase * -100.0f;
				v[lvBase + V1 + ZVEC]	= -0.01f;

				v[lvBase + V2 + XVEC]	= gfZBase * 100.0f * gfPerspective;
				v[lvBase + V2 + YVEC]	= gfZBase * -100.0f;
				v[lvBase + V2 + ZVEC]	= -0.01f;

				v[lvBase + V3 + XVEC]	= gfZBase * 100.0f * gfPerspective;
				v[lvBase + V3 + YVEC]	= gfZBase * 100.0f;
				v[lvBase + V3 + ZVEC]	= -0.01f;

				v[lvBase + V4 + XVEC]	= gfZBase * -100.0f * gfPerspective;
				v[lvBase + V4 + YVEC]	= gfZBase * 100.0f;
				v[lvBase + V4 + ZVEC]	= -0.01f;


			//////////
			// Vector original values
			//////
				vo[lvBase + V1 + XVEC]	= v[lvBase + V1 + XVEC];			// Original vector 1
				vo[lvBase + V1 + YVEC]	= v[lvBase + V1 + YVEC];
				vo[lvBase + V1 + ZVEC]	= v[lvBase + V1 + ZVEC];

				vo[lvBase + V2 + XVEC]	= v[lvBase + V2 + XVEC];			// Original vector 2
				vo[lvBase + V2 + YVEC]	= v[lvBase + V2 + YVEC];
				vo[lvBase + V2 + ZVEC]	= v[lvBase + V2 + ZVEC];

				vo[lvBase + V3 + XVEC]	= v[lvBase + V3 + XVEC];			// Original vector 3
				vo[lvBase + V3 + YVEC]	= v[lvBase + V3 + YVEC];
				vo[lvBase + V3 + ZVEC]	= v[lvBase + V3 + ZVEC];

				vo[lvBase + V4 + XVEC]	= v[lvBase + V4 + XVEC];			// Original vector 4
				vo[lvBase + V4 + YVEC]	= v[lvBase + V4 + YVEC];
				vo[lvBase + V4 + ZVEC]	= v[lvBase + V4 + ZVEC];


			//////////
			// Colors
			//////
				c[lcBase + RVEC]		= 1.0f;
				c[lcBase + GVEC]		= 1.0f;
				c[lcBase + BVEC]		= 1.0f;
				c[lcBase + AVEC]		= 1.0f;


		// Iterate through the records, loading the vector data into the arrays
		for (lnRecno = 2; lnRecno <= gnReccount; lnRecno++, gnGraceEventCount++)
		{
			//////////
			// Create offsets for base of each group
			//////
				lvBase = (lnRecno - 1) * VTOTAL;
				lcBase = (lnRecno - 1) * CTOTAL;
				ltBase = (lnRecno - 1) * TTOTAL;


			//////////
			// Vectors
			//////
				v[lvBase + V1 + XVEC]	= (-gfZBase_over_2) * ((f32)_jdebi->bmp->bi.biWidth  / lnWidth) * gfPerspective;
				v[lvBase + V1 + YVEC]	= (-gfZBase_over_2) * ((f32)_jdebi->bmp->bi.biHeight / lnHeight);// * gfPerspective;
				v[lvBase + V1 + ZVEC]	= 0.0f;

				v[lvBase + V2 + XVEC]	= (+gfZBase_over_2) * ((f32)_jdebi->bmp->bi.biWidth / lnWidth) * gfPerspective;
				v[lvBase + V2 + YVEC]	= v[lvBase + V1 + YVEC];
				v[lvBase + V2 + ZVEC]	= 0.0f;

				v[lvBase + V3 + XVEC]	= v[lvBase + V2 + XVEC];
				v[lvBase + V3 + YVEC]	= (+gfZBase_over_2) * ((f32)_jdebi->bmp->bi.biHeight / lnHeight);// * gfPerspective;
				v[lvBase + V3 + ZVEC]	= 0.0f;

				v[lvBase + V4 + XVEC]	= v[lvBase + V1 + XVEC];
				v[lvBase + V4 + YVEC]	= v[lvBase + V3	+ YVEC];
				v[lvBase + V4 + ZVEC]	= 0.0f;


			//////////
			// Vector original values
			//////
				vo[lvBase + V1 + XVEC]	= v[lvBase + V1 + XVEC];			// Original vector 1
				vo[lvBase + V1 + YVEC]	= v[lvBase + V1 + YVEC];
				vo[lvBase + V1 + ZVEC]	= v[lvBase + V1 + ZVEC];

				vo[lvBase + V2 + XVEC]	= v[lvBase + V2 + XVEC];			// Original vector 2
				vo[lvBase + V2 + YVEC]	= v[lvBase + V2 + YVEC];
				vo[lvBase + V2 + ZVEC]	= v[lvBase + V2 + ZVEC];

				vo[lvBase + V3 + XVEC]	= v[lvBase + V3 + XVEC];			// Original vector 3
				vo[lvBase + V3 + YVEC]	= v[lvBase + V3 + YVEC];
				vo[lvBase + V3 + ZVEC]	= v[lvBase + V3 + ZVEC];

				vo[lvBase + V4 + XVEC]	= v[lvBase + V4 + XVEC];			// Original vector 4
				vo[lvBase + V4 + YVEC]	= v[lvBase + V4 + YVEC];
				vo[lvBase + V4 + ZVEC]	= v[lvBase + V4 + ZVEC];


			//////////
			// Colors
			//////
				c[lcBase + RVEC]		= 0.98f;
				c[lcBase + GVEC]		= 0.98f;
				c[lcBase + BVEC]		= 0.98f;
				c[lcBase + AVEC]		= 1.0f;


			//////////
			// Do texture coordinates (regardless of whether or not there is texture information
			//////
				// Upper-left
				t[ltBase + T1 + XVEC]	= 0.0f;
				t[ltBase + T1 + YVEC]	= 0.0f;

				// Upper-right
				t[ltBase + T2 + XVEC]	= 1.0f;
				t[ltBase + T2 + YVEC]	= 0.0f;

				// Lower-right
				t[ltBase + T3 + XVEC]	= 1.0f;
				t[ltBase + T3 + YVEC]	= 1.0f;

				// Lower-left
				t[ltBase + T4 + XVEC]	= 0.0f;
				t[ltBase + T4 + YVEC]	= 1.0f;


			//////////
			// Create the texture
			//////
				// Delete any previous texture
				if (*(GLuint*)&t[ltBase + THANDLE] != -1)
					glDeleteTextures(1, (GLuint*)&t[ltBase + THANDLE]);

				// Generate a new texture
				glGenTextures(1, (GLuint*)&texture);

				// Mipmap the image
				glBindTexture(GL_TEXTURE_2D, texture);
				lnBitDepth = ((_jdebi->bmp->bi.biBitCount == 24) ? GL_BGR : GL_BGRA);
				gluBuild2DMipmaps(GL_TEXTURE_2D, 3, _jdebi->bmp->bi.biWidth, _jdebi->bmp->bi.biHeight, lnBitDepth, GL_UNSIGNED_BYTE, _jdebi->bmp->bd);
				*(GLuint*)&t[ltBase + THANDLE] = texture;
		}
	}


	void iGrace_display(void)
	{
		u32 lnRecno;
		u32 lncBase, lntBase, lnvBase, lnnBase;


		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glPushMatrix();

		// Always looking straight forward at the x,y coordinate from the zoomed in z location
		gluLookAt(gfX, gfY, gfZ,
				  gfX, gfY, 0.0, 
				  0.0, 1.0, 0.0);

		if (glLighting)
		{
			// Indicate where the light is
			gfv4LightFixture[XVEC] = gfLightViewX;
			gfv4LightFixture[YVEC] = gfLightViewY;
			gfv4LightFixture[ZVEC] = (gfLightViewX + gfLightViewY) / (f32)2.0;
			glLightfv(GL_LIGHT0, GL_POSITION, gfv4LightFixture);

			glPushMatrix(); 
			glTranslatef	(gfv4LightFixture[XVEC], gfv4LightFixture[YVEC], gfv4LightFixture[ZVEC]);
			glDisable(GL_LIGHTING);
			glColor3f		(1.0, 1.0, 0.0);
			glutWireCube	(1.0);
			glEnable(GL_LIGHTING);
			glPopMatrix();
		}

		// Only draw if there are things to draw
		if (t && v && n)
		{
			for (lnRecno = 1; lnRecno <= gnReccount; ++lnRecno)
			{
				// Create the base offsets into the arrays
				lncBase = (lnRecno - 1) * CTOTAL;
				lntBase = (lnRecno - 1) * TTOTAL;
				lnvBase = (lnRecno - 1) * VTOTAL;
				lnnBase = (lnRecno - 1) * NTOTAL;

				// Set the color
 				glColor4f(c[lncBase + RVEC], c[lncBase + GVEC], c[lncBase + BVEC], c[lncBase + AVEC]);

// 				// Provide any animation for this object
// 				iGrace_animateObject(lnvBase);

				// Bind the texture for this quad
				glBindTexture(GL_TEXTURE_2D, *(GLuint*)&t[lntBase + THANDLE]);

				// Based on whether or not there's texture information, do the texture coords
				glBegin(GL_QUADS);

					glTexCoord2d(t[lntBase + T1 + XVEC], t[lntBase + T1 + YVEC]);
					glNormal3f	(n[lnnBase + N1 + XVEC], n[lnnBase + N1 + YVEC], n[lnnBase + N1 + ZVEC]);
					glVertex3f  (v[lnvBase + V1 + XVEC], v[lnvBase + V1 + YVEC], v[lnvBase + V1 + ZVEC]);

					glTexCoord2d(t[lntBase + T2 + XVEC], t[lntBase + T2 + YVEC]);
					glNormal3f	(n[lnnBase + N2 + XVEC], n[lnnBase + N2 + YVEC], n[lnnBase + N2 + ZVEC]);
					glVertex3f  (v[lnvBase + V2 + XVEC], v[lnvBase + V2 + YVEC], v[lnvBase + V2 + ZVEC]);

					glTexCoord2d(t[lntBase + T3 + XVEC], t[lntBase + T3 + YVEC]);
					glNormal3f	(n[lnnBase + N3 + XVEC], n[lnnBase + N3 + YVEC], n[lnnBase + N3 + ZVEC]);
					glVertex3f  (v[lnvBase + V3 + XVEC], v[lnvBase + V3 + YVEC], v[lnvBase + V3 + ZVEC]);

					glTexCoord2d(t[lntBase + T4 + XVEC], t[lntBase + T4 + YVEC]);
					glNormal3f	(n[lnnBase + N4 + XVEC], n[lnnBase + N4 + YVEC], n[lnnBase + N4 + ZVEC]);
					glVertex3f  (v[lnvBase + V4 + XVEC], v[lnvBase + V4 + YVEC], v[lnvBase + V4 + ZVEC]);

				glEnd();
			}
		}

		glPopMatrix();
		glutSwapBuffers();
	}
