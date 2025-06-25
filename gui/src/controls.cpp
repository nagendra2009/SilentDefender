#include <windows.h>
#include <commctrl.h>
#pragma comment(lib, "comctl32.lib")

#include "../include/controls.h"
#include "../include/layout.h"

void CreateControls(HWND hwnd) {
    // Folder Label
    CreateWindowEx(0, "STATIC", "Folder to Scan:", WS_VISIBLE | WS_CHILD,
                   MARGIN_LEFT, MARGIN_TOP, LABEL_WIDTH, CONTROL_HEIGHT,
                   hwnd, NULL, NULL, NULL);

    // Select Folder Button
    CreateWindowEx(0, "BUTTON", "Select Folder",
                   WS_VISIBLE | WS_CHILD | BS_FLAT,
                   MARGIN_LEFT + LABEL_WIDTH + GAP, MARGIN_TOP, BUTTON_WIDTH, BUTTON_HEIGHT,
                   hwnd, (HMENU)ID_BTN_SELECT_FOLDER, NULL, NULL);

    // Path Label
    CreateWindowEx(0, "STATIC", "Path:", WS_VISIBLE | WS_CHILD,
                   MARGIN_LEFT, MARGIN_TOP + 40, LABEL_WIDTH, CONTROL_HEIGHT,
                   hwnd, NULL, NULL, NULL);

    CreateWindowEx(0, "STATIC", "(No folder selected)", WS_VISIBLE | WS_CHILD,
                   MARGIN_LEFT + LABEL_WIDTH + GAP, MARGIN_TOP + 40, 300, CONTROL_HEIGHT,
                   hwnd, (HMENU)ID_LABEL_FOLDER_PATH, NULL, NULL);

    // Scan Now Button
    CreateWindowEx(0, "BUTTON", "Scan Now",
                   WS_VISIBLE | WS_CHILD | BS_FLAT,
                   MARGIN_LEFT, MARGIN_TOP + 80, BUTTON_WIDTH, BUTTON_HEIGHT,
                   hwnd, (HMENU)ID_BTN_SCAN, NULL, NULL);

    // Quarantine Button
    CreateWindowEx(0, "BUTTON", "Quarantine",
                   WS_VISIBLE | WS_CHILD | BS_FLAT,
                   MARGIN_LEFT + BUTTON_WIDTH + GAP, MARGIN_TOP + 80, BUTTON_WIDTH, BUTTON_HEIGHT,
                   hwnd, (HMENU)ID_BTN_QUARANTINE, NULL, NULL);

    // ListView Setup
    INITCOMMONCONTROLSEX icex = { sizeof(icex), ICC_LISTVIEW_CLASSES };
    InitCommonControlsEx(&icex);

    HWND hList = CreateWindowEx(WS_EX_CLIENTEDGE, WC_LISTVIEW, "",
                                WS_VISIBLE | WS_CHILD | WS_BORDER | LVS_REPORT,
                                MARGIN_LEFT, MARGIN_TOP + 130, 440, 200,
                                hwnd, (HMENU)ID_LIST_RESULTS, GetModuleHandle(NULL), NULL);

    if (hList) {
        ListView_SetExtendedListViewStyle(hList, LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

        LVCOLUMN col = {};
        col.mask = LVCF_TEXT | LVCF_WIDTH;

        col.pszText = (LPSTR)"File Name"; col.cx = 300;
        ListView_InsertColumn(hList, 0, &col);

        col.pszText = (LPSTR)"Status"; col.cx = 120;
        ListView_InsertColumn(hList, 1, &col);
    }

    // Clean/Infected Labels
    CreateWindowEx(0, "STATIC", "✔ Clean Files: 0", WS_VISIBLE | WS_CHILD,
                   MARGIN_LEFT, MARGIN_TOP + 350, 200, CONTROL_HEIGHT,
                   hwnd, (HMENU)ID_LABEL_CLEAN_COUNT, NULL, NULL);

    CreateWindowEx(0, "STATIC", "⚠ Infected Files: 0", WS_VISIBLE | WS_CHILD,
                   MARGIN_LEFT + 220, MARGIN_TOP + 350, 200, CONTROL_HEIGHT,
                   hwnd, (HMENU)ID_LABEL_INFECTED_COUNT, NULL, NULL);
}
