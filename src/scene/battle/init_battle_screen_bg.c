/*
** EPITECH PROJECT, 2020
** init_battle_screen_bg.c
** File description:
** init battle screen bg function
*/

#include "lib/utils/string.h"
#include "scene/battle.h"

static const battle_bg_t bg[] = {{1, "forest.bmp"}, {2, "plains.png"}, {3, "poison.png"}, {4, "dungeon.png"}, {0, 0}};

static char *get_bg_path(game_t *game, battle_screen_t *battle)
{
    int zone = game->player->zone;
    for (int i = 0; bg[i].zone_code != 0; i++) {
        if (bg[i].zone_code == zone)
            return bg[i].fp;
    }
    return (0);
}

void init_battle_screen_bg(game_t *game, battle_screen_t *battle)
{
    char *fp = get_bg_path(game, battle);
    if (!fp)
        return;
    battle->bg = init_sprite(str_cat("assets/sprite/background/", fp), 0);
    set_sprite_scale(battle->bg, (float) 3.4);
}