#include <Windows.h>

#include "GameManager.h"
//#include "BitImage.h"
#include "BitImageManager.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hlnst;
LPCTSTR lpszClass = TEXT("Chess");

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevlnstance
	, LPSTR lpszCmdParam, int nCmdShow)
{
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;
	g_hlnst = hInstance;

	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = WndProc;
	WndClass.lpszClassName = lpszClass;
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);

	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, (HMENU)NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);

	while (GetMessage(&Message, NULL, 0, 0))
	{
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return (int)Message.wParam;
}

HDC hdc;
PAINTSTRUCT ps;

static int x;
static int y;


LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch (iMessage)
	{
	case WM_CREATE:
		SetTimer(hWnd, 1, 300, NULL);
		GameManager::GetInstance()->Init(hdc);
		return 0;
	case WM_TIMER:
		GameManager::GetInstance()->Update(hdc);
		InvalidateRect(hWnd, NULL, FALSE);
		return 0;

	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);		
		GameManager::GetInstance()->Draw(hdc);
		EndPaint(hWnd, &ps);
		return 0;
		
	case WM_LBUTTONDOWN:
		x = LOWORD(lParam);
		y = HIWORD(lParam);

		GameManager::GetInstance()->Input(x, y, hWnd);
		return 0;

	case WM_DESTROY:
		GameManager::GetInstance()->Release();
		KillTimer(hWnd, 1);
		PostQuitMessage(0);
		return 0;
	}

	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}