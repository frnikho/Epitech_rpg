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
int input_overworld(game_t *game, overworld_t *overworld);
int update_overworld(game_t *game, overworld_t *overworld, long int delta);
int render_overworld(game_t *game, overworld_t *overworld, long int delta);
int init_overworld_map(overworld_t *overworld);
void init_zone_world(overworld_t *overworld, interaction_box_t **boxs);

dialog_t *create_levelup_dialog(player_t *player, int *stats);

#endif