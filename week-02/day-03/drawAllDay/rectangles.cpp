// draw four different size and color rectangles.
// avoid code duplication.
#include <stdlib.h>
#include <time.h>
#include "draw.h"


//4 IS NOT ENOUGH :(

void draw(SDL_Renderer* gRenderer) {
    srand (time(NULL));

    for(int i = 0; i < 1000; i++) {
        SDL_SetRenderDrawColor(gRenderer, rand() % 255, rand() % 255, rand() % 255, 255);
        SDL_Rect fillRect = {rand() % SCREEN_WIDTH, rand() % SCREEN_HEIGHT, rand() % (SCREEN_WIDTH - fillRect.x) / 2,
                             rand() % (SCREEN_HEIGHT - fillRect.y) / 2};
        SDL_RenderFillRect(gRenderer, &fillRect);
    }
}
