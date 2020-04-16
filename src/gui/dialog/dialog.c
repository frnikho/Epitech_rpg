/*
** EPITECH PROJECT, 2020
** dialog.c
** File description:
**  function
*/

#include "gui/dialog.h"
#include "lib/components/anim_sprite.h"
#include "lib/utils/file.h"
#include "lib/utils/json_parser.h"
#include <stdlib.h>
#include <lib/utils/string.h>

static void init_dialog_sound(dialog_t *dialog, int pitch)
{
    pitch = 0;
    if (!dialog || pitch < 0)
        return;
    if (pitch == 0)
        dialog->sound = init_sound("assets/sound/gui/dialog_normal.ogg");
}

static sfIntRect *get_slime_animations(char *filepath)
{
    int fd = open_file(filepath);
    if (fd <= 0)
        return &(sfIntRect){0, 0, 0, 0};
    char *content = read_file(fd, filepath);
    int count = fget_nbr(get_key_data(content, "count"));
    sfIntRect *anim_rect = malloc(sizeof(sfIntRect) * (count + 1));
    int i = 0;
    for (; i < count; i++) {
        char *tmp = convert_str(i+1);
        char *rect = get_key_data(content, tmp);
        int x = fget_nbr(get_key_data(rect, "x"));
        int y = fget_nbr(get_key_data(rect, "y"));
        int width = fget_nbr(get_key_data(rect, "width"));
        int height = fget_nbr(get_key_data(rect, "height"));
        anim_rect[i] = (sfIntRect){x, y, width, height};
    }
    anim_rect[i] = (sfIntRect) {0, 0, 0, -9999};
    free(content);
    return (anim_rect);
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
    dialog->box = init_sprite("assets/sprite/gui/box_dialog.png", 0);
    set_sprite_position(dialog->box, pos);
    pos.x += 10;
    pos.y += 10;
    dialog->msg = init_text("", 22, pos);
    pos.x += 730;
    pos.y += 80;
    set_text_font(dialog->msg, "assets/font/dq.ttf");
    set_text_color(dialog->msg, sfWhite);
    init_dialog_sound(dialog, p);
}

dialog_t *create_dialog(char **text, int pitch, sfVector2f pos, int speed)
{
    dialog_t *dialog = malloc(sizeof(dialog_t));
    init(dialog, text, pitch, pos);
    sfVector2f gui = (sfVector2f)GUI_POS;
    sfVector2f dot_pos = {gui.x += 745, gui.y += 90};
    sfIntRect *rect = get_slime_animations("content/slime.json");
    dialog->dot = create_anim_sprite(DOT_FP, dot_pos);
    for (int i = 0; rect[i].height != -9999; i++)
        add_anim_frame(dialog->dot, rect[i]);
    return (dialog);
}

void destroy_dialog(dialog_t *dialog)
{
    for (int i = 0; dialog->text[i] != 0; i++)
        free(dialog->text[i]);
    free(dialog->text);
    dispose_sprite(dialog->box);
    dispose_text(dialog->msg);
    dispose_anim_sprite(dialog->dot);
    dispose_sound(dialog->sound);
    free(dialog);
}