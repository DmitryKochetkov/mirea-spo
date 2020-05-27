#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <sysinfoapi.h>
#include <tchar.h>

int main()
{
	MEMORYSTATUSEX status;
	status.dwLength = sizeof(status);
	GlobalMemoryStatusEx(&status);
	_tprintf(TEXT("There are %*I64d total  KB of extended memory.\n"), 7, status.ullTotalPhys / 1024);
	_tprintf(TEXT("There are %*I64d free  KB of extended memory.\n"), 7, status.ullAvailPhys / 1024);
}
