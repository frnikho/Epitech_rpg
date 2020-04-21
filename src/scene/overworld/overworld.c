/*
** EPITECH PROJECT, 2020
** overworld.c
** File description:
** overworld function
*/

#include "game.h"
#include "scene/overworld.h"
#include "lib/utils/json_parser.h"

static overworld_t *init(game_t *game)
{
    overworld_t *overworld = malloc(sizeof(overworld_t));
    if (init_overworld(game, overworld) == 84)
        return (NULL);
    return (overworld);
}

static void overworld_offset(game_t *game, overworld_t *overworld, int coeff)
{
    switch (game->event.key.code) {
    case (sfKeyRight):
        overworld->map->offset.x -= coeff*overworld->map->zoom;
        break;
    case (sfKeyLeft):
        overworld->map->offset.x += coeff*overworld->map->zoom;
        break;
    case (sfKeyUp):
        overworld->map->offset.y += coeff*overworld->map->zoom;
        break;
    case (sfKeyDown):
        overworld->map->offset.y -= coeff*overworld->map->zoom;
        break;
    case (sfKeyZ):
        overworld->map->zoom += 0.1;
        break;
    case (sfKeyA):
        overworld->map->zoom -= 0.1;
    }
}

static void update(game_t *game, overworld_t *overworld, long int delta)
{
    static int map_act = -1;

    if (overworld->current_map != map_act && map_act != -1) {
        destroy_overworld(game, overworld);
        if (init_overworld_map(overworld) == 84) {
            sfRenderWindow_close(game->window);
            return;
        }
    }
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed) {
            destroy_overworld(game, overworld);
            sfRenderWindow_close(game->window);
            return;
        }
    }
    map_act = overworld->current_map;
    update_overworld(game, overworld, delta);
    render_overworld(game, overworld, delta);
}

void destroy_overworld(game_t *game, overworld_t *overworld)
{
    destroy_and_free_map(overworld->map);
    free(overworld->map);
    free_tab(overworld->obs_tab);
    free_double_tab(overworld->tiles_tab);
    free_double_tab(overworld->objs_tab);
}

void overworld(game_t *game, long int delta)
{
    static overworld_t *overworld;

    if (!overworld)
        overworld = init(game);
    if (overworld == NULL) {
        sfRenderWindow_close(game->window);
        return;
    }
    update(game, overworld, delta);
}