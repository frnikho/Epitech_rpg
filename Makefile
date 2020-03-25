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

SRC						=					src/main.c																\
											src/game.c																\
											src/gui/dialog/dialog.c													\
											src/gui/dialog/active_dialog.c											\
											src/gui/dialog/set_dialog_text.c										\
											src/gui/dialog/update_dialog.c											\
											src/gui/dialog/draw_dialog.c											\
											src/game/item/item.c													\
											src/game/monster/monster.c												\
											src/game/inventory/inventory.c											\
											src/game/stats/stats.c													\
											src/game/stats/damage_stats.c											\
											src/game/player/player.c												\
											src/game/player/deserialize_player.c									\
											src/game/player/serialize_player.c

SCENE					=					$(PATH_SCENE)/intro/intro_screen.c										\
											$(PATH_SCENE)/intro/init_intro_screen.c 								\
											$(PATH_SCENE)/intro/input_intro_screen.c								\
											$(PATH_SCENE)/intro/render_intro_screen.c								\
											$(PATH_SCENE)/intro/update_intro_screen.c								\

OBJ						=					$(SRC:%.c=%.o) $(SCENE:%.c=%.o)

LIB						=					-lm -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -L lib/ -lcsfml

CFLAGS					=					-I include/ $(LIB) -g

all:					$(NAME)
$(NAME):				$(OBJ)
						$(MAKE) -C lib/
						$(CC) -o $(NAME) $(OBJ) $(LIB) $(CFLAGS)
clean: clean
						$(RM) -rf $(OBJ)
fclean:					clean
						$(RM) -rf $(NAME)
re:						fclean all

test_run:
						$(MAKE) -C tests/