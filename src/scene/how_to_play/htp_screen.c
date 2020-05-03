/*
** EPITECH PROJECT, 2020
** htp_screen.c
** File description:
**  function
*/

#include "scene/how_to_play_scene.h"
#include "game.h"

static htp_scene_t *init(game_t *game)
{
    game->code = 0;
    htp_scene_t *htp = malloc(sizeof(htp_scene_t));
    init_htp_screen(game, htp);
    return (htp);
}

void destroy_how_to_play(game_t *game, htp_scene_t *htp)
{
    htp->delta = 0;
    dispose_text(htp->text);
    dispose_sprite(htp->cursor);
    dispose_sprite(htp->box);
    dispose_sprite(htp->bg);
    free(htp);
}

static void update_htp(game_t *game, htp_scene_t *screen_htp, long int delta)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed) {
            sfRenderWindow_close(game->window);
            destroy_how_to_play(game, screen_htp);
            return;
        }
        input_htp_screen(game, screen_htp);
    }
    update_htp_screen(game, screen_htp, delta);
    render_htp_screen(game, screen_htp, delta);
}

void how_to_play(game_t *game, long int delta)
{
    static htp_scene_t *htp;
    if (!htp || game->code == GAMECODE_RESET)
        htp = init(game);
    update_htp(game, htp, delta);
}