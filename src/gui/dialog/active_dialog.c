/*
** EPITECH PROJECT, 2020
** active_dialog.c
** File description:
**  function
*/

#include "gui/dialog.h"

void set_dialog_active(dialog_t *dialog, int is_active)
{
    if (!dialog)
        return;
    dialog->is_active = is_active;
}

void toggle_dialog_active(dialog_t *dialog)
{
    if (!dialog)
        return;
    dialog->is_active = !dialog->is_active;
}