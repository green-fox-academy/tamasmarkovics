#include <cmath>
#include "FractalGenerator.h"


FractalGenerator::FractalGenerator(SDL_Renderer* renderer, int maxDepth) : _renderer(renderer),
                                                                           maxDepth(maxDepth), _angle(0.5f),
                                                                           _ratioOfStraight(0.75f), _ratioOfSides(0.7f) {}

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

        //if (depth == 0) SDL_SetRenderDrawColor(_renderer, 0, 0, 255, 0xFF);
        drawCircle(startX - radius / 2 / pow(3, 0.5) * 1.5, startY + radius / 4, radius / 2, depth + 1);

        //if (depth == 0) SDL_SetRenderDrawColor(_renderer, 150, 0, 0, 0xFF);
        drawCircle(startX + radius / 2 / pow(3, 0.5) * 1.5, startY + radius / 4, radius / 2, depth + 1);

        //if (depth == 0) SDL_SetRenderDrawColor(_renderer, 0, 100, 0, 0xFF);
        drawCircle(startX, startY - radius / 2, radius / 2, depth + 1);
    }
}

void FractalGenerator::draw3(int x0, int y0, int radius)
{
    drawCircle(x0, y0, radius, 0);
}


//TREE


void FractalGenerator::drawBranch(double xStart, double yStart, int depth, double actualSize, double actualAngle)
{
    if (depth < maxDepth) {

        //straight branch
        int xEndOfStraightSide = xStart + _ratioOfStraight * actualSize * cosf(actualAngle);      //depth should start with 0
        int yEndOfStraightSide = yStart - _ratioOfStraight * actualSize * sinf(actualAngle);
        SDL_RenderDrawLine(_renderer, xStart, yStart, xEndOfStraightSide, yEndOfStraightSide);

        //left side branch
        int xEndOfLeftSide = xStart + _ratioOfSides * actualSize * cosf(actualAngle + _angle);      //depth should start with 0
        int yEndOfLeftSide = yStart - _ratioOfSides * actualSize * sinf(actualAngle + _angle);
        SDL_RenderDrawLine(_renderer, xStart, yStart, xEndOfLeftSide, yEndOfLeftSide);

        //right side branch
        int xEndOfRightSide = xStart + _ratioOfSides * actualSize * cosf(actualAngle - _angle);      //depth should start with 0
        int yEndOfRightSide = yStart - _ratioOfSides * actualSize * sinf(actualAngle - _angle);
        SDL_RenderDrawLine(_renderer, xStart, yStart, xEndOfRightSide, yEndOfRightSide);

        //draw next straight branch
        drawBranch(xEndOfStraightSide, yEndOfStraightSide, depth + 1, _ratioOfStraight * actualSize, actualAngle);
        //draw next left branch
        drawBranch(xEndOfLeftSide, yEndOfLeftSide, depth + 1, _ratioOfSides * actualSize, actualAngle + _angle);
        //draw next right branch
        drawBranch(xEndOfRightSide, yEndOfRightSide, depth + 1, _ratioOfSides * actualSize, actualAngle - _angle);

    }
}

void FractalGenerator::drawTree(int xStart, int yStart, int depth, float size) {
    maxDepth = depth;

    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 0xFF);
    int xEnd = xStart;
    int yEnd = yStart - 150;
    SDL_RenderDrawLine(_renderer, xStart, yStart, xEnd, yEnd);
    drawBranch(xEnd, yEnd, 0, size, 3.1415 / 2);

}


