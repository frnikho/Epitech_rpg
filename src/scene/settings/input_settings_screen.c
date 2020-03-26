/*
** EPITECH PROJECT, 2020
** input_settings_screen.c
** File description:
**  function
*/

#include "game.h"
#include "scene/settings.h"

static int handle_selection(game_t *game, settings_screen_t *settings)
{
    if (game->event.key.code == sfKeyZ)
        settings->select_cursor = 0;
    if (game->event.key.code == sfKeyS)
        settings->select_cursor = 5;
    if (game->event.key.code == sfKeyQ)
        settings->select_cursor--;
    if (game->event.key.code == sfKeyD)
        settings->select_cursor++;
}

int input_settings_screen(game_t *game, settings_screen_t *settings)
{
    if (game->event.type == sfEvtKeyPressed) {

    }
}