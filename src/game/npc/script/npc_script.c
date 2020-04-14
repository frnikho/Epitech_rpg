/*
** EPITECH PROJECT, 2020
** npc_script.c
** File description:
** npc_script function
*/

#include "game/npc.h"

void set_npc_script(npc_t *npc, script_t *script)
{
    npc->script = script;
}