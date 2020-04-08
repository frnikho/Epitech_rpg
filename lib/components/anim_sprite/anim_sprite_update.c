/*
** EPITECH PROJECT, 2020
** anim_sprite_update.c
** File description:
** anim sprite update function
*/

#include "lib/components/anim_sprite.h"
#include <stdlib.h>

static void update_anim_frame(anim_sprite_t *sprite)
{
    sprite->current_count++;
    if (sprite->current_count >= sprite->count) {
        sprite->current_count = 0;
    }
}

void update_anim_sprite_rect(anim_sprite_t *sprite)
{
    update_anim_frame(sprite);
}

static int get_anim_size(sfIntRect *array)
{
    int count = 0;
    for (; array[count].height != -9999; count++)
        continue;
    return (count);
}

void add_anim_frame(anim_sprite_t *anim, sfIntRect rect)
{
    sfIntRect *result = malloc(sizeof(sfIntRect) * (get_anim_size(anim->rect) + 2));
    int i = 0;
    for (; anim->rect[i].height != -9999; i++) {
        result[i] = anim->rect[i];
    }
    result[i] = rect;
    result[i+1] = (sfIntRect){0, 0, 0, -9999};
    free(anim->rect);
    anim->rect = result;
    anim->count++;
}