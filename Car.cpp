//
//  Car.cpp
//  SDL_Prac_1
//
//  Created by Jody Spikes on 11/18/25.
//

#include <stdio.h>
#include "Car.h"
void drawRect(int x, int y, int width, int height, color c, SDL_Plotter& g){
    for(int row = y; row < y + height; row++){
        for(int col = x; col < x + width; col++){
            g.plotPixel(row, col, c);
        }
    }
}

//Move
void Car::move(char direction){
    _prvLoc.x = _loc.x;
    _prvLoc.y = _loc.y;
    
    switch(direction){
        //Right Move, with road constraint
        case RIGHT_ARROW: if(_loc.x < (ROW * 3 /4) - 10) {_loc.x+=SPEED;} break;
            
        //Left Move, with road constraint
        case LEFT_ARROW: if(_loc.x > (ROW / 4) + 10) {_loc.x-=SPEED;}break;
    }
}

void Car::draw(SDL_Plotter& g){
    //
    int whlSize = _size/5 + 2;
    color black(0,0,0);
    
    erase(g);
    //car base
    drawRect( _loc.y - _size/2,_loc.x - _size/2, _size, _size, _color, g);
    
    //wheels
    drawRect( _loc.y - _size/2,_loc.x - _size/2, whlSize, whlSize, black, g);
    drawRect( _loc.y + _size/2 - 5, _loc.x - _size/2, whlSize, whlSize, black, g);
    drawRect( _loc.y - _size/2,_loc.x + _size/2 - whlSize + 1,whlSize,whlSize,black,g);
    drawRect( _loc.y + _size/2 - whlSize + 1,_loc.x + _size/2 - whlSize + 1,whlSize,whlSize,black,g);
    
}


void Car::erase(SDL_Plotter& g){
    color _grass(34,139, 34);
    color _road(60,60,60);
    
    int rdStrt = ROW / 4;
    int rdEnd  = ROW * 3 /4;
    
    for (int y = _prvLoc.y - _size / 2; y <= _prvLoc.y + _size / 2; y++){
        for(int x = _prvLoc.x - _size / 2; x <= _prvLoc.x + _size / 2; x++) {
            if(x >= rdStrt && x < rdEnd){
                g.plotPixel(x,y,_road);
            }
            else{
                g.plotPixel(x,y,_grass);
            }
        }
    }
}


