/*
** EPITECH PROJECT, 2020
** render_overworld.c
** File description:
** render overworld function
*/

#include "game.h"
#include "scene/overworld.h"

void draw_rectangle(sfFloatRect *rec, sfRenderWindow *window)
{
    sfRectangleShape *shape = sfRectangleShape_create();
    sfRectangleShape_setSize(shape, (sfVector2f){rec->width, rec->height});
    sfRectangleShape_setPosition(shape, (sfVector2f){rec->left, rec->top});
    sfRectangleShape_setFillColor(shape, sfColor_fromRGBA(172, 0, 230, 255));
    sfRenderWindow_drawRectangleShape(window, shape, NULL);
    sfRectangleShape_destroy(shape);
}

int render_overworld(game_t *game, overworld_t *overworld, long int delta)
{
    sfRenderWindow_clear(game->window, sfBlack);
    update_zoom_and_offset(overworld->map);
    draw_map(overworld->map, game->window, (int []){0}, (int []){99, 0});
    draw_map(overworld->map, game->window, (int []){99, 0}, (int []){0});
    return (0);
}