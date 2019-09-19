#include "draw.h"

//EVERYTHING IS ADJUSTABLE

void draw(SDL_Renderer* gRenderer) {
    SDL_SetRenderDrawColor(gRenderer, 0xFF /*R*/, 0 /*G*/, 0 /*B*/, 0xFF /*A*/);
    double offset_y = 0;
    double offset_x = 0;
    double noOfLines = 20;
    int x = 0;
    int y = 0;
    int noOfSquares = 8; // On each side //

    for (int stepDown = 0; stepDown < noOfSquares; ++stepDown) {
        y = SCREEN_HEIGHT / noOfSquares;

        for (int stepRight = 0; stepRight < noOfSquares; ++stepRight) {
            x = SCREEN_WIDTH / noOfSquares;

            for (int i = 0; i <= noOfLines; i += 1) {
            offset_y = (y / noOfLines) * i;
            offset_x = (x / noOfLines) * i;

            SDL_RenderDrawLine(gRenderer, x * stepRight + offset_x, y * stepDown, x + x * stepRight, y * stepDown + offset_y);
            SDL_RenderDrawLine(gRenderer, x * stepRight, y * stepDown + offset_y, x * stepRight +  offset_x, y * (stepDown + 1));
            }
        }
    }
}


