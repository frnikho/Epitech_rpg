/*
** EPITECH PROJECT, 2020
** world_state.c
** File description:
** world state function
*/

#include "state.h"

void world_state(state_t *state, game_t *game, long int delta)
{
    state->npcs = 0;
    game->player->can_move = 1;
    state->fade_in = init_fade((sfVector2f){1600*10, 800*10}, \
sfBlack, 1, FADE_IN);
    set_fade_active(state->fade_in);
}

void update_world_state(state_t *state, game_t *game, long int delta)
{
    static long int d = 0;
    update_fade(state->fade_in, delta);
    d += delta;
}