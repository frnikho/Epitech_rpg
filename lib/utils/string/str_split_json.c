/*
** EPITECH PROJECT, 2020
** str_split_json.c
** File description:
**  function
*/

#include "lib/utils/string.h"
#include <stdlib.h>

static char *clean_str(char *str)
{
    int count = 0;
    int index = 0;

    char clean[6] = {'\"', '[', ']', '\n', ' ', 0};

    for (int i = 0; str[i] != 0; i++)
        for (int y = 0; clean[y] != 0; y++)
            str[i] == str[y] ? count++ : 0;
    char *result = malloc(sizeof(char) * (count + 1));
    for (int i = 0; str[i] != 0; i++) {
        int skip = 0;
        for (int y = 0; clean[y] != 0; y++) {
            clean[y] == str[i] ? skip = 1: 0;
        }
        if (!skip) {
            result[index] = str[i];
            index++;
        }
    }
    free(str);
    result[index] = 0;
    return (result);
}

char **str_split_json_array(char *content, char c, int with_clean)
{
    int start = 0;
    int end = 0;

    for (; content[start] != '['; start++)
        continue;
    for (; content[end] != ']'; end++)
        continue;

    char **array = str_split(&content[start], c);
    if (!with_clean)
        return (array);

    for (int i = 0; array[i] != 0; i++)
        array[i] = clean_str(array[i]);

    return (array);
}