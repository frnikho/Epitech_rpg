/*
** EPITECH PROJECT, 2020
** set_dialog_text.c
** File description:
**  function
*/

#include <gui/dialog.h>

void set_dialog_text(dialog_t *dialog, char **text)
{
    if (!dialog)
        return;
    dialog->text = text;
}