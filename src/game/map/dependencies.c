/*
** EPITECH PROJECT, 2020
** map_parser
** File description:
** dependencies
*/

#include "game/map.h"

int get_tab_width(int **tab)
{
    int result = 0;

    for (; tab[result]; result++);
    return (result);
}

int get_tab_height(int **tab)
{
    int result = 0;

    for (; tab[0][result]; result++);
    return (result);
}

void center_on_map_coord(map_t *map, sfRenderWindow *window, sfVector2f center)
{
    map->offset.x = (1600 / 2) - \
    ((center.x* map->zoom) / 2);
    map->offset.y = (800 / 2) - \
    ((center.y* map->zoom) / 2);
}