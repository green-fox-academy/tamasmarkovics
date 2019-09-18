// draw four different size and color rectangles.
// avoid code duplication.
#include <stdlib.h>
#include <time.h>
#include "draw.h"


void draw(SDL_Renderer* gRenderer) {
    srand (time(NULL));
    int x = 0;
    int y = 0;
    int a = 10;
    for(int i = 0; i < 10000; i++) {
        SDL_SetRenderDrawColor(gRenderer, 255, 59, 255, 255);
        SDL_Rect fillRect = {x, y, a, a};
        SDL_RenderFillRect(gRenderer, &fillRect);
        SDL_SetRenderDrawColor(gRenderer, 102, 55, 102, 255);
        SDL_RenderDrawRect(gRenderer, &fillRect);
        x = fillRect.x + fillRect.w;
        y = fillRect.y + fillRect.w;
        a *= 1.2;
        if (x + a < SCREEN_WIDTH && y + a < SCREEN_HEIGHT){
            continue;
        } else {break;}

    }
}
