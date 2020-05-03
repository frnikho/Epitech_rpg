/*
** EPITECH PROJECT, 2020
** battle_screen_check_player.c
** File description:
** battle_screen_check_player function
*/

#include "lib/utils/string.h"
#include "scene/battle.h"

int check_player_dead(game_t *g, battle_screen_t *b, long int delta)
{
    static int is_dead = 0;
    printf("is dead: %d\n", is_dead);
    if (!is_dead && g->player->health <= 0) {
        is_dead = 1;
        char **dialog = str_split("Vous n'avez plus assez de point de vie.", '&');
        b->dialog = create_dialog(dialog, 1, (sfVector2f)GUI_POS, 1);
        set_dialog_active(b->dialog, 1);
        stop_sound(b->music);
        b->music = init_sound("assets/sound/dead.ogg");
        play_sound(b->music, 50);
        b->fade_out = init_fade((sfVector2f){1600*10, 800*10}, sfBlack, 1, FADE_OUT);
        set_fade_active(b->fade_out);
    }
    if (is_dead && b->dialog && b->dialog->is_finished) {
        update_fade(b->fade_out, delta);
    }
    if (is_dead && b->fade_out->is_finish) {
        g->current_state = OVERWORLD;
        g->code = RESET_CODE;
        g->player->health = g->player->stats->hp;
        g->player->mp = g->player->stats->mp;
        is_dead = 0;
        dispose_battle_screen(g, b);
        g->player->fight = 0;
        return (0);
    }
    return (0);
}