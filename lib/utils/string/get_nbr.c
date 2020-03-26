/*
** EPITECH PROJECT, 2020
** get_nbr.c
** File description:
**  function
*/

#include <stdlib.h>

int get_nbr(char *str)
{
    int result = 0;
    char *buff = str;
    int neg = 1;
    int buff_len = 0;
    int index = 1;

    if (buff[0] == '-') {
        neg = -1;
        buff = &str[1];
    }
    for (; buff[buff_len]; buff_len++);
    for (int i = buff_len-1; i >= 0; i--) {
        if (buff[i] > 57 || buff[i] < 48)
            return (0);
        result += (buff[i] - 48) * index;
        index *= 10;
    }
    return (result*neg);
}

int fget_nbr(char *str)
{
    if (!str)
        return (-1);
    int nbr = get_nbr(str);
    free(str);
    return (nbr);
}