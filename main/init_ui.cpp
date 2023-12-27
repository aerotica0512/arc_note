// by M1Rin(Aerotica), 2023.12

#include "init_ui.h"
#include "ui.h"
#include "resource_id.h"
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
	wndclass.hIcon = LoadIcon(0, IDI_APPLICATION);
	wndclass.style = CS_HREDRAW|CS_VREDRAW;
	wndclass.lpfnWndProc = (WNDPROC)ProcWinMain;
	wndclass.hbrBackground = GetSysColorBrush(COLOR_3DFACE);
	wndclass.lpszClassName = lpszClassName;
	RegisterClassExW(&wndclass);
	
    return;
}

LPCWSTR lpszWindowTitleFormat = L"Aerotica单词本 (build_%d, STAGE %d)";
void createMainWindow(void)
{
    HINSTANCE hInstance = GetModuleHandleW(NULL);
    HWND hWnd;

    wchar_t titleBuffer[256];
    generateWindowTitle(titleBuffer, lpszWindowTitleFormat);
	
    hWnd = CreateWindowExW(0, lpszClassName, titleBuffer,
						  WS_OVERLAPPEDWINDOW|WS_CLIPCHILDREN|WS_CLIPSIBLINGS,
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

void putControls(HWND hWnd)
{
	HFONT hFontMSYH = generateFont(L"Microsoft Yahei UI", 20);
	HFONT hFontMSYH2 = generateFont(L"Microsoft Yahei UI", 40);

	createControlInWindow(ControlInfo(L"edit", L"", IDC_SEARCH_BOX, ES_LEFT|WS_BORDER), Area(15, 15, 210, 25), hWnd, hFontMSYH);
	createControlInWindow(ControlInfo(L"LISTBOX", L"", IDC_WORDS_LIST, LBS_STANDARD), Area(15, 50, 210, MAINWIN_YSIZE-90), hWnd, hFontMSYH);
	createControlInWindow(ControlInfo(L"button", L"添加", IDC_ADD_BUTTON, 0), Area(15, MAINWIN_YSIZE-40, 65, 25), hWnd, hFontMSYH);
	createControlInWindow(ControlInfo(L"button", L"编辑", IDC_EDIT_BUTTON, 0), Area(87, MAINWIN_YSIZE-40, 65, 25), hWnd, hFontMSYH);
	createControlInWindow(ControlInfo(L"button", L"删除", IDC_DELETE_BUTTON, 0), Area(159, MAINWIN_YSIZE-40, 65, 25), hWnd, hFontMSYH);
	createControlInWindow(ControlInfo(L"static", L"", IDC_TEXT, 0), Area(250, 15, MAINWIN_XSIZE-265, 40), hWnd, hFontMSYH2);
	createControlInWindow(ControlInfo(L"edit", L"", IDC_MEANING_BOX, ES_MULTILINE|ES_READONLY|ES_AUTOVSCROLL|WS_BORDER), 
						  Area(250, 65, MAINWIN_XSIZE-265, MAINWIN_YSIZE-120), hWnd, hFontMSYH);
	createControlInWindow(ControlInfo(L"static", L"", IDC_TEXT_BUTTOM, 0), Area(250, MAINWIN_YSIZE-37, MAINWIN_XSIZE-265, 20), hWnd, hFontMSYH);

	return;
}

void fixControlsPosition(HWND hWnd, int x, int y)
{
	setControlPosition(hWnd, IDC_SEARCH_BOX, Area(15, 15, 210, 25));
	setControlPosition(hWnd, IDC_WORDS_LIST, Area(15, 50, 210, y-90));
	setControlPosition(hWnd, IDC_ADD_BUTTON, Area(15, y-40, 65, 25));
	setControlPosition(hWnd, IDC_EDIT_BUTTON, Area(87, y-40, 65, 25));
	setControlPosition(hWnd, IDC_DELETE_BUTTON, Area(159, y-40, 65, 25));
	setControlPosition(hWnd, IDC_TEXT, Area(250, 15, x-265, 40));
	setControlPosition(hWnd, IDC_MEANING_BOX, Area(250, 65, x-265, y-120));
	setControlPosition(hWnd, IDC_TEXT_BUTTOM, Area(250, y-37, x-265, 20));

	return;
}
