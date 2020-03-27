/*
** EPITECH PROJECT, 2020
** sprite.c
** File description:
** sprite function
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "lib/components/sprite.h"

sprite_t *init_sprite(char *filepath, sfIntRect *area)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));
    sprite->texture = sfTexture_createFromFile(filepath, area);
    sprite->sprite = sfSprite_create();
    sprite->delta = 0;
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfFalse);
    return (sprite);
}

void update_sprite(sprite_t *sprite, long int delta)
{
    sprite->delta += delta;
}

void draw_sprite(sfRenderWindow *window, sprite_t *sprite)
{
    sfRenderWindow_drawSprite(window, sprite->sprite, 0);
}

void dispose_sprite(sprite_t *sprite)
{
    sfTexture_destroy(sprite->texture);
    sfSprite_destroy(sprite->sprite);
    free(sprite);
}