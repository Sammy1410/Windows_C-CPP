#include <essentials.h>
#include <essentials.hpp>
#include <screen/text.hpp>
#include <screen/text.h>
#include <extern.h>

void PushText(const WCHAR *txt,int posX,int posY,float Fheight,float Fwidth,WCHAR* font,COLORREF color){
    text T;
    T.color=color;
    T.pos.X=posX;
    T.pos.Y=posY;
    swprintf_s(T.font,font);
    swprintf_s(T.t,txt);

    T.Lheight=Fheight;
    T.Lwidth=Fwidth;
    stringOut.push_back(T);
    textCount++;
}


void _exit(int err_code){
    fclose(err_logs);
    fclose(warn_logs);
    fclose(msg_logs);
    //ReleaseDC(MainHandle,DeviceContext);
    exit(err_code);
}

int location(int x,int y){
    return (y*window.width+x);
}

