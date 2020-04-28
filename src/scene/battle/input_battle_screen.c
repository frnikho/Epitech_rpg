/*
** EPITECH PROJECT, 2020
** input_battle_screen.c
** File description:
**  function
*/

#include "game.h"
#include "scene/battle.h"

int input_battle_screen(game_t *game, battle_screen_t *battle)
{
    int active = 0;
    if (battle->attack_gui->is_selected) {
        handle_select_gui(game->event, battle->select_gui);
        battle->select_gui->is_active = 1;
    }
    handle_attack_gui(battle->attack_gui, game->event);
    if (game->event.type != sfEvtKeyPressed)
        return (0);
    if (battle->dialog && battle->dialog->is_active) {
        update_dialog_line(battle->dialog);
    }
    sfKeyCode key = game->event.key.code;
    active = battle->select_gui->is_active;
    if (!battle->select_choice && key == sfKeyEscape && active) {
        battle->select_gui->is_active = 0;
        battle->attack_gui->is_selected = 0;
    }
}