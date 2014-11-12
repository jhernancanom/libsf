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
		f64		lfX_new, lfY_new, lfZ_new, lfX_old, lfY_old, lfZ_old;
		bool	llRedisplay;


		//////////
		// Initialize
		//////
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

			winX = (f32)x;
			winY = (f32)gnHeight - (f32)y; //(float)viewport[3] - (float)mouse.y;
			winZ = 0.0f;

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
		// Colors
		//////
			for (lnI = V1; lnI <= V4; lnI++)
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
		f32			lfZ;
		RECT		lrc;
		SYSTEMTIME	timeNow;


		// Render if we have something to render
		if (gWinJDebi && gWinJDebi->obj)
		{
			//////////
			// We will be building centered around the origin
			//////
				SetRect(&lrc, -(gWinJDebi->rc.right - gWinJDebi->rc.left) / 2, -(gWinJDebi->rc.bottom - gWinJDebi->rc.top) / 2, 0, 0);
				SetRect(&lrc, lrc.left, lrc.top, lrc.left + (gWinJDebi->rc.right - gWinJDebi->rc.left), lrc.top + (gWinJDebi->rc.bottom - gWinJDebi->rc.top));


			//////////
			// Render
			//////
				// Start
				lfZ = 0.0f;
				iGrace_renderBegin(lfZ);
				{
					// Apply animations
					GetSystemTime(&timeNow);
					iGrace_animate_childrenAndSiblings(gWinJDebi->obj, &lrc, true, true, lfZ, iTime_computeMilliseconds(&timeNow));

					// Render the nodes
					iGrace_renderNode_childrenAndSiblings(gWinJDebi->obj, true, true, lfZ);

					// Render Objects
					iGrace_renderObj_childrenAndSiblings(gWinJDebi->obj, true, true, lfZ);
				}
				// End
				iGrace_renderEnd();
		}
	}




	// Note:  glPushMatrix() here must match with corresponding glPopMatrix() in iGrace_renderEnd()
	void iGrace_renderBegin(f32 tfZ)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glPushMatrix();


		//////////
		// Always looking straight forward at the x,y coordinate from the zoomed in z location
		//////
			gluLookAt(gfX, gfY, gfZ,
					  gfX, gfY, 0.0, 
					  0.0, 1.0, 0.0);

		//////////
		// Lighting
		//////
			if (glLighting)
			{
				// Indicate where the light is
				gfv4LightFixture[XVEC] = gfLightViewX;
				gfv4LightFixture[YVEC] = gfLightViewY;
				gfv4LightFixture[ZVEC] = (gfLightViewX + gfLightViewY) / (f32)2.0;
				glLightfv(GL_LIGHT0, GL_POSITION, gfv4LightFixture);

				glPushMatrix(); 
					glTranslatef	(gfv4LightFixture[XVEC], gfv4LightFixture[YVEC], gfv4LightFixture[ZVEC]);
					glDisable		(GL_LIGHTING);
					glColor3f		(1.0, 1.0, 0.0);
					glutWireCube	(1.0);
					glEnable		(GL_LIGHTING);
				glPopMatrix();
			}


		//////////
		// Render the white background
		//////
			glBegin(GL_QUADS);

				glColor4f	(1.0f, 1.0f, 1.0f, 1.0f);
				glVertex3f	(-500.0f, -500.0f, tfZ - 0.01f);
				glVertex3f	( 500.0f, -500.0f, tfZ - 0.01f);
				glVertex3f	( 500.0f,  500.0f, tfZ - 0.01f);
				glVertex3f	(-500.0f,  500.0f, tfZ - 0.01f);

			glEnd();
	}




	void iGrace_renderEnd(void)
	{
		//////////
		// Render finish
		//////
			glPopMatrix();
			glutSwapBuffers();
	}




	void iGrace_animate_childrenAndSiblings(SObject* obj, RECT* rc, bool tlRenderChildren, bool tlRenderSiblings, f32 tfZ, s64 tnMs)
	{
		RECT		lrc, lrcClient;
		SObject*	objSib;


		logfunc(__FUNCTION__);
		//////////
		// Make sure there is render data
		//////
			if (!obj || !isVisible(obj) || !isEnabled(obj))
				return;

		
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
				iGrace_animate_childrenAndSiblings(obj->firstChild, &lrcClient, true, true, tfZ + 0.01f, tnMs);


		//////////
		// Render self
		//////
			iGrace_assignCoordinates(obj, &lrc, tfZ);
			iiGrace_animate(obj, tnMs);


		//////////
		// Render any siblings
		//////
			if (tlRenderSiblings && obj->ll.next)
			{
				objSib = (SObject*)obj->ll.next;
				while (objSib)
				{
					// Render this sibling
					iGrace_animate_childrenAndSiblings(objSib, rc, true, false, tfZ, tnMs);

					// Move to next sibling
					objSib = (SObject*)objSib->ll.next;
				}
			}
	}




	void iiGrace_animate(SObject* obj, s64 tnMs)
	{
		s32 lnI;


		// If an animation is active, apply it
		if (obj->ogl.anim.msNext <= tnMs)
		{
			// It's time to animate the next frame
			obj->ogl.anim.msNext += obj->ogl.anim.msInterval;

			// Iterate applying any transformations
			for (lnI = V1; lnI <= V4; lnI++)
			{
				// Migrate this axis as it should be migrated
				obj->ogl.quad.v[lnI].x += obj->ogl.anim.delta.v[lnI].x;
				obj->ogl.quad.v[lnI].y += obj->ogl.anim.delta.v[lnI].y;
				obj->ogl.quad.v[lnI].z += obj->ogl.anim.delta.v[lnI].z;
			}
		}
	}




	void iGrace_renderNode_childrenAndSiblings(SObject* obj, bool tlRenderChildren, bool tlRenderSiblings, f32 tfZ)
	{
		SObject*	objSib;
		SObjNode*	objNodeFrom;


		logfunc(__FUNCTION__);
		//////////
		// Make sure there is render data
		//////
			if (!obj || !isVisible(obj) || !isEnabled(obj))
				return;

		
		//////////
		// Render any children
		//////
			if (tlRenderChildren && obj->firstChild)
				iGrace_renderObj_childrenAndSiblings(obj->firstChild, true, true, tfZ + 0.01f);


		//////////
		// Render nodes from the bottom of this item
		//////
			objNodeFrom = obj->fromBottom;
			while (objNodeFrom)
			{
				// Render this node
				iiGrace_renderNode(objNodeFrom, 0.2f);

				// Move to the next node
				objNodeFrom = (SObjNode*)objNodeFrom->llFrom.next;
			}


		//////////
		// Render nodes from the right of this item
		//////
			objNodeFrom = obj->fromRight;
			while (objNodeFrom)
			{
				// Render this node
				iiGrace_renderNode(objNodeFrom, 0.2f);

				// Move to the next node
				objNodeFrom = (SObjNode*)objNodeFrom->llFrom.next;
			}


		//////////
		// Render any siblings
		//////
			if (tlRenderSiblings && obj->ll.next)
			{
				objSib = (SObject*)obj->ll.next;
				while (objSib)
				{
					// Render this sibling
					iGrace_renderNode_childrenAndSiblings(objSib, true, false, tfZ);

					// Move to next sibling
					objSib = (SObject*)objSib->ll.next;
				}
			}
	}




	// Note:  This algorithm ignores Z for the bezier calculation, but rather uses a linear tsGv1->z to tsGv2->z for its orientation
	SGraceRect* iiGrace_computeNodeLine(SGraceVec* tsV1, SGraceVec* tsV2, f32 tfNodeWidth, bool tlIsP1East, bool tlIsP2West, s32* tnReturnVecCount)
	{
		s32				lnI, lnMaxVecs, lnMaxRecs;
		f32				lfNodeWidth2;
		f32				lfThetaMinusCosP2, lfThetaMinusSinP2;
		f32				lfThetaPlusCosP2, lfThetaPlusSinP2;
		SGraceXy		p1, p2;
		SGraceLine		line;
		SGraceVec*		vecsFrom;
		SGraceVec*		vecsTo;
		SGraceVec		v1, v2, v3, v4, v5;
		SGraceRect*		recs;


		//////////
		// Grab our starting and ending points based on direction and orientation
		//////
			iiGrace_computeNodeLine_fivePoints(tsV1, tsV2, &v1, &v2, &v3, &v4, &v5, tlIsP1East, tlIsP2West);


		//////////
		// Compute our points
		//////
			lnMaxVecs			= 20;
			vecsFrom			= iiGrace_computeVecBezier3(lnMaxVecs, &v1, &v2, &v3);
			vecsTo				= iiGrace_computeVecBezier3(lnMaxVecs, &v5, &v4, &v3);
			lnMaxRecs			= (2 * lnMaxVecs) - 1;
			recs				= (SGraceRect*)malloc(lnMaxRecs * sizeof(SGraceRect));
			memset(recs, 0, lnMaxRecs * sizeof(SGraceRect));
			*tnReturnVecCount	= lnMaxRecs;


		//////////
		// Combine them into a single SGraceRect array with color data
		//////
			lfNodeWidth2 = tfNodeWidth / 2.0f;
			for (lnI = 0; lnI < lnMaxVecs; lnI++)
			{
				//////////
				// From points, proceed clockwise from NW corner of rectangle
				//////
					p1.x = vecsFrom[lnI].x;
					p1.y = vecsFrom[lnI].y;
					v1.z = vecsFrom[lnI].z;
					p2.x = vecsFrom[lnI+1].x;
					p2.y = vecsFrom[lnI+1].y;
					v2.z = vecsFrom[lnI+1].z;
					iiGrace_copyAndComputeLine(&line, &p1, &p2);

					// Common computations
					lfThetaMinusCosP2	= lfNodeWidth2 * (f32)cos(line.theta - _PI2);
					lfThetaMinusSinP2	= lfNodeWidth2 * (f32)sin(line.theta - _PI2);
					lfThetaPlusCosP2	= lfNodeWidth2 * (f32)cos(line.theta + _PI2);
					lfThetaPlusSinP2	= lfNodeWidth2 * (f32)sin(line.theta + _PI2);

					// Northwest
					recs[lnI].v[V1].x = p1.x + lfThetaMinusCosP2;
					recs[lnI].v[V1].y = p1.y + lfThetaMinusSinP2;
					recs[lnI].v[V1].z = v1.z;

					// Northeast
					recs[lnI].v[V2].x = p2.x + lfThetaMinusCosP2;
					recs[lnI].v[V2].y = p2.y + lfThetaMinusSinP2;
					recs[lnI].v[V2].z = v2.z;

					// Southeast
					recs[lnI].v[V3].x = p2.x + lfThetaPlusCosP2;
					recs[lnI].v[V3].y = p2.y + lfThetaPlusSinP2;
					recs[lnI].v[V3].z = v2.z;

					// Southwest
					recs[lnI].v[V4].x = p1.x + lfThetaPlusCosP2;
					recs[lnI].v[V4].y = p1.y + lfThetaPlusSinP2;
					recs[lnI].v[V4].z = v1.z;


				//////////
				// To points, proceed clockwise from NW corner of rectangle
				//////
					p1.x = vecsTo[lnI].x;
					p1.y = vecsTo[lnI].y;
					v1.z = vecsTo[lnI].z;
					p2.x = vecsTo[lnI+1].x;
					p2.y = vecsTo[lnI+1].y;
					v2.z = vecsTo[lnI+1].z;
					iiGrace_copyAndComputeLine(&line, &p1, &p2);

					// Common computations
					lfThetaMinusCosP2	= lfNodeWidth2 * (f32)cos(line.theta - _PI2);
					lfThetaMinusSinP2	= lfNodeWidth2 * (f32)sin(line.theta - _PI2);
					lfThetaPlusCosP2	= lfNodeWidth2 * (f32)cos(line.theta + _PI2);
					lfThetaPlusSinP2	= lfNodeWidth2 * (f32)sin(line.theta + _PI2);

					// Northwest
					recs[lnMaxVecs + lnI - 1].v[V1].x = p1.x + lfThetaMinusCosP2;
					recs[lnMaxVecs + lnI - 1].v[V1].y = p1.y + lfThetaMinusSinP2;
					recs[lnMaxVecs + lnI - 1].v[V1].z = v1.z;

					// Northeast
					recs[lnMaxVecs + lnI - 1].v[V2].x = p2.x + lfThetaMinusCosP2;
					recs[lnMaxVecs + lnI - 1].v[V2].y = p2.y + lfThetaMinusSinP2;
					recs[lnMaxVecs + lnI - 1].v[V2].z = v2.z;

					// Southeast
					recs[lnMaxVecs + lnI - 1].v[V3].x = p2.x + lfThetaPlusCosP2;
					recs[lnMaxVecs + lnI - 1].v[V3].y = p2.y + lfThetaPlusSinP2;
					recs[lnMaxVecs + lnI - 1].v[V3].z = v2.z;

					// Southwest
					recs[lnMaxVecs + lnI - 1].v[V4].x = p1.x + lfThetaPlusCosP2;
					recs[lnMaxVecs + lnI - 1].v[V4].y = p1.y + lfThetaPlusSinP2;
					recs[lnMaxVecs + lnI - 1].v[V4].z = v1.z;
			}
			--lnI;
//			iBmp_drawArbitraryQuad(bmp, (s32)vecsFrom[lnI].x, (s32)vecsFrom[lnI].y, (s32)vecsTo[lnI].x, (s32)vecsTo[lnI].y, lnWidth, true, blackColor);


		//////////
		// Clean house
		//////
			free(vecsFrom);
			free(vecsTo);


		///////////
		// Return the constructed rectangle segment which make this up
		//////
			return(recs);
	}




//////////
//
// Called to position the vector based on where it's going from, and where it's going to.
//
//////
	void iiGrace_positionNodeVectors(SObjNode* objNode, SGraceVec* vFrom, SGraceVec* vTo)
	{
		s32 		lnTextLengthFrom, lnTextLengthTo;
		SObjNode*	objNodeText;


		//////////
		// From
		//////
			//////////
			// Determine the maximum length of any label text
			//////
				objNodeText = (SObjNode*)iLl_getFirstNode(&objNode->llFrom);
				for (lnTextLengthFrom = 0; objNodeText; objNodeText = (SObjNode*)objNodeText->llFrom.next)
				{
					// If it's longer, get the length, but only up to 10
					lnTextLengthFrom = min(max(objNodeText->from.label.length, lnTextLengthFrom), 10);
				}


			//////////
			// Position
			//////
				if (objNode->isFromEast)
				{
					// It's departing from the right (east)
					vFrom->y += objNode->slotNumFrom * ...

				} else {
					// It's departing from the bottom (south)
				}


		//////////
		// To
		//////
			//////////
			// Determine the maximum length of the text in the nodes
			//////
				objNodeText = (SObjNode*)iLl_getFirstNode(&objNode->llTo);
				for (lnTextLengthTo = 0; objNodeText; objNodeText = (SObjNode*)objNodeText->llTo.next)
				{
					// If it's longer, get the length, but only up to 10
					lnTextLengthTo = min(max(objNodeText->to.label.length, lnTextLengthTo), 10);
				}
	}




//////////
//
// The nodes originate on the right and bottom, and terminate on the top and left.
// These equate to the standard east,south and north,west orientations.
//
//		       | |
//		       o o
//		      +----------+ o----
//		      |          | o----
//		      |          |
//		----o |          |
//		----o +----------+
//		               o o
//		               | |
//
// Based on the source and destination locations, the three points for each portion
// of the bezier needs to be adjusted.  A typical connection has v1 and v2 in the
// appropriate orientations, which yields these five points (two o's, and three x's):
//
//		       v1
//		+----+ o--- __x
//		|    |          -x- __    v2
//		+----+              x  ---o +----+
//		                            |    |
//		                            +----+
//
// But there may be times when they are in other orientations, which yields these
// five points (two o's, and three x's):
//
//		             v2
//		 x       __---o +----+
//		        |       |    |
//		         - __   +----+
//		              ----- _____x_____
//		                                -----_
//		                               v1    _-
//		                         +----+ o----          x
//		                         |    |
//		                         +----+
//
// And for the other orientations, they perform the similar operations but in the
// vertical rather than horizontal orientations.
//
//////
	void iiGrace_computeNodeLine_fivePoints(SGraceVec* tsV1, SGraceVec* tsV2, SGraceVec* v1, SGraceVec* v2, SGraceVec* v3, SGraceVec* v4, SGraceVec* v5, bool tlIsP1East, bool tlIsP2West)
	{
		//////////
		// v1 is always tsV1, v3 is always dead center, and v5 is always tsV2
		//////
			memcpy(v1, tsV1, sizeof(SGraceVec));
			memcpy(v5, tsV2, sizeof(SGraceVec));
			v3->x = (tsV1->x + tsV2->x) / 2.0f;
			v3->y = (tsV1->y + tsV2->y) / 2.0f;
			v3->z = (tsV1->z + tsV2->z) / 2.0f;

		//////////
		// From
		//////
			if (tlIsP1East)
			{
				// v2->y,z is always tsV1->y,z
				v2->y = tsV1->y;
				v2->z = tsV1->z;

				// Originates on the right
				if (tsV1->x < tsV2->x)
				{
					// v1 is to the left of v2, so it can be extended outward in the easterly direction proportionally
					v2->x = (tsV1->x + v3->x) / 2.0f;

				} else if (tsV1->x == tsV2->x) {
					// v1 and v2 are on top of each other
					v2->x = tsV1->x + 1.0f;

				} else {
					// v1 is to the right of v2, which means it must cross-over
					v2->x = tsV1->x + ((tsV1->x - v3->x) / 2.0f);
				}

			} else {
				// v2->x,z is always tsV1->x,z
				v2->x = tsV1->x;
				v2->z = tsV1->z;

				// Originates on the bottom
				if (tsV1->y < tsV2->y)
				{
					// v1 is above v2, so it can be extended outward normally
					v2->y = (tsV1->y + v3->y) / 2.0f;

				} else if (tsV1->y == tsV2->y) {
					// v1 and v2 are directly beside each other
					v2->y = tsV1->y + 1.0f;

				} else {
					// v1 is below v2, which means it must go down and then back up
					v2->y = tsV1->y + ((tsV1->y - v3->y) / 2.0f);
				}
			}


		//////////
		// To
		//////
			if (tlIsP2West)
			{
				// v4->y,z is always tsV2->y,z
				v4->y = tsV2->y;
				v4->z = tsV2->z;

				// Terminates on the left
				if (tsV1->x < tsV2->x)
				{
					// v1 is to the left of v2, so it can be extended outward in the easterly direction proportionally
					v4->x = (tsV2->x - v3->x) / 2.0f;

				} else if (tsV1->x == tsV2->x) {
					// v1 and v2 are on top of each other
					v4->x = tsV2->x - 1.0f;

				} else {
					// v1 is to the right of v2, which means it must cross-over
					v2->x = tsV2->x - ((v3->x - tsV2->x) / 2.0f);
				}

			} else {
				// v4->x,z is always tsV2->x,z
				v4->x = tsV2->x;
				v4->z = tsV2->z;

				// Terminates on the top
				if (tsV1->y < tsV2->y)
				{
					// v1 is above v2, so it can be extended outward normally
					v4->y = (tsV2->y + v3->y) / 2.0f;

				} else if (tsV1->y == tsV2->y) {
					// v1 and v2 are directly beside each other
					v4->y = tsV2->y - 1.0f;

				} else {
					// v1 is below v2, which means it must go down and then back up
					v4->y = tsV2->y - ((tsV2->y - v3->y) / 2.0f);
				}
			}
	}




	void iiGrace_renderNode(SObjNode* objNode, f32 tfNodeWidth)
	{
		s32			lnI, lnV, lnVecCount;
		f32			lfR, lfG, lfB, lfPercent, lfPercentInc;
		SGraceVec	v1, v2;
		SGraceRect*	recs;


		//////////
		// Compute the node line geometry
		//////
			memcpy(&v1, &objNode->from.obj->ogl.quad.v,	sizeof(SGraceVec));
			memcpy(&v2, &objNode->to.obj->ogl.quad.v,	sizeof(SGraceVec));
			iiGrace_positionNodeVectors(objNode, &v1, &v2);
			recs = iiGrace_computeNodeLine(&v1, &v2, tfNodeWidth, objNode->isFromEast, objNode->isToWest, &lnVecCount);


		//////////
		// Populate the texture and colors
		//////
			for (	lnI = 0, lfPercent = 0.0f, lfPercentInc = 1.0f / (f32)lnVecCount;
					lnI < lnVecCount;
					lnI++, lfPercent += lfPercentInc	)
			{
				//////////
				// Compute the color for this iteration
				//////
					lfR	= (lfPercent * ((f32)objNode->from.color.red / 255.0f)) + ((1.0f - lfPercent) * ((f32)objNode->to.color.red / 255.0f));
					lfG	= (lfPercent * ((f32)objNode->from.color.grn / 255.0f)) + ((1.0f - lfPercent) * ((f32)objNode->to.color.grn / 255.0f));
					lfB	= (lfPercent * ((f32)objNode->from.color.blu / 255.0f)) + ((1.0f - lfPercent) * ((f32)objNode->to.color.blu / 255.0f));


				//////////
				// Store the color and normals
				//////
					for (lnV = V1; lnV <= V4; lnV++)
					{
						// Store the colors
						recs[lnI].c[lnV].r = lfR;
						recs[lnI].c[lnV].g = lfG;
						recs[lnI].c[lnV].b = lfB;

						// Store the normals
						recs[lnI].n[lnV].x = 0.0f;
						recs[lnI].n[lnV].y = 0.0f;
						recs[lnI].n[lnV].z = 1.0f;
					}


				//////////
				// Store the texture coordinates
				//////
					// Upper-left
					recs[lnI].t[V1].s = 0.0f;
					recs[lnI].t[V1].t = 1.0f;
					// Upper-right
					recs[lnI].t[V2].s = 1.0f;
					recs[lnI].t[V2].t = 1.0f;
					// Lower-right
					recs[lnI].t[V3].s = 1.0f;
					recs[lnI].t[V3].t = 0.0f;
					// Lower-left
					recs[lnI].t[V4].s = 0.0f;
					recs[lnI].t[V4].t = 0.0f;
			}

		
		//////////
		// Draw the quads
		//////
			glBegin(GL_QUADS);
			{
				// Iterate and create them
				for (lnI = 0; lnI < lnVecCount; lnI++)
				{
					// Upper-left
					glColor4f		(recs[lnI].c[V1].r, recs[lnI].c[V1].g, recs[lnI].c[V1].b, recs[lnI].c[V1].a);
					glTexCoord2d	(recs[lnI].t[V1].s, recs[lnI].t[V1].t);
					glNormal3f		(recs[lnI].n[V1].x, recs[lnI].n[V1].y, recs[lnI].n[V1].z);
					glVertex3f		(recs[lnI].v[V1].x, recs[lnI].v[V1].y, recs[lnI].v[V1].z);
					// Upper-right
					glColor4f		(recs[lnI].c[V2].r, recs[lnI].c[V2].g, recs[lnI].c[V2].b, recs[lnI].c[V2].a);
					glTexCoord2d	(recs[lnI].t[V2].s, recs[lnI].t[V2].t);
					glNormal3f		(recs[lnI].n[V2].x, recs[lnI].n[V2].y, recs[lnI].n[V2].z);
					glVertex3f		(recs[lnI].v[V2].x, recs[lnI].v[V2].y, recs[lnI].v[V2].z);
					// Lower-right
					glColor4f		(recs[lnI].c[V3].r, recs[lnI].c[V3].g, recs[lnI].c[V3].b, recs[lnI].c[V3].a);
					glTexCoord2d	(recs[lnI].t[V3].s, recs[lnI].t[V3].t);
					glNormal3f		(recs[lnI].n[V3].x, recs[lnI].n[V3].y, recs[lnI].n[V3].z);
					glVertex3f		(recs[lnI].v[V3].x, recs[lnI].v[V3].y, recs[lnI].v[V3].z);
					// Lower-left
					glColor4f		(recs[lnI].c[V4].r, recs[lnI].c[V4].g, recs[lnI].c[V4].b, recs[lnI].c[V4].a);
					glTexCoord2d	(recs[lnI].t[V4].s, recs[lnI].t[V4].t);
					glNormal3f		(recs[lnI].n[V4].x, recs[lnI].n[V4].y, recs[lnI].n[V4].z);
					glVertex3f		(recs[lnI].v[V4].x, recs[lnI].v[V4].y, recs[lnI].v[V4].z);
				}
			}
			glEnd();

// TODO:  A speedup here by saving the recs to last recs, and comparing if the last from and to has changed since last compute, and if not then use the last recs
		// Free the node vectors
		free(recs);
	}




	void iGrace_renderObj_childrenAndSiblings(SObject* obj, bool tlRenderChildren, bool tlRenderSiblings, f32 tfZ)
	{
		SObject* objSib;


		logfunc(__FUNCTION__);
		//////////
		// Make sure there is render data
		//////
			if (!obj || !isVisible(obj) || !isEnabled(obj))
				return;


		//////////
		// Render any children
		//////
			if (tlRenderChildren && obj->firstChild)
				iGrace_renderObj_childrenAndSiblings(obj->firstChild, true, true, tfZ + 0.01f);


		//////////
		// Render self
		//////
			iiGrace_renderObj(obj);


		//////////
		// Render any siblings
		//////
			if (tlRenderSiblings && obj->ll.next)
			{
				objSib = (SObject*)obj->ll.next;
				while (objSib)
				{
					// Render this sibling
					iGrace_renderObj_childrenAndSiblings(objSib, true, false, tfZ);

					// Move to next sibling
					objSib = (SObject*)objSib->ll.next;
				}
			}
	}




	void iiGrace_renderObj(SObject* obj)
	{
		// Bind the texture for this quad
		glBindTexture(GL_TEXTURE_2D, obj->ogl.quad.mipmap);

		// Based on whether or not there's texture information, do the texture coords
		glBegin(GL_QUADS);
		{
			// Upper-left
			glColor4f		(obj->ogl.quad.c[V1].r, obj->ogl.quad.c[V1].g, obj->ogl.quad.c[V1].b, obj->ogl.quad.c[V1].a);
			glTexCoord2d	(obj->ogl.quad.t[V1].s, obj->ogl.quad.t[V1].t);
			glNormal3f		(obj->ogl.quad.n[V1].x, obj->ogl.quad.n[V1].y, obj->ogl.quad.n[V1].z);
			glVertex3f		(obj->ogl.quad.v[V1].x, obj->ogl.quad.v[V1].y, obj->ogl.quad.v[V1].z);
			// Upper-right
			glColor4f		(obj->ogl.quad.c[V2].r, obj->ogl.quad.c[V2].g, obj->ogl.quad.c[V2].b, obj->ogl.quad.c[V2].a);
			glTexCoord2d	(obj->ogl.quad.t[V2].s, obj->ogl.quad.t[V2].t);
			glNormal3f		(obj->ogl.quad.n[V2].x, obj->ogl.quad.n[V2].y, obj->ogl.quad.n[V2].z);
			glVertex3f		(obj->ogl.quad.v[V2].x, obj->ogl.quad.v[V2].y, obj->ogl.quad.v[V2].z);
			// Lower-right
			glColor4f		(obj->ogl.quad.c[V3].r, obj->ogl.quad.c[V3].g, obj->ogl.quad.c[V3].b, obj->ogl.quad.c[V3].a);
			glTexCoord2d	(obj->ogl.quad.t[V3].s, obj->ogl.quad.t[V3].t);
			glNormal3f		(obj->ogl.quad.n[V3].x, obj->ogl.quad.n[V3].y, obj->ogl.quad.n[V3].z);
			glVertex3f		(obj->ogl.quad.v[V3].x, obj->ogl.quad.v[V3].y, obj->ogl.quad.v[V3].z);
			// Lower-left
			glColor4f		(obj->ogl.quad.c[V4].r, obj->ogl.quad.c[V4].g, obj->ogl.quad.c[V4].b, obj->ogl.quad.c[V4].a);
			glTexCoord2d	(obj->ogl.quad.t[V4].s, obj->ogl.quad.t[V4].t);
			glNormal3f		(obj->ogl.quad.n[V4].x, obj->ogl.quad.n[V4].y, obj->ogl.quad.n[V4].z);
			glVertex3f		(obj->ogl.quad.v[V4].x, obj->ogl.quad.v[V4].y, obj->ogl.quad.v[V4].z);
		}
		glEnd();
	}




//////////
//
// Called to compute the midpoint, slope, and perpendicular slope of a vector line
//
//////
	void iiGrace_computeVecLine(SGraceVecLine* line)
	{
		// Midpoint = (x2-x1)/2, (y2-y1)/2, (z2-z1)/2
		line->mid.x		= (line->v1.x + line->v2.x) / 2.0f;
		line->mid.y		= (line->v1.y + line->v2.y) / 2.0f;
		line->mid.z		= (line->v1.z + line->v2.z) / 2.0f;

		// Compute our deltas
		line->delta.x	= line->v2.x - line->v1.x;
		line->delta.y	= line->v2.y - line->v1.y;
		line->delta.z	= line->v2.z - line->v1.z;

		// Length
		line->lengthXy	= (f32)sqrt(line->delta.x*line->delta.x + line->delta.y*line->delta.y);
		line->lengthXz	= (f32)sqrt(line->delta.x*line->delta.x + line->delta.z*line->delta.z);
		line->lengthYz	= (f32)sqrt(line->delta.y*line->delta.y + line->delta.z*line->delta.z);
		line->length	= (f32)sqrt(line->lengthXy*line->lengthXy + line->delta.z*line->delta.z);

		// Slope = rise over run
		line->mXy		= line->delta.y / ((line->delta.x == 0.0f) ? 0.000001f : line->delta.x);
		line->mXz		= line->delta.z / ((line->delta.x == 0.0f) ? 0.000001f : line->delta.x);
		line->mYz		= line->delta.z / ((line->delta.y == 0.0f) ? 0.000001f : line->delta.y);

		// Perpendicular slope = -1/m
		line->mpXy		= -1.0f / ((line->mXy == 0.0) ? 0.000001f : line->mXy);
		line->mpXz		= -1.0f / ((line->mXz == 0.0) ? 0.000001f : line->mXz);
		line->mpYz		= -1.0f / ((line->mYz == 0.0) ? 0.000001f : line->mYz);

		// Compute theta
		line->thetaXy	= (f32)atan2(line->delta.y, line->delta.x);
		line->thetaXz	= (f32)atan2(line->delta.z, line->delta.x);
		line->thetaYz	= (f32)atan2(line->delta.z, line->delta.y);
	}




	void iiGrace_copyAndComputeVecLine(SGraceVecLine* line, SGraceVec* p1, SGraceVec* p2)
	{
		// Copy
		memcpy(&line->v1, p1, sizeof(line->v1));
		memcpy(&line->v2, p2, sizeof(line->v2));

		// Compute
		iiGrace_computeVecLine(line);
	}




	SGraceVec* iiGrace_computeVecBezier3(s32 tnSegmentCount, SGraceVec* tsV1, SGraceVec* tsV2, SGraceVec* tsV3)
	{
		s32				lnSegment, lnSize;
		f32				lfPercent, lfPercentStep;
		f32				lfCosTheta1, lfSinTheta1;
		f32				lfCosTheta2, lfSinTheta2;
		f32				lfSinTheta1Z, lfSinTheta2Z;
		SGraceVec		v1, v2;
		SGraceVecLine	l1, l2;		// Static lines from bez->p1 to bez->p2, and bez->p2 to bez->p3
		SGraceVecLine	lmid;		// Dynamically computed line from l1 to l2 through segments
		SGraceVec*		vecs;


		// Allocate our return buffer
		lnSize	= tnSegmentCount * sizeof(SGraceVec);
		vecs	= (SGraceVec*)malloc(lnSize);
		memset(vecs, 0, lnSize);


		//////////
		// Copy and compute our lines
		//////
			memset(&l1,   0, sizeof(l1));
			memset(&l2,   0, sizeof(l2));
			memset(&lmid, 0, sizeof(lmid));
			iiGrace_copyAndComputeVecLine(&l1, tsV1, tsV2);
			iiGrace_copyAndComputeVecLine(&l2, tsV2, tsV3);


		//////////
		// Compute our thetas for rapid use
		//////
			// L1
			lfCosTheta1		= (f32)cos(l1.thetaXy);
			lfSinTheta1		= (f32)sin(l1.thetaXy);
			lfSinTheta1Z	= (f32)sin(l1.thetaXz);
			// L2
			lfCosTheta2		= (f32)cos(l2.thetaXy);
			lfSinTheta2		= (f32)sin(l2.thetaXy);
			lfSinTheta2Z	= (f32)sin(l2.thetaXz);


		//////////
		// Now, iterate through the bezier building the points
		//////
			for (	lnSegment = 0, lfPercent = 0.0f, lfPercentStep = 1.0f / (f32)tnSegmentCount;
					lnSegment < tnSegmentCount;
					lnSegment++, lfPercent += lfPercentStep		)
			{
				//////////
				// Compute our vectors
				//////
					// v1 for l1
					v1.x = tsV1->x + (lfPercent * l1.lengthXy * lfCosTheta1);
					v1.y = tsV1->y + (lfPercent * l1.lengthXy * lfSinTheta1);
					v1.z = tsV1->z + (lfPercent * l1.lengthXz * lfSinTheta1Z);

					// v2 for l2
					v2.x = tsV2->x + (lfPercent * l2.lengthXy * lfCosTheta2);
					v2.y = tsV2->y + (lfPercent * l2.lengthXy * lfSinTheta2);
					v2.z = tsV2->z + (lfPercent * l2.lengthXz * lfSinTheta2Z);

					// Compute the line
					iiGrace_copyAndComputeVecLine(&lmid, &v1, &v2);


				//////////
				// Derive the position of this bezier point
				//////
					vecs[lnSegment].x = lmid.v1.x + (lfPercent * lmid.lengthXy * (f32)cos(lmid.thetaXy));
					vecs[lnSegment].y = lmid.v1.y + (lfPercent * lmid.lengthXy * (f32)sin(lmid.thetaXy));
					vecs[lnSegment].z = lmid.v1.z + (lfPercent * lmid.lengthXz * (f32)sin(lmid.thetaXz));
			}


		//////////
		// Return our vectors
		//////
			return(vecs);
	}




	void iiGrace_copyAndComputeLine(SGraceLine* line, SGraceXy* p1, SGraceXy* p2)
	{
		// Midpoint = (x2-x1)/2, (y2-y1)/2
		line->mid.x		= (line->p1.x + line->p2.x) / 2.0f;
		line->mid.y		= (line->p1.y + line->p2.y) / 2.0f;

		// Compute our deltas
		line->delta.x	= line->p2.x - line->p1.x;
		line->delta.y	= line->p2.y - line->p1.y;

		// Length
		line->length	= (f32)sqrt(line->delta.x*line->delta.x + line->delta.y*line->delta.y);

		// Slope = rise over run
		line->m			= line->delta.y / ((line->delta.x == 0.0f) ? 0.000001f : line->delta.x);

		// Perpendicular slope = -1/m
		line->mp		= -1.0f / ((line->m == 0.0) ? 0.000001f : line->m);

		// Compute theta
		line->theta		= (f32)atan2(line->delta.y, line->delta.x);
	}
