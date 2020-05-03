/*
** EPITECH PROJECT, 2020
** render_battle_screen.c
** File description:
**  function
*/

#include <game.h>
#include <scene/battle.h>

static void render_effects(game_t *game, \
battle_screen_t *battle, long int delta)
{
    if (battle->fade_out) {
        draw_fade(game->window, battle->fade_out);
    }
    if (battle->fade_in) {
        draw_fade(game->window, battle->fade_in);
        game->current_state = OVERWORLD;
        game->code = RESET_CODE;
        dispose_battle_screen(game, battle);
        game->player->fight = 0;
    }
    if (battle->particle_system)
        draw_particle_system(game->window, battle->particle_system);
}

int render_battle_screen(game_t *game, battle_screen_t *battle, long int delta)
{
    if (game->current_state != BATTLE)
        return (0);
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
    render_effects(game, battle, delta);
    return (0);
}