/*
** EPITECH PROJECT, 2020
** map_parser
** File description:
** global_map_updates
*/

#include "game/map.h"

void destroy_and_free_map(map_t *map)
{
    for (int i = 0; map->tile_layers[i]; i++)
        destroy_and_free_tile_layer(map->tile_layers[i]);
    free(map->tile_layers);
    for (int i = 0; map->obj_layers[i]; i++)
        destroy_and_free_object_layer(map->obj_layers[i]);
    free(map->obj_layers);
    destroy_and_free_obstacles(map->obs);
}

void draw_map(map_t *map, sfRenderWindow *window, int *layers_to_print_tiles, \
int *layers_to_print_objs)
{
    draw_tiles(map, window, layers_to_print_tiles);
    draw_objects(map, window, layers_to_print_objs);
    //draw_obstacles(map, window);
}

void init_map(map_t *map, int ***tiles_tab, int ***objs_tab, char **obs_tab)
{
    create_tile_tab(map, tiles_tab, map->tile_set);
    create_object_tab(map, objs_tab);
    create_obtacles_tab(obs_tab, map);
    map->offset = (sfVector2f){0, 0};
    map->zoom = 1;
}

void update_zoom_and_offset(map_t *map)
{
    for (int i = 0; map->tile_layers[i]; i++) {
        map->tile_layers[i]->zoom = map->zoom;
        map->tile_layers[i]->offset.x = map->offset.x;
        map->tile_layers[i]->offset.y = map->offset.y;
    }
    for (int i = 0; map->obj_layers[i]; i++) {
        map->obj_layers[i]->zoom = map->zoom;
        map->obj_layers[i]->offset.x = map->offset.x;
        map->obj_layers[i]->offset.y = map->offset.y;
    }
}