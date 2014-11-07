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




	void iGrace_assignCoordinates(SObject* obj, RECT* rc, f32 tfZ)
	{
		s32		lnI, lnWidth, lnHeight;
		RECT	lrcDesktop;


		//////////
		// Get the desktop size
		//////
			GetWindowRect(GetDesktopWindow(), &lrcDesktop);
			lnWidth		= lrcDesktop.right - lrcDesktop.left;
			lnHeight	= lrcDesktop.bottom - lrcDesktop.top;


		//////////
		// Vectors
		//////
			// Upper-left
			obj->ogl.quad.v[V1].x	= (gfZBase_over_2) * ((f32)rc->left	/ lnWidth) * gfPerspective;
			obj->ogl.quad.v[V1].y	= (-gfZBase_over_2) * ((f32)rc->top		/ lnHeight);
			obj->ogl.quad.v[V1].z	= tfZ;

			obj->ogl.quad.v[V2].x	= (gfZBase_over_2) * ((f32)rc->right	/ lnWidth) * gfPerspective;
			obj->ogl.quad.v[V2].y	= obj->ogl.quad.v[V1].y;
			obj->ogl.quad.v[V2].z	= tfZ;

			obj->ogl.quad.v[V3].x	= obj->ogl.quad.v[V2].x;
			obj->ogl.quad.v[V3].y	= (-gfZBase_over_2) * ((f32)rc->bottom	/ lnHeight);
			obj->ogl.quad.v[V3].z	= tfZ;

			obj->ogl.quad.v[V4].x	= obj->ogl.quad.v[V1].x;
			obj->ogl.quad.v[V4].y	= obj->ogl.quad.v[V3].y;
			obj->ogl.quad.v[V4].z	= tfZ;


		//////////
		// Copy vectors to original values
		//////
			memcpy(&obj->ogl.quad.vo, obj->ogl.quad.v, sizeof(obj->ogl.quad.v));


		//////////
		// Colors
		//////
			for (lnI = 0; lnI <= V4; lnI++)
			{
				obj->ogl.quad.c[lnI].r = 0.98f;	// Red
				obj->ogl.quad.c[lnI].g = 0.98f;	// Grn
				obj->ogl.quad.c[lnI].b = 0.98f;	// Blu
				obj->ogl.quad.c[lnI].a = 1.0f;	// Alp
			}


		//////////
		// Do texture coordinates (regardless of whether or not there is texture information
		//////
			// Upper-left
			obj->ogl.quad.t[V1].s	= 0.0f;
			obj->ogl.quad.t[V1].t	= 1.0f;

			// Upper-right
			obj->ogl.quad.t[V2].s	= 1.0f;
			obj->ogl.quad.t[V2].t	= 1.0f;

			// Lower-right
			obj->ogl.quad.t[V3].s	= 1.0f;
			obj->ogl.quad.t[V3].t	= 0.0f;

			// Lower-left
			obj->ogl.quad.t[V4].s	= 0.0f;
			obj->ogl.quad.t[V4].t	= 0.0f;


		//////////
		// Texture ops
		//////
			if (obj->bmp && obj->bmp->bd && obj->ogl.quad.mipmap == 0)
			{
				// Delete any previous texture
				glDeleteTextures(1, &obj->ogl.quad.mipmap);

				// Generate a new texture
				glGenTextures(1, &obj->ogl.quad.mipmap);

				// Mipmap the image
				glBindTexture(GL_TEXTURE_2D, obj->ogl.quad.mipmap);
				gluBuild2DMipmaps(GL_TEXTURE_2D, 3, obj->bmp->bi.biWidth, obj->bmp->bi.biHeight, ((obj->bmp->bi.biBitCount == 24) ? GL_BGR : GL_BGRA), GL_UNSIGNED_BYTE, obj->bmp->bd);
			}
	}




	void iGrace_display(void)
	{
		RECT lrc;


		// Render if we have something to render
		if (gWinJDebi && gWinJDebi->obj)
		{
			// We will be building centered around the origin
			SetRect(&lrc, -(gWinJDebi->rc.right - gWinJDebi->rc.left) / 2, -(gWinJDebi->rc.bottom - gWinJDebi->rc.top) / 2, 0, 0);
			SetRect(&lrc, lrc.left, lrc.top, lrc.left + (gWinJDebi->rc.right - gWinJDebi->rc.left), lrc.top + (gWinJDebi->rc.bottom - gWinJDebi->rc.top));

			// Render
			iGrace_renderChildrenAndSiblings(gWinJDebi->obj, &lrc, true, true, true, true, 0.0f);
		}
	}




	void iGrace_renderChildrenAndSiblings(SObject* obj, RECT* rc, bool tlRootRender, bool tlRenderChildren, bool tlRenderSiblings, bool tlForceRender, f32 tfZ)
	{
		RECT		lrc, lrcClient;
		SObject*	objSib;


		logfunc(__FUNCTION__);
		//////////
		// Make sure there is render data
		//////
			if (!obj || !isVisible(obj) && !isEnabled(obj))
				return;


		//////////
		// Render begin
		//////
			if (tlRootRender)
			{
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

				// Render the white background
				glBegin(GL_QUADS);

					glColor4f	(1.0f, 1.0f, 1.0f, 1.0f);
					glVertex3f	(-1000.0f, -1000.0f, tfZ - 0.01f);
					glVertex3f	(1000.0f, -1000.0f, tfZ - 0.01f);
					glVertex3f	(1000.0f, 1000.0f, tfZ - 0.01f);
					glVertex3f	(-1000.0f, 1000.0f, tfZ - 0.01f);

				glEnd();

			}

		
		//////////
		// Adjust the coordinates for this item
		//////
			SetRect(&lrc,		rc->left	+ obj->rc.left,
								rc->top		+ obj->rc.top,
								rc->left	+ obj->rc.left			+ obj->bmp->bi.biWidth,
								rc->top		+ obj->rc.top			+ obj->bmp->bi.biHeight);

			SetRect(&lrcClient,	rc->left	+ obj->rcClient.left,
								rc->top		+ obj->rcClient.top,
								rc->left	+ obj->rcClient.left	+ obj->bmp->bi.biWidth,
								rc->top		+ obj->rcClient.top		+ obj->bmp->bi.biHeight);


		//////////
		// Render any children
		//////
			if (tlRenderChildren && obj->firstChild)
				iGrace_renderChildrenAndSiblings(obj->firstChild, &lrcClient, false, true, true, tlForceRender, tfZ + 0.01f);


		//////////
		// Render self
		//////
			obj->isDirtyRender |= tlForceRender;
			iGrace_assignCoordinates(obj, &lrc, tfZ);
			iGrace_render(obj, tlForceRender);


		//////////
		// Render any siblings
		//////
			if (tlRenderSiblings && obj->ll.next)
			{
				objSib = (SObject*)obj->ll.next;
				while (objSib)
				{
					// Render this sibling
					iGrace_renderChildrenAndSiblings(objSib, rc, false, true, false, tlForceRender, tfZ);

					// Move to next sibling
					objSib = (SObject*)objSib->ll.next;
				}
			}


		//////////
		// Render finish
		//////
			if (tlRootRender)
			{
				glPopMatrix();
				glutSwapBuffers();
			}
	}




	void iGrace_render(SObject* obj, bool tlForceRender)
	{
//		// Provide any animation for this object
//		iGrace_animateObject(lnvBase);

		// Bind the texture for this quad
		glBindTexture(GL_TEXTURE_2D, obj->ogl.quad.mipmap);

		// Based on whether or not there's texture information, do the texture coords
		glBegin(GL_QUADS);

			glColor4f		(obj->ogl.quad.c[V1].r, obj->ogl.quad.c[V1].g, obj->ogl.quad.c[V1].b, obj->ogl.quad.c[V1].a);
			glTexCoord2d	(obj->ogl.quad.t[V1].s, obj->ogl.quad.t[V1].t);
			glNormal3f		(obj->ogl.quad.n[V1].x, obj->ogl.quad.n[V1].y, obj->ogl.quad.n[V1].z);
			glVertex3f		(obj->ogl.quad.v[V1].x, obj->ogl.quad.v[V1].y, obj->ogl.quad.v[V1].z);

			glColor4f		(obj->ogl.quad.c[V2].r, obj->ogl.quad.c[V2].g, obj->ogl.quad.c[V2].b, obj->ogl.quad.c[V2].a);
			glTexCoord2d	(obj->ogl.quad.t[V2].s, obj->ogl.quad.t[V2].t);
			glNormal3f		(obj->ogl.quad.n[V2].x, obj->ogl.quad.n[V2].y, obj->ogl.quad.n[V2].z);
			glVertex3f		(obj->ogl.quad.v[V2].x, obj->ogl.quad.v[V2].y, obj->ogl.quad.v[V2].z);

			glColor4f		(obj->ogl.quad.c[V3].r, obj->ogl.quad.c[V3].g, obj->ogl.quad.c[V3].b, obj->ogl.quad.c[V3].a);
			glTexCoord2d	(obj->ogl.quad.t[V3].s, obj->ogl.quad.t[V3].t);
			glNormal3f		(obj->ogl.quad.n[V3].x, obj->ogl.quad.n[V3].y, obj->ogl.quad.n[V3].z);
			glVertex3f		(obj->ogl.quad.v[V3].x, obj->ogl.quad.v[V3].y, obj->ogl.quad.v[V3].z);

			glColor4f		(obj->ogl.quad.c[V4].r, obj->ogl.quad.c[V4].g, obj->ogl.quad.c[V4].b, obj->ogl.quad.c[V4].a);
			glTexCoord2d	(obj->ogl.quad.t[V4].s, obj->ogl.quad.t[V4].t);
			glNormal3f		(obj->ogl.quad.n[V4].x, obj->ogl.quad.n[V4].y, obj->ogl.quad.n[V4].z);
			glVertex3f		(obj->ogl.quad.v[V4].x, obj->ogl.quad.v[V4].y, obj->ogl.quad.v[V4].z);

		glEnd();
	}
