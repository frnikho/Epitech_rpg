/*
** EPITECH PROJECT, 2020
** end_screen
** File description:
** end_screen function
*/

#ifndef DEFENDER_end_SCREEN_H
#define DEFENDER_end_SCREEN_H

#include "game/npc.h"
#include "gui/dialog.h"
#include "lib/components/anim_sprite.h"
#include "game.h"

typedef struct end_screen_s {
    long int delta;
    sprite_t *bg;
    text_t *text;
} end_screen_t;

void end_screen(game_t *game, long int delta);
void destroy_end_screen(game_t *game, end_screen_t *screen);
int init_end_screen(game_t *game, end_screen_t *screen);
int input_end_screen(game_t *game, end_screen_t *screen);
int update_end_screen(game_t *game, end_screen_t *screen, long int delta);
int render_end_screen(game_t *game, end_screen_t *screen, long int delta);

#endif