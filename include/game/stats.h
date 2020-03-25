/*
** EPITECH PROJECT, 2020
** stats.h
** File description:
**  function
*/

#ifndef MY_RPG_STATS_H
#define MY_RPG_STATS_H

#define STATS_I_HP 0
#define STATS_I_MP 1
#define STATS_I_STR 2
#define STATS_I_RES 3
#define STATS_I_AG 4
#define STATS_I_MAG 5

typedef struct stats_s {
    int hp;
    int strenght;
    int resistance;
    int agility;
    int mp;
    int magic;
} stats_t;

stats_t *init_stats(const int value[6]);
void dispose_stats(stats_t *stats);

#endif