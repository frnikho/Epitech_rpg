/*
** EPITECH PROJECT, 2020
** map_parser
** File description:
** temp_dependencies
*/

#include "lib/utils/string.h"

char *my_strcpy(char *dest, char const *src)
{
    int i;
    for (i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0'; 
    return (dest);
}

char *my_strdup(char const *src)
{
    char *dest = malloc(sizeof(char) * str_len(src) + 1);
    my_strcpy(dest, src);
    return (dest);
}