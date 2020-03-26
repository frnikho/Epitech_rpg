/*
** EPITECH PROJECT, 2020
** stats.c
** File description:
** stats function
*/

#include "game/stats.h"
#include <stdlib.h>

stats_t *init_stats(const int value[6])
{
    stats_t *stats = malloc(sizeof(stats_t));
    stats->hp = value[0];
    stats->mp = value[1];
    stats->strenght = value[2];
    stats->resistance = value[3];
    stats->agility = value[4];
    stats->magic = value[5];
    return (stats);
}

void destroy_stats(stats_t *stats)
{
    free(stats);
}