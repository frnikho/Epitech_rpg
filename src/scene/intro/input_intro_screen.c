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
    handle_inventory(game->event, game->player->inventory);
    if (game->event.type == sfEvtKeyPressed) {
        if (game->event.key.code == sfKeyL)
            sfRenderWindow_close(game->window);
        if (game->event.key.code == sfKeyE)
            toggle_inventory(game->player->inventory);
    }
}