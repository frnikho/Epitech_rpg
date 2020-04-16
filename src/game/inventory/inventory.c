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
    inv->content = malloc(sizeof(case_t*) * INV_SIZE);
    inv->is_open = 0;
    for (int i = 0; i < INV_SIZE; i++) {
        inv->content[i] = malloc(sizeof(case_t));
        inv->content[i]->id = i;
    }
    inv->box = init_sprite("assets/sprite/inventory.png", 0);
    return (inv);
}