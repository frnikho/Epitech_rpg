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
    game->code = 0;
    init_settings_screen(game, settings);
    return (settings);
}

void dispose_settings_screen(settings_screen_t *settings)
{
    settings->is_active = 0;
    settings->select_cursor = 0;
    sfVector2f pos = {1600*10, 800*10};
    settings->fade = init_fade(pos, sfBlack, 1, FADE_OUT);
}

void update(game_t* g, settings_screen_t *s, long int delta)
{
    while (sfRenderWindow_pollEvent(g->window, &g->event)) {
        if (g->event.type == sfEvtClosed) {
            dispose_settings_screen(s);
            sfRenderWindow_close(g->window);
            return;
        }
        input_settings_screen(g, s);
    }
    if (g->current_state != SETTINGS)
        return;
    render_settings_screen(g, s, delta);
    update_settings_screen(g, s, delta);
}

void settings_screen(game_t *game, long int delta)
{
    static settings_screen_t *settings;
    if (!settings || game->code == GAMECODE_RESET)
        settings = init(game);
    update(game, settings, delta);
}