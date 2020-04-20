/*
** EPITECH PROJECT, 2020
** update_state.c
** File description:
** update state function
*/

#include "state.h"

const list_state_t updateList[] = {{0, update_intro_state}, {-999, 0}};

static void iterateLists(state_t  *state, int code)
{
    for (int i = 0; updateList[i].code != 999; i++) {
        if (code == updateList[i].code) {
            updateList[i].init(state, 0);
            return;
        }
    }
}

void update_state(state_t *state, long int delta)
{
    iterateLists(state, state->code);
}