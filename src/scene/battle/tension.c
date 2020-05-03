/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** tension
*/

#include "game.h"
#include "scene/battle.h"

void tension(game_t *game, battle_screen_t *battle, int *streak)
{
    if (battle->attack_gui->select_index == SELECT_TENSION \
&& battle->attack_gui->is_selected && battle->round.code != ATTACK_CODE) {
        battle->attack_gui->is_selected = 0;
        if ((*streak) <= 3) {
            game->player->tmp_stats->strenght = \
            add_tension(game, battle, (*streak));
            (*streak)++;
        }
        battle->round.code = ATTACK_CODE;
    }
}

int add_tension(game_t *game, battle_screen_t *battle, int streak)
{
    if (streak == 0)
        return (game->player->stats->strenght * 0.05);
    if (streak == 1)
        return (game->player->stats->strenght * 0.2);
    if (streak == 2)
        return (game->player->stats->strenght * 0.5);
    if (streak == 3)
        return (game->player->stats->strenght);
    return (0);
}