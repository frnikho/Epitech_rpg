/*
** EPITECH PROJECT, 2020
** input_overworld.c
** File description:
** input overworld function
*/

#include "game.h"
#include "scene/overworld.h"
#include "gui/dialog.h"

void overworld_key_code(game_t *game)
{
    if (game->event.key.code == sfKeyE)
        open_inventory(game->player->inventory);
    if (game->event.key.code == sfKeyL)
        sfRenderWindow_close(game->window);
}

static void input_pause(game_t *game, pause_gui_t *pause, overworld_t *world)
{
    if (!pause->is_selected)
        return;
    if (pause->cursor_select == 1) {
        game->current_state = MAIN_MENU;
        destroy_overworld(game, world);
    }
}

static int interact_npc(game_t *game, overworld_t *overworld)
{
    if (game->event.key.code == sfKeySpace) {
        if (game->player->interlocutor && game->player->interlocutor->\
        dialog && !game->player->interlocutor->dialog->is_active) {
            clear_dialog(game->player->interlocutor->dialog);
            set_dialog_active(game->player->interlocutor->dialog, 1);
        }
    }
}

int input_overworld(game_t *game, overworld_t *overworld, long int delta)
{
    handle_pause(overworld->pause, game->event);
    handle_inventory(game->event, game->player->inventory);
    if (game->event.type == sfEvtKeyPressed) {
        if (game->event.key.code == sfKeyEscape)
            toggle_pause(overworld->pause);
        overworld_key_code(game);
        if (overworld->state->dialog && overworld->state->dialog->is_active) {
            update_dialog_line(overworld->state->dialog);
        }
        for (int i = 0; overworld->npcs[i]; i++) {
            update_dialog_line(overworld->npcs[i]->dialog);
        }
        interact_npc(game, overworld);
    }
    input_pause(game, overworld->pause, overworld);
    return (0);
}