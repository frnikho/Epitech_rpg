/*
** EPITECH PROJECT, 2020
** anim_sprite_update.c
** File description:
** anim sprite update function
*/

#include "lib/components/anim_sprite.h"

static void update(anim_sprite_t *sprite, int count)
{
    int width = sprite->info->width;
    int height = sprite->info->height;
    sprite->rect.left = width * sprite->info->count_column;
    sprite->rect.top = height * sprite->info->count_row;
    sfSprite_setTextureRect(sprite->sprite, sprite->rect);
    sprite->info->count_column++;
}

void update_anim_sprite_rect(anim_sprite_t *sprite)
{
    if (sprite->info->count_anim >= sprite->info->anim) {
        sprite->info->count_anim = 0;
        sprite->info->count_column = 0;
        sprite->info->count_row = 0;
    }
    update(sprite, sprite->info->count_anim);
    sprite->info->count_anim++;
}

void set_anim_sprite_anim(anim_sprite_t *sprite, int count)
{

}