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
} item_t;

#endif