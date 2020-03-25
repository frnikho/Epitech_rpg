/*
** EPITECH PROJECT, 2020
** sprite_size.c
** File description:
** sprite size function
*/

#include "lib/components/sprite.h"
#include <SFML/Graphics.h>

void set_sprite_scale(sprite_t *sprite, float scale)
{
    sfVector2f size = {scale, scale};
    sfSprite_setScale(sprite->sprite, size);
}

sfVector2f get_sprite_scale(sprite_t *sprite)
{
    return sfSprite_getScale(sprite->sprite);
}