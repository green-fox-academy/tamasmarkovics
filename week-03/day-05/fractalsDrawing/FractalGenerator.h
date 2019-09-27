#ifndef FRACTALS_FRACTALGENERATOR_H
#define FRACTALS_FRACTALGENERATOR_H

#include <SDL_render.h>


class FractalGenerator {
public:
    FractalGenerator(SDL_Renderer* renderer, int maxDepth);

    void drawFractal(int x0, int y0, int xm, int ym, int depth);
    void drawTriangle(int startX, int startY, int sideLength, float height, int depth);
    void drawCircle(int startX, int startY, int side, int depth);

    void drawTree(double startX, double startY, double endX, double endY, double angle, int depth);

    void draw(int x0, int y0, int xm, int ym);                      //MISI
    void draw2(int x0, int y0, int side, int height);               //TRIANGLES


    void draw3(int x0, int y0, int radius);                         //CIRCLES

    void draw4(int lenght);
private:
    SDL_Renderer* _renderer;
    int maxDepth;
};


#endif //FRACTALS_FRACTALGENERATOR_H