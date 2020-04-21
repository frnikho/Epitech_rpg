/*
** EPITECH PROJECT, 2020
** json_writer.c
** File description:
** json_writer function
*/

#include "lib/utils/string.h"
#include "lib/utils/json_parser.h"
#include "lib/utils/json_writer.h"
#include "lib/utils/file.h"

int str_start_with(char *str, char *start_with)
{
    for (int i = 0; start_with[i] != 0 && str[i] != 0; i++) {
        if (start_with[i] != str[i])
            return (0);
    }
    return (1);
}

static int get_index_key(char *content, char *key)
{
    int found = 1;

    int i = 0;

    for (int i = 0; content[i] != 0; i++) {
        if (str_start_with(&content[i], key)) {
            return (i+str_len(key)+2);
        }
    }
    return (0);
}

static char *add_space(char *content, char c, int char_index)
{
    char *result = malloc(sizeof(char) * (str_len(content) + 2));
    for (int i = 0; content[i] != 0; i++) {
        if (i != char_index) {
            result[i] = content[i];
        } else {
            result[i] = c;
        }
    }
    return (result);
}

static char *write_value(char *content, int index, char *value)
{
    char *nc = malloc(sizeof(char) * (str_len(content) + str_len(value) + 2));
    int part_index = 0;
    int tmp_index = 0;
    int shift = 0;
    for (; content[part_index] != 0; part_index++) {
        if (part_index == index)
            break;
        nc[part_index] = content[part_index];
    }
    for (int i = 0; value[i] != 0; i++) {
        nc[part_index+i] = value[i];
        tmp_index = part_index+i;
    }
    for (; content[part_index] != 0; part_index++) {
        content[part_index] == ',' ? shift = 1 : 0;
        if (shift)
            nc[++tmp_index] = content[part_index];
    }
    nc[tmp_index+1] = 0;
    return (nc);
}

int json_writer(char *fp, char *key, char *value)
{
    int fd = open_file(fp);
    if (fd < 1)
        return (-1);
    char *content = read_file(fd, fp);
    if (!content)
        return (-1);
    int value_pos = get_index_key(content, key);
    content = write_value(content, value_pos, value);


    fd = open_file(fp);
    write(fd, content, str_len(content));

    return (0);
}