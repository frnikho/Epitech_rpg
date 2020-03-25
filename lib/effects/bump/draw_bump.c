/*
** EPITECH PROJECT, 2020
** draw_bump.c
** File description:
**  function
*/

#include <SFML/Graphics.h>
#include "lib/effects/bump.h"

void draw_bump(sfRenderWindow *window, bump_t *bump)
{
    if (bump->is_active)
        sfRenderWindow_drawSprite(window, bump->sprite, 0);
}