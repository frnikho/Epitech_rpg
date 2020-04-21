/*
** EPITECH PROJECT, 2020
** intro_screen_init
** File description:
** intro_screen_init function
*/

#include "lib/utils/file.h"
#include "lib/components/anim_sprite.h"
#include "game.h"
#include "scene/intro_screen.h"

int init_intro_screen(game_t *game, intro_screen_t *screen)
{
    screen->delta = 0;
    set_player_scale(game->player, 2);

    screen->npc = get_town_npcs("topaze");

    for (int i = 0; screen->npc[i] != 0; i++)
        for (int y = 0; screen->npc[i]->animations[y] != 0; y++)
            set_anim_sprite_scale(screen->npc[i]->animations[y], 2);

    item_t *medicinal = create_item("content/items/medicinal_herb.json");
    item_t *strong = create_item("content/items/strong_medicine.json");
    add_inventory_item(game->player->inventory, medicinal);
    add_inventory_item(game->player->inventory, strong);
    add_inventory_item(game->player->inventory, strong);
    return (0);
}