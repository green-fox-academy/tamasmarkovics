#include "draw.h"

void draw(SDL_Renderer* gRenderer) {
    int a = 7;
    int z = 1;
    for(int j = 0; j <= SCREEN_HEIGHT - a; j += a){
        int i = 0;
        if (j % (2 * a) == 0){i += a;}
        for(i; i <= SCREEN_WIDTH - a; i += 2*a) {
            SDL_SetRenderDrawColor(gRenderer, 255, 30, 255, 255);
            SDL_Rect fillRect = {i, j, a, a};
            SDL_RenderFillRect(gRenderer, &fillRect);
        }
    }
}

