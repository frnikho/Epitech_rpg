/*
** EPITECH PROJECT, 2020
** text_font.c
** File description:
** text function
*/

#include "lib/components/text.h"

void set_text_font(text_t *text, char *filepath)
{
    text->font = sfFont_createFromFile(filepath);
}