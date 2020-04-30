/*
** EPITECH PROJECT, 2020
** zone_world.c
** File description:
** zone_world function
*/

#include "scene/overworld.h"

void init_zone_world(overworld_t *overworld, interaction_box_t **inter)
{
    sfVector2f null = {0, 0};
    sfVector2f town_enter = {200, 430};
    sfVector2f town_out = {450, 990*2};
    sfVector2f dungeon_out = {1200, 300*2};
    sfVector2f dungeon_enter = {960, 960};
    inter[TOWN_SAFE-1] = create_interaction_box((sfFloatRect){0, 0, 1500, 1300}, null, -1, 0);
    inter[TOWN_OUT-1] = create_interaction_box((sfFloatRect){0, 205, 20, 80}, town_out, 1, 0);
    inter[TOWN_ENTER-1] = create_interaction_box((sfFloatRect){310, 940, 40, 22}, town_enter, 0, 0);
    inter[DUNGEON_ENTER-1] = create_interaction_box((sfFloatRect){460, 300, 40, 40}, dungeon_enter, 2, 0);
    inter[DUNGEON_OUT-1] = create_interaction_box((sfFloatRect){960, 920, 40, 22}, dungeon_out, 1, 0);
    inter[FOREST-1] = create_interaction_box((sfFloatRect){0, 0, 2500, 2000}, null, -1, 1);
    inter[END-2] = 0;
}