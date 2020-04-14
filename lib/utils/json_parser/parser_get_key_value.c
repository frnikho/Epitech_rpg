/*
** EPITECH PROJECT, 2020
** map_parser
** File description:
** parser_get_index_value
*/

#include "lib/utils/json_parser.h"
#include "lib/utils/string.h"

int add_container_index(char *buff, int *i_tab, \
char *cont_tab, int *in_cont_tab)
{
    if (buff[i_tab[0]] == cont_tab[i_tab[1]]) {
        if (i_tab[1] % 2 == 0)
            in_cont_tab[i_tab[1]]++;
        else
            in_cont_tab[i_tab[1]-1]--;
        return (-1);
    }
    return (0);
}

void check_container_opening_closing(char *buff, int indx_e, \
int *in_cont_tab, char *cont_tab)
{
    int i_tab[] = {0, 0};

    if (buff[indx_e] == '"') {
        if (in_cont_tab[4] == 2)
            in_cont_tab[4]++;
        else
            in_cont_tab[4]--;
    }
    for (int i = 0; cont_tab[i] && in_cont_tab[4] == 2; i++) {
        i_tab[0] = indx_e;
        i_tab[1] = i;
        if (add_container_index(buff, i_tab, cont_tab, in_cont_tab) == -1)
            break;
    }
}

int is_in_container(int in_container_tt, int *in_cont_tab)
{
    in_container_tt = 0;
    for (int i = 0; i < 5; i++) {
        if (in_cont_tab[i] > 2) {
            in_container_tt = 1;
            break;
        }
    }
    return (in_container_tt);
}

int check_paragraphe_end(char *buff, int indx_e, int in_container_tt)
{
    int force_stop = 0;

    if ((buff[indx_e] == '\n' || buff[indx_e] == '\n') \
    && in_container_tt == 0) {
        force_stop = 1;
        indx_e--;
    }
    if ((buff[indx_e] == '}' || buff[indx_e] == ']') && in_container_tt == 0)
        force_stop = 1;
    return (force_stop);
}

char *get_key_data(char *buff, char *balise)
{
    int indx_b = get_patern_index(buff, balise);
    int indx_e = 0;
    char cont_tab[] = {'[', ']', '{', '}', 0};
    int in_cont_tab[] = {2, 2, 2, 2, 2, 0};
    int in_container_tt = 0;
    int force_stop = 0;

    for (; buff[indx_b-1] != ':'; indx_b ++);
    indx_e = indx_b;
    while (1) {
        if ((buff[indx_e] == ',' && in_container_tt == 0) || force_stop == 1)
            break;
        check_container_opening_closing(buff, indx_e, in_cont_tab, cont_tab);
        in_container_tt = is_in_container(in_container_tt, in_cont_tab);
        force_stop = check_paragraphe_end(buff, indx_e, in_container_tt);
        if (force_stop == 1 && buff[indx_e+1] != ',')
            indx_e--;
        indx_e++;
    }
    return (my_str_part_copy(buff, indx_b, indx_e));
}