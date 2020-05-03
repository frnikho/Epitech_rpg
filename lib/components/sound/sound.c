/*
** EPITECH PROJECT, 2020
** sound
** File description:
** sound function
*/

#include "lib/components/sound.h"
#include <stdlib.h>
#include <game.h>

sound_t *init_sound(char *fp)
{
    sound_t *sound = malloc(sizeof(sound_t));
    if (!sound) {
        free(sound);
        return (0);
    }
    sound->buffer = sfSoundBuffer_createFromFile(fp);
    if (!sound->buffer)
        return (0);
    sound->sound = sfSound_create();
    sfSound_setBuffer(sound->sound, sound->buffer);
    return (sound);
}

void play_sound(sound_t *sound, int volume)
{
    sfSound_setVolume(sound->sound, (float) volume);
    sfSound_play(sound->sound);
}

void stop_fade_sound(sound_t *sound)
{

}

void dispose_sound(sound_t *sound)
{
    sfSound_stop(sound->sound);
    sfSoundBuffer_destroy(sound->buffer);
    sfSound_destroy(sound->sound);
    free(sound);
}