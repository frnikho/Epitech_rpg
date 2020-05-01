/*
** EPITECH PROJECT, 2020
** pause.c
** File description:
** pause function
*/

#include "gui/pause_gui.h"
#include <stdlib.h>

pause_gui_t *create_pause(sfRenderWindow *window, sfView *view)
{
    pause_gui_t *gui = malloc(sizeof(pause_gui_t));
    gui->game_camera = view;
    gui->game_window = window;
    gui->box = init_sprite("assets/sprite/gui/menu.png", 0);
    gui->cursor = init_sprite("assets/sprite/gui/pointer_small.png", 0);
    gui->is_selected = 0;
    gui->is_open = 0;
    gui->cursor_select = 0;
    return (gui);
}

void toggle_pause(pause_gui_t *pause)
{
    pause->is_open = !pause->is_open;
}

void destroy_pause(pause_gui_t *pause)
{

}