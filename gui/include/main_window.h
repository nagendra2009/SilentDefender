#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <windows.h>

// Window class name
#define WINDOW_CLASS_NAME "AntivirusMainWindow"

// Window title
#define WINDOW_TITLE "⚠️ Antivirus Scanner"

// Forward declaration of message procedure
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

// Function to register window class
void RegisterMainWindowClass(HINSTANCE hInstance);

// Function to create the main application window
HWND CreateMainWindow(HINSTANCE hInstance, int nCmdShow);

#endif // MAIN_WINDOW_H
