/*
** EPITECH PROJECT, 2020
** intro_screen_init
** File description:
** intro_screen_init function
*/

#include <lib/utils/string.h>
#include "lib/components/anim_sprite.h"
#include "game.h"
#include "scene/intro_screen.h"

int init_intro_screen(game_t *game, intro_screen_t *screen)
{
    screen->delta = 0;
    char *test = "Warning, this game is so very very fun, please play with caution ";
    char **content = str_split(test, '#');
    screen->dialog = create_dialog(content, 1, (sfVector2f){420, 640}, 1);
}