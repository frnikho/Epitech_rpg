/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** particles_tools
*/

#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "lib/effects/particle.h"

void particle_setsize(particle_t *p, sfVector2f size)
{
    sfSprite_setScale(p->sprite, size);
}

void particle_system_setsize(particle_system_t *sys, sfVector2f size)
{
    for (int i = 0; i < sys->particule_nb; i++) {
        particle_setsize(sys->particles[i], size);
    }
}