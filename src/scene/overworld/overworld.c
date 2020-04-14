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
    init_overworld(game, overworld);
    return (overworld);
}

static void update(game_t *game, overworld_t *overworld, long int delta)
{
    int coeff = 5;
    sfVector2f prev_offset = overworld->map->offset;

    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed) {
            destroy_overworld(game, overworld);
            sfRenderWindow_close(game->window);
            return;
        }
        if (game->event.type == sfEvtKeyPressed) {
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
                default:
                    break;
            }
            if (check_collisions_ahead(overworld->map, game->player) == 1)
                overworld->map->offset = prev_offset;
        }
    }
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
    update(game, overworld, delta);
}