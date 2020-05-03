/*
** EPITECH PROJECT, 2020
** battle_screen.c
** File description:
**  function
*/

#include "game.h"
#include "scene/battle.h"

static battle_screen_t *init(game_t *game)
{
    game->code = 0;
    battle_screen_t *battle = malloc(sizeof(battle_screen_t));
    if (!battle)
        return (0);
    init_battle_screen(game, battle);
    return (battle);
}

void dispose_battle_screen(game_t *game, battle_screen_t *battle)
{
    //dispose_fade(battle->fade_in);
    //dispose_fade(battle->fade_out);
    for (int i = 0; battle->monster[i]; i++) {
        dispose_monster(battle->monster[i]);
    }
    free(battle->monster);
    dispose_select_gui(battle->select_gui);
    destroy_attack_gui(battle->attack_gui);
    battle->attacking = 0;
    if (battle->dialog)
        destroy_dialog(battle->dialog);
    dispose_sprite(battle->bg);
    battle->round.order_index = 0;
    game->player->fight = 0;
    battle->round.code = 0;
    free(battle);
    game->code = RESET_CODE;
}

static void update(game_t *game, battle_screen_t *battle, long int delta)
{
    static int delta_i = 0;

    delta_i += delta;
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed) {
            sfRenderWindow_close(game->window);
            dispose_battle_screen(game, battle);
            return;
        }
        if (delta_i < 1000)
            continue;
        input_battle_screen(game, battle);
        delta_i = 0;
    }
    update_battle_screen(game, battle, delta);
    render_battle_screen(game, battle, delta);
}

void battle_screen(game_t *game, long int delta)
{
    static battle_screen_t *battle;
    if (!battle || game->code == RESET_CODE) {
        battle = init(game);
        if (!battle)
            return;
    }
    update(game, battle, delta);
}