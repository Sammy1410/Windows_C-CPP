#ifndef WINAPI_H_INCLUDED
#define WINAPI_H_INCLUDED

#include <essentials.h>

#ifdef __cplusplus
extern "C" {
#endif
    LPCWSTR CLASS_NAME= L"Main Window Class";
    const wchar_t AppHeader[]=L"Default_WindowName";

    HWND MainHandle,ActiveWindow;
    HINSTANCE MainInstance,prevMainInstance;
    PSTR pCmdLine;
    int ConsoleShowing;

    WNDCLASSW MainWindowClass={};
    HDC DeviceContext;
    MSG MainWinMsg = {};

#ifdef __cplusplus
}
#endif


#endif