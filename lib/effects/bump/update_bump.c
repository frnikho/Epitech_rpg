/*
** EPITECH PROJECT, 2020
** update_bump.c
** File description:
**  function
*/

#include "lib/effects/bump.h"
#include <SFML/Graphics.h>

int update_bump(bump_t *bump, sfRenderWindow *window, long int delta)
{
    if (bump->delta < (480000 / bump->speed)) {
        bump->delta += delta;
        return (0);
    } else {
        bump->delta = 0;
    }
    if (!window || !bump || !bump->is_active)
        return (0);
    sfTexture_updateFromRenderWindow(bump->screen, window, 0, 0);
    sfSprite_setTexture(bump->sprite, bump->screen, sfFalse);
    float y = cos(bump->count_y * ((180) / M_PI)) * bump->magnitude_y;
    float x = cos(bump->count_x) * bump->magnitude_x;
    sfSprite_setPosition(bump->sprite, (sfVector2f){0 + x, 0 + y});
    bump->count_y+=M_PI;
    bump->count_x+=M_PI;
    return (1);
}