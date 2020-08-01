#include "render3D.h"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 800

int SDL_report(const char *error){
    SDL_Log("ERREUR : %s\n", error);
    SDL_Quit();
    return EXIT_FAILURE;
}

// gcc view.c cube.c vector3D.c render3D.h -o view -lmingw32 -lSDL2main -lSDL2
int main(int argc, char *argv[]){
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    if(SDL_Init(SDL_INIT_VIDEO) != 0) return SDL_report(SDL_GetError());
    if(SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer) != 0)
        return SDL_report(SDL_GetError());
    
    float proj_mx[] = {1, 0, 0, 0, 1, 0};
    cube_t *cube_a = cube_init((vector3D_t) {600, 400, 0}, 100);

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
        cube_render(renderer, cube_a, proj_mx);
        SDL_RenderPresent(renderer);
        SDL_Delay(60);
    }

    free(cube_a);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}