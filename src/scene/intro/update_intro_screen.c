/*
** EPITECH PROJECT, 2020
** intro_screen_update
** File description:
** intro_screen_update function
*/

#include "game.h"
#include "scene/intro_screen.h"
#include "game/collision.h"

int update_intro_screen(game_t *game, intro_screen_t *screen, long int delta)
{
    screen->delta += delta;
    update_player(game->player, delta);
    update_inventory(game->player->inventory, delta);
    if (game->player->inventory->is_open)
        return (0);
    if (move_player(game->player, screen->npc, delta)) {
        //block_move_on_collision(game->player, screen->npc, delta);
        sfView_setCenter(game->camera, get_player_position(game->player));
        sfRenderWindow_setView(game->window, game->camera);
    }
    //block_move_on_collision(game->player, screen->npc, delta);
}