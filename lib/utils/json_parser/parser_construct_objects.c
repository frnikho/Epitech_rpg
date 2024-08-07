/*
** EPITECH PROJECT, 2020
** map_parser
** File description:
** parser_construct_objects
*/

#include "lib/utils/json_parser.h"
#include "lib/utils/string.h"

void clear_chars_from_str(char *excluded_chars, char *str)
{
    int index = 0;
    int pass = 0;

    for (int i = 0; str[i]; i++) {
        pass = 0;
        for (int y = 0; excluded_chars[y]; y++)
            str[i] == excluded_chars[y] ? pass = 1 : 0;
        if (pass == 1)
            continue;
        str[index] = str[i];
        index++;
    }
    str[index] = '\0';
}

void copy_index_part_from_str(int **data_tab, char *data_str, int i, int y)
{
    int current = 0;
    static int last = 1;
    char *temp_value = NULL;

    if (i == 0 && y == 0)
        last = 1;
    for (int z = last; data_str[z] != ',' && data_str[z] != ']'; z++)
        current = z+1;
    temp_value = my_str_part_copy(data_str, last, current);
    clear_chars_from_str(" ", temp_value);
    data_tab[i][y] = get_nbr(temp_value);
    if (data_tab[i][y] == 0)
        data_tab[i][y] = -1;
    last = current+1;
    free(temp_value);
}

int **contruct_map_from_layer(char *str)
{
    char *data_str = get_key_data(str, "data");
    char *width_str = get_key_data(str, "width");
    int width = get_nbr(width_str);
    char *height_str = get_key_data(str, "height");
    int height = get_nbr(height_str);
    int **data_tab = malloc(sizeof(int *) * (width+1));

    data_tab[width] = NULL;
    for (int i = 0; i < width; i++) {
        data_tab[i] = malloc(sizeof(int) * (height+1));
        data_tab[i][height] = 0;
        for (int y = 0; y < height; y++)
            copy_index_part_from_str(data_tab, data_str, i, y);
    }
    free(data_str);
    free(width_str);
    free(height_str);
    return (data_tab);
}

int ***construct_map_tab_from_layers(char **map_layers)
{
    int tab_len = 0;
    int ***map_tab = NULL;

    for (; map_layers[tab_len]; tab_len++);
    map_tab = malloc(sizeof(int **)* (tab_len+1));
    map_tab[tab_len] = NULL;
    for (int i = 0; map_layers[i]; i++)
        map_tab[i] = contruct_map_from_layer(map_layers[i]);
    return (map_tab);
}