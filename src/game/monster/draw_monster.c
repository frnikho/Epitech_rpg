/*
** EPITECH PROJECT, 2020
** draw_monster.c
** File description:
**  function
*/

#include <game/monster.h>

void draw_monster(sfRenderWindow *window, monster_t *monster)
{
    draw_sprite(window, monster->sprite);
}