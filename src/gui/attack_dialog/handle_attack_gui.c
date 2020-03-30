/*
** EPITECH PROJECT, 2020
** handle_attack_gui.c
** File description:
**  function
*/

#include "gui/attack_gui.h"

void handle_attack_gui(attack_gui_t *gui, sfEvent event)
{
    if (gui->is_selected || event.type != sfEvtKeyPressed)
        return;
    if (event.key.code == sfKeyZ)
        gui->select_index-=2;
    if (event.key.code == sfKeyS)
        gui->select_index+=2;
    if (event.key.code == sfKeyQ)
        gui->select_index--;
    if (event.key.code == sfKeyD)
        gui->select_index++;
    if (event.key.code == sfKeySpace || event.key.code == sfKeyEnter)
        gui->is_selected = 1;
}