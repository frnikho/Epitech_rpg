/*
** EPITECH PROJECT, 2020
** init_htp_screen.c
** File description:
**  function
*/

#include "game.h"
#include "scene/how_to_play_scene.h"

int init_htp_screen(game_t *game, htp_scene_t *htp)
{
    htp->bg = init_sprite("assets/sprite/gui/htp.png", 0);
    return (0);
}
