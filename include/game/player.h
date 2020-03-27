/*
** EPITECH PROJECT, 2020
** game.h
** File description:
**  function
*/

#ifndef MY_RPG_PLAYER_H
#define MY_RPG_PLAYER_H

#include "inventory.h"
#include "stats.h"

typedef struct player_s {
    int level;
    int xp;
    inventory_t *inventory;
    stats_t *stats;
    int zone;
} player_t;

void debug_player(player_t *player);
player_t *deserialize_player(void);
void serialize_player(player_t *player);
void destroy_player(player_t *player);

#endif
