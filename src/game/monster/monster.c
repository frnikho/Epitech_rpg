/*
** EPITECH PROJECT, 2020
** monster.c
** File description:
**  function
*/

#include "game/monster.h"
#include "lib/utils/string.h"
#include <malloc.h>
#include <stdlib.h>
#include <lib/utils/file.h>

static void init_monster_sprite(monster_t *monster, char *content)
{
    char *rect = get_key_data(content, "sprite");
    int x = fget_nbr(get_key_data(rect, "x"));
    int y = fget_nbr(get_key_data(rect, "y"));
    int width = fget_nbr(get_key_data(rect, "width"));
    int height = fget_nbr(get_key_data(rect, "height"));
    sfIntRect sprite = {x, y, width, height};
    monster->sprite = init_sprite("assets/sprite/monster.png", &sprite);
    free(rect);
}

static void init_monster_gain(monster_t *monster, char *content)
{
    int factor = fget_nbr(get_key_data(content, "gain_factor"));
    int gold = fget_nbr(get_key_data(content, "gold"));
    int xp = fget_nbr(get_key_data(content, "xp"));
    monster->xp = (rand() % factor) + xp;
    monster->gold = (rand() % factor) + gold;
}

static void init_monster_stats(monster_t *monster, char *content)
{
    int f = fget_nbr(get_key_data(content, "stats_factor"));
    char *s = get_key_data(content, "stats");
    int values[6];
    values[STATS_I_HP] = (fget_nbr(get_key_data(s, "hp")) + rand() % f);
    values[STATS_I_MP] = (fget_nbr(get_key_data(s, "pm")) + rand() % f);
    values[STATS_I_STR] = (fget_nbr(get_key_data(s, "strength")) + rand() % f);
    values[STATS_I_RES] = (fget_nbr(get_key_data(s, "resistance")) + rand() % f);
    values[STATS_I_AG] = (fget_nbr(get_key_data(s, "agility")) + rand() % f);
    values[STATS_I_MAG] = (fget_nbr(get_key_data(s, "magic")) + rand() % f);
    monster->stats = init_stats(values);
}

monster_t *create_monster(char *fp, sfVector2f pos)
{
    monster_t *monster = malloc(sizeof(monster_t));
    if (!monster)
        return (0);
    char **name = str_split(fp, '.');
    monster->name = name[0];
    monster->is_alive = 1;
    free(name[1]);
    free(name);
    fp = str_cat("content/monsters/", fp);
    int fd = open_file(fp);
    char *content = read_file(fd, fp);

    init_monster_sprite(monster, content);
    pos.x -= (sfSprite_getGlobalBounds(monster->sprite->sprite).width / 2);
    set_sprite_position(monster->sprite, pos);
    set_sprite_scale(monster->sprite, 2.2);
    init_monster_gain(monster, content);
    init_monster_stats(monster, content);
    free(content);
    return (monster);
}

void dispose_monster(monster_t *monster)
{
    destroy_stats(monster->stats);
    dispose_sprite(monster->sprite);
    free(monster->name);
    free(monster);
}