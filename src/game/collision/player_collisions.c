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

static void update_collisions_box(player_t *p, npc_t **npcs, long int delta)
{
    sfFloatRect r = {0, 0, 0, 0};

    p->collision->collision_box = \
    sfSprite_getGlobalBounds(p->animations[p->current_animations]->sprite);
    for (int i = 0; npcs[i]; i++) {
        r = sfSprite_getGlobalBounds(npcs[i]->animations[npcs[i]->\
        current_animations]->sprite);
        npcs[i]->collision->collision_box = r;
        npcs[i]->trigger->collision_box = (sfFloatRect){r.left-5, r.top-5, \
            r.width+10, r.height+10};
    }
}

int block_move_on_collision(player_t *p, npc_t **npcs, long int delta, obstacle_t **obs)
{
    update_collisions_box(p, npcs, delta);
    if (check_collision_ahead(obs, npcs, p->collision, delta) == 1) {
        add_player_position(p, (sfVector2f){p->pre_pos.x * -1, \
            p->pre_pos.y * -1});
        p->pre_pos = (sfVector2f){0, 0};
        return (1);
    }
    p->pre_pos = (sfVector2f){0, 0};
    return (0);
}