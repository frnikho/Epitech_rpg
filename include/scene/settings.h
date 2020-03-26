/*
** EPITECH PROJECT, 2020
** settings.h
** File description:
**  function
*/

#ifndef MY_RPG_SETTINGS_H
#define MY_RPG_SETTINGS_H

#include <lib/components/text.h>
#include <gui/dialog.h>
#include <lib/effects/fade.h>
#include "game.h"
#include "lib/components/sprite.h"
#include "lib/components/anim_sprite.h"

#define SELECT_FRAME_30 0
#define SELECT_FRAME_50 1
#define SELECT_FRAME_60 2
#define SELECT_FRAME_144 3
#define SELECT_FRAME_240 4
#define SELECT_DIALOG_1 5
#define SELECT_DIALOG_2 6
#define SELECT_DIALOG_3 7
#define SELECT_QUIT 8

typedef struct settings_screen_s {
    long int delta;
    int select_cursor;
    sprite_t *cursor;
    sprite_t *box;
    sprite_t *bg;
    text_t *text;
    text_t *title;
    text_t *current_frame;
    text_t *current_dialog;
    text_t *quit;
    dialog_t*dialog;
    fade_t *fade;
} settings_screen_t;

void settings_screen(game_t *game, long int delta);
void dispose_settings_screen(settings_screen_t *settings);
int init_settings_screen(game_t *game, settings_screen_t *settings);
int input_settings_screen(game_t *game, settings_screen_t *settings);
int render_settings_screen(game_t *game, settings_screen_t *s, long int delta);
int update_settings_screen(game_t *game, settings_screen_t *s, long int delta);

#endif