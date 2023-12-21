// by M1Rin(Aerotica), 2023.12

#include "init_ui.h"
#include "../version.h"

void registerClasses(void);
void createMainWindow(void);
void generateWindowTitle(wchar_t *titleBuffer, const wchar_t *titleFormat);
int TopXY(int a, int b);

LRESULT ProcWinMain(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam);

void initUI(void)
{
    registerClasses();
    createMainWindow();
    return;
}

LPCWSTR lpszClassName = L"Aerotica01-Main";
void registerClasses(void)
{
    HINSTANCE hInstance = GetModuleHandleW(NULL);
    WNDCLASSEXW wndclass;

	memset(&wndclass, 0, sizeof(WNDCLASSEXW));
	wndclass.cbSize = sizeof(WNDCLASSEXW);
	wndclass.hInstance = hInstance;
	wndclass.hCursor = LoadCursor(0, IDC_ARROW);
	wndclass.style = CS_HREDRAW|CS_VREDRAW;
	wndclass.lpfnWndProc = (WNDPROC)ProcWinMain;
	wndclass.hbrBackground = GetSysColorBrush(COLOR_3DFACE);
	wndclass.lpszClassName = lpszClassName;
	RegisterClassExW(&wndclass);
	
    return;
}

LPCWSTR lpszWindowTitleFormat = L"Aerotica Word Notebook (build_%d, STAGE %d)";
void createMainWindow(void)
{
    HINSTANCE hInstance = GetModuleHandleW(NULL);
    HWND hWnd;

    wchar_t titleBuffer[256];
    generateWindowTitle(titleBuffer, lpszWindowTitleFormat);
	
    hWnd = CreateWindowExW(0, lpszClassName, titleBuffer,
						  WS_OVERLAPPEDWINDOW,
						  100, 100, 300, 200,
						  NULL, NULL, hInstance, NULL);
	ShowWindow(hWnd, SW_SHOWNORMAL);
	UpdateWindow(hWnd);

    return;
}

void generateWindowTitle(wchar_t *titleBuffer, const wchar_t *titleFormat)
{
	wsprintfW(titleBuffer, titleFormat, BUILD, STAGE);
	return;
}

// 不要随便去动这个地方！
const int MAINWIN_XSIZE = 720;
const int MAINWIN_YSIZE = 405;
void fixWindowSize(HWND hWnd)
{
	int xWindow, yWindow, xPosition, yPosition;
	RECT rectWindow, rectClient;
	
	GetWindowRect(hWnd, &rectWindow);
	GetClientRect(hWnd, &rectClient);
	
	xWindow = (rectWindow.right - rectWindow.left) - (rectClient.right - rectClient.left) + MAINWIN_XSIZE;
	yWindow = (rectWindow.bottom - rectWindow.top) - (rectClient.bottom - rectClient.top) + MAINWIN_YSIZE;
	xPosition = TopXY(GetSystemMetrics(SM_CXSCREEN), xWindow);
	yPosition = TopXY(GetSystemMetrics(SM_CYSCREEN), yWindow);

	SetWindowPos(hWnd, HWND_TOP, xPosition, yPosition, xWindow, yWindow, 0);
	return;
}

int TopXY(int a, int b)
{
	return (a-b)/2;
}
