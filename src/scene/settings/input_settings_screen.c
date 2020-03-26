/*
** EPITECH PROJECT, 2020
** input_settings_screen.c
** File description:
**  function
*/

#include "game.h"
#include "scene/settings.h"

static void handle_click_dialog(game_t *game, settings_screen_t *settings)
{
    switch (settings->select_cursor) {
        case SELECT_DIALOG_1:
            game->config.dialog_speed = 1;
            break;
        case SELECT_DIALOG_2:
            break;
        case SELECT_DIALOG_3:
            break;
    }
}

static void handle_click_frame(game_t *game, settings_screen_t *settings)
{
    switch (settings->select_cursor) {
        case SELECT_DIALOG_1:
            break;
    }
}

static int handle_selection(game_t *game, settings_screen_t *settings)
{
    sfKeyEvent key = game->event.key;
    if (key.code == sfKeyZ)
        settings->select_cursor = 0;
    if (key.code == sfKeyS)
        settings->select_cursor = 5;
    if (key.code == sfKeyQ)
        settings->select_cursor--;
    if (key.code == sfKeyD)
        settings->select_cursor++;
    if (key.code == sfKeyEnter || key.code == sfKeySpace) {
        handle_click_dialog(game, settings);
        handle_click_frame(game, settings);
    }
}

int input_settings_screen(game_t *game, settings_screen_t *settings)
{
    if (game->event.type == sfEvtKeyPressed)
        handle_selection(game, settings);
}