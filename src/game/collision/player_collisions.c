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

int block_move_on_collision(player_t *p, npc_t **n, long int d, \
overworld_t *world)
{
    if (p->is_ghost == 1)
        return (0);
    update_collisions_box(p, n, d, world->map);
    if (check_collision_ahead(world->map->obs, n, p, d) == 1) {
        add_player_position(p, (sfVector2f){p->pre_pos.x * -1, \
            p->pre_pos.y * -1});
        p->pre_pos = (sfVector2f){0, 0};
        return (1);
    }
    if (check_interaction_ahead(p, world, d) == 1) {
        add_player_position(p, (sfVector2f){p->pre_pos.x * -1, \
            p->pre_pos.y * -1});
        p->pre_pos = (sfVector2f){0, 0};
        return (1);
    }
    p->pre_pos = (sfVector2f){0, 0};
    return (0);
}