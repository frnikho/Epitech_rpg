/*
** EPITECH PROJECT, 2020
** serialize_player.c
** File description:
**  function
*/

#include "lib/utils/json_writer.h"
#include "game/player.h"
#include "lib/utils/string.h"

void serialize_player(player_t *player)
{
    if (!player)
        return;
    char *fp = "content/player.json";
    json_writer(fp, "level", convert_str(player->level));
    json_writer(fp, "xp", convert_str(player->xp));
    json_writer(fp, "hp", convert_str(player->stats->hp));
    json_writer(fp, "mp", convert_str(player->stats->mp));
    json_writer(fp, "resistance", convert_str(player->stats->resistance));
    json_writer(fp, "magic", convert_str(player->stats->magic));
    json_writer(fp, "agility", convert_str(player->stats->agility));
    json_writer(fp, "strength", convert_str(player->stats->strenght));
    json_writer(fp, "gold", convert_str(player->gold));
}