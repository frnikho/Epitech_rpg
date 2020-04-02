/*
** EPITECH PROJECT, 2020
** update_monster.c
** File description:
** update monster function
*/

#include "game/monster.h"

void update_monster(monster_t *monster, long int delta)
{
    if (monster->stats->hp < 0)
        monster->stats->hp = 0;
    if (monster->stats->hp == 0)
        monster->is_alive = 0;
    if (!monster->is_alive)
        monster->delta += delta;
}