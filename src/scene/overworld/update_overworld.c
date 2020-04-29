/*
** EPITECH PROJECT, 2020
** update_overworld.c
** File description:
** update overworld function
*/

#include "game.h"
#include "scene/overworld.h"

static void update_map_world(game_t *game, overworld_t *world, long int delta)
{
    npc_t **npcs = world->npcs;
    block_move_on_collision(game->player, npcs, delta, world);
}

static void update_npcs(npc_t **npcs, long int delta)
{
    for (int i = 0; npcs[i]; i++) {
        update_dialog(npcs[i]->dialog, delta);
    }
}

int update_overworld(game_t *game, overworld_t *world, long int delta)
{
    printf("player pos: %1.0f - %1.0f\n", get_player_position(game->player).x, get_player_position(game->player).y);
    update_map_world(game, world, delta);
    update_state(world->state, game, delta);
    update_player(game->player, delta);
    update_npcs(world->npcs, delta);
    if (game->player->inventory->is_open)
        return (0);
    move_player(game->player, world->state->npcs, delta);
    if (game->player->fight) {
        game->current_state = BATTLE;
        return (0);
    }
    sfView_setCenter(game->camera, get_player_position(game->player));
    sfRenderWindow_setView(game->window, game->camera);
    return (0);
}