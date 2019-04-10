#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include<cmath>
#include<string>
using namespace std;
using namespace sf;

int main(){
    RenderWindow window(VideoMode(800,600),"CAFE");
    Text text;
    Font font;
    Texture bp;
    bp.loadFromFile("blackpink-o-lens-cover.jpg");
    Sprite spt;
    spt.setTexture(bp);
    if(!font.loadFromFile("ARIALI.ttf")){}
    text.setFont(font);
    text.setString("Input : ");
    text.setPosition(10.f, 50.f);
    text.setCharacterSize(100);
    text.setFillColor(Color::Red);
    int x;
    string y;
    cin >> y;
    x=stoi(y);
    x=x*x;
    string s = to_string(x);
    Text text1;
    text1.setFont(font);
    text1.setString(s);
    text1.setPosition(300.f, 50.f);
    text1.setCharacterSize(100);
    text1.setFillColor(Color::Blue);

        while(window.isOpen()){
            Event evnt;
            while(window.pollEvent(evnt)){
                if (evnt.type == sf::Event::Closed)
                window.close();
            }
        window.clear();
        window.draw(spt);
        window.draw(text);
        window.draw(text1);
        window.display();
        }

    return 0;
}
