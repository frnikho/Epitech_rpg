/*
** EPITECH PROJECT, 2020
** settings_screen.c
** File description:
**  function
*/

#include "scene/settings.h"
#include "game.h"

settings_screen_t *init(game_t *game)
{
    settings_screen_t *settings = malloc(sizeof(settings_screen_t));
    init_settings_screen(game, settings);
    return (settings);
}

void dispose_settings_screen(settings_screen_t *settings)
{
    dispose_sprite(settings->cursor);
    dispose_sprite(settings->box);
    dispose_sprite(settings->bg);
    free(settings);
}

void update(game_t* g, settings_screen_t *s, long int delta)
{
    while(sfRenderWindow_pollEvent(g->window, &g->event)) {
        if (g->event.type == sfEvtClosed) {
            //dispose_settings_screen(s);
            sfRenderWindow_close(g->window);
            return;
        }
        input_settings_screen(g, s);
    }
    update_settings_screen(g, s, delta);
    render_settings_screen(g, s, delta);
}

void settings_screen(game_t *game, long int delta)
{
    static settings_screen_t *settings;
    if (!settings)
        settings = init(game);
    update(game, settings, delta);
}