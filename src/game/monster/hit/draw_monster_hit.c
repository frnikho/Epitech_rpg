/*
** EPITECH PROJECT, 2020
** draw_monster_hit.c
** File description:
** draw monster hit function
*/

#include "game/monster.h"

void draw_monster_hit(sfRenderWindow *window, monster_hit_t *hit)
{
    if (!hit->is_active)
        return;
    draw_sprite(window, hit->damage);
    draw_anim_sprite(window, hit->stroke);
}