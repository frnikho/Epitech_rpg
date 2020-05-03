/*
** EPITECH PROJECT, 2020
** how_to_play_scene.h
** File description:
**  function
*/

#ifndef MY_RPG_HTP_SCENE_H
#define MY_RPG_HTP_SCENE_H

#include "game.h"
#include <lib/components/sound.h>

typedef struct htp_scene_s {
    long int delta;
    sprite_t *cursor;
    sprite_t *box;
    sprite_t *bg;
    text_t *title;
    sound_t *sound;
    text_t *text;
} htp_scene_t;

void how_to_play(game_t *game, long int delta);
void destroy_how_to_play(game_t *game, htp_scene_t *htp);
int init_htp_screen(game_t *game, htp_scene_t *htp_scene);
int input_htp_screen(game_t *game, htp_scene_t *hpt_scene);
int update_htp_screen(game_t *game, htp_scene_t *htp, long int delta);
int render_htp_screen(game_t *game, htp_scene_t *htp, long int delta);

#endif