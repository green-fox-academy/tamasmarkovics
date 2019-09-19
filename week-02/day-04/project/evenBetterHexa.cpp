#include <math.h>
#include "draw.h"

void betterHexa(SDL_Renderer* gRenderer, int startX, int startY, int size){
    int n = size;
    SDL_RenderDrawLine(gRenderer, startX, startY, startX + n, startY);
    SDL_RenderDrawLine(gRenderer, startX + n, startY, startX + n * 90 / 60, startY + n * 50 / 60);
    SDL_RenderDrawLine(gRenderer, startX + n * 90 / 60, startY + n * 50 / 60, startX + n, startY+ n * 100 / 60);
    SDL_RenderDrawLine(gRenderer, startX + n, startY + 100 * n / 60, startX, startY + 100 * n / 60);
    SDL_RenderDrawLine(gRenderer,  startX, startY + 100 * n / 60, startX - 30 * n / 60, startY + 50 * n / 60);
    SDL_RenderDrawLine(gRenderer, startX - 30 * n / 60, startY + 50 * n / 60, startX, startY);
}

void draw(SDL_Renderer* gRenderer){

    int rad = 20;
    int hei = 100.0 / 60 * rad;
    int noOfHexas = 10;
    SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
    int min = 1 - noOfHexas;
    int max = noOfHexas;
    for (int i = 0; i < 2 * noOfHexas - 1; i ++){
        if (i >= noOfHexas){
            min++;
            max--;
        }
        for (int j = min; j < max; j ++){
            betterHexa(gRenderer,
                    SCREEN_WIDTH / 2 - 50 - j * 1.5 * rad   ,
                    50 + abs(j) * hei / 2 + i * hei, rad);
        }
    }
}

