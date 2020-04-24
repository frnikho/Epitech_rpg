/*
** EPITECH PROJECT, 2020
** overworld.h
** File description:
** overworld function
*/

#ifndef MY_RPG_OVERWORLD_H
#define MY_RPG_OVERWORLD_H

#include "game.h"
#include "state.h"
#include "game/map.h"

typedef struct overworld_s {
    map_setup_t **maps;
    int current_map;
    map_t *map;
    char **obs_tab;
    int ***objs_tab;
    int ***tiles_tab;
    state_t *state;
} overworld_t;

void overworld(game_t *game, long int delta);
void destroy_overworld(game_t *game, overworld_t *overworld);
int init_overworld(game_t *game, overworld_t *overworld);
int input_overworld(game_t *game, overworld_t *overworld);
int update_overworld(game_t *game, overworld_t *overworld, long int delta);
int render_overworld(game_t *game, overworld_t *overworld, long int delta);
int init_overworld_map(overworld_t *overworld);


#endif