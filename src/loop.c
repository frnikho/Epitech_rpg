/*
** EPITECH PROJECT, 2020
** loop.c
** File description:
** main loop function
*/

#include "game.h"
#include "scene/main_menu.h"
#include "scene/settings.h"
#include "scene/battle.h"
#include "scene/overworld.h"
#include "scene/end_screen.h"
#include "scene/how_to_play_scene.h"

void update_scene(game_t *game, long int delta)
{
    switch (game->current_state) {
    case MAIN_MENU:
        main_menu(game, delta);
        break;
    case BATTLE:
        battle_screen(game, delta);
        break;
    case SETTINGS:
        settings_screen(game, delta);
        break;
    case OVERWORLD:
        overworld(game, delta);
        break;
    case HOW_TO_PLAY:
        how_to_play(game, delta);
        break;
    case END_SCREEN:
        end_screen(game, delta);
    }
}

int loop(game_t *game)
{
    long int delta = 0;
    void (*useless[])(game_t *, long int) = \
    {main_menu, battle_screen, settings_screen, overworld};

    while (sfRenderWindow_isOpen(game->window)) {
        delta = sfClock_restart(game->clock).microseconds;
        update_scene(game, delta);
        if (game->player->in_teleportation) {
            sfRenderWindow_setTitle(game->window, \
            "Dragon EpiQuest - Loading ...");
        } else {
            sfRenderWindow_setTitle(game->window, "Dragon EpiQuest");
        }
        sfRenderWindow_display(game->window);
    }
    return (1);
}