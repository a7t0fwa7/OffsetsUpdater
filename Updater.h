#pragma once
#include "FileIO.hpp"

namespace Updater
{
	BOOL Check(const BYTE* pData, const BYTE* bMask, const char* szMask);
	UINT64 FindPattern(BYTE *bMask, char* szMask, DWORD dwOffset);
	UINT64 FindPointerAddressPattern(BYTE *bMask, char* szMask, DWORD dwOffset);
}

namespace Patterns
{
	static CONST unsigned char Example[] = {0x48, 0x55, 0x56, 0x57, '?', '?', '?', '?'};
}

namespace Offsets
{
	static CONST UINT64 MemoryAddressToFind = Updater::FindPattern((unsigned char*)Patterns::Example, "xxxx????", 0); //examples
}
