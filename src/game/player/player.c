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

static anim_sprite_t **create_annimations(void)
{
    anim_sprite_t **animations = malloc(sizeof(anim_sprite_t*) * 5);
    animations[0] = init_player_action("content/player.json", "idle");
    animations[1] = init_player_action("content/player.json", "walk_right");
    animations[2] = init_player_action("content/player.json", "walk_left");
    animations[3] = init_player_action("content/player.json", "walk_up");
    animations[4] = 0;
    for (int i = 0; animations[i] != 0; i++)
        set_anim_sprite_scale(animations[i], 1.8);
    return (animations);
}

static void create_player_init_values(player_t *player)
{
    player->interlocutor = NULL;
    player->learned_abi = 0;
    player->learned_spell = 0;
    player->delta = 0;
    player->current_animations = 0;
    player->delta_fight = 0;
    player->fight = 0;
    player->can_run_away = -1;
    player->inventory = create_inventory();
    player->in_teleportation = 1;
    player->animations = create_annimations();
}

player_t *create_player(void)
{
    player_t *player = deserialize_player();

    create_player_init_values(player);
    create_gui(player);
    player->collision = create_collision_box(\
    sfSprite_getGlobalBounds(player->animations[0]->sprite), 0, 1);
    player->free_moves = malloc(sizeof(int) * 5);
    player->free_moves = (int []){1, 1, 1, 1, 0};
    player->search_for_interlocutor = 1;
    player->in_teleportation = 0;
    return (player);
}