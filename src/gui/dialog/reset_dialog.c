/*
** EPITECH PROJECT, 2020
** reset_dialog.c
** File description:
**  function
*/

#include "gui/dialog.h"

void reset_dialog(dialog_t *dialog, char **str, int p, sfVector2f pos)
{
    destroy_dialog(dialog);
    dialog = create_dialog(str, p, pos, 1);
}

void clear_dialog(dialog_t *dialog)
{
    dialog->index_line = 0;
    dialog->index_msg = 0;
    dialog->is_finished = 0;
    dialog->is_active = 0;
    dialog->line_finish = 0;
}