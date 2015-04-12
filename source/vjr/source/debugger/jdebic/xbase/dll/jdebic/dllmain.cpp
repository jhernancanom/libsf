//////////
//
// dllmain.cpp
//
//////




#include "jdebic.h"




BOOL APIENTRY DllMain(	HMODULE hModule,
						DWORD   ul_reason_for_call,
						LPVOID  lpReserved	)
{
	switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
			// Store our module
			ghInstance = hModule;
			InitializeCriticalSection(&gcs_accessMessages);
			break;

		case DLL_THREAD_ATTACH:
			_asm nop;
			break;

		case DLL_THREAD_DETACH:
			_asm nop;
			break;

		case DLL_PROCESS_DETACH:
			break;
	}
	return TRUE;
}
