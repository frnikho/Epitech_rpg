/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_particles
*/

#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "lib/effects/particle.h"

static void init_particle_pixels(particle_t *particle)
{
    particle->pixels = malloc(sizeof(sfUint8) * 5);
    particle->pixels[0] = particle->color.r;
    particle->pixels[1] = particle->color.g;
    particle->pixels[2] = particle->color.b;
    particle->pixels[3] = particle->color.a;
    particle->pixels[4] = 0;
}

static void init_particle_velocity(particle_t *particle)
{
    float r1 = ((float) rand() / (float)(RAND_MAX)) * particle->speed;
    float r2 = ((float) rand() / (float)(RAND_MAX)) * particle->speed;
    float dx = ((float)rand()/(float)(RAND_MAX)) * r1 - r1 / 2;
    float dy = ((float)rand()/(float)(RAND_MAX)) * r2 - r2 / 2;
    if (dy == 0)
        dy++;
    if (dx == 0)
        dx++;
    sfVector2f velocity = {dx, dy};
    particle->velocity = velocity;
}

particle_t *create_particule(sfVector2f pos, int speed, \
float life, sfColor color)
{
    particle_t *particle = malloc(sizeof(particle_t));
    particle->pos = pos;
    particle->speed = speed;
    particle->color = color;
    particle->life = life * 10;
    particle->count = 0;
    particle->is_show = 1;
    particle->texture = sfTexture_create(1, 1);
    init_particle_velocity(particle);
    init_particle_pixels(particle);
    particle->sprite = sfSprite_create();
    return (particle);
}

particle_system_t *create_particle_system(int particle_nb, \
sfVector2f pos, int life_time, int speed)
{
    time_t t;
    srand((unsigned) time(&t));
    particle_system_t *system = malloc(sizeof(particle_system_t));
    particle_t **particle = malloc(particle_nb * sizeof(particle_t *));
    for (int i = 0; i < particle_nb; i++) {
        int life = (rand() % life_time);
        int r = (rand() % 255);
        int g = (rand() % 255);
        int b = (rand() % 255);
        sfColor color = sfColor_fromRGBA(r, g, b, 255);
        particle[i] = create_particule(pos, speed, life, color);
    }
    system->particles = particle;
    system->particule_nb = particle_nb;
    return (system);
}