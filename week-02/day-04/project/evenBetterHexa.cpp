#include <math.h>
#include "draw.h"

void betterHexa(SDL_Renderer* gRenderer, int startX, int startY, int size)
{
    int n = size;
    SDL_RenderDrawLine(gRenderer, startX, startY, startX + n, startY);
    SDL_RenderDrawLine(gRenderer, startX + n, startY, startX + n * 3 / 2, startY + n * 5 / 6);
    SDL_RenderDrawLine(gRenderer, startX + n * 3 / 2, startY + n * 5 / 6, startX + n, startY + n * 5 / 3);
    SDL_RenderDrawLine(gRenderer, startX + n, startY + n * 5 / 3, startX, startY +  n * 5 / 3);
    SDL_RenderDrawLine(gRenderer,  startX, startY +  n * 5 / 3, startX -  n / 2, startY +  n * 5 / 6);
    SDL_RenderDrawLine(gRenderer, startX -  n / 2, startY + n * 5 / 6, startX, startY);
}


void draw(SDL_Renderer* gRenderer)
{
    SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);

    int sideLength = 50;                                                    //BASIC SETUP
    int noOfHexas = 4;

    int height = 5.0 / 3 * sideLength;                                     //DO MATH FOR THE FUNCTION, AND CALCULATE WHERE TO START
    int verticalSum = 2 * noOfHexas - 1;
    int startMidX = (SCREEN_WIDTH - sideLength) / 2;
    int startMidY = (SCREEN_HEIGHT - height * (2 * noOfHexas - 1)) / 2;

    int min = 1 - noOfHexas;                                               //START AND END OF THE INNER CYCLE
    int max = noOfHexas;

    for (int i = 0; i < verticalSum; i ++){
        if (i >= noOfHexas){
            min++;
            max--;
        }
        for (int j = min; j < max; j ++){
            betterHexa(gRenderer,
                    startMidX - j * 1.5 * sideLength,
                    startMidY+ abs(j) * height / 2 + i * height,
                    sideLength);
        }
    }
}

