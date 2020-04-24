/*
** EPITECH PROJECT, 2020
** update_npc.c
** File description:
** update_npc function
*/

#include "game/npc.h"

static void setup_action(npc_t *npc, float *f, \
int current_animations, int sign)
{
    npc->current_animations = current_animations;
    if (sign > 0)
        (*f)++;
    else
        (*f)--;
}

static void move_npc_nextpos(npc_t *npc, long int delta)
{
    sfVector2f p = {0, 0};

    p = sfSprite_getPosition(npc->animations[npc->current_animations]->sprite);
    int nx = npc->next_pos.x;
    int ny = npc->next_pos.y;
    npc->delta_movement += delta;
    if (npc->delta_movement < 5000)
        return;
    if (p.x > nx)
        setup_action(npc, &p.x, 2, -1);
    if (p.x < nx)
        setup_action(npc, &p.x, 1, 1);
    if (p.y > ny)
        setup_action(npc, &p.y, 3, -1);
    if (p.y < ny)
        setup_action(npc, &p.y, 0, 1);
    for (int i = 0; npc->animations[i] != 0; i++)
        sfSprite_setPosition(npc->animations[i]->sprite, p);
    npc->delta_movement = 0;
}

static void do_action(npc_t *npc, action_t *action, long int delta)
{
    sfVector2f p = {0, 0};

    p = sfSprite_getPosition(npc->animations[npc->current_animations]->sprite);
    int nx = action->pos.x;
    int ny = action->pos.y;
    npc->delta_movement += delta;
    if (npc->delta_movement < 5000)
        return;
    if (p.x > nx)
        setup_action(npc, &p.x, 2, -1);
    if (p.x < nx)
        setup_action(npc, &p.x, 1, 1);
    if (p.y > ny)
        setup_action(npc, &p.y, 3, -1);
    if (p.y < ny)
        setup_action(npc, &p.y, 0, 1);
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
    static int speed[] = {0, 260000, 220000, 180000, 160000, 140000, 120000, \
        100000, 80000, 60000, 40000, 20000};
    npc->delta += delta;
    if (npc->speed == 0)
        return;
    update_action_script(npc, delta);
    if (npc->delta >= speed[npc->speed]) {
        npc->delta = 0;
        printf("oui\n");
        update_anim_sprite_rect(npc->animations[npc->current_animations]);
    }
}