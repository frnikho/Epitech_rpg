/*
** EPITECH PROJECT, 2020
** monster_hit.c
** File description:
** hit function
*/

#include "game/monster.h"
#include <stdlib.h>

monster_hit_t *create_monster_hit(int damage, monster_t monster)
{
    monster_hit_t *hit = malloc(sizeof(monster_hit_t));
    hit->is_active = 0;
    return (hit);
}