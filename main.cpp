//============================================================================
// Name        : SDL.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Pixel Racers - Top-down racing game
//============================================================================

#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "SDL_Plotter.h"
#include "Car.h"
#include "AICar.h"
#include "Const.h"
#include "Background.h"
using namespace std;

int main(int argc, char ** argv)
{
    // Initialize random seed ONCE at program start
    srand(static_cast<unsigned>(time(0)));
    
    SDL_Plotter g(ROW, COL);
    
    Car playerCar;
    Background bg;
    
    // Create AI opponents with different colors and speeds
    vector<AICar> aiCars;
    aiCars.push_back(AICar(ROW/2 - 100, -50, color(0, 100, 255), 4));    // Blue car, speed 4
    aiCars.push_back(AICar(ROW/2 + 100, -150, color(0, 255, 0), 3));     // Green car, speed 3
    aiCars.push_back(AICar(ROW/2, -250, color(255, 255, 0), 5));         // Yellow car, speed 5
    
    int frameCount = 0;

    while (!g.getQuit()) {
        // Handle keyboard input
        if(g.kbhit()) {
            char c = toupper(g.getKey());
            
            switch(c) {
                case 'C': g.clear(); break;
                case RIGHT_ARROW: playerCar.move(RIGHT_ARROW); break;
                case LEFT_ARROW: playerCar.move(LEFT_ARROW); break;
            }
        }

        if(g.mouseClick()) {
            g.getMouseClick(); // Clear the click queue
        }
        
        // Update background animation
        bg.update();
        
        // Update AI cars
        for(auto& aiCar : aiCars) {
            aiCar.updateAI(bg.offset);
            
            // Respawn AI cars when they go off screen
            if(aiCar.isOffScreen()) {
                aiCar.respawn();
            }
        }
        
        // DRAW EVERYTHING (redrawing eliminates need for erase functions)
        bg.draw(g);           // Draw background first
        
        // Draw all AI cars
        for(auto& aiCar : aiCars) {
            aiCar.draw(g);
        }
        
        playerCar.draw(g);    // Draw player on top
        
        g.Sleep(30);          // ~30 FPS
        g.update();
        
        frameCount++;
    }
    
    return 0;
}
