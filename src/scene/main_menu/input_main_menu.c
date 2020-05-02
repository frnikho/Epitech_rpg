/*
** EPITECH PROJECT, 2020
** intro_screen_input
** File description:
** intro_screen_input function
*/

#include "game.h"
#include "scene/main_menu.h"
#include "lib/components/pad.h"

int is_point_in_coords(sfVector2i mouse, sfVector2i up_left, \
sfVector2i down_right, int *is_clicked)
{
    if (mouse.x >= up_left.x && mouse.x <= down_right.x) {
        if (mouse.y >= up_left.y && mouse.y <= down_right.y) {
            (*is_clicked) = 1;
            return (1);
        }    
    }
    return (0);
}

int input_main_menu(game_t *game, main_menu_t *screen)
{
    sfEventType evt = game->event.type;
    sfVector2i pos = {0, 0};
    int is_clicked = 0;

    if (screen->is_selected)
        return (0);
    if (evt == sfEvtJoystickMoved || evt == sfEvtKeyPressed) {
        if (game->event.key.code == sfKeyL)
            sfRenderWindow_close(game->window);
        if (game->event.key.code == sfKeyZ || (pad_arrow() == PAD_UP))
            screen->select_index--;
        if (game->event.key.code == sfKeyS || (pad_arrow() == PAD_DOWN))
            screen->select_index++;
        if (game->event.key.code == sfKeySpace || pad_pressed(PAD_A)) {
            stop_sound(screen->sound);
            screen->is_selected = 1;
        }
    }
    if (evt == sfEvtMouseButtonPressed) {
        pos = sfMouse_getPosition(game->window);
        if (is_point_in_coords(pos, (sfVector2i){639, 424}, \
        (sfVector2i){699, 442}, &is_clicked) == 1)
            screen->select_index = 0;
        if (is_point_in_coords(pos, (sfVector2i){639, 479}, \
        (sfVector2i){759, 495}, &is_clicked) == 1)
            screen->select_index = 1;
        if (is_point_in_coords(pos, (sfVector2i){639, 529}, \
        (sfVector2i){770, 546}, &is_clicked) == 1)
            screen->select_index = 2;
        if (is_point_in_coords(pos, (sfVector2i){639, 584}, \
        (sfVector2i){688, 595}, &is_clicked) == 1)
            screen->select_index = 3;
        if (is_clicked == 1)
            screen->is_selected = 1;
    }
    return (0);
}