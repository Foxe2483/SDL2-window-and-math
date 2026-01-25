#include <iostream>
#include <SDL2/SDL.h>
#include <cmath>

int main() {

SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;
SDL_Event e;
SDL_Init(SDL_INIT_VIDEO);
const int X = 640, Y = 480; const float scale = 1.4;
SDL_CreateWindowAndRenderer(X*scale, Y*scale, 0, &window, &renderer);
SDL_RenderSetScale(renderer,scale,scale);

float num = 0;
while(true) {
SDL_SetRenderDrawColor(renderer,255,255,255,255);
SDL_RenderClear(renderer);
SDL_SetRenderDrawColor(renderer,0,0,0,255);
SDL_RenderDrawLine(renderer, 0  , Y/2, X  , Y/2);
SDL_RenderDrawLine(renderer, X/2, 0  , X/2, Y);
num+=0.2;
if(num == 10000){num = 0;}
while(SDL_PollEvent(&e)) {
	if(e.type == SDL_QUIT){
		return 0;
		}
}
//Red
for (float i = X/-2; i != (X/2); i+=1) {
// f = math function 
//
//float f = sin(i/80 + num)*80;

//Direct x and y
//
float a = cos(i), f = sin(i) + sqrt(abs(cos(i)));

SDL_SetRenderDrawColor(renderer,255,0,0,255);
SDL_RenderDrawPoint(renderer, a*40+(X/2), -f*32+(Y/2));
}
//Green
for (float i = X/-2; i != (X/2); i+=1) {
// f = math function 
//
float f = sin(i/30 + num) * 30;
//

SDL_SetRenderDrawColor(renderer,0,255,0,255);
SDL_RenderDrawPoint(renderer, i+(X/2), -f+(Y/2));
}

SDL_RenderPresent(renderer);
SDL_Delay(50);
}

return 0;
}