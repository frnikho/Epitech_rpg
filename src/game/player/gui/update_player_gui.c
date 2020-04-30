/*
** EPITECH PROJECT, 2020
** update_player_gui.c
** File description:
** update player gui function
*/

#include <game/player.h>
#include "lib/utils/string.h"

void update_player_gui(player_t *player)
{
    if (player->health < 0)
        player->health = 0;
    if (player->mp < 0)
        player->mp = 0;
    float hp_width = player->health / (float) player->stats->hp;
    float mp_width = player->mp / (float) player->stats->mp;
    player_gui_t *gui = player->gui;
    sfRectangleShape_setSize(gui->hp_bar, (sfVector2f){246*hp_width, 6});
    sfRectangleShape_setSize(gui->mp_bar, (sfVector2f){246*mp_width, 6});
    char *hp = str_cat("HP\t\t\t\t", convert_str(player->health));
    char *mp = str_cat("MP\t\t\t\t", convert_str(player->mp));

    char *level = str_cat("Lv. ", convert_str(player->level));
    if (player->gui)
        player->gui->level->title = level;
    player->gui->hp->title = hp;
    player->gui->mp->title = mp;
}