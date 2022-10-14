#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <essentials.h>

#ifdef __cplusplus
    extern "C" {
#endif
    typedef struct {
        BOOL state;
        BOOL isPressed;
        BOOL wasPressed;
        float holdStart;
        float holdEnd;
        float holdTime;
        float lastHoldTime;
    }keydata; 
#ifdef __cplusplus
}
#endif

#endif