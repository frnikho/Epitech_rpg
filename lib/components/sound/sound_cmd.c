/*
** EPITECH PROJECT, 2020
** sound_cmd
** File description:
** sound_cmd function
*/

#include "lib/components/sound.h"

void stop_sound(sound_t *sound)
{
    sfSound_stop(sound->sound);
}

void set_sound_volume(sound_t *sound, float volume)
{
    sfSound_setVolume(sound->sound, volume);
}

void set_sound_loop(sound_t *sound, int loop)
{
    sfSound_setLoop(sound->sound, loop);
}

sfSoundStatus get_sound_status(sound_t *sound)
{
    return sfSound_getStatus(sound->sound);
}