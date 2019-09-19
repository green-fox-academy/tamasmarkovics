#include "draw.h"
#include <stdlib.h>
#include <time.h>

void draw(SDL_Renderer* gRenderer) {
    srand (time(NULL));
    
    for (int i = 0; i < 100; i++) {
        int color = rand() % 200;
        SDL_SetRenderDrawColor(gRenderer, color, color, color, color);
        SDL_Rect fillRect = {rand() % SCREEN_WIDTH, rand() % SCREEN_HEIGHT, 2,
                             2};
        SDL_RenderFillRect(gRenderer, &fillRect);
    }

}