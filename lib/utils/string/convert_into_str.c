/*
** EPITECH PROJECT, 2020
** convert_into_str
** File description:
** convert_into_str function
*/

#include <math.h>
#include <stdlib.h>

int get_int_length(int number)
{
    if (number <= 0)
        return (1);
    return log10(number) + 1;
}

char *convert_str(int number)
{
    char *result = malloc(sizeof(char) * (get_int_length(number) + 1));
    int length = get_int_length(number);
    int coef = pow(10, length);
    int index = 0;

    while (coef > 1) {
        int tmp = coef / 10;
        result[index] = (number % coef / tmp) + 48;
        coef /= 10;
        index++;
    }
    result[index] = 0;
    return (result);
}