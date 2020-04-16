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
        sfVector2f current_pos = sfSprite_getPosition(player->animations[i]->sprite);
        int x = current_pos.x + pos.x;
        int y = current_pos.y + pos.y;
        set_player_position(player, (sfVector2f){x, y});
    }
}

int move_player(player_t *p, npc_t **npcs, long int delta)
{
    static int current_delta = 0;
    current_delta += delta;

    if (current_delta <= 30000) {
        current_delta += delta;
        return (0);
    }
    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        add_player_position(p, (sfVector2f){0, -1});
        p->pre_pos = (sfVector2f){0, -1};
        p->current_animations = 3;
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        p->current_animations = 2;
        add_player_position(p, (sfVector2f){-1, 0});
        p->pre_pos = (sfVector2f){-1, 0};
    }
    if (sfKeyboard_isKeyPressed(sfKeyS)) {
        add_player_position(p, (sfVector2f){0, 1});
        p->current_animations = 0;
        p->pre_pos = (sfVector2f){0, 1};
    }
    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        p->current_animations = 1;
        add_player_position(p, (sfVector2f){1, 0});
        p->pre_pos = (sfVector2f){1, 0};
    }
    current_delta = 0;
    return (1);
}