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

static void init_battle_zone(game_t *game, battle_screen_t *battle)
{

    int monsters = (rand() % 3) +1;

    int fd = open_file("content/zone_info.json");
    char *content = read_file(fd, "content/zone_info.json");
    char *zone = convert_str(game->player->zone);
    char *zone_json = get_key_data(content, zone);
    char **array = str_split_json_array(zone_json, ',', 1);

    battle->monster = malloc(sizeof(monster_t) * (monsters+1));
    for (int i = 0; i < monsters; i++) {
        int index = rand() % array_length(array);
        printf("index: %d\n", index);
        battle->monster[i] = create_monster(array[index]);
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
}