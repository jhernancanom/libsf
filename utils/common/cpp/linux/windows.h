//////////
//
// /libsf/utils/common/cpp/linux/windows.h
//
//////
// Version 0.55
// Copyright (c) 2015 by Rick C. Hodgin
//////
// Last update:
//     Jan.17.2014
//////
// Change log:
//     Jan.17.2014 - Initial creation
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
//




// Added as a temporary placeholder.
// windows.h and windows.cpp will provide Linux-based simulation of Windows
// functionality for those features required by LibSF software.

#define	HDC				sptr
#define HBITMAP			sptr
#define HWND			sptr
#define HANDLE			sptr
#define HFONT			sptr
#define HRGN			sptr
#define HBRUSH			sptr
#define HINSTANCE		sptr
#define HACCEL			sptr
#define HICON			sptr
#define HCURSOR			sptr
#define HMENU			sptr
#define HGDIOBJ			sptr
#define HMODULE			sptr
#define WPARAM			sptr
#define LPARAM			sptr
#define ATOM			u16

#define BOOL			bool
#define CONST			const
#define VOID			void
#define SIZE_T			size_t

#define ULONG_PTR		uptr*
#define _MAX_PATH		256
#define BYTE			u8
#define WORD			u16
#define DWORD			u32
#define LPDWORD			u32*
#define UINT			uptr
#define UINT_PTR		uptr*
#define LPVOID			void*
#define LRESULT			sptr*
#define COLORREF		DWORD

#define RGB(r,g,b)			((COLORREF)(((BYTE)(r)|((WORD)((BYTE)(g))<<8))|(((DWORD)(BYTE)(b))<<16)))
#define MAKEINTRESOURCE(i)	((s8*)((ULONG_PTR)((WORD)(i))))

#define __stdcall
#define WINAPI			__stdcall
#define CALLBACK		__stdcall

typedef LRESULT		(CALLBACK*	WNDPROC)				(HWND, UINT, WPARAM, LPARAM);
typedef VOID		(CALLBACK*	TIMERPROC)				(HWND, UINT, UINT_PTR, DWORD);
typedef DWORD		(__stdcall*	LPTHREAD_START_ROUTINE)	(LPVOID lpThreadParameter);


#define WINUSERAPI	/*__declspec(dllimport)*/
#define WINBASEAPI	/*__declspec(dllimport)*/
#define WINGDIAPI	/*__declspec(dllimport)*/
#define __in_opt
#define __in
#define __out_opt
#define __out
#define __inout
#define __deref
#define __drv_aliasesMem

#define MB_OK			0x00000000L

#define PM_NOREMOVE		0x0000

#define WM_TIMER		0x0113

#define CS_VREDRAW          0x0001
#define CS_HREDRAW          0x0002
#define CS_DBLCLKS          0x0008
#define CS_OWNDC            0x0020
#define CS_CLASSDC          0x0040
#define CS_PARENTDC         0x0080
#define CS_NOCLOSE          0x0200
#define CS_SAVEBITS         0x0800
#define CS_BYTEALIGNCLIENT  0x1000
#define CS_BYTEALIGNWINDOW  0x2000
#define CS_GLOBALCLASS      0x4000
#define CS_IME              0x00010000
#define CS_DROPSHADOW       0x00020000

#define IDC_ARROW           MAKEINTRESOURCE(32512)
#define IDC_IBEAM           MAKEINTRESOURCE(32513)
#define IDC_WAIT            MAKEINTRESOURCE(32514)
#define IDC_CROSS           MAKEINTRESOURCE(32515)
#define IDC_UPARROW         MAKEINTRESOURCE(32516)
#define IDC_SIZENWSE        MAKEINTRESOURCE(32642)
#define IDC_SIZENESW        MAKEINTRESOURCE(32643)
#define IDC_SIZEWE          MAKEINTRESOURCE(32644)
#define IDC_SIZENS          MAKEINTRESOURCE(32645)
#define IDC_SIZEALL         MAKEINTRESOURCE(32646)
#define IDC_NO              MAKEINTRESOURCE(32648)
#define IDC_HAND            MAKEINTRESOURCE(32649)
#define IDC_APPSTARTING     MAKEINTRESOURCE(32650)
#define IDC_HELP            MAKEINTRESOURCE(32651)
#define IDC_SIZE            IDC_SIZEALL
#define IDC_ICON            IDC_ARROW

#define DT_TOP                      0x00000000
#define DT_LEFT                     0x00000000
#define DT_CENTER                   0x00000001
#define DT_RIGHT                    0x00000002
#define DT_VCENTER                  0x00000004
#define DT_BOTTOM                   0x00000008
#define DT_WORDBREAK                0x00000010
#define DT_SINGLELINE               0x00000020
#define DT_EXPANDTABS               0x00000040
#define DT_TABSTOP                  0x00000080
#define DT_NOCLIP                   0x00000100
#define DT_EXTERNALLEADING          0x00000200
#define DT_CALCRECT                 0x00000400
#define DT_NOPREFIX                 0x00000800
#define DT_INTERNAL                 0x00001000
#define DT_EDITCONTROL              0x00002000
#define DT_PATH_ELLIPSIS            0x00004000
#define DT_END_ELLIPSIS             0x00008000
#define DT_MODIFYSTRING             0x00010000
#define DT_RTLREADING               0x00020000
#define DT_WORD_ELLIPSIS            0x00040000
#define DT_NOFULLWIDTHCHARBREAK     0x00080000
#define DT_HIDEPREFIX               0x00100000
#define DT_PREFIXONLY               0x00200000

#define TRANSPARENT		1
#define OPAQUE			2

#define OUT_DEFAULT_PRECIS          0
#define OUT_STRING_PRECIS           1
#define OUT_CHARACTER_PRECIS        2
#define OUT_STROKE_PRECIS           3
#define OUT_TT_PRECIS               4
#define OUT_DEVICE_PRECIS           5
#define OUT_RASTER_PRECIS           6
#define OUT_TT_ONLY_PRECIS          7
#define OUT_OUTLINE_PRECIS          8
#define OUT_SCREEN_OUTLINE_PRECIS   9
#define OUT_PS_ONLY_PRECIS          10

#define CLIP_DEFAULT_PRECIS     0
#define CLIP_CHARACTER_PRECIS   1
#define CLIP_STROKE_PRECIS      2
#define CLIP_MASK               0xf
#define CLIP_LH_ANGLES          (1<<4)
#define CLIP_TT_ALWAYS          (2<<4)
#define CLIP_DFA_DISABLE        (4<<4)
#define CLIP_EMBEDDED           (8<<4)

#define DEFAULT_QUALITY			0
#define DRAFT_QUALITY			1
#define PROOF_QUALITY			2
#define NONANTIALIASED_QUALITY	3
#define ANTIALIASED_QUALITY		4
#define CLEARTYPE_QUALITY		5
#define CLEARTYPE_NATURAL_QUALITY	6

#define DEFAULT_PITCH           0
#define FIXED_PITCH             1
#define VARIABLE_PITCH          2
#define MONO_FONT               8

#define ANSI_CHARSET            0
#define DEFAULT_CHARSET         1
//#define SYMBOL_CHARSET          2
//#define SHIFTJIS_CHARSET        128
//#define HANGEUL_CHARSET         129
//#define HANGUL_CHARSET          129
//#define GB2312_CHARSET          134
//#define CHINESEBIG5_CHARSET     136
#define OEM_CHARSET             255
//#define JOHAB_CHARSET           130
//#define HEBREW_CHARSET          177
//#define ARABIC_CHARSET          178
//#define GREEK_CHARSET           161
//#define TURKISH_CHARSET         162
//#define VIETNAMESE_CHARSET      163
//#define THAI_CHARSET            222
//#define EASTEUROPE_CHARSET      238
//#define RUSSIAN_CHARSET         204

#define FS_LATIN1               0x00000001L
#define FS_LATIN2               0x00000002L
#define FS_CYRILLIC             0x00000004L
#define FS_GREEK                0x00000008L
#define FS_TURKISH              0x00000010L
#define FS_HEBREW               0x00000020L
#define FS_ARABIC               0x00000040L
#define FS_BALTIC               0x00000080L
#define FS_VIETNAMESE           0x00000100L
#define FS_THAI                 0x00010000L
#define FS_JISJAPAN             0x00020000L
#define FS_CHINESESIMP          0x00040000L
#define FS_WANSUNG              0x00080000L
#define FS_CHINESETRAD          0x00100000L
#define FS_JOHAB                0x00200000L
#define FS_SYMBOL               0x80000000L

#define FF_DONTCARE         	(0<<4)  /* Don't care or don't know. */
#define FF_ROMAN            	(1<<4)  /* Variable stroke width, serifed. Times Roman, Century Schoolbook, etc. */
#define FF_SWISS            	(2<<4)  /* Variable stroke width, sans-serifed. Helvetica, Swiss, etc. */
#define FF_MODERN           	(3<<4)  /* Constant stroke width, serifed or sans-serifed. Pica, Elite, Courier, etc. */
#define FF_SCRIPT           	(4<<4)  /* Cursive, etc. */
#define FF_DECORATIVE       	(5<<4)  /* Old English, etc. */

/* Font Weights */
#define FW_DONTCARE         0
#define FW_THIN             100
#define FW_EXTRALIGHT       200
#define FW_LIGHT            300
#define FW_NORMAL           400
#define FW_MEDIUM           500
#define FW_SEMIBOLD         600
#define FW_BOLD             700
#define FW_EXTRABOLD        800
#define FW_HEAVY            900

#define FW_ULTRALIGHT       FW_EXTRALIGHT
#define FW_REGULAR          FW_NORMAL
#define FW_DEMIBOLD         FW_SEMIBOLD
#define FW_ULTRABOLD        FW_EXTRABOLD
#define FW_BLACK            FW_HEAVY

#define WS_OVERLAPPED       0x00000000L
#define WS_POPUP            0x80000000L
#define WS_CHILD            0x40000000L
#define WS_MINIMIZE         0x20000000L
#define WS_VISIBLE          0x10000000L
#define WS_DISABLED         0x08000000L
#define WS_CLIPSIBLINGS     0x04000000L
#define WS_CLIPCHILDREN     0x02000000L
#define WS_MAXIMIZE         0x01000000L
#define WS_CAPTION          0x00C00000L     /* WS_BORDER | WS_DLGFRAME  */
#define WS_BORDER           0x00800000L
#define WS_DLGFRAME         0x00400000L
#define WS_VSCROLL          0x00200000L
#define WS_HSCROLL          0x00100000L
#define WS_SYSMENU          0x00080000L
#define WS_THICKFRAME       0x00040000L
#define WS_GROUP            0x00020000L
#define WS_TABSTOP          0x00010000L

#define WS_MINIMIZEBOX      0x00020000L
#define WS_MAXIMIZEBOX      0x00010000L

#define WS_TILED            WS_OVERLAPPED
#define WS_ICONIC           WS_MINIMIZE
#define WS_SIZEBOX          WS_THICKFRAME
#define WS_TILEDWINDOW      WS_OVERLAPPEDWINDOW

#define WS_OVERLAPPEDWINDOW (WS_OVERLAPPED     | \
                             WS_CAPTION        | \
                             WS_SYSMENU        | \
                             WS_THICKFRAME     | \
                             WS_MINIMIZEBOX    | \
                             WS_MAXIMIZEBOX)

#define WS_POPUPWINDOW      (WS_POPUP          | \
                             WS_BORDER         | \
                             WS_SYSMENU)

#define WS_CHILDWINDOW      (WS_CHILD)

#define WS_EX_DLGMODALFRAME     0x00000001L
#define WS_EX_NOPARENTNOTIFY    0x00000004L
#define WS_EX_TOPMOST           0x00000008L
#define WS_EX_ACCEPTFILES       0x00000010L
#define WS_EX_TRANSPARENT       0x00000020L
#define WS_EX_MDICHILD          0x00000040L
#define WS_EX_TOOLWINDOW        0x00000080L
#define WS_EX_WINDOWEDGE        0x00000100L
#define WS_EX_CLIENTEDGE        0x00000200L
#define WS_EX_CONTEXTHELP       0x00000400L
#define WS_EX_RIGHT             0x00001000L
#define WS_EX_LEFT              0x00000000L
#define WS_EX_RTLREADING        0x00002000L
#define WS_EX_LTRREADING        0x00000000L
#define WS_EX_LEFTSCROLLBAR     0x00004000L
#define WS_EX_RIGHTSCROLLBAR    0x00000000L
#define WS_EX_CONTROLPARENT     0x00010000L
#define WS_EX_STATICEDGE        0x00020000L
#define WS_EX_APPWINDOW         0x00040000L
#define WS_EX_OVERLAPPEDWINDOW  (WS_EX_WINDOWEDGE | WS_EX_CLIENTEDGE)
#define WS_EX_PALETTEWINDOW     (WS_EX_WINDOWEDGE | WS_EX_TOOLWINDOW | WS_EX_TOPMOST)
#define WS_EX_LAYERED           0x00080000
#define WS_EX_NOINHERITLAYOUT   0x00100000L // Disable inheritence of mirroring by children
#define WS_EX_LAYOUTRTL         0x00400000L // Right to left mirroring
#define WS_EX_COMPOSITED        0x02000000L
#define WS_EX_NOACTIVATE        0x08000000L

#define SWP_NOSIZE          0x0001
#define SWP_NOMOVE          0x0002
#define SWP_NOZORDER        0x0004
#define SWP_NOREDRAW        0x0008
#define SWP_NOACTIVATE      0x0010
#define SWP_FRAMECHANGED    0x0020  /* The frame changed: send WM_NCCALCSIZE */
#define SWP_SHOWWINDOW      0x0040
#define SWP_HIDEWINDOW      0x0080
#define SWP_NOCOPYBITS      0x0100
#define SWP_NOOWNERZORDER   0x0200  /* Don't do owner Z ordering */
#define SWP_NOSENDCHANGING  0x0400  /* Don't send WM_WINDOWPOSCHANGING */
#define SWP_DRAWFRAME       SWP_FRAMECHANGED
#define SWP_NOREPOSITION    SWP_NOOWNERZORDER
#define SWP_DEFERERASE      0x2000
#define SWP_ASYNCWINDOWPOS  0x4000

#define HWND_TOP        ((HWND)0)
#define HWND_BOTTOM     ((HWND)1)
#define HWND_TOPMOST    ((HWND)-1)
#define HWND_NOTOPMOST  ((HWND)-2)
#define HWND_MESSAGE	((HWND)-3)

struct RECT
{
	s32		left;
	s32		top;
	s32		right;
	s32		bottom;
};
#define LPRECT RECT*

struct POINT
{
	s32		x;
	s32		y;
};

struct POINTS
{
	s16		x;
	s16		y;
};

typedef struct tagBITMAPFILEHEADER {
	u16		bfType;
	u32		bfSize;
	u16		bfReserved1;
	u16		bfReserved2;
	u32		bfOffBits;
} BITMAPFILEHEADER, *PBITMAPFILEHEADER;

typedef struct tagBITMAPINFOHEADER {
	u32		biSize;
	s32		biWidth;
	s32		biHeight;
	u16		biPlanes;
	u16		biBitCount;
	u32		biCompression;
	u32		biSizeImage;
	s32		biXPelsPerMeter;
	s32		biYPelsPerMeter;
	u32		biClrUsed;
	u32		biClrImportant;
} BITMAPINFOHEADER, *PBITMAPINFOHEADER;

struct _RTL_CRITICAL_SECTION;

typedef struct _LIST_ENTRY
{
   struct _LIST_ENTRY *Flink;
   struct _LIST_ENTRY *Blink;
} LIST_ENTRY;

typedef struct _RTL_CRITICAL_SECTION_DEBUG
{
	u16		Type;
	u16		CreatorBackTraceIndex;
	_RTL_CRITICAL_SECTION *CriticalSection;
	LIST_ENTRY ProcessLocksList;
	u32		EntryCount;
	u32		ContentionCount;
	u32		Flags;
	u16		CreatorBackTraceIndexHigh;
	u16		SpareWORD  ;
} RTL_CRITICAL_SECTION_DEBUG, *PRTL_CRITICAL_SECTION_DEBUG, RTL_RESOURCE_DEBUG, *PRTL_RESOURCE_DEBUG;

typedef struct _RTL_CRITICAL_SECTION
{
	PRTL_CRITICAL_SECTION_DEBUG DebugInfo;

	//
	//  The following three fields control entering and exiting the critical
	//  section for the resource
	//

	s32			LockCount;
	s32			RecursionCount;
	HANDLE		OwningThread;        // from the thread's ClientId->UniqueThread
	HANDLE		LockSemaphore;
	ULONG_PTR	SpinCount;        // force size on 64-bit systems when packed
} RTL_CRITICAL_SECTION, *PRTL_CRITICAL_SECTION;
typedef RTL_CRITICAL_SECTION CRITICAL_SECTION;
#define LPCRITICAL_SECTION CRITICAL_SECTION*

typedef struct tagTEXTMETRICW
{
	s32		tmHeight;
	s32		tmAscent;
	s32		tmDescent;
	s32		tmInternalLeading;
	s32		tmExternalLeading;
	s32		tmAveCharWidth;
	s32		tmMaxCharWidth;
	s32		tmWeight;
	s32		tmOverhang;
	s32		tmDigitizedAspectX;
	s32		tmDigitizedAspectY;
	u16		tmFirstChar;
	u16		tmLastChar;
	u16		tmDefaultChar;
	u16		tmBreakChar;
	u8		tmItalic;
	u8		tmUnderlined;
	u8		tmStruckOut;
	u8		tmPitchAndFamily;
	u8		tmCharSet;
} TEXTMETRIC;

typedef struct _SYSTEMTIME
{
	u16		wYear;
	u16		wMonth;
	u16		wDayOfWeek;
	u16		wDay;
	u16		wHour;
	u16		wMinute;
	u16		wSecond;
	u16		wMilliseconds;
} SYSTEMTIME;

typedef struct tagWNDCLASSEXA
{
    UINT        cbSize;
    UINT        style;
    WNDPROC     lpfnWndProc;
    int         cbClsExtra;
    int         cbWndExtra;
    HINSTANCE   hInstance;
    HICON       hIcon;
    HCURSOR     hCursor;
    HBRUSH      hbrBackground;
    cs8*		lpszMenuName;
    cs8*		lpszClassName;
    HICON       hIconSm;
} WNDCLASSEXA;

typedef struct _SECURITY_ATTRIBUTES
{
    DWORD		nLength;
    LPVOID		lpSecurityDescriptor;
    BOOL		bInheritHandle;
} SECURITY_ATTRIBUTES, *PSECURITY_ATTRIBUTES, *LPSECURITY_ATTRIBUTES;

typedef struct tagMSG
{
    HWND		hwnd;
    UINT		message;
    WPARAM		wParam;
    LPARAM		lParam;
    DWORD		time;
    POINT		pt;
} MSG;
#define LPMSG MSG*

WINUSERAPI HWND WINAPI CreateWindowEx(	__in		DWORD dwExStyle,
										__in_opt	cs8* lpClassName,
										__in_opt	cs8* lpWindowName,
										__in		DWORD dwStyle,
										__in		int X,
										__in		int Y,
										__in		int nWidth,
										__in		int nHeight,
										__in_opt	HWND hWndParent,
										__in_opt	HMENU hMenu,
										__in_opt	HINSTANCE hInstance,
										__in_opt	LPVOID lpParam);

#define CreateWindowA(lpClassName, lpWindowName, dwStyle, x, y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam) \
		CreateWindowEx(0L,	lpClassName, lpWindowName, dwStyle, x, y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam)

WINUSERAPI UINT_PTR WINAPI	SetTimer				(__in_opt	HWND hWnd, __in UINT_PTR nIDEvent, __in UINT uElapse, __in_opt uptr/*TIMERPROC*/ lpTimerFunc);
WINUSERAPI int WINAPI		MessageBox				(__in_opt HWND hWnd, __in_opt cs8* lpText, __in_opt cs8* lpCaption, __in UINT uType);
WINBASEAPI HANDLE WINAPI	CreateThread			(	__in_opt	LPSECURITY_ATTRIBUTES lpThreadAttributes,
														__in		SIZE_T dwStackSize,
														__in		LPTHREAD_START_ROUTINE lpStartAddress,
														__in_opt	__deref __drv_aliasesMem LPVOID lpParameter,
														__in		DWORD dwCreationFlags,
														__out_opt	LPDWORD lpThreadId);
WINUSERAPI BOOL WINAPI		GetClassInfoExA			(__in_opt HINSTANCE hInstance, __in cs8* lpszClass, __out WNDCLASSEXA* lpwcx);
WINUSERAPI ATOM WINAPI		RegisterClassExA		(__in CONST WNDCLASSEXA* lpwcx);
WINUSERAPI BOOL WINAPI		GetMessage				(__out LPMSG lpMsg, __in_opt HWND hWnd, __in UINT wMsgFilterMin, __in UINT wMsgFilterMax);
WINUSERAPI BOOL WINAPI		TranslateMessage		(__in CONST MSG *lpMsg);
WINUSERAPI LRESULT WINAPI	DispatchMessage			(__in CONST MSG *lpMsg);
WINUSERAPI BOOL WINAPI		PeekMessage				(__out LPMSG lpMsg, __in_opt HWND hWnd, __in UINT wMsgFilterMin, __in UINT wMsgFilterMax, __in UINT wRemoveMsg);
LRESULT CALLBACK			DefWindowProc			(__in HWND hWnd, __in UINT Msg, __in WPARAM wParam, __in LPARAM lParam);
WINUSERAPI BOOL WINAPI		PostMessage				(__in_opt HWND hWnd, __in UINT Msg, __in WPARAM wParam, __in LPARAM lParam);
WINUSERAPI HWND WINAPI		GetDesktopWindow		(VOID);
WINUSERAPI BOOL WINAPI		GetClientRect			(__in HWND hWnd, __out LPRECT lpRect);
WINUSERAPI BOOL WINAPI		GetWindowRect			(__in HWND hWnd, __out LPRECT lpRect);
WINUSERAPI BOOL WINAPI		SetRect					(__out LPRECT lprc, __in int xLeft, __in int yTop, __in int xRight, __in int yBottom);
WINGDIAPI HGDIOBJ WINAPI	SelectObject			(__in HDC hdc, __in HGDIOBJ h);
WINGDIAPI COLORREF WINAPI	SetTextColor			(__in HDC hdc, __in COLORREF color);
WINGDIAPI int WINAPI		SetBkMode				(__in HDC hdc, __in int mode);
WINUSERAPI int WINAPI		DrawText				(__in HDC hdc, cs8* lpchText, __in int cchText, __inout LPRECT lprc, __in UINT format);
WINBASEAPI DWORD WINAPI		GetTickCount			(VOID);
WINBASEAPI VOID WINAPI		InitializeCriticalSection(__out LPCRITICAL_SECTION lpCriticalSection);
WINBASEAPI VOID WINAPI		EnterCriticalSection	(__inout LPCRITICAL_SECTION lpCriticalSection);
WINBASEAPI BOOL WINAPI		TryEnterCriticalSection	(__inout LPCRITICAL_SECTION lpCriticalSection);
WINBASEAPI VOID WINAPI		LeaveCriticalSection	(__inout LPCRITICAL_SECTION lpCriticalSection);
WINUSERAPI VOID WINAPI		PostQuitMessage			(__in int nExitCode);
WINUSERAPI HCURSOR WINAPI	LoadCursor				(__in_opt HINSTANCE hInstance, __in cs8* lpCursorName);
WINBASEAPI HMODULE WINAPI	GetModuleHandle			(__in_opt cs8* lpModuleName);
WINUSERAPI int WINAPI		SetWindowRgn			(__in HWND hWnd, __in_opt HRGN hRgn, __in BOOL bRedraw);
