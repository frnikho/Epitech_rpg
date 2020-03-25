/*
** EPITECH PROJECT, 2020
** game.h
** File description:
** header file
*/

#ifndef DEFENDER_GAME_H
#define DEFENDER_GAME_H

#define READ_SIZE 1024*1024
#define DEBUG 1
#define DEFAULT_CONFIG 1

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "game/player.h"

enum game_state {INTRO_SCREEN = 0, MAIN_MENU = 1, LEVEL_1 = 2};

typedef struct config_s {
    int framerate;
    int dialog_speed;
    int sound_volumn;
    int music_volumn;

    int key_left;
    int key_right;
    int key_up;
    int key_down;
    int key_inventory;
    int key_pause;
} config_t;

typedef struct game_s {
    sfRenderWindow *window;
    sfClock *clock;
    sfVideoMode mode;
    sfEvent event;
    sfView *camera;
    float volume;
    enum game_state current_state;
    config_t config;
    player_t *player;
} game_t;

game_t *init_game(sfVector2f win_size, char *title);
void dispose_game(game_t *game);

void drag_camera(game_t *game);
void handle_move_camera(game_t *game);

#endif
