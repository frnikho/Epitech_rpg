/*
** EPITECH PROJECT, 2020
** draw_attack_dialog.c
** File description:
**  function
*/

#include <gui/attack_gui.h>

void draw_attack_gui(sfRenderWindow *window, attack_gui_t *gui)
{
    draw_sprite(window, gui->box);
    draw_text(window, gui->attack);
    draw_text(window, gui->habilities);
    draw_text(window, gui->spells);
    draw_text(window, gui->goaway);
    draw_text(window, gui->objects);
    draw_text(window, gui->tension);
    draw_sprite(window, gui->cursor);
}