#include "draw.h"


void draw(SDL_Renderer* gRenderer) {

    SDL_SetRenderDrawColor(gRenderer, 0xFF /*R*/, 0 /*G*/, 0 /*B*/, 0xFF /*A*/);
    for (int i = 0; i <= SCREEN_WIDTH; i += 20) {
        SDL_RenderDrawLine(gRenderer, i, 0, SCREEN_WIDTH - i, SCREEN_HEIGHT);
    }
    for (int i = 0; i <= SCREEN_HEIGHT; i += 20) {
        SDL_RenderDrawLine(gRenderer, 0, i, SCREEN_WIDTH, SCREEN_HEIGHT - i);
    }
}