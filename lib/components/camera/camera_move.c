/*
** EPITECH PROJECT, 2020
** camera_move
** File description:
** camera_move function
*/

#include "game.h"

void handle_move_camera(game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        sfView_move(game->camera, (sfVector2f){-2, 0});
        sfRenderWindow_setView(game->window, game->camera);
    }
    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        sfView_move(game->camera, (sfVector2f){2, 0});
        sfRenderWindow_setView(game->window, game->camera);
    }
    if (sfKeyboard_isKeyPressed(sfKeyS)) {
        sfView_move(game->camera, (sfVector2f){0, 2});
        sfRenderWindow_setView(game->window, game->camera);
    }
    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        sfView_move(game->camera, (sfVector2f){0, -2});
        sfRenderWindow_setView(game->window, game->camera);
    }
}