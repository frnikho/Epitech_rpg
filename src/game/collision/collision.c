/*
** EPITECH PROJECT, 2020
** collision.c
** File description:
**  function
*/

#include "game/collision.h"
#include "game/player.h"
#include "game/map.h"
#include "game/npc.h"
#include "lib/components/anim_sprite.h"
#include <stdlib.h>
#include <SFML/Graphics.h>

collision_box_t *create_collision_box(sfFloatRect rec, int update_on_default, int is_blocking)
{
    collision_box_t *box = malloc(sizeof(collision_box_t));
    box->is_active = 1;
    box->is_blocking = is_blocking;
    box->update_on_default = update_on_default;
    box->collision_box = rec;
    return (box);
}

int is_rectangles_in_collision(sfFloatRect *r_one, sfFloatRect *r_two)
{
    if (r_one->left + r_one->width > r_two->left && \
    r_one->left < r_two->left + r_two->width) {
        if (r_one->top + r_one->height > r_two->top &&\
        r_one->top < r_two->top + r_two->height) {
            return (1);
        }
    }
    return (0);
}

int check_collisions(collision_box_t *c1, collision_box_t *c2)
{
    if (c1->is_active == 0 || c2->is_active == 0)
        return (0);
    if (is_rectangles_in_collision(&c1->collision_box, &c2->collision_box) == 1) {
        if (c1->is_blocking == 0 || c2->is_blocking == 0)
            return (2);
        return (1);
    }
    return (0);
}

int check_collision_ahead(obstacle_t **map_obs, npc_t **npcs, collision_box_t *player, long int delta)
{
    int result = 0;

    for (int i = 0; npcs[i]; i++) {
        result = check_collisions(player, npcs[i]->collision);
        if (result != 0)
            return (result);
        else if (npcs[i]->collision->update_on_default == 1)
            update_npc(npcs[i], delta);
        result = check_collisions(player, npcs[i]->trigger);
        if (result != 0)
            return (result);
        else if (npcs[i]->trigger->update_on_default == 1)
            update_npc(npcs[i], delta);
    }
    for (int i = 0; map_obs[i]; i++) {
        if (check_collisions(player, map_obs[i]->collision) == 1)
            return (1);
    }
    return (0);
}

int block_move_on_collision(player_t *p, npc_t **npcs, long int delta)
{
    obstacle_t **obs = malloc(sizeof(obstacle_t*));
    sfFloatRect r = {0, 0, 0, 0};

    obs[0] = NULL;
    p->collision->collision_box = sfSprite_getGlobalBounds(p->animations[p->current_animations]->sprite);
    for (int i = 0; npcs[i]; i++) {
        r = sfSprite_getGlobalBounds(npcs[i]->animations[npcs[i]->current_animations]->sprite);
        npcs[i]->collision->collision_box = r;
        npcs[i]->trigger->collision_box = (sfFloatRect){r.left-5, r.top-5, r.width+10, r.height+10};
    }
    if (check_collision_ahead(obs, npcs, p->collision, delta) == 1) {
        free(obs);
        add_player_position(p, (sfVector2f){p->pre_pos.x * -1, p->pre_pos.y * -1});
        p->pre_pos = (sfVector2f){0, 0};
        return (1);
    }
    free(obs);
    p->pre_pos = (sfVector2f){0, 0};
    return (0);
}