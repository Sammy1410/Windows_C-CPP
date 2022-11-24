#ifndef COLORS_H
#define COLORS_H

#include <essentials.h>

#ifdef __cplusplus
extern "C" {
#endif

    //store color data in BGR format since BitBlt reverse blends
    #define red RGB(69,56,255)
    #define green RGB(73,139,0)
    #define blue RGB(255,0,0)
    #define best RGB(78,28,17)
    #define white RGB(255,255,255)
    #define black RGB(0,0,0)
    #define shadow RGB(178,175,191)
    #define Wincolor RGB(240,240,240)
    #define DarkWincolor RGB(15,15,15)

    //color data for text
    #define redT RGB(255,56,69)
    #define greenT RGB(0,139,73)
    #define blueT RGB(0,0,255)
    #define bestT RGB(17,28,78)


#ifdef __cplusplus
}
#endif

#endif