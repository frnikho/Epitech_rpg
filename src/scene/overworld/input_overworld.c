/*
** EPITECH PROJECT, 2020
** input_overworld.c
** File description:
** input overworld function
*/

#include "game.h"
#include "scene/overworld.h"

int input_overworld(game_t *game, overworld_t *overworld)
{
    handle_inventory(game->event, game->player->inventory);
    return (0);
}