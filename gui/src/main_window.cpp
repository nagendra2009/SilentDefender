#include "../include/main_window.h"
#include "../include/layout.h"
#include "../include/controls.h"

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_CREATE:
        CreateControls(hwnd);
        return 0;

    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);
        HBRUSH bgBrush = CreateSolidBrush(RGB(30, 30, 30));  // Dark background
        FillRect(hdc, &ps.rcPaint, bgBrush);
        DeleteObject(bgBrush);
        EndPaint(hwnd, &ps);
        return 0;
    }

    case WM_CTLCOLORSTATIC: {
        HDC hdcStatic = (HDC)wParam;
        SetTextColor(hdcStatic, RGB(200, 200, 200));           // Light grey text
        SetBkMode(hdcStatic, TRANSPARENT);
        return (INT_PTR)CreateSolidBrush(RGB(30, 30, 30));     // Match background
    }

    case WM_CTLCOLORBTN: {
        HDC hdcBtn = (HDC)wParam;
        SetTextColor(hdcBtn, RGB(255, 255, 255));              // White text
        SetBkMode(hdcBtn, TRANSPARENT);
        return (INT_PTR)CreateSolidBrush(RGB(50, 120, 220));   // Blue button
    }

    case WM_COMMAND:
        switch (LOWORD(wParam)) {
        case ID_BTN_SELECT_FOLDER:
            // Folder select logic here
            break;
        case ID_BTN_SCAN:
            // Scan logic here
            break;
        case ID_BTN_QUARANTINE:
            // Quarantine logic here
            break;
        }
        return 0;

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

void RegisterMainWindowClass(HINSTANCE hInstance) {
    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = WINDOW_CLASS_NAME;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);  // Not used, WM_PAINT handles background
    RegisterClass(&wc);
}

HWND CreateMainWindow(HINSTANCE hInstance, int nCmdShow) {
    int screenW = GetSystemMetrics(SM_CXSCREEN);
    int screenH = GetSystemMetrics(SM_CYSCREEN);

    HWND hwnd = CreateWindowEx(
        0,
        WINDOW_CLASS_NAME,
        WINDOW_TITLE,
        WS_POPUP | WS_VISIBLE,    // Fullscreen
        0, 0, screenW, screenH,
        NULL, NULL, hInstance, NULL
    );

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);
    return hwnd;
}
