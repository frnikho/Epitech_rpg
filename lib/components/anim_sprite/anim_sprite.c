/*
** EPITECH PROJECT, 2020
** anim_sprite.c
** File description:
** animate sprite function
*/

#include "lib/components/anim_sprite.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

anim_sprite_t *init_anim_sprite(char *fp, sfVector2f p, anim_info_t *i)
{
    anim_sprite_t *sprite = malloc(sizeof(anim_sprite_t));
    if (!sprite)
        return (0);
    sprite->info = i;
    sprite->delta = 0;
    sprite->texture = sfTexture_createFromFile(fp, 0);
    sprite->sprite = sfSprite_create();
    sfSprite_setPosition(sprite->sprite, p);
    sfIntRect rect = {i->x, i->y, i->width, i->height};
    sfSprite_setTextureRect(sprite->sprite, rect);
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfTrue);
    sprite->rect = rect;
    return (sprite);
}

void update_anim_sprite(anim_sprite_t *sprite, long int delta)
{
    sprite->delta += delta;
}

void draw_anim_sprite(sfRenderWindow *window, anim_sprite_t *sprite)
{
    sfSprite_setTextureRect(sprite->sprite, sprite->rect);
    sfRenderWindow_drawSprite(window, sprite->sprite, 0);
}

void dispose_anim_sprite(anim_sprite_t *sprite)
{
    sfTexture_destroy(sprite->texture);
    sfSprite_destroy(sprite->sprite);
    dispose_anim_info(sprite->info);
    free(sprite);
}