/*
** EPITECH PROJECT, 2020
** attack_player.c
** File description:
**  function
*/

#include <stdlib.h>
#include "game/player.h"
#include "game/monster.h"

static int calc_attack_damage(int att, int def)
{
    int more_dmg = rand() % 2;
    int random = rand() % 255;
    int damage = (att - (def / 2) + (((att - def / 2+1) * random) / 256) / 4);
    if (damage < 0)
        damage = 0;
    damage += more_dmg;
    return (damage);
}

void player_attack_monster(player_t *player, monster_t *monster)
{
    if (!monster || !player)
        return;
    int str = player->stats->strenght;
    int damage = calc_attack_damage(str, monster->stats->resistance);
    monster->stats->hp -= damage;
}