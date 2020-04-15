/*
** EPITECH PROJECT, 2020
** add_inventory_item.c
** File description:
** inventory function
*/

#include "game/inventory.h"

void add_inventory_item(inventory_t *inv, item_t *item)
{
    for (int i = 0; inv->content[i] != 0; i++) {
        if (inv->content[i]->item == 0) {
            inv->content[i]->item = item;
        }
    }
}

void set_inventory_item(inventory_t *inv, item_t *item, int place)
{
    inv->content[place]->item = item;
}