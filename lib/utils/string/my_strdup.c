/*
** EPITECH PROJECT, 2019
** my_strdup file
** File description:
** allocates memory and copies the string given as argument
*/

#include <stdlib.h>
#include "lib/utils/string.h"

char *my_strdup(char const *src)
{
    int length = str_len(src)+1;
    char *new;

    new = malloc(sizeof(char) * length);
    if (!new)
        return (NULL);
    my_strcpy(new, src);
    return (new);
}
