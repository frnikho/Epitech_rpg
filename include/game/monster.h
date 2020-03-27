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
    char *name;
    sprite_t *sprite;
    stats_t *stats;
    int gains_factor;
    int stats_factor;
    int xp;
    int gold;
} monster_t;

monster_t *create_monster(char *fp, sfVector2f pos);
void dispose_monster(monster_t *monster);
void draw_monster(sfRenderWindow *window, monster_t *monster);

#endif