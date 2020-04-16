/*
** EPITECH PROJECT, 2020
** player.c
** File description:
**  function
*/

#include "game/player.h"
#include <stdlib.h>

static player_t *init_player(void)
{
    player_t *player = malloc(sizeof(player_t));
    int values[6];
    values[STATS_I_HP] = 20;
    values[STATS_I_MP] = 10;
    values[STATS_I_MAG] = 8 + (rand() % 5);
    values[STATS_I_STR] = 8 + (rand() % 5);
    values[STATS_I_RES] = 8 + (rand() % 5);
    values[STATS_I_AG] = 8 + (rand() % 5);
    player->stats = init_stats(values);
    player->level = 1;
    player->xp = 0;
    player->zone = 1;
    return (player);
}

player_t *create_player(void)
{
    player_t *player = deserialize_player();
    player->learned_abi = 0;
    player->learned_spell = 0;
    create_gui(player);
    return (player);
}

void destroy_player(player_t *player)
{
    //TODO destroy inventory
    destroy_stats(player->stats);
    free(player);
}