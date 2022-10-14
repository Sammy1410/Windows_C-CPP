#ifndef MOUSE_H
#define MOUSE_H

#include <utilis.h> 

#ifdef __cplusplus
    extern "C" {
#endif
      typedef struct {
        BOOL isHolding;
        float holdStart;
        float holdEnd;
        float holdTime;
        float lastHoldTime;
        FCOORD lastClickPos;
    }MouseButton;

#ifdef __cplusplus
}
#endif

#endif