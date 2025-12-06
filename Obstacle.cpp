//
//  Obstacle.cpp
//  SDL_Prac_1
//
//  Obstacles implementation
//

#include "Obstacle.h"
#include "Utils.h"
#include <cstdlib>

Obstacle::Obstacle(int x, int y, color c, int size, int speed)
    : _loc{point(x, y)},
      _color{c},
      _size{size},
      _speed{speed},
      _active{true}
{}

void Obstacle::update() {
    if (!_active) return;
    
    // Move obstacle down the screen
    _loc.y += _speed;
}

void Obstacle::draw(SDL_Plotter& g) {
    if (!_active) return;
    
    // Draw a triangle obstacle (cone/barrier)
    color orange(255, 140, 0);
    color white(255, 255, 255);
    
    // Draw triangle shape
    for(int y = 0; y < _size; y++) {
        int width = (y * _size) / _size;
        for(int x = -width/2; x <= width/2; x++) {
            int drawX = _loc.x + x;
            int drawY = _loc.y - _size/2 + y;
            
            if(drawX >= 0 && drawX < ROW && drawY >= 0 && drawY < COL) {
                // Alternating stripes for traffic cone look
                if(y / 5 % 2 == 0) {
                    g.plotPixel(drawX, drawY, orange);
                } else {
                    g.plotPixel(drawX, drawY, white);
                }
            }
        }
    }
}

bool Obstacle::collidesWith(const Car& car) const {
    if (!_active) return false;
    
    point carLoc = car.getLoc();
    int carSize = car.getSize();
    
    // FIXED: Corrected coordinate system (x is horizontal, y is vertical)
    // Car boundaries
    int carLeft = carLoc.x - carSize/2;
    int carRight = carLoc.x + carSize/2;
    int carTop = carLoc.y - carSize/2;
    int carBottom = carLoc.y + carSize/2;
    
    // Obstacle boundaries
    int obsLeft = _loc.x - _size/2;
    int obsRight = _loc.x + _size/2;
    int obsTop = _loc.y - _size/2;
    int obsBottom = _loc.y + _size/2;
    
    // AABB (Axis-Aligned Bounding Box) collision detection
    return (carRight > obsLeft &&
            carLeft < obsRight &&
            carBottom > obsTop &&
            carTop < obsBottom);
}

bool Obstacle::isOffScreen() const {
    return _loc.y > COL + _size;
}

void Obstacle::respawn() {
    // Respawn at top of screen in a random lane
    int rdStrt = ROW / 4;
    int rdEnd = ROW * 3 / 4;
    int roadWidth = rdEnd - rdStrt;
    
    // Pick random x position within road
    _loc.x = rdStrt + 50 + (rand() % (roadWidth - 100));
    _loc.y = -_size - (rand() % 300);  // Random spacing
    _active = true;
}
