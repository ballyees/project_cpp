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
    settextstyle(SANS_SERIF_FONT,HORIZ_DIR,4);
    setcolor(WHITE);
    outtextxy(225,25,"PIE CHART");

    midx = getmaxx()/2+80;
    midy = getmaxy()/2+20;

    float sum =0;
    vector<bill> test = getdataChart(10,"2019");
    for(int i=0; i<test.size(); i++){
        sum+=test[i].detailP.price;
    }
    float pend=0,pstart=0;
    for (int i=0; i<test.size(); i++){
        pend += (test[i].detailP.price/sum)*360;
        setfillstyle(3,(i/2,i*2,i+2));
        pieslice(midx , midy , pstart , pend , 150);
        pieslice(25,150 + (i*25), 0 , 360 , 10);
        settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
        outtextxy(40, 138 + (i*25),&test[i].detailP.name[0]);
        pstart=pend;
    }


    getch();
    return 0;
}
