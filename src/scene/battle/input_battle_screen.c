/*
** EPITECH PROJECT, 2020
** input_battle_screen.c
** File description:
**  function
*/

#include <game.h>
#include <scene/battle.h>

int input_battle_screen(game_t *game, battle_screen_t *battle)
{
    handle_attack_gui(battle->attack_gui, game->event);
}