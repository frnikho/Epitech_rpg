/*
** EPITECH PROJECT, 2020
** str_len.c
** File description:
**  function
*/

int str_len(char const *str)
{
    if (!str)
        return (-1);
    int count = 0;
    for (; str[count] != 0; count++)
        continue;
    return (count);
}