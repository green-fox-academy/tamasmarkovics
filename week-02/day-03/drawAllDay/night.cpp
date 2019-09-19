#include "draw.h"
#include <stdlib.h>
#include <time.h>

void draw(SDL_Renderer* gRenderer) {
    srand (time(NULL));
    for (int i = 0; i < 100; i++) {
        SDL_SetRenderDrawColor(gRenderer, rand() % 255, rand() % 255, rand() % 255, 255);
        SDL_Rect fillRect = {rand() % SCREEN_WIDTH, rand() % SCREEN_HEIGHT, 5,
                             5};
        SDL_RenderFillRect(gRenderer, &fillRect);
    }

}