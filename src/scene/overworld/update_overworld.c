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
    npc_t **npcs = world->state->npcs;
    block_move_on_collision(game->player, npcs, delta, world->map->obs);
    sfFloatRect rect = sfSprite_getGlobalBounds(game->player->animations[game->player->current_animations]->sprite);
    //if (rect.top > 150 && rect.left > 150)
    //world->current_map = 1;
}

int update_overworld(game_t *game, overworld_t *world, long int delta)
{
    update_state(world->state, game, delta);
    update_player(game->player, delta);
    if (game->player->inventory->is_open)
        return (0);
    move_player(game->player, world->state->npcs, delta);
    update_map_world(game, world, delta);
    sfView_setCenter(game->camera, get_player_position(game->player));
    sfRenderWindow_setView(game->window, game->camera);
    return (0);
}