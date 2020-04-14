/*
** EPITECH PROJECT, 2020
** intro_screen_input
** File description:
** intro_screen_input function
*/

#include "game.h"
#include "scene/main_menu.h"

int input_main_menu(game_t *game, main_menu_t *screen)
{
    if (screen->is_selected)
        return (0);
    if (game->event.type == sfEvtKeyPressed) {
        if (game->event.key.code == sfKeyZ)
            screen->select_index--;
        if (game->event.key.code == sfKeyS)
            screen->select_index++;
        if (game->event.key.code == sfKeySpace)
            screen->is_selected = 1;
    }
    return (0);
}