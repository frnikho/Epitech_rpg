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

static void update_collisions_box(player_t *p, npc_t **npcs, \
long int delta, overworld_t *world)
{
    sfFloatRect r = {0, 0, 0, 0};
    float z = world->map->zoom;
    float ox = world->map->offset.x;
    float oy = world->map->offset.y;
    p->collision->collision_box = \
    sfSprite_getGlobalBounds(p->animations[p->current_animations]->sprite);
    p->collision->collision_box.top += p->collision->collision_box.width/2;
    p->collision->collision_box.height -= (p->collision->\
collision_box.height/2);
    for (int i = 0; npcs[i]; i++) {
        r = sfSprite_getGlobalBounds(npcs[i]->animations[npcs[i]->\
        current_animations]->sprite);
        npcs[i]->collision->collision_box = r;
        npcs[i]->trigger->collision_box = (sfFloatRect){r.left-5, r.top-5, \
            r.width+10, r.height+10};
    }
    for (int i = 0; world->state->npcs[i]; i++) {
        r = sfSprite_getGlobalBounds(world->state->npcs[i]->animations[world->state->npcs[i]->\
        current_animations]->sprite);
        world->state->npcs[i]->collision->collision_box = r;
        world->state->npcs[i]->trigger->collision_box = (sfFloatRect){r.left-5, r.top-5, \
            r.width+10, r.height+10};
    }
    for (int i = 0; world->map->obs[i]; i++) {
        r = world->map->obs[i]->shape;
        world->map->obs[i]->collision->collision_box = (sfFloatRect){r.left*z+ox, \
r.top*z+oy, r.width*z+ox, r.height*z+oy};
    }
    for (int i = 0; world->map->interaction_boxes[i]; i++) {
        r = world->map->interaction_boxes[i]->shape;
        world->map->interaction_boxes[i]->collision_box = (sfFloatRect){r.left*z+ox, \
r.top*z+oy, r.width*z, r.height*z};
    }
}

int check_direction_collision(player_t *p, long int d, \
overworld_t *world)
{
    if (check_collision_ahead(world, p, d) == 1)
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
        update_collisions_box(p, n, d, world);
        p->free_moves[i] = check_direction_collision(p, d, world);
        add_player_position(p, (sfVector2f){moves[i].x*-1, moves[i].y*-1});
        p->search_for_interlocutor = 0;
    }
    return (0);
}