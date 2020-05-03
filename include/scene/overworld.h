/*
** EPITECH PROJECT, 2020
** overworld.h
** File description:
** overworld function
*/

#ifndef MY_RPG_OVERWORLD_H
#define MY_RPG_OVERWORLD_H

#include <gui/pause_gui.h>
#include "game.h"
#include "state.h"
#include "game/map.h"
#include "game/npc.h"

enum zone_info {DEFAULT, TOWN_SAFE, TOWN_OUT, TOWN_ENTER, DUNGEON_ENTER,
    DUNGEON_OUT, FOREST_1, FOREST_2, POISON, BOSS, END};

typedef struct overworld_s {
    map_setup_t **maps;
    int current_map;
    map_t *map;
    char **obs_tab;
    int ***objs_tab;
    int ***tiles_tab;
    state_t *state;
    interaction_box_t **maps_interaction_boxes;
    npc_t **npcs;
    pause_gui_t *pause;
} overworld_t;

void overworld(game_t *game, long int delta);
void destroy_overworld(game_t *game, overworld_t *overworld);
int init_overworld(game_t *game, overworld_t *overworld);
int input_overworld(game_t *game, overworld_t *overworld, long int delta);
int update_overworld(game_t *game, overworld_t *overworld, long int delta);
int render_overworld(game_t *game, overworld_t *overworld, long int delta);
int init_overworld_map(overworld_t *overworld);
void init_zone_world(overworld_t *overworld, interaction_box_t **boxs);
int ***create_tiles_tab(overworld_t *overworld, char **layers);
int ***create_objs_tab(overworld_t *overworld, char **layers);
char **create_obs_tab(overworld_t *overworld, char **layers);
void load_setup_in_map(overworld_t *overworld, \
int ***tiles_tab, int ***objs_tab, char **obs_tab);
void load_interaction_boxes(map_setup_t *setup, map_t *map, overworld_t *world);
void init_maps(overworld_t *world);
void init_maps_interactions(overworld_t *world);
void init_interactions_boxes_indexs(map_setup_t *map, int *indexs);
void init_layers_id(map_setup_t *map, int *tile_ids, \
int *objs_ids, int *obs_ids);
dialog_t *create_levelup_dialog(player_t *player, int *stats);

#endif