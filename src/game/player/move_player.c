/*
** EPITECH PROJECT, 2020
** move_player.c
** File description:
** move_player function
*/

#include <game/map.h>
#include "game/player.h"

void set_player_position(player_t *player, sfVector2f position)
{
    for (int i = 0; player->animations[i] != 0; i++) {
        sfSprite_setPosition(player->animations[i]->sprite, position);
    }
}

void add_player_position(player_t *player, sfVector2f pos)
{
    for (int i = 0; player->animations[i] != 0; i++) {
        sfVector2f current_pos = \
        sfSprite_getPosition(player->animations[i]->sprite);
        int x = current_pos.x + pos.x;
        int y = current_pos.y + pos.y;
        set_player_position(player, (sfVector2f){x, y});
    }
}

int exec_move(player_t *p, sfVector2f pos, int current_annimation, \
int *current_delta)
{
    add_player_position(p, pos);
    p->pre_pos = pos;
    p->current_animations = current_annimation;
    (*current_delta) = 0;
}

int move_player(player_t *p, npc_t **npcs, long int delta)
{
    static int current_delta = 0;
    current_delta += delta;

    if (current_delta <= 30000) {
        current_delta += delta;
        return (0);
    }
    if (sfKeyboard_isKeyPressed(sfKeyZ) && current_delta != 0)
        exec_move(p, (sfVector2f){0, -1}, 3, &current_delta);
    if (sfKeyboard_isKeyPressed(sfKeyQ) && current_delta != 0)
        exec_move(p, (sfVector2f){-1, 0}, 2, &current_delta);
    if (sfKeyboard_isKeyPressed(sfKeyS) && current_delta != 0)
        exec_move(p, (sfVector2f){0, 1}, 0, &current_delta);
    if (sfKeyboard_isKeyPressed(sfKeyD) && current_delta != 0)
        exec_move(p, (sfVector2f){1, 0}, 1, &current_delta);
    current_delta = 0;
    return (1);
}