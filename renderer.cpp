#include <stdlib.h>

#include "SDL.h"

#define WINDOW_WIDTH 600

int main(void) {
    SDL_Event event;
    SDL_Renderer *renderer;
    SDL_Window *window;
    int i;

    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_WIDTH, 0, &window, &renderer);
    

    unsigned int lastFrame;
    unsigned int currentFrame;
    int frameCount;


    while (1) {
        if (SDL_PollEvent(&event) && event.type == SDL_QUIT){
            break;
        }
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);

        for (int i = 0; i < 100000; i++){
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            double j = i * 0.01;
            SDL_RenderDrawPoint(renderer, (WINDOW_WIDTH / 2) + (j * cos(j)), (WINDOW_WIDTH / 2) + (j * sin(j)));
        }
        SDL_RenderPresent(renderer);

        frameCount++;
        currentFrame = SDL_GetTicks();
        float fps = currentFrame / frameCount;

        printf("%d\n", currentFrame);

        lastFrame = currentFrame;
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}