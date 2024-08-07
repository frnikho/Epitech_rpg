/*
** EPITECH PROJECT, 2020
** inventory.c
** File description:
** inventory function
*/

#include "game/inventory.h"
#include <stdlib.h>

static int init_inventory_content(inventory_t *inv)
{
    inv->content = malloc(sizeof(case_t*) * (INV_SIZE + 1));
    if (!inv->content)
        return (-1);
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
    return (0);
}

static void init_info_panel(inventory_t *inv)
{
    inv->panel.title = init_text("Item:", 16, (sfVector2f){-5, -5});
    inv->panel.box = init_sprite("assets/sprite/gui/item_info.png", 0);
    set_text_font(inv->panel.title, FONT);
}

inventory_t *create_inventory(void)
{
    inventory_t *inv = malloc(sizeof(inventory_t));
    if (init_inventory_content(inv) == -1)
        return (0);
    init_info_panel(inv);
    inv->box = init_sprite("assets/sprite/inventory.png", 0);
    inv->cursor = init_sprite("assets/sprite/gui/pointer_small.png", 0);
    return (inv);
}