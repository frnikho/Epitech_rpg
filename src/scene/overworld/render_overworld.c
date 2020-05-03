/*
** EPITECH PROJECT, 2020
** render_overworld.c
** File description:
** render overworld function
*/

#include "gui/pause_gui.h"
#include "game.h"
#include "scene/overworld.h"

void draw_interaction_boxes(sfRenderWindow *window, map_t *map)
{
    sfConvexShape *shape = sfConvexShape_create();

    sfConvexShape_setPointCount(shape, 4);
    sfConvexShape_setFillColor(shape, sfColor_fromRGBA(0, 255, 0, 150));
    for (int i = 0; map->interaction_boxes[i]; i++) {
        sfFloatRect r = map->interaction_boxes[i]->collision_box;
        sfConvexShape_setPoint(shape, 0, (sfVector2f){r.left, r.top});
        sfConvexShape_setPoint(shape, 1, (sfVector2f)\
{(r.left+r.width), r.top});
        sfConvexShape_setPoint(shape, 2, (sfVector2f)\
{(r.left+r.width), (r.top+r.height)});
        sfConvexShape_setPoint(shape, 3, (sfVector2f)\
{(r.left), (r.top+r.height)});
        sfRenderWindow_drawConvexShape(window, shape, NULL);
    }
    sfConvexShape_destroy(shape);
}

static void render_map_world(game_t *game, overworld_t *world, long int delta)
{
    sfRenderWindow_clear(game->window, sfBlack);
    update_zoom_and_offset(world->map);
    draw_map(world->map, game->window, (int []){0}, \
(int []){99, 0});
}

static void draw_npcs(sfRenderWindow *window, npc_t **npcs, sfView *camera)
{
    for (int i = 0; npcs[i]; i++)
        draw_npc(window, npcs[i]);
    for (int i = 0; npcs[i]; i++) {
        set_dialog_relative(npcs[i]->dialog, camera);
        draw_dialog(window, npcs[i]->dialog);
    }
}

int render_overworld(game_t *game, overworld_t *world, long int delta)
{
    if (game->current_state != OVERWORLD)
        return (0);
    sfRenderWindow_clear(game->window, sfBlack);
    render_map_world(game, world, delta);
    draw_state(game->camera, game->window, world->state);
    if (world->current_map == 0)
        if (world->state->npcs)
            for (int i = 0; world->state->npcs[i] != 0; i++)
                draw_npc(game->window, world->state->npcs[i]);
    draw_npcs(game->window, world->npcs, game->camera);
    draw_inventory(game->window, game->camera, game->player->inventory);
    draw_player(game->window, game->player);
    draw_pause(world->pause, game->window, delta);
    return (0);
}