#include "draw.h"
#include <stdlib.h>
#include <time.h>


void draw(SDL_Renderer* gRenderer) {
    // Create a function that draws a single line and takes 2 parameters:
    // The x and y coordinates of the line's starting point
    // and draws a line from that point to the center of the canvas.
    // Draw at least 3 lines with that function using a loop.


    srand (time(NULL));

    for (int i = 0; i < 3; i++){
        SDL_SetRenderDrawColor(gRenderer, 250 /*R*/, 100 /*G*/, 50 /*B*/, 0xFF /*A*/);
        SDL_RenderDrawLine(gRenderer, rand()%SCREEN_WIDTH, rand()%SCREEN_HEIGHT, SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
    }
    for (int i = 0; i < 10000; i++){
        SDL_SetRenderDrawColor(gRenderer, rand()%255 /*R*/, rand()%255 /*G*/, rand()%255 /*B*/, 0xFF /*A*/);
       SDL_RenderDrawLine(gRenderer, rand()%SCREEN_WIDTH, rand()%SCREEN_HEIGHT, rand()%SCREEN_WIDTH,  rand()%SCREEN_HEIGHT);
    }

    SDL_SetRenderDrawColor(gRenderer, rand(), rand(), rand(), 0xFF);
    SDL_Rect fillRect = { SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2 - 100, 200, 200};
    SDL_RenderFillRect( gRenderer, &fillRect );


}

