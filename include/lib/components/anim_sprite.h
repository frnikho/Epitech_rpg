/*
** EPITECH PROJECT, 2020
** anim_sprite.h
** File description:
** anim sprite function
*/

#ifndef MUL_MY_DEFENDER_2019_ANIM_SPRITE_H
#define MUL_MY_DEFENDER_2019_ANIM_SPRITE_H

#include <SFML/Graphics.h>

typedef struct anim_sprite_s {
    long int delta;
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect *rect;
    int count;
    int current_count;
} anim_sprite_t;

anim_sprite_t *create_anim_sprite(char *fp, sfVector2f p);
void add_anim_frame(anim_sprite_t *anim, sfIntRect rect);
void update_anim_sprite(anim_sprite_t *sprite, long int delta);
void draw_anim_sprite(sfRenderWindow *window, anim_sprite_t *sprite);
void dispose_anim_sprite(anim_sprite_t *sprite);
void set_anim_sprite_scale(anim_sprite_t *sprite, float scale);
void update_anim_sprite_rect(anim_sprite_t *sprite);

#endif