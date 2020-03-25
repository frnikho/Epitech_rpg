/*
** EPITECH PROJECT, 2020
** map_parser
** File description:
** try_csfml
*/

#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/System.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <fcntl.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    sfTexture **tiles;
    int width;
    int height;
    int tile_size;
    sfConvexShape *tile_shape;
    int **tiles_map;
    float zoom;
    sfVector2f offset;
} map_t;

typedef struct {
    sfRenderWindow *window;
    sfVideoMode video_mode;
    int current_scene;
    int prev_scene;
    int framerate;
} window_t;

void create_window(window_t *window)
{
    window->video_mode.bitsPerPixel = 32;
    window->video_mode.width = 1280;
    window->video_mode.height = 720;
    window->window = sfRenderWindow_create(window->video_mode, "RPG_MAP", \
    sfResize | sfClose, NULL);
    window->framerate = 60;
}

void analyse_event(sfEvent *event, window_t \
*window, sfVector2f *offset, float *zoom)
{
    while (sfRenderWindow_pollEvent(window->window, event)) {
        if (event->type == sfEvtClosed)
            sfRenderWindow_close(window->window);
        /*if(event->type == sfEvtKeyPressed) {
            switch (event->key.code) {
                case (sfKeyRight):
                    offset->x -= 2*(*zoom);
                    break;
                case (sfKeyLeft):
                    offset->x += 2*(*zoom);
                    break;
                case (sfKeyUp):
                    offset->y += 2*(*zoom);
                    break;
                case (sfKeyDown):
                    offset->y -= 2*(*zoom);
                    break;
                case (sfKeyZ):
                    (*zoom) += 0.1;
                    break;
                case (sfKeyA):
                    (*zoom) -= 0.1;
                    break;
            }
        }*/
    }
}

int get_tab_width(int **tab)
{
    int result = 0;

    for (; tab[result]; result++);
    return (result);
}

int get_tab_height(int **tab)
{
    int result = 0;

    for (; tab[0][result]; result++);
    return (result);
}

sfTexture **create_tiles(void)
{
    sfTexture **tab = malloc(sizeof(sfTexture*) * 3);

    tab[0] = sfTexture_createFromFile("tiles/tile1.png", NULL);
    tab[1] = sfTexture_createFromFile("tiles/tile2.png", NULL);
    tab[2] = sfTexture_createFromFile("tiles/tile3.png", NULL);
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

void destroy_tiles(sfTexture **tiles)
{
    sfTexture_destroy(tiles[0]);
    sfTexture_destroy(tiles[1]);
    sfTexture_destroy(tiles[2]);
}

void destroy_and_free_map(map_t *map)
{
    destroy_tiles(map->tiles);
    free(map->tiles);
    sfConvexShape_destroy(map->tile_shape);
}

void draw_tile(map_t *map, window_t *window, int i, int y)
{
    int t_size = map->tile_size;
    float zoom = map->zoom;
    float off_x = map->offset.x;
    float off_y = map->offset.y;

    if (map->tiles_map[y][i] == -1)
        return;
    sfConvexShape_setPoint(map->tile_shape, 0, \
    (sfVector2f){(i*t_size)*zoom+off_x, (y*t_size)*zoom+off_y});
    sfConvexShape_setPoint(map->tile_shape, 1, \
    (sfVector2f){((i*t_size)+t_size)*zoom+off_x, (y*t_size)*zoom+off_y});
    sfConvexShape_setPoint(map->tile_shape, 2, \
    (sfVector2f){((i*t_size)+t_size)*zoom+off_x, \
    ((y*t_size)+t_size)*zoom+off_y});
    sfConvexShape_setPoint(map->tile_shape, 3, \
    (sfVector2f){(i*t_size)*zoom+off_x, ((y*t_size)+t_size)*zoom+off_y});
    sfConvexShape_setTexture(map->tile_shape, \
    map->tiles[map_tile_id(map->tiles_map[y][i])], sfTrue);
    sfRenderWindow_drawConvexShape(window->window, map->tile_shape, NULL);
}

void draw_map(map_t *map, window_t *window)
{
    sfConvexShape_setPointCount(map->tile_shape, 4);
    for (int y = 0; y < map->height; y++) {
        for (int i = 0; i < map->width; i++) {
            draw_tile(map, window, i, y);
        }
    }
}

void init_map(map_t *map, int **tiles_map)
{
    map->tiles = create_tiles();
    map->width = get_tab_width(tiles_map);
    map->height = get_tab_height(tiles_map);
    map->tile_size = 32;
    map->tile_shape = sfConvexShape_create();
    map->tiles_map = tiles_map;
    map->zoom = 1;
    map->offset.x = 0;
    map->offset.y = 0;
}

/*void center_on_map_coord(map_t *map, window_t *window, sfVector2f center)
{
    map->offset.x = (window->video_mode.width / 2) - \
    ((center.x* map->zoom) / 2);
    map->offset.y = (window->video_mode.height / 2) - \
    ((center.y* map->zoom) / 2);
}*/

void csfml_loop(int **tiles_map_one, int **tiles_map_two)
{
    window_t window;
    sfEvent event;
    map_t map;
    map_t map2;

    create_window(&window);
    init_map(&map, tiles_map_one);
    init_map(&map2, tiles_map_two);
    //center_on_map_coord(&map, &window, (sfVector2f){300, 300});
    while (sfRenderWindow_isOpen(window.window)) {
        draw_map(&map, &window);
        draw_map(&map2, &window);
        //map.zoom += 0.0001;
        //map2.zoom += 0.0001;
        analyse_event(&event, &window, &map.offset, &map.zoom);
        sfRenderWindow_display(window.window);
        sfRenderWindow_clear(window.window, sfBlack);
    }
    destroy_and_free_map(&map);
    destroy_and_free_map(&map2);
    sfRenderWindow_destroy(window.window);
}