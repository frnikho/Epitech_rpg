/*
** EPITECH PROJECT, 2020
** update_npc.c
** File description:
** update_npc function
*/

#include "game/npc.h"

static void do_action(npc_t *npc, action_t *action, long int delta)
{
    sfVector2f p;
    p = sfSprite_getPosition(npc->animations[npc->current_animations]->sprite);
    int nx = action->pos.x;
    int ny = action->pos.y;
    npc->delta_movement += delta;
    if (npc->delta_movement < 5000)
        return;
    if (p.x > nx) {
        npc->current_animations = 2;
        p.x--;
    }
    if (p.x < nx) {
        npc->current_animations = 1;
        p.x++;
    }
    if (p.y > ny) {
        npc->current_animations = 3;
        p.y--;
    }
    if (p.y < ny) {
        npc->current_animations = 0;
        p.y++;
    }
    for (int i = 0; npc->animations[i] != 0; i++)
        sfSprite_setPosition(npc->animations[i]->sprite, p);
    npc->delta_movement = 0;

}

static void update_action_script(npc_t *npc, long int delta)
{
    if (npc->script == 0)
        return;
    action_t *action = &npc->script->actions[npc->script->pos_count];
    if (action->delta > action->time) {
        action->delta = 0;
        npc->script->pos_count++;
    }
    if (npc->script->pos_count >= npc->script->max_count) {
        npc->script->pos_count = 0;
    } else {
        action->delta += delta;
    }
    do_action(npc, &npc->script->actions[npc->script->pos_count], delta);

}

void update_npc(npc_t *npc, long int delta)
{
    static int speed[] = {0, 260000, 220000, 180000, 160000, 140000, 120000, 100000, 80000, 60000, 40000, 20000};
    npc->delta += delta;
    if (npc->speed == 0)
        return;

    update_action_script(npc, delta);

    if (npc->delta >= speed[npc->speed]) {
        npc->delta = 0;
        update_anim_sprite_rect(npc->animations[npc->current_animations]);
    }
}