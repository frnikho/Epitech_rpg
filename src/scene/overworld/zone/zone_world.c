/*
** EPITECH PROJECT, 2020
** zone_world.c
** File description:
** zone_world function
*/

#include "scene/overworld.h"

void init_zone_world(overworld_t *overworld, interaction_box_t **inter)
{
    inter[TOWN_SAFE] = create_interaction_box((sfFloatRect){0, 0, 1500, 1300}, 0, -1, 0);

    inter[1] = create_interaction_box((sfFloatRect){850, 990, 250, 200}, 0, -1, 1);
    inter[2] = create_interaction_box((sfFloatRect){460, 280, 40, 40}, 0, 2, 0);
    inter[3] = create_interaction_box((sfFloatRect){200, 980, 40, 22}, 0, 0, 0);
    inter[4] = NULL;
}