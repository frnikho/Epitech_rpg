/*
** EPITECH PROJECT, 2020
** map_parser
** File description:
** parser_get_pater_index
*/

#include "lib/utils/string.h"


int get_patern_index_core(char *balise, char *buff, int i, int index)
{
    int pos_act = 0;

    for (int y = 0; balise[y]; y++) {
        if (balise[y] != buff[i+pos_act])
            break;
        pos_act++;
        if (!balise[y+1] && buff[i+pos_act] == '"')
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

float my_pow(float x, int y)
{
    float result = 1;
    
    for (; y > 0; y--)
        result *= x;
    return (result);
}

void my_getfloat_point_handling(int decimals, float *values, int *i)
{
    values[0] = values[0] / my_pow(10, decimals);
    for (; decimals > 0; decimals--)
        values[1] /= 10;
    (*i)--;
}

float my_getfloat(char *str)
{
    char *buff = str;
    int neg = 1;
    int buff_len = 0;
    float values[] = {0, 1};

    if (buff[0] == '-') {
        neg = -1;
        buff = &str[1];
    }
    for (; buff[buff_len]; buff_len++);
    for (int i = buff_len-1; i >= 0; i--) {
        if ((buff[i] > 57 || buff[i] < 48) && buff[i] != '.')
            return (0);
        if (buff[i] == '.')
            my_getfloat_point_handling(((buff_len-1)-i), values, &i);

        values[0] += (buff[i] - 48) * values[1];
        values[1] *= 10;
    }
    return (values[0]*neg);
}