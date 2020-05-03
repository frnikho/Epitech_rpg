/*
** EPITECH PROJECT, 2020
** main
** File description:
** main function
*/

#include <time.h>
#include "game.h"


int main(int ac, char **av)
{
    sfVector2f mode = {1600, 800};
    game_t *game = init_game(mode, "Dragon EpiQuest - Loading ...");
    game->player = create_player();
    srand(time(0));
    loop(game);
    serialize_player(game->player);
    dispose_game(game);
    return (0);
}