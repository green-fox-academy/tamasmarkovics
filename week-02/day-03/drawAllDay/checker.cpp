#include "draw.h"

//NOT 8X8, FULLSCREEN, MORE FUN

void draw(SDL_Renderer* gRenderer) {
    int sideLength = 7;

    for(int j = 0; j <= SCREEN_HEIGHT - sideLength; j += sideLength){
        int i = 0;
        if (j % (2 * sideLength) == 0){i += sideLength;}
        for(i; i <= SCREEN_WIDTH - sideLength; i += 2 * sideLength) {
            SDL_SetRenderDrawColor(gRenderer, 255, 30, 255, 255);
            SDL_Rect fillRect = {i, j, sideLength, sideLength};
            SDL_RenderFillRect(gRenderer, &fillRect);
        }
    }
}

