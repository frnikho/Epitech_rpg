/*
** EPITECH PROJECT, 2020
** map_parser
** File description:
** parser_get_pater_index
*/

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "lib/utils/string.h"

int get_patern_index_core(char *balise, char *buff, int i, int index)
{
    int pos_act = 0;

    for (int y = 0; balise[y]; y++) {
        if (balise[y] != buff[i+pos_act])
            break;
        pos_act++;
        if (!balise[y+1])
            index = i;
    }
    pos_act = 0;
    if (index != -1)
        return (index);
    return (-1);
}

int get_patern_index(char *buff, char *balise)
{
    int index = -1;

    for (int i = 0; i < str_len(buff) - str_len(balise); i++) {
        index = get_patern_index_core(balise, buff, i, index);
        if (index != -1)
            break;
    }
    return (index);
}