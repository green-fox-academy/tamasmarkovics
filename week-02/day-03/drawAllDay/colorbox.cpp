// Draw a box that has different colored lines on each edge.
// The center of the box should align with the center of the screen.

#include "draw.h"

void draw(SDL_Renderer* gRenderer) {
    SDL_SetRenderDrawColor(gRenderer, 200 /*R*/, 100 /*G*/, 0 /*B*/, 0xFF /*A*/);
    //draw line
    SDL_RenderDrawLine(gRenderer, 100,   100, SCREEN_WIDTH -100,  100);
    SDL_SetRenderDrawColor(gRenderer, 0xFF /*R*/, 0xFF /*G*/, 40 /*B*/, 0xFF /*A*/);
    SDL_RenderDrawLine(gRenderer, 100, SCREEN_HEIGHT - 100 , SCREEN_WIDTH -100, SCREEN_HEIGHT - 100);
    SDL_SetRenderDrawColor(gRenderer, 0xFF /*R*/, 10 /*G*/, 0xFF /*B*/, 0xFF /*A*/);
    //draw line
    SDL_RenderDrawLine(gRenderer, SCREEN_WIDTH -100, 100 , SCREEN_WIDTH -100, SCREEN_HEIGHT - 100);
    SDL_SetRenderDrawColor(gRenderer, 43 /*R*/, 43 /*G*/, 43 /*B*/, 0xFF /*A*/);
    SDL_RenderDrawLine(gRenderer, 100, 100 , 100, SCREEN_HEIGHT - 100);
}
