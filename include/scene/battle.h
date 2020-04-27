/*
** EPITECH PROJECT, 2020
** battle.h
** File description:
**  function
*/

#ifndef MY_RPG_BATTLE_H
#define MY_RPG_BATTLE_H

#define PLAYER_INDEX 500
#define ATTACK_CODE 200

#include "gui/dialog.h"
#include "lib/components/sound.h"
#include "gui/attack_gui.h"
#include "gui/select_gui.h"
#include "game/monster.h"
#include "game/player.h"
#include "lib/effects/fade.h"

typedef struct round_s {
    sfVector2i *order;
    int order_index;
    int code;
} round_t;

typedef struct battle_screen_s {
    int select_choice;
    int attacking;
    monster_t **monster;
    sprite_t *bg;
    attack_gui_t *attack_gui;
    select_gui_t *select_gui;
    sound_t *music;
    dialog_t *dialog;
    round_t round;
    fade_t *fade_in;
    fade_t *fade_out;
} battle_screen_t;

void battle_screen(game_t *game, long int delta);
void dispose_battle_screen(game_t *game, battle_screen_t *battle);
int init_battle_screen(game_t *game, battle_screen_t *battle);
int input_battle_screen(game_t *game, battle_screen_t *battle);
int update_battle_screen(game_t *game, battle_screen_t *battle, long int delta);
void update_attack_battle_screen(game_t *g, battle_screen_t *b, long int d);
int render_battle_screen(game_t *game, battle_screen_t *battle, long int delta);
void reset_battle_gui(game_t *game, battle_screen_t *battle);
int end_battle_screen(game_t *g, battle_screen_t *b, long int delta);

#endif
