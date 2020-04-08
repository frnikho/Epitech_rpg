/*
** EPITECH PROJECT, 2020
** overworld.c
** File description:
** overworld function
*/

#include "game.h"
#include "scene/overworld.h"

static overworld_t *init(game_t *game)
{
    overworld_t *(overworld) = malloc(sizeof(overworld_t));

    return (overworld);
}

static void update(game_t *game, overworld_t *overworld, long int delta)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed) {
            destroy_overworld(game, overworld);
            sfRenderWindow_close(game->window);
            return;
        }
    }
    update_overworld(game, overworld, delta);
    render_overworld(game, overworld, delta);
}

void destroy_overworld(game_t *game, overworld_t *overworld)
{
}

void overworld(game_t *game, long int delta)
{
    static overworld_t *overworld;
    if (!overworld)
        overworld = init(game);
    update(game, overworld, delta);
}