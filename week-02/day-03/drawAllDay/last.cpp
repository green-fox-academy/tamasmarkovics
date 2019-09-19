#include "draw.h"
#include <vector>
using std::vector;

//CONNECTING THE DOTS


void connect(SDL_Renderer* gRenderer,int size,  int arr[][2]) {
    SDL_SetRenderDrawColor(gRenderer, 00 /*R*/, 255 /*G*/, 0x00 /*B*/, 0xFF /*A*/);
    for (int i = 0; i < size-1; i++){
        SDL_RenderDrawLine(gRenderer, arr[i][0], arr[i][1], arr[i+1][0], arr[i+1][1]);      //CONNECTS EVERY DOT
    }
    SDL_RenderDrawLine(gRenderer, arr[0][0], arr[0][1], arr[size-1][0], arr[size-1][1]);    //AAAND THE LAST ONE
}

void draw(SDL_Renderer* gRenderer) {
    int fox[][2] = {{10, 10}, {290,  10}, {290, 290}, {10, 290}};
    int box[][2] = {{50, 100}, {70, 70}, {80, 90}, {90, 90}, {100, 70}, {120, 100}, {85, 130}, {50, 100}};
    connect(gRenderer, 8, box);
    connect(gRenderer, 4, fox);

}