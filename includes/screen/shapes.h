#ifndef SHAPES_H
#define SHAPES_H
#include <essentials.h>
#include <utilis.h>

#ifdef __cplusplus
extern "C" {
#endif

        typedef struct _circledata{
                FCOORD center;
                float radius;
                BOOL filled;
                COLORREF color;
                COLORREF defcolor;
                FCOORD *points;
        }circle;

#ifdef __cplusplus
}
#endif

#endif