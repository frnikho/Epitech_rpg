/*
** EPITECH PROJECT, 2020
** render_htp_screen.c
** File description:
**  function
*/

#include "game.h"
#include "how_to_play_scene.h"

int render_settings_screen(game_t *game, htp_scene_t *htp, long int delta)
{
    draw_sprite(game->window, htp->bg);
    draw_sprite(game->window, htp->box);
    draw_text(game->window, htp->title);
    draw_text(game->window, htp->text);
    draw_sprite(game->window, htp->cursor);
}