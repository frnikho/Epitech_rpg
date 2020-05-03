/*
** EPITECH PROJECT, 2020
** udpate_dialog.c
** File description:
**  function
*/

#include "lib/utils/string.h"
#include "gui/dialog.h"

static void update_text_dialog(dialog_t *d)
{
    char *new;
    if (d->text[d->index_line] == 0) {
        d->is_finished = 1;
        dispose_sound(d->sound);
        d->is_active = 0;
        return;
    }
    if (d->text[d->index_line][d->index_msg] == 0) {
        d->line_finish = 1;
        return;
    }
    new = str_cat_char(d->msg->title, d->text[d->index_line][d->index_msg]);
    d->msg->title = new;
    play_sound(d->sound, 60);
    d->index_msg++;
}

void update_dialog(dialog_t *dialog, long int delta)
{
    if (!dialog || !dialog->is_active)
        return;
    dialog->delta += delta;
    update_anim_sprite(dialog->dot, delta);
    if (dialog->dot->delta > 80000) {
        dialog->dot->delta = 0;
        update_anim_sprite_rect(dialog->dot);
    }
    int t = 50000;
    if (dialog->delta >= t && !dialog->is_finished && !dialog->line_finish) {
        dialog->delta = 0;
        update_text_dialog(dialog);
    }
}

void update_dialog_line(dialog_t *dialog)
{
    if (!dialog || !dialog->is_active || dialog->is_finished)
        return;
    if (!dialog->line_finish) {
        dialog->msg->title = dialog->text[dialog->index_line];
        dialog->line_finish = 1;
        return;
    }
    if (dialog->line_finish) {
        dialog->msg->title = "";
        dialog->line_finish = 0;
        dialog->index_line++;
    }
    dialog->index_msg = 0;
}