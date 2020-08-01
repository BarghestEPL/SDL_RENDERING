#include "render3D.h"

cube_t *cube_init(vector3D_t pos, int size){
    cube_t *new = malloc(sizeof(cube_t));
    if(new == NULL) exit(EXIT_FAILURE);
    
    new->a = (vector3D_t) {pos.x - size, pos.y - size, pos.z - size};
    new->b = (vector3D_t) {pos.x + size, pos.y - size, pos.z - size};
    new->c = (vector3D_t) {pos.x + size, pos.y + size, pos.z - size};
    new->d = (vector3D_t) {pos.x - size, pos.y + size, pos.z - size};

    new->e = (vector3D_t) {pos.x + size, pos.y + size, pos.z + size};
    new->f = (vector3D_t) {pos.x - size, pos.y + size, pos.z + size};
    new->g = (vector3D_t) {pos.x - size, pos.y - size, pos.z + size};
    new->h = (vector3D_t) {pos.x + size, pos.y - size, pos.z + size};

    new->size = size;
    new->pos = pos;
    return new;
}

void cube_render(SDL_Renderer *renderer, cube_t *cube, float *proj_mx){
    float angle = 0.1f;
    
    vector3D_rotx(&cube->a, &cube->pos, angle);
    vector3D_rotx(&cube->b, &cube->pos, angle);
    vector3D_rotx(&cube->c, &cube->pos, angle);
    vector3D_rotx(&cube->d, &cube->pos, angle);
    vector3D_rotx(&cube->e, &cube->pos, angle);
    vector3D_rotx(&cube->f, &cube->pos, angle);
    vector3D_rotx(&cube->g, &cube->pos, angle);
    vector3D_rotx(&cube->h, &cube->pos, angle);

    vector3D_roty(&cube->a, &cube->pos, angle);
    vector3D_roty(&cube->b, &cube->pos, angle);
    vector3D_roty(&cube->c, &cube->pos, angle);
    vector3D_roty(&cube->d, &cube->pos, angle);
    vector3D_roty(&cube->e, &cube->pos, angle);
    vector3D_roty(&cube->f, &cube->pos, angle);
    vector3D_roty(&cube->g, &cube->pos, angle);
    vector3D_roty(&cube->h, &cube->pos, angle);

    vector3D_rotz(&cube->a, &cube->pos, angle);
    vector3D_rotz(&cube->b, &cube->pos, angle);
    vector3D_rotz(&cube->c, &cube->pos, angle);
    vector3D_rotz(&cube->d, &cube->pos, angle);
    vector3D_rotz(&cube->e, &cube->pos, angle);
    vector3D_rotz(&cube->f, &cube->pos, angle);
    vector3D_rotz(&cube->g, &cube->pos, angle);
    vector3D_rotz(&cube->h, &cube->pos, angle);
    
    // RENDERING
    vector3D_join(renderer, &cube->a, &cube->b, proj_mx);
    vector3D_join(renderer, &cube->b, &cube->c, proj_mx);
    vector3D_join(renderer, &cube->c, &cube->d, proj_mx);
    vector3D_join(renderer, &cube->d, &cube->a, proj_mx);

    vector3D_join(renderer, &cube->e, &cube->f, proj_mx);
    vector3D_join(renderer, &cube->f, &cube->g, proj_mx);
    vector3D_join(renderer, &cube->g, &cube->h, proj_mx);
    vector3D_join(renderer, &cube->h, &cube->e, proj_mx);

    vector3D_join(renderer, &cube->a, &cube->g, proj_mx);
    vector3D_join(renderer, &cube->b, &cube->h, proj_mx);
    vector3D_join(renderer, &cube->c, &cube->e, proj_mx);
    vector3D_join(renderer, &cube->d, &cube->f, proj_mx);
}