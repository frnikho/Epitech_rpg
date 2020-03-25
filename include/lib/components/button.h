/*
** EPITECH PROJECT, 2020
** button.h
** File description:
** button header
*/
#ifndef DEFENDER_BUTTON_H
#define DEFENDER_BUTTON_H

#include "anim_sprite.h"

typedef struct button_s {
    void (*action)(struct button_s);
    anim_sprite_t *sprite;
} button_t;

button_t *init_button(anim_sprite_t *sprite);
void dispose_button(button_t *btn);
void draw_button(sfRenderWindow *window, button_t *btn);

#endif