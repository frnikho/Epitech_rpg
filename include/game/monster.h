/*
** EPITECH PROJECT, 2020
** monster.h
** File description:
**  function
*/

#ifndef MY_RPG_MONSTER_H
#define MY_RPG_MONSTER_H

#include "lib/components/sprite.h"
#include "game/stats.h"

typedef struct monster_s {
    int id;
    sprite_t *sprite;
    stats_t entity_stats;
    int gains_factor;
    int stats_factor;
    int xp;
    int gold;
} monster_t;

#endif