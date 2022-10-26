#include <essentials.h>
#include <input.h>
#include <extern.h>

extern HWND MainHandle;
extern BOOL WindowInitialized;


BOOL wasPressed(int keyNum){
    if(key[keyNum].wasPressed){
        key[keyNum].wasPressed=0;
        return 1;
    }else{
        //key[keyNum].wasPressed=0;
        return 0;
    }
    
}

void *InputThreadFunc(void *vargp){
    while(!(WindowInitialized)){ }

    while(1){
        if(GetForegroundWindow()!=MainHandle){
            Sleep(10);
            continue;
        }
              
        GetCursorPos(&mouse);
        ScreenToClient(MainHandle, &mouse);
        mousePos.x=(float)mouse.x;
        mousePos.y=(float)mouse.y;
        
        for(int i=0x01;i<=0xFE;i++){
            key[i].state=((GetKeyState(i)) & 0x8000 ? 1:0);
            if(key[i].state){
                if(!key[i].isPressed)
                    key[i].holdStart=runtime;
                key[i].isPressed=1;
                key[i].holdEnd=runtime;
                key[i].holdTime=key[i].holdEnd-key[i].holdStart;
            }else{
                if(key[i].isPressed){
                    key[i].isPressed=0;
                    key[i].wasPressed=1;
                    key[i].holdEnd=runtime;
                    key[i].holdTime=0;
                    key[i].lastHoldTime=key[i].holdEnd-key[i].holdStart;                    
                }
            }
        }
        Sleep(1);
    }
        
}