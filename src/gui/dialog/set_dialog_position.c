/*
** EPITECH PROJECT, 2020
** set_dialog_position.c
** File description:
** set_dialog_position function
*/

#include "gui/dialog.h"

void set_dialog_scale(dialog_t *dialog, float scale)
{
    set_sprite_scale(dialog->box, scale);
    set_anim_sprite_scale(dialog->dot, scale);
}

void set_dialog_relative(dialog_t *dialog, sfView *view)
{
    dialog->relative = 1;
    dialog->cam = view;
    //set_dialog_scale(dialog, 0.5f);
}

void set_dialog_position(dialog_t *d, sfRenderWindow *w, sfView *v)
{
    sfVector2f p = sfRenderWindow_mapPixelToCoords(w, (sfVector2i)GUI_POS, v);
    set_sprite_position(d->box, p);
    d->msg->position = sfRenderWindow_mapPixelToCoords(w, \
(sfVector2i) {425, 650}, v);
    p.x += 745;
    p.y += 80;
    sfSprite_setPosition(d->dot->sprite, p);
}