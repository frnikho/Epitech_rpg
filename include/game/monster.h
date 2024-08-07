/*
** EPITECH PROJECT, 2020
** monster.h
** File description:
**  function
*/

#ifndef MY_RPG_MONSTER_H
#define MY_RPG_MONSTER_H

#include <lib/components/anim_sprite.h>
#include "lib/components/sprite.h"
#include "game/stats.h"
#include "player.h"

typedef struct monster_hit_s {
    int is_active;
    long int delta;
    anim_sprite_t *stroke;
    sprite_t *damage;
} monster_hit_t;

typedef struct monster_s {
    long int delta;
    int id;
    int is_alive;
    char *name;
    sprite_t *sprite;
    stats_t *stats;
    int gains_factor;
    int stats_factor;
    int xp;
    int gold;
} monster_t;

monster_t *create_monster(char *fp, sfVector2f pos);
void dispose_monster(monster_t *monster);
void draw_monster(sfRenderWindow *window, monster_t *monster);
void update_monster(monster_t *monster, long int delta);
int get_monsters_length(monster_t **monsters);

int player_attack_monster(player_t *player, monster_t *monster);
int monster_attack_player(monster_t *monster, player_t *player);

monster_hit_t *create_monster_hit(int damage, monster_t monster);
void update_monster_hit(monster_hit_t *hit, long int delta);
void draw_monster_hit(sfRenderWindow *window, monster_hit_t *hit);

#endif