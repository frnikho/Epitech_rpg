/*
** EPITECH PROJECT, 2020
** render_battle_screen.c
** File description:
**  function
*/

#include <game.h>
#include <scene/battle.h>

int render_battle_screen(game_t *game, battle_screen_t *battle, long int delta)
{
    draw_sprite(game->window, battle->bg);
    draw_player_gui(game->window, game->player);
    for (int i = 0; battle->monster[i] != 0; i++)
        draw_monster(game->window, battle->monster[i]);
    if (battle->round.code != ATTACK_CODE || !battle->attacking) {
        draw_select_gui(game->window, battle->select_gui);
        draw_attack_gui(game->window, battle->attack_gui);
    }
    if (battle->attacking == 1 && battle->dialog != 0)
        draw_dialog(game->window, battle->dialog);
    if (battle->fade_in) {
        draw_fade(game->window, battle->fade_in);
        game->current_state = INTRO_SCREEN;
    }

}