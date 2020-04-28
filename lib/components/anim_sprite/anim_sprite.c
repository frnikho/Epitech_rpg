/*
** EPITECH PROJECT, 2020
** anim_sprite.c
** File description:
** animate sprite function
*/

#include "lib/components/anim_sprite.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

anim_sprite_t *create_anim_sprite(char *fp, sfVector2f p)
{
    anim_sprite_t *sprite = malloc(sizeof(anim_sprite_t));
    if (!sprite)
        return (0);
    sprite->delta = 0;
    sprite->current_count = 0;
    sprite->count = 0;
    sprite->rect = malloc(sizeof(sfIntRect) + 1);
    sprite->rect[0] = (sfIntRect){0, 0, 0, -9999};
    sprite->texture = sfTexture_createFromFile(fp, 0);
    sprite->sprite = sfSprite_create();
    sfSprite_setPosition(sprite->sprite, p);
    sfSprite_setTextureRect(sprite->sprite, (sfIntRect){0, 0, 0, 0});
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfTrue);
    return (sprite);
}

void update_anim_sprite(anim_sprite_t *sprite, long int delta)
{
    sprite->delta += delta;
}

void draw_anim_sprite(sfRenderWindow *window, anim_sprite_t *sprite)
{
    int count = sprite->current_count;
    sfSprite_setTextureRect(sprite->sprite, sprite->rect[count]);
    sfRenderWindow_drawSprite(window, sprite->sprite, 0);
}

void dispose_anim_sprite(anim_sprite_t *sprite)
{
    sfTexture_destroy(sprite->texture);
    sfSprite_destroy(sprite->sprite);
    free(sprite);
}