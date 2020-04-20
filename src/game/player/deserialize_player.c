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

static int init_other_stats(char *content, player_t *player)
{
    char *stats = get_key_data(content, "stats");
    char *hp = get_key_data(stats, "hp");
    char *mp = get_key_data(stats, "mp");
    player->stats->hp = get_nbr(hp);
    player->stats->mp = get_nbr(mp);
    player->health = get_nbr(hp);
    player->mp = get_nbr(mp);
    free(stats);
    free(hp);
    free(mp);
    return (0);
}

static int init_player_stats(char *content, player_t *player)
{
    char *stats = get_key_data(content, "stats");
    char *agility = get_key_data(stats, "agility");
    char *resistance = get_key_data(stats, "resistance");
    char *strength = get_key_data(stats, "strength");
    char *magic = get_key_data(stats, "magic");
    int value[6];
    value[STATS_I_AG] = get_nbr(agility);
    value[STATS_I_RES] = get_nbr(resistance);
    value[STATS_I_STR] = get_nbr(strength);
    value[STATS_I_MAG] = get_nbr(magic);
    value[STATS_I_HP] = 0;
    value[STATS_I_MP] = 0;
    player->stats = init_stats(value);
    free(stats);
    free(agility);
    free(resistance);
    free(strength);
    free(magic);
    return (0);
}

int init_player_objects(char *content, player_t *player)
{
    char *xp = get_key_data(content, "xp");
    char *level = get_key_data(content, "level");
    int i_xp = get_nbr(xp);
    int i_level = get_nbr(level);
    player->xp = i_xp;
    player->level = i_level;
    free(xp);
    free(level);
    return (0);
}

player_t *deserialize_player(void)
{
    player_t *p = malloc(sizeof(player_t));
    int fd = open_file("content/player.json");
    char *c = read_file(fd, "content/player.json");
    if (!c)
        return (0);
    if (init_player_stats(c, p) == -1 || init_other_stats(c, p))
        return (0);
    if (init_player_objects(c, p) == -1)
        return (0);
    if (!p->stats)
        return (0);
    p->zone = 1;
    free(c);
    return (p);
}