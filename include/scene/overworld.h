/*
** EPITECH PROJECT, 2020
** overworld.h
** File description:
** overworld function
*/

#ifndef MY_RPG_OVERWORLD_H
#define MY_RPG_OVERWORLD_H

#include "game/map.h"

typedef struct overworld_s {
    map_t *map;
    char **obs_tab;
    int ***objs_tab;
    int ***tiles_tab;
} overworld_t;

void overworld(game_t *game, long int delta);
void destroy_overworld(game_t *game, overworld_t *overworld);
int init_overworld(game_t *game, overworld_t *overworld);
int input_overworld(game_t *game, overworld_t *overworld);
int update_overworld(game_t *game, overworld_t *overworld, long int delta);
int render_overworld(game_t *game, overworld_t *overworld, long int delta);


#endif