#ifndef THREADS_H_INCLUDED
#define THREADS_H_INCLUDED

#ifdef __cplusplus 
extern "C" {
#endif
    //thread start bool
    BOOL WindowInitialized=0;

    //thread work bool
    BOOL FrameUpdated=0;
    BOOL screenEnable=0;
    BOOL WindowThreadDone=0;
    BOOL WorkerThreadDone=0;


#ifdef __cplusplus 
}
#endif

#endif
