#include "draw.h"

void drawTriangle(SDL_Renderer* renderer, int startX, int startY, int sideLength, float height)
{

    // Base line:
    SDL_RenderDrawLine(renderer, startX, startY, startX + sideLength, startY);
    // Second line from start:
    SDL_RenderDrawLine(renderer, startX, startY, startX + sideLength / 2, startY - height);
    // Third line:
    SDL_RenderDrawLine(renderer, startX + sideLength / 2, startY - height, startX + sideLength, startY);

}

void draw(SDL_Renderer* gRenderer) {

    SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);

    int size = 30;
    float height = size * 0.886;

    int max = SCREEN_HEIGHT;

    for (int j = 21; j > 0; --j) {
        for (int i = 0; i < j; ++i) {

            int Xstart =  (21 - j) * (size / 2) + (i * size);
            int Ystart = max - ((21 - j) * height);

            drawTriangle(gRenderer, Xstart, Ystart, size, height);
        }
    }
}



