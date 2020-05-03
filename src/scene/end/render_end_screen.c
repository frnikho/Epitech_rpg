/*
** EPITECH PROJECT, 2020
** end_screen_render
** File description:
** end_screen_render function
*/

#include "game.h"
#include "scene/end_screen.h"

int render_end_screen(game_t *game, end_screen_t *screen, long int delta)
{
    if (game->current_state != END_SCREEN)
        return (0);
    sfRenderWindow_clear(game->window, sfBlack);
    draw_sprite(game->window, screen->bg);
    draw_text(game->window, screen->text);
}