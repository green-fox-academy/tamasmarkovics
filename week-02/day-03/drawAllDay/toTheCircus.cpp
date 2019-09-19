#include "draw.h"


void draw(SDL_Renderer* gRenderer) {

    SDL_SetRenderDrawColor(gRenderer, 0xFF /*R*/, 0 /*G*/, 0 /*B*/, 0xFF /*A*/);
    for (int i = 0; i <= SCREEN_WIDTH; i += 15) {
        SDL_RenderDrawLine(gRenderer, i, 0, SCREEN_WIDTH/2, SCREEN_HEIGHT / 2);
        SDL_RenderDrawLine(gRenderer, SCREEN_WIDTH-i, SCREEN_HEIGHT, SCREEN_WIDTH/2, SCREEN_HEIGHT / 2);
    }

    for (int i = 0; i <= SCREEN_HEIGHT; i += 15) {
        SDL_RenderDrawLine(gRenderer, 0, i, SCREEN_WIDTH/2, SCREEN_HEIGHT / 2);
        SDL_RenderDrawLine(gRenderer, SCREEN_WIDTH, SCREEN_HEIGHT - i, SCREEN_WIDTH/2, SCREEN_HEIGHT / 2);
    }

    SDL_SetRenderDrawColor(gRenderer, 0 /*R*/, 0xFF /*G*/, 0 /*B*/, 0xFF /*A*/);
    for (int i = 10; i <= SCREEN_WIDTH; i += 15) {
        SDL_RenderDrawLine(gRenderer, i, 0, SCREEN_WIDTH/2, SCREEN_HEIGHT / 2);
        SDL_RenderDrawLine(gRenderer, SCREEN_WIDTH-i, SCREEN_HEIGHT, SCREEN_WIDTH/2, SCREEN_HEIGHT / 2);
    }

    for (int i = 10; i <= SCREEN_HEIGHT; i += 15) {
        SDL_RenderDrawLine(gRenderer, 0, i, SCREEN_WIDTH/2, SCREEN_HEIGHT / 2);
        SDL_RenderDrawLine(gRenderer, SCREEN_WIDTH, SCREEN_HEIGHT - i, SCREEN_WIDTH/2, SCREEN_HEIGHT / 2);
    }
    SDL_SetRenderDrawColor(gRenderer, 100 /*R*/, 100 /*G*/,  100/*B*/, 0xFF /*A*/);
    for (int i = 5; i <= SCREEN_WIDTH; i += 15) {
        SDL_RenderDrawLine(gRenderer, i, 0, SCREEN_WIDTH/2, SCREEN_HEIGHT / 2);
        SDL_RenderDrawLine(gRenderer, SCREEN_WIDTH-i, SCREEN_HEIGHT, SCREEN_WIDTH/2, SCREEN_HEIGHT / 2);
    }

    for (int i = 5; i <= SCREEN_HEIGHT; i += 15) {
        SDL_RenderDrawLine(gRenderer, 0, i, SCREEN_WIDTH/2, SCREEN_HEIGHT / 2);
        SDL_RenderDrawLine(gRenderer, SCREEN_WIDTH, SCREEN_HEIGHT - i, SCREEN_WIDTH/2, SCREEN_HEIGHT / 2);
    }

}