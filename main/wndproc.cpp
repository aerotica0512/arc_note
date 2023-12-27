// by M1Rin(Aerotica), 2023.12

#include "wndproc.h"
#include "init_ui.h"
#include "ui.h"
#include "resource_id.h"

LRESULT ProcWinMain(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam)
{
    switch(uMessage) {
        case WM_SIZE:
            fixControlsPosition(hWnd, LOWORD(lParam), HIWORD(lParam));
            break;

        case WM_CREATE:
            fixWindowSize(hWnd);
            putControls(hWnd);
            setButtomText(hWnd, 0);
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
