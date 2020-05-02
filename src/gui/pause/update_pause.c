/*
** EPITECH PROJECT, 2020
** update_pause.c
** File description:
** update pause function
*/

#include "gui/pause_gui.h"

static void update_cursor(pause_gui_t *pause)
{
    static sfVector2i pos[] = {{120, 235}, {120, 275},  {120, 315}, {0, 0}};
    if (pause->cursor_select < 0)
        pause->cursor_select = 0;
    if (pause->cursor_select > 2)
        pause->cursor_select = 2;
    sfVector2i tmp = pos[pause->cursor_select];
    sfVector2f rf;
    rf = sfRenderWindow_mapPixelToCoords(pause->window, tmp, pause->camera);
    set_sprite_position(pause->cursor, rf);
}


void update_pause(pause_gui_t *pause, long int delta)
{
    sfVector2i bp = {100, 200};
    sfVector2i tp = {150, 230};
    update_cursor(pause);
    sfVector2f pos;
    pos = sfRenderWindow_mapPixelToCoords(pause->window, bp, pause->camera);
    set_sprite_position(pause->box, pos);
    pos = sfRenderWindow_mapPixelToCoords(pause->window, tp, pause->camera);
    pause->resume->position = pos;
    tp.y += 40;
    pos = sfRenderWindow_mapPixelToCoords(pause->window, tp, pause->camera);
    pause->main_menu->position = pos;
    tp.y += 40;
    pos = sfRenderWindow_mapPixelToCoords(pause->window, tp, pause->camera);
    pause->quit->position = pos;
    tp.y += 40;
}