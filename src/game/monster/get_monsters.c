/*
** EPITECH PROJECT, 2020
** get_monsters.c
** File description:
**  function
*/

#include "game/monster.h"

int get_monsters_length(monster_t **monsters)
{
    int length = 0;
    for (;monsters[length] != 0; length++)
        continue;
    return (length);
}