/*
** EPITECH PROJECT, 2020
** render_overworld.c
** File description:
** render overworld function
*/

#include "game.h"
#include "scene/overworld.h"


static void render_map_world(game_t *game, overworld_t *world, long int delta)
{
    sfRenderWindow_clear(game->window, sfBlack);
    update_zoom_and_offset(world->map);
    draw_map(world->map, game->window, (int []){0}, (int []){99, 0}, game->camera);
    //draw_map(world->map, game->window, (int []){2, 0}, (int []){99, 0});
}

int render_overworld(game_t *game, overworld_t *world, long int delta)
{
    sfRenderWindow_clear(game->window, sfBlack);
    render_map_world(game, world, delta);
    draw_player(game->window, game->player);
    draw_inventory(game->window, game->camera, game->player->inventory);
    draw_state(game->camera, game->window, world->state);
    return (0);
}