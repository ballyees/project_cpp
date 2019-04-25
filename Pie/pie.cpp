#include <conio.h>
#include <graphics.h>
#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <cstdlib>
#include "sqlForPie.cpp"
using namespace std;

int main()
{
    int gd = DETECT , gm , midx , midy;


    initgraph(&gd , &gm , "C:\\TC\\BGI");
    //setcolor(MAGENTA);
    //rectangle(0,40,639,450);
    settextstyle(SANS_SERIF_FONT,HORIZ_DIR,4);
    setcolor(WHITE);
    outtextxy(225,25,"PIE CHART");

    midx = getmaxx()/2;
    midy = getmaxy()/2+20;

    float sum =0;
    vector<bill> test = getdataChart(10,"2019");
    for(int i=0; i<test.size(); i++){
        sum+=test[i].detailP.price;
    }
    float pend=0,pstart=0;
    settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
    for (int i=0; i<test.size(); i++){
        pend += (test[i].detailP.price/sum)*360;
        setfillstyle(3,(i/2,i*2,i+2));
        pieslice(midx , midy , pstart , pend , 150);
        /*settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
        outtextxy(midx*cos((pend-pstart)/2), midy *sin((pend-pstart)/2),&test[0].detailP.name[0]);
        if((pend-pstart)/2 >= 0 && (pend-pstart)/2 <90){
            outtextxy(midx*cos((pend-pstart)/2), midy *sin((pend-pstart)/2),&test[i].detailP.name[0]);
        }else if ((pend-pstart)/2 >= 90 && (pend-pstart)/2 <180){
            outtextxy(midx*cos((pend-pstart)/2), midy *sin((pend-pstart)/2),&test[i].detailP.name[0]);
        }else if ((pend-pstart)/2 >= 180 && (pend-pstart)/2 <270){
            outtextxy(midx*cos((pend-pstart)/2), midy *sin((pend-pstart)/2),&test[i].detailP.name[0]);
        }else{
            outtextxy(midx*cos((pend-pstart)/2), midy *sin((pend-pstart)/2),&test[i].detailP.name[0]);
        }*/
        pstart=pend;
    }


    getch();
    return 0;
}
