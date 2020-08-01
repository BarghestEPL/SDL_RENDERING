#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 800


typedef struct _vector2D{
    float x, y;
} vector2D_t;

void vector2D_rot(vector2D_t *vector2D, vector2D_t *center, float angle){
    float c = SDL_cos(angle), s = SDL_sinf(angle);

    vector2D->x -= center->x;
    vector2D->y -= center->y;

    float rotated_x = vector2D->x * c - vector2D->y * s;
    float rotated_y = vector2D->x * s + vector2D->y * c;

    vector2D->x = rotated_x + center->x;
    vector2D->y = rotated_y + center->y;
}

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
    
    vector2D_t a = {600, 200}, b = {600, 400};
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

        SDL_RenderDrawLineF(renderer, a.x, a.y, b.x, b.y);
        vector2D_rot(&a, &b, 0.1);

        SDL_RenderPresent(renderer);
        SDL_Delay(60);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}