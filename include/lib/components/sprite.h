/*
** EPITECH PROJECT, 2020
** sprite.h
** File description:
** header file
*/

#ifndef MUL_MY_DEFENDER_2019_SPRITE_H
#define MUL_MY_DEFENDER_2019_SPRITE_H

#include <SFML/Graphics.h>

typedef struct sprite_s {
    long int delta;
    sfTexture *texture;
    sfSprite *sprite;
} sprite_t;

sprite_t *init_sprite(char *filepath);
void dispose_sprite(sprite_t *sprite);
void set_sprite_position(sprite_t *sprite, sfVector2f position);
void move_sprite_position(sprite_t *sprite, sfVector2f offset);
sfVector2f get_sprite_position(sprite_t *sprite);
void draw_sprite(sfRenderWindow *window, sprite_t *sprite);
void update_sprite(sprite_t *sprite, long int delta);
sfVector2f
get_sprite_scale(sprite_t *sprite);
void set_sprite_scale(sprite_t *sprite, float scale);
int is_sprite_clicked(sprite_t *sp, sfEvent event);
int is_sprite_hovered(sprite_t *sprite, sfEvent event);

#endif