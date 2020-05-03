/*
** EPITECH PROJECT, 2020
** init_battle_screen.c
** File description:
**  function
*/

#include <game.h>
#include <scene/battle.h>
#include "lib/utils/string.h"
#include "lib/utils/file.h"

static const sfVector2f pos[] = {{150, 300}, {550, 300}, {950, 300},
    {1350, 300}, {700, 300}, 0};

static void init_battle_gui(game_t *game, battle_screen_t *battle)
{
    sfColor grey = sfColor_fromRGBA(87, 89, 93, 255);
    battle->dialog = 0;
    battle->attack_gui = create_attack_gui(battle->monster);
    battle->select_gui = create_select_gui(battle->monster);
    if (game->player->learned_abi == 0)
        set_text_color(battle->attack_gui->abilities, grey);
    if (game->player->learned_spell == 0)
        set_text_color(battle->attack_gui->spells, grey);
}

static void init_battle_zone(game_t *game, battle_screen_t *battle)
{
    int fd = open_file("content/zone_info.json");
    char *content = read_file(fd, "content/zone_info.json");
    char *zone = convert_str(game->player->zone);
    char *zone_json = get_key_data(content, zone);
    int monsters = fget_nbr(get_key_data(zone_json, "count"));
    monsters = (rand() % monsters) + 1;

    zone_json = get_key_data(zone_json, "monsters");
    char **array = str_split_json_array(zone_json, ',', 1);
    battle->monster = malloc(sizeof(monster_t) * (monsters+1));
    for (int i = 0; i < monsters; i++) {
        int index = rand() % array_length(array);
        battle->monster[i] = create_monster(array[index], pos[i]);
    }
    battle->monster[monsters] = 0;
    free(zone_json);
    free(zone);
    free(array);
    free(content);
}

static void init_spell_gui(game_t *game, battle_screen_t *battle)
{
    battle->spell_gui.spell = get_spells(game->player);
    battle->spell_gui.box = init_sprite("assets/", 0);
    battle->spell_gui.is_selected = 0;
    battle->spell_gui.cursor = 0;
}

static void init_battle_boss(game_t *game, battle_screen_t *battle)
{
    battle->monster = malloc(sizeof(monster_t) * 2);
    battle->monster[0] = create_monster("belze.json", pos[4]);
    battle->monster[1] = 0;
}

int init_battle_screen(game_t *game, battle_screen_t *battle)
{
    if (game->player->zone == 4) {
        init_battle_boss(game, battle);
    } else {
        init_battle_zone(game, battle);
    }
    battle->select_choice = 0;
    init_battle_screen_bg(game, battle);
    battle->music = init_sound("assets/music/monster_battle.ogg");
    battle->round.code = 0;
    battle->round.order_index = 0;
    battle->round.order = 0;
    battle->attacking = 0;
    battle->dialog = 0;
    battle->particle_system = 0;
    //init_spell_gui(game, battle);
    play_sound(battle->music, 60);
    sfView_setCenter(game->camera, (sfVector2f){800, 400});
    set_sound_loop(battle->music, 1);
    init_battle_gui(game, battle);
    battle->fade_out = 0;
    battle->fade_in = 0;
    return (0);
}