// draw four different size and color rectangles.
// avoid code duplication.
#include <stdlib.h>
#include <time.h>
#include "draw.h"


void draw(SDL_Renderer* gRenderer) {
    srand (time(NULL));
        for(int i = 0; i < 10000; i++) {
            //choose color
            SDL_SetRenderDrawColor(gRenderer, rand() % 255, rand() % 255, rand() % 255, 255);
            //create a rectangle
            SDL_Rect fillRect = {rand() % SCREEN_WIDTH, rand() % SCREEN_HEIGHT, rand() % (SCREEN_WIDTH - fillRect.x),
                                 rand() % (SCREEN_HEIGHT - fillRect.y)};
            //draw rectangle

            SDL_RenderFillRect(gRenderer, &fillRect);
        }
}
