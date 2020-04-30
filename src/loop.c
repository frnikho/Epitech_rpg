/*
** EPITECH PROJECT, 2020
** loop.c
** File description:
** main loop function
*/

#include <game.h>
#include "scene/main_menu.h"
#include "scene/settings.h"
#include "scene/intro_screen.h"
#include "scene/battle.h"
#include "scene/overworld.h"

int loop(game_t *game)
{
    void (*game_state[])(game_t *game, long int delta) =
            {intro_screen, main_menu, battle_screen, settings_screen, overworld};

    sfClock_restart(game->clock);
    while (sfRenderWindow_isOpen(game->window)) {
        long int delta = sfClock_restart(game->clock).microseconds;
        game_state[game->current_state](game, delta);
        if (game->player->in_teleportation) {
            sfRenderWindow_setTitle(game->window, "Dragon EpiQuest - Loading ...");
        } else {
            sfRenderWindow_setTitle(game->window, "Dragon EpiQuest");
        }
        sfRenderWindow_display(game->window);
    }
    return (1);
}