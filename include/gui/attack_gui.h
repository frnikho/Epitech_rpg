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

#define SELECT_ATTACK 1
#define SELECT_DEFENSE 2
#define SELECT_MAGIC 3
#define SELECT TENSION 4
#define SELECT_GO_AWAY 5

typedef struct attack_gui_s {
    int select_index;
    int is_selected;
    sprite_t *box;
    sprite_t *cursor;

    text_t *attack;
    text_t *spells;
    text_t *habilities;
    text_t *objects;
    text_t *goaway;
    text_t *tension;

} attack_gui_t;

attack_gui_t *create_attack_gui(monster_t **monster);
void destroy_attack_gui(attack_gui_t *gui);
void draw_attack_gui(sfRenderWindow *window, attack_gui_t *gui);

#endif