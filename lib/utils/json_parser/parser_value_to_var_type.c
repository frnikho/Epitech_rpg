/*
** EPITECH PROJECT, 2020
** map_parser
** File description:
** parser_value_to_var_type
*/

#include "lib/utils/json_parser.h"
#include "lib/utils/string.h"

char *my_str_part_copy(char *buff, int beg, int end)
{
    char *result = malloc(sizeof(char) * (end-beg+1));
    int index = 0;

    if (beg == -1 || end == -1) {
        free(result);
        return (my_strdup("Undefined"));
    }
    result[end-beg] = '\0';
    for (int i = beg; i < end; i++) {
        result[index] = buff[i];
        index++;
    }
    return (result);
}

void set_variables_to_zero(int *entry_point, int *obj_index, \
int *last_begining, int indx_e)
{
    if (indx_e == 0) {
        *entry_point = 1;
        *obj_index = 0;
        *last_begining = 1;
    }
}

void check_next_object(char *buff, int indx_e, int *in_cont_tab, \
char ***obj_tab)
{
    int pass = 0;
    static int entry_point = 1;
    static int obj_index = 0;
    static int last_begining = 1;

    set_variables_to_zero(&entry_point, &obj_index, &last_begining, indx_e);
    for (int i = 1; i < 5; i++) {
        if (in_cont_tab[i] != 2)
            break;
        if (!(i+1 < 5))
            pass = 1;
    }
    if (pass == 1 && in_cont_tab[0] == 3 && entry_point == 0) {
        (*obj_tab)[obj_index] = my_str_part_copy(buff, last_begining, indx_e+1);
        last_begining = indx_e+2;
        obj_index++;
        entry_point = 1;
    }
    if (pass != 1)
        entry_point = 0;
}

char **get_value_tab(char *value, int tab_len)
{
    int indx_e = 0;
    char cont_tab[] = {'[', ']', '{', '}', 0};
    int in_cont_tab[] = {2, 2, 2, 2, 2, 0};
    int in_container_tt = 0;
    int force_stop = 0;
    char **obj_tab = malloc(sizeof(char*)*(tab_len+1));

    obj_tab[tab_len] = NULL;
    while (1) {
        if ((value[indx_e] == ',' && in_container_tt == 0) || force_stop == 1)
            break;
        check_container_opening_closing(value, indx_e, in_cont_tab, cont_tab);
        in_container_tt = is_in_container(in_container_tt, in_cont_tab);
        force_stop = check_paragraphe_end(value, indx_e, in_container_tt);
        check_next_object(value, indx_e, in_cont_tab, &obj_tab);
        if (force_stop == 1 && value[indx_e+1] != ',')
            indx_e--;
        indx_e++;
    }
    return (obj_tab);
}

char **get_layers_by_ids(int *ids, char **layers)
{
    char *id_act_char = NULL;
    int id_act = 0;
    int tab_len = 0;
    char **result = 0;
    int idnx = 0;

    for (; ids[tab_len]; tab_len++);
    result = malloc(sizeof(char *) * (tab_len+1));
    result[tab_len] = NULL;
    if (tab_len == 0)
        return (result);
    for (int i = 0; layers[i]; i++) {
        id_act_char = get_key_data(layers[i], "id");
        id_act = get_nbr(id_act_char);
        free(id_act_char);
        for (int y = 0; ids[y]; y++)
            ids[y] == id_act ? result[idnx] = my_strdup(layers[i]), idnx++ : 0;
    }
    return (result);
}