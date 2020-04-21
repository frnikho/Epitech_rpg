/*
** EPITECH PROJECT, 2020
** intro_state.c
** File description:
** intro function
*/

#include "state.h"

void intro_state(state_t *state, long int delta)
{
    state->npcs = get_town_npcs("topaze");
}

void update_intro_state(state_t *state, long int delta)
{
}