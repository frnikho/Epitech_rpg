/*
** EPITECH PROJECT, 2020
** sprite_event.c
** File description:
** sprite event function
*/

#include "lib/components/sprite.h"
#include <SFML/Graphics.h>

int is_sprite_clicked(sprite_t *sp, sfEvent event)
{
    sfVector2f pos = get_sprite_position(sp);
    sfIntRect rect = sfSprite_getTextureRect(sp->sprite);

    int mx = rect.width + pos.x;
    int my = rect.height + pos.y;
    if (event.type != sfEvtMouseButtonPressed)
        return (0);
    float x = event.mouseButton.x;
    float y = event.mouseButton.y;
    if (x <= mx && x >= pos.x && y <= my && y >= pos.y)
        return (1);
    else
        return (0);
}

int is_sprite_hovered(sprite_t *sprite, sfEvent event)
{
    sfVector2f pos = get_sprite_position(sprite);
    sfIntRect rect = sfSprite_getTextureRect(sprite->sprite);

    int mx = rect.width + pos.x;
    int my = rect.height + pos.y;
    if (event.type != sfEvtMouseMoved)
        return (0);
    float x = event.mouseMove.x;
    float y = event.mouseMove.y;
    if (x <= mx && x >= pos.x && y <= my && y >= pos.y)
        return (1);
    else
        return (0);
}