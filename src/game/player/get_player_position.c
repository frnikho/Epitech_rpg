/*
** EPITECH PROJECT, 2020
** get_player_position.c
** File description:
** get player position function
*/

#include "SFML/Audio.h"
#include "game/player.h"

sfVector2f get_player_position(player_t *player)
{
    int count = player->current_animations;
    return (sfSprite_getPosition(player->animations[count]->sprite));
}