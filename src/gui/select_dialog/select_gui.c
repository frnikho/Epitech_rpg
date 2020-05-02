/*
** EPITECH PROJECT, 2020
** select_dialog.c
** File description:
**  function
*/

#include "gui/select_gui.h"
#include <stdlib.h>
#include "lib/utils/string.h"

static void monster_loop(monster_t **monsters, \
int count_monster, select_gui_t *gui)
{
    for (int i = 0; i < count_monster; i++) {
        char *count = convert_str(i+1);
        char *name = monsters[i]->name;
        char *tmp = str_cat(count, ". ");
        tmp = str_cat(tmp, name);
        gui->monsters_name[i] = init_text(tmp, 18, \
        (sfVector2f){920, 640 + (i*20)});
        set_text_font(gui->monsters_name[i], FONT);
    }
}

select_gui_t *create_select_gui(monster_t **monsters)
{
    select_gui_t *gui = malloc(sizeof(select_gui_t));
    int count_monster = get_monsters_length(monsters);

    gui->is_selected = 0;
    gui->is_active = 0;
    gui->monster_index = 0;
    gui->monsters = monsters;
    gui->gui = init_sprite("assets/sprite/gui/select_enemy_gui.png", 0);
    set_sprite_position(gui->gui, (sfVector2f){850, 600});
    gui->monsters_name = malloc(sizeof(text_t*) * \
(get_monsters_length(monsters) + 1));
    monster_loop(monsters, count_monster, gui);
    gui->monsters_name[count_monster] = 0;
    gui->cursor = init_sprite("assets/sprite/gui/pointer_small.png", 0);
    set_sprite_position(gui->cursor, (sfVector2f){880, 640});
    set_sprite_scale(gui->cursor, 2.2f);
    return (gui);
}

void dispose_select_gui(select_gui_t *gui)
{
    dispose_sprite(gui->gui);
    dispose_sprite(gui->cursor);
    free(gui);
}