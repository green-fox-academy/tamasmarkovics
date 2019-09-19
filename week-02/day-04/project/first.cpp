#include "draw.h"


void draw(SDL_Renderer* gRenderer) {

    SDL_SetRenderDrawColor(gRenderer, 0xFF /*R*/, 0 /*G*/, 0 /*B*/, 0xFF /*A*/);
    double a = 0;
    double b = 0;
    double n = 2000;
    for (int i = 0; i <= n; i += 1) {
        a = (SCREEN_WIDTH / n) * i;
        b = (SCREEN_HEIGHT / n) * i;
        SDL_RenderDrawLine(gRenderer, a, 0, SCREEN_WIDTH, b);
        SDL_RenderDrawLine(gRenderer, 0, b, a, SCREEN_HEIGHT);
    }
}