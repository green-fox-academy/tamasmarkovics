#include "draw.h"
#include <stdlib.h>
#include <time.h>

void drawLine(SDL_Renderer* gRenderer, int startX, int startY){
    SDL_RenderDrawLine(gRenderer, startX, startY, SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
}

void draw(SDL_Renderer* gRenderer) {
    // Create a function that draws a single line and takes 2 parameters:
    // The x and y coordinates of the line's starting point
    // and draws a line from that point to the center of the canvas.
    // Draw at least 3 lines with that function using a loop.
    srand (time(NULL));

    for (int i = 0; i < 1000; i++){
        SDL_SetRenderDrawColor(gRenderer, rand() % 255 /*R*/, rand() % 255 /*G*/, rand() % 255 /*B*/, 0xFF /*A*/);
        drawLine(gRenderer, rand() % SCREEN_WIDTH, rand() % SCREEN_HEIGHT);
    }
}

