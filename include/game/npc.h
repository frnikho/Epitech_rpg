/*
** EPITECH PROJECT, 2020
** npc.h
** File description:
** header file
*/

#ifndef MY_RPG_NPC_H
#define MY_RPG_NPC_H

#include "lib/components/anim_sprite.h"

#define NPC_FP "assets/sprite/npc.png"

typedef struct npc_s {
    long int delta;
    int speed;
    char *fp;
    anim_sprite_t **animations;
    int current_animations;
} npc_t;

npc_t *create_npc(char *filepath, sfVector2f pos, int speed);
void draw_npc(sfRenderWindow *windows, npc_t *npc);
void update_npc(npc_t *npc, long int delta);
char **get_npc_dialog(npc_t *npc);
npc_t **get_town_npcs(char *town);

#endif