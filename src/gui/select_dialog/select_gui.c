/*
** EPITECH PROJECT, 2020
** select_dialog.c
** File description:
**  function
*/

#include "gui/select_gui.h"
#include <stdlib.h>
#include "lib/utils/string.h"

select_gui_t *create_select_gui(monster_t **monsters)
{
    select_gui_t *gui = malloc(sizeof(select_gui_t));
    gui->is_selected = 0;
    gui->is_active = 0;
    gui->monster_index = 0;
    gui->monsters = monsters;
    gui->gui = init_sprite("assets/sprite/gui/select_enemy_gui.png", 0);
    set_sprite_position(gui->gui, (sfVector2f){850, 600});

    char *str = str_cat("1.\t", monsters[0]->name);
    for (int i = 1; monsters[i] != 0; i++) {
        str = str_cat_char(str, '\n');
        str = str_cat(str, convert_str(i+1));
        str = str_cat(str, ".\t");
        str = str_cat(str, monsters[i]->name);
    }

    gui->monsters_name = init_text(str, 18, (sfVector2f){920, 640});
    set_text_font(gui->monsters_name, "assets/font/dq.ttf");
    return (gui);
}

void dispose_select_gui(select_gui_t *gui)
{
    //TODO dispose gui
}