/*
** EPITECH PROJECT, 2020
** sound
** File description:
** sound function
*/

#ifndef DEFENDER_SOUND_H
#define DEFENDER_SOUND_H

#include <SFML/Audio.h>

typedef struct sound_s {
    sfSoundBuffer *buffer;
    sfSound *sound;
} sound_t;

sound_t *init_sound(char *fp);
void dispose_sound(sound_t *sound);

void play_sound(sound_t *sound);
void stop_sound(sound_t *sound);
void set_sound_volume(sound_t *sound, float volume);
void set_sound_loop(sound_t *sound, int loop);
sfSoundStatus get_sound_status(sound_t *sound);

#endif
