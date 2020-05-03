/*
** EPITECH PROJECT, 2020
** handle_attack_gui.c
** File description:
**  function
*/

#include "gui/attack_gui.h"

void handle_attack_gui(attack_gui_t *gui, sfEvent event)
{
    sfColor grey = sfColor_fromRGBA(87, 89, 93, 255);

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
    if (event.key.code == sfKeySpace || event.key.code == sfKeyEnter) {
        gui->is_selected = 1;
        int in = gui->select_index;
        if ((compare_color(gui->objects->color, grey) == 0 && in == 1))
            gui->is_selected = 0;
        if ((compare_color(gui->abilities->color, grey) == 0 && in == 3))
            gui->is_selected = 0;
        if ((compare_color(gui->spells->color, grey) == 0 && in == 2))
            gui->is_selected = 0;
    }
}

int compare_color(sfColor selected, sfColor grey)
{
    if (selected.r != grey.r || selected.g != grey.g)
        return (1);
    if (selected.b != grey.b || selected.a != grey.a)
        return (1);
    return (0);
}