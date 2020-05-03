/*
** EPITECH PROJECT, 2020
** end_screen
** File description:
** end_screen function
*/

#include "game.h"
#include "scene/end_screen.h"

static void update(game_t *game, end_screen_t *screen, long int delta)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed) {
            sfRenderWindow_close(game->window);
            destroy_end_screen(game, screen);
            return;
        }
        input_end_screen(game, screen);
    }
    update_end_screen(game, screen, delta);
    render_end_screen(game, screen, delta);
}

static end_screen_t *init(game_t *game)
{
    end_screen_t *screen = malloc(sizeof(end_screen_t));
    init_end_screen(game, screen);
    return (screen);
}

void destroy_end_screen(game_t *game, end_screen_t *screen)
{
    dispose_text(screen->text);
    dispose_sprite(screen->bg);
    free(screen);
}

void end_screen(game_t *game, long int delta)
{
    static end_screen_t *screen;
    if (!screen)
        screen = init(game);
    update(game, screen, delta);
}