/*
** EPITECH PROJECT, 2020
** battle.h
** File description:
**  function
*/

#ifndef MY_RPG_BATTLE_H
#define MY_RPG_BATTLE_H

#include "game/monster.h"
#include "game/player.h"

typedef struct battle_screen_s {
    player_t *player;
    monster_t **monster;

    //TODO create action box

} battle_screen_t;

void battle_screen(game_t *game, long int delta);
void dispose_battle_screen(game_t *game, battle_screen_t *battle);
int init_battle_screen(game_t *game, battle_screen_t *battle);
int input_battle_screen(game_t *game, battle_screen_t *battle);
int update_battle_screen(game_t *game, battle_screen_t *battle, long int delta);
int render_battle_screen(game_t *game, battle_screen_t *battle, long int delta);

#endif
