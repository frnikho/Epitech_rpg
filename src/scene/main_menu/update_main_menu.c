/*
** EPITECH PROJECT, 2020
** intro_screen_update
** File description:
** intro_screen_update function
*/

#include "scene/main_menu.h"
#include "game.h"

int update_main_menu(game_t *game, main_menu_t *menu, long int delta)
{
    menu->delta += delta;
    static sfVector2f pos[] = {{570, 435}, {570, 480}, {570, 535}};
    if (menu->select_index < 0)
        menu->select_index = 0;
    if (menu->select_index > 2)
        menu->select_index = 2;
    set_sprite_position(menu->cursor, pos[menu->select_index]);
    if (menu->is_selected) {
        if (menu->select_index == 2)
            game->current_state = SETTINGS;
        if (menu->select_index == 1 || menu->select_index == 0)
            game->current_state = BATTLE;
        game->code = GAMECODE_RESET;
        destroy_main_menu(game, menu);
    }
}