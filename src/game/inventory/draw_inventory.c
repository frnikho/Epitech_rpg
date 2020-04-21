/*
** EPITECH PROJECT, 2020
** draw_inventory.c
** File description:
** draw inventory function
*/

#include "game/inventory.h"

static void update_inv_cursor(sfRenderWindow *w, sfView *cam, inventory_t *inv)
{
    static const sfVector2i pos = {540, 620};
    sfVector2f cursor_pos = {0, 0};
    sfVector2f shift = {55, 55};
    unsigned int x = inv->cursor_index.x;
    unsigned int y = inv->cursor_index.y;

    cursor_pos = sfRenderWindow_mapPixelToCoords(w, pos, cam);

    cursor_pos.x += (x * shift.x);
    cursor_pos.y += (y * shift.y);

    set_sprite_scale(inv->cursor, 1.5f);
    set_sprite_position(inv->cursor, cursor_pos);
}

static void update_items(sfRenderWindow *window, sfView *cam, inventory_t *inv)
{
    static const sfVector2i point = {550, 600};
    sfVector2f box_pos = {0, 0};
    box_pos = sfRenderWindow_mapPixelToCoords(window, point, cam);
    set_sprite_position(inv->box, box_pos);
    set_sprite_scale(inv->box, 1.4f);
    draw_sprite(window, inv->box);
}

void draw_inventory(sfRenderWindow *window, sfView *camera, inventory_t *inv)
{
    sfVector2i dot = {0, 0};
    sfVector2f tmp = {0, 0};

    if (!inv->is_open)
        return;
    update_items(window, camera, inv);
    for (int i = 0; inv->content[i] != 0; i++) {
        if (inv->content[i]->item != 0) {
            dot = (sfVector2i) {560, 610};
            tmp = sfRenderWindow_mapPixelToCoords(window, dot, camera);
            int x = inv->content[i]->pos.x;
            int y = inv->content[i]->pos.y;
            sfVector2f pos = {tmp.x + (x * 56), tmp.y + (y * 56)};
            set_sprite_position(inv->content[i]->item->sprite, pos);
            set_sprite_scale(inv->content[i]->item->sprite, 1.5);
            draw_sprite(window, inv->content[i]->item->sprite);
        }
    }
    update_inv_cursor(window, camera, inv);
    draw_sprite(window, inv->cursor);
}