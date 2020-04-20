/*
** EPITECH PROJECT, 2020
** state.h
** File description:
** state function
*/

#ifndef MY_RPG_STATE_H
#define MY_RPG_STATE_H

#include "game/npc.h"
#include "game.h"

typedef struct state_s {
    long int delta;
    int code;
    int sub_code;
    npc_t **npcs;
} state_t;

typedef struct list_state_s {
    int code;
    void (*init)(state_t *state, long int delta);
} list_state_t;

void update_state(state_t *state, long int delta);
state_t *create_state(int code, int sub_code);
void draw_state(sfRenderWindow *window, state_t *state);

void intro_state(state_t *state, long int delta);
void update_intro_state(state_t *state, long int delta);

#endif
