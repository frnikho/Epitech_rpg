/*
** EPITECH PROJECT, 2020
** map_parser
** File description:
** temp_dependencies
*/

#include "game/map.h"

void print_point(sfRenderWindow *window, sfVector2f point)
{
    sfCircleShape *circle = sfCircleShape_create();
    int radius = 2;

    sfCircleShape_setFillColor(circle, sfColor_fromRGBA(255, 0, 0, 255));
    sfCircleShape_setPosition(circle, (sfVector2f){point.x-(radius/2), \
        point.y-(radius/2)});
    sfCircleShape_setRadius(circle, radius);
    sfRenderWindow_drawCircleShape(window, circle, NULL);
    sfCircleShape_destroy(circle);
}

void draw_rectangle(sfFloatRect *rec, sfRenderWindow *window)
{
    sfRectangleShape *shape = sfRectangleShape_create();

    sfRectangleShape_setSize(shape, (sfVector2f){rec->width, rec->height});
    sfRectangleShape_setPosition(shape, (sfVector2f){rec->left, rec->top});
    sfRectangleShape_setFillColor(shape, sfColor_fromRGBA(172, 0, 230, 255));
    sfRenderWindow_drawRectangleShape(window, shape, NULL);
    sfRectangleShape_destroy(shape);
}

void print_player(sfRenderWindow *window, map_t *map)
{
    sfCircleShape *circle = sfCircleShape_create();
    int radius = 16;

    sfCircleShape_setFillColor(circle, sfColor_fromRGBA(172, 0, 230, 255));
    sfCircleShape_setPosition(circle, \
    (sfVector2f){(1600/2)-((radius*map->zoom)), \
(800/2)-((radius*map->zoom))});
    sfCircleShape_setRadius(circle, radius*map->zoom);
    sfRenderWindow_drawCircleShape(window, circle, NULL);
    sfCircleShape_destroy(circle);
}

void print_framerate(void)
{
    static int first = 1;
    static sfClock *clock;
    static int fps = 0;

    if (first == 1) {
        clock = sfClock_create();
        first = 0;
    }
    sfTime elapsed = sfClock_getElapsedTime(clock);
    if (sfTime_asSeconds(elapsed) >= 1) {
        fflush(stdout);
        fps = 0;
        sfClock_restart(clock);
    } else
        fps ++;
}