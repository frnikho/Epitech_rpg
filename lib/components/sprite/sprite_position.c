/*
** EPITECH PROJECT, 2020
** sprite_position.c
** File description:
** sprite position function
*/

#include "lib/components/sprite.h"

void set_sprite_position(sprite_t *sprite, sfVector2f position)
{
    sfSprite_setPosition(sprite->sprite, position);
}

void move_sprite_position(sprite_t *sprite, sfVector2f offset)
{
    sfSprite_move(sprite->sprite, offset);
}

sfVector2f get_sprite_position(sprite_t *sprite)
{
    return sfSprite_getPosition(sprite->sprite);
}