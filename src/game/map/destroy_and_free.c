/*
** EPITECH PROJECT, 2020
** map_parser
** File description:
** destroy_and_free
*/

#include "game/map.h"

void destroy_tiles(sfSprite **tiles)
{
    for (int i = 0; tiles[i]; i++)
        sfSprite_destroy(tiles[i]);
}

void destroy_objects(object_t **obj)
{
    for (int i = 0; obj[i]; i++) {
        sfTexture_destroy(obj[i]->texture);
        free(obj[i]);
    }
}

void destroy_and_free_obstacles(obstacle_t **obs)
{
    for (int i = 0; obs[i]; i++) {
        sfConvexShape_destroy(obs[i]->body);
        free(obs[i]);
    }
    free(obs);
}

void destroy_and_free_tile_layer(tile_layer_t *layer)
{
    destroy_tiles(layer->tiles);
    free(layer->tiles);
    sfConvexShape_destroy(layer->tile_shape);
    free(layer);
}

void destroy_and_free_object_layer(object_layer_t *layer)
{
    destroy_objects(layer->objects);
    free(layer->objects);
    sfSprite_destroy(layer->obj_sprite);
    free(layer);
}