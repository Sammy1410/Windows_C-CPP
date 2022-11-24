#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

#include <essentials.h>
#include <input/keyboard.h>
#include <input/mouse.h>
#include <utilis.h>

#ifdef __cplusplus
extern "C" {
#endif
    keydata key[256];

    POINT mouse;
    FCOORD mousePos;

    MouseButton Lbutton,Mbutton,Rbutton;

#ifdef __cplusplus
}
#endif

#endif