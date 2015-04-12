//////////
//
// /libsf/source/vjr/source/debugger/jdebic/xbase/dll/jdebic.cpp
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
// Creates a pipe based on the number, which will be an outgoing pipe for various purposes.
//
//////
	void ijdebic_createNamedPipe_byNumber(u32 tnPipeNumber)
	{
		HANDLE	lnPipe;
		s8		pipeName[_MAX_PATH];


		// Create it
		sprintf(pipeName, "\\\\.\\pipe\\jdebic_pipe_%08x\0", tnPipeNumber);
		lnPipe = ijdebic_createNamedPipe(	tnPipeNumber,					// This pipe number instance
											pipeName,						// pipe name
											PIPE_ACCESS_DUPLEX,				// read/write access
											PIPE_TYPE_MESSAGE |				// message type pipe
											PIPE_READMODE_MESSAGE |			// message-read mode
											PIPE_NOWAIT,					// blocking mode
											PIPE_UNLIMITED_INSTANCES,		// max. instances
											_PIPE_BUFFER_SIZE,				// output buffer size
											_PIPE_BUFFER_SIZE,				// input buffer size
											NMPWAIT_USE_DEFAULT_WAIT,		// client time-out
											NULL);							// no security attribute

		// Connect to this pipe
		ConnectNamedPipe(lnPipe, NULL);
	}




//////////
//
// Called to create / connect to a named pipe. These pipes will be automatically
// closed when this DLL shuts down.
//
//////
	HANDLE ijdebic_createNamedPipe(u32 tnPipeNumber, LPCTSTR lpName, DWORD dwOpenMode, DWORD dwPipeMode, DWORD nMaxInstances, DWORD nOutBufferSize, DWORD nInBufferSize, DWORD nDefaultTimeOut, LPSECURITY_ATTRIBUTES lpSecurityAttributes)
	{
		return(CreateNamedPipe(lpName, dwOpenMode, dwPipeMode, nMaxInstances, nOutBufferSize, nInBufferSize, nDefaultTimeOut, lpSecurityAttributes));
	}




//////////
//
// Called to close a pipe handle that was opened into the SNamedPipePool previously
//
//////
	void ijdebic_closeHandle(HANDLE thPipe)
	{
		//////////
		// Clear everything
		//////
			FlushFileBuffers(thPipe);
			DisconnectNamedPipe(thPipe);


		//////////
		// Physically close the handle
		//////
			CloseHandle(thPipe);
	}




//////////
//
// Allocates a new message in the builder, or reuses an old one which is unused.
//
//////
	SJDebiCMessage* ijdebic_allocateNewMessage(void)
	{
		u32				lnI;
		SJDebiCMessage*	msg;


		//////////
		// Iterate looking for unused slots
		//////
			for (lnI = 0, msg = (SJDebiCMessage*)gsMessageMaster->buffer; lnI < gsMessageMaster->populatedLength; lnI++)
			{
				// If this slot is unused, re-use it
				if (!msg->isUsed)
					return(msg);
			}


		//////////
		// Allocate a new message
		//////
			return((SJDebiCMessage*)iBuilder_allocateBytes(gsMessageMaster, sizeof(SJDebiCMessage)));
	}




//////////
//
// Creates a pipe that can be used for diagnostics.
// Note:  This source code was taken from the "pipe_server()" function in the LibSF project entitled, "Exodus Operating System".
// Note:  See https://github.com/RickCHodgin/libsf-full.git and the _exodus bochs directories.
//
//////
	void ijdebic_read_message(u32 tnBytes, u32 tnPipeNumber)
	{
		BOOL			llSuccess;
		DWORD			lnBytesRead;
		HANDLE			lhPipe;
		SJDebiCMessage*	msg;


// TODO:  Working here ... need to do a lookup for allocated pipes (remote vjr.exe instances)
lhPipe = 0;

	
	//////////
	// Allocate a new message
	//////
		msg = (SJDebiCMessage*)ijdebic_allocateNewMessage();
		if (msg)
		{
			// Allocate space for the write
			msg->rawData = (s8*)malloc(tnBytes);
			if (msg->rawData)
			{
				//////////
				// Read the size from requests from the pipe
				//////
					msg->rawDataLength = tnBytes;
					llSuccess = ReadFile(	lhPipe,					// handle to pipe
											msg->rawData,			// buffer to receive data
											msg->rawDataLength,		// size of buffer
											&lnBytesRead,			// number of bytes actually read
											NULL	);				// not overlapped I/O

				//////////
				// Did we read everything?
				//////
					if (!llSuccess || lnBytesRead != msg->rawDataLength)
					{
						// Failure reading...
						// Free the buffer
						free(msg->rawData);

						// Release the message
						msg->isUsed		= false;

					} else {
						// Dispatch the message
						msg->isUsed		= true;
						msg->message	= _WMJDEBIC_INCOMING_MESSAGE;
						SendMessage(ghWndMessageThread, msg->message, (u32)msg, 0);
					}
			}
		} 
	}




//////////
//
// Creates the main message window, and enters a READ EVENTS loop.
//
//////
	DWORD WINAPI ijdebic_messageThread(LPVOID param)
	{
		MSG				msg;
		WNDCLASSEXA		wcex;
		ATOM			lnAtom;


		// If we haven't yet registered the class, attempt to register it
		// First see if the class is already registered
		if (!GetClassInfoExA(GetModuleHandle(NULL), cgcJDebiCClassName, &wcex))
		{
			// If we get here, not yet registered
			memset(&wcex, 0, sizeof(wcex));
			wcex.cbSize         = sizeof(wcex);
			wcex.style          = CS_NOCLOSE;
			wcex.lpfnWndProc    = (WNDPROC)ijdebic_wndProc;
			wcex.hInstance      = GetModuleHandle(NULL);
			wcex.lpszClassName  = cgcJDebiCClassName;
			lnAtom				= RegisterClassExA(&wcex);

			// Was it registered?
			if (lnAtom == NULL)
				ExitThread(-1);		// Nope ... when we get here, failure
		}

		// Register the class if not registered
		ghWndMessageThread = CreateWindow(cgcJDebiCClassName, NULL, 0, 0, 0, 0, 0, HWND_MESSAGE, NULL, GetModuleHandle(NULL), 0);

		// Enter a message loop
		while (GetMessage(&msg, ghWndMessageThread, 0, 0))
		{
			// Receive and dispatch
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		// When we get here, we're done
		ExitThread(0);
		return(0);
	}




//////////
//
// Receives messages and dispatches them as encountered.
//
//////
	LRESULT CALLBACK ijdebic_wndProc(HWND h, UINT m, LPARAM w, LPARAM l)
	{
		u32 lnPipeNumber;


		// Lock
		EnterCriticalSection(&gcs_accessMessages);

		// Process
		switch (m)
		{
			case _WMJDEBIC_DATA_IN_PIPE_N:
				// Retrieve the message in the pipe
				ijdebic_read_message((u32)w, (u32)l);

				// Unlock
				LeaveCriticalSection(&gcs_accessMessages);

				// All done
				return(0);

			case _WMJDEBIC_PIPE_REQUEST:
				lnPipeNumber = gnPipeNumber++;
				ijdebic_createNamedPipe_byNumber(lnPipeNumber);

				// Unlock
				LeaveCriticalSection(&gcs_accessMessages);

				// All done
				return(lnPipeNumber);

			default:
				// Unlock
				LeaveCriticalSection(&gcs_accessMessages);

				// Let Windows handle everything itself
				return(DefWindowProc(h, m, w, l));
		}

		// Unlock
		LeaveCriticalSection(&gcs_accessMessages);

		// We processed it
		return 0;
	}
