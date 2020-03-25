/*
** EPITECH PROJECT, 2020
** bump.h
** File description:
**  function
*/

#ifndef DEFENDER_BUMP_H
#define DEFENDER_BUMP_H

#include <SFML/Graphics/Types.h>
#include <math.h>
#include <SFML/Audio.h>

typedef struct bump_s {
    float delta;
    sfTexture *screen;
    sfSprite *sprite;
    float speed;
    float magnitude_y;
    float magnitude_x;
    float count_x;
    float count_y;
    int is_active;
} bump_t;

bump_t *create_bump(sfRenderWindow *w, float s, float magn_x, float magn_y);
void free_bump(bump_t *bump);

int update_bump(bump_t *bump, sfRenderWindow *window, long int delta);
void draw_bump(sfRenderWindow *window, bump_t *bump);

void set_bump_active(bump_t *bump, int is_active);
void toggle_bump_active(bump_t *bump);
int is_bump_active(bump_t *bump);

#endif