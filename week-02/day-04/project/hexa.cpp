#include "draw.h"
#include <math.h>

//OUTDATED MESSY PIECE OF GARBAGE

void drawHexa(SDL_Renderer* gRenderer, int startX, int startY, int side)
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
        SDL_RenderDrawLine(gRenderer, oldX, oldY, newX, newY);
    }
}

void draw(SDL_Renderer* gRenderer)
{
    SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
    int hei = 80;
    int rad = hei * 0.6;

    for (int j = -3; j < 4; j ++){
        for (int i = 0; i < 4; i ++){
        drawHexa(gRenderer, 600 + j * 2 * 0.77 * rad   , 150 + abs(j) * hei / 2 + i * hei, rad);
        }
    }

    for (int j = 0; j < 4; j ++){
        for (int i = 0; i < 4; i ++){
        drawHexa(gRenderer, 600 - j * 2 * 0.77 * rad   , 150 + j * hei / 2 + i * hei, rad);
        }
    }

    for (int j = 0; j < 3; j ++){
        for (int i = 0; i < 3 - j; i ++){
        drawHexa(gRenderer, 600 - j * 2 * 0.77 * rad   , 150 + 4 * hei + j * hei / 2 + i * hei, rad);
        }
    }

    for (int j = 0; j < 3; j ++){
        for (int i = 0; i < 3 - j; i ++){
        drawHexa(gRenderer, 600 + j * 2 * 0.77 * rad   , 150 + 4 * hei + j * hei / 2 + i * hei, rad);
        }
    }
}