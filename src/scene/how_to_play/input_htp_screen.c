/*
** EPITECH PROJECT, 2020
** input_htp_screen.c
** File description:
**  function
*/

#include "game.h"
#include "scene/how_to_play_scene.h"

int input_htp_screen(game_t *game, htp_scene_t *htp)
{
    
}

void event_key_pressed_htp(game_t *game, htp_scene_t *htp)
{
    sfKeyEvent key = game->event.key;
    if (key.code == sfKeyL)
        sfRenderWindow_close(game->window);
    if (key.code == sfKeyEnter || key.code == sfKeySpace) {
        destroy_how_to_play(game, htp);
        game->current_state = MAIN_MENU;
    }
}