#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 800

// gcc rotation.c -o rotation -lmingw32 -lSDL2main -lSDL2
int main(int argc, char *argv[]){
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    
    if(SDL_Init(SDL_INIT_VIDEO) != 0){
        SDL_Log(SDL_GetError());
        return EXIT_FAILURE;
    }
        
    if(SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer) != 0){
        SDL_Log(SDL_GetError());
        return EXIT_FAILURE;
    }
    
    SDL_bool run = SDL_TRUE;
    while(run){
        SDL_Event event;
        while(SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_QUIT:
                    run = SDL_FALSE;
                    break;
                default:
                    break;
            }
        }
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // DRAW HERE
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderDrawLine(renderer, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

        SDL_RenderPresent(renderer);
        SDL_Delay(60);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}