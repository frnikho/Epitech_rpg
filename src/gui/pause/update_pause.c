/*
** EPITECH PROJECT, 2020
** update_pause.c
** File description:
** update pause function
*/

#include "gui/pause_gui.h"

void update_pause(pause_gui_t *pause, long int delta)
{
    sfVector2i box_point = {100, 200};

    sfVector2f pos = sfRenderWindow_mapPixelToCoords(pause->game_window, box_point, pause->game_camera);
    set_sprite_position(pause->box, pos);
}