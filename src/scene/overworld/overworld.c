/*
** EPITECH PROJECT, 2020
** overworld.c
** File description:
** overworld function
*/

#include "game.h"
#include "scene/overworld.h"
#include "lib/utils/json_parser.h"

static overworld_t *init(game_t *game)
{
    overworld_t *overworld = malloc(sizeof(overworld_t));
    game->restart = 0;
    if (init_overworld(game, overworld) == 84)
        return (NULL);
    return (overworld);
}

static void overworld_commands(game_t *game, overworld_t *overworld)
{
    if (game->event.key.code == sfKeyG) {
        game->player->is_ghost = 1 - (game->player->is_ghost * 1);
        for (int i = 0; i < 4; i++)
            game->player->free_moves[i] = 1;
    }
}

static void change_current_map(game_t *game, overworld_t *overworld)
{
    static int map_act = -1;

    if (overworld->current_map != map_act && map_act != -1) {
        destroy_overworld(game, overworld);
        if (init_overworld_map(overworld) == 84) {
            sfRenderWindow_close(game->window);
            return;
        }
        game->player->in_teleportation = 0;
    }
    map_act = overworld->current_map;
}

static void update(game_t *game, overworld_t *overworld, long int delta)
{
    static int delta_i = 0;
    if (overworld->current_map == 0 && game->player->health != game->player->stats->hp)
        game->player->health = game->player->stats->hp;
    delta_i += delta;
    change_current_map(game, overworld);
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed) {
            destroy_overworld(game, overworld);
            sfRenderWindow_close(game->window);
            return;
        }
        if (delta_i < 1000)
            continue;
        input_overworld(game, overworld);
        delta_i = 0;
    }
    if (game->current_state != OVERWORLD)
        return;
    overworld_commands(game, overworld);
    update_overworld(game, overworld, delta);
    if (game->player->in_teleportation == 0)
        render_overworld(game, overworld, delta);
}

void destroy_overworld(game_t *game, overworld_t *overworld)
{
    free(overworld->map->interaction_boxes);
    destroy_and_free_map(overworld->map);
    free(overworld->map);
    free_tab(overworld->obs_tab);
    free_double_tab(overworld->tiles_tab);
    free_double_tab(overworld->objs_tab);
    for (int i = 0; overworld->npcs[i]; i++) {
        free(overworld->npcs[i]->script->actions);
        free(overworld->npcs[i]->script);
        free(overworld->npcs[i]->dialog);
        free(overworld->npcs[i]);
    }
    free(overworld->npcs);
}

void overworld(game_t *game, long int delta)
{
    static overworld_t *overworld = 0;

    if (!overworld || game->restart == 1)
        overworld = init(game);
    if (overworld == NULL) {
        sfRenderWindow_close(game->window);
        return;
    }
    update(game, overworld, delta);
}