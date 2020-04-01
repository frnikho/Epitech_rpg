/*
** EPITECH PROJECT, 2020
** player_gui.c
** File description:
**  function
*/

#include "game/player.h"
#include "lib/utils/string.h"
#include <stdlib.h>

static void init_player_bar_gui(player_t *player)
{
    sfColor health_color = sfColor_fromRGBA(16, 107, 255, 255);
    sfColor mana_color = sfColor_fromRGBA(255, 123, 24, 255);
    player->gui->hp_bar = sfRectangleShape_create();
    player->gui->mp_bar = sfRectangleShape_create();
    sfRectangleShape_setPosition(player->gui->hp_bar, (sfVector2f){73, 690});
    sfRectangleShape_setFillColor(player->gui->hp_bar, health_color);
    sfRectangleShape_setPosition(player->gui->mp_bar, (sfVector2f){73, 743});
    sfRectangleShape_setFillColor(player->gui->mp_bar, mana_color);
    update_player_gui(player);
}

void create_gui(player_t *player)
{
    player->gui = malloc(sizeof(player_gui_t));
    player->gui->name = init_text("Hero", 26, (sfVector2f){170, 610});
    set_text_font(player->gui->name, FONT);
    char *level = str_cat("Lv. ", convert_str(player->level));
    player->gui->level = init_text(level, 16, (sfVector2f){278, 758});
    set_text_font(player->gui->level, FONT);
    char *hp = str_cat("HP\t\t\t\t", convert_str(player->stats->hp));
    char *mp = str_cat("MP\t\t\t\t", convert_str(player->stats->mp));
    player->gui->hp = init_text(hp, 20, (sfVector2f){90, 660});
    set_text_font(player->gui->hp, FONT);
    player->gui->mp = init_text(mp, 20, (sfVector2f){85, 710});
    set_text_font(player->gui->mp, FONT);
    player->gui->box = init_sprite("assets/sprite/gui/player_gui.png", 0);
    set_sprite_position(player->gui->box, (sfVector2f){50, 600});
    init_player_bar_gui(player);
}