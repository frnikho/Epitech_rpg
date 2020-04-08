/*
** EPITECH PROJECT, 2020
** anim_sprite_scale.c
** File description:
** anim sprite scale function
*/

#include "lib/components/anim_sprite.h"

void set_anim_sprite_scale(anim_sprite_t *sprite, float scale)
{
    sfSprite_setScale(sprite->sprite, (sfVector2f){scale, scale});
}