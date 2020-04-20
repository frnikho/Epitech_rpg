/*
** EPITECH PROJECT, 2020
** intro_screen_input
** File description:
** intro_screen_input function
*/

#include "game.h"
#include "scene/main_menu.h"
#include "lib/components/pad.h"

int input_main_menu(game_t *game, main_menu_t *screen)
{
    sfEventType evt = game->event.type;
    if (screen->is_selected)
        return (0);
    if (evt == sfEvtJoystickMoved || evt == sfEvtKeyPressed) {
        if (game->event.key.code == sfKeyZ || (pad_arrow() == PAD_UP))
            screen->select_index--;
        if (game->event.key.code == sfKeyS || (pad_arrow() == PAD_DOWN))
            screen->select_index++;
        if (game->event.key.code == sfKeySpace || pad_pressed(PAD_A))
            screen->is_selected = 1;
    }
    return (0);
}