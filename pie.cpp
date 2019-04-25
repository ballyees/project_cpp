#include <conio.h>
#include <graphics.h>
#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

void pieChartBGI(short int cmd, const char *date)
{
    int gd = DETECT , gm , midx , midy;


    initgraph(&gd , &gm , "C:\\TC\\BGI");
    setcolor(MAGENTA);
    rectangle(0,40,900,620);
    //rectangle(0,40,639,450);
    settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
    setcolor(WHITE);
    outtextxy(getmaxx()/1.425,10,"PIE CHART");

    midx = getmaxx()/1.28;
    midy = getmaxy()/2;

    float sum =0;
    vector<bill> test = getdataChart(cmd, date);
    for(int i=0; i<test.size(); i++){
        //cout << test[i].detailP.name << ":" << test[i].detailP.price << endl;
        sum+=test[i].detailP.price;
    }
    float pend=0,pstart=0;
    //string temp;
    for (int i=0; i<test.size(); i++){
        test[i].date = test[i].detailP.name+"( "+get2decimal((test[i].detailP.price/sum)*100)+"% )";
        //temp = test[i].detailP
        pend += (test[i].detailP.price/sum)*360;
        setfillstyle(3,(i/2,i*2,i+2));
        pieslice(midx , midy , pstart , pend , 150);
        pieslice(25,80 + (i*25), 0 , 360 , 10);
        settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
        //outtextxy(40, 138 + (i*25),&test[i].detailP.name[0]);
        outtextxy(40, 65 + (i*25),&test[i].date[0]);
        pstart=pend;
    }

    getch();
    //return 0;
}
