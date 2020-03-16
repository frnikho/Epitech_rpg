##
## EPITECH PROJECT, 2020
## Makefile header
## File description:
## Main makefile
##

CC						=					gcc

NAME					=					my_rpg

SRC						=					src/main.c														\

OBJ						=					$(SRC:%.c=%.o)

LIB						=					-lm -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

CFLAGS					=					-I include/ $(LIB)

all:					$(NAME)
$(NAME):				$(OBJ)
						$(CC) -o $(NAME) $(OBJ) $(LIB) $(CFLAGS)
clean: clean
						$(RM) -rf $(OBJ)
fclean:					clean
						$(RM) -rf $(NAME)
re:						fclean all

test_run:
						$(MAKE) -C tests/