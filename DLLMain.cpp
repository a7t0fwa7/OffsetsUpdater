#include "Updater.hpp"

VOID Initialize()
{
  	AllocConsole();
    freopen("CON", "w", stdout);
		freopen("CON", "r", stdin);
	  printf("%llX - ExampleAddr", Offsets::Example);
  
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	{

		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)&Initialize, 0, 0, 0);

	}break;

	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}
