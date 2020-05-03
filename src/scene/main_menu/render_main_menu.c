/*
** EPITECH PROJECT, 2020
** intro_screen_render
** File description:
** render main menu
*/

#include "scene/main_menu.h"
#include "game.h"

int render_main_menu(game_t *game, main_menu_t *menu, long int delta)
{
    if (game->current_state != MAIN_MENU)
        return (0);
    sfView_setCenter(game->camera, (sfVector2f){800, 400});
    sfRenderWindow_setView(game->window, game->camera);
    sfRenderWindow_clear(game->window, sfBlack);
    draw_sprite(game->window, menu->bg);
    draw_sprite(game->window, menu->box);
    draw_text(game->window, menu->text);
    draw_sprite(game->window, menu->cursor);
}