/*
** EPITECH PROJECT, 2020
** anim_sprite_info.c
** File description:
** anim sprite info function
*/

#include "lib/components/anim_sprite.h"
#include <stdlib.h>

anim_info_t *init_anim_info(sfIntRect rect, int row, int column, int count)
{
    anim_info_t *info = malloc(sizeof(anim_info_t));
    info->x = rect.left;
    info->y = rect.top;
    info->width = rect.width;
    info->height = rect.height;

    info->row = row;
    info->column = row;
    info->anim = count;

    info->count_anim = 0;
    info->count_column = 0;
    info->count_row = 0;

    return (info);
}

void move_anim_sprite_position(anim_sprite_t *sprite, sfVector2f pos)
{
    sfSprite_move(sprite->sprite, pos);
}

void set_anim_sprite_position(anim_sprite_t *sprite, sfVector2f pos)
{
    sfSprite_setPosition(sprite->sprite, pos);
}

sfVector2f get_anim_sprite_position(anim_sprite_t *sprite)
{
    return sfSprite_getPosition(sprite->sprite);
}

void dispose_anim_info(anim_info_t *info)
{
    free(info);
}