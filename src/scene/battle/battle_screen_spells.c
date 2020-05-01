/*
** EPITECH PROJECT, 2020
** battle_screen_spells.c
** File description:
** battle screen spells function
*/

#include "game/spell.h"
#include "lib/utils/file.h"
#include "lib/utils/string.h"
#include "scene/battle.h"

static const spell_t spells[] = {{"heal", "Premier secours", heal},
    {"weak_point", "Point faible", weakness_hit},
    {"flame", "Flame", flame}, {0, 0}};

spell_t *get_spells(player_t *player)
{
    int fd = open_file("content/spells.json");
    char *content = read_file(fd, "content/spells.json");
    int index = 0;
    spell_t *learn_spells = malloc(sizeof(spells) * 20);

    for (int i = 0; spells[i].key != 0; i++) {
        int learn = fget_nbr(get_key_data(content, spells[i].key));
        if (learn)
            learn_spells[index++] = spells[i];
    }
    return (learn_spells);
}