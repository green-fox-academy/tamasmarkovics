#include "draw.h"

void draw(SDL_Renderer* gRenderer) {
    SDL_SetRenderDrawColor(gRenderer, 255 /*R*/, 0 /*G*/, 0 /*B*/, 0xFF /*A*/);
    SDL_RenderDrawLine(gRenderer, 0,   0, SCREEN_WIDTH,  SCREEN_HEIGHT);
    SDL_SetRenderDrawColor(gRenderer, 0 /*R*/, 255 /*G*/, 0 /*B*/, 0xFF /*A*/);
    SDL_RenderDrawLine(gRenderer, 0, SCREEN_HEIGHT , SCREEN_WIDTH, 0);
}
