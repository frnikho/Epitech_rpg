/*
** EPITECH PROJECT, 2020
** anim_sprite_event.c
** File description:
** anim sprite function
*/

#include "lib/components/anim_sprite.h"

int is_anim_sprite_clicked(anim_sprite_t *sprite, sfEvent event)
{
    sfVector2f pos = sfSprite_getPosition(sprite->sprite);
    sfIntRect rect = sfSprite_getTextureRect(sprite->sprite);
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

int is_anim_sprite_hovered(anim_sprite_t *sprite, sfRenderWindow *window)
{
    sfVector2i mpos = sfMouse_getPositionRenderWindow(window);
    sfVector2f box_p = get_anim_sprite_position(sprite);
    sfFloatRect rect = sfSprite_getGlobalBounds(sprite->sprite);

    int mx = rect.width + box_p.x;
    int my = rect.height + box_p.y;

    if (mpos.x < box_p.x || mpos.y < box_p.y)
        return (0);
    if (mpos.x > mx || mpos.y > my)
        return (0);
    return (1);
}