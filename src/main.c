#ifndef UNICODE
#define UNICODE
#endif

#include <essentials.h>
#include <WinAPI.h>
#include <files.h>
#include <functions.h>
#include <extern.h>



#include "inline/default.c"
/*
#include "threads.c"
#include "default.c"
#include "WinAPI.c"
#include "input.c"
#include "graphic.c"

#include "frame.cpp"
#include "functions.cpp"
*/

int WINAPI WinMain(HINSTANCE thisInstance,HINSTANCE prevInstance,PSTR _pCmdLine,int _ConsoleShowing){
    //Threads needed are defined    
    pthread_t GraphicsThread,WorkThread,InputThread;

    //The value of main Window are global so it is sent from these local variables in WinMain
    MainInstance = thisInstance;
    prevMainInstance = prevInstance;
    pCmdLine = _pCmdLine;
    //ConsoleShowing = _ConsoleShowing;
    ConsoleShowing = 0;
    
    //Default info for the application is set here
    SetDefaults();

    int checkWindow;
    
    err_logs=fopen(".\\logs\\error_logs.txt","a");
    msg_logs=fopen(".\\logs\\message_logs.txt","a");
    //msg_logs=fopen("./logs/message_logs.txt","w");
    warn_logs=fopen(".\\logs\\warn_logs.txt","a");
    tr_logs=fopen(".\\logs\\trial_logs.txt","w");

    //Threads initialized and connected to respective main functions
    pthread_create(&GraphicsThread,NULL,GraphicsUpdater,NULL);
    pthread_create(&WorkThread,NULL,WorkerThread,NULL);
    //pthread_create(&InputThread,NULL,InputThreadFunc,NULL);

    checkWindow=_InitializeWindow(thisInstance,_ConsoleShowing);
    WindowThreadDone=1;
    while (GetMessage(&MainWinMsg,NULL,0,0))
    {  
        Sleep(1);
        TranslateMessage(&MainWinMsg);
        DispatchMessage(&MainWinMsg);
    }
    
    _exit(0);   
}

#include "inline/WinAPI.c"



