#include "draw.h"

void drawTriangle(SDL_Renderer* renderer, int startX, int startY, int sideLength, float height){
    SDL_RenderDrawLine(renderer, startX, startY, startX + sideLength, startY);
    SDL_RenderDrawLine(renderer, startX, startY, startX + sideLength / 2, startY - height);
    SDL_RenderDrawLine(renderer, startX + sideLength / 2, startY - height, startX + sideLength, startY);
}

void draw(SDL_Renderer* gRenderer) {
    SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);

    int size = 20;
    float height = size * 0.886;
    int max = SCREEN_HEIGHT;

    for (int j = 40; j > 0; --j) {
        for (int i = 0; i < j; ++i) {

            int startX =  (40 - j) * (size / 2) + (i * size);
            int startY = max - ((40 - j) * height);

            drawTriangle(gRenderer, startX, startY, size, height);
        }
    }
}



