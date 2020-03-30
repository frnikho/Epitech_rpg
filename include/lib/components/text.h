/*
** EPITECH PROJECT, 2020
** text.h
** File description:
** header file
*/

#ifndef MUL_MY_DEFENDER_2019_TEXT_H
#define MUL_MY_DEFENDER_2019_TEXT_H

#define FONT "assets/font/dq.ttf"

#include <SFML/Graphics.h>

typedef struct text_s {
    long int delta;
    sfFont *font;
    sfText *text;
    char *title;
    int size;
    float letter_spacing;
    float line_spacing;
    sfVector2f position;
} text_t;

text_t *init_text(char *title, int size, sfVector2f position);
void update_text(text_t *text, long int delta);
void draw_text(sfRenderWindow *window, text_t *text);
void dispose_text(text_t *text);
void set_text_color(text_t *text, sfColor color);
void set_text_random_color(text_t *text);
void set_text_font(text_t *text, char *filepath);
int is_text_clicked(text_t *text, sfEvent event);

#endif
