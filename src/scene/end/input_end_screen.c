/*
** EPITECH PROJECT, 2020
** end_screen_input
** File description:
** end_screen_input function
*/

#include "game.h"
#include "scene/end_screen.h"

int input_end_screen(game_t *game, end_screen_t *screen)
{
    if (game->event.type == sfEvtKeyPressed) {
        if (game->event.key.code == sfKeyL)
            sfRenderWindow_close(game->window);
    }
}