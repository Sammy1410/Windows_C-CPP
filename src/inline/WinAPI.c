#include <essentials.h>
#include <files.h>
#include <WinAPI.h>
#include <extern.h>


LRESULT CALLBACK MainHandleMsg(HWND _MainHandle,UINT uMsg,WPARAM wParam,LPARAM lparam){
    switch(uMsg){
      case WM_DESTROY:
        PostQuitMessage(0);
        break;
      case WM_CLOSE:
      case WM_QUIT:
        _exit(0);
    }
    return DefWindowProc(_MainHandle,uMsg, wParam, lparam);
}



//Window Procedure for Main Application Window
/*
This only sends message back to Main Program Thread
*/

//Sets values to MainWindow Class, registers it and creates a window
//Finally it shows the window in the screen
int _InitializeWindow(HINSTANCE _thisInstance,int _ConsoleShowing){
    /*int len=wcslen(CLASS_NAME);
    wchar_t CLASS[len];
    swprintf(CLASS,sizeof(CLASS_NAME),CLASS_NAME);
*/

    MainWindowClass.lpfnWndProc = MainHandleMsg;
    MainWindowClass.hInstance=_thisInstance;
    MainWindowClass.lpszClassName= CLASS_NAME;

    RegisterClassW(&MainWindowClass);

    MainHandle = CreateWindowExW(
        0,
        CLASS_NAME,
        AppHeader,
        WS_OVERLAPPEDWINDOW | WS_MAXIMIZE ,
        window.xPos,
        window.yPos,
        window.width,
        window.height,
        NULL,
        NULL,
        _thisInstance,
        NULL
    );


    if(MainHandle == NULL){
        return 0;
    }
    //FreeConsole();

    ShowWindow(MainHandle,_ConsoleShowing);
    return 1;
}
