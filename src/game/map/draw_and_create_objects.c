/*
** EPITECH PROJECT, 2020
** map_parser
** File description:
** create_objects
*/

#include "game/map.h"

void draw_single_object(object_layer_t *layer, sfRenderWindow *window, int i, int y)
{
    int t_size = layer->tile_size;
    float zoom = layer->zoom;
    int obj_id = map_obj_id(layer->obj_map[y][i]);
    sfVector2f position;
    object_t *obj = layer->objects[obj_id];

    if (layer->obj_map[y][i] == -1)
        return;
    if (is_object_displayed(i, y, layer, window) == 0)
        return;
    position.x = ((i*t_size)-obj->center_offset.x+(t_size/2))*\
    zoom+layer->offset.x;
    position.y = ((y*t_size)-obj->center_offset.y+(t_size/2))*\
    zoom+layer->offset.y;
    obj_id = map_obj_id(layer->obj_map[y][i]);
    sfSprite_setPosition(layer->obj_sprite, position);
    sfSprite_setTexture(layer->obj_sprite, obj->texture, sfFalse);
    sfSprite_setScale(layer->obj_sprite, (sfVector2f){obj->scale.x * zoom, \
        obj->scale.y * zoom});
    sfRenderWindow_drawSprite(window, layer->obj_sprite, NULL);
}

void draw_object_layer(object_layer_t *layer, sfRenderWindow *window)
{
    for (int y = 0; y < layer->height; y++) {
        for (int i = 0; i < layer->width; i++) {
            draw_single_object(layer, window, i, y);
        }
    }
}

void draw_objects(map_t *map, sfRenderWindow *window, int *layers_to_print)
{
    for (int i = 0; map->obj_layers[i]; i++) {
        if (layers_to_print[0] == 0) {
            draw_object_layer(map->obj_layers[i], window);
            continue;
        }
        for (int y = 0; layers_to_print[y]; y++) {
            i == (layers_to_print[y]-1) ? \
        draw_object_layer(map->obj_layers[i], window) : 0;
        }
    }
}

object_layer_t *init_obj_layer(int **obj_map)
{
    object_layer_t *layer = malloc(sizeof(object_layer_t));

    layer->objects = create_objects();
    layer->width = get_tab_width(obj_map);
    layer->height = get_tab_height(obj_map);
    layer->tile_size = 32;
    layer->obj_sprite = sfSprite_create();
    layer->obj_map = obj_map;
    layer->zoom = 1;
    layer->offset = (sfVector2f){0, 0};
    return (layer);
}

void create_object_tab(map_t *map, int ***objs_tab)
{
    int tab_len = 0;

    for (; objs_tab[tab_len]; tab_len++);
    map->obj_layers = malloc(sizeof(object_layer_t*) * (tab_len+1));
    map->obj_layers[tab_len] = NULL;
    for (int i = 0; objs_tab[i]; i++)
        map->obj_layers[i] = init_obj_layer(objs_tab[i]);
}