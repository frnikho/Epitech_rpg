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


void add_player_position(player_t *player, sfVector2f pre_pos)
{
    for (int i = 0; player->animations[i] != 0; i++) {
        sfVector2f current_pos = sfSprite_getPosition(player->animations[i]->sprite);
        int x = current_pos.x + pre_pos.x;
        int y = current_pos.y + pre_pos.y;
        set_player_position(player, (sfVector2f){x, y});
    }
}

int block_move_on_collision(player_t *p, npc_t **npcs, long int delta, sfVector2f pre_pos)
{
    obstacle_t **obs = malloc(sizeof(obstacle_t*));

    obs[0] = NULL;
    if (check_collision_ahead(obs, npcs, p->collision, delta) == 1) {
        free(obs);
        add_player_position(p, (sfVector2f){pre_pos.x * -1, pre_pos.y * -1});
        return (1);
    }
    free(obs);
    return (0);
}

int move_player(player_t *p, npc_t **npcs, long int delta)
{
    static int current_delta = 0;
    current_delta += delta;
    static sfVector2f pre_pos = {0, 0};

    if (block_move_on_collision(p, npcs, delta, pre_pos) == 1)
        return (0);
    if (current_delta <= 30000) {
        current_delta += delta;
        return (0);
    }
    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        add_player_position(p, (sfVector2f){0, -1});
        pre_pos = (sfVector2f){0, -1};
        p->current_animations = 3;
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        p->current_animations = 2;
        add_player_position(p, (sfVector2f){-1, 0});
        pre_pos = (sfVector2f){-1, 0};
    }
    if (sfKeyboard_isKeyPressed(sfKeyS)) {
        add_player_position(p, (sfVector2f){0, 1});
        p->current_animations = 0;
        pre_pos = (sfVector2f){0, 1};
    }
    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        p->current_animations = 1;
        add_player_position(p, (sfVector2f){1, 0});
        pre_pos = (sfVector2f){1, 0};
    }
    current_delta = 0;
    return (1);
}