/*
** EPITECH PROJECT, 2020
** update_player.c
** File description:
** update player function
*/

#include "game/player.h"

void update_player(player_t *player, long int delta)
{
    player->delta += delta;
    if (player->delta >= 180000) {
        player->delta = 0;
        update_anim_sprite_rect(player->animations[player->current_animations]);
    }
    //player->collision->collision_box = sfSprite_getGlobalBounds(player->animations[player->current_animations]->sprite);
}