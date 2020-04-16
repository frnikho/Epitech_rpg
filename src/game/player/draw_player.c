/*
** EPITECH PROJECT, 2020
** draw_player.c
** File description:
** draw player function
*/

#include "game/player.h"

void draw_player(sfRenderWindow *window, player_t *player)
{
    draw_anim_sprite(window, player->animations[player->current_animations]);
}

void set_player_scale(player_t *player, float scale)
{
    for (int i = 0; player->animations[i] != 0; i++) {
        set_anim_sprite_scale(player->animations[i], 2);
    }
}