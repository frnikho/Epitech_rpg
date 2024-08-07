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
#define RESET_CODE 500

#include "gui/dialog.h"
#include "lib/components/sound.h"
#include "gui/attack_gui.h"
#include "gui/select_gui.h"
#include "game/monster.h"
#include "game/player.h"
#include "lib/effects/fade.h"
#include "game/spell.h"
#include "lib/effects/particle.h"

typedef struct round_s {
    sfVector2i *order;
    int order_index;
    int code;
} round_t;

typedef struct battle_bg_s {
    int zone_code;
    char *fp;
} battle_bg_t;

typedef struct spell_gui {
    sprite_t *box;
    spell_t *spell;
    int is_selected;
    int cursor;

} spell_gui_t;

typedef struct battle_screen_s {
    int select_choice;
    int attacking;
    int code;
    monster_t **monster;
    sprite_t *bg;
    attack_gui_t *attack_gui;
    select_gui_t *select_gui;
    sound_t *music;
    dialog_t *dialog;
    round_t round;
    fade_t *fade_in;
    fade_t *fade_out;
    spell_gui_t spell_gui;
    particle_system_t *particle_system;
} battle_screen_t;

void battle_screen(game_t *game, long int delta);
void dispose_battle_screen(game_t *game, battle_screen_t *battle);
int init_battle_screen(game_t *game, battle_screen_t *battle);
void init_battle_screen_bg(game_t *game, battle_screen_t *battle);
int input_battle_screen(game_t *game, battle_screen_t *battle);
int update_battle_screen(game_t *game, battle_screen_t *battle, long int delta);
void update_attack_battle_screen(game_t *g, battle_screen_t *b, long int d);
int render_battle_screen(game_t *game, battle_screen_t *battle, long int delta);
void reset_battle_gui(game_t *game, battle_screen_t *battle);
int end_battle_screen(game_t *g, battle_screen_t *b, long int delta);
void check_run_away(game_t *game, battle_screen_t *battle, long int delta);
int run_away(battle_screen_t *battle, game_t *game);
int try_run_away(game_t *game, battle_screen_t *battle);
void tension(game_t *game, battle_screen_t *battle, int *streak);
int add_tension(game_t *game, battle_screen_t *battle, int streak);
int check_player_dead(game_t *g, battle_screen_t *b, long int delta);
void check_attack_monster(game_t *g, battle_screen_t *b, int selected);
void check_attack_player(game_t *g, battle_screen_t *b, int selected);
int check_monsters_is_alive(game_t *game, battle_screen_t *b);

#endif