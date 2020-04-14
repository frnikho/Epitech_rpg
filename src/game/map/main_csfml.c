/*
** EPITECH PROJECT, 2020
** map_parser
** File description:
** try_csfml
*/

#include "game/map.h"

char *get_key_data(char *buff, char *balise);
float my_getfloat(char *str);
/*
void csfml_loop(int ***tiles_tab, int ***objs_tab, char **obs_tab)
{
    window_t window;
    sfEvent event;
    map_t map;
    player_t player;

    create_window(&window);
    init_map(&map, tiles_tab, objs_tab, obs_tab);
    while (sfRenderWindow_isOpen(window.window)) {
        update_zoom_and_offset(&map);
        update_player_collision_box(&window, &player, &map);

        draw_map(&map, &window, (int []){0}, (int []){99, 0});
        draw_rectangle(&player.collision_box, &window);
        draw_map(&map, &window, (int []){99, 0}, (int []){0});

        print_framerate();
        analyse_event(&event, &window, &map, &player);
        sfRenderWindow_display(window.window);
        sfRenderWindow_clear(window.window, sfBlack);
    }
    destroy_and_free_map(&map);
    sfRenderWindow_destroy(window.window);
}*/