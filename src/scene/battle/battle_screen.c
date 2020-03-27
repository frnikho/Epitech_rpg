/*
** EPITECH PROJECT, 2020
** battle_screen.c
** File description:
**  function
*/

#include "game.h"
#include "scene/battle.h"

static battle_screen_t *init(game_t *game)
{
    battle_screen_t *battle = malloc(sizeof(battle_screen_t));
    if (!battle)
        return (0);
    init_battle_screen(game, battle);
    return (battle);
}

void dispose_battle_screen(game_t *game, battle_screen_t *battle)
{

}

static void update(game_t *game, battle_screen_t *battle, long int delta)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed) {
            sfRenderWindow_close(game->window);
            dispose_battle_screen(game, battle);
            return;
        }
        input_battle_screen(game, battle);
    }
    update_battle_screen(game, battle, delta);
    render_battle_screen(game, battle, delta);
}

void battle_screen(game_t *game, long int delta)
{
    static battle_screen_t *battle;
    if (!battle) {
        battle = init(game);
        if (!battle)
            return;
    }
    update(game, battle, delta);
}