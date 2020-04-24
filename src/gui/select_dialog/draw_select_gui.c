/*
** EPITECH PROJECT, 2020
** draw_select_gui.c
** File description:
**  function
*/

#include <gui/select_gui.h>

void draw_select_gui(sfRenderWindow *window, select_gui_t *gui)
{
    sfColor grey = sfColor_fromRGBA(87, 89, 93, 255);

    draw_sprite(window, gui->gui);
    for (int i = 0; gui->monsters_name[i] != 0; i++) {
        if (!gui->monsters[i]->is_alive) {
            set_text_color(gui->monsters_name[i], grey);
        }
        draw_text(window, gui->monsters_name[i]);
    }
    if (gui->is_active)
        draw_sprite(window, gui->cursor);
}