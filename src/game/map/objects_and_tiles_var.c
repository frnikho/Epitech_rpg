/*
** EPITECH PROJECT, 2020
** map_parser
** File description:
** objects_and_tiles_var
*/

#include "game/map.h"

sfTexture **create_tiles(void)
{
    sfTexture **tab = malloc(sizeof(sfTexture*) * 4);

    tab[0] = sfTexture_createFromFile("assets/sprite/tiles/tile1.png", NULL);
    tab[1] = sfTexture_createFromFile("assets/sprite/tiles/tile2.png", NULL);
    tab[2] = sfTexture_createFromFile("assets/sprite/tiles/tile3.png", NULL);
    tab[3] = NULL;
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

int map_tile_id(int id)
{
    int default_tile = 1;
    int tab[][2] = {{31, 0},
                    {61, 1},
                    {19, 2}};

    for (int i = 0; i < 3; i++) {
        if (tab[i][0] == id)
            return (tab[i][1]);
    }
    return (default_tile);
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
