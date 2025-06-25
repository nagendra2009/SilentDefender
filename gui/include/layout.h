#ifndef LAYOUT_H
#define LAYOUT_H

#include <windows.h>

// Recommended control size and spacing constants
#define WINDOW_WIDTH     500
#define WINDOW_HEIGHT    450

#define MARGIN_LEFT      20
#define MARGIN_TOP       20
#define CONTROL_HEIGHT   25
#define LABEL_WIDTH      120
#define INPUT_WIDTH      300
#define BUTTON_WIDTH     120
#define BUTTON_HEIGHT    30
#define GAP              10

// Function to create and place all controls inside the window
void CreateControls(HWND hwnd);

#endif // LAYOUT_H
