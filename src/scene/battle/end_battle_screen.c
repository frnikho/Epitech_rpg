/*
** EPITECH PROJECT, 2020
** end_battle_screen.c
** File description:
** end battle function
*/

#include <game.h>
#include <scene/battle.h>
#include "lib/utils/string.h"
#include "game/player.h"
#include "gui/dialog.h"

dialog_t *create_levelup_dialog(player_t *player, int *stats)
{
    char *msg = "Vous gagner un niveau (level ";
    msg = str_cat(msg, convert_str(player->level));
    msg = str_cat(msg, ") #+");
    msg = str_cat(msg, convert_str(stats[0]));
    msg = str_cat(msg, " puissance \n+");
    msg = str_cat(msg, convert_str(stats[1]));
    msg = str_cat(msg, " ressistance \n+");
    msg = str_cat(msg, convert_str(stats[2]));
    msg = str_cat(msg, " agilite \n#+");
    msg = str_cat(msg, convert_str(stats[3]));
    msg = str_cat(msg, " point de vie \n+");
    msg = str_cat(msg, convert_str(stats[4]));
    msg = str_cat(msg, " point de magie \n+");
    msg = str_cat(msg, convert_str(stats[5]));
    msg = str_cat(msg, " puissance magic");
    char **dialog = str_split(msg, '#');
    return create_dialog(dialog, 1, (sfVector2f)GUI_POS, 1);
}

static void init_end_dialog(game_t *g, battle_screen_t *b, int *gold, int *xp)
{
    char *str = "Vous avez vaincu tout les monstres ! # +";
    str = str_cat(str, convert_str((*gold)));
    str = str_cat(str, " golds, +");
    str = str_cat(str, convert_str((*xp)));
    str = str_cat(str, " xp");
    b->dialog = create_dialog(str_split(str, '#'), 1, (sfVector2f)GUI_POS, 1);
    set_dialog_active(b->dialog, 1);
    g->player->gold += (*gold);
    g->player->xp += (*xp);
}

static int check_monsters_is_alive(game_t *game, battle_screen_t *b)
{
    for (int i = 0; b->monster[i] != 0; i++) {
        if (!b->monster || b->monster[i]->is_alive)
            return (1);
    }
    return (0);
}

static int check_level(game_t *g, battle_screen_t *b, int **var)
{
    int *stats = check_player_levelup(g->player);
    if (stats != 0) {
        b->dialog = create_levelup_dialog(g->player, stats);
        set_dialog_active(b->dialog, 1);
    } else {
        sfVector2f pos = (sfVector2f){1600*10, 800*10};
        b->fade_in = init_fade(pos, sfBlack, 1, FADE_IN);
        set_fade_active(b->fade_in);
        update_attack_battle_screen(g, b, -1);
        (*var[1]) = 0;
        (*var[0]) = 0;
        (*var[2]) = 0;
        (*var[3]) = 0;
        return (0);
    }
}

int end_battle_screen(game_t *g, battle_screen_t *b, long int delta)
{
    static int tmp_delta = 0;
    static int code = 0;
    static int xp = 0;
    static int gold = 0;
    if (check_monsters_is_alive(g, b))
        return (1);
    if (tmp_delta == 0) {
        for (int i = 0; b->monster[i] != 0; i++) {
            xp += b->monster[i]->xp;
            gold += b->monster[i]->gold;
        }
    }
    if (tmp_delta == 0)
        init_end_dialog(g, b, &gold, &xp);
    if (b->dialog->is_finished && code == 0)
        return check_level(g, b, ((int*[]){&code, &tmp_delta, &xp, &gold}));
    tmp_delta += delta;
    return (0);
}