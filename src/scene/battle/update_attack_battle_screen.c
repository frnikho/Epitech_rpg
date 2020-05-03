/*
** EPITECH PROJECT, 2020
** update_attack_battle_screen.c
** File description:
** update attack battle screen function
*/

#include "lib/utils/string.h"
#include "game.h"
#include "scene/battle.h"

static void check_end(game_t *g, battle_screen_t *b, int *index, long int *d)
{
    if (b->round.order_index >= get_monsters_length(b->monster)+1) {
        b->attacking = 0;
        b->attack_gui->is_selected = 0;
        b->select_choice = 0;
        b->round.code = 0;
        b->round.order_index = 0;
        b->attack_gui->select_index = 0;
        b->select_gui->is_selected = 0;
        b->select_gui->is_active = 0;
        free(b->round.order);
        b->attack_gui->select_index = 0;
    }
}

static void check_dialog(battle_screen_t *b, long int *delta, \
long int *d, int *index)
{
    if (b->dialog && b->dialog->is_finished) {
        (*delta) += (*d);
        if ((*delta) >= 30000) {
            b->round.order_index++;
            set_dialog_active(b->dialog, 0);
            (*delta) = 0;
            (*index) = -1;
        }
    }
}

static void update_round_order(int index, game_t *g, battle_screen_t *b)
{
    if (index == 0) {
        if (b->round.order[b->round.order_index].x == -999)
            b->round.code = ATTACK_CODE;
        if (b->round.order[b->round.order_index].x == PLAYER_INDEX)
            check_attack_player(g, b, b->select_gui->monster_index);
        else
            check_attack_monster(g, b, b->select_gui->monster_index);
    }
}

void update_attack_battle_screen(game_t *g, battle_screen_t *b, long int d)
{
    static int index = 0;
    static long int delta = 0;
    if (g->current_state != BATTLE)
        return;
    if (d == -1) {
        index = 0;
        delta = 0;
        return;
    }
    update_round_order(index, g, b);
    check_dialog(b, &delta, &d, &index);
    check_end(g, b, &index, &delta);
    index++;
    update_dialog(b->dialog, d);
}