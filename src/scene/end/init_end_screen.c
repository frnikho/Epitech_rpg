/*
** EPITECH PROJECT, 2020
** end_screen_init
** File description:
** end_screen_init function
*/

#include "lib/utils/file.h"
#include "lib/components/anim_sprite.h"
#include "game.h"
#include "scene/end_screen.h"

int init_end_screen(game_t *game, end_screen_t *screen)
{
    screen->bg = init_sprite("assets/sprite/background/ending_screen.png", 0);
    screen->text = init_text("Apres tous ces efforts, le Roi offrit la \
recompense au jeune heros.\nAinsi la paix revint sur les terres de Topaze.", \
30, (sfVector2f){320, 15});
    set_text_font(screen->text, FONT);
    return (0);
}