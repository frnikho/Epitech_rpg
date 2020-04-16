/*
** EPITECH PROJECT, 2020
** player.c
** File description:
**  function
*/

#include "game/player.h"
#include "lib/utils/file.h"
#include "lib/utils/json_parser.h"
#include <stdlib.h>
#include "lib/utils/string.h"
#include "game/collision.h"

static sfIntRect *get_player_json_rect(char *filepath, char *animations)
{
    int fd = open_file(filepath);
    if (fd <= 0)
        return (0);
    char *content = read_file(fd, filepath);
    char *anim = get_key_data(content, animations);
    int count = fget_nbr(get_key_data(anim, "count"));
    sfIntRect *anim_rect = malloc(sizeof(sfIntRect) * (count + 1));
    int i = 0;
    for (; i < count; i++) {
        char *tmp = convert_str(i+1);
        char *rect = get_key_data(anim, tmp);
        int x = fget_nbr(get_key_data(rect, "x"));
        int y = fget_nbr(get_key_data(rect, "y"));
        int width = fget_nbr(get_key_data(rect, "width"));
        int height = fget_nbr(get_key_data(rect, "height"));
        anim_rect[i] = (sfIntRect){x, y, width, height};
    }
    anim_rect[i] = (sfIntRect) {0, 0, 0, -9999};
    free(content);
    return (anim_rect);
}

static anim_sprite_t *init_player_action(char *filepath, char *anim_name)
{
    sfIntRect *rect = get_player_json_rect(filepath, anim_name);
    anim_sprite_t *sprite = create_anim_sprite("assets/sprite/player.png", (sfVector2f){0, 0});
    for (int i = 0; rect[i].height != -9999; i++)
        add_anim_frame(sprite, rect[i]);
    return (sprite);
}

static player_t *init_player(void)
{
    player_t *player = malloc(sizeof(player_t));
    int values[6];
    values[STATS_I_HP] = 20;
    values[STATS_I_MP] = 10;
    values[STATS_I_MAG] = 8 + (rand() % 5);
    values[STATS_I_STR] = 8 + (rand() % 5);
    values[STATS_I_RES] = 8 + (rand() % 5);
    values[STATS_I_AG] = 8 + (rand() % 5);
    player->stats = init_stats(values);
    player->level = 1;
    player->xp = 0;
    player->zone = 1;
    return (player);
}

player_t *create_player(void)
{
    player_t *player = deserialize_player();
    create_gui(player);
    player->current_animations = 0;
    player->inventory = create_inventory();
    player->animations = malloc(sizeof(anim_sprite_t*) * 5);
    player->animations[0] = init_player_action("content/player.json", "idle");
    player->animations[1] = init_player_action("content/player.json", "walk_right");
    player->animations[2] = init_player_action("content/player.json", "walk_left");
    player->animations[3] = init_player_action("content/player.json", "walk_up");
    player->animations[4] = 0;
    player->pre_pos = (sfVector2f){0, 0};
    player->collision = create_collision_box(sfSprite_getGlobalBounds(player->animations[0]->sprite), 0, 1);
    return (player);
}

void destroy_player(player_t *player)
{
    //TODO destroy inventory
    destroy_stats(player->stats);
    free(player);
}