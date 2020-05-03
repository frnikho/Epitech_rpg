/*
** EPITECH PROJECT, 2020
** update_settings_screen.c
** File description:
**  function
*/

#include "game.h"
#include "scene/settings.h"


int update_settings_screen(game_t *game, settings_screen_t *s, long int delta)
{
    static int pos[][2] = {{490, 259}, {595, 259}, {700, 259}, {810, 259},
        {920, 259}, {490, 412}, {590, 412}, {680, 412}, {700, 695}};
    if (s->select_cursor < 0)
        s->select_cursor = 0;
    if (s->select_cursor > 8)
        s->select_cursor = 8;
    sfVector2f spos = {pos[s->select_cursor][0], pos[s->select_cursor][1]};
    set_sprite_position(s->cursor, spos);
    update_dialog(s->dialog, delta);
    update_fade(s->fade, delta);
    if (s->fade->is_finish) {
        game->current_state = MAIN_MENU;
        return (0);
    }
    if (s->dialog->is_finished && !s->fade->is_active && !s->fade->is_finish) {
        set_fade_active(s->fade);
    }
}