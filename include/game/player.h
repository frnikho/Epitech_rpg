/*
** EPITECH PROJECT, 2020
** game.h
** File description:
**  function
*/

#ifndef MY_RPG_PLAYER_H
#define MY_RPG_PLAYER_H

#include "lib/components/text.h"
#include "inventory.h"
#include "stats.h"
#include "npc.h"
#include "game/collision.h"

typedef struct player_gui_s {
    sprite_t *box;
    text_t *level;
    text_t *name;
    text_t *hp;
    text_t *mp;
    sfRectangleShape *hp_bar;
    sfRectangleShape *hp_shadow;
    sfRectangleShape *mp_bar;
    sfRectangleShape *mp_shadow;
} player_gui_t;

typedef struct player_s {
    long int delta;
    int health;
    int mp;
    int level;
    int xp;
    int zone;
    inventory_t *inventory;
    player_gui_t *gui;
    stats_t *stats;
    collision_box_t *collision;
    int current_animations;
    anim_sprite_t **animations;
} player_t;

player_t *create_player(void);
void debug_player(player_t *player);
player_t *deserialize_player(void);
void serialize_player(player_t *player);
void destroy_player(player_t *player);

void create_gui(player_t *player);
void draw_player_gui(sfRenderWindow *window, player_t *player);
void update_player_gui(player_t *player);
void draw_player(sfRenderWindow *window, player_t *player);
void set_player_scale(player_t *player, float scale);
void update_player(player_t *player, long int delta);
int move_player(player_t *p, npc_t **npcs, long int delta);

sfVector2f get_player_position(player_t *player);

#endif
