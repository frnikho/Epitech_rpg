/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** load_map_dependencies
*/

#include <lib/utils/file.h>
#include "game.h"
#include "game/map.h"
#include "scene/overworld.h"
#include "lib/utils/json_parser.h"
#include "lib/utils/string.h"

void load_interaction_boxes(map_setup_t *setup, map_t *map, overworld_t *world)
{
    int tab_len = 0;
    int i = 0;

    for (tab_len = 0; setup->interaction_boxes_indexs[tab_len]; tab_len++);
    map->interaction_boxes = malloc(sizeof(interaction_box_t *) * (tab_len+1));
    for (i = 0; setup->interaction_boxes_indexs[i]; i++) {
        map->interaction_boxes[i] = \
        world->maps_interaction_boxes[setup->interaction_boxes_indexs[i]-1];
    }
    map->interaction_boxes[i] = NULL;
}

void load_setup_in_map(overworld_t *overworld, \
int ***tiles_tab, int ***objs_tab, char **obs_tab)
{
    overworld->map->tile_set = overworld->\
    maps[overworld->current_map]->tile_set;
    overworld->map->tile_size = overworld->\
    maps[overworld->current_map]->tile_size;
    overworld->map->offset = overworld->maps[overworld->current_map]->offset;
    overworld->map->zoom = overworld->maps[overworld->current_map]->zoom;
    overworld->obs_tab = obs_tab;
    overworld->objs_tab = objs_tab;
    overworld->tiles_tab = tiles_tab;
}

int ***create_tiles_tab(overworld_t *overworld, char **layers)
{
    char **tiles_layers = get_layers_by_ids(overworld->\
    maps[overworld->current_map]->tile_layers_id, layers);
    int ***tiles_tab = construct_map_tab_from_layers(tiles_layers);

    free(tiles_layers);
    return (tiles_tab);
}

int ***create_objs_tab(overworld_t *overworld, char **layers)
{
    char **objs_layers = get_layers_by_ids(overworld->\
    maps[overworld->current_map]->objs_layers_id, layers);
    int ***objs_tab = construct_map_tab_from_layers(objs_layers);

    free(objs_layers);
    return (objs_tab);
}

char **create_obs_tab(overworld_t *overworld, char **layers)
{
    char **obs_layer = get_layers_by_ids(overworld->\
    maps[overworld->current_map]->obs_layers_id, layers);
    char *obstacles_str = get_key_data(obs_layer[0], "objects");
    char **obs_tab = get_value_tab(obstacles_str, \
    overworld->maps[overworld->current_map]->obs_nb);

    free(obstacles_str);
    free(obs_layer);
    return (obs_tab);
}