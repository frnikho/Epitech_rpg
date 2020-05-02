/*
** EPITECH PROJECT, 2020
** map_parser
** File description:
** render_optimisation
*/

#include "game/map.h"

int is_point_in_window(sfFloatRect rect, sfVector2f point)
{
    if (point.x > rect.left && point.x < rect.width)
        if (point.y > rect.top && point.y < rect.height)
            return (1);
    return (0);
}

int is_square_in_window(sfFloatRect rect, sfVector2f *points)
{
    for (int i = 0; i < 4; i++) {
        if (is_point_in_window(rect, points[i]) == 1)
            return (1);
    }
    return (0);
}

int is_object_displayed(int i, int y, object_layer_t *layer, \
sfRenderWindow *window)
{
    sfVector2f position;
    sfVector2f points[4] = {{0, 0}, {0, 0}, {0, 0}, {0, 0}};
    object_t *obj = layer->objects[map_obj_id(layer->obj_map[y][i])];

    position.x = ((i*layer->tile_size)+(obj->center_offset.x*0)+\
    (layer->tile_size/2))*layer->zoom+layer->offset.x;
    position.y = ((y*layer->tile_size)+(obj->center_offset.y*0)+\
    (layer->tile_size/2))*layer->zoom+layer->offset.y;
    points[0].x = position.x - obj->disapear_dist.x;
    points[0].y = position.y - obj->disapear_dist.y;
    points[1].x = position.x + obj->disapear_dist.x;
    points[1].y = position.y - obj->disapear_dist.y;
    points[2].x = position.x + obj->disapear_dist.x;
    points[2].y = position.y + obj->disapear_dist.y;
    points[3].x = position.x - obj->disapear_dist.x;
    points[3].y = position.y + obj->disapear_dist.y;
    return (1);
}

sfVector2f *is_tile_displayed(tile_layer_t *layer, int i, int y)
{
    int t_size = layer->tile_size;
    float zoom = layer->zoom;
    float off_x = layer->offset.x;
    float off_y = layer->offset.y;
    sfVector2f *points = malloc(sizeof(sfVector2f) * 4);

    points[0] = (sfVector2f){(i*t_size)*zoom+off_x, \
        (y*t_size)*zoom+off_y};
    points[1] = (sfVector2f){((i*t_size)+t_size)*zoom+off_x, \
        (y*t_size)*zoom+off_y};
    points[2] = (sfVector2f){((i*t_size)+t_size)*zoom+off_x, \
        ((y*t_size)+t_size)*zoom+off_y};
    points[3] = (sfVector2f){(i*t_size)*zoom+off_x, \
        ((y*t_size)+t_size)*zoom+off_y};
    return (points);
}