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
    dispose_text(settings->title);
    dispose_text(settings->text);
    dispose_text(settings->current_dialog);
    dispose_text(settings->current_frame);
    dispose_text(settings->quit);
    dispose_fade(settings->fade);
    dispose_sprite(settings->cursor);
    dispose_sprite(settings->box);
    dispose_sprite(settings->bg);
    destroy_dialog(settings->dialog);
    free(settings);
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