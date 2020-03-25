/*
** EPITECH PROJECT, 2020
** dialog.c
** File description:
**  function
*/

#include "gui/dialog.h"
#include "lib/components/anim_sprite.h"
#include <stdlib.h>

static void init_dialog_sound(dialog_t *dialog, int pitch)
{
    pitch = 0;
    if (!dialog || pitch < 0)
        return;
    if (pitch == 0)
        dialog->sound = init_sound("assets/sound/gui/dialog_normal.ogg");
}

static void init(dialog_t *dialog, char **text, int p, sfVector2f pos)
{
    dialog->is_active = 0;
    dialog->is_finished = 0;
    dialog->delta = 0;
    dialog->index_msg = 0;
    dialog->index_line = 0;
    dialog->text = text;
    dialog->line_finish = 0;
    dialog->box = init_sprite("assets/sprite/gui/box_dialog.png");
    set_sprite_position(dialog->box, pos);
    pos.x += 10;
    pos.y += 10;
    dialog->msg = init_text("", 22, pos);
    sfIntRect slime_rect = {0, 0, 40, 48};
    anim_info_t *info = init_anim_info(slime_rect, 1, 4, 7);
    pos.x += 730;
    pos.y += 80;
    dialog->dot = init_anim_sprite("assets/sprite/king_slime_1.png", pos, info);
    set_text_font(dialog->msg, "assets/font/dq.ttf");
    set_text_color(dialog->msg, sfWhite);
    init_dialog_sound(dialog, p);
}

dialog_t *create_dialog(char **text, int pitch, sfVector2f pos, int speed)
{
    dialog_t *dialog = malloc(sizeof(dialog_t));
    init(dialog, text, pitch, pos);
    return (dialog);
}

void destroy_dialog(dialog_t *dialog)
{
    for (int i = 0; dialog->text[i] != 0; i++) {
        free(dialog->text[i]);
    }
    free(dialog->text);
    dispose_anim_sprite(dialog->dot);
    dispose_sprite(dialog->box);
    dispose_text(dialog->msg);
    dispose_sound(dialog->sound);
    free(dialog);
}