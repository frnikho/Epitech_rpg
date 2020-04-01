/*
** EPITECH PROJECT, 2020
** handle_select_gui.c
** File description:
**  function
*/

#include "gui/select_gui.h"

void handle_select_gui(sfEvent event, select_gui_t *gui)
{
    if (event.type != sfEvtKeyPressed)
        return;
    sfKeyCode key = event.key.code;
    if (gui->is_selected)
        return;
    if (key == sfKeyZ || key == sfKeyQ)
        gui->monster_index--;
    if (key == sfKeyS || key == sfKeyD)
        gui->monster_index++;
    if (key == sfKeySpace || key == sfKeyEnter) {
        gui->is_selected = 1;
    }
}