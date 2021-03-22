##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC	=	main.c						\
		init/window/init_window.c	\
		init/from_file/get_string_after_c.c	\
		init/from_file/get_the_int_after_c.c	\
		init/from_file/get_the_vector_i_after_c.c	\
		scen/default_page.c			\
		time/speed_of_game.c

SRC_PRI = ./src/

OBJ     =       $(addprefix $(SRC_PRI), $(SRC:.c=.o))

NAME    =       my_rpg

CFLAGS	=	-l csfml-audio -l csfml-graphics -l csfml-system -l csfml-window -l m \
			-Wall -Wextra -g\
			-I include -I lib/src/include

LFLAGS	=	-L. -lstr -ltools

all:	$(NAME)

$(NAME):	$(OBJ)
	$(MAKE) -C lib/
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LFLAGS)

clean:
	$(MAKE) -C lib/ clean
	rm -f $(OBJ)

fclean:	clean
	$(MAKE) -C lib/ fclean
	rm -f $(NAME)

re:	fclean all
