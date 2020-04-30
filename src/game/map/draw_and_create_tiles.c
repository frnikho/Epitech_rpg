/*
** EPITECH PROJECT, 2020
** map_parser
** File description:
** create_tiles
*/

#include "game/map.h"

void draw_single_tile(tile_layer_t *layer, sfRenderWindow *window, \
sfFloatRect rect, int *coords)
{
    sfVector2f *points = NULL;

    if (layer->tiles_map[coords[1]][coords[0]] == -1)
        return;
    points = is_tile_displayed(layer, coords[0], coords[1]);

    if (is_square_in_window(rect, points) == 0) {
        free(points);
        return;
    }
    sfSprite_setPosition(layer->tiles[layer->\
tiles_map[coords[1]][coords[0]]-1], points[0]);
    sfSprite_setScale(layer->tiles[layer->tiles_map[coords[1]][coords[0]]-1], \
(sfVector2f){layer->zoom, layer->zoom});
    /*sfConvexShape_setPoint(layer->tile_shape, 0, points[0]);
    sfConvexShape_setPoint(layer->tile_shape, 1, points[1]);
    sfConvexShape_setPoint(layer->tile_shape, 2, points[2]);
    sfConvexShape_setPoint(layer->tile_shape, 3, points[3]);
    sfConvexShape_setTexture(layer->tile_shape, \
    layer->tiles[layer->tiles_map[coords[1]][coords[0]]-1], sfTrue); */
    sfRenderWindow_drawSprite(window, layer->tiles[layer->\
tiles_map[coords[1]][coords[0]]-1], 0);
    //sfRenderWindow_drawConvexShape(window, layer->tile_shape, NULL);
    free(points);
}

void draw_tile_layer(tile_layer_t *layer, sfRenderWindow *window, \
sfFloatRect rect)
{
    for (int y = 0; y < layer->height; y++) {
        for (int i = 0; i < layer->width; i++) {
            draw_single_tile(layer, window, rect, (int []){i, y});
        }
    }
}

void draw_tiles(map_t *map, sfRenderWindow *window, \
int *layers_to_print, sfView *camera)
{
    sfVector2i min_p = {0, 0};
    sfVector2i max_p = {1600, 800};
    sfVector2f min = sfRenderWindow_mapPixelToCoords(window, min_p, camera);
    sfVector2f max = sfRenderWindow_mapPixelToCoords(window, max_p, camera);
    sfFloatRect rect = {min.x, min.y, max.x, max.y};

    for (int i = 0; map->tile_layers[i]; i++) {
        if (layers_to_print[0] == 0) {
            draw_tile_layer(map->tile_layers[i], window, rect);
            continue;
        }
        for (int y = 0; layers_to_print[y]; y++) {
            i == (layers_to_print[y]-1) ? \
        draw_tile_layer(map->tile_layers[i], window, rect) : 0;
        }
    }
}

tile_layer_t *init_tile_layer(int **tiles_map, char *tile_set, int tile_size)
{
    tile_layer_t *layer = malloc(sizeof(tile_layer_t));

    layer->tiles = create_tiles(tile_set, tile_size);
    layer->width = get_tab_width(tiles_map);
    layer->height = get_tab_height(tiles_map);
    layer->tile_size = tile_size;
    layer->tile_shape = sfConvexShape_create();
    sfConvexShape_setPointCount(layer->tile_shape, 4);
    layer->tiles_map = tiles_map;
    layer->zoom = 1;
    layer->offset = (sfVector2f){0, 0};
    return (layer);
}

void create_tile_tab(map_t *map, int ***layers_tab, char *tile_set)
{
    int tab_len = 0;

    for (; layers_tab[tab_len]; tab_len++);
    map->tile_layers = malloc(sizeof(tile_layer_t*) * (tab_len+1));
    map->tile_layers[tab_len] = NULL;
    for (int i = 0; layers_tab[i]; i++) {
        map->tile_layers[i] = init_tile_layer(layers_tab[i], tile_set, \
        map->tile_size);
    }
}