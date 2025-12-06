//
//  Car.cpp
//  SDL_Prac_1
//
//  Created by Jody Spikes on 11/18/25.
//

#include "Car.h"
#include "Utils.h"

//Move
void Car::move(char direction){
    _prvLoc.x = _loc.x;
    _prvLoc.y = _loc.y;
    
    switch(direction){
        //Right Move, with road constraint
        case RIGHT_ARROW:
            if(_loc.x < (ROW * 3 / 4) - _size/2 - 10) {
                _loc.x += SPEED;
            }
            break;
            
        //Left Move, with road constraint
        case LEFT_ARROW:
            if(_loc.x > (ROW / 4) + _size/2 + 10) {
                _loc.x -= SPEED;
            }
            break;
    }
}

void Car::draw(SDL_Plotter& g){
    int whlSize = _size / 5 + 2;
    color black(0, 0, 0);
    
    // Car base
    drawRect(_loc.x - _size/2, _loc.y - _size/2, _size, _size, _color, g);
    
    // Wheels
    drawRect(_loc.x - _size/2, _loc.y - _size/2, whlSize, whlSize, black, g);
    drawRect(_loc.x + _size/2 - whlSize, _loc.y - _size/2, whlSize, whlSize, black, g);
    drawRect(_loc.x - _size/2, _loc.y + _size/2 - whlSize, whlSize, whlSize, black, g);
    drawRect(_loc.x + _size/2 - whlSize, _loc.y + _size/2 - whlSize, whlSize, whlSize, black, g);
}
