#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

typedef struct _vector3D{
    float x, y, z;
} vector3D_t;
vector3D_t *vector3D_init(float x, float y, float z);
void vector3D_proj(vector3D_t *vector3D_in, vector3D_t *vector3D_out, float *proj_mx);
void vector3D_rotx(vector3D_t *vector3D, vector3D_t *center, float angle);
void vector3D_roty(vector3D_t *vector3D, vector3D_t *center, float angle);
void vector3D_rotz(vector3D_t *vector3D, vector3D_t *center, float angle);
void vector3D_render(SDL_Renderer *renderer, vector3D_t *vector3D, float *proj__mx);
void vector3D_join(SDL_Renderer *renderer, vector3D_t *a, vector3D_t *b, float *proj_mx);

typedef struct _cube{
    int size;
    vector3D_t a, b, c, d;
    vector3D_t e, f, g, h, pos;
} cube_t;
cube_t *cube_init(vector3D_t pos, int size);
void cube_render(SDL_Renderer *renderer, cube_t *cube, float *proj_mx);
