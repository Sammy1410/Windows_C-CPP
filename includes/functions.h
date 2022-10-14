#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <screen/shapes.h>

#ifdef __cplusplus
extern "C" {
#endif

    void *WorkerThread(void *vargp);
    void *GraphicsUpdater(void *vargp);
    void *InputThreadFunc(void *vargp);

    int _InitializeWindow(HINSTANCE _thisInstance,int _ConsoleShowing);
    LRESULT CALLBACK MainHandleMsg(HWND _MainHandle,UINT uMsg,WPARAM wParam,LPARAM lparam);

#ifdef __cplusplus
}
#endif
    
int location(int x,int y);
void CanvasDraw(int x,int y,COLORREF color);

void _exit(int err_code);

void Circle_Create(circle Circle);

#endif