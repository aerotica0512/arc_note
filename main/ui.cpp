// by M1Rin(Aerotica), 2023.12

#include "ui.h"

HFONT generateFont(std::wstring fontName, int size)
{
    HFONT hFont = CreateFontW(size, 0, 0, 0, FW_NORMAL, FALSE, FALSE, 0, ANSI_CHARSET, 
							  OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
						      DEFAULT_PITCH, fontName.c_str());
    return hFont;
}

HWND createControlInWindow(ControlInfo info, Aera aera, HWND hParent, HFONT hFont)
{
    HINSTANCE hInstance = GetModuleHandleW(NULL);

    HWND hControl = CreateWindowExW(0, info.className.c_str(), info.title.c_str(), WS_CHILD|WS_VISIBLE|info.dwStyle, 
                                    aera.x, aera.y, aera.w, aera.h,
							        hParent, (HMENU)info.id, hInstance, NULL);
	SendMessageW(hControl, WM_SETFONT, (WPARAM)hFont, 0);

    return hControl;
}
