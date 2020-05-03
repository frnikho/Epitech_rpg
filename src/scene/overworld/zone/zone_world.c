/*
** EPITECH PROJECT, 2020
** zone_world.c
** File description:
** zone_world function
*/

#include "scene/overworld.h"

static void init_zone_battle(overworld_t *overworld, interaction_box_t **inter)
{
    sfVector2f null = {0, 0};
    inter[FOREST_1-1] = \
    create_interaction_box((sfFloatRect){150, 860, 300, 300}, null, -1, 1);
    inter[FOREST_2-1] = \
    create_interaction_box((sfFloatRect) {450, 900, 70, 220}, null, -1, 1);
    inter[POISON-1] = \
    create_interaction_box((sfFloatRect){360, 160, 240, 340}, null, -1, 3);
    inter[BOSS-1] = \
    create_interaction_box((sfFloatRect){540, 140, 200, 140}, null, -1, 4);
}

void init_zone_world(overworld_t *overworld, interaction_box_t **inter)
{
    sfVector2f null = {0, 0};
    sfVector2f town_enter = {200, 430};
    sfVector2f town_out = {1110, 2816};
    sfVector2f dungeon_out = {1426, 1036};
    sfVector2f dungeon_enter = {1268, 2388};

    inter[TOWN_SAFE-1] = \
    create_interaction_box((sfFloatRect){0, 0, 1500, 1300}, null, -1, 0);
    inter[TOWN_OUT-1] = \
    create_interaction_box((sfFloatRect){0, 205, 20, 80}, town_out, 1, 0);
    inter[TOWN_ENTER-1] = \
    create_interaction_box((sfFloatRect){310, 940, 40, 22}, town_enter, 0, 0);
    inter[DUNGEON_ENTER-1] = \
    create_interaction_box((sfFloatRect){460, 300, 40, 40}, \
    dungeon_enter, 2, 0);
    inter[DUNGEON_OUT-1] = \
    create_interaction_box((sfFloatRect){940, 920, 20, 20}, dungeon_out, 1, 0);
    init_zone_battle(overworld, inter);
    inter[END-1] = 0;
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