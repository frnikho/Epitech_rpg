/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** particle
*/

#ifndef CSFML_EFFECT_LIB_PARTICLE_H
#define CSFML_EFFECT_LIB_PARTICLE_H

#include <SFML/Graphics.h>

typedef struct particle_s {
    sfVector2f pos;
    sfVector2f velocity;
    sfUint8 *pixels;
    float life;
    int speed;
    int count;
    int is_show;
    sfColor color;
    sfTexture *texture;
    sfSprite *sprite;
} particle_t;

typedef struct particle_system_s {
    particle_t **particles;
    int particule_nb;
} particle_system_t;

particle_t *create_particule(sfVector2f pos, int speed, float life, sfColor color);
particle_system_t *create_particle_system(int particle_nb, sfVector2f pos, int life_time, int speed);
void draw_particle(sfRenderWindow *window, particle_t *particle);
void draw_particle_system(sfRenderWindow *win, particle_system_t *sys);
void destroy_particle(particle_t *p);
void particle_setSize(particle_t *p, sfVector2f size);
void particle_system_setSize(particle_system_t *sys, sfVector2f size);

#endif
