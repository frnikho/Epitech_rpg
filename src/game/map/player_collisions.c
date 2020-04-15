/*
** EPITECH PROJECT, 2020
** map_parser
** File description:
** player_collisions
*/

#include "game/map.h"
/*
int is_rectangles_in_collision(sfFloatRect *r_one, sfFloatRect *r_two)
{
    if (r_one->left + r_one->width > r_two->left && \
    r_one->left < r_two->left + r_two->width) {
        if (r_one->top + r_one->height > r_two->top &&\
        r_one->top < r_two->top + r_two->height) {
            return (1);
        }
    }
    return (0);
}

int check_collisions_ahead(map_t *map, player_t *player)
{
    sfFloatRect rect = {0, 0, 0, 0};

    for (int i = 0; map->obs[i]; i++) {
        rect.left = map->obs[i]->shape.left*map->zoom+map->offset.x;
        rect.top = map->obs[i]->shape.top*map->zoom+map->offset.y;
        rect.width = map->obs[i]->shape.width*map->zoom;
        rect.height = map->obs[i]->shape.height*map->zoom;
        //if (is_rectangles_in_collision(&player->collision_box, &rect) == 1)
        //    return (1);
    }
    return (0);
}

void update_player_collision_box(sfVideoMode *mode, player_t *player, \
map_t *map)
{
    int size = 50 * map->zoom;

    //player->collision_box.left = (mode->width / 2) - (size / 2);
    //player->collision_box.top = (mode->height / 2) - (size / 2);
    //player->collision_box.height = size;
    //player->collision_box.width = size;
}*/