/*
** EPITECH PROJECT, 2020
** main_menu
** File description:
** main_menu function
*/

#include <scene/main_menu.h>
#include "game.h"

static void update(game_t *game, main_menu_t *screen, long int delta)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed) {
            sfRenderWindow_close(game->window);
            destroy_main_menu(game, screen);
            return;
        }
        input_main_menu(game, screen);
    }
    update_main_menu(game, screen, delta);
    render_main_menu(game, screen, delta);
}

static main_menu_t *init(game_t *game)
{
    game->code = 0;
    main_menu_t *screen = malloc(sizeof(main_menu_t));
    init_main_menu(game, screen);
    return (screen);
}

void destroy_main_menu(game_t *game, main_menu_t *screen)
{
    screen->select_index = 0;
    screen->is_selected = 0;
    screen->delta = 0;
    dispose_text(screen->text);
    dispose_sprite(screen->cursor);
    dispose_sprite(screen->box);
    dispose_sprite(screen->bg);
    free(screen);
}

void main_menu(game_t *game, long int delta)
{
    printf("main menu call\n");
    static main_menu_t *screen;
    if (!screen || game->code == GAMECODE_RESET)
        screen = init(game);
    update(game, screen, delta);
}