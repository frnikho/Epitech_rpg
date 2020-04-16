/*
** EPITECH PROJECT, 2020
** update_attack_battle_screen.c
** File description:
** update attack battle screen function
*/

#include "lib/utils/string.h"
#include "game.h"
#include "scene/battle.h"

void update_attack_battle_screen(game_t *g, battle_screen_t *b, long int d)
{
    static int index = 0;
    static long int delta = 0;
    if (index == 0) {
        if (b->round.order[b->round.order_index].x == -999) {
            b->round.code = ATTACK_CODE;
            return;
        }
        int tmp = b->select_gui->monster_index;
        if (b->round.order[b->round.order_index].x == PLAYER_INDEX) {
            char *m_name = b->monster[b->select_gui->monster_index]->name;
            char *msg = str_cat("Le joueur attaque ", m_name);
            char **dialog = str_split(msg, '&');
            b->dialog = create_dialog(dialog, 1, (sfVector2f) GUI_POS, 1);
            player_attack_monster(g->player, b->monster[tmp]);
        } else {
            char **dialog = str_split("Monster a attaque le jouer !", '&');
            b->dialog = create_dialog(dialog, 1, (sfVector2f) GUI_POS, 1);
            monster_attack_player(b->monster[tmp], g->player);
        }
        set_dialog_active(b->dialog, 1);
    }
    if (b->dialog && b->dialog->is_active && b->dialog->line_finish) {
        delta += d;
        if (delta >= 500000) {
            b->round.order_index++;
            set_dialog_active(b->dialog, 0);
            delta = 0;
            //TODO ATTACK ENEMY SPRITE
            index = -1;
        }
    }
    if (b->round.order_index >= get_monsters_length(b->monster)+1) {
        b->attacking = 0;
        b->select_gui->is_selected = 0;
        b->select_choice = 0;
        b->attack_gui->is_selected = 0;
        b->attack_gui->select_index = 0;
        return;
    }
    index++;
    update_dialog(b->dialog, d);
}