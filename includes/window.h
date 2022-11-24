#ifndef WINDOW_H_INCLUDED
#define WINDOW_H_INCLUDED

#include <essentials.h>
#include <screen/window.h>

#ifdef __cplusplus
extern "C" {
#endif

    WINDOW window;
    float scale=100;


    uint32_t *WinBuffer;
    HDC BufferMem;
    HBITMAP BufferBMP;

#ifdef __cplusplus
}
#endif

#endif