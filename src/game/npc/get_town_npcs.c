/*
** EPITECH PROJECT, 2020
** get_town_npc.c
** File description:
** get town npc function
*/

#include "game/npc.h"
#include "lib/utils/string.h"
#include "lib/utils/file.h"
#include <stdlib.h>

static char *clean_fp(char *fp)
{
    char *result = malloc(sizeof(char) * (str_len(fp)));
    int index = 0;
    for (int i = 0; fp[i] != 0; i++) {
        if (fp[i] == ' ' || fp[i] == '\n');
        if (fp[i] != '\"') {
            result[index] = fp[i];
            index++;
        }
    }
    result[index] = 0;
    return (result);
}

npc_t **get_town_npcs(char *town)
{
    int fd = open_file("content/npc/location.json");
    char *content = read_file(fd, "content/npc/location.json");

    char *town_npcs = get_key_data(content, town);
    int count = fget_nbr(get_key_data(town_npcs, "count"));
    npc_t **npcs = malloc(sizeof(npc_t*) * (count + 1));
    for (int i = 0; i < count; i++) {
        char *value = convert_str(i+1);
        char *key = get_key_data(town_npcs, value);
        int x = fget_nbr(get_key_data(key, "x"));
        int y = fget_nbr(get_key_data(key, "y"));
        int speed = fget_nbr(get_key_data(key, "speed"));
        char *fp = get_key_data(key, "file");
        char *clear_fp = clean_fp(fp);
        free(fp);
        npcs[i] = create_npc(clear_fp, (sfVector2f){x, y}, speed, "topaze_king");
        npcs[i]->script = get_npc_script(get_key_data(key, "script"));
    }
    npcs[count] = 0;
    return (npcs);
}