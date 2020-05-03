/*
** EPITECH PROJECT, 2020
** intro_screen
** File description:
** intro_screen function
*/

#include "game.h"
#include "scene/intro_screen.h"

static void update(game_t *game, intro_screen_t *screen, long int delta)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed) {
            sfRenderWindow_close(game->window);
            destroy_intro_screen(game, screen);
            return;
        }
        input_intro_screen(game, screen);
    }
    update_intro_screen(game, screen, delta);
    render_intro_screen(game, screen, delta);
}

static intro_screen_t *init(game_t *game)
{
    intro_screen_t *screen = malloc(sizeof(intro_screen_t));
    init_intro_screen(game, screen);
    return (screen);
}

void destroy_intro_screen(game_t *game, intro_screen_t *screen)
{
    free(screen);
}

void intro_screen(game_t *game, long int delta)
{
    static intro_screen_t *screen;
    if (!screen)
        screen = init(game);
    update(game, screen, delta);
}