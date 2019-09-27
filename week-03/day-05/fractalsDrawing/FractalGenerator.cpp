#include <cmath>
#include "FractalGenerator.h"


FractalGenerator::FractalGenerator(SDL_Renderer* renderer, int maxDepth) : _renderer(renderer),
                                                                           maxDepth(maxDepth) {}

void FractalGenerator::draw(int x0, int y0, int xm, int ym)
{
    drawFractal(x0, y0, xm, ym, 0);
}

void FractalGenerator::drawFractal(int x0, int y0, int xm, int ym, int depth)
{
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


//TRIANGLES


void FractalGenerator::drawTriangle(int startX, int startY, int sideLength, float height, int depth)
{
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


void FractalGenerator::draw2(int x0, int y0, int side, int height)
{
    drawTriangle(x0, y0, side, height, 0);
}


//CIRCLES


void FractalGenerator::drawCircle(int startX, int startY, int radius, int depth)
{   float PI = 3.14159265;
    int noSides = 100;

    float angle = 0.0f;
    float incr = 2 * PI / noSides;

    int newX = radius * cos(angle) + startX;
    int newY = radius * sin(angle) + startY;

    for (int i=0; i<noSides; i++){
        int oldX = newX;
        int oldY = newY;
        angle += incr;
        newX = radius * cos(angle) + startX;
        newY = radius * sin(angle) + startY;
        SDL_RenderDrawLine( _renderer, oldX, oldY, newX, newY);
    }

    if(depth < maxDepth){

        if (depth == 0) SDL_SetRenderDrawColor(_renderer, 0, 0, 255, 0xFF);
        drawCircle(startX - radius / 2 / pow(3, 0.5) * 1.5, startY + radius / 4, radius / 2, depth + 1);

        if (depth == 0) SDL_SetRenderDrawColor(_renderer, 150, 0, 0, 0xFF);
        drawCircle(startX + radius / 2 / pow(3, 0.5) * 1.5, startY + radius / 4, radius / 2, depth + 1);

        if (depth == 0) SDL_SetRenderDrawColor(_renderer, 0, 100, 0, 0xFF);
        drawCircle(startX, startY - radius / 2, radius / 2, depth + 1);
    }
}

void FractalGenerator::draw3(int x0, int y0, int radius)
{
    drawCircle(x0, y0, radius, 0);
}


//TREE


void FractalGenerator::drawTree(double startX, double startY, double endX, double endY, double angle, int depth)
{
    SDL_RenderDrawLine(_renderer, startX, startY, endX, endY);
    int lenght = 100 - 20 * depth;
    if(depth < maxDepth){
        drawTree(endX, endY, endX, endY - lenght, 0, depth++);
        drawTree(endX, endY, endX - lenght * cos(angle * depth), endY - lenght * 0.6 * sin(angle * depth), angle + 20, depth++);
        drawTree(endX, endY, endX + lenght * cos(angle * depth), endY - lenght * 0.6 * sin(angle * depth), angle - 20, depth++);
    }
}


void FractalGenerator::draw4(int lenght){
    drawTree(400, 800, 400, 800 - lenght, 0, 0);
}