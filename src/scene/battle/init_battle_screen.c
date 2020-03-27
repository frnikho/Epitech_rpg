/*
** EPITECH PROJECT, 2020
** init_battle_screen.c
** File description:
**  function
*/

#include <game.h>
#include <scene/battle.h>
#include "lib/utils/string.h"
#include "lib/utils/file.h"

static void init_battle_gui(game_t *game, battle_screen_t *battle)
{
    battle->attack_gui = create_attack_gui(battle->monster);
    battle->select_gui = create_select_gui(battle->monster);
}

static void init_battle_zone(game_t *game, battle_screen_t *battle)
{
    static sfVector2f pos[] = {{150, 300}, {550, 300}, {950, 300}, {1350, 300}, 0};
    int fd = open_file("content/zone_info.json");
    char *content = read_file(fd, "content/zone_info.json");
    char *zone = convert_str(game->player->zone);
    char *zone_json = get_key_data(content, zone);

    int monsters = fget_nbr(get_key_data(zone_json, "count"));
    monsters = (rand() % monsters) + 1;


    zone_json = get_key_data(zone_json, "monsters");
    char **array = str_split_json_array(zone_json, ',', 1);

    battle->monster = malloc(sizeof(monster_t) * (monsters+1));
    for (int i = 0; i < monsters; i++) {
        int index = rand() % array_length(array);
        battle->monster[i] = create_monster(array[index], pos[i]);
    }
    battle->monster[monsters] = 0;

    free(zone_json);
    free(zone);
    free(array);
    free(content);
}

int init_battle_screen(game_t *game, battle_screen_t *battle)
{
    init_battle_zone(game, battle);
    battle->bg = init_sprite("assets/sprite/background/forest.bmp", 0);
    set_sprite_scale(battle->bg, (float) 3.4);
    init_battle_gui(game, battle);
}