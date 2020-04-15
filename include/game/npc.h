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

typedef struct action_s {
    long int delta;
    sfVector2f pos;
    long int time;
} action_t;

typedef struct script_s {
    int max_count;
    int pos_count;
    action_t *actions;
} script_t;

typedef struct npc_s {
    long int delta;
    long int delta_movement;
    int speed;
    char *fp;
    anim_sprite_t **animations;
    int current_animations;
    script_t *script;
    sfCircleShape *collision;
} npc_t;

npc_t *create_npc(char *filepath, sfVector2f pos, int speed);
void draw_npc(sfRenderWindow *windows, npc_t *npc);
void update_npc(npc_t *npc, long int delta);
char **get_npc_dialog(npc_t *npc);
npc_t **get_town_npcs(char *town);

void set_npc_script(npc_t *npc, script_t *script);
script_t *get_npc_script(char *str_script);

#endif