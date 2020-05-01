/*
** EPITECH PROJECT, 2020
** spell.h
** File description:
** spell function
*/

#ifndef MY_RPG_SPELL_H
#define MY_RPG_SPELL_H

#include "game.h"
#include "game/monster.h"

typedef struct spell_s {
    char *key;
    char *name;
    int (*callback)(game_t *game, monster_t **monsters);
} spell_t;

spell_t *get_spells(player_t *player);
int flame(game_t *game, monster_t **monster);
int heal(game_t *game, monster_t **monster);
int weakness_hit(game_t *game, monster_t **monster);


#endif
