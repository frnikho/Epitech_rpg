/*
** EPITECH PROJECT, 2020
** open_inventory.c
** File description:
** open inventory function
*/

#include "game/inventory.h"

void open_inventory(inventory_t *inv)
{
    inv->is_open = !inv->is_open;
}

void toggle_inventory(inventory_t *inv)
{
    inv->is_open = !inv->is_open;
}