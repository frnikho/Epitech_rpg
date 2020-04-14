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

int parser(char **argv)
{
    char *file_data = create_file_buffer(argv[1]);                         // Retourne le contenu du fichier dont le path est argv[1]

    if (file_data[0] == 'E' && str_len(file_data) == 1)
        return (84);

    char *layers_str = get_key_data(file_data, "layers");                  // Retourne la valeur correspondant a la clef "layers" dans le fichier json
    char **layers = get_value_tab(layers_str, 4);                          // Transforme le string de la valeur en tableau si s'en est un
    //int **map_one = contruct_map_from_layer(layers[0]);                  // Transforme une valeur de type [layers:data] en tableau de int


    char **tiles_layers = get_layers_by_ids((int []){1, 2, 0}, layers);    // Selectionne les layers coorespondant aux ids donnés en paramètres
    int ***tiles_tab = construct_map_tab_from_layers(tiles_layers);        // Contruit une liste de tableau de int à partir d'une valeur de type [layers]
    
    char **objs_layers = get_layers_by_ids((int []){4, 0}, layers);
    int ***objs_tab = construct_map_tab_from_layers(objs_layers);

    char **obs_layer = get_layers_by_ids((int []){3, 0}, layers);
    char *obstacles_str = get_key_data(obs_layer[0], "objects");
    char **obs_tab = get_value_tab(obstacles_str, 4);
    
    //csfml_loop(tiles_tab, objs_tab, obs_tab);                              // {beta} Fonction en rapport avec la map, layers pour csfml




    free_tab(obs_tab);
    free(obstacles_str);
    free_tab(obs_layer);

    free_double_tab(objs_tab);
    free_tab(objs_layers);

    free_double_tab(tiles_tab);
    free_tab(tiles_layers);
    free_tab(layers);

    free(layers_str);
    free(file_data);
    return (0);
}