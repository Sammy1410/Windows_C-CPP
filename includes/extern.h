#ifndef EXTERN_H_INCLUDED
#define EXTERN_H_INCLUDED

#include <essentials.h>
#include <utilis.h>
#include <input/keyboard.h>
#include <input/mouse.h>
#include <screen/window.h>


    #ifndef FILES_H_INCLUDED
        extern FILE *err_logs,*warn_logs,*msg_logs,*tr_logs;
    #endif

    #ifndef INPUT_H_INCLUDED
        extern keydata *key;
        extern MouseButton Lbutton,Mbutton,Rbutton;
        extern POINT mouse;
        extern FCOORD mousePos;
    #endif

    #ifndef TIMEVAR_H_INCLUDED
        extern float runtime;
    #endif


    #ifndef THREADS_H_INCLUDED
        extern BOOL WindowInitialized,
                    FrameUpdated,
                    screenEnable,
                    WindowThreadDone,
                    WorkerThreadDone;
    #endif


    #ifndef WINAPI_H_INCLUDED
        extern HWND MainHandle;
        extern HDC DeviceContext;

    #endif

    #ifndef WINDOW_H_INCLUDED
        extern WINDOW window;
        extern float scale;
        extern uint32_t *WinBuffer;
    #endif

#endif