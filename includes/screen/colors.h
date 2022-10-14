#ifndef COLORS_H
#define COLORS_H

#include <essentials.h>

#ifdef __cplusplus
extern "C" {
#endif

//store color data in BGR format since BitBlt reverse blends

    static COLORREF red=RGB(69,56,255);
    static COLORREF green=RGB(73,139,0);
    static COLORREF blue=RGB(255,0,0);
    static COLORREF best=RGB(78,28,17);
    static COLORREF white=RGB(255,255,255);
    static COLORREF black=RGB(0,0,0);
    static COLORREF shadow=RGB(178,175,191);
    static COLORREF Wincolor=RGB(240,240,240);
    static COLORREF DarkWincolor=RGB(15,15,15);

    //color data for text
    static COLORREF redT=RGB(255,56,69);
    static COLORREF greenT=RGB(0,139,73);
    static COLORREF blueT=RGB(0,0,255);
    static COLORREF bestT=RGB(17,28,78);


#ifdef __cplusplus
}
#endif

#endif