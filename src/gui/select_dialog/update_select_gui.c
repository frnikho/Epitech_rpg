/*
** EPITECH PROJECT, 2020
** update_select_gui.c
** File description:
**  function
*/

#include "gui/select_gui.h"

void update_select_gui(select_gui_t *gui, long int delta)
{
    int count_monster = get_monsters_length(gui->monsters);
    static sfVector2f pos[] = {{880, 640}, {880, 662}, {880, 684}, {880, 726}};
    if (gui->monster_index < 0)
        gui->monster_index = 0;
    if (gui->monster_index > count_monster-1)
        gui->monster_index = count_monster-1;
    set_sprite_position(gui->cursor, pos[gui->monster_index]);
}