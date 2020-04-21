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
    sfVector2u pos;
    item_t *item;
} case_t;

typedef struct inventory_s {
    case_t **content;
    sprite_t *box;
    sprite_t *cursor;
    sfVector2u cursor_index;
    int action;
    int is_selected;
    int is_open;
} inventory_t;

inventory_t *create_inventory(void);
void add_inventory_item(inventory_t *inv, item_t *item);
void draw_inventory(sfRenderWindow *window, sfView *camera, inventory_t *inv);
void open_inventory(inventory_t *inv);
void handle_inventory(sfEvent event, inventory_t *inv);
void update_inventory(inventory_t *inv, long int update);
void toggle_inventory(inventory_t *inv);

#endif
