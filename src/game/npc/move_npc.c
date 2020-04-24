/*
** EPITECH PROJECT, 2020
** move_npc.c
** File description:
** move npc function
*/

#include "game/npc.h"

void move_npc(npc_t *npc, sfVector2f next_pos)
{
    npc->need_move = 1;
    npc->next_pos = next_pos;
}