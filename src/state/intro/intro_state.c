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
    state->fade_in = init_fade((sfVector2f){1600*10, 800*10}, \
sfBlack, 1, FADE_IN);
    set_fade_active(state->fade_in);
    game->player->can_move = 0;
    state->npcs = malloc(sizeof(npc_t*) * 6);
    state->npcs[0] = create_npc("content/npc/musclor.json", \
(sfVector2f){400, 300}, 1);
    state->npcs[1] = create_npc("content/npc/sister.json", \
(sfVector2f){600, 800}, 1);
    state->npcs[2] = 0;
    set_player_position(game->player, (sfVector2f) {});
    set_player_position(game->player, (sfVector2f) {543, 300});
}

static void sub_one(state_t *state, game_t *game, long int delta, long int d)
{
    if (state->sub_code == 0) {
        update_fade(state->fade_in, delta);
    }
    if (state->sub_code == 0 && fade_is_finish(state->fade_in))
        state->sub_code++;
    if (state->sub_code == 1 && delta) {
        state->sub_code++;
        move_npc(state->npcs[0], (sfVector2f){500, 300});
    }
    if (state->sub_code == 2 && d >= 400000) {
        state->sub_code++;
        char **msg = get_dialog("history_begin");
        state->dialog = create_dialog(msg, 1, (sfVector2f)GUI_POS, 1);
        set_dialog_active(state->dialog, 1);
    }
    if (state->sub_code == 3 && state->dialog->is_finished) {
        move_npc(state->npcs[0], (sfVector2f){331, 196});
        state->sub_code++;
        game->player->can_move = 1;
    }
}

void update_intro_state(state_t *state, game_t *game, long int delta)
{
    static long int d = 0;
    d += delta;
    sub_one(state, game, delta, d);
    if (state->sub_code == 4) {
        if (state->npcs[0]->finish_move) {
            state->npcs[0]->current_animations = 0;
        }
    }
}