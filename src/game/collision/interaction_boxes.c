/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** interaction_boxes
*/

#include "game/collision.h"
#include "game/player.h"
#include "game/map.h"
#include "game/npc.h"
#include "scene/overworld.h"
#include "lib/components/anim_sprite.h"
#include <stdlib.h>
#include <SFML/Graphics.h>

interaction_box_t *create_interaction_box(sfFloatRect rec, \
sfVector2f spaw_pos, int load_zone, int zone_act)
{
    interaction_box_t *box = malloc(sizeof(interaction_box_t));
    box->is_active = 1;
    box->is_blocking = 0;
    box->collision_box = (sfFloatRect){rec.left, rec.top, \
rec.width, rec.height};
    box->shape = (sfFloatRect){rec.left, rec.top, rec.width, rec.height};
    box->load_map = load_zone;
    box->zone_act = zone_act;
    box->spawn_pos = spaw_pos;
    return (box);
}

int check_interactions(collision_box_t *player, interaction_box_t *c2)
{
    if (player->is_active == 0 || c2->is_active == 0)
        return (0);
    if (is_rectangles_in_collision(player->collision_box, \
c2->collision_box) == 1) {
        if (player->is_blocking == 0 || c2->is_blocking == 0)
            return (2);
        return (1);
    }
    return (0);
}

int check_interaction_ahead(player_t *player, overworld_t *world, \
long int delta)
{
    int result = 0;
    int to_return = 0;

    for (int i = 0; world->map->interaction_boxes[i]; i++) {
        result = check_interactions(player->collision, \
        world->map->interaction_boxes[i]);
        if (result != 0 && world->map->interaction_boxes[i]->load_map != -1) {
            world->current_map = world->map->interaction_boxes[i]->load_map;
            set_player_position(player, world->map->\
interaction_boxes[i]->spawn_pos);
            player->in_teleportation = 1;
        }
        if (result != 0 && world->map->interaction_boxes[i]->zone_act > \
player->zone)
            player->zone = world->map->interaction_boxes[i]->zone_act;
        if (result != 0)
            to_return = result;

    }
    return (to_return);
}