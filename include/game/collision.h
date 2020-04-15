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
typedef struct obstacle_s obstacle_t;

typedef struct collision_box_s {
    int is_active;
    int is_blocking;
    int update_on_default;
    sfFloatRect collision_box;
} collision_box_t;

collision_box_t *create_collision_box(sfFloatRect rec, int update_on_default);
int check_collision_ahead(obstacle_t **map_obs, npc_t **npcs, collision_box_t *player, long int delta);

#endif /* !COLLISION_H_ */
