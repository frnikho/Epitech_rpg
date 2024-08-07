/*
** EPITECH PROJECT, 2020
** npc.c
** File description:
** npc function
*/

#include "game/npc.h"
#include "lib/utils/file.h"
#include "lib/utils/string.h"
#include <stdlib.h>
#include "game/collision.h"

static sfIntRect *get_npc_json_rect(char *filepath, char *animations)
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

static anim_sprite_t *init_npc(npc_t *npc, char *filepath, char *anim_name)
{
    sfIntRect *rect = get_npc_json_rect(filepath, anim_name);
    anim_sprite_t *sprite = create_anim_sprite(NPC_FP, (sfVector2f){0, 0});
    for (int i = 0; rect[i].height != -9999; i++)
        add_anim_frame(sprite, rect[i]);
    return (sprite);
}

void destroy_npc(npc_t *npc)
{
    for (int i = 0; npc->animations[i]; i++)
        dispose_anim_sprite(npc->animations[i]);
    free(npc->animations);
    free(npc->collision);
    free(npc->trigger);
    free(npc);
}

static void npc_init_values(npc_t *npc, int speed, char *filepath)
{
    npc->delta = 0;
    npc->delta_movement = 0;
    npc->current_animations = 0;
    npc->speed = speed;
    npc->fp = filepath;
    npc->need_move = 0;
    npc->finish_move = 0;
    npc->script = 0;
}

npc_t *create_npc(char *filepath, sfVector2f pos, int speed)
{
    npc_t *npc = malloc(sizeof(npc_t));

    npc_init_values(npc, speed, filepath);
    npc->next_pos = (sfVector2f){0, 0};
    npc->animations = malloc(sizeof(anim_sprite_t*) * 5);
    npc->animations[0] = init_npc(npc, filepath, "idle");
    npc->animations[1] = init_npc(npc, filepath, "walk_right");
    npc->animations[2] = init_npc(npc, filepath, "walk_left");
    npc->animations[3] = init_npc(npc, filepath, "walk_up");
    npc->animations[4] = 0;
    for (int i = 0; npc->animations[i] != 0; i++) {
        sfSprite_setPosition(npc->animations[i]->sprite, pos);
        set_anim_sprite_scale(npc->animations[i], 2);
    }
    sfFloatRect r = sfSprite_getGlobalBounds(npc->animations[0]->sprite);
    npc->collision = create_collision_box(r, 0, 1);
    npc->trigger = create_collision_box((sfFloatRect){r.left-10, r.top-10, \
        r.width+20, r.height+20}, 1, 0);
    return (npc);
}