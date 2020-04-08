/*
** EPITECH PROJECT, 2020
** draw_npc.c
** File description:
** draw_npc function
*/

#include <SFML/Graphics/Types.h>
#include "game/npc.h"

void draw_npc(sfRenderWindow *windows, npc_t *npc)
{
    draw_anim_sprite(windows, npc->animations[npc->current_animations]);
}