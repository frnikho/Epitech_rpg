/*
** EPITECH PROJECT, 2020
** string.h
** File description:
**  function
*/

#ifndef DEFENDER_STRING_H
#define DEFENDER_STRING_H

#define ERROR_OUTPUT 2
#define NORMAL_OUTPUT 1

int str_len(char const *str);
void putstr(char const *str);
char **str_split(char *str, char split);
char *str_cat(char *one, char *two);
char *str_cat_char(char *one , char c);
int array_length(char **array);

#endif