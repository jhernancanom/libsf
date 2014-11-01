//////////
//
// tetraprimes.cpp : Defines the entry point for the application.
//
//////
//
//




#include "stdafx.h"
#include "tetraprimes.h"

#define _MAX_LOADSTRING		100
#define _MAX_PRIME_BLOCKS	24
#define _MAX_BASE			36
#define _PI					3.1415926535897930f




//////////
// Global Variables
//////
	HWND					ghWnd								= NULL;						// Main window
	HFONT					ghFontBig							= NULL;						// Global font for cells
	HFONT					ghFontSmall							= NULL;						// Global font for totals
	HINSTANCE				ghInst								= NULL;						// current instance

	COLORREF				white;
	COLORREF				yellow;
	COLORREF				green;
	COLORREF				darkGreen;
	COLORREF				black;

	HBRUSH					ghbrWhite;
	HBRUSH					ghbrYellow;
	HBRUSH					ghbrGreen;
	HBRUSH					ghbrBlue;

	bool					glShowDividers						= false;					// The green bar up/down the middle
	bool					glShowColors						= true;						// Colors other cells
	bool					glShowDigitalRoot					= true;						// Shows either digital root or persistence
	bool					glShowDifference					= false;					// Shows digital root minus persistence
	bool					glShowCharacters					= true;						// Show the individual digits?

	int						gnBase								= 10;						// Begin at this base
	int						gnBlock								= 0;						// Which modulo 90 block are we on?
	int						gnColorShift						= 0;						// Amount to offset starting colors
	int						gnAngleShift						= 0;						// Amount to offset the angle displays
	bool					glAngleShiftChanged					= false;					// The angle shift orients the display differently so it's at more readable angles

	int						gnFontBigHeight						= 20;						// Height for ghFontBig
	int						gnFontBigWidth						= 16;						// Width for ghFontBig
	int						gnFontSmallHeight					= 20;						// Height for ghFontSmall
	int						gnFontSmallWidth					= 16;						// Width for ghFontSmall

	const char				cgcLegend[]							= "Toggle:  [R] Digital Root/Persistence   [C] Color  [D] Divider  [T] DR-P  [X] Characters       [+] Base    [-] Base       [Ctrl++] Block    [Ctrl+-] Block       [Ctrl+Alt+] Palette    [Ctrl+Alt-] Palette       [Ctrl+Shift+] Angles";
	char					primeBlockFounds[8192];											// Space to store our list of 24 found prime starting blocks
	char					szTitle[_MAX_LOADSTRING];										// The title bar text
	char					szWindowClass[_MAX_LOADSTRING];									// the main window class name
	HBRUSH					masterBrushes[10];
	COLORREF				masterColors[10];


//////////
// Master prime table
// These are created during initialization.
// It generates the first 576 (24x24) prime numbers, excluding those in the group which would be in the 2,3,5 place of each set
//////
	// We add an extra row because we have a stride of use 1, skip 4, use 1 skip 4
	int primeBlocks[_MAX_PRIME_BLOCKS + 1][24] =
	{
// 		// Excluding the 2,3,5 place
// 		{	  1,   7,  11,  13,  17,  19,  23,  29,  31,  37,  41,  43,  47,  49,  53,  59,  61,  67,  71,  73,  77,  79,  83,  89	},		// First 24 primes, excluding 2,3,5
// 
// 		// Excluding the 2,3,5 place in this set 101 103 107 
// 		{	 97, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233	},		// Second 24 primes
// 
// 		// Excluding the 2,3,5 place in this set 241 251 257 
// 		{	239, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397	},		// Third 24 primes
// 
// 		// Excluding the 2,3,5 place in this set 409 419 421 
// 		{	401, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569 ,571	},		// Fourth 24 primes
// 
// 		// Excluding the 2,3,5 place in this set 587 593 599
// 		{	577, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743	},		// Fifth 24 primes
// 
// 		// Excluding the 2,3,5 place in this set 757 761 769
// 		{	751, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937	}		// Sixth 24 primes
	};

	int masterPrimeTable[24][24] =
	{
		// Only the first row is populated, the rest are computed during init.
		// The formula is simple, horizontal across the top, vertical all primes 1,7..89,
		// with the same values going down along the left, 1,7..89.  Then at
		// each point within, the left prime value is multiplied by the top
		// prime value, modulo 90, and the remainder is summed in various
		// digital roots based on user selection from this master table
		{	1,	7,	11,	13,	17,	19,	23,	29,	31,	37,	41,	43,	47,	49,	53,	59,	61,	67,	71,	73,	77,	79,	83,	89	},
		{	7,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0	},
		{	11,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0	},
		{	13,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0	},
		{	17,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0	},
		{	19,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0	},
		{	23,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0	},
		{	29,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0	},
		{	31,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0	},
		{	37,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0	},
		{	41,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0	},
		{	43,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0	},
		{	47,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0	},
		{	49,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0	},
		{	53,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0	},
		{	59,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0	},
		{	61,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0	},
		{	67,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0	},
		{	71,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0	},
		{	73,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0	},
		{	77,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0	},
		{	79,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0	},
		{	83,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0	},
		{	89,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0	}
	};

	// These are re-computed / populated each time the display is re-drawn
	char masterDigitalRoots[24][24];

	// For the 8-dimension spiral
	float masterAngles[16] =
	{
		(_PI *  12.0f / 180.0f) + (_PI / 2),
		(_PI *  84.0f / 180.0f) + (_PI / 2),
		(_PI * 132.0f / 180.0f) + (_PI / 2),
		(_PI * 156.0f / 180.0f) + (_PI / 2),
		(_PI * 204.0f / 180.0f) + (_PI / 2),
		(_PI * 228.0f / 180.0f) + (_PI / 2),
		(_PI * 276.0f / 180.0f) + (_PI / 2),
		(_PI * 348.0f / 180.0f) + (_PI / 2),

		// More normalized angles
		(_PI *  20.0f / 180.0f) + (_PI / 2),
		(_PI *  60.0f / 180.0f) + (_PI / 2),
		(_PI * 120.0f / 180.0f) + (_PI / 2),
		(_PI * 160.0f / 180.0f) + (_PI / 2),
		(_PI * 200.0f / 180.0f) + (_PI / 2),
		(_PI * 240.0f / 180.0f) + (_PI / 2),
		(_PI * 300.0f / 180.0f) + (_PI / 2),
		(_PI * 340.0f / 180.0f) + (_PI / 2)
	};



//////////
// Forward declarations
//////
	ATOM					MyRegisterClass						(void);
	BOOL					Initialize							(int nCmdShow);
	void					calculateDigitRootAndPersistence	(int value, int* digitalRoot, int* persistence);
	LRESULT CALLBACK		WndProc								(HWND h, UINT m, WPARAM w, LPARAM l);
	INT_PTR CALLBACK		About								(HWND h, UINT m, WPARAM w, LPARAM l);




// Starting point
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	MSG msg;
	HACCEL hAccelTable;


	//////////
	// Initialize
	//////
		ghInst = hInstance;
		if (!Initialize(nCmdShow))
			return FALSE;


	//////////
	// Read events
	//////
		hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_TETRAPRIMES));
		while (GetMessage(&msg, NULL, 0, 0))
		{
			if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		// All done
		return (int) msg.wParam;
}




//////////
//
// Called to set the prime block for the group of modulo 90 primes
//
//////
	void setPrimeBlock(int tnBlock)
	{
		int lnCol, lnRow;


		//////////
		// Master prime table initialization
		//////
			// Initialize row 0
			for (lnCol = 0; lnCol < 24; lnCol++)
				masterPrimeTable[0][lnCol] = primeBlocks[tnBlock][lnCol];

			// Initialize column 0
			for (lnRow = 0; lnRow < 24; lnRow++)
				masterPrimeTable[lnRow][0] = primeBlocks[tnBlock][lnRow];

			// Iterate across each prime horizontally computing the prime multiplication modulo 90
			for (lnCol = 1; lnCol < 24; lnCol++)
			{
				// Iterate down each row vertically from 7..89
				for (lnRow = 1; lnRow < 24; lnRow++)
				{
					// Multiply primes, modulo 90
					masterPrimeTable[lnRow][lnCol] = (masterPrimeTable[0][lnCol] * masterPrimeTable[lnRow][0]) % 90;
				}
			}
	}




//////////
//
// Called to check if the number is prime
//
//////
	bool isPrime(int tnValue)
	{
		int lnI, lnTarget;

		// Handle constants
		if (tnValue == 1 || tnValue == 2 || tnValue == 3 || tnValue == 5 || tnValue == 7)
			return(true);

		// Perform simple tests
		if (tnValue % 2 == 0 || tnValue % 5 == 0)
			return(false);

		// Iterate up to sqrt(tnValue)
		lnTarget = (int)(sqrt((double)tnValue));
		for (lnI = 3; lnI <= lnTarget; lnI += 2)
		{
			// Does it divide by this?
			if (tnValue % lnI == 0)
				return(false);
		}

		// If we get here, it's prime
		return(true);
	}




//////////
//
// Called to obtain the next prime root by brute force.
//
//////
	int getNextPrimeRoot(int tnCandidate)
	{
		// Iterate upward until we find the next prime root
		for ( ; ; tnCandidate++)
		{
			// If it's not even, or divisible by 5, then try it
			if (tnCandidate % 2 != 0 && tnCandidate % 3 != 0 && tnCandidate % 5 != 0)
				return(tnCandidate);		// Yes
		}
	}

	void storeNextMasterPrimeRow(int* tnPrime, int tnRow)
	{
		int lnCol;


		// Iterate for the next 23 primes
		for (lnCol = 0; lnCol < 24; lnCol++)
		{
			// Grab the next prime
			*tnPrime = getNextPrimeRoot(*tnPrime + 1);

			// Populate our master table with it
			primeBlocks[tnRow][lnCol] = *tnPrime;
		}
	}

	// Returns 1 if validated, 0 if not validated
	int validatePrimeBlocks_inBase4(int tnRow)
	{
		int lnRow, lnCol, lnSumBase, lnSumThis, lnDigitalRoot, lnPersistence, lnSaveBase, lnReturn;


		// Set the primes
		setPrimeBlock(tnRow);

		// Calculate the horizontal sums on every line
		lnSaveBase	= gnBase;
		gnBase		= 4;
		lnReturn	= 1;
		// Iterate down every row
		for (lnRow = 0; lnRow < 24; lnRow++)
		{
			// Iterate across every column on this row
			for (lnCol = 0, lnSumThis = 0; lnCol < 24; lnCol++)
			{
				// Grab the digital root in base-4
				calculateDigitRootAndPersistence(masterPrimeTable[lnRow][lnCol], &lnDigitalRoot, &lnPersistence);
				lnSumThis += lnDigitalRoot;
			}

			// Are we still okay?
			if (lnRow == 0)
			{
				// First row
				lnSumBase = lnSumThis;

			} else {
				// Compare
				if (lnSumThis != lnSumBase)
				{
					// Failure
					lnReturn = 0;

					// We're done
					break;
				}
			}
		}

		// Restore the base
		gnBase = lnSaveBase;

		// Indicate our success or failure
		return(lnReturn);
	}

	void initializeMasterPrimes(void)
	{
		int lnPrime, lnRow, lnIsOkay, lnDigitalRoot, lnPersistence, lnSkipped, lnAttempt;


		// Populate all rows
		memset(primeBlockFounds, 0, sizeof(primeBlockFounds));
		for (lnRow = 0, lnPrime = 0, lnSkipped = 0, lnAttempt = 0; lnRow < _MAX_PRIME_BLOCKS; lnRow += lnIsOkay, ++lnAttempt)
		{
			// Grab this row
			storeNextMasterPrimeRow(&lnPrime, lnRow);

			// Validate this row in base-4
			// If it's good, keep it, if not, then do it again
			lnIsOkay = validatePrimeBlocks_inBase4(lnRow);

			// Update our list if this one was okay
			if (lnIsOkay)
			{
				// Determine the digital root of
				calculateDigitRootAndPersistence(primeBlocks[lnRow][0], &lnDigitalRoot, &lnPersistence);
				sprintf(primeBlockFounds + strlen(primeBlockFounds), "%u, %u, %u\n", primeBlocks[lnRow][0], lnSkipped, lnAttempt);
				lnSkipped = 0;

			} else {
				++lnSkipped;
			}
		}
	}




//////////
//
// Called to perform startup initialization
//
//////
	BOOL Initialize(int nCmdShow)
	{
		int			lnI;
		RECT		lrc;
		HDC			hdc;
		ATOM		lnAtom;
		WNDCLASSEX	wcex;


		//////////
		// Basic initialization
		//////
			LoadString(ghInst, IDS_APP_TITLE,	szTitle,		_MAX_LOADSTRING);
			LoadString(ghInst, IDC_TETRAPRIMES,	szWindowClass,	_MAX_LOADSTRING);
			initializeMasterPrimes();
			setPrimeBlock(0);


		//////////
		// Setup the colors (taken from a palette ranging from 255,80,0 to 255,255,255 to 0,80,255
		//////
			masterColors[0]		= RGB(255,128,0);
			masterColors[1]		= RGB(255,80,0);
			masterColors[2]		= RGB(255,164,0);
			masterColors[3]		= RGB(255,212,48);
			masterColors[4]		= RGB(255,225,128);
			masterColors[5]		= RGB(255,255,255);
			masterColors[6]		= RGB(128,225,255);
			masterColors[7]		= RGB(64,192,255);
			masterColors[8]		= RGB(0,92,255);
			masterColors[9]		= RGB(32,164,255);

			// Create commensurate brushes
			for (lnI = 0; lnI < 10; lnI++)
				masterBrushes[lnI] = CreateSolidBrush(masterColors[lnI]);


		//////////
		// Class initialization
		//////
			memset(&wcex, 0, sizeof(wcex));
			wcex.cbSize			= sizeof(WNDCLASSEX);
			wcex.style			= CS_HREDRAW | CS_VREDRAW;
			wcex.lpfnWndProc	= WndProc;
			wcex.hInstance		= ghInst;
			wcex.hIcon			= LoadIcon(ghInst, MAKEINTRESOURCE(IDI_TETRAPRIMES));
			wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
			wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
			wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_TETRAPRIMES);
			wcex.lpszClassName	= szWindowClass;
			wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
			lnAtom = RegisterClassEx(&wcex);


		//////////
		// Compute font peculiarities
		//////
			// Create fonts
			ghFontBig	= CreateFont(-MulDiv(8, GetDeviceCaps(GetDC(GetDesktopWindow()), LOGPIXELSY), 72), 0, 0, 0, FW_NORMAL, 0, 0, 0, ANSI_CHARSET, OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, FF_MODERN, "Arial");
			ghFontSmall	= CreateFont(-MulDiv(6, GetDeviceCaps(GetDC(GetDesktopWindow()), LOGPIXELSY), 72), 0, 0, 0, FW_NORMAL, 0, 0, 0, ANSI_CHARSET, OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, FF_MODERN, "Arial");

			// Create temporary DC
			hdc = CreateCompatibleDC(GetDC(GetDesktopWindow()));

			// Font big
			SelectObject(hdc, ghFontBig);
			DrawText(hdc, "W", 1, &lrc, DT_CALCRECT);
			gnFontBigWidth		= ((lrc.right - lrc.left) * 2) + 0;
			gnFontBigHeight		= ((lrc.bottom - lrc.top) * 1) + 2;

			// Font small
			SelectObject(hdc, ghFontSmall);
			DrawText(hdc, "W", 1, &lrc, DT_CALCRECT);
			gnFontSmallWidth	= ((lrc.right - lrc.left) * 2) + 0;
			gnFontSmallHeight	= ((lrc.bottom - lrc.top) * 1) + 2;

			// Delete the DC
			DeleteDC(hdc);


		//////////
		// Create font, colors, brushes, and window
		//////
			white		= RGB(255,255,255);
			yellow		= RGB(255,255,0);
			green		= RGB(140,205,77);
			darkGreen	= RGB(100,150,50);
			black		= RGB(0,0,0);
			ghbrWhite	= CreateSolidBrush(white);
			ghbrYellow	= CreateSolidBrush(yellow);
			ghbrGreen	= CreateSolidBrush(green);
			ghbrBlue	= CreateSolidBrush(RGB(190,220,231));
			ghWnd		= CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, gnFontBigWidth * 50, gnFontBigHeight * 32, NULL, NULL, ghInst, NULL);
			if (!ghWnd)
			  return FALSE;


		//////////
		// Bring it forward
		//////
			ShowWindow(ghWnd, nCmdShow);
			UpdateWindow(ghWnd);

			// All done
			return TRUE;
	}




//////////
//
// Called to calculate the digital root of the modulo 90 prime value at the col,row
//
//////
	void calculateDigitRootAndPersistence(int value, int* digitalRoot, int* persistence)
	{
		int		lnI, persistenceCount;
		char	buffer[16];


		//////////
		// Compute in the indicated base so long as the number length is > 1
		//////
			persistenceCount = 0;
			do {
				// Another iteration
				++persistenceCount;

				//////////
				// Compute the digits in the current base
				//////
					memset(buffer, 0, sizeof(buffer));
					_ultoa(value, buffer, gnBase);


				//////////
				// Add up the digits
				//////
					for (lnI = 0, value = 0; buffer[lnI] != 0; lnI++)
					{
						if (buffer[lnI] >= '0' && buffer[lnI] <= '9')
							value += (int)(buffer[lnI] - '0');
						else
							value += (int)(buffer[lnI] - 'a' + 10);
					}

			} while (value >= gnBase);


		//////////
		// Indicate the digital root
		//////
			*digitalRoot	= value;
			*persistence	= persistenceCount;
	}




//////////
//
// Windows callback
//
//////
	LRESULT CALLBACK WndProc(HWND h, UINT m, WPARAM w, LPARAM l)
	{
		int				wmId, wmEvent, lnI, lnCol, lnRow, lnDigitalRoot, lnPersistence, lnSum1, lnSum2, lnIterate, lnDeltaX, lnDeltaY, lnPrimeRoot, lnX1, lnY1, lnX2, lnY2;
		float			lfRadius, lfRadiusStep;
		POINT			pt;
		PAINTSTRUCT		ps;
		RECT			lrc, lrc2, lrc3, lrcClient, lrcCenter;
		HBRUSH			lhBrush;
		HDC				hdc, hdcDest;
		char			buffer[256];


		// Process command
		switch (m)
		{
			case WM_COMMAND:
				wmId    = LOWORD(w);
				wmEvent = HIWORD(w);
				// Parse the menu selections:
				switch (wmId)
				{
					case ID_BASE_BASE2:
						gnBase = 2;
						break;

					case ID_BASE_BASE3:
						gnBase = 3;
						break;

					case ID_BASE_BASE4:
						gnBase = 4;
						break;

					case ID_BASE_BASE5:
						gnBase = 5;
						break;

					case ID_BASE_BASE6:
						gnBase = 6;
						break;

					case ID_BASE_BASE7:
						gnBase = 7;
						break;

					case ID_BASE_BASE8:
						gnBase = 8;
						break;

					case ID_BASE_BASE9:
						gnBase = 9;
						break;

					case ID_BASE_BASE10:
						gnBase = 10;
						break;

					case ID_SETTINGS_TOGGLEDIVIDERS:
						glShowDividers = !glShowDividers;
						break;

					case ID_SETTINGS_TOGGLECOLORS:
						glShowColors = !glShowColors;
						break;

					case ID_VIEW_TOGGLEDIGITALROOT:
						glShowDigitalRoot = !glShowDigitalRoot;
						break;

					case ID_VIEW_TOGGLEVIEW:
						glShowDifference = !glShowDifference;
						break;

					case IDM_ABOUT:
						DialogBox(ghInst, MAKEINTRESOURCE(IDD_ABOUTBOX), h, About);
						break;

					case IDM_EXIT:
						DestroyWindow(h);
						break;

					default:
						return DefWindowProc(h, m, w, l);
				}
				// Redraw regardless
				InvalidateRect(h, NULL, false);
				break;

			case WM_PAINT:
				hdc = BeginPaint(h, &ps);
				SelectObject(hdc, ghFontBig);
				SetBkMode(hdc, TRANSPARENT);
				SetTextColor(hdc, black);
				GetClientRect(h, &lrcClient);


				//////////
				// Draw the general parameters
				//////
					sprintf(buffer, "Base %u%s%s%s%s\0", gnBase,	((glShowDividers)							? ", Dividers"		: ""),
																	((glShowColors)								? ", Colors"		: ""),
																	((glShowDigitalRoot && !glShowDifference)	? ", Digital Root"	: ((!glShowDigitalRoot && !glShowDifference) ? ", Persistence" : "")),
																	((glShowDifference)							? ", DR-P"			: ""));
					SetRect(&lrc, gnFontBigWidth * 2, 0, lrcClient.right, gnFontBigHeight);
					FillRect(hdc, &lrc, ghbrWhite);
					DrawText(hdc, buffer, strlen(buffer), &lrc, DT_LEFT);


				//////////
				// Draw the frame vertically along left-side
				//////
					SelectObject(hdc, ghFontSmall);
					SetRect(&lrc, gnFontBigWidth, (gnFontBigHeight * 2), gnFontBigWidth * 2, (gnFontBigHeight * 3));
					for (lnRow = 0; lnRow < 24; lnRow++)
					{
						//////////
						// Draw the digital root and persistence
						//////
							sprintf(buffer, "%u\0", masterPrimeTable[lnRow][0]);
							FillRect(hdc, &lrc, ghbrBlue);
							FrameRect(hdc, &lrc, (HBRUSH)GetStockObject(BLACK_BRUSH));
							DrawText(hdc, buffer, strlen(buffer), &lrc, DT_VCENTER | DT_CENTER | DT_SINGLELINE);


						//////////
						// Scooch over for the next cell
						//////
							lrc.top		+= gnFontBigHeight;
							lrc.bottom	+= gnFontBigHeight;
					}


				//////////
				// Draw horizontally across the top
				//////
					SetRect(&lrc, (gnFontBigWidth * 2), (gnFontBigHeight * 1), (gnFontBigWidth * 3), (gnFontBigHeight * 2));
					for (lnCol = 0; lnCol < 24; lnCol++)
					{
						//////////
						// Draw the digital root and persistence
						//////
							sprintf(buffer, "%u\0", masterPrimeTable[0][lnCol]);
							FillRect(hdc, &lrc, ghbrBlue);
							FrameRect(hdc, &lrc, (HBRUSH)GetStockObject(BLACK_BRUSH));
							DrawText(hdc, buffer, strlen(buffer), &lrc, DT_VCENTER | DT_CENTER | DT_SINGLELINE);


						//////////
						// Scooch over for the next cell
						//////
							lrc.left	+= gnFontBigWidth;
							lrc.right	+= gnFontBigWidth;
					}


				//////////
				// Draw the digital roots
				//////
					SelectObject(hdc, ghFontBig);
					for (lnCol = 0; lnCol < 24; lnCol++)
					{
						// Iterate down each row vertically from 1,7..89
						SetRect(&lrc, (lnCol + 2) * gnFontBigWidth, (gnFontBigHeight * 2), (lnCol + 3) * gnFontBigWidth, (gnFontBigHeight * 3));
						for (lnRow = 0; lnRow < 24; lnRow++)
						{
							//////////
							// Calculate the digital root and persistence, and adjust if need be
							//////
								calculateDigitRootAndPersistence(masterPrimeTable[lnRow][lnCol], &lnDigitalRoot, &lnPersistence);
								if (glShowDifference)
								{
									if (lnDigitalRoot > lnPersistence)		lnDigitalRoot -= lnPersistence;
									else									lnDigitalRoot = (lnPersistence - lnDigitalRoot);
								}


							//////////
							// Set color for this cell
							//////
								if (glShowDividers && (lnRow == lnCol || 23-lnCol == lnRow || 23-lnRow == lnCol))
								{
									lhBrush = ghbrGreen;
									SetBkColor(hdc, green);

								} else {
									if (glShowColors)
									{
										if (glShowDigitalRoot)
										{
											// Show the digital root
											lhBrush = masterBrushes[abs((9 - lnDigitalRoot) + gnColorShift) % 10];
											SetBkColor(hdc, masterColors[abs((9 - lnDigitalRoot) + gnColorShift) % 10]);

										} else {
											// Show the persistence counts
											lhBrush = masterBrushes[abs(lnPersistence + gnColorShift) % 10];
											SetBkColor(hdc, masterColors[abs(lnPersistence + gnColorShift) % 10]);
										}

									} else {
										lhBrush = ghbrWhite;
										SetBkColor(hdc, white);
									}
								}


							//////////
							// Draw the digital root and persistence
							//////
								sprintf(buffer, " : ", lnDigitalRoot, lnPersistence);
								_ultoa(lnDigitalRoot, buffer + 0, gnBase);
								_ultoa(lnDigitalRoot, buffer + 2, gnBase);
								FillRect(hdc, &lrc, lhBrush);
								FrameRect(hdc, &lrc, (HBRUSH)GetStockObject(BLACK_BRUSH));
								if (glShowDigitalRoot)
								{
									// Showing digital roots
									masterDigitalRoots[lnRow][lnCol] = buffer[0];
									if (glShowCharacters && buffer[0] != '0')
										DrawText(hdc, buffer + 0, 1, &lrc, DT_VCENTER | DT_CENTER | DT_SINGLELINE);

								} else {
									// Showing persistence
									masterDigitalRoots[lnRow][lnCol] = buffer[2];
									if (glShowCharacters && buffer[2] != '0')
										DrawText(hdc, buffer + 2, 1, &lrc, DT_VCENTER | DT_CENTER | DT_SINGLELINE);
								}


							//////////
							// Scooch down for the next cell
							//////
								lrc.top		+= gnFontBigHeight;
								lrc.bottom	+= gnFontBigHeight;
						}
					}


				//////////
				// Total the columns horizontally to the right
				//////
					SelectObject(hdc, ghFontSmall);
					SetRect(&lrc, (lnCol + 2) * gnFontBigWidth, (gnFontBigHeight * 2), (lnCol + 3) * gnFontBigWidth, (gnFontBigHeight * 3));
					for (lnRow = 0; lnRow < 24; lnRow++)
					{
						//////////
						// Sum it
						//////
							for (lnCol = 0, lnSum1 = 0; lnCol < 24; lnCol++)
								lnSum1 += (int)(masterDigitalRoots[lnRow][lnCol] - '0');

						
						//////////
						// Show it
						//////
							sprintf(buffer, "%u\0", lnSum1);
							FillRect(hdc, &lrc, ghbrWhite);
							lrc.top += 3;
							DrawText(hdc, buffer, strlen(buffer), &lrc, DT_VCENTER | DT_LEFT | DT_SINGLELINE);
							lrc.top -= 3;


						//////////
						// Scooch down for the next cell
						//////
							lrc.top		+= gnFontBigHeight;
							lrc.bottom	+= gnFontBigHeight;
					}


				//////////
				// Total the columns vertically to the bottom
				//////
					SetRect(&lrc, (gnFontBigWidth * 2), lrc.top, (gnFontBigWidth * 3), lrc.bottom);
					for (lnCol = 0; lnCol < 24; lnCol ++)
					{
						//////////
						// Sum it
						//////
							for (lnRow = 0, lnSum1 = 0; lnRow < 24; lnRow++)
								lnSum1 += (int)(masterDigitalRoots[lnRow][lnCol] - '0');

						
						//////////
						// Show it
						//////
							sprintf(buffer, "%u\0", lnSum1);
							FillRect(hdc, &lrc, ghbrWhite);
							DrawText(hdc, buffer, strlen(buffer), &lrc, DT_VCENTER | DT_CENTER | DT_SINGLELINE);


						//////////
						// Scooch over for the next cell
						//////
							lrc.left	+= gnFontBigWidth;
							lrc.right	+= gnFontBigWidth;
					}


				//////////
				// Total the columns diagonally
				//////
					SetTextColor(hdc, darkGreen);
					for (lnRow = 0, lnSum1 = 0, lnSum2 = 0; lnRow < 24; lnRow++)
					{
						for (lnCol = 0; lnCol < 24; lnCol ++)
						{
							if (lnRow == lnCol)
								lnSum1 += (int)(masterDigitalRoots[lnRow][lnCol] - '0');

							if (23-lnCol == lnRow || 23-lnRow == lnCol)
								lnSum2 += (int)(masterDigitalRoots[23-lnRow][23-lnCol] - '0');
						}
					}


				//////////
				// Show diagonal down
				//////
					CopyRect(&lrc2, &lrc);
					sprintf(buffer, "=%u\0", lnSum1);
					FillRect(hdc, &lrc2, ghbrWhite);
					DrawText(hdc, buffer, strlen(buffer), &lrc2, DT_VCENTER | DT_CENTER | DT_SINGLELINE);
					OffsetRect(&lrc2, 1, 0);
					DrawText(hdc, buffer, strlen(buffer), &lrc2, DT_VCENTER | DT_CENTER | DT_SINGLELINE);


				//////////
				// Show diagonal up
				//////
					SetRect(&lrc2, lrc.left, (gnFontBigHeight * 1), lrc.right, (gnFontBigHeight * 2));
					sprintf(buffer, "=%u\0", lnSum2);
					FillRect(hdc, &lrc2, ghbrWhite);
					DrawText(hdc, buffer, strlen(buffer), &lrc2, DT_VCENTER | DT_CENTER | DT_SINGLELINE);
					OffsetRect(&lrc2, 1, 0);
					DrawText(hdc, buffer, strlen(buffer), &lrc2, DT_VCENTER | DT_CENTER | DT_SINGLELINE);


				//////////
				// Show the legend at the bottom
				//////
					CopyRect(&lrc2, &lrcClient);
					lrc2.top	= lrc2.bottom - gnFontSmallHeight;
					SetBkMode(hdc, OPAQUE);
					SetBkColor(hdc, white);
					SelectObject(hdc, ghFontSmall);
					SetTextColor(hdc, RGB(92,92,148));
					DrawText(hdc, cgcLegend, sizeof(cgcLegend) - 1, &lrc2, DT_BOTTOM | DT_CENTER);


				//////////
				// Draw the 8-part spiral
				//////
					// Iterate at every prime going around clockwise
					SelectObject(hdc, ghFontBig);
					SetRect(&lrcCenter, (lrc.right + lrcClient.right) / 2, lrcClient.bottom / 2, 0, 0);

					// Clear the portion if the angle shift has changed
					if (glAngleShiftChanged)
					{
						SetRect(&lrc3, lrc.right, 0, lrcClient.right, lrcClient.bottom);
						lrc3.bottom -= gnFontBigHeight;
						FillRect(hdc, &lrc3, ghbrWhite);
					}
					glAngleShiftChanged = false;

					// Iterate through twice, the first time to draw the background, the second to position the points
					lfRadiusStep = (float)(sqrt((double)((gnFontBigHeight*gnFontBigHeight) + (gnFontBigWidth*gnFontBigWidth))) / 6.5);
					for (lnI = 0; lnI < 2; lnI++)
					{
						for (lnRow = gnBlock, lfRadius = lfRadiusStep * 8.0f, lnIterate = 0, lnPrimeRoot = masterPrimeTable[0][0] - 1; lnRow < gnBlock + 2; lnRow++)
						{
							for (lnCol = 0; lnCol < 24; lnCol++, lfRadius += lfRadiusStep, lnIterate++)
							{
								// Grab the offset for the delta
								lnDeltaY = (int)(sin(masterAngles[(lnIterate % 8) + ((gnAngleShift % 2) * 8)]) * lfRadius);
								lnDeltaX = (int)(cos(masterAngles[(lnIterate % 8) + ((gnAngleShift % 2) * 8)]) * lfRadius);

								// On the first pass, draw the connections
								if (lnI == 0)
								{
									// Draw the basic frame
									if (lnRow == gnBlock && lnIterate < 8)
									{
										// Get the range
										lnY1 = (int)(sin(masterAngles[(lnIterate % 8) + ((gnAngleShift % 2) * 8)]) * lfRadius);
										lnX1 = (int)(cos(masterAngles[(lnIterate % 8) + ((gnAngleShift % 2) * 8)]) * lfRadius);
										lnY2 = (int)(sin(masterAngles[(lnIterate % 8) + ((gnAngleShift % 2) * 8)]) * (lfRadius + lfRadiusStep * 8.0f * 3.0f));
										lnX2 = (int)(cos(masterAngles[(lnIterate % 8) + ((gnAngleShift % 2) * 8)]) * (lfRadius + lfRadiusStep * 8.0f * 3.0f));
										MoveToEx(hdc, lrcCenter.left - lnX1, lrcCenter.top - lnY1, NULL);
										LineTo(hdc,   lrcCenter.left - lnX2, lrcCenter.top - lnY2);
									}

									// Draw the line connecting from where it was to where we are
									if (lnIterate != 0)
									{
										// Draw a line connecting where we were to where we are
										MoveToEx(hdc, pt.x, pt.y, NULL);
										LineTo(hdc, lrcCenter.left - lnDeltaX, lrcCenter.top - lnDeltaY);
									}
									pt.x = lrcCenter.left - lnDeltaX;
									pt.y = lrcCenter.top  - lnDeltaY;

								} else {
									// On the second pass, draw the thing

									// Compute this value
									lnPrimeRoot = getNextPrimeRoot(lnPrimeRoot + 1);
									sprintf(buffer, "%u\0", lnPrimeRoot);

									// Based on its primality, display in white, or in green
									if (isPrime(lnPrimeRoot))
									{
										// Prime
										SetBkColor(hdc, white);
										lhBrush = ghbrWhite;

									} else {
										// Not prime
										SetBkColor(hdc, yellow);
										lhBrush = ghbrYellow;
									}

									// Find out how big it will draw
									DrawText(hdc, buffer, strlen(buffer), &lrc2, DT_VCENTER | DT_CENTER | DT_SINGLELINE | DT_CALCRECT);

									// Center it around the location
									SetRect(&lrc2,	lrcCenter.left	- lnDeltaX - ((lrc2.right - lrc2.left) / 2),
													lrcCenter.top	- lnDeltaY - ((lrc2.bottom - lrc2.top) / 2),
													lrcCenter.left	- lnDeltaX + ((lrc2.right - lrc2.left) / 2),
													lrcCenter.top	- lnDeltaY + ((lrc2.bottom - lrc2.top) / 2));

									// Remove the portion that was there before
									CopyRect(&lrc3, &lrc2);
									InflateRect(&lrc3, 4, 2);
									FillRect(hdc, &lrc3, ghbrWhite);
// 									InflateRect(&lrc, -4, -2);
// 									FillRect(hdc, &lrc3, lhBrush);
// 									FrameRect(hdc, &lrc3, (HBRUSH)GetStockObject(BLACK_BRUSH));

									// Draw it
									DrawText(hdc, buffer, strlen(buffer), &lrc2, DT_VCENTER | DT_CENTER | DT_SINGLELINE);
								}
							}
						}
					}


				// All done painting
				EndPaint(h, &ps);
				break;

			case WM_KEYUP:
				switch (w)
				{
					case VK_ADD:
						if (GetAsyncKeyState(VK_CONTROL))
						{
							// Control key is down
							if (GetAsyncKeyState(VK_MENU))
							{
								// Alt key is down too
								++gnColorShift;

							} else if (GetAsyncKeyState(VK_SHIFT)) {
								// Shift key is down too
								++gnAngleShift;
								glAngleShiftChanged = true;

							} else {
								// Just control
								++gnBlock;
								gnBlock = min(gnBlock, _MAX_PRIME_BLOCKS - 1);
								setPrimeBlock(gnBlock);
							}

						} else {
							// Normal plus key
							++gnBase;
						}
						break;

					case VK_SUBTRACT:
						if (GetAsyncKeyState(VK_CONTROL))
						{
							// Control key is down
							if (GetAsyncKeyState(VK_MENU))
							{
								// Alt key is down too
								--gnColorShift;

							} else if (GetAsyncKeyState(VK_SHIFT)) {
								// Shift key is down too
								--gnAngleShift;
								glAngleShiftChanged = true;

							} else {
								// Just control
								--gnBlock;
								gnBlock = max(gnBlock, 0);
								setPrimeBlock(gnBlock);
							}

						} else {
							// Normal minus key
							--gnBase;
						}
						break;

					case 'C':
						glShowColors = !glShowColors;
						break;

					case 'D':
						glShowDividers = !glShowDividers;
						break;

					case 'R':
						glShowDigitalRoot = !glShowDigitalRoot;
						break;

					case 'T':
						glShowDifference = !glShowDifference;
						break;

					case 'X':
						glShowCharacters = !glShowCharacters;
						break;

					case '1':
						gnBlock = 0;
						setPrimeBlock(0);
						break;

					case '2':
						gnBlock = 1;
						setPrimeBlock(1);
						break;

					case '3':
						gnBlock = 2;
						setPrimeBlock(2);
						break;

					case '4':
						gnBlock = 3;
						setPrimeBlock(3);
						break;

					case '5':
						gnBlock = 4;
						setPrimeBlock(4);
						break;

					case '6':
						gnBlock = 5;
						setPrimeBlock(5);
						break;

					case '7':
						gnBlock = 6;
						setPrimeBlock(6);
						break;

					case '8':
						gnBlock = 7;
						setPrimeBlock(7);
						break;

					case '9':
						gnBlock = 8;
						setPrimeBlock(8);
						break;

					case '0':
						gnBlock = 9;
						setPrimeBlock(9);
						break;
				}
				// Force the base into the range 2..10
				InvalidateRect(h, NULL, false);
				gnBase = max(min(gnBase, _MAX_BASE), 2);
				break;

			case WM_DESTROY:
				PostQuitMessage(0);
				break;

			default:
				return DefWindowProc(h, m, w, l);
		}
		return 0;
	}




//////////
//
// Help -> About dialog
//
//////
	INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
	{
		UNREFERENCED_PARAMETER(lParam);
		switch (message)
		{
			case WM_INITDIALOG:
				return (INT_PTR)TRUE;

			case WM_COMMAND:
				if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
				{
					EndDialog(hDlg, LOWORD(wParam));
					return (INT_PTR)TRUE;
				}
				break;
		}
		return (INT_PTR)FALSE;
	}
