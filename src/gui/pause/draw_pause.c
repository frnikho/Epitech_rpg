/*
** EPITECH PROJECT, 2020
** draw_pause.c
** File description:
** draw pause function
*/

#include "gui/pause_gui.h"

void draw_pause(pause_gui_t *gui, sfRenderWindow *window, long int delta)
{
    if (!gui->is_open)
        return;
    update_pause(gui, delta);
    draw_sprite(window, gui->box);
    draw_sprite(window, gui->cursor);
}