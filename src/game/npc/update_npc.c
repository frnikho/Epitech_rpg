/*
** EPITECH PROJECT, 2020
** update_npc.c
** File description:
** update_npc function
*/

#include "game/npc.h"

void update_npc(npc_t *npc, long int delta)
{
    static int speed[] = {0, 260000, 220000, 180000, 160000, 140000, 120000, 100000, 80000, 60000, 40000, 20000};
    npc->delta += delta;
    if (npc->speed == 0)
        return;
    if (npc->delta >= speed[npc->speed]) {
        npc->delta = 0;
        update_anim_sprite_rect(npc->animations[npc->current_animations]);
    }
}