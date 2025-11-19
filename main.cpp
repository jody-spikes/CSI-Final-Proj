//============================================================================
// Name        : SDL.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
#include "SDL_Plotter.h"
#include "Car.h"
#include "Const.h"
#include "Background.h"
using namespace std;
int main(int argc, char ** argv)
{
    SDL_Plotter g(ROW,COL);
    point p;
    color c;
    int size;
    Uint32 RGB;

    Car car;
    Background bg;

    bg.draw(g);
    car.draw(g);

    while (!g.getQuit()) {
        if(g.kbhit()){
            char c = toupper(g.getKey());
                    cout << int(c) << endl;
            switch(c){
                case 'C': g.clear(); break;
                case RIGHT_ARROW: car.move(RIGHT_ARROW); break;
                case LEFT_ARROW: car.move(LEFT_ARROW); break;
            }
            car.draw(g);
        }

        if(g.mouseClick()){}
        
        bg.update();
        bg.draw(g);
        car.draw(g);
        
        g.Sleep(30);
        g.update();
    }
}



