/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_different_maps
*/

#include <lib/utils/file.h>
#include "game.h"
#include "game/map.h"
#include "scene/overworld.h"
#include "lib/utils/json_parser.h"
#include "lib/utils/string.h"

void init_maps_interactions(overworld_t *world)
{
    interaction_box_t **inter = malloc(sizeof(interaction_box_t *)*(END + 1));
    init_zone_world(world, inter);
    world->maps_interaction_boxes = inter;
}

static void create_topaze_map(map_setup_t **maps)
{
    maps[0] = malloc(sizeof(map_setup_t));
    maps[0]->file = "assets/maps/topaze.json";
    maps[0]->tile_set = "assets/tiles/outside.png";
    maps[0]->location = "topaze";
    maps[0]->layer_nb = 2;
    maps[0]->obs_nb = 272;
    maps[0]->tile_size = 20;
    maps[0]->offset = (sfVector2f){0, 0};
    maps[0]->zoom = 1.8f;
    init_interactions_boxes_indexs(maps[0], (int []){TOWN_SAFE, \
        TOWN_OUT, 0});
    init_layers_id(maps[0], (int []){1, 0}, (int []){0}, (int []){2, 0});
}

static void create_world_map(map_setup_t **maps)
{
    create_topaze_map(maps);
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
        DUNGEON_ENTER, FOREST_2, FOREST_1, POISON, 0});
    init_layers_id(maps[1], (int []){1, 0}, (int []){0}, (int []){2, 0});
}

static void create_dungeon_map(map_setup_t **maps)
{
    maps[2] = malloc(sizeof(map_setup_t));
    maps[2]->file = "assets/maps/dungeon.json";
    maps[2]->tile_set = "assets/tiles/inside.png";
    maps[2]->location = "default";
    maps[2]->layer_nb = 2;
    maps[2]->obs_nb = 183;
    maps[2]->tile_size = 20;
    maps[2]->offset = (sfVector2f){0, 0};
    maps[2]->zoom = 2.0f;
    init_interactions_boxes_indexs(maps[2], (int []){DUNGEON_OUT, BOSS, 0});
    init_layers_id(maps[2], (int []){1, 0}, (int []){0}, (int []){2, 0});
}

void init_maps(overworld_t *world)
{
    map_setup_t **maps = malloc(sizeof(map_setup_t*) * 4);

    if (!maps)
        return;
    create_topaze_map(maps);
    create_world_map(maps);
    create_dungeon_map(maps);
    maps[3] = NULL;
    world->maps = maps;
}