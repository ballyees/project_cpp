#include <SFML/Graphics.hpp>
//#include <iostream>
#include <sstream>
#include <cmath>
//#include <string>
//#include <cstdlib>
#include "use_sql.cpp"
using namespace sf;
using namespace std;

constexpr double pi() {
    /*vector<bill> chart = getdataChart(10,"");
    bill inx;
    inx.detailP.name, inx.detailP.id, inx.amount, inx.detailP.price;*/
    return atan(1)*4; }

int main()
{
    vector<bill> chart = getdataChart(10,"");
    for(int i=0 ; i<chart.size(); i++){
        cout << chart[i].detailP.name << endl;
        cout << chart[i].detailP.id << endl;
        cout << chart[i].amount << endl;
        cout << chart[i].detailP.price << endl;
        //cout << inx.detailP.name, inx.detailP.id, inx.amount, inx.detailP.price;;
    }/*
    const unsigned int s = 800;
    const unsigned int N = 450;

    RenderWindow window(VideoMode(s, N),"Graph");
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);
    string graphname; //define Graph's name
    cout<<"Enter Graph's name : ";
    getline(cin,graphname);

    string axisX,axisY; //define Axis's name
    cout<<"Enter Name of X axis : ";
    getline(cin,axisX);
    cout<<"Enter Name of Y axis : ";
    getline(cin,axisY);

    int data=chart.size(); //define data number

    float Y[chart.size()+1]={};
    Y[0] = 0;
    for (int i=1;i<chart.size();i++){
        Y
    }
    float Ymax = chart[0].detailP.price;
    for(int i=1;i<chart.size()+1;i++){
        if(chart[i].detailP.price>Ymax) Ymax = chart[i].detailP.price;
    }

    VertexArray graph(LinesStrip,5);
    graph[0].position = Vector2f(100,100);
    graph[0].color = Color::Black;
    graph[1].position = Vector2f(100,350);
    graph[1].color = Color::Black;
    graph[2].position = Vector2f(700,350);
    graph[2].color = Color::Black;
    graph[3].position = Vector2f(700,100);
    graph[3].color = Color::Black;
    graph[4].position = Vector2f(100,100);
    graph[4].color = Color::Black;

    Font font;
    if (!font.loadFromFile("arial.ttf"))
    {
    // error...
    }
    Text text;
    text.setFont(font);
    text.setString(graphname);
    text.setCharacterSize(40);
    text.setFillColor(sf::Color::Black);
    text.setStyle(Text::Bold);
    text.setPosition(100, 20);

    Text texty[chart.size()+1];
    for(int i=0;i<chart.size()+1;i++){
        texty[i].setFont(font);
        texty[i].setCharacterSize(10);
        texty[i].setFillColor(sf::Color::Black);
    }
    Text textx[chart.size()+1];
    for(int i=0;i<chart.size()+1;i++){
        textx[i].setFont(font);
        textx[i].setCharacterSize(10);
        textx[i].setFillColor(sf::Color::Black);
    }

    Text textaxisY;
    textaxisY.setFont(font);
    textaxisY.setString("[Y]:"+axisY);
    textaxisY.setCharacterSize(10);
    textaxisY.setFillColor(sf::Color::Black);
    textaxisY.setStyle(Text::Bold);
    textaxisY.setPosition(80-(axisY.size())*10, 80);

    Text textaxisX;
    textaxisX.setFont(font);
    textaxisX.setString("[X]:"+axisX);
    textaxisX.setCharacterSize(10);
    textaxisX.setFillColor(sf::Color::Black);
    textaxisX.setStyle(Text::Bold);
    textaxisX.setPosition(720, 360);

    VertexArray chart(LinesStrip,chart.size()+1);
    for (int i=0;i<data+1;i++){
        unsigned int x = (i*(600/chart.size()))+100;
        unsigned int y = 350-(250/Ymax)*Y[i];
        chart[i].position = Vector2f(x,y);
        chart[i].color = Color::Red;
        textx[i].setString(to_string(i));
        textx[i].setPosition(x,360);
        int r=0;
        for(int j=0;j<i;j++){
            if(Y[i] == Y[j]) r++;;
        }
        if(r!=0) texty[i].setPosition(1000,1000);
        else texty[i].setPosition(80,y);
        texty[i].setString(to_string((int)Y[i]));

    }


    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
            if (event.type == Event::Closed) window.close();
        window.clear(Color::White);
        window.draw(graph);
        window.draw(chart);
        window.draw(text);
        window.draw(textaxisX);
        window.draw(textaxisY);
        for(int i=0; i<chart.size()+1; i++){
            window.draw(texty[i]);
            if (i>0) window.draw(textx[i]);
        }
        window.display();
    }*/
    return 0;
}

