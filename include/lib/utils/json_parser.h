/*
** EPITECH PROJECT, 2020
** map_parser
** File description:
** parser
*/

#ifndef PARSER_H_
#define PARSER_H_

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
int ***construct_map_tab_from_layers(char **tiles_layers);
char **get_layers_by_ids(int *ids, char **layers);
char *my_str_part_copy(char *buff, int beg, int end);
int check_paragraphe_end(char *buff, int indx_e, int in_container_tt);
int is_in_container(int in_container_tt, int *in_cont_tab);
void check_container_opening_closing(char *buff, int indx_e, \
int *in_cont_tab, char *cont_tab);
int add_container_index(char *buff, int *i_tab, \
char *cont_tab, int *in_cont_tab);
int get_patern_index(char *buff, char *balise);
char *create_file_buffer(char *file);
void free_tab(char **tab);
void free_double_tab(int ***tab);

//void csfml_loop(int ***tiles_tab, int ***objs_tab, char **obs_tab);

#endif /* !PARSER_H_ */
