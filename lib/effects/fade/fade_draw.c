/*
** EPITECH PROJECT, 2020
** fade_draw.c
** File description:
** fade draw function
*/

#include "lib/effects/fade.h"
#include <SFML/Graphics.h>

static void update_fade_out(fade_t *fade)
{
    if (fade->color.a - fade->speed <= 0) {
        fade->color.a = 255;
        fade->is_finish = 1;
        fade->is_active = 0;
    } else {
        fade->color.a -= fade->speed;
    }
}

static void update_fade_in(fade_t *fade)
{
    if (fade->color.a >= 254 - fade->speed) {
        fade->color.a = 255;
        fade->is_finish = 1;
        fade->is_active = 0;
    } else {
        fade->color.a += fade->speed;
    }
}

void update_delta(fade_t *fade, long int delta)
{
    fade->delta += delta;
}

void update_fade(fade_t *fade)
{
    if (!fade->is_active)
        return;
    if (fade->fade_in) {
        update_fade_in(fade);
    } else {
        update_fade_out(fade);
    }
    sfRectangleShape_setFillColor(fade->shape, fade->color);
}

void draw_fade(sfRenderWindow *window, fade_t *fade)
{
    if (fade->is_active == 1) {
        sfRenderWindow_drawRectangleShape(window, fade->shape, 0);
    }
}