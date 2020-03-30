/*
** EPITECH PROJECT, 2020
** update_attack_gui.c
** File description:
**  function
*/

#include "gui/attack_gui.h"

void update_attack_gui(attack_gui_t *gui, long int delta)
{
    static sfVector2f pos[] = {{405, 635}, {570, 635}, {405, 685},
        {570, 685}, {405, 735}, {570, 735}, 0};
    if (gui->select_index < 0)
        gui->select_index = 0;
    if (gui->select_index > 5)
        gui->select_index = 5;
    set_sprite_position(gui->cursor, pos[gui->select_index]);
}