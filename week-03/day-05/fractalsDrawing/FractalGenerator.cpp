#include "FractalGenerator.h"


FractalGenerator::FractalGenerator(SDL_Renderer* renderer, int maxDepth) : _renderer(renderer),
                                                                           maxDepth(maxDepth) {}

void FractalGenerator::draw(int x0, int y0, int xm, int ym) {               //ez rajzol
    drawFractal(x0, y0, xm, ym, 0);
}

void FractalGenerator::drawFractal(int x0, int y0, int xm, int ym, int depth) {
    int yh = (ym+y0)/2;
    int xh = (xm+x0)/2;

    SDL_RenderDrawLine(_renderer, xh, y0, xh, ym); //vertical
    SDL_RenderDrawLine(_renderer, x0, yh, xm, yh); //horizontal

    if(depth < maxDepth){
        drawFractal(x0, y0, xh, yh, depth+1);
        drawFractal(xh, y0, xm, yh, depth+1);
        drawFractal(x0, yh, xh, ym, depth+1);
        drawFractal(xh, yh, xm, ym, depth+1);
    }
}

void FractalGenerator::drawTriangle(int startX, int startY, int sideLength, float height, int depth){
    SDL_RenderDrawLine(_renderer, startX, startY, startX + sideLength, startY);
    SDL_RenderDrawLine(_renderer, startX, startY, startX + sideLength / 2, startY - height);
    SDL_RenderDrawLine(_renderer, startX + sideLength / 2, startY - height, startX + sideLength, startY);

    if(depth < maxDepth){

        if (depth == 0) SDL_SetRenderDrawColor(_renderer, 0, 100, 0, 0xFF);
        drawTriangle(startX, startY, sideLength / 2, height / 2, depth + 1);
        if (depth == 0) SDL_SetRenderDrawColor(_renderer, 150, 0, 0, 0xFF);
        drawTriangle(startX + sideLength / 2, startY, sideLength / 2, height / 2, depth + 1);
        if (depth == 0) SDL_SetRenderDrawColor(_renderer, 0, 0, 255, 0xFF);
        drawTriangle(startX + sideLength / 4, startY - height / 2, sideLength / 2, height / 2, depth + 1);
    }
}


void FractalGenerator::draw2(int x0, int y0, int side, int height) {
    drawTriangle(x0, y0, side, height, 0);
}


void FractalGenerator::drawCircle(int startX, int startY, int side)
{    float PI = 3.14159265;
    int noSides = 10;

    float angle = 0.0f;
    float incr = 2 * PI / noSides;

    int newX = side * cos(angle) + startX;
    int newY = side * sin(angle) + startY;

    for (int i=0; i<noSides; i++){
        int oldX = newX;
        int oldY = newY;
        angle += incr;
        newX = side * cos(angle) + startX;
        newY = side * sin(angle) + startY;
        SDL_RenderDrawLine( _renderer, oldX, oldY, newX, newY);
    }
}