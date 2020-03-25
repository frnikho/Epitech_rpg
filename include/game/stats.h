/*
** EPITECH PROJECT, 2020
** stats.h
** File description:
**  function
*/

#ifndef MY_RPG_STATS_H
#define MY_RPG_STATS_H

typedef struct stats_s {
    int hp;
    int strenght;
    int resistance;
    int agility;
    int mp;
    int magic;
} stats_t;

stats_t *init_stats(const int value[6]);

#endif
