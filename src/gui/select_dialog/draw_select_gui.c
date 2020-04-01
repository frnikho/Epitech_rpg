/*
** EPITECH PROJECT, 2020
** draw_select_gui.c
** File description:
**  function
*/

#include <gui/select_gui.h>

void draw_select_gui(sfRenderWindow *window, select_gui_t *gui)
{
    draw_sprite(window, gui->gui);
    draw_text(window, gui->monsters_name);
    if (gui->is_active)
        draw_sprite(window, gui->cursor);
}