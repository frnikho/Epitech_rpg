/*
** EPITECH PROJECT, 2020
** text_color.c
** File description:
** text function
*/

#include "lib/components/text.h"

void set_text_color(text_t *text, sfColor color)
{
    sfText_setColor(text->text, color);
}

void set_text_random_color(text_t *text)
{
}