/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** destroy_player
*/

#include "game/player.h"
#include "lib/utils/file.h"
#include "lib/utils/json_parser.h"
#include <stdlib.h>
#include "lib/utils/string.h"
#include "game/collision.h"

void destroy_player(player_t *player)
{
    destroy_stats(player->stats);
    free(player);
}