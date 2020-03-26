/*
** EPITECH PROJECT, 2020
** update_settings_screen.c
** File description:
**  function
*/

#include "game.h"
#include "scene/settings.h"

int change_settings()
{

}

int update_settings_screen(game_t *game, settings_screen_t *s, long int delta)
{
    static int pos[][2] = {{490, 259}, {595, 259}, {700, 259}, {810, 259},
        {920, 259}, {490, 412}, {590, 412}, {680, 412}};
    if (s->select_cursor < 0)
        s->select_cursor = 0;
    if (s->select_cursor > 7)
        s->select_cursor = 7;
    sfVector2f spos = {pos[s->select_cursor][0], pos[s->select_cursor][1]};
    set_sprite_position(s->cursor, spos);
}