#include "draw.h"

void draw(SDL_Renderer* gRenderer) {
    // draw a red horizontal line to the canvas' middle.
    // draw a green vertical line to the canvas' middle.

    SDL_SetRenderDrawColor(gRenderer, 0xFF /*R*/, 0 /*G*/, 0 /*B*/, 0xFF /*A*/);
    SDL_RenderDrawLine(gRenderer, 0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT /2);
    SDL_SetRenderDrawColor(gRenderer, 0 /*R*/, 255 /*G*/, 0 /*B*/, 0xFF /*A*/);
    SDL_RenderDrawLine(gRenderer, SCREEN_WIDTH /2, SCREEN_HEIGHT, SCREEN_WIDTH / 2, 0);


}