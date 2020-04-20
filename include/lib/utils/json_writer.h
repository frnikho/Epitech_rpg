/*
** EPITECH PROJECT, 2020
** json_writer.h
** File description:
** json_writer function
*/

#ifndef MY_RPG_JSON_WRITER_H
#define MY_RPG_JSON_WRITER_H

enum json_type {INT = 0, BOOL = 1, STRING = 2};

int json_writer(char *fp, char *key, char *value);


#endif