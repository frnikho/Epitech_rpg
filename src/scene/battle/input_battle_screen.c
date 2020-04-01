/*
** EPITECH PROJECT, 2020
** input_battle_screen.c
** File description:
**  function
*/

#include <game.h>
#include <scene/battle.h>

int input_battle_screen(game_t *game, battle_screen_t *battle)
{
    if (battle->attack_gui->is_selected)
        handle_select_gui(game->event, battle->select_gui);
    handle_attack_gui(battle->attack_gui, game->event);
    if (game->event.type != sfEvtKeyPressed)
        return (0);
    sfKeyCode key = game->event.key.code;
    if (!battle->select_choice && key == sfKeyEscape && battle->select_gui->is_active) {
        battle->select_gui->is_active = 0;
        battle->attack_gui->is_selected = 0;
    }
}