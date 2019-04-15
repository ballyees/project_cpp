#include <conio.h>
#include <graphics.h>
#include <iostream>
#include <cmath>

int main()
{
    int gd = DETECT , gm , midx , midy;

    initgraph(&gd , &gm , "C:\\TC\\BGI");

    setcolor(MAGENTA);
    rectangle(0,40,639,450);
    settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
    setcolor(WHITE);
    outtextxy(270,10,"PIE CHART");

    midx = getmaxx()/2;
    midy = getmaxy()/2;

    setfillstyle(4,BLUE);
    pieslice(midx , midy ,0 , 75 , 100);
    outtextxy(midx+100,midy-75,"20.83%");

    setfillstyle(5,RED);
    pieslice(midx , midy ,75 , 255 , 100);
    outtextxy(midx-175,midy-75,"41.67%");

    setfillstyle(6,GREEN);
    pieslice(midx , midy ,255 , 360 , 100);
    outtextxy(midx+75,midy+75,"37.50%");

    getch();
    return 0;
}
