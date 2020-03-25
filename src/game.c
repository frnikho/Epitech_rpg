/*
** EPITECH PROJECT, 2020
** game.c
** File description:
** game function
*/

#include "game.h"
#include <stdlib.h>
#include <stdio.h>

static void init_default_settings(game_t *game)
{
    game->config.key_left = sfKeyLeft;
    game->config.key_right = sfKeyRight;
    game->config.key_down = sfKeyDown;
    game->config.key_up = sfKeyUp;
    game->config.key_inventory = 'e';
    game->config.key_pause = sfKeyEscape;
    game->config.sound_volumn = 100;
    game->config.music_volumn = 100;
    game->config.dialog_speed = 3;
    game->config.framerate = 144;
}

static void debug(game_t *game, sfVector2f win_size)
{
    config_t conf = game->config;
    printf("[debug] created windows (%.fx%.f)\n", win_size.x, win_size.y);
    printf("[debug] with max %d FPS\n", conf.framerate);
    printf("[debug] CONFIG:\n[debug]\t sound = ");
    printf("%d%%, music = %d%%\n", conf.sound_volumn, conf.music_volumn);
    printf("[debug]\t dialog speed = %d\n", conf.dialog_speed);
}

game_t *init_game(sfVector2f win_size, char *title)
{
    game_t *game = malloc(sizeof(game_t));
    #ifdef DEFAULT_CONFIG
    init_default_settings(game);
    #endif
    game->mode.width = win_size.x;
    game->mode.height = win_size.y;
    game->mode.bitsPerPixel = 32;
    game->clock = sfClock_create();
    sfFloatRect rect = {0, 0, win_size.x, win_size.y};
    game->camera = sfView_createFromRect(rect);
    #ifdef DEBUG
    debug(game, win_size);
    #endif
    game->window = sfRenderWindow_create(game->mode, title, sfClose, 0);
    game->current_state = 0;
    sfRenderWindow_setFramerateLimit(game->window, game->config.framerate);
    sfRenderWindow_setView(game->window, game->camera);
    return (game);
}

void dispose_game(game_t *game)
{
    sfRenderWindow_destroy(game->window);
    sfView_destroy(game->camera);
    sfClock_destroy(game->clock);
    free(game);
}