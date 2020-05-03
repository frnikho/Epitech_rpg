/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** check_attacks
*/

#include "lib/utils/string.h"
#include "game.h"
#include "scene/battle.h"

void check_attack_monster(game_t *g, battle_screen_t *b, int selected)
{
    if (b->monster[b->round.order[b->round.order_index].x]->is_alive) {
        int damage = monster_attack_player(b->monster\
        [b->round.order[b->round.order_index].x], g->player);
        char *name = b->monster[b->round.order[b->round.order_index].x]->name;
        char *str = str_cat(name, " attaque le joueur, -");
        str = str_cat(str, convert_str(damage));
        str = str_cat(str, " de vie");
        char **dialog = str_split(str, '#');
        b->dialog = create_dialog(dialog, 1, (sfVector2f) GUI_POS, 2);
        set_dialog_active(b->dialog, 1);
    }
}

void check_attack_player(game_t *g, battle_screen_t *b, int selected)
{
    if (b->attack_gui->select_index == SELECT_ATTACK) {
        char *m_name = b->monster[selected]->name;
        char *msg = str_cat("Vous attaquez ", m_name);
        int damage = player_attack_monster(g->player, b->monster[selected]);
        msg = str_cat(msg, str_cat("#Vous avez inflige ", \
        convert_str(damage)));
        msg = str_cat(msg, " degats.");
        char **dialog = str_split(msg, '#');
        b->dialog = create_dialog(dialog, 1, (sfVector2f) GUI_POS, 2);
        set_dialog_active(b->dialog, 1);
        b->monster[b->select_gui->monster_index]->stats->hp -= damage;
    } else if (b->attack_gui->select_index == SELECT_TENSION){
        char *tension = "Votre tension augmente !";
        char **dialog = str_split(tension, '#');
        b->dialog = create_dialog(dialog, 1, (sfVector2f) GUI_POS, 2);
        set_dialog_active(b->dialog, 1);
    }
}

int check_monsters_is_alive(game_t *game, battle_screen_t *b)
{
    for (int i = 0; b->monster[i] != 0; i++) {
        if (!b->monster || b->monster[i]->is_alive)
            return (1);
    }
    return (0);
}