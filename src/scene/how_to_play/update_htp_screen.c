/*
** EPITECH PROJECT, 2020
** update_htp_screen.c
** File description:
**  function
*/

#include "game.h"
#include "how_to_play_scene.h"

int update_htp_screen(game_t *game, htp_scene_t *htp, long int delta)
{
    set_sprite_position(htp->cursor, (sfVector2f){10, 10});
}