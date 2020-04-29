/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player_collisions
*/

#include "game/collision.h"
#include "game/player.h"
#include "game/map.h"
#include "game/npc.h"
#include "lib/components/anim_sprite.h"
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "scene/overworld.h"

static void update_collisions_box(player_t *p, npc_t **npcs, long int delta, map_t *map)
{
    sfFloatRect r = {0, 0, 0, 0};
    float z = map->zoom;
    float ox = map->offset.x;
    float oy = map->offset.y;

    p->collision->collision_box = \
    sfSprite_getGlobalBounds(p->animations[p->current_animations]->sprite);
    for (int i = 0; npcs[i]; i++) {
        r = sfSprite_getGlobalBounds(npcs[i]->animations[npcs[i]->\
        current_animations]->sprite);
        npcs[i]->collision->collision_box = r;
        npcs[i]->trigger->collision_box = (sfFloatRect){r.left-5, r.top-5, \
            r.width+10, r.height+10};
    }
    for (int i = 0; map->obs[i]; i++) {
        r = map->obs[i]->shape;
        map->obs[i]->collision->collision_box = (sfFloatRect){r.left*z+ox, \
        r.top*z+oy, r.width*z+ox, r.height*z+oy};
    }
    for (int i = 0; map->interaction_boxes[i]; i++) {
        r = map->interaction_boxes[i]->shape;
        map->interaction_boxes[i]->collision_box = (sfFloatRect){r.left*z+ox, \
        r.top*z+oy, r.width*z, r.height*z};
    }
}

int check_direction_collision(player_t *p, npc_t **n, long int d, overworld_t *world)
{
    if (check_collision_ahead(world->map->obs, n, p, d) == 1)
        return (0);
    if (check_interaction_ahead(p, world, d) == 1)
        return (0);
    return (1);    
}

int block_move_on_collision(player_t *p, npc_t **n, long int d, \
overworld_t *world)
{
    sfVector2f moves[] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    int result = 0;

    if (p->is_ghost == 1 || p->in_teleportation == 1)
        return (0);
    p->search_for_interlocutor = 1;
    p->interlocutor = NULL;
    p->zone = 0;
    for (int i = 0; i < 4; i++) {
        add_player_position(p, moves[i]);
        update_collisions_box(p, n, d, world->map);
        p->free_moves[i] = check_direction_collision(p, n, d, world);
        add_player_position(p, (sfVector2f){moves[i].x*-1, moves[i].y*-1});
        p->search_for_interlocutor = 0;
    }
    return (0);
}