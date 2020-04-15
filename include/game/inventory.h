/*
** EPITECH PROJECT, 2020
** inventory.h
** File description:
**  function
*/

#ifndef MY_RPG_INVENTORY_H
#define MY_RPG_INVENTORY_H

#include "game/item.h"

#define INV_SIZE 30

typedef struct case_s {
    int id;
    item_t *item;
} case_t;

typedef struct inventory_s {
    case_t **content;
    sprite_t *box;
} inventory_t;

#endif
