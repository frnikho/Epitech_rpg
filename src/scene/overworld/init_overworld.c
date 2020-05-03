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

static void free_map_parser_buffer(char ***layers, \
char **layers_str, char **fd)
{
    free_tab((*layers));
    free((*layers_str));
    free((*fd));
}

int init_overworld_map(overworld_t *overworld)
{
    overworld->map = malloc(sizeof(map_t));
    char *fd = create_file_buffer(overworld->\
    maps[overworld->current_map]->file);
    if (fd[0] == 'E' && str_len(fd) == 1)
        return (84);
    char *layers_str = get_key_data(fd, "layers");
    char **layers = get_value_tab(layers_str, \
    overworld->maps[overworld->current_map]->layer_nb);
    int ***tiles_tab = create_tiles_tab(overworld, layers);
    int ***objs_tab = create_objs_tab(overworld, layers);
    char **obs_tab = create_obs_tab(overworld, layers);
    load_setup_in_map(overworld, tiles_tab, objs_tab, obs_tab);
    init_map(overworld->map, tiles_tab, objs_tab, obs_tab);
    load_interaction_boxes(overworld->maps[overworld->current_map], \
    overworld->map, overworld);
    overworld->npcs = get_town_npcs(overworld->\
    maps[overworld->current_map]->location);
    free_map_parser_buffer(&layers, &layers_str, &fd);
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

    world->current_map = 0;
    init_world_map(game, world);
    world->state = create_state(100, game, 0);
    world->pause = create_pause(game->window, game->camera);
    game->player->in_teleportation = 0;
    return (0);
}