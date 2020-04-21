/*
** EPITECH PROJECT, 2020
** create_state.c
** File description:
** create state function
*/

#include "state.h"

const list_state_t lists[] = {{0, intro_state}, {999, 0}};

static void iterate_lists(state_t *state, int code)
{
    for (int i = 0; lists[i].code != 999; i++) {
        if (code == lists[i].code) {
            lists[i].init(state, 0);
            return;
        }
    }
}

state_t *create_state(int code, int sub_code)
{
    state_t *state = malloc(sizeof(state_t));
    state->code = code;
    state->sub_code = sub_code;
    iterate_lists(state, code);
    return (state);
}