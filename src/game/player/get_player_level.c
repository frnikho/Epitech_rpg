/*
** EPITECH PROJECT, 2020
** get_player_level.c
** File description:
** get player level function
*/

#include "game/player.h"

int get_next_xp_level(player_t *player)
{
    int start = 20;
    for (int i = 0; i < player->level; i++)
        start += (start / 2);
    return (start);
}

int get_player_level(player_t *player)
{
    return (player->level);
}