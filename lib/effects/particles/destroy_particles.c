/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** destroy_particles
*/

#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "lib/effects/particle.h"

void destroy_particle(particle_t *p)
{
    sfSprite_destroy(p->sprite);
    sfTexture_destroy(p->texture);
    free(p);
}

void destroy_particle_system(particle_system_t *sys)
{
    for (int i = 0; i < sys->particule_nb; i++) {
        destroy_particle(sys->particles[i]);
    }
}