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
int ***construct_map_tab_from_layers(char **map_layers);
char **get_layers_by_ids(int *ids, char **layers);

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

int parser(char **argv)
{
    int fd = open_file(argv[1]);
    char *file_data = read_file(fd, argv[1]); // Retourne le contenu du fichier dont le path est argv[1]
    
    if (file_data[0] == 'E' && str_len(file_data) == 1)
        return (84);

    char *layers_str = get_key_data(file_data, "layers");                   // Retourne la valeur correspondant a la clef "layers" dans le fichier json
    char **layers = get_value_tab(layers_str, 3);                           // Transforme le string de la valeur en tableau si s'en est un
    //int **map_one = contruct_map_from_layer(layers[0]);                   // Transforme une valeur de type [layers:data] en tableau de int

    char **map_layers = get_layers_by_ids((int []){1, 2, 0}, layers);       // Selectionne les layers coorespondant aux ids donnés en paramètres
    int ***map_tab = construct_map_tab_from_layers(map_layers);             // Contruit une liste de tableau de int à partir d'une valeur de type [layers]
    
    char **obj_layer = get_layers_by_ids((int []){3, 0}, layers);
    char *objects_str = get_key_data(obj_layer[0], "objects");
    char **obj_tab = get_value_tab(objects_str, 4);

    free_tab(obj_tab);
    free(objects_str);
    free_tab(obj_layer);
    free_double_tab(map_tab);
    free_tab(map_layers);
    free_tab(layers);
    free(layers_str);
    free(file_data);
    return (0);
}