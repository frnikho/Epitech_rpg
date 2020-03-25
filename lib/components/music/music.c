/*
** EPITECH PROJECT, 2020
** music
** File description:
** music function
*/

#include "lib/components/music.h"
#include <stdlib.h>

music_t *init_music(char *fp)
{
    music_t *music = malloc(sizeof(music_t));
    if (!music) {
        free(music);
        return (0);
    }
    music->music = sfMusic_createFromFile(fp);
    sfMusic_setVolume(music->music, 5);
    sfMusic_setLoop(music->music, sfTrue);
    return (music);
}

void play_music(music_t *music)
{
    sfMusic_play(music->music);
}

void dispose_music(music_t *music)
{
    sfMusic_destroy(music->music);
    free(music);
}