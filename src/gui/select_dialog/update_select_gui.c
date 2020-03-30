/*
** EPITECH PROJECT, 2020
** update_select_gui.c
** File description:
**  function
*/

#include "gui/select_gui.h"

void update_select_gui(select_gui_t *gui, long int delta)
{
    static sfVector2f pos[] = {{820, 700}, 0};
    if (gui->monster_index < 0)
        gui->monster_index = 0;
    gui->monsters
    if (gui->monster_index > )
    set_sprite_position(gui->cursor, pos[gui->monster_index]);

}