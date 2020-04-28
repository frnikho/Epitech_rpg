/*
** EPITECH PROJECT, 2020
** collision.h
** File description:
** header file
*/

#ifndef MY_RPG_COLLISION_H_
#define MY_RPG_COLLISION_H_

#include <SFML/Graphics.h>

typedef struct npc_s npc_t;
typedef struct player_s player_t;
typedef struct obstacle_s obstacle_t;
typedef struct map_s map_t;
typedef struct overworld_s overworld_t;

typedef struct collision_box_s {
    int is_active;
    int is_blocking;
    int update_on_default;
    sfFloatRect collision_box;
} collision_box_t;

typedef struct interaction_box_s {
    int is_active;
    int is_blocking;
    sfFloatRect collision_box;
    sfFloatRect shape;
    int load_map;
    int zone_act;
} interaction_box_t;

collision_box_t *create_collision_box(sfFloatRect rec, int update_on_default, int is_blocking);
int check_collision_ahead(obstacle_t **map_obs, npc_t **npcs, player_t *player, long int delta);
int block_move_on_collision(player_t *p, npc_t **n, long int d, overworld_t *world);
int check_interaction_ahead(player_t *player, overworld_t *world, long int delta);
interaction_box_t *create_interaction_box(sfFloatRect rec, int is_blocking, \
int load_zone, int zone_act);
int is_rectangles_in_collision(sfFloatRect r_one, sfFloatRect r_two);

#endif /* !COLLISION_H_ */
