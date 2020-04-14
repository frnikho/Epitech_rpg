/*
** EPITECH PROJECT, 2020
** init_overworld.c
** File description:
** init overworld function
*/

#include "game.h"
#include "game/map.h"
#include "scene/overworld.h"
#include "lib/utils/json_parser.h"
#include "lib/utils/string.h"

int init_overworld(game_t *game, overworld_t *overworld)
{
    overworld->map = malloc(sizeof(map_t));

    char *file_data = create_file_buffer("map_one.json");

    if (file_data[0] == 'E' && str_len(file_data) == 1)
        return (84);

    char *layers_str = get_key_data(file_data, "layers");
    char **layers = get_value_tab(layers_str, 4);

    char **tiles_layers = get_layers_by_ids((int []){1, 2, 0}, layers);
    int ***tiles_tab = construct_map_tab_from_layers(tiles_layers);
    
    char **objs_layers = get_layers_by_ids((int []){4, 0}, layers);
    int ***objs_tab = construct_map_tab_from_layers(objs_layers);

    char **obs_layer = get_layers_by_ids((int []){3, 0}, layers);
    char *obstacles_str = get_key_data(obs_layer[0], "objects");
    char **obs_tab = get_value_tab(obstacles_str, 4);

    init_map(overworld->map, tiles_tab, objs_tab, obs_tab);

    overworld->obs_tab = obs_tab;
    overworld->objs_tab = objs_tab;
    overworld->tiles_tab = tiles_tab;

    free(obstacles_str);
    free_tab(obs_layer);
    free_tab(objs_layers);
    free_tab(tiles_layers);
    free_tab(layers);
    free(layers_str);
    free(file_data);
}