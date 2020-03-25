/*
** EPITECH PROJECT, 2020
** button.c
** File description:
** function
*/

#include "lib/components/button.h"
#include <stdlib.h>

button_t *init_button(anim_sprite_t *sprite)
{
    button_t *btn = malloc(sizeof(button_t));
    btn->sprite = sprite;
    return (btn);
}

void dispose_button(button_t *btn)
{
    dispose_anim_sprite(btn->sprite);
}

void draw_button(sfRenderWindow *window, button_t *btn)
{
    draw_anim_sprite(window, btn->sprite);
}