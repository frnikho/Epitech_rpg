/*
** EPITECH PROJECT, 2020
** map_parser
** File description:
** parser
*/

#include "lib/utils/file.h"
#include "lib/utils/string.h"
#include <stdlib.h>

char *get_key_data(char *buff, char *balise);
char **get_value_tab(char *value, int tab_len);
int **contruct_map_from_layer(char *str);

int parser(char **argv)
{
    int fd = open_file(argv[1]);
    char *file_data = read_file(fd, argv[1]); // Retourne le contenu du fichier dont le path est argv[1]
    if (file_data[0] == 'E' && str_len(file_data) == 1)
        return (84);

    char *n_value = get_key_data(file_data, "layers");    /* Retourne la valeur correspondant a la clef "layers" dans le fichier json */
    char **values = get_value_tab(n_value, 3);            // Transforme le string de la valeur en tableau si s'en est un
    int **map_one = contruct_map_from_layer(values[0]);   // {beta} Transforme une valeur de type "[1, 2, 3, 4]" en tableau de int
    int **map_two = contruct_map_from_layer(values[2]);
    char *objects = get_key_data(values[1], "objects");
    char **obj_tab = get_value_tab(objects, 2);

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
    free(objects);
    for (int i = 0; obj_tab[i]; i++)
        free(obj_tab[i]);
    free(obj_tab);
    return (0);
}