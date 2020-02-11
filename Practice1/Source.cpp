#include <windows.h>
#include <string.h>
#include <stdio.h>

LRESULT CALLBACK WindowFunc(HWND, UINT, WPARAM, LPARAM);
char szWinName[] = "MyWin"; // ��� ������ ����
char str[255] = ""; // ������ ������
int WINAPI WinMain(HINSTANCE hThisInst, HINSTANCE hPrevInst, LPSTR lpszArgs, int nWinMode)
{
	HWND hwnd; // ���������� ����
	MSG msg; // ��������� ��������� Windows
	WNDCLASSEX wcl; // ���������, ������������ ����� ����
	/* ����������� ������ ���� */
	wcl.hInstance = hThisInst; // ������ � ������ �����������
	wcl.lpszClassName = szWinName; // ��� ������ ����
	wcl.lpfnWndProc = WindowFunc; // ������� �������
	wcl.style = 0; // ������������ ����� ���� �� ���������
	wcl.cbSize = sizeof(WNDCLASSEX); // ��������� �������
	// WNDCLASSEX
	wcl.hIcon = LoadIcon(NULL, IDI_APPLICATION); // ������� ������
	wcl.hIconSm = LoadIcon(NULL, IDI_WINLOGO); // ���������
	// ������
	wcl.hCursor = LoadCursor(NULL, IDC_ARROW); // ����� �������
	wcl.lpszMenuName = NULL; // ���� ���
	wcl.cbClsExtra = 0; // �������������� ���������� ���
	wcl.cbWndExtra = 0; // �������������� ���������� ���
	wcl.hbrBackground = (HBRUSH)GetStockObject(HOLLOW_BRUSH);
	// ��������� ���� ����
	/* ����������� ������ ���� */
	if (!RegisterClassEx(&wcl)) return 0;
	/* ������ ���� ���� */
	hwnd = CreateWindow(szWinName, // ��� ������ ����
		"API application", // ���������
		WS_OVERLAPPEDWINDOW, // ����� ���� - ����������
		CW_USEDEFAULT, // ���������� X - �������� Windows
		CW_USEDEFAULT, // ���������� Y - �������� Windows
		CW_USEDEFAULT, // ������ - �������� Windows
		CW_USEDEFAULT, // ������ - �������� Windows
		HWND_DESKTOP, // ��� ������������� ����
		NULL, // ��� ����
		hThisInst, // ������ � ������ ����������� ���������
		NULL // �������������� ��������� �����������
	);
	/* ����� ���� */
	ShowWindow(hwnd, nWinMode);
	UpdateWindow(hwnd);
	/* �������� ����� ��������� ��������� */
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg); //��������� ������������� ����������
		DispatchMessage(&msg); // ������� ���������� Windows
	}
	return msg.wParam;
} // WinMain
/* ������� ������� ��������� ���������, ���������� �� ������� ���������. */
LRESULT CALLBACK WindowFunc(HWND hwnd, UINT message,
	WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	switch (message)
	{
	case WM_CHAR: // ���������� ���������
   //�� ����������
		break;
	case WM_LBUTTONDOWN: // ����������
   //������� ����� ������ ����
		break;
	case WM_RBUTTONDOWN: // ����������
   //������� ������ ������ ����
		break;
	case WM_DESTROY: // ���������� ���������
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, message, wParam,
			lParam);
	}
	return 0;
}