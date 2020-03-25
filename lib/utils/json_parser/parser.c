/*
** EPITECH PROJECT, 2020
** map_parser
** File description:
** parser
*/

#include "lib/utils/string.h"
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

char *get_key_data(char *buff, char *balise);
char **get_value_tab(char *value, int tab_len);
int **contruct_map_from_layer(char *str);

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

char *my_str_part_copy(char *buff, int beg, int end)
{
    char *result = malloc(sizeof(char) * (end-beg+1));
    int index = 0;

    result[end-beg] = '\0';
    for (int i = beg; i < end; i++) {
        result[index] = buff[i];
        index++;
    }
    return (result);
}

int parser(char **argv)
{
    char *file_data = create_file_buffer(argv[1]);        // Retourne le contenu du fichier dont le path est argv[1]

    if (file_data[0] == 'E' && str_len(file_data) == 1)
        return (84);

    char *n_value = get_key_data(file_data, "layers");    // Retourne la valeur correspondant a la clef "layers" dans le fichier json
    char **values = get_value_tab(n_value, 3);            // Transforme le string de la valeur en tableau si s'en est un
    int **map_one = contruct_map_from_layer(values[0]);   // {beta} Transforme une valeur de type "[1, 2, 3, 4]" en tableau de int
    int **map_two = contruct_map_from_layer(values[2]);

    for (int i = 0; map_one[i]; i++)
        free(map_one[i]);
    free(map_one);
    for (int i = 0; map_two[i]; i++)
        free(map_two[i]);
    free(map_two);
    free(file_data);
    free(n_value);
    for (int i = 0; values[i]; i++)
        free(values[i]);
    free(values);
    return (0);
}