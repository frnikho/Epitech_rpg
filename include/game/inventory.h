/*
** EPITECH PROJECT, 2020
** inventory.h
** File description:
**  function
*/

#ifndef MY_RPG_INVENTORY_H
#define MY_RPG_INVENTORY_H

#include "player/item"

typedef struct case_s {
    int id;
    item_t *item;
} case_t;

typedef struct inventory_s {
    case_t **equipements;
    case_t **bag
} inventory_t;

#endif
