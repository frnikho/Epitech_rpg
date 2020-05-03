/*
** EPITECH PROJECT, 2020
** intro_screen_update
** File description:
** intro_screen_update function
*/

#include "scene/main_menu.h"
#include "game.h"

int choice_main_menu(game_t *game, main_menu_t *menu)
{
    if (menu->is_selected) {
        if (menu->select_index == 0) {
            game->current_state = OVERWORLD;
            game->player->in_teleportation = 1;
            game->restart = 1;
            game->code = RESTART_GAME;
        }
        if (menu->select_index == 1)
            game->current_state = SETTINGS;
        if (menu->select_index == 2)
            game->current_state = OVERWORLD;
        if (menu->select_index == 3) {
            sfRenderWindow_close(game->window);
            return (0);
        }
        game->code = GAMECODE_RESET;
        destroy_main_menu(game, menu);
    }
    return (1);
}

int update_main_menu(game_t *game, main_menu_t *menu, long int delta)
{
    menu->delta += delta;
    static sfVector2f pos[] = {{570, 435}, {570, 480}, {570, 535}, {570, 580}};
    if (menu->select_index < 0)
        menu->select_index = 0;
    if (menu->select_index > 3)
        menu->select_index = 3;
    set_sprite_position(menu->cursor, pos[menu->select_index]);
    if (choice_main_menu(game, menu) == 0)
        return (0);
}