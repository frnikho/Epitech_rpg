/*
** EPITECH PROJECT, 2020
** init_overworld.c
** File description:
** init overworld function
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

int init_overworld_map(overworld_t *overworld)
{
    overworld->map = malloc(sizeof(map_t));
    char *fd = create_file_buffer(overworld->\
maps[overworld->current_map]->file);
    if (fd[0] == 'E' && str_len(fd) == 1)
        return (84);
    char *layers_str = get_key_data(fd, "layers");
    char **layers = get_value_tab(layers_str, overworld->\
maps[overworld->current_map]->layer_nb);
    char **tiles_layers = get_layers_by_ids(overworld->maps[overworld->\
current_map]->tile_layers_id, layers);
    int ***tiles_tab = construct_map_tab_from_layers(tiles_layers);
    char **objs_layers = get_layers_by_ids(overworld->maps[overworld->\
current_map]->objs_layers_id, layers);
    int ***objs_tab = construct_map_tab_from_layers(objs_layers);
    char **obs_layer = get_layers_by_ids(overworld->maps[overworld->\
current_map]->obs_layers_id, layers);
    char *obstacles_str = get_key_data(obs_layer[0], "objects");
    char **obs_tab = get_value_tab(obstacles_str, overworld->\
maps[overworld->current_map]->obs_nb);
    overworld->map->tile_set = overworld->\
maps[overworld->current_map]->tile_set;
    overworld->map->tile_size = overworld->\
maps[overworld->current_map]->tile_size;
    overworld->map->offset = overworld->maps[overworld->current_map]->offset;
    overworld->map->zoom = overworld->maps[overworld->current_map]->zoom;
    init_map(overworld->map, tiles_tab, objs_tab, obs_tab);
    load_interaction_boxes(overworld->maps[overworld->current_map], \
overworld->map, overworld);
    overworld->obs_tab = obs_tab;
    overworld->objs_tab = objs_tab;
    overworld->tiles_tab = tiles_tab;
    overworld->npcs = get_town_npcs(overworld->\
maps[overworld->current_map]->location);
    free(obstacles_str);
    free_tab(obs_layer);
    free_tab(objs_layers);
    free_tab(tiles_layers);
    free_tab(layers);
    free(layers_str);
    free(fd);
    return (0);
}

void init_interactions_boxes_indexs(map_setup_t *map, int *indexs)
{
    int tab_len = 0;
    int i = 0;

    for (tab_len = 0; indexs[tab_len]; tab_len++);
    map->interaction_boxes_indexs = malloc(sizeof(int) * (tab_len + 1));
    for (i = 0; indexs[i]; i++)
        map->interaction_boxes_indexs[i] = indexs[i];
    map->interaction_boxes_indexs[i] = 0;
}

void init_layers_id(map_setup_t *map, int *tile_ids, \
int *objs_ids, int *obs_ids)
{
    int tab_len = 0;
    int i = 0;

    for (tab_len = 0; tile_ids[tab_len]; tab_len++);
    map->tile_layers_id = malloc(sizeof(int) * (tab_len+1));
    for (i = 0; tile_ids[i]; i++)
        map->tile_layers_id[i] = tile_ids[i];
    map->tile_layers_id[i] = 0;
    for (tab_len = 0; objs_ids[tab_len]; tab_len++);
    map->objs_layers_id = malloc(sizeof(int) * (tab_len+1));
    for (i = 0; objs_ids[i]; i++)
        map->objs_layers_id[i] = objs_ids[i];
    map->objs_layers_id[i] = 0;
    for (tab_len = 0; obs_ids[tab_len]; tab_len++);
    map->obs_layers_id = malloc(sizeof(int) * (tab_len+1));
    for (i = 0; obs_ids[i]; i++)
        map->obs_layers_id[i] = obs_ids[i];
    map->obs_layers_id[i] = 0;
}

void init_maps_interactions(overworld_t *world)
{
    interaction_box_t **inter = malloc(sizeof(interaction_box_t *) * 9);
    init_zone_world(world, inter);
    world->maps_interaction_boxes = inter;
}

void init_maps(overworld_t *world)
{
    map_setup_t **maps = malloc(sizeof(map_setup_t*) * 4);
    if (!maps)
        return;
    maps[0] = malloc(sizeof(map_setup_t));
    maps[0]->file = "assets/maps/topaze.json";
    maps[0]->tile_set = "assets/tiles/outside.png";
    maps[0]->location = "topaze";
    maps[0]->layer_nb = 2;
    maps[0]->obs_nb = 265;
    maps[0]->tile_size = 20;
    maps[0]->offset = (sfVector2f){0, 0};
    maps[0]->zoom = 1.5f;
    init_interactions_boxes_indexs(maps[0], (int []){TOWN_SAFE, \
TOWN_OUT, 0});
    init_layers_id(maps[0], (int []){1, 0}, (int []){0}, (int []){2, 0});
    maps[1] = malloc(sizeof(map_setup_t));
    maps[1]->file = "assets/maps/world.json";
    maps[1]->tile_set = "assets/tiles/world.png";
    maps[1]->location = "default";
    maps[1]->layer_nb = 2;
    maps[1]->obs_nb = 128;
    maps[1]->tile_size = 20;
    maps[1]->offset = (sfVector2f){0, 0};
    maps[1]->zoom = 3.0f;
    init_interactions_boxes_indexs(maps[1], (int []){TOWN_ENTER, \
DUNGEON_ENTER, 0});
    init_layers_id(maps[1], (int []){1, 0}, (int []){0}, (int []){2, 0});

    maps[2] = malloc(sizeof(map_setup_t));
    maps[2]->file = "assets/maps/dungeon.json";
    maps[2]->tile_set = "assets/tiles/inside.png";
    maps[2]->location = "default";
    maps[2]->layer_nb = 2;
    maps[2]->obs_nb = 0;
    maps[2]->tile_size = 20;
    maps[2]->offset = (sfVector2f){0, 0};
    maps[2]->zoom = 2.0f;
    init_interactions_boxes_indexs(maps[2], (int []){DUNGEON_OUT, 0});
    init_layers_id(maps[2], (int []){1, 0}, (int []){0}, (int []){2, 0});

    maps[3] = NULL;
    world->maps = maps;
}

static int init_world_map(game_t *game, overworld_t *world)
{
    init_maps(world);
    init_maps_interactions(world);
    if (init_overworld_map(world) == 84)
        return (84);
}

int init_overworld(game_t *game, overworld_t *world)
{
    int fd = open_file("content/stats.json");
    char *content = read_file(fd, "content/stats.json");
    int code = get_nbr(get_key_data(content, "code"));
    world->state = create_state(code, game, 0);
    world->current_map = 0;
    init_world_map(game, world);
    return (0);
}