/*
** EPITECH PROJECT, 2020
** item.c
** File description:
**  function
*/

#include "game/item.h"
#include <stdlib.h>

item_t *create_item(int id, char *fp)
{
    item_t *item = malloc(sizeof(item_t));
    item->id = id;
    item->fp = fp;
    item->count = 1;
    return (item);
}

void dispose_item(item_t *item)
{
    free(item);
}