/*
** EPITECH PROJECT, 2020
** intro_screen
** File description:
** intro_screen function
*/

#ifndef DEFENDER_INTRO_SCREEN_H
#define DEFENDER_INTRO_SCREEN_H

#include "game/npc.h"
#include "gui/dialog.h"
#include "lib/components/anim_sprite.h"
#include "game.h"

typedef struct intro_screen_s {
    long int delta;
    dialog_t *dialog;
    npc_t **npc;
} intro_screen_t;

void intro_screen(game_t *game, long int delta);
void destroy_intro_screen(game_t *game, intro_screen_t *screen);
int init_intro_screen(game_t *game, intro_screen_t *screen);
int input_intro_screen(game_t *game, intro_screen_t *screen);
int update_intro_screen(game_t *game, intro_screen_t *screen, long int delta);
int render_intro_screen(game_t *game, intro_screen_t *screen, long int delta);

#endif