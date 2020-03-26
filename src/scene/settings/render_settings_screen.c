/*
** EPITECH PROJECT, 2020
** render_settings_screen.c
** File description:
**  function
*/

#include "game.h"
#include "scene/settings.h"

int render_settings_screen(game_t *game, settings_screen_t *s, long int delta)
{
    draw_sprite(game->window, s->bg);
    draw_sprite(game->window, s->box);
    draw_text(game->window, s->title);
    draw_text(game->window, s->text);
    draw_text(game->window, s->current_frame);
    draw_text(game->window, s->current_dialog);
    draw_sprite(game->window, s->cursor);
    draw_dialog(game->window, s->dialog);
    draw_fade(game->window, s->fade);
}