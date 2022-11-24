#include <essentials.h>
#include <arduino.h>
#include <extern.h>

void startHandle();

void *ArduinoThreadFunc(void *vargp){
    startHandle();
    char readTemp;
   // return 0;
    do{
            
        if (arduinoHandle != INVALID_HANDLE_VALUE)
        {
           ArduinoInitialized=1; 
            
        }else{
            startHandle();
        }
        //do something;

    }while(1);
    
    while(!(WindowInitialized /*&& TimerInitialized*/ && ArduinoInitialized)){ }
    //char *arr=(char *)malloc(50*sizeof(char));
    //wchar_t *send=(wchar_t *)malloc(50*sizeof(char));

    strcpy(Tx,"all off\n");
    WriteFile(arduinoHandle,Tx,strlen(Tx),&bytes_written,NULL);

    do{
        if(updated){
            WriteFile(arduinoHandle,Tx,strlen(Tx),&bytes_written,NULL);
            updated=0;
        }

        Sleep(1);
    }while(1);
    
    CloseHandle(arduinoHandle);
    return 0;
}

void startHandle(){
    arduinoHandle = CreateFileA("\\\\.\\COM6", GENERIC_READ | GENERIC_WRITE, 1, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    arduinoParams.DCBlength=sizeof(arduinoParams);
    GetCommState(arduinoHandle,&arduinoParams);
    
    arduinoParams.BaudRate = 9600;
    arduinoParams.ByteSize = 8;
    arduinoParams.StopBits = TWOSTOPBITS;
    arduinoParams.Parity = NOPARITY;
    SetCommState(arduinoHandle, &arduinoParams);
}
