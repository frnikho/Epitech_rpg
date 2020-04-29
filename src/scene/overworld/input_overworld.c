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
    if (game->event.key.code == sfKeyE) {
        open_inventory(game->player->inventory);
    }
    if (game->event.key.code == sfKeyL) {
        sfRenderWindow_close(game->window);
    }
}

int input_overworld(game_t *game, overworld_t *overworld)
{
    handle_inventory(game->event, game->player->inventory);
    if (game->event.type == sfEvtKeyPressed) {
        overworld_key_code(game);
        if (overworld->state->dialog && overworld->state->dialog->is_active) {
            update_dialog_line(overworld->state->dialog);
        }
        for (int i = 0; overworld->npcs[i]; i++) {
            update_dialog_line(overworld->npcs[i]->dialog);
        }
        if (game->event.key.code == sfKeySpace) {
            if (game->player->interlocutor && game->player->interlocutor->dialog && !game->player->interlocutor->dialog->is_active) {
                clear_dialog(game->player->interlocutor->dialog);
                set_dialog_active(game->player->interlocutor->dialog, 1);
            }
        }
    }
    return (0);
}