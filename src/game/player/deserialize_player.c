/*
** EPITECH PROJECT, 2020
** deserialize_player.c
** File description:
**  function
*/

#include "game/player.h"
#include <stdlib.h>
#include "lib/utils/string.h"
#include "lib/utils/file.h"

static int init_player_stats(char *content, player_t *player)
{
    if (!content)
        return (-1);
    char *stats = get_key_data(content, "stats");
    char *hp = get_key_data(stats, "hp");
    char *mp = get_key_data(stats, "mp");
    char *agility = get_key_data(stats, "agility");
    char *resistance = get_key_data(stats, "resistance");
    char *strength = get_key_data(stats, "strength");
    char *magic = get_key_data(stats, "magic");
    if (!hp || !mp || !agility || !resistance || !strength || !magic)
        return (-1);
    int value[6];
    value[STATS_I_HP] = get_nbr(hp);
    value[STATS_I_MP] = get_nbr(mp);
    value[STATS_I_AG] = get_nbr(agility);
    value[STATS_I_RES] = get_nbr(resistance);
    value[STATS_I_STR] = get_nbr(strength);
    value[STATS_I_MAG] = get_nbr(magic);
    player->stats = init_stats(value);
    return (0);
}

int init_player_objects(char *content, player_t *player)
{
    char *xp = get_key_data(content, "xp");
    char *level = get_key_data(content, "level");
    if (!xp || !level)
        return (-1);
    int i_xp = get_nbr(xp);
    int i_level = get_nbr(level);
    player->xp = i_xp;
    player->level = i_level;
    return (0);
}

player_t *deserialize_player(void)
{
    player_t *player = malloc(sizeof(player_t));
    int fd = open_file("content/player.json");
    char *content = read_file(fd, "content/player.json");
    if (init_player_stats(content, player) == -1)
        return (0);
    if (init_player_objects(content, player) == -1)
        return (0);
    if (player->level <= 0 || player->xp < 0 || !player->stats)
        return (0);
    debug_player(player);
    return (player);
}