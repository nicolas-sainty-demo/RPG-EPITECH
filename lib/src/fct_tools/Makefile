##
## EPITECH PROJECT, 2021
## B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
## File description:
## Makefile
##

SRC	=	src/can_in_int_map.c				\
		src/get_nbr.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libtools.a

CFLAGS	=	-Wall -Wextra -I ../include

all:	$(NAME)


$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	mv $(NAME) ../../../

clean :
	rm -f $(OBJ)

fclean: clean
	rm -f ../../../$(NAME)

re: fclean all
