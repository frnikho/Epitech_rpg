/*
** EPITECH PROJECT, 2020
** anim_sprite.h
** File description:
** anim sprite function
*/

#ifndef MUL_MY_DEFENDER_2019_ANIM_SPRITE_H
#define MUL_MY_DEFENDER_2019_ANIM_SPRITE_H

#include <SFML/Graphics.h>

typedef struct anim_info_s {
    int x;
    int y;
    int width;
    int height;
    int column;
    int row;
    int anim;

    int count_anim;
    int count_row;
    int count_column;

} anim_info_t;

typedef struct anim_sprite_s {
    long int delta;
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    anim_info_t *info;
} anim_sprite_t;

anim_sprite_t *init_anim_sprite(char *fp, sfVector2f p, anim_info_t *i);
anim_info_t *init_anim_info(sfIntRect rect, int row, int column, int count);

void draw_anim_sprite(sfRenderWindow *window, anim_sprite_t *sprite);
void update_anim_sprite(anim_sprite_t *sprite, long int delta);
void dispose_anim_sprite(anim_sprite_t *sprite);
void move_anim_sprite_position(anim_sprite_t *sprite, sfVector2f pos);
void set_anim_sprite_position(anim_sprite_t *sprite, sfVector2f pos);
sfVector2f get_anim_sprite_position(anim_sprite_t *sprite);
void update_anim_sprite_rect(anim_sprite_t *sprite);
int is_anim_sprite_clicked(anim_sprite_t *sprite, sfEvent event);
int is_anim_sprite_release(anim_sprite_t *sprite, sfEvent event);
int is_anim_sprite_hovered(anim_sprite_t *sprite, sfRenderWindow *window);
void dispose_anim_info(anim_info_t *info);
void set_anim_sprite_anim(anim_sprite_t *sprite, int count);

#endif