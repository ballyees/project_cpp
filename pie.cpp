#include <conio.h>
#include <graphics.h>
#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

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

    ifstream input("simple.txt");
    string d;
    vector <float> data;
    vector <string> name_data;
    float sum = 0;
    int n = 0;
    while(getline(input,d)){
        char format[] = "%[^:] %f";
        char name[100];
        float cost;
        sscanf(d.c_str(),format,name,&cost);
        data.push_back(cost);
        name_data.push_back(name);
        sum += cost;
        n ++;
        cout<<cost<<endl;
    }
    cout<<data[0];
    //int n = 6; //input data number
    //float data[6]={55,34,21,3,2,4},sum=0;//input data
    float pend=0,pstart=0;
    for (int i=0; i<n; i++){
        pend += (data[i]/sum)*360;
        setfillstyle(3,(i,i+1,i+2));
        pieslice(midx , midy , pstart , pend , 100);
        pstart=pend;
    }

    getch();
    return 0;
}