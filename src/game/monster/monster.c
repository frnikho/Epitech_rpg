/*
** EPITECH PROJECT, 2020
** monster.c
** File description:
**  function
*/

#include "game/monster.h"
#include <malloc.h>

monster_t *create_monster(char *fp)
{
    monster_t *monster = malloc(sizeof(monster_t));
    return (monster);
}

void dispose_monster(monster_t *monster)
{
    dispose_stats(monster->stats);
    dispose_sprite(monster->sprite);
    free(monster->name);
    free(monster);
}