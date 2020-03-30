/*
** EPITECH PROJECT, 2020
** update_battle_screen.c
** File description:
**  function
*/

#include <game.h>
#include <scene/battle.h>

int update_battle_screen(game_t *game, battle_screen_t *battle, long int delta)
{
    update_attack_gui(battle->attack_gui, delta);
}