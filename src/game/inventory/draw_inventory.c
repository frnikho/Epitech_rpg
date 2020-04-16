/*
** EPITECH PROJECT, 2020
** draw_inventory.c
** File description:
** draw inventory function
*/

#include "game/inventory.h"

void draw_inventory(sfRenderWindow *window, sfView *camera, inventory_t *inv)
{
    if (!inv->is_open)
        return;
    static sfVector2i point = {500, 600};
    sfVector2f pos = sfRenderWindow_mapPixelToCoords(window, point, camera);
    set_sprite_position(inv->box, pos);
    draw_sprite(window, inv->box);
}