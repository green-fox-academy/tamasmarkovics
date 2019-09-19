#include "draw.h"



void draw(SDL_Renderer* gRenderer) {
    SDL_SetRenderDrawColor(gRenderer, 0xFF /*R*/, 0 /*G*/, 0 /*B*/, 0xFF /*A*/);
    double a = 0;
    double b = 0;
    double n = 40;
    for (int i = 0; i <= n; i += 1) {
        a = (SCREEN_WIDTH/2 / n) * i;
        b = (SCREEN_HEIGHT/ 2 / n) * i;
        SDL_RenderDrawLine(gRenderer, 0 + a, SCREEN_HEIGHT / 2, SCREEN_WIDTH / 2, SCREEN_HEIGHT/2 - b);
        SDL_RenderDrawLine(gRenderer, 0 + a, SCREEN_HEIGHT / 2, SCREEN_WIDTH / 2, SCREEN_HEIGHT/2 + b);
        SDL_RenderDrawLine(gRenderer, SCREEN_WIDTH - a, SCREEN_HEIGHT / 2, SCREEN_WIDTH / 2, SCREEN_HEIGHT/2 - b);
        SDL_RenderDrawLine(gRenderer, SCREEN_WIDTH - a, SCREEN_HEIGHT / 2, SCREEN_WIDTH / 2, SCREEN_HEIGHT/2 + b);
    }
}