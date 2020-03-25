/*
** EPITECH PROJECT, 2020
** music
** File description:
** music function
*/

#ifndef DEFENDER_MUSIC_H
#define DEFENDER_MUSIC_H

#include <SFML/Audio.h>

typedef struct music_s {
    sfMusic *music;
} music_t;

music_t *init_music(char *fp);
void play_music(music_t *music);
void dispose_music(music_t *music);

#endif
