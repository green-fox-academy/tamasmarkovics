#include "draw.h"
#include <math.h>

//LESS OUTDATED, STILL GARBAGE


void betterHexa(SDL_Renderer* gRenderer, int startX, int startY)
{
    SDL_RenderDrawLine(gRenderer, startX, startY, startX + 60, startY);
    SDL_RenderDrawLine(gRenderer, startX + 60, startY, startX + 90, startY + 50);
    SDL_RenderDrawLine(gRenderer, startX + 90, startY + 50, startX + 60, startY + 100);
    SDL_RenderDrawLine(gRenderer, startX + 60, startY + 100, startX, startY + 100);
    SDL_RenderDrawLine(gRenderer,  startX, startY + 100, startX - 30, startY + 50);
    SDL_RenderDrawLine(gRenderer, startX - 30, startY + 50, startX, startY);
}

void draw(SDL_Renderer* gRenderer){

    int hei = 100;
    int rad = 60;

    SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
    int min = - 3;
    int max = 4;
    for (int i = 0; i < 7; i ++){
        if (i > 3){
            min++;
            max--;
        }
        for (int j = min; j < max; j ++){
                betterHexa(gRenderer, SCREEN_WIDTH / 2 - 50 - j * 1.5 * rad   , 50 + abs(j) * hei / 2 + i * hei);
        }
    }
}