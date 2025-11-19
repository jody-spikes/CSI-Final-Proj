//
//  Background.h
//  SDL_Prac_1
//
//  Created by Jody Spikes on 11/18/25.
//

#ifndef Background_h
#define Background_h
#include "SDL_Plotter.h"
#include "Const.h"
struct Background{
    int offset;
    
    Background();
    void update();
    void draw(SDL_Plotter&);
    
};


#endif /* Background_h */
