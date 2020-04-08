/*
** EPITECH PROJECT, 2020
** get_npc_dialog.c
** File description:
** get_npc_dialog function
*/

#include "lib/utils/string.h"
#include "lib/utils/file.h"
#include "game/npc.h"
#include <stdlib.h>

char **get_npc_dialog(npc_t *npc)
{
    int fd = open_file(npc->fp);
    if (fd < 1)
        return (0);
    char *content = read_file(fd, npc->fp);
    char *dialog_key = get_key_data(content, "dialog");
    int count = fget_nbr(get_key_data(dialog_key, "count"));
    int dialog = (rand() % count) + 1;
    char *dialog_msg = get_key_data(dialog_key, convert_str(dialog));
    for (int i = 0; dialog_msg[i] != 0; i++) {
        if (dialog_msg[i] == '$')
            dialog_msg[i] = '\n';
        if (dialog_msg[i] == '\"')
            dialog_msg[i] = ' ';
    }
    char **result = str_split(dialog_msg, '#');
    free(content);
    return (result);
}