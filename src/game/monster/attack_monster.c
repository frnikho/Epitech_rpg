/*
** EPITECH PROJECT, 2020
** attack_monter.c
** File description:
**  function
*/

#include <game/monster.h>
#include <game/player.h>
#include <stdlib.h>

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

void monster_attack_player(monster_t *monster, player_t *player)
{
    if (!monster || !player)
        return;
    int str = monster->stats->strenght;
    int damage = calc_attack_damage(str, player->stats->resistance);
    player->health -= damage;
    update_player_gui(player);
}