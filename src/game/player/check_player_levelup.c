/*
** EPITECH PROJECT, 2020
** check_player_levelup.c
** File description:
** check player levelup function
*/

#include <stdlib.h>
#include "game/player.h"

int *check_player_levelup(player_t *player)
{
    int require_xp = get_next_xp_level(player);
    int *current_xp = &player->xp;

    if (require_xp <= (*current_xp)) {
        (*current_xp) = (*current_xp) - require_xp;
        player->level++;
        int *stats = malloc(sizeof(int) * 7);
        stats[0] = (rand() % 3) + 1;
        stats[1] = (rand() % 3) + 1;
        stats[2] = (rand() % 3) + 1;
        stats[3] = (rand() % 3) + 1;
        stats[4] = (rand() % 3) + 1;
        stats[5] = (rand() % 3) + 1;
        stats[6] = 0;
        player->stats->strenght += stats[0];
        player->stats->resistance += stats[1];
        player->stats->agility += stats[2];
        player->stats->hp += stats[3];
        player->stats->mp += stats[4];
        player->stats->magic += stats[5];
        return (stats);
    }
    return (0);
}