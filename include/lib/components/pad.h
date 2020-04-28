/*
** EPITECH PROJECT, 2020
** pad.h
** File description:
** pad function
*/

#ifndef MY_RPG_PAD_H
#define MY_RPG_PAD_H

enum pad {UNKNOW, PAD_LEFT, PAD_UP, PAD_RIGHT, PAD_DOWN};

#define PAD_A 0
#define PAD_B 1
#define PAD_X 2
#define PAD_Y 3
#define PAD_L1 4
#define PAD_R1 5

#define PAD_SELECT 6
#define PAD_START 7
#define PAD_MAIN 8

int pad_pressed(int PAD_KEY);
enum pad pad_arrow(void);

#endif