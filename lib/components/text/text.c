/*
** EPITECH PROJECT, 2020
** text.c
** File description:
** text function
*/

#include "lib/components/text.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

text_t *init_text(char *title, int size, sfVector2f position)
{
    text_t *text = malloc(sizeof(text_t));
    text->text = sfText_create();
    text->size = size;
    text->title = title;
    text->delta = 0;
    text->letter_spacing = 1;
    text->line_spacing = 1;
    text->position = position;
    return (text);
}

void update_text(text_t *text, long int delta)
{
    text->delta += delta;
}

void draw_text(sfRenderWindow *window, text_t *text)
{
    sfText_setString(text->text, text->title);
    sfText_setPosition(text->text, text->position);
    sfText_setCharacterSize(text->text, text->size);
    sfText_setFont(text->text, text->font);
    sfText_setColor(text->text, sfWhite);
    sfText_setLetterSpacing(text->text, text->letter_spacing);
    sfText_setLineSpacing(text->text, text->line_spacing);
    sfRenderWindow_drawText(window, text->text, NULL);
}

void dispose_text(text_t *text)
{
    sfFont_destroy(text->font);
    sfText_destroy(text->text);
    free(text);
}