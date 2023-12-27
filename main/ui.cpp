// by M1Rin(Aerotica), 2023.12

#include "ui.h"
#include "../version.h"
#include "resource_id.h"

HWND getControlFromID(HWND hParent, DWORD id);
void generateButtomText(int count, wchar_t *textBuffer, const wchar_t *textFormat);

HFONT generateFont(std::wstring fontName, int size)
{
    HFONT hFont = CreateFontW(size, 0, 0, 0, FW_NORMAL, FALSE, FALSE, 0, ANSI_CHARSET, 
							  OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
						      DEFAULT_PITCH, fontName.c_str());
    return hFont;
}

HWND createControlInWindow(ControlInfo info, Area area, HWND hParent, HFONT hFont)
{
    HINSTANCE hInstance = GetModuleHandleW(NULL);

    HWND hControl = CreateWindowExW(0, info.className.c_str(), info.title.c_str(), WS_CHILD|WS_VISIBLE|info.dwStyle, 
                                    area.x, area.y, area.w, area.h,
							        hParent, (HMENU)info.id, hInstance, NULL);
	SendMessageW(hControl, WM_SETFONT, (WPARAM)hFont, 0);

    return hControl;
}

void setControlPosition(HWND hParent, DWORD id, Area area)
{
    HWND hControl = getControlFromID(hParent, id);
    SetWindowPos(hControl, NULL, area.x, area.y, area.w, area.h, 0);

    return;
}

HWND getControlFromID(HWND hParent, DWORD id)
{
    HWND hControl = NULL;

    do {
        hControl = FindWindowEx(hParent, hControl, NULL, NULL);

        DWORD thisID = GetWindowLongW(hControl, GWL_ID);
        if(thisID == id) {
            break;
        }
    } while(hControl);

    return hControl;
}

LPCWSTR lpszButtomTitleFormat = L"单词数量: %d  作者: Aerotica %s";
void setButtomText(HWND hParent, int count)
{
    HWND hControl = getControlFromID(hParent, IDC_TEXT_BUTTOM);

    wchar_t textBuffer[256];
    generateButtomText(count, textBuffer, lpszButtomTitleFormat);

    SetWindowTextW(hControl, textBuffer);
    return;
}

void generateButtomText(int count, wchar_t *textBuffer, const wchar_t *textFormat)
{
    wsprintfW(textBuffer, textFormat, count, BD_DATE);
    return;
}