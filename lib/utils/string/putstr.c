/*
** EPITECH PROJECT, 2020
** putstr.c
** File description:
**  function
*/

#include <zconf.h>
#include "lib/utils/string.h"

void putstr(char const *str)
{
    write(NORMAL_OUTPUT, str, str_len(str));
}

void puterr(char const *str)
{
    write(ERROR_OUTPUT, str, str_len(str));
}