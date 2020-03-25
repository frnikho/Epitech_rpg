/*
** EPITECH PROJECT, 2020
** open_file.c
** File description:
**  function
*/

#include <fcntl.h>

int open_file(char *content)
{
    int fd = open(content, O_RDWR);
    if (fd <= 1)
        return (-1);
    return (fd);
}