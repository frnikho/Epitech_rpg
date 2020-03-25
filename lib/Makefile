##
## EPITECH PROJECT, 2020
## Makefile header
## File description:
## Main makefile
##

CC						=					gcc
NAME					=					libcsfml.a

PATH_COMPONENTS			=					components
PATH_EFFECTS			=					effects
PATH_UTILS				=					utils

COMPONENTS				=					$(PATH_COMPONENTS)/camera/camera_drag.c										\
											$(PATH_COMPONENTS)/camera/camera_move.c										\
											$(PATH_COMPONENTS)/sprite/sprite.c											\
											$(PATH_COMPONENTS)/sprite/sprite_position.c									\
											$(PATH_COMPONENTS)/sprite/sprite_size.c										\
											$(PATH_COMPONENTS)/sprite/sprite_event.c									\
											$(PATH_COMPONENTS)/anim_sprite/anim_sprite.c								\
											$(PATH_COMPONENTS)/anim_sprite/anim_sprite_info.c							\
											$(PATH_COMPONENTS)/anim_sprite/anim_sprite_update.c							\
											$(PATH_COMPONENTS)/anim_sprite/anim_sprite_event.c							\
											$(PATH_COMPONENTS)/text/text.c												\
											$(PATH_COMPONENTS)/text/text_color.c										\
											$(PATH_COMPONENTS)/text/text_font.c											\
											$(PATH_COMPONENTS)/text/text_event.c										\
											$(PATH_COMPONENTS)/button/button.c											\
											$(PATH_COMPONENTS)/button/button_listener.c									\
											$(PATH_COMPONENTS)/sound/sound.c											\
											$(PATH_COMPONENTS)/sound/sound_cmd.c										\
											$(PATH_COMPONENTS)/music/music.c											\


EFFECTS					=					$(PATH_EFFECTS)/bump/bump.c													\
											$(PATH_EFFECTS)/bump/draw_bump.c											\
											$(PATH_EFFECTS)/bump/update_bump.c											\
											$(PATH_EFFECTS)/bump/active_bump.c											\

UTILS					=					$(PATH_UTILS)/string/str_split.c											\
											$(PATH_UTILS)/string/str_len.c												\
											$(PATH_UTILS)/string/str_cat.c												\
											$(PATH_UTILS)/string/get_nbr.c												\
											$(PATH_UTILS)/json_parser/parser_construct_objects.c						\
											$(PATH_UTILS)/json_parser/parser_get_key_value.c							\
											$(PATH_UTILS)/json_parser/parser_get_patern_index.c							\
											$(PATH_UTILS)/json_parser/parser_value_to_var_type.c						\
											$(PATH_UTILS)/json_parser/parser.c											\
											$(PATH_UTILS)/file/open_file.c												\
											$(PATH_UTILS)/file/read_file.c												\


OBJ						=					$(COMPONENTS:%.c=%.o) $(EFFECTS:%.c=%.o) $(UTILS:%.c=%.o)

LIB						=					-lm -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

CFLAGS					=					-I ../include/ $(LIB)

all:										$(NAME)
$(NAME):									$(OBJ)
											ar rcs $(NAME) $(OBJ)
clean:
											rm -rf $(OBJ) $(OBJTESTS)
fclean:										clean
											rm -rf $(NAME) $(TNAME)
re:											fclean all
