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
    char **dialog = NULL;
    char *chosen_name = NULL;
    if (index == 0) {
        if (b->round.order[b->round.order_index].x == -999) {
            b->round.code = ATTACK_CODE;
            return;
        }
        if (b->round.order[b->round.order_index].x == PLAYER_INDEX) {
            chosen_name = b->monster[b->select_choice]->name;
            dialog = str_split("Le joueur attaque {monster}", '&');
            b->dialog = create_dialog(dialog, 1, (sfVector2f) GUI_POS, 1);
        } else {
            dialog = str_split("Monster a attaque le jouer !", '&');
            b->dialog = create_dialog(dialog, 1, (sfVector2f) GUI_POS, 1);
        }
        set_dialog_active(b->dialog, 1);
    }
    if (b->dialog->line_finish) {
        index = 0;
        b->round.order_index++;
    }
    printf("dialog: %d\n", b->dialog->line_finish);
    update_dialog(b->dialog, d);
    index++;
}