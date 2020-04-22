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

int init_overworld_map(overworld_t *overworld)
{
    overworld->map = malloc(sizeof(map_t));
    char *fd = create_file_buffer(overworld->maps[overworld->current_map]);
    if (fd[0] == 'E' && str_len(fd) == 1)
        return (84);
    char *layers_str = get_key_data(fd, "layers");
    char **layers = get_value_tab(layers_str, 3);
    char **tiles_layers = get_layers_by_ids((int []){1, 0}, layers);
    int ***tiles_tab = construct_map_tab_from_layers(tiles_layers);
    char **objs_layers = get_layers_by_ids((int []){4, 0}, layers);
    int ***objs_tab = construct_map_tab_from_layers(objs_layers);
    char **obs_layer = get_layers_by_ids((int []){2, 0}, layers);
    char *obstacles_str = get_key_data(obs_layer[0], "objects");
    char **obs_tab = get_value_tab(obstacles_str, 36);
    overworld->map->tile_set = overworld->tile_sets[overworld->current_map];
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
    free(fd);
    return (0);
}

static void init_maps(overworld_t *world)
{
    char *maps[] = {"first_village.json", "map_one_copy.json", NULL};
    int tab_len = 0;

    for (; maps[tab_len]; tab_len++);
    world->maps = malloc(sizeof(char *) * (tab_len+1));
    world->maps[tab_len] = NULL;
    for (int i = 0; i < tab_len; i++) {
        world->maps[i] = maps[i];
    }
    world->current_map = 0;
}

static void init_tile_sets(overworld_t *world)
{
    char *tile_sets[] = {"assets/tiles/outside.png",
        "assets/sprite/tiles/set_one.png", NULL};
    int tab_len = 0;

    for (; tile_sets[tab_len]; tab_len++);
    world->tile_sets = malloc(sizeof(char *) * (tab_len+1));
    world->tile_sets[tab_len] = NULL;
    for (int i = 0; i < tab_len; i++) {
        world->tile_sets[i] = tile_sets[i];
    }
}

static int init_world_map(game_t *game, overworld_t *world)
{
    init_maps(world);
    init_tile_sets(world);
    if (init_overworld_map(world) == 84)
        return (84);
}

int init_overworld(game_t *game, overworld_t *world)
{
    world->state = create_state(0, 0);
    //sfView_zoom(game->camera, 0.5);
    //init_world_map(game, world);
    return (0);
}