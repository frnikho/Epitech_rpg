/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** run_away
*/

#include "game.h"
#include "scene/battle.h"

int try_run_away(game_t *game, battle_screen_t *battle)
{
    int m_agi = 0;
    int p_side = 0;
    int m_side = 0;

    for (int i = 0; battle->monster[i]; i++) {
        if (m_agi < battle->monster[i]->stats->agility)
            m_agi = battle->monster[i]->stats->agility;
    }
    p_side = (game->player->stats->agility * (rand() % 255));
    m_side = (m_agi * (rand() % 255));
    if (p_side >= m_side)
        return (1);
    return (0);
}