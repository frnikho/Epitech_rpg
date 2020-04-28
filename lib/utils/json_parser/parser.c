/*
** EPITECH PROJECT, 2020
** map_parser
** File description:
** parser
*/

#include "lib/utils/json_parser.h"
#include "lib/utils/string.h"

int get_file_infos(char *file)
{
    struct stat *buff_stat;
    int file_size;

    buff_stat = malloc(sizeof(struct stat));
    stat(file, buff_stat);
    file_size = buff_stat->st_size;
    free(buff_stat);
    return (file_size);
}

char *create_file_buffer(char *file)
{
    char *buff;
    int fd = 0;
    int size = 0;
    int file_size = get_file_infos(file);

    buff = malloc(sizeof(char) * (file_size + 1));
    fd = open(file, O_RDONLY);
    if (fd == -1)
        return ("E");
    size = read(fd, buff, file_size);
    buff[size] = 0;
    close(fd);
    return (buff);
}

void free_tab(char **tab)
{
    for (int i = 0; tab[i]; i++)
        free(tab[i]);
    free(tab);
}

void free_double_tab(int ***tab)
{
    for (int i = 0; tab[i]; i++) {
        for (int y = 0; tab[i][y]; y++)
            free(tab[i][y]);
        free(tab[i]);
    }
    free(tab);
}