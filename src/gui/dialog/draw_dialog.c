/*
** EPITECH PROJECT, 2020
** draw_dialog.c
** File description:
**  function
*/

#include "gui/dialog.h"

void draw_dialog(sfRenderWindow *window, dialog_t *dialog)
{
    if (!dialog || !dialog->is_active)
        return;
    draw_sprite(window, dialog->box);
    draw_text(window, dialog->msg);
    draw_anim_sprite(window, dialog->dot);
}