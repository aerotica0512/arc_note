// by M1Rin(Aerotica), 2023.12

#include "wndproc.h"
#include "init_ui.h"

LRESULT ProcWinMain(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam)
{
    switch(uMessage) {
        case WM_CREATE:
            fixWindowSize(hWnd);
            break;

        case WM_CLOSE:
			DestroyWindow(hWnd);
			PostQuitMessage(0);
            break;

        default:
            return DefWindowProcW(hWnd, uMessage, wParam, lParam);
    }

    return FALSE;
}
