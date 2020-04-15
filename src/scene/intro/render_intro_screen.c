/*
** EPITECH PROJECT, 2020
** intro_screen_render
** File description:
** intro_screen_render function
*/

#include "game.h"
#include "scene/intro_screen.h"

int render_intro_screen(game_t *game, intro_screen_t *screen, long int delta)
{
    sfRenderWindow_clear(game->window, sfBlack);
    for (int i = 0; screen->npc[i] != 0; i++)
        draw_npc(game->window, screen->npc[i]);
    draw_player(game->window, game->player);
    draw_inventory(game->window, game->camera, game->player->inventory);
}