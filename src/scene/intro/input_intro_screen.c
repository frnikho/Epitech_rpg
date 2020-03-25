/*
** EPITECH PROJECT, 2020
** intro_screen_input
** File description:
** intro_screen_input function
*/

#include "game.h"
#include "scene/intro_screen.h"

int input_intro_screen(game_t *game, intro_screen_t *screen)
{
    if (game->event.type == sfEvtKeyPressed) {
        if (!screen->dialog->is_active && !screen->dialog->is_finished)
            screen->dialog->is_active = 1;
        else
            update_dialog_line(screen->dialog);
    }
}