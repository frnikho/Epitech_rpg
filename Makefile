##
## EPITECH PROJECT, 2020
## Makefile header
## File description:
## Main makefile
##

CC						=					gcc -g
NAME					=					my_rpg
PATH_COMPONENT			=					src/component
PATH_SCENE				=					src/scene
PATH_STATE				=					src/state
PATH_MAIN				=					src

SRC						=					$(PATH_MAIN)/main.c																\
											$(PATH_MAIN)/game.c																\
											$(PATH_MAIN)/loop.c																\
											$(PATH_MAIN)/gui/dialog/dialog.c												\
											$(PATH_MAIN)/gui/dialog/active_dialog.c											\
											$(PATH_MAIN)/gui/dialog/set_dialog_text.c										\
											$(PATH_MAIN)/gui/dialog/update_dialog.c											\
											$(PATH_MAIN)/gui/dialog/draw_dialog.c											\
											$(PATH_MAIN)/gui/dialog/reset_dialog.c											\
											$(PATH_MAIN)/gui/dialog/set_dialog_position.c									\
											$(PATH_MAIN)/game/item/item.c													\
											$(PATH_MAIN)/game/monster/monster.c												\
											$(PATH_MAIN)/game/monster/draw_monster.c										\
											$(PATH_MAIN)/game/monster/attack_monster.c										\
											$(PATH_MAIN)/game/monster/update_monster.c										\
											$(PATH_MAIN)/game/monster/get_monsters.c										\
											$(PATH_MAIN)/game/monster/gui/monster_gui.c										\
											$(PATH_MAIN)/game/monster/gui/draw_monster_gui.c								\
											$(PATH_MAIN)/game/monster/gui/update_monster_gui.c								\
											$(PATH_MAIN)/game/inventory/inventory.c											\
											$(PATH_MAIN)/game/inventory/add_inventory_item.c								\
											$(PATH_MAIN)/game/inventory/draw_inventory.c									\
											$(PATH_MAIN)/game/inventory/open_inventory.c									\
											$(PATH_MAIN)/game/inventory/update_inventory.c									\
											$(PATH_MAIN)/game/inventory/handle_inventory.c									\
											$(PATH_MAIN)/game/stats/stats.c													\
											$(PATH_MAIN)/game/stats/damage_stats.c											\
											$(PATH_MAIN)/game/player/player.c												\
											$(PATH_MAIN)/game/player/draw_player.c											\
											$(PATH_MAIN)/game/player/update_player.c										\
											$(PATH_MAIN)/game/player/attack_player.c										\
											$(PATH_MAIN)/game/player/move_player.c											\
											$(PATH_MAIN)/game/player/get_player_position.c									\
											$(PATH_MAIN)/game/player/deserialize_player.c									\
											$(PATH_MAIN)/game/player/serialize_player.c										\
											$(PATH_MAIN)/game/player/destroy_player.c										\
											$(PATH_MAIN)/game/player/check_player_levelup.c									\
											$(PATH_MAIN)/game/player/get_player_level.c										\
											$(PATH_MAIN)/game/player/gui/player_gui.c										\
											$(PATH_MAIN)/game/player/gui/draw_player_gui.c									\
											$(PATH_MAIN)/game/player/gui/update_player_gui.c								\
											$(PATH_MAIN)/game/npc/npc.c														\
											$(PATH_MAIN)/game/npc/move_npc.c												\
											$(PATH_MAIN)/game/npc/draw_npc.c												\
											$(PATH_MAIN)/game/npc/update_npc.c												\
											$(PATH_MAIN)/game/npc/get_npc_dialog.c											\
											$(PATH_MAIN)/game/npc/get_town_npcs.c											\
											$(PATH_MAIN)/game/npc/script/get_npc_script.c									\
											$(PATH_MAIN)/game/npc/script/npc_script.c										\
											$(PATH_MAIN)/gui/attack_dialog/attack_gui.c										\
											$(PATH_MAIN)/gui/attack_dialog/draw_attack_gui.c								\
											$(PATH_MAIN)/gui/attack_dialog/handle_attack_gui.c								\
											$(PATH_MAIN)/gui/attack_dialog/update_attack_gui.c								\
											$(PATH_MAIN)/gui/select_dialog/select_gui.c										\
											$(PATH_MAIN)/gui/select_dialog/draw_select_gui.c								\
											$(PATH_MAIN)/gui/select_dialog/update_select_gui.c								\
											$(PATH_MAIN)/gui/select_dialog/handle_select_gui.c								\
											$(PATH_MAIN)/gui/pause/pause.c													\
											$(PATH_MAIN)/gui/pause/draw_pause.c												\
											$(PATH_MAIN)/gui/pause/update_pause.c											\
											$(PATH_MAIN)/game/map/dependencies.c											\
											$(PATH_MAIN)/game/map/destroy_and_free.c										\
											$(PATH_MAIN)/game/map/draw_and_create_objects.c									\
											$(PATH_MAIN)/game/map/draw_and_create_obstacles.c								\
											$(PATH_MAIN)/game/map/draw_and_create_tiles.c									\
											$(PATH_MAIN)/game/map/global_map_updates.c										\
											$(PATH_MAIN)/game/map/objects_and_tiles_var.c									\
											$(PATH_MAIN)/game/map/player_collisions.c										\
											$(PATH_MAIN)/game/map/render_optimisation.c										\
											$(PATH_MAIN)/game/collision/collision.c											\
											$(PATH_MAIN)/game/collision/interaction_boxes.c									\
											$(PATH_MAIN)/game/collision/player_collisions.c

SCENE					=					$(PATH_SCENE)/intro/intro_screen.c												\
											$(PATH_SCENE)/intro/init_intro_screen.c 										\
											$(PATH_SCENE)/intro/input_intro_screen.c										\
											$(PATH_SCENE)/intro/render_intro_screen.c										\
											$(PATH_SCENE)/intro/update_intro_screen.c										\
											$(PATH_SCENE)/main_menu/init_main_menu.c										\
											$(PATH_SCENE)/main_menu/input_main_menu.c										\
											$(PATH_SCENE)/main_menu/render_main_menu.c										\
											$(PATH_SCENE)/main_menu/update_main_menu.c										\
											$(PATH_SCENE)/main_menu/main_menu.c												\
											$(PATH_SCENE)/settings/init_settings_screen.c									\
											$(PATH_SCENE)/settings/input_settings_screen.c									\
											$(PATH_SCENE)/settings/render_settings_screen.c									\
											$(PATH_SCENE)/settings/settings_screen.c										\
											$(PATH_SCENE)/settings/update_settings_screen.c									\
											$(PATH_SCENE)/battle/battle_screen.c											\
											$(PATH_SCENE)/battle/init_battle_screen.c										\
											$(PATH_SCENE)/battle/init_battle_screen_bg.c									\
											$(PATH_SCENE)/battle/input_battle_screen.c										\
											$(PATH_SCENE)/battle/render_battle_screen.c										\
											$(PATH_SCENE)/battle/update_battle_screen.c										\
											$(PATH_SCENE)/battle/update_attack_battle_screen.c								\
											$(PATH_SCENE)/battle/run_away.c													\
											$(PATH_SCENE)/battle/battle_screen_check_player.c								\
											$(PATH_SCENE)/battle/end_battle_screen.c										\
											$(PATH_SCENE)/overworld/overworld.c												\
											$(PATH_SCENE)/overworld/init_overworld.c										\
											$(PATH_SCENE)/overworld/input_overworld.c										\
											$(PATH_SCENE)/overworld/render_overworld.c										\
											$(PATH_SCENE)/overworld/update_overworld.c										\
											$(PATH_SCENE)/overworld/zone/zone_world.c										\

STATE					=					$(PATH_STATE)/draw_state.c														\
											$(PATH_STATE)/update_state.c													\
											$(PATH_STATE)/create_state.c													\
											$(PATH_STATE)/intro/intro_state.c												\
											$(PATH_STATE)/world/world_state.c												\


OBJ						=					$(SRC:%.c=%.o) $(SCENE:%.c=%.o)	$(STATE:%.c=%.o)

LIB						=					-lm -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -L lib/ -lcsfml

CFLAGS					=					-I include/ $(LIB)

all:					$(NAME)
$(NAME):				$(OBJ)
						$(MAKE) -C lib/
						$(CC) -o $(NAME) $(OBJ) $(LIB) $(CFLAGS)
clean: clean
						$(RM) -rf $(OBJ)
						make -C lib/ clean
fclean:					clean
						$(RM) -rf $(NAME)
						make -C lib/ fclean
re:						fclean all
test_run:
						$(MAKE) -C tests/

debug:					CFLAGS+=-g
debug:					re