//////////
//
// tetraprimes.cpp : Defines the entry point for the application.
//
//////
//
//




#include "stdafx.h"
#include "tetraprimes.h"

#define MAX_LOADSTRING 100




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

	bool					glShowDividers						= true;						// The green bar up/down the middle
	bool					glShowColors						= true;						// Colors other cells
	bool					glShowDigitalRoot					= true;						// Shows either digital root or persistence

	int						gnBase								= 10;						// Begin at this base
	int						gnFontHeight						= 20;						// Height width for each cell
	int						gnFontWidth							= 16;						// Height for each cell

	const char				cgcLegend[]							= "Toggles:  [R] Digital Root/Persistence   [C] Color  [D] Divider       [+] Increase Base    [-] Decrease Base";
	char					szTitle[MAX_LOADSTRING];										// The title bar text
	char					szWindowClass[MAX_LOADSTRING];									// the main window class name
	HBRUSH					masterBrushes[10];
	COLORREF				masterColors[10];


//////////
// Master prime table
//////
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



//////////
// Forward declarations
//////
	ATOM					MyRegisterClass						(void);
	BOOL					Initialize							(int nCmdShow);
	void					calculateDigitRootAndPersistence	(int lnRow, int lnCol, int* digitalRoot, int* persistence);
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
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//////
	BOOL Initialize(int nCmdShow)
	{
		int			lnI, lnCol, lnRow;
		RECT		lrc;
		HDC			hdc;
		ATOM		lnAtom;
		WNDCLASSEX	wcex;


		//////////
		// Basic initialization
		//////
			LoadString(ghInst, IDS_APP_TITLE,	szTitle,		MAX_LOADSTRING);
			LoadString(ghInst, IDC_TETRAPRIMES,	szWindowClass,	MAX_LOADSTRING);


		//////////
		// Master prime table initialization
		//////
			// Iterate across each prime horizontally from 7..89
			for (lnCol = 1; lnCol < 24; lnCol++)
			{
				// Iterate down each row vertically from 7..89
				for (lnRow = 1; lnRow < 24; lnRow++)
				{
					// Multiply primes, modulo 90
					masterPrimeTable[lnRow][lnCol] = (masterPrimeTable[0][lnCol] * masterPrimeTable[lnRow][0]) % 90;
				}
			}


		//////////
		// Setup the colors (taken from a palette ranging from 255,80,0 to 255,255,255 to 0,80,255
		//////
			masterColors[0]		= RGB(255,80,0);
			masterColors[1]		= RGB(255,128,0);
			masterColors[2]		= RGB(255,164,0);
			masterColors[3]		= RGB(255,212,48);
			masterColors[4]		= RGB(255,225,128);
			masterColors[5]		= RGB(255,255,255);
			masterColors[6]		= RGB(128,225,255);
			masterColors[7]		= RGB(64,192,255);
			masterColors[8]		= RGB(32,164,255);
			masterColors[9]		= RGB(0,92,255);

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
			hdc				= CreateCompatibleDC(GetDC(GetDesktopWindow()));
			SelectObject(hdc, ghFontBig);
			DrawText(hdc, "W", 1, &lrc, DT_CALCRECT);
			gnFontWidth		= ((lrc.right - lrc.left) * 2) + 4;
			gnFontHeight	= ((lrc.bottom - lrc.top) * 1) + 6;
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
			ghFontBig	= CreateFont(-MulDiv(12, GetDeviceCaps(GetDC(GetDesktopWindow()), LOGPIXELSY), 72), 0, 0, 0, FW_NORMAL, 0, 0, 0, ANSI_CHARSET, OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, FF_MODERN, "Arial");
			ghFontSmall	= CreateFont(-MulDiv(8,  GetDeviceCaps(GetDC(GetDesktopWindow()), LOGPIXELSY), 72), 0, 0, 0, FW_NORMAL, 0, 0, 0, ANSI_CHARSET, OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, FF_MODERN, "Arial");
			ghWnd		= CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, gnFontWidth * 28, gnFontHeight * 30, NULL, NULL, ghInst, NULL);
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
	void calculateDigitRootAndPersistence(int lnRow, int lnCol, int* digitalRoot, int* persistence)
	{
		int		value, lnI, persistenceCount;
		char	buffer[16];


		//////////
		// Compute in the indicated base so long as the number length is > 1
		//////
			persistenceCount = 0;
			value = masterPrimeTable[lnRow][lnCol];
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
						value += (int)(buffer[lnI] - '0');

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
		int				wmId, wmEvent, lnCol, lnRow, lnDigitalRoot, lnPersistence, lnSum1, lnSum2;
		PAINTSTRUCT		ps;
		RECT			lrc, lrc2, lrcClient;
		HBRUSH			lhBrush;
		HDC				hdc;
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
					sprintf(buffer, "Base %u, %s%s%s\0", gnBase,	((glShowDividers)		? "Dividers " : ""),
																	((glShowColors)			? "Colors " : ""),
																	((glShowDigitalRoot)	? "Digital Root" : "Persistence")	);
					SetRect(&lrc, gnFontWidth * 2, 0, lrcClient.right, gnFontHeight);
					FillRect(hdc, &lrc, ghbrWhite);
					DrawText(hdc, buffer, strlen(buffer), &lrc, DT_LEFT);


				//////////
				// Draw the frame vertically along left-side
				//////
					SetRect(&lrc, gnFontWidth, (gnFontHeight * 2), gnFontWidth * 2, (gnFontHeight * 3));
					for (lnRow = 0; lnRow < 24; lnRow++)
					{
						//////////
						// Draw the digital root and persistence
						//////
							sprintf(buffer, "%u\0", masterPrimeTable[lnRow][0]);
							FillRect(hdc, &lrc, ghbrBlue);
							FrameRect(hdc, &lrc, (HBRUSH)GetStockObject(BLACK_BRUSH));
							DrawText(hdc, buffer, strlen(buffer), &lrc, DT_VCENTER | DT_CENTER);


						//////////
						// Scooch over for the next cell
						//////
							lrc.top		+= gnFontHeight;
							lrc.bottom	+= gnFontHeight;
					}


				//////////
				// Draw horizontally across the top
				//////
					SetRect(&lrc, (gnFontWidth * 2), (gnFontHeight * 1), (gnFontWidth * 3), (gnFontHeight * 2));
					for (lnCol = 0; lnCol < 24; lnCol++)
					{
						//////////
						// Draw the digital root and persistence
						//////
							sprintf(buffer, "%u\0", masterPrimeTable[0][lnCol]);
							FillRect(hdc, &lrc, ghbrBlue);
							FrameRect(hdc, &lrc, (HBRUSH)GetStockObject(BLACK_BRUSH));
							DrawText(hdc, buffer, strlen(buffer), &lrc, DT_VCENTER | DT_CENTER);


						//////////
						// Scooch over for the next cell
						//////
							lrc.left	+= gnFontWidth;
							lrc.right	+= gnFontWidth;
					}


				//////////
				// Draw the digital roots
				//////
					for (lnCol = 0; lnCol < 24; lnCol++)
					{
						// Iterate down each row vertically from 1,7..89
						SetRect(&lrc, (lnCol + 2) * gnFontWidth, (gnFontHeight * 2), (lnCol + 3) * gnFontWidth, (gnFontHeight * 3));
						for (lnRow = 0; lnRow < 24; lnRow++)
						{
							//////////
							// Set color for this cell
							//////
								calculateDigitRootAndPersistence(lnRow, lnCol, &lnDigitalRoot, &lnPersistence);
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
											lhBrush = masterBrushes[9 - lnDigitalRoot];
											SetBkColor(hdc, masterColors[9 - lnDigitalRoot]);

										} else {
											// Show the persistence counts
											lhBrush = masterBrushes[9 - lnPersistence];
											SetBkColor(hdc, masterColors[9 - lnPersistence]);
										}

									} else {
										lhBrush = ghbrWhite;
										SetBkColor(hdc, white);
									}
								}


							//////////
							// Draw the digital root and persistence
							//////
								sprintf(buffer, "%u:%u", lnDigitalRoot, lnPersistence);
								FillRect(hdc, &lrc, lhBrush);
								FrameRect(hdc, &lrc, (HBRUSH)GetStockObject(BLACK_BRUSH));
								if (glShowDigitalRoot)
								{
									// Showing digital roots
									DrawText(hdc, buffer + 0, 1, &lrc, DT_VCENTER | DT_CENTER);
									masterDigitalRoots[lnRow][lnCol] = buffer[0];

								} else {
									// Showing persistence
									DrawText(hdc, buffer + 2, 1, &lrc, DT_VCENTER | DT_CENTER);
									masterDigitalRoots[lnRow][lnCol] = buffer[2];
								}


							//////////
							// Scooch down for the next cell
							//////
								lrc.top		+= gnFontHeight;
								lrc.bottom	+= gnFontHeight;
						}
					}


				//////////
				// Total the columns horizontally to the right
				//////
					SelectObject(hdc, ghFontSmall);
					SetRect(&lrc, (lnCol + 2) * gnFontWidth, (gnFontHeight * 2), (lnCol + 3) * gnFontWidth, (gnFontHeight * 3));
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
							DrawText(hdc, buffer, strlen(buffer), &lrc, DT_VCENTER | DT_LEFT);
							lrc.top -= 3;


						//////////
						// Scooch down for the next cell
						//////
							lrc.top		+= gnFontHeight;
							lrc.bottom	+= gnFontHeight;
					}


				//////////
				// Total the columns vertically to the bottom
				//////
					SetRect(&lrc, (gnFontWidth * 2), lrc.top, (gnFontWidth * 3), lrc.bottom);
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
							DrawText(hdc, buffer, strlen(buffer), &lrc, DT_VCENTER | DT_CENTER);


						//////////
						// Scooch over for the next cell
						//////
							lrc.left	+= gnFontWidth;
							lrc.right	+= gnFontWidth;
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
						DrawText(hdc, buffer, strlen(buffer), &lrc2, DT_VCENTER | DT_CENTER);
						OffsetRect(&lrc2, 1, 0);
						DrawText(hdc, buffer, strlen(buffer), &lrc2, DT_VCENTER | DT_CENTER);


					//////////
					// Show diagonal up
					//////
						SetRect(&lrc2, lrc.left, (gnFontHeight * 1), lrc.right, (gnFontHeight * 2));
						sprintf(buffer, "=%u\0", lnSum2);
						FillRect(hdc, &lrc2, ghbrWhite);
						DrawText(hdc, buffer, strlen(buffer), &lrc2, DT_VCENTER | DT_CENTER);
						OffsetRect(&lrc2, 1, 0);
						DrawText(hdc, buffer, strlen(buffer), &lrc2, DT_VCENTER | DT_CENTER);


				//////////
				// Show the legend at the bottom
				//////
					CopyRect(&lrc2, &lrcClient);
					lrc2.top	= lrc2.bottom - gnFontHeight;
					SetBkMode(hdc, OPAQUE);
					SetBkColor(hdc, white);
					SetTextColor(hdc, RGB(92,92,148));
					DrawText(hdc, cgcLegend, sizeof(cgcLegend) - 1, &lrc2, DT_BOTTOM | DT_CENTER);


				// All done painting
				EndPaint(h, &ps);
				break;

			case WM_KEYUP:
				switch (w)
				{
					case VK_ADD:
						++gnBase;
						break;

					case VK_SUBTRACT:
						--gnBase;
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
				}
				// Range 2..10
				InvalidateRect(h, NULL, false);
				gnBase = max(min(gnBase, 10), 2);
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
