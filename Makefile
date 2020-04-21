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

SRC						=					src/main.c																\
											src/game.c																\
											src/gui/dialog/dialog.c													\
											src/gui/dialog/active_dialog.c											\
											src/gui/dialog/set_dialog_text.c										\
											src/gui/dialog/update_dialog.c											\
											src/gui/dialog/draw_dialog.c											\
											src/gui/dialog/reset_dialog.c											\
											src/game/item/item.c													\
											src/game/monster/monster.c												\
											src/game/monster/draw_monster.c											\
											src/game/monster/attack_monster.c										\
											src/game/monster/update_monster.c										\
											src/game/monster/get_monsters.c											\
											src/game/monster/gui/monster_gui.c										\
											src/game/monster/gui/draw_monster_gui.c									\
											src/game/monster/gui/update_monster_gui.c								\
											src/game/inventory/inventory.c											\
											src/game/inventory/add_inventory_item.c									\
											src/game/inventory/draw_inventory.c										\
											src/game/inventory/open_inventory.c										\
											src/game/inventory/update_inventory.c									\
											src/game/inventory/handle_inventory.c									\
											src/game/stats/stats.c													\
											src/game/stats/damage_stats.c											\
											src/game/player/player.c												\
											src/game/player/draw_player.c											\
											src/game/player/update_player.c											\
											src/game/player/attack_player.c											\
											src/game/player/move_player.c											\
											src/game/player/get_player_position.c									\
											src/game/player/deserialize_player.c									\
											src/game/player/serialize_player.c										\
											src/game/player/destroy_player.c										\
											src/game/player/gui/player_gui.c										\
											src/game/player/gui/draw_player_gui.c									\
											src/game/player/gui/update_player_gui.c									\
											src/game/npc/npc.c														\
											src/game/npc/draw_npc.c													\
											src/game/npc/update_npc.c												\
											src/game/npc/get_npc_dialog.c											\
											src/game/npc/get_town_npcs.c											\
											src/game/npc/script/get_npc_script.c									\
											src/game/npc/script/npc_script.c										\
											src/gui/attack_dialog/attack_gui.c										\
											src/gui/attack_dialog/draw_attack_gui.c									\
											src/gui/attack_dialog/handle_attack_gui.c								\
											src/gui/attack_dialog/update_attack_gui.c								\
											src/gui/select_dialog/select_gui.c										\
											src/gui/select_dialog/draw_select_gui.c									\
											src/gui/select_dialog/update_select_gui.c								\
											src/gui/select_dialog/handle_select_gui.c								\
											src/game/map/dependencies.c												\
											src/game/map/destroy_and_free.c											\
											src/game/map/draw_and_create_objects.c									\
											src/game/map/draw_and_create_obstacles.c								\
											src/game/map/draw_and_create_tiles.c									\
											src/game/map/global_map_updates.c										\
											src/game/map/objects_and_tiles_var.c									\
											src/game/map/player_collisions.c										\
											src/game/map/render_optimisation.c										\
											src/game/collision/collision.c											\
											src/game/collision/player_collisions.c

SCENE					=					$(PATH_SCENE)/intro/intro_screen.c										\
											$(PATH_SCENE)/intro/init_intro_screen.c 								\
											$(PATH_SCENE)/intro/input_intro_screen.c								\
											$(PATH_SCENE)/intro/render_intro_screen.c								\
											$(PATH_SCENE)/intro/update_intro_screen.c								\
											$(PATH_SCENE)/main_menu/init_main_menu.c								\
											$(PATH_SCENE)/main_menu/input_main_menu.c								\
											$(PATH_SCENE)/main_menu/render_main_menu.c								\
											$(PATH_SCENE)/main_menu/update_main_menu.c								\
											$(PATH_SCENE)/main_menu/main_menu.c										\
											$(PATH_SCENE)/settings/init_settings_screen.c							\
											$(PATH_SCENE)/settings/input_settings_screen.c							\
											$(PATH_SCENE)/settings/render_settings_screen.c							\
											$(PATH_SCENE)/settings/settings_screen.c								\
											$(PATH_SCENE)/settings/update_settings_screen.c							\
											$(PATH_SCENE)/battle/battle_screen.c									\
											$(PATH_SCENE)/battle/init_battle_screen.c								\
											$(PATH_SCENE)/battle/input_battle_screen.c								\
											$(PATH_SCENE)/battle/render_battle_screen.c								\
											$(PATH_SCENE)/battle/update_battle_screen.c								\
											$(PATH_SCENE)/battle/update_attack_battle_screen.c						\
											$(PATH_SCENE)/overworld/overworld.c										\
											$(PATH_SCENE)/overworld/init_overworld.c								\
											$(PATH_SCENE)/overworld/input_overworld.c								\
											$(PATH_SCENE)/overworld/render_overworld.c								\
											$(PATH_SCENE)/overworld/update_overworld.c								\

STATE					=					$(PATH_STATE)/draw_state.c												\
											$(PATH_STATE)/update_state.c											\
											$(PATH_STATE)/create_state.c											\
											$(PATH_STATE)/intro/intro_state.c										\


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