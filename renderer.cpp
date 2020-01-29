#include "SDL.h"
#include <iostream>

void setUpSDL(){
SDL_Init(SDL_INIT_VIDEO);

  SDL_Window *window = SDL_CreateWindow(
    "Rendering Engine",
    SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED,
    500,
    500,
    0
  );

  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
  SDL_RenderClear(renderer);
  // update SDL Window
  SDL_RenderPresent(renderer);
}


int main(int argc, char *argv[])
{
  setUpSDL();

  return 0;
}