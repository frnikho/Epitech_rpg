/*
** EPITECH PROJECT, 2020
** map_parser
** File description:
** objects_and_tiles_var
*/

#include "game/map.h"

sfTexture **create_tiles(char *tile_set)
{
    sfTexture **tab = NULL;
    sfIntRect rect = {0, 0, 20, 20};
    sfTexture *tile_set_texture = sfTexture_createFromFile(tile_set, NULL);
    sfVector2u max_size = sfTexture_getSize(tile_set_texture);
    int index = 0;

    tab = malloc(sizeof(sfTexture*) * (((max_size.x / rect.width) * \
    (max_size.y / rect.height))+1));
    for (int y = 0; (rect.top + rect.height) <= max_size.y; y++) {
        for (int x = 0; (rect.left + rect.width) <= max_size.x; x++) {
            tab[index] = sfTexture_createFromFile(tile_set, &rect);
            tab[index+1] = NULL;
            rect.left += rect.width;
            index++;
        }
        rect.left = 0;
        rect.top += rect.height;
    }
    sfTexture_destroy(tile_set_texture);
    return (tab);
}

object_t **create_objects(void)
{
    object_t **tab = malloc(sizeof(object_t*) * 3);

    tab[0] = malloc(sizeof(object_t));
    tab[0]->texture = sfTexture_createFromFile("assets/sprite/tiles/pine-tree.png", NULL);
    tab[0]->scale = (sfVector2f){0.8, 0.8};
    tab[0]->texture_size = sfTexture_getSize(tab[0]->texture);
    tab[0]->disapear_dist = (sfVector2f){tab[0]->texture_size.x + 10, tab[0]->texture_size.y + 10};
    tab[0]->center_offset = (sfVector2f){((tab[0]->texture_size.x * tab[0]->scale.x)/2), (tab[0]->texture_size.y * tab[0]->scale.y)-5};

    tab[1] = malloc(sizeof(object_t));
    tab[1]->texture = sfTexture_createFromFile("assets/sprite/tiles/tiny-house.png", NULL);
    tab[1]->scale = (sfVector2f){0.8, 0.8};
    tab[1]->texture_size = sfTexture_getSize(tab[1]->texture);
    tab[1]->disapear_dist = (sfVector2f){tab[1]->texture_size.x + 10, tab[1]->texture_size.y + 10};
    tab[1]->center_offset = (sfVector2f){((tab[1]->texture_size.x * tab[1]->scale.x)/2), (tab[1]->texture_size.y * tab[1]->scale.y)/2};

    tab[2] = NULL;
    return (tab);
}

int map_obj_id(int id)
{
    int default_tile = 0;
    int tab[][2] = {{155, 0},
                    {8, 1}};

    for (int i = 0; i < 2; i++) {
        if (tab[i][0] == id)
            return (tab[i][1]);
    }
    return (default_tile);
}
