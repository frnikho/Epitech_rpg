/*
** EPITECH PROJECT, 2020
** attack_dialog.h
** File description:
**  function
*/

#ifndef MY_RPG_ATTACK_GUI_H
#define MY_RPG_ATTACK_GUI_H

#include "game/monster.h"
#include "lib/components/sprite.h"
#include "lib/components/text.h"

#define SELECT_ATTACK 0
#define SELECT_DEFENSE 1
#define SELECT_MAGIC 2
#define SELECT_TENSION 5
#define SELECT_RUN_AWAY 4

typedef struct attack_gui_s {
    int select_index;
    int is_selected;
    sprite_t *box;
    sprite_t *cursor;

    text_t *attack;
    text_t *spells;
    text_t *abilities;
    text_t *objects;
    text_t *goaway;
    text_t *tension;

} attack_gui_t;

attack_gui_t *create_attack_gui(monster_t **monster);
void destroy_attack_gui(attack_gui_t *gui);
void draw_attack_gui(sfRenderWindow *window, attack_gui_t *gui);
void handle_attack_gui(attack_gui_t *gui, sfEvent event);
void update_attack_gui(attack_gui_t *gui, long int delta);
int compare_color(sfColor selected, sfColor grey);

#endif