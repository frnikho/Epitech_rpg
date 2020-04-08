/*
** EPITECH PROJECT, 2020
** read_file.c
** File description:
**  function
*/

#include "game.h"
#include "lib/utils/file.h"
#include "lib/utils/string.h"
#include <zconf.h>

char **get_dialog(char *key)
{
    int fd = open_file("content/dialog.json");
    char *content = read_file(fd, "content/dialog.json");
    char *msg = get_key_data(content, key);

    for (int i = 0; msg[i] != 0; i++) {
        if (msg[i] == '$')
            msg[i] = '\n';
        if (msg[i] == '\"')
            msg[i] = ' ';
    }
    char **result = str_split(msg, '#');
    free(content);
    return (result);
}

char *read_file(int fd, char *fp)
{
    char *buffer = malloc(sizeof(char) * READ_SIZE);
    int size = 0;
    while (((read(fd, buffer, 1)) > 0))
        size++;
    close(fd);
    free(buffer);
    fd = open_file(fp);
    buffer = malloc(sizeof(char) * (size + 1));
    read(fd, buffer, size);
    buffer[size] = 0;
    close(fd);
    return (buffer);
}