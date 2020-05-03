/*
** EPITECH PROJECT, 2020
** end_screen_update
** File description:
** end_screen_update function
*/

#include "game.h"
#include "scene/end_screen.h"
#include "game/collision.h"

int update_end_screen(game_t *game, end_screen_t *screen, long int delta)
{
    screen->delta += delta;
}