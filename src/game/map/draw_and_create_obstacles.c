/*
** EPITECH PROJECT, 2020
** map_parser
** File description:
** create_obstacles
*/

#include "game/map.h"
#include "game/collision.h"

void draw_single_obstacle(sfRenderWindow *window, map_t *map, obstacle_t *obs)
{
    float zoom = map->zoom;
    float off_x = map->offset.x;
    float off_y = map->offset.y;

    sfConvexShape_setPoint(obs->body, 0, \
    (sfVector2f){obs->shape.left*zoom+off_x, obs->shape.top*zoom+off_y});
    sfConvexShape_setPoint(obs->body, 1, \
    (sfVector2f){(obs->shape.left+obs->shape.width)*zoom+off_x, \
        obs->shape.top*zoom+off_y});
    sfConvexShape_setPoint(obs->body, 2, \
    (sfVector2f){(obs->shape.left+obs->shape.width)*zoom+off_x, \
        (obs->shape.top+obs->shape.height)*zoom+off_y});
    sfConvexShape_setPoint(obs->body, 3, \
    (sfVector2f){(obs->shape.left)*zoom+off_x, \
        (obs->shape.top+obs->shape.height)*zoom+off_y});
    sfRenderWindow_drawConvexShape(window, obs->body, NULL);
}

void draw_obstacles(map_t *map, sfRenderWindow *window)
{
    for (int i = 0; map->obs[i]; i++)
        draw_single_obstacle(window, map, map->obs[i]);
}

obstacle_t *create_obtacle(char **obj_tab, int index)
{
    obstacle_t *obs = malloc(sizeof(obstacle_t));

    char *width_str = get_key_data(obj_tab[index], "width");
    char *height_str = get_key_data(obj_tab[index], "height");
    char *top_str = get_key_data(obj_tab[index], "y");
    char *left_str = get_key_data(obj_tab[index], "x");

    obs->body = sfConvexShape_create();
    sfConvexShape_setPointCount(obs->body, 4);
    sfConvexShape_setFillColor(obs->body, sfColor_fromRGBA(255, 0, 0, 100));
    obs->rotation = 0;
    obs->shape.width = my_getfloat(width_str);
    obs->shape.height = my_getfloat(height_str);
    obs->shape.top = my_getfloat(top_str);
    obs->shape.left = my_getfloat(left_str);
    obs->collision = create_collision_box(obs->shape, 0, 1);
    free(width_str);
    free(height_str);
    free(top_str);
    free(left_str);
    return (obs);
}

void create_obtacles_tab(char **obj_tab, map_t *map)
{
    int tab_len = 0;

    for (; obj_tab[tab_len]; tab_len++);
    map->obs = malloc(sizeof(obstacle_t *) * (tab_len+1));
    map->obs[tab_len] = NULL;
    for (int i = 0; obj_tab[i]; i++)
        map->obs[i] = create_obtacle(obj_tab, i);
}