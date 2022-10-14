#include <essentials.h>
#include <screen/shapes.h>
#include <screen/colors.h>
#include <screen/text.h>
#include <functions.h>
#include <timevar.h>
#include <threads.h>
extern BOOL WindowInitialized;
extern BOOL screenEnable;
WCHAR defFont[]= L"Segoe UI";

void *WorkerThread(void *vargp){
    clock_t loop_start,loop_end;
    double dt=0;
    static int framelast=0;
    static int framenow=0;
    double _timenow=0;

    while(!WindowInitialized){ }

    circle C;
    C.center= {100,100};
    C.radius= 20;
    C.color= blue;
    do{
        loop_start=clock();
        
        
        if(screenEnable){
            Circle_Create(C);
            //CanvasDraw(10,10,best);
            PushText(L"LED 1",175,230,25,10,defFont,bestT);
        }    
        //Frame Update Message Generator
        loop_end=clock();
        loop_time+=(double)(loop_end-loop_start)/(CLOCKS_PER_SEC);
        loop_start=clock();
        screenEnable=0;
        
        if(frametime>=(1/targetFPS)){
            screenEnable=1;
            WorkerThreadDone=1;
            while(!FrameUpdated){}
            FrameUpdated=0; 
        }
        
        loop_end=clock();
        loop_time+=(double)(loop_end-loop_start)/(CLOCKS_PER_SEC);
        frametime+=loop_time;
        dt=loop_time;
        _timenow+=loop_time;
        loop_time=0;
    }while(1);
}


