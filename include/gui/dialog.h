/*
** EPITECH PROJECT, 2020
** dialog.h
** File description:
**  function
*/

#ifndef DEFENDER_DIALOG_H
#define DEFENDER_DIALOG_H

#define GUI_POS {420, 640}

#include "lib/components/anim_sprite.h"
#include "lib/components/sound.h"
#include "lib/components/text.h"
#include "lib/components/sprite.h"

typedef struct dialog_s {
    long int delta;
    sprite_t *box;
    text_t *msg;
    anim_sprite_t *dot;
    sound_t *sound;
    char **text;
    int speed;
    int line_finish;
    int index_msg;
    int index_line;
    int is_finished;
    int is_active;
} dialog_t;

dialog_t *create_dialog(char **text, int pitch, sfVector2f pos, int speed);
void destroy_dialog(dialog_t *dialog);
void draw_dialog(sfRenderWindow *window, dialog_t *dialog);
void set_dialog_active(dialog_t *dialog, int is_active);
void toggle_dialog_active(dialog_t *dialog);
void set_dialog_text(dialog_t *dialog, char **text);
void update_dialog(dialog_t *dialog, long int delta);
void update_dialog_line(dialog_t *dialog);
void reset_dialog(dialog_t *dialog, char **str, int p, sfVector2f pos);

#endif
