#include "render3D.h"

vector3D_t *vector3D_init(float x, float y, float z){
    vector3D_t *new = malloc(sizeof(vector3D_t));
    if(new == NULL) exit(EXIT_FAILURE);
    *new = (vector3D_t) {x, y, z};
    return new;
}

void vector3D_proj(vector3D_t *vector3D_in, vector3D_t *vector3D_out, float *proj_mx){
    vector3D_out->x = vector3D_in->x * proj_mx[0] + vector3D_in->y * proj_mx[1] + vector3D_in->z * proj_mx[2];
    vector3D_out->y = vector3D_in->x * proj_mx[3] + vector3D_in->y * proj_mx[4] + vector3D_in->z * proj_mx[5];
}

void vector3D_rotx(vector3D_t *vector3D, vector3D_t *center, float angle){
    float c = SDL_cos(angle), s = SDL_sinf(angle);

    vector3D->y -= center->y;
    vector3D->z -= center->z;

    float rotated_y = vector3D->y * c - vector3D->z * s;
    float rotated_z = vector3D->y * s + vector3D->z * c;

    vector3D->y = rotated_y + center->y;
    vector3D->z = rotated_z + center->z;
}

void vector3D_roty(vector3D_t *vector3D, vector3D_t *center, float angle){
    float c = SDL_cos(angle), s = SDL_sinf(angle);

    vector3D->x -= center->x;
    vector3D->z -= center->z;

    float rotated_x = vector3D->x * c + vector3D->z * s;
    float rotated_z = vector3D->z * c - vector3D->x * s;

    vector3D->x = rotated_x + center->x;
    vector3D->z = rotated_z + center->z;
}

void vector3D_rotz(vector3D_t *vector3D, vector3D_t *center, float angle){
    float c = SDL_cos(angle), s = SDL_sinf(angle);

    vector3D->x -= center->x;
    vector3D->y -= center->y;

    float rotated_x = vector3D->x * c - vector3D->y * s;
    float rotated_y = vector3D->x * s + vector3D->y * c;

    vector3D->x = rotated_x + center->x;
    vector3D->y = rotated_y + center->y;
}

void vector3D_render(SDL_Renderer *renderer, vector3D_t *vector3D, float *proj_mx){
    vector3D_t vector3D_projected;
    vector3D_proj(vector3D, &vector3D_projected, proj_mx);
    SDL_RenderDrawPointF(renderer, vector3D_projected.x, vector3D_projected.y);
}

void vector3D_join(SDL_Renderer *renderer, vector3D_t *a, vector3D_t *b, float *proj_mx){
    vector3D_t a_projected, b_projected;
    vector3D_proj(a, &a_projected, proj_mx);
    vector3D_proj(b, &b_projected, proj_mx);
    SDL_RenderDrawLineF(renderer, a_projected.x, a_projected.y, b_projected.x, b_projected.y);
}