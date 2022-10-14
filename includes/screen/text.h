#ifndef TEXT_H
#define TEXT_H


#ifdef __cplusplus
extern "C"{
#endif

    typedef struct {
        COORD pos;
        float Lheight;
        float Lwidth;
        int len;
        COLORREF color;
        WCHAR font[32];
        WCHAR t[640];    
    }text;

#ifdef __cplusplus
}
#endif
void PushText(const WCHAR *txt,int posX,int posY,float Fheight,float Fwidth,WCHAR* font,COLORREF color);


#endif