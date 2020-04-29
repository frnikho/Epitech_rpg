/*
** EPITECH PROJECT, 2020
** how_to_play_scene.h
** File description:
**  function
*/

#ifndef MY_RPG_HTP_SCENE_H
#define MY_RPG_HTP_SCENE_H

#include "game.h"

typedef struct htp_scene_s {
    sprite_t *box;
    sprite_t *bg;
    text_t *text;
} htp_scene_t;

void how_to_play(game_t *game, long int delta);
void destroy_how_to_play(game_t *game, htp_scene_t *scene);
int init_htp_screen(game_t *game, htp_scene_t *scene);
int input_htp_screen(game_t *game, htp_scene_t *scene);
int update_htp_screen(game_t *game, htp_scene_t *scene, long int delta);
int render_htp_screen(game_t *game, htp_scene_t *scene, long int delta);

#endif