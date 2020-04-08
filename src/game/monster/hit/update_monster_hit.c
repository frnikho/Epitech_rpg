/*
** EPITECH PROJECT, 2020
** update_monster_hit.c
** File description:
** update monster hit function
*/

#include "game/monster.h"

void update_monster_hit(monster_hit_t *hit, long int delta)
{
    if (hit->is_active)
        hit->delta += delta;
}