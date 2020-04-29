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
#include "lib/effects/fade.h"

sfVector2i *get_attack_order(monster_t **m, player_t *p, int p_attack)
{
    int length = get_monsters_length(m) + 1;
    int cursor = 0;
    sfVector2i *order = malloc(sizeof(sfVector2i) * (length + 1));
    if (p_attack == 0) {
        order[0] = (sfVector2i){PLAYER_INDEX, p->stats->agility};
        cursor = 1;
    }
    for (int i = 0; i < length-1; i++)
        order[i+cursor] = (sfVector2i){i+cursor, m[i]->stats->agility};
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
    int attack = g->player->can_run_away;
    sfVector2i *attack_order = get_attack_order(b->monster, g->player, attack);
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
    if (game->current_state != BATTLE)
        return (0);
    sfRenderWindow_setView(game->window, game->camera);
    update_attack_gui(battle->attack_gui, delta);
    if (battle->dialog && battle->dialog->is_active && !battle->dialog->is_finished) {
        update_dialog_line(battle->dialog);
    }
    for (int i = 0; battle->monster[i]; i++)
        update_monster(battle->monster[i], delta);
    update_select_gui(battle->select_gui, delta);
    update_player_gui(game->player);
    //check_run_away(game, battle, delta);
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
    static int code = 0;
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
    if (tmp_delta == 0) {
        char *str = "Vous avez vaincu tout les monstres ! # +";
        str = str_cat(str, convert_str(gold));
        str = str_cat(str, " golds, +");
        str = str_cat(str, convert_str(xp));
        str = str_cat(str, " xp");
        b->dialog = create_dialog(str_split(str, '#'), 1, (sfVector2f)GUI_POS, 1);
        set_dialog_active(b->dialog, 1);
    }
    if (b->dialog->is_finished && code == 0) {
        b->fade_in = init_fade((sfVector2f){1600*10, 800*10}, sfBlack, 1, FADE_IN);
        set_fade_active(b->fade_in);
        code++;
        update_attack_battle_screen(g, b, -1);
        tmp_delta = 0;
        code = 0;
        xp = 0;
        gold = 0;
        return (0);
    }
    tmp_delta += delta;
    return (0);
}

void check_run_away(game_t *game, battle_screen_t *battle, long int delta)
{
    static int tmp = 0;
    if (game->player->can_run_away == -1) {
        return;
    }
    if (!tmp && battle->attack_gui->select_index == SELECT_RUN_AWAY && game->player->can_run_away == 1) {
        char **dialog = str_split("Vous avez reussi a jouir !", '#');
        battle->dialog = create_dialog(dialog, 1, (sfVector2f) GUI_POS, 2);
        set_dialog_active(battle->dialog, 1);
        battle->attack_gui->is_selected = 0;
        game->player->can_run_away = -1;
    } else if (!tmp) {
        char **dialog = str_split("Vous n'avez pas reussi a jouir...", '#');
        battle->dialog = create_dialog(dialog, 1, (sfVector2f) GUI_POS, 2);
        set_dialog_active(battle->dialog, 1);
        game->player->can_run_away = -1;
    }
    battle->attack_gui->is_selected = 0;
    battle->attack_gui->select_index = 0;
    tmp = 1;
}