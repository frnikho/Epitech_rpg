/*
** EPITECH PROJECT, 2020
** intro_screen_update
** File description:
** intro_screen_update function
*/

#include "game.h"
#include "scene/intro_screen.h"

int update_intro_screen(game_t *game, intro_screen_t *screen, long int delta)
{
    screen->delta += delta;
    update_dialog(screen->dialog, delta);
    for (int i = 0; screen->npc[i] != 0; i++)
        update_npc(screen->npc[i], delta);
}