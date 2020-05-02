/*
** EPITECH PROJECT, 2020
** pause_gui.h
** File description:
** pause gui function
*/

#ifndef MY_RPG_PAUSE_GUI_H
#define MY_RPG_PAUSE_GUI_H

#include <lib/components/text.h>
#include "lib/components/sprite.h"

typedef struct pause_gui_s {
    int cursor_select;
    int is_selected;
    int is_open;
    sfRenderWindow *window;
    sfView *camera;
    sprite_t *box;
    sprite_t *cursor;

    text_t *resume;
    text_t *equipements;
    text_t *quit;
    text_t *main_menu;
} pause_gui_t;

pause_gui_t *create_pause(sfRenderWindow *window, sfView *view);
void destroy_pause(pause_gui_t *pause);
void draw_pause(pause_gui_t *gui, sfRenderWindow *window, long int delta);
void update_pause(pause_gui_t *pause, long int delta);
void toggle_pause(pause_gui_t *pause);
int handle_pause(pause_gui_t *gui, sfEvent event);

#endif