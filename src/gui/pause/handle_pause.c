/*
** EPITECH PROJECT, 2020
** handle_pause.c
** File description:
** handle pause function
*/

#include "gui/pause_gui.h"

static void handle_selection(pause_gui_t *pause)
{
    if (pause->cursor_select == 0) {
        pause->is_selected = 0;
        pause->is_open = 0;
        pause->cursor_select = 0;
    }
    if (pause->cursor_select == 2)
        sfRenderWindow_close(pause->window);
}

int handle_pause(pause_gui_t *gui, sfEvent event)
{
    if (!gui->is_open || event.type != sfEvtKeyPressed)
        return (0);
    sfKeyCode code = event.key.code;
    if (code == sfKeyZ || code == sfKeyQ)
        gui->cursor_select--;
    if (code == sfKeyS || code == sfKeyD)
        gui->cursor_select++;
    if (code == sfKeyEnter || code == sfKeySpace)
        gui->is_selected = 1;
    if (gui->is_selected)
        handle_selection(gui);
    return (1);
}