// SystemInfo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <mmsystem.h>
#include <string>
#include <tchar.h>
#pragma warning(disable : 4996)


int main()
{
	setlocale(LC_ALL, "Russian");
	char device[256];
	char user[256];
	
	char winpath[256];
	char syspath[256];
	char temppath[256];

	DWORD size;

	//имя компьютера и имя пользователя

	size = sizeof(device);
	GetComputerNameA((LPSTR)device, &size);
	size = sizeof(user);
	GetUserNameA((LPSTR)user, &size);
	std::cout << "Computer Name: " << device << std::endl;
	std::cout << "Username: " << user << std::endl;

	//пути к системным каталогам Windows

	size = sizeof(winpath);
	GetWindowsDirectoryA((LPSTR)winpath, size);
	GetSystemDirectoryA((LPSTR)syspath, size);

	GetTempPathA(size, (LPSTR)temppath);
	std::cout << "Windows directory: " << winpath << std::endl;
	std::cout << "System directory: " << syspath << std::endl;
	std::cout << "Temp directory: " << temppath << std::endl;

	//версия операционной системы

	OSVERSIONINFOW versionInfo;
	versionInfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFOW);
	LPOSVERSIONINFOW ptrVersionInfo = &versionInfo;

	GetVersionEx(&versionInfo);
	_tprintf(TEXT("\nOS version [Major.Minor.Build_number]: "));
	_tprintf(TEXT("%lu.%lu.%lu\n"), versionInfo.dwMajorVersion, versionInfo.dwMinorVersion, versionInfo.dwBuildNumber);

	//системные метрики (не менее двух метрик)

	//Ширина прямоугольника, в пределах которого оба щелчка мыши должны быть опознаны,как двойной щелчок
	int x = GetSystemMetrics(SM_CXDOUBLECLK); 
	std::cout << "SM_CXDOUBLECLK: " << x << std::endl;

	int y = GetSystemMetrics(SM_CYMIN); //Минимальная высота окна
	std::cout << "SM_CYMIN: " << y << std::endl;

	//системные параметры (не менее двух параметров)

	int uLines;
	SystemParametersInfo(SPI_GETWHEELSCROLLLINES, 0, &uLines, 0);

	//количество пролистываемых строк за один поворот колесика мыши
	std::cout << "SPI_GETWHEELSCROLLLINES: " << uLines << std::endl;

	int uChars;
	SystemParametersInfo(SPI_GETWHEELSCROLLCHARS, 0, &uChars, 0);

	//количество пролистываемых строк за один поворот колесика мыши
	std::cout << "SPI_GETWHEELSCROLLCHARS: " << uChars << std::endl;
}
