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
    anim_sprite_t *sprite = create_anim_sprite("assets/sprite/player.png", \
    (sfVector2f){0, 0});
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
    player->can_move = 1;
    return (player);
}

static anim_sprite_t **create_annimations(void)
{
    anim_sprite_t **animations = malloc(sizeof(anim_sprite_t*) * 5);
    animations[0] = init_player_action("content/player.json", "idle");
    animations[1] = init_player_action("content/player.json", "walk_right");
    animations[2] = init_player_action("content/player.json", "walk_left");
    animations[3] = init_player_action("content/player.json", "walk_up");
    animations[4] = 0;
    for (int i = 0; animations[i] != 0; i++)
        set_anim_sprite_scale(animations[i], 2);
    return (animations);
}

player_t *create_player(void)
{
    player_t *player = deserialize_player();
    player->interlocutor = NULL;
    player->learned_abi = 0;
    player->learned_spell = 0;
    player->delta = 0;
    player->current_animations = 0;
    player->delta_fight = 0;
    player->fight = 0;
    player->inventory = create_inventory();
    player->animations = create_annimations();
    create_gui(player);
    player->pre_pos = (sfVector2f){0, 0};
    player->is_ghost = 0;
    player->collision = create_collision_box(\
    sfSprite_getGlobalBounds(player->animations[0]->sprite), 0, 1);
    return (player);
}