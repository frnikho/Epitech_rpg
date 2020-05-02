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
    gui->camera = view;
    gui->window = window;
    gui->box = init_sprite("assets/sprite/gui/menu.png", 0);
    set_sprite_scale(gui->box, 1.4f);
    gui->cursor = init_sprite("assets/sprite/gui/pointer_small.png", 0);
    set_sprite_scale(gui->cursor, 1.4f);
    gui->is_selected = 0;
    gui->is_open = 0;
    gui->cursor_select = 0;
    gui->quit = init_text("Quitter", 17, (sfVector2f){0, 0});
    gui->resume = init_text("Continuer", 17, (sfVector2f){0, 0});
    gui->main_menu = init_text("Menu principal", 17, (sfVector2f){0, 0});
    set_text_font(gui->quit, FONT);
    set_text_font(gui->resume, FONT);
    set_text_font(gui->main_menu, FONT);
    return (gui);
}

void toggle_pause(pause_gui_t *pause)
{
    pause->is_open = !pause->is_open;
}

void destroy_pause(pause_gui_t *pause)
{

}