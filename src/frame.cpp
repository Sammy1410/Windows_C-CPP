#include <essentials.h>
#include <essentials.hpp>
#include <screen/text.h>
#include <window.h>
#include <functions.h>
#include <extern.h>
#include <screen/colors.h>

extern std::vector<text> stringOut;
extern int textCount;

void *GraphicsUpdater(void *vargp){
    HFONT hFont;
    wchar_t myText[64];

    WinBuffer=(uint32_t *)malloc(window.width*window.height*sizeof(uint32_t));

    for (int i=0;i<(window.width*window.height);i++){
       WinBuffer[i]=Wincolor;
    }

    while(!(WindowThreadDone)){ }
    WindowInitialized=1;

  do{
        while(!WorkerThreadDone){}
    ///// 
        DeviceContext=GetDC(MainHandle);
        BufferBMP=CreateBitmap(window.width,window.height,1,sizeof(COLORREF)*8,(void*)WinBuffer);
        BufferMem= CreateCompatibleDC(DeviceContext);
    /////    
    
        for(int i=0;i<textCount;i++){
            swprintf_s(myText, stringOut[i].t);

            hFont = CreateFontW(stringOut[i].Lheight, stringOut[i].Lwidth, 0, 10, FW_DONTCARE,
                0, 0, 0, ANSI_CHARSET,
                OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DRAFT_QUALITY, VARIABLE_PITCH,
                stringOut[i].font);

            SelectObject(BufferMem, hFont);
            SelectObject(BufferMem,BufferBMP);
            SetBkMode(BufferMem, TRANSPARENT);
            SetTextColor(BufferMem,stringOut[i].color);
            TextOutW(BufferMem,stringOut[i].pos.X,stringOut[i].pos.Y,myText,wcslen(stringOut[i].t));
            DeleteObject(hFont);
        }
       
        stringOut.clear();
        textCount=0;
        SelectObject(BufferMem,BufferBMP);
        BitBlt(DeviceContext,0,0,window.width,window.height,BufferMem,0,0,SRCCOPY); 
        
        WorkerThreadDone=0;
   
        
        for (int i=0;i<(window.width*window.height);i++){
            WinBuffer[i]=Wincolor;
        }    
        
        DeleteObject(BufferBMP);
        DeleteDC(BufferMem);
        ReleaseDC(MainHandle,DeviceContext);
        FrameUpdated=1;
        
    }while(1);
    
    free(WinBuffer);
    _exit(0);

}
