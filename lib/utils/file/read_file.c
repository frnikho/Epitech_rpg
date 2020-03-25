/*
** EPITECH PROJECT, 2020
** read_file.c
** File description:
**  function
*/

#include "game.h"
#include <zconf.h>
#include "lib/utils/file.h"

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