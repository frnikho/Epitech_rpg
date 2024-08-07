/*
** EPITECH PROJECT, 2020
** update_state.c
** File description:
** update state function
*/

#include "state.h"

const list_state_t update_list[] = {{0, update_intro_state}, \
{100, update_world_state}, {-999, 0}};

static void call_list(state_t *state, game_t *game, int code, long int delta)
{
    for (int i = 0; update_list[i].code != 999; i++) {
        if (code == update_list[i].code) {
            update_list[i].init(state, game, delta);
            return;
        }
    }
}

void update_npcs_dialogs(state_t *state, long int delta)
{
    for (int i = 0; state->npcs[i]; i++)
        update_dialog(state->npcs[i]->dialog, delta);
}

void update_state(state_t *state, game_t *game, long int delta)
{
    call_list(state, game, state->code, delta);
    if (state->dialog)
        update_dialog(state->dialog, delta);
}