/*
** EPITECH PROJECT, 2020
** item.h
** File description:
**  function
*/

#ifndef MY_RPG_ITEM_H
#define MY_RPG_ITEM_H

#include "lib/components/sprite.h"

typedef struct item_s {
    int id;
    char *fp;
    int count;
    sprite_t *sprite;
} item_t;

item_t *create_item(char *fp);
item_t *deserialize_item(char *fp);
void dispose_item(item_t *item);

#endif