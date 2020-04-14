/*
** EPITECH PROJECT, 2020
** get_npc_script.c
** File description:
** npc script function
*/

#include "lib/utils/string.h"
#include "game/npc.h"
#include <stdlib.h>

script_t *get_npc_script(char *str_script)
{
    char *action = get_key_data(str_script, "actions");
    int count = fget_nbr(get_key_data(action, "count"));
    if (count == 0)
        return (0);
    script_t *script = malloc(sizeof(script_t));
    script->max_count = count;
    script->pos_count = 0;
    action_t *actions = malloc(sizeof(action_t) * (count+1));

    for (int i = 0; i < count; i++) {
        char abc_key[] = {i+1 + 96, 0};
        char *key = get_key_data(action, abc_key);
        int x = fget_nbr(get_key_data(key, "x"));
        int y = fget_nbr(get_key_data(key, "y"));
        int time = fget_nbr(get_key_data(key, "time"));
        actions[i] = (action_t){0, (sfVector2f){x, y}, time};
    }
    actions[count] = (action_t){-9999, 0, 0, 0};
    script->actions = actions;
    return (script);
}