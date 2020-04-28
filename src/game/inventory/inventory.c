/*
** EPITECH PROJECT, 2020
** inventory.c
** File description:
** inventory function
*/

#include "game/inventory.h"
#include <stdlib.h>

inventory_t *create_inventory(void)
{
    inventory_t *inv = malloc(sizeof(inventory_t));
    inv->content = malloc(sizeof(case_t*) * (INV_SIZE + 1));
    if (!inv->content)
        return (0);
    inv->is_open = 0;
    inv->action = 0;
    inv->cursor_index = (sfVector2u) {0, 0};
    int x = 0;
    int y = 0;
    for (int i = 0; i < INV_SIZE; i++, x++) {
        if (x >= 10) {
            y++;
            x = 0;
        }
        inv->content[i] = malloc(sizeof(case_t));
        inv->content[i]->item = 0;
        inv->content[i]->pos = (sfVector2u) {x, y};
    }
    inv->content[INV_SIZE] = 0;
    inv->box = init_sprite("assets/sprite/inventory.png", 0);
    inv->cursor = init_sprite("assets/sprite/gui/pointer_small.png", 0);
    return (inv);
}