/*
** EPITECH PROJECT, 2020
** intro_screen_init
** File description:
** main_menu_init function
*/

#include "game.h"
#include "scene/main_menu.h"

int init_main_menu(game_t *game, main_menu_t *menu)
{
    menu->delta = 0;
    menu->select_index = 0;
    menu->is_selected = 0;
    menu->bg = init_sprite("assets/sprite/background/main_menu_bg.jpg", 0);
    menu->cursor = init_sprite("assets/sprite/gui/pointer_big.png", 0);
    set_sprite_scale(menu->cursor, 1.2);
    menu->box = init_sprite("assets/sprite/gui/select_enemy_gui.png", 0);
    set_sprite_position(menu->box, (sfVector2f){550, 415});
    menu->text = init_text("Continuer\n\nNouvelle partie\n\nParametres\n\nHow to Play", 20, (sfVector2f){640, 420});
    set_text_font(menu->text, FONT);
    set_sprite_scale(menu->bg, 0.9);
    return (0);
}