// by M1Rin(Aerotica), 2023.12

#include <windows.h>
#include <cstdio>

void initUI(void);
int messageLoop(void);

#define UNUSED  __attribute__((unused))
int WINAPI WinMain(HINSTANCE UNUSED hInstance, HINSTANCE UNUSED hPrevInstance, LPSTR UNUSED lpszCmdLine, int UNUSED nCmdShow)
{
    initUI();
    messageLoop();
    return 0;
}

int messageLoop(void)
{
	MSG message;
	
	while(GetMessageW(&message, NULL, 0, 0) != 0) {
		TranslateMessage(&message);
		DispatchMessageW(&message);
	}

	return 0;
}
