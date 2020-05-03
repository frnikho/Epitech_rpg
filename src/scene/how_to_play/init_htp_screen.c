/*
** EPITECH PROJECT, 2020
** init_htp_screen.c
** File description:
**  function
*/

#include "game.h"
#include "how_to_play_scene.h"

int init_htp_screen(game_t *game, htp_scene_t *htp)
{
    htp->delta = 0;
    htp->sound = init_sound("assets/music/menu.ogg");
    play_sound(htp->sound, 60);
    htp->bg = init_sprite("assets/sprite/background/bg.png", 0);
    htp->box = init_sprite("assets/sprite/gui/select_enemy_gui.png", 0);
    set_sprite_position(htp->box, (sfVector2f){550, 400});
    htp->text = init_text("Z to move forward\n\n\
Q to move left\n\nD to move rightn\nS to move backward", 20, (sfVector2f){640, 420});
    htp->cursor = init_sprite("assets/sprite/gui/pointer_big.png", 0);
    htp->text = init_text("Quit", 20, (sfVector2f){30, 30});
    set_sprite_scale(htp->cursor, 1.2);
    set_text_font(htp->text, FONT);
    set_sprite_scale(htp->bg, 0.9);
    htp->title = init_text("How to play", 28, (sfVector2f){760, 80});
    set_text_font(htp->title, "assets/font/dq.ttf");
    return (0);
}
