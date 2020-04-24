/*
** EPITECH PROJECT, 2020
** update_battle_screen.c
** File description:
**  function
*/

#include <game.h>
#include <scene/battle.h>
#include <stdio.h>
#include "lib/utils/string.h"

static sfVector2i *get_attack_order(monster_t **m, player_t *p)
{
    int length = get_monsters_length(m) + 1;

    sfVector2i *order = malloc(sizeof(sfVector2i) * (length + 1));
    order[0] = (sfVector2i){PLAYER_INDEX, p->stats->agility};
    for (int i = 0; i < length-1; i++)
        order[i+1] = (sfVector2i){i+1, m[i]->stats->agility};
    order[length] = (sfVector2i){-999, -999};
    int index = 0;
    while (index != length) {
        if (order[index].y < order[index+1].y) {
            sfVector2i tmp = order[index];
            order[index] = order[index+1];
            order[index+1] = tmp;
            index = 0;
            continue;
        }
        index++;
    }
    return (order);
}

static void update_monster_battle(game_t *g, battle_screen_t *b, long int delta)
{
    if (!b->select_choice && b->round.code != ATTACK_CODE)
        return;
    sfVector2i *attack_order = get_attack_order(b->monster, g->player);
    b->round.order = attack_order;
    b->round.code = ATTACK_CODE;
}

static void end_monster_attack(game_t *game, battle_screen_t *b)
{
    b->select_choice = 0;
    b->attack_gui->select_index = 0;
    b->attack_gui->is_selected = 0;
    b->select_gui->monster_index = 0;
    b->select_gui->is_selected = 0;
    b->select_gui->is_active = 0;
    free(b->round.order);
}

int update_battle_screen(game_t *game, battle_screen_t *battle, long int delta)
{
    sfRenderWindow_setView(game->window, game->camera);
    update_attack_gui(battle->attack_gui, delta);
    for (int i = 0; battle->monster[i]; i++)
        update_monster(battle->monster[i], delta);
    update_select_gui(battle->select_gui, delta);
    update_player_gui(game->player);
    if (battle->attack_gui->is_selected) {
        if (battle->attack_gui->select_index == SELECT_ATTACK && battle->attacking) {
            battle->select_gui->is_active = 1;
        }
    }
    if (!battle->select_choice && battle->select_gui->is_selected)
        battle->select_choice = 1;
    update_monster_battle(game, battle, delta);
    if (battle->round.code == ATTACK_CODE) {
        battle->attacking = 1;
        update_attack_battle_screen(game, battle, delta);
    }
    end_battle_screen(game, battle, delta);
}

int end_battle_screen(game_t *g, battle_screen_t *b, long int delta)
{
    static long int tmp_delta = 0;
    static int xp = 0;
    static int gold = 0;
    for (int i = 0; b->monster[i] != 0; i++) {
        if (b->monster[i]->is_alive)
            return (1);
    }
    if (tmp_delta == 0) {
        for (int i = 0; b->monster[i] != 0; i++) {
            xp += b->monster[i]->xp;
            gold += b->monster[i]->gold;
        }
    }
    char *str = "vous avez vaincu tout les monstres ! # +";
    str = str_cat(str, convert_str(gold));
    str = str_cat(str, " golds, +");
    str = str_cat(str, convert_str(xp));
    str = str_cat(str, " xp");

    if (tmp_delta == 0) {
        b->dialog = create_dialog(str_split(str, '#'), 1, (sfVector2f)GUI_POS, 1);
        set_dialog_active(b->dialog, 1);
    }
    tmp_delta += delta;
    return (0);
}