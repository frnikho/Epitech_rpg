/*
** EPITECH PROJECT, 2020
** update_overworld.c
** File description:
** update overworld function
*/

#include "game.h"
#include "scene/overworld.h"

int update_overworld(game_t *game, overworld_t *world, long int delta)
{
    update_state(world->state, delta);
    update_player(game->player, delta);
    if (game->player->inventory->is_open)
        return (0);
    if (move_player(game->player, world->state->npcs, delta)) {
        block_move_on_collision(game->player, world->state->npcs, delta);
        sfView_setCenter(game->camera, get_player_position(game->player));
        sfRenderWindow_setView(game->window, game->camera);
    }
    block_move_on_collision(game->player, world->state->npcs, delta);
}