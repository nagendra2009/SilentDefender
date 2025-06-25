#include <windows.h>
#include "gui/include/main_window.h"

// Entry point for any Win32 GUI application
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nCmdShow)
{
    // Register window class
    RegisterMainWindowClass(hInstance);

    // Create and show main window
    HWND hwnd = CreateMainWindow(hInstance, nCmdShow);
    if (!hwnd) {
        MessageBox(NULL, "Failed to create window.", "Error", MB_ICONERROR);
        return 1;
    }

    // Message loop (event loop)
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}
