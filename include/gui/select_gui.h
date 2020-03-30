/*
** EPITECH PROJECT, 2020
** select_dialog.h
** File description:
**  function
*/

#ifndef MY_RPG_SELECT_GUI_H
#define MY_RPG_SELECT_GUI_H

#include "game/monster.h"
#include "lib/components/text.h"

typedef struct select_gui_s {
    int is_active;
    int is_selected;
    int monster_index;
    monster_t **monsters;
    text_t *monsters_name;
    sprite_t *cursor;
    sprite_t *gui;
} select_gui_t;

select_gui_t *create_select_gui(monster_t **monsters);
void dispose_select_gui(select_gui_t *gui);
void draw_select_gui(sfRenderWindow *window, select_gui_t *gui);

#endif
