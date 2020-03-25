/*
** EPITECH PROJECT, 2020
** main
** File description:
** main function
*/

#include <time.h>
#include "scene/intro_screen.h"
#include "game.h"

int loop(game_t *game)
{
    void (*game_state[])(game_t *game, long int delta) = {intro_screen};
    sfClock_restart(game->clock);
    while (sfRenderWindow_isOpen(game->window)) {
        long int delta = sfClock_restart(game->clock).microseconds;
        game_state[game->current_state](game, delta);
        sfRenderWindow_display(game->window);
    }
    return (1);
}

int main(int ac, char **av)
{
    sfVector2f mode = {1600, 800};
    game_t *game = init_game(mode, "Paint Defender");
    srand(time(0));
    deserialize_player();
    loop(game);
    dispose_game(game);
    return (0);
}