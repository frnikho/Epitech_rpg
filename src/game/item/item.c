/*
** EPITECH PROJECT, 2020
** item.c
** File description:
**  function
*/

#include "game/item.h"
#include <stdlib.h>
#include "lib/utils/string.h"
#include "lib/utils/json_parser.h"
#include "lib/utils/file.h"

item_t *deserialize_item(char *fp)
{
    item_t *item = malloc(sizeof(item_t));
    int fd = open_file(fp);
    if (fd <= 1)
        return (0);
    char *content = read_file(fd, fp);
    if (content == 0)
        return (0);
    sfIntRect rect;
    item->id = fget_nbr(get_key_data(content, "id"));
    char *texture = get_key_data(content, "texture");
    rect.left = fget_nbr(get_key_data(texture, "x"));
    rect.top = fget_nbr(get_key_data(texture, "y"));
    rect.width = fget_nbr(get_key_data(texture, "width"));
    rect.height = fget_nbr(get_key_data(texture, "height"));
    item->count = 1;
    item->sprite = init_sprite("assets/sprite/items.png", &rect);
    return (item);
}

item_t *create_item(char *fp)
{
    return deserialize_item(fp);
}

void dispose_item(item_t *item)
{
    free(item);
}