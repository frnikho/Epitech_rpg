/*
** EPITECH PROJECT, 2020
** damage_stats.c
** File description:
**  function
*/

#include "game/stats.h"

unsigned int calcul_damage_stats(stats_t *attacker, stats_t *receiver)
{
    if (!attacker || !receiver)
        return (-1);
    unsigned int res_dmg = attacker->strenght - receiver->resistance;
    unsigned int final_damage = (attacker->strenght / 2) - res_dmg;
    return (final_damage);
}

int calcul_first(stats_t *s1, stats_t *s2)
{
    if (s1->agility > s2->agility)
        return (1);
    else
        return (2);
}