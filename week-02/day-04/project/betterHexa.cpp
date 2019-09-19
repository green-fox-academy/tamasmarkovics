#include "draw.h"
#include <math.h>

void betterHexa(SDL_Renderer* gRenderer, int startX, int startY){
    int side = 20;
    double sideDia = 7.32;
    SDL_RenderDrawLine(gRenderer, startX, startY, startX + 60, startY);
    SDL_RenderDrawLine(gRenderer, startX + 60, startY, startX + 90, startY + 50);
    SDL_RenderDrawLine(gRenderer, startX + 90, startY + 50, startX + 60, startY+100);
    SDL_RenderDrawLine(gRenderer, startX + 60, startY+100, startX, startY + 100);
    SDL_RenderDrawLine(gRenderer,  startX, startY + 100, startX - 30, startY + 50);
    SDL_RenderDrawLine(gRenderer, startX - 30, startY + 50, startX, startY);


}

void draw(SDL_Renderer* gRenderer){

    SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
    int hei = 100;
    int rad = 60;
    for (int j = 0; j < 4; j ++){

        for (int i = 0; i < 4; i ++){
            betterHexa(gRenderer, 800 + j * 2 *0.75* rad   , 50 + j * hei/2 + i * hei);
        }
    }

    SDL_SetRenderDrawColor(gRenderer, 0, 255, 0, 255);
    for (int j = 0; j < 4; j ++){

        for (int i = 0; i < 4; i ++){
            betterHexa(gRenderer, 800 - j * 2 *0.75* rad   , 50 + j * hei/2 + i * hei);
        }
    }

    SDL_SetRenderDrawColor(gRenderer,  255, 0,0, 255);
    for (int j = 0; j < 3; j ++){

        for (int i = 0; i < 3 - j; i ++){
            betterHexa(gRenderer, 800 - j * 2 *0.75* rad   , 50+ 4*hei + j * hei/2 + i * hei);
        }
    }

    SDL_SetRenderDrawColor(gRenderer,  0, 0,255, 255);
    for (int j = 0; j < 3; j ++){

        for (int i = 0; i < 3 - j; i ++){
            betterHexa(gRenderer, 800 + j * 2 *0.75* rad   , 50+ 4*hei + j * hei/2 + i * hei);
        }
    }
}