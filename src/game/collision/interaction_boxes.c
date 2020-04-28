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

interaction_box_t *create_interaction_box(sfFloatRect rec, int is_blocking, \
int load_zone, int zone_act)
{
    interaction_box_t *box = malloc(sizeof(interaction_box_t));
    box->is_active = 1;
    box->is_blocking = is_blocking;
    box->collision_box = (sfFloatRect){rec.left,rec.top,rec.width,rec.height};
    box->shape = (sfFloatRect){rec.left,rec.top,rec.width,rec.height};
    box->load_map = load_zone;
    box->zone_act = zone_act;
    return (box);
}

int check_interactions(collision_box_t *player, interaction_box_t *c2)
{
    if (player->is_active == 0 || c2->is_active == 0)
        return (0);
    if (is_rectangles_in_collision(player->collision_box, \
        c2->collision_box) == 1) {
        printf("Player col: %.2f  %.2f  %.2f  %.2f  down:%.2f   right:%.2f\n", player->collision_box.left, player->collision_box.top, player->collision_box.width, player->collision_box.height, player->collision_box.top+player->collision_box.height, player->collision_box.left+player->collision_box.width);
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

    for (int i = 0; world->map->interaction_boxes[i]; i++) {
        result = check_interactions(player->collision, \
        world->map->interaction_boxes[i]);
        if (result != 0 && world->map->interaction_boxes[i]->load_map != -1)
            world->current_map = world->map->interaction_boxes[i]->load_map;
        if (result != 0) {
            player->zone = world->map->interaction_boxes[i]->zone_act;
            sfFloatRect r = world->map->interaction_boxes[i]->collision_box;
            sfFloatRect p = sfSprite_getGlobalBounds(player->animations[player->current_animations]->sprite);
            return (result);
        }
    }
    return (0);
}