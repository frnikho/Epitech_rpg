/*
** EPITECH PROJECT, 2020
** fade.h
** File description:
** header file
*/

#ifndef CSFML_EFFECT_LIB_FADE_H
#define CSFML_EFFECT_LIB_FADE_H

#include <SFML/Graphics.h>
#include "game.h"

enum FADE_TYPE {FADE_IN = 0, FADE_OUT = 1};

typedef struct fade_s {
    long int delta;
    sfVector2f screen_size;
    sfRectangleShape *shape;
    sfColor color;
    sfVector2f size;
    float speed;
    int fade_in;
    int is_finish;
    int is_active;
    void (*callback)(game_t *game);
} fade_t;

fade_t *init_fade(sfVector2f size, sfColor color, float speed, int in);
void draw_fade(sfRenderWindow *window, fade_t *fade);
void update_delta(fade_t *fade, long int delta);
void update_fade(fade_t *fade, long int delta);
void dispose_fade(fade_t *fade);
void reset_fade(fade_t *fade);
int fade_is_active(fade_t *fade);
int fade_is_finish(fade_t *fade);
void set_fade_active(fade_t *fade);

#endif
