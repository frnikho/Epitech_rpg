/*
** EPITECH PROJECT, 2020
** init_settings_screen.c
** File description:
**  function
*/

#include "lib/utils/string.h"
#include "game.h"
#include "scene/settings.h"

static void init_settings_text(game_t *game, settings_screen_t *settings)
{
    settings->title = init_text("Settings", 28, (sfVector2f){760, 80});
    set_text_font(settings->title, "assets/font/dq.ttf");
    sfVector2f p = {500, 200};
    char *framerate = "Framerate:\n\n\t30\t\t50\t\t60\t\t144\t\t240\n\n\n\n";
    char *dialog = "Dialog Speed\n\n\t1\t\t2\t\t3\n\n";
    char *text = str_cat(framerate, dialog);
    settings->text = init_text(text, 20, p);

    char *cf = str_cat("* ", convert_str(game->config.framerate));
    settings->current_frame = init_text(cf, 16, (sfVector2f){1120, 260});
    sfText_setStyle(settings->current_frame->text, sfTextItalic);
    set_text_font(settings->text, "assets/font/dq.ttf");
    set_text_font(settings->current_frame, "assets/font/dq.ttf");

    char *cd = str_cat("* ", convert_str(game->config.dialog_speed));
    settings->current_dialog = init_text(cd, 16, (sfVector2f){1120, 420});
    sfText_setStyle(settings->current_dialog->text, sfTextItalic);
    set_text_font(settings->text, "assets/font/dq.ttf");
    set_text_font(settings->current_dialog, "assets/font/dq.ttf");
}

int init_settings_screen(game_t *game, settings_screen_t *settings)
{
    settings->select_cursor = 0;
    settings->is_active = 0;
    settings->bg = init_sprite("assets/sprite/bg.png", 0);
    set_sprite_scale(settings->bg, (float) 1.2);
    settings->box = init_sprite("assets/sprite/gui/box_settings.png", 0);
    set_sprite_position(settings->box, (sfVector2f){400, 50});
    settings->cursor = init_sprite("assets/sprite/gui/pointer_big.png", 0);
    set_sprite_position(settings->cursor, (sfVector2f){490, 259});
    init_settings_text(game, settings);
    char *tmp = "configuration sauvegardee";
    char **dialog = str_split(tmp, '#');
    settings->dialog = create_dialog(dialog, 1, (sfVector2f) GUI_POS, 1);
    sfVector2f pos = {1600*10, 800*10};
    settings->fade = init_fade(pos, sfBlack, 1, FADE_OUT);
    settings->quit = init_text("Sauvegarder", 20, (sfVector2f){750, 690});
    set_text_font(settings->quit, FONT);
}