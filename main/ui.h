// by M1Rin(Aerotica), 2023.12

#pragma once

#include <windows.h>
#include <string>

struct Aera {
    Aera(int x, int y, int w, int h) : x(x), y(y), w(w), h(h) {};
    int x, y, w, h;
};

struct ControlInfo {
    ControlInfo(std::wstring className, std::wstring title, int id, DWORD dwStyle) : className(className), title(title), id(id), dwStyle(dwStyle) {};
    std::wstring className, title;
    DWORD id, dwStyle;
};

HFONT generateFont(std::wstring fontName, int size);
HWND createControlInWindow(ControlInfo info, Aera aera, HWND hParent, HFONT hFont);
