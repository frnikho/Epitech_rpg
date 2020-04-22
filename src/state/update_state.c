/*
** EPITECH PROJECT, 2020
** update_state.c
** File description:
** update state function
*/

#include "state.h"

const list_state_t update_list[] = {{0, update_intro_state}, {-999, 0}};

static void call_list(state_t *state, int code, long int delta)
{
    for (int i = 0; update_list[i].code != 999; i++) {
        if (code == update_list[i].code) {
            update_list[i].init(state, delta);
            return;
        }
    }
}

void update_state(state_t *state, long int delta)
{
    call_list(state, state->code, delta);
    if (state && state->dialog)
        update_dialog(state->dialog, delta);
}