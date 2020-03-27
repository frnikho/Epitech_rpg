/*
** EPITECH PROJECT, 2020
** render_battle_screen.c
** File description:
**  function
*/

#include <game.h>
#include <scene/battle.h>

int render_battle_screen(game_t *game, battle_screen_t *battle, long int delta)
{
    for (int i = 0; battle->monster[i] != 0; i++)
        draw_monster(game->window, battle->monster[i]);
}