/*
** EPITECH PROJECT, 2020
** draw_select_gui.c
** File description:
**  function
*/

#include <gui/select_gui.h>

void draw_select_gui(sfRenderWindow *window, select_gui_t *gui)
{
    draw_text(window, gui->monsters_name);
}