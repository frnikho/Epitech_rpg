/*
** EPITECH PROJECT, 2020
** move_player.c
** File description:
** move_player function
*/

#include "game/map.h"
#include "game/player.h"
#include "lib/components/pad.h"

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
        float x = current_pos.x + pos.x;
        float y = current_pos.y + pos.y;
        set_player_position(player, (sfVector2f){x, y});
    }
}

static void handle_player_fight(player_t *player, long int delta)
{
    static long int random_delta = 0;

    random_delta += delta;
    if (random_delta >= 900000) {
        int rdn = rand() % 900000;
        player->delta_fight -= rdn;
        random_delta = 0;
    }
    if (player->delta_fight >= 4500000) {
        player->delta_fight = 0;
        if (player->zone != 0)
            player->fight = 0;
        return;
    }
    player->delta_fight += delta;
}

int exec_move(player_t *p, sfVector2f pos, int current_annimation, \
int *current_delta)
{
    if ((*current_delta) == 0)
        return (1);
    handle_player_fight(p, (*current_delta));
    add_player_position(p, pos);
    p->current_animations = current_annimation;
    p->pre_pos = pos;
    (*current_delta) = 0;
    return (0);
}

int move_player(player_t *p, npc_t **npcs, long int delta)
{
    static int current_delta = 0;

    if (!p || !p->can_move)
        return (0);
    current_delta += delta;
    if (current_delta <= 30000) {
        current_delta += delta;
        return (0);
    }
    if (sfKeyboard_isKeyPressed(sfKeyZ) || pad_arrow() == PAD_UP)
        exec_move(p, (sfVector2f){0, -1}, 3, &current_delta);
    if (sfKeyboard_isKeyPressed(sfKeyQ) || pad_arrow() == PAD_LEFT)
        exec_move(p, (sfVector2f){-1, 0}, 2, &current_delta);
    if (sfKeyboard_isKeyPressed(sfKeyS) || pad_arrow() == PAD_DOWN)
        exec_move(p, (sfVector2f){0, 1}, 0, &current_delta);
    if (sfKeyboard_isKeyPressed(sfKeyD) || pad_arrow() == PAD_RIGHT)
        exec_move(p, (sfVector2f){1, 0}, 1, &current_delta);
    current_delta = 0;
    return (1);
}