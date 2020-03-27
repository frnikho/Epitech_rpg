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
    monster_t **monsters;
    text_t *monsters_name;
} select_gui_t;

#endif
