/*
** EPITECH PROJECT, 2020
** input_battle_screen.c
** File description:
**  function
*/

#include "game.h"
#include "scene/battle.h"

int battle_screen_key_pressed(game_t *game)
{
    if (game->event.type != sfEvtKeyPressed)
        return (0);
    else if (game->event.key.code == sfKeyL)
        sfRenderWindow_close(game->window);
    return (1);
}

int input_battle_screen(game_t *game, battle_screen_t *battle)
{
    int active = 0;
    static int streak = 1;
    if (battle->dialog && battle->dialog->is_active) {
        update_dialog_line(battle->dialog);
    }
    if (game->player->health <= 0)
        return (0);
    if (battle->attack_gui->select_index == SELECT_ATTACK \
&& battle->attack_gui->is_selected) {
        battle->select_gui->is_active = 1;
        streak = 0;
    }
    tension(game, battle, &streak);
    if (run_away(battle, game) == 0)
        return (0);
    if (battle->attack_gui->is_selected) {
        handle_select_gui(game->event, battle->select_gui);
        battle->select_gui->is_active = 1;
    }
    handle_attack_gui(battle->attack_gui, game->event);
    if (game->event.type != sfEvtKeyPressed)
        return (0);
    sfKeyCode key = game->event.key.code;
    active = battle->select_gui->is_active;
    if (!battle->select_choice && key == sfKeyEscape && active) {
        battle->select_gui->is_active = 0;
        battle->attack_gui->is_selected = 0;
    }
}