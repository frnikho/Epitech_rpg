/*
** EPITECH PROJECT, 2020
** draw_player_gui.c
** File description:
**  function
*/

#include "game/player.h"

void draw_player_gui(sfRenderWindow *window, player_t *player)
{
    draw_sprite(window, player->gui->box);
    draw_text(window, player->gui->name);
    draw_text(window, player->gui->level);
    draw_text(window, player->gui->hp);
    draw_text(window, player->gui->mp);

    sfRenderWindow_drawRectangleShape(window, player->gui->hp_bar, 0);
}