#include "Updater.hpp"

BOOL Updater::Check(const BYTE* pData, const BYTE* bMask, const char* szMask) {
	for (; *szMask; ++szMask, ++pData, ++bMask)
		if (*szMask != '?' && *pData != *bMask)
			return false;
	return (*szMask) == NULL;
}

UINT64 Updater::FindPattern(BYTE *bMask, char* szMask, DWORD dwOffset)
{
	UINT64 dwLen = 0x010000000000;
	UINT64 dwStartAddress = (UINT64)GetModuleHandleA(NULL);

	__try
	{
		for (UINT64 i = 0; i < dwLen; i++)
			if (Check((BYTE*)(dwStartAddress + i), bMask, szMask))
				return (UINT64)(dwStartAddress + i + dwOffset);
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		MessageBoxA(NULL, szMask, "Error Finding Pattern", MB_OK);
	}

	return 0;
}

UINT64 Updater::FindPointerAddressPattern(BYTE *bMask, char* szMask, DWORD dwOffset) {

	UINT64 dwLen = 0x010000000000;
	UINT64 dwStartAddress = (UINT64)GetModuleHandleA(NULL);

	__try
	{
		for (UINT64 i = 0; i < dwLen; i++)
			if (Check((BYTE*)(dwStartAddress + i), bMask, szMask)) {

				return *(UINT64*)(dwStartAddress + i + dwOffset);
			}
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		MessageBoxA(NULL, szMask, "Error finding pattern.", MB_OK);
	}

	return 0;
}
