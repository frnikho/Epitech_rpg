/*
** EPITECH PROJECT, 2020
** main_menu_screen
** File description:
** header file
*/

#ifndef DEFENDER_MAIN_MENU_H
#define DEFENDER_MAIN_MENU_H

#include "game.h"

typedef struct main_menu_s {
    long int delta;
    int select_index;
    int is_selected;
    sprite_t *cursor;
    sprite_t *bg;
    sprite_t *box;
    text_t *text;
} main_menu_t;

void main_menu(game_t *game, long int delta);
void destroy_main_menu(game_t *game, main_menu_t *menu);
int init_main_menu(game_t *game, main_menu_t *menu);
int input_main_menu(game_t *game, main_menu_t *menu);
int update_main_menu(game_t *game, main_menu_t *menu, long int delta);
int render_main_menu(game_t *game, main_menu_t *menu, long int delta);

#endif