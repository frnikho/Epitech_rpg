/*
** EPITECH PROJECT, 2020
** game.c
** File description:
** game function
*/

#include "game.h"
#include "lib/utils/file.h"
#include "lib/utils/string.h"
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
    game->config.sound_volume = 100;
    game->config.music_volume = 100;
    game->config.dialog_speed = 3;
    game->config.framerate = 144;
}

static void load_game_settings(game_t *game)
{
    int fd = open_file("content/settings.json");
    if (!fd) {
        init_default_settings(game);
        return;
    }
    char *content = read_file(fd, "content/settings.json");
    if (!content || content[0] == 0) {
        init_default_settings(game);
        return;
    }
    game->config.framerate = fget_nbr(get_key_data(content, "framerate"));
    game->config.dialog_speed = fget_nbr(get_key_data(content, "dialog_speed"));
    game->config.sound_volume = fget_nbr(get_key_data(content, "sound_volume"));
    game->config.music_volume = fget_nbr(get_key_data(content, "music_volume"));
    free(content);
}

game_t *init_game(sfVector2f win_size, char *title)
{
    game_t *game = malloc(sizeof(game_t));
    #ifdef DEFAULT_CONFIG
    load_game_settings(game);
    #endif
    game->mode.width = (unsigned int) win_size.x;
    game->mode.height =(unsigned int) win_size.y;
    game->mode.bitsPerPixel = 32;
    game->clock = sfClock_create();
    game->code = 0;
    sfFloatRect rect = {0, 0, win_size.x, win_size.y};
    game->camera = sfView_createFromRect(rect);
    game->window = sfRenderWindow_create(game->mode, title, sfClose, 0);
    game->current_state = OVERWORLD;
    sfRenderWindow_setFramerateLimit(game->window, game->config.framerate);
    sfRenderWindow_setView(game->window, game->camera);
    //sfView_zoom(game->camera, 0.5);
    return (game);
}

void dispose_game(game_t *game)
{
    sfRenderWindow_destroy(game->window);
    sfView_destroy(game->camera);
    sfClock_destroy(game->clock);
    free(game);
}