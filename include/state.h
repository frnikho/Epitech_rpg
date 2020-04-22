/*
** EPITECH PROJECT, 2020
** state.h
** File description:
** state function
*/

#ifndef MY_RPG_STATE_H
#define MY_RPG_STATE_H

#include <gui/dialog.h>
#include "lib/effects/fade.h"
#include "game/npc.h"
#include "game.h"

typedef struct state_s {
    long int delta;
    int code;
    int sub_code;

    fade_t *fade_in;
    fade_t *fade_out;
    npc_t **npcs;
    dialog_t *dialog;
} state_t;

typedef struct list_state_s {
    int code;
    void (*init)(state_t *state, long int delta);
} list_state_t;

void update_state(state_t *state, long int delta);
state_t *create_state(int code, int sub_code);
void draw_state(sfView *camera, sfRenderWindow *window, state_t *state);
void set_dialog_scale(dialog_t *dialog, float scale);

void intro_state(state_t *state, long int delta);
void update_intro_state(state_t *state, long int delta);

#endif
