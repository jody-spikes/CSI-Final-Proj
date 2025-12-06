//
//  Car.h
//  SDL_Prac_1
//
//  Created by Jody Spikes on 11/13/25.
//

#ifndef Car_h
#define Car_h
#include "Const.h"
#include "SDL_Plotter.h"

class Car{
private:
    point _loc, _prvLoc;
    color _color;
    int   _size;
    
public:
    Car() : _loc{point(ROW / 2, COL - SIZE - 50)},
            _prvLoc{ROW / 2, COL - SIZE - 50},
            _color{color{255, 30, 30}},
            _size{SIZE} {}
    
    void move(char direction);
    void draw(SDL_Plotter& g);
    
    // Getters for collision detection
    point getLocation() const { return _loc; }
    int getSize() const { return _size; }
};
    
#endif /* Car_h */
