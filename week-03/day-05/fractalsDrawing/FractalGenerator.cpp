#include "FractalGenerator.h"


FractalGenerator::FractalGenerator(SDL_Renderer* renderer, int maxDepth) : _renderer(renderer),
                                                                           maxDepth(maxDepth) {}

void FractalGenerator::draw(int x0, int y0, int xm, int ym) {
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

void FractalGenerator::drawTriangle(int startX, int startY, int sideLength, float height){
    SDL_RenderDrawLine(_renderer, startX, startY, startX + sideLength, startY);
    SDL_RenderDrawLine(_renderer, startX, startY, startX + sideLength / 2, startY - height);
    SDL_RenderDrawLine(_renderer, startX + sideLength / 2, startY - height, startX + sideLength, startY);
}

void FractalGenerator::drawTriangleFractal(){
    
}