/*
** EPITECH PROJECT, 2020
** map_parser
** File description:
** map_loading
*/

#ifndef MAP_LOADING_H_
#define MAP_LOADING_H_

#include "game/player.h"
#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/System.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game/collision.h"

typedef struct object_s{
    sfTexture *texture;
    sfVector2f scale;
    sfVector2f center_offset;
    sfVector2f disapear_dist;
    sfVector2u texture_size;
} object_t;

typedef struct obstacle_s {
    sfConvexShape *body;
    sfFloatRect shape;
    float rotation;
    collision_box_t *collision;
} obstacle_t;

typedef struct tile_layer_s{
    sfTexture **tiles;
    int width;
    int height;
    int tile_size;
    sfConvexShape *tile_shape;
    int **tiles_map;
    float zoom;
    sfVector2f offset;
} tile_layer_t;

typedef struct object_layer_s{
    object_t **objects;
    int width;
    int height;
    int tile_size;
    sfSprite *obj_sprite;
    int **obj_map;
    float zoom;
    sfVector2f offset;
} object_layer_t;

typedef struct map_s{
    char *tile_set;
    tile_layer_t **tile_layers;
    object_layer_t **obj_layers;
    obstacle_t **obs;
    float zoom;
    sfVector2f offset;
    int tile_size;
} map_t;

typedef struct map_setup_s {
    char *file;
    char *tile_set;
    int layer_nb;
    int obs_nb;
    int *tile_layers_id;
    int *objs_layers_id;
    int *obs_layers_id;
    int tile_size;
    sfVector2f offset;
    float zoom;
} map_setup_t;

char *get_key_data(char *buff, char *balise);
float my_getfloat(char *str);

void draw_map(map_t *map, sfRenderWindow *window, int *layers_to_print_tiles, \
int *layers_to_print_objs, sfView *camera);
void update_zoom_and_offset(map_t *map);
void destroy_and_free_map(map_t *map);
int map_obj_id(int id);
int is_square_in_window(sfFloatRect rect, sfVector2f *points);
object_t **create_objects(void);
sfTexture **create_tiles(char *tile_set, int tile_size);
int get_tab_width(int **tab);
int get_tab_height(int **tab);
void init_map(map_t *map, int ***tiles_tab, int ***objs_tab, char **obs_tab);
void destroy_and_free_tile_layer(tile_layer_t *layer);
void destroy_and_free_obstacles(obstacle_t **obs);
void destroy_objects(object_t **obj);
void destroy_and_free_object_layer(object_layer_t *layer);
void draw_tiles(map_t *map, sfRenderWindow *window, int *layers_to_print, sfView *camera);
void draw_objects(map_t *map, sfRenderWindow *window, int *layers_to_print);
void draw_obstacles(map_t *map, sfRenderWindow *window);
void create_tile_tab(map_t *map, int ***layers_tab, char *tile_set);
void create_object_tab(map_t *map, int ***objs_tab);
void create_obtacles_tab(char **obj_tab, map_t *map);
int is_object_displayed(int i, int y, object_layer_t *layer, sfRenderWindow *window);
sfVector2f *is_tile_displayed(tile_layer_t *layer, int i, int y);

void create_window(sfRenderWindow *window);
void print_player(sfRenderWindow *window, map_t *map);
void print_framerate(void);
void draw_rectangle(sfFloatRect *rec, sfRenderWindow *window);
void analyse_event(sfEvent *event, sfRenderWindow \
*window, map_t *map, player_t *player);

#endif /* !MAP_LOADING_H_ */
