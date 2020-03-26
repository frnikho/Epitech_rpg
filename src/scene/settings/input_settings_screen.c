/*
** EPITECH PROJECT, 2020
** input_settings_screen.c
** File description:
**  function
*/

#include <lib/utils/string.h>
#include "game.h"
#include "scene/settings.h"

static void update_and_quit(game_t *game, settings_screen_t *settings)
{
    static int is_active = 0;

    if (settings->select_cursor == SELECT_QUIT && !is_active) {
        set_dialog_active(settings->dialog, sfTrue);
        is_active = 1;
    }
}

static void handle_click_dialog(game_t *game, settings_screen_t *settings)
{
    switch (settings->select_cursor) {
    case SELECT_DIALOG_1:
        game->config.dialog_speed = 1;
        break;
    case SELECT_DIALOG_2:
        game->config.dialog_speed = 2;
        break;
    case SELECT_DIALOG_3:
        game->config.dialog_speed = 3;
        break;
    }
    char *cf = str_cat("* ", convert_str(game->config.dialog_speed));
    settings->current_dialog->title = cf;
}

static void handle_click_frame(game_t *game, settings_screen_t *settings)
{
    switch (settings->select_cursor) {
    case SELECT_FRAME_30:
        game->config.framerate = 30;
        break;
    case SELECT_FRAME_50:
        game->config.framerate = 50;
        break;
    case SELECT_FRAME_60:
        game->config.framerate = 60;
        break;
    case SELECT_FRAME_144:
        game->config.framerate = 144;
        break;
    case SELECT_FRAME_240:
        game->config.framerate = 240;
        break;
    }
    char *cf = str_cat("* ", convert_str(game->config.framerate));
    settings->current_frame->title = cf;
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
        update_and_quit(game, settings);
    }
}

int input_settings_screen(game_t *game, settings_screen_t *settings)
{
    if (game->event.type == sfEvtKeyPressed) {
        if (settings->dialog->is_active) {
            update_dialog_line(settings->dialog);
        }
        handle_selection(game, settings);
    }
}