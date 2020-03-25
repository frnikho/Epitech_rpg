/*
** EPITECH PROJECT, 2020
** bump.c
** File description:
**  function
*/

#include "lib/effects/bump.h"
#include <stdlib.h>
#include <SFML/Graphics.h>

bump_t *create_bump(sfRenderWindow *window, float speed, float x, float y)
{
    bump_t *bump = malloc(sizeof(bump_t));
    if (!bump || !window)
        return (0);
    bump->is_active = 0;
    bump->delta = 0;
    bump->speed = speed;
    bump->magnitude_x = x;
    bump->magnitude_y = y;
    sfVector2u window_size = sfRenderWindow_getSize(window);
    bump->screen = sfTexture_create(window_size.x, window_size.y);
    bump->sprite = sfSprite_create();
    sfTexture_updateFromRenderWindow(bump->screen, window, 1, 1);
    sfSprite_setTexture(bump->sprite, bump->screen, sfFalse);
    return (bump);
}

void free_bump(bump_t *bump)
{
    sfTexture_destroy(bump->screen);
    sfSprite_destroy(bump->sprite);
    free(bump);
}