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
    if (game->event.type != sfEvtKeyPressed)
        return (0);
    sfKeyCode code = game->event.key.code;
    if (code == sfKeyEscape)
        game->current_state = MAIN_MENU;
}