/*
** EPITECH PROJECT, 2020
** intro_state.c
** File description:
** intro function
*/

#include <lib/utils/file.h>
#include "state.h"

void intro_state(state_t *state, game_t *game, long int delta)
{
    state->fade_in = init_fade((sfVector2f){1600, 800}, sfBlack, 1, FADE_IN);
    set_fade_active(state->fade_in);
    game->player->can_move = 1;
    state->npcs = malloc(sizeof(npc_t*) * 6);
    state->npcs[0] = create_npc("content/npc/musclor.json", (sfVector2f){20, 30}, 1, "topaze_king");
    state->npcs[1] = 0;
}

void update_intro_state(state_t *state, game_t *game, long int delta)
{
    static long int d = 0;
    if (state->sub_code == 0) {
        update_fade(state->fade_in, delta);
    }
    if (state->sub_code == 0 && fade_is_finish(state->fade_in))
        state->sub_code++;
    d += delta;
    if (state->sub_code == 1 && delta) {
        state->sub_code++;
        //char **tmp = get_dialog("topaze_king");
        //update_npc(state->npcs[0], delta);
        //state->dialog = create_dialog(tmp, 1, (sfVector2f){0, 0}, 1);
        //set_dialog_active(state->dialog, 1);
    }
}