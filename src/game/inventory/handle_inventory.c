/*
** EPITECH PROJECT, 2020
** handle_inventory.c
** File description:
** handle inventory function
*/

#include "lib/components/pad.h"
#include "game/inventory.h"

static void handle_inv_gamepad(sfEvent e, inventory_t *inv)
{
    if (!inv->is_open)
        return;
    if (e.type != sfEvtJoystickButtonPressed)
        return;
}

void handle_inventory(sfEvent event, inventory_t *inv)
{
    handle_inv_gamepad(event, inv);
    if (!inv->is_open || event.type != sfEvtKeyPressed)
        return;
    if (event.key.code == sfKeyZ) {
        if (inv->cursor_index.y != 0)
            inv->cursor_index.y--;
    }
    if (event.key.code == sfKeyS) {
        if (inv->cursor_index.y != 2)
            inv->cursor_index.y++;
    }
    if (event.key.code == sfKeyQ) {
        if (inv->cursor_index.x != 0)
            inv->cursor_index.x--;
    }
    if (event.key.code == sfKeyD) {
        if (inv->cursor_index.x != 9)
            inv->cursor_index.x++;
    }
}