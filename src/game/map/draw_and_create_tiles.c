/*
** EPITECH PROJECT, 2020
** map_parser
** File description:
** create_tiles
*/

#include "game/map.h"

void draw_single_tile(tile_layer_t *layer, sfRenderWindow *window, int i, int y)
{
    sfVector2f *points = NULL;

    if (layer->tiles_map[y][i] == -1)
        return;
    points = is_tile_displayed(layer, i, y);
    if (is_square_in_window(window, points) == 0) {
        free(points);
        return;
    }
    sfConvexShape_setPoint(layer->tile_shape, 0, points[0]);
    sfConvexShape_setPoint(layer->tile_shape, 1, points[1]);
    sfConvexShape_setPoint(layer->tile_shape, 2, points[2]);
    sfConvexShape_setPoint(layer->tile_shape, 3, points[3]);
    sfConvexShape_setTexture(layer->tile_shape, \
    layer->tiles[map_tile_id(layer->tiles_map[y][i])], sfTrue);
    sfRenderWindow_drawConvexShape(window, layer->tile_shape, NULL);
    free(points);
}

void draw_tile_layer(tile_layer_t *layer, sfRenderWindow *window)
{
    for (int y = 0; y < layer->height; y++) {
        for (int i = 0; i < layer->width; i++) {
            draw_single_tile(layer, window, i, y);
        }
    }
}

void draw_tiles(map_t *map, sfRenderWindow *window, int *layers_to_print)
{
    for (int i = 0; map->tile_layers[i]; i++) {
        if (layers_to_print[0] == 0) {
            draw_tile_layer(map->tile_layers[i], window);
            continue;
        }
        for (int y = 0; layers_to_print[y]; y++) {
            i == (layers_to_print[y]-1) ? \
        draw_tile_layer(map->tile_layers[i], window) : 0;
        }
    }
}

tile_layer_t *init_tile_layer(int **tiles_map)
{
    tile_layer_t *layer = malloc(sizeof(tile_layer_t));

    layer->tiles = create_tiles();
    layer->width = get_tab_width(tiles_map);
    layer->height = get_tab_height(tiles_map);
    layer->tile_size = 32;
    layer->tile_shape = sfConvexShape_create();
    sfConvexShape_setPointCount(layer->tile_shape, 4);
    layer->tiles_map = tiles_map;
    layer->zoom = 1;
    layer->offset = (sfVector2f){0, 0};
    return (layer);
}

void create_tile_tab(map_t *map, int ***layers_tab)
{
    int tab_len = 0;

    for (; layers_tab[tab_len]; tab_len++);
    map->tile_layers = malloc(sizeof(tile_layer_t*) * (tab_len+1));
    map->tile_layers[tab_len] = NULL;
    for (int i = 0; layers_tab[i]; i++)
        map->tile_layers[i] = init_tile_layer(layers_tab[i]);
}