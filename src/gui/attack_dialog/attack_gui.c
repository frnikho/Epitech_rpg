/*
** EPITECH PROJECT, 2020
** attack_dialog.c
** File description:
**  function
*/

#include "game/monster.h"
#include "gui/attack_gui.h"
#include <stdlib.h>

attack_gui_t *create_attack_gui(monster_t **monster)
{
    attack_gui_t *gui = malloc(sizeof(attack_gui_t));
    gui->is_selected = 0;
    gui->select_index = 0;
    gui->box = init_sprite("assets/sprite/gui/attack_gui.png", 0);
    set_sprite_position(gui->box, (sfVector2f){390, 600});
    gui->cursor = init_sprite("assets/sprite/gui/pointer_small.png", 0);
    set_sprite_scale(gui->cursor, 2);
    gui->attack = init_text("Attaquer", 23, (sfVector2f){450, 630});
    gui->habilities = init_text("Aptitudes", 23, (sfVector2f){615, 630});
    gui->spells = init_text("Sorts", 23, (sfVector2f){450, 680});
    gui->objects = init_text("Objets", 23, (sfVector2f){615, 680});
    gui->goaway = init_text("Fuite", 23, (sfVector2f){450, 730});
    gui->tension = init_text("Tension", 23, (sfVector2f){615, 730});
    set_text_font(gui->attack, "assets/font/dq.ttf");
    set_text_font(gui->tension, "assets/font/dq.ttf");
    set_text_font(gui->objects, "assets/font/dq.ttf");
    set_text_font(gui->habilities, "assets/font/dq.ttf");
    set_text_font(gui->spells, "assets/font/dq.ttf");
    set_text_font(gui->goaway, "assets/font/dq.ttf");
    return (gui);
}

void destroy_attack_gui(attack_gui_t *gui)
{
    dispose_sprite(gui->box);
}