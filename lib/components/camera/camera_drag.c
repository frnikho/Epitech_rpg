/*
** EPITECH PROJECT, 2020
** camera_drag
** File description:
** camera_drag function
*/

#include "game.h"

void drag_camera(game_t *game)
{
    static int mouse_click = 0;
    sfVector2f old_pos;
    sfView *camera = game->camera;
    sfRenderWindow *window = game->window;
    sfEvent e = game->event;

    if (e.type == sfEvtMouseButtonPressed) {
        mouse_click = 1;
        sfVector2i p = {e.mouseButton.x, e.mouseButton.y};
        old_pos = sfRenderWindow_mapPixelToCoords(window, p, camera);
    }
    if (e.type == sfEvtMouseButtonReleased)
        mouse_click = 0;
    if (mouse_click) {
        sfVector2i p = {e.mouseButton.x, e.mouseButton.y};
        sfVector2f v = sfRenderWindow_mapPixelToCoords(window, p, camera);
        sfVector2f delta_pos = {old_pos.x - v.x - old_pos.y - v.y};
        sfView_setCenter(camera, delta_pos);
        sfRenderWindow_setView(window, camera);
    }
}