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

static void check_attack_monster(game_t *g, battle_screen_t *b, int tmp)
{
    if (b->monster[tmp]->is_alive) {
        monster_attack_player(b->monster[tmp], g->player);
        char **dialog = str_split("Monster a attaque le joueur !", '&');
        b->dialog = create_dialog(dialog, 1, (sfVector2f) GUI_POS, 2);
        set_dialog_active(b->dialog, 1);
    }
}

static void check_attack_player(game_t *g, battle_screen_t *b, int tmp)
{
    char *m_name = b->monster[b->select_gui->monster_index]->name;
    char *msg = str_cat("Vous attaquez ", m_name);
    int damage = player_attack_monster(g->player, b->monster[tmp]);
    msg = str_cat(msg, str_cat("#Vous avez inflige ", convert_str(damage)));
    msg = str_cat(msg, " degats.");
    char **dialog = str_split(msg, '#');
    b->dialog = create_dialog(dialog, 1, (sfVector2f) GUI_POS, 2);
    set_dialog_active(b->dialog, 1);
    b->monster[b->select_gui->monster_index]->stats->hp -= damage;
}

static void check_dialog(battle_screen_t *b, long int *delta, long int *d, int *index)
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

void update_attack_battle_screen(game_t *g, battle_screen_t *b, long int d)
{
    static int index = 0;
    static long int delta = 0;
    if (d == -1) {
        index = 0;
        delta = 0;
        return;
    }
    if (index == 0) {
        if (b->round.order[b->round.order_index].x == -999) {
            b->round.code = ATTACK_CODE;
            return;
        }
        int tmp = b->select_gui->monster_index;
        if (b->round.order[b->round.order_index].x == PLAYER_INDEX)
            check_attack_player(g, b, tmp);
        else {
            check_attack_monster(g, b, tmp);
        }
    }
    check_dialog(b, &delta, &d, &index);
    check_end(g, b, &index, &delta);
    index++;
    update_dialog(b->dialog, d);
}