/*
** EPITECH PROJECT, 2020
** main
** File description:
** main function
*/

#include <time.h>
#include "scene/main_menu.h"
#include "scene/settings.h"
#include "scene/intro_screen.h"
#include "scene/battle.h"
#include "scene/overworld.h"
#include "game.h"

int loop(game_t *game)
{
    void (*game_state[])(game_t *game, long int delta) =
    {intro_screen, main_menu, battle_screen, settings_screen, overworld};

    sfClock_restart(game->clock);
    while (sfRenderWindow_isOpen(game->window)) {
        long int delta = sfClock_restart(game->clock).microseconds;
        game_state[game->current_state](game, delta);
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

int main(int ac, char **av)
{
    sfVector2f mode = {1600, 800};
    game_t *game = init_game(mode, "Dragon EpiQuest - Loading ...");
    game->player = create_player();
    set_player_position(game->player, (sfVector2f){500, 500});
    srand(time(0));
    loop(game);
    serialize_player(game->player);
    dispose_game(game);
    return (0);
}