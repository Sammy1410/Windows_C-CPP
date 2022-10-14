#include <essentials.h>
#include <screen/shapes.h>
#include <extern.h>
//extern uint32_t *WinBuffer;

//Here the definition of functions for graphics is written

void CanvasDraw(int x,int y,COLORREF color){
    int pos;
    pos=y*window.width+x;
    if(!(x<0 || y<0 || x>=(window.width-1) || y>=(window.height-1))){
        WinBuffer[pos]=color;
    }
}


void Circle_Create(circle Circle){
    int i,j;
    float dist;
    i=Circle.center.x-Circle.radius;

    do{
        j=Circle.center.y-Circle.radius;
        do{
            dist= sqrt(pow((Circle.center.x-i),2)+pow((Circle.center.y-j),2));
            
            //if(fabs(dist-radius)<0.5){
            if(dist<Circle.radius){
                CanvasDraw(i,j,Circle.color);
            }    
            j+=1;
        }while(j<=(Circle.center.y+Circle.radius));
        i+=1;
    }while(i<=(Circle.center.x+Circle.radius));
     
}
