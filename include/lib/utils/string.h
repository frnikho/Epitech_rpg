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

#include "lib/utils/json_parser.h"

int str_len(char const *str);
void putstr(char const *str);
char **str_split(char *str, char split);
char **str_split_json_array(char *content, char c, int with_clean);
char *str_cat(char *one, char *two);
char *str_cat_char(char *one , char c);
int array_length(char **array);
int get_nbr(char *str);
char *convert_str(int number);
char *my_strdup(char const *src);
char *my_strcpy(char *dest, char const *src);
int fget_nbr(char *str);

#endif
