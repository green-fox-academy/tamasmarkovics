#include "draw.h"

//DOES THE WORK ON ANY SCREEN SIZE

void draw(SDL_Renderer* gRenderer) {

    SDL_SetRenderDrawColor(gRenderer, 0xFF /*R*/, 0 /*G*/, 0 /*B*/, 0xFF /*A*/);
    double horizontalSteps = 0;
    double verticalSteps = 0;
    double noOfLines = 100;
    for (int i = 0; i <= noOfLines; i += 1) {
        horizontalSteps = (SCREEN_WIDTH / noOfLines) * i;
        verticalSteps = (SCREEN_HEIGHT / noOfLines) * i;
        SDL_RenderDrawLine(gRenderer, horizontalSteps, 0, SCREEN_WIDTH, verticalSteps);
        SDL_RenderDrawLine(gRenderer, 0, verticalSteps, horizontalSteps, SCREEN_HEIGHT);
    }
}