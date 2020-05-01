/*
** EPITECH PROJECT, 2020
** create_state.c
** File description:
** create state function
*/

#include "state.h"

const list_state_t lists[] = {{0, intro_state}, {100, world_state}, {999, 0}};

static void iterate_lists(state_t *state, game_t *game, int code)
{
    for (int i = 0; lists[i].code != 999; i++) {
        if (code == lists[i].code) {
            lists[i].init(state, game, 0);
            return;
        }
    }
}

state_t *create_state(int code, game_t *game, int sub_code)
{
    state_t *state = malloc(sizeof(state_t));
    state->code = code;
    state->music = 0;
    state->sub_code = sub_code;
    state->dialog = 0;
    state->npcs = 0;
    state->delta = 0;
    state->fade_out = 0;
    state->fade_in = 0;
    state->npcs = malloc(sizeof(npc_t *));
    state->npcs[0] = NULL;
    iterate_lists(state, game, code);
    return (state);
}