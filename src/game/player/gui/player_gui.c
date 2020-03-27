/*
** EPITECH PROJECT, 2020
** player_gui.c
** File description:
**  function
*/

#include "game/player.h"
#include "lib/utils/string.h"
#include <stdlib.h>

void create_gui(player_t *player)
{
    player->gui = malloc(sizeof(player_gui_t));
    player->gui->name = init_text("Hero", 26, (sfVector2f){170, 610});
    set_text_font(player->gui->name, "assets/font/dq.ttf");

    char *level = str_cat("Lv. ", convert_str(player->level));
    player->gui->level = init_text(level, 20, (sfVector2f){270, 752});
    set_text_font(player->gui->level, "assets/font/dq.ttf");

    player->gui->box = init_sprite("assets/sprite/gui/player_gui.png", 0);
    set_sprite_position(player->gui->box, (sfVector2f){50, 600});
}