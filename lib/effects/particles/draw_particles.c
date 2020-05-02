/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** particle_draw
*/

#include "lib/effects/particle.h"

static void check_particle_dead(particle_t *particle)
{
    if (particle->count >= particle->life) {
        particle->is_show = 0;
    } else {
        particle->count += 1;
    }
}

static void update_particle_pixels(particle_t *particle)
{
    particle->pos.x += (particle->velocity.x);
    particle->pos.y += (particle->velocity.y);
    particle->pixels[3] = particle->life / particle->count * 100;
    check_particle_dead(particle);
}

void draw_particle(sfRenderWindow *window, particle_t *particle)
{
    if (particle->is_show) {
        update_particle_pixels(particle);
        sfTexture_updateFromPixels(particle->texture, \
        particle->pixels, 1, 1, 0, 0);
        sfSprite_setTexture(particle->sprite, particle->texture, sfFalse);
        sfSprite_setPosition(particle->sprite, particle->pos);
        sfRenderWindow_drawSprite(window, particle->sprite, 0);
    }
}

void draw_particle_system(sfRenderWindow *win, particle_system_t *sys)
{
    for (int i = 0; i < sys->particule_nb; i++) {
        draw_particle(win, sys->particles[i]);
    }
}