#ifndef TIMEVAR_H_INCLUDED
#define TIMEVAR_H_INCLUDED


#ifdef __cplusplus
extern "C" {
#endif
    float runtime,program_time;

    double frametime=0,loop_time=0;
    float targetFPS=60.00f;

#ifdef __cplusplus
}
#endif
/*
void GetLocalTime(LPSYSTEMTIME lpSystemTime);
SYSTEMTIME *Time;
Time=(struct _SYSTEMTIME*)malloc(sizeof(struct _SYSTEMTIME));


*/

#endif