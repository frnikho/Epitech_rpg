/*
** EPITECH PROJECT, 2020
** input_overworld.c
** File description:
** input overworld function
*/

#include "game.h"
#include "scene/overworld.h"

int input_overworld(game_t *game, overworld_t *overworld)
{
    handle_inventory(game->event, game->player->inventory);
    if (game->event.type == sfEvtKeyPressed) {
        if (overworld->state->dialog && overworld->state->dialog->is_active) {
            update_dialog_line(overworld->state->dialog);
        }
    }
    return (0);
}